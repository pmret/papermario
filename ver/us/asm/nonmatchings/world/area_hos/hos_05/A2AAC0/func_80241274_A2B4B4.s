.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241274_A2B4B4
/* A2B4B4 80241274 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* A2B4B8 80241278 3C04800B */  lui       $a0, %hi(gCameras)
/* A2B4BC 8024127C 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A2B4C0 80241280 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A2B4C4 80241284 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A2B4C8 80241288 3C05800A */  lui       $a1, %hi(nuGfxCfb_ptr)
/* A2B4CC 8024128C 8CA5A64C */  lw        $a1, %lo(nuGfxCfb_ptr)($a1)
/* A2B4D0 80241290 3C088025 */  lui       $t0, %hi(D_802498D4_A33B14)
/* A2B4D4 80241294 250898D4 */  addiu     $t0, $t0, %lo(D_802498D4_A33B14)
/* A2B4D8 80241298 AFBF0030 */  sw        $ra, 0x30($sp)
/* A2B4DC 8024129C AFB5002C */  sw        $s5, 0x2c($sp)
/* A2B4E0 802412A0 AFB40028 */  sw        $s4, 0x28($sp)
/* A2B4E4 802412A4 AFB30024 */  sw        $s3, 0x24($sp)
/* A2B4E8 802412A8 AFB20020 */  sw        $s2, 0x20($sp)
/* A2B4EC 802412AC AFB1001C */  sw        $s1, 0x1c($sp)
/* A2B4F0 802412B0 AFB00018 */  sw        $s0, 0x18($sp)
/* A2B4F4 802412B4 F7B40038 */  sdc1      $f20, 0x38($sp)
/* A2B4F8 802412B8 00031080 */  sll       $v0, $v1, 2
/* A2B4FC 802412BC 00431021 */  addu      $v0, $v0, $v1
/* A2B500 802412C0 00021080 */  sll       $v0, $v0, 2
/* A2B504 802412C4 00431023 */  subu      $v0, $v0, $v1
/* A2B508 802412C8 000218C0 */  sll       $v1, $v0, 3
/* A2B50C 802412CC 00431021 */  addu      $v0, $v0, $v1
/* A2B510 802412D0 000210C0 */  sll       $v0, $v0, 3
/* A2B514 802412D4 8D030000 */  lw        $v1, ($t0)
/* A2B518 802412D8 10A30059 */  beq       $a1, $v1, .L80241440
/* A2B51C 802412DC 0044A821 */   addu     $s5, $v0, $a0
/* A2B520 802412E0 3C138025 */  lui       $s3, %hi(D_802498D0_A33B10)
/* A2B524 802412E4 267398D0 */  addiu     $s3, $s3, %lo(D_802498D0_A33B10)
/* A2B528 802412E8 3C01437A */  lui       $at, 0x437a
/* A2B52C 802412EC 44816000 */  mtc1      $at, $f12
/* A2B530 802412F0 8E660000 */  lw        $a2, ($s3)
/* A2B534 802412F4 3C073F00 */  lui       $a3, 0x3f00
/* A2B538 802412F8 4480A000 */  mtc1      $zero, $f20
/* A2B53C 802412FC AD050000 */  sw        $a1, ($t0)
/* A2B540 80241300 AFB30010 */  sw        $s3, 0x10($sp)
/* A2B544 80241304 0C090411 */  jal       func_80241044_A2B284
/* A2B548 80241308 4600A386 */   mov.s    $f14, $f20
/* A2B54C 8024130C 24040002 */  addiu     $a0, $zero, 2
/* A2B550 80241310 3C108025 */  lui       $s0, %hi(D_8024963C_A3387C)
/* A2B554 80241314 2610963C */  addiu     $s0, $s0, %lo(D_8024963C_A3387C)
/* A2B558 80241318 3C054302 */  lui       $a1, 0x4302
/* A2B55C 8024131C 34A56666 */  ori       $a1, $a1, 0x6666
/* A2B560 80241320 8E060004 */  lw        $a2, 4($s0)
/* A2B564 80241324 4407A000 */  mfc1      $a3, $f20
/* A2B568 80241328 3C0143EB */  lui       $at, 0x43eb
/* A2B56C 8024132C 44810000 */  mtc1      $at, $f0
/* A2B570 80241330 3C148025 */  lui       $s4, %hi(D_802498D8_A33B18)
/* A2B574 80241334 269498D8 */  addiu     $s4, $s4, %lo(D_802498D8_A33B18)
/* A2B578 80241338 AFB40014 */  sw        $s4, 0x14($sp)
/* A2B57C 8024133C 0C090439 */  jal       func_802410E4_A2B324
/* A2B580 80241340 E7A00010 */   swc1     $f0, 0x10($sp)
/* A2B584 80241344 3C128025 */  lui       $s2, %hi(D_802498DC_A33B1C)
/* A2B588 80241348 265298DC */  addiu     $s2, $s2, %lo(D_802498DC_A33B1C)
/* A2B58C 8024134C 3C014146 */  lui       $at, 0x4146
/* A2B590 80241350 34216666 */  ori       $at, $at, 0x6666
/* A2B594 80241354 44816000 */  mtc1      $at, $f12
/* A2B598 80241358 C60E0008 */  lwc1      $f14, 8($s0)
/* A2B59C 8024135C 3C013D4C */  lui       $at, 0x3d4c
/* A2B5A0 80241360 3421CCCD */  ori       $at, $at, 0xcccd
/* A2B5A4 80241364 4481A000 */  mtc1      $at, $f20
/* A2B5A8 80241368 8E460000 */  lw        $a2, ($s2)
/* A2B5AC 8024136C 4407A000 */  mfc1      $a3, $f20
/* A2B5B0 80241370 0C090411 */  jal       func_80241044_A2B284
/* A2B5B4 80241374 AFB20010 */   sw       $s2, 0x10($sp)
/* A2B5B8 80241378 3C118025 */  lui       $s1, %hi(D_802498E0_A33B20)
/* A2B5BC 8024137C 263198E0 */  addiu     $s1, $s1, %lo(D_802498E0_A33B20)
/* A2B5C0 80241380 3C01C186 */  lui       $at, 0xc186
/* A2B5C4 80241384 34216666 */  ori       $at, $at, 0x6666
/* A2B5C8 80241388 44816000 */  mtc1      $at, $f12
/* A2B5CC 8024138C C60E0024 */  lwc1      $f14, 0x24($s0)
/* A2B5D0 80241390 8E260000 */  lw        $a2, ($s1)
/* A2B5D4 80241394 4407A000 */  mfc1      $a3, $f20
/* A2B5D8 80241398 0C090411 */  jal       func_80241044_A2B284
/* A2B5DC 8024139C AFB10010 */   sw       $s1, 0x10($sp)
/* A2B5E0 802413A0 3C108025 */  lui       $s0, %hi(D_802498E4_A33B24)
/* A2B5E4 802413A4 261098E4 */  addiu     $s0, $s0, %lo(D_802498E4_A33B24)
/* A2B5E8 802413A8 3C014278 */  lui       $at, 0x4278
/* A2B5EC 802413AC 44816000 */  mtc1      $at, $f12
/* A2B5F0 802413B0 3C014244 */  lui       $at, 0x4244
/* A2B5F4 802413B4 44817000 */  mtc1      $at, $f14
/* A2B5F8 802413B8 8E060000 */  lw        $a2, ($s0)
/* A2B5FC 802413BC 3C073DCC */  lui       $a3, 0x3dcc
/* A2B600 802413C0 34E7CCCD */  ori       $a3, $a3, 0xcccd
/* A2B604 802413C4 0C090411 */  jal       func_80241044_A2B284
/* A2B608 802413C8 AFB00010 */   sw       $s0, 0x10($sp)
/* A2B60C 802413CC 8E050000 */  lw        $a1, ($s0)
/* A2B610 802413D0 0C090355 */  jal       func_80240D54_A2AF94
/* A2B614 802413D4 0000202D */   daddu    $a0, $zero, $zero
/* A2B618 802413D8 C6800000 */  lwc1      $f0, ($s4)
/* A2B61C 802413DC C66C0000 */  lwc1      $f12, ($s3)
/* A2B620 802413E0 C6420000 */  lwc1      $f2, ($s2)
/* A2B624 802413E4 C6240000 */  lwc1      $f4, ($s1)
/* A2B628 802413E8 E6A004DC */  swc1      $f0, 0x4dc($s5)
/* A2B62C 802413EC E6A204E0 */  swc1      $f2, 0x4e0($s5)
/* A2B630 802413F0 0C00A8BB */  jal       sin_deg
/* A2B634 802413F4 E6A404FC */   swc1     $f4, 0x4fc($s5)
/* A2B638 802413F8 3C0143FA */  lui       $at, 0x43fa
/* A2B63C 802413FC 44811000 */  mtc1      $at, $f2
/* A2B640 80241400 00000000 */  nop
/* A2B644 80241404 46020002 */  mul.s     $f0, $f0, $f2
/* A2B648 80241408 00000000 */  nop
/* A2B64C 8024140C C66C0000 */  lwc1      $f12, ($s3)
/* A2B650 80241410 0C00A8D4 */  jal       cos_deg
/* A2B654 80241414 E6A004F0 */   swc1     $f0, 0x4f0($s5)
/* A2B658 80241418 3C01C3FA */  lui       $at, 0xc3fa
/* A2B65C 8024141C 44811000 */  mtc1      $at, $f2
/* A2B660 80241420 00000000 */  nop
/* A2B664 80241424 46020002 */  mul.s     $f0, $f0, $f2
/* A2B668 80241428 00000000 */  nop
/* A2B66C 8024142C 24020002 */  addiu     $v0, $zero, 2
/* A2B670 80241430 24030001 */  addiu     $v1, $zero, 1
/* A2B674 80241434 A6A30506 */  sh        $v1, 0x506($s5)
/* A2B678 80241438 08090511 */  j         .L80241444
/* A2B67C 8024143C E6A004F8 */   swc1     $f0, 0x4f8($s5)
.L80241440:
/* A2B680 80241440 0000102D */  daddu     $v0, $zero, $zero
.L80241444:
/* A2B684 80241444 8FBF0030 */  lw        $ra, 0x30($sp)
/* A2B688 80241448 8FB5002C */  lw        $s5, 0x2c($sp)
/* A2B68C 8024144C 8FB40028 */  lw        $s4, 0x28($sp)
/* A2B690 80241450 8FB30024 */  lw        $s3, 0x24($sp)
/* A2B694 80241454 8FB20020 */  lw        $s2, 0x20($sp)
/* A2B698 80241458 8FB1001C */  lw        $s1, 0x1c($sp)
/* A2B69C 8024145C 8FB00018 */  lw        $s0, 0x18($sp)
/* A2B6A0 80241460 D7B40038 */  ldc1      $f20, 0x38($sp)
/* A2B6A4 80241464 03E00008 */  jr        $ra
/* A2B6A8 80241468 27BD0040 */   addiu    $sp, $sp, 0x40
