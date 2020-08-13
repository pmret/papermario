.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel set_defeated
/* 01A240 8003EE40 0080182D */  daddu $v1, $a0, $zero
/* 01A244 8003EE44 00A0102D */  daddu $v0, $a1, $zero
/* 01A248 8003EE48 04410002 */  bgez  $v0, .L8003EE54
/* 01A24C 8003EE4C 0040202D */   daddu $a0, $v0, $zero
/* 01A250 8003EE50 2444001F */  addiu $a0, $v0, 0x1f
.L8003EE54:
/* 01A254 8003EE54 00042143 */  sra   $a0, $a0, 5
/* 01A258 8003EE58 00042940 */  sll   $a1, $a0, 5
/* 01A25C 8003EE5C 00452823 */  subu  $a1, $v0, $a1
/* 01A260 8003EE60 00042080 */  sll   $a0, $a0, 2
/* 01A264 8003EE64 00031040 */  sll   $v0, $v1, 1
/* 01A268 8003EE68 00431021 */  addu  $v0, $v0, $v1
/* 01A26C 8003EE6C 00021100 */  sll   $v0, $v0, 4
/* 01A270 8003EE70 00822021 */  addu  $a0, $a0, $v0
/* 01A274 8003EE74 3C02800B */  lui   $v0, 0x800b
/* 01A278 8003EE78 24420F10 */  addiu $v0, $v0, 0xf10
/* 01A27C 8003EE7C 00822021 */  addu  $a0, $a0, $v0
/* 01A280 8003EE80 24030001 */  addiu $v1, $zero, 1
/* 01A284 8003EE84 8C8200B0 */  lw    $v0, 0xb0($a0)
/* 01A288 8003EE88 00A31804 */  sllv  $v1, $v1, $a1
/* 01A28C 8003EE8C 00431025 */  or    $v0, $v0, $v1
/* 01A290 8003EE90 03E00008 */  jr    $ra
/* 01A294 8003EE94 AC8200B0 */   sw    $v0, 0xb0($a0)

/* 01A298 8003EE98 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01A29C 8003EE9C 10A00004 */  beqz  $a1, .L8003EEB0
/* 01A2A0 8003EEA0 AFBF0010 */   sw    $ra, 0x10($sp)
/* 01A2A4 8003EEA4 0000202D */  daddu $a0, $zero, $zero
/* 01A2A8 8003EEA8 0C011740 */  jal   func_80045D00
/* 01A2AC 8003EEAC 2405003C */   addiu $a1, $zero, 0x3c
.L8003EEB0:
/* 01A2B0 8003EEB0 0C0117E9 */  jal   func_80045FA4
/* 01A2B4 8003EEB4 00000000 */   nop   
/* 01A2B8 8003EEB8 2C420001 */  sltiu $v0, $v0, 1
/* 01A2BC 8003EEBC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 01A2C0 8003EEC0 00021040 */  sll   $v0, $v0, 1
/* 01A2C4 8003EEC4 03E00008 */  jr    $ra
/* 01A2C8 8003EEC8 27BD0018 */   addiu $sp, $sp, 0x18

/* 01A2CC 8003EECC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01A2D0 8003EED0 10A00004 */  beqz  $a1, .L8003EEE4
/* 01A2D4 8003EED4 AFBF0010 */   sw    $ra, 0x10($sp)
/* 01A2D8 8003EED8 24040001 */  addiu $a0, $zero, 1
/* 01A2DC 8003EEDC 0C011740 */  jal   func_80045D00
/* 01A2E0 8003EEE0 2405003C */   addiu $a1, $zero, 0x3c
.L8003EEE4:
/* 01A2E4 8003EEE4 0C0117E9 */  jal   func_80045FA4
/* 01A2E8 8003EEE8 00000000 */   nop   
/* 01A2EC 8003EEEC 2C420001 */  sltiu $v0, $v0, 1
/* 01A2F0 8003EEF0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 01A2F4 8003EEF4 00021040 */  sll   $v0, $v0, 1
/* 01A2F8 8003EEF8 03E00008 */  jr    $ra
/* 01A2FC 8003EEFC 27BD0018 */   addiu $sp, $sp, 0x18

