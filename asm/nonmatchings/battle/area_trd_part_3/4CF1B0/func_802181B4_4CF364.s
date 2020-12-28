.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802181B4_4CF364
/* 4CF364 802181B4 3C06800E */  lui       $a2, %hi(gBattleStatus)
/* 4CF368 802181B8 24C6C070 */  addiu     $a2, $a2, %lo(gBattleStatus)
/* 4CF36C 802181BC 10A00002 */  beqz      $a1, .L802181C8
/* 4CF370 802181C0 2402000A */   addiu    $v0, $zero, 0xa
/* 4CF374 802181C4 AC820070 */  sw        $v0, 0x70($a0)
.L802181C8:
/* 4CF378 802181C8 8CC20004 */  lw        $v0, 4($a2)
/* 4CF37C 802181CC 2403FFFB */  addiu     $v1, $zero, -5
/* 4CF380 802181D0 00431024 */  and       $v0, $v0, $v1
/* 4CF384 802181D4 ACC20004 */  sw        $v0, 4($a2)
/* 4CF388 802181D8 8C820070 */  lw        $v0, 0x70($a0)
/* 4CF38C 802181DC 14400003 */  bnez      $v0, .L802181EC
/* 4CF390 802181E0 2442FFFF */   addiu    $v0, $v0, -1
/* 4CF394 802181E4 03E00008 */  jr        $ra
/* 4CF398 802181E8 24020002 */   addiu    $v0, $zero, 2
.L802181EC:
/* 4CF39C 802181EC AC820070 */  sw        $v0, 0x70($a0)
/* 4CF3A0 802181F0 03E00008 */  jr        $ra
/* 4CF3A4 802181F4 0000102D */   daddu    $v0, $zero, $zero
