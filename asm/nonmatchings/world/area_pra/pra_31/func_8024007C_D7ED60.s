.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024007C_D7EDDC
/* D7EDDC 8024007C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D7EDE0 80240080 AFB10014 */  sw        $s1, 0x14($sp)
/* D7EDE4 80240084 0080882D */  daddu     $s1, $a0, $zero
/* D7EDE8 80240088 AFBF0024 */  sw        $ra, 0x24($sp)
/* D7EDEC 8024008C AFB40020 */  sw        $s4, 0x20($sp)
/* D7EDF0 80240090 AFB3001C */  sw        $s3, 0x1c($sp)
/* D7EDF4 80240094 AFB20018 */  sw        $s2, 0x18($sp)
/* D7EDF8 80240098 AFB00010 */  sw        $s0, 0x10($sp)
/* D7EDFC 8024009C F7BC0048 */  sdc1      $f28, 0x48($sp)
/* D7EE00 802400A0 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* D7EE04 802400A4 F7B80038 */  sdc1      $f24, 0x38($sp)
/* D7EE08 802400A8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* D7EE0C 802400AC F7B40028 */  sdc1      $f20, 0x28($sp)
/* D7EE10 802400B0 8E30000C */  lw        $s0, 0xc($s1)
/* D7EE14 802400B4 8E130000 */  lw        $s3, ($s0)
/* D7EE18 802400B8 26100004 */  addiu     $s0, $s0, 4
/* D7EE1C 802400BC 0C0B1EAF */  jal       get_variable
/* D7EE20 802400C0 0260282D */   daddu    $a1, $s3, $zero
/* D7EE24 802400C4 4482E000 */  mtc1      $v0, $f28
/* D7EE28 802400C8 00000000 */  nop       
/* D7EE2C 802400CC 4680E720 */  cvt.s.w   $f28, $f28
/* D7EE30 802400D0 8E140000 */  lw        $s4, ($s0)
/* D7EE34 802400D4 26100004 */  addiu     $s0, $s0, 4
/* D7EE38 802400D8 0220202D */  daddu     $a0, $s1, $zero
/* D7EE3C 802400DC 0C0B1EAF */  jal       get_variable
/* D7EE40 802400E0 0280282D */   daddu    $a1, $s4, $zero
/* D7EE44 802400E4 4482D000 */  mtc1      $v0, $f26
/* D7EE48 802400E8 00000000 */  nop       
/* D7EE4C 802400EC 4680D6A0 */  cvt.s.w   $f26, $f26
/* D7EE50 802400F0 8E100000 */  lw        $s0, ($s0)
/* D7EE54 802400F4 0220202D */  daddu     $a0, $s1, $zero
/* D7EE58 802400F8 0C0B1EAF */  jal       get_variable
/* D7EE5C 802400FC 0200282D */   daddu    $a1, $s0, $zero
/* D7EE60 80240100 4482C000 */  mtc1      $v0, $f24
/* D7EE64 80240104 00000000 */  nop       
/* D7EE68 80240108 4680C620 */  cvt.s.w   $f24, $f24
/* D7EE6C 8024010C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* D7EE70 80240110 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* D7EE74 80240114 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* D7EE78 80240118 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* D7EE7C 8024011C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* D7EE80 80240120 44800000 */  mtc1      $zero, $f0
/* D7EE84 80240124 00031080 */  sll       $v0, $v1, 2
/* D7EE88 80240128 00431021 */  addu      $v0, $v0, $v1
/* D7EE8C 8024012C 00021080 */  sll       $v0, $v0, 2
/* D7EE90 80240130 00431023 */  subu      $v0, $v0, $v1
/* D7EE94 80240134 000218C0 */  sll       $v1, $v0, 3
/* D7EE98 80240138 00431021 */  addu      $v0, $v0, $v1
/* D7EE9C 8024013C 000210C0 */  sll       $v0, $v0, 3
/* D7EEA0 80240140 46001032 */  c.eq.s    $f2, $f0
/* D7EEA4 80240144 3C01800B */  lui       $at, 0x800b
/* D7EEA8 80240148 00220821 */  addu      $at, $at, $v0
/* D7EEAC 8024014C C4361DEC */  lwc1      $f22, 0x1dec($at)
/* D7EEB0 80240150 45000005 */  bc1f      .L80240168
/* D7EEB4 80240154 00000000 */   nop      
/* D7EEB8 80240158 3C0142C8 */  lui       $at, 0x42c8
/* D7EEBC 8024015C 44810000 */  mtc1      $at, $f0
/* D7EEC0 80240160 0809005E */  j         .L80240178
/* D7EEC4 80240164 4600B581 */   sub.s    $f22, $f22, $f0
.L80240168:
/* D7EEC8 80240168 3C0142C8 */  lui       $at, 0x42c8
/* D7EECC 8024016C 44810000 */  mtc1      $at, $f0
/* D7EED0 80240170 00000000 */  nop       
/* D7EED4 80240174 4600B580 */  add.s     $f22, $f22, $f0
.L80240178:
/* D7EED8 80240178 0C00A6C9 */  jal       clamp_angle
/* D7EEDC 8024017C 4600B306 */   mov.s    $f12, $f22
/* D7EEE0 80240180 46000586 */  mov.s     $f22, $f0
/* D7EEE4 80240184 3C014170 */  lui       $at, 0x4170
/* D7EEE8 80240188 4481A000 */  mtc1      $at, $f20
/* D7EEEC 8024018C 0C00A8BB */  jal       sin_deg
/* D7EEF0 80240190 4600B306 */   mov.s    $f12, $f22
/* D7EEF4 80240194 46140002 */  mul.s     $f0, $f0, $f20
/* D7EEF8 80240198 00000000 */  nop       
/* D7EEFC 8024019C 864200B0 */  lh        $v0, 0xb0($s2)
/* D7EF00 802401A0 3C013F00 */  lui       $at, 0x3f00
/* D7EF04 802401A4 44812000 */  mtc1      $at, $f4
/* D7EF08 802401A8 44821000 */  mtc1      $v0, $f2
/* D7EF0C 802401AC 00000000 */  nop       
/* D7EF10 802401B0 468010A0 */  cvt.s.w   $f2, $f2
/* D7EF14 802401B4 46041082 */  mul.s     $f2, $f2, $f4
/* D7EF18 802401B8 00000000 */  nop       
/* D7EF1C 802401BC 4600E700 */  add.s     $f28, $f28, $f0
/* D7EF20 802401C0 4602D680 */  add.s     $f26, $f26, $f2
/* D7EF24 802401C4 0C00A8D4 */  jal       cos_deg
/* D7EF28 802401C8 4600B306 */   mov.s    $f12, $f22
/* D7EF2C 802401CC 46140002 */  mul.s     $f0, $f0, $f20
/* D7EF30 802401D0 00000000 */  nop       
/* D7EF34 802401D4 0220202D */  daddu     $a0, $s1, $zero
/* D7EF38 802401D8 0260282D */  daddu     $a1, $s3, $zero
/* D7EF3C 802401DC 4600E18D */  trunc.w.s $f6, $f28
/* D7EF40 802401E0 44063000 */  mfc1      $a2, $f6
/* D7EF44 802401E4 0C0B2026 */  jal       set_variable
/* D7EF48 802401E8 4600C601 */   sub.s    $f24, $f24, $f0
/* D7EF4C 802401EC 0220202D */  daddu     $a0, $s1, $zero
/* D7EF50 802401F0 4600D18D */  trunc.w.s $f6, $f26
/* D7EF54 802401F4 44063000 */  mfc1      $a2, $f6
/* D7EF58 802401F8 0C0B2026 */  jal       set_variable
/* D7EF5C 802401FC 0280282D */   daddu    $a1, $s4, $zero
/* D7EF60 80240200 0220202D */  daddu     $a0, $s1, $zero
/* D7EF64 80240204 4600C18D */  trunc.w.s $f6, $f24
/* D7EF68 80240208 44063000 */  mfc1      $a2, $f6
/* D7EF6C 8024020C 0C0B2026 */  jal       set_variable
/* D7EF70 80240210 0200282D */   daddu    $a1, $s0, $zero
/* D7EF74 80240214 8FBF0024 */  lw        $ra, 0x24($sp)
/* D7EF78 80240218 8FB40020 */  lw        $s4, 0x20($sp)
/* D7EF7C 8024021C 8FB3001C */  lw        $s3, 0x1c($sp)
/* D7EF80 80240220 8FB20018 */  lw        $s2, 0x18($sp)
/* D7EF84 80240224 8FB10014 */  lw        $s1, 0x14($sp)
/* D7EF88 80240228 8FB00010 */  lw        $s0, 0x10($sp)
/* D7EF8C 8024022C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* D7EF90 80240230 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* D7EF94 80240234 D7B80038 */  ldc1      $f24, 0x38($sp)
/* D7EF98 80240238 D7B60030 */  ldc1      $f22, 0x30($sp)
/* D7EF9C 8024023C D7B40028 */  ldc1      $f20, 0x28($sp)
/* D7EFA0 80240240 24020002 */  addiu     $v0, $zero, 2
/* D7EFA4 80240244 03E00008 */  jr        $ra
/* D7EFA8 80240248 27BD0050 */   addiu    $sp, $sp, 0x50
