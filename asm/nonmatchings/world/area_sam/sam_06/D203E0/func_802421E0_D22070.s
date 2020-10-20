.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421E0_D22070
/* D22070 802421E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D22074 802421E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* D22078 802421E8 8C82000C */  lw        $v0, 0xc($a0)
/* D2207C 802421EC 3C068011 */  lui       $a2, 0x8011
/* D22080 802421F0 80C6F2A2 */  lb        $a2, -0xd5e($a2)
/* D22084 802421F4 0C0B2026 */  jal       set_variable
/* D22088 802421F8 8C450000 */   lw       $a1, ($v0)
/* D2208C 802421FC 0C03AC5A */  jal       func_800EB168
/* D22090 80242200 0000202D */   daddu    $a0, $zero, $zero
/* D22094 80242204 8FBF0010 */  lw        $ra, 0x10($sp)
/* D22098 80242208 24020002 */  addiu     $v0, $zero, 2
/* D2209C 8024220C 03E00008 */  jr        $ra
/* D220A0 80242210 27BD0018 */   addiu    $sp, $sp, 0x18
