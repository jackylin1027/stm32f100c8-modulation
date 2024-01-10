my $filename="udm_symb.h";
open(my $file,"<$filename");
my $head="";
my $body="";
my $tail="";
my $step=0;
my $addr=-1;
while (<$file>)
{
	$line=$_;
	$addr=hex($1)-1 if ($line=~/UDM_BASE_PATTERN_START\s+(\S+)/ && $addr == -1);
	if ($line=~/Auto ReIndex Start/)
	{
		$step=1;
		$head.=$line;	
	}
	$step=2 if ($line=~/Auto ReIndex Stop/);
	$head.=$line if ($step==0);
	$tail.=$line if ($step==2);
}
close($file);
$filename="udm_symb.c";
open($file,"<$filename");
my $type="UDM_CHAR_SIZE";
my $ltype="UDM_CHAR_SIZE";
$step=0;
my $last1="0";
my $key;
my $dataline=0;
my $itemname="";
my $temp;
my $PatLen=0;
my $PatLenName="";
my $LastPatLenName="";
my $PatternStart=0;
while (<$file>)
{
	$line=$_;
	if ($line=~/CHAR SYMBOL START/)
	{
		$step=1;
		$body.="\n".$line;
		$itemname="UDM_CHAR";
	}
	else 
	{
		if ($step!=0)
		{
				if ($line=~/(\w+) SYMBOL START/)
				{
					$ltype=$type;
					$type="UDM_".$1."_SIZE";
					$body.="\n".$line;   
					$itemname="UDM_".$1; 
					$PatternStart=1 if ($itemname eq "UDM_PATTERN");   
				}
				else
				{	
					if ($line=~/\/\*\s+(\w+)\s/)
					{
						$last1=$key;
						$key=$1;
						$body.="#define $itemname"."_SYMBOL_START\t\t\t\t$key"."_SYMB\n" if ($itemname ne "");
						$itemname="";
						if ($PatternStart)
						{
							$body.="#define $key"."_LEN\t\t\t\t";
							if ($line=~/W:(\d+)\sH:(\d+)/)
							{
								my $h=int($2/8);
								$h++ if ($2%8);
								$addr+=$PatLen;
								$PatLen=$1*$h+2;
								$body.=$PatLen."\n";
								$LastPatLenName=$PatLenName;
								$PatLenName=$key."_LEN";
							}
						}	
						$body.="#define $key"."_SYMB ";
						$dataline=0;  
					}	
					elsif ($line=~/\S+/ && $dataline<1)
					{
						for (my $cnt=length($key);$cnt<21;$cnt++) { $body.=" ";}
						
						if ($last1 ne "" && $key ne "NULL_SYMB")
						{
							if ($ltype ne "UDM_PATTERN_SIZE")
							{
								$temp="($last1"."_SYMB + $ltype)";
							}
							else
							{
								$temp="($last1"."_SYMB + $LastPatLenName)";	
							}
						}
						else
						{
							$temp="UDM_BASE_PATTERN_START";	
						}	
						$body.=$temp;
						for ($cnt=length($temp);$cnt<40;$cnt++) {	$body.=" ";}
						$addr+=1	if ($ltype eq "UDM_CHAR_SIZE");
						$addr+=2 if ($ltype eq "UDM_NCHAR2_SIZE");
						$addr+=5 if ($ltype eq "UDM_ICON_SIZE");
						$addr+=10 if ($ltype eq "UDM_ICON2_SIZE");
						$addr+=15 if ($ltype eq "UDM_ICON3_SIZE");
						$addr+=$PatLen if (ltype eq "PATTERN");
						$body.="\t\t\/\*\t".sprintf("0x%X",$addr)."\t\*\/";
						$body.="\n";
						$ltype=$type;
						$dataline++;
					}
				}
		}
	}
}
close($file);
open($out,">udm_symb.h");
print $out $head.$body.$tail."\n";
close($out);

