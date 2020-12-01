.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050F64
/* 2C364 80050F64 00041100 */  sll       $v0, $a0, 4
/* 2C368 80050F68 00441023 */  subu      $v0, $v0, $a0
/* 2C36C 80050F6C 000210C0 */  sll       $v0, $v0, 3
/* 2C370 80050F70 00441021 */  addu      $v0, $v0, $a0
/* 2C374 80050F74 00021080 */  sll       $v0, $v0, 2
/* 2C378 80050F78 3C03800A */  lui       $v1, %hi(D_8009A628)
/* 2C37C 80050F7C 8C63A628 */  lw        $v1, %lo(D_8009A628)($v1)
/* 2C380 80050F80 24420024 */  addiu     $v0, $v0, 0x24
/* 2C384 80050F84 00621821 */  addu      $v1, $v1, $v0
/* 2C388 80050F88 8C620004 */  lw        $v0, 4($v1)
/* 2C38C 80050F8C 1040000E */  beqz      $v0, .L80050FC8
/* 2C390 80050F90 00000000 */   nop      
/* 2C394 80050F94 8C620008 */  lw        $v0, 8($v1)
/* 2C398 80050F98 1040000B */  beqz      $v0, .L80050FC8
/* 2C39C 80050F9C 00000000 */   nop      
/* 2C3A0 80050FA0 10A00003 */  beqz      $a1, .L80050FB0
/* 2C3A4 80050FA4 240200FA */   addiu    $v0, $zero, 0xfa
/* 2C3A8 80050FA8 080143ED */  j         .L80050FB4
/* 2C3AC 80050FAC A4650028 */   sh       $a1, 0x28($v1)
.L80050FB0:
/* 2C3B0 80050FB0 A4620028 */  sh        $v0, 0x28($v1)
.L80050FB4:
/* 2C3B4 80050FB4 240200FF */  addiu     $v0, $zero, 0xff
/* 2C3B8 80050FB8 A062002A */  sb        $v0, 0x2a($v1)
/* 2C3BC 80050FBC 24020001 */  addiu     $v0, $zero, 1
/* 2C3C0 80050FC0 A060002B */  sb        $zero, 0x2b($v1)
/* 2C3C4 80050FC4 A0620026 */  sb        $v0, 0x26($v1)
.L80050FC8:
/* 2C3C8 80050FC8 03E00008 */  jr        $ra
/* 2C3CC 80050FCC 00000000 */   nop      
