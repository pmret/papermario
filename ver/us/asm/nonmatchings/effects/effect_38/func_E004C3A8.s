.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E004C3A8
/* 35A2C8 E004C3A8 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 35A2CC E004C3AC 0080182D */  daddu     $v1, $a0, $zero
/* 35A2D0 E004C3B0 3C0838E3 */  lui       $t0, 0x38e3
/* 35A2D4 E004C3B4 35088E39 */  ori       $t0, $t0, 0x8e39
/* 35A2D8 E004C3B8 3C05DB06 */  lui       $a1, 0xdb06
/* 35A2DC E004C3BC 34A50024 */  ori       $a1, $a1, 0x24
/* 35A2E0 E004C3C0 27A40018 */  addiu     $a0, $sp, 0x18
/* 35A2E4 E004C3C4 AFB500AC */  sw        $s5, 0xac($sp)
/* 35A2E8 E004C3C8 3C150001 */  lui       $s5, 1
/* 35A2EC E004C3CC AFB200A0 */  sw        $s2, 0xa0($sp)
/* 35A2F0 E004C3D0 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 35A2F4 E004C3D4 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 35A2F8 E004C3D8 AFB600B0 */  sw        $s6, 0xb0($sp)
/* 35A2FC E004C3DC 3C16E700 */  lui       $s6, 0xe700
/* 35A300 E004C3E0 AFBF00B4 */  sw        $ra, 0xb4($sp)
/* 35A304 E004C3E4 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 35A308 E004C3E8 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 35A30C E004C3EC AFB1009C */  sw        $s1, 0x9c($sp)
/* 35A310 E004C3F0 AFB00098 */  sw        $s0, 0x98($sp)
/* 35A314 E004C3F4 F7B400B8 */  sdc1      $f20, 0xb8($sp)
/* 35A318 E004C3F8 8E460000 */  lw        $a2, ($s2)
/* 35A31C E004C3FC 8C71000C */  lw        $s1, 0xc($v1)
/* 35A320 E004C400 00C0102D */  daddu     $v0, $a2, $zero
/* 35A324 E004C404 24C60008 */  addiu     $a2, $a2, 8
/* 35A328 E004C408 AE460000 */  sw        $a2, ($s2)
/* 35A32C E004C40C 8E27001C */  lw        $a3, 0x1c($s1)
/* 35A330 E004C410 8E330020 */  lw        $s3, 0x20($s1)
/* 35A334 E004C414 3C14DE00 */  lui       $s4, 0xde00
/* 35A338 E004C418 AC560000 */  sw        $s6, ($v0)
/* 35A33C E004C41C AC400004 */  sw        $zero, 4($v0)
/* 35A340 E004C420 24C20008 */  addiu     $v0, $a2, 8
/* 35A344 E004C424 AE420000 */  sw        $v0, ($s2)
/* 35A348 E004C428 24C20010 */  addiu     $v0, $a2, 0x10
/* 35A34C E004C42C ACC50000 */  sw        $a1, ($a2)
/* 35A350 E004C430 AE420000 */  sw        $v0, ($s2)
/* 35A354 E004C434 8C630010 */  lw        $v1, 0x10($v1)
/* 35A358 E004C438 24C20018 */  addiu     $v0, $a2, 0x18
/* 35A35C E004C43C AE420000 */  sw        $v0, ($s2)
/* 35A360 E004C440 3C020900 */  lui       $v0, 0x900
/* 35A364 E004C444 24420FC0 */  addiu     $v0, $v0, 0xfc0
/* 35A368 E004C448 00072840 */  sll       $a1, $a3, 1
/* 35A36C E004C44C 8C63001C */  lw        $v1, 0x1c($v1)
/* 35A370 E004C450 00A72821 */  addu      $a1, $a1, $a3
/* 35A374 E004C454 ACC2000C */  sw        $v0, 0xc($a2)
/* 35A378 E004C458 3C02FA00 */  lui       $v0, 0xfa00
/* 35A37C E004C45C ACC20010 */  sw        $v0, 0x10($a2)
/* 35A380 E004C460 3C028000 */  lui       $v0, 0x8000
/* 35A384 E004C464 00A80018 */  mult      $a1, $t0
/* 35A388 E004C468 ACD40008 */  sw        $s4, 8($a2)
/* 35A38C E004C46C 00621821 */  addu      $v1, $v1, $v0
/* 35A390 E004C470 000517C3 */  sra       $v0, $a1, 0x1f
/* 35A394 E004C474 ACC30004 */  sw        $v1, 4($a2)
/* 35A398 E004C478 00004810 */  mfhi      $t1
/* 35A39C E004C47C 000918C3 */  sra       $v1, $t1, 3
/* 35A3A0 E004C480 00621823 */  subu      $v1, $v1, $v0
/* 35A3A4 E004C484 000310C0 */  sll       $v0, $v1, 3
/* 35A3A8 E004C488 00431021 */  addu      $v0, $v0, $v1
/* 35A3AC E004C48C 00021080 */  sll       $v0, $v0, 2
/* 35A3B0 E004C490 00A22823 */  subu      $a1, $a1, $v0
/* 35A3B4 E004C494 3C02E005 */  lui       $v0, %hi(D_E004C67C)
/* 35A3B8 E004C498 00451021 */  addu      $v0, $v0, $a1
/* 35A3BC E004C49C 9042C67C */  lbu       $v0, %lo(D_E004C67C)($v0)
/* 35A3C0 E004C4A0 3C03E005 */  lui       $v1, %hi(D_E004C67D)
/* 35A3C4 E004C4A4 00651821 */  addu      $v1, $v1, $a1
/* 35A3C8 E004C4A8 9063C67D */  lbu       $v1, %lo(D_E004C67D)($v1)
/* 35A3CC E004C4AC 3C01E005 */  lui       $at, %hi(D_E004C67E)
/* 35A3D0 E004C4B0 00250821 */  addu      $at, $at, $a1
/* 35A3D4 E004C4B4 9025C67E */  lbu       $a1, %lo(D_E004C67E)($at)
/* 35A3D8 E004C4B8 00021600 */  sll       $v0, $v0, 0x18
/* 35A3DC E004C4BC 00031C00 */  sll       $v1, $v1, 0x10
/* 35A3E0 E004C4C0 00431025 */  or        $v0, $v0, $v1
/* 35A3E4 E004C4C4 00052A00 */  sll       $a1, $a1, 8
/* 35A3E8 E004C4C8 92230017 */  lbu       $v1, 0x17($s1)
/* 35A3EC E004C4CC 00451025 */  or        $v0, $v0, $a1
/* 35A3F0 E004C4D0 00431025 */  or        $v0, $v0, $v1
/* 35A3F4 E004C4D4 ACC20014 */  sw        $v0, 0x14($a2)
/* 35A3F8 E004C4D8 8E250004 */  lw        $a1, 4($s1)
/* 35A3FC E004C4DC 8E260008 */  lw        $a2, 8($s1)
/* 35A400 E004C4E0 8E27000C */  lw        $a3, 0xc($s1)
/* 35A404 E004C4E4 4480A000 */  mtc1      $zero, $f20
/* 35A408 E004C4E8 0C080108 */  jal       shim_guTranslateF
/* 35A40C E004C4EC 36B51630 */   ori      $s5, $s5, 0x1630
/* 35A410 E004C4F0 27B00058 */  addiu     $s0, $sp, 0x58
/* 35A414 E004C4F4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 35A418 E004C4F8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 35A41C E004C4FC 4406A000 */  mfc1      $a2, $f20
/* 35A420 E004C500 00031080 */  sll       $v0, $v1, 2
/* 35A424 E004C504 00431021 */  addu      $v0, $v0, $v1
/* 35A428 E004C508 00021080 */  sll       $v0, $v0, 2
/* 35A42C E004C50C 00431023 */  subu      $v0, $v0, $v1
/* 35A430 E004C510 000218C0 */  sll       $v1, $v0, 3
/* 35A434 E004C514 00431021 */  addu      $v0, $v0, $v1
/* 35A438 E004C518 000210C0 */  sll       $v0, $v0, 3
/* 35A43C E004C51C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 35A440 E004C520 00220821 */  addu      $at, $at, $v0
/* 35A444 E004C524 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 35A448 E004C528 3C073F80 */  lui       $a3, 0x3f80
/* 35A44C E004C52C 46000007 */  neg.s     $f0, $f0
/* 35A450 E004C530 44050000 */  mfc1      $a1, $f0
/* 35A454 E004C534 0200202D */  daddu     $a0, $s0, $zero
/* 35A458 E004C538 0C080104 */  jal       shim_guRotateF
/* 35A45C E004C53C E7B40010 */   swc1     $f20, 0x10($sp)
/* 35A460 E004C540 0200202D */  daddu     $a0, $s0, $zero
/* 35A464 E004C544 27A50018 */  addiu     $a1, $sp, 0x18
/* 35A468 E004C548 0C080114 */  jal       shim_guMtxCatF
/* 35A46C E004C54C 00A0302D */   daddu    $a2, $a1, $zero
/* 35A470 E004C550 0200202D */  daddu     $a0, $s0, $zero
/* 35A474 E004C554 8E250010 */  lw        $a1, 0x10($s1)
/* 35A478 E004C558 4407A000 */  mfc1      $a3, $f20
/* 35A47C E004C55C 0C080110 */  jal       shim_guScaleF
/* 35A480 E004C560 00A0302D */   daddu    $a2, $a1, $zero
/* 35A484 E004C564 0200202D */  daddu     $a0, $s0, $zero
/* 35A488 E004C568 27A50018 */  addiu     $a1, $sp, 0x18
/* 35A48C E004C56C 0C080114 */  jal       shim_guMtxCatF
/* 35A490 E004C570 00A0302D */   daddu    $a2, $a1, $zero
/* 35A494 E004C574 27A40018 */  addiu     $a0, $sp, 0x18
/* 35A498 E004C578 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 35A49C E004C57C 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 35A4A0 E004C580 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 35A4A4 E004C584 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 35A4A8 E004C588 96050000 */  lhu       $a1, ($s0)
/* 35A4AC E004C58C 8E220000 */  lw        $v0, ($s1)
/* 35A4B0 E004C590 00052980 */  sll       $a1, $a1, 6
/* 35A4B4 E004C594 00B52821 */  addu      $a1, $a1, $s5
/* 35A4B8 E004C598 0C080118 */  jal       shim_guMtxF2L
/* 35A4BC E004C59C 00452821 */   addu     $a1, $v0, $a1
/* 35A4C0 E004C5A0 3C06D838 */  lui       $a2, 0xd838
/* 35A4C4 E004C5A4 34C60002 */  ori       $a2, $a2, 2
/* 35A4C8 E004C5A8 8E440000 */  lw        $a0, ($s2)
/* 35A4CC E004C5AC 3C03DA38 */  lui       $v1, 0xda38
/* 35A4D0 E004C5B0 0080282D */  daddu     $a1, $a0, $zero
/* 35A4D4 E004C5B4 24840008 */  addiu     $a0, $a0, 8
/* 35A4D8 E004C5B8 AE440000 */  sw        $a0, ($s2)
/* 35A4DC E004C5BC 96020000 */  lhu       $v0, ($s0)
/* 35A4E0 E004C5C0 00139880 */  sll       $s3, $s3, 2
/* 35A4E4 E004C5C4 ACA30000 */  sw        $v1, ($a1)
/* 35A4E8 E004C5C8 24430001 */  addiu     $v1, $v0, 1
/* 35A4EC E004C5CC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 35A4F0 E004C5D0 00021180 */  sll       $v0, $v0, 6
/* 35A4F4 E004C5D4 A6030000 */  sh        $v1, ($s0)
/* 35A4F8 E004C5D8 8E230000 */  lw        $v1, ($s1)
/* 35A4FC E004C5DC 00551021 */  addu      $v0, $v0, $s5
/* 35A500 E004C5E0 00621821 */  addu      $v1, $v1, $v0
/* 35A504 E004C5E4 24820008 */  addiu     $v0, $a0, 8
/* 35A508 E004C5E8 ACA30004 */  sw        $v1, 4($a1)
/* 35A50C E004C5EC AE420000 */  sw        $v0, ($s2)
/* 35A510 E004C5F0 AC940000 */  sw        $s4, ($a0)
/* 35A514 E004C5F4 3C03E005 */  lui       $v1, %hi(D_E004C660)
/* 35A518 E004C5F8 00731821 */  addu      $v1, $v1, $s3
/* 35A51C E004C5FC 8C63C660 */  lw        $v1, %lo(D_E004C660)($v1)
/* 35A520 E004C600 24820010 */  addiu     $v0, $a0, 0x10
/* 35A524 E004C604 AE420000 */  sw        $v0, ($s2)
/* 35A528 E004C608 24020040 */  addiu     $v0, $zero, 0x40
/* 35A52C E004C60C AC82000C */  sw        $v0, 0xc($a0)
/* 35A530 E004C610 24820018 */  addiu     $v0, $a0, 0x18
/* 35A534 E004C614 AC860008 */  sw        $a2, 8($a0)
/* 35A538 E004C618 AE420000 */  sw        $v0, ($s2)
/* 35A53C E004C61C AC960010 */  sw        $s6, 0x10($a0)
/* 35A540 E004C620 AC800014 */  sw        $zero, 0x14($a0)
/* 35A544 E004C624 AC830004 */  sw        $v1, 4($a0)
/* 35A548 E004C628 8FBF00B4 */  lw        $ra, 0xb4($sp)
/* 35A54C E004C62C 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 35A550 E004C630 8FB500AC */  lw        $s5, 0xac($sp)
/* 35A554 E004C634 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 35A558 E004C638 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 35A55C E004C63C 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 35A560 E004C640 8FB1009C */  lw        $s1, 0x9c($sp)
/* 35A564 E004C644 8FB00098 */  lw        $s0, 0x98($sp)
/* 35A568 E004C648 D7B400B8 */  ldc1      $f20, 0xb8($sp)
/* 35A56C E004C64C 03E00008 */  jr        $ra
/* 35A570 E004C650 27BD00C0 */   addiu    $sp, $sp, 0xc0
/* 35A574 E004C654 00000000 */  nop
/* 35A578 E004C658 00000000 */  nop
/* 35A57C E004C65C 00000000 */  nop
