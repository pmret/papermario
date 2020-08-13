.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024A454
.L8024A454:
/* 13D794 8024A454 3C038027 */  lui   $v1, 0x8027
/* 13D798 8024A458 8C6305D4 */  lw    $v1, 0x5d4($v1)
/* 13D79C 8024A45C 3C028027 */  lui   $v0, 0x8027
/* 13D7A0 8024A460 8C4205D8 */  lw    $v0, 0x5d8($v0)
/* 13D7A4 8024A464 1062000A */  beq   $v1, $v0, .L8024A490
/* 13D7A8 8024A468 24040021 */   addiu $a0, $zero, 0x21
/* 13D7AC 8024A46C 26050055 */  addiu $a1, $s0, 0x55
/* 13D7B0 8024A470 24C60017 */  addiu $a2, $a2, 0x17
/* 13D7B4 8024A474 8FAB00AC */  lw    $t3, 0xac($sp)
/* 13D7B8 8024A478 8FAA00B0 */  lw    $t2, 0xb0($sp)
/* 13D7BC 8024A47C 01652821 */  addu  $a1, $t3, $a1
/* 13D7C0 8024A480 0C090AEB */  jal   func_80242BAC
/* 13D7C4 8024A484 01463021 */   addu  $a2, $t2, $a2
/* 13D7C8 8024A488 0809292B */  j     func_8024A4AC
/* 13D7CC 8024A48C 00000000 */   nop   

.L8024A490:
/* 13D7D0 8024A490 26050055 */  addiu $a1, $s0, 0x55
/* 13D7D4 8024A494 24C60017 */  addiu $a2, $a2, 0x17
/* 13D7D8 8024A498 8FAB00AC */  lw    $t3, 0xac($sp)
/* 13D7DC 8024A49C 8FAA00B0 */  lw    $t2, 0xb0($sp)
/* 13D7E0 8024A4A0 01652821 */  addu  $a1, $t3, $a1
