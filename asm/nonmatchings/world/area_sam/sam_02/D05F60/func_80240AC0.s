.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AC0
/* D061F0 80240AC0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D061F4 80240AC4 AFBF0010 */  sw        $ra, 0x10($sp)
/* D061F8 80240AC8 8C82000C */  lw        $v0, 0xc($a0)
/* D061FC 80240ACC 3C068011 */  lui       $a2, 0x8011
/* D06200 80240AD0 80C6F2A2 */  lb        $a2, -0xd5e($a2)
/* D06204 80240AD4 0C0B2026 */  jal       set_variable
/* D06208 80240AD8 8C450000 */   lw       $a1, ($v0)
/* D0620C 80240ADC 0C03AC5A */  jal       func_800EB168
/* D06210 80240AE0 0000202D */   daddu    $a0, $zero, $zero
/* D06214 80240AE4 8FBF0010 */  lw        $ra, 0x10($sp)
/* D06218 80240AE8 24020002 */  addiu     $v0, $zero, 2
/* D0621C 80240AEC 03E00008 */  jr        $ra
/* D06220 80240AF0 27BD0018 */   addiu    $sp, $sp, 0x18
