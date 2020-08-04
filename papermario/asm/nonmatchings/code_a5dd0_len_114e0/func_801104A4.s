.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_801104A4
/* 0A6BA4 801104A4 27BDFF48 */  addiu $sp, $sp, -0xb8
/* 0A6BA8 801104A8 F7B400A8 */  sdc1  $f20, 0xa8($sp)
/* 0A6BAC 801104AC 4480A000 */  mtc1  $zero, $f20
/* 0A6BB0 801104B0 AFB1009C */  sw    $s1, 0x9c($sp)
/* 0A6BB4 801104B4 0080882D */  daddu $s1, $a0, $zero
/* 0A6BB8 801104B8 AFBF00A0 */  sw    $ra, 0xa0($sp)
/* 0A6BBC 801104BC AFB00098 */  sw    $s0, 0x98($sp)
/* 0A6BC0 801104C0 F7B600B0 */  sdc1  $f22, 0xb0($sp)
/* 0A6BC4 801104C4 C6200064 */  lwc1  $f0, 0x64($s1)
/* 0A6BC8 801104C8 3C013F80 */  lui   $at, 0x3f80
/* 0A6BCC 801104CC 4481B000 */  mtc1  $at, $f22
/* 0A6BD0 801104D0 46000007 */  neg.s $f0, $f0
/* 0A6BD4 801104D4 4406A000 */  mfc1  $a2, $f20
/* 0A6BD8 801104D8 4407B000 */  mfc1  $a3, $f22
/* 0A6BDC 801104DC 44050000 */  mfc1  $a1, $f0
/* 0A6BE0 801104E0 27A40018 */  addiu $a0, $sp, 0x18
/* 0A6BE4 801104E4 0C019EC8 */  jal   guRotateF
/* 0A6BE8 801104E8 E7B40010 */   swc1  $f20, 0x10($sp)
/* 0A6BEC 801104EC 27B00058 */  addiu $s0, $sp, 0x58
/* 0A6BF0 801104F0 4406A000 */  mfc1  $a2, $f20
/* 0A6BF4 801104F4 C6200068 */  lwc1  $f0, 0x68($s1)
/* 0A6BF8 801104F8 4407A000 */  mfc1  $a3, $f20
/* 0A6BFC 801104FC 46000007 */  neg.s $f0, $f0
/* 0A6C00 80110500 44050000 */  mfc1  $a1, $f0
/* 0A6C04 80110504 0200202D */  daddu $a0, $s0, $zero
/* 0A6C08 80110508 0C019EC8 */  jal   guRotateF
/* 0A6C0C 8011050C E7B60010 */   swc1  $f22, 0x10($sp)
/* 0A6C10 80110510 27A40018 */  addiu $a0, $sp, 0x18
/* 0A6C14 80110514 0200282D */  daddu $a1, $s0, $zero
/* 0A6C18 80110518 0C019D80 */  jal   guMtxCatF
/* 0A6C1C 8011051C 0080302D */   daddu $a2, $a0, $zero
/* 0A6C20 80110520 4406B000 */  mfc1  $a2, $f22
/* 0A6C24 80110524 C6200060 */  lwc1  $f0, 0x60($s1)
/* 0A6C28 80110528 4407A000 */  mfc1  $a3, $f20
/* 0A6C2C 8011052C 46000007 */  neg.s $f0, $f0
/* 0A6C30 80110530 44050000 */  mfc1  $a1, $f0
/* 0A6C34 80110534 0200202D */  daddu $a0, $s0, $zero
/* 0A6C38 80110538 0C019EC8 */  jal   guRotateF
/* 0A6C3C 8011053C AFA70010 */   sw    $a3, 0x10($sp)
/* 0A6C40 80110540 27A40018 */  addiu $a0, $sp, 0x18
/* 0A6C44 80110544 0200282D */  daddu $a1, $s0, $zero
/* 0A6C48 80110548 0C019D80 */  jal   guMtxCatF
/* 0A6C4C 8011054C 26260070 */   addiu $a2, $s1, 0x70
/* 0A6C50 80110550 8622000C */  lh    $v0, 0xc($s1)
/* 0A6C54 80110554 00420018 */  mult  $v0, $v0
/* 0A6C58 80110558 00001812 */  mflo  $v1
/* 0A6C5C 8011055C 86220010 */  lh    $v0, 0x10($s1)
/* 0A6C60 80110560 00000000 */  nop   
/* 0A6C64 80110564 00420018 */  mult  $v0, $v0
/* 0A6C68 80110568 00004812 */  mflo  $t1
/* 0A6C6C 8011056C 8622000E */  lh    $v0, 0xe($s1)
/* 0A6C70 80110570 00000000 */  nop   
/* 0A6C74 80110574 00420018 */  mult  $v0, $v0
/* 0A6C78 80110578 3C013E80 */  lui   $at, 0x3e80
/* 0A6C7C 8011057C 44811000 */  mtc1  $at, $f2
/* 0A6C80 80110580 00691021 */  addu  $v0, $v1, $t1
/* 0A6C84 80110584 44820000 */  mtc1  $v0, $f0
/* 0A6C88 80110588 00000000 */  nop   
/* 0A6C8C 8011058C 46800020 */  cvt.s.w $f0, $f0
/* 0A6C90 80110590 46020002 */  mul.s $f0, $f0, $f2
/* 0A6C94 80110594 00000000 */  nop   
/* 0A6C98 80110598 00002012 */  mflo  $a0
/* 0A6C9C 8011059C 44841000 */  mtc1  $a0, $f2
/* 0A6CA0 801105A0 00000000 */  nop   
/* 0A6CA4 801105A4 468010A0 */  cvt.s.w $f2, $f2
/* 0A6CA8 801105A8 46020300 */  add.s $f12, $f0, $f2
/* 0A6CAC 801105AC 46006004 */  sqrt.s $f0, $f12
/* 0A6CB0 801105B0 46000032 */  c.eq.s $f0, $f0
/* 0A6CB4 801105B4 00000000 */  nop   
/* 0A6CB8 801105B8 45030004 */  bc1tl .L801105CC
/* 0A6CBC 801105BC E62000B0 */   swc1  $f0, 0xb0($s1)
/* 0A6CC0 801105C0 0C0187BC */  jal   sqrtf
/* 0A6CC4 801105C4 00000000 */   nop   
/* 0A6CC8 801105C8 E62000B0 */  swc1  $f0, 0xb0($s1)
.L801105CC:
/* 0A6CCC 801105CC 8FBF00A0 */  lw    $ra, 0xa0($sp)
/* 0A6CD0 801105D0 8FB1009C */  lw    $s1, 0x9c($sp)
/* 0A6CD4 801105D4 8FB00098 */  lw    $s0, 0x98($sp)
/* 0A6CD8 801105D8 D7B600B0 */  ldc1  $f22, 0xb0($sp)
/* 0A6CDC 801105DC D7B400A8 */  ldc1  $f20, 0xa8($sp)
/* 0A6CE0 801105E0 03E00008 */  jr    $ra
/* 0A6CE4 801105E4 27BD00B8 */   addiu $sp, $sp, 0xb8

