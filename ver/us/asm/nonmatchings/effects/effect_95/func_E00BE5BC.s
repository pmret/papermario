.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00BE5BC
/* 3BC51C E00BE5BC 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 3BC520 E00BE5C0 3C05DB06 */  lui       $a1, 0xdb06
/* 3BC524 E00BE5C4 34A50024 */  ori       $a1, $a1, 0x24
/* 3BC528 E00BE5C8 AFA400C0 */  sw        $a0, 0xc0($sp)
/* 3BC52C E00BE5CC 27A40010 */  addiu     $a0, $sp, 0x10
/* 3BC530 E00BE5D0 AFB1009C */  sw        $s1, 0x9c($sp)
/* 3BC534 E00BE5D4 3C110001 */  lui       $s1, 1
/* 3BC538 E00BE5D8 36311630 */  ori       $s1, $s1, 0x1630
/* 3BC53C E00BE5DC AFB300A4 */  sw        $s3, 0xa4($sp)
/* 3BC540 E00BE5E0 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 3BC544 E00BE5E4 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 3BC548 E00BE5E8 AFBF00BC */  sw        $ra, 0xbc($sp)
/* 3BC54C E00BE5EC AFBE00B8 */  sw        $fp, 0xb8($sp)
/* 3BC550 E00BE5F0 AFB700B4 */  sw        $s7, 0xb4($sp)
/* 3BC554 E00BE5F4 AFB600B0 */  sw        $s6, 0xb0($sp)
/* 3BC558 E00BE5F8 AFB500AC */  sw        $s5, 0xac($sp)
/* 3BC55C E00BE5FC AFB400A8 */  sw        $s4, 0xa8($sp)
/* 3BC560 E00BE600 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 3BC564 E00BE604 AFB00098 */  sw        $s0, 0x98($sp)
/* 3BC568 E00BE608 8E670000 */  lw        $a3, ($s3)
/* 3BC56C E00BE60C 8FAC00C0 */  lw        $t4, 0xc0($sp)
/* 3BC570 E00BE610 00E0182D */  daddu     $v1, $a3, $zero
/* 3BC574 E00BE614 8D92000C */  lw        $s2, 0xc($t4)
/* 3BC578 E00BE618 24E70008 */  addiu     $a3, $a3, 8
/* 3BC57C E00BE61C AE670000 */  sw        $a3, ($s3)
/* 3BC580 E00BE620 8E4C0030 */  lw        $t4, 0x30($s2)
/* 3BC584 E00BE624 24160001 */  addiu     $s6, $zero, 1
/* 3BC588 E00BE628 AFAC0090 */  sw        $t4, 0x90($sp)
/* 3BC58C E00BE62C C6400004 */  lwc1      $f0, 4($s2)
/* 3BC590 E00BE630 C6420008 */  lwc1      $f2, 8($s2)
/* 3BC594 E00BE634 3C02E700 */  lui       $v0, 0xe700
/* 3BC598 E00BE638 AC620000 */  sw        $v0, ($v1)
/* 3BC59C E00BE63C 24E20008 */  addiu     $v0, $a3, 8
/* 3BC5A0 E00BE640 AC600004 */  sw        $zero, 4($v1)
/* 3BC5A4 E00BE644 AE620000 */  sw        $v0, ($s3)
/* 3BC5A8 E00BE648 ACE50000 */  sw        $a1, ($a3)
/* 3BC5AC E00BE64C 4600010D */  trunc.w.s $f4, $f0
/* 3BC5B0 E00BE650 E7A40094 */  swc1      $f4, 0x94($sp)
/* 3BC5B4 E00BE654 C7A40094 */  lwc1      $f4, 0x94($sp)
/* 3BC5B8 E00BE658 46802120 */  cvt.s.w   $f4, $f4
/* 3BC5BC E00BE65C 44052000 */  mfc1      $a1, $f4
/* 3BC5C0 E00BE660 4600110D */  trunc.w.s $f4, $f2
/* 3BC5C4 E00BE664 441E2000 */  mfc1      $fp, $f4
/* 3BC5C8 E00BE668 8FAC00C0 */  lw        $t4, 0xc0($sp)
/* 3BC5CC E00BE66C 3C038000 */  lui       $v1, 0x8000
/* 3BC5D0 E00BE670 8D820010 */  lw        $v0, 0x10($t4)
/* 3BC5D4 E00BE674 449E2000 */  mtc1      $fp, $f4
/* 3BC5D8 E00BE678 00000000 */  nop
/* 3BC5DC E00BE67C 46802120 */  cvt.s.w   $f4, $f4
/* 3BC5E0 E00BE680 8C42001C */  lw        $v0, 0x1c($v0)
/* 3BC5E4 E00BE684 44062000 */  mfc1      $a2, $f4
/* 3BC5E8 E00BE688 00431021 */  addu      $v0, $v0, $v1
/* 3BC5EC E00BE68C 3C03800B */  lui       $v1, %hi(gCameras)
/* 3BC5F0 E00BE690 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3BC5F4 E00BE694 ACE20004 */  sw        $v0, 4($a3)
/* 3BC5F8 E00BE698 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3BC5FC E00BE69C 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3BC600 E00BE6A0 8E47000C */  lw        $a3, 0xc($s2)
/* 3BC604 E00BE6A4 00028080 */  sll       $s0, $v0, 2
/* 3BC608 E00BE6A8 02028021 */  addu      $s0, $s0, $v0
/* 3BC60C E00BE6AC 00108080 */  sll       $s0, $s0, 2
/* 3BC610 E00BE6B0 02028023 */  subu      $s0, $s0, $v0
/* 3BC614 E00BE6B4 001010C0 */  sll       $v0, $s0, 3
/* 3BC618 E00BE6B8 02028021 */  addu      $s0, $s0, $v0
/* 3BC61C E00BE6BC 001080C0 */  sll       $s0, $s0, 3
/* 3BC620 E00BE6C0 0C080108 */  jal       shim_guTranslateF
/* 3BC624 E00BE6C4 02038021 */   addu     $s0, $s0, $v1
/* 3BC628 E00BE6C8 27B40050 */  addiu     $s4, $sp, 0x50
/* 3BC62C E00BE6CC 8E450034 */  lw        $a1, 0x34($s2)
/* 3BC630 E00BE6D0 0280202D */  daddu     $a0, $s4, $zero
/* 3BC634 E00BE6D4 00A0302D */  daddu     $a2, $a1, $zero
/* 3BC638 E00BE6D8 0C080110 */  jal       shim_guScaleF
/* 3BC63C E00BE6DC 00A0382D */   daddu    $a3, $a1, $zero
/* 3BC640 E00BE6E0 0280202D */  daddu     $a0, $s4, $zero
/* 3BC644 E00BE6E4 27A50010 */  addiu     $a1, $sp, 0x10
/* 3BC648 E00BE6E8 0C080114 */  jal       shim_guMtxCatF
/* 3BC64C E00BE6EC 00A0302D */   daddu    $a2, $a1, $zero
/* 3BC650 E00BE6F0 27A40010 */  addiu     $a0, $sp, 0x10
/* 3BC654 E00BE6F4 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 3BC658 E00BE6F8 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 3BC65C E00BE6FC 3C17800A */  lui       $s7, %hi(gDisplayContext)
/* 3BC660 E00BE700 26F7A674 */  addiu     $s7, $s7, %lo(gDisplayContext)
/* 3BC664 E00BE704 96A50000 */  lhu       $a1, ($s5)
/* 3BC668 E00BE708 8EE20000 */  lw        $v0, ($s7)
/* 3BC66C E00BE70C 00052980 */  sll       $a1, $a1, 6
/* 3BC670 E00BE710 00B12821 */  addu      $a1, $a1, $s1
/* 3BC674 E00BE714 0C080118 */  jal       shim_guMtxF2L
/* 3BC678 E00BE718 00452821 */   addu     $a1, $v0, $a1
/* 3BC67C E00BE71C 3C03DA38 */  lui       $v1, 0xda38
/* 3BC680 E00BE720 34630002 */  ori       $v1, $v1, 2
/* 3BC684 E00BE724 3C06DA38 */  lui       $a2, 0xda38
/* 3BC688 E00BE728 00D63025 */  or        $a2, $a2, $s6
/* 3BC68C E00BE72C 8E640000 */  lw        $a0, ($s3)
/* 3BC690 E00BE730 96A20000 */  lhu       $v0, ($s5)
/* 3BC694 E00BE734 0080282D */  daddu     $a1, $a0, $zero
/* 3BC698 E00BE738 24840008 */  addiu     $a0, $a0, 8
/* 3BC69C E00BE73C AE640000 */  sw        $a0, ($s3)
/* 3BC6A0 E00BE740 ACA30000 */  sw        $v1, ($a1)
/* 3BC6A4 E00BE744 00561821 */  addu      $v1, $v0, $s6
/* 3BC6A8 E00BE748 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3BC6AC E00BE74C 00021180 */  sll       $v0, $v0, 6
/* 3BC6B0 E00BE750 A6A30000 */  sh        $v1, ($s5)
/* 3BC6B4 E00BE754 8EE30000 */  lw        $v1, ($s7)
/* 3BC6B8 E00BE758 00511021 */  addu      $v0, $v0, $s1
/* 3BC6BC E00BE75C 00621821 */  addu      $v1, $v1, $v0
/* 3BC6C0 E00BE760 24820008 */  addiu     $v0, $a0, 8
/* 3BC6C4 E00BE764 ACA30004 */  sw        $v1, 4($a1)
/* 3BC6C8 E00BE768 AE620000 */  sw        $v0, ($s3)
/* 3BC6CC E00BE76C AC860000 */  sw        $a2, ($a0)
/* 3BC6D0 E00BE770 8E030204 */  lw        $v1, 0x204($s0)
/* 3BC6D4 E00BE774 3C02DE00 */  lui       $v0, 0xde00
/* 3BC6D8 E00BE778 AC820008 */  sw        $v0, 8($a0)
/* 3BC6DC E00BE77C 3C020900 */  lui       $v0, 0x900
/* 3BC6E0 E00BE780 24420100 */  addiu     $v0, $v0, 0x100
/* 3BC6E4 E00BE784 AC82000C */  sw        $v0, 0xc($a0)
/* 3BC6E8 E00BE788 AC830004 */  sw        $v1, 4($a0)
/* 3BC6EC E00BE78C 8FAC00C0 */  lw        $t4, 0xc0($sp)
/* 3BC6F0 E00BE790 26520038 */  addiu     $s2, $s2, 0x38
/* 3BC6F4 E00BE794 8D820008 */  lw        $v0, 8($t4)
/* 3BC6F8 E00BE798 24840010 */  addiu     $a0, $a0, 0x10
/* 3BC6FC E00BE79C 02C2102A */  slt       $v0, $s6, $v0
/* 3BC700 E00BE7A0 104000BB */  beqz      $v0, .LE00BEA90
/* 3BC704 E00BE7A4 AE640000 */   sw       $a0, ($s3)
/* 3BC708 E00BE7A8 0260882D */  daddu     $s1, $s3, $zero
/* 3BC70C E00BE7AC 3C130001 */  lui       $s3, 1
/* 3BC710 E00BE7B0 36731630 */  ori       $s3, $s3, 0x1630
/* 3BC714 E00BE7B4 26500030 */  addiu     $s0, $s2, 0x30
.LE00BE7B8:
/* 3BC718 E00BE7B8 C600FFD4 */  lwc1      $f0, -0x2c($s0)
/* 3BC71C E00BE7BC 4600010D */  trunc.w.s $f4, $f0
/* 3BC720 E00BE7C0 44022000 */  mfc1      $v0, $f4
/* 3BC724 E00BE7C4 8FAC0094 */  lw        $t4, 0x94($sp)
/* 3BC728 E00BE7C8 C600FFD8 */  lwc1      $f0, -0x28($s0)
/* 3BC72C E00BE7CC 004C5021 */  addu      $t2, $v0, $t4
/* 3BC730 E00BE7D0 4600010D */  trunc.w.s $f4, $f0
/* 3BC734 E00BE7D4 44022000 */  mfc1      $v0, $f4
/* 3BC738 E00BE7D8 05410004 */  bgez      $t2, .LE00BE7EC
/* 3BC73C E00BE7DC 005E5821 */   addu     $t3, $v0, $fp
/* 3BC740 E00BE7E0 3142007F */  andi      $v0, $t2, 0x7f
/* 3BC744 E00BE7E4 0802F9FC */  j         .LE00BE7F0
/* 3BC748 E00BE7E8 00025023 */   negu     $t2, $v0
.LE00BE7EC:
/* 3BC74C E00BE7EC 314A007F */  andi      $t2, $t2, 0x7f
.LE00BE7F0:
/* 3BC750 E00BE7F0 19600003 */  blez      $t3, .LE00BE800
/* 3BC754 E00BE7F4 3162003F */   andi     $v0, $t3, 0x3f
/* 3BC758 E00BE7F8 0802FA01 */  j         .LE00BE804
/* 3BC75C E00BE7FC 00025823 */   negu     $t3, $v0
.LE00BE800:
/* 3BC760 E00BE800 316B003F */  andi      $t3, $t3, 0x3f
.LE00BE804:
/* 3BC764 E00BE804 3C02FD10 */  lui       $v0, 0xfd10
/* 3BC768 E00BE808 3442013F */  ori       $v0, $v0, 0x13f
/* 3BC76C E00BE80C 3C07F510 */  lui       $a3, 0xf510
/* 3BC770 E00BE810 34E71100 */  ori       $a3, $a3, 0x1100
/* 3BC774 E00BE814 3C050701 */  lui       $a1, 0x701
/* 3BC778 E00BE818 34A54050 */  ori       $a1, $a1, 0x4050
/* 3BC77C E00BE81C 3C090101 */  lui       $t1, 0x101
/* 3BC780 E00BE820 35294050 */  ori       $t1, $t1, 0x4050
/* 3BC784 E00BE824 3C038000 */  lui       $v1, 0x8000
/* 3BC788 E00BE828 25660078 */  addiu     $a2, $t3, 0x78
/* 3BC78C E00BE82C 00063080 */  sll       $a2, $a2, 2
/* 3BC790 E00BE830 8E280000 */  lw        $t0, ($s1)
/* 3BC794 E00BE834 30C60FFF */  andi      $a2, $a2, 0xfff
/* 3BC798 E00BE838 0100202D */  daddu     $a0, $t0, $zero
/* 3BC79C E00BE83C AC820000 */  sw        $v0, ($a0)
/* 3BC7A0 E00BE840 3C02800A */  lui       $v0, %hi(nuGfxCfb_ptr)
/* 3BC7A4 E00BE844 8C42A64C */  lw        $v0, %lo(nuGfxCfb_ptr)($v0)
/* 3BC7A8 E00BE848 25080008 */  addiu     $t0, $t0, 8
/* 3BC7AC E00BE84C 00431021 */  addu      $v0, $v0, $v1
/* 3BC7B0 E00BE850 AC820004 */  sw        $v0, 4($a0)
/* 3BC7B4 E00BE854 3C02E600 */  lui       $v0, 0xe600
/* 3BC7B8 E00BE858 AD050004 */  sw        $a1, 4($t0)
/* 3BC7BC E00BE85C 254500A0 */  addiu     $a1, $t2, 0xa0
/* 3BC7C0 E00BE860 00052880 */  sll       $a1, $a1, 2
/* 3BC7C4 E00BE864 30A50FFF */  andi      $a1, $a1, 0xfff
/* 3BC7C8 E00BE868 00052B00 */  sll       $a1, $a1, 0xc
/* 3BC7CC E00BE86C AD020008 */  sw        $v0, 8($t0)
/* 3BC7D0 E00BE870 3C02F400 */  lui       $v0, 0xf400
/* 3BC7D4 E00BE874 00C21025 */  or        $v0, $a2, $v0
/* 3BC7D8 E00BE878 00A21025 */  or        $v0, $a1, $v0
/* 3BC7DC E00BE87C 254400BF */  addiu     $a0, $t2, 0xbf
/* 3BC7E0 E00BE880 00042080 */  sll       $a0, $a0, 2
/* 3BC7E4 E00BE884 30840FFF */  andi      $a0, $a0, 0xfff
/* 3BC7E8 E00BE888 00042300 */  sll       $a0, $a0, 0xc
/* 3BC7EC E00BE88C 25630097 */  addiu     $v1, $t3, 0x97
/* 3BC7F0 E00BE890 00031880 */  sll       $v1, $v1, 2
/* 3BC7F4 E00BE894 30630FFF */  andi      $v1, $v1, 0xfff
/* 3BC7F8 E00BE898 AD020010 */  sw        $v0, 0x10($t0)
/* 3BC7FC E00BE89C 3C020700 */  lui       $v0, 0x700
/* 3BC800 E00BE8A0 00621025 */  or        $v0, $v1, $v0
/* 3BC804 E00BE8A4 00821025 */  or        $v0, $a0, $v0
/* 3BC808 E00BE8A8 AD020014 */  sw        $v0, 0x14($t0)
/* 3BC80C E00BE8AC 3C02E700 */  lui       $v0, 0xe700
/* 3BC810 E00BE8B0 AD020018 */  sw        $v0, 0x18($t0)
/* 3BC814 E00BE8B4 3C02F200 */  lui       $v0, 0xf200
/* 3BC818 E00BE8B8 00C23025 */  or        $a2, $a2, $v0
/* 3BC81C E00BE8BC 00A62825 */  or        $a1, $a1, $a2
/* 3BC820 E00BE8C0 3C020100 */  lui       $v0, 0x100
/* 3BC824 E00BE8C4 00621825 */  or        $v1, $v1, $v0
/* 3BC828 E00BE8C8 00832025 */  or        $a0, $a0, $v1
/* 3BC82C E00BE8CC AD04002C */  sw        $a0, 0x2c($t0)
/* 3BC830 E00BE8D0 27A40010 */  addiu     $a0, $sp, 0x10
/* 3BC834 E00BE8D4 AD070000 */  sw        $a3, ($t0)
/* 3BC838 E00BE8D8 AD00000C */  sw        $zero, 0xc($t0)
/* 3BC83C E00BE8DC AD00001C */  sw        $zero, 0x1c($t0)
/* 3BC840 E00BE8E0 AD070020 */  sw        $a3, 0x20($t0)
/* 3BC844 E00BE8E4 AD090024 */  sw        $t1, 0x24($t0)
/* 3BC848 E00BE8E8 AD050028 */  sw        $a1, 0x28($t0)
/* 3BC84C E00BE8EC 8E05FFD4 */  lw        $a1, -0x2c($s0)
/* 3BC850 E00BE8F0 8E06FFD8 */  lw        $a2, -0x28($s0)
/* 3BC854 E00BE8F4 8E07FFDC */  lw        $a3, -0x24($s0)
/* 3BC858 E00BE8F8 25020008 */  addiu     $v0, $t0, 8
/* 3BC85C E00BE8FC AE280000 */  sw        $t0, ($s1)
/* 3BC860 E00BE900 AE220000 */  sw        $v0, ($s1)
/* 3BC864 E00BE904 25020010 */  addiu     $v0, $t0, 0x10
/* 3BC868 E00BE908 AE220000 */  sw        $v0, ($s1)
/* 3BC86C E00BE90C 25020018 */  addiu     $v0, $t0, 0x18
/* 3BC870 E00BE910 AE220000 */  sw        $v0, ($s1)
/* 3BC874 E00BE914 25020020 */  addiu     $v0, $t0, 0x20
/* 3BC878 E00BE918 AE220000 */  sw        $v0, ($s1)
/* 3BC87C E00BE91C 25020028 */  addiu     $v0, $t0, 0x28
/* 3BC880 E00BE920 25080030 */  addiu     $t0, $t0, 0x30
/* 3BC884 E00BE924 AE220000 */  sw        $v0, ($s1)
/* 3BC888 E00BE928 0C080108 */  jal       shim_guTranslateF
/* 3BC88C E00BE92C AE280000 */   sw       $t0, ($s1)
/* 3BC890 E00BE930 8E050004 */  lw        $a1, 4($s0)
/* 3BC894 E00BE934 0280202D */  daddu     $a0, $s4, $zero
/* 3BC898 E00BE938 00A0302D */  daddu     $a2, $a1, $zero
/* 3BC89C E00BE93C 0C080110 */  jal       shim_guScaleF
/* 3BC8A0 E00BE940 00A0382D */   daddu    $a3, $a1, $zero
/* 3BC8A4 E00BE944 0280202D */  daddu     $a0, $s4, $zero
/* 3BC8A8 E00BE948 27A50010 */  addiu     $a1, $sp, 0x10
/* 3BC8AC E00BE94C 0C080114 */  jal       shim_guMtxCatF
/* 3BC8B0 E00BE950 00A0302D */   daddu    $a2, $a1, $zero
/* 3BC8B4 E00BE954 27A40010 */  addiu     $a0, $sp, 0x10
/* 3BC8B8 E00BE958 96A50000 */  lhu       $a1, ($s5)
/* 3BC8BC E00BE95C 8EE20000 */  lw        $v0, ($s7)
/* 3BC8C0 E00BE960 00052980 */  sll       $a1, $a1, 6
/* 3BC8C4 E00BE964 00B32821 */  addu      $a1, $a1, $s3
/* 3BC8C8 E00BE968 0C080118 */  jal       shim_guMtxF2L
/* 3BC8CC E00BE96C 00452821 */   addu     $a1, $v0, $a1
/* 3BC8D0 E00BE970 3C088080 */  lui       $t0, 0x8080
/* 3BC8D4 E00BE974 35088081 */  ori       $t0, $t0, 0x8081
/* 3BC8D8 E00BE978 3C09C8FF */  lui       $t1, 0xc8ff
/* 3BC8DC E00BE97C 3529FF00 */  ori       $t1, $t1, 0xff00
/* 3BC8E0 E00BE980 3C070020 */  lui       $a3, 0x20
/* 3BC8E4 E00BE984 34E72000 */  ori       $a3, $a3, 0x2000
/* 3BC8E8 E00BE988 3C0AD838 */  lui       $t2, 0xd838
/* 3BC8EC E00BE98C 3C02DA38 */  lui       $v0, 0xda38
/* 3BC8F0 E00BE990 8E240000 */  lw        $a0, ($s1)
/* 3BC8F4 E00BE994 96A50000 */  lhu       $a1, ($s5)
/* 3BC8F8 E00BE998 0080302D */  daddu     $a2, $a0, $zero
/* 3BC8FC E00BE99C 24840008 */  addiu     $a0, $a0, 8
/* 3BC900 E00BE9A0 ACC20000 */  sw        $v0, ($a2)
/* 3BC904 E00BE9A4 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 3BC908 E00BE9A8 00021180 */  sll       $v0, $v0, 6
/* 3BC90C E00BE9AC 8EE30000 */  lw        $v1, ($s7)
/* 3BC910 E00BE9B0 00531021 */  addu      $v0, $v0, $s3
/* 3BC914 E00BE9B4 00621821 */  addu      $v1, $v1, $v0
/* 3BC918 E00BE9B8 3C02FA00 */  lui       $v0, 0xfa00
/* 3BC91C E00BE9BC ACC30004 */  sw        $v1, 4($a2)
/* 3BC920 E00BE9C0 AC820000 */  sw        $v0, ($a0)
/* 3BC924 E00BE9C4 8E030000 */  lw        $v1, ($s0)
/* 3BC928 E00BE9C8 24A50001 */  addiu     $a1, $a1, 1
/* 3BC92C E00BE9CC AE240000 */  sw        $a0, ($s1)
/* 3BC930 E00BE9D0 A6A50000 */  sh        $a1, ($s5)
/* 3BC934 E00BE9D4 8FAC0090 */  lw        $t4, 0x90($sp)
/* 3BC938 E00BE9D8 354A0002 */  ori       $t2, $t2, 2
/* 3BC93C E00BE9DC 01830018 */  mult      $t4, $v1
/* 3BC940 E00BE9E0 24820008 */  addiu     $v0, $a0, 8
/* 3BC944 E00BE9E4 AE220000 */  sw        $v0, ($s1)
/* 3BC948 E00BE9E8 24820010 */  addiu     $v0, $a0, 0x10
/* 3BC94C E00BE9EC AE220000 */  sw        $v0, ($s1)
/* 3BC950 E00BE9F0 00001812 */  mflo      $v1
/* 3BC954 E00BE9F4 3C02FB00 */  lui       $v0, 0xfb00
/* 3BC958 E00BE9F8 AC820008 */  sw        $v0, 8($a0)
/* 3BC95C E00BE9FC 00680018 */  mult      $v1, $t0
/* 3BC960 E00BEA00 3C02DE00 */  lui       $v0, 0xde00
/* 3BC964 E00BEA04 AC87000C */  sw        $a3, 0xc($a0)
/* 3BC968 E00BEA08 AC820010 */  sw        $v0, 0x10($a0)
/* 3BC96C E00BEA0C 3C0CE00C */  lui       $t4, %hi(D_E00BEAF0)
/* 3BC970 E00BEA10 258CEAF0 */  addiu     $t4, $t4, %lo(D_E00BEAF0)
/* 3BC974 E00BEA14 00004010 */  mfhi      $t0
/* 3BC978 E00BEA18 01031021 */  addu      $v0, $t0, $v1
/* 3BC97C E00BEA1C 000211C3 */  sra       $v0, $v0, 7
/* 3BC980 E00BEA20 00031FC3 */  sra       $v1, $v1, 0x1f
/* 3BC984 E00BEA24 00431023 */  subu      $v0, $v0, $v1
/* 3BC988 E00BEA28 304200FF */  andi      $v0, $v0, 0xff
/* 3BC98C E00BEA2C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 3BC990 E00BEA30 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 3BC994 E00BEA34 00491025 */  or        $v0, $v0, $t1
/* 3BC998 E00BEA38 AC820004 */  sw        $v0, 4($a0)
/* 3BC99C E00BEA3C 94620134 */  lhu       $v0, 0x134($v1)
/* 3BC9A0 E00BEA40 24830018 */  addiu     $v1, $a0, 0x18
/* 3BC9A4 E00BEA44 AE230000 */  sw        $v1, ($s1)
/* 3BC9A8 E00BEA48 00021042 */  srl       $v0, $v0, 1
/* 3BC9AC E00BEA4C 02C21021 */  addu      $v0, $s6, $v0
/* 3BC9B0 E00BEA50 30420003 */  andi      $v0, $v0, 3
/* 3BC9B4 E00BEA54 00021080 */  sll       $v0, $v0, 2
/* 3BC9B8 E00BEA58 004C1021 */  addu      $v0, $v0, $t4
/* 3BC9BC E00BEA5C 8C430000 */  lw        $v1, ($v0)
/* 3BC9C0 E00BEA60 24820020 */  addiu     $v0, $a0, 0x20
/* 3BC9C4 E00BEA64 AE220000 */  sw        $v0, ($s1)
/* 3BC9C8 E00BEA68 24020040 */  addiu     $v0, $zero, 0x40
/* 3BC9CC E00BEA6C AC8A0018 */  sw        $t2, 0x18($a0)
/* 3BC9D0 E00BEA70 AC82001C */  sw        $v0, 0x1c($a0)
/* 3BC9D4 E00BEA74 AC830014 */  sw        $v1, 0x14($a0)
/* 3BC9D8 E00BEA78 8FAC00C0 */  lw        $t4, 0xc0($sp)
/* 3BC9DC E00BEA7C 8D820008 */  lw        $v0, 8($t4)
/* 3BC9E0 E00BEA80 26D60001 */  addiu     $s6, $s6, 1
/* 3BC9E4 E00BEA84 02C2102A */  slt       $v0, $s6, $v0
/* 3BC9E8 E00BEA88 1440FF4B */  bnez      $v0, .LE00BE7B8
/* 3BC9EC E00BEA8C 26100038 */   addiu    $s0, $s0, 0x38
.LE00BEA90:
/* 3BC9F0 E00BEA90 3C05D838 */  lui       $a1, 0xd838
/* 3BC9F4 E00BEA94 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 3BC9F8 E00BEA98 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 3BC9FC E00BEA9C 8C620000 */  lw        $v0, ($v1)
/* 3BCA00 E00BEAA0 34A50002 */  ori       $a1, $a1, 2
/* 3BCA04 E00BEAA4 0040202D */  daddu     $a0, $v0, $zero
/* 3BCA08 E00BEAA8 24420008 */  addiu     $v0, $v0, 8
/* 3BCA0C E00BEAAC AC620000 */  sw        $v0, ($v1)
/* 3BCA10 E00BEAB0 24020040 */  addiu     $v0, $zero, 0x40
/* 3BCA14 E00BEAB4 AC850000 */  sw        $a1, ($a0)
/* 3BCA18 E00BEAB8 AC820004 */  sw        $v0, 4($a0)
/* 3BCA1C E00BEABC 8FBF00BC */  lw        $ra, 0xbc($sp)
/* 3BCA20 E00BEAC0 8FBE00B8 */  lw        $fp, 0xb8($sp)
/* 3BCA24 E00BEAC4 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 3BCA28 E00BEAC8 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 3BCA2C E00BEACC 8FB500AC */  lw        $s5, 0xac($sp)
/* 3BCA30 E00BEAD0 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 3BCA34 E00BEAD4 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 3BCA38 E00BEAD8 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 3BCA3C E00BEADC 8FB1009C */  lw        $s1, 0x9c($sp)
/* 3BCA40 E00BEAE0 8FB00098 */  lw        $s0, 0x98($sp)
/* 3BCA44 E00BEAE4 03E00008 */  jr        $ra
/* 3BCA48 E00BEAE8 27BD00C0 */   addiu    $sp, $sp, 0xc0
/* 3BCA4C E00BEAEC 00000000 */  nop
