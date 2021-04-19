.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DEA40
/* 101B30 802DEA40 00042080 */  sll       $a0, $a0, 2
/* 101B34 802DEA44 3C02802E */  lui       $v0, %hi(spr_npcSprites)
/* 101B38 802DEA48 00441021 */  addu      $v0, $v0, $a0
/* 101B3C 802DEA4C 8C42F5B0 */  lw        $v0, %lo(spr_npcSprites)($v0)
/* 101B40 802DEA50 14400003 */  bnez      $v0, .L802DEA60
/* 101B44 802DEA54 00000000 */   nop
/* 101B48 802DEA58 03E00008 */  jr        $ra
/* 101B4C 802DEA5C 0000102D */   daddu    $v0, $zero, $zero
.L802DEA60:
/* 101B50 802DEA60 8C420004 */  lw        $v0, 4($v0)
/* 101B54 802DEA64 03E00008 */  jr        $ra
/* 101B58 802DEA68 00000000 */   nop
