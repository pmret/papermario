.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80052614
/* 02DA14 80052614 0000282D */  daddu $a1, $zero, $zero
/* 02DA18 80052618 24060080 */  addiu $a2, $zero, 0x80
/* 02DA1C 8005261C 24031320 */  addiu $v1, $zero, 0x1320
.L80052620:
/* 02DA20 80052620 00831021 */  addu  $v0, $a0, $v1
/* 02DA24 80052624 24A50001 */  addiu $a1, $a1, 1
/* 02DA28 80052628 AC40001C */  sw    $zero, 0x1c($v0)
/* 02DA2C 8005262C AC400020 */  sw    $zero, 0x20($v0)
/* 02DA30 80052630 AC400024 */  sw    $zero, 0x24($v0)
/* 02DA34 80052634 AC400028 */  sw    $zero, 0x28($v0)
/* 02DA38 80052638 A040003B */  sb    $zero, 0x3b($v0)
/* 02DA3C 8005263C A040003C */  sb    $zero, 0x3c($v0)
/* 02DA40 80052640 A040003D */  sb    $zero, 0x3d($v0)
/* 02DA44 80052644 A040003E */  sb    $zero, 0x3e($v0)
/* 02DA48 80052648 A046003F */  sb    $a2, 0x3f($v0)
/* 02DA4C 8005264C 28A20018 */  slti  $v0, $a1, 0x18
/* 02DA50 80052650 1440FFF3 */  bnez  $v0, .L80052620
/* 02DA54 80052654 24630048 */   addiu $v1, $v1, 0x48
/* 02DA58 80052658 03E00008 */  jr    $ra
/* 02DA5C 8005265C 00000000 */   nop   

