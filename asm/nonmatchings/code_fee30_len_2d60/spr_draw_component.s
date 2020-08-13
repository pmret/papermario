.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel spr_draw_component
/* 0FFFCC 802DCEDC 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0FFFD0 802DCEE0 AFB30054 */  sw    $s3, 0x54($sp)
/* 0FFFD4 802DCEE4 0080982D */  daddu $s3, $a0, $zero
/* 0FFFD8 802DCEE8 AFB1004C */  sw    $s1, 0x4c($sp)
/* 0FFFDC 802DCEEC 00A0882D */  daddu $s1, $a1, $zero
/* 0FFFE0 802DCEF0 00C0402D */  daddu $t0, $a2, $zero
/* 0FFFE4 802DCEF4 AFBF0058 */  sw    $ra, 0x58($sp)
/* 0FFFE8 802DCEF8 AFB20050 */  sw    $s2, 0x50($sp)
/* 0FFFEC 802DCEFC AFB00048 */  sw    $s0, 0x48($sp)
/* 0FFFF0 802DCF00 F7B80070 */  sdc1  $f24, 0x70($sp)
/* 0FFFF4 802DCF04 F7B60068 */  sdc1  $f22, 0x68($sp)
/* 0FFFF8 802DCF08 F7B40060 */  sdc1  $f20, 0x60($sp)
/* 0FFFFC 802DCF0C 8E220000 */  lw    $v0, ($s1)
/* 100000 802DCF10 10400068 */  beqz  $v0, .L802DD0B4
/* 100004 802DCF14 00E0802D */   daddu $s0, $a3, $zero
/* 100008 802DCF18 8E230014 */  lw    $v1, 0x14($s1)
/* 10000C 802DCF1C 2402FFFF */  addiu $v0, $zero, -1
/* 100010 802DCF20 10620064 */  beq   $v1, $v0, .L802DD0B4
/* 100014 802DCF24 00000000 */   nop   
/* 100018 802DCF28 3C02802E */  lui   $v0, 0x802e
/* 10001C 802DCF2C 2442FEA0 */  addiu $v0, $v0, -0x160
/* 100020 802DCF30 C4540000 */  lwc1  $f20, ($v0)
/* 100024 802DCF34 4680A520 */  cvt.s.w $f20, $f20
/* 100028 802DCF38 4600A20D */  trunc.w.s $f8, $f20
/* 10002C 802DCF3C 44044000 */  mfc1  $a0, $f8
/* 100030 802DCF40 C4560004 */  lwc1  $f22, 4($v0)
/* 100034 802DCF44 4680B5A0 */  cvt.s.w $f22, $f22
/* 100038 802DCF48 4600B20D */  trunc.w.s $f8, $f22
/* 10003C 802DCF4C 44054000 */  mfc1  $a1, $f8
/* 100040 802DCF50 C4580008 */  lwc1  $f24, 8($v0)
/* 100044 802DCF54 4680C620 */  cvt.s.w $f24, $f24
/* 100048 802DCF58 4600C20D */  trunc.w.s $f8, $f24
/* 10004C 802DCF5C 44064000 */  mfc1  $a2, $f8
/* 100050 802DCF60 8502000A */  lh    $v0, 0xa($t0)
/* 100054 802DCF64 C6240030 */  lwc1  $f4, 0x30($s1)
/* 100058 802DCF68 85070006 */  lh    $a3, 6($t0)
/* 10005C 802DCF6C 44820000 */  mtc1  $v0, $f0
/* 100060 802DCF70 00000000 */  nop   
/* 100064 802DCF74 46800020 */  cvt.s.w $f0, $f0
/* 100068 802DCF78 46002100 */  add.s $f4, $f4, $f0
/* 10006C 802DCF7C C7A0008C */  lwc1  $f0, 0x8c($sp)
/* 100070 802DCF80 C6260028 */  lwc1  $f6, 0x28($s1)
/* 100074 802DCF84 46002102 */  mul.s $f4, $f4, $f0
/* 100078 802DCF88 00000000 */  nop   
/* 10007C 802DCF8C 85030008 */  lh    $v1, 8($t0)
/* 100080 802DCF90 C622002C */  lwc1  $f2, 0x2c($s1)
/* 100084 802DCF94 27A20038 */  addiu $v0, $sp, 0x38
/* 100088 802DCF98 44830000 */  mtc1  $v1, $f0
/* 10008C 802DCF9C 00000000 */  nop   
/* 100090 802DCFA0 46800020 */  cvt.s.w $f0, $f0
/* 100094 802DCFA4 46001080 */  add.s $f2, $f2, $f0
/* 100098 802DCFA8 AFA20018 */  sw    $v0, 0x18($sp)
/* 10009C 802DCFAC 44870000 */  mtc1  $a3, $f0
/* 1000A0 802DCFB0 00000000 */  nop   
/* 1000A4 802DCFB4 46800020 */  cvt.s.w $f0, $f0
/* 1000A8 802DCFB8 46003180 */  add.s $f6, $f6, $f0
/* 1000AC 802DCFBC 27A2003C */  addiu $v0, $sp, 0x3c
/* 1000B0 802DCFC0 AFA2001C */  sw    $v0, 0x1c($sp)
/* 1000B4 802DCFC4 44073000 */  mfc1  $a3, $f6
/* 1000B8 802DCFC8 27A20040 */  addiu $v0, $sp, 0x40
/* 1000BC 802DCFCC AFA20020 */  sw    $v0, 0x20($sp)
/* 1000C0 802DCFD0 E7A20010 */  swc1  $f2, 0x10($sp)
/* 1000C4 802DCFD4 0C0B7340 */  jal   spr_transform_point
/* 1000C8 802DCFD8 E7A40014 */   swc1  $f4, 0x14($sp)
/* 1000CC 802DCFDC 3C030800 */  lui   $v1, 0x800
/* 1000D0 802DCFE0 8E240014 */  lw    $a0, 0x14($s1)
/* 1000D4 802DCFE4 02631824 */  and   $v1, $s3, $v1
/* 1000D8 802DCFE8 00041080 */  sll   $v0, $a0, 2
/* 1000DC 802DCFEC 00501021 */  addu  $v0, $v0, $s0
/* 1000E0 802DCFF0 8C520000 */  lw    $s2, ($v0)
/* 1000E4 802DCFF4 8E300018 */  lw    $s0, 0x18($s1)
/* 1000E8 802DCFF8 10600007 */  beqz  $v1, .L802DD018
/* 1000EC 802DCFFC 00101880 */   sll   $v1, $s0, 2
/* 1000F0 802DD000 3C05802E */  lui   $a1, 0x802e
/* 1000F4 802DD004 8CA5F57C */  lw    $a1, -0xa84($a1)
/* 1000F8 802DD008 0C0B7BA8 */  jal   func_802DEEA0
/* 1000FC 802DD00C 30840FFF */   andi  $a0, $a0, 0xfff
/* 100100 802DD010 AE420000 */  sw    $v0, ($s2)
/* 100104 802DD014 00101880 */  sll   $v1, $s0, 2
.L802DD018:
/* 100108 802DD018 C7A00038 */  lwc1  $f0, 0x38($sp)
/* 10010C 802DD01C 8FA20088 */  lw    $v0, 0x88($sp)
/* 100110 802DD020 C7A2003C */  lwc1  $f2, 0x3c($sp)
/* 100114 802DD024 C7A40040 */  lwc1  $f4, 0x40($sp)
/* 100118 802DD028 00621821 */  addu  $v1, $v1, $v0
/* 10011C 802DD02C 44050000 */  mfc1  $a1, $f0
/* 100120 802DD030 C6200034 */  lwc1  $f0, 0x34($s1)
/* 100124 802DD034 46800020 */  cvt.s.w $f0, $f0
/* 100128 802DD038 4600A000 */  add.s $f0, $f20, $f0
/* 10012C 802DD03C 8E22004C */  lw    $v0, 0x4c($s1)
/* 100130 802DD040 8C630000 */  lw    $v1, ($v1)
/* 100134 802DD044 E7A00010 */  swc1  $f0, 0x10($sp)
/* 100138 802DD048 C6200038 */  lwc1  $f0, 0x38($s1)
/* 10013C 802DD04C 46800020 */  cvt.s.w $f0, $f0
/* 100140 802DD050 4600B000 */  add.s $f0, $f22, $f0
/* 100144 802DD054 44061000 */  mfc1  $a2, $f2
/* 100148 802DD058 E7A00014 */  swc1  $f0, 0x14($sp)
/* 10014C 802DD05C C620003C */  lwc1  $f0, 0x3c($s1)
/* 100150 802DD060 46800020 */  cvt.s.w $f0, $f0
/* 100154 802DD064 4600C000 */  add.s $f0, $f24, $f0
/* 100158 802DD068 44072000 */  mfc1  $a3, $f4
/* 10015C 802DD06C E7A00018 */  swc1  $f0, 0x18($sp)
/* 100160 802DD070 C6200040 */  lwc1  $f0, 0x40($s1)
/* 100164 802DD074 E7A0001C */  swc1  $f0, 0x1c($sp)
/* 100168 802DD078 C6200044 */  lwc1  $f0, 0x44($s1)
/* 10016C 802DD07C E7A00020 */  swc1  $f0, 0x20($sp)
/* 100170 802DD080 C6200048 */  lwc1  $f0, 0x48($s1)
/* 100174 802DD084 3C10802E */  lui   $s0, 0x802e
/* 100178 802DD088 2610F540 */  addiu $s0, $s0, -0xac0
/* 10017C 802DD08C AE020000 */  sw    $v0, ($s0)
/* 100180 802DD090 8FA20090 */  lw    $v0, 0x90($sp)
/* 100184 802DD094 0240202D */  daddu $a0, $s2, $zero
/* 100188 802DD098 AFB30028 */  sw    $s3, 0x28($sp)
/* 10018C 802DD09C AFA3002C */  sw    $v1, 0x2c($sp)
/* 100190 802DD0A0 AFA20030 */  sw    $v0, 0x30($sp)
/* 100194 802DD0A4 0C0B723D */  jal   spr_appendMDL_component
/* 100198 802DD0A8 E7A00024 */   swc1  $f0, 0x24($sp)
/* 10019C 802DD0AC 8E020000 */  lw    $v0, ($s0)
/* 1001A0 802DD0B0 AE22004C */  sw    $v0, 0x4c($s1)
.L802DD0B4:
/* 1001A4 802DD0B4 8FBF0058 */  lw    $ra, 0x58($sp)
/* 1001A8 802DD0B8 8FB30054 */  lw    $s3, 0x54($sp)
/* 1001AC 802DD0BC 8FB20050 */  lw    $s2, 0x50($sp)
/* 1001B0 802DD0C0 8FB1004C */  lw    $s1, 0x4c($sp)
/* 1001B4 802DD0C4 8FB00048 */  lw    $s0, 0x48($sp)
/* 1001B8 802DD0C8 D7B80070 */  ldc1  $f24, 0x70($sp)
/* 1001BC 802DD0CC D7B60068 */  ldc1  $f22, 0x68($sp)
/* 1001C0 802DD0D0 D7B40060 */  ldc1  $f20, 0x60($sp)
/* 1001C4 802DD0D4 03E00008 */  jr    $ra
/* 1001C8 802DD0D8 27BD0078 */   addiu $sp, $sp, 0x78

