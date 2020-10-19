.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024009C_CEE2FC
/* CEE2FC 8024009C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CEE300 802400A0 AFB10014 */  sw        $s1, 0x14($sp)
/* CEE304 802400A4 0080882D */  daddu     $s1, $a0, $zero
/* CEE308 802400A8 AFBF0024 */  sw        $ra, 0x24($sp)
/* CEE30C 802400AC AFB40020 */  sw        $s4, 0x20($sp)
/* CEE310 802400B0 AFB3001C */  sw        $s3, 0x1c($sp)
/* CEE314 802400B4 AFB20018 */  sw        $s2, 0x18($sp)
/* CEE318 802400B8 AFB00010 */  sw        $s0, 0x10($sp)
/* CEE31C 802400BC F7BC0048 */  sdc1      $f28, 0x48($sp)
/* CEE320 802400C0 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* CEE324 802400C4 F7B80038 */  sdc1      $f24, 0x38($sp)
/* CEE328 802400C8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* CEE32C 802400CC F7B40028 */  sdc1      $f20, 0x28($sp)
/* CEE330 802400D0 8E30000C */  lw        $s0, 0xc($s1)
/* CEE334 802400D4 8E130000 */  lw        $s3, ($s0)
/* CEE338 802400D8 26100004 */  addiu     $s0, $s0, 4
/* CEE33C 802400DC 0C0B1EAF */  jal       get_variable
/* CEE340 802400E0 0260282D */   daddu    $a1, $s3, $zero
/* CEE344 802400E4 4482E000 */  mtc1      $v0, $f28
/* CEE348 802400E8 00000000 */  nop       
/* CEE34C 802400EC 4680E720 */  cvt.s.w   $f28, $f28
/* CEE350 802400F0 8E140000 */  lw        $s4, ($s0)
/* CEE354 802400F4 26100004 */  addiu     $s0, $s0, 4
/* CEE358 802400F8 0220202D */  daddu     $a0, $s1, $zero
/* CEE35C 802400FC 0C0B1EAF */  jal       get_variable
/* CEE360 80240100 0280282D */   daddu    $a1, $s4, $zero
/* CEE364 80240104 4482D000 */  mtc1      $v0, $f26
/* CEE368 80240108 00000000 */  nop       
/* CEE36C 8024010C 4680D6A0 */  cvt.s.w   $f26, $f26
/* CEE370 80240110 8E100000 */  lw        $s0, ($s0)
/* CEE374 80240114 0220202D */  daddu     $a0, $s1, $zero
/* CEE378 80240118 0C0B1EAF */  jal       get_variable
/* CEE37C 8024011C 0200282D */   daddu    $a1, $s0, $zero
/* CEE380 80240120 4482C000 */  mtc1      $v0, $f24
/* CEE384 80240124 00000000 */  nop       
/* CEE388 80240128 4680C620 */  cvt.s.w   $f24, $f24
/* CEE38C 8024012C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* CEE390 80240130 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* CEE394 80240134 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CEE398 80240138 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CEE39C 8024013C C64200A8 */  lwc1      $f2, 0xa8($s2)
/* CEE3A0 80240140 44800000 */  mtc1      $zero, $f0
/* CEE3A4 80240144 00031080 */  sll       $v0, $v1, 2
/* CEE3A8 80240148 00431021 */  addu      $v0, $v0, $v1
/* CEE3AC 8024014C 00021080 */  sll       $v0, $v0, 2
/* CEE3B0 80240150 00431023 */  subu      $v0, $v0, $v1
/* CEE3B4 80240154 000218C0 */  sll       $v1, $v0, 3
/* CEE3B8 80240158 00431021 */  addu      $v0, $v0, $v1
/* CEE3BC 8024015C 000210C0 */  sll       $v0, $v0, 3
/* CEE3C0 80240160 46001032 */  c.eq.s    $f2, $f0
/* CEE3C4 80240164 3C01800B */  lui       $at, 0x800b
/* CEE3C8 80240168 00220821 */  addu      $at, $at, $v0
/* CEE3CC 8024016C C4361DEC */  lwc1      $f22, 0x1dec($at)
/* CEE3D0 80240170 45000005 */  bc1f      .L80240188
/* CEE3D4 80240174 00000000 */   nop      
/* CEE3D8 80240178 3C0142C8 */  lui       $at, 0x42c8
/* CEE3DC 8024017C 44810000 */  mtc1      $at, $f0
/* CEE3E0 80240180 08090066 */  j         .L80240198
/* CEE3E4 80240184 4600B581 */   sub.s    $f22, $f22, $f0
.L80240188:
/* CEE3E8 80240188 3C0142C8 */  lui       $at, 0x42c8
/* CEE3EC 8024018C 44810000 */  mtc1      $at, $f0
/* CEE3F0 80240190 00000000 */  nop       
/* CEE3F4 80240194 4600B580 */  add.s     $f22, $f22, $f0
.L80240198:
/* CEE3F8 80240198 0C00A6C9 */  jal       clamp_angle
/* CEE3FC 8024019C 4600B306 */   mov.s    $f12, $f22
/* CEE400 802401A0 46000586 */  mov.s     $f22, $f0
/* CEE404 802401A4 3C014170 */  lui       $at, 0x4170
/* CEE408 802401A8 4481A000 */  mtc1      $at, $f20
/* CEE40C 802401AC 0C00A8BB */  jal       sin_deg
/* CEE410 802401B0 4600B306 */   mov.s    $f12, $f22
/* CEE414 802401B4 46140002 */  mul.s     $f0, $f0, $f20
/* CEE418 802401B8 00000000 */  nop       
/* CEE41C 802401BC 864200B0 */  lh        $v0, 0xb0($s2)
/* CEE420 802401C0 3C013F00 */  lui       $at, 0x3f00
/* CEE424 802401C4 44812000 */  mtc1      $at, $f4
/* CEE428 802401C8 44821000 */  mtc1      $v0, $f2
/* CEE42C 802401CC 00000000 */  nop       
/* CEE430 802401D0 468010A0 */  cvt.s.w   $f2, $f2
/* CEE434 802401D4 46041082 */  mul.s     $f2, $f2, $f4
/* CEE438 802401D8 00000000 */  nop       
/* CEE43C 802401DC 4600E700 */  add.s     $f28, $f28, $f0
/* CEE440 802401E0 4602D680 */  add.s     $f26, $f26, $f2
/* CEE444 802401E4 0C00A8D4 */  jal       cos_deg
/* CEE448 802401E8 4600B306 */   mov.s    $f12, $f22
/* CEE44C 802401EC 46140002 */  mul.s     $f0, $f0, $f20
/* CEE450 802401F0 00000000 */  nop       
/* CEE454 802401F4 0220202D */  daddu     $a0, $s1, $zero
/* CEE458 802401F8 0260282D */  daddu     $a1, $s3, $zero
/* CEE45C 802401FC 4600E18D */  trunc.w.s $f6, $f28
/* CEE460 80240200 44063000 */  mfc1      $a2, $f6
/* CEE464 80240204 0C0B2026 */  jal       set_variable
/* CEE468 80240208 4600C601 */   sub.s    $f24, $f24, $f0
/* CEE46C 8024020C 0220202D */  daddu     $a0, $s1, $zero
/* CEE470 80240210 4600D18D */  trunc.w.s $f6, $f26
/* CEE474 80240214 44063000 */  mfc1      $a2, $f6
/* CEE478 80240218 0C0B2026 */  jal       set_variable
/* CEE47C 8024021C 0280282D */   daddu    $a1, $s4, $zero
/* CEE480 80240220 0220202D */  daddu     $a0, $s1, $zero
/* CEE484 80240224 4600C18D */  trunc.w.s $f6, $f24
/* CEE488 80240228 44063000 */  mfc1      $a2, $f6
/* CEE48C 8024022C 0C0B2026 */  jal       set_variable
/* CEE490 80240230 0200282D */   daddu    $a1, $s0, $zero
/* CEE494 80240234 8FBF0024 */  lw        $ra, 0x24($sp)
/* CEE498 80240238 8FB40020 */  lw        $s4, 0x20($sp)
/* CEE49C 8024023C 8FB3001C */  lw        $s3, 0x1c($sp)
/* CEE4A0 80240240 8FB20018 */  lw        $s2, 0x18($sp)
/* CEE4A4 80240244 8FB10014 */  lw        $s1, 0x14($sp)
/* CEE4A8 80240248 8FB00010 */  lw        $s0, 0x10($sp)
/* CEE4AC 8024024C D7BC0048 */  ldc1      $f28, 0x48($sp)
/* CEE4B0 80240250 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* CEE4B4 80240254 D7B80038 */  ldc1      $f24, 0x38($sp)
/* CEE4B8 80240258 D7B60030 */  ldc1      $f22, 0x30($sp)
/* CEE4BC 8024025C D7B40028 */  ldc1      $f20, 0x28($sp)
/* CEE4C0 80240260 24020002 */  addiu     $v0, $zero, 2
/* CEE4C4 80240264 03E00008 */  jr        $ra
/* CEE4C8 80240268 27BD0050 */   addiu    $sp, $sp, 0x50
