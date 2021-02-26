.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D790
/* 28B90 8004D790 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 28B94 8004D794 AFB00010 */  sw        $s0, 0x10($sp)
/* 28B98 8004D798 0080802D */  daddu     $s0, $a0, $zero
/* 28B9C 8004D79C 12000009 */  beqz      $s0, .L8004D7C4
/* 28BA0 8004D7A0 AFBF0014 */   sw       $ra, 0x14($sp)
/* 28BA4 8004D7A4 0C013511 */  jal       func_8004D444
/* 28BA8 8004D7A8 00000000 */   nop
/* 28BAC 8004D7AC 50400006 */  beql      $v0, $zero, .L8004D7C8
/* 28BB0 8004D7B0 24020002 */   addiu    $v0, $zero, 2
/* 28BB4 8004D7B4 8C42001C */  lw        $v0, 0x1c($v0)
/* 28BB8 8004D7B8 02021026 */  xor       $v0, $s0, $v0
/* 28BBC 8004D7BC 080135F2 */  j         .L8004D7C8
/* 28BC0 8004D7C0 2C420001 */   sltiu    $v0, $v0, 1
.L8004D7C4:
/* 28BC4 8004D7C4 24020003 */  addiu     $v0, $zero, 3
.L8004D7C8:
/* 28BC8 8004D7C8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 28BCC 8004D7CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 28BD0 8004D7D0 03E00008 */  jr        $ra
/* 28BD4 8004D7D4 27BD0018 */   addiu    $sp, $sp, 0x18
