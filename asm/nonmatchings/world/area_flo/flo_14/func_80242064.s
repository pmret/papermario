.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242064
/* CCD374 80242064 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CCD378 80242068 AFB10014 */  sw        $s1, 0x14($sp)
/* CCD37C 8024206C 0080882D */  daddu     $s1, $a0, $zero
/* CCD380 80242070 AFBF0024 */  sw        $ra, 0x24($sp)
/* CCD384 80242074 AFB40020 */  sw        $s4, 0x20($sp)
/* CCD388 80242078 AFB3001C */  sw        $s3, 0x1c($sp)
/* CCD38C 8024207C AFB20018 */  sw        $s2, 0x18($sp)
/* CCD390 80242080 AFB00010 */  sw        $s0, 0x10($sp)
/* CCD394 80242084 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* CCD398 80242088 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* CCD39C 8024208C F7B80038 */  sdc1      $f24, 0x38($sp)
/* CCD3A0 80242090 F7B60030 */  sdc1      $f22, 0x30($sp)
/* CCD3A4 80242094 F7B40028 */  sdc1      $f20, 0x28($sp)
/* CCD3A8 80242098 8E30000C */  lw        $s0, 0xc($s1)
/* CCD3AC 8024209C 8E130000 */  lw        $s3, ($s0)
/* CCD3B0 802420A0 26100004 */  addiu     $s0, $s0, 4
/* CCD3B4 802420A4 0C0B1EAF */  jal       get_variable
/* CCD3B8 802420A8 0260282D */   daddu    $a1, $s3, $zero
/* CCD3BC 802420AC 4482E000 */  mtc1      $v0, $f28
/* CCD3C0 802420B0 00000000 */  nop       
/* CCD3C4 802420B4 4680E720 */  cvt.s.w   $f28, $f28
/* CCD3C8 802420B8 8E140000 */  lw        $s4, ($s0)
/* CCD3CC 802420BC 26100004 */  addiu     $s0, $s0, 4
/* CCD3D0 802420C0 0220202D */  daddu     $a0, $s1, $zero
/* CCD3D4 802420C4 0C0B1EAF */  jal       get_variable
/* CCD3D8 802420C8 0280282D */   daddu    $a1, $s4, $zero
/* CCD3DC 802420CC 4482D000 */  mtc1      $v0, $f26
/* CCD3E0 802420D0 00000000 */  nop       
/* CCD3E4 802420D4 4680D6A0 */  cvt.s.w   $f26, $f26
/* CCD3E8 802420D8 8E100000 */  lw        $s0, ($s0)
/* CCD3EC 802420DC 0220202D */  daddu     $a0, $s1, $zero
/* CCD3F0 802420E0 0C0B1EAF */  jal       get_variable
/* CCD3F4 802420E4 0200282D */   daddu    $a1, $s0, $zero
/* CCD3F8 802420E8 4482C000 */  mtc1      $v0, $f24
/* CCD3FC 802420EC 00000000 */  nop       
/* CCD400 802420F0 4680C620 */  cvt.s.w   $f24, $f24
/* CCD404 802420F4 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* CCD408 802420F8 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* CCD40C 802420FC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CCD410 80242100 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CCD414 80242104 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* CCD418 80242108 44800000 */  mtc1      $zero, $f0
/* CCD41C 8024210C 00031080 */  sll       $v0, $v1, 2
/* CCD420 80242110 00431021 */  addu      $v0, $v0, $v1
/* CCD424 80242114 00021080 */  sll       $v0, $v0, 2
/* CCD428 80242118 00431023 */  subu      $v0, $v0, $v1
/* CCD42C 8024211C 000218C0 */  sll       $v1, $v0, 3
/* CCD430 80242120 00431021 */  addu      $v0, $v0, $v1
/* CCD434 80242124 000210C0 */  sll       $v0, $v0, 3
/* CCD438 80242128 46001032 */  c.eq.s    $f2, $f0
/* CCD43C 8024212C 3C01800B */  lui       $at, 0x800b
/* CCD440 80242130 00220821 */  addu      $at, $at, $v0
/* CCD444 80242134 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* CCD448 80242138 45000005 */  bc1f      .L80242150
/* CCD44C 8024213C 00000000 */   nop      
/* CCD450 80242140 3C0142C8 */  lui       $at, 0x42c8
/* CCD454 80242144 44810000 */  mtc1      $at, $f0
/* CCD458 80242148 08090858 */  j         .L80242160
/* CCD45C 8024214C 4600B581 */   sub.s    $f22, $f22, $f0
.L80242150:
/* CCD460 80242150 3C0142C8 */  lui       $at, 0x42c8
/* CCD464 80242154 44810000 */  mtc1      $at, $f0
/* CCD468 80242158 00000000 */  nop       
/* CCD46C 8024215C 4600B580 */  add.s     $f22, $f22, $f0
.L80242160:
/* CCD470 80242160 0C00A6C9 */  jal       clamp_angle
/* CCD474 80242164 4600B306 */   mov.s    $f12, $f22
/* CCD478 80242168 46000586 */  mov.s     $f22, $f0
/* CCD47C 8024216C 3C014170 */  lui       $at, 0x4170
/* CCD480 80242170 4481A000 */  mtc1      $at, $f20
/* CCD484 80242174 0C00A8BB */  jal       sin_deg
/* CCD488 80242178 4600B306 */   mov.s    $f12, $f22
/* CCD48C 8024217C 46140002 */  mul.s     $f0, $f0, $f20
/* CCD490 80242180 00000000 */  nop       
/* CCD494 80242184 864200B0 */  lh        $v0, 0xb0($s2)
/* CCD498 80242188 3C013F00 */  lui       $at, 0x3f00
/* CCD49C 8024218C 44812000 */  mtc1      $at, $f4
/* CCD4A0 80242190 44821000 */  mtc1      $v0, $f2
/* CCD4A4 80242194 00000000 */  nop       
/* CCD4A8 80242198 468010A0 */  cvt.s.w   $f2, $f2
/* CCD4AC 8024219C 46041082 */  mul.s     $f2, $f2, $f4
/* CCD4B0 802421A0 00000000 */  nop       
/* CCD4B4 802421A4 4600E700 */  add.s     $f28, $f28, $f0
/* CCD4B8 802421A8 4602D680 */  add.s     $f26, $f26, $f2
/* CCD4BC 802421AC 0C00A8D4 */  jal       cos_deg
/* CCD4C0 802421B0 4600B306 */   mov.s    $f12, $f22
/* CCD4C4 802421B4 46140002 */  mul.s     $f0, $f0, $f20
/* CCD4C8 802421B8 00000000 */  nop       
/* CCD4CC 802421BC 0220202D */  daddu     $a0, $s1, $zero
/* CCD4D0 802421C0 0260282D */  daddu     $a1, $s3, $zero
/* CCD4D4 802421C4 4600E18D */  trunc.w.s $f6, $f28
/* CCD4D8 802421C8 44063000 */  mfc1      $a2, $f6
/* CCD4DC 802421CC 0C0B2026 */  jal       set_variable
/* CCD4E0 802421D0 4600C601 */   sub.s    $f24, $f24, $f0
/* CCD4E4 802421D4 0220202D */  daddu     $a0, $s1, $zero
/* CCD4E8 802421D8 4600D18D */  trunc.w.s $f6, $f26
/* CCD4EC 802421DC 44063000 */  mfc1      $a2, $f6
/* CCD4F0 802421E0 0C0B2026 */  jal       set_variable
/* CCD4F4 802421E4 0280282D */   daddu    $a1, $s4, $zero
/* CCD4F8 802421E8 0220202D */  daddu     $a0, $s1, $zero
/* CCD4FC 802421EC 4600C18D */  trunc.w.s $f6, $f24
/* CCD500 802421F0 44063000 */  mfc1      $a2, $f6
/* CCD504 802421F4 0C0B2026 */  jal       set_variable
/* CCD508 802421F8 0200282D */   daddu    $a1, $s0, $zero
/* CCD50C 802421FC 8FBF0024 */  lw        $ra, 0x24($sp)
/* CCD510 80242200 8FB40020 */  lw        $s4, 0x20($sp)
/* CCD514 80242204 8FB3001C */  lw        $s3, 0x1c($sp)
/* CCD518 80242208 8FB20018 */  lw        $s2, 0x18($sp)
/* CCD51C 8024220C 8FB10014 */  lw        $s1, 0x14($sp)
/* CCD520 80242210 8FB00010 */  lw        $s0, 0x10($sp)
/* CCD524 80242214 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* CCD528 80242218 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* CCD52C 8024221C D7B80038 */  ldc1      $f24, 0x38($sp)
/* CCD530 80242220 D7B60030 */  ldc1      $f22, 0x30($sp)
/* CCD534 80242224 D7B40028 */  ldc1      $f20, 0x28($sp)
/* CCD538 80242228 24020002 */  addiu     $v0, $zero, 2
/* CCD53C 8024222C 03E00008 */  jr        $ra
/* CCD540 80242230 27BD0050 */   addiu    $sp, $sp, 0x50
