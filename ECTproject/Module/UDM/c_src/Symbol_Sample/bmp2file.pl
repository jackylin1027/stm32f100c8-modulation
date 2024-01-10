my $list=`dir *.bmp`;
my @lines=split(/\n/,$list);
while (<@lines>)
{
	my $tmp=$_;
	if ($tmp=~/(.*.bmp)/)
	{
		my $file=$1;
		my $filename=$1 if ($file=~/(.*).bmp/);
		my $result=`b2b $file`;
		my $width;
		my $height;
		my $data;
		$width=$1 if ($result=~/Width: (\d+)/);
		$height=$1 if ($result=~/Height:(\d+)/);
		print "\t\/* UDM_".$filename." W:$width H:$height *\/\n";
		printf("\t0x%02X,0x%02X,",$width,$height);
		$data=$' if ($result=~/\{/);
		$data=~s/\}//g;
		print "$data";
	}
}