.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050E84
/* 2C284 80050E84 00041100 */  sll       $v0, $a0, 4
/* 2C288 80050E88 00441023 */  subu      $v0, $v0, $a0
/* 2C28C 80050E8C 000210C0 */  sll       $v0, $v0, 3
/* 2C290 80050E90 00441021 */  addu      $v0, $v0, $a0
/* 2C294 80050E94 00021080 */  sll       $v0, $v0, 2
/* 2C298 80050E98 3C03800A */  lui       $v1, 0x800a
/* 2C29C 80050E9C 8C63A628 */  lw        $v1, -0x59d8($v1)
/* 2C2A0 80050EA0 24420024 */  addiu     $v0, $v0, 0x24
/* 2C2A4 80050EA4 00621821 */  addu      $v1, $v1, $v0
/* 2C2A8 80050EA8 8C620004 */  lw        $v0, 4($v1)
/* 2C2AC 80050EAC 1040000E */  beqz      $v0, .L80050EE8
/* 2C2B0 80050EB0 00000000 */   nop      
/* 2C2B4 80050EB4 8C620008 */  lw        $v0, 8($v1)
/* 2C2B8 80050EB8 1040000B */  beqz      $v0, .L80050EE8
/* 2C2BC 80050EBC 24020001 */   addiu    $v0, $zero, 1
/* 2C2C0 80050EC0 10A00003 */  beqz      $a1, .L80050ED0
/* 2C2C4 80050EC4 A0620024 */   sb       $v0, 0x24($v1)
/* 2C2C8 80050EC8 080143B6 */  j         .L80050ED8
/* 2C2CC 80050ECC A4650028 */   sh       $a1, 0x28($v1)
.L80050ED0:
/* 2C2D0 80050ED0 240200FA */  addiu     $v0, $zero, 0xfa
/* 2C2D4 80050ED4 A4620028 */  sh        $v0, 0x28($v1)
.L80050ED8:
/* 2C2D8 80050ED8 2402007F */  addiu     $v0, $zero, 0x7f
/* 2C2DC 80050EDC A060002A */  sb        $zero, 0x2a($v1)
/* 2C2E0 80050EE0 A062002B */  sb        $v0, 0x2b($v1)
/* 2C2E4 80050EE4 A0600026 */  sb        $zero, 0x26($v1)
.L80050EE8:
/* 2C2E8 80050EE8 03E00008 */  jr        $ra
/* 2C2EC 80050EEC 00000000 */   nop      
