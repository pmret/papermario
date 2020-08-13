.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024A960
/* 13DCA0 8024A960 10400011 */  beqz  $v0, .L8024A9A8
/* 13DCA4 8024A964 2462FFFF */   addiu $v0, $v1, -1
/* 13DCA8 8024A968 08092A6A */  j     func_8024A9A8
/* 13DCAC 8024A96C AC820000 */   sw    $v0, ($a0)

.L8024A970:
/* 13DCB0 8024A970 3C038027 */  lui   $v1, 0x8027
/* 13DCB4 8024A974 246304C8 */  addiu $v1, $v1, 0x4c8
/* 13DCB8 8024A978 8C620000 */  lw    $v0, ($v1)
/* 13DCBC 8024A97C 2442FFFF */  addiu $v0, $v0, -1
/* 13DCC0 8024A980 04410002 */  bgez  $v0, .L8024A98C
/* 13DCC4 8024A984 AC620000 */   sw    $v0, ($v1)
/* 13DCC8 8024A988 AC600000 */  sw    $zero, ($v1)
.L8024A98C:
/* 13DCCC 8024A98C 8C630000 */  lw    $v1, ($v1)
/* 13DCD0 8024A990 00031040 */  sll   $v0, $v1, 1
/* 13DCD4 8024A994 00431021 */  addu  $v0, $v0, $v1
/* 13DCD8 8024A998 00021080 */  sll   $v0, $v0, 2
/* 13DCDC 8024A99C 3C058027 */  lui   $a1, 0x8027
/* 13DCE0 8024A9A0 00A22821 */  addu  $a1, $a1, $v0
/* 13DCE4 8024A9A4 90A504D1 */  lbu   $a1, 0x4d1($a1)