/* 01A300 8003EF00 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01A304 8003EF04 AFB00010 */  sw    $s0, 0x10($sp)
/* 01A308 8003EF08 0080802D */  daddu $s0, $a0, $zero
/* 01A30C 8003EF0C 10A0000E */  beqz  $a1, .L8003EF48
/* 01A310 8003EF10 AFBF0014 */   sw    $ra, 0x14($sp)
/* 01A314 8003EF14 0C04760B */  jal   func_8011D82C
/* 01A318 8003EF18 24040001 */   addiu $a0, $zero, 1
/* 01A31C 8003EF1C 0000202D */  daddu $a0, $zero, $zero
/* 01A320 8003EF20 0080282D */  daddu $a1, $a0, $zero
/* 01A324 8003EF24 0080302D */  daddu $a2, $a0, $zero
/* 01A328 8003EF28 0080382D */  daddu $a3, $a0, $zero
/* 01A32C 8003EF2C 3C028015 */  lui   $v0, 0x8015
/* 01A330 8003EF30 8C4212F0 */  lw    $v0, 0x12f0($v0)
/* 01A334 8003EF34 24030001 */  addiu $v1, $zero, 1
/* 01A338 8003EF38 0C046F97 */  jal   func_8011BE5C
/* 01A33C 8003EF3C A0430000 */   sb    $v1, ($v0)
/* 01A340 8003EF40 24020019 */  addiu $v0, $zero, 0x19
/* 01A344 8003EF44 AE020070 */  sw    $v0, 0x70($s0)
.L8003EF48:
/* 01A348 8003EF48 0000202D */  daddu $a0, $zero, $zero
/* 01A34C 8003EF4C 0080282D */  daddu $a1, $a0, $zero
/* 01A350 8003EF50 0080302D */  daddu $a2, $a0, $zero
/* 01A354 8003EF54 8E030070 */  lw    $v1, 0x70($s0)
/* 01A358 8003EF58 24020019 */  addiu $v0, $zero, 0x19
/* 01A35C 8003EF5C 00431023 */  subu  $v0, $v0, $v1
/* 01A360 8003EF60 00023880 */  sll   $a3, $v0, 2
/* 01A364 8003EF64 00E23821 */  addu  $a3, $a3, $v0
/* 01A368 8003EF68 00073840 */  sll   $a3, $a3, 1
/* 01A36C 8003EF6C 0C046F97 */  jal   func_8011BE5C
/* 01A370 8003EF70 30E700FE */   andi  $a3, $a3, 0xfe
/* 01A374 8003EF74 8E020070 */  lw    $v0, 0x70($s0)
/* 01A378 8003EF78 2442FFFF */  addiu $v0, $v0, -1
/* 01A37C 8003EF7C AE020070 */  sw    $v0, 0x70($s0)
/* 01A380 8003EF80 2C420001 */  sltiu $v0, $v0, 1
/* 01A384 8003EF84 8FBF0014 */  lw    $ra, 0x14($sp)
/* 01A388 8003EF88 8FB00010 */  lw    $s0, 0x10($sp)
/* 01A38C 8003EF8C 00021040 */  sll   $v0, $v0, 1
/* 01A390 8003EF90 03E00008 */  jr    $ra
/* 01A394 8003EF94 27BD0018 */   addiu $sp, $sp, 0x18

/* 01A398 8003EF98 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01A39C 8003EF9C AFB00010 */  sw    $s0, 0x10($sp)
/* 01A3A0 8003EFA0 0080802D */  daddu $s0, $a0, $zero
/* 01A3A4 8003EFA4 10A00003 */  beqz  $a1, .L8003EFB4
/* 01A3A8 8003EFA8 AFBF0014 */   sw    $ra, 0x14($sp)
/* 01A3AC 8003EFAC 24020019 */  addiu $v0, $zero, 0x19
/* 01A3B0 8003EFB0 AE020070 */  sw    $v0, 0x70($s0)
.L8003EFB4:
/* 01A3B4 8003EFB4 0000202D */  daddu $a0, $zero, $zero
/* 01A3B8 8003EFB8 0080282D */  daddu $a1, $a0, $zero
/* 01A3BC 8003EFBC 8E020070 */  lw    $v0, 0x70($s0)
/* 01A3C0 8003EFC0 0080302D */  daddu $a2, $a0, $zero
/* 01A3C4 8003EFC4 00023880 */  sll   $a3, $v0, 2
/* 01A3C8 8003EFC8 00E23821 */  addu  $a3, $a3, $v0
/* 01A3CC 8003EFCC 00073840 */  sll   $a3, $a3, 1
/* 01A3D0 8003EFD0 0C046F97 */  jal   func_8011BE5C
/* 01A3D4 8003EFD4 30E700FE */   andi  $a3, $a3, 0xfe
/* 01A3D8 8003EFD8 8E020070 */  lw    $v0, 0x70($s0)
/* 01A3DC 8003EFDC 2442FFFB */  addiu $v0, $v0, -5
/* 01A3E0 8003EFE0 10400003 */  beqz  $v0, .L8003EFF0
/* 01A3E4 8003EFE4 AE020070 */   sw    $v0, 0x70($s0)
/* 01A3E8 8003EFE8 0800FC02 */  j     .L8003F008
/* 01A3EC 8003EFEC 0000102D */   daddu $v0, $zero, $zero

