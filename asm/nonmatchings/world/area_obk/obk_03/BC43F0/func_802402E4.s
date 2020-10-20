.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402E4
/* BC4564 802402E4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BC4568 802402E8 AFB10014 */  sw        $s1, 0x14($sp)
/* BC456C 802402EC 0080882D */  daddu     $s1, $a0, $zero
/* BC4570 802402F0 AFBF0024 */  sw        $ra, 0x24($sp)
/* BC4574 802402F4 AFB40020 */  sw        $s4, 0x20($sp)
/* BC4578 802402F8 AFB3001C */  sw        $s3, 0x1c($sp)
/* BC457C 802402FC AFB20018 */  sw        $s2, 0x18($sp)
/* BC4580 80240300 AFB00010 */  sw        $s0, 0x10($sp)
/* BC4584 80240304 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* BC4588 80240308 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* BC458C 8024030C F7B80038 */  sdc1      $f24, 0x38($sp)
/* BC4590 80240310 F7B60030 */  sdc1      $f22, 0x30($sp)
/* BC4594 80240314 F7B40028 */  sdc1      $f20, 0x28($sp)
/* BC4598 80240318 8E30000C */  lw        $s0, 0xc($s1)
/* BC459C 8024031C 8E130000 */  lw        $s3, ($s0)
/* BC45A0 80240320 26100004 */  addiu     $s0, $s0, 4
/* BC45A4 80240324 0C0B1EAF */  jal       get_variable
/* BC45A8 80240328 0260282D */   daddu    $a1, $s3, $zero
/* BC45AC 8024032C 4482E000 */  mtc1      $v0, $f28
/* BC45B0 80240330 00000000 */  nop       
/* BC45B4 80240334 4680E720 */  cvt.s.w   $f28, $f28
/* BC45B8 80240338 8E140000 */  lw        $s4, ($s0)
/* BC45BC 8024033C 26100004 */  addiu     $s0, $s0, 4
/* BC45C0 80240340 0220202D */  daddu     $a0, $s1, $zero
/* BC45C4 80240344 0C0B1EAF */  jal       get_variable
/* BC45C8 80240348 0280282D */   daddu    $a1, $s4, $zero
/* BC45CC 8024034C 4482D000 */  mtc1      $v0, $f26
/* BC45D0 80240350 00000000 */  nop       
/* BC45D4 80240354 4680D6A0 */  cvt.s.w   $f26, $f26
/* BC45D8 80240358 8E100000 */  lw        $s0, ($s0)
/* BC45DC 8024035C 0220202D */  daddu     $a0, $s1, $zero
/* BC45E0 80240360 0C0B1EAF */  jal       get_variable
/* BC45E4 80240364 0200282D */   daddu    $a1, $s0, $zero
/* BC45E8 80240368 4482C000 */  mtc1      $v0, $f24
/* BC45EC 8024036C 00000000 */  nop       
/* BC45F0 80240370 4680C620 */  cvt.s.w   $f24, $f24
/* BC45F4 80240374 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* BC45F8 80240378 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* BC45FC 8024037C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* BC4600 80240380 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* BC4604 80240384 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* BC4608 80240388 44800000 */  mtc1      $zero, $f0
/* BC460C 8024038C 00031080 */  sll       $v0, $v1, 2
/* BC4610 80240390 00431021 */  addu      $v0, $v0, $v1
/* BC4614 80240394 00021080 */  sll       $v0, $v0, 2
/* BC4618 80240398 00431023 */  subu      $v0, $v0, $v1
/* BC461C 8024039C 000218C0 */  sll       $v1, $v0, 3
/* BC4620 802403A0 00431021 */  addu      $v0, $v0, $v1
/* BC4624 802403A4 000210C0 */  sll       $v0, $v0, 3
/* BC4628 802403A8 46001032 */  c.eq.s    $f2, $f0
/* BC462C 802403AC 3C01800B */  lui       $at, 0x800b
/* BC4630 802403B0 00220821 */  addu      $at, $at, $v0
/* BC4634 802403B4 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* BC4638 802403B8 45000005 */  bc1f      .L802403D0
/* BC463C 802403BC 00000000 */   nop      
/* BC4640 802403C0 3C0142C8 */  lui       $at, 0x42c8
/* BC4644 802403C4 44810000 */  mtc1      $at, $f0
/* BC4648 802403C8 080900F8 */  j         .L802403E0
/* BC464C 802403CC 4600B581 */   sub.s    $f22, $f22, $f0
.L802403D0:
/* BC4650 802403D0 3C0142C8 */  lui       $at, 0x42c8
/* BC4654 802403D4 44810000 */  mtc1      $at, $f0
/* BC4658 802403D8 00000000 */  nop       
/* BC465C 802403DC 4600B580 */  add.s     $f22, $f22, $f0
.L802403E0:
/* BC4660 802403E0 0C00A6C9 */  jal       clamp_angle
/* BC4664 802403E4 4600B306 */   mov.s    $f12, $f22
/* BC4668 802403E8 46000586 */  mov.s     $f22, $f0
/* BC466C 802403EC 3C014170 */  lui       $at, 0x4170
/* BC4670 802403F0 4481A000 */  mtc1      $at, $f20
/* BC4674 802403F4 0C00A8BB */  jal       sin_deg
/* BC4678 802403F8 4600B306 */   mov.s    $f12, $f22
/* BC467C 802403FC 46140002 */  mul.s     $f0, $f0, $f20
/* BC4680 80240400 00000000 */  nop       
/* BC4684 80240404 864200B0 */  lh        $v0, 0xb0($s2)
/* BC4688 80240408 3C013F00 */  lui       $at, 0x3f00
/* BC468C 8024040C 44812000 */  mtc1      $at, $f4
/* BC4690 80240410 44821000 */  mtc1      $v0, $f2
/* BC4694 80240414 00000000 */  nop       
/* BC4698 80240418 468010A0 */  cvt.s.w   $f2, $f2
/* BC469C 8024041C 46041082 */  mul.s     $f2, $f2, $f4
/* BC46A0 80240420 00000000 */  nop       
/* BC46A4 80240424 4600E700 */  add.s     $f28, $f28, $f0
/* BC46A8 80240428 4602D680 */  add.s     $f26, $f26, $f2
/* BC46AC 8024042C 0C00A8D4 */  jal       cos_deg
/* BC46B0 80240430 4600B306 */   mov.s    $f12, $f22
/* BC46B4 80240434 46140002 */  mul.s     $f0, $f0, $f20
/* BC46B8 80240438 00000000 */  nop       
/* BC46BC 8024043C 0220202D */  daddu     $a0, $s1, $zero
/* BC46C0 80240440 0260282D */  daddu     $a1, $s3, $zero
/* BC46C4 80240444 4600E18D */  trunc.w.s $f6, $f28
/* BC46C8 80240448 44063000 */  mfc1      $a2, $f6
/* BC46CC 8024044C 0C0B2026 */  jal       set_variable
/* BC46D0 80240450 4600C601 */   sub.s    $f24, $f24, $f0
/* BC46D4 80240454 0220202D */  daddu     $a0, $s1, $zero
/* BC46D8 80240458 4600D18D */  trunc.w.s $f6, $f26
/* BC46DC 8024045C 44063000 */  mfc1      $a2, $f6
/* BC46E0 80240460 0C0B2026 */  jal       set_variable
/* BC46E4 80240464 0280282D */   daddu    $a1, $s4, $zero
/* BC46E8 80240468 0220202D */  daddu     $a0, $s1, $zero
/* BC46EC 8024046C 4600C18D */  trunc.w.s $f6, $f24
/* BC46F0 80240470 44063000 */  mfc1      $a2, $f6
/* BC46F4 80240474 0C0B2026 */  jal       set_variable
/* BC46F8 80240478 0200282D */   daddu    $a1, $s0, $zero
/* BC46FC 8024047C 8FBF0024 */  lw        $ra, 0x24($sp)
/* BC4700 80240480 8FB40020 */  lw        $s4, 0x20($sp)
/* BC4704 80240484 8FB3001C */  lw        $s3, 0x1c($sp)
/* BC4708 80240488 8FB20018 */  lw        $s2, 0x18($sp)
/* BC470C 8024048C 8FB10014 */  lw        $s1, 0x14($sp)
/* BC4710 80240490 8FB00010 */  lw        $s0, 0x10($sp)
/* BC4714 80240494 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* BC4718 80240498 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* BC471C 8024049C D7B80038 */  ldc1      $f24, 0x38($sp)
/* BC4720 802404A0 D7B60030 */  ldc1      $f22, 0x30($sp)
/* BC4724 802404A4 D7B40028 */  ldc1      $f20, 0x28($sp)
/* BC4728 802404A8 24020002 */  addiu     $v0, $zero, 2
/* BC472C 802404AC 03E00008 */  jr        $ra
/* BC4730 802404B0 27BD0050 */   addiu    $sp, $sp, 0x50
