.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050C14
/* 2C014 80050C14 00041100 */  sll       $v0, $a0, 4
/* 2C018 80050C18 00441023 */  subu      $v0, $v0, $a0
/* 2C01C 80050C1C 000210C0 */  sll       $v0, $v0, 3
/* 2C020 80050C20 00441021 */  addu      $v0, $v0, $a0
/* 2C024 80050C24 00021080 */  sll       $v0, $v0, 2
/* 2C028 80050C28 3C03800A */  lui       $v1, %hi(D_8009A608)
/* 2C02C 80050C2C 8C63A608 */  lw        $v1, %lo(D_8009A608)($v1)
/* 2C030 80050C30 24420024 */  addiu     $v0, $v0, 0x24
/* 2C034 80050C34 00621821 */  addu      $v1, $v1, $v0
/* 2C038 80050C38 8C620004 */  lw        $v0, 4($v1)
/* 2C03C 80050C3C 1040000E */  beqz      $v0, .L80050C78
/* 2C040 80050C40 00000000 */   nop
/* 2C044 80050C44 8C620008 */  lw        $v0, 8($v1)
/* 2C048 80050C48 1040000B */  beqz      $v0, .L80050C78
/* 2C04C 80050C4C 00000000 */   nop
/* 2C050 80050C50 10A00003 */  beqz      $a1, .L80050C60
/* 2C054 80050C54 240200FA */   addiu    $v0, $zero, 0xfa
/* 2C058 80050C58 08014319 */  j         .L80050C64
/* 2C05C 80050C5C A4650028 */   sh       $a1, 0x28($v1)
.L80050C60:
/* 2C060 80050C60 A4620028 */  sh        $v0, 0x28($v1)
.L80050C64:
/* 2C064 80050C64 240200FF */  addiu     $v0, $zero, 0xff
/* 2C068 80050C68 A062002A */  sb        $v0, 0x2a($v1)
/* 2C06C 80050C6C 24020001 */  addiu     $v0, $zero, 1
/* 2C070 80050C70 A060002B */  sb        $zero, 0x2b($v1)
/* 2C074 80050C74 A0620026 */  sb        $v0, 0x26($v1)
.L80050C78:
/* 2C078 80050C78 03E00008 */  jr        $ra
/* 2C07C 80050C7C 00000000 */   nop
