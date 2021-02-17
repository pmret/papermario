.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242214_96B3D4
/* 96B3D4 80242214 27BDFEE8 */  addiu     $sp, $sp, -0x118
/* 96B3D8 80242218 AFB100E4 */  sw        $s1, 0xe4($sp)
/* 96B3DC 8024221C 0080882D */  daddu     $s1, $a0, $zero
/* 96B3E0 80242220 AFB300EC */  sw        $s3, 0xec($sp)
/* 96B3E4 80242224 00A0982D */  daddu     $s3, $a1, $zero
/* 96B3E8 80242228 AFB500F4 */  sw        $s5, 0xf4($sp)
/* 96B3EC 8024222C 00C0A82D */  daddu     $s5, $a2, $zero
/* 96B3F0 80242230 AFB600F8 */  sw        $s6, 0xf8($sp)
/* 96B3F4 80242234 00E0B02D */  daddu     $s6, $a3, $zero
/* 96B3F8 80242238 3C05F4AC */  lui       $a1, 0xf4ac
/* 96B3FC 8024223C AFB000E0 */  sw        $s0, 0xe0($sp)
/* 96B400 80242240 3C108025 */  lui       $s0, %hi(D_8024EFCC)
/* 96B404 80242244 2610EFCC */  addiu     $s0, $s0, %lo(D_8024EFCC)
/* 96B408 80242248 AFBF00FC */  sw        $ra, 0xfc($sp)
/* 96B40C 8024224C AFB400F0 */  sw        $s4, 0xf0($sp)
/* 96B410 80242250 AFB200E8 */  sw        $s2, 0xe8($sp)
/* 96B414 80242254 F7B80110 */  sdc1      $f24, 0x110($sp)
/* 96B418 80242258 F7B60108 */  sdc1      $f22, 0x108($sp)
/* 96B41C 8024225C F7B40100 */  sdc1      $f20, 0x100($sp)
/* 96B420 80242260 8E040000 */  lw        $a0, ($s0)
/* 96B424 80242264 8FB40128 */  lw        $s4, 0x128($sp)
/* 96B428 80242268 0C0B1EAF */  jal       get_variable
/* 96B42C 8024226C 34A5D484 */   ori      $a1, $a1, 0xd484
/* 96B430 80242270 3C05F4AC */  lui       $a1, 0xf4ac
/* 96B434 80242274 8E040000 */  lw        $a0, ($s0)
/* 96B438 80242278 4482C000 */  mtc1      $v0, $f24
/* 96B43C 8024227C 00000000 */  nop
/* 96B440 80242280 4680C620 */  cvt.s.w   $f24, $f24
/* 96B444 80242284 0C0B1EAF */  jal       get_variable
/* 96B448 80242288 34A5D485 */   ori      $a1, $a1, 0xd485
/* 96B44C 8024228C 3C05F4AC */  lui       $a1, 0xf4ac
/* 96B450 80242290 4482A000 */  mtc1      $v0, $f20
/* 96B454 80242294 00000000 */  nop
/* 96B458 80242298 4680A520 */  cvt.s.w   $f20, $f20
/* 96B45C 8024229C 8E040000 */  lw        $a0, ($s0)
/* 96B460 802422A0 4480B000 */  mtc1      $zero, $f22
/* 96B464 802422A4 0C0B1EAF */  jal       get_variable
/* 96B468 802422A8 34A5D486 */   ori      $a1, $a1, 0xd486
/* 96B46C 802422AC 27B200A0 */  addiu     $s2, $sp, 0xa0
/* 96B470 802422B0 4405B000 */  mfc1      $a1, $f22
/* 96B474 802422B4 4407B000 */  mfc1      $a3, $f22
/* 96B478 802422B8 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 96B47C 802422BC 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 96B480 802422C0 3C013F36 */  lui       $at, 0x3f36
/* 96B484 802422C4 3421DB6E */  ori       $at, $at, 0xdb6e
/* 96B488 802422C8 44810000 */  mtc1      $at, $f0
/* 96B48C 802422CC 00041880 */  sll       $v1, $a0, 2
/* 96B490 802422D0 00641821 */  addu      $v1, $v1, $a0
/* 96B494 802422D4 00031880 */  sll       $v1, $v1, 2
/* 96B498 802422D8 00641823 */  subu      $v1, $v1, $a0
/* 96B49C 802422DC 000320C0 */  sll       $a0, $v1, 3
/* 96B4A0 802422E0 00641821 */  addu      $v1, $v1, $a0
/* 96B4A4 802422E4 000318C0 */  sll       $v1, $v1, 3
/* 96B4A8 802422E8 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 96B4AC 802422EC 00230821 */  addu      $at, $at, $v1
/* 96B4B0 802422F0 C4221DEC */  lwc1      $f2, %lo(gCameras+0x6C)($at)
/* 96B4B4 802422F4 0240202D */  daddu     $a0, $s2, $zero
/* 96B4B8 802422F8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 96B4BC 802422FC 46001087 */  neg.s     $f2, $f2
/* 96B4C0 80242300 44061000 */  mfc1      $a2, $f2
/* 96B4C4 80242304 44820000 */  mtc1      $v0, $f0
/* 96B4C8 80242308 00000000 */  nop
/* 96B4CC 8024230C 46800020 */  cvt.s.w   $f0, $f0
/* 96B4D0 80242310 E7B80014 */  swc1      $f24, 0x14($sp)
/* 96B4D4 80242314 E7B40018 */  swc1      $f20, 0x18($sp)
/* 96B4D8 80242318 0C018FC4 */  jal       guPositionF
/* 96B4DC 8024231C E7A0001C */   swc1     $f0, 0x1c($sp)
/* 96B4E0 80242320 3C028025 */  lui       $v0, %hi(D_8024F010)
/* 96B4E4 80242324 2442F010 */  addiu     $v0, $v0, %lo(D_8024F010)
/* 96B4E8 80242328 001180C0 */  sll       $s0, $s1, 3
/* 96B4EC 8024232C 02118021 */  addu      $s0, $s0, $s1
/* 96B4F0 80242330 00108080 */  sll       $s0, $s0, 2
/* 96B4F4 80242334 02028021 */  addu      $s0, $s0, $v0
/* 96B4F8 80242338 27B10060 */  addiu     $s1, $sp, 0x60
/* 96B4FC 8024233C 8E050004 */  lw        $a1, 4($s0)
/* 96B500 80242340 8E060008 */  lw        $a2, 8($s0)
/* 96B504 80242344 8E07000C */  lw        $a3, 0xc($s0)
/* 96B508 80242348 0C019E40 */  jal       guTranslateF
/* 96B50C 8024234C 0220202D */   daddu    $a0, $s1, $zero
/* 96B510 80242350 0220202D */  daddu     $a0, $s1, $zero
/* 96B514 80242354 0240282D */  daddu     $a1, $s2, $zero
/* 96B518 80242358 0C019D80 */  jal       guMtxCatF
/* 96B51C 8024235C 27A60020 */   addiu    $a2, $sp, 0x20
/* 96B520 80242360 E7B60010 */  swc1      $f22, 0x10($sp)
/* 96B524 80242364 8E050010 */  lw        $a1, 0x10($s0)
/* 96B528 80242368 3C013F80 */  lui       $at, 0x3f80
/* 96B52C 8024236C 4481A000 */  mtc1      $at, $f20
/* 96B530 80242370 4406B000 */  mfc1      $a2, $f22
/* 96B534 80242374 4407A000 */  mfc1      $a3, $f20
/* 96B538 80242378 0C019EC8 */  jal       guRotateF
/* 96B53C 8024237C 0220202D */   daddu    $a0, $s1, $zero
/* 96B540 80242380 0220202D */  daddu     $a0, $s1, $zero
/* 96B544 80242384 27A50020 */  addiu     $a1, $sp, 0x20
/* 96B548 80242388 0C019D80 */  jal       guMtxCatF
/* 96B54C 8024238C 00A0302D */   daddu    $a2, $a1, $zero
/* 96B550 80242390 0220202D */  daddu     $a0, $s1, $zero
/* 96B554 80242394 4405B000 */  mfc1      $a1, $f22
/* 96B558 80242398 4407A000 */  mfc1      $a3, $f20
/* 96B55C 8024239C 0C019E40 */  jal       guTranslateF
/* 96B560 802423A0 00A0302D */   daddu    $a2, $a1, $zero
/* 96B564 802423A4 0220202D */  daddu     $a0, $s1, $zero
/* 96B568 802423A8 27A50020 */  addiu     $a1, $sp, 0x20
/* 96B56C 802423AC 0C019D80 */  jal       guMtxCatF
/* 96B570 802423B0 00A0302D */   daddu    $a2, $a1, $zero
/* 96B574 802423B4 C7A00050 */  lwc1      $f0, 0x50($sp)
/* 96B578 802423B8 E6600000 */  swc1      $f0, ($s3)
/* 96B57C 802423BC C7A00054 */  lwc1      $f0, 0x54($sp)
/* 96B580 802423C0 E6A00000 */  swc1      $f0, ($s5)
/* 96B584 802423C4 C7A00058 */  lwc1      $f0, 0x58($sp)
/* 96B588 802423C8 E6C00000 */  swc1      $f0, ($s6)
/* 96B58C 802423CC 0C00A6C9 */  jal       clamp_angle
/* 96B590 802423D0 C60C0010 */   lwc1     $f12, 0x10($s0)
/* 96B594 802423D4 E6800000 */  swc1      $f0, ($s4)
/* 96B598 802423D8 8FBF00FC */  lw        $ra, 0xfc($sp)
/* 96B59C 802423DC 8FB600F8 */  lw        $s6, 0xf8($sp)
/* 96B5A0 802423E0 8FB500F4 */  lw        $s5, 0xf4($sp)
/* 96B5A4 802423E4 8FB400F0 */  lw        $s4, 0xf0($sp)
/* 96B5A8 802423E8 8FB300EC */  lw        $s3, 0xec($sp)
/* 96B5AC 802423EC 8FB200E8 */  lw        $s2, 0xe8($sp)
/* 96B5B0 802423F0 8FB100E4 */  lw        $s1, 0xe4($sp)
/* 96B5B4 802423F4 8FB000E0 */  lw        $s0, 0xe0($sp)
/* 96B5B8 802423F8 D7B80110 */  ldc1      $f24, 0x110($sp)
/* 96B5BC 802423FC D7B60108 */  ldc1      $f22, 0x108($sp)
/* 96B5C0 80242400 D7B40100 */  ldc1      $f20, 0x100($sp)
/* 96B5C4 80242404 03E00008 */  jr        $ra
/* 96B5C8 80242408 27BD0118 */   addiu    $sp, $sp, 0x118
