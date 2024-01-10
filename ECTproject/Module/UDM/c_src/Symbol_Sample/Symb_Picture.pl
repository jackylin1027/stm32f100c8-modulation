my $filename="..\\udm_symb.c";
my $gcc_order="c:\\dev-cpp\\bin\\gcc symbol.c -o symbol.exe";
open(my $file,"<$filename") || print "Can't open $filename";
my $symb_name="";
my $symb_data="";
my $pattern=0,$pattern_size=0;
my $symb_w=0,$symb_h=8;

while (<$file>)
{
	my $line=$_;

	$symb_w=5  if ($line=~/ICON SYMBOL START/);
	$symb_w=10 if ($line=~/ICON2 SYMBOL START/);
	$symb_w=15 if ($line=~/ICON3 SYMBOL START/);
	$pattern=1 if ($line=~/PATTERN SYMBOL START/);

	
	$pattern_size-- if ($pattern_size!=0);

	if ($line=~/\/\*\s+(\S+)/ && $line!=~/START/)
	{
		$symb_name=$1;
		print "$symb_name \n";
		if ($pattern==1)
		{
			if ($line=~/W:(\d+)\s+H:(\d+)/)
			{
				$symb_w=$1;
				$symb_h=$2;
				$pattern_size=2;
			}
		}
	}
	elsif ($line=~/(0x\S+)/ && $line!=~/\/\*/ && $pattern_size==0 )
	{
		my $key=$1;
		$key=~s/\t//g;
		$key=~s/\s+//g;
		$key=~s/\n//g;
		$symb_data.="\t".$key."\n";
	}
	elsif ($line!=~/\S+/ && $symb_name ne "" && $symb_w!=0 && $pattern_size==0)
	{
		my $source_file="#include <stdio.h>\n#pragma pack(1)\n";
		$source_file.="#define PIC_W		$symb_w\n";
		$source_file.="#define PIC_H		$symb_h\n";
		$source_file.="#define FILENAME	\"$symb_name.bmp\"\n";
		my $row=int($symb_h/8);
		$row ++ if ($symb_h%8);
		$source_file.="unsigned char data[".($symb_w*$row)."]=\n";
		$source_file.="{\n";
		$source_file.="$symb_data";
		$source_file.="};\n\n";
		my $sample_file="symbol_to_bmp.c";
		open(my $sample,"<$sample_file");
		while (<$sample>) { $source_file.=$_;}
		close($sample);

		my $outname="symbol.c";
		open(my $outfile,">$outname");
		print $outfile $source_file;
		close($outfile);
		my $gcc_order=$gcc_path.
		`$gcc_order`;
		`symbol`;
		`del symbol.c symbol.exe`;
		$symb_name=$symb_data="";
		
	}
}

close($file);