.L8003EFF0:
/* 01A3F0 8003EFF0 0000202D */  daddu $a0, $zero, $zero
/* 01A3F4 8003EFF4 0080282D */  daddu $a1, $a0, $zero
/* 01A3F8 8003EFF8 0080302D */  daddu $a2, $a0, $zero
/* 01A3FC 8003EFFC 0C046F97 */  jal   func_8011BE5C
/* 01A400 8003F000 0080382D */   daddu $a3, $a0, $zero
/* 01A404 8003F004 24020002 */  addiu $v0, $zero, 2
.L8003F008:
/* 01A408 8003F008 8FBF0014 */  lw    $ra, 0x14($sp)
/* 01A40C 8003F00C 8FB00010 */  lw    $s0, 0x10($sp)
/* 01A410 8003F010 03E00008 */  jr    $ra
/* 01A414 8003F014 27BD0018 */   addiu $sp, $sp, 0x18

/* 01A418 8003F018 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 01A41C 8003F01C AFB00010 */  sw    $s0, 0x10($sp)
/* 01A420 8003F020 00A0802D */  daddu $s0, $a1, $zero
/* 01A424 8003F024 2404FFF6 */  addiu $a0, $zero, -0xa
/* 01A428 8003F028 AFBF0018 */  sw    $ra, 0x18($sp)
/* 01A42C 8003F02C 0C00EABB */  jal   get_npc_unsafe
/* 01A430 8003F030 AFB10014 */   sw    $s1, 0x14($sp)
/* 01A434 8003F034 12000004 */  beqz  $s0, .L8003F048
/* 01A438 8003F038 0040882D */   daddu $s1, $v0, $zero
/* 01A43C 8003F03C 0C05272D */  jal   play_sound
/* 01A440 8003F040 2404024B */   addiu $a0, $zero, 0x24b
/* 01A444 8003F044 A22000AC */  sb    $zero, 0xac($s1)
.L8003F048:
/* 01A448 8003F048 922200AC */  lbu   $v0, 0xac($s1)
/* 01A44C 8003F04C 24420011 */  addiu $v0, $v0, 0x11
/* 01A450 8003F050 A22200AC */  sb    $v0, 0xac($s1)
/* 01A454 8003F054 304200FF */  andi  $v0, $v0, 0xff
/* 01A458 8003F058 2C4200FF */  sltiu $v0, $v0, 0xff
/* 01A45C 8003F05C 14400004 */  bnez  $v0, .L8003F070
/* 01A460 8003F060 0000102D */   daddu $v0, $zero, $zero
/* 01A464 8003F064 240200FF */  addiu $v0, $zero, 0xff
/* 01A468 8003F068 A22200AC */  sb    $v0, 0xac($s1)
/* 01A46C 8003F06C 24020001 */  addiu $v0, $zero, 1
.L8003F070:
/* 01A470 8003F070 8FBF0018 */  lw    $ra, 0x18($sp)
/* 01A474 8003F074 8FB10014 */  lw    $s1, 0x14($sp)
/* 01A478 8003F078 8FB00010 */  lw    $s0, 0x10($sp)
/* 01A47C 8003F07C 03E00008 */  jr    $ra
/* 01A480 8003F080 27BD0020 */   addiu $sp, $sp, 0x20

