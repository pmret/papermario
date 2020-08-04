.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel InterpPlayerYaw
/* 0F62EC 802D193C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F62F0 802D1940 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F62F4 802D1944 0080882D */  daddu $s1, $a0, $zero
/* 0F62F8 802D1948 AFB50024 */  sw    $s5, 0x24($sp)
/* 0F62FC 802D194C 3C158011 */  lui   $s5, 0x8011
/* 0F6300 802D1950 26B5EFC8 */  addiu $s5, $s5, -0x1038
/* 0F6304 802D1954 AFB60028 */  sw    $s6, 0x28($sp)
/* 0F6308 802D1958 26360074 */  addiu $s6, $s1, 0x74
/* 0F630C 802D195C AFB40020 */  sw    $s4, 0x20($sp)
/* 0F6310 802D1960 26340078 */  addiu $s4, $s1, 0x78
/* 0F6314 802D1964 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F6318 802D1968 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0F631C 802D196C AFB20018 */  sw    $s2, 0x18($sp)
/* 0F6320 802D1970 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F6324 802D1974 8E32000C */  lw    $s2, 0xc($s1)
/* 0F6328 802D1978 10A0002C */  beqz  $a1, .L802D1A2C
/* 0F632C 802D197C 2633007C */   addiu $s3, $s1, 0x7c
/* 0F6330 802D1980 3C10802E */  lui   $s0, 0x802e
/* 0F6334 802D1984 26109D20 */  addiu $s0, $s0, -0x62e0
/* 0F6338 802D1988 8E020000 */  lw    $v0, ($s0)
/* 0F633C 802D198C C6A00080 */  lwc1  $f0, 0x80($s5)
/* 0F6340 802D1990 E440000C */  swc1  $f0, 0xc($v0)
/* 0F6344 802D1994 E6200074 */  swc1  $f0, 0x74($s1)
/* 0F6348 802D1998 8E450000 */  lw    $a1, ($s2)
/* 0F634C 802D199C 0C0B210B */  jal   get_float_variable
/* 0F6350 802D19A0 26520004 */   addiu $s2, $s2, 4
/* 0F6354 802D19A4 C6220074 */  lwc1  $f2, 0x74($s1)
/* 0F6358 802D19A8 46020001 */  sub.s $f0, $f0, $f2
/* 0F635C 802D19AC E6200078 */  swc1  $f0, 0x78($s1)
/* 0F6360 802D19B0 8E450000 */  lw    $a1, ($s2)
/* 0F6364 802D19B4 0C0B1EAF */  jal   get_variable
/* 0F6368 802D19B8 0220202D */   daddu $a0, $s1, $zero
/* 0F636C 802D19BC AE22007C */  sw    $v0, 0x7c($s1)
/* 0F6370 802D19C0 8E020000 */  lw    $v0, ($s0)
/* 0F6374 802D19C4 3C01C334 */  lui   $at, 0xc334
/* 0F6378 802D19C8 44810000 */  mtc1  $at, $f0
/* 0F637C 802D19CC A440008E */  sh    $zero, 0x8e($v0)
/* 0F6380 802D19D0 C6220078 */  lwc1  $f2, 0x78($s1)
/* 0F6384 802D19D4 4600103C */  c.lt.s $f2, $f0
/* 0F6388 802D19D8 00000000 */  nop   
/* 0F638C 802D19DC 45000007 */  bc1f  .L802D19FC
/* 0F6390 802D19E0 00000000 */   nop   
/* 0F6394 802D19E4 3C0143B4 */  lui   $at, 0x43b4
/* 0F6398 802D19E8 44810000 */  mtc1  $at, $f0
/* 0F639C 802D19EC 00000000 */  nop   
/* 0F63A0 802D19F0 46001000 */  add.s $f0, $f2, $f0
/* 0F63A4 802D19F4 E6200078 */  swc1  $f0, 0x78($s1)
/* 0F63A8 802D19F8 C6220078 */  lwc1  $f2, 0x78($s1)
.L802D19FC:
/* 0F63AC 802D19FC 3C014334 */  lui   $at, 0x4334
/* 0F63B0 802D1A00 44810000 */  mtc1  $at, $f0
/* 0F63B4 802D1A04 00000000 */  nop   
/* 0F63B8 802D1A08 4602003C */  c.lt.s $f0, $f2
/* 0F63BC 802D1A0C 00000000 */  nop   
/* 0F63C0 802D1A10 45000006 */  bc1f  .L802D1A2C
/* 0F63C4 802D1A14 00000000 */   nop   
/* 0F63C8 802D1A18 3C0143B4 */  lui   $at, 0x43b4
/* 0F63CC 802D1A1C 44810000 */  mtc1  $at, $f0
/* 0F63D0 802D1A20 00000000 */  nop   
/* 0F63D4 802D1A24 46001001 */  sub.s $f0, $f2, $f0
/* 0F63D8 802D1A28 E6200078 */  swc1  $f0, 0x78($s1)
.L802D1A2C:
/* 0F63DC 802D1A2C 8E620000 */  lw    $v0, ($s3)
/* 0F63E0 802D1A30 1C40000E */  bgtz  $v0, .L802D1A6C
/* 0F63E4 802D1A34 00000000 */   nop   
/* 0F63E8 802D1A38 3C10802E */  lui   $s0, 0x802e
/* 0F63EC 802D1A3C 26109D20 */  addiu $s0, $s0, -0x62e0
/* 0F63F0 802D1A40 8E020000 */  lw    $v0, ($s0)
/* 0F63F4 802D1A44 C6800000 */  lwc1  $f0, ($s4)
/* 0F63F8 802D1A48 C44C000C */  lwc1  $f12, 0xc($v0)
/* 0F63FC 802D1A4C 46006300 */  add.s $f12, $f12, $f0
/* 0F6400 802D1A50 0C00A6C9 */  jal   clamp_angle
/* 0F6404 802D1A54 E44C000C */   swc1  $f12, 0xc($v0)
/* 0F6408 802D1A58 8E030000 */  lw    $v1, ($s0)
/* 0F640C 802D1A5C 24020002 */  addiu $v0, $zero, 2
/* 0F6410 802D1A60 E460000C */  swc1  $f0, 0xc($v1)
/* 0F6414 802D1A64 080B46B7 */  j     .L802D1ADC
/* 0F6418 802D1A68 E6A00080 */   swc1  $f0, 0x80($s5)

