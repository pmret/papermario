.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241424_BE01B4
/* BE01B4 80241424 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BE01B8 80241428 AFB10014 */  sw        $s1, 0x14($sp)
/* BE01BC 8024142C 0080882D */  daddu     $s1, $a0, $zero
/* BE01C0 80241430 AFBF0024 */  sw        $ra, 0x24($sp)
/* BE01C4 80241434 AFB40020 */  sw        $s4, 0x20($sp)
/* BE01C8 80241438 AFB3001C */  sw        $s3, 0x1c($sp)
/* BE01CC 8024143C AFB20018 */  sw        $s2, 0x18($sp)
/* BE01D0 80241440 AFB00010 */  sw        $s0, 0x10($sp)
/* BE01D4 80241444 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* BE01D8 80241448 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* BE01DC 8024144C F7B80038 */  sdc1      $f24, 0x38($sp)
/* BE01E0 80241450 F7B60030 */  sdc1      $f22, 0x30($sp)
/* BE01E4 80241454 F7B40028 */  sdc1      $f20, 0x28($sp)
/* BE01E8 80241458 8E30000C */  lw        $s0, 0xc($s1)
/* BE01EC 8024145C 8E130000 */  lw        $s3, ($s0)
/* BE01F0 80241460 26100004 */  addiu     $s0, $s0, 4
/* BE01F4 80241464 0C0B1EAF */  jal       get_variable
/* BE01F8 80241468 0260282D */   daddu    $a1, $s3, $zero
/* BE01FC 8024146C 4482E000 */  mtc1      $v0, $f28
/* BE0200 80241470 00000000 */  nop       
/* BE0204 80241474 4680E720 */  cvt.s.w   $f28, $f28
/* BE0208 80241478 8E140000 */  lw        $s4, ($s0)
/* BE020C 8024147C 26100004 */  addiu     $s0, $s0, 4
/* BE0210 80241480 0220202D */  daddu     $a0, $s1, $zero
/* BE0214 80241484 0C0B1EAF */  jal       get_variable
/* BE0218 80241488 0280282D */   daddu    $a1, $s4, $zero
/* BE021C 8024148C 4482D000 */  mtc1      $v0, $f26
/* BE0220 80241490 00000000 */  nop       
/* BE0224 80241494 4680D6A0 */  cvt.s.w   $f26, $f26
/* BE0228 80241498 8E100000 */  lw        $s0, ($s0)
/* BE022C 8024149C 0220202D */  daddu     $a0, $s1, $zero
/* BE0230 802414A0 0C0B1EAF */  jal       get_variable
/* BE0234 802414A4 0200282D */   daddu    $a1, $s0, $zero
/* BE0238 802414A8 4482C000 */  mtc1      $v0, $f24
/* BE023C 802414AC 00000000 */  nop       
/* BE0240 802414B0 4680C620 */  cvt.s.w   $f24, $f24
/* BE0244 802414B4 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* BE0248 802414B8 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* BE024C 802414BC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* BE0250 802414C0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* BE0254 802414C4 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* BE0258 802414C8 44800000 */  mtc1      $zero, $f0
/* BE025C 802414CC 00031080 */  sll       $v0, $v1, 2
/* BE0260 802414D0 00431021 */  addu      $v0, $v0, $v1
/* BE0264 802414D4 00021080 */  sll       $v0, $v0, 2
/* BE0268 802414D8 00431023 */  subu      $v0, $v0, $v1
/* BE026C 802414DC 000218C0 */  sll       $v1, $v0, 3
/* BE0270 802414E0 00431021 */  addu      $v0, $v0, $v1
/* BE0274 802414E4 000210C0 */  sll       $v0, $v0, 3
/* BE0278 802414E8 46001032 */  c.eq.s    $f2, $f0
/* BE027C 802414EC 3C01800B */  lui       $at, 0x800b
/* BE0280 802414F0 00220821 */  addu      $at, $at, $v0
/* BE0284 802414F4 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* BE0288 802414F8 45000005 */  bc1f      .L80241510
/* BE028C 802414FC 00000000 */   nop      
/* BE0290 80241500 3C0142C8 */  lui       $at, 0x42c8
/* BE0294 80241504 44810000 */  mtc1      $at, $f0
/* BE0298 80241508 08090548 */  j         .L80241520
/* BE029C 8024150C 4600B581 */   sub.s    $f22, $f22, $f0
.L80241510:
/* BE02A0 80241510 3C0142C8 */  lui       $at, 0x42c8
/* BE02A4 80241514 44810000 */  mtc1      $at, $f0
/* BE02A8 80241518 00000000 */  nop       
/* BE02AC 8024151C 4600B580 */  add.s     $f22, $f22, $f0
.L80241520:
/* BE02B0 80241520 0C00A6C9 */  jal       clamp_angle
/* BE02B4 80241524 4600B306 */   mov.s    $f12, $f22
/* BE02B8 80241528 46000586 */  mov.s     $f22, $f0
/* BE02BC 8024152C 3C014170 */  lui       $at, 0x4170
/* BE02C0 80241530 4481A000 */  mtc1      $at, $f20
/* BE02C4 80241534 0C00A8BB */  jal       sin_deg
/* BE02C8 80241538 4600B306 */   mov.s    $f12, $f22
/* BE02CC 8024153C 46140002 */  mul.s     $f0, $f0, $f20
/* BE02D0 80241540 00000000 */  nop       
/* BE02D4 80241544 864200B0 */  lh        $v0, 0xb0($s2)
/* BE02D8 80241548 3C013F00 */  lui       $at, 0x3f00
/* BE02DC 8024154C 44812000 */  mtc1      $at, $f4
/* BE02E0 80241550 44821000 */  mtc1      $v0, $f2
/* BE02E4 80241554 00000000 */  nop       
/* BE02E8 80241558 468010A0 */  cvt.s.w   $f2, $f2
/* BE02EC 8024155C 46041082 */  mul.s     $f2, $f2, $f4
/* BE02F0 80241560 00000000 */  nop       
/* BE02F4 80241564 4600E700 */  add.s     $f28, $f28, $f0
/* BE02F8 80241568 4602D680 */  add.s     $f26, $f26, $f2
/* BE02FC 8024156C 0C00A8D4 */  jal       cos_deg
/* BE0300 80241570 4600B306 */   mov.s    $f12, $f22
/* BE0304 80241574 46140002 */  mul.s     $f0, $f0, $f20
/* BE0308 80241578 00000000 */  nop       
/* BE030C 8024157C 0220202D */  daddu     $a0, $s1, $zero
/* BE0310 80241580 0260282D */  daddu     $a1, $s3, $zero
/* BE0314 80241584 4600E18D */  trunc.w.s $f6, $f28
/* BE0318 80241588 44063000 */  mfc1      $a2, $f6
/* BE031C 8024158C 0C0B2026 */  jal       set_variable
/* BE0320 80241590 4600C601 */   sub.s    $f24, $f24, $f0
/* BE0324 80241594 0220202D */  daddu     $a0, $s1, $zero
/* BE0328 80241598 4600D18D */  trunc.w.s $f6, $f26
/* BE032C 8024159C 44063000 */  mfc1      $a2, $f6
/* BE0330 802415A0 0C0B2026 */  jal       set_variable
/* BE0334 802415A4 0280282D */   daddu    $a1, $s4, $zero
/* BE0338 802415A8 0220202D */  daddu     $a0, $s1, $zero
/* BE033C 802415AC 4600C18D */  trunc.w.s $f6, $f24
/* BE0340 802415B0 44063000 */  mfc1      $a2, $f6
/* BE0344 802415B4 0C0B2026 */  jal       set_variable
/* BE0348 802415B8 0200282D */   daddu    $a1, $s0, $zero
/* BE034C 802415BC 8FBF0024 */  lw        $ra, 0x24($sp)
/* BE0350 802415C0 8FB40020 */  lw        $s4, 0x20($sp)
/* BE0354 802415C4 8FB3001C */  lw        $s3, 0x1c($sp)
/* BE0358 802415C8 8FB20018 */  lw        $s2, 0x18($sp)
/* BE035C 802415CC 8FB10014 */  lw        $s1, 0x14($sp)
/* BE0360 802415D0 8FB00010 */  lw        $s0, 0x10($sp)
/* BE0364 802415D4 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* BE0368 802415D8 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* BE036C 802415DC D7B80038 */  ldc1      $f24, 0x38($sp)
/* BE0370 802415E0 D7B60030 */  ldc1      $f22, 0x30($sp)
/* BE0374 802415E4 D7B40028 */  ldc1      $f20, 0x28($sp)
/* BE0378 802415E8 24020002 */  addiu     $v0, $zero, 2
/* BE037C 802415EC 03E00008 */  jr        $ra
/* BE0380 802415F0 27BD0050 */   addiu    $sp, $sp, 0x50
