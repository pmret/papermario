.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_19_appendGfx
/* 33B674 E00264F4 27BDFEE8 */  addiu     $sp, $sp, -0x118
/* 33B678 E00264F8 AFB70104 */  sw        $s7, 0x104($sp)
/* 33B67C E00264FC 0080B82D */  daddu     $s7, $a0, $zero
/* 33B680 E0026500 3C07DB06 */  lui       $a3, 0xdb06
/* 33B684 E0026504 34E70024 */  ori       $a3, $a3, 0x24
/* 33B688 E0026508 AFB500FC */  sw        $s5, 0xfc($sp)
/* 33B68C E002650C 3C15800A */  lui       $s5, %hi(gMasterGfxPos)
/* 33B690 E0026510 26B5A66C */  addiu     $s5, $s5, %lo(gMasterGfxPos)
/* 33B694 E0026514 27A40020 */  addiu     $a0, $sp, 0x20
/* 33B698 E0026518 3C08800B */  lui       $t0, %hi(gCameras)
/* 33B69C E002651C 25081D80 */  addiu     $t0, $t0, %lo(gCameras)
/* 33B6A0 E0026520 AFBF010C */  sw        $ra, 0x10c($sp)
/* 33B6A4 E0026524 AFBE0108 */  sw        $fp, 0x108($sp)
/* 33B6A8 E0026528 AFB60100 */  sw        $s6, 0x100($sp)
/* 33B6AC E002652C AFB400F8 */  sw        $s4, 0xf8($sp)
/* 33B6B0 E0026530 AFB300F4 */  sw        $s3, 0xf4($sp)
/* 33B6B4 E0026534 AFB200F0 */  sw        $s2, 0xf0($sp)
/* 33B6B8 E0026538 AFB100EC */  sw        $s1, 0xec($sp)
/* 33B6BC E002653C AFB000E8 */  sw        $s0, 0xe8($sp)
/* 33B6C0 E0026540 F7B40110 */  sdc1      $f20, 0x110($sp)
/* 33B6C4 E0026544 8EA50000 */  lw        $a1, ($s5)
/* 33B6C8 E0026548 8EF3000C */  lw        $s3, 0xc($s7)
/* 33B6CC E002654C 00A0182D */  daddu     $v1, $a1, $zero
/* 33B6D0 E0026550 24A50008 */  addiu     $a1, $a1, 8
/* 33B6D4 E0026554 AEA50000 */  sw        $a1, ($s5)
/* 33B6D8 E0026558 8E740000 */  lw        $s4, ($s3)
/* 33B6DC E002655C 24A20008 */  addiu     $v0, $a1, 8
/* 33B6E0 E0026560 AEA20000 */  sw        $v0, ($s5)
/* 33B6E4 E0026564 00141080 */  sll       $v0, $s4, 2
/* 33B6E8 E0026568 3C06E002 */  lui       $a2, %hi(D_E00269F8)
/* 33B6EC E002656C 00C23021 */  addu      $a2, $a2, $v0
/* 33B6F0 E0026570 8CC669F8 */  lw        $a2, %lo(D_E00269F8)($a2)
/* 33B6F4 E0026574 3C1EE002 */  lui       $fp, %hi(D_E00269F0)
/* 33B6F8 E0026578 03C2F021 */  addu      $fp, $fp, $v0
/* 33B6FC E002657C 8FDE69F0 */  lw        $fp, %lo(D_E00269F0)($fp)
/* 33B700 E0026580 3C02E700 */  lui       $v0, 0xe700
/* 33B704 E0026584 AC620000 */  sw        $v0, ($v1)
/* 33B708 E0026588 AC600004 */  sw        $zero, 4($v1)
/* 33B70C E002658C ACA70000 */  sw        $a3, ($a1)
/* 33B710 E0026590 8EE30010 */  lw        $v1, 0x10($s7)
/* 33B714 E0026594 24A20010 */  addiu     $v0, $a1, 0x10
/* 33B718 E0026598 AEA20000 */  sw        $v0, ($s5)
/* 33B71C E002659C 8C63001C */  lw        $v1, 0x1c($v1)
/* 33B720 E00265A0 3C02DE00 */  lui       $v0, 0xde00
/* 33B724 E00265A4 ACA20008 */  sw        $v0, 8($a1)
/* 33B728 E00265A8 3C028000 */  lui       $v0, 0x8000
/* 33B72C E00265AC ACA6000C */  sw        $a2, 0xc($a1)
/* 33B730 E00265B0 00621821 */  addu      $v1, $v1, $v0
/* 33B734 E00265B4 ACA30004 */  sw        $v1, 4($a1)
/* 33B738 E00265B8 8E650010 */  lw        $a1, 0x10($s3)
/* 33B73C E00265BC 8E660014 */  lw        $a2, 0x14($s3)
/* 33B740 E00265C0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 33B744 E00265C4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 33B748 E00265C8 8E670018 */  lw        $a3, 0x18($s3)
/* 33B74C E00265CC 00031080 */  sll       $v0, $v1, 2
/* 33B750 E00265D0 00431021 */  addu      $v0, $v0, $v1
/* 33B754 E00265D4 00021080 */  sll       $v0, $v0, 2
/* 33B758 E00265D8 00431023 */  subu      $v0, $v0, $v1
/* 33B75C E00265DC 000218C0 */  sll       $v1, $v0, 3
/* 33B760 E00265E0 00431021 */  addu      $v0, $v0, $v1
/* 33B764 E00265E4 000210C0 */  sll       $v0, $v0, 3
/* 33B768 E00265E8 0C080108 */  jal       shim_guTranslateF
/* 33B76C E00265EC 00488821 */   addu     $s1, $v0, $t0
/* 33B770 E00265F0 27B00060 */  addiu     $s0, $sp, 0x60
/* 33B774 E00265F4 0200202D */  daddu     $a0, $s0, $zero
/* 33B778 E00265F8 3C013F80 */  lui       $at, 0x3f80
/* 33B77C E00265FC 4481A000 */  mtc1      $at, $f20
/* 33B780 E0026600 8E65001C */  lw        $a1, 0x1c($s3)
/* 33B784 E0026604 4407A000 */  mfc1      $a3, $f20
/* 33B788 E0026608 0C080110 */  jal       shim_guScaleF
/* 33B78C E002660C 00A0302D */   daddu    $a2, $a1, $zero
/* 33B790 E0026610 0200202D */  daddu     $a0, $s0, $zero
/* 33B794 E0026614 27A50020 */  addiu     $a1, $sp, 0x20
/* 33B798 E0026618 0C080114 */  jal       shim_guMtxCatF
/* 33B79C E002661C 00A0302D */   daddu    $a2, $a1, $zero
/* 33B7A0 E0026620 24160001 */  addiu     $s6, $zero, 1
/* 33B7A4 E0026624 3C0141F0 */  lui       $at, 0x41f0
/* 33B7A8 E0026628 44810000 */  mtc1      $at, $f0
/* 33B7AC E002662C 16960003 */  bne       $s4, $s6, .LE002663C
/* 33B7B0 E0026630 27A500E0 */   addiu    $a1, $sp, 0xe0
/* 33B7B4 E0026634 3C014302 */  lui       $at, 0x4302
/* 33B7B8 E0026638 44810000 */  mtc1      $at, $f0
.LE002663C:
/* 33B7BC E002663C 0200202D */  daddu     $a0, $s0, $zero
/* 33B7C0 E0026640 3C120001 */  lui       $s2, 1
/* 33B7C4 E0026644 44060000 */  mfc1      $a2, $f0
/* 33B7C8 E0026648 8622000A */  lh        $v0, 0xa($s1)
/* 33B7CC E002664C 8623000C */  lh        $v1, 0xc($s1)
/* 33B7D0 E0026650 3C014080 */  lui       $at, 0x4080
/* 33B7D4 E0026654 44811000 */  mtc1      $at, $f2
/* 33B7D8 E0026658 3C014680 */  lui       $at, 0x4680
/* 33B7DC E002665C 44812000 */  mtc1      $at, $f4
/* 33B7E0 E0026660 44823000 */  mtc1      $v0, $f6
/* 33B7E4 E0026664 00000000 */  nop
/* 33B7E8 E0026668 468031A0 */  cvt.s.w   $f6, $f6
/* 33B7EC E002666C 44830000 */  mtc1      $v1, $f0
/* 33B7F0 E0026670 00000000 */  nop
/* 33B7F4 E0026674 46800020 */  cvt.s.w   $f0, $f0
/* 33B7F8 E0026678 46003183 */  div.s     $f6, $f6, $f0
/* 33B7FC E002667C 44073000 */  mfc1      $a3, $f6
/* 33B800 E0026680 36521630 */  ori       $s2, $s2, 0x1630
/* 33B804 E0026684 E7B40018 */  swc1      $f20, 0x18($sp)
/* 33B808 E0026688 E7A20010 */  swc1      $f2, 0x10($sp)
/* 33B80C E002668C 0C080160 */  jal       shim_guPerspectiveF
/* 33B810 E0026690 E7A40014 */   swc1     $f4, 0x14($sp)
/* 33B814 E0026694 0200202D */  daddu     $a0, $s0, $zero
/* 33B818 E0026698 27A50020 */  addiu     $a1, $sp, 0x20
/* 33B81C E002669C 0C080114 */  jal       shim_guMtxCatF
/* 33B820 E00266A0 00A0302D */   daddu    $a2, $a1, $zero
/* 33B824 E00266A4 27A40020 */  addiu     $a0, $sp, 0x20
/* 33B828 E00266A8 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 33B82C E00266AC 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 33B830 E00266B0 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 33B834 E00266B4 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 33B838 E00266B8 96050000 */  lhu       $a1, ($s0)
/* 33B83C E00266BC 8E220000 */  lw        $v0, ($s1)
/* 33B840 E00266C0 00052980 */  sll       $a1, $a1, 6
/* 33B844 E00266C4 00B22821 */  addu      $a1, $a1, $s2
/* 33B848 E00266C8 0C080118 */  jal       shim_guMtxF2L
/* 33B84C E00266CC 00452821 */   addu     $a1, $v0, $a1
/* 33B850 E00266D0 3C04DA38 */  lui       $a0, 0xda38
/* 33B854 E00266D4 34840007 */  ori       $a0, $a0, 7
/* 33B858 E00266D8 8EA30000 */  lw        $v1, ($s5)
/* 33B85C E00266DC 96020000 */  lhu       $v0, ($s0)
/* 33B860 E00266E0 0060282D */  daddu     $a1, $v1, $zero
/* 33B864 E00266E4 24630008 */  addiu     $v1, $v1, 8
/* 33B868 E00266E8 AEA30000 */  sw        $v1, ($s5)
/* 33B86C E00266EC 24430001 */  addiu     $v1, $v0, 1
/* 33B870 E00266F0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 33B874 E00266F4 00021180 */  sll       $v0, $v0, 6
/* 33B878 E00266F8 ACA40000 */  sw        $a0, ($a1)
/* 33B87C E00266FC A6030000 */  sh        $v1, ($s0)
/* 33B880 E0026700 8E230000 */  lw        $v1, ($s1)
/* 33B884 E0026704 00521021 */  addu      $v0, $v0, $s2
/* 33B888 E0026708 00621821 */  addu      $v1, $v1, $v0
/* 33B88C E002670C 12800009 */  beqz      $s4, .LE0026734
/* 33B890 E0026710 ACA30004 */   sw       $v1, 4($a1)
/* 33B894 E0026714 1696000E */  bne       $s4, $s6, .LE0026750
/* 33B898 E0026718 3C120001 */   lui      $s2, 1
/* 33B89C E002671C 44800000 */  mtc1      $zero, $f0
/* 33B8A0 E0026720 00000000 */  nop
/* 33B8A4 E0026724 44050000 */  mfc1      $a1, $f0
/* 33B8A8 E0026728 3C07C28C */  lui       $a3, 0xc28c
/* 33B8AC E002672C 080099D1 */  j         .LE0026744
/* 33B8B0 E0026730 27A40020 */   addiu    $a0, $sp, 0x20
.LE0026734:
/* 33B8B4 E0026734 44800000 */  mtc1      $zero, $f0
/* 33B8B8 E0026738 27A40020 */  addiu     $a0, $sp, 0x20
/* 33B8BC E002673C 44050000 */  mfc1      $a1, $f0
/* 33B8C0 E0026740 3C07C2A0 */  lui       $a3, 0xc2a0
.LE0026744:
/* 33B8C4 E0026744 0C080108 */  jal       shim_guTranslateF
/* 33B8C8 E0026748 00A0302D */   daddu    $a2, $a1, $zero
/* 33B8CC E002674C 3C120001 */  lui       $s2, 1
.LE0026750:
/* 33B8D0 E0026750 36521630 */  ori       $s2, $s2, 0x1630
/* 33B8D4 E0026754 27A40020 */  addiu     $a0, $sp, 0x20
/* 33B8D8 E0026758 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 33B8DC E002675C 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 33B8E0 E0026760 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 33B8E4 E0026764 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 33B8E8 E0026768 96050000 */  lhu       $a1, ($s0)
/* 33B8EC E002676C 8E220000 */  lw        $v0, ($s1)
/* 33B8F0 E0026770 00052980 */  sll       $a1, $a1, 6
/* 33B8F4 E0026774 00B22821 */  addu      $a1, $a1, $s2
/* 33B8F8 E0026778 0C080118 */  jal       shim_guMtxF2L
/* 33B8FC E002677C 00452821 */   addu     $a1, $v0, $a1
/* 33B900 E0026780 3C03DA38 */  lui       $v1, 0xda38
/* 33B904 E0026784 34630002 */  ori       $v1, $v1, 2
/* 33B908 E0026788 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 33B90C E002678C 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 33B910 E0026790 8CC20000 */  lw        $v0, ($a2)
/* 33B914 E0026794 96040000 */  lhu       $a0, ($s0)
/* 33B918 E0026798 0040282D */  daddu     $a1, $v0, $zero
/* 33B91C E002679C 24420008 */  addiu     $v0, $v0, 8
/* 33B920 E00267A0 ACC20000 */  sw        $v0, ($a2)
/* 33B924 E00267A4 3082FFFF */  andi      $v0, $a0, 0xffff
/* 33B928 E00267A8 00021180 */  sll       $v0, $v0, 6
/* 33B92C E00267AC ACA30000 */  sw        $v1, ($a1)
/* 33B930 E00267B0 8E230000 */  lw        $v1, ($s1)
/* 33B934 E00267B4 00521021 */  addu      $v0, $v0, $s2
/* 33B938 E00267B8 00621821 */  addu      $v1, $v1, $v0
/* 33B93C E00267BC ACA30004 */  sw        $v1, 4($a1)
/* 33B940 E00267C0 8E63002C */  lw        $v1, 0x2c($s3)
/* 33B944 E00267C4 24840001 */  addiu     $a0, $a0, 1
/* 33B948 E00267C8 A6040000 */  sh        $a0, ($s0)
/* 33B94C E00267CC 00031040 */  sll       $v0, $v1, 1
/* 33B950 E00267D0 00434821 */  addu      $t1, $v0, $v1
/* 33B954 E00267D4 8EE20008 */  lw        $v0, 8($s7)
/* 33B958 E00267D8 8E630024 */  lw        $v1, 0x24($s3)
/* 33B95C E00267DC 18400059 */  blez      $v0, .LE0026944
/* 33B960 E00267E0 0000602D */   daddu    $t4, $zero, $zero
/* 33B964 E00267E4 3C112AAA */  lui       $s1, 0x2aaa
/* 33B968 E00267E8 3631AAAB */  ori       $s1, $s1, 0xaaab
/* 33B96C E00267EC 00C0582D */  daddu     $t3, $a2, $zero
/* 33B970 E00267F0 3C14FB00 */  lui       $s4, 0xfb00
/* 33B974 E00267F4 000317C2 */  srl       $v0, $v1, 0x1f
/* 33B978 E00267F8 00621021 */  addu      $v0, $v1, $v0
/* 33B97C E00267FC 00021043 */  sra       $v0, $v0, 1
/* 33B980 E0026800 305000FF */  andi      $s0, $v0, 0xff
/* 33B984 E0026804 3C12FA00 */  lui       $s2, 0xfa00
/* 33B988 E0026808 3C0EE002 */  lui       $t6, %hi(D_E0026A00)
/* 33B98C E002680C 25CE6A00 */  addiu     $t6, $t6, %lo(D_E0026A00)
/* 33B990 E0026810 306F00FF */  andi      $t7, $v1, 0xff
/* 33B994 E0026814 3C0DF200 */  lui       $t5, 0xf200
/* 33B998 E0026818 266A0048 */  addiu     $t2, $s3, 0x48
.LE002681C:
/* 33B99C E002681C 2529001E */  addiu     $t1, $t1, 0x1e
/* 33B9A0 E0026820 258C0001 */  addiu     $t4, $t4, 1
/* 33B9A4 E0026824 8D660000 */  lw        $a2, ($t3)
/* 33B9A8 E0026828 01310018 */  mult      $t1, $s1
/* 33B9AC E002682C 00C0102D */  daddu     $v0, $a2, $zero
/* 33B9B0 E0026830 24C60008 */  addiu     $a2, $a2, 8
/* 33B9B4 E0026834 AD660000 */  sw        $a2, ($t3)
/* 33B9B8 E0026838 AC540000 */  sw        $s4, ($v0)
/* 33B9BC E002683C AC500004 */  sw        $s0, 4($v0)
/* 33B9C0 E0026840 24C20008 */  addiu     $v0, $a2, 8
/* 33B9C4 E0026844 AD620000 */  sw        $v0, ($t3)
/* 33B9C8 E0026848 000917C3 */  sra       $v0, $t1, 0x1f
/* 33B9CC E002684C ACD20000 */  sw        $s2, ($a2)
/* 33B9D0 E0026850 0000C010 */  mfhi      $t8
/* 33B9D4 E0026854 00181883 */  sra       $v1, $t8, 2
/* 33B9D8 E0026858 00621823 */  subu      $v1, $v1, $v0
/* 33B9DC E002685C 00031040 */  sll       $v0, $v1, 1
/* 33B9E0 E0026860 00431021 */  addu      $v0, $v0, $v1
/* 33B9E4 E0026864 000210C0 */  sll       $v0, $v0, 3
/* 33B9E8 E0026868 01224823 */  subu      $t1, $t1, $v0
/* 33B9EC E002686C 012E1021 */  addu      $v0, $t1, $t6
/* 33B9F0 E0026870 0040202D */  daddu     $a0, $v0, $zero
/* 33B9F4 E0026874 90430000 */  lbu       $v1, ($v0)
/* 33B9F8 E0026878 90840002 */  lbu       $a0, 2($a0)
/* 33B9FC E002687C 24C20010 */  addiu     $v0, $a2, 0x10
/* 33BA00 E0026880 AD620000 */  sw        $v0, ($t3)
/* 33BA04 E0026884 24C20018 */  addiu     $v0, $a2, 0x18
/* 33BA08 E0026888 AD620000 */  sw        $v0, ($t3)
/* 33BA0C E002688C 24C20020 */  addiu     $v0, $a2, 0x20
/* 33BA10 E0026890 AD620000 */  sw        $v0, ($t3)
/* 33BA14 E0026894 00031E00 */  sll       $v1, $v1, 0x18
/* 33BA18 E0026898 00042200 */  sll       $a0, $a0, 8
/* 33BA1C E002689C 00641825 */  or        $v1, $v1, $a0
/* 33BA20 E00268A0 006F1825 */  or        $v1, $v1, $t7
/* 33BA24 E00268A4 ACC30004 */  sw        $v1, 4($a2)
/* 33BA28 E00268A8 8D44FFE8 */  lw        $a0, -0x18($t2)
/* 33BA2C E00268AC 8D47FFF8 */  lw        $a3, -8($t2)
/* 33BA30 E00268B0 8D45FFF0 */  lw        $a1, -0x10($t2)
/* 33BA34 E00268B4 8D480000 */  lw        $t0, ($t2)
/* 33BA38 E00268B8 3C02DE00 */  lui       $v0, 0xde00
/* 33BA3C E00268BC ACC20018 */  sw        $v0, 0x18($a2)
/* 33BA40 E00268C0 ACDE001C */  sw        $fp, 0x1c($a2)
/* 33BA44 E00268C4 30830FFF */  andi      $v1, $a0, 0xfff
/* 33BA48 E00268C8 00031B00 */  sll       $v1, $v1, 0xc
/* 33BA4C E00268CC 30E20FFF */  andi      $v0, $a3, 0xfff
/* 33BA50 E00268D0 004D1025 */  or        $v0, $v0, $t5
/* 33BA54 E00268D4 00621825 */  or        $v1, $v1, $v0
/* 33BA58 E00268D8 24840100 */  addiu     $a0, $a0, 0x100
/* 33BA5C E00268DC 30840FFF */  andi      $a0, $a0, 0xfff
/* 33BA60 E00268E0 00042300 */  sll       $a0, $a0, 0xc
/* 33BA64 E00268E4 24E70100 */  addiu     $a3, $a3, 0x100
/* 33BA68 E00268E8 30E70FFF */  andi      $a3, $a3, 0xfff
/* 33BA6C E00268EC 00872025 */  or        $a0, $a0, $a3
/* 33BA70 E00268F0 ACC30008 */  sw        $v1, 8($a2)
/* 33BA74 E00268F4 30A30FFF */  andi      $v1, $a1, 0xfff
/* 33BA78 E00268F8 00031B00 */  sll       $v1, $v1, 0xc
/* 33BA7C E00268FC 31020FFF */  andi      $v0, $t0, 0xfff
/* 33BA80 E0026900 004D1025 */  or        $v0, $v0, $t5
/* 33BA84 E0026904 00621825 */  or        $v1, $v1, $v0
/* 33BA88 E0026908 24A50100 */  addiu     $a1, $a1, 0x100
/* 33BA8C E002690C 30A50FFF */  andi      $a1, $a1, 0xfff
/* 33BA90 E0026910 00052B00 */  sll       $a1, $a1, 0xc
/* 33BA94 E0026914 25080100 */  addiu     $t0, $t0, 0x100
/* 33BA98 E0026918 31080FFF */  andi      $t0, $t0, 0xfff
/* 33BA9C E002691C 3C020100 */  lui       $v0, 0x100
/* 33BAA0 E0026920 01024025 */  or        $t0, $t0, $v0
/* 33BAA4 E0026924 00A82825 */  or        $a1, $a1, $t0
/* 33BAA8 E0026928 ACC4000C */  sw        $a0, 0xc($a2)
/* 33BAAC E002692C ACC30010 */  sw        $v1, 0x10($a2)
/* 33BAB0 E0026930 ACC50014 */  sw        $a1, 0x14($a2)
/* 33BAB4 E0026934 8EE20008 */  lw        $v0, 8($s7)
/* 33BAB8 E0026938 0182102A */  slt       $v0, $t4, $v0
/* 33BABC E002693C 1440FFB7 */  bnez      $v0, .LE002681C
/* 33BAC0 E0026940 254A0060 */   addiu    $t2, $t2, 0x60
.LE0026944:
/* 33BAC4 E0026944 3C02D838 */  lui       $v0, 0xd838
/* 33BAC8 E0026948 34420002 */  ori       $v0, $v0, 2
/* 33BACC E002694C 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 33BAD0 E0026950 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 33BAD4 E0026954 8CA40000 */  lw        $a0, ($a1)
/* 33BAD8 E0026958 3C06DA38 */  lui       $a2, 0xda38
/* 33BADC E002695C 0080182D */  daddu     $v1, $a0, $zero
/* 33BAE0 E0026960 24840008 */  addiu     $a0, $a0, 8
/* 33BAE4 E0026964 ACA40000 */  sw        $a0, ($a1)
/* 33BAE8 E0026968 AC620000 */  sw        $v0, ($v1)
/* 33BAEC E002696C 24020040 */  addiu     $v0, $zero, 0x40
/* 33BAF0 E0026970 AC620004 */  sw        $v0, 4($v1)
/* 33BAF4 E0026974 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 33BAF8 E0026978 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 33BAFC E002697C 24820008 */  addiu     $v0, $a0, 8
/* 33BB00 E0026980 ACA20000 */  sw        $v0, ($a1)
/* 33BB04 E0026984 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 33BB08 E0026988 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 33BB0C E002698C 34C60007 */  ori       $a2, $a2, 7
/* 33BB10 E0026990 AC860000 */  sw        $a2, ($a0)
/* 33BB14 E0026994 00031980 */  sll       $v1, $v1, 6
/* 33BB18 E0026998 24630030 */  addiu     $v1, $v1, 0x30
/* 33BB1C E002699C 00431021 */  addu      $v0, $v0, $v1
/* 33BB20 E00269A0 AC820004 */  sw        $v0, 4($a0)
/* 33BB24 E00269A4 24820010 */  addiu     $v0, $a0, 0x10
/* 33BB28 E00269A8 ACA20000 */  sw        $v0, ($a1)
/* 33BB2C E00269AC 3C02E700 */  lui       $v0, 0xe700
/* 33BB30 E00269B0 AC820008 */  sw        $v0, 8($a0)
/* 33BB34 E00269B4 AC80000C */  sw        $zero, 0xc($a0)
/* 33BB38 E00269B8 8FBF010C */  lw        $ra, 0x10c($sp)
/* 33BB3C E00269BC 8FBE0108 */  lw        $fp, 0x108($sp)
/* 33BB40 E00269C0 8FB70104 */  lw        $s7, 0x104($sp)
/* 33BB44 E00269C4 8FB60100 */  lw        $s6, 0x100($sp)
/* 33BB48 E00269C8 8FB500FC */  lw        $s5, 0xfc($sp)
/* 33BB4C E00269CC 8FB400F8 */  lw        $s4, 0xf8($sp)
/* 33BB50 E00269D0 8FB300F4 */  lw        $s3, 0xf4($sp)
/* 33BB54 E00269D4 8FB200F0 */  lw        $s2, 0xf0($sp)
/* 33BB58 E00269D8 8FB100EC */  lw        $s1, 0xec($sp)
/* 33BB5C E00269DC 8FB000E8 */  lw        $s0, 0xe8($sp)
/* 33BB60 E00269E0 D7B40110 */  ldc1      $f20, 0x110($sp)
/* 33BB64 E00269E4 03E00008 */  jr        $ra
/* 33BB68 E00269E8 27BD0118 */   addiu    $sp, $sp, 0x118
/* 33BB6C E00269EC 00000000 */  nop
