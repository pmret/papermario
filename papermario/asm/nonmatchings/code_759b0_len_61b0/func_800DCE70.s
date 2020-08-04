.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800DCE70
/* 076320 800DCE70 27BDFF50 */  addiu $sp, $sp, -0xb0
/* 076324 800DCE74 AFB20078 */  sw    $s2, 0x78($sp)
/* 076328 800DCE78 8FB200C0 */  lw    $s2, 0xc0($sp)
/* 07632C 800DCE7C F7BA00A8 */  sdc1  $f26, 0xa8($sp)
/* 076330 800DCE80 3C013F80 */  lui   $at, 0x3f80
/* 076334 800DCE84 4481D000 */  mtc1  $at, $f26
/* 076338 800DCE88 AFB00070 */  sw    $s0, 0x70($sp)
/* 07633C 800DCE8C 0080802D */  daddu $s0, $a0, $zero
/* 076340 800DCE90 AFB3007C */  sw    $s3, 0x7c($sp)
/* 076344 800DCE94 00A0982D */  daddu $s3, $a1, $zero
/* 076348 800DCE98 AFB40080 */  sw    $s4, 0x80($sp)
/* 07634C 800DCE9C 00C0A02D */  daddu $s4, $a2, $zero
/* 076350 800DCEA0 AFB50084 */  sw    $s5, 0x84($sp)
/* 076354 800DCEA4 00E0A82D */  daddu $s5, $a3, $zero
/* 076358 800DCEA8 AFBF0088 */  sw    $ra, 0x88($sp)
/* 07635C 800DCEAC AFB10074 */  sw    $s1, 0x74($sp)
/* 076360 800DCEB0 F7B800A0 */  sdc1  $f24, 0xa0($sp)
/* 076364 800DCEB4 F7B60098 */  sdc1  $f22, 0x98($sp)
/* 076368 800DCEB8 F7B40090 */  sdc1  $f20, 0x90($sp)
/* 07636C 800DCEBC C6400000 */  lwc1  $f0, ($s2)
/* 076370 800DCEC0 27A20038 */  addiu $v0, $sp, 0x38
/* 076374 800DCEC4 E7A00044 */  swc1  $f0, 0x44($sp)
/* 076378 800DCEC8 E7A00060 */  swc1  $f0, 0x60($sp)
/* 07637C 800DCECC C6760000 */  lwc1  $f22, ($s3)
/* 076380 800DCED0 C6980000 */  lwc1  $f24, ($s4)
/* 076384 800DCED4 C6B40000 */  lwc1  $f20, ($s5)
/* 076388 800DCED8 AFA2001C */  sw    $v0, 0x1c($sp)
/* 07638C 800DCEDC 27A2003C */  addiu $v0, $sp, 0x3c
/* 076390 800DCEE0 AFA20020 */  sw    $v0, 0x20($sp)
/* 076394 800DCEE4 27A20040 */  addiu $v0, $sp, 0x40
/* 076398 800DCEE8 AFA20024 */  sw    $v0, 0x24($sp)
/* 07639C 800DCEEC 27A20044 */  addiu $v0, $sp, 0x44
/* 0763A0 800DCEF0 AFA20028 */  sw    $v0, 0x28($sp)
/* 0763A4 800DCEF4 27A20048 */  addiu $v0, $sp, 0x48
/* 0763A8 800DCEF8 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0763AC 800DCEFC 27A2004C */  addiu $v0, $sp, 0x4c
/* 0763B0 800DCF00 AFA20030 */  sw    $v0, 0x30($sp)
/* 0763B4 800DCF04 4406C000 */  mfc1  $a2, $f24
/* 0763B8 800DCF08 4407A000 */  mfc1  $a3, $f20
/* 0763BC 800DCF0C 4405B000 */  mfc1  $a1, $f22
/* 0763C0 800DCF10 27A20050 */  addiu $v0, $sp, 0x50
/* 0763C4 800DCF14 AFA00010 */  sw    $zero, 0x10($sp)
/* 0763C8 800DCF18 E7BA0014 */  swc1  $f26, 0x14($sp)
/* 0763CC 800DCF1C AFA00018 */  sw    $zero, 0x18($sp)
/* 0763D0 800DCF20 0C017334 */  jal   test_ray_colliders
/* 0763D4 800DCF24 AFA20034 */   sw    $v0, 0x34($sp)
/* 0763D8 800DCF28 0040882D */  daddu $s1, $v0, $zero
/* 0763DC 800DCF2C 3C020004 */  lui   $v0, 4
/* 0763E0 800DCF30 02028024 */  and   $s0, $s0, $v0
/* 0763E4 800DCF34 16000029 */  bnez  $s0, .L800DCFDC
/* 0763E8 800DCF38 0220182D */   daddu $v1, $s1, $zero
/* 0763EC 800DCF3C 27A20054 */  addiu $v0, $sp, 0x54
/* 0763F0 800DCF40 AFA20018 */  sw    $v0, 0x18($sp)
/* 0763F4 800DCF44 27A20058 */  addiu $v0, $sp, 0x58
/* 0763F8 800DCF48 AFA2001C */  sw    $v0, 0x1c($sp)
/* 0763FC 800DCF4C 27A2005C */  addiu $v0, $sp, 0x5c
/* 076400 800DCF50 AFA20020 */  sw    $v0, 0x20($sp)
/* 076404 800DCF54 27A20060 */  addiu $v0, $sp, 0x60
/* 076408 800DCF58 AFA20024 */  sw    $v0, 0x24($sp)
/* 07640C 800DCF5C 27A20064 */  addiu $v0, $sp, 0x64
/* 076410 800DCF60 AFA20028 */  sw    $v0, 0x28($sp)
/* 076414 800DCF64 27A20068 */  addiu $v0, $sp, 0x68
/* 076418 800DCF68 AFA2002C */  sw    $v0, 0x2c($sp)
/* 07641C 800DCF6C 27A2006C */  addiu $v0, $sp, 0x6c
/* 076420 800DCF70 4600B306 */  mov.s $f12, $f22
/* 076424 800DCF74 44800000 */  mtc1  $zero, $f0
/* 076428 800DCF78 4406A000 */  mfc1  $a2, $f20
/* 07642C 800DCF7C 44070000 */  mfc1  $a3, $f0
/* 076430 800DCF80 4600C386 */  mov.s $f14, $f24
/* 076434 800DCF84 E7BA0010 */  swc1  $f26, 0x10($sp)
/* 076438 800DCF88 AFA20030 */  sw    $v0, 0x30($sp)
/* 07643C 800DCF8C 0C017512 */  jal   test_ray_entities
/* 076440 800DCF90 AFA70014 */   sw    $a3, 0x14($sp)
/* 076444 800DCF94 04400010 */  bltz  $v0, .L800DCFD8
/* 076448 800DCF98 34434000 */   ori   $v1, $v0, 0x4000
/* 07644C 800DCF9C C7A00060 */  lwc1  $f0, 0x60($sp)
/* 076450 800DCFA0 C7A20054 */  lwc1  $f2, 0x54($sp)
/* 076454 800DCFA4 C7A40058 */  lwc1  $f4, 0x58($sp)
/* 076458 800DCFA8 C7A6005C */  lwc1  $f6, 0x5c($sp)
/* 07645C 800DCFAC C7A80064 */  lwc1  $f8, 0x64($sp)
/* 076460 800DCFB0 C7AA0068 */  lwc1  $f10, 0x68($sp)
/* 076464 800DCFB4 C7AC006C */  lwc1  $f12, 0x6c($sp)
/* 076468 800DCFB8 E7A00044 */  swc1  $f0, 0x44($sp)
/* 07646C 800DCFBC E7A20038 */  swc1  $f2, 0x38($sp)
/* 076470 800DCFC0 E7A4003C */  swc1  $f4, 0x3c($sp)
/* 076474 800DCFC4 E7A60040 */  swc1  $f6, 0x40($sp)
/* 076478 800DCFC8 E7A80048 */  swc1  $f8, 0x48($sp)
/* 07647C 800DCFCC E7AA004C */  swc1  $f10, 0x4c($sp)
/* 076480 800DCFD0 080373F7 */  j     .L800DCFDC
/* 076484 800DCFD4 E7AC0050 */   swc1  $f12, 0x50($sp)

