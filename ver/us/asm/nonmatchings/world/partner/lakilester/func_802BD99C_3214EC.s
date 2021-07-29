.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD99C_3214EC
/* 3214EC 802BD99C 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3214F0 802BD9A0 AFB1004C */  sw        $s1, 0x4c($sp)
/* 3214F4 802BD9A4 0080882D */  daddu     $s1, $a0, $zero
/* 3214F8 802BD9A8 AFB00048 */  sw        $s0, 0x48($sp)
/* 3214FC 802BD9AC 3C10802C */  lui       $s0, %hi(D_802BFF24)
/* 321500 802BD9B0 2610FF24 */  addiu     $s0, $s0, %lo(D_802BFF24)
/* 321504 802BD9B4 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* 321508 802BD9B8 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* 32150C 802BD9BC 27A20034 */  addiu     $v0, $sp, 0x34
/* 321510 802BD9C0 AFA60034 */  sw        $a2, 0x34($sp)
/* 321514 802BD9C4 27A6002C */  addiu     $a2, $sp, 0x2c
/* 321518 802BD9C8 27A70030 */  addiu     $a3, $sp, 0x30
/* 32151C 802BD9CC AFBF0050 */  sw        $ra, 0x50($sp)
/* 321520 802BD9D0 AE000000 */  sw        $zero, ($s0)
/* 321524 802BD9D4 C4840028 */  lwc1      $f4, 0x28($a0)
/* 321528 802BD9D8 C480002C */  lwc1      $f0, 0x2c($a0)
/* 32152C 802BD9DC 44854000 */  mtc1      $a1, $f8
/* 321530 802BD9E0 C4820030 */  lwc1      $f2, 0x30($a0)
/* 321534 802BD9E4 46080000 */  add.s     $f0, $f0, $f8
/* 321538 802BD9E8 27A50028 */  addiu     $a1, $sp, 0x28
/* 32153C 802BD9EC E7A40028 */  swc1      $f4, 0x28($sp)
/* 321540 802BD9F0 E7A20030 */  swc1      $f2, 0x30($sp)
/* 321544 802BD9F4 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 321548 802BD9F8 AFA20010 */  sw        $v0, 0x10($sp)
/* 32154C 802BD9FC 27A20038 */  addiu     $v0, $sp, 0x38
/* 321550 802BDA00 AFA20014 */  sw        $v0, 0x14($sp)
/* 321554 802BDA04 27A2003C */  addiu     $v0, $sp, 0x3c
/* 321558 802BDA08 AFA20018 */  sw        $v0, 0x18($sp)
/* 32155C 802BDA0C 27A20040 */  addiu     $v0, $sp, 0x40
/* 321560 802BDA10 AFA2001C */  sw        $v0, 0x1c($sp)
/* 321564 802BDA14 27A20044 */  addiu     $v0, $sp, 0x44
/* 321568 802BDA18 0C03791B */  jal       player_raycast_below_cam_relative
/* 32156C 802BDA1C AFA20020 */   sw       $v0, 0x20($sp)
/* 321570 802BDA20 04420016 */  bltzl     $v0, .L802BDA7C
/* 321574 802BDA24 0000102D */   daddu    $v0, $zero, $zero
/* 321578 802BDA28 C7A6002C */  lwc1      $f6, 0x2c($sp)
/* 32157C 802BDA2C C6200064 */  lwc1      $f0, 0x64($s1)
/* 321580 802BDA30 46003101 */  sub.s     $f4, $f6, $f0
/* 321584 802BDA34 44800000 */  mtc1      $zero, $f0
/* 321588 802BDA38 00000000 */  nop
/* 32158C 802BDA3C 46002032 */  c.eq.s    $f4, $f0
/* 321590 802BDA40 00000000 */  nop
/* 321594 802BDA44 4501000D */  bc1t      .L802BDA7C
/* 321598 802BDA48 24020001 */   addiu    $v0, $zero, 1
/* 32159C 802BDA4C 46002021 */  cvt.d.s   $f0, $f4
/* 3215A0 802BDA50 3C014024 */  lui       $at, 0x4024
/* 3215A4 802BDA54 44811800 */  mtc1      $at, $f3
/* 3215A8 802BDA58 44801000 */  mtc1      $zero, $f2
/* 3215AC 802BDA5C 46200005 */  abs.d     $f0, $f0
/* 3215B0 802BDA60 4622003C */  c.lt.d    $f0, $f2
/* 3215B4 802BDA64 00000000 */  nop
/* 3215B8 802BDA68 45020004 */  bc1fl     .L802BDA7C
/* 3215BC 802BDA6C 0000102D */   daddu    $v0, $zero, $zero
/* 3215C0 802BDA70 4600220D */  trunc.w.s $f8, $f4
/* 3215C4 802BDA74 E6080000 */  swc1      $f8, ($s0)
/* 3215C8 802BDA78 E6260064 */  swc1      $f6, 0x64($s1)
.L802BDA7C:
/* 3215CC 802BDA7C 8FBF0050 */  lw        $ra, 0x50($sp)
/* 3215D0 802BDA80 8FB1004C */  lw        $s1, 0x4c($sp)
/* 3215D4 802BDA84 8FB00048 */  lw        $s0, 0x48($sp)
/* 3215D8 802BDA88 03E00008 */  jr        $ra
/* 3215DC 802BDA8C 27BD0058 */   addiu    $sp, $sp, 0x58
