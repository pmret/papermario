.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800DEE5C
/* 07830C 800DEE5C 27BDFF70 */  addiu $sp, $sp, -0x90
/* 078310 800DEE60 F7B40060 */  sdc1  $f20, 0x60($sp)
/* 078314 800DEE64 4485A000 */  mtc1  $a1, $f20
/* 078318 800DEE68 F7BA0078 */  sdc1  $f26, 0x78($sp)
/* 07831C 800DEE6C 4486D000 */  mtc1  $a2, $f26
/* 078320 800DEE70 F7BC0080 */  sdc1  $f28, 0x80($sp)
/* 078324 800DEE74 4487E000 */  mtc1  $a3, $f28
/* 078328 800DEE78 F7BE0088 */  sdc1  $f30, 0x88($sp)
/* 07832C 800DEE7C C7BE00A0 */  lwc1  $f30, 0xa0($sp)
/* 078330 800DEE80 F7B60068 */  sdc1  $f22, 0x68($sp)
/* 078334 800DEE84 C7B600A4 */  lwc1  $f22, 0xa4($sp)
/* 078338 800DEE88 F7B80070 */  sdc1  $f24, 0x70($sp)
/* 07833C 800DEE8C C7B800A8 */  lwc1  $f24, 0xa8($sp)
/* 078340 800DEE90 AFB5004C */  sw    $s5, 0x4c($sp)
/* 078344 800DEE94 8FB500AC */  lw    $s5, 0xac($sp)
/* 078348 800DEE98 AFB60050 */  sw    $s6, 0x50($sp)
/* 07834C 800DEE9C 8FB600B0 */  lw    $s6, 0xb0($sp)
/* 078350 800DEEA0 AFB70054 */  sw    $s7, 0x54($sp)
/* 078354 800DEEA4 8FB700B4 */  lw    $s7, 0xb4($sp)
/* 078358 800DEEA8 AFBE0058 */  sw    $fp, 0x58($sp)
/* 07835C 800DEEAC 8FBE00B8 */  lw    $fp, 0xb8($sp)
/* 078360 800DEEB0 AFB40048 */  sw    $s4, 0x48($sp)
/* 078364 800DEEB4 8FB400C0 */  lw    $s4, 0xc0($sp)
/* 078368 800DEEB8 AFB30044 */  sw    $s3, 0x44($sp)
/* 07836C 800DEEBC 8FB300C4 */  lw    $s3, 0xc4($sp)
/* 078370 800DEEC0 8FA800BC */  lw    $t0, 0xbc($sp)
/* 078374 800DEEC4 AFB20040 */  sw    $s2, 0x40($sp)
/* 078378 800DEEC8 0080902D */  daddu $s2, $a0, $zero
/* 07837C 800DEECC AFB1003C */  sw    $s1, 0x3c($sp)
/* 078380 800DEED0 2411FFFF */  addiu $s1, $zero, -1
/* 078384 800DEED4 AFBF005C */  sw    $ra, 0x5c($sp)
/* 078388 800DEED8 AFB00038 */  sw    $s0, 0x38($sp)
/* 07838C 800DEEDC 4600A306 */  mov.s $f12, $f20
/* 078390 800DEEE0 4406E000 */  mfc1  $a2, $f28
/* 078394 800DEEE4 4407F000 */  mfc1  $a3, $f30
/* 078398 800DEEE8 4600D386 */  mov.s $f14, $f26
/* 07839C 800DEEEC E7B60010 */  swc1  $f22, 0x10($sp)
/* 0783A0 800DEEF0 E7B80014 */  swc1  $f24, 0x14($sp)
/* 0783A4 800DEEF4 AFB50018 */  sw    $s5, 0x18($sp)
/* 0783A8 800DEEF8 AFB6001C */  sw    $s6, 0x1c($sp)
/* 0783AC 800DEEFC AFB70020 */  sw    $s7, 0x20($sp)
/* 0783B0 800DEF00 AFBE0024 */  sw    $fp, 0x24($sp)
/* 0783B4 800DEF04 AFA80028 */  sw    $t0, 0x28($sp)
/* 0783B8 800DEF08 AFB4002C */  sw    $s4, 0x2c($sp)
/* 0783BC 800DEF0C 0C017512 */  jal   test_ray_entities
/* 0783C0 800DEF10 AFB30030 */   sw    $s3, 0x30($sp)
/* 0783C4 800DEF14 0040802D */  daddu $s0, $v0, $zero
/* 0783C8 800DEF18 0600000D */  bltz  $s0, .L800DEF50
/* 0783CC 800DEF1C 24020003 */   addiu $v0, $zero, 3
/* 0783D0 800DEF20 0C04417A */  jal   get_entity_by_index
/* 0783D4 800DEF24 0200202D */   daddu $a0, $s0, $zero
/* 0783D8 800DEF28 0040182D */  daddu $v1, $v0, $zero
/* 0783DC 800DEF2C 9062000B */  lbu   $v0, 0xb($v1)
/* 0783E0 800DEF30 2C4200FF */  sltiu $v0, $v0, 0xff
/* 0783E4 800DEF34 50400019 */  beql  $v0, $zero, .L800DEF9C
/* 0783E8 800DEF38 36114000 */   ori   $s1, $s0, 0x4000
/* 0783EC 800DEF3C 8C620000 */  lw    $v0, ($v1)
/* 0783F0 800DEF40 A0600007 */  sb    $zero, 7($v1)
/* 0783F4 800DEF44 34420040 */  ori   $v0, $v0, 0x40
/* 0783F8 800DEF48 08037BE7 */  j     .L800DEF9C
/* 0783FC 800DEF4C AC620000 */   sw    $v0, ($v1)

