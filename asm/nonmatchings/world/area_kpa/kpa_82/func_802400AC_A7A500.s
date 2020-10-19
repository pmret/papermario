.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400AC_A7A5AC
/* A7A5AC 802400AC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A7A5B0 802400B0 AFB10014 */  sw        $s1, 0x14($sp)
/* A7A5B4 802400B4 0080882D */  daddu     $s1, $a0, $zero
/* A7A5B8 802400B8 AFBF0024 */  sw        $ra, 0x24($sp)
/* A7A5BC 802400BC AFB40020 */  sw        $s4, 0x20($sp)
/* A7A5C0 802400C0 AFB3001C */  sw        $s3, 0x1c($sp)
/* A7A5C4 802400C4 AFB20018 */  sw        $s2, 0x18($sp)
/* A7A5C8 802400C8 AFB00010 */  sw        $s0, 0x10($sp)
/* A7A5CC 802400CC F7BC0048 */  sdc1      $f28, 0x48($sp)
/* A7A5D0 802400D0 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* A7A5D4 802400D4 F7B80038 */  sdc1      $f24, 0x38($sp)
/* A7A5D8 802400D8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* A7A5DC 802400DC F7B40028 */  sdc1      $f20, 0x28($sp)
/* A7A5E0 802400E0 8E30000C */  lw        $s0, 0xc($s1)
/* A7A5E4 802400E4 8E130000 */  lw        $s3, ($s0)
/* A7A5E8 802400E8 26100004 */  addiu     $s0, $s0, 4
/* A7A5EC 802400EC 0C0B1EAF */  jal       get_variable
/* A7A5F0 802400F0 0260282D */   daddu    $a1, $s3, $zero
/* A7A5F4 802400F4 4482E000 */  mtc1      $v0, $f28
/* A7A5F8 802400F8 00000000 */  nop       
/* A7A5FC 802400FC 4680E720 */  cvt.s.w   $f28, $f28
/* A7A600 80240100 8E140000 */  lw        $s4, ($s0)
/* A7A604 80240104 26100004 */  addiu     $s0, $s0, 4
/* A7A608 80240108 0220202D */  daddu     $a0, $s1, $zero
/* A7A60C 8024010C 0C0B1EAF */  jal       get_variable
/* A7A610 80240110 0280282D */   daddu    $a1, $s4, $zero
/* A7A614 80240114 4482D000 */  mtc1      $v0, $f26
/* A7A618 80240118 00000000 */  nop       
/* A7A61C 8024011C 4680D6A0 */  cvt.s.w   $f26, $f26
/* A7A620 80240120 8E100000 */  lw        $s0, ($s0)
/* A7A624 80240124 0220202D */  daddu     $a0, $s1, $zero
/* A7A628 80240128 0C0B1EAF */  jal       get_variable
/* A7A62C 8024012C 0200282D */   daddu    $a1, $s0, $zero
/* A7A630 80240130 4482C000 */  mtc1      $v0, $f24
/* A7A634 80240134 00000000 */  nop       
/* A7A638 80240138 4680C620 */  cvt.s.w   $f24, $f24
/* A7A63C 8024013C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* A7A640 80240140 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* A7A644 80240144 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A7A648 80240148 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A7A64C 8024014C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* A7A650 80240150 44800000 */  mtc1      $zero, $f0
/* A7A654 80240154 00031080 */  sll       $v0, $v1, 2
/* A7A658 80240158 00431021 */  addu      $v0, $v0, $v1
/* A7A65C 8024015C 00021080 */  sll       $v0, $v0, 2
/* A7A660 80240160 00431023 */  subu      $v0, $v0, $v1
/* A7A664 80240164 000218C0 */  sll       $v1, $v0, 3
/* A7A668 80240168 00431021 */  addu      $v0, $v0, $v1
/* A7A66C 8024016C 000210C0 */  sll       $v0, $v0, 3
/* A7A670 80240170 46001032 */  c.eq.s    $f2, $f0
/* A7A674 80240174 3C01800B */  lui       $at, 0x800b
/* A7A678 80240178 00220821 */  addu      $at, $at, $v0
/* A7A67C 8024017C C4361DEC */  lwc1      $f22, 0x1dec($at)
/* A7A680 80240180 45000005 */  bc1f      .L80240198
/* A7A684 80240184 00000000 */   nop      
/* A7A688 80240188 3C0142C8 */  lui       $at, 0x42c8
/* A7A68C 8024018C 44810000 */  mtc1      $at, $f0
/* A7A690 80240190 0809006A */  j         .L802401A8
/* A7A694 80240194 4600B581 */   sub.s    $f22, $f22, $f0
.L80240198:
/* A7A698 80240198 3C0142C8 */  lui       $at, 0x42c8
/* A7A69C 8024019C 44810000 */  mtc1      $at, $f0
/* A7A6A0 802401A0 00000000 */  nop       
/* A7A6A4 802401A4 4600B580 */  add.s     $f22, $f22, $f0
.L802401A8:
/* A7A6A8 802401A8 0C00A6C9 */  jal       clamp_angle
/* A7A6AC 802401AC 4600B306 */   mov.s    $f12, $f22
/* A7A6B0 802401B0 46000586 */  mov.s     $f22, $f0
/* A7A6B4 802401B4 3C014170 */  lui       $at, 0x4170
/* A7A6B8 802401B8 4481A000 */  mtc1      $at, $f20
/* A7A6BC 802401BC 0C00A8BB */  jal       sin_deg
/* A7A6C0 802401C0 4600B306 */   mov.s    $f12, $f22
/* A7A6C4 802401C4 46140002 */  mul.s     $f0, $f0, $f20
/* A7A6C8 802401C8 00000000 */  nop       
/* A7A6CC 802401CC 864200B0 */  lh        $v0, 0xb0($s2)
/* A7A6D0 802401D0 3C013F00 */  lui       $at, 0x3f00
/* A7A6D4 802401D4 44812000 */  mtc1      $at, $f4
/* A7A6D8 802401D8 44821000 */  mtc1      $v0, $f2
/* A7A6DC 802401DC 00000000 */  nop       
/* A7A6E0 802401E0 468010A0 */  cvt.s.w   $f2, $f2
/* A7A6E4 802401E4 46041082 */  mul.s     $f2, $f2, $f4
/* A7A6E8 802401E8 00000000 */  nop       
/* A7A6EC 802401EC 4600E700 */  add.s     $f28, $f28, $f0
/* A7A6F0 802401F0 4602D680 */  add.s     $f26, $f26, $f2
/* A7A6F4 802401F4 0C00A8D4 */  jal       cos_deg
/* A7A6F8 802401F8 4600B306 */   mov.s    $f12, $f22
/* A7A6FC 802401FC 46140002 */  mul.s     $f0, $f0, $f20
/* A7A700 80240200 00000000 */  nop       
/* A7A704 80240204 0220202D */  daddu     $a0, $s1, $zero
/* A7A708 80240208 0260282D */  daddu     $a1, $s3, $zero
/* A7A70C 8024020C 4600E18D */  trunc.w.s $f6, $f28
/* A7A710 80240210 44063000 */  mfc1      $a2, $f6
/* A7A714 80240214 0C0B2026 */  jal       set_variable
/* A7A718 80240218 4600C601 */   sub.s    $f24, $f24, $f0
/* A7A71C 8024021C 0220202D */  daddu     $a0, $s1, $zero
/* A7A720 80240220 4600D18D */  trunc.w.s $f6, $f26
/* A7A724 80240224 44063000 */  mfc1      $a2, $f6
/* A7A728 80240228 0C0B2026 */  jal       set_variable
/* A7A72C 8024022C 0280282D */   daddu    $a1, $s4, $zero
/* A7A730 80240230 0220202D */  daddu     $a0, $s1, $zero
/* A7A734 80240234 4600C18D */  trunc.w.s $f6, $f24
/* A7A738 80240238 44063000 */  mfc1      $a2, $f6
/* A7A73C 8024023C 0C0B2026 */  jal       set_variable
/* A7A740 80240240 0200282D */   daddu    $a1, $s0, $zero
/* A7A744 80240244 8FBF0024 */  lw        $ra, 0x24($sp)
/* A7A748 80240248 8FB40020 */  lw        $s4, 0x20($sp)
/* A7A74C 8024024C 8FB3001C */  lw        $s3, 0x1c($sp)
/* A7A750 80240250 8FB20018 */  lw        $s2, 0x18($sp)
/* A7A754 80240254 8FB10014 */  lw        $s1, 0x14($sp)
/* A7A758 80240258 8FB00010 */  lw        $s0, 0x10($sp)
/* A7A75C 8024025C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* A7A760 80240260 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* A7A764 80240264 D7B80038 */  ldc1      $f24, 0x38($sp)
/* A7A768 80240268 D7B60030 */  ldc1      $f22, 0x30($sp)
/* A7A76C 8024026C D7B40028 */  ldc1      $f20, 0x28($sp)
/* A7A770 80240270 24020002 */  addiu     $v0, $zero, 2
/* A7A774 80240274 03E00008 */  jr        $ra
/* A7A778 80240278 27BD0050 */   addiu    $sp, $sp, 0x50
