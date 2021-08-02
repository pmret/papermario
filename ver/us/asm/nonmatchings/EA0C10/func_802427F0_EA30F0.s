.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427F0_EA30F0
/* EA30F0 802427F0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EA30F4 802427F4 AFB10014 */  sw        $s1, 0x14($sp)
/* EA30F8 802427F8 0080882D */  daddu     $s1, $a0, $zero
/* EA30FC 802427FC AFBF0024 */  sw        $ra, 0x24($sp)
/* EA3100 80242800 AFB40020 */  sw        $s4, 0x20($sp)
/* EA3104 80242804 AFB3001C */  sw        $s3, 0x1c($sp)
/* EA3108 80242808 AFB20018 */  sw        $s2, 0x18($sp)
/* EA310C 8024280C AFB00010 */  sw        $s0, 0x10($sp)
/* EA3110 80242810 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* EA3114 80242814 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* EA3118 80242818 F7B80038 */  sdc1      $f24, 0x38($sp)
/* EA311C 8024281C F7B60030 */  sdc1      $f22, 0x30($sp)
/* EA3120 80242820 F7B40028 */  sdc1      $f20, 0x28($sp)
/* EA3124 80242824 8E30000C */  lw        $s0, 0xc($s1)
/* EA3128 80242828 8E130000 */  lw        $s3, ($s0)
/* EA312C 8024282C 26100004 */  addiu     $s0, $s0, 4
/* EA3130 80242830 0C0B53A3 */  jal       dead_get_variable
/* EA3134 80242834 0260282D */   daddu    $a1, $s3, $zero
/* EA3138 80242838 4482E000 */  mtc1      $v0, $f28
/* EA313C 8024283C 00000000 */  nop
/* EA3140 80242840 4680E720 */  cvt.s.w   $f28, $f28
/* EA3144 80242844 8E140000 */  lw        $s4, ($s0)
/* EA3148 80242848 26100004 */  addiu     $s0, $s0, 4
/* EA314C 8024284C 0220202D */  daddu     $a0, $s1, $zero
/* EA3150 80242850 0C0B53A3 */  jal       dead_get_variable
/* EA3154 80242854 0280282D */   daddu    $a1, $s4, $zero
/* EA3158 80242858 4482D000 */  mtc1      $v0, $f26
/* EA315C 8024285C 00000000 */  nop
/* EA3160 80242860 4680D6A0 */  cvt.s.w   $f26, $f26
/* EA3164 80242864 8E100000 */  lw        $s0, ($s0)
/* EA3168 80242868 0220202D */  daddu     $a0, $s1, $zero
/* EA316C 8024286C 0C0B53A3 */  jal       dead_get_variable
/* EA3170 80242870 0200282D */   daddu    $a1, $s0, $zero
/* EA3174 80242874 4482C000 */  mtc1      $v0, $f24
/* EA3178 80242878 00000000 */  nop
/* EA317C 8024287C 4680C620 */  cvt.s.w   $f24, $f24
/* EA3180 80242880 3C128011 */  lui       $s2, %hi(D_80117578)
/* EA3184 80242884 26527578 */  addiu     $s2, $s2, %lo(D_80117578)
/* EA3188 80242888 3C038008 */  lui       $v1, %hi(D_8007C760)
/* EA318C 8024288C 8C63C760 */  lw        $v1, %lo(D_8007C760)($v1)
/* EA3190 80242890 C64200A8 */  lwc1      $f2, 0xa8($s2)
/* EA3194 80242894 44800000 */  mtc1      $zero, $f0
/* EA3198 80242898 00031080 */  sll       $v0, $v1, 2
/* EA319C 8024289C 00431021 */  addu      $v0, $v0, $v1
/* EA31A0 802428A0 00021080 */  sll       $v0, $v0, 2
/* EA31A4 802428A4 00431023 */  subu      $v0, $v0, $v1
/* EA31A8 802428A8 000218C0 */  sll       $v1, $v0, 3
/* EA31AC 802428AC 00431021 */  addu      $v0, $v0, $v1
/* EA31B0 802428B0 000210C0 */  sll       $v0, $v0, 3
/* EA31B4 802428B4 46001032 */  c.eq.s    $f2, $f0
/* EA31B8 802428B8 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* EA31BC 802428BC 00220821 */  addu      $at, $at, $v0
/* EA31C0 802428C0 C4368DEC */  lwc1      $f22, %lo(D_800B8DEC)($at)
/* EA31C4 802428C4 45000005 */  bc1f      .L802428DC
/* EA31C8 802428C8 00000000 */   nop
/* EA31CC 802428CC 3C0142C8 */  lui       $at, 0x42c8
/* EA31D0 802428D0 44810000 */  mtc1      $at, $f0
/* EA31D4 802428D4 08090A3B */  j         .L802428EC
/* EA31D8 802428D8 4600B581 */   sub.s    $f22, $f22, $f0
.L802428DC:
/* EA31DC 802428DC 3C0142C8 */  lui       $at, 0x42c8
/* EA31E0 802428E0 44810000 */  mtc1      $at, $f0
/* EA31E4 802428E4 00000000 */  nop
/* EA31E8 802428E8 4600B580 */  add.s     $f22, $f22, $f0
.L802428EC:
/* EA31EC 802428EC 0C00AB85 */  jal       dead_clamp_angle
/* EA31F0 802428F0 4600B306 */   mov.s    $f12, $f22
/* EA31F4 802428F4 46000586 */  mov.s     $f22, $f0
/* EA31F8 802428F8 3C014170 */  lui       $at, 0x4170
/* EA31FC 802428FC 4481A000 */  mtc1      $at, $f20
/* EA3200 80242900 0C00AD77 */  jal       func_8002B5DC
/* EA3204 80242904 4600B306 */   mov.s    $f12, $f22
/* EA3208 80242908 46140002 */  mul.s     $f0, $f0, $f20
/* EA320C 8024290C 00000000 */  nop
/* EA3210 80242910 864200B0 */  lh        $v0, 0xb0($s2)
/* EA3214 80242914 3C013F00 */  lui       $at, 0x3f00
/* EA3218 80242918 44812000 */  mtc1      $at, $f4
/* EA321C 8024291C 44821000 */  mtc1      $v0, $f2
/* EA3220 80242920 00000000 */  nop
/* EA3224 80242924 468010A0 */  cvt.s.w   $f2, $f2
/* EA3228 80242928 46041082 */  mul.s     $f2, $f2, $f4
/* EA322C 8024292C 00000000 */  nop
/* EA3230 80242930 4600E700 */  add.s     $f28, $f28, $f0
/* EA3234 80242934 4602D680 */  add.s     $f26, $f26, $f2
/* EA3238 80242938 0C00AD90 */  jal       func_8002B640
/* EA323C 8024293C 4600B306 */   mov.s    $f12, $f22
/* EA3240 80242940 46140002 */  mul.s     $f0, $f0, $f20
/* EA3244 80242944 00000000 */  nop
/* EA3248 80242948 0220202D */  daddu     $a0, $s1, $zero
/* EA324C 8024294C 0260282D */  daddu     $a1, $s3, $zero
/* EA3250 80242950 4600E18D */  trunc.w.s $f6, $f28
/* EA3254 80242954 44063000 */  mfc1      $a2, $f6
/* EA3258 80242958 0C0B551A */  jal       dead_set_variable
/* EA325C 8024295C 4600C601 */   sub.s    $f24, $f24, $f0
/* EA3260 80242960 0220202D */  daddu     $a0, $s1, $zero
/* EA3264 80242964 4600D18D */  trunc.w.s $f6, $f26
/* EA3268 80242968 44063000 */  mfc1      $a2, $f6
/* EA326C 8024296C 0C0B551A */  jal       dead_set_variable
/* EA3270 80242970 0280282D */   daddu    $a1, $s4, $zero
/* EA3274 80242974 0220202D */  daddu     $a0, $s1, $zero
/* EA3278 80242978 4600C18D */  trunc.w.s $f6, $f24
/* EA327C 8024297C 44063000 */  mfc1      $a2, $f6
/* EA3280 80242980 0C0B551A */  jal       dead_set_variable
/* EA3284 80242984 0200282D */   daddu    $a1, $s0, $zero
/* EA3288 80242988 8FBF0024 */  lw        $ra, 0x24($sp)
/* EA328C 8024298C 8FB40020 */  lw        $s4, 0x20($sp)
/* EA3290 80242990 8FB3001C */  lw        $s3, 0x1c($sp)
/* EA3294 80242994 8FB20018 */  lw        $s2, 0x18($sp)
/* EA3298 80242998 8FB10014 */  lw        $s1, 0x14($sp)
/* EA329C 8024299C 8FB00010 */  lw        $s0, 0x10($sp)
/* EA32A0 802429A0 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* EA32A4 802429A4 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* EA32A8 802429A8 D7B80038 */  ldc1      $f24, 0x38($sp)
/* EA32AC 802429AC D7B60030 */  ldc1      $f22, 0x30($sp)
/* EA32B0 802429B0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* EA32B4 802429B4 24020002 */  addiu     $v0, $zero, 2
/* EA32B8 802429B8 03E00008 */  jr        $ra
/* EA32BC 802429BC 27BD0050 */   addiu    $sp, $sp, 0x50
