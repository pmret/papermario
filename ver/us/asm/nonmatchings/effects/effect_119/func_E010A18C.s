.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E010A18C
/* 3E452C E010A18C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3E4530 E010A190 AFBF001C */  sw        $ra, 0x1c($sp)
/* 3E4534 E010A194 AFB20018 */  sw        $s2, 0x18($sp)
/* 3E4538 E010A198 AFB10014 */  sw        $s1, 0x14($sp)
/* 3E453C E010A19C AFB00010 */  sw        $s0, 0x10($sp)
/* 3E4540 E010A1A0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 3E4544 E010A1A4 8C830000 */  lw        $v1, ($a0)
/* 3E4548 E010A1A8 8C91000C */  lw        $s1, 0xc($a0)
/* 3E454C E010A1AC 30620010 */  andi      $v0, $v1, 0x10
/* 3E4550 E010A1B0 10400005 */  beqz      $v0, .LE010A1C8
/* 3E4554 E010A1B4 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3E4558 E010A1B8 00621024 */  and       $v0, $v1, $v0
/* 3E455C E010A1BC AC820000 */  sw        $v0, ($a0)
/* 3E4560 E010A1C0 24020010 */  addiu     $v0, $zero, 0x10
/* 3E4564 E010A1C4 AE22001C */  sw        $v0, 0x1c($s1)
.LE010A1C8:
/* 3E4568 E010A1C8 8E23001C */  lw        $v1, 0x1c($s1)
/* 3E456C E010A1CC 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3E4570 E010A1D0 10400002 */  beqz      $v0, .LE010A1DC
/* 3E4574 E010A1D4 2462FFFF */   addiu    $v0, $v1, -1
/* 3E4578 E010A1D8 AE22001C */  sw        $v0, 0x1c($s1)
.LE010A1DC:
/* 3E457C E010A1DC 8E220020 */  lw        $v0, 0x20($s1)
/* 3E4580 E010A1E0 8E25001C */  lw        $a1, 0x1c($s1)
/* 3E4584 E010A1E4 24420001 */  addiu     $v0, $v0, 1
/* 3E4588 E010A1E8 04A10005 */  bgez      $a1, .LE010A200
/* 3E458C E010A1EC AE220020 */   sw       $v0, 0x20($s1)
/* 3E4590 E010A1F0 0C080128 */  jal       shim_remove_effect
/* 3E4594 E010A1F4 00000000 */   nop
/* 3E4598 E010A1F8 08042921 */  j         .LE010A484
/* 3E459C E010A1FC 00000000 */   nop
.LE010A200:
/* 3E45A0 E010A200 0040902D */  daddu     $s2, $v0, $zero
/* 3E45A4 E010A204 28A20020 */  slti      $v0, $a1, 0x20
/* 3E45A8 E010A208 10400002 */  beqz      $v0, .LE010A214
/* 3E45AC E010A20C 000510C0 */   sll      $v0, $a1, 3
/* 3E45B0 E010A210 AE220030 */  sw        $v0, 0x30($s1)
.LE010A214:
/* 3E45B4 E010A214 8E23004C */  lw        $v1, 0x4c($s1)
/* 3E45B8 E010A218 24020001 */  addiu     $v0, $zero, 1
/* 3E45BC E010A21C 1462002F */  bne       $v1, $v0, .LE010A2DC
/* 3E45C0 E010A220 24020020 */   addiu    $v0, $zero, 0x20
/* 3E45C4 E010A224 C6260044 */  lwc1      $f6, 0x44($s1)
/* 3E45C8 E010A228 C6240048 */  lwc1      $f4, 0x48($s1)
/* 3E45CC E010A22C 46062101 */  sub.s     $f4, $f4, $f6
/* 3E45D0 E010A230 3C01E011 */  lui       $at, %hi(D_E010AF90)
/* 3E45D4 E010A234 D420AF90 */  ldc1      $f0, %lo(D_E010AF90)($at)
/* 3E45D8 E010A238 46002121 */  cvt.d.s   $f4, $f4
/* 3E45DC E010A23C 46202102 */  mul.d     $f4, $f4, $f0
/* 3E45E0 E010A240 00000000 */  nop
/* 3E45E4 E010A244 3C013F73 */  lui       $at, 0x3f73
/* 3E45E8 E010A248 34213333 */  ori       $at, $at, 0x3333
/* 3E45EC E010A24C 44818000 */  mtc1      $at, $f16
/* 3E45F0 E010A250 C62E0010 */  lwc1      $f14, 0x10($s1)
/* 3E45F4 E010A254 46107382 */  mul.s     $f14, $f14, $f16
/* 3E45F8 E010A258 00000000 */  nop
/* 3E45FC E010A25C C62C0018 */  lwc1      $f12, 0x18($s1)
/* 3E4600 E010A260 46106302 */  mul.s     $f12, $f12, $f16
/* 3E4604 E010A264 00000000 */  nop
/* 3E4608 E010A268 C62A0004 */  lwc1      $f10, 4($s1)
/* 3E460C E010A26C C6200010 */  lwc1      $f0, 0x10($s1)
/* 3E4610 E010A270 C6280008 */  lwc1      $f8, 8($s1)
/* 3E4614 E010A274 46005280 */  add.s     $f10, $f10, $f0
/* 3E4618 E010A278 C6200014 */  lwc1      $f0, 0x14($s1)
/* 3E461C E010A27C C622000C */  lwc1      $f2, 0xc($s1)
/* 3E4620 E010A280 46004200 */  add.s     $f8, $f8, $f0
/* 3E4624 E010A284 C6200018 */  lwc1      $f0, 0x18($s1)
/* 3E4628 E010A288 46001080 */  add.s     $f2, $f2, $f0
/* 3E462C E010A28C C6200014 */  lwc1      $f0, 0x14($s1)
/* 3E4630 E010A290 460031A1 */  cvt.d.s   $f6, $f6
/* 3E4634 E010A294 E62E0010 */  swc1      $f14, 0x10($s1)
/* 3E4638 E010A298 E62C0018 */  swc1      $f12, 0x18($s1)
/* 3E463C E010A29C 46100002 */  mul.s     $f0, $f0, $f16
/* 3E4640 E010A2A0 00000000 */  nop
/* 3E4644 E010A2A4 E62A0004 */  swc1      $f10, 4($s1)
/* 3E4648 E010A2A8 E6280008 */  swc1      $f8, 8($s1)
/* 3E464C E010A2AC E622000C */  swc1      $f2, 0xc($s1)
/* 3E4650 E010A2B0 3C01E011 */  lui       $at, %hi(D_E010AF98)
/* 3E4654 E010A2B4 D422AF98 */  ldc1      $f2, %lo(D_E010AF98)($at)
/* 3E4658 E010A2B8 46243180 */  add.d     $f6, $f6, $f4
/* 3E465C E010A2BC E6200014 */  swc1      $f0, 0x14($s1)
/* 3E4660 E010A2C0 46000021 */  cvt.d.s   $f0, $f0
/* 3E4664 E010A2C4 46220001 */  sub.d     $f0, $f0, $f2
/* 3E4668 E010A2C8 462031A0 */  cvt.s.d   $f6, $f6
/* 3E466C E010A2CC E6260044 */  swc1      $f6, 0x44($s1)
/* 3E4670 E010A2D0 46200020 */  cvt.s.d   $f0, $f0
/* 3E4674 E010A2D4 08042921 */  j         .LE010A484
/* 3E4678 E010A2D8 E6200014 */   swc1     $f0, 0x14($s1)
.LE010A2DC:
/* 3E467C E010A2DC 00521023 */  subu      $v0, $v0, $s2
/* 3E4680 E010A2E0 4482A000 */  mtc1      $v0, $f20
/* 3E4684 E010A2E4 00000000 */  nop
/* 3E4688 E010A2E8 4680A520 */  cvt.s.w   $f20, $f20
/* 3E468C E010A2EC 32440003 */  andi      $a0, $s2, 3
/* 3E4690 E010A2F0 00048080 */  sll       $s0, $a0, 2
/* 3E4694 E010A2F4 02308021 */  addu      $s0, $s1, $s0
/* 3E4698 E010A2F8 00121840 */  sll       $v1, $s2, 1
/* 3E469C E010A2FC C6200010 */  lwc1      $f0, 0x10($s1)
/* 3E46A0 E010A300 00721821 */  addu      $v1, $v1, $s2
/* 3E46A4 E010A304 46140002 */  mul.s     $f0, $f0, $f20
/* 3E46A8 E010A308 00000000 */  nop
/* 3E46AC E010A30C 00031100 */  sll       $v0, $v1, 4
/* 3E46B0 E010A310 00431023 */  subu      $v0, $v0, $v1
/* 3E46B4 E010A314 C6220004 */  lwc1      $f2, 4($s1)
/* 3E46B8 E010A318 00021040 */  sll       $v0, $v0, 1
/* 3E46BC E010A31C 46001081 */  sub.s     $f2, $f2, $f0
/* 3E46C0 E010A320 00021143 */  sra       $v0, $v0, 5
/* 3E46C4 E010A324 44826000 */  mtc1      $v0, $f12
/* 3E46C8 E010A328 00000000 */  nop
/* 3E46CC E010A32C 46806320 */  cvt.s.w   $f12, $f12
/* 3E46D0 E010A330 0C080140 */  jal       shim_sin_deg
/* 3E46D4 E010A334 E6020050 */   swc1     $f2, 0x50($s0)
/* 3E46D8 E010A338 C6260014 */  lwc1      $f6, 0x14($s1)
/* 3E46DC E010A33C 46143182 */  mul.s     $f6, $f6, $f20
/* 3E46E0 E010A340 00000000 */  nop
/* 3E46E4 E010A344 3C0142A0 */  lui       $at, 0x42a0
/* 3E46E8 E010A348 44812000 */  mtc1      $at, $f4
/* 3E46EC E010A34C 00000000 */  nop
/* 3E46F0 E010A350 46040002 */  mul.s     $f0, $f0, $f4
/* 3E46F4 E010A354 00000000 */  nop
/* 3E46F8 E010A358 C6220008 */  lwc1      $f2, 8($s1)
/* 3E46FC E010A35C 46061081 */  sub.s     $f2, $f2, $f6
/* 3E4700 E010A360 46002101 */  sub.s     $f4, $f4, $f0
/* 3E4704 E010A364 46041081 */  sub.s     $f2, $f2, $f4
/* 3E4708 E010A368 E6020060 */  swc1      $f2, 0x60($s0)
/* 3E470C E010A36C C6200018 */  lwc1      $f0, 0x18($s1)
/* 3E4710 E010A370 46140002 */  mul.s     $f0, $f0, $f20
/* 3E4714 E010A374 00000000 */  nop
/* 3E4718 E010A378 C622000C */  lwc1      $f2, 0xc($s1)
/* 3E471C E010A37C 46001081 */  sub.s     $f2, $f2, $f0
/* 3E4720 E010A380 2404000A */  addiu     $a0, $zero, 0xa
/* 3E4724 E010A384 0C080138 */  jal       shim_rand_int
/* 3E4728 E010A388 E6020070 */   swc1     $f2, 0x70($s0)
/* 3E472C E010A38C 2442FFFB */  addiu     $v0, $v0, -5
/* 3E4730 E010A390 3C013DCC */  lui       $at, 0x3dcc
/* 3E4734 E010A394 3421CCCD */  ori       $at, $at, 0xcccd
/* 3E4738 E010A398 4481A000 */  mtc1      $at, $f20
/* 3E473C E010A39C 44820000 */  mtc1      $v0, $f0
/* 3E4740 E010A3A0 00000000 */  nop
/* 3E4744 E010A3A4 46800020 */  cvt.s.w   $f0, $f0
/* 3E4748 E010A3A8 46140002 */  mul.s     $f0, $f0, $f20
/* 3E474C E010A3AC 00000000 */  nop
/* 3E4750 E010A3B0 2404000A */  addiu     $a0, $zero, 0xa
/* 3E4754 E010A3B4 0C080138 */  jal       shim_rand_int
/* 3E4758 E010A3B8 E6000080 */   swc1     $f0, 0x80($s0)
/* 3E475C E010A3BC 2442FFFB */  addiu     $v0, $v0, -5
/* 3E4760 E010A3C0 44820000 */  mtc1      $v0, $f0
/* 3E4764 E010A3C4 00000000 */  nop
/* 3E4768 E010A3C8 46800020 */  cvt.s.w   $f0, $f0
/* 3E476C E010A3CC 46140002 */  mul.s     $f0, $f0, $f20
/* 3E4770 E010A3D0 00000000 */  nop
/* 3E4774 E010A3D4 2404000A */  addiu     $a0, $zero, 0xa
/* 3E4778 E010A3D8 0C080138 */  jal       shim_rand_int
/* 3E477C E010A3DC E6000090 */   swc1     $f0, 0x90($s0)
/* 3E4780 E010A3E0 0000202D */  daddu     $a0, $zero, $zero
/* 3E4784 E010A3E4 2442FFFB */  addiu     $v0, $v0, -5
/* 3E4788 E010A3E8 44820000 */  mtc1      $v0, $f0
/* 3E478C E010A3EC 00000000 */  nop
/* 3E4790 E010A3F0 46800020 */  cvt.s.w   $f0, $f0
/* 3E4794 E010A3F4 46140002 */  mul.s     $f0, $f0, $f20
/* 3E4798 E010A3F8 00000000 */  nop
/* 3E479C E010A3FC 2A45001B */  slti      $a1, $s2, 0x1b
/* 3E47A0 E010A400 3C01E011 */  lui       $at, %hi(D_E010AFA0)
/* 3E47A4 E010A404 D42AAFA0 */  ldc1      $f10, %lo(D_E010AFA0)($at)
/* 3E47A8 E010A408 3C01C47A */  lui       $at, 0xc47a
/* 3E47AC E010A40C 44816000 */  mtc1      $at, $f12
/* 3E47B0 E010A410 0220182D */  daddu     $v1, $s1, $zero
/* 3E47B4 E010A414 E60000A0 */  swc1      $f0, 0xa0($s0)
.LE010A418:
/* 3E47B8 E010A418 C4660050 */  lwc1      $f6, 0x50($v1)
/* 3E47BC E010A41C C4600080 */  lwc1      $f0, 0x80($v1)
/* 3E47C0 E010A420 C4640070 */  lwc1      $f4, 0x70($v1)
/* 3E47C4 E010A424 46003180 */  add.s     $f6, $f6, $f0
/* 3E47C8 E010A428 C46200A0 */  lwc1      $f2, 0xa0($v1)
/* 3E47CC E010A42C C4680060 */  lwc1      $f8, 0x60($v1)
/* 3E47D0 E010A430 46022100 */  add.s     $f4, $f4, $f2
/* 3E47D4 E010A434 C4600090 */  lwc1      $f0, 0x90($v1)
/* 3E47D8 E010A438 46004200 */  add.s     $f8, $f8, $f0
/* 3E47DC E010A43C 46000021 */  cvt.d.s   $f0, $f0
/* 3E47E0 E010A440 462A0001 */  sub.d     $f0, $f0, $f10
/* 3E47E4 E010A444 E4660050 */  swc1      $f6, 0x50($v1)
/* 3E47E8 E010A448 E4640070 */  swc1      $f4, 0x70($v1)
/* 3E47EC E010A44C 46200020 */  cvt.s.d   $f0, $f0
/* 3E47F0 E010A450 E4680060 */  swc1      $f8, 0x60($v1)
/* 3E47F4 E010A454 14A00002 */  bnez      $a1, .LE010A460
/* 3E47F8 E010A458 E4600090 */   swc1     $f0, 0x90($v1)
/* 3E47FC E010A45C E46C0060 */  swc1      $f12, 0x60($v1)
.LE010A460:
/* 3E4800 E010A460 24840001 */  addiu     $a0, $a0, 1
/* 3E4804 E010A464 28820004 */  slti      $v0, $a0, 4
/* 3E4808 E010A468 1440FFEB */  bnez      $v0, .LE010A418
/* 3E480C E010A46C 24630004 */   addiu    $v1, $v1, 4
/* 3E4810 E010A470 2A420020 */  slti      $v0, $s2, 0x20
/* 3E4814 E010A474 14400003 */  bnez      $v0, .LE010A484
/* 3E4818 E010A478 24020001 */   addiu    $v0, $zero, 1
/* 3E481C E010A47C AE22004C */  sw        $v0, 0x4c($s1)
/* 3E4820 E010A480 AE220020 */  sw        $v0, 0x20($s1)
.LE010A484:
/* 3E4824 E010A484 8FBF001C */  lw        $ra, 0x1c($sp)
/* 3E4828 E010A488 8FB20018 */  lw        $s2, 0x18($sp)
/* 3E482C E010A48C 8FB10014 */  lw        $s1, 0x14($sp)
/* 3E4830 E010A490 8FB00010 */  lw        $s0, 0x10($sp)
/* 3E4834 E010A494 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 3E4838 E010A498 03E00008 */  jr        $ra
/* 3E483C E010A49C 27BD0028 */   addiu    $sp, $sp, 0x28