/* 01A484 8003F084 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01A488 8003F088 AFBF0010 */  sw    $ra, 0x10($sp)
/* 01A48C 8003F08C 0C00EABB */  jal   get_npc_unsafe
/* 01A490 8003F090 2404FFF6 */   addiu $a0, $zero, -0xa
/* 01A494 8003F094 0040182D */  daddu $v1, $v0, $zero
/* 01A498 8003F098 906200AC */  lbu   $v0, 0xac($v1)
/* 01A49C 8003F09C 2442FFEF */  addiu $v0, $v0, -0x11
/* 01A4A0 8003F0A0 A06200AC */  sb    $v0, 0xac($v1)
/* 01A4A4 8003F0A4 304200FF */  andi  $v0, $v0, 0xff
/* 01A4A8 8003F0A8 14400003 */  bnez  $v0, .L8003F0B8
/* 01A4AC 8003F0AC 0000102D */   daddu $v0, $zero, $zero
/* 01A4B0 8003F0B0 A06000AC */  sb    $zero, 0xac($v1)
/* 01A4B4 8003F0B4 24020001 */  addiu $v0, $zero, 1
.L8003F0B8:
/* 01A4B8 8003F0B8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 01A4BC 8003F0BC 03E00008 */  jr    $ra
/* 01A4C0 8003F0C0 27BD0018 */   addiu $sp, $sp, 0x18

