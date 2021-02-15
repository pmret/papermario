.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BE280_31EFF0
/* 31EFF0 802BE280 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 31EFF4 802BE284 AFB3006C */  sw        $s3, 0x6c($sp)
/* 31EFF8 802BE288 8FB300A0 */  lw        $s3, 0xa0($sp)
/* 31EFFC 802BE28C 3C0140C9 */  lui       $at, 0x40c9
/* 31F000 802BE290 34210FD0 */  ori       $at, $at, 0xfd0
/* 31F004 802BE294 44810000 */  mtc1      $at, $f0
/* 31F008 802BE298 AFB00060 */  sw        $s0, 0x60($sp)
/* 31F00C 802BE29C 00A0802D */  daddu     $s0, $a1, $zero
/* 31F010 802BE2A0 AFB10064 */  sw        $s1, 0x64($sp)
/* 31F014 802BE2A4 00C0882D */  daddu     $s1, $a2, $zero
/* 31F018 802BE2A8 AFB20068 */  sw        $s2, 0x68($sp)
/* 31F01C 802BE2AC 00E0902D */  daddu     $s2, $a3, $zero
/* 31F020 802BE2B0 AFBF0070 */  sw        $ra, 0x70($sp)
/* 31F024 802BE2B4 F7B60080 */  sdc1      $f22, 0x80($sp)
/* 31F028 802BE2B8 F7B40078 */  sdc1      $f20, 0x78($sp)
/* 31F02C 802BE2BC C66C0000 */  lwc1      $f12, ($s3)
/* 31F030 802BE2C0 27A50038 */  addiu     $a1, $sp, 0x38
/* 31F034 802BE2C4 46006302 */  mul.s     $f12, $f12, $f0
/* 31F038 802BE2C8 00000000 */  nop
/* 31F03C 802BE2CC 27A6003C */  addiu     $a2, $sp, 0x3c
/* 31F040 802BE2D0 C7B60098 */  lwc1      $f22, 0x98($sp)
/* 31F044 802BE2D4 3C0143B4 */  lui       $at, 0x43b4
/* 31F048 802BE2D8 44810000 */  mtc1      $at, $f0
/* 31F04C 802BE2DC C7B4009C */  lwc1      $f20, 0x9c($sp)
/* 31F050 802BE2E0 0C00A82D */  jal       sin_cos_rad
/* 31F054 802BE2E4 46006303 */   div.s    $f12, $f12, $f0
/* 31F058 802BE2E8 27A20040 */  addiu     $v0, $sp, 0x40
/* 31F05C 802BE2EC 4616A500 */  add.s     $f20, $f20, $f22
/* 31F060 802BE2F0 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 31F064 802BE2F4 C7A20038 */  lwc1      $f2, 0x38($sp)
/* 31F068 802BE2F8 46000007 */  neg.s     $f0, $f0
/* 31F06C 802BE2FC E7A0003C */  swc1      $f0, 0x3c($sp)
/* 31F070 802BE300 E7B4004C */  swc1      $f20, 0x4c($sp)
/* 31F074 802BE304 AFA2001C */  sw        $v0, 0x1c($sp)
/* 31F078 802BE308 27A20044 */  addiu     $v0, $sp, 0x44
/* 31F07C 802BE30C AFA20020 */  sw        $v0, 0x20($sp)
/* 31F080 802BE310 27A20048 */  addiu     $v0, $sp, 0x48
/* 31F084 802BE314 AFA20024 */  sw        $v0, 0x24($sp)
/* 31F088 802BE318 27A2004C */  addiu     $v0, $sp, 0x4c
/* 31F08C 802BE31C AFA20028 */  sw        $v0, 0x28($sp)
/* 31F090 802BE320 27A20050 */  addiu     $v0, $sp, 0x50
/* 31F094 802BE324 AFA2002C */  sw        $v0, 0x2c($sp)
/* 31F098 802BE328 27A20054 */  addiu     $v0, $sp, 0x54
/* 31F09C 802BE32C AFA20030 */  sw        $v0, 0x30($sp)
/* 31F0A0 802BE330 27A20058 */  addiu     $v0, $sp, 0x58
/* 31F0A4 802BE334 E7A20010 */  swc1      $f2, 0x10($sp)
/* 31F0A8 802BE338 AFA00014 */  sw        $zero, 0x14($sp)
/* 31F0AC 802BE33C E7A00018 */  swc1      $f0, 0x18($sp)
/* 31F0B0 802BE340 AFA20034 */  sw        $v0, 0x34($sp)
/* 31F0B4 802BE344 8E050000 */  lw        $a1, ($s0)
/* 31F0B8 802BE348 8E260000 */  lw        $a2, ($s1)
/* 31F0BC 802BE34C 8E470000 */  lw        $a3, ($s2)
/* 31F0C0 802BE350 0C017334 */  jal       test_ray_colliders
/* 31F0C4 802BE354 3C040001 */   lui      $a0, 1
/* 31F0C8 802BE358 0040802D */  daddu     $s0, $v0, $zero
/* 31F0CC 802BE35C 06000008 */  bltz      $s0, .L802BE380
/* 31F0D0 802BE360 0200102D */   daddu    $v0, $s0, $zero
/* 31F0D4 802BE364 8FA60050 */  lw        $a2, 0x50($sp)
/* 31F0D8 802BE368 44806000 */  mtc1      $zero, $f12
/* 31F0DC 802BE36C 8FA70058 */  lw        $a3, 0x58($sp)
/* 31F0E0 802BE370 0C00A720 */  jal       atan2
/* 31F0E4 802BE374 46006386 */   mov.s    $f14, $f12
/* 31F0E8 802BE378 E6600000 */  swc1      $f0, ($s3)
/* 31F0EC 802BE37C 0200102D */  daddu     $v0, $s0, $zero
.L802BE380:
/* 31F0F0 802BE380 8FBF0070 */  lw        $ra, 0x70($sp)
/* 31F0F4 802BE384 8FB3006C */  lw        $s3, 0x6c($sp)
/* 31F0F8 802BE388 8FB20068 */  lw        $s2, 0x68($sp)
/* 31F0FC 802BE38C 8FB10064 */  lw        $s1, 0x64($sp)
/* 31F100 802BE390 8FB00060 */  lw        $s0, 0x60($sp)
/* 31F104 802BE394 D7B60080 */  ldc1      $f22, 0x80($sp)
/* 31F108 802BE398 D7B40078 */  ldc1      $f20, 0x78($sp)
/* 31F10C 802BE39C 03E00008 */  jr        $ra
/* 31F110 802BE3A0 27BD0088 */   addiu    $sp, $sp, 0x88
