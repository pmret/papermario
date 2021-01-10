.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8023808C_710F7C
/* 710F7C 8023808C 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 710F80 80238090 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 710F84 80238094 8C8200D8 */  lw        $v0, 0xd8($a0)
/* 710F88 80238098 8C4501F4 */  lw        $a1, 0x1f4($v0)
/* 710F8C 8023809C 8C820004 */  lw        $v0, 4($a0)
/* 710F90 802380A0 24030001 */  addiu     $v1, $zero, 1
/* 710F94 802380A4 30420002 */  andi      $v0, $v0, 2
/* 710F98 802380A8 14400003 */  bnez      $v0, .L802380B8
/* 710F9C 802380AC A083009A */   sb       $v1, 0x9a($a0)
/* 710FA0 802380B0 2402FFFF */  addiu     $v0, $zero, -1
/* 710FA4 802380B4 A082009A */  sb        $v0, 0x9a($a0)
.L802380B8:
/* 710FA8 802380B8 3C02FBFF */  lui       $v0, 0xfbff
/* 710FAC 802380BC 3C038028 */  lui       $v1, %hi(D_80283370)
/* 710FB0 802380C0 24633370 */  addiu     $v1, $v1, %lo(D_80283370)
/* 710FB4 802380C4 ACA30094 */  sw        $v1, 0x94($a1)
/* 710FB8 802380C8 8C830000 */  lw        $v1, ($a0)
/* 710FBC 802380CC 3442FFFF */  ori       $v0, $v0, 0xffff
/* 710FC0 802380D0 A080008B */  sb        $zero, 0x8b($a0)
/* 710FC4 802380D4 00621824 */  and       $v1, $v1, $v0
/* 710FC8 802380D8 24020002 */  addiu     $v0, $zero, 2
/* 710FCC 802380DC 03E00008 */  jr        $ra
/* 710FD0 802380E0 AC830000 */   sw       $v1, ($a0)
