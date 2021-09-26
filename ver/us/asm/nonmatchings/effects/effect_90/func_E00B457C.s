.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00B457C
/* 3B626C E00B457C 27BDFEF8 */  addiu     $sp, $sp, -0x108
/* 3B6270 E00B4580 0080282D */  daddu     $a1, $a0, $zero
/* 3B6274 E00B4584 3C06DB06 */  lui       $a2, 0xdb06
/* 3B6278 E00B4588 34C60024 */  ori       $a2, $a2, 0x24
/* 3B627C E00B458C 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B6280 E00B4590 AFB300BC */  sw        $s3, 0xbc($sp)
/* 3B6284 E00B4594 3C130001 */  lui       $s3, 1
/* 3B6288 E00B4598 36731630 */  ori       $s3, $s3, 0x1630
/* 3B628C E00B459C AFB600C8 */  sw        $s6, 0xc8($sp)
/* 3B6290 E00B45A0 3C16E00B */  lui       $s6, %hi(D_E00B4CF0)
/* 3B6294 E00B45A4 26D64CF0 */  addiu     $s6, $s6, %lo(D_E00B4CF0)
/* 3B6298 E00B45A8 AFB100B4 */  sw        $s1, 0xb4($sp)
/* 3B629C E00B45AC 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 3B62A0 E00B45B0 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 3B62A4 E00B45B4 3C02E700 */  lui       $v0, 0xe700
/* 3B62A8 E00B45B8 AFBF00D4 */  sw        $ra, 0xd4($sp)
/* 3B62AC E00B45BC AFBE00D0 */  sw        $fp, 0xd0($sp)
/* 3B62B0 E00B45C0 AFB700CC */  sw        $s7, 0xcc($sp)
/* 3B62B4 E00B45C4 AFB500C4 */  sw        $s5, 0xc4($sp)
/* 3B62B8 E00B45C8 AFB400C0 */  sw        $s4, 0xc0($sp)
/* 3B62BC E00B45CC AFB200B8 */  sw        $s2, 0xb8($sp)
/* 3B62C0 E00B45D0 AFB000B0 */  sw        $s0, 0xb0($sp)
/* 3B62C4 E00B45D4 F7BE0100 */  sdc1      $f30, 0x100($sp)
/* 3B62C8 E00B45D8 F7BC00F8 */  sdc1      $f28, 0xf8($sp)
/* 3B62CC E00B45DC F7BA00F0 */  sdc1      $f26, 0xf0($sp)
/* 3B62D0 E00B45E0 F7B800E8 */  sdc1      $f24, 0xe8($sp)
/* 3B62D4 E00B45E4 F7B600E0 */  sdc1      $f22, 0xe0($sp)
/* 3B62D8 E00B45E8 F7B400D8 */  sdc1      $f20, 0xd8($sp)
/* 3B62DC E00B45EC 8E280000 */  lw        $t0, ($s1)
/* 3B62E0 E00B45F0 8CAD000C */  lw        $t5, 0xc($a1)
/* 3B62E4 E00B45F4 0100182D */  daddu     $v1, $t0, $zero
/* 3B62E8 E00B45F8 AFAD00A0 */  sw        $t5, 0xa0($sp)
/* 3B62EC E00B45FC 8DAD0024 */  lw        $t5, 0x24($t5)
/* 3B62F0 E00B4600 25080008 */  addiu     $t0, $t0, 8
/* 3B62F4 E00B4604 AFAD00A4 */  sw        $t5, 0xa4($sp)
/* 3B62F8 E00B4608 AC620000 */  sw        $v0, ($v1)
/* 3B62FC E00B460C AC600004 */  sw        $zero, 4($v1)
/* 3B6300 E00B4610 AD060000 */  sw        $a2, ($t0)
/* 3B6304 E00B4614 8CA20010 */  lw        $v0, 0x10($a1)
/* 3B6308 E00B4618 0000B82D */  daddu     $s7, $zero, $zero
/* 3B630C E00B461C AE280000 */  sw        $t0, ($s1)
/* 3B6310 E00B4620 8C42001C */  lw        $v0, 0x1c($v0)
/* 3B6314 E00B4624 3C038000 */  lui       $v1, 0x8000
/* 3B6318 E00B4628 00431021 */  addu      $v0, $v0, $v1
/* 3B631C E00B462C AD020004 */  sw        $v0, 4($t0)
/* 3B6320 E00B4630 8FAD00A0 */  lw        $t5, 0xa0($sp)
/* 3B6324 E00B4634 26D5000A */  addiu     $s5, $s6, 0xa
/* 3B6328 E00B4638 8DA50004 */  lw        $a1, 4($t5)
/* 3B632C E00B463C 8DA60008 */  lw        $a2, 8($t5)
/* 3B6330 E00B4640 8DA7000C */  lw        $a3, 0xc($t5)
/* 3B6334 E00B4644 25080008 */  addiu     $t0, $t0, 8
/* 3B6338 E00B4648 0C080108 */  jal       shim_guTranslateF
/* 3B633C E00B464C AE280000 */   sw       $t0, ($s1)
/* 3B6340 E00B4650 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B6344 E00B4654 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3B6348 E00B4658 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3B634C E00B465C 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 3B6350 E00B4660 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 3B6354 E00B4664 96050000 */  lhu       $a1, ($s0)
/* 3B6358 E00B4668 8E420000 */  lw        $v0, ($s2)
/* 3B635C E00B466C 00052980 */  sll       $a1, $a1, 6
/* 3B6360 E00B4670 00B32821 */  addu      $a1, $a1, $s3
/* 3B6364 E00B4674 0C080118 */  jal       shim_guMtxF2L
/* 3B6368 E00B4678 00452821 */   addu     $a1, $v0, $a1
/* 3B636C E00B467C 3C02DA38 */  lui       $v0, 0xda38
/* 3B6370 E00B4680 8E240000 */  lw        $a0, ($s1)
/* 3B6374 E00B4684 34420002 */  ori       $v0, $v0, 2
/* 3B6378 E00B4688 0080302D */  daddu     $a2, $a0, $zero
/* 3B637C E00B468C 24840008 */  addiu     $a0, $a0, 8
/* 3B6380 E00B4690 248D0008 */  addiu     $t5, $a0, 8
/* 3B6384 E00B4694 01A0F02D */  daddu     $fp, $t5, $zero
/* 3B6388 E00B4698 AFAD00A8 */  sw        $t5, 0xa8($sp)
/* 3B638C E00B469C 96050000 */  lhu       $a1, ($s0)
/* 3B6390 E00B46A0 24940017 */  addiu     $s4, $a0, 0x17
/* 3B6394 E00B46A4 AE240000 */  sw        $a0, ($s1)
/* 3B6398 E00B46A8 ACC20000 */  sw        $v0, ($a2)
/* 3B639C E00B46AC 8E430000 */  lw        $v1, ($s2)
/* 3B63A0 E00B46B0 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 3B63A4 E00B46B4 00021180 */  sll       $v0, $v0, 6
/* 3B63A8 E00B46B8 00531021 */  addu      $v0, $v0, $s3
/* 3B63AC E00B46BC 00621821 */  addu      $v1, $v1, $v0
/* 3B63B0 E00B46C0 3C02DE01 */  lui       $v0, 0xde01
/* 3B63B4 E00B46C4 ACC30004 */  sw        $v1, 4($a2)
/* 3B63B8 E00B46C8 AC820000 */  sw        $v0, ($a0)
/* 3B63BC E00B46CC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 3B63C0 E00B46D0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 3B63C4 E00B46D4 24830288 */  addiu     $v1, $a0, 0x288
/* 3B63C8 E00B46D8 AC830004 */  sw        $v1, 4($a0)
/* 3B63CC E00B46DC 94420134 */  lhu       $v0, 0x134($v0)
/* 3B63D0 E00B46E0 24A50001 */  addiu     $a1, $a1, 1
/* 3B63D4 E00B46E4 A6050000 */  sh        $a1, ($s0)
/* 3B63D8 E00B46E8 AE230000 */  sw        $v1, ($s1)
/* 3B63DC E00B46EC 00028080 */  sll       $s0, $v0, 2
.LE00B46F0:
/* 3B63E0 E00B46F0 82C30000 */  lb        $v1, ($s6)
/* 3B63E4 E00B46F4 4480F000 */  mtc1      $zero, $f30
/* 3B63E8 E00B46F8 00031080 */  sll       $v0, $v1, 2
/* 3B63EC E00B46FC 00431021 */  addu      $v0, $v0, $v1
/* 3B63F0 E00B4700 00021040 */  sll       $v0, $v0, 1
/* 3B63F4 E00B4704 82A3FFF7 */  lb        $v1, -9($s5)
/* 3B63F8 E00B4708 4482E000 */  mtc1      $v0, $f28
/* 3B63FC E00B470C 00000000 */  nop
/* 3B6400 E00B4710 4680E720 */  cvt.s.w   $f28, $f28
/* 3B6404 E00B4714 00031080 */  sll       $v0, $v1, 2
/* 3B6408 E00B4718 00431021 */  addu      $v0, $v0, $v1
/* 3B640C E00B471C 00021040 */  sll       $v0, $v0, 1
/* 3B6410 E00B4720 4482C000 */  mtc1      $v0, $f24
/* 3B6414 E00B4724 00000000 */  nop
/* 3B6418 E00B4728 4680C620 */  cvt.s.w   $f24, $f24
/* 3B641C E00B472C 82A3FFF8 */  lb        $v1, -8($s5)
/* 3B6420 E00B4730 461EC032 */  c.eq.s    $f24, $f30
/* 3B6424 E00B4734 00031080 */  sll       $v0, $v1, 2
/* 3B6428 E00B4738 00431021 */  addu      $v0, $v0, $v1
/* 3B642C E00B473C 00021040 */  sll       $v0, $v0, 1
/* 3B6430 E00B4740 4482D000 */  mtc1      $v0, $f26
/* 3B6434 E00B4744 00000000 */  nop
/* 3B6438 E00B4748 4680D6A0 */  cvt.s.w   $f26, $f26
/* 3B643C E00B474C 45010052 */  bc1t      .LE00B4898
/* 3B6440 E00B4750 00000000 */   nop
/* 3B6444 E00B4754 3C014120 */  lui       $at, 0x4120
/* 3B6448 E00B4758 44813000 */  mtc1      $at, $f6
/* 3B644C E00B475C 00000000 */  nop
/* 3B6450 E00B4760 4606C002 */  mul.s     $f0, $f24, $f6
/* 3B6454 E00B4764 00000000 */  nop
/* 3B6458 E00B4768 3C0142C8 */  lui       $at, 0x42c8
/* 3B645C E00B476C 44813000 */  mtc1      $at, $f6
/* 3B6460 E00B4770 00000000 */  nop
/* 3B6464 E00B4774 4606D082 */  mul.s     $f2, $f26, $f6
/* 3B6468 E00B4778 00000000 */  nop
/* 3B646C E00B477C 4600E000 */  add.s     $f0, $f28, $f0
/* 3B6470 E00B4780 46020000 */  add.s     $f0, $f0, $f2
/* 3B6474 E00B4784 4600018D */  trunc.w.s $f6, $f0
/* 3B6478 E00B4788 44053000 */  mfc1      $a1, $f6
/* 3B647C E00B478C 0C080011 */  jal       func_E0200044
/* 3B6480 E00B4790 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 3B6484 E00B4794 02021021 */  addu      $v0, $s0, $v0
/* 3B6488 E00B4798 44826000 */  mtc1      $v0, $f12
/* 3B648C E00B479C 00000000 */  nop
/* 3B6490 E00B47A0 0C080140 */  jal       shim_sin_deg
/* 3B6494 E00B47A4 46806320 */   cvt.s.w  $f12, $f12
/* 3B6498 E00B47A8 3C014120 */  lui       $at, 0x4120
/* 3B649C E00B47AC 44813000 */  mtc1      $at, $f6
/* 3B64A0 E00B47B0 00000000 */  nop
/* 3B64A4 E00B47B4 4606E102 */  mul.s     $f4, $f28, $f6
/* 3B64A8 E00B47B8 00000000 */  nop
/* 3B64AC E00B47BC 3C0142C8 */  lui       $at, 0x42c8
/* 3B64B0 E00B47C0 44813000 */  mtc1      $at, $f6
/* 3B64B4 E00B47C4 00000000 */  nop
/* 3B64B8 E00B47C8 4606C082 */  mul.s     $f2, $f24, $f6
/* 3B64BC E00B47CC 00000000 */  nop
/* 3B64C0 E00B47D0 46022100 */  add.s     $f4, $f4, $f2
/* 3B64C4 E00B47D4 461A2100 */  add.s     $f4, $f4, $f26
/* 3B64C8 E00B47D8 4600218D */  trunc.w.s $f6, $f4
/* 3B64CC E00B47DC 44053000 */  mfc1      $a1, $f6
/* 3B64D0 E00B47E0 3C0141A0 */  lui       $at, 0x41a0
/* 3B64D4 E00B47E4 44813000 */  mtc1      $at, $f6
/* 3B64D8 E00B47E8 00000000 */  nop
/* 3B64DC E00B47EC 46060582 */  mul.s     $f22, $f0, $f6
/* 3B64E0 E00B47F0 00000000 */  nop
/* 3B64E4 E00B47F4 0C080011 */  jal       func_E0200044
/* 3B64E8 E00B47F8 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 3B64EC E00B47FC 02021021 */  addu      $v0, $s0, $v0
/* 3B64F0 E00B4800 44826000 */  mtc1      $v0, $f12
/* 3B64F4 E00B4804 00000000 */  nop
/* 3B64F8 E00B4808 0C080140 */  jal       shim_sin_deg
/* 3B64FC E00B480C 46806320 */   cvt.s.w  $f12, $f12
/* 3B6500 E00B4810 3C0142C8 */  lui       $at, 0x42c8
/* 3B6504 E00B4814 44813000 */  mtc1      $at, $f6
/* 3B6508 E00B4818 00000000 */  nop
/* 3B650C E00B481C 4606E082 */  mul.s     $f2, $f28, $f6
/* 3B6510 E00B4820 00000000 */  nop
/* 3B6514 E00B4824 3C014120 */  lui       $at, 0x4120
/* 3B6518 E00B4828 44813000 */  mtc1      $at, $f6
/* 3B651C E00B482C 00000000 */  nop
/* 3B6520 E00B4830 4606D102 */  mul.s     $f4, $f26, $f6
/* 3B6524 E00B4834 00000000 */  nop
/* 3B6528 E00B4838 46181080 */  add.s     $f2, $f2, $f24
/* 3B652C E00B483C 46041080 */  add.s     $f2, $f2, $f4
/* 3B6530 E00B4840 4600118D */  trunc.w.s $f6, $f2
/* 3B6534 E00B4844 44053000 */  mfc1      $a1, $f6
/* 3B6538 E00B4848 3C0141A0 */  lui       $at, 0x41a0
/* 3B653C E00B484C 44813000 */  mtc1      $at, $f6
/* 3B6540 E00B4850 00000000 */  nop
/* 3B6544 E00B4854 46060502 */  mul.s     $f20, $f0, $f6
/* 3B6548 E00B4858 00000000 */  nop
/* 3B654C E00B485C 0C080011 */  jal       func_E0200044
/* 3B6550 E00B4860 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 3B6554 E00B4864 02021021 */  addu      $v0, $s0, $v0
/* 3B6558 E00B4868 44826000 */  mtc1      $v0, $f12
/* 3B655C E00B486C 00000000 */  nop
/* 3B6560 E00B4870 0C080140 */  jal       shim_sin_deg
/* 3B6564 E00B4874 46806320 */   cvt.s.w  $f12, $f12
/* 3B6568 E00B4878 3C0141A0 */  lui       $at, 0x41a0
/* 3B656C E00B487C 44813000 */  mtc1      $at, $f6
/* 3B6570 E00B4880 00000000 */  nop
/* 3B6574 E00B4884 46060002 */  mul.s     $f0, $f0, $f6
/* 3B6578 E00B4888 00000000 */  nop
/* 3B657C E00B488C 4616E700 */  add.s     $f28, $f28, $f22
/* 3B6580 E00B4890 4614C600 */  add.s     $f24, $f24, $f20
/* 3B6584 E00B4894 4600D680 */  add.s     $f26, $f26, $f0
.LE00B4898:
/* 3B6588 E00B4898 4600E18D */  trunc.w.s $f6, $f28
/* 3B658C E00B489C 44023000 */  mfc1      $v0, $f6
/* 3B6590 E00B48A0 00000000 */  nop
/* 3B6594 E00B48A4 A7C20000 */  sh        $v0, ($fp)
/* 3B6598 E00B48A8 4600C18D */  trunc.w.s $f6, $f24
/* 3B659C E00B48AC 44023000 */  mfc1      $v0, $f6
/* 3B65A0 E00B48B0 00000000 */  nop
/* 3B65A4 E00B48B4 A682FFF3 */  sh        $v0, -0xd($s4)
/* 3B65A8 E00B48B8 4600D18D */  trunc.w.s $f6, $f26
/* 3B65AC E00B48BC 44023000 */  mfc1      $v0, $f6
/* 3B65B0 E00B48C0 00000000 */  nop
/* 3B65B4 E00B48C4 A682FFF5 */  sh        $v0, -0xb($s4)
/* 3B65B8 E00B48C8 96A2FFFA */  lhu       $v0, -6($s5)
/* 3B65BC E00B48CC A682FFF9 */  sh        $v0, -7($s4)
/* 3B65C0 E00B48D0 96A2FFFC */  lhu       $v0, -4($s5)
/* 3B65C4 E00B48D4 26F70001 */  addiu     $s7, $s7, 1
/* 3B65C8 E00B48D8 A682FFFB */  sh        $v0, -5($s4)
/* 3B65CC E00B48DC 92A2FFFE */  lbu       $v0, -2($s5)
/* 3B65D0 E00B48E0 26D6000C */  addiu     $s6, $s6, 0xc
/* 3B65D4 E00B48E4 A282FFFD */  sb        $v0, -3($s4)
/* 3B65D8 E00B48E8 92A2FFFF */  lbu       $v0, -1($s5)
/* 3B65DC E00B48EC 27DE0010 */  addiu     $fp, $fp, 0x10
/* 3B65E0 E00B48F0 A282FFFE */  sb        $v0, -2($s4)
/* 3B65E4 E00B48F4 92A30000 */  lbu       $v1, ($s5)
/* 3B65E8 E00B48F8 26B5000C */  addiu     $s5, $s5, 0xc
/* 3B65EC E00B48FC 24020050 */  addiu     $v0, $zero, 0x50
/* 3B65F0 E00B4900 A2820000 */  sb        $v0, ($s4)
/* 3B65F4 E00B4904 2AE20028 */  slti      $v0, $s7, 0x28
/* 3B65F8 E00B4908 A283FFFF */  sb        $v1, -1($s4)
/* 3B65FC E00B490C 1440FF78 */  bnez      $v0, .LE00B46F0
/* 3B6600 E00B4910 26940010 */   addiu    $s4, $s4, 0x10
/* 3B6604 E00B4914 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B6608 E00B4918 3C100001 */  lui       $s0, 1
/* 3B660C E00B491C 36101630 */  ori       $s0, $s0, 0x1630
/* 3B6610 E00B4920 0000B82D */  daddu     $s7, $zero, $zero
/* 3B6614 E00B4924 4600F506 */  mov.s     $f20, $f30
/* 3B6618 E00B4928 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 3B661C E00B492C 2442A674 */  addiu     $v0, $v0, %lo(gDisplayContext)
/* 3B6620 E00B4930 0040A82D */  daddu     $s5, $v0, $zero
/* 3B6624 E00B4934 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 3B6628 E00B4938 244241F0 */  addiu     $v0, $v0, %lo(gMatrixListPos)
/* 3B662C E00B493C 0040982D */  daddu     $s3, $v0, $zero
/* 3B6630 E00B4940 3C013DCC */  lui       $at, 0x3dcc
/* 3B6634 E00B4944 3421CCCD */  ori       $at, $at, 0xcccd
/* 3B6638 E00B4948 44810000 */  mtc1      $at, $f0
/* 3B663C E00B494C 3C140001 */  lui       $s4, 1
/* 3B6640 E00B4950 44050000 */  mfc1      $a1, $f0
/* 3B6644 E00B4954 8FB100A0 */  lw        $s1, 0xa0($sp)
/* 3B6648 E00B4958 00A0302D */  daddu     $a2, $a1, $zero
/* 3B664C E00B495C 0C080110 */  jal       shim_guScaleF
/* 3B6650 E00B4960 00A0382D */   daddu    $a3, $a1, $zero
/* 3B6654 E00B4964 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B6658 E00B4968 96650000 */  lhu       $a1, ($s3)
/* 3B665C E00B496C 8EA20000 */  lw        $v0, ($s5)
/* 3B6660 E00B4970 00052980 */  sll       $a1, $a1, 6
/* 3B6664 E00B4974 00B02821 */  addu      $a1, $a1, $s0
/* 3B6668 E00B4978 0C080118 */  jal       shim_guMtxF2L
/* 3B666C E00B497C 00452821 */   addu     $a1, $v0, $a1
/* 3B6670 E00B4980 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* 3B6674 E00B4984 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* 3B6678 E00B4988 8C440000 */  lw        $a0, ($v0)
/* 3B667C E00B498C 0040902D */  daddu     $s2, $v0, $zero
/* 3B6680 E00B4990 0080282D */  daddu     $a1, $a0, $zero
/* 3B6684 E00B4994 24840008 */  addiu     $a0, $a0, 8
/* 3B6688 E00B4998 AE440000 */  sw        $a0, ($s2)
/* 3B668C E00B499C 96620000 */  lhu       $v0, ($s3)
/* 3B6690 E00B49A0 3C03DA38 */  lui       $v1, 0xda38
/* 3B6694 E00B49A4 ACA30000 */  sw        $v1, ($a1)
/* 3B6698 E00B49A8 24430001 */  addiu     $v1, $v0, 1
/* 3B669C E00B49AC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3B66A0 E00B49B0 00021180 */  sll       $v0, $v0, 6
/* 3B66A4 E00B49B4 A6630000 */  sh        $v1, ($s3)
/* 3B66A8 E00B49B8 8EA30000 */  lw        $v1, ($s5)
/* 3B66AC E00B49BC 00501021 */  addu      $v0, $v0, $s0
/* 3B66B0 E00B49C0 00621821 */  addu      $v1, $v1, $v0
/* 3B66B4 E00B49C4 24820008 */  addiu     $v0, $a0, 8
/* 3B66B8 E00B49C8 ACA30004 */  sw        $v1, 4($a1)
/* 3B66BC E00B49CC AE420000 */  sw        $v0, ($s2)
/* 3B66C0 E00B49D0 3C02FB00 */  lui       $v0, 0xfb00
/* 3B66C4 E00B49D4 AC820000 */  sw        $v0, ($a0)
/* 3B66C8 E00B49D8 8FAD00A0 */  lw        $t5, 0xa0($sp)
/* 3B66CC E00B49DC 36941630 */  ori       $s4, $s4, 0x1630
/* 3B66D0 E00B49E0 91A3002B */  lbu       $v1, 0x2b($t5)
/* 3B66D4 E00B49E4 24820010 */  addiu     $v0, $a0, 0x10
/* 3B66D8 E00B49E8 AE420000 */  sw        $v0, ($s2)
/* 3B66DC E00B49EC 3C02FA00 */  lui       $v0, 0xfa00
/* 3B66E0 E00B49F0 AC820008 */  sw        $v0, 8($a0)
/* 3B66E4 E00B49F4 8FAD00A4 */  lw        $t5, 0xa4($sp)
/* 3B66E8 E00B49F8 2402FF00 */  addiu     $v0, $zero, -0x100
/* 3B66EC E00B49FC 01A21025 */  or        $v0, $t5, $v0
/* 3B66F0 E00B4A00 AC82000C */  sw        $v0, 0xc($a0)
/* 3B66F4 E00B4A04 24820018 */  addiu     $v0, $a0, 0x18
/* 3B66F8 E00B4A08 AE420000 */  sw        $v0, ($s2)
/* 3B66FC E00B4A0C 3C02DE00 */  lui       $v0, 0xde00
/* 3B6700 E00B4A10 AC820010 */  sw        $v0, 0x10($a0)
/* 3B6704 E00B4A14 3C020900 */  lui       $v0, 0x900
/* 3B6708 E00B4A18 244203B0 */  addiu     $v0, $v0, 0x3b0
/* 3B670C E00B4A1C 3463FF00 */  ori       $v1, $v1, 0xff00
/* 3B6710 E00B4A20 AC820014 */  sw        $v0, 0x14($a0)
/* 3B6714 E00B4A24 AC830004 */  sw        $v1, 4($a0)
.LE00B4A28:
/* 3B6718 E00B4A28 8E220088 */  lw        $v0, 0x88($s1)
/* 3B671C E00B4A2C 04420032 */  bltzl     $v0, .LE00B4AF8
/* 3B6720 E00B4A30 26F70001 */   addiu    $s7, $s7, 1
/* 3B6724 E00B4A34 C6200078 */  lwc1      $f0, 0x78($s1)
/* 3B6728 E00B4A38 4405A000 */  mfc1      $a1, $f20
/* 3B672C E00B4A3C 4406A000 */  mfc1      $a2, $f20
/* 3B6730 E00B4A40 4407A000 */  mfc1      $a3, $f20
/* 3B6734 E00B4A44 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3B6738 E00B4A48 C6200038 */  lwc1      $f0, 0x38($s1)
/* 3B673C E00B4A4C E7A00014 */  swc1      $f0, 0x14($sp)
/* 3B6740 E00B4A50 C6200048 */  lwc1      $f0, 0x48($s1)
/* 3B6744 E00B4A54 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B6748 E00B4A58 E7B4001C */  swc1      $f20, 0x1c($sp)
/* 3B674C E00B4A5C 0C080180 */  jal       shim_guPositionF
/* 3B6750 E00B4A60 E7A00018 */   swc1     $f0, 0x18($sp)
/* 3B6754 E00B4A64 27A40020 */  addiu     $a0, $sp, 0x20
/* 3B6758 E00B4A68 96650000 */  lhu       $a1, ($s3)
/* 3B675C E00B4A6C 8EA20000 */  lw        $v0, ($s5)
/* 3B6760 E00B4A70 00052980 */  sll       $a1, $a1, 6
/* 3B6764 E00B4A74 00B42821 */  addu      $a1, $a1, $s4
/* 3B6768 E00B4A78 0C080118 */  jal       shim_guMtxF2L
/* 3B676C E00B4A7C 00452821 */   addu     $a1, $v0, $a1
/* 3B6770 E00B4A80 3C06D838 */  lui       $a2, 0xd838
/* 3B6774 E00B4A84 8E440000 */  lw        $a0, ($s2)
/* 3B6778 E00B4A88 34C60002 */  ori       $a2, $a2, 2
/* 3B677C E00B4A8C 0080282D */  daddu     $a1, $a0, $zero
/* 3B6780 E00B4A90 24840008 */  addiu     $a0, $a0, 8
/* 3B6784 E00B4A94 AE440000 */  sw        $a0, ($s2)
/* 3B6788 E00B4A98 96620000 */  lhu       $v0, ($s3)
/* 3B678C E00B4A9C 3C03DA38 */  lui       $v1, 0xda38
/* 3B6790 E00B4AA0 ACA30000 */  sw        $v1, ($a1)
/* 3B6794 E00B4AA4 24430001 */  addiu     $v1, $v0, 1
/* 3B6798 E00B4AA8 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3B679C E00B4AAC 00021180 */  sll       $v0, $v0, 6
/* 3B67A0 E00B4AB0 A6630000 */  sh        $v1, ($s3)
/* 3B67A4 E00B4AB4 8EA30000 */  lw        $v1, ($s5)
/* 3B67A8 E00B4AB8 00541021 */  addu      $v0, $v0, $s4
/* 3B67AC E00B4ABC 00621821 */  addu      $v1, $v1, $v0
/* 3B67B0 E00B4AC0 24820008 */  addiu     $v0, $a0, 8
/* 3B67B4 E00B4AC4 ACA30004 */  sw        $v1, 4($a1)
/* 3B67B8 E00B4AC8 AE420000 */  sw        $v0, ($s2)
/* 3B67BC E00B4ACC 3C02DE00 */  lui       $v0, 0xde00
/* 3B67C0 E00B4AD0 AC820000 */  sw        $v0, ($a0)
/* 3B67C4 E00B4AD4 3C020900 */  lui       $v0, 0x900
/* 3B67C8 E00B4AD8 244204A0 */  addiu     $v0, $v0, 0x4a0
/* 3B67CC E00B4ADC AC820004 */  sw        $v0, 4($a0)
/* 3B67D0 E00B4AE0 24820010 */  addiu     $v0, $a0, 0x10
/* 3B67D4 E00B4AE4 AE420000 */  sw        $v0, ($s2)
/* 3B67D8 E00B4AE8 24020040 */  addiu     $v0, $zero, 0x40
/* 3B67DC E00B4AEC AC860008 */  sw        $a2, 8($a0)
/* 3B67E0 E00B4AF0 AC82000C */  sw        $v0, 0xc($a0)
/* 3B67E4 E00B4AF4 26F70001 */  addiu     $s7, $s7, 1
.LE00B4AF8:
/* 3B67E8 E00B4AF8 2AE20004 */  slti      $v0, $s7, 4
/* 3B67EC E00B4AFC 1440FFCA */  bnez      $v0, .LE00B4A28
/* 3B67F0 E00B4B00 26310004 */   addiu    $s1, $s1, 4
/* 3B67F4 E00B4B04 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 3B67F8 E00B4B08 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 3B67FC E00B4B0C 3C02DE00 */  lui       $v0, 0xde00
/* 3B6800 E00B4B10 8C830000 */  lw        $v1, ($a0)
/* 3B6804 E00B4B14 3C01E00B */  lui       $at, %hi(D_E00B4EF8)
/* 3B6808 E00B4B18 D4224EF8 */  ldc1      $f2, %lo(D_E00B4EF8)($at)
/* 3B680C E00B4B1C 0060282D */  daddu     $a1, $v1, $zero
/* 3B6810 E00B4B20 24630008 */  addiu     $v1, $v1, 8
/* 3B6814 E00B4B24 AC830000 */  sw        $v1, ($a0)
/* 3B6818 E00B4B28 ACA20000 */  sw        $v0, ($a1)
/* 3B681C E00B4B2C C7A000A4 */  lwc1      $f0, 0xa4($sp)
/* 3B6820 E00B4B30 46800021 */  cvt.d.w   $f0, $f0
/* 3B6824 E00B4B34 3C020900 */  lui       $v0, 0x900
/* 3B6828 E00B4B38 24420300 */  addiu     $v0, $v0, 0x300
/* 3B682C E00B4B3C ACA20004 */  sw        $v0, 4($a1)
/* 3B6830 E00B4B40 24620008 */  addiu     $v0, $v1, 8
/* 3B6834 E00B4B44 AC820000 */  sw        $v0, ($a0)
/* 3B6838 E00B4B48 3C02FA00 */  lui       $v0, 0xfa00
/* 3B683C E00B4B4C 246C0004 */  addiu     $t4, $v1, 4
/* 3B6840 E00B4B50 46220002 */  mul.d     $f0, $f0, $f2
/* 3B6844 E00B4B54 00000000 */  nop
/* 3B6848 E00B4B58 AC620000 */  sw        $v0, ($v1)
/* 3B684C E00B4B5C 8FAD00A0 */  lw        $t5, 0xa0($sp)
/* 3B6850 E00B4B60 3C0141E0 */  lui       $at, 0x41e0
/* 3B6854 E00B4B64 44811800 */  mtc1      $at, $f3
/* 3B6858 E00B4B68 44801000 */  mtc1      $zero, $f2
/* 3B685C E00B4B6C 91A4001B */  lbu       $a0, 0x1b($t5)
/* 3B6860 E00B4B70 91A3001F */  lbu       $v1, 0x1f($t5)
/* 3B6864 E00B4B74 91A20023 */  lbu       $v0, 0x23($t5)
/* 3B6868 E00B4B78 00042600 */  sll       $a0, $a0, 0x18
/* 3B686C E00B4B7C 00031C00 */  sll       $v1, $v1, 0x10
/* 3B6870 E00B4B80 00832025 */  or        $a0, $a0, $v1
/* 3B6874 E00B4B84 00021200 */  sll       $v0, $v0, 8
/* 3B6878 E00B4B88 4620103E */  c.le.d    $f2, $f0
/* 3B687C E00B4B8C 00000000 */  nop
/* 3B6880 E00B4B90 45010005 */  bc1t      .LE00B4BA8
/* 3B6884 E00B4B94 00825825 */   or       $t3, $a0, $v0
/* 3B6888 E00B4B98 4620018D */  trunc.w.d $f6, $f0
/* 3B688C E00B4B9C 440A3000 */  mfc1      $t2, $f6
/* 3B6890 E00B4BA0 0802D2F1 */  j         .LE00B4BC4
/* 3B6894 E00B4BA4 3C05D9FF */   lui      $a1, 0xd9ff
.LE00B4BA8:
/* 3B6898 E00B4BA8 46220001 */  sub.d     $f0, $f0, $f2
/* 3B689C E00B4BAC 3C028000 */  lui       $v0, 0x8000
/* 3B68A0 E00B4BB0 4620018D */  trunc.w.d $f6, $f0
/* 3B68A4 E00B4BB4 440A3000 */  mfc1      $t2, $f6
/* 3B68A8 E00B4BB8 00000000 */  nop
/* 3B68AC E00B4BBC 01425025 */  or        $t2, $t2, $v0
/* 3B68B0 E00B4BC0 3C05D9FF */  lui       $a1, 0xd9ff
.LE00B4BC4:
/* 3B68B4 E00B4BC4 34A5F9FF */  ori       $a1, $a1, 0xf9ff
/* 3B68B8 E00B4BC8 3C06D9FF */  lui       $a2, 0xd9ff
/* 3B68BC E00B4BCC 34C6FFFF */  ori       $a2, $a2, 0xffff
/* 3B68C0 E00B4BD0 3C070101 */  lui       $a3, 0x101
/* 3B68C4 E00B4BD4 34E7E03C */  ori       $a3, $a3, 0xe03c
/* 3B68C8 E00B4BD8 3C090100 */  lui       $t1, 0x100
/* 3B68CC E00B4BDC 3529C018 */  ori       $t1, $t1, 0xc018
/* 3B68D0 E00B4BE0 3C08D838 */  lui       $t0, 0xd838
/* 3B68D4 E00B4BE4 35080002 */  ori       $t0, $t0, 2
/* 3B68D8 E00B4BE8 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 3B68DC E00B4BEC 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 3B68E0 E00B4BF0 314200FF */  andi      $v0, $t2, 0xff
/* 3B68E4 E00B4BF4 8C830000 */  lw        $v1, ($a0)
/* 3B68E8 E00B4BF8 01621025 */  or        $v0, $t3, $v0
/* 3B68EC E00B4BFC AD820000 */  sw        $v0, ($t4)
/* 3B68F0 E00B4C00 0060102D */  daddu     $v0, $v1, $zero
/* 3B68F4 E00B4C04 24630008 */  addiu     $v1, $v1, 8
/* 3B68F8 E00B4C08 AC830000 */  sw        $v1, ($a0)
/* 3B68FC E00B4C0C AC450000 */  sw        $a1, ($v0)
/* 3B6900 E00B4C10 AC400004 */  sw        $zero, 4($v0)
/* 3B6904 E00B4C14 24620008 */  addiu     $v0, $v1, 8
/* 3B6908 E00B4C18 AC820000 */  sw        $v0, ($a0)
/* 3B690C E00B4C1C 24020400 */  addiu     $v0, $zero, 0x400
/* 3B6910 E00B4C20 AC620004 */  sw        $v0, 4($v1)
/* 3B6914 E00B4C24 24620010 */  addiu     $v0, $v1, 0x10
/* 3B6918 E00B4C28 AC660000 */  sw        $a2, ($v1)
/* 3B691C E00B4C2C AC820000 */  sw        $v0, ($a0)
/* 3B6920 E00B4C30 24620018 */  addiu     $v0, $v1, 0x18
/* 3B6924 E00B4C34 AC670008 */  sw        $a3, 8($v1)
/* 3B6928 E00B4C38 8FAD00A8 */  lw        $t5, 0xa8($sp)
/* 3B692C E00B4C3C 3C05DE00 */  lui       $a1, 0xde00
/* 3B6930 E00B4C40 AC6D000C */  sw        $t5, 0xc($v1)
/* 3B6934 E00B4C44 AC820000 */  sw        $v0, ($a0)
/* 3B6938 E00B4C48 3C020900 */  lui       $v0, 0x900
/* 3B693C E00B4C4C 244204D8 */  addiu     $v0, $v0, 0x4d8
/* 3B6940 E00B4C50 AC620014 */  sw        $v0, 0x14($v1)
/* 3B6944 E00B4C54 24620020 */  addiu     $v0, $v1, 0x20
/* 3B6948 E00B4C58 AC650010 */  sw        $a1, 0x10($v1)
/* 3B694C E00B4C5C AC820000 */  sw        $v0, ($a0)
/* 3B6950 E00B4C60 AC690018 */  sw        $t1, 0x18($v1)
/* 3B6954 E00B4C64 25A201C0 */  addiu     $v0, $t5, 0x1c0
/* 3B6958 E00B4C68 AC62001C */  sw        $v0, 0x1c($v1)
/* 3B695C E00B4C6C 24620028 */  addiu     $v0, $v1, 0x28
/* 3B6960 E00B4C70 AC820000 */  sw        $v0, ($a0)
/* 3B6964 E00B4C74 3C020900 */  lui       $v0, 0x900
/* 3B6968 E00B4C78 24420538 */  addiu     $v0, $v0, 0x538
/* 3B696C E00B4C7C AC620024 */  sw        $v0, 0x24($v1)
/* 3B6970 E00B4C80 24620030 */  addiu     $v0, $v1, 0x30
/* 3B6974 E00B4C84 AC650020 */  sw        $a1, 0x20($v1)
/* 3B6978 E00B4C88 24050040 */  addiu     $a1, $zero, 0x40
/* 3B697C E00B4C8C AC820000 */  sw        $v0, ($a0)
/* 3B6980 E00B4C90 24620038 */  addiu     $v0, $v1, 0x38
/* 3B6984 E00B4C94 AC680028 */  sw        $t0, 0x28($v1)
/* 3B6988 E00B4C98 AC65002C */  sw        $a1, 0x2c($v1)
/* 3B698C E00B4C9C AC820000 */  sw        $v0, ($a0)
/* 3B6990 E00B4CA0 AC680030 */  sw        $t0, 0x30($v1)
/* 3B6994 E00B4CA4 AC650034 */  sw        $a1, 0x34($v1)
/* 3B6998 E00B4CA8 8FBF00D4 */  lw        $ra, 0xd4($sp)
/* 3B699C E00B4CAC 8FBE00D0 */  lw        $fp, 0xd0($sp)
/* 3B69A0 E00B4CB0 8FB700CC */  lw        $s7, 0xcc($sp)
/* 3B69A4 E00B4CB4 8FB600C8 */  lw        $s6, 0xc8($sp)
/* 3B69A8 E00B4CB8 8FB500C4 */  lw        $s5, 0xc4($sp)
/* 3B69AC E00B4CBC 8FB400C0 */  lw        $s4, 0xc0($sp)
/* 3B69B0 E00B4CC0 8FB300BC */  lw        $s3, 0xbc($sp)
/* 3B69B4 E00B4CC4 8FB200B8 */  lw        $s2, 0xb8($sp)
/* 3B69B8 E00B4CC8 8FB100B4 */  lw        $s1, 0xb4($sp)
/* 3B69BC E00B4CCC 8FB000B0 */  lw        $s0, 0xb0($sp)
/* 3B69C0 E00B4CD0 D7BE0100 */  ldc1      $f30, 0x100($sp)
/* 3B69C4 E00B4CD4 D7BC00F8 */  ldc1      $f28, 0xf8($sp)
/* 3B69C8 E00B4CD8 D7BA00F0 */  ldc1      $f26, 0xf0($sp)
/* 3B69CC E00B4CDC D7B800E8 */  ldc1      $f24, 0xe8($sp)
/* 3B69D0 E00B4CE0 D7B600E0 */  ldc1      $f22, 0xe0($sp)
/* 3B69D4 E00B4CE4 D7B400D8 */  ldc1      $f20, 0xd8($sp)
/* 3B69D8 E00B4CE8 03E00008 */  jr        $ra
/* 3B69DC E00B4CEC 27BD0108 */   addiu    $sp, $sp, 0x108
