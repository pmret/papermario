.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80249B30
/* 13CE70 80249B30 3C04ED00 */  lui   $a0, 0xed00
/* 13CE74 80249B34 AFA00054 */  sw    $zero, 0x54($sp)
/* 13CE78 80249B38 AFA00050 */  sw    $zero, 0x50($sp)
/* 13CE7C 80249B3C 254A0077 */  addiu $t2, $t2, 0x77
/* 13CE80 80249B40 46041082 */  mul.s $f2, $f2, $f4
/* 13CE84 80249B44 00000000 */  nop   
/* 13CE88 80249B48 256B0011 */  addiu $t3, $t3, 0x11
/* 13CE8C 80249B4C AFAA006C */  sw    $t2, 0x6c($sp)
/* 13CE90 80249B50 AFAB0070 */  sw    $t3, 0x70($sp)
/* 13CE94 80249B54 8C620000 */  lw    $v0, ($v1)
/* 13CE98 80249B58 46040002 */  mul.s $f0, $f0, $f4
/* 13CE9C 80249B5C 00000000 */  nop   
/* 13CEA0 80249B60 0040282D */  daddu $a1, $v0, $zero
/* 13CEA4 80249B64 24420008 */  addiu $v0, $v0, 8
/* 13CEA8 80249B68 AC620000 */  sw    $v0, ($v1)
/* 13CEAC 80249B6C 4600118D */  trunc.w.s $f6, $f2
/* 13CEB0 80249B70 44023000 */  mfc1  $v0, $f6
/* 13CEB4 80249B74 00000000 */  nop   
/* 13CEB8 80249B78 30420FFF */  andi  $v0, $v0, 0xfff
/* 13CEBC 80249B7C 00021300 */  sll   $v0, $v0, 0xc
/* 13CEC0 80249B80 4600018D */  trunc.w.s $f6, $f0
/* 13CEC4 80249B84 44033000 */  mfc1  $v1, $f6
/* 13CEC8 80249B88 44871000 */  mtc1  $a3, $f2
/* 13CECC 80249B8C 00000000 */  nop   
/* 13CED0 80249B90 468010A0 */  cvt.s.w $f2, $f2
/* 13CED4 80249B94 46041082 */  mul.s $f2, $f2, $f4
/* 13CED8 80249B98 00000000 */  nop   
/* 13CEDC 80249B9C 30630FFF */  andi  $v1, $v1, 0xfff
/* 13CEE0 80249BA0 00641825 */  or    $v1, $v1, $a0
/* 13CEE4 80249BA4 00431025 */  or    $v0, $v0, $v1
/* 13CEE8 80249BA8 44880000 */  mtc1  $t0, $f0
/* 13CEEC 80249BAC 00000000 */  nop   
/* 13CEF0 80249BB0 46800020 */  cvt.s.w $f0, $f0
/* 13CEF4 80249BB4 46040002 */  mul.s $f0, $f0, $f4
/* 13CEF8 80249BB8 00000000 */  nop   
/* 13CEFC 80249BBC ACA20000 */  sw    $v0, ($a1)
/* 13CF00 80249BC0 4600118D */  trunc.w.s $f6, $f2
/* 13CF04 80249BC4 44023000 */  mfc1  $v0, $f6
/* 13CF08 80249BC8 00000000 */  nop   
/* 13CF0C 80249BCC 30420FFF */  andi  $v0, $v0, 0xfff
/* 13CF10 80249BD0 00021300 */  sll   $v0, $v0, 0xc
/* 13CF14 80249BD4 4600018D */  trunc.w.s $f6, $f0
/* 13CF18 80249BD8 44033000 */  mfc1  $v1, $f6
/* 13CF1C 80249BDC 00000000 */  nop   
/* 13CF20 80249BE0 30630FFF */  andi  $v1, $v1, 0xfff
/* 13CF24 80249BE4 00431025 */  or    $v0, $v0, $v1
/* 13CF28 80249BE8 ACA20004 */  sw    $v0, 4($a1)
.L80249BEC:
/* 13CF2C 80249BEC 0000F02D */  daddu $fp, $zero, $zero
/* 13CF30 80249BF0 3C0B8027 */  lui   $t3, 0x8027
/* 13CF34 80249BF4 256B04D0 */  addiu $t3, $t3, 0x4d0
/* 13CF38 80249BF8 AFAB007C */  sw    $t3, 0x7c($sp)
.L80249BFC:
/* 13CF3C 80249BFC 8FAA007C */  lw    $t2, 0x7c($sp)
/* 13CF40 80249C00 91420000 */  lbu   $v0, ($t2)
/* 13CF44 80249C04 104000E2 */  beqz  $v0, .L80249F90
/* 13CF48 80249C08 00000000 */   nop   
/* 13CF4C 80249C0C 03C0202D */  daddu $a0, $fp, $zero
/* 13CF50 80249C10 0C09260A */  jal   func_80249828
/* 13CF54 80249C14 0000282D */   daddu $a1, $zero, $zero
/* 13CF58 80249C18 8FAB007C */  lw    $t3, 0x7c($sp)
/* 13CF5C 80249C1C 8D620008 */  lw    $v0, 8($t3)
/* 13CF60 80249C20 184000D5 */  blez  $v0, .L80249F78
/* 13CF64 80249C24 0000902D */   daddu $s2, $zero, $zero
/* 13CF68 80249C28 8FAA0054 */  lw    $t2, 0x54($sp)
/* 13CF6C 80249C2C 3C0B8027 */  lui   $t3, 0x8027
/* 13CF70 80249C30 256B05E8 */  addiu $t3, $t3, 0x5e8
/* 13CF74 80249C34 000A1080 */  sll   $v0, $t2, 2
/* 13CF78 80249C38 004B5821 */  addu  $t3, $v0, $t3
/* 13CF7C 80249C3C AFAB0078 */  sw    $t3, 0x78($sp)
.L80249C40:
/* 13CF80 80249C40 8FAA007C */  lw    $t2, 0x7c($sp)
/* 13CF84 80249C44 3C0B8027 */  lui   $t3, 0x8027
/* 13CF88 80249C48 256B0400 */  addiu $t3, $t3, 0x400
/* 13CF8C 80249C4C 8D420004 */  lw    $v0, 4($t2)
/* 13CF90 80249C50 24037FFF */  addiu $v1, $zero, 0x7fff
/* 13CF94 80249C54 00521021 */  addu  $v0, $v0, $s2
/* 13CF98 80249C58 00021040 */  sll   $v0, $v0, 1
/* 13CF9C 80249C5C 004B1021 */  addu  $v0, $v0, $t3
/* 13CFA0 80249C60 84500000 */  lh    $s0, ($v0)
/* 13CFA4 80249C64 94560000 */  lhu   $s6, ($v0)
/* 13CFA8 80249C68 120300BD */  beq   $s0, $v1, .L80249F60
/* 13CFAC 80249C6C 0000982D */   daddu $s3, $zero, $zero
/* 13CFB0 80249C70 03C0202D */  daddu $a0, $fp, $zero
/* 13CFB4 80249C74 0C0925F4 */  jal   func_802497D0
/* 13CFB8 80249C78 0240282D */   daddu $a1, $s2, $zero
/* 13CFBC 80249C7C 03C0202D */  daddu $a0, $fp, $zero
/* 13CFC0 80249C80 0240282D */  daddu $a1, $s2, $zero
/* 13CFC4 80249C84 0C09260A */  jal   func_80249828
/* 13CFC8 80249C88 AFA20068 */   sw    $v0, 0x68($sp)
/* 13CFCC 80249C8C 0040B82D */  daddu $s7, $v0, $zero
/* 13CFD0 80249C90 3A027FFE */  xori  $v0, $s0, 0x7ffe