/* 01A4C4 8003F0C4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 01A4C8 8003F0C8 AFB20020 */  sw    $s2, 0x20($sp)
/* 01A4CC 8003F0CC 0080902D */  daddu $s2, $a0, $zero
/* 01A4D0 8003F0D0 AFB00018 */  sw    $s0, 0x18($sp)
/* 01A4D4 8003F0D4 00A0802D */  daddu $s0, $a1, $zero
/* 01A4D8 8003F0D8 2404FFF6 */  addiu $a0, $zero, -0xa
/* 01A4DC 8003F0DC AFBF0024 */  sw    $ra, 0x24($sp)
/* 01A4E0 8003F0E0 0C00EABB */  jal   get_npc_unsafe
/* 01A4E4 8003F0E4 AFB1001C */   sw    $s1, 0x1c($sp)
/* 01A4E8 8003F0E8 12000024 */  beqz  $s0, .L8003F17C
/* 01A4EC 8003F0EC 0040882D */   daddu $s1, $v0, $zero
/* 01A4F0 8003F0F0 AE400074 */  sw    $zero, 0x74($s2)
/* 01A4F4 8003F0F4 C622003C */  lwc1  $f2, 0x3c($s1)
/* 01A4F8 8003F0F8 3C013ECC */  lui   $at, 0x3ecc
/* 01A4FC 8003F0FC 3421CCCD */  ori   $at, $at, 0xcccd
/* 01A500 8003F100 44810000 */  mtc1  $at, $f0
/* 01A504 8003F104 AFA00014 */  sw    $zero, 0x14($sp)
/* 01A508 8003F108 E7A00010 */  swc1  $f0, 0x10($sp)
/* 01A50C 8003F10C 8E250038 */  lw    $a1, 0x38($s1)
/* 01A510 8003F110 8E26003C */  lw    $a2, 0x3c($s1)
/* 01A514 8003F114 8E270040 */  lw    $a3, 0x40($s1)
/* 01A518 8003F118 3C01800A */  lui   $at, 0x800a
/* 01A51C 8003F11C E4220BA4 */  swc1  $f2, 0xba4($at)
/* 01A520 8003F120 0C01C5D4 */  jal   func_80071750
/* 01A524 8003F124 0000202D */   daddu $a0, $zero, $zero
/* 01A528 8003F128 3C013727 */  lui   $at, 0x3727
/* 01A52C 8003F12C 3421C5AC */  ori   $at, $at, 0xc5ac
/* 01A530 8003F130 44810000 */  mtc1  $at, $f0
/* 01A534 8003F134 AFA00014 */  sw    $zero, 0x14($sp)
/* 01A538 8003F138 E7A00010 */  swc1  $f0, 0x10($sp)
/* 01A53C 8003F13C 8E250038 */  lw    $a1, 0x38($s1)
/* 01A540 8003F140 8E26003C */  lw    $a2, 0x3c($s1)
/* 01A544 8003F144 8E270040 */  lw    $a3, 0x40($s1)
/* 01A548 8003F148 3C01800A */  lui   $at, 0x800a
/* 01A54C 8003F14C AC220BA8 */  sw    $v0, 0xba8($at)
/* 01A550 8003F150 0C01C5D4 */  jal   func_80071750
/* 01A554 8003F154 24040003 */   addiu $a0, $zero, 3
/* 01A558 8003F158 3C01800A */  lui   $at, 0x800a
/* 01A55C 8003F15C AC220BAC */  sw    $v0, 0xbac($at)
/* 01A560 8003F160 2402000C */  addiu $v0, $zero, 0xc
/* 01A564 8003F164 3C01800A */  lui   $at, 0x800a
/* 01A568 8003F168 A4200BB8 */  sh    $zero, 0xbb8($at)
/* 01A56C 8003F16C 3C01800A */  lui   $at, 0x800a
/* 01A570 8003F170 AC220BA0 */  sw    $v0, 0xba0($at)
/* 01A574 8003F174 0C05272D */  jal   play_sound
/* 01A578 8003F178 24042074 */   addiu $a0, $zero, 0x2074
.L8003F17C:
/* 01A57C 8003F17C 3C0140C9 */  lui   $at, 0x40c9
/* 01A580 8003F180 34210FD0 */  ori   $at, $at, 0xfd0
/* 01A584 8003F184 44810000 */  mtc1  $at, $f0
/* 01A588 8003F188 C64C0074 */  lwc1  $f12, 0x74($s2)
/* 01A58C 8003F18C 46806320 */  cvt.s.w $f12, $f12
/* 01A590 8003F190 46006302 */  mul.s $f12, $f12, $f0
/* 01A594 8003F194 00000000 */  nop   
/* 01A598 8003F198 3C0143B4 */  lui   $at, 0x43b4
/* 01A59C 8003F19C 44810000 */  mtc1  $at, $f0
/* 01A5A0 8003F1A0 0C00A85B */  jal   sin_rad
/* 01A5A4 8003F1A4 46006303 */   div.s $f12, $f12, $f0
/* 01A5A8 8003F1A8 3C014040 */  lui   $at, 0x4040
/* 01A5AC 8003F1AC 44811000 */  mtc1  $at, $f2
/* 01A5B0 8003F1B0 00000000 */  nop   
/* 01A5B4 8003F1B4 46020002 */  mul.s $f0, $f0, $f2
/* 01A5B8 8003F1B8 00000000 */  nop   
/* 01A5BC 8003F1BC 3C01800A */  lui   $at, 0x800a
/* 01A5C0 8003F1C0 C4220BA4 */  lwc1  $f2, 0xba4($at)
/* 01A5C4 8003F1C4 46001080 */  add.s $f2, $f2, $f0
/* 01A5C8 8003F1C8 E622003C */  swc1  $f2, 0x3c($s1)
/* 01A5CC 8003F1CC 8E420074 */  lw    $v0, 0x74($s2)
/* 01A5D0 8003F1D0 2442000A */  addiu $v0, $v0, 0xa
/* 01A5D4 8003F1D4 44826000 */  mtc1  $v0, $f12
/* 01A5D8 8003F1D8 00000000 */  nop   
/* 01A5DC 8003F1DC 46806320 */  cvt.s.w $f12, $f12
/* 01A5E0 8003F1E0 0C00A6C9 */  jal   clamp_angle
/* 01A5E4 8003F1E4 AE420074 */   sw    $v0, 0x74($s2)
/* 01A5E8 8003F1E8 4600018D */  trunc.w.s $f6, $f0
/* 01A5EC 8003F1EC E6460074 */  swc1  $f6, 0x74($s2)
/* 01A5F0 8003F1F0 3C05800A */  lui   $a1, 0x800a
/* 01A5F4 8003F1F4 8CA50BA8 */  lw    $a1, 0xba8($a1)
/* 01A5F8 8003F1F8 C6200038 */  lwc1  $f0, 0x38($s1)
/* 01A5FC 8003F1FC 3C014180 */  lui   $at, 0x4180
/* 01A600 8003F200 44811000 */  mtc1  $at, $f2
/* 01A604 8003F204 8CA2000C */  lw    $v0, 0xc($a1)
/* 01A608 8003F208 E4400004 */  swc1  $f0, 4($v0)
/* 01A60C 8003F20C C620003C */  lwc1  $f0, 0x3c($s1)
/* 01A610 8003F210 46020000 */  add.s $f0, $f0, $f2
/* 01A614 8003F214 3C08800A */  lui   $t0, 0x800a
/* 01A618 8003F218 25080BAC */  addiu $t0, $t0, 0xbac
/* 01A61C 8003F21C E4400008 */  swc1  $f0, 8($v0)
/* 01A620 8003F220 C6200040 */  lwc1  $f0, 0x40($s1)
/* 01A624 8003F224 8D040000 */  lw    $a0, ($t0)
/* 01A628 8003F228 E440000C */  swc1  $f0, 0xc($v0)
/* 01A62C 8003F22C 8C82000C */  lw    $v0, 0xc($a0)
/* 01A630 8003F230 C6200038 */  lwc1  $f0, 0x38($s1)
/* 01A634 8003F234 E4400004 */  swc1  $f0, 4($v0)
/* 01A638 8003F238 C620003C */  lwc1  $f0, 0x3c($s1)
/* 01A63C 8003F23C 46020000 */  add.s $f0, $f0, $f2
/* 01A640 8003F240 3C0140A0 */  lui   $at, 0x40a0
/* 01A644 8003F244 44811000 */  mtc1  $at, $f2
/* 01A648 8003F248 E4400008 */  swc1  $f0, 8($v0)
/* 01A64C 8003F24C C6200040 */  lwc1  $f0, 0x40($s1)
/* 01A650 8003F250 46020000 */  add.s $f0, $f0, $f2
/* 01A654 8003F254 3C07800A */  lui   $a3, 0x800a
/* 01A658 8003F258 24E70BB8 */  addiu $a3, $a3, 0xbb8
/* 01A65C 8003F25C E440000C */  swc1  $f0, 0xc($v0)
/* 01A660 8003F260 84E30000 */  lh    $v1, ($a3)
/* 01A664 8003F264 24060002 */  addiu $a2, $zero, 2
/* 01A668 8003F268 14660011 */  bne   $v1, $a2, .L8003F2B0
/* 01A66C 8003F26C 24020001 */   addiu $v0, $zero, 1
/* 01A670 8003F270 8CA2000C */  lw    $v0, 0xc($a1)
/* 01A674 8003F274 3C013727 */  lui   $at, 0x3727
/* 01A678 8003F278 3421C5AC */  ori   $at, $at, 0xc5ac
/* 01A67C 8003F27C 44810000 */  mtc1  $at, $f0
/* 01A680 8003F280 00000000 */  nop   
/* 01A684 8003F284 E4400030 */  swc1  $f0, 0x30($v0)
/* 01A688 8003F288 8C82000C */  lw    $v0, 0xc($a0)
/* 01A68C 8003F28C E4400030 */  swc1  $f0, 0x30($v0)
/* 01A690 8003F290 8CA20000 */  lw    $v0, ($a1)
/* 01A694 8003F294 34420010 */  ori   $v0, $v0, 0x10
/* 01A698 8003F298 ACA20000 */  sw    $v0, ($a1)
/* 01A69C 8003F29C 8C830000 */  lw    $v1, ($a0)
/* 01A6A0 8003F2A0 24020001 */  addiu $v0, $zero, 1
/* 01A6A4 8003F2A4 34630010 */  ori   $v1, $v1, 0x10
/* 01A6A8 8003F2A8 0800FCDB */  j     .L8003F36C
/* 01A6AC 8003F2AC AC830000 */   sw    $v1, ($a0)

