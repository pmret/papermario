.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel spr_get_player_palettes
/* 1011B0 802DE0C0 2484FFFF */  addiu     $a0, $a0, -1
/* 1011B4 802DE0C4 00042080 */  sll       $a0, $a0, 2
/* 1011B8 802DE0C8 3C02802E */  lui       $v0, %hi(spr_playerSprites)
/* 1011BC 802DE0CC 00441021 */  addu      $v0, $v0, $a0
/* 1011C0 802DE0D0 8C42F548 */  lw        $v0, %lo(spr_playerSprites)($v0)
/* 1011C4 802DE0D4 10400003 */  beqz      $v0, .L802DE0E4
/* 1011C8 802DE0D8 00000000 */   nop
/* 1011CC 802DE0DC 03E00008 */  jr        $ra
/* 1011D0 802DE0E0 8C420004 */   lw       $v0, 4($v0)
.L802DE0E4:
/* 1011D4 802DE0E4 03E00008 */  jr        $ra
/* 1011D8 802DE0E8 0000102D */   daddu    $v0, $zero, $zero
