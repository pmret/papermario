.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel UpdateLerp
/* 0F8FDC 802D462C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F8FE0 802D4630 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F8FE4 802D4634 0080802D */  daddu $s0, $a0, $zero
/* 0F8FE8 802D4638 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F8FEC 802D463C C60200B4 */  lwc1  $f2, 0xb4($s0)
/* 0F8FF0 802D4640 468010A0 */  cvt.s.w $f2, $f2
/* 0F8FF4 802D4644 C60000B8 */  lwc1  $f0, 0xb8($s0)
/* 0F8FF8 802D4648 46800020 */  cvt.s.w $f0, $f0
/* 0F8FFC 802D464C 8E0200C0 */  lw    $v0, 0xc0($s0)
/* 0F9000 802D4650 44051000 */  mfc1  $a1, $f2
/* 0F9004 802D4654 44060000 */  mfc1  $a2, $f0
/* 0F9008 802D4658 AFA20010 */  sw    $v0, 0x10($sp)
/* 0F900C 802D465C 8E0400B0 */  lw    $a0, 0xb0($s0)
/* 0F9010 802D4660 0C00A8ED */  jal   update_lerp
/* 0F9014 802D4664 8E0700BC */   lw    $a3, 0xbc($s0)
/* 0F9018 802D4668 8E0200BC */  lw    $v0, 0xbc($s0)
/* 0F901C 802D466C 8E0300C0 */  lw    $v1, 0xc0($s0)
/* 0F9020 802D4670 4600010D */  trunc.w.s $f4, $f0
/* 0F9024 802D4674 E6040084 */  swc1  $f4, 0x84($s0)
/* 0F9028 802D4678 0043102A */  slt   $v0, $v0, $v1
/* 0F902C 802D467C 14400003 */  bnez  $v0, .L802D468C
/* 0F9030 802D4680 24020001 */   addiu $v0, $zero, 1
/* 0F9034 802D4684 080B51A4 */  j     .L802D4690
/* 0F9038 802D4688 AE000088 */   sw    $zero, 0x88($s0)

.L802D468C:
/* 0F903C 802D468C AE020088 */  sw    $v0, 0x88($s0)
.L802D4690:
/* 0F9040 802D4690 8E0200BC */  lw    $v0, 0xbc($s0)
/* 0F9044 802D4694 24420001 */  addiu $v0, $v0, 1
/* 0F9048 802D4698 AE0200BC */  sw    $v0, 0xbc($s0)
/* 0F904C 802D469C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F9050 802D46A0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F9054 802D46A4 24020002 */  addiu $v0, $zero, 2
/* 0F9058 802D46A8 03E00008 */  jr    $ra
/* 0F905C 802D46AC 27BD0020 */   addiu $sp, $sp, 0x20

