.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024039C
/* AF303C 8024039C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* AF3040 802403A0 AFB10014 */  sw        $s1, 0x14($sp)
/* AF3044 802403A4 0080882D */  daddu     $s1, $a0, $zero
/* AF3048 802403A8 AFBF0024 */  sw        $ra, 0x24($sp)
/* AF304C 802403AC AFB40020 */  sw        $s4, 0x20($sp)
/* AF3050 802403B0 AFB3001C */  sw        $s3, 0x1c($sp)
/* AF3054 802403B4 AFB20018 */  sw        $s2, 0x18($sp)
/* AF3058 802403B8 AFB00010 */  sw        $s0, 0x10($sp)
/* AF305C 802403BC F7BC0048 */  sdc1      $f28, 0x48($sp)
/* AF3060 802403C0 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* AF3064 802403C4 F7B80038 */  sdc1      $f24, 0x38($sp)
/* AF3068 802403C8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* AF306C 802403CC F7B40028 */  sdc1      $f20, 0x28($sp)
/* AF3070 802403D0 8E30000C */  lw        $s0, 0xc($s1)
/* AF3074 802403D4 8E130000 */  lw        $s3, ($s0)
/* AF3078 802403D8 26100004 */  addiu     $s0, $s0, 4
/* AF307C 802403DC 0C0B1EAF */  jal       get_variable
/* AF3080 802403E0 0260282D */   daddu    $a1, $s3, $zero
/* AF3084 802403E4 4482E000 */  mtc1      $v0, $f28
/* AF3088 802403E8 00000000 */  nop       
/* AF308C 802403EC 4680E720 */  cvt.s.w   $f28, $f28
/* AF3090 802403F0 8E140000 */  lw        $s4, ($s0)
/* AF3094 802403F4 26100004 */  addiu     $s0, $s0, 4
/* AF3098 802403F8 0220202D */  daddu     $a0, $s1, $zero
/* AF309C 802403FC 0C0B1EAF */  jal       get_variable
/* AF30A0 80240400 0280282D */   daddu    $a1, $s4, $zero
/* AF30A4 80240404 4482D000 */  mtc1      $v0, $f26
/* AF30A8 80240408 00000000 */  nop       
/* AF30AC 8024040C 4680D6A0 */  cvt.s.w   $f26, $f26
/* AF30B0 80240410 8E100000 */  lw        $s0, ($s0)
/* AF30B4 80240414 0220202D */  daddu     $a0, $s1, $zero
/* AF30B8 80240418 0C0B1EAF */  jal       get_variable
/* AF30BC 8024041C 0200282D */   daddu    $a1, $s0, $zero
/* AF30C0 80240420 4482C000 */  mtc1      $v0, $f24
/* AF30C4 80240424 00000000 */  nop       
/* AF30C8 80240428 4680C620 */  cvt.s.w   $f24, $f24
/* AF30CC 8024042C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* AF30D0 80240430 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* AF30D4 80240434 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* AF30D8 80240438 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* AF30DC 8024043C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* AF30E0 80240440 44800000 */  mtc1      $zero, $f0
/* AF30E4 80240444 00031080 */  sll       $v0, $v1, 2
/* AF30E8 80240448 00431021 */  addu      $v0, $v0, $v1
/* AF30EC 8024044C 00021080 */  sll       $v0, $v0, 2
/* AF30F0 80240450 00431023 */  subu      $v0, $v0, $v1
/* AF30F4 80240454 000218C0 */  sll       $v1, $v0, 3
/* AF30F8 80240458 00431021 */  addu      $v0, $v0, $v1
/* AF30FC 8024045C 000210C0 */  sll       $v0, $v0, 3
/* AF3100 80240460 46001032 */  c.eq.s    $f2, $f0
/* AF3104 80240464 3C01800B */  lui       $at, 0x800b
/* AF3108 80240468 00220821 */  addu      $at, $at, $v0
/* AF310C 8024046C C4361DEC */  lwc1      $f22, 0x1dec($at)
/* AF3110 80240470 45000005 */  bc1f      .L80240488
/* AF3114 80240474 00000000 */   nop      
/* AF3118 80240478 3C0142C8 */  lui       $at, 0x42c8
/* AF311C 8024047C 44810000 */  mtc1      $at, $f0
/* AF3120 80240480 08090126 */  j         .L80240498
/* AF3124 80240484 4600B581 */   sub.s    $f22, $f22, $f0
.L80240488:
/* AF3128 80240488 3C0142C8 */  lui       $at, 0x42c8
/* AF312C 8024048C 44810000 */  mtc1      $at, $f0
/* AF3130 80240490 00000000 */  nop       
/* AF3134 80240494 4600B580 */  add.s     $f22, $f22, $f0
.L80240498:
/* AF3138 80240498 0C00A6C9 */  jal       clamp_angle
/* AF313C 8024049C 4600B306 */   mov.s    $f12, $f22
/* AF3140 802404A0 46000586 */  mov.s     $f22, $f0
/* AF3144 802404A4 3C014170 */  lui       $at, 0x4170
/* AF3148 802404A8 4481A000 */  mtc1      $at, $f20
/* AF314C 802404AC 0C00A8BB */  jal       sin_deg
/* AF3150 802404B0 4600B306 */   mov.s    $f12, $f22
/* AF3154 802404B4 46140002 */  mul.s     $f0, $f0, $f20
/* AF3158 802404B8 00000000 */  nop       
/* AF315C 802404BC 864200B0 */  lh        $v0, 0xb0($s2)
/* AF3160 802404C0 3C013F00 */  lui       $at, 0x3f00
/* AF3164 802404C4 44812000 */  mtc1      $at, $f4
/* AF3168 802404C8 44821000 */  mtc1      $v0, $f2
/* AF316C 802404CC 00000000 */  nop       
/* AF3170 802404D0 468010A0 */  cvt.s.w   $f2, $f2
/* AF3174 802404D4 46041082 */  mul.s     $f2, $f2, $f4
/* AF3178 802404D8 00000000 */  nop       
/* AF317C 802404DC 4600E700 */  add.s     $f28, $f28, $f0
/* AF3180 802404E0 4602D680 */  add.s     $f26, $f26, $f2
/* AF3184 802404E4 0C00A8D4 */  jal       cos_deg
/* AF3188 802404E8 4600B306 */   mov.s    $f12, $f22
/* AF318C 802404EC 46140002 */  mul.s     $f0, $f0, $f20
/* AF3190 802404F0 00000000 */  nop       
/* AF3194 802404F4 0220202D */  daddu     $a0, $s1, $zero
/* AF3198 802404F8 0260282D */  daddu     $a1, $s3, $zero
/* AF319C 802404FC 4600E18D */  trunc.w.s $f6, $f28
/* AF31A0 80240500 44063000 */  mfc1      $a2, $f6
/* AF31A4 80240504 0C0B2026 */  jal       set_variable
/* AF31A8 80240508 4600C601 */   sub.s    $f24, $f24, $f0
/* AF31AC 8024050C 0220202D */  daddu     $a0, $s1, $zero
/* AF31B0 80240510 4600D18D */  trunc.w.s $f6, $f26
/* AF31B4 80240514 44063000 */  mfc1      $a2, $f6
/* AF31B8 80240518 0C0B2026 */  jal       set_variable
/* AF31BC 8024051C 0280282D */   daddu    $a1, $s4, $zero
/* AF31C0 80240520 0220202D */  daddu     $a0, $s1, $zero
/* AF31C4 80240524 4600C18D */  trunc.w.s $f6, $f24
/* AF31C8 80240528 44063000 */  mfc1      $a2, $f6
/* AF31CC 8024052C 0C0B2026 */  jal       set_variable
/* AF31D0 80240530 0200282D */   daddu    $a1, $s0, $zero
/* AF31D4 80240534 8FBF0024 */  lw        $ra, 0x24($sp)
/* AF31D8 80240538 8FB40020 */  lw        $s4, 0x20($sp)
/* AF31DC 8024053C 8FB3001C */  lw        $s3, 0x1c($sp)
/* AF31E0 80240540 8FB20018 */  lw        $s2, 0x18($sp)
/* AF31E4 80240544 8FB10014 */  lw        $s1, 0x14($sp)
/* AF31E8 80240548 8FB00010 */  lw        $s0, 0x10($sp)
/* AF31EC 8024054C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* AF31F0 80240550 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* AF31F4 80240554 D7B80038 */  ldc1      $f24, 0x38($sp)
/* AF31F8 80240558 D7B60030 */  ldc1      $f22, 0x30($sp)
/* AF31FC 8024055C D7B40028 */  ldc1      $f20, 0x28($sp)
/* AF3200 80240560 24020002 */  addiu     $v0, $zero, 2
/* AF3204 80240564 03E00008 */  jr        $ra
/* AF3208 80240568 27BD0050 */   addiu    $sp, $sp, 0x50
