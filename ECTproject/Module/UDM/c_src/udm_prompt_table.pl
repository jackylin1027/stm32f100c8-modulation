my $filename="udm_prompt_string_english.txt";
my $prompt_file="udm_glb_vars.c";
my $prompt_tbl_name="gs_udm_rom_prompt";

my $cnt=0;
my $total_num=0;
my $offset=0;
my $result="";

open(my $file,"<$filename");
while (<$file>)
{
	$total_num+=1 if ($_=~/"(.*)"/);
}
$result.="// There're $total_num prompts\n\t";
$total_num*=2;
close($file);

open(my $file,"<$filename");
while (<$file>)
{
	my $line=$_;
	if ($line=~/"(.*)"/)
	{
		my $str=$1;
		$result.=sprintf("0x%02X,",($total_num+$offset)%256);
		$result.=sprintf("0x%02X,",($total_num+$offset)/256);
		$offset+=length($str)+1;
		$cnt++;
		$result.="\n\t" if (!($cnt%8));
	}
}
$result.="\n\t";
close($file);

open($file,"<$filename");
while (<$file>)
{
	my $line=$_;
	if ($line=~/\"(.*)\"/)
	{
		my $str=$1;
		$str=~s/ /@/g;
		while ($str=~/(\S)/)
		{
			my $char=$1;
			$char=~s/@/ /g;
			$result.="'$char',";
			$char=~s/ /@/g;
			$str=~s/$char//;
		}
		$result.="0x00,\n\t";
	}
}

close($file);
my $result_file="";
my $toggle=0;
open ($file,"<$prompt_file");
while (<$file>)
{
	my $line=$_;
	$result_file.=$line if ($toggle<=1 || $toggle==3);
	$toggle=1 if ($line=~/const UINT8 $prompt_tbl_name/);
	if ($toggle==2 && $line=~/}/)
	{
		chomp($result_file);
		$result_file.="\n};\n";
		$toggle=3;
	}
	if ($toggle==1 && $line=~/{/)
	{
		$result_file.=$result;
		$toggle=2;
	}
}

close($file);

open ($file,">$prompt_file");
print $file $result_file;
close($file);