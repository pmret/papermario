.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D2884
/* F7234 802D2884 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* F7238 802D2888 AFB20018 */  sw        $s2, 0x18($sp)
/* F723C 802D288C 0080902D */  daddu     $s2, $a0, $zero
/* F7240 802D2890 AFB3001C */  sw        $s3, 0x1c($sp)
/* F7244 802D2894 3C138011 */  lui       $s3, %hi(gPlayerStatus)
/* F7248 802D2898 2673EFC8 */  addiu     $s3, $s3, %lo(gPlayerStatus)
/* F724C 802D289C AFB50024 */  sw        $s5, 0x24($sp)
/* F7250 802D28A0 26550074 */  addiu     $s5, $s2, 0x74
/* F7254 802D28A4 AFB10014 */  sw        $s1, 0x14($sp)
/* F7258 802D28A8 26510078 */  addiu     $s1, $s2, 0x78
/* F725C 802D28AC AFB40020 */  sw        $s4, 0x20($sp)
/* F7260 802D28B0 AFBF0028 */  sw        $ra, 0x28($sp)
/* F7264 802D28B4 AFB00010 */  sw        $s0, 0x10($sp)
/* F7268 802D28B8 F7B40030 */  sdc1      $f20, 0x30($sp)
/* F726C 802D28BC 8E50000C */  lw        $s0, 0xc($s2)
/* F7270 802D28C0 10A00043 */  beqz      $a1, .L802D29D0
/* F7274 802D28C4 2654007C */   addiu    $s4, $s2, 0x7c
/* F7278 802D28C8 8E050000 */  lw        $a1, ($s0)
/* F727C 802D28CC 0C0B210B */  jal       get_float_variable
/* F7280 802D28D0 26100004 */   addiu    $s0, $s0, 4
/* F7284 802D28D4 0240202D */  daddu     $a0, $s2, $zero
/* F7288 802D28D8 8E050000 */  lw        $a1, ($s0)
/* F728C 802D28DC 0C0B210B */  jal       get_float_variable
/* F7290 802D28E0 46000506 */   mov.s    $f20, $f0
/* F7294 802D28E4 3C02802E */  lui       $v0, %hi(playerNpc)
/* F7298 802D28E8 8C429D20 */  lw        $v0, %lo(playerNpc)($v0)
/* F729C 802D28EC C6620080 */  lwc1      $f2, 0x80($s3)
/* F72A0 802D28F0 26100004 */  addiu     $s0, $s0, 4
/* F72A4 802D28F4 E442000C */  swc1      $f2, 0xc($v0)
/* F72A8 802D28F8 E6420074 */  swc1      $f2, 0x74($s2)
/* F72AC 802D28FC C66C0028 */  lwc1      $f12, 0x28($s3)
/* F72B0 802D2900 46146032 */  c.eq.s    $f12, $f20
/* F72B4 802D2904 00000000 */  nop
/* F72B8 802D2908 45000006 */  bc1f      .L802D2924
/* F72BC 802D290C 46000086 */   mov.s    $f2, $f0
/* F72C0 802D2910 C6600030 */  lwc1      $f0, 0x30($s3)
/* F72C4 802D2914 46020032 */  c.eq.s    $f0, $f2
/* F72C8 802D2918 00000000 */  nop
/* F72CC 802D291C 45010008 */  bc1t      .L802D2940
/* F72D0 802D2920 00000000 */   nop
.L802D2924:
/* F72D4 802D2924 C66E0030 */  lwc1      $f14, 0x30($s3)
/* F72D8 802D2928 4406A000 */  mfc1      $a2, $f20
/* F72DC 802D292C 44071000 */  mfc1      $a3, $f2
/* F72E0 802D2930 0C00A720 */  jal       atan2
/* F72E4 802D2934 00000000 */   nop
/* F72E8 802D2938 080B4A51 */  j         .L802D2944
/* F72EC 802D293C 46000086 */   mov.s    $f2, $f0
.L802D2940:
/* F72F0 802D2940 C6620080 */  lwc1      $f2, 0x80($s3)
.L802D2944:
/* F72F4 802D2944 C6A00000 */  lwc1      $f0, ($s5)
/* F72F8 802D2948 46001001 */  sub.s     $f0, $f2, $f0
/* F72FC 802D294C E6200000 */  swc1      $f0, ($s1)
/* F7300 802D2950 8E050000 */  lw        $a1, ($s0)
/* F7304 802D2954 0C0B1EAF */  jal       get_variable
/* F7308 802D2958 0240202D */   daddu    $a0, $s2, $zero
/* F730C 802D295C AE820000 */  sw        $v0, ($s4)
/* F7310 802D2960 3C02802E */  lui       $v0, %hi(playerNpc)
/* F7314 802D2964 8C429D20 */  lw        $v0, %lo(playerNpc)($v0)
/* F7318 802D2968 3C01C334 */  lui       $at, 0xc334
/* F731C 802D296C 44810000 */  mtc1      $at, $f0
/* F7320 802D2970 A440008E */  sh        $zero, 0x8e($v0)
/* F7324 802D2974 C6220000 */  lwc1      $f2, ($s1)
/* F7328 802D2978 4600103C */  c.lt.s    $f2, $f0
/* F732C 802D297C 00000000 */  nop
/* F7330 802D2980 45000007 */  bc1f      .L802D29A0
/* F7334 802D2984 00000000 */   nop
/* F7338 802D2988 3C0143B4 */  lui       $at, 0x43b4
/* F733C 802D298C 44810000 */  mtc1      $at, $f0
/* F7340 802D2990 00000000 */  nop
/* F7344 802D2994 46001000 */  add.s     $f0, $f2, $f0
/* F7348 802D2998 E6200000 */  swc1      $f0, ($s1)
/* F734C 802D299C C6220000 */  lwc1      $f2, ($s1)
.L802D29A0:
/* F7350 802D29A0 3C014334 */  lui       $at, 0x4334
/* F7354 802D29A4 44810000 */  mtc1      $at, $f0
/* F7358 802D29A8 00000000 */  nop
/* F735C 802D29AC 4602003C */  c.lt.s    $f0, $f2
/* F7360 802D29B0 00000000 */  nop
/* F7364 802D29B4 45000006 */  bc1f      .L802D29D0
/* F7368 802D29B8 00000000 */   nop
/* F736C 802D29BC 3C0143B4 */  lui       $at, 0x43b4
/* F7370 802D29C0 44810000 */  mtc1      $at, $f0
/* F7374 802D29C4 00000000 */  nop
/* F7378 802D29C8 46001001 */  sub.s     $f0, $f2, $f0
/* F737C 802D29CC E6200000 */  swc1      $f0, ($s1)
.L802D29D0:
/* F7380 802D29D0 8E820000 */  lw        $v0, ($s4)
/* F7384 802D29D4 1C40000E */  bgtz      $v0, .L802D2A10
/* F7388 802D29D8 00000000 */   nop
/* F738C 802D29DC 3C10802E */  lui       $s0, %hi(playerNpc)
/* F7390 802D29E0 26109D20 */  addiu     $s0, $s0, %lo(playerNpc)
/* F7394 802D29E4 8E020000 */  lw        $v0, ($s0)
/* F7398 802D29E8 C6200000 */  lwc1      $f0, ($s1)
/* F739C 802D29EC C44C000C */  lwc1      $f12, 0xc($v0)
/* F73A0 802D29F0 46006300 */  add.s     $f12, $f12, $f0
/* F73A4 802D29F4 0C00A6C9 */  jal       clamp_angle
/* F73A8 802D29F8 E44C000C */   swc1     $f12, 0xc($v0)
/* F73AC 802D29FC 8E030000 */  lw        $v1, ($s0)
/* F73B0 802D2A00 24020002 */  addiu     $v0, $zero, 2
/* F73B4 802D2A04 E460000C */  swc1      $f0, 0xc($v1)
/* F73B8 802D2A08 080B4AA0 */  j         .L802D2A80
/* F73BC 802D2A0C E6600080 */   swc1     $f0, 0x80($s3)
.L802D2A10:
/* F73C0 802D2A10 3C10802E */  lui       $s0, %hi(playerNpc)
/* F73C4 802D2A14 26109D20 */  addiu     $s0, $s0, %lo(playerNpc)
/* F73C8 802D2A18 8E030000 */  lw        $v1, ($s0)
/* F73CC 802D2A1C 9462008E */  lhu       $v0, 0x8e($v1)
/* F73D0 802D2A20 24420001 */  addiu     $v0, $v0, 1
/* F73D4 802D2A24 A462008E */  sh        $v0, 0x8e($v1)
/* F73D8 802D2A28 00021400 */  sll       $v0, $v0, 0x10
/* F73DC 802D2A2C 00021403 */  sra       $v0, $v0, 0x10
/* F73E0 802D2A30 C6200000 */  lwc1      $f0, ($s1)
/* F73E4 802D2A34 44821000 */  mtc1      $v0, $f2
/* F73E8 802D2A38 00000000 */  nop
/* F73EC 802D2A3C 468010A0 */  cvt.s.w   $f2, $f2
/* F73F0 802D2A40 46020002 */  mul.s     $f0, $f0, $f2
/* F73F4 802D2A44 00000000 */  nop
/* F73F8 802D2A48 C6AC0000 */  lwc1      $f12, ($s5)
/* F73FC 802D2A4C C6820000 */  lwc1      $f2, ($s4)
/* F7400 802D2A50 468010A0 */  cvt.s.w   $f2, $f2
/* F7404 802D2A54 46020003 */  div.s     $f0, $f0, $f2
/* F7408 802D2A58 46006300 */  add.s     $f12, $f12, $f0
/* F740C 802D2A5C 0C00A6C9 */  jal       clamp_angle
/* F7410 802D2A60 E46C000C */   swc1     $f12, 0xc($v1)
/* F7414 802D2A64 8E020000 */  lw        $v0, ($s0)
/* F7418 802D2A68 E440000C */  swc1      $f0, 0xc($v0)
/* F741C 802D2A6C E6600080 */  swc1      $f0, 0x80($s3)
/* F7420 802D2A70 8442008E */  lh        $v0, 0x8e($v0)
/* F7424 802D2A74 8E830000 */  lw        $v1, ($s4)
/* F7428 802D2A78 0043102A */  slt       $v0, $v0, $v1
/* F742C 802D2A7C 38420001 */  xori      $v0, $v0, 1
.L802D2A80:
/* F7430 802D2A80 8FBF0028 */  lw        $ra, 0x28($sp)
/* F7434 802D2A84 8FB50024 */  lw        $s5, 0x24($sp)
/* F7438 802D2A88 8FB40020 */  lw        $s4, 0x20($sp)
/* F743C 802D2A8C 8FB3001C */  lw        $s3, 0x1c($sp)
/* F7440 802D2A90 8FB20018 */  lw        $s2, 0x18($sp)
/* F7444 802D2A94 8FB10014 */  lw        $s1, 0x14($sp)
/* F7448 802D2A98 8FB00010 */  lw        $s0, 0x10($sp)
/* F744C 802D2A9C D7B40030 */  ldc1      $f20, 0x30($sp)
/* F7450 802D2AA0 03E00008 */  jr        $ra
/* F7454 802D2AA4 27BD0038 */   addiu    $sp, $sp, 0x38
