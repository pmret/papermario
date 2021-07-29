.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003A7AC
/* 15BAC 8003A7AC 0000282D */  daddu     $a1, $zero, $zero
/* 15BB0 8003A7B0 3C06800A */  lui       $a2, %hi(D_8009E9A0)
/* 15BB4 8003A7B4 8CC6E9A0 */  lw        $a2, %lo(D_8009E9A0)($a2)
.L8003A7B8:
/* 15BB8 8003A7B8 8CC30000 */  lw        $v1, ($a2)
/* 15BBC 8003A7BC 50600008 */  beql      $v1, $zero, .L8003A7E0
/* 15BC0 8003A7C0 24A50001 */   addiu    $a1, $a1, 1
/* 15BC4 8003A7C4 8C620000 */  lw        $v0, ($v1)
/* 15BC8 8003A7C8 50400005 */  beql      $v0, $zero, .L8003A7E0
/* 15BCC 8003A7CC 24A50001 */   addiu    $a1, $a1, 1
/* 15BD0 8003A7D0 806200A4 */  lb        $v0, 0xa4($v1)
/* 15BD4 8003A7D4 10440006 */  beq       $v0, $a0, .L8003A7F0
/* 15BD8 8003A7D8 28A20040 */   slti     $v0, $a1, 0x40
/* 15BDC 8003A7DC 24A50001 */  addiu     $a1, $a1, 1
.L8003A7E0:
/* 15BE0 8003A7E0 28A20040 */  slti      $v0, $a1, 0x40
/* 15BE4 8003A7E4 1440FFF4 */  bnez      $v0, .L8003A7B8
/* 15BE8 8003A7E8 24C60004 */   addiu    $a2, $a2, 4
/* 15BEC 8003A7EC 28A20040 */  slti      $v0, $a1, 0x40
.L8003A7F0:
/* 15BF0 8003A7F0 14400003 */  bnez      $v0, .L8003A800
/* 15BF4 8003A7F4 00000000 */   nop
.L8003A7F8:
/* 15BF8 8003A7F8 0800E9FE */  j         .L8003A7F8
/* 15BFC 8003A7FC 00000000 */   nop
.L8003A800:
/* 15C00 8003A800 03E00008 */  jr        $ra
/* 15C04 8003A804 0060102D */   daddu    $v0, $v1, $zero
