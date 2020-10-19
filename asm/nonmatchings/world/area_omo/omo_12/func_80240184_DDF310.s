.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240184_DDF494
/* DDF494 80240184 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DDF498 80240188 AFB00018 */  sw        $s0, 0x18($sp)
/* DDF49C 8024018C 0080802D */  daddu     $s0, $a0, $zero
/* DDF4A0 80240190 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* DDF4A4 80240194 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* DDF4A8 80240198 AFB1001C */  sw        $s1, 0x1c($sp)
/* DDF4AC 8024019C 3C118011 */  lui       $s1, %hi(gPlayerData)
/* DDF4B0 802401A0 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* DDF4B4 802401A4 AFB20020 */  sw        $s2, 0x20($sp)
/* DDF4B8 802401A8 0220902D */  daddu     $s2, $s1, $zero
/* DDF4BC 802401AC 10A00004 */  beqz      $a1, .L802401C0
/* DDF4C0 802401B0 AFBF0024 */   sw       $ra, 0x24($sp)
/* DDF4C4 802401B4 240200FF */  addiu     $v0, $zero, 0xff
/* DDF4C8 802401B8 AE020070 */  sw        $v0, 0x70($s0)
/* DDF4CC 802401BC AE000074 */  sw        $zero, 0x74($s0)
.L802401C0:
/* DDF4D0 802401C0 24040001 */  addiu     $a0, $zero, 1
/* DDF4D4 802401C4 C460002C */  lwc1      $f0, 0x2c($v1)
/* DDF4D8 802401C8 3C014100 */  lui       $at, 0x4100
/* DDF4DC 802401CC 44811000 */  mtc1      $at, $f2
/* DDF4E0 802401D0 00000000 */  nop       
/* DDF4E4 802401D4 46020000 */  add.s     $f0, $f0, $f2
/* DDF4E8 802401D8 C4620030 */  lwc1      $f2, 0x30($v1)
/* DDF4EC 802401DC C4640028 */  lwc1      $f4, 0x28($v1)
/* DDF4F0 802401E0 4600118D */  trunc.w.s $f6, $f2
/* DDF4F4 802401E4 E7A60010 */  swc1      $f6, 0x10($sp)
/* DDF4F8 802401E8 4600218D */  trunc.w.s $f6, $f4
/* DDF4FC 802401EC 44063000 */  mfc1      $a2, $f6
/* DDF500 802401F0 4600018D */  trunc.w.s $f6, $f0
/* DDF504 802401F4 44073000 */  mfc1      $a3, $f6
/* DDF508 802401F8 0C04DFB0 */  jal       func_80137EC0
/* DDF50C 802401FC 0080282D */   daddu    $a1, $a0, $zero
/* DDF510 80240200 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* DDF514 80240204 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* DDF518 80240208 10400012 */  beqz      $v0, .L80240254
/* DDF51C 8024020C 24020006 */   addiu    $v0, $zero, 6
/* DDF520 80240210 82230012 */  lb        $v1, 0x12($s1)
/* DDF524 80240214 14620022 */  bne       $v1, $v0, .L802402A0
/* DDF528 80240218 00000000 */   nop      
/* DDF52C 8024021C 8E020074 */  lw        $v0, 0x74($s0)
/* DDF530 80240220 14400004 */  bnez      $v0, .L80240234
/* DDF534 80240224 24020001 */   addiu    $v0, $zero, 1
/* DDF538 80240228 AE020074 */  sw        $v0, 0x74($s0)
/* DDF53C 8024022C 0C05272D */  jal       play_sound
/* DDF540 80240230 24042011 */   addiu    $a0, $zero, 0x2011
.L80240234:
/* DDF544 80240234 8E020070 */  lw        $v0, 0x70($s0)
/* DDF548 80240238 2442FFF8 */  addiu     $v0, $v0, -8
/* DDF54C 8024023C AE020070 */  sw        $v0, 0x70($s0)
/* DDF550 80240240 2842005A */  slti      $v0, $v0, 0x5a
/* DDF554 80240244 10400016 */  beqz      $v0, .L802402A0
/* DDF558 80240248 2402005A */   addiu    $v0, $zero, 0x5a
/* DDF55C 8024024C 080900A8 */  j         .L802402A0
/* DDF560 80240250 AE020070 */   sw       $v0, 0x70($s0)
.L80240254:
/* DDF564 80240254 82430012 */  lb        $v1, 0x12($s2)
/* DDF568 80240258 14620010 */  bne       $v1, $v0, .L8024029C
/* DDF56C 8024025C 240200FF */   addiu    $v0, $zero, 0xff
/* DDF570 80240260 8E020074 */  lw        $v0, 0x74($s0)
/* DDF574 80240264 10400007 */  beqz      $v0, .L80240284
/* DDF578 80240268 00000000 */   nop      
/* DDF57C 8024026C 8E020070 */  lw        $v0, 0x70($s0)
/* DDF580 80240270 284200FF */  slti      $v0, $v0, 0xff
/* DDF584 80240274 10400003 */  beqz      $v0, .L80240284
/* DDF588 80240278 AE000074 */   sw       $zero, 0x74($s0)
/* DDF58C 8024027C 0C05272D */  jal       play_sound
/* DDF590 80240280 24042012 */   addiu    $a0, $zero, 0x2012
.L80240284:
/* DDF594 80240284 8E020070 */  lw        $v0, 0x70($s0)
/* DDF598 80240288 24420008 */  addiu     $v0, $v0, 8
/* DDF59C 8024028C AE020070 */  sw        $v0, 0x70($s0)
/* DDF5A0 80240290 284200FF */  slti      $v0, $v0, 0xff
/* DDF5A4 80240294 14400002 */  bnez      $v0, .L802402A0
/* DDF5A8 80240298 240200FF */   addiu    $v0, $zero, 0xff
.L8024029C:
/* DDF5AC 8024029C AE020070 */  sw        $v0, 0x70($s0)
.L802402A0:
/* DDF5B0 802402A0 C6060070 */  lwc1      $f6, 0x70($s0)
/* DDF5B4 802402A4 468031A0 */  cvt.s.w   $f6, $f6
/* DDF5B8 802402A8 44053000 */  mfc1      $a1, $f6
/* DDF5BC 802402AC 0C04E035 */  jal       func_801380D4
/* DDF5C0 802402B0 24040001 */   addiu    $a0, $zero, 1
/* DDF5C4 802402B4 3C05437F */  lui       $a1, 0x437f
/* DDF5C8 802402B8 0C04DF69 */  jal       func_80137DA4
/* DDF5CC 802402BC 2404000B */   addiu    $a0, $zero, 0xb
/* DDF5D0 802402C0 8FBF0024 */  lw        $ra, 0x24($sp)
/* DDF5D4 802402C4 8FB20020 */  lw        $s2, 0x20($sp)
/* DDF5D8 802402C8 8FB1001C */  lw        $s1, 0x1c($sp)
/* DDF5DC 802402CC 8FB00018 */  lw        $s0, 0x18($sp)
/* DDF5E0 802402D0 0000102D */  daddu     $v0, $zero, $zero
/* DDF5E4 802402D4 03E00008 */  jr        $ra
/* DDF5E8 802402D8 27BD0028 */   addiu    $sp, $sp, 0x28
