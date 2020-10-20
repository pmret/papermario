.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240974_D060A4
/* D060A4 80240974 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D060A8 80240978 AFBF0010 */  sw        $ra, 0x10($sp)
/* D060AC 8024097C 8C82000C */  lw        $v0, 0xc($a0)
/* D060B0 80240980 0C0B1EAF */  jal       get_variable
/* D060B4 80240984 8C450000 */   lw       $a1, ($v0)
/* D060B8 80240988 0C0B1059 */  jal       does_script_exist
/* D060BC 8024098C 0040202D */   daddu    $a0, $v0, $zero
/* D060C0 80240990 2C420001 */  sltiu     $v0, $v0, 1
/* D060C4 80240994 8FBF0010 */  lw        $ra, 0x10($sp)
/* D060C8 80240998 00021040 */  sll       $v0, $v0, 1
/* D060CC 8024099C 03E00008 */  jr        $ra
/* D060D0 802409A0 27BD0018 */   addiu    $sp, $sp, 0x18
