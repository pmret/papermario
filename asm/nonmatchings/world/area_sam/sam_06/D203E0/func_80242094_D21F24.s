.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242094_D21F24
/* D21F24 80242094 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D21F28 80242098 AFBF0010 */  sw        $ra, 0x10($sp)
/* D21F2C 8024209C 8C82000C */  lw        $v0, 0xc($a0)
/* D21F30 802420A0 0C0B1EAF */  jal       get_variable
/* D21F34 802420A4 8C450000 */   lw       $a1, ($v0)
/* D21F38 802420A8 0C0B1059 */  jal       does_script_exist
/* D21F3C 802420AC 0040202D */   daddu    $a0, $v0, $zero
/* D21F40 802420B0 2C420001 */  sltiu     $v0, $v0, 1
/* D21F44 802420B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* D21F48 802420B8 00021040 */  sll       $v0, $v0, 1
/* D21F4C 802420BC 03E00008 */  jr        $ra
/* D21F50 802420C0 27BD0018 */   addiu    $sp, $sp, 0x18