.L802D1A6C:
/* 0F641C 802D1A6C 3C10802E */  lui   $s0, 0x802e
/* 0F6420 802D1A70 26109D20 */  addiu $s0, $s0, -0x62e0
/* 0F6424 802D1A74 8E030000 */  lw    $v1, ($s0)
/* 0F6428 802D1A78 9462008E */  lhu   $v0, 0x8e($v1)
/* 0F642C 802D1A7C 24420001 */  addiu $v0, $v0, 1
/* 0F6430 802D1A80 A462008E */  sh    $v0, 0x8e($v1)
/* 0F6434 802D1A84 00021400 */  sll   $v0, $v0, 0x10
/* 0F6438 802D1A88 00021403 */  sra   $v0, $v0, 0x10
/* 0F643C 802D1A8C C6800000 */  lwc1  $f0, ($s4)
/* 0F6440 802D1A90 44821000 */  mtc1  $v0, $f2
/* 0F6444 802D1A94 00000000 */  nop   
/* 0F6448 802D1A98 468010A0 */  cvt.s.w $f2, $f2
/* 0F644C 802D1A9C 46020002 */  mul.s $f0, $f0, $f2
/* 0F6450 802D1AA0 00000000 */  nop   
/* 0F6454 802D1AA4 C6CC0000 */  lwc1  $f12, ($s6)
/* 0F6458 802D1AA8 C6620000 */  lwc1  $f2, ($s3)
/* 0F645C 802D1AAC 468010A0 */  cvt.s.w $f2, $f2
/* 0F6460 802D1AB0 46020003 */  div.s $f0, $f0, $f2
/* 0F6464 802D1AB4 46006300 */  add.s $f12, $f12, $f0
/* 0F6468 802D1AB8 0C00A6C9 */  jal   clamp_angle
/* 0F646C 802D1ABC E46C000C */   swc1  $f12, 0xc($v1)
/* 0F6470 802D1AC0 8E020000 */  lw    $v0, ($s0)
/* 0F6474 802D1AC4 E440000C */  swc1  $f0, 0xc($v0)
/* 0F6478 802D1AC8 E6A00080 */  swc1  $f0, 0x80($s5)
/* 0F647C 802D1ACC 8442008E */  lh    $v0, 0x8e($v0)
/* 0F6480 802D1AD0 8E630000 */  lw    $v1, ($s3)
/* 0F6484 802D1AD4 0043102A */  slt   $v0, $v0, $v1
/* 0F6488 802D1AD8 38420001 */  xori  $v0, $v0, 1
.L802D1ADC:
/* 0F648C 802D1ADC 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0F6490 802D1AE0 8FB60028 */  lw    $s6, 0x28($sp)
/* 0F6494 802D1AE4 8FB50024 */  lw    $s5, 0x24($sp)
/* 0F6498 802D1AE8 8FB40020 */  lw    $s4, 0x20($sp)
/* 0F649C 802D1AEC 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F64A0 802D1AF0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F64A4 802D1AF4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F64A8 802D1AF8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F64AC 802D1AFC 03E00008 */  jr    $ra
/* 0F64B0 802D1B00 27BD0030 */   addiu $sp, $sp, 0x30

