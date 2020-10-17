.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80260B70
/* 18F450 80260B70 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 18F454 80260B74 AFB1001C */  sw        $s1, 0x1c($sp)
/* 18F458 80260B78 0080882D */  daddu     $s1, $a0, $zero
/* 18F45C 80260B7C AFB00018 */  sw        $s0, 0x18($sp)
/* 18F460 80260B80 3C10800E */  lui       $s0, 0x800e
/* 18F464 80260B84 8E10C148 */  lw        $s0, -0x3eb8($s0)
/* 18F468 80260B88 3C0141A0 */  lui       $at, 0x41a0
/* 18F46C 80260B8C 44811000 */  mtc1      $at, $f2
/* 18F470 80260B90 24040002 */  addiu     $a0, $zero, 2
/* 18F474 80260B94 AFBF0020 */  sw        $ra, 0x20($sp)
/* 18F478 80260B98 C6040148 */  lwc1      $f4, 0x148($s0)
/* 18F47C 80260B9C C600014C */  lwc1      $f0, 0x14c($s0)
/* 18F480 80260BA0 46022100 */  add.s     $f4, $f4, $f2
/* 18F484 80260BA4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 18F488 80260BA8 8E060144 */  lw        $a2, 0x144($s0)
/* 18F48C 80260BAC 44072000 */  mfc1      $a3, $f4
/* 18F490 80260BB0 0C0999FC */  jal       func_802667F0
/* 18F494 80260BB4 0200282D */   daddu    $a1, $s0, $zero
/* 18F498 80260BB8 0C05272D */  jal       play_sound
/* 18F49C 80260BBC 240403FC */   addiu    $a0, $zero, 0x3fc
/* 18F4A0 80260BC0 AE200084 */  sw        $zero, 0x84($s1)
/* 18F4A4 80260BC4 92020210 */  lbu       $v0, 0x210($s0)
/* 18F4A8 80260BC8 2442FFFD */  addiu     $v0, $v0, -3
/* 18F4AC 80260BCC 2C420006 */  sltiu     $v0, $v0, 6
/* 18F4B0 80260BD0 10400002 */  beqz      $v0, .L80260BDC
/* 18F4B4 80260BD4 24020001 */   addiu    $v0, $zero, 1
/* 18F4B8 80260BD8 AE220084 */  sw        $v0, 0x84($s1)
.L80260BDC:
/* 18F4BC 80260BDC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 18F4C0 80260BE0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 18F4C4 80260BE4 8FB00018 */  lw        $s0, 0x18($sp)
/* 18F4C8 80260BE8 24020002 */  addiu     $v0, $zero, 2
/* 18F4CC 80260BEC 03E00008 */  jr        $ra
/* 18F4D0 80260BF0 27BD0028 */   addiu    $sp, $sp, 0x28