.L8003F2B0:
/* 01A6B0 8003F2B0 1462002E */  bne   $v1, $v0, .L8003F36C
/* 01A6B4 8003F2B4 0000102D */   daddu $v0, $zero, $zero
/* 01A6B8 8003F2B8 8CA2000C */  lw    $v0, 0xc($a1)
/* 01A6BC 8003F2BC C4400030 */  lwc1  $f0, 0x30($v0)
/* 01A6C0 8003F2C0 3C01800A */  lui   $at, 0x800a
/* 01A6C4 8003F2C4 D42285F0 */  ldc1  $f2, -0x7a10($at)
/* 01A6C8 8003F2C8 46000021 */  cvt.d.s $f0, $f0
/* 01A6CC 8003F2CC 46220000 */  add.d $f0, $f0, $f2
/* 01A6D0 8003F2D0 3C01400C */  lui   $at, 0x400c
/* 01A6D4 8003F2D4 44812800 */  mtc1  $at, $f5
/* 01A6D8 8003F2D8 44802000 */  mtc1  $zero, $f4
/* 01A6DC 8003F2DC 46200020 */  cvt.s.d $f0, $f0
/* 01A6E0 8003F2E0 460000A1 */  cvt.d.s $f2, $f0
/* 01A6E4 8003F2E4 4622203C */  c.lt.d $f4, $f2
/* 01A6E8 8003F2E8 00000000 */  nop   
/* 01A6EC 8003F2EC 45000005 */  bc1f  .L8003F304
/* 01A6F0 8003F2F0 E4400030 */   swc1  $f0, 0x30($v0)
/* 01A6F4 8003F2F4 3C014060 */  lui   $at, 0x4060
/* 01A6F8 8003F2F8 44810000 */  mtc1  $at, $f0
/* 01A6FC 8003F2FC 00000000 */  nop   
/* 01A700 8003F300 E4400030 */  swc1  $f0, 0x30($v0)
.L8003F304:
/* 01A704 8003F304 3C03800A */  lui   $v1, 0x800a
/* 01A708 8003F308 24630BA0 */  addiu $v1, $v1, 0xba0
/* 01A70C 8003F30C 8C620000 */  lw    $v0, ($v1)
/* 01A710 8003F310 10400003 */  beqz  $v0, .L8003F320
/* 01A714 8003F314 2442FFFF */   addiu $v0, $v0, -1
/* 01A718 8003F318 0800FCDA */  j     .L8003F368
/* 01A71C 8003F31C AC620000 */   sw    $v0, ($v1)

