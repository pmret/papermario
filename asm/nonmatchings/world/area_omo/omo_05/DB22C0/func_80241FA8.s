.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FA8
/* DB4268 80241FA8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* DB426C 80241FAC AFB10014 */  sw        $s1, 0x14($sp)
/* DB4270 80241FB0 0080882D */  daddu     $s1, $a0, $zero
/* DB4274 80241FB4 AFBF0024 */  sw        $ra, 0x24($sp)
/* DB4278 80241FB8 AFB40020 */  sw        $s4, 0x20($sp)
/* DB427C 80241FBC AFB3001C */  sw        $s3, 0x1c($sp)
/* DB4280 80241FC0 AFB20018 */  sw        $s2, 0x18($sp)
/* DB4284 80241FC4 AFB00010 */  sw        $s0, 0x10($sp)
/* DB4288 80241FC8 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* DB428C 80241FCC F7BA0040 */  sdc1      $f26, 0x40($sp)
/* DB4290 80241FD0 F7B80038 */  sdc1      $f24, 0x38($sp)
/* DB4294 80241FD4 F7B60030 */  sdc1      $f22, 0x30($sp)
/* DB4298 80241FD8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* DB429C 80241FDC 8E30000C */  lw        $s0, 0xc($s1)
/* DB42A0 80241FE0 8E130000 */  lw        $s3, ($s0)
/* DB42A4 80241FE4 26100004 */  addiu     $s0, $s0, 4
/* DB42A8 80241FE8 0C0B1EAF */  jal       get_variable
/* DB42AC 80241FEC 0260282D */   daddu    $a1, $s3, $zero
/* DB42B0 80241FF0 4482E000 */  mtc1      $v0, $f28
/* DB42B4 80241FF4 00000000 */  nop       
/* DB42B8 80241FF8 4680E720 */  cvt.s.w   $f28, $f28
/* DB42BC 80241FFC 8E140000 */  lw        $s4, ($s0)
/* DB42C0 80242000 26100004 */  addiu     $s0, $s0, 4
/* DB42C4 80242004 0220202D */  daddu     $a0, $s1, $zero
/* DB42C8 80242008 0C0B1EAF */  jal       get_variable
/* DB42CC 8024200C 0280282D */   daddu    $a1, $s4, $zero
/* DB42D0 80242010 4482D000 */  mtc1      $v0, $f26
/* DB42D4 80242014 00000000 */  nop       
/* DB42D8 80242018 4680D6A0 */  cvt.s.w   $f26, $f26
/* DB42DC 8024201C 8E100000 */  lw        $s0, ($s0)
/* DB42E0 80242020 0220202D */  daddu     $a0, $s1, $zero
/* DB42E4 80242024 0C0B1EAF */  jal       get_variable
/* DB42E8 80242028 0200282D */   daddu    $a1, $s0, $zero
/* DB42EC 8024202C 4482C000 */  mtc1      $v0, $f24
/* DB42F0 80242030 00000000 */  nop       
/* DB42F4 80242034 4680C620 */  cvt.s.w   $f24, $f24
/* DB42F8 80242038 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* DB42FC 8024203C 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* DB4300 80242040 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* DB4304 80242044 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* DB4308 80242048 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* DB430C 8024204C 44800000 */  mtc1      $zero, $f0
/* DB4310 80242050 00031080 */  sll       $v0, $v1, 2
/* DB4314 80242054 00431021 */  addu      $v0, $v0, $v1
/* DB4318 80242058 00021080 */  sll       $v0, $v0, 2
/* DB431C 8024205C 00431023 */  subu      $v0, $v0, $v1
/* DB4320 80242060 000218C0 */  sll       $v1, $v0, 3
/* DB4324 80242064 00431021 */  addu      $v0, $v0, $v1
/* DB4328 80242068 000210C0 */  sll       $v0, $v0, 3
/* DB432C 8024206C 46001032 */  c.eq.s    $f2, $f0
/* DB4330 80242070 3C01800B */  lui       $at, 0x800b
/* DB4334 80242074 00220821 */  addu      $at, $at, $v0
/* DB4338 80242078 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* DB433C 8024207C 45000005 */  bc1f      .L80242094
/* DB4340 80242080 00000000 */   nop      
/* DB4344 80242084 3C0142C8 */  lui       $at, 0x42c8
/* DB4348 80242088 44810000 */  mtc1      $at, $f0
/* DB434C 8024208C 08090829 */  j         .L802420A4
/* DB4350 80242090 4600B581 */   sub.s    $f22, $f22, $f0
.L80242094:
/* DB4354 80242094 3C0142C8 */  lui       $at, 0x42c8
/* DB4358 80242098 44810000 */  mtc1      $at, $f0
/* DB435C 8024209C 00000000 */  nop       
/* DB4360 802420A0 4600B580 */  add.s     $f22, $f22, $f0
.L802420A4:
/* DB4364 802420A4 0C00A6C9 */  jal       clamp_angle
/* DB4368 802420A8 4600B306 */   mov.s    $f12, $f22
/* DB436C 802420AC 46000586 */  mov.s     $f22, $f0
/* DB4370 802420B0 3C014170 */  lui       $at, 0x4170
/* DB4374 802420B4 4481A000 */  mtc1      $at, $f20
/* DB4378 802420B8 0C00A8BB */  jal       sin_deg
/* DB437C 802420BC 4600B306 */   mov.s    $f12, $f22
/* DB4380 802420C0 46140002 */  mul.s     $f0, $f0, $f20
/* DB4384 802420C4 00000000 */  nop       
/* DB4388 802420C8 864200B0 */  lh        $v0, 0xb0($s2)
/* DB438C 802420CC 3C013F00 */  lui       $at, 0x3f00
/* DB4390 802420D0 44812000 */  mtc1      $at, $f4
/* DB4394 802420D4 44821000 */  mtc1      $v0, $f2
/* DB4398 802420D8 00000000 */  nop       
/* DB439C 802420DC 468010A0 */  cvt.s.w   $f2, $f2
/* DB43A0 802420E0 46041082 */  mul.s     $f2, $f2, $f4
/* DB43A4 802420E4 00000000 */  nop       
/* DB43A8 802420E8 4600E700 */  add.s     $f28, $f28, $f0
/* DB43AC 802420EC 4602D680 */  add.s     $f26, $f26, $f2
/* DB43B0 802420F0 0C00A8D4 */  jal       cos_deg
/* DB43B4 802420F4 4600B306 */   mov.s    $f12, $f22
/* DB43B8 802420F8 46140002 */  mul.s     $f0, $f0, $f20
/* DB43BC 802420FC 00000000 */  nop       
/* DB43C0 80242100 0220202D */  daddu     $a0, $s1, $zero
/* DB43C4 80242104 0260282D */  daddu     $a1, $s3, $zero
/* DB43C8 80242108 4600E18D */  trunc.w.s $f6, $f28
/* DB43CC 8024210C 44063000 */  mfc1      $a2, $f6
/* DB43D0 80242110 0C0B2026 */  jal       set_variable
/* DB43D4 80242114 4600C601 */   sub.s    $f24, $f24, $f0
/* DB43D8 80242118 0220202D */  daddu     $a0, $s1, $zero
/* DB43DC 8024211C 4600D18D */  trunc.w.s $f6, $f26
/* DB43E0 80242120 44063000 */  mfc1      $a2, $f6
/* DB43E4 80242124 0C0B2026 */  jal       set_variable
/* DB43E8 80242128 0280282D */   daddu    $a1, $s4, $zero
/* DB43EC 8024212C 0220202D */  daddu     $a0, $s1, $zero
/* DB43F0 80242130 4600C18D */  trunc.w.s $f6, $f24
/* DB43F4 80242134 44063000 */  mfc1      $a2, $f6
/* DB43F8 80242138 0C0B2026 */  jal       set_variable
/* DB43FC 8024213C 0200282D */   daddu    $a1, $s0, $zero
/* DB4400 80242140 8FBF0024 */  lw        $ra, 0x24($sp)
/* DB4404 80242144 8FB40020 */  lw        $s4, 0x20($sp)
/* DB4408 80242148 8FB3001C */  lw        $s3, 0x1c($sp)
/* DB440C 8024214C 8FB20018 */  lw        $s2, 0x18($sp)
/* DB4410 80242150 8FB10014 */  lw        $s1, 0x14($sp)
/* DB4414 80242154 8FB00010 */  lw        $s0, 0x10($sp)
/* DB4418 80242158 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* DB441C 8024215C D7BA0040 */  ldc1      $f26, 0x40($sp)
/* DB4420 80242160 D7B80038 */  ldc1      $f24, 0x38($sp)
/* DB4424 80242164 D7B60030 */  ldc1      $f22, 0x30($sp)
/* DB4428 80242168 D7B40028 */  ldc1      $f20, 0x28($sp)
/* DB442C 8024216C 24020002 */  addiu     $v0, $zero, 2
/* DB4430 80242170 03E00008 */  jr        $ra
/* DB4434 80242174 27BD0050 */   addiu    $sp, $sp, 0x50
