.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_8029CC20
.double 0.4

.section .text

glabel func_8024AFE4
/* 1798C4 8024AFE4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 1798C8 8024AFE8 AFB00020 */  sw        $s0, 0x20($sp)
/* 1798CC 8024AFEC 3C10800B */  lui       $s0, %hi(gCameras+0x558)
/* 1798D0 8024AFF0 261022D8 */  addiu     $s0, $s0, %lo(gCameras+0x558)
/* 1798D4 8024AFF4 3C02802A */  lui       $v0, %hi(D_8029F27C)
/* 1798D8 8024AFF8 9442F27C */  lhu       $v0, %lo(D_8029F27C)($v0)
/* 1798DC 8024AFFC 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 1798E0 8024B000 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 1798E4 8024B004 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1798E8 8024B008 F7BE0050 */  sdc1      $f30, 0x50($sp)
/* 1798EC 8024B00C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 1798F0 8024B010 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 1798F4 8024B014 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 1798F8 8024B018 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 1798FC 8024B01C F7B40028 */  sdc1      $f20, 0x28($sp)
/* 179900 8024B020 30430700 */  andi      $v1, $v0, 0x700
/* 179904 8024B024 304600FF */  andi      $a2, $v0, 0xff
/* 179908 8024B028 24020100 */  addiu     $v0, $zero, 0x100
/* 17990C 8024B02C 10620026 */  beq       $v1, $v0, .L8024B0C8
/* 179910 8024B030 28620101 */   slti     $v0, $v1, 0x101
/* 179914 8024B034 10400005 */  beqz      $v0, .L8024B04C
/* 179918 8024B038 24020200 */   addiu    $v0, $zero, 0x200
/* 17991C 8024B03C 10600007 */  beqz      $v1, .L8024B05C
/* 179920 8024B040 24020002 */   addiu    $v0, $zero, 2
/* 179924 8024B044 08092D75 */  j         .L8024B5D4
/* 179928 8024B048 00000000 */   nop
.L8024B04C:
/* 17992C 8024B04C 10620021 */  beq       $v1, $v0, .L8024B0D4
/* 179930 8024B050 24020002 */   addiu    $v0, $zero, 2
/* 179934 8024B054 08092D75 */  j         .L8024B5D4
/* 179938 8024B058 00000000 */   nop
.L8024B05C:
/* 17993C 8024B05C 8C8400D8 */  lw        $a0, 0xd8($a0)
/* 179940 8024B060 1080015C */  beqz      $a0, .L8024B5D4
/* 179944 8024B064 0000102D */   daddu    $v0, $zero, $zero
/* 179948 8024B068 C49E001C */  lwc1      $f30, 0x1c($a0)
/* 17994C 8024B06C C4860144 */  lwc1      $f6, 0x144($a0)
/* 179950 8024B070 C49A0018 */  lwc1      $f26, 0x18($a0)
/* 179954 8024B074 E7BE0018 */  swc1      $f30, 0x18($sp)
/* 179958 8024B078 90830191 */  lbu       $v1, 0x191($a0)
/* 17995C 8024B07C 90820190 */  lbu       $v0, 0x190($a0)
/* 179960 8024B080 C49E0020 */  lwc1      $f30, 0x20($a0)
/* 179964 8024B084 00621821 */  addu      $v1, $v1, $v0
/* 179968 8024B088 00031843 */  sra       $v1, $v1, 1
/* 17996C 8024B08C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 179970 8024B090 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 179974 8024B094 E7BE0010 */  swc1      $f30, 0x10($sp)
/* 179978 8024B098 944200B0 */  lhu       $v0, 0xb0($v0)
/* 17997C 8024B09C 4483F000 */  mtc1      $v1, $f30
/* 179980 8024B0A0 00000000 */  nop
/* 179984 8024B0A4 4680F7A0 */  cvt.s.w   $f30, $f30
/* 179988 8024B0A8 E7BE0014 */  swc1      $f30, 0x14($sp)
/* 17998C 8024B0AC C4820148 */  lwc1      $f2, 0x148($a0)
/* 179990 8024B0B0 00021400 */  sll       $v0, $v0, 0x10
/* 179994 8024B0B4 00021C03 */  sra       $v1, $v0, 0x10
/* 179998 8024B0B8 000217C2 */  srl       $v0, $v0, 0x1f
/* 17999C 8024B0BC 00621821 */  addu      $v1, $v1, $v0
/* 1799A0 8024B0C0 08092C4A */  j         .L8024B128
/* 1799A4 8024B0C4 00031843 */   sra      $v1, $v1, 1
.L8024B0C8:
/* 1799A8 8024B0C8 8C8400DC */  lw        $a0, 0xdc($a0)
/* 1799AC 8024B0CC 08092C38 */  j         .L8024B0E0
/* 1799B0 8024B0D0 00000000 */   nop
.L8024B0D4:
/* 1799B4 8024B0D4 00061080 */  sll       $v0, $a2, 2
/* 1799B8 8024B0D8 00441021 */  addu      $v0, $v0, $a0
/* 1799BC 8024B0DC 8C4400E0 */  lw        $a0, 0xe0($v0)
.L8024B0E0:
/* 1799C0 8024B0E0 1080013C */  beqz      $a0, .L8024B5D4
/* 1799C4 8024B0E4 0000102D */   daddu    $v0, $zero, $zero
/* 1799C8 8024B0E8 C49E001C */  lwc1      $f30, 0x1c($a0)
/* 1799CC 8024B0EC C4860144 */  lwc1      $f6, 0x144($a0)
/* 1799D0 8024B0F0 C49A0018 */  lwc1      $f26, 0x18($a0)
/* 1799D4 8024B0F4 E7BE0018 */  swc1      $f30, 0x18($sp)
/* 1799D8 8024B0F8 90830191 */  lbu       $v1, 0x191($a0)
/* 1799DC 8024B0FC 90820190 */  lbu       $v0, 0x190($a0)
/* 1799E0 8024B100 C49E0020 */  lwc1      $f30, 0x20($a0)
/* 1799E4 8024B104 00621021 */  addu      $v0, $v1, $v0
/* 1799E8 8024B108 00021043 */  sra       $v0, $v0, 1
/* 1799EC 8024B10C E7BE0010 */  swc1      $f30, 0x10($sp)
/* 1799F0 8024B110 4482F000 */  mtc1      $v0, $f30
/* 1799F4 8024B114 00000000 */  nop
/* 1799F8 8024B118 4680F7A0 */  cvt.s.w   $f30, $f30
/* 1799FC 8024B11C 00031842 */  srl       $v1, $v1, 1
/* 179A00 8024B120 E7BE0014 */  swc1      $f30, 0x14($sp)
/* 179A04 8024B124 C4820148 */  lwc1      $f2, 0x148($a0)
.L8024B128:
/* 179A08 8024B128 44830000 */  mtc1      $v1, $f0
/* 179A0C 8024B12C 00000000 */  nop
/* 179A10 8024B130 46800020 */  cvt.s.w   $f0, $f0
/* 179A14 8024B134 3C02802A */  lui       $v0, %hi(D_8029F2A2)
/* 179A18 8024B138 8042F2A2 */  lb        $v0, %lo(D_8029F2A2)($v0)
/* 179A1C 8024B13C 1040000F */  beqz      $v0, .L8024B17C
/* 179A20 8024B140 46001000 */   add.s    $f0, $f2, $f0
/* 179A24 8024B144 C7BE0018 */  lwc1      $f30, 0x18($sp)
/* 179A28 8024B148 461E0001 */  sub.s     $f0, $f0, $f30
/* 179A2C 8024B14C 3C013F00 */  lui       $at, 0x3f00
/* 179A30 8024B150 44811000 */  mtc1      $at, $f2
/* 179A34 8024B154 00000000 */  nop
/* 179A38 8024B158 46020082 */  mul.s     $f2, $f0, $f2
/* 179A3C 8024B15C 00000000 */  nop
/* 179A40 8024B160 3C0140C0 */  lui       $at, 0x40c0
/* 179A44 8024B164 44812000 */  mtc1      $at, $f4
/* 179A48 8024B168 00000000 */  nop
/* 179A4C 8024B16C 46040003 */  div.s     $f0, $f0, $f4
/* 179A50 8024B170 46001080 */  add.s     $f2, $f2, $f0
/* 179A54 8024B174 4602F780 */  add.s     $f30, $f30, $f2
/* 179A58 8024B178 E7BE0018 */  swc1      $f30, 0x18($sp)
.L8024B17C:
/* 179A5C 8024B17C 3C02802A */  lui       $v0, %hi(D_8029F2A3)
/* 179A60 8024B180 8042F2A3 */  lb        $v0, %lo(D_8029F2A3)($v0)
/* 179A64 8024B184 10400012 */  beqz      $v0, .L8024B1D0
/* 179A68 8024B188 00000000 */   nop
/* 179A6C 8024B18C 461A3001 */  sub.s     $f0, $f6, $f26
/* 179A70 8024B190 3C013F00 */  lui       $at, 0x3f00
/* 179A74 8024B194 44811000 */  mtc1      $at, $f2
/* 179A78 8024B198 00000000 */  nop
/* 179A7C 8024B19C 46020002 */  mul.s     $f0, $f0, $f2
/* 179A80 8024B1A0 00000000 */  nop
/* 179A84 8024B1A4 4600D680 */  add.s     $f26, $f26, $f0
/* 179A88 8024B1A8 3C014296 */  lui       $at, 0x4296
/* 179A8C 8024B1AC 44810000 */  mtc1      $at, $f0
/* 179A90 8024B1B0 00000000 */  nop
/* 179A94 8024B1B4 461A003C */  c.lt.s    $f0, $f26
/* 179A98 8024B1B8 00000000 */  nop
/* 179A9C 8024B1BC 45000004 */  bc1f      .L8024B1D0
/* 179AA0 8024B1C0 00000000 */   nop
/* 179AA4 8024B1C4 461A0001 */  sub.s     $f0, $f0, $f26
/* 179AA8 8024B1C8 46000005 */  abs.s     $f0, $f0
/* 179AAC 8024B1CC 4600D681 */  sub.s     $f26, $f26, $f0
.L8024B1D0:
/* 179AB0 8024B1D0 3C02802A */  lui       $v0, %hi(D_8029F2A6)
/* 179AB4 8024B1D4 8042F2A6 */  lb        $v0, %lo(D_8029F2A6)($v0)
/* 179AB8 8024B1D8 10400029 */  beqz      $v0, .L8024B280
/* 179ABC 8024B1DC 00000000 */   nop
/* 179AC0 8024B1E0 3C01802A */  lui       $at, %hi(D_8029F28C)
/* 179AC4 8024B1E4 C422F28C */  lwc1      $f2, %lo(D_8029F28C)($at)
/* 179AC8 8024B1E8 3C0143FA */  lui       $at, 0x43fa
/* 179ACC 8024B1EC 44810000 */  mtc1      $at, $f0
/* 179AD0 8024B1F0 00000000 */  nop
/* 179AD4 8024B1F4 46020001 */  sub.s     $f0, $f0, $f2
/* 179AD8 8024B1F8 3C01802A */  lui       $at, %hi(D_8029CC20)
/* 179ADC 8024B1FC D422CC20 */  ldc1      $f2, %lo(D_8029CC20)($at)
/* 179AE0 8024B200 46000021 */  cvt.d.s   $f0, $f0
/* 179AE4 8024B204 46220002 */  mul.d     $f0, $f0, $f2
/* 179AE8 8024B208 00000000 */  nop
/* 179AEC 8024B20C 3C01403E */  lui       $at, 0x403e
/* 179AF0 8024B210 44811800 */  mtc1      $at, $f3
/* 179AF4 8024B214 44801000 */  mtc1      $zero, $f2
/* 179AF8 8024B218 00000000 */  nop
/* 179AFC 8024B21C 46220000 */  add.d     $f0, $f0, $f2
/* 179B00 8024B220 46200120 */  cvt.s.d   $f4, $f0
/* 179B04 8024B224 46002007 */  neg.s     $f0, $f4
/* 179B08 8024B228 4600D03C */  c.lt.s    $f26, $f0
/* 179B0C 8024B22C 00000000 */  nop
/* 179B10 8024B230 45000008 */  bc1f      .L8024B254
/* 179B14 8024B234 00000000 */   nop
/* 179B18 8024B238 461A0001 */  sub.s     $f0, $f0, $f26
/* 179B1C 8024B23C 3C013F00 */  lui       $at, 0x3f00
/* 179B20 8024B240 44811000 */  mtc1      $at, $f2
/* 179B24 8024B244 00000000 */  nop
/* 179B28 8024B248 46020002 */  mul.s     $f0, $f0, $f2
/* 179B2C 8024B24C 00000000 */  nop
/* 179B30 8024B250 4600D680 */  add.s     $f26, $f26, $f0
.L8024B254:
/* 179B34 8024B254 461A203C */  c.lt.s    $f4, $f26
/* 179B38 8024B258 00000000 */  nop
/* 179B3C 8024B25C 45000008 */  bc1f      .L8024B280
/* 179B40 8024B260 00000000 */   nop
/* 179B44 8024B264 461A2001 */  sub.s     $f0, $f4, $f26
/* 179B48 8024B268 3C013F00 */  lui       $at, 0x3f00
/* 179B4C 8024B26C 44811000 */  mtc1      $at, $f2
/* 179B50 8024B270 00000000 */  nop
/* 179B54 8024B274 46020002 */  mul.s     $f0, $f0, $f2
/* 179B58 8024B278 00000000 */  nop
/* 179B5C 8024B27C 4600D680 */  add.s     $f26, $f26, $f0
.L8024B280:
/* 179B60 8024B280 10A00029 */  beqz      $a1, .L8024B328
/* 179B64 8024B284 00000000 */   nop
/* 179B68 8024B288 8602001E */  lh        $v0, 0x1e($s0)
/* 179B6C 8024B28C 86040026 */  lh        $a0, 0x26($s0)
/* 179B70 8024B290 86030024 */  lh        $v1, 0x24($s0)
/* 179B74 8024B294 44820000 */  mtc1      $v0, $f0
/* 179B78 8024B298 00000000 */  nop
/* 179B7C 8024B29C 46800020 */  cvt.s.w   $f0, $f0
/* 179B80 8024B2A0 86020022 */  lh        $v0, 0x22($s0)
/* 179B84 8024B2A4 3C01802A */  lui       $at, %hi(D_8029F28C)
/* 179B88 8024B2A8 E420F28C */  swc1      $f0, %lo(D_8029F28C)($at)
/* 179B8C 8024B2AC 44820000 */  mtc1      $v0, $f0
/* 179B90 8024B2B0 00000000 */  nop
/* 179B94 8024B2B4 46800020 */  cvt.s.w   $f0, $f0
/* 179B98 8024B2B8 3C01802A */  lui       $at, %hi(D_8029F294)
/* 179B9C 8024B2BC E420F294 */  swc1      $f0, %lo(D_8029F294)($at)
/* 179BA0 8024B2C0 44830000 */  mtc1      $v1, $f0
/* 179BA4 8024B2C4 00000000 */  nop
/* 179BA8 8024B2C8 46800020 */  cvt.s.w   $f0, $f0
/* 179BAC 8024B2CC 3C01802A */  lui       $at, %hi(D_8029F290)
/* 179BB0 8024B2D0 E420F290 */  swc1      $f0, %lo(D_8029F290)($at)
/* 179BB4 8024B2D4 04820001 */  bltzl     $a0, .L8024B2DC
/* 179BB8 8024B2D8 248400FF */   addiu    $a0, $a0, 0xff
.L8024B2DC:
/* 179BBC 8024B2DC 00041203 */  sra       $v0, $a0, 8
/* 179BC0 8024B2E0 C6020054 */  lwc1      $f2, 0x54($s0)
/* 179BC4 8024B2E4 C6040058 */  lwc1      $f4, 0x58($s0)
/* 179BC8 8024B2E8 C606005C */  lwc1      $f6, 0x5c($s0)
/* 179BCC 8024B2EC 3C03802A */  lui       $v1, %hi(D_8029F29E)
/* 179BD0 8024B2F0 9463F29E */  lhu       $v1, %lo(D_8029F29E)($v1)
/* 179BD4 8024B2F4 44820000 */  mtc1      $v0, $f0
/* 179BD8 8024B2F8 00000000 */  nop
/* 179BDC 8024B2FC 46800020 */  cvt.s.w   $f0, $f0
/* 179BE0 8024B300 3C01802A */  lui       $at, %hi(D_8029F298)
/* 179BE4 8024B304 E420F298 */  swc1      $f0, %lo(D_8029F298)($at)
/* 179BE8 8024B308 3C01802A */  lui       $at, %hi(D_8029F2A8)
/* 179BEC 8024B30C E422F2A8 */  swc1      $f2, %lo(D_8029F2A8)($at)
/* 179BF0 8024B310 3C01802A */  lui       $at, %hi(D_8029F2AC)
/* 179BF4 8024B314 E424F2AC */  swc1      $f4, %lo(D_8029F2AC)($at)
/* 179BF8 8024B318 3C01802A */  lui       $at, %hi(D_8029F2B0)
/* 179BFC 8024B31C E426F2B0 */  swc1      $f6, %lo(D_8029F2B0)($at)
/* 179C00 8024B320 3C01802A */  lui       $at, %hi(D_8029F2A0)
/* 179C04 8024B324 A423F2A0 */  sh        $v1, %lo(D_8029F2A0)($at)
.L8024B328:
/* 179C08 8024B328 3C02802A */  lui       $v0, %hi(D_8029F2A5)
/* 179C0C 8024B32C 8042F2A5 */  lb        $v0, %lo(D_8029F2A5)($v0)
/* 179C10 8024B330 14400027 */  bnez      $v0, .L8024B3D0
/* 179C14 8024B334 00000000 */   nop
/* 179C18 8024B338 3C02802A */  lui       $v0, %hi(D_8029F29E)
/* 179C1C 8024B33C 8442F29E */  lh        $v0, %lo(D_8029F29E)($v0)
/* 179C20 8024B340 3C03802A */  lui       $v1, %hi(D_8029F2A0)
/* 179C24 8024B344 8463F2A0 */  lh        $v1, %lo(D_8029F2A0)($v1)
/* 179C28 8024B348 3C013F80 */  lui       $at, 0x3f80
/* 179C2C 8024B34C 4481C000 */  mtc1      $at, $f24
/* 179C30 8024B350 4482E000 */  mtc1      $v0, $f28
/* 179C34 8024B354 00000000 */  nop
/* 179C38 8024B358 4680E720 */  cvt.s.w   $f28, $f28
/* 179C3C 8024B35C 44830000 */  mtc1      $v1, $f0
/* 179C40 8024B360 00000000 */  nop
/* 179C44 8024B364 46800020 */  cvt.s.w   $f0, $f0
/* 179C48 8024B368 4600E703 */  div.s     $f28, $f28, $f0
/* 179C4C 8024B36C 461CC301 */  sub.s     $f12, $f24, $f28
/* 179C50 8024B370 3C014049 */  lui       $at, 0x4049
/* 179C54 8024B374 34210FD0 */  ori       $at, $at, 0xfd0
/* 179C58 8024B378 4481B000 */  mtc1      $at, $f22
/* 179C5C 8024B37C 00000000 */  nop
/* 179C60 8024B380 46166302 */  mul.s     $f12, $f12, $f22
/* 179C64 8024B384 00000000 */  nop
/* 179C68 8024B388 3C013F00 */  lui       $at, 0x3f00
/* 179C6C 8024B38C 4481A000 */  mtc1      $at, $f20
/* 179C70 8024B390 00000000 */  nop
/* 179C74 8024B394 46146302 */  mul.s     $f12, $f12, $f20
/* 179C78 8024B398 0C00A85B */  jal       sin_rad
/* 179C7C 8024B39C 00000000 */   nop
/* 179C80 8024B3A0 46160002 */  mul.s     $f0, $f0, $f22
/* 179C84 8024B3A4 00000000 */  nop
/* 179C88 8024B3A8 46140302 */  mul.s     $f12, $f0, $f20
/* 179C8C 8024B3AC 0C00A85B */  jal       sin_rad
/* 179C90 8024B3B0 00000000 */   nop
/* 179C94 8024B3B4 46160002 */  mul.s     $f0, $f0, $f22
/* 179C98 8024B3B8 00000000 */  nop
/* 179C9C 8024B3BC 46140302 */  mul.s     $f12, $f0, $f20
/* 179CA0 8024B3C0 0C00A85B */  jal       sin_rad
/* 179CA4 8024B3C4 00000000 */   nop
/* 179CA8 8024B3C8 08092CFF */  j         .L8024B3FC
/* 179CAC 8024B3CC 4600C701 */   sub.s    $f28, $f24, $f0
.L8024B3D0:
/* 179CB0 8024B3D0 3C02802A */  lui       $v0, %hi(D_8029F29E)
/* 179CB4 8024B3D4 8442F29E */  lh        $v0, %lo(D_8029F29E)($v0)
/* 179CB8 8024B3D8 3C03802A */  lui       $v1, %hi(D_8029F2A0)
/* 179CBC 8024B3DC 8463F2A0 */  lh        $v1, %lo(D_8029F2A0)($v1)
/* 179CC0 8024B3E0 4482E000 */  mtc1      $v0, $f28
/* 179CC4 8024B3E4 00000000 */  nop
/* 179CC8 8024B3E8 4680E720 */  cvt.s.w   $f28, $f28
/* 179CCC 8024B3EC 44830000 */  mtc1      $v1, $f0
/* 179CD0 8024B3F0 00000000 */  nop
/* 179CD4 8024B3F4 46800020 */  cvt.s.w   $f0, $f0
/* 179CD8 8024B3F8 4600E703 */  div.s     $f28, $f28, $f0
.L8024B3FC:
/* 179CDC 8024B3FC 3C01802A */  lui       $at, %hi(D_8029F2A8)
/* 179CE0 8024B400 C434F2A8 */  lwc1      $f20, %lo(D_8029F2A8)($at)
/* 179CE4 8024B404 461CA502 */  mul.s     $f20, $f20, $f28
/* 179CE8 8024B408 00000000 */  nop
/* 179CEC 8024B40C 3C01802A */  lui       $at, %hi(D_8029F2AC)
/* 179CF0 8024B410 C432F2AC */  lwc1      $f18, %lo(D_8029F2AC)($at)
/* 179CF4 8024B414 461C9482 */  mul.s     $f18, $f18, $f28
/* 179CF8 8024B418 00000000 */  nop
/* 179CFC 8024B41C 3C01802A */  lui       $at, %hi(D_8029F2B0)
/* 179D00 8024B420 C430F2B0 */  lwc1      $f16, %lo(D_8029F2B0)($at)
/* 179D04 8024B424 461C8402 */  mul.s     $f16, $f16, $f28
/* 179D08 8024B428 00000000 */  nop
/* 179D0C 8024B42C 3C01802A */  lui       $at, %hi(D_8029F298)
/* 179D10 8024B430 C42AF298 */  lwc1      $f10, %lo(D_8029F298)($at)
/* 179D14 8024B434 461C5282 */  mul.s     $f10, $f10, $f28
/* 179D18 8024B438 00000000 */  nop
/* 179D1C 8024B43C 3C01802A */  lui       $at, %hi(D_8029F28C)
/* 179D20 8024B440 C42EF28C */  lwc1      $f14, %lo(D_8029F28C)($at)
/* 179D24 8024B444 461C7382 */  mul.s     $f14, $f14, $f28
/* 179D28 8024B448 00000000 */  nop
/* 179D2C 8024B44C 3C01802A */  lui       $at, %hi(D_8029F290)
/* 179D30 8024B450 C428F290 */  lwc1      $f8, %lo(D_8029F290)($at)
/* 179D34 8024B454 461C4202 */  mul.s     $f8, $f8, $f28
/* 179D38 8024B458 00000000 */  nop
/* 179D3C 8024B45C 3C01802A */  lui       $at, %hi(D_8029F294)
/* 179D40 8024B460 C424F294 */  lwc1      $f4, %lo(D_8029F294)($at)
/* 179D44 8024B464 461C2102 */  mul.s     $f4, $f4, $f28
/* 179D48 8024B468 00000000 */  nop
/* 179D4C 8024B46C 3C013F80 */  lui       $at, 0x3f80
/* 179D50 8024B470 44811000 */  mtc1      $at, $f2
/* 179D54 8024B474 00000000 */  nop
/* 179D58 8024B478 461C1081 */  sub.s     $f2, $f2, $f28
/* 179D5C 8024B47C 4602D682 */  mul.s     $f26, $f26, $f2
/* 179D60 8024B480 00000000 */  nop
/* 179D64 8024B484 C7BE0018 */  lwc1      $f30, 0x18($sp)
/* 179D68 8024B488 4602F602 */  mul.s     $f24, $f30, $f2
/* 179D6C 8024B48C 00000000 */  nop
/* 179D70 8024B490 3C02802A */  lui       $v0, %hi(D_8029F286)
/* 179D74 8024B494 8442F286 */  lh        $v0, %lo(D_8029F286)($v0)
/* 179D78 8024B498 44820000 */  mtc1      $v0, $f0
/* 179D7C 8024B49C 00000000 */  nop
/* 179D80 8024B4A0 46800020 */  cvt.s.w   $f0, $f0
/* 179D84 8024B4A4 3C02802A */  lui       $v0, %hi(D_8029F280)
/* 179D88 8024B4A8 8442F280 */  lh        $v0, %lo(D_8029F280)($v0)
/* 179D8C 8024B4AC 46020002 */  mul.s     $f0, $f0, $f2
/* 179D90 8024B4B0 00000000 */  nop
/* 179D94 8024B4B4 44826000 */  mtc1      $v0, $f12
/* 179D98 8024B4B8 00000000 */  nop
/* 179D9C 8024B4BC 46806320 */  cvt.s.w   $f12, $f12
/* 179DA0 8024B4C0 3C02802A */  lui       $v0, %hi(D_8029F282)
/* 179DA4 8024B4C4 8442F282 */  lh        $v0, %lo(D_8029F282)($v0)
/* 179DA8 8024B4C8 44823000 */  mtc1      $v0, $f6
/* 179DAC 8024B4CC 00000000 */  nop
/* 179DB0 8024B4D0 468031A0 */  cvt.s.w   $f6, $f6
/* 179DB4 8024B4D4 46023182 */  mul.s     $f6, $f6, $f2
/* 179DB8 8024B4D8 00000000 */  nop
/* 179DBC 8024B4DC C7BE0010 */  lwc1      $f30, 0x10($sp)
/* 179DC0 8024B4E0 4602F582 */  mul.s     $f22, $f30, $f2
/* 179DC4 8024B4E4 00000000 */  nop
/* 179DC8 8024B4E8 46005280 */  add.s     $f10, $f10, $f0
/* 179DCC 8024B4EC 3C014380 */  lui       $at, 0x4380
/* 179DD0 8024B4F0 44810000 */  mtc1      $at, $f0
/* 179DD4 8024B4F4 00000000 */  nop
/* 179DD8 8024B4F8 46005282 */  mul.s     $f10, $f10, $f0
/* 179DDC 8024B4FC 00000000 */  nop
/* 179DE0 8024B500 C7BE0014 */  lwc1      $f30, 0x14($sp)
/* 179DE4 8024B504 3C014200 */  lui       $at, 0x4200
/* 179DE8 8024B508 44810000 */  mtc1      $at, $f0
/* 179DEC 8024B50C 00000000 */  nop
/* 179DF0 8024B510 4600F001 */  sub.s     $f0, $f30, $f0
/* 179DF4 8024B514 3C02802A */  lui       $v0, %hi(D_8029F284)
/* 179DF8 8024B518 8442F284 */  lh        $v0, %lo(D_8029F284)($v0)
/* 179DFC 8024B51C 46006300 */  add.s     $f12, $f12, $f0
/* 179E00 8024B520 44820000 */  mtc1      $v0, $f0
/* 179E04 8024B524 00000000 */  nop
/* 179E08 8024B528 46800020 */  cvt.s.w   $f0, $f0
/* 179E0C 8024B52C 46020002 */  mul.s     $f0, $f0, $f2
/* 179E10 8024B530 00000000 */  nop
/* 179E14 8024B534 46026302 */  mul.s     $f12, $f12, $f2
/* 179E18 8024B538 00000000 */  nop
/* 179E1C 8024B53C 461AA500 */  add.s     $f20, $f20, $f26
/* 179E20 8024B540 46189480 */  add.s     $f18, $f18, $f24
/* 179E24 8024B544 46064200 */  add.s     $f8, $f8, $f6
/* 179E28 8024B548 3C04802A */  lui       $a0, %hi(D_8029F29E)
/* 179E2C 8024B54C 2484F29E */  addiu     $a0, $a0, %lo(D_8029F29E)
/* 179E30 8024B550 46168400 */  add.s     $f16, $f16, $f22
/* 179E34 8024B554 E6140054 */  swc1      $f20, 0x54($s0)
/* 179E38 8024B558 E6120058 */  swc1      $f18, 0x58($s0)
/* 179E3C 8024B55C E610005C */  swc1      $f16, 0x5c($s0)
/* 179E40 8024B560 46002100 */  add.s     $f4, $f4, $f0
/* 179E44 8024B564 4600478D */  trunc.w.s $f30, $f8
/* 179E48 8024B568 4402F000 */  mfc1      $v0, $f30
/* 179E4C 8024B56C 00000000 */  nop
/* 179E50 8024B570 A6020024 */  sh        $v0, 0x24($s0)
/* 179E54 8024B574 460C7380 */  add.s     $f14, $f14, $f12
/* 179E58 8024B578 4600278D */  trunc.w.s $f30, $f4
/* 179E5C 8024B57C 4402F000 */  mfc1      $v0, $f30
/* 179E60 8024B580 00000000 */  nop
/* 179E64 8024B584 A6020022 */  sh        $v0, 0x22($s0)
/* 179E68 8024B588 4600778D */  trunc.w.s $f30, $f14
/* 179E6C 8024B58C 4402F000 */  mfc1      $v0, $f30
/* 179E70 8024B590 00000000 */  nop
/* 179E74 8024B594 A602001E */  sh        $v0, 0x1e($s0)
/* 179E78 8024B598 4600578D */  trunc.w.s $f30, $f10
/* 179E7C 8024B59C 4402F000 */  mfc1      $v0, $f30
/* 179E80 8024B5A0 00000000 */  nop
/* 179E84 8024B5A4 A6020026 */  sh        $v0, 0x26($s0)
/* 179E88 8024B5A8 84820000 */  lh        $v0, ($a0)
/* 179E8C 8024B5AC 94830000 */  lhu       $v1, ($a0)
/* 179E90 8024B5B0 14400006 */  bnez      $v0, .L8024B5CC
/* 179E94 8024B5B4 2462FFFF */   addiu    $v0, $v1, -1
/* 179E98 8024B5B8 24020001 */  addiu     $v0, $zero, 1
/* 179E9C 8024B5BC 3C01802A */  lui       $at, %hi(D_8029F29C)
/* 179EA0 8024B5C0 A022F29C */  sb        $v0, %lo(D_8029F29C)($at)
/* 179EA4 8024B5C4 08092D75 */  j         .L8024B5D4
/* 179EA8 8024B5C8 0000102D */   daddu    $v0, $zero, $zero
.L8024B5CC:
/* 179EAC 8024B5CC A4820000 */  sh        $v0, ($a0)
/* 179EB0 8024B5D0 0000102D */  daddu     $v0, $zero, $zero
.L8024B5D4:
/* 179EB4 8024B5D4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 179EB8 8024B5D8 8FB00020 */  lw        $s0, 0x20($sp)
/* 179EBC 8024B5DC D7BE0050 */  ldc1      $f30, 0x50($sp)
/* 179EC0 8024B5E0 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 179EC4 8024B5E4 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 179EC8 8024B5E8 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 179ECC 8024B5EC D7B60030 */  ldc1      $f22, 0x30($sp)
/* 179ED0 8024B5F0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 179ED4 8024B5F4 03E00008 */  jr        $ra
/* 179ED8 8024B5F8 27BD0058 */   addiu    $sp, $sp, 0x58
