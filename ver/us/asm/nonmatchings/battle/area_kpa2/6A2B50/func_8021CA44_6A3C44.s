.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021CA44_6A3C44
/* 6A3C44 8021CA44 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6A3C48 8021CA48 AFB20018 */  sw        $s2, 0x18($sp)
/* 6A3C4C 8021CA4C 0080902D */  daddu     $s2, $a0, $zero
/* 6A3C50 8021CA50 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6A3C54 8021CA54 AFB10014 */  sw        $s1, 0x14($sp)
/* 6A3C58 8021CA58 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A3C5C 8021CA5C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 6A3C60 8021CA60 10A00044 */  beqz      $a1, .L8021CB74
/* 6A3C64 8021CA64 8E50000C */   lw       $s0, 0xc($s2)
/* 6A3C68 8021CA68 0C00AB39 */  jal       heap_malloc
/* 6A3C6C 8021CA6C 24040024 */   addiu    $a0, $zero, 0x24
/* 6A3C70 8021CA70 0040882D */  daddu     $s1, $v0, $zero
/* 6A3C74 8021CA74 AE510070 */  sw        $s1, 0x70($s2)
/* 6A3C78 8021CA78 8E050000 */  lw        $a1, ($s0)
/* 6A3C7C 8021CA7C 26100004 */  addiu     $s0, $s0, 4
/* 6A3C80 8021CA80 0C0B1EAF */  jal       get_variable
/* 6A3C84 8021CA84 0240202D */   daddu    $a0, $s2, $zero
/* 6A3C88 8021CA88 AE220020 */  sw        $v0, 0x20($s1)
/* 6A3C8C 8021CA8C 8E050000 */  lw        $a1, ($s0)
/* 6A3C90 8021CA90 26100004 */  addiu     $s0, $s0, 4
/* 6A3C94 8021CA94 0C0B210B */  jal       evt_get_float_variable
/* 6A3C98 8021CA98 0240202D */   daddu    $a0, $s2, $zero
/* 6A3C9C 8021CA9C E6200000 */  swc1      $f0, ($s1)
/* 6A3CA0 8021CAA0 8E050000 */  lw        $a1, ($s0)
/* 6A3CA4 8021CAA4 26100004 */  addiu     $s0, $s0, 4
/* 6A3CA8 8021CAA8 0C0B210B */  jal       evt_get_float_variable
/* 6A3CAC 8021CAAC 0240202D */   daddu    $a0, $s2, $zero
/* 6A3CB0 8021CAB0 E6200004 */  swc1      $f0, 4($s1)
/* 6A3CB4 8021CAB4 8E050000 */  lw        $a1, ($s0)
/* 6A3CB8 8021CAB8 26100004 */  addiu     $s0, $s0, 4
/* 6A3CBC 8021CABC 0C0B210B */  jal       evt_get_float_variable
/* 6A3CC0 8021CAC0 0240202D */   daddu    $a0, $s2, $zero
/* 6A3CC4 8021CAC4 E6200008 */  swc1      $f0, 8($s1)
/* 6A3CC8 8021CAC8 8E050000 */  lw        $a1, ($s0)
/* 6A3CCC 8021CACC 26100004 */  addiu     $s0, $s0, 4
/* 6A3CD0 8021CAD0 0C0B1EAF */  jal       get_variable
/* 6A3CD4 8021CAD4 0240202D */   daddu    $a0, $s2, $zero
/* 6A3CD8 8021CAD8 AE22001C */  sw        $v0, 0x1c($s1)
/* 6A3CDC 8021CADC 8E050000 */  lw        $a1, ($s0)
/* 6A3CE0 8021CAE0 0C0B210B */  jal       evt_get_float_variable
/* 6A3CE4 8021CAE4 0240202D */   daddu    $a0, $s2, $zero
/* 6A3CE8 8021CAE8 8E240020 */  lw        $a0, 0x20($s1)
/* 6A3CEC 8021CAEC 0C04C3D6 */  jal       get_item_entity
/* 6A3CF0 8021CAF0 E6200010 */   swc1     $f0, 0x10($s1)
/* 6A3CF4 8021CAF4 0040802D */  daddu     $s0, $v0, $zero
/* 6A3CF8 8021CAF8 C60C0008 */  lwc1      $f12, 8($s0)
/* 6A3CFC 8021CAFC C60E0010 */  lwc1      $f14, 0x10($s0)
/* 6A3D00 8021CB00 8E260000 */  lw        $a2, ($s1)
/* 6A3D04 8021CB04 0C00A7B5 */  jal       dist2D
/* 6A3D08 8021CB08 8E270008 */   lw       $a3, 8($s1)
/* 6A3D0C 8021CB0C C60C0008 */  lwc1      $f12, 8($s0)
/* 6A3D10 8021CB10 C60E0010 */  lwc1      $f14, 0x10($s0)
/* 6A3D14 8021CB14 8E260000 */  lw        $a2, ($s1)
/* 6A3D18 8021CB18 8E270008 */  lw        $a3, 8($s1)
/* 6A3D1C 8021CB1C 0C00A720 */  jal       atan2
/* 6A3D20 8021CB20 46000506 */   mov.s    $f20, $f0
/* 6A3D24 8021CB24 C6240010 */  lwc1      $f4, 0x10($s1)
/* 6A3D28 8021CB28 C626001C */  lwc1      $f6, 0x1c($s1)
/* 6A3D2C 8021CB2C 468031A0 */  cvt.s.w   $f6, $f6
/* 6A3D30 8021CB30 46062102 */  mul.s     $f4, $f4, $f6
/* 6A3D34 8021CB34 00000000 */  nop
/* 6A3D38 8021CB38 3C013F00 */  lui       $at, 0x3f00
/* 6A3D3C 8021CB3C 44811000 */  mtc1      $at, $f2
/* 6A3D40 8021CB40 00000000 */  nop
/* 6A3D44 8021CB44 46022102 */  mul.s     $f4, $f4, $f2
/* 6A3D48 8021CB48 00000000 */  nop
/* 6A3D4C 8021CB4C E620000C */  swc1      $f0, 0xc($s1)
/* 6A3D50 8021CB50 C6200004 */  lwc1      $f0, 4($s1)
/* 6A3D54 8021CB54 C602000C */  lwc1      $f2, 0xc($s0)
/* 6A3D58 8021CB58 46020001 */  sub.s     $f0, $f0, $f2
/* 6A3D5C 8021CB5C 46003086 */  mov.s     $f2, $f6
/* 6A3D60 8021CB60 46060003 */  div.s     $f0, $f0, $f6
/* 6A3D64 8021CB64 46002100 */  add.s     $f4, $f4, $f0
/* 6A3D68 8021CB68 4602A503 */  div.s     $f20, $f20, $f2
/* 6A3D6C 8021CB6C E6340014 */  swc1      $f20, 0x14($s1)
/* 6A3D70 8021CB70 E6240018 */  swc1      $f4, 0x18($s1)
.L8021CB74:
/* 6A3D74 8021CB74 8E510070 */  lw        $s1, 0x70($s2)
/* 6A3D78 8021CB78 0C04C3D6 */  jal       get_item_entity
/* 6A3D7C 8021CB7C 8E240020 */   lw       $a0, 0x20($s1)
/* 6A3D80 8021CB80 0040802D */  daddu     $s0, $v0, $zero
/* 6A3D84 8021CB84 16000005 */  bnez      $s0, .L8021CB9C
/* 6A3D88 8021CB88 00000000 */   nop
/* 6A3D8C 8021CB8C 0C00AB4B */  jal       heap_free
/* 6A3D90 8021CB90 8E440070 */   lw       $a0, 0x70($s2)
/* 6A3D94 8021CB94 08087310 */  j         .L8021CC40
/* 6A3D98 8021CB98 24020002 */   addiu    $v0, $zero, 2
.L8021CB9C:
/* 6A3D9C 8021CB9C C62C000C */  lwc1      $f12, 0xc($s1)
/* 6A3DA0 8021CBA0 0C00A8BB */  jal       sin_deg
/* 6A3DA4 8021CBA4 00000000 */   nop
/* 6A3DA8 8021CBA8 C6220014 */  lwc1      $f2, 0x14($s1)
/* 6A3DAC 8021CBAC 46001082 */  mul.s     $f2, $f2, $f0
/* 6A3DB0 8021CBB0 00000000 */  nop
/* 6A3DB4 8021CBB4 C6000008 */  lwc1      $f0, 8($s0)
/* 6A3DB8 8021CBB8 46020000 */  add.s     $f0, $f0, $f2
/* 6A3DBC 8021CBBC E6000008 */  swc1      $f0, 8($s0)
/* 6A3DC0 8021CBC0 0C00A8D4 */  jal       cos_deg
/* 6A3DC4 8021CBC4 C62C000C */   lwc1     $f12, 0xc($s1)
/* 6A3DC8 8021CBC8 C6220014 */  lwc1      $f2, 0x14($s1)
/* 6A3DCC 8021CBCC 46001082 */  mul.s     $f2, $f2, $f0
/* 6A3DD0 8021CBD0 00000000 */  nop
/* 6A3DD4 8021CBD4 C6000010 */  lwc1      $f0, 0x10($s0)
/* 6A3DD8 8021CBD8 46020001 */  sub.s     $f0, $f0, $f2
/* 6A3DDC 8021CBDC E6000010 */  swc1      $f0, 0x10($s0)
/* 6A3DE0 8021CBE0 C600000C */  lwc1      $f0, 0xc($s0)
/* 6A3DE4 8021CBE4 C6220018 */  lwc1      $f2, 0x18($s1)
/* 6A3DE8 8021CBE8 46020000 */  add.s     $f0, $f0, $f2
/* 6A3DEC 8021CBEC E600000C */  swc1      $f0, 0xc($s0)
/* 6A3DF0 8021CBF0 C6200018 */  lwc1      $f0, 0x18($s1)
/* 6A3DF4 8021CBF4 C6220010 */  lwc1      $f2, 0x10($s1)
/* 6A3DF8 8021CBF8 8E22001C */  lw        $v0, 0x1c($s1)
/* 6A3DFC 8021CBFC 46020001 */  sub.s     $f0, $f0, $f2
/* 6A3E00 8021CC00 2442FFFF */  addiu     $v0, $v0, -1
/* 6A3E04 8021CC04 AE22001C */  sw        $v0, 0x1c($s1)
/* 6A3E08 8021CC08 04400003 */  bltz      $v0, .L8021CC18
/* 6A3E0C 8021CC0C E6200018 */   swc1     $f0, 0x18($s1)
/* 6A3E10 8021CC10 08087310 */  j         .L8021CC40
/* 6A3E14 8021CC14 0000102D */   daddu    $v0, $zero, $zero
.L8021CC18:
/* 6A3E18 8021CC18 C6200000 */  lwc1      $f0, ($s1)
/* 6A3E1C 8021CC1C E6000008 */  swc1      $f0, 8($s0)
/* 6A3E20 8021CC20 C6200004 */  lwc1      $f0, 4($s1)
/* 6A3E24 8021CC24 E600000C */  swc1      $f0, 0xc($s0)
/* 6A3E28 8021CC28 C6200008 */  lwc1      $f0, 8($s1)
/* 6A3E2C 8021CC2C E6000010 */  swc1      $f0, 0x10($s0)
/* 6A3E30 8021CC30 AE200018 */  sw        $zero, 0x18($s1)
/* 6A3E34 8021CC34 0C00AB4B */  jal       heap_free
/* 6A3E38 8021CC38 8E440070 */   lw       $a0, 0x70($s2)
/* 6A3E3C 8021CC3C 24020001 */  addiu     $v0, $zero, 1
.L8021CC40:
/* 6A3E40 8021CC40 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6A3E44 8021CC44 8FB20018 */  lw        $s2, 0x18($sp)
/* 6A3E48 8021CC48 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A3E4C 8021CC4C 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A3E50 8021CC50 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 6A3E54 8021CC54 03E00008 */  jr        $ra
/* 6A3E58 8021CC58 27BD0028 */   addiu    $sp, $sp, 0x28
