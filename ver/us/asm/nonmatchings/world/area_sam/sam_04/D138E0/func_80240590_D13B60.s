.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240590_D13B60
/* D13B60 80240590 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D13B64 80240594 AFBF0010 */  sw        $ra, 0x10($sp)
/* D13B68 80240598 8C82000C */  lw        $v0, 0xc($a0)
/* D13B6C 8024059C 0C0B1EAF */  jal       get_variable
/* D13B70 802405A0 8C450000 */   lw       $a1, ($v0)
/* D13B74 802405A4 3C018024 */  lui       $at, %hi(D_80243880_D16E50)
/* D13B78 802405A8 AC223880 */  sw        $v0, %lo(D_80243880_D16E50)($at)
/* D13B7C 802405AC 24020002 */  addiu     $v0, $zero, 2
/* D13B80 802405B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D13B84 802405B4 24030001 */  addiu     $v1, $zero, 1
/* D13B88 802405B8 3C018024 */  lui       $at, %hi(D_8024387C_D16E4C)
/* D13B8C 802405BC AC23387C */  sw        $v1, %lo(D_8024387C_D16E4C)($at)
/* D13B90 802405C0 03E00008 */  jr        $ra
/* D13B94 802405C4 27BD0018 */   addiu    $sp, $sp, 0x18
