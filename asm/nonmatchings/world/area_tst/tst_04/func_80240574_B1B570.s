.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240574_B1BAE4
/* B1BAE4 80240574 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B1BAE8 80240578 AFBF0010 */  sw        $ra, 0x10($sp)
/* B1BAEC 8024057C 0C00EAD2 */  jal       get_npc_safe
/* B1BAF0 80240580 2404FFFC */   addiu    $a0, $zero, -4
/* B1BAF4 80240584 0040202D */  daddu     $a0, $v0, $zero
/* B1BAF8 80240588 10800006 */  beqz      $a0, .L802405A4
/* B1BAFC 8024058C 3C030002 */   lui      $v1, 2
/* B1BB00 80240590 8C820000 */  lw        $v0, ($a0)
/* B1BB04 80240594 00431025 */  or        $v0, $v0, $v1
/* B1BB08 80240598 3C030008 */  lui       $v1, 8
/* B1BB0C 8024059C 00431025 */  or        $v0, $v0, $v1
/* B1BB10 802405A0 AC820000 */  sw        $v0, ($a0)
.L802405A4:
/* B1BB14 802405A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* B1BB18 802405A8 03E00008 */  jr        $ra
/* B1BB1C 802405AC 27BD0018 */   addiu    $sp, $sp, 0x18
