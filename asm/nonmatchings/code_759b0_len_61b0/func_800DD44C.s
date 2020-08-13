.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800DD44C
/* 0768FC 800DD44C 27BDFF70 */  addiu $sp, $sp, -0x90
/* 076900 800DD450 F7B40060 */  sdc1  $f20, 0x60($sp)
/* 076904 800DD454 4485A000 */  mtc1  $a1, $f20
/* 076908 800DD458 F7BA0078 */  sdc1  $f26, 0x78($sp)
/* 07690C 800DD45C 4486D000 */  mtc1  $a2, $f26
/* 076910 800DD460 F7B80070 */  sdc1  $f24, 0x70($sp)
/* 076914 800DD464 4487C000 */  mtc1  $a3, $f24
/* 076918 800DD468 F7B60068 */  sdc1  $f22, 0x68($sp)
/* 07691C 800DD46C C7B600A0 */  lwc1  $f22, 0xa0($sp)
/* 076920 800DD470 F7BC0080 */  sdc1  $f28, 0x80($sp)
/* 076924 800DD474 C7BC00A4 */  lwc1  $f28, 0xa4($sp)
/* 076928 800DD478 F7BE0088 */  sdc1  $f30, 0x88($sp)
/* 07692C 800DD47C C7BE00A8 */  lwc1  $f30, 0xa8($sp)
/* 076930 800DD480 AFB20040 */  sw    $s2, 0x40($sp)
/* 076934 800DD484 8FB200AC */  lw    $s2, 0xac($sp)
/* 076938 800DD488 AFB30044 */  sw    $s3, 0x44($sp)
/* 07693C 800DD48C 8FB300B0 */  lw    $s3, 0xb0($sp)
/* 076940 800DD490 AFB40048 */  sw    $s4, 0x48($sp)
/* 076944 800DD494 8FB400B4 */  lw    $s4, 0xb4($sp)
/* 076948 800DD498 AFB5004C */  sw    $s5, 0x4c($sp)
/* 07694C 800DD49C 8FB500B8 */  lw    $s5, 0xb8($sp)
/* 076950 800DD4A0 AFB60050 */  sw    $s6, 0x50($sp)
/* 076954 800DD4A4 8FB600BC */  lw    $s6, 0xbc($sp)
/* 076958 800DD4A8 AFB1003C */  sw    $s1, 0x3c($sp)
/* 07695C 800DD4AC 0080882D */  daddu $s1, $a0, $zero
/* 076960 800DD4B0 AFB00038 */  sw    $s0, 0x38($sp)
/* 076964 800DD4B4 2410FFFF */  addiu $s0, $zero, -1
/* 076968 800DD4B8 AFB70054 */  sw    $s7, 0x54($sp)
/* 07696C 800DD4BC 8FB700C0 */  lw    $s7, 0xc0($sp)
/* 076970 800DD4C0 3C020010 */  lui   $v0, 0x10
/* 076974 800DD4C4 AFBE0058 */  sw    $fp, 0x58($sp)
/* 076978 800DD4C8 8FBE00C4 */  lw    $fp, 0xc4($sp)
/* 07697C 800DD4CC 02221024 */  and   $v0, $s1, $v0
/* 076980 800DD4D0 14400015 */  bnez  $v0, .L800DD528
/* 076984 800DD4D4 AFBF005C */   sw    $ra, 0x5c($sp)
/* 076988 800DD4D8 4406D000 */  mfc1  $a2, $f26
/* 07698C 800DD4DC 4407C000 */  mfc1  $a3, $f24
/* 076990 800DD4E0 4405A000 */  mfc1  $a1, $f20
/* 076994 800DD4E4 0220202D */  daddu $a0, $s1, $zero
/* 076998 800DD4E8 E7B60010 */  swc1  $f22, 0x10($sp)
/* 07699C 800DD4EC E7BC0014 */  swc1  $f28, 0x14($sp)
/* 0769A0 800DD4F0 E7BE0018 */  swc1  $f30, 0x18($sp)
/* 0769A4 800DD4F4 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0769A8 800DD4F8 AFB30020 */  sw    $s3, 0x20($sp)
/* 0769AC 800DD4FC AFB40024 */  sw    $s4, 0x24($sp)
/* 0769B0 800DD500 AFB50028 */  sw    $s5, 0x28($sp)
/* 0769B4 800DD504 AFB6002C */  sw    $s6, 0x2c($sp)
/* 0769B8 800DD508 AFB70030 */  sw    $s7, 0x30($sp)
/* 0769BC 800DD50C 0C017334 */  jal   test_ray_colliders
/* 0769C0 800DD510 AFBE0034 */   sw    $fp, 0x34($sp)
/* 0769C4 800DD514 0040802D */  daddu $s0, $v0, $zero
/* 0769C8 800DD518 3C020004 */  lui   $v0, 4
/* 0769CC 800DD51C 02221024 */  and   $v0, $s1, $v0
/* 0769D0 800DD520 14400012 */  bnez  $v0, .L800DD56C
/* 0769D4 800DD524 0200102D */   daddu $v0, $s0, $zero
.L800DD528:
/* 0769D8 800DD528 4600A306 */  mov.s $f12, $f20
/* 0769DC 800DD52C 4406C000 */  mfc1  $a2, $f24
/* 0769E0 800DD530 4407B000 */  mfc1  $a3, $f22
/* 0769E4 800DD534 4600D386 */  mov.s $f14, $f26
/* 0769E8 800DD538 E7BC0010 */  swc1  $f28, 0x10($sp)
/* 0769EC 800DD53C E7BE0014 */  swc1  $f30, 0x14($sp)
/* 0769F0 800DD540 AFB20018 */  sw    $s2, 0x18($sp)
/* 0769F4 800DD544 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0769F8 800DD548 AFB40020 */  sw    $s4, 0x20($sp)
/* 0769FC 800DD54C AFB50024 */  sw    $s5, 0x24($sp)
/* 076A00 800DD550 AFB60028 */  sw    $s6, 0x28($sp)
/* 076A04 800DD554 AFB7002C */  sw    $s7, 0x2c($sp)
/* 076A08 800DD558 0C017512 */  jal   test_ray_entities
/* 076A0C 800DD55C AFBE0030 */   sw    $fp, 0x30($sp)
/* 076A10 800DD560 04430001 */  bgezl $v0, .L800DD568
/* 076A14 800DD564 34504000 */   ori   $s0, $v0, 0x4000
.L800DD568:
/* 076A18 800DD568 0200102D */  daddu $v0, $s0, $zero
.L800DD56C:
/* 076A1C 800DD56C 8FBF005C */  lw    $ra, 0x5c($sp)
/* 076A20 800DD570 8FBE0058 */  lw    $fp, 0x58($sp)
/* 076A24 800DD574 8FB70054 */  lw    $s7, 0x54($sp)
/* 076A28 800DD578 8FB60050 */  lw    $s6, 0x50($sp)
/* 076A2C 800DD57C 8FB5004C */  lw    $s5, 0x4c($sp)
/* 076A30 800DD580 8FB40048 */  lw    $s4, 0x48($sp)
/* 076A34 800DD584 8FB30044 */  lw    $s3, 0x44($sp)
/* 076A38 800DD588 8FB20040 */  lw    $s2, 0x40($sp)
/* 076A3C 800DD58C 8FB1003C */  lw    $s1, 0x3c($sp)
/* 076A40 800DD590 8FB00038 */  lw    $s0, 0x38($sp)
/* 076A44 800DD594 D7BE0088 */  ldc1  $f30, 0x88($sp)
/* 076A48 800DD598 D7BC0080 */  ldc1  $f28, 0x80($sp)
/* 076A4C 800DD59C D7BA0078 */  ldc1  $f26, 0x78($sp)
/* 076A50 800DD5A0 D7B80070 */  ldc1  $f24, 0x70($sp)
/* 076A54 800DD5A4 D7B60068 */  ldc1  $f22, 0x68($sp)
/* 076A58 800DD5A8 D7B40060 */  ldc1  $f20, 0x60($sp)
/* 076A5C 800DD5AC 03E00008 */  jr    $ra
/* 076A60 800DD5B0 27BD0090 */   addiu $sp, $sp, 0x90

