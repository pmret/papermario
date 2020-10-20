.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242934
/* C63644 80242934 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C63648 80242938 AFBF0010 */  sw        $ra, 0x10($sp)
/* C6364C 8024293C 8C82000C */  lw        $v0, 0xc($a0)
/* C63650 80242940 0C0B1EAF */  jal       get_variable
/* C63654 80242944 8C450000 */   lw       $a1, ($v0)
/* C63658 80242948 3C018024 */  lui       $at, 0x8024
/* C6365C 8024294C AC224208 */  sw        $v0, 0x4208($at)
/* C63660 80242950 24020002 */  addiu     $v0, $zero, 2
/* C63664 80242954 8FBF0010 */  lw        $ra, 0x10($sp)
/* C63668 80242958 24030001 */  addiu     $v1, $zero, 1
/* C6366C 8024295C 3C018024 */  lui       $at, 0x8024
/* C63670 80242960 AC234204 */  sw        $v1, 0x4204($at)
/* C63674 80242964 03E00008 */  jr        $ra
/* C63678 80242968 27BD0018 */   addiu    $sp, $sp, 0x18
