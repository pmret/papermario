.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_8AA450
/* 8AA450 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8AA454 80240004 AFB00018 */  sw        $s0, 0x18($sp)
/* 8AA458 80240008 0080802D */  daddu     $s0, $a0, $zero
/* 8AA45C 8024000C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 8AA460 80240010 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 8AA464 80240014 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8AA468 80240018 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 8AA46C 8024001C 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 8AA470 80240020 AFB20020 */  sw        $s2, 0x20($sp)
/* 8AA474 80240024 0220902D */  daddu     $s2, $s1, $zero
/* 8AA478 80240028 10A00004 */  beqz      $a1, .L8024003C
/* 8AA47C 8024002C AFBF0024 */   sw       $ra, 0x24($sp)
/* 8AA480 80240030 240200FF */  addiu     $v0, $zero, 0xff
/* 8AA484 80240034 AE020070 */  sw        $v0, 0x70($s0)
/* 8AA488 80240038 AE000074 */  sw        $zero, 0x74($s0)
.L8024003C:
/* 8AA48C 8024003C 24040001 */  addiu     $a0, $zero, 1
/* 8AA490 80240040 C460002C */  lwc1      $f0, 0x2c($v1)
/* 8AA494 80240044 3C014100 */  lui       $at, 0x4100
/* 8AA498 80240048 44811000 */  mtc1      $at, $f2
/* 8AA49C 8024004C 00000000 */  nop       
/* 8AA4A0 80240050 46020000 */  add.s     $f0, $f0, $f2
/* 8AA4A4 80240054 C4620030 */  lwc1      $f2, 0x30($v1)
/* 8AA4A8 80240058 C4640028 */  lwc1      $f4, 0x28($v1)
/* 8AA4AC 8024005C 4600118D */  trunc.w.s $f6, $f2
/* 8AA4B0 80240060 E7A60010 */  swc1      $f6, 0x10($sp)
/* 8AA4B4 80240064 4600218D */  trunc.w.s $f6, $f4
/* 8AA4B8 80240068 44063000 */  mfc1      $a2, $f6
/* 8AA4BC 8024006C 4600018D */  trunc.w.s $f6, $f0
/* 8AA4C0 80240070 44073000 */  mfc1      $a3, $f6
/* 8AA4C4 80240074 0C04DFB0 */  jal       func_80137EC0
/* 8AA4C8 80240078 0080282D */   daddu    $a1, $a0, $zero
/* 8AA4CC 8024007C 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* 8AA4D0 80240080 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* 8AA4D4 80240084 10400012 */  beqz      $v0, .L802400D0
/* 8AA4D8 80240088 24020006 */   addiu    $v0, $zero, 6
/* 8AA4DC 8024008C 82230012 */  lb        $v1, 0x12($s1)
/* 8AA4E0 80240090 14620022 */  bne       $v1, $v0, .L8024011C
/* 8AA4E4 80240094 00000000 */   nop      
/* 8AA4E8 80240098 8E020074 */  lw        $v0, 0x74($s0)
/* 8AA4EC 8024009C 14400004 */  bnez      $v0, .L802400B0
/* 8AA4F0 802400A0 24020001 */   addiu    $v0, $zero, 1
/* 8AA4F4 802400A4 AE020074 */  sw        $v0, 0x74($s0)
/* 8AA4F8 802400A8 0C05272D */  jal       play_sound
/* 8AA4FC 802400AC 24042011 */   addiu    $a0, $zero, 0x2011
.L802400B0:
/* 8AA500 802400B0 8E020070 */  lw        $v0, 0x70($s0)
/* 8AA504 802400B4 2442FFF8 */  addiu     $v0, $v0, -8
/* 8AA508 802400B8 AE020070 */  sw        $v0, 0x70($s0)
/* 8AA50C 802400BC 2842005A */  slti      $v0, $v0, 0x5a
/* 8AA510 802400C0 10400016 */  beqz      $v0, .L8024011C
/* 8AA514 802400C4 2402005A */   addiu    $v0, $zero, 0x5a
/* 8AA518 802400C8 08090047 */  j         .L8024011C
/* 8AA51C 802400CC AE020070 */   sw       $v0, 0x70($s0)
.L802400D0:
/* 8AA520 802400D0 82430012 */  lb        $v1, 0x12($s2)
/* 8AA524 802400D4 14620010 */  bne       $v1, $v0, .L80240118
/* 8AA528 802400D8 240200FF */   addiu    $v0, $zero, 0xff
/* 8AA52C 802400DC 8E020074 */  lw        $v0, 0x74($s0)
/* 8AA530 802400E0 10400007 */  beqz      $v0, .L80240100
/* 8AA534 802400E4 00000000 */   nop      
/* 8AA538 802400E8 8E020070 */  lw        $v0, 0x70($s0)
/* 8AA53C 802400EC 284200FF */  slti      $v0, $v0, 0xff
/* 8AA540 802400F0 10400003 */  beqz      $v0, .L80240100
/* 8AA544 802400F4 AE000074 */   sw       $zero, 0x74($s0)
/* 8AA548 802400F8 0C05272D */  jal       play_sound
/* 8AA54C 802400FC 24042012 */   addiu    $a0, $zero, 0x2012
.L80240100:
/* 8AA550 80240100 8E020070 */  lw        $v0, 0x70($s0)
/* 8AA554 80240104 24420008 */  addiu     $v0, $v0, 8
/* 8AA558 80240108 AE020070 */  sw        $v0, 0x70($s0)
/* 8AA55C 8024010C 284200FF */  slti      $v0, $v0, 0xff
/* 8AA560 80240110 14400002 */  bnez      $v0, .L8024011C
/* 8AA564 80240114 240200FF */   addiu    $v0, $zero, 0xff
.L80240118:
/* 8AA568 80240118 AE020070 */  sw        $v0, 0x70($s0)
.L8024011C:
/* 8AA56C 8024011C C6060070 */  lwc1      $f6, 0x70($s0)
/* 8AA570 80240120 468031A0 */  cvt.s.w   $f6, $f6
/* 8AA574 80240124 44053000 */  mfc1      $a1, $f6
/* 8AA578 80240128 0C04E035 */  jal       func_801380D4
/* 8AA57C 8024012C 24040001 */   addiu    $a0, $zero, 1
/* 8AA580 80240130 3C05437F */  lui       $a1, 0x437f
/* 8AA584 80240134 0C04DF69 */  jal       func_80137DA4
/* 8AA588 80240138 2404000B */   addiu    $a0, $zero, 0xb
/* 8AA58C 8024013C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 8AA590 80240140 8FB20020 */  lw        $s2, 0x20($sp)
/* 8AA594 80240144 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8AA598 80240148 8FB00018 */  lw        $s0, 0x18($sp)
/* 8AA59C 8024014C 0000102D */  daddu     $v0, $zero, $zero
/* 8AA5A0 80240150 03E00008 */  jr        $ra
/* 8AA5A4 80240154 27BD0028 */   addiu    $sp, $sp, 0x28
/* 8AA5A8 80240158 00000000 */  nop       
/* 8AA5AC 8024015C 00000000 */  nop       