.L800DCFD8:
/* 076488 800DCFD8 0220182D */  daddu $v1, $s1, $zero
.L800DCFDC:
/* 07648C 800DCFDC 0460000D */  bltz  $v1, .L800DD014
/* 076490 800DCFE0 24020001 */   addiu $v0, $zero, 1
/* 076494 800DCFE4 C7A00044 */  lwc1  $f0, 0x44($sp)
/* 076498 800DCFE8 E6400000 */  swc1  $f0, ($s2)
/* 07649C 800DCFEC C7A00038 */  lwc1  $f0, 0x38($sp)
/* 0764A0 800DCFF0 E6600000 */  swc1  $f0, ($s3)
/* 0764A4 800DCFF4 C7A0003C */  lwc1  $f0, 0x3c($sp)
/* 0764A8 800DCFF8 E6800000 */  swc1  $f0, ($s4)
/* 0764AC 800DCFFC C7A00040 */  lwc1  $f0, 0x40($sp)
/* 0764B0 800DD000 E6A00000 */  swc1  $f0, ($s5)
/* 0764B4 800DD004 3C018011 */  lui   $at, 0x8011
/* 0764B8 800DD008 AC23C978 */  sw    $v1, -0x3688($at)
/* 0764BC 800DD00C 08037406 */  j     .L800DD018
/* 0764C0 800DD010 00000000 */   nop   

.L800DD014:
/* 0764C4 800DD014 0000102D */  daddu $v0, $zero, $zero
.L800DD018:
/* 0764C8 800DD018 8FBF0088 */  lw    $ra, 0x88($sp)
/* 0764CC 800DD01C 8FB50084 */  lw    $s5, 0x84($sp)
/* 0764D0 800DD020 8FB40080 */  lw    $s4, 0x80($sp)
/* 0764D4 800DD024 8FB3007C */  lw    $s3, 0x7c($sp)
/* 0764D8 800DD028 8FB20078 */  lw    $s2, 0x78($sp)
/* 0764DC 800DD02C 8FB10074 */  lw    $s1, 0x74($sp)
/* 0764E0 800DD030 8FB00070 */  lw    $s0, 0x70($sp)
/* 0764E4 800DD034 D7BA00A8 */  ldc1  $f26, 0xa8($sp)
/* 0764E8 800DD038 D7B800A0 */  ldc1  $f24, 0xa0($sp)
/* 0764EC 800DD03C D7B60098 */  ldc1  $f22, 0x98($sp)
/* 0764F0 800DD040 D7B40090 */  ldc1  $f20, 0x90($sp)
/* 0764F4 800DD044 03E00008 */  jr    $ra
/* 0764F8 800DD048 27BD00B0 */   addiu $sp, $sp, 0xb0

