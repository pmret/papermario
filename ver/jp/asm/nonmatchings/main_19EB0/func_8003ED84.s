.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003ED84
/* 1A184 8003ED84 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1A188 8003ED88 AFB20020 */  sw        $s2, 0x20($sp)
/* 1A18C 8003ED8C 0080902D */  daddu     $s2, $a0, $zero
/* 1A190 8003ED90 AFB00018 */  sw        $s0, 0x18($sp)
/* 1A194 8003ED94 00A0802D */  daddu     $s0, $a1, $zero
/* 1A198 8003ED98 2404FFF6 */  addiu     $a0, $zero, -0xa
/* 1A19C 8003ED9C AFBF0024 */  sw        $ra, 0x24($sp)
/* 1A1A0 8003EDA0 0C00E9EB */  jal       func_8003A7AC
/* 1A1A4 8003EDA4 AFB1001C */   sw       $s1, 0x1c($sp)
/* 1A1A8 8003EDA8 12000024 */  beqz      $s0, .L8003EE3C
/* 1A1AC 8003EDAC 0040882D */   daddu    $s1, $v0, $zero
/* 1A1B0 8003EDB0 AE400074 */  sw        $zero, 0x74($s2)
/* 1A1B4 8003EDB4 C622003C */  lwc1      $f2, 0x3c($s1)
/* 1A1B8 8003EDB8 3C013ECC */  lui       $at, 0x3ecc
/* 1A1BC 8003EDBC 3421CCCD */  ori       $at, $at, 0xcccd
/* 1A1C0 8003EDC0 44810000 */  mtc1      $at, $f0
/* 1A1C4 8003EDC4 AFA00014 */  sw        $zero, 0x14($sp)
/* 1A1C8 8003EDC8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A1CC 8003EDCC 8E250038 */  lw        $a1, 0x38($s1)
/* 1A1D0 8003EDD0 8E26003C */  lw        $a2, 0x3c($s1)
/* 1A1D4 8003EDD4 8E270040 */  lw        $a3, 0x40($s1)
/* 1A1D8 8003EDD8 3C01800A */  lui       $at, %hi(D_8009E9B4)
/* 1A1DC 8003EDDC E422E9B4 */  swc1      $f2, %lo(D_8009E9B4)($at)
/* 1A1E0 8003EDE0 0C01C5CC */  jal       func_80071730
/* 1A1E4 8003EDE4 0000202D */   daddu    $a0, $zero, $zero
/* 1A1E8 8003EDE8 3C013727 */  lui       $at, 0x3727
/* 1A1EC 8003EDEC 3421C5AC */  ori       $at, $at, 0xc5ac
/* 1A1F0 8003EDF0 44810000 */  mtc1      $at, $f0
/* 1A1F4 8003EDF4 AFA00014 */  sw        $zero, 0x14($sp)
/* 1A1F8 8003EDF8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1A1FC 8003EDFC 8E250038 */  lw        $a1, 0x38($s1)
/* 1A200 8003EE00 8E26003C */  lw        $a2, 0x3c($s1)
/* 1A204 8003EE04 8E270040 */  lw        $a3, 0x40($s1)
/* 1A208 8003EE08 3C01800A */  lui       $at, %hi(D_8009E9B8)
/* 1A20C 8003EE0C AC22E9B8 */  sw        $v0, %lo(D_8009E9B8)($at)
/* 1A210 8003EE10 0C01C5CC */  jal       func_80071730
/* 1A214 8003EE14 24040003 */   addiu    $a0, $zero, 3
/* 1A218 8003EE18 3C01800A */  lui       $at, %hi(D_8009E9BC)
/* 1A21C 8003EE1C AC22E9BC */  sw        $v0, %lo(D_8009E9BC)($at)
/* 1A220 8003EE20 2402000C */  addiu     $v0, $zero, 0xc
/* 1A224 8003EE24 3C01800A */  lui       $at, %hi(D_8009E9C8)
/* 1A228 8003EE28 A420E9C8 */  sh        $zero, %lo(D_8009E9C8)($at)
/* 1A22C 8003EE2C 3C01800A */  lui       $at, %hi(D_8009E9B0)
/* 1A230 8003EE30 AC22E9B0 */  sw        $v0, %lo(D_8009E9B0)($at)
/* 1A234 8003EE34 0C053B59 */  jal       func_8014ED64
/* 1A238 8003EE38 24042074 */   addiu    $a0, $zero, 0x2074
.L8003EE3C:
/* 1A23C 8003EE3C 3C0140C9 */  lui       $at, 0x40c9
/* 1A240 8003EE40 34210FD0 */  ori       $at, $at, 0xfd0
/* 1A244 8003EE44 44810000 */  mtc1      $at, $f0
/* 1A248 8003EE48 C64C0074 */  lwc1      $f12, 0x74($s2)
/* 1A24C 8003EE4C 46806320 */  cvt.s.w   $f12, $f12
/* 1A250 8003EE50 46006302 */  mul.s     $f12, $f12, $f0
/* 1A254 8003EE54 00000000 */  nop
/* 1A258 8003EE58 3C0143B4 */  lui       $at, 0x43b4
/* 1A25C 8003EE5C 44810000 */  mtc1      $at, $f0
/* 1A260 8003EE60 0C00A84B */  jal       func_8002A12C
/* 1A264 8003EE64 46006303 */   div.s    $f12, $f12, $f0
/* 1A268 8003EE68 3C014040 */  lui       $at, 0x4040
/* 1A26C 8003EE6C 44811000 */  mtc1      $at, $f2
/* 1A270 8003EE70 00000000 */  nop
/* 1A274 8003EE74 46020002 */  mul.s     $f0, $f0, $f2
/* 1A278 8003EE78 00000000 */  nop
/* 1A27C 8003EE7C 3C01800A */  lui       $at, %hi(D_8009E9B4)
/* 1A280 8003EE80 C422E9B4 */  lwc1      $f2, %lo(D_8009E9B4)($at)
/* 1A284 8003EE84 46001080 */  add.s     $f2, $f2, $f0
/* 1A288 8003EE88 E622003C */  swc1      $f2, 0x3c($s1)
/* 1A28C 8003EE8C 8E420074 */  lw        $v0, 0x74($s2)
/* 1A290 8003EE90 2442000A */  addiu     $v0, $v0, 0xa
/* 1A294 8003EE94 44826000 */  mtc1      $v0, $f12
/* 1A298 8003EE98 00000000 */  nop
/* 1A29C 8003EE9C 46806320 */  cvt.s.w   $f12, $f12
/* 1A2A0 8003EEA0 0C00A6B9 */  jal       func_80029AE4
/* 1A2A4 8003EEA4 AE420074 */   sw       $v0, 0x74($s2)
/* 1A2A8 8003EEA8 4600018D */  trunc.w.s $f6, $f0
/* 1A2AC 8003EEAC E6460074 */  swc1      $f6, 0x74($s2)
/* 1A2B0 8003EEB0 3C05800A */  lui       $a1, %hi(D_8009E9B8)
/* 1A2B4 8003EEB4 8CA5E9B8 */  lw        $a1, %lo(D_8009E9B8)($a1)
/* 1A2B8 8003EEB8 C6200038 */  lwc1      $f0, 0x38($s1)
/* 1A2BC 8003EEBC 3C014180 */  lui       $at, 0x4180
/* 1A2C0 8003EEC0 44811000 */  mtc1      $at, $f2
/* 1A2C4 8003EEC4 8CA2000C */  lw        $v0, 0xc($a1)
/* 1A2C8 8003EEC8 E4400004 */  swc1      $f0, 4($v0)
/* 1A2CC 8003EECC C620003C */  lwc1      $f0, 0x3c($s1)
/* 1A2D0 8003EED0 46020000 */  add.s     $f0, $f0, $f2
/* 1A2D4 8003EED4 3C08800A */  lui       $t0, %hi(D_8009E9BC)
/* 1A2D8 8003EED8 2508E9BC */  addiu     $t0, $t0, %lo(D_8009E9BC)
/* 1A2DC 8003EEDC E4400008 */  swc1      $f0, 8($v0)
/* 1A2E0 8003EEE0 C6200040 */  lwc1      $f0, 0x40($s1)
/* 1A2E4 8003EEE4 8D040000 */  lw        $a0, ($t0)
/* 1A2E8 8003EEE8 E440000C */  swc1      $f0, 0xc($v0)
/* 1A2EC 8003EEEC 8C82000C */  lw        $v0, 0xc($a0)
/* 1A2F0 8003EEF0 C6200038 */  lwc1      $f0, 0x38($s1)
/* 1A2F4 8003EEF4 E4400004 */  swc1      $f0, 4($v0)
/* 1A2F8 8003EEF8 C620003C */  lwc1      $f0, 0x3c($s1)
/* 1A2FC 8003EEFC 46020000 */  add.s     $f0, $f0, $f2
/* 1A300 8003EF00 3C0140A0 */  lui       $at, 0x40a0
/* 1A304 8003EF04 44811000 */  mtc1      $at, $f2
/* 1A308 8003EF08 E4400008 */  swc1      $f0, 8($v0)
/* 1A30C 8003EF0C C6200040 */  lwc1      $f0, 0x40($s1)
/* 1A310 8003EF10 46020000 */  add.s     $f0, $f0, $f2
/* 1A314 8003EF14 3C07800A */  lui       $a3, %hi(D_8009E9C8)
/* 1A318 8003EF18 24E7E9C8 */  addiu     $a3, $a3, %lo(D_8009E9C8)
/* 1A31C 8003EF1C E440000C */  swc1      $f0, 0xc($v0)
/* 1A320 8003EF20 84E30000 */  lh        $v1, ($a3)
/* 1A324 8003EF24 24060002 */  addiu     $a2, $zero, 2
/* 1A328 8003EF28 14660011 */  bne       $v1, $a2, .L8003EF70
/* 1A32C 8003EF2C 24020001 */   addiu    $v0, $zero, 1
/* 1A330 8003EF30 8CA2000C */  lw        $v0, 0xc($a1)
/* 1A334 8003EF34 3C013727 */  lui       $at, 0x3727
/* 1A338 8003EF38 3421C5AC */  ori       $at, $at, 0xc5ac
/* 1A33C 8003EF3C 44810000 */  mtc1      $at, $f0
/* 1A340 8003EF40 00000000 */  nop
/* 1A344 8003EF44 E4400030 */  swc1      $f0, 0x30($v0)
/* 1A348 8003EF48 8C82000C */  lw        $v0, 0xc($a0)
/* 1A34C 8003EF4C E4400030 */  swc1      $f0, 0x30($v0)
/* 1A350 8003EF50 8CA20000 */  lw        $v0, ($a1)
/* 1A354 8003EF54 34420010 */  ori       $v0, $v0, 0x10
/* 1A358 8003EF58 ACA20000 */  sw        $v0, ($a1)
/* 1A35C 8003EF5C 8C830000 */  lw        $v1, ($a0)
/* 1A360 8003EF60 24020001 */  addiu     $v0, $zero, 1
/* 1A364 8003EF64 34630010 */  ori       $v1, $v1, 0x10
/* 1A368 8003EF68 0800FC0B */  j         .L8003F02C
/* 1A36C 8003EF6C AC830000 */   sw       $v1, ($a0)
.L8003EF70:
/* 1A370 8003EF70 1462002E */  bne       $v1, $v0, .L8003F02C
/* 1A374 8003EF74 0000102D */   daddu    $v0, $zero, $zero
/* 1A378 8003EF78 8CA2000C */  lw        $v0, 0xc($a1)
/* 1A37C 8003EF7C C4400030 */  lwc1      $f0, 0x30($v0)
/* 1A380 8003EF80 3C01800A */  lui       $at, %hi(D_800985D0)
/* 1A384 8003EF84 D42285D0 */  ldc1      $f2, %lo(D_800985D0)($at)
/* 1A388 8003EF88 46000021 */  cvt.d.s   $f0, $f0
/* 1A38C 8003EF8C 46220000 */  add.d     $f0, $f0, $f2
/* 1A390 8003EF90 3C01400C */  lui       $at, 0x400c
/* 1A394 8003EF94 44812800 */  mtc1      $at, $f5
/* 1A398 8003EF98 44802000 */  mtc1      $zero, $f4
/* 1A39C 8003EF9C 46200020 */  cvt.s.d   $f0, $f0
/* 1A3A0 8003EFA0 460000A1 */  cvt.d.s   $f2, $f0
/* 1A3A4 8003EFA4 4622203C */  c.lt.d    $f4, $f2
/* 1A3A8 8003EFA8 00000000 */  nop
/* 1A3AC 8003EFAC 45000005 */  bc1f      .L8003EFC4
/* 1A3B0 8003EFB0 E4400030 */   swc1     $f0, 0x30($v0)
/* 1A3B4 8003EFB4 3C014060 */  lui       $at, 0x4060
/* 1A3B8 8003EFB8 44810000 */  mtc1      $at, $f0
/* 1A3BC 8003EFBC 00000000 */  nop
/* 1A3C0 8003EFC0 E4400030 */  swc1      $f0, 0x30($v0)
.L8003EFC4:
/* 1A3C4 8003EFC4 3C03800A */  lui       $v1, %hi(D_8009E9B0)
/* 1A3C8 8003EFC8 2463E9B0 */  addiu     $v1, $v1, %lo(D_8009E9B0)
/* 1A3CC 8003EFCC 8C620000 */  lw        $v0, ($v1)
/* 1A3D0 8003EFD0 10400003 */  beqz      $v0, .L8003EFE0
/* 1A3D4 8003EFD4 2442FFFF */   addiu    $v0, $v0, -1
/* 1A3D8 8003EFD8 0800FC0A */  j         .L8003F028
/* 1A3DC 8003EFDC AC620000 */   sw       $v0, ($v1)
.L8003EFE0:
/* 1A3E0 8003EFE0 8D020000 */  lw        $v0, ($t0)
/* 1A3E4 8003EFE4 8C42000C */  lw        $v0, 0xc($v0)
/* 1A3E8 8003EFE8 C4400030 */  lwc1      $f0, 0x30($v0)
/* 1A3EC 8003EFEC 3C013FE0 */  lui       $at, 0x3fe0
/* 1A3F0 8003EFF0 44811800 */  mtc1      $at, $f3
/* 1A3F4 8003EFF4 44801000 */  mtc1      $zero, $f2
/* 1A3F8 8003EFF8 46000021 */  cvt.d.s   $f0, $f0
/* 1A3FC 8003EFFC 46220000 */  add.d     $f0, $f0, $f2
/* 1A400 8003F000 3C014014 */  lui       $at, 0x4014
/* 1A404 8003F004 44812800 */  mtc1      $at, $f5
/* 1A408 8003F008 44802000 */  mtc1      $zero, $f4
/* 1A40C 8003F00C 46200020 */  cvt.s.d   $f0, $f0
/* 1A410 8003F010 460000A1 */  cvt.d.s   $f2, $f0
/* 1A414 8003F014 4622203C */  c.lt.d    $f4, $f2
/* 1A418 8003F018 00000000 */  nop
/* 1A41C 8003F01C 45000002 */  bc1f      .L8003F028
/* 1A420 8003F020 E4400030 */   swc1     $f0, 0x30($v0)
/* 1A424 8003F024 A4E60000 */  sh        $a2, ($a3)
.L8003F028:
/* 1A428 8003F028 0000102D */  daddu     $v0, $zero, $zero
.L8003F02C:
/* 1A42C 8003F02C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1A430 8003F030 8FB20020 */  lw        $s2, 0x20($sp)
/* 1A434 8003F034 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1A438 8003F038 8FB00018 */  lw        $s0, 0x18($sp)
/* 1A43C 8003F03C 03E00008 */  jr        $ra
/* 1A440 8003F040 27BD0028 */   addiu    $sp, $sp, 0x28