.L800DEF50:
/* 078400 800DEF50 16420013 */  bne   $s2, $v0, .L800DEFA0
/* 078404 800DEF54 24020001 */   addiu $v0, $zero, 1
/* 078408 800DEF58 4405A000 */  mfc1  $a1, $f20
/* 07840C 800DEF5C 4406D000 */  mfc1  $a2, $f26
/* 078410 800DEF60 4407E000 */  mfc1  $a3, $f28
/* 078414 800DEF64 8FA800BC */  lw    $t0, 0xbc($sp)
/* 078418 800DEF68 34048000 */  ori   $a0, $zero, 0x8000
/* 07841C 800DEF6C E7BE0010 */  swc1  $f30, 0x10($sp)
/* 078420 800DEF70 E7B60014 */  swc1  $f22, 0x14($sp)
/* 078424 800DEF74 E7B80018 */  swc1  $f24, 0x18($sp)
/* 078428 800DEF78 AFB5001C */  sw    $s5, 0x1c($sp)
/* 07842C 800DEF7C AFB60020 */  sw    $s6, 0x20($sp)
/* 078430 800DEF80 AFB70024 */  sw    $s7, 0x24($sp)
/* 078434 800DEF84 AFBE0028 */  sw    $fp, 0x28($sp)
/* 078438 800DEF88 AFB40030 */  sw    $s4, 0x30($sp)
/* 07843C 800DEF8C AFB30034 */  sw    $s3, 0x34($sp)
/* 078440 800DEF90 0C017334 */  jal   test_ray_colliders
/* 078444 800DEF94 AFA8002C */   sw    $t0, 0x2c($sp)
/* 078448 800DEF98 0040882D */  daddu $s1, $v0, $zero
.L800DEF9C:
/* 07844C 800DEF9C 24020001 */  addiu $v0, $zero, 1
.L800DEFA0:
/* 078450 800DEFA0 1242005B */  beq   $s2, $v0, .L800DF110
/* 078454 800DEFA4 24020003 */   addiu $v0, $zero, 3
/* 078458 800DEFA8 12420059 */  beq   $s2, $v0, .L800DF110
/* 07845C 800DEFAC 24020004 */   addiu $v0, $zero, 4
/* 078460 800DEFB0 16420002 */  bne   $s2, $v0, .L800DEFBC
/* 078464 800DEFB4 3C040001 */   lui   $a0, 1
/* 078468 800DEFB8 3C040008 */  lui   $a0, 8
.L800DEFBC:
/* 07846C 800DEFBC 4405A000 */  mfc1  $a1, $f20
/* 078470 800DEFC0 4406D000 */  mfc1  $a2, $f26
/* 078474 800DEFC4 4407E000 */  mfc1  $a3, $f28
/* 078478 800DEFC8 8FA800BC */  lw    $t0, 0xbc($sp)
/* 07847C 800DEFCC E7BE0010 */  swc1  $f30, 0x10($sp)
/* 078480 800DEFD0 E7B60014 */  swc1  $f22, 0x14($sp)
/* 078484 800DEFD4 E7B80018 */  swc1  $f24, 0x18($sp)
/* 078488 800DEFD8 AFB5001C */  sw    $s5, 0x1c($sp)
/* 07848C 800DEFDC AFB60020 */  sw    $s6, 0x20($sp)
/* 078490 800DEFE0 AFB70024 */  sw    $s7, 0x24($sp)
/* 078494 800DEFE4 AFBE0028 */  sw    $fp, 0x28($sp)
/* 078498 800DEFE8 AFB40030 */  sw    $s4, 0x30($sp)
/* 07849C 800DEFEC AFB30034 */  sw    $s3, 0x34($sp)
/* 0784A0 800DEFF0 0C017334 */  jal   test_ray_colliders
/* 0784A4 800DEFF4 AFA8002C */   sw    $t0, 0x2c($sp)
/* 0784A8 800DEFF8 06210004 */  bgez  $s1, .L800DF00C
/* 0784AC 800DEFFC 00000000 */   nop   
/* 0784B0 800DF000 0040882D */  daddu $s1, $v0, $zero
/* 0784B4 800DF004 06200043 */  bltz  $s1, .L800DF114
/* 0784B8 800DF008 0220102D */   daddu $v0, $s1, $zero
.L800DF00C:
/* 0784BC 800DF00C C6620000 */  lwc1  $f2, ($s3)
/* 0784C0 800DF010 3C014059 */  lui   $at, 0x4059
/* 0784C4 800DF014 4481A800 */  mtc1  $at, $f21
/* 0784C8 800DF018 4480A000 */  mtc1  $zero, $f20
/* 0784CC 800DF01C 460010A1 */  cvt.d.s $f2, $f2
/* 0784D0 800DF020 46341082 */  mul.d $f2, $f2, $f20
/* 0784D4 800DF024 00000000 */  nop   
/* 0784D8 800DF028 C6800000 */  lwc1  $f0, ($s4)
/* 0784DC 800DF02C 46000021 */  cvt.d.s $f0, $f0
/* 0784E0 800DF030 46340002 */  mul.d $f0, $f0, $f20
/* 0784E4 800DF034 00000000 */  nop   
/* 0784E8 800DF038 4480B000 */  mtc1  $zero, $f22
/* 0784EC 800DF03C 00000000 */  nop   
/* 0784F0 800DF040 4600B306 */  mov.s $f12, $f22
/* 0784F4 800DF044 462010A0 */  cvt.s.d $f2, $f2
/* 0784F8 800DF048 46200020 */  cvt.s.d $f0, $f0
/* 0784FC 800DF04C 44061000 */  mfc1  $a2, $f2
/* 078500 800DF050 44070000 */  mfc1  $a3, $f0
/* 078504 800DF054 0C00A720 */  jal   atan2
/* 078508 800DF058 4600B386 */   mov.s $f14, $f22
/* 07850C 800DF05C C6820000 */  lwc1  $f2, ($s4)
/* 078510 800DF060 460010A1 */  cvt.d.s $f2, $f2
/* 078514 800DF064 46341082 */  mul.d $f2, $f2, $f20
/* 078518 800DF068 00000000 */  nop   
/* 07851C 800DF06C 8FA800BC */  lw    $t0, 0xbc($sp)
/* 078520 800DF070 C5040000 */  lwc1  $f4, ($t0)
/* 078524 800DF074 46002121 */  cvt.d.s $f4, $f4
/* 078528 800DF078 46342102 */  mul.d $f4, $f4, $f20
/* 07852C 800DF07C 00000000 */  nop   
/* 078530 800DF080 3C014334 */  lui   $at, 0x4334
/* 078534 800DF084 4481A000 */  mtc1  $at, $f20
/* 078538 800DF088 4600B306 */  mov.s $f12, $f22
/* 07853C 800DF08C 4600A581 */  sub.s $f22, $f20, $f0
/* 078540 800DF090 462010A0 */  cvt.s.d $f2, $f2
/* 078544 800DF094 44071000 */  mfc1  $a3, $f2
/* 078548 800DF098 46202120 */  cvt.s.d $f4, $f4
/* 07854C 800DF09C 44062000 */  mfc1  $a2, $f4
/* 078550 800DF0A0 0C00A720 */  jal   atan2
/* 078554 800DF0A4 46006386 */   mov.s $f14, $f12
/* 078558 800DF0A8 3C0142B4 */  lui   $at, 0x42b4
/* 07855C 800DF0AC 44811000 */  mtc1  $at, $f2
/* 078560 800DF0B0 00000000 */  nop   
/* 078564 800DF0B4 4602B032 */  c.eq.s $f22, $f2
/* 078568 800DF0B8 00000000 */  nop   
/* 07856C 800DF0BC 45000005 */  bc1f  .L800DF0D4
/* 078570 800DF0C0 4600A501 */   sub.s $f20, $f20, $f0
/* 078574 800DF0C4 4602A032 */  c.eq.s $f20, $f2
/* 078578 800DF0C8 00000000 */  nop   
/* 07857C 800DF0CC 45010011 */  bc1t  .L800DF114
/* 078580 800DF0D0 0220102D */   daddu $v0, $s1, $zero
.L800DF0D4:
/* 078584 800DF0D4 4600B021 */  cvt.d.s $f0, $f22
/* 078588 800DF0D8 3C01403E */  lui   $at, 0x403e
/* 07858C 800DF0DC 44811800 */  mtc1  $at, $f3
/* 078590 800DF0E0 44801000 */  mtc1  $zero, $f2
/* 078594 800DF0E4 46200005 */  abs.d $f0, $f0
/* 078598 800DF0E8 4620103E */  c.le.d $f2, $f0
/* 07859C 800DF0EC 00000000 */  nop   
/* 0785A0 800DF0F0 45010008 */  bc1t  .L800DF114
/* 0785A4 800DF0F4 0220102D */   daddu $v0, $s1, $zero
/* 0785A8 800DF0F8 4600A021 */  cvt.d.s $f0, $f20
/* 0785AC 800DF0FC 46200005 */  abs.d $f0, $f0
/* 0785B0 800DF100 4620103E */  c.le.d $f2, $f0
/* 0785B4 800DF104 00000000 */  nop   
/* 0785B8 800DF108 45020001 */  bc1fl .L800DF110
/* 0785BC 800DF10C 2411FFFF */   addiu $s1, $zero, -1
.L800DF110:
/* 0785C0 800DF110 0220102D */  daddu $v0, $s1, $zero
.L800DF114:
/* 0785C4 800DF114 8FBF005C */  lw    $ra, 0x5c($sp)
/* 0785C8 800DF118 8FBE0058 */  lw    $fp, 0x58($sp)
/* 0785CC 800DF11C 8FB70054 */  lw    $s7, 0x54($sp)
/* 0785D0 800DF120 8FB60050 */  lw    $s6, 0x50($sp)
/* 0785D4 800DF124 8FB5004C */  lw    $s5, 0x4c($sp)
/* 0785D8 800DF128 8FB40048 */  lw    $s4, 0x48($sp)
/* 0785DC 800DF12C 8FB30044 */  lw    $s3, 0x44($sp)
/* 0785E0 800DF130 8FB20040 */  lw    $s2, 0x40($sp)
/* 0785E4 800DF134 8FB1003C */  lw    $s1, 0x3c($sp)
/* 0785E8 800DF138 8FB00038 */  lw    $s0, 0x38($sp)
/* 0785EC 800DF13C D7BE0088 */  ldc1  $f30, 0x88($sp)
/* 0785F0 800DF140 D7BC0080 */  ldc1  $f28, 0x80($sp)
/* 0785F4 800DF144 D7BA0078 */  ldc1  $f26, 0x78($sp)
/* 0785F8 800DF148 D7B80070 */  ldc1  $f24, 0x70($sp)
/* 0785FC 800DF14C D7B60068 */  ldc1  $f22, 0x68($sp)
/* 078600 800DF150 D7B40060 */  ldc1  $f20, 0x60($sp)
/* 078604 800DF154 03E00008 */  jr    $ra
/* 078608 800DF158 27BD0090 */   addiu $sp, $sp, 0x90