.L8003F320:
/* 01A720 8003F320 8D020000 */  lw    $v0, ($t0)
/* 01A724 8003F324 8C42000C */  lw    $v0, 0xc($v0)
/* 01A728 8003F328 C4400030 */  lwc1  $f0, 0x30($v0)
/* 01A72C 8003F32C 3C013FE0 */  lui   $at, 0x3fe0
/* 01A730 8003F330 44811800 */  mtc1  $at, $f3
/* 01A734 8003F334 44801000 */  mtc1  $zero, $f2
/* 01A738 8003F338 46000021 */  cvt.d.s $f0, $f0
/* 01A73C 8003F33C 46220000 */  add.d $f0, $f0, $f2
/* 01A740 8003F340 3C014014 */  lui   $at, 0x4014
/* 01A744 8003F344 44812800 */  mtc1  $at, $f5
/* 01A748 8003F348 44802000 */  mtc1  $zero, $f4
/* 01A74C 8003F34C 46200020 */  cvt.s.d $f0, $f0
/* 01A750 8003F350 460000A1 */  cvt.d.s $f2, $f0
/* 01A754 8003F354 4622203C */  c.lt.d $f4, $f2
/* 01A758 8003F358 00000000 */  nop   
/* 01A75C 8003F35C 45000002 */  bc1f  .L8003F368
/* 01A760 8003F360 E4400030 */   swc1  $f0, 0x30($v0)
/* 01A764 8003F364 A4E60000 */  sh    $a2, ($a3)
.L8003F368:
/* 01A768 8003F368 0000102D */  daddu $v0, $zero, $zero
.L8003F36C:
/* 01A76C 8003F36C 8FBF0024 */  lw    $ra, 0x24($sp)
/* 01A770 8003F370 8FB20020 */  lw    $s2, 0x20($sp)
/* 01A774 8003F374 8FB1001C */  lw    $s1, 0x1c($sp)
/* 01A778 8003F378 8FB00018 */  lw    $s0, 0x18($sp)
/* 01A77C 8003F37C 03E00008 */  jr    $ra
/* 01A780 8003F380 27BD0028 */   addiu $sp, $sp, 0x28

/* 01A784 8003F384 24020001 */  addiu $v0, $zero, 1
/* 01A788 8003F388 3C01800A */  lui   $at, 0x800a
/* 01A78C 8003F38C A4220BB8 */  sh    $v0, 0xbb8($at)
/* 01A790 8003F390 03E00008 */  jr    $ra
/* 01A794 8003F394 24020002 */   addiu $v0, $zero, 2

