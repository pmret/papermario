.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240590_CF8100
/* CF8100 80240590 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF8104 80240594 AFBF0010 */  sw        $ra, 0x10($sp)
/* CF8108 80240598 8C82000C */  lw        $v0, 0xc($a0)
/* CF810C 8024059C 0C0B1EAF */  jal       evt_get_variable
/* CF8110 802405A0 8C450000 */   lw       $a1, ($v0)
/* CF8114 802405A4 3C018024 */  lui       $at, %hi(D_802432D4_CFAE44)
/* CF8118 802405A8 AC2232D4 */  sw        $v0, %lo(D_802432D4_CFAE44)($at)
/* CF811C 802405AC 24020002 */  addiu     $v0, $zero, 2
/* CF8120 802405B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF8124 802405B4 24030001 */  addiu     $v1, $zero, 1
/* CF8128 802405B8 3C018024 */  lui       $at, %hi(D_802432D0_CFAE40)
/* CF812C 802405BC AC2332D0 */  sw        $v1, %lo(D_802432D0_CFAE40)($at)
/* CF8130 802405C0 03E00008 */  jr        $ra
/* CF8134 802405C4 27BD0018 */   addiu    $sp, $sp, 0x18
