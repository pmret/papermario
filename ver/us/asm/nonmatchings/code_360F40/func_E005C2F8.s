.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E005C2F8
/* 361238 E005C2F8 27BDFEF8 */  addiu     $sp, $sp, -0x108
/* 36123C E005C2FC AFBE0100 */  sw        $fp, 0x100($sp)
/* 361240 E005C300 0080F02D */  daddu     $fp, $a0, $zero
/* 361244 E005C304 3C08DB06 */  lui       $t0, 0xdb06
/* 361248 E005C308 35080024 */  ori       $t0, $t0, 0x24
/* 36124C E005C30C 27A40018 */  addiu     $a0, $sp, 0x18
/* 361250 E005C310 AFB500F4 */  sw        $s5, 0xf4($sp)
/* 361254 E005C314 3C150001 */  lui       $s5, 1
/* 361258 E005C318 AFB700FC */  sw        $s7, 0xfc($sp)
/* 36125C E005C31C 3C17800A */  lui       $s7, %hi(gMasterGfxPos)
/* 361260 E005C320 26F7A66C */  addiu     $s7, $s7, %lo(gMasterGfxPos)
/* 361264 E005C324 AFBF0104 */  sw        $ra, 0x104($sp)
/* 361268 E005C328 AFB600F8 */  sw        $s6, 0xf8($sp)
/* 36126C E005C32C AFB400F0 */  sw        $s4, 0xf0($sp)
/* 361270 E005C330 AFB300EC */  sw        $s3, 0xec($sp)
/* 361274 E005C334 AFB200E8 */  sw        $s2, 0xe8($sp)
/* 361278 E005C338 AFB100E4 */  sw        $s1, 0xe4($sp)
/* 36127C E005C33C AFB000E0 */  sw        $s0, 0xe0($sp)
/* 361280 E005C340 8EE50000 */  lw        $a1, ($s7)
/* 361284 E005C344 8FD6000C */  lw        $s6, 0xc($fp)
/* 361288 E005C348 00A0302D */  daddu     $a2, $a1, $zero
/* 36128C E005C34C 24A50008 */  addiu     $a1, $a1, 8
/* 361290 E005C350 AEE50000 */  sw        $a1, ($s7)
/* 361294 E005C354 96C30000 */  lhu       $v1, ($s6)
/* 361298 E005C358 24A20008 */  addiu     $v0, $a1, 8
/* 36129C E005C35C AEE20000 */  sw        $v0, ($s7)
/* 3612A0 E005C360 C6C20030 */  lwc1      $f2, 0x30($s6)
/* 3612A4 E005C364 00031880 */  sll       $v1, $v1, 2
/* 3612A8 E005C368 3C09E006 */  lui       $t1, %hi(D_E005C700)
/* 3612AC E005C36C 01234821 */  addu      $t1, $t1, $v1
/* 3612B0 E005C370 8D29C700 */  lw        $t1, %lo(D_E005C700)($t1)
/* 3612B4 E005C374 36B51630 */  ori       $s5, $s5, 0x1630
/* 3612B8 E005C378 AFA900D8 */  sw        $t1, 0xd8($sp)
/* 3612BC E005C37C 3C07E006 */  lui       $a3, %hi(D_E005C704)
/* 3612C0 E005C380 00E33821 */  addu      $a3, $a3, $v1
/* 3612C4 E005C384 8CE7C704 */  lw        $a3, %lo(D_E005C704)($a3)
/* 3612C8 E005C388 3C02E700 */  lui       $v0, 0xe700
/* 3612CC E005C38C ACC20000 */  sw        $v0, ($a2)
/* 3612D0 E005C390 ACC00004 */  sw        $zero, 4($a2)
/* 3612D4 E005C394 ACA80000 */  sw        $t0, ($a1)
/* 3612D8 E005C398 8FC30010 */  lw        $v1, 0x10($fp)
/* 3612DC E005C39C 24A20010 */  addiu     $v0, $a1, 0x10
/* 3612E0 E005C3A0 AEE20000 */  sw        $v0, ($s7)
/* 3612E4 E005C3A4 3C02DE00 */  lui       $v0, 0xde00
/* 3612E8 E005C3A8 4600110D */  trunc.w.s $f4, $f2
/* 3612EC E005C3AC 44132000 */  mfc1      $s3, $f4
/* 3612F0 E005C3B0 00000000 */  nop
/* 3612F4 E005C3B4 44930000 */  mtc1      $s3, $f0
/* 3612F8 E005C3B8 00000000 */  nop
/* 3612FC E005C3BC 46800020 */  cvt.s.w   $f0, $f0
/* 361300 E005C3C0 3A740006 */  xori      $s4, $s3, 6
/* 361304 E005C3C4 46001081 */  sub.s     $f2, $f2, $f0
/* 361308 E005C3C8 3C014380 */  lui       $at, 0x4380
/* 36130C E005C3CC 44810000 */  mtc1      $at, $f0
/* 361310 E005C3D0 8C63001C */  lw        $v1, 0x1c($v1)
/* 361314 E005C3D4 ACA20008 */  sw        $v0, 8($a1)
/* 361318 E005C3D8 3C028000 */  lui       $v0, 0x8000
/* 36131C E005C3DC ACA7000C */  sw        $a3, 0xc($a1)
/* 361320 E005C3E0 00621821 */  addu      $v1, $v1, $v0
/* 361324 E005C3E4 46001082 */  mul.s     $f2, $f2, $f0
/* 361328 E005C3E8 00000000 */  nop
/* 36132C E005C3EC ACA30004 */  sw        $v1, 4($a1)
/* 361330 E005C3F0 8EC50004 */  lw        $a1, 4($s6)
/* 361334 E005C3F4 8EC60008 */  lw        $a2, 8($s6)
/* 361338 E005C3F8 8EC7000C */  lw        $a3, 0xc($s6)
/* 36133C E005C3FC 4600110D */  trunc.w.s $f4, $f2
/* 361340 E005C400 44122000 */  mfc1      $s2, $f4
/* 361344 E005C404 0C080108 */  jal       func_E0200420
/* 361348 E005C408 2E940001 */   sltiu    $s4, $s4, 1
/* 36134C E005C40C 27B00058 */  addiu     $s0, $sp, 0x58
/* 361350 E005C410 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 361354 E005C414 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 361358 E005C418 44800000 */  mtc1      $zero, $f0
/* 36135C E005C41C 00031080 */  sll       $v0, $v1, 2
/* 361360 E005C420 00431021 */  addu      $v0, $v0, $v1
/* 361364 E005C424 00021080 */  sll       $v0, $v0, 2
/* 361368 E005C428 00431023 */  subu      $v0, $v0, $v1
/* 36136C E005C42C 000218C0 */  sll       $v1, $v0, 3
/* 361370 E005C430 00431021 */  addu      $v0, $v0, $v1
/* 361374 E005C434 000210C0 */  sll       $v0, $v0, 3
/* 361378 E005C438 44060000 */  mfc1      $a2, $f0
/* 36137C E005C43C 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 361380 E005C440 00220821 */  addu      $at, $at, $v0
/* 361384 E005C444 C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 361388 E005C448 3C073F80 */  lui       $a3, 0x3f80
/* 36138C E005C44C 46000007 */  neg.s     $f0, $f0
/* 361390 E005C450 44050000 */  mfc1      $a1, $f0
/* 361394 E005C454 0200202D */  daddu     $a0, $s0, $zero
/* 361398 E005C458 0C080104 */  jal       func_E0200410
/* 36139C E005C45C AFA60010 */   sw       $a2, 0x10($sp)
/* 3613A0 E005C460 0200202D */  daddu     $a0, $s0, $zero
/* 3613A4 E005C464 27A50018 */  addiu     $a1, $sp, 0x18
/* 3613A8 E005C468 27B00098 */  addiu     $s0, $sp, 0x98
/* 3613AC E005C46C 0C080114 */  jal       func_E0200450
/* 3613B0 E005C470 0200302D */   daddu    $a2, $s0, $zero
/* 3613B4 E005C474 0200202D */  daddu     $a0, $s0, $zero
/* 3613B8 E005C478 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3613BC E005C47C 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3613C0 E005C480 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 3613C4 E005C484 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 3613C8 E005C488 96050000 */  lhu       $a1, ($s0)
/* 3613CC E005C48C 8E220000 */  lw        $v0, ($s1)
/* 3613D0 E005C490 00052980 */  sll       $a1, $a1, 6
/* 3613D4 E005C494 00B52821 */  addu      $a1, $a1, $s5
/* 3613D8 E005C498 0C080118 */  jal       func_E0200460
/* 3613DC E005C49C 00452821 */   addu     $a1, $v0, $a1
/* 3613E0 E005C4A0 3C05E6DE */  lui       $a1, 0xe6de
/* 3613E4 E005C4A4 34A5DE82 */  ori       $a1, $a1, 0xde82
/* 3613E8 E005C4A8 8EE60000 */  lw        $a2, ($s7)
/* 3613EC E005C4AC 3C03DA38 */  lui       $v1, 0xda38
/* 3613F0 E005C4B0 00C0202D */  daddu     $a0, $a2, $zero
/* 3613F4 E005C4B4 24C60008 */  addiu     $a2, $a2, 8
/* 3613F8 E005C4B8 AEE60000 */  sw        $a2, ($s7)
/* 3613FC E005C4BC 96020000 */  lhu       $v0, ($s0)
/* 361400 E005C4C0 325200FF */  andi      $s2, $s2, 0xff
/* 361404 E005C4C4 AC830000 */  sw        $v1, ($a0)
/* 361408 E005C4C8 24430001 */  addiu     $v1, $v0, 1
/* 36140C E005C4CC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 361410 E005C4D0 00021180 */  sll       $v0, $v0, 6
/* 361414 E005C4D4 A6030000 */  sh        $v1, ($s0)
/* 361418 E005C4D8 8E230000 */  lw        $v1, ($s1)
/* 36141C E005C4DC 00551021 */  addu      $v0, $v0, $s5
/* 361420 E005C4E0 00621821 */  addu      $v1, $v1, $v0
/* 361424 E005C4E4 24C20008 */  addiu     $v0, $a2, 8
/* 361428 E005C4E8 AC830004 */  sw        $v1, 4($a0)
/* 36142C E005C4EC AEE20000 */  sw        $v0, ($s7)
/* 361430 E005C4F0 3C02FA00 */  lui       $v0, 0xfa00
/* 361434 E005C4F4 ACC20000 */  sw        $v0, ($a2)
/* 361438 E005C4F8 24C20010 */  addiu     $v0, $a2, 0x10
/* 36143C E005C4FC ACC50004 */  sw        $a1, 4($a2)
/* 361440 E005C500 AEE20000 */  sw        $v0, ($s7)
/* 361444 E005C504 3C02FB00 */  lui       $v0, 0xfb00
/* 361448 E005C508 ACC20008 */  sw        $v0, 8($a2)
/* 36144C E005C50C 24C20018 */  addiu     $v0, $a2, 0x18
/* 361450 E005C510 ACD2000C */  sw        $s2, 0xc($a2)
/* 361454 E005C514 AEE20000 */  sw        $v0, ($s7)
/* 361458 E005C518 001311C0 */  sll       $v0, $s3, 7
/* 36145C E005C51C 30420FFF */  andi      $v0, $v0, 0xfff
/* 361460 E005C520 00021300 */  sll       $v0, $v0, 0xc
/* 361464 E005C524 3C04F200 */  lui       $a0, 0xf200
/* 361468 E005C528 00441025 */  or        $v0, $v0, $a0
/* 36146C E005C52C 00139940 */  sll       $s3, $s3, 5
/* 361470 E005C530 ACC20010 */  sw        $v0, 0x10($a2)
/* 361474 E005C534 26620020 */  addiu     $v0, $s3, 0x20
/* 361478 E005C538 00021080 */  sll       $v0, $v0, 2
/* 36147C E005C53C 30420FFF */  andi      $v0, $v0, 0xfff
/* 361480 E005C540 00022B00 */  sll       $a1, $v0, 0xc
/* 361484 E005C544 34A20080 */  ori       $v0, $a1, 0x80
/* 361488 E005C548 1280000F */  beqz      $s4, .LE005C588
/* 36148C E005C54C ACC20014 */   sw       $v0, 0x14($a2)
/* 361490 E005C550 0080182D */  daddu     $v1, $a0, $zero
/* 361494 E005C554 34630080 */  ori       $v1, $v1, 0x80
/* 361498 E005C558 3C040100 */  lui       $a0, 0x100
/* 36149C E005C55C 34840100 */  ori       $a0, $a0, 0x100
/* 3614A0 E005C560 24C20020 */  addiu     $v0, $a2, 0x20
/* 3614A4 E005C564 00A31825 */  or        $v1, $a1, $v1
/* 3614A8 E005C568 AEE20000 */  sw        $v0, ($s7)
/* 3614AC E005C56C 26620040 */  addiu     $v0, $s3, 0x40
/* 3614B0 E005C570 00021080 */  sll       $v0, $v0, 2
/* 3614B4 E005C574 30420FFF */  andi      $v0, $v0, 0xfff
/* 3614B8 E005C578 00021300 */  sll       $v0, $v0, 0xc
/* 3614BC E005C57C 00441025 */  or        $v0, $v0, $a0
/* 3614C0 E005C580 0801716D */  j         .LE005C5B4
/* 3614C4 E005C584 ACC30018 */   sw       $v1, 0x18($a2)
.LE005C588:
/* 3614C8 E005C588 3C030100 */  lui       $v1, 0x100
/* 3614CC E005C58C 34630080 */  ori       $v1, $v1, 0x80
/* 3614D0 E005C590 24C20020 */  addiu     $v0, $a2, 0x20
/* 3614D4 E005C594 AEE20000 */  sw        $v0, ($s7)
/* 3614D8 E005C598 00A41025 */  or        $v0, $a1, $a0
/* 3614DC E005C59C ACC20018 */  sw        $v0, 0x18($a2)
/* 3614E0 E005C5A0 26620040 */  addiu     $v0, $s3, 0x40
/* 3614E4 E005C5A4 00021080 */  sll       $v0, $v0, 2
/* 3614E8 E005C5A8 30420FFF */  andi      $v0, $v0, 0xfff
/* 3614EC E005C5AC 00021300 */  sll       $v0, $v0, 0xc
/* 3614F0 E005C5B0 00431025 */  or        $v0, $v0, $v1
.LE005C5B4:
/* 3614F4 E005C5B4 ACC2001C */  sw        $v0, 0x1c($a2)
/* 3614F8 E005C5B8 8FC20008 */  lw        $v0, 8($fp)
/* 3614FC E005C5BC 24110001 */  addiu     $s1, $zero, 1
/* 361500 E005C5C0 0222102A */  slt       $v0, $s1, $v0
/* 361504 E005C5C4 10400037 */  beqz      $v0, .LE005C6A4
/* 361508 E005C5C8 26D60034 */   addiu    $s6, $s6, 0x34
/* 36150C E005C5CC 3C15800A */  lui       $s5, %hi(gDisplayContext)
/* 361510 E005C5D0 26B5A674 */  addiu     $s5, $s5, %lo(gDisplayContext)
/* 361514 E005C5D4 3C148007 */  lui       $s4, %hi(gMatrixListPos)
/* 361518 E005C5D8 269441F0 */  addiu     $s4, $s4, %lo(gMatrixListPos)
/* 36151C E005C5DC 3C130001 */  lui       $s3, 1
/* 361520 E005C5E0 36731630 */  ori       $s3, $s3, 0x1630
/* 361524 E005C5E4 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 361528 E005C5E8 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 36152C E005C5EC 26D0000C */  addiu     $s0, $s6, 0xc
.LE005C5F0:
/* 361530 E005C5F0 27A40018 */  addiu     $a0, $sp, 0x18
/* 361534 E005C5F4 26310001 */  addiu     $s1, $s1, 1
/* 361538 E005C5F8 8E05FFF8 */  lw        $a1, -8($s0)
/* 36153C E005C5FC 8E06FFFC */  lw        $a2, -4($s0)
/* 361540 E005C600 8E070000 */  lw        $a3, ($s0)
/* 361544 E005C604 0C080108 */  jal       func_E0200420
/* 361548 E005C608 26100034 */   addiu    $s0, $s0, 0x34
/* 36154C E005C60C 27A40018 */  addiu     $a0, $sp, 0x18
/* 361550 E005C610 96850000 */  lhu       $a1, ($s4)
/* 361554 E005C614 8EA20000 */  lw        $v0, ($s5)
/* 361558 E005C618 00052980 */  sll       $a1, $a1, 6
/* 36155C E005C61C 00B32821 */  addu      $a1, $a1, $s3
/* 361560 E005C620 0C080118 */  jal       func_E0200460
/* 361564 E005C624 00452821 */   addu     $a1, $v0, $a1
/* 361568 E005C628 3C06D838 */  lui       $a2, 0xd838
/* 36156C E005C62C 8E440000 */  lw        $a0, ($s2)
/* 361570 E005C630 34C60002 */  ori       $a2, $a2, 2
/* 361574 E005C634 0080282D */  daddu     $a1, $a0, $zero
/* 361578 E005C638 24840008 */  addiu     $a0, $a0, 8
/* 36157C E005C63C AE440000 */  sw        $a0, ($s2)
/* 361580 E005C640 96820000 */  lhu       $v0, ($s4)
/* 361584 E005C644 3C03DA38 */  lui       $v1, 0xda38
/* 361588 E005C648 ACA30000 */  sw        $v1, ($a1)
/* 36158C E005C64C 24430001 */  addiu     $v1, $v0, 1
/* 361590 E005C650 3042FFFF */  andi      $v0, $v0, 0xffff
/* 361594 E005C654 00021180 */  sll       $v0, $v0, 6
/* 361598 E005C658 A6830000 */  sh        $v1, ($s4)
/* 36159C E005C65C 8EA30000 */  lw        $v1, ($s5)
/* 3615A0 E005C660 00531021 */  addu      $v0, $v0, $s3
/* 3615A4 E005C664 00621821 */  addu      $v1, $v1, $v0
/* 3615A8 E005C668 24820008 */  addiu     $v0, $a0, 8
/* 3615AC E005C66C ACA30004 */  sw        $v1, 4($a1)
/* 3615B0 E005C670 AE420000 */  sw        $v0, ($s2)
/* 3615B4 E005C674 3C02DE00 */  lui       $v0, 0xde00
/* 3615B8 E005C678 AC820000 */  sw        $v0, ($a0)
/* 3615BC E005C67C 8FA900D8 */  lw        $t1, 0xd8($sp)
/* 3615C0 E005C680 24020040 */  addiu     $v0, $zero, 0x40
/* 3615C4 E005C684 AC860008 */  sw        $a2, 8($a0)
/* 3615C8 E005C688 AC82000C */  sw        $v0, 0xc($a0)
/* 3615CC E005C68C AC890004 */  sw        $t1, 4($a0)
/* 3615D0 E005C690 8FC20008 */  lw        $v0, 8($fp)
/* 3615D4 E005C694 24840010 */  addiu     $a0, $a0, 0x10
/* 3615D8 E005C698 0222102A */  slt       $v0, $s1, $v0
/* 3615DC E005C69C 1440FFD4 */  bnez      $v0, .LE005C5F0
/* 3615E0 E005C6A0 AE440000 */   sw       $a0, ($s2)
.LE005C6A4:
/* 3615E4 E005C6A4 3C05D838 */  lui       $a1, 0xd838
/* 3615E8 E005C6A8 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 3615EC E005C6AC 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 3615F0 E005C6B0 8C620000 */  lw        $v0, ($v1)
/* 3615F4 E005C6B4 34A50002 */  ori       $a1, $a1, 2
/* 3615F8 E005C6B8 0040202D */  daddu     $a0, $v0, $zero
/* 3615FC E005C6BC 24420008 */  addiu     $v0, $v0, 8
/* 361600 E005C6C0 AC620000 */  sw        $v0, ($v1)
/* 361604 E005C6C4 24020040 */  addiu     $v0, $zero, 0x40
/* 361608 E005C6C8 AC850000 */  sw        $a1, ($a0)
/* 36160C E005C6CC AC820004 */  sw        $v0, 4($a0)
/* 361610 E005C6D0 8FBF0104 */  lw        $ra, 0x104($sp)
/* 361614 E005C6D4 8FBE0100 */  lw        $fp, 0x100($sp)
/* 361618 E005C6D8 8FB700FC */  lw        $s7, 0xfc($sp)
/* 36161C E005C6DC 8FB600F8 */  lw        $s6, 0xf8($sp)
/* 361620 E005C6E0 8FB500F4 */  lw        $s5, 0xf4($sp)
/* 361624 E005C6E4 8FB400F0 */  lw        $s4, 0xf0($sp)
/* 361628 E005C6E8 8FB300EC */  lw        $s3, 0xec($sp)
/* 36162C E005C6EC 8FB200E8 */  lw        $s2, 0xe8($sp)
/* 361630 E005C6F0 8FB100E4 */  lw        $s1, 0xe4($sp)
/* 361634 E005C6F4 8FB000E0 */  lw        $s0, 0xe0($sp)
/* 361638 E005C6F8 03E00008 */  jr        $ra
/* 36163C E005C6FC 27BD0108 */   addiu    $sp, $sp, 0x108
