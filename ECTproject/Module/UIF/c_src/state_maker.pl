my $module_name="";
my $author="";
my $date="";

print "Please Input State Name:";
$module_name=<>;
chomp($module_name);
$module_name=~s/ /_/g;
return if ($module_name!~/\S/);
print "Please Input Author Name:";
$author=<>;
chomp($author);
return if ($author!~/\S/);
print "Please Input Create Date:";
$date=<>;
chomp($date);
return if ($date!~/\S/);

my $c_src=$module_name.'\c_src';
my $asm_src=$module_name.'\asm_src';
my $drv_src=$module_name.'\drv_src';
my $copyright="Copyright (C) 2009, FINE-TEK CO.,LTD. Taiwan  All Rights Reserved";
my $const_str="EXTERNAL GLOBAL CONSTANCE / VARIABLES IN EEPROM";
my $condition_str="CONDICTION COMPILE";
my $include_str="INCLUDE FILES / EXTERNAL VARIABLES";
my $api_for_str="API FOR OTHER MODULES";
my $api_str="API CALL FROM OTHER MODULES";
my $func_str="FUNCTION PROTOTYPES";
my $external_def="EXTERNAL VARIABLE ALLOC";
my $glb_vars="DECLARE GLOBE VARIABLE";
my $io_definition_str="I/O PORT DEFINITION";
my $marco_definition_str="MACRO DEFINITION";
my $glb_state_str="DECLARE GLOBE VARIABLE";

my $step="\t\t\t\t\t\t\t\t\t\t\t\t\t\t";

new_state();

print "It's done!\n";
print "State Name: $module_name\n";
print "Author     : $author \n";
print "Create Date: $date\n";
$module_name=<>;

sub new_state()
{
	my $Mname="uif_".lc($module_name);
	my $def="UIF_".uc($module_name)."_STATE_H";
	my $filename=$Mname.'_state.h';
	my $path_filename=$filename;
	open(my $file,">$path_filename");
	print $file "#ifndef $def\n";
	print $file "#define $def\n";
	new_file_detail($file,$filename,"Here declare state task function");
	new_box($file,$include_str);
	print $file "#include \""."..\\uif_udef.h\"\n";
	new_box($file,$glb_state_str);
	print $file "extern const STC_UIF_STATE "."uif_".lc($module_name)."_state;\n";
	new_box($file,$marco_definition_str);
	new_box($file,$func_str);
#	print $file "void "."uif_".lc($module_name).'_state_task();'."\n";
	print $file "#endif		// $def \n";
	close($file);

	my $filename=$Mname.'_state.c';
	my $path_filename=$filename;
	open(my $file,">$path_filename");
	new_file_detail($file,$filename,lc($Mname)."_state functions");
	new_box($file,$include_str);
	print $file "#include \""."uif_glb_vars.h\"\n";
	print $file "#include \""."uif_idef.h\"\n";
	print $file "#include \""."..\\uif_udef.h\"\n";
	new_info($file,$Mname." Level list definition");
	print $file "enum ".uc($Mname)."_LEVEL_LIST\n";
	print $file "{\n";
	print $file "\t".uc($Mname).'_LEVEL,'."\n";
	print $file "\t".uc($Mname).'_TOTAL,'."\n";
	print $file "};\n";
	new_info($file,$Mname." map definition");
	print $file "const STC_UIF_MENU ".lc($Mname).'_menu_map[]='."\n";
	print $file "{\n";
	print	$file "\tUIF_NULL,UIF_NULL,\n";
	print $file "};\n";
	$func_name=$Mname.'_state_task';	
	new_func($file,$func_name,"task function");
	print $file "void $func_name()\n";
	print $file "{\n\n";
	print $file "}\n";
	new_info($file,lc($module_name)." keymap ");
	print $file "const STC_UIF_KEYMAP ".lc($Mname)."_keymap\[\]=\n";
	print $file "{\n";
	print $file	"\tUIF_NULL_FUNC,UIF_NULL,\n";
	print $file	"\tUIF_NULL_FUNC,UIF_NULL,\n";
	print $file	"\tUIF_NULL_FUNC,UIF_NULL,\n";
	print $file	"\tUIF_NULL_FUNC,UIF_NULL,\n";
	print $file "};\n";
	new_info($file,uc($module_name)." state Table ");
	print $file "const STC_UIF_STATE $Mname"."_state=\n";
	print $file "{\n".'/*        level                  item_cnt                     menu_func            menu_keymap   			max_line*/'."\n";
	print $file "\tUIF_SWAP_MENU_LEVEL       ,UIF_".uc($module_name).'_TOTAL       ,'.$func_name.",       ".lc($Mname)."_keymap		,1\n";
	print $file "};\n\n";
	close($file);	
}

sub new_func()
{
	my $file=shift;
	my $func=shift;
	my $brief=shift;
	print $file "//**********************************************************************************************************************\n";
   print $file "//\n";
	print $file "// $copyright\n";
	print $file "//\n";
	print $file "//! \@fn \t\t\t $func\n";
	print $file "//\n";
	print $file "//! \@author \t $author\n";
	print $file "//\n";
	print $file "//! \@date \t\t $date\n";
	print $file "//\n";
	print $file "//! \@brief \t\t $brief\n";
	print $file "//\n";
	print $file "//! \@param \t\t None\n";
	print $file "//\n";
	print $file "//! \@return \t None\n";
	print $file "//\n";
	print $file "//**********************************************************************************************************************\n";
}

sub new_info()
{
	my $file=shift;
	my $brief=shift;
	print $file "//**********************************************************************************************************************\n";
   print $file "//\n";
	print $file "// $copyright\n";
	print $file "//\n";
	print $file "//! \@author \t $author\n";
	print $file "//\n";
	print $file "//! \@date \t\t $date\n";
	print $file "//\n";
	print $file "//! \@brief \t\t $brief\n";
	print $file "//\n";
	print $file "//**********************************************************************************************************************\n";
}

sub new_file_detail()
{
	my $file=shift;
	my $filename=shift;
	my $brief=shift;
	print $file "//**********************************************************************************************************************\n";
   print $file "//\n";
	print $file "// $copyright\n";
	print $file "//\n";
	print $file "//! \@file \t\t $filename\n";
	print $file "//\n";
	print $file "//! \@author \t $author\n";
	print $file "//\n";
	print $file "//! \@date \t\t $date\n";
	print $file "//\n";
	print $file "//  \@brief \t\t $brief\n";
	print $file "//\n";
	print $file "//**********************************************************************************************************************\n";
}

sub new_box()
{
	my $file=shift;
	my $str=shift;
	my @char=split(//,$str);
	print $file "//**********************************************************************************************************************\n";
 	print $file "//\n";
 	print $file "// ";
	for (my $i=0;$i<@char;$i++)
	{
		print $file "$char[$i] ";
	}
	print $file "\n";
 	print $file "//\n";
 	print $file "//**********************************************************************************************************************\n";
	#print $file "\n";
}

