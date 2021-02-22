.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800F09EC
/* 89E9C 800F09EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 89EA0 800F09F0 AFB00018 */  sw        $s0, 0x18($sp)
/* 89EA4 800F09F4 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 89EA8 800F09F8 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 89EAC 800F09FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 89EB0 800F0A00 920400B4 */  lbu       $a0, 0xb4($s0)
/* 89EB4 800F0A04 2482FFFF */  addiu     $v0, $a0, -1
/* 89EB8 800F0A08 2C420002 */  sltiu     $v0, $v0, 2
/* 89EBC 800F0A0C 14400013 */  bnez      $v0, .L800F0A5C
/* 89EC0 800F0A10 3C02FF00 */   lui      $v0, 0xff00
/* 89EC4 800F0A14 8E0300B4 */  lw        $v1, 0xb4($s0)
/* 89EC8 800F0A18 3442FF00 */  ori       $v0, $v0, 0xff00
/* 89ECC 800F0A1C 00621824 */  and       $v1, $v1, $v0
/* 89ED0 800F0A20 3C021A00 */  lui       $v0, 0x1a00
/* 89ED4 800F0A24 1062000D */  beq       $v1, $v0, .L800F0A5C
/* 89ED8 800F0A28 00041600 */   sll      $v0, $a0, 0x18
/* 89EDC 800F0A2C 00021E03 */  sra       $v1, $v0, 0x18
/* 89EE0 800F0A30 2402000A */  addiu     $v0, $zero, 0xa
/* 89EE4 800F0A34 10620003 */  beq       $v1, $v0, .L800F0A44
/* 89EE8 800F0A38 00000000 */   nop
/* 89EEC 800F0A3C 14600004 */  bnez      $v1, .L800F0A50
/* 89EF0 800F0A40 24020004 */   addiu    $v0, $zero, 4
.L800F0A44:
/* 89EF4 800F0A44 8E020000 */  lw        $v0, ($s0)
/* 89EF8 800F0A48 04400004 */  bltz      $v0, .L800F0A5C
/* 89EFC 800F0A4C 24020004 */   addiu    $v0, $zero, 4
.L800F0A50:
/* 89F00 800F0A50 3C018011 */  lui       $at, %hi(D_801094AC)
/* 89F04 800F0A54 0803C2CB */  j         .L800F0B2C
/* 89F08 800F0A58 A42294AC */   sh       $v0, %lo(D_801094AC)($at)
.L800F0A5C:
/* 89F0C 800F0A5C 3C048011 */  lui       $a0, %hi(D_801094AC)
/* 89F10 800F0A60 248494AC */  addiu     $a0, $a0, %lo(D_801094AC)
/* 89F14 800F0A64 94820000 */  lhu       $v0, ($a0)
/* 89F18 800F0A68 24430001 */  addiu     $v1, $v0, 1
/* 89F1C 800F0A6C 00021400 */  sll       $v0, $v0, 0x10
/* 89F20 800F0A70 00021403 */  sra       $v0, $v0, 0x10
/* 89F24 800F0A74 28420004 */  slti      $v0, $v0, 4
/* 89F28 800F0A78 1440002C */  bnez      $v0, .L800F0B2C
/* 89F2C 800F0A7C A4830000 */   sh       $v1, ($a0)
/* 89F30 800F0A80 C60C0084 */  lwc1      $f12, 0x84($s0)
/* 89F34 800F0A84 A4800000 */  sh        $zero, ($a0)
/* 89F38 800F0A88 0C00A6C9 */  jal       clamp_angle
/* 89F3C 800F0A8C 46006307 */   neg.s    $f12, $f12
/* 89F40 800F0A90 3C0140C9 */  lui       $at, 0x40c9
/* 89F44 800F0A94 34210FD0 */  ori       $at, $at, 0xfd0
/* 89F48 800F0A98 44811000 */  mtc1      $at, $f2
/* 89F4C 800F0A9C 00000000 */  nop
/* 89F50 800F0AA0 46020002 */  mul.s     $f0, $f0, $f2
/* 89F54 800F0AA4 00000000 */  nop
/* 89F58 800F0AA8 27A50010 */  addiu     $a1, $sp, 0x10
/* 89F5C 800F0AAC 3C0143B4 */  lui       $at, 0x43b4
/* 89F60 800F0AB0 44816000 */  mtc1      $at, $f12
/* 89F64 800F0AB4 27A60014 */  addiu     $a2, $sp, 0x14
/* 89F68 800F0AB8 0C00A82D */  jal       sin_cos_rad
/* 89F6C 800F0ABC 460C0303 */   div.s    $f12, $f0, $f12
/* 89F70 800F0AC0 860200B2 */  lh        $v0, 0xb2($s0)
/* 89F74 800F0AC4 C7A40010 */  lwc1      $f4, 0x10($sp)
/* 89F78 800F0AC8 44821000 */  mtc1      $v0, $f2
/* 89F7C 800F0ACC 00000000 */  nop
/* 89F80 800F0AD0 468010A0 */  cvt.s.w   $f2, $f2
/* 89F84 800F0AD4 46041102 */  mul.s     $f4, $f2, $f4
/* 89F88 800F0AD8 00000000 */  nop
/* 89F8C 800F0ADC C7A00014 */  lwc1      $f0, 0x14($sp)
/* 89F90 800F0AE0 46001082 */  mul.s     $f2, $f2, $f0
/* 89F94 800F0AE4 00000000 */  nop
/* 89F98 800F0AE8 3C013E4C */  lui       $at, 0x3e4c
/* 89F9C 800F0AEC 3421CCCD */  ori       $at, $at, 0xcccd
/* 89FA0 800F0AF0 44810000 */  mtc1      $at, $f0
/* 89FA4 800F0AF4 00000000 */  nop
/* 89FA8 800F0AF8 46002102 */  mul.s     $f4, $f4, $f0
/* 89FAC 800F0AFC 00000000 */  nop
/* 89FB0 800F0B00 46001082 */  mul.s     $f2, $f2, $f0
/* 89FB4 800F0B04 00000000 */  nop
/* 89FB8 800F0B08 C6000028 */  lwc1      $f0, 0x28($s0)
/* 89FBC 800F0B0C 46040000 */  add.s     $f0, $f0, $f4
/* 89FC0 800F0B10 44050000 */  mfc1      $a1, $f0
/* 89FC4 800F0B14 C6000030 */  lwc1      $f0, 0x30($s0)
/* 89FC8 800F0B18 46020000 */  add.s     $f0, $f0, $f2
/* 89FCC 800F0B1C 3C064220 */  lui       $a2, 0x4220
/* 89FD0 800F0B20 44070000 */  mfc1      $a3, $f0
/* 89FD4 800F0B24 0C01C244 */  jal       func_80070910
/* 89FD8 800F0B28 0000202D */   daddu    $a0, $zero, $zero
.L800F0B2C:
/* 89FDC 800F0B2C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 89FE0 800F0B30 8FB00018 */  lw        $s0, 0x18($sp)
/* 89FE4 800F0B34 03E00008 */  jr        $ra
/* 89FE8 800F0B38 27BD0020 */   addiu    $sp, $sp, 0x20
