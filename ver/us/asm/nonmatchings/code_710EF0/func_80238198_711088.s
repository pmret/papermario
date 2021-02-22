.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238198_711088
/* 711088 80238198 3C03800E */  lui       $v1, %hi(gBattleStatus+0xD8)
/* 71108C 8023819C 8C63C148 */  lw        $v1, %lo(gBattleStatus+0xD8)($v1)
/* 711090 802381A0 90620210 */  lbu       $v0, 0x210($v1)
/* 711094 802381A4 80630214 */  lb        $v1, 0x214($v1)
/* 711098 802381A8 2442FFFD */  addiu     $v0, $v0, -3
/* 71109C 802381AC 2C450006 */  sltiu     $a1, $v0, 6
/* 7110A0 802381B0 2402000C */  addiu     $v0, $zero, 0xc
/* 7110A4 802381B4 50620001 */  beql      $v1, $v0, .L802381BC
/* 7110A8 802381B8 24050001 */   addiu    $a1, $zero, 1
.L802381BC:
/* 7110AC 802381BC AC850084 */  sw        $a1, 0x84($a0)
/* 7110B0 802381C0 03E00008 */  jr        $ra
/* 7110B4 802381C4 24020002 */   addiu    $v0, $zero, 2
