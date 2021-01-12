.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026709C
/* 19597C 8026709C 8C820094 */  lw        $v0, 0x94($a0)
/* 195980 802670A0 10400007 */  beqz      $v0, .L802670C0
/* 195984 802670A4 00000000 */   nop
/* 195988 802670A8 8C820000 */  lw        $v0, ($a0)
/* 19598C 802670AC 30420002 */  andi      $v0, $v0, 2
/* 195990 802670B0 14400003 */  bnez      $v0, .L802670C0
/* 195994 802670B4 00000000 */   nop
/* 195998 802670B8 8C8200C0 */  lw        $v0, 0xc0($a0)
/* 19599C 802670BC A0400764 */  sb        $zero, 0x764($v0)
.L802670C0:
/* 1959A0 802670C0 03E00008 */  jr        $ra
/* 1959A4 802670C4 00000000 */   nop
