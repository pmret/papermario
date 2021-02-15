.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DEE5C
/* 7830C 800DEE5C 27BDFF70 */  addiu     $sp, $sp, -0x90
/* 78310 800DEE60 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 78314 800DEE64 4485A000 */  mtc1      $a1, $f20
/* 78318 800DEE68 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 7831C 800DEE6C 4486D000 */  mtc1      $a2, $f26
/* 78320 800DEE70 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* 78324 800DEE74 4487E000 */  mtc1      $a3, $f28
/* 78328 800DEE78 F7BE0088 */  sdc1      $f30, 0x88($sp)
/* 7832C 800DEE7C C7BE00A0 */  lwc1      $f30, 0xa0($sp)
/* 78330 800DEE80 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 78334 800DEE84 C7B600A4 */  lwc1      $f22, 0xa4($sp)
/* 78338 800DEE88 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 7833C 800DEE8C C7B800A8 */  lwc1      $f24, 0xa8($sp)
/* 78340 800DEE90 AFB5004C */  sw        $s5, 0x4c($sp)
/* 78344 800DEE94 8FB500AC */  lw        $s5, 0xac($sp)
/* 78348 800DEE98 AFB60050 */  sw        $s6, 0x50($sp)
/* 7834C 800DEE9C 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 78350 800DEEA0 AFB70054 */  sw        $s7, 0x54($sp)
/* 78354 800DEEA4 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 78358 800DEEA8 AFBE0058 */  sw        $fp, 0x58($sp)
/* 7835C 800DEEAC 8FBE00B8 */  lw        $fp, 0xb8($sp)
/* 78360 800DEEB0 AFB40048 */  sw        $s4, 0x48($sp)
/* 78364 800DEEB4 8FB400C0 */  lw        $s4, 0xc0($sp)
/* 78368 800DEEB8 AFB30044 */  sw        $s3, 0x44($sp)
/* 7836C 800DEEBC 8FB300C4 */  lw        $s3, 0xc4($sp)
/* 78370 800DEEC0 8FA800BC */  lw        $t0, 0xbc($sp)
/* 78374 800DEEC4 AFB20040 */  sw        $s2, 0x40($sp)
/* 78378 800DEEC8 0080902D */  daddu     $s2, $a0, $zero
/* 7837C 800DEECC AFB1003C */  sw        $s1, 0x3c($sp)
/* 78380 800DEED0 2411FFFF */  addiu     $s1, $zero, -1
/* 78384 800DEED4 AFBF005C */  sw        $ra, 0x5c($sp)
/* 78388 800DEED8 AFB00038 */  sw        $s0, 0x38($sp)
/* 7838C 800DEEDC 4600A306 */  mov.s     $f12, $f20
/* 78390 800DEEE0 4406E000 */  mfc1      $a2, $f28
/* 78394 800DEEE4 4407F000 */  mfc1      $a3, $f30
/* 78398 800DEEE8 4600D386 */  mov.s     $f14, $f26
/* 7839C 800DEEEC E7B60010 */  swc1      $f22, 0x10($sp)
/* 783A0 800DEEF0 E7B80014 */  swc1      $f24, 0x14($sp)
/* 783A4 800DEEF4 AFB50018 */  sw        $s5, 0x18($sp)
/* 783A8 800DEEF8 AFB6001C */  sw        $s6, 0x1c($sp)
/* 783AC 800DEEFC AFB70020 */  sw        $s7, 0x20($sp)
/* 783B0 800DEF00 AFBE0024 */  sw        $fp, 0x24($sp)
/* 783B4 800DEF04 AFA80028 */  sw        $t0, 0x28($sp)
/* 783B8 800DEF08 AFB4002C */  sw        $s4, 0x2c($sp)
/* 783BC 800DEF0C 0C017512 */  jal       test_ray_entities
/* 783C0 800DEF10 AFB30030 */   sw       $s3, 0x30($sp)
/* 783C4 800DEF14 0040802D */  daddu     $s0, $v0, $zero
/* 783C8 800DEF18 0600000D */  bltz      $s0, .L800DEF50
/* 783CC 800DEF1C 24020003 */   addiu    $v0, $zero, 3
/* 783D0 800DEF20 0C04417A */  jal       get_entity_by_index
/* 783D4 800DEF24 0200202D */   daddu    $a0, $s0, $zero
/* 783D8 800DEF28 0040182D */  daddu     $v1, $v0, $zero
/* 783DC 800DEF2C 9062000B */  lbu       $v0, 0xb($v1)
/* 783E0 800DEF30 2C4200FF */  sltiu     $v0, $v0, 0xff
/* 783E4 800DEF34 50400019 */  beql      $v0, $zero, .L800DEF9C
/* 783E8 800DEF38 36114000 */   ori      $s1, $s0, 0x4000
/* 783EC 800DEF3C 8C620000 */  lw        $v0, ($v1)
/* 783F0 800DEF40 A0600007 */  sb        $zero, 7($v1)
/* 783F4 800DEF44 34420040 */  ori       $v0, $v0, 0x40
/* 783F8 800DEF48 08037BE7 */  j         .L800DEF9C
/* 783FC 800DEF4C AC620000 */   sw       $v0, ($v1)
.L800DEF50:
/* 78400 800DEF50 16420013 */  bne       $s2, $v0, .L800DEFA0
/* 78404 800DEF54 24020001 */   addiu    $v0, $zero, 1
/* 78408 800DEF58 4405A000 */  mfc1      $a1, $f20
/* 7840C 800DEF5C 4406D000 */  mfc1      $a2, $f26
/* 78410 800DEF60 4407E000 */  mfc1      $a3, $f28
/* 78414 800DEF64 8FA800BC */  lw        $t0, 0xbc($sp)
/* 78418 800DEF68 34048000 */  ori       $a0, $zero, 0x8000
/* 7841C 800DEF6C E7BE0010 */  swc1      $f30, 0x10($sp)
/* 78420 800DEF70 E7B60014 */  swc1      $f22, 0x14($sp)
/* 78424 800DEF74 E7B80018 */  swc1      $f24, 0x18($sp)
/* 78428 800DEF78 AFB5001C */  sw        $s5, 0x1c($sp)
/* 7842C 800DEF7C AFB60020 */  sw        $s6, 0x20($sp)
/* 78430 800DEF80 AFB70024 */  sw        $s7, 0x24($sp)
/* 78434 800DEF84 AFBE0028 */  sw        $fp, 0x28($sp)
/* 78438 800DEF88 AFB40030 */  sw        $s4, 0x30($sp)
/* 7843C 800DEF8C AFB30034 */  sw        $s3, 0x34($sp)
/* 78440 800DEF90 0C017334 */  jal       test_ray_colliders
/* 78444 800DEF94 AFA8002C */   sw       $t0, 0x2c($sp)
/* 78448 800DEF98 0040882D */  daddu     $s1, $v0, $zero
.L800DEF9C:
/* 7844C 800DEF9C 24020001 */  addiu     $v0, $zero, 1
.L800DEFA0:
/* 78450 800DEFA0 1242005B */  beq       $s2, $v0, .L800DF110
/* 78454 800DEFA4 24020003 */   addiu    $v0, $zero, 3
/* 78458 800DEFA8 12420059 */  beq       $s2, $v0, .L800DF110
/* 7845C 800DEFAC 24020004 */   addiu    $v0, $zero, 4
/* 78460 800DEFB0 16420002 */  bne       $s2, $v0, .L800DEFBC
/* 78464 800DEFB4 3C040001 */   lui      $a0, 1
/* 78468 800DEFB8 3C040008 */  lui       $a0, 8
.L800DEFBC:
/* 7846C 800DEFBC 4405A000 */  mfc1      $a1, $f20
/* 78470 800DEFC0 4406D000 */  mfc1      $a2, $f26
/* 78474 800DEFC4 4407E000 */  mfc1      $a3, $f28
/* 78478 800DEFC8 8FA800BC */  lw        $t0, 0xbc($sp)
/* 7847C 800DEFCC E7BE0010 */  swc1      $f30, 0x10($sp)
/* 78480 800DEFD0 E7B60014 */  swc1      $f22, 0x14($sp)
/* 78484 800DEFD4 E7B80018 */  swc1      $f24, 0x18($sp)
/* 78488 800DEFD8 AFB5001C */  sw        $s5, 0x1c($sp)
/* 7848C 800DEFDC AFB60020 */  sw        $s6, 0x20($sp)
/* 78490 800DEFE0 AFB70024 */  sw        $s7, 0x24($sp)
/* 78494 800DEFE4 AFBE0028 */  sw        $fp, 0x28($sp)
/* 78498 800DEFE8 AFB40030 */  sw        $s4, 0x30($sp)
/* 7849C 800DEFEC AFB30034 */  sw        $s3, 0x34($sp)
/* 784A0 800DEFF0 0C017334 */  jal       test_ray_colliders
/* 784A4 800DEFF4 AFA8002C */   sw       $t0, 0x2c($sp)
/* 784A8 800DEFF8 06210004 */  bgez      $s1, .L800DF00C
/* 784AC 800DEFFC 00000000 */   nop
/* 784B0 800DF000 0040882D */  daddu     $s1, $v0, $zero
/* 784B4 800DF004 06200043 */  bltz      $s1, .L800DF114
/* 784B8 800DF008 0220102D */   daddu    $v0, $s1, $zero
.L800DF00C:
/* 784BC 800DF00C C6620000 */  lwc1      $f2, ($s3)
/* 784C0 800DF010 3C014059 */  lui       $at, 0x4059
/* 784C4 800DF014 4481A800 */  mtc1      $at, $f21
/* 784C8 800DF018 4480A000 */  mtc1      $zero, $f20
/* 784CC 800DF01C 460010A1 */  cvt.d.s   $f2, $f2
/* 784D0 800DF020 46341082 */  mul.d     $f2, $f2, $f20
/* 784D4 800DF024 00000000 */  nop
/* 784D8 800DF028 C6800000 */  lwc1      $f0, ($s4)
/* 784DC 800DF02C 46000021 */  cvt.d.s   $f0, $f0
/* 784E0 800DF030 46340002 */  mul.d     $f0, $f0, $f20
/* 784E4 800DF034 00000000 */  nop
/* 784E8 800DF038 4480B000 */  mtc1      $zero, $f22
/* 784EC 800DF03C 00000000 */  nop
/* 784F0 800DF040 4600B306 */  mov.s     $f12, $f22
/* 784F4 800DF044 462010A0 */  cvt.s.d   $f2, $f2
/* 784F8 800DF048 46200020 */  cvt.s.d   $f0, $f0
/* 784FC 800DF04C 44061000 */  mfc1      $a2, $f2
/* 78500 800DF050 44070000 */  mfc1      $a3, $f0
/* 78504 800DF054 0C00A720 */  jal       atan2
/* 78508 800DF058 4600B386 */   mov.s    $f14, $f22
/* 7850C 800DF05C C6820000 */  lwc1      $f2, ($s4)
/* 78510 800DF060 460010A1 */  cvt.d.s   $f2, $f2
/* 78514 800DF064 46341082 */  mul.d     $f2, $f2, $f20
/* 78518 800DF068 00000000 */  nop
/* 7851C 800DF06C 8FA800BC */  lw        $t0, 0xbc($sp)
/* 78520 800DF070 C5040000 */  lwc1      $f4, ($t0)
/* 78524 800DF074 46002121 */  cvt.d.s   $f4, $f4
/* 78528 800DF078 46342102 */  mul.d     $f4, $f4, $f20
/* 7852C 800DF07C 00000000 */  nop
/* 78530 800DF080 3C014334 */  lui       $at, 0x4334
/* 78534 800DF084 4481A000 */  mtc1      $at, $f20
/* 78538 800DF088 4600B306 */  mov.s     $f12, $f22
/* 7853C 800DF08C 4600A581 */  sub.s     $f22, $f20, $f0
/* 78540 800DF090 462010A0 */  cvt.s.d   $f2, $f2
/* 78544 800DF094 44071000 */  mfc1      $a3, $f2
/* 78548 800DF098 46202120 */  cvt.s.d   $f4, $f4
/* 7854C 800DF09C 44062000 */  mfc1      $a2, $f4
/* 78550 800DF0A0 0C00A720 */  jal       atan2
/* 78554 800DF0A4 46006386 */   mov.s    $f14, $f12
/* 78558 800DF0A8 3C0142B4 */  lui       $at, 0x42b4
/* 7855C 800DF0AC 44811000 */  mtc1      $at, $f2
/* 78560 800DF0B0 00000000 */  nop
/* 78564 800DF0B4 4602B032 */  c.eq.s    $f22, $f2
/* 78568 800DF0B8 00000000 */  nop
/* 7856C 800DF0BC 45000005 */  bc1f      .L800DF0D4
/* 78570 800DF0C0 4600A501 */   sub.s    $f20, $f20, $f0
/* 78574 800DF0C4 4602A032 */  c.eq.s    $f20, $f2
/* 78578 800DF0C8 00000000 */  nop
/* 7857C 800DF0CC 45010011 */  bc1t      .L800DF114
/* 78580 800DF0D0 0220102D */   daddu    $v0, $s1, $zero
.L800DF0D4:
/* 78584 800DF0D4 4600B021 */  cvt.d.s   $f0, $f22
/* 78588 800DF0D8 3C01403E */  lui       $at, 0x403e
/* 7858C 800DF0DC 44811800 */  mtc1      $at, $f3
/* 78590 800DF0E0 44801000 */  mtc1      $zero, $f2
/* 78594 800DF0E4 46200005 */  abs.d     $f0, $f0
/* 78598 800DF0E8 4620103E */  c.le.d    $f2, $f0
/* 7859C 800DF0EC 00000000 */  nop
/* 785A0 800DF0F0 45010008 */  bc1t      .L800DF114
/* 785A4 800DF0F4 0220102D */   daddu    $v0, $s1, $zero
/* 785A8 800DF0F8 4600A021 */  cvt.d.s   $f0, $f20
/* 785AC 800DF0FC 46200005 */  abs.d     $f0, $f0
/* 785B0 800DF100 4620103E */  c.le.d    $f2, $f0
/* 785B4 800DF104 00000000 */  nop
/* 785B8 800DF108 45020001 */  bc1fl     .L800DF110
/* 785BC 800DF10C 2411FFFF */   addiu    $s1, $zero, -1
.L800DF110:
/* 785C0 800DF110 0220102D */  daddu     $v0, $s1, $zero
.L800DF114:
/* 785C4 800DF114 8FBF005C */  lw        $ra, 0x5c($sp)
/* 785C8 800DF118 8FBE0058 */  lw        $fp, 0x58($sp)
/* 785CC 800DF11C 8FB70054 */  lw        $s7, 0x54($sp)
/* 785D0 800DF120 8FB60050 */  lw        $s6, 0x50($sp)
/* 785D4 800DF124 8FB5004C */  lw        $s5, 0x4c($sp)
/* 785D8 800DF128 8FB40048 */  lw        $s4, 0x48($sp)
/* 785DC 800DF12C 8FB30044 */  lw        $s3, 0x44($sp)
/* 785E0 800DF130 8FB20040 */  lw        $s2, 0x40($sp)
/* 785E4 800DF134 8FB1003C */  lw        $s1, 0x3c($sp)
/* 785E8 800DF138 8FB00038 */  lw        $s0, 0x38($sp)
/* 785EC 800DF13C D7BE0088 */  ldc1      $f30, 0x88($sp)
/* 785F0 800DF140 D7BC0080 */  ldc1      $f28, 0x80($sp)
/* 785F4 800DF144 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 785F8 800DF148 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 785FC 800DF14C D7B60068 */  ldc1      $f22, 0x68($sp)
/* 78600 800DF150 D7B40060 */  ldc1      $f20, 0x60($sp)
/* 78604 800DF154 03E00008 */  jr        $ra
/* 78608 800DF158 27BD0090 */   addiu    $sp, $sp, 0x90
