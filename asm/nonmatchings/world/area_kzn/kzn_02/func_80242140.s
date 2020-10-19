.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242140
/* C5C880 80242140 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C5C884 80242144 AFB10014 */  sw        $s1, 0x14($sp)
/* C5C888 80242148 0080882D */  daddu     $s1, $a0, $zero
/* C5C88C 8024214C AFBF0024 */  sw        $ra, 0x24($sp)
/* C5C890 80242150 AFB40020 */  sw        $s4, 0x20($sp)
/* C5C894 80242154 AFB3001C */  sw        $s3, 0x1c($sp)
/* C5C898 80242158 AFB20018 */  sw        $s2, 0x18($sp)
/* C5C89C 8024215C AFB00010 */  sw        $s0, 0x10($sp)
/* C5C8A0 80242160 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* C5C8A4 80242164 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* C5C8A8 80242168 F7B80038 */  sdc1      $f24, 0x38($sp)
/* C5C8AC 8024216C F7B60030 */  sdc1      $f22, 0x30($sp)
/* C5C8B0 80242170 F7B40028 */  sdc1      $f20, 0x28($sp)
/* C5C8B4 80242174 8E30000C */  lw        $s0, 0xc($s1)
/* C5C8B8 80242178 8E130000 */  lw        $s3, ($s0)
/* C5C8BC 8024217C 26100004 */  addiu     $s0, $s0, 4
/* C5C8C0 80242180 0C0B1EAF */  jal       get_variable
/* C5C8C4 80242184 0260282D */   daddu    $a1, $s3, $zero
/* C5C8C8 80242188 4482E000 */  mtc1      $v0, $f28
/* C5C8CC 8024218C 00000000 */  nop       
/* C5C8D0 80242190 4680E720 */  cvt.s.w   $f28, $f28
/* C5C8D4 80242194 8E140000 */  lw        $s4, ($s0)
/* C5C8D8 80242198 26100004 */  addiu     $s0, $s0, 4
/* C5C8DC 8024219C 0220202D */  daddu     $a0, $s1, $zero
/* C5C8E0 802421A0 0C0B1EAF */  jal       get_variable
/* C5C8E4 802421A4 0280282D */   daddu    $a1, $s4, $zero
/* C5C8E8 802421A8 4482D000 */  mtc1      $v0, $f26
/* C5C8EC 802421AC 00000000 */  nop       
/* C5C8F0 802421B0 4680D6A0 */  cvt.s.w   $f26, $f26
/* C5C8F4 802421B4 8E100000 */  lw        $s0, ($s0)
/* C5C8F8 802421B8 0220202D */  daddu     $a0, $s1, $zero
/* C5C8FC 802421BC 0C0B1EAF */  jal       get_variable
/* C5C900 802421C0 0200282D */   daddu    $a1, $s0, $zero
/* C5C904 802421C4 4482C000 */  mtc1      $v0, $f24
/* C5C908 802421C8 00000000 */  nop       
/* C5C90C 802421CC 4680C620 */  cvt.s.w   $f24, $f24
/* C5C910 802421D0 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* C5C914 802421D4 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* C5C918 802421D8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* C5C91C 802421DC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* C5C920 802421E0 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* C5C924 802421E4 44800000 */  mtc1      $zero, $f0
/* C5C928 802421E8 00031080 */  sll       $v0, $v1, 2
/* C5C92C 802421EC 00431021 */  addu      $v0, $v0, $v1
/* C5C930 802421F0 00021080 */  sll       $v0, $v0, 2
/* C5C934 802421F4 00431023 */  subu      $v0, $v0, $v1
/* C5C938 802421F8 000218C0 */  sll       $v1, $v0, 3
/* C5C93C 802421FC 00431021 */  addu      $v0, $v0, $v1
/* C5C940 80242200 000210C0 */  sll       $v0, $v0, 3
/* C5C944 80242204 46001032 */  c.eq.s    $f2, $f0
/* C5C948 80242208 3C01800B */  lui       $at, 0x800b
/* C5C94C 8024220C 00220821 */  addu      $at, $at, $v0
/* C5C950 80242210 C4361DEC */  lwc1      $f22, 0x1dec($at)
/* C5C954 80242214 45000005 */  bc1f      .L8024222C
/* C5C958 80242218 00000000 */   nop      
/* C5C95C 8024221C 3C0142C8 */  lui       $at, 0x42c8
/* C5C960 80242220 44810000 */  mtc1      $at, $f0
/* C5C964 80242224 0809088F */  j         .L8024223C
/* C5C968 80242228 4600B581 */   sub.s    $f22, $f22, $f0
.L8024222C:
/* C5C96C 8024222C 3C0142C8 */  lui       $at, 0x42c8
/* C5C970 80242230 44810000 */  mtc1      $at, $f0
/* C5C974 80242234 00000000 */  nop       
/* C5C978 80242238 4600B580 */  add.s     $f22, $f22, $f0
.L8024223C:
/* C5C97C 8024223C 0C00A6C9 */  jal       clamp_angle
/* C5C980 80242240 4600B306 */   mov.s    $f12, $f22
/* C5C984 80242244 46000586 */  mov.s     $f22, $f0
/* C5C988 80242248 3C014170 */  lui       $at, 0x4170
/* C5C98C 8024224C 4481A000 */  mtc1      $at, $f20
/* C5C990 80242250 0C00A8BB */  jal       sin_deg
/* C5C994 80242254 4600B306 */   mov.s    $f12, $f22
/* C5C998 80242258 46140002 */  mul.s     $f0, $f0, $f20
/* C5C99C 8024225C 00000000 */  nop       
/* C5C9A0 80242260 864200B0 */  lh        $v0, 0xb0($s2)
/* C5C9A4 80242264 3C013F00 */  lui       $at, 0x3f00
/* C5C9A8 80242268 44812000 */  mtc1      $at, $f4
/* C5C9AC 8024226C 44821000 */  mtc1      $v0, $f2
/* C5C9B0 80242270 00000000 */  nop       
/* C5C9B4 80242274 468010A0 */  cvt.s.w   $f2, $f2
/* C5C9B8 80242278 46041082 */  mul.s     $f2, $f2, $f4
/* C5C9BC 8024227C 00000000 */  nop       
/* C5C9C0 80242280 4600E700 */  add.s     $f28, $f28, $f0
/* C5C9C4 80242284 4602D680 */  add.s     $f26, $f26, $f2
/* C5C9C8 80242288 0C00A8D4 */  jal       cos_deg
/* C5C9CC 8024228C 4600B306 */   mov.s    $f12, $f22
/* C5C9D0 80242290 46140002 */  mul.s     $f0, $f0, $f20
/* C5C9D4 80242294 00000000 */  nop       
/* C5C9D8 80242298 0220202D */  daddu     $a0, $s1, $zero
/* C5C9DC 8024229C 0260282D */  daddu     $a1, $s3, $zero
/* C5C9E0 802422A0 4600E18D */  trunc.w.s $f6, $f28
/* C5C9E4 802422A4 44063000 */  mfc1      $a2, $f6
/* C5C9E8 802422A8 0C0B2026 */  jal       set_variable
/* C5C9EC 802422AC 4600C601 */   sub.s    $f24, $f24, $f0
/* C5C9F0 802422B0 0220202D */  daddu     $a0, $s1, $zero
/* C5C9F4 802422B4 4600D18D */  trunc.w.s $f6, $f26
/* C5C9F8 802422B8 44063000 */  mfc1      $a2, $f6
/* C5C9FC 802422BC 0C0B2026 */  jal       set_variable
/* C5CA00 802422C0 0280282D */   daddu    $a1, $s4, $zero
/* C5CA04 802422C4 0220202D */  daddu     $a0, $s1, $zero
/* C5CA08 802422C8 4600C18D */  trunc.w.s $f6, $f24
/* C5CA0C 802422CC 44063000 */  mfc1      $a2, $f6
/* C5CA10 802422D0 0C0B2026 */  jal       set_variable
/* C5CA14 802422D4 0200282D */   daddu    $a1, $s0, $zero
/* C5CA18 802422D8 8FBF0024 */  lw        $ra, 0x24($sp)
/* C5CA1C 802422DC 8FB40020 */  lw        $s4, 0x20($sp)
/* C5CA20 802422E0 8FB3001C */  lw        $s3, 0x1c($sp)
/* C5CA24 802422E4 8FB20018 */  lw        $s2, 0x18($sp)
/* C5CA28 802422E8 8FB10014 */  lw        $s1, 0x14($sp)
/* C5CA2C 802422EC 8FB00010 */  lw        $s0, 0x10($sp)
/* C5CA30 802422F0 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* C5CA34 802422F4 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* C5CA38 802422F8 D7B80038 */  ldc1      $f24, 0x38($sp)
/* C5CA3C 802422FC D7B60030 */  ldc1      $f22, 0x30($sp)
/* C5CA40 80242300 D7B40028 */  ldc1      $f20, 0x28($sp)
/* C5CA44 80242304 24020002 */  addiu     $v0, $zero, 2
/* C5CA48 80242308 03E00008 */  jr        $ra
/* C5CA4C 8024230C 27BD0050 */   addiu    $sp, $sp, 0x50
