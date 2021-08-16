.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00EA000
/* 3E1EE0 E00EA000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3E1EE4 E00EA004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3E1EE8 E00EA008 4485A000 */  mtc1      $a1, $f20
/* 3E1EEC E00EA00C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3E1EF0 E00EA010 4486B000 */  mtc1      $a2, $f22
/* 3E1EF4 E00EA014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3E1EF8 E00EA018 0080902D */  daddu     $s2, $a0, $zero
/* 3E1EFC E00EA01C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3E1F00 E00EA020 4487C000 */  mtc1      $a3, $f24
/* 3E1F04 E00EA024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3E1F08 E00EA028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3E1F0C E00EA02C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3E1F10 E00EA030 3C02E00F */  lui       $v0, %hi(func_E00EA190)
/* 3E1F14 E00EA034 2442A190 */  addiu     $v0, $v0, %lo(func_E00EA190)
/* 3E1F18 E00EA038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3E1F1C E00EA03C 3C02E00F */  lui       $v0, %hi(func_E00EA198)
/* 3E1F20 E00EA040 2442A198 */  addiu     $v0, $v0, %lo(func_E00EA198)
/* 3E1F24 E00EA044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3E1F28 E00EA048 3C02E00F */  lui       $v0, %hi(func_E00EA520)
/* 3E1F2C E00EA04C 2442A520 */  addiu     $v0, $v0, %lo(func_E00EA520)
/* 3E1F30 E00EA050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3E1F34 E00EA054 24020075 */  addiu     $v0, $zero, 0x75
/* 3E1F38 E00EA058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3E1F3C E00EA05C AFB00028 */  sw        $s0, 0x28($sp)
/* 3E1F40 E00EA060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3E1F44 E00EA064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3E1F48 E00EA068 0C080124 */  jal       func_E0200490
/* 3E1F4C E00EA06C AFA20014 */   sw       $v0, 0x14($sp)
/* 3E1F50 E00EA070 24040080 */  addiu     $a0, $zero, 0x80
/* 3E1F54 E00EA074 24030001 */  addiu     $v1, $zero, 1
/* 3E1F58 E00EA078 0040802D */  daddu     $s0, $v0, $zero
/* 3E1F5C E00EA07C 0C08012C */  jal       func_E02004B0
/* 3E1F60 E00EA080 AE030008 */   sw       $v1, 8($s0)
/* 3E1F64 E00EA084 0040202D */  daddu     $a0, $v0, $zero
/* 3E1F68 E00EA088 14800003 */  bnez      $a0, .LE00EA098
/* 3E1F6C E00EA08C AE02000C */   sw       $v0, 0xc($s0)
.LE00EA090:
/* 3E1F70 E00EA090 0803A824 */  j         .LE00EA090
/* 3E1F74 E00EA094 00000000 */   nop
.LE00EA098:
/* 3E1F78 E00EA098 AC920000 */  sw        $s2, ($a0)
/* 3E1F7C E00EA09C 1E200004 */  bgtz      $s1, .LE00EA0B0
/* 3E1F80 E00EA0A0 AC800014 */   sw       $zero, 0x14($a0)
/* 3E1F84 E00EA0A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3E1F88 E00EA0A8 0803A82D */  j         .LE00EA0B4
/* 3E1F8C E00EA0AC AC820010 */   sw       $v0, 0x10($a0)
.LE00EA0B0:
/* 3E1F90 E00EA0B0 AC910010 */  sw        $s1, 0x10($a0)
.LE00EA0B4:
/* 3E1F94 E00EA0B4 0200102D */  daddu     $v0, $s0, $zero
/* 3E1F98 E00EA0B8 AC800024 */  sw        $zero, 0x24($a0)
/* 3E1F9C E00EA0BC E4940004 */  swc1      $f20, 4($a0)
/* 3E1FA0 E00EA0C0 E4960008 */  swc1      $f22, 8($a0)
/* 3E1FA4 E00EA0C4 E498000C */  swc1      $f24, 0xc($a0)
/* 3E1FA8 E00EA0C8 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3E1FAC E00EA0CC 3C013F66 */  lui       $at, 0x3f66
/* 3E1FB0 E00EA0D0 34216666 */  ori       $at, $at, 0x6666
/* 3E1FB4 E00EA0D4 44811000 */  mtc1      $at, $f2
/* 3E1FB8 E00EA0D8 3C01C000 */  lui       $at, 0xc000
/* 3E1FBC E00EA0DC 44812000 */  mtc1      $at, $f4
/* 3E1FC0 E00EA0E0 3C013FA0 */  lui       $at, 0x3fa0
/* 3E1FC4 E00EA0E4 44813000 */  mtc1      $at, $f6
/* 3E1FC8 E00EA0E8 3C01433E */  lui       $at, 0x433e
/* 3E1FCC E00EA0EC 44814000 */  mtc1      $at, $f8
/* 3E1FD0 E00EA0F0 3C01435C */  lui       $at, 0x435c
/* 3E1FD4 E00EA0F4 44815000 */  mtc1      $at, $f10
/* 3E1FD8 E00EA0F8 240300B4 */  addiu     $v1, $zero, 0xb4
/* 3E1FDC E00EA0FC AC83001C */  sw        $v1, 0x1c($a0)
/* 3E1FE0 E00EA100 E480003C */  swc1      $f0, 0x3c($a0)
/* 3E1FE4 E00EA104 3C013F80 */  lui       $at, 0x3f80
/* 3E1FE8 E00EA108 44810000 */  mtc1      $at, $f0
/* 3E1FEC E00EA10C 240300DC */  addiu     $v1, $zero, 0xdc
/* 3E1FF0 E00EA110 AC800018 */  sw        $zero, 0x18($a0)
/* 3E1FF4 E00EA114 AC830020 */  sw        $v1, 0x20($a0)
/* 3E1FF8 E00EA118 AC800028 */  sw        $zero, 0x28($a0)
/* 3E1FFC E00EA11C AC80002C */  sw        $zero, 0x2c($a0)
/* 3E2000 E00EA120 AC800030 */  sw        $zero, 0x30($a0)
/* 3E2004 E00EA124 AC800034 */  sw        $zero, 0x34($a0)
/* 3E2008 E00EA128 AC800038 */  sw        $zero, 0x38($a0)
/* 3E200C E00EA12C AC800040 */  sw        $zero, 0x40($a0)
/* 3E2010 E00EA130 AC800044 */  sw        $zero, 0x44($a0)
/* 3E2014 E00EA134 AC800050 */  sw        $zero, 0x50($a0)
/* 3E2018 E00EA138 AC800054 */  sw        $zero, 0x54($a0)
/* 3E201C E00EA13C E482004C */  swc1      $f2, 0x4c($a0)
/* 3E2020 E00EA140 E482006C */  swc1      $f2, 0x6c($a0)
/* 3E2024 E00EA144 E4840058 */  swc1      $f4, 0x58($a0)
/* 3E2028 E00EA148 E4840070 */  swc1      $f4, 0x70($a0)
/* 3E202C E00EA14C E486005C */  swc1      $f6, 0x5c($a0)
/* 3E2030 E00EA150 E4860074 */  swc1      $f6, 0x74($a0)
/* 3E2034 E00EA154 E4880060 */  swc1      $f8, 0x60($a0)
/* 3E2038 E00EA158 E4880078 */  swc1      $f8, 0x78($a0)
/* 3E203C E00EA15C E48A0064 */  swc1      $f10, 0x64($a0)
/* 3E2040 E00EA160 E48A007C */  swc1      $f10, 0x7c($a0)
/* 3E2044 E00EA164 E4800048 */  swc1      $f0, 0x48($a0)
/* 3E2048 E00EA168 E4800068 */  swc1      $f0, 0x68($a0)
/* 3E204C E00EA16C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3E2050 E00EA170 8FB20030 */  lw        $s2, 0x30($sp)
/* 3E2054 E00EA174 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3E2058 E00EA178 8FB00028 */  lw        $s0, 0x28($sp)
/* 3E205C E00EA17C D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3E2060 E00EA180 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3E2064 E00EA184 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3E2068 E00EA188 03E00008 */  jr        $ra
/* 3E206C E00EA18C 27BD0050 */   addiu    $sp, $sp, 0x50
