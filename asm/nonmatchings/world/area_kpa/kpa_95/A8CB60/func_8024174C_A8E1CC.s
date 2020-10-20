.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024174C_A8E1CC
/* A8E1CC 8024174C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A8E1D0 80241750 AFBF0010 */  sw        $ra, 0x10($sp)
/* A8E1D4 80241754 8C82000C */  lw        $v0, 0xc($a0)
/* A8E1D8 80241758 0C0B1EAF */  jal       get_variable
/* A8E1DC 8024175C 8C450000 */   lw       $a1, ($v0)
/* A8E1E0 80241760 0C0B1059 */  jal       does_script_exist
/* A8E1E4 80241764 0040202D */   daddu    $a0, $v0, $zero
/* A8E1E8 80241768 2C420001 */  sltiu     $v0, $v0, 1
/* A8E1EC 8024176C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A8E1F0 80241770 00021040 */  sll       $v0, $v0, 1
/* A8E1F4 80241774 03E00008 */  jr        $ra
/* A8E1F8 80241778 27BD0018 */   addiu    $sp, $sp, 0x18
