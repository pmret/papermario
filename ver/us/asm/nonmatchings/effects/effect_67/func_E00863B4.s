.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00863B4
/* 389C04 E00863B4 27BDFF00 */  addiu     $sp, $sp, -0x100
/* 389C08 E00863B8 AFBF00EC */  sw        $ra, 0xec($sp)
/* 389C0C E00863BC AFBE00E8 */  sw        $fp, 0xe8($sp)
/* 389C10 E00863C0 AFB700E4 */  sw        $s7, 0xe4($sp)
/* 389C14 E00863C4 AFB600E0 */  sw        $s6, 0xe0($sp)
/* 389C18 E00863C8 AFB500DC */  sw        $s5, 0xdc($sp)
/* 389C1C E00863CC AFB400D8 */  sw        $s4, 0xd8($sp)
/* 389C20 E00863D0 AFB300D4 */  sw        $s3, 0xd4($sp)
/* 389C24 E00863D4 AFB200D0 */  sw        $s2, 0xd0($sp)
/* 389C28 E00863D8 AFB100CC */  sw        $s1, 0xcc($sp)
/* 389C2C E00863DC AFB000C8 */  sw        $s0, 0xc8($sp)
/* 389C30 E00863E0 F7B600F8 */  sdc1      $f22, 0xf8($sp)
/* 389C34 E00863E4 F7B400F0 */  sdc1      $f20, 0xf0($sp)
/* 389C38 E00863E8 AFA40100 */  sw        $a0, 0x100($sp)
/* 389C3C E00863EC 8C94000C */  lw        $s4, 0xc($a0)
/* 389C40 E00863F0 3C0140A0 */  lui       $at, 0x40a0
/* 389C44 E00863F4 44810000 */  mtc1      $at, $f0
/* 389C48 E00863F8 C6820038 */  lwc1      $f2, 0x38($s4)
/* 389C4C E00863FC 46001502 */  mul.s     $f20, $f2, $f0
/* 389C50 E0086400 00000000 */  nop
/* 389C54 E0086404 4600A10D */  trunc.w.s $f4, $f20
/* 389C58 E0086408 E7A400A4 */  swc1      $f4, 0xa4($sp)
/* 389C5C E008640C 8FA900A4 */  lw        $t1, 0xa4($sp)
/* 389C60 E0086410 8E960034 */  lw        $s6, 0x34($s4)
/* 389C64 E0086414 8E950000 */  lw        $s5, ($s4)
/* 389C68 E0086418 29220005 */  slti      $v0, $t1, 5
/* 389C6C E008641C 10400191 */  beqz      $v0, .LE0086A64
/* 389C70 E0086420 3C08DB06 */   lui      $t0, 0xdb06
/* 389C74 E0086424 35080024 */  ori       $t0, $t0, 0x24
/* 389C78 E0086428 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 389C7C E008642C 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 389C80 E0086430 3C02E700 */  lui       $v0, 0xe700
/* 389C84 E0086434 8E260000 */  lw        $a2, ($s1)
/* 389C88 E0086438 44800000 */  mtc1      $zero, $f0
/* 389C8C E008643C 00C0182D */  daddu     $v1, $a2, $zero
/* 389C90 E0086440 24C60008 */  addiu     $a2, $a2, 8
/* 389C94 E0086444 AC620000 */  sw        $v0, ($v1)
/* 389C98 E0086448 AC600004 */  sw        $zero, 4($v1)
/* 389C9C E008644C ACC80000 */  sw        $t0, ($a2)
/* 389CA0 E0086450 8FA90100 */  lw        $t1, 0x100($sp)
/* 389CA4 E0086454 3C088000 */  lui       $t0, 0x8000
/* 389CA8 E0086458 8D220010 */  lw        $v0, 0x10($t1)
/* 389CAC E008645C 44050000 */  mfc1      $a1, $f0
/* 389CB0 E0086460 8C42001C */  lw        $v0, 0x1c($v0)
/* 389CB4 E0086464 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 389CB8 E0086468 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 389CBC E008646C 00481021 */  addu      $v0, $v0, $t0
/* 389CC0 E0086470 ACC20004 */  sw        $v0, 4($a2)
/* 389CC4 E0086474 00031080 */  sll       $v0, $v1, 2
/* 389CC8 E0086478 00431021 */  addu      $v0, $v0, $v1
/* 389CCC E008647C 00021080 */  sll       $v0, $v0, 2
/* 389CD0 E0086480 00431023 */  subu      $v0, $v0, $v1
/* 389CD4 E0086484 000218C0 */  sll       $v1, $v0, 3
/* 389CD8 E0086488 00431021 */  addu      $v0, $v0, $v1
/* 389CDC E008648C 000210C0 */  sll       $v0, $v0, 3
/* 389CE0 E0086490 C6800028 */  lwc1      $f0, 0x28($s4)
/* 389CE4 E0086494 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 389CE8 E0086498 00220821 */  addu      $at, $at, $v0
/* 389CEC E008649C C4221DEC */  lwc1      $f2, %lo(gCameras+0x6C)($at)
/* 389CF0 E00864A0 27A40020 */  addiu     $a0, $sp, 0x20
/* 389CF4 E00864A4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 389CF8 E00864A8 C6800004 */  lwc1      $f0, 4($s4)
/* 389CFC E00864AC 3C130001 */  lui       $s3, 1
/* 389D00 E00864B0 AE260000 */  sw        $a2, ($s1)
/* 389D04 E00864B4 24C60008 */  addiu     $a2, $a2, 8
/* 389D08 E00864B8 E7A00014 */  swc1      $f0, 0x14($sp)
/* 389D0C E00864BC C6800008 */  lwc1      $f0, 8($s4)
/* 389D10 E00864C0 46001087 */  neg.s     $f2, $f2
/* 389D14 E00864C4 AE260000 */  sw        $a2, ($s1)
/* 389D18 E00864C8 44061000 */  mfc1      $a2, $f2
/* 389D1C E00864CC 36731630 */  ori       $s3, $s3, 0x1630
/* 389D20 E00864D0 E7A00018 */  swc1      $f0, 0x18($sp)
/* 389D24 E00864D4 C680000C */  lwc1      $f0, 0xc($s4)
/* 389D28 E00864D8 00A0382D */  daddu     $a3, $a1, $zero
/* 389D2C E00864DC 0C080180 */  jal       func_E0200600
/* 389D30 E00864E0 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 389D34 E00864E4 27A40020 */  addiu     $a0, $sp, 0x20
/* 389D38 E00864E8 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 389D3C E00864EC 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 389D40 E00864F0 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 389D44 E00864F4 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 389D48 E00864F8 96050000 */  lhu       $a1, ($s0)
/* 389D4C E00864FC 8E420000 */  lw        $v0, ($s2)
/* 389D50 E0086500 00052980 */  sll       $a1, $a1, 6
/* 389D54 E0086504 00B32821 */  addu      $a1, $a1, $s3
/* 389D58 E0086508 0C080118 */  jal       func_E0200460
/* 389D5C E008650C 00452821 */   addu     $a1, $v0, $a1
/* 389D60 E0086510 8E220000 */  lw        $v0, ($s1)
/* 389D64 E0086514 3C014380 */  lui       $at, 0x4380
/* 389D68 E0086518 44811000 */  mtc1      $at, $f2
/* 389D6C E008651C 0040202D */  daddu     $a0, $v0, $zero
/* 389D70 E0086520 24420008 */  addiu     $v0, $v0, 8
/* 389D74 E0086524 AE220000 */  sw        $v0, ($s1)
/* 389D78 E0086528 96030000 */  lhu       $v1, ($s0)
/* 389D7C E008652C 3C02DA38 */  lui       $v0, 0xda38
/* 389D80 E0086530 AC820000 */  sw        $v0, ($a0)
/* 389D84 E0086534 24620001 */  addiu     $v0, $v1, 1
/* 389D88 E0086538 A6020000 */  sh        $v0, ($s0)
/* 389D8C E008653C C7A000A4 */  lwc1      $f0, 0xa4($sp)
/* 389D90 E0086540 46800020 */  cvt.s.w   $f0, $f0
/* 389D94 E0086544 4600A001 */  sub.s     $f0, $f20, $f0
/* 389D98 E0086548 3063FFFF */  andi      $v1, $v1, 0xffff
/* 389D9C E008654C 00031980 */  sll       $v1, $v1, 6
/* 389DA0 E0086550 46020002 */  mul.s     $f0, $f0, $f2
/* 389DA4 E0086554 00000000 */  nop
/* 389DA8 E0086558 8E420000 */  lw        $v0, ($s2)
/* 389DAC E008655C 00731821 */  addu      $v1, $v1, $s3
/* 389DB0 E0086560 00431021 */  addu      $v0, $v0, $v1
/* 389DB4 E0086564 AC820004 */  sw        $v0, 4($a0)
/* 389DB8 E0086568 4600010D */  trunc.w.s $f4, $f0
/* 389DBC E008656C E7A400A0 */  swc1      $f4, 0xa0($sp)
/* 389DC0 E0086570 8FA900A4 */  lw        $t1, 0xa4($sp)
/* 389DC4 E0086574 29220004 */  slti      $v0, $t1, 4
/* 389DC8 E0086578 38480001 */  xori      $t0, $v0, 1
/* 389DCC E008657C 8E89002C */  lw        $t1, 0x2c($s4)
/* 389DD0 E0086580 24020001 */  addiu     $v0, $zero, 1
/* 389DD4 E0086584 12A20008 */  beq       $s5, $v0, .LE00865A8
/* 389DD8 E0086588 AFA900BC */   sw       $t1, 0xbc($sp)
/* 389DDC E008658C 2AA20002 */  slti      $v0, $s5, 2
/* 389DE0 E0086590 14400035 */  bnez      $v0, .LE0086668
/* 389DE4 E0086594 24020002 */   addiu    $v0, $zero, 2
/* 389DE8 E0086598 12A20028 */  beq       $s5, $v0, .LE008663C
/* 389DEC E008659C 32C20001 */   andi     $v0, $s6, 1
/* 389DF0 E00865A0 0802199A */  j         .LE0086668
/* 389DF4 E00865A4 00000000 */   nop
.LE00865A8:
/* 389DF8 E00865A8 26C3FFFF */  addiu     $v1, $s6, -1
/* 389DFC E00865AC 2862000D */  slti      $v0, $v1, 0xd
/* 389E00 E00865B0 50400004 */  beql      $v0, $zero, .LE00865C4
/* 389E04 E00865B4 0000182D */   daddu    $v1, $zero, $zero
/* 389E08 E00865B8 3C01E008 */  lui       $at, %hi(D_E0086AE4)
/* 389E0C E00865BC 00230821 */  addu      $at, $at, $v1
/* 389E10 E00865C0 90236AE4 */  lbu       $v1, %lo(D_E0086AE4)($at)
.LE00865C4:
/* 389E14 E00865C4 9282003D */  lbu       $v0, 0x3d($s4)
/* 389E18 E00865C8 00430018 */  mult      $v0, $v1
/* 389E1C E00865CC 00003812 */  mflo      $a3
/* 389E20 E00865D0 9282003E */  lbu       $v0, 0x3e($s4)
/* 389E24 E00865D4 00000000 */  nop
/* 389E28 E00865D8 00430018 */  mult      $v0, $v1
/* 389E2C E00865DC 00003012 */  mflo      $a2
/* 389E30 E00865E0 9282003F */  lbu       $v0, 0x3f($s4)
/* 389E34 E00865E4 00000000 */  nop
/* 389E38 E00865E8 00430018 */  mult      $v0, $v1
/* 389E3C E00865EC 00002812 */  mflo      $a1
/* 389E40 E00865F0 92820040 */  lbu       $v0, 0x40($s4)
/* 389E44 E00865F4 00000000 */  nop
/* 389E48 E00865F8 00430018 */  mult      $v0, $v1
/* 389E4C E00865FC 9289003C */  lbu       $t1, 0x3c($s4)
/* 389E50 E0086600 00073A03 */  sra       $a3, $a3, 8
/* 389E54 E0086604 0006F203 */  sra       $fp, $a2, 8
/* 389E58 E0086608 92820041 */  lbu       $v0, 0x41($s4)
/* 389E5C E008660C 00002012 */  mflo      $a0
/* 389E60 E0086610 00052A03 */  sra       $a1, $a1, 8
/* 389E64 E0086614 AFA900A8 */  sw        $t1, 0xa8($sp)
/* 389E68 E0086618 00430018 */  mult      $v0, $v1
/* 389E6C E008661C AFA700AC */  sw        $a3, 0xac($sp)
/* 389E70 E0086620 AFA500B0 */  sw        $a1, 0xb0($sp)
/* 389E74 E0086624 00042203 */  sra       $a0, $a0, 8
/* 389E78 E0086628 AFA400B4 */  sw        $a0, 0xb4($sp)
/* 389E7C E008662C 00001012 */  mflo      $v0
/* 389E80 E0086630 00021203 */  sra       $v0, $v0, 8
/* 389E84 E0086634 080219A5 */  j         .LE0086694
/* 389E88 E0086638 AFA200B8 */   sw       $v0, 0xb8($sp)
.LE008663C:
/* 389E8C E008663C 1440000A */  bnez      $v0, .LE0086668
/* 389E90 E0086640 0000F02D */   daddu    $fp, $zero, $zero
/* 389E94 E0086644 AFA000A8 */  sw        $zero, 0xa8($sp)
/* 389E98 E0086648 AFA000AC */  sw        $zero, 0xac($sp)
/* 389E9C E008664C 9289003C */  lbu       $t1, 0x3c($s4)
/* 389EA0 E0086650 AFA900B0 */  sw        $t1, 0xb0($sp)
/* 389EA4 E0086654 9289003D */  lbu       $t1, 0x3d($s4)
/* 389EA8 E0086658 AFA900B4 */  sw        $t1, 0xb4($sp)
/* 389EAC E008665C 9289003E */  lbu       $t1, 0x3e($s4)
/* 389EB0 E0086660 080219A5 */  j         .LE0086694
/* 389EB4 E0086664 AFA900B8 */   sw       $t1, 0xb8($sp)
.LE0086668:
/* 389EB8 E0086668 9289003C */  lbu       $t1, 0x3c($s4)
/* 389EBC E008666C AFA900A8 */  sw        $t1, 0xa8($sp)
/* 389EC0 E0086670 9289003D */  lbu       $t1, 0x3d($s4)
/* 389EC4 E0086674 AFA900AC */  sw        $t1, 0xac($sp)
/* 389EC8 E0086678 9289003F */  lbu       $t1, 0x3f($s4)
/* 389ECC E008667C 929E003E */  lbu       $fp, 0x3e($s4)
/* 389ED0 E0086680 AFA900B0 */  sw        $t1, 0xb0($sp)
/* 389ED4 E0086684 92890040 */  lbu       $t1, 0x40($s4)
/* 389ED8 E0086688 AFA900B4 */  sw        $t1, 0xb4($sp)
/* 389EDC E008668C 92890041 */  lbu       $t1, 0x41($s4)
/* 389EE0 E0086690 AFA900B8 */  sw        $t1, 0xb8($sp)
.LE0086694:
/* 389EE4 E0086694 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 389EE8 E0086698 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 389EEC E008669C 8C930000 */  lw        $s3, ($a0)
/* 389EF0 E00866A0 3C02DE00 */  lui       $v0, 0xde00
/* 389EF4 E00866A4 AE620008 */  sw        $v0, 8($s3)
/* 389EF8 E00866A8 00151080 */  sll       $v0, $s5, 2
/* 389EFC E00866AC 3C03E008 */  lui       $v1, %hi(D_E0086AB4)
/* 389F00 E00866B0 00621821 */  addu      $v1, $v1, $v0
/* 389F04 E00866B4 8C636AB4 */  lw        $v1, %lo(D_E0086AB4)($v1)
/* 389F08 E00866B8 26620010 */  addiu     $v0, $s3, 0x10
/* 389F0C E00866BC AC820000 */  sw        $v0, ($a0)
/* 389F10 E00866C0 AE63000C */  sw        $v1, 0xc($s3)
/* 389F14 E00866C4 3C03E008 */  lui       $v1, %hi(D_E0086AB4)
/* 389F18 E00866C8 24636AB4 */  addiu     $v1, $v1, %lo(D_E0086AB4)
/* 389F1C E00866CC 11000007 */  beqz      $t0, .LE00866EC
/* 389F20 E00866D0 26940044 */   addiu    $s4, $s4, 0x44
/* 389F24 E00866D4 26620018 */  addiu     $v0, $s3, 0x18
/* 389F28 E00866D8 AC820000 */  sw        $v0, ($a0)
/* 389F2C E00866DC 3C02F200 */  lui       $v0, 0xf200
/* 389F30 E00866E0 AE620010 */  sw        $v0, 0x10($s3)
/* 389F34 E00866E4 3C020100 */  lui       $v0, 0x100
/* 389F38 E00866E8 AE620014 */  sw        $v0, 0x14($s3)
.LE00866EC:
/* 389F3C E00866EC 8FA90100 */  lw        $t1, 0x100($sp)
/* 389F40 E00866F0 8D220008 */  lw        $v0, 8($t1)
/* 389F44 E00866F4 24120001 */  addiu     $s2, $zero, 1
/* 389F48 E00866F8 0242102A */  slt       $v0, $s2, $v0
/* 389F4C E00866FC 10400063 */  beqz      $v0, .LE008688C
/* 389F50 E0086700 0080A82D */   daddu    $s5, $a0, $zero
/* 389F54 E0086704 27B10060 */  addiu     $s1, $sp, 0x60
/* 389F58 E0086708 3C178007 */  lui       $s7, %hi(gMatrixListPos)
/* 389F5C E008670C 26F741F0 */  addiu     $s7, $s7, %lo(gMatrixListPos)
/* 389F60 E0086710 3C160001 */  lui       $s6, 1
/* 389F64 E0086714 36D61630 */  ori       $s6, $s6, 0x1630
/* 389F68 E0086718 3C03E008 */  lui       $v1, %hi(D_E0086AA0)
/* 389F6C E008671C 24636AA0 */  addiu     $v1, $v1, %lo(D_E0086AA0)
/* 389F70 E0086720 2690000C */  addiu     $s0, $s4, 0xc
/* 389F74 E0086724 8FA900A4 */  lw        $t1, 0xa4($sp)
/* 389F78 E0086728 4480A000 */  mtc1      $zero, $f20
/* 389F7C E008672C 3C013F80 */  lui       $at, 0x3f80
/* 389F80 E0086730 4481B000 */  mtc1      $at, $f22
/* 389F84 E0086734 00091080 */  sll       $v0, $t1, 2
/* 389F88 E0086738 00431021 */  addu      $v0, $v0, $v1
/* 389F8C E008673C AFA200C0 */  sw        $v0, 0xc0($sp)
.LE0086740:
/* 389F90 E0086740 27A40020 */  addiu     $a0, $sp, 0x20
/* 389F94 E0086744 26520001 */  addiu     $s2, $s2, 1
/* 389F98 E0086748 8EA30000 */  lw        $v1, ($s5)
/* 389F9C E008674C 4406A000 */  mfc1      $a2, $f20
/* 389FA0 E0086750 4407A000 */  mfc1      $a3, $f20
/* 389FA4 E0086754 0060282D */  daddu     $a1, $v1, $zero
/* 389FA8 E0086758 3C09DE00 */  lui       $t1, 0xde00
/* 389FAC E008675C ACA90000 */  sw        $t1, ($a1)
/* 389FB0 E0086760 8E820000 */  lw        $v0, ($s4)
/* 389FB4 E0086764 3C09E008 */  lui       $t1, %hi(D_E0086AB4)
/* 389FB8 E0086768 25296AB4 */  addiu     $t1, $t1, %lo(D_E0086AB4)
/* 389FBC E008676C 00021080 */  sll       $v0, $v0, 2
/* 389FC0 E0086770 00491021 */  addu      $v0, $v0, $t1
/* 389FC4 E0086774 8C420000 */  lw        $v0, ($v0)
/* 389FC8 E0086778 24630008 */  addiu     $v1, $v1, 8
/* 389FCC E008677C ACA20004 */  sw        $v0, 4($a1)
/* 389FD0 E0086780 E7B60010 */  swc1      $f22, 0x10($sp)
/* 389FD4 E0086784 8E050010 */  lw        $a1, 0x10($s0)
/* 389FD8 E0086788 26940044 */  addiu     $s4, $s4, 0x44
/* 389FDC E008678C 0C080104 */  jal       func_E0200410
/* 389FE0 E0086790 AEA30000 */   sw       $v1, ($s5)
/* 389FE4 E0086794 E7B40010 */  swc1      $f20, 0x10($sp)
/* 389FE8 E0086798 8E050018 */  lw        $a1, 0x18($s0)
/* 389FEC E008679C 4406A000 */  mfc1      $a2, $f20
/* 389FF0 E00867A0 4407B000 */  mfc1      $a3, $f22
/* 389FF4 E00867A4 0C080104 */  jal       func_E0200410
/* 389FF8 E00867A8 0220202D */   daddu    $a0, $s1, $zero
/* 389FFC E00867AC 0220202D */  daddu     $a0, $s1, $zero
/* 38A000 E00867B0 27A50020 */  addiu     $a1, $sp, 0x20
/* 38A004 E00867B4 0C080114 */  jal       func_E0200450
/* 38A008 E00867B8 00A0302D */   daddu    $a2, $a1, $zero
/* 38A00C E00867BC 8E05FFF8 */  lw        $a1, -8($s0)
/* 38A010 E00867C0 8E06FFFC */  lw        $a2, -4($s0)
/* 38A014 E00867C4 8E070000 */  lw        $a3, ($s0)
/* 38A018 E00867C8 0C080108 */  jal       func_E0200420
/* 38A01C E00867CC 0220202D */   daddu    $a0, $s1, $zero
/* 38A020 E00867D0 0220202D */  daddu     $a0, $s1, $zero
/* 38A024 E00867D4 27A50020 */  addiu     $a1, $sp, 0x20
/* 38A028 E00867D8 0C080114 */  jal       func_E0200450
/* 38A02C E00867DC 00A0302D */   daddu    $a2, $a1, $zero
/* 38A030 E00867E0 27A40020 */  addiu     $a0, $sp, 0x20
/* 38A034 E00867E4 96E50000 */  lhu       $a1, ($s7)
/* 38A038 E00867E8 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 38A03C E00867EC 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 38A040 E00867F0 00052980 */  sll       $a1, $a1, 6
/* 38A044 E00867F4 00B62821 */  addu      $a1, $a1, $s6
/* 38A048 E00867F8 0C080118 */  jal       func_E0200460
/* 38A04C E00867FC 00452821 */   addu     $a1, $v0, $a1
/* 38A050 E0086800 8EA40000 */  lw        $a0, ($s5)
/* 38A054 E0086804 3C06D838 */  lui       $a2, 0xd838
/* 38A058 E0086808 0080282D */  daddu     $a1, $a0, $zero
/* 38A05C E008680C 24840008 */  addiu     $a0, $a0, 8
/* 38A060 E0086810 AEA40000 */  sw        $a0, ($s5)
/* 38A064 E0086814 96E20000 */  lhu       $v0, ($s7)
/* 38A068 E0086818 3C03DA38 */  lui       $v1, 0xda38
/* 38A06C E008681C ACA30000 */  sw        $v1, ($a1)
/* 38A070 E0086820 24430001 */  addiu     $v1, $v0, 1
/* 38A074 E0086824 3042FFFF */  andi      $v0, $v0, 0xffff
/* 38A078 E0086828 00021180 */  sll       $v0, $v0, 6
/* 38A07C E008682C A6E30000 */  sh        $v1, ($s7)
/* 38A080 E0086830 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 38A084 E0086834 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 38A088 E0086838 00561021 */  addu      $v0, $v0, $s6
/* 38A08C E008683C 00621821 */  addu      $v1, $v1, $v0
/* 38A090 E0086840 ACA30004 */  sw        $v1, 4($a1)
/* 38A094 E0086844 3C09DE00 */  lui       $t1, 0xde00
/* 38A098 E0086848 AC890000 */  sw        $t1, ($a0)
/* 38A09C E008684C 8FA900C0 */  lw        $t1, 0xc0($sp)
/* 38A0A0 E0086850 34C60002 */  ori       $a2, $a2, 2
/* 38A0A4 E0086854 8D230000 */  lw        $v1, ($t1)
/* 38A0A8 E0086858 24820008 */  addiu     $v0, $a0, 8
/* 38A0AC E008685C AEA20000 */  sw        $v0, ($s5)
/* 38A0B0 E0086860 24020040 */  addiu     $v0, $zero, 0x40
/* 38A0B4 E0086864 AC860008 */  sw        $a2, 8($a0)
/* 38A0B8 E0086868 AC82000C */  sw        $v0, 0xc($a0)
/* 38A0BC E008686C AC830004 */  sw        $v1, 4($a0)
/* 38A0C0 E0086870 8FA90100 */  lw        $t1, 0x100($sp)
/* 38A0C4 E0086874 26100044 */  addiu     $s0, $s0, 0x44
/* 38A0C8 E0086878 8D220008 */  lw        $v0, 8($t1)
/* 38A0CC E008687C 24840010 */  addiu     $a0, $a0, 0x10
/* 38A0D0 E0086880 0242102A */  slt       $v0, $s2, $v0
/* 38A0D4 E0086884 1440FFAE */  bnez      $v0, .LE0086740
/* 38A0D8 E0086888 AEA40000 */   sw       $a0, ($s5)
.LE008688C:
/* 38A0DC E008688C 27A40020 */  addiu     $a0, $sp, 0x20
/* 38A0E0 E0086890 3C150001 */  lui       $s5, 1
/* 38A0E4 E0086894 36B51630 */  ori       $s5, $s5, 0x1630
/* 38A0E8 E0086898 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 38A0EC E008689C 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* 38A0F0 E00868A0 3C02DF00 */  lui       $v0, 0xdf00
/* 38A0F4 E00868A4 3C14DE00 */  lui       $s4, 0xde00
/* 38A0F8 E00868A8 8E080000 */  lw        $t0, ($s0)
/* 38A0FC E00868AC 3C013F80 */  lui       $at, 0x3f80
/* 38A100 E00868B0 44810000 */  mtc1      $at, $f0
/* 38A104 E00868B4 0100182D */  daddu     $v1, $t0, $zero
/* 38A108 E00868B8 25080008 */  addiu     $t0, $t0, 8
/* 38A10C E00868BC AE080000 */  sw        $t0, ($s0)
/* 38A110 E00868C0 AC620000 */  sw        $v0, ($v1)
/* 38A114 E00868C4 3C02DE01 */  lui       $v0, 0xde01
/* 38A118 E00868C8 AC600004 */  sw        $zero, 4($v1)
/* 38A11C E00868CC AE620000 */  sw        $v0, ($s3)
/* 38A120 E00868D0 25020008 */  addiu     $v0, $t0, 8
/* 38A124 E00868D4 AE680004 */  sw        $t0, 4($s3)
/* 38A128 E00868D8 AE020000 */  sw        $v0, ($s0)
/* 38A12C E00868DC 3C02FA00 */  lui       $v0, 0xfa00
/* 38A130 E00868E0 AD020000 */  sw        $v0, ($t0)
/* 38A134 E00868E4 8FA900A8 */  lw        $t1, 0xa8($sp)
/* 38A138 E00868E8 3C0542F0 */  lui       $a1, 0x42f0
/* 38A13C E00868EC 00091E00 */  sll       $v1, $t1, 0x18
/* 38A140 E00868F0 8FA900AC */  lw        $t1, 0xac($sp)
/* 38A144 E00868F4 26730008 */  addiu     $s3, $s3, 8
/* 38A148 E00868F8 312200FF */  andi      $v0, $t1, 0xff
/* 38A14C E00868FC 00021400 */  sll       $v0, $v0, 0x10
/* 38A150 E0086900 00621825 */  or        $v1, $v1, $v0
/* 38A154 E0086904 33C200FF */  andi      $v0, $fp, 0xff
/* 38A158 E0086908 00021200 */  sll       $v0, $v0, 8
/* 38A15C E008690C 8FA900BC */  lw        $t1, 0xbc($sp)
/* 38A160 E0086910 00621825 */  or        $v1, $v1, $v0
/* 38A164 E0086914 312200FF */  andi      $v0, $t1, 0xff
/* 38A168 E0086918 00621825 */  or        $v1, $v1, $v0
/* 38A16C E008691C 25020010 */  addiu     $v0, $t0, 0x10
/* 38A170 E0086920 AD030004 */  sw        $v1, 4($t0)
/* 38A174 E0086924 AE020000 */  sw        $v0, ($s0)
/* 38A178 E0086928 3C02FB00 */  lui       $v0, 0xfb00
/* 38A17C E008692C AD020008 */  sw        $v0, 8($t0)
/* 38A180 E0086930 8FA900B0 */  lw        $t1, 0xb0($sp)
/* 38A184 E0086934 44060000 */  mfc1      $a2, $f0
/* 38A188 E0086938 00091E00 */  sll       $v1, $t1, 0x18
/* 38A18C E008693C 8FA900B4 */  lw        $t1, 0xb4($sp)
/* 38A190 E0086940 00C0382D */  daddu     $a3, $a2, $zero
/* 38A194 E0086944 312200FF */  andi      $v0, $t1, 0xff
/* 38A198 E0086948 00021400 */  sll       $v0, $v0, 0x10
/* 38A19C E008694C 8FA900B8 */  lw        $t1, 0xb8($sp)
/* 38A1A0 E0086950 00621825 */  or        $v1, $v1, $v0
/* 38A1A4 E0086954 312200FF */  andi      $v0, $t1, 0xff
/* 38A1A8 E0086958 00021200 */  sll       $v0, $v0, 8
/* 38A1AC E008695C 8FA900A0 */  lw        $t1, 0xa0($sp)
/* 38A1B0 E0086960 00621825 */  or        $v1, $v1, $v0
/* 38A1B4 E0086964 312200FF */  andi      $v0, $t1, 0xff
/* 38A1B8 E0086968 00621825 */  or        $v1, $v1, $v0
/* 38A1BC E008696C 25020018 */  addiu     $v0, $t0, 0x18
/* 38A1C0 E0086970 AD03000C */  sw        $v1, 0xc($t0)
/* 38A1C4 E0086974 AE020000 */  sw        $v0, ($s0)
/* 38A1C8 E0086978 AD140010 */  sw        $s4, 0x10($t0)
/* 38A1CC E008697C AD130014 */  sw        $s3, 0x14($t0)
/* 38A1D0 E0086980 0C080104 */  jal       func_E0200410
/* 38A1D4 E0086984 AFA60010 */   sw       $a2, 0x10($sp)
/* 38A1D8 E0086988 27A40020 */  addiu     $a0, $sp, 0x20
/* 38A1DC E008698C 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 38A1E0 E0086990 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 38A1E4 E0086994 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 38A1E8 E0086998 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 38A1EC E008699C 96250000 */  lhu       $a1, ($s1)
/* 38A1F0 E00869A0 8E420000 */  lw        $v0, ($s2)
/* 38A1F4 E00869A4 00052980 */  sll       $a1, $a1, 6
/* 38A1F8 E00869A8 00B52821 */  addu      $a1, $a1, $s5
/* 38A1FC E00869AC 0C080118 */  jal       func_E0200460
/* 38A200 E00869B0 00452821 */   addu     $a1, $v0, $a1
/* 38A204 E00869B4 3C06DA38 */  lui       $a2, 0xda38
/* 38A208 E00869B8 34C60001 */  ori       $a2, $a2, 1
/* 38A20C E00869BC 3C07D838 */  lui       $a3, 0xd838
/* 38A210 E00869C0 34E70002 */  ori       $a3, $a3, 2
/* 38A214 E00869C4 8E030000 */  lw        $v1, ($s0)
/* 38A218 E00869C8 96220000 */  lhu       $v0, ($s1)
/* 38A21C E00869CC 0060202D */  daddu     $a0, $v1, $zero
/* 38A220 E00869D0 24630008 */  addiu     $v1, $v1, 8
/* 38A224 E00869D4 00021180 */  sll       $v0, $v0, 6
/* 38A228 E00869D8 AE030000 */  sw        $v1, ($s0)
/* 38A22C E00869DC AC860000 */  sw        $a2, ($a0)
/* 38A230 E00869E0 8E450000 */  lw        $a1, ($s2)
/* 38A234 E00869E4 00551021 */  addu      $v0, $v0, $s5
/* 38A238 E00869E8 00A21021 */  addu      $v0, $a1, $v0
/* 38A23C E00869EC AC820004 */  sw        $v0, 4($a0)
/* 38A240 E00869F0 24620008 */  addiu     $v0, $v1, 8
/* 38A244 E00869F4 AE020000 */  sw        $v0, ($s0)
/* 38A248 E00869F8 AC740000 */  sw        $s4, ($v1)
/* 38A24C E00869FC AC730004 */  sw        $s3, 4($v1)
/* 38A250 E0086A00 96220000 */  lhu       $v0, ($s1)
/* 38A254 E0086A04 24640010 */  addiu     $a0, $v1, 0x10
/* 38A258 E0086A08 AE040000 */  sw        $a0, ($s0)
/* 38A25C E0086A0C AC660008 */  sw        $a2, 8($v1)
/* 38A260 E0086A10 24440001 */  addiu     $a0, $v0, 1
/* 38A264 E0086A14 3042FFFF */  andi      $v0, $v0, 0xffff
/* 38A268 E0086A18 00021180 */  sll       $v0, $v0, 6
/* 38A26C E0086A1C 00551021 */  addu      $v0, $v0, $s5
/* 38A270 E0086A20 00A22821 */  addu      $a1, $a1, $v0
/* 38A274 E0086A24 24620018 */  addiu     $v0, $v1, 0x18
/* 38A278 E0086A28 A6240000 */  sh        $a0, ($s1)
/* 38A27C E0086A2C AC65000C */  sw        $a1, 0xc($v1)
/* 38A280 E0086A30 AE020000 */  sw        $v0, ($s0)
/* 38A284 E0086A34 24620020 */  addiu     $v0, $v1, 0x20
/* 38A288 E0086A38 AC740010 */  sw        $s4, 0x10($v1)
/* 38A28C E0086A3C AC730014 */  sw        $s3, 0x14($v1)
/* 38A290 E0086A40 AE020000 */  sw        $v0, ($s0)
/* 38A294 E0086A44 24020040 */  addiu     $v0, $zero, 0x40
/* 38A298 E0086A48 AC62001C */  sw        $v0, 0x1c($v1)
/* 38A29C E0086A4C 24620028 */  addiu     $v0, $v1, 0x28
/* 38A2A0 E0086A50 AC670018 */  sw        $a3, 0x18($v1)
/* 38A2A4 E0086A54 AE020000 */  sw        $v0, ($s0)
/* 38A2A8 E0086A58 3C02E700 */  lui       $v0, 0xe700
/* 38A2AC E0086A5C AC620020 */  sw        $v0, 0x20($v1)
/* 38A2B0 E0086A60 AC600024 */  sw        $zero, 0x24($v1)
.LE0086A64:
/* 38A2B4 E0086A64 8FBF00EC */  lw        $ra, 0xec($sp)
/* 38A2B8 E0086A68 8FBE00E8 */  lw        $fp, 0xe8($sp)
/* 38A2BC E0086A6C 8FB700E4 */  lw        $s7, 0xe4($sp)
/* 38A2C0 E0086A70 8FB600E0 */  lw        $s6, 0xe0($sp)
/* 38A2C4 E0086A74 8FB500DC */  lw        $s5, 0xdc($sp)
/* 38A2C8 E0086A78 8FB400D8 */  lw        $s4, 0xd8($sp)
/* 38A2CC E0086A7C 8FB300D4 */  lw        $s3, 0xd4($sp)
/* 38A2D0 E0086A80 8FB200D0 */  lw        $s2, 0xd0($sp)
/* 38A2D4 E0086A84 8FB100CC */  lw        $s1, 0xcc($sp)
/* 38A2D8 E0086A88 8FB000C8 */  lw        $s0, 0xc8($sp)
/* 38A2DC E0086A8C D7B600F8 */  ldc1      $f22, 0xf8($sp)
/* 38A2E0 E0086A90 D7B400F0 */  ldc1      $f20, 0xf0($sp)
/* 38A2E4 E0086A94 03E00008 */  jr        $ra
/* 38A2E8 E0086A98 27BD0100 */   addiu    $sp, $sp, 0x100
/* 38A2EC E0086A9C 00000000 */  nop
