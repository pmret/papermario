.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80266E14
/* 1956F4 80266E14 8C820094 */  lw        $v0, 0x94($a0)
/* 1956F8 80266E18 10400007 */  beqz      $v0, .L80266E38
/* 1956FC 80266E1C 00000000 */   nop      
/* 195700 80266E20 8C820000 */  lw        $v0, ($a0)
/* 195704 80266E24 30420002 */  andi      $v0, $v0, 2
/* 195708 80266E28 14400003 */  bnez      $v0, .L80266E38
/* 19570C 80266E2C 00000000 */   nop      
/* 195710 80266E30 8C8200C0 */  lw        $v0, 0xc0($a0)
/* 195714 80266E34 A04006C0 */  sb        $zero, 0x6c0($v0)
.L80266E38:
/* 195718 80266E38 03E00008 */  jr        $ra
/* 19571C 80266E3C 00000000 */   nop      
