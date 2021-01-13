.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DCE70
/* 76320 800DCE70 27BDFF50 */  addiu     $sp, $sp, -0xb0
/* 76324 800DCE74 AFB20078 */  sw        $s2, 0x78($sp)
/* 76328 800DCE78 8FB200C0 */  lw        $s2, 0xc0($sp)
/* 7632C 800DCE7C F7BA00A8 */  sdc1      $f26, 0xa8($sp)
/* 76330 800DCE80 3C013F80 */  lui       $at, 0x3f80
/* 76334 800DCE84 4481D000 */  mtc1      $at, $f26
/* 76338 800DCE88 AFB00070 */  sw        $s0, 0x70($sp)
/* 7633C 800DCE8C 0080802D */  daddu     $s0, $a0, $zero
/* 76340 800DCE90 AFB3007C */  sw        $s3, 0x7c($sp)
/* 76344 800DCE94 00A0982D */  daddu     $s3, $a1, $zero
/* 76348 800DCE98 AFB40080 */  sw        $s4, 0x80($sp)
/* 7634C 800DCE9C 00C0A02D */  daddu     $s4, $a2, $zero
/* 76350 800DCEA0 AFB50084 */  sw        $s5, 0x84($sp)
/* 76354 800DCEA4 00E0A82D */  daddu     $s5, $a3, $zero
/* 76358 800DCEA8 AFBF0088 */  sw        $ra, 0x88($sp)
/* 7635C 800DCEAC AFB10074 */  sw        $s1, 0x74($sp)
/* 76360 800DCEB0 F7B800A0 */  sdc1      $f24, 0xa0($sp)
/* 76364 800DCEB4 F7B60098 */  sdc1      $f22, 0x98($sp)
/* 76368 800DCEB8 F7B40090 */  sdc1      $f20, 0x90($sp)
/* 7636C 800DCEBC C6400000 */  lwc1      $f0, ($s2)
/* 76370 800DCEC0 27A20038 */  addiu     $v0, $sp, 0x38
/* 76374 800DCEC4 E7A00044 */  swc1      $f0, 0x44($sp)
/* 76378 800DCEC8 E7A00060 */  swc1      $f0, 0x60($sp)
/* 7637C 800DCECC C6760000 */  lwc1      $f22, ($s3)
/* 76380 800DCED0 C6980000 */  lwc1      $f24, ($s4)
/* 76384 800DCED4 C6B40000 */  lwc1      $f20, ($s5)
/* 76388 800DCED8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 7638C 800DCEDC 27A2003C */  addiu     $v0, $sp, 0x3c
/* 76390 800DCEE0 AFA20020 */  sw        $v0, 0x20($sp)
/* 76394 800DCEE4 27A20040 */  addiu     $v0, $sp, 0x40
/* 76398 800DCEE8 AFA20024 */  sw        $v0, 0x24($sp)
/* 7639C 800DCEEC 27A20044 */  addiu     $v0, $sp, 0x44
/* 763A0 800DCEF0 AFA20028 */  sw        $v0, 0x28($sp)
/* 763A4 800DCEF4 27A20048 */  addiu     $v0, $sp, 0x48
/* 763A8 800DCEF8 AFA2002C */  sw        $v0, 0x2c($sp)
/* 763AC 800DCEFC 27A2004C */  addiu     $v0, $sp, 0x4c
/* 763B0 800DCF00 AFA20030 */  sw        $v0, 0x30($sp)
/* 763B4 800DCF04 4406C000 */  mfc1      $a2, $f24
/* 763B8 800DCF08 4407A000 */  mfc1      $a3, $f20
/* 763BC 800DCF0C 4405B000 */  mfc1      $a1, $f22
/* 763C0 800DCF10 27A20050 */  addiu     $v0, $sp, 0x50
/* 763C4 800DCF14 AFA00010 */  sw        $zero, 0x10($sp)
/* 763C8 800DCF18 E7BA0014 */  swc1      $f26, 0x14($sp)
/* 763CC 800DCF1C AFA00018 */  sw        $zero, 0x18($sp)
/* 763D0 800DCF20 0C017334 */  jal       test_ray_colliders
/* 763D4 800DCF24 AFA20034 */   sw       $v0, 0x34($sp)
/* 763D8 800DCF28 0040882D */  daddu     $s1, $v0, $zero
/* 763DC 800DCF2C 3C020004 */  lui       $v0, 4
/* 763E0 800DCF30 02028024 */  and       $s0, $s0, $v0
/* 763E4 800DCF34 16000029 */  bnez      $s0, .L800DCFDC
/* 763E8 800DCF38 0220182D */   daddu    $v1, $s1, $zero
/* 763EC 800DCF3C 27A20054 */  addiu     $v0, $sp, 0x54
/* 763F0 800DCF40 AFA20018 */  sw        $v0, 0x18($sp)
/* 763F4 800DCF44 27A20058 */  addiu     $v0, $sp, 0x58
/* 763F8 800DCF48 AFA2001C */  sw        $v0, 0x1c($sp)
/* 763FC 800DCF4C 27A2005C */  addiu     $v0, $sp, 0x5c
/* 76400 800DCF50 AFA20020 */  sw        $v0, 0x20($sp)
/* 76404 800DCF54 27A20060 */  addiu     $v0, $sp, 0x60
/* 76408 800DCF58 AFA20024 */  sw        $v0, 0x24($sp)
/* 7640C 800DCF5C 27A20064 */  addiu     $v0, $sp, 0x64
/* 76410 800DCF60 AFA20028 */  sw        $v0, 0x28($sp)
/* 76414 800DCF64 27A20068 */  addiu     $v0, $sp, 0x68
/* 76418 800DCF68 AFA2002C */  sw        $v0, 0x2c($sp)
/* 7641C 800DCF6C 27A2006C */  addiu     $v0, $sp, 0x6c
/* 76420 800DCF70 4600B306 */  mov.s     $f12, $f22
/* 76424 800DCF74 44800000 */  mtc1      $zero, $f0
/* 76428 800DCF78 4406A000 */  mfc1      $a2, $f20
/* 7642C 800DCF7C 44070000 */  mfc1      $a3, $f0
/* 76430 800DCF80 4600C386 */  mov.s     $f14, $f24
/* 76434 800DCF84 E7BA0010 */  swc1      $f26, 0x10($sp)
/* 76438 800DCF88 AFA20030 */  sw        $v0, 0x30($sp)
/* 7643C 800DCF8C 0C017512 */  jal       test_ray_entities
/* 76440 800DCF90 AFA70014 */   sw       $a3, 0x14($sp)
/* 76444 800DCF94 04400010 */  bltz      $v0, .L800DCFD8
/* 76448 800DCF98 34434000 */   ori      $v1, $v0, 0x4000
/* 7644C 800DCF9C C7A00060 */  lwc1      $f0, 0x60($sp)
/* 76450 800DCFA0 C7A20054 */  lwc1      $f2, 0x54($sp)
/* 76454 800DCFA4 C7A40058 */  lwc1      $f4, 0x58($sp)
/* 76458 800DCFA8 C7A6005C */  lwc1      $f6, 0x5c($sp)
/* 7645C 800DCFAC C7A80064 */  lwc1      $f8, 0x64($sp)
/* 76460 800DCFB0 C7AA0068 */  lwc1      $f10, 0x68($sp)
/* 76464 800DCFB4 C7AC006C */  lwc1      $f12, 0x6c($sp)
/* 76468 800DCFB8 E7A00044 */  swc1      $f0, 0x44($sp)
/* 7646C 800DCFBC E7A20038 */  swc1      $f2, 0x38($sp)
/* 76470 800DCFC0 E7A4003C */  swc1      $f4, 0x3c($sp)
/* 76474 800DCFC4 E7A60040 */  swc1      $f6, 0x40($sp)
/* 76478 800DCFC8 E7A80048 */  swc1      $f8, 0x48($sp)
/* 7647C 800DCFCC E7AA004C */  swc1      $f10, 0x4c($sp)
/* 76480 800DCFD0 080373F7 */  j         .L800DCFDC
/* 76484 800DCFD4 E7AC0050 */   swc1     $f12, 0x50($sp)
.L800DCFD8:
/* 76488 800DCFD8 0220182D */  daddu     $v1, $s1, $zero
.L800DCFDC:
/* 7648C 800DCFDC 0460000D */  bltz      $v1, .L800DD014
/* 76490 800DCFE0 24020001 */   addiu    $v0, $zero, 1
/* 76494 800DCFE4 C7A00044 */  lwc1      $f0, 0x44($sp)
/* 76498 800DCFE8 E6400000 */  swc1      $f0, ($s2)
/* 7649C 800DCFEC C7A00038 */  lwc1      $f0, 0x38($sp)
/* 764A0 800DCFF0 E6600000 */  swc1      $f0, ($s3)
/* 764A4 800DCFF4 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 764A8 800DCFF8 E6800000 */  swc1      $f0, ($s4)
/* 764AC 800DCFFC C7A00040 */  lwc1      $f0, 0x40($sp)
/* 764B0 800DD000 E6A00000 */  swc1      $f0, ($s5)
/* 764B4 800DD004 3C018011 */  lui       $at, %hi(D_8010C978)
/* 764B8 800DD008 AC23C978 */  sw        $v1, %lo(D_8010C978)($at)
/* 764BC 800DD00C 08037406 */  j         .L800DD018
/* 764C0 800DD010 00000000 */   nop
.L800DD014:
/* 764C4 800DD014 0000102D */  daddu     $v0, $zero, $zero
.L800DD018:
/* 764C8 800DD018 8FBF0088 */  lw        $ra, 0x88($sp)
/* 764CC 800DD01C 8FB50084 */  lw        $s5, 0x84($sp)
/* 764D0 800DD020 8FB40080 */  lw        $s4, 0x80($sp)
/* 764D4 800DD024 8FB3007C */  lw        $s3, 0x7c($sp)
/* 764D8 800DD028 8FB20078 */  lw        $s2, 0x78($sp)
/* 764DC 800DD02C 8FB10074 */  lw        $s1, 0x74($sp)
/* 764E0 800DD030 8FB00070 */  lw        $s0, 0x70($sp)
/* 764E4 800DD034 D7BA00A8 */  ldc1      $f26, 0xa8($sp)
/* 764E8 800DD038 D7B800A0 */  ldc1      $f24, 0xa0($sp)
/* 764EC 800DD03C D7B60098 */  ldc1      $f22, 0x98($sp)
/* 764F0 800DD040 D7B40090 */  ldc1      $f20, 0x90($sp)
/* 764F4 800DD044 03E00008 */  jr        $ra
/* 764F8 800DD048 27BD00B0 */   addiu    $sp, $sp, 0xb0
