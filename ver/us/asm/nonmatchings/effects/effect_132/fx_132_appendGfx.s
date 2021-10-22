.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_132_appendGfx
/* 412BF4 E01244C4 27BDFEE0 */  addiu     $sp, $sp, -0x120
/* 412BF8 E01244C8 3C06DB06 */  lui       $a2, 0xdb06
/* 412BFC E01244CC 34C60024 */  ori       $a2, $a2, 0x24
/* 412C00 E01244D0 AFB000E0 */  sw        $s0, 0xe0($sp)
/* 412C04 E01244D4 27B00098 */  addiu     $s0, $sp, 0x98
/* 412C08 E01244D8 AFA40120 */  sw        $a0, 0x120($sp)
/* 412C0C E01244DC 0200202D */  daddu     $a0, $s0, $zero
/* 412C10 E01244E0 AFB300EC */  sw        $s3, 0xec($sp)
/* 412C14 E01244E4 0000982D */  daddu     $s3, $zero, $zero
/* 412C18 E01244E8 AFB400F0 */  sw        $s4, 0xf0($sp)
/* 412C1C E01244EC 3C14800A */  lui       $s4, %hi(gMasterGfxPos)
/* 412C20 E01244F0 2694A66C */  addiu     $s4, $s4, %lo(gMasterGfxPos)
/* 412C24 E01244F4 3C02E700 */  lui       $v0, 0xe700
/* 412C28 E01244F8 AFBF0104 */  sw        $ra, 0x104($sp)
/* 412C2C E01244FC AFBE0100 */  sw        $fp, 0x100($sp)
/* 412C30 E0124500 AFB700FC */  sw        $s7, 0xfc($sp)
/* 412C34 E0124504 AFB600F8 */  sw        $s6, 0xf8($sp)
/* 412C38 E0124508 AFB500F4 */  sw        $s5, 0xf4($sp)
/* 412C3C E012450C AFB200E8 */  sw        $s2, 0xe8($sp)
/* 412C40 E0124510 AFB100E4 */  sw        $s1, 0xe4($sp)
/* 412C44 E0124514 F7B80118 */  sdc1      $f24, 0x118($sp)
/* 412C48 E0124518 F7B60110 */  sdc1      $f22, 0x110($sp)
/* 412C4C E012451C F7B40108 */  sdc1      $f20, 0x108($sp)
/* 412C50 E0124520 8E830000 */  lw        $v1, ($s4)
/* 412C54 E0124524 8FA90120 */  lw        $t1, 0x120($sp)
/* 412C58 E0124528 0060282D */  daddu     $a1, $v1, $zero
/* 412C5C E012452C 8D31000C */  lw        $s1, 0xc($t1)
/* 412C60 E0124530 24630008 */  addiu     $v1, $v1, 8
/* 412C64 E0124534 AE830000 */  sw        $v1, ($s4)
/* 412C68 E0124538 ACA20000 */  sw        $v0, ($a1)
/* 412C6C E012453C 24620008 */  addiu     $v0, $v1, 8
/* 412C70 E0124540 ACA00004 */  sw        $zero, 4($a1)
/* 412C74 E0124544 AE820000 */  sw        $v0, ($s4)
/* 412C78 E0124548 AC660000 */  sw        $a2, ($v1)
/* 412C7C E012454C 8D250010 */  lw        $a1, 0x10($t1)
/* 412C80 E0124550 24620010 */  addiu     $v0, $v1, 0x10
/* 412C84 E0124554 AE820000 */  sw        $v0, ($s4)
/* 412C88 E0124558 8CA5001C */  lw        $a1, 0x1c($a1)
/* 412C8C E012455C 3C02DE00 */  lui       $v0, 0xde00
/* 412C90 E0124560 AC620008 */  sw        $v0, 8($v1)
/* 412C94 E0124564 3C020900 */  lui       $v0, 0x900
/* 412C98 E0124568 24420F20 */  addiu     $v0, $v0, 0xf20
/* 412C9C E012456C AC62000C */  sw        $v0, 0xc($v1)
/* 412CA0 E0124570 3C028000 */  lui       $v0, 0x8000
/* 412CA4 E0124574 00A22821 */  addu      $a1, $a1, $v0
/* 412CA8 E0124578 AC650004 */  sw        $a1, 4($v1)
/* 412CAC E012457C 8E250004 */  lw        $a1, 4($s1)
/* 412CB0 E0124580 8E260008 */  lw        $a2, 8($s1)
/* 412CB4 E0124584 8E27000C */  lw        $a3, 0xc($s1)
/* 412CB8 E0124588 8E220020 */  lw        $v0, 0x20($s1)
/* 412CBC E012458C 2631002C */  addiu     $s1, $s1, 0x2c
/* 412CC0 E0124590 2442FFFF */  addiu     $v0, $v0, -1
/* 412CC4 E0124594 00021840 */  sll       $v1, $v0, 1
/* 412CC8 E0124598 00621821 */  addu      $v1, $v1, $v0
/* 412CCC E012459C 0C080108 */  jal       shim_guTranslateF
/* 412CD0 E01245A0 AFA300D8 */   sw       $v1, 0xd8($sp)
/* 412CD4 E01245A4 27B20058 */  addiu     $s2, $sp, 0x58
/* 412CD8 E01245A8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 412CDC E01245AC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 412CE0 E01245B0 44800000 */  mtc1      $zero, $f0
/* 412CE4 E01245B4 00031080 */  sll       $v0, $v1, 2
/* 412CE8 E01245B8 00431021 */  addu      $v0, $v0, $v1
/* 412CEC E01245BC 00021080 */  sll       $v0, $v0, 2
/* 412CF0 E01245C0 00431023 */  subu      $v0, $v0, $v1
/* 412CF4 E01245C4 000218C0 */  sll       $v1, $v0, 3
/* 412CF8 E01245C8 00431021 */  addu      $v0, $v0, $v1
/* 412CFC E01245CC 000210C0 */  sll       $v0, $v0, 3
/* 412D00 E01245D0 44060000 */  mfc1      $a2, $f0
/* 412D04 E01245D4 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 412D08 E01245D8 00220821 */  addu      $at, $at, $v0
/* 412D0C E01245DC C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 412D10 E01245E0 3C073F80 */  lui       $a3, 0x3f80
/* 412D14 E01245E4 46000007 */  neg.s     $f0, $f0
/* 412D18 E01245E8 44050000 */  mfc1      $a1, $f0
/* 412D1C E01245EC 0240202D */  daddu     $a0, $s2, $zero
/* 412D20 E01245F0 0C080104 */  jal       shim_guRotateF
/* 412D24 E01245F4 AFA60010 */   sw       $a2, 0x10($sp)
/* 412D28 E01245F8 0240202D */  daddu     $a0, $s2, $zero
/* 412D2C E01245FC 0200282D */  daddu     $a1, $s0, $zero
/* 412D30 E0124600 0C080114 */  jal       shim_guMtxCatF
/* 412D34 E0124604 00A0302D */   daddu    $a2, $a1, $zero
/* 412D38 E0124608 3C013F33 */  lui       $at, 0x3f33
/* 412D3C E012460C 34213333 */  ori       $at, $at, 0x3333
/* 412D40 E0124610 4481A000 */  mtc1      $at, $f20
/* 412D44 E0124614 8FA90120 */  lw        $t1, 0x120($sp)
/* 412D48 E0124618 3C013FB3 */  lui       $at, 0x3fb3
/* 412D4C E012461C 34213333 */  ori       $at, $at, 0x3333
/* 412D50 E0124620 4481B000 */  mtc1      $at, $f22
/* 412D54 E0124624 8D220008 */  lw        $v0, 8($t1)
/* 412D58 E0124628 2442FFFF */  addiu     $v0, $v0, -1
/* 412D5C E012462C 18400083 */  blez      $v0, .LE012483C
/* 412D60 E0124630 4600A606 */   mov.s    $f24, $f20
/* 412D64 E0124634 0240B02D */  daddu     $s6, $s2, $zero
/* 412D68 E0124638 3C178007 */  lui       $s7, %hi(gMatrixListPos)
/* 412D6C E012463C 26F741F0 */  addiu     $s7, $s7, %lo(gMatrixListPos)
/* 412D70 E0124640 3C150001 */  lui       $s5, 1
/* 412D74 E0124644 36B51630 */  ori       $s5, $s5, 0x1630
/* 412D78 E0124648 0280902D */  daddu     $s2, $s4, $zero
/* 412D7C E012464C 26310024 */  addiu     $s1, $s1, 0x24
/* 412D80 E0124650 8FA900D8 */  lw        $t1, 0xd8($sp)
/* 412D84 E0124654 3C1EE012 */  lui       $fp, %hi(D_E0124BC0)
/* 412D88 E0124658 27DE4BC0 */  addiu     $fp, $fp, %lo(D_E0124BC0)
/* 412D8C E012465C 013E8021 */  addu      $s0, $t1, $fp
.LE0124660:
/* 412D90 E0124660 8E340004 */  lw        $s4, 4($s1)
/* 412D94 E0124664 0680006E */  bltz      $s4, .LE0124820
/* 412D98 E0124668 00000000 */   nop
/* 412D9C E012466C 8E25FFE0 */  lw        $a1, -0x20($s1)
/* 412DA0 E0124670 8E26FFE4 */  lw        $a2, -0x1c($s1)
/* 412DA4 E0124674 8E27FFE8 */  lw        $a3, -0x18($s1)
/* 412DA8 E0124678 0C080108 */  jal       shim_guTranslateF
/* 412DAC E012467C 02C0202D */   daddu    $a0, $s6, $zero
/* 412DB0 E0124680 02C0202D */  daddu     $a0, $s6, $zero
/* 412DB4 E0124684 27A50098 */  addiu     $a1, $sp, 0x98
/* 412DB8 E0124688 C6200000 */  lwc1      $f0, ($s1)
/* 412DBC E012468C 27A60018 */  addiu     $a2, $sp, 0x18
/* 412DC0 E0124690 E7A00080 */  swc1      $f0, 0x80($sp)
/* 412DC4 E0124694 E7A0006C */  swc1      $f0, 0x6c($sp)
/* 412DC8 E0124698 0C080114 */  jal       shim_guMtxCatF
/* 412DCC E012469C E7A00058 */   swc1     $f0, 0x58($sp)
/* 412DD0 E01246A0 27A40018 */  addiu     $a0, $sp, 0x18
/* 412DD4 E01246A4 96E50000 */  lhu       $a1, ($s7)
/* 412DD8 E01246A8 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 412DDC E01246AC 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 412DE0 E01246B0 00052980 */  sll       $a1, $a1, 6
/* 412DE4 E01246B4 00B52821 */  addu      $a1, $a1, $s5
/* 412DE8 E01246B8 0C080118 */  jal       shim_guMtxF2L
/* 412DEC E01246BC 00452821 */   addu     $a1, $v0, $a1
/* 412DF0 E01246C0 27C20024 */  addiu     $v0, $fp, 0x24
/* 412DF4 E01246C4 0202102A */  slt       $v0, $s0, $v0
/* 412DF8 E01246C8 50400001 */  beql      $v0, $zero, .LE01246D0
/* 412DFC E01246CC 03C0802D */   daddu    $s0, $fp, $zero
.LE01246D0:
/* 412E00 E01246D0 92020000 */  lbu       $v0, ($s0)
/* 412E04 E01246D4 44822000 */  mtc1      $v0, $f4
/* 412E08 E01246D8 00000000 */  nop
/* 412E0C E01246DC 46802120 */  cvt.s.w   $f4, $f4
/* 412E10 E01246E0 46162102 */  mul.s     $f4, $f4, $f22
/* 412E14 E01246E4 00000000 */  nop
/* 412E18 E01246E8 26100001 */  addiu     $s0, $s0, 1
/* 412E1C E01246EC 92020000 */  lbu       $v0, ($s0)
/* 412E20 E01246F0 44821000 */  mtc1      $v0, $f2
/* 412E24 E01246F4 00000000 */  nop
/* 412E28 E01246F8 468010A0 */  cvt.s.w   $f2, $f2
/* 412E2C E01246FC 46181082 */  mul.s     $f2, $f2, $f24
/* 412E30 E0124700 00000000 */  nop
/* 412E34 E0124704 26100001 */  addiu     $s0, $s0, 1
/* 412E38 E0124708 92020000 */  lbu       $v0, ($s0)
/* 412E3C E012470C 44820000 */  mtc1      $v0, $f0
/* 412E40 E0124710 00000000 */  nop
/* 412E44 E0124714 46800020 */  cvt.s.w   $f0, $f0
/* 412E48 E0124718 46140002 */  mul.s     $f0, $f0, $f20
/* 412E4C E012471C 00000000 */  nop
/* 412E50 E0124720 4600218D */  trunc.w.s $f6, $f4
/* 412E54 E0124724 44033000 */  mfc1      $v1, $f6
/* 412E58 E0124728 00000000 */  nop
/* 412E5C E012472C 28620100 */  slti      $v0, $v1, 0x100
/* 412E60 E0124730 4600118D */  trunc.w.s $f6, $f2
/* 412E64 E0124734 44073000 */  mfc1      $a3, $f6
/* 412E68 E0124738 4600018D */  trunc.w.s $f6, $f0
/* 412E6C E012473C 44083000 */  mfc1      $t0, $f6
/* 412E70 E0124740 14400002 */  bnez      $v0, .LE012474C
/* 412E74 E0124744 26100001 */   addiu    $s0, $s0, 1
/* 412E78 E0124748 240300FF */  addiu     $v1, $zero, 0xff
.LE012474C:
/* 412E7C E012474C 28E20100 */  slti      $v0, $a3, 0x100
/* 412E80 E0124750 50400001 */  beql      $v0, $zero, .LE0124758
/* 412E84 E0124754 240700FF */   addiu    $a3, $zero, 0xff
.LE0124758:
/* 412E88 E0124758 29020100 */  slti      $v0, $t0, 0x100
/* 412E8C E012475C 50400001 */  beql      $v0, $zero, .LE0124764
/* 412E90 E0124760 240800FF */   addiu    $t0, $zero, 0xff
.LE0124764:
/* 412E94 E0124764 3C06D838 */  lui       $a2, 0xd838
/* 412E98 E0124768 34C60002 */  ori       $a2, $a2, 2
/* 412E9C E012476C 3C02FA00 */  lui       $v0, 0xfa00
/* 412EA0 E0124770 00031E00 */  sll       $v1, $v1, 0x18
/* 412EA4 E0124774 8E440000 */  lw        $a0, ($s2)
/* 412EA8 E0124778 3C09E012 */  lui       $t1, %hi(D_E01248A0)
/* 412EAC E012477C 252948A0 */  addiu     $t1, $t1, %lo(D_E01248A0)
/* 412EB0 E0124780 0080282D */  daddu     $a1, $a0, $zero
/* 412EB4 E0124784 24840008 */  addiu     $a0, $a0, 8
/* 412EB8 E0124788 AE440000 */  sw        $a0, ($s2)
/* 412EBC E012478C ACA20000 */  sw        $v0, ($a1)
/* 412EC0 E0124790 30E200FF */  andi      $v0, $a3, 0xff
/* 412EC4 E0124794 00021400 */  sll       $v0, $v0, 0x10
/* 412EC8 E0124798 00621825 */  or        $v1, $v1, $v0
/* 412ECC E012479C 310200FF */  andi      $v0, $t0, 0xff
/* 412ED0 E01247A0 00021200 */  sll       $v0, $v0, 8
/* 412ED4 E01247A4 00621825 */  or        $v1, $v1, $v0
/* 412ED8 E01247A8 346300FF */  ori       $v1, $v1, 0xff
/* 412EDC E01247AC 24820008 */  addiu     $v0, $a0, 8
/* 412EE0 E01247B0 ACA30004 */  sw        $v1, 4($a1)
/* 412EE4 E01247B4 AE420000 */  sw        $v0, ($s2)
/* 412EE8 E01247B8 96E20000 */  lhu       $v0, ($s7)
/* 412EEC E01247BC 3C03DA38 */  lui       $v1, 0xda38
/* 412EF0 E01247C0 AC830000 */  sw        $v1, ($a0)
/* 412EF4 E01247C4 24430001 */  addiu     $v1, $v0, 1
/* 412EF8 E01247C8 3042FFFF */  andi      $v0, $v0, 0xffff
/* 412EFC E01247CC 00021180 */  sll       $v0, $v0, 6
/* 412F00 E01247D0 A6E30000 */  sh        $v1, ($s7)
/* 412F04 E01247D4 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 412F08 E01247D8 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 412F0C E01247DC 00551021 */  addu      $v0, $v0, $s5
/* 412F10 E01247E0 00621821 */  addu      $v1, $v1, $v0
/* 412F14 E01247E4 24820010 */  addiu     $v0, $a0, 0x10
/* 412F18 E01247E8 AC830004 */  sw        $v1, 4($a0)
/* 412F1C E01247EC AE420000 */  sw        $v0, ($s2)
/* 412F20 E01247F0 3C02DE00 */  lui       $v0, 0xde00
/* 412F24 E01247F4 AC820008 */  sw        $v0, 8($a0)
/* 412F28 E01247F8 32820007 */  andi      $v0, $s4, 7
/* 412F2C E01247FC 00021080 */  sll       $v0, $v0, 2
/* 412F30 E0124800 00491021 */  addu      $v0, $v0, $t1
/* 412F34 E0124804 8C430000 */  lw        $v1, ($v0)
/* 412F38 E0124808 24820018 */  addiu     $v0, $a0, 0x18
/* 412F3C E012480C AE420000 */  sw        $v0, ($s2)
/* 412F40 E0124810 24020040 */  addiu     $v0, $zero, 0x40
/* 412F44 E0124814 AC860010 */  sw        $a2, 0x10($a0)
/* 412F48 E0124818 AC820014 */  sw        $v0, 0x14($a0)
/* 412F4C E012481C AC83000C */  sw        $v1, 0xc($a0)
.LE0124820:
/* 412F50 E0124820 8FA90120 */  lw        $t1, 0x120($sp)
/* 412F54 E0124824 26730001 */  addiu     $s3, $s3, 1
/* 412F58 E0124828 8D220008 */  lw        $v0, 8($t1)
/* 412F5C E012482C 2442FFFF */  addiu     $v0, $v0, -1
/* 412F60 E0124830 0262102A */  slt       $v0, $s3, $v0
/* 412F64 E0124834 1440FF8A */  bnez      $v0, .LE0124660
/* 412F68 E0124838 2631002C */   addiu    $s1, $s1, 0x2c
.LE012483C:
/* 412F6C E012483C 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 412F70 E0124840 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 412F74 E0124844 8C620000 */  lw        $v0, ($v1)
/* 412F78 E0124848 0040202D */  daddu     $a0, $v0, $zero
/* 412F7C E012484C 24420008 */  addiu     $v0, $v0, 8
/* 412F80 E0124850 AC620000 */  sw        $v0, ($v1)
/* 412F84 E0124854 3C02E700 */  lui       $v0, 0xe700
/* 412F88 E0124858 AC820000 */  sw        $v0, ($a0)
/* 412F8C E012485C AC800004 */  sw        $zero, 4($a0)
/* 412F90 E0124860 8FBF0104 */  lw        $ra, 0x104($sp)
/* 412F94 E0124864 8FBE0100 */  lw        $fp, 0x100($sp)
/* 412F98 E0124868 8FB700FC */  lw        $s7, 0xfc($sp)
/* 412F9C E012486C 8FB600F8 */  lw        $s6, 0xf8($sp)
/* 412FA0 E0124870 8FB500F4 */  lw        $s5, 0xf4($sp)
/* 412FA4 E0124874 8FB400F0 */  lw        $s4, 0xf0($sp)
/* 412FA8 E0124878 8FB300EC */  lw        $s3, 0xec($sp)
/* 412FAC E012487C 8FB200E8 */  lw        $s2, 0xe8($sp)
/* 412FB0 E0124880 8FB100E4 */  lw        $s1, 0xe4($sp)
/* 412FB4 E0124884 8FB000E0 */  lw        $s0, 0xe0($sp)
/* 412FB8 E0124888 D7B80118 */  ldc1      $f24, 0x118($sp)
/* 412FBC E012488C D7B60110 */  ldc1      $f22, 0x110($sp)
/* 412FC0 E0124890 D7B40108 */  ldc1      $f20, 0x108($sp)
/* 412FC4 E0124894 03E00008 */  jr        $ra
/* 412FC8 E0124898 27BD0120 */   addiu    $sp, $sp, 0x120
/* 412FCC E012489C 00000000 */  nop
