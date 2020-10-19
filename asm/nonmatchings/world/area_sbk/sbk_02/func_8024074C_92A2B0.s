.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024074C_92A9FC
/* 92A9FC 8024074C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 92AA00 80240750 AFB10014 */  sw        $s1, 0x14($sp)
/* 92AA04 80240754 0080882D */  daddu     $s1, $a0, $zero
/* 92AA08 80240758 AFBF0024 */  sw        $ra, 0x24($sp)
/* 92AA0C 8024075C AFB40020 */  sw        $s4, 0x20($sp)
/* 92AA10 80240760 AFB3001C */  sw        $s3, 0x1c($sp)
/* 92AA14 80240764 AFB20018 */  sw        $s2, 0x18($sp)
/* 92AA18 80240768 AFB00010 */  sw        $s0, 0x10($sp)
/* 92AA1C 8024076C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 92AA20 80240770 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 92AA24 80240774 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 92AA28 80240778 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 92AA2C 8024077C F7B40028 */  sdc1      $f20, 0x28($sp)
/* 92AA30 80240780 8E30000C */  lw        $s0, 0xc($s1)
/* 92AA34 80240784 8E130000 */  lw        $s3, ($s0)
/* 92AA38 80240788 26100004 */  addiu     $s0, $s0, 4
/* 92AA3C 8024078C 0C0B1EAF */  jal       get_variable
/* 92AA40 80240790 0260282D */   daddu    $a1, $s3, $zero
/* 92AA44 80240794 4482E000 */  mtc1      $v0, $f28
/* 92AA48 80240798 00000000 */  nop       
/* 92AA4C 8024079C 4680E720 */  cvt.s.w   $f28, $f28
/* 92AA50 802407A0 8E140000 */  lw        $s4, ($s0)
/* 92AA54 802407A4 26100004 */  addiu     $s0, $s0, 4
/* 92AA58 802407A8 0220202D */  daddu     $a0, $s1, $zero
/* 92AA5C 802407AC 0C0B1EAF */  jal       get_variable
/* 92AA60 802407B0 0280282D */   daddu    $a1, $s4, $zero
/* 92AA64 802407B4 4482D000 */  mtc1      $v0, $f26
/* 92AA68 802407B8 00000000 */  nop       
/* 92AA6C 802407BC 4680D6A0 */  cvt.s.w   $f26, $f26
/* 92AA70 802407C0 8E100000 */  lw        $s0, ($s0)
/* 92AA74 802407C4 0220202D */  daddu     $a0, $s1, $zero
/* 92AA78 802407C8 0C0B1EAF */  jal       get_variable
/* 92AA7C 802407CC 0200282D */   daddu    $a1, $s0, $zero
/* 92AA80 802407D0 4482C000 */  mtc1      $v0, $f24
/* 92AA84 802407D4 00000000 */  nop       
/* 92AA88 802407D8 4680C620 */  cvt.s.w   $f24, $f24
/* 92AA8C 802407DC 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 92AA90 802407E0 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 92AA94 802407E4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 92AA98 802407E8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 92AA9C 802407EC C64200A8 */  lwc1      $f2, 0xa8($s2)
/* 92AAA0 802407F0 44800000 */  mtc1      $zero, $f0
/* 92AAA4 802407F4 00031080 */  sll       $v0, $v1, 2
/* 92AAA8 802407F8 00431021 */  addu      $v0, $v0, $v1
/* 92AAAC 802407FC 00021080 */  sll       $v0, $v0, 2
/* 92AAB0 80240800 00431023 */  subu      $v0, $v0, $v1
/* 92AAB4 80240804 000218C0 */  sll       $v1, $v0, 3
/* 92AAB8 80240808 00431021 */  addu      $v0, $v0, $v1
/* 92AABC 8024080C 000210C0 */  sll       $v0, $v0, 3
/* 92AAC0 80240810 46001032 */  c.eq.s    $f2, $f0
/* 92AAC4 80240814 3C01800B */  lui       $at, 0x800b
/* 92AAC8 80240818 00220821 */  addu      $at, $at, $v0
/* 92AACC 8024081C C4361DEC */  lwc1      $f22, 0x1dec($at)
/* 92AAD0 80240820 45000005 */  bc1f      .L80240838
/* 92AAD4 80240824 00000000 */   nop      
/* 92AAD8 80240828 3C0142C8 */  lui       $at, 0x42c8
/* 92AADC 8024082C 44810000 */  mtc1      $at, $f0
/* 92AAE0 80240830 08090212 */  j         .L80240848
/* 92AAE4 80240834 4600B581 */   sub.s    $f22, $f22, $f0
.L80240838:
/* 92AAE8 80240838 3C0142C8 */  lui       $at, 0x42c8
/* 92AAEC 8024083C 44810000 */  mtc1      $at, $f0
/* 92AAF0 80240840 00000000 */  nop       
/* 92AAF4 80240844 4600B580 */  add.s     $f22, $f22, $f0
.L80240848:
/* 92AAF8 80240848 0C00A6C9 */  jal       clamp_angle
/* 92AAFC 8024084C 4600B306 */   mov.s    $f12, $f22
/* 92AB00 80240850 46000586 */  mov.s     $f22, $f0
/* 92AB04 80240854 3C014170 */  lui       $at, 0x4170
/* 92AB08 80240858 4481A000 */  mtc1      $at, $f20
/* 92AB0C 8024085C 0C00A8BB */  jal       sin_deg
/* 92AB10 80240860 4600B306 */   mov.s    $f12, $f22
/* 92AB14 80240864 46140002 */  mul.s     $f0, $f0, $f20
/* 92AB18 80240868 00000000 */  nop       
/* 92AB1C 8024086C 864200B0 */  lh        $v0, 0xb0($s2)
/* 92AB20 80240870 3C013F00 */  lui       $at, 0x3f00
/* 92AB24 80240874 44812000 */  mtc1      $at, $f4
/* 92AB28 80240878 44821000 */  mtc1      $v0, $f2
/* 92AB2C 8024087C 00000000 */  nop       
/* 92AB30 80240880 468010A0 */  cvt.s.w   $f2, $f2
/* 92AB34 80240884 46041082 */  mul.s     $f2, $f2, $f4
/* 92AB38 80240888 00000000 */  nop       
/* 92AB3C 8024088C 4600E700 */  add.s     $f28, $f28, $f0
/* 92AB40 80240890 4602D680 */  add.s     $f26, $f26, $f2
/* 92AB44 80240894 0C00A8D4 */  jal       cos_deg
/* 92AB48 80240898 4600B306 */   mov.s    $f12, $f22
/* 92AB4C 8024089C 46140002 */  mul.s     $f0, $f0, $f20
/* 92AB50 802408A0 00000000 */  nop       
/* 92AB54 802408A4 0220202D */  daddu     $a0, $s1, $zero
/* 92AB58 802408A8 0260282D */  daddu     $a1, $s3, $zero
/* 92AB5C 802408AC 4600E18D */  trunc.w.s $f6, $f28
/* 92AB60 802408B0 44063000 */  mfc1      $a2, $f6
/* 92AB64 802408B4 0C0B2026 */  jal       set_variable
/* 92AB68 802408B8 4600C601 */   sub.s    $f24, $f24, $f0
/* 92AB6C 802408BC 0220202D */  daddu     $a0, $s1, $zero
/* 92AB70 802408C0 4600D18D */  trunc.w.s $f6, $f26
/* 92AB74 802408C4 44063000 */  mfc1      $a2, $f6
/* 92AB78 802408C8 0C0B2026 */  jal       set_variable
/* 92AB7C 802408CC 0280282D */   daddu    $a1, $s4, $zero
/* 92AB80 802408D0 0220202D */  daddu     $a0, $s1, $zero
/* 92AB84 802408D4 4600C18D */  trunc.w.s $f6, $f24
/* 92AB88 802408D8 44063000 */  mfc1      $a2, $f6
/* 92AB8C 802408DC 0C0B2026 */  jal       set_variable
/* 92AB90 802408E0 0200282D */   daddu    $a1, $s0, $zero
/* 92AB94 802408E4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 92AB98 802408E8 8FB40020 */  lw        $s4, 0x20($sp)
/* 92AB9C 802408EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 92ABA0 802408F0 8FB20018 */  lw        $s2, 0x18($sp)
/* 92ABA4 802408F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 92ABA8 802408F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 92ABAC 802408FC D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 92ABB0 80240900 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 92ABB4 80240904 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 92ABB8 80240908 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 92ABBC 8024090C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 92ABC0 80240910 24020002 */  addiu     $v0, $zero, 2
/* 92ABC4 80240914 03E00008 */  jr        $ra
/* 92ABC8 80240918 27BD0050 */   addiu    $sp, $sp, 0x50
