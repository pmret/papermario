.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_80252970_864AE0
.word L80243624_855794, L80243610_855780, L80243624_855794, L80243624_855794, L80243624_855794, L80243624_855794, L80243624_855794, L80243624_855794, L80243624_855794, L80243610_855780, L80243624_855794, L80243624_855794, L80243624_855794, 0, 0, 0

.section .text

glabel func_80243588_8556F8
/* 8556F8 80243588 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 8556FC 8024358C AFB20018 */  sw        $s2, 0x18($sp)
/* 855700 80243590 0080902D */  daddu     $s2, $a0, $zero
/* 855704 80243594 AFB10014 */  sw        $s1, 0x14($sp)
/* 855708 80243598 00A0882D */  daddu     $s1, $a1, $zero
/* 85570C 8024359C AFB7002C */  sw        $s7, 0x2c($sp)
/* 855710 802435A0 00C0B82D */  daddu     $s7, $a2, $zero
/* 855714 802435A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 855718 802435A8 00E0802D */  daddu     $s0, $a3, $zero
/* 85571C 802435AC AFBF0030 */  sw        $ra, 0x30($sp)
/* 855720 802435B0 AFB60028 */  sw        $s6, 0x28($sp)
/* 855724 802435B4 AFB50024 */  sw        $s5, 0x24($sp)
/* 855728 802435B8 AFB40020 */  sw        $s4, 0x20($sp)
/* 85572C 802435BC AFB3001C */  sw        $s3, 0x1c($sp)
/* 855730 802435C0 F7BE0060 */  sdc1      $f30, 0x60($sp)
/* 855734 802435C4 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* 855738 802435C8 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 85573C 802435CC F7B80048 */  sdc1      $f24, 0x48($sp)
/* 855740 802435D0 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 855744 802435D4 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 855748 802435D8 8E160000 */  lw        $s6, ($s0)
/* 85574C 802435DC 0C00EAD2 */  jal       get_npc_safe
/* 855750 802435E0 0000202D */   daddu    $a0, $zero, $zero
/* 855754 802435E4 8C420028 */  lw        $v0, 0x28($v0)
/* 855758 802435E8 3C03FF4A */  lui       $v1, 0xff4a
/* 85575C 802435EC 00431821 */  addu      $v1, $v0, $v1
/* 855760 802435F0 2C62000D */  sltiu     $v0, $v1, 0xd
/* 855764 802435F4 1040000B */  beqz      $v0, L80243624_855794
/* 855768 802435F8 00031080 */   sll      $v0, $v1, 2
/* 85576C 802435FC 3C018025 */  lui       $at, %hi(jtbl_80252970_864AE0)
/* 855770 80243600 00220821 */  addu      $at, $at, $v0
/* 855774 80243604 8C222970 */  lw        $v0, %lo(jtbl_80252970_864AE0)($at)
/* 855778 80243608 00400008 */  jr        $v0
/* 85577C 8024360C 00000000 */   nop
dlabel L80243610_855780
/* 855780 80243610 8E020000 */  lw        $v0, ($s0)
/* 855784 80243614 04410003 */  bgez      $v0, L80243624_855794
/* 855788 80243618 00000000 */   nop
/* 85578C 8024361C 0000B02D */  daddu     $s6, $zero, $zero
/* 855790 80243620 AE000000 */  sw        $zero, ($s0)
dlabel L80243624_855794
/* 855794 80243624 1AE00065 */  blez      $s7, .L802437BC
/* 855798 80243628 0000A02D */   daddu    $s4, $zero, $zero
/* 85579C 8024362C 0220982D */  daddu     $s3, $s1, $zero
/* 8557A0 80243630 3C014220 */  lui       $at, 0x4220
/* 8557A4 80243634 4481F000 */  mtc1      $at, $f30
/* 8557A8 80243638 3C014120 */  lui       $at, 0x4120
/* 8557AC 8024363C 4481E000 */  mtc1      $at, $f28
.L80243640:
/* 8557B0 80243640 86440000 */  lh        $a0, ($s2)
/* 8557B4 80243644 2882001F */  slti      $v0, $a0, 0x1f
/* 8557B8 80243648 54400058 */  bnel      $v0, $zero, .L802437AC
/* 8557BC 8024364C 26730010 */   addiu    $s3, $s3, 0x10
/* 8557C0 80243650 3C026666 */  lui       $v0, 0x6666
/* 8557C4 80243654 34426667 */  ori       $v0, $v0, 0x6667
/* 8557C8 80243658 2483FFE2 */  addiu     $v1, $a0, -0x1e
/* 8557CC 8024365C 00620018 */  mult      $v1, $v0
/* 8557D0 80243660 4480C000 */  mtc1      $zero, $f24
/* 8557D4 80243664 0000802D */  daddu     $s0, $zero, $zero
/* 8557D8 80243668 00031FC3 */  sra       $v1, $v1, 0x1f
/* 8557DC 8024366C 4600C686 */  mov.s     $f26, $f24
/* 8557E0 80243670 00004010 */  mfhi      $t0
/* 8557E4 80243674 00081083 */  sra       $v0, $t0, 2
/* 8557E8 80243678 00438823 */  subu      $s1, $v0, $v1
/* 8557EC 8024367C 00111080 */  sll       $v0, $s1, 2
/* 8557F0 80243680 00511021 */  addu      $v0, $v0, $s1
/* 8557F4 80243684 00021040 */  sll       $v0, $v0, 1
/* 8557F8 80243688 2442001E */  addiu     $v0, $v0, 0x1e
/* 8557FC 8024368C 1A20001D */  blez      $s1, .L80243704
/* 855800 80243690 0082A823 */   subu     $s5, $a0, $v0
.L80243694:
/* 855804 80243694 44966000 */  mtc1      $s6, $f12
/* 855808 80243698 00000000 */  nop
/* 85580C 8024369C 0C00A8BB */  jal       sin_deg
/* 855810 802436A0 46806320 */   cvt.s.w  $f12, $f12
/* 855814 802436A4 44902000 */  mtc1      $s0, $f4
/* 855818 802436A8 00000000 */  nop
/* 85581C 802436AC 46802120 */  cvt.s.w   $f4, $f4
/* 855820 802436B0 461E2083 */  div.s     $f2, $f4, $f30
/* 855824 802436B4 46001082 */  mul.s     $f2, $f2, $f0
/* 855828 802436B8 00000000 */  nop
/* 85582C 802436BC 3C014170 */  lui       $at, 0x4170
/* 855830 802436C0 44813000 */  mtc1      $at, $f6
/* 855834 802436C4 00000000 */  nop
/* 855838 802436C8 46062103 */  div.s     $f4, $f4, $f6
/* 85583C 802436CC 46022580 */  add.s     $f22, $f4, $f2
/* 855840 802436D0 0C00A874 */  jal       cos_rad
/* 855844 802436D4 4600B306 */   mov.s    $f12, $f22
/* 855848 802436D8 461C0002 */  mul.s     $f0, $f0, $f28
/* 85584C 802436DC 00000000 */  nop
/* 855850 802436E0 4600D680 */  add.s     $f26, $f26, $f0
/* 855854 802436E4 0C00A85B */  jal       sin_rad
/* 855858 802436E8 4600B306 */   mov.s    $f12, $f22
/* 85585C 802436EC 461C0002 */  mul.s     $f0, $f0, $f28
/* 855860 802436F0 00000000 */  nop
/* 855864 802436F4 26100001 */  addiu     $s0, $s0, 1
/* 855868 802436F8 0211102A */  slt       $v0, $s0, $s1
/* 85586C 802436FC 1440FFE5 */  bnez      $v0, .L80243694
/* 855870 80243700 4600C600 */   add.s    $f24, $f24, $f0
.L80243704:
/* 855874 80243704 44966000 */  mtc1      $s6, $f12
/* 855878 80243708 00000000 */  nop
/* 85587C 8024370C 0C00A8BB */  jal       sin_deg
/* 855880 80243710 46806320 */   cvt.s.w  $f12, $f12
/* 855884 80243714 44902000 */  mtc1      $s0, $f4
/* 855888 80243718 00000000 */  nop
/* 85588C 8024371C 46802120 */  cvt.s.w   $f4, $f4
/* 855890 80243720 461E2083 */  div.s     $f2, $f4, $f30
/* 855894 80243724 46001082 */  mul.s     $f2, $f2, $f0
/* 855898 80243728 00000000 */  nop
/* 85589C 8024372C 3C014170 */  lui       $at, 0x4170
/* 8558A0 80243730 44813000 */  mtc1      $at, $f6
/* 8558A4 80243734 00000000 */  nop
/* 8558A8 80243738 46062103 */  div.s     $f4, $f4, $f6
/* 8558AC 8024373C 46022580 */  add.s     $f22, $f4, $f2
/* 8558B0 80243740 0C00A874 */  jal       cos_rad
/* 8558B4 80243744 4600B306 */   mov.s    $f12, $f22
/* 8558B8 80243748 4495A000 */  mtc1      $s5, $f20
/* 8558BC 8024374C 00000000 */  nop
/* 8558C0 80243750 4680A520 */  cvt.s.w   $f20, $f20
/* 8558C4 80243754 4600A002 */  mul.s     $f0, $f20, $f0
/* 8558C8 80243758 00000000 */  nop
/* 8558CC 8024375C 4600D680 */  add.s     $f26, $f26, $f0
/* 8558D0 80243760 0C00A85B */  jal       sin_rad
/* 8558D4 80243764 4600B306 */   mov.s    $f12, $f22
/* 8558D8 80243768 4600A502 */  mul.s     $f20, $f20, $f0
/* 8558DC 8024376C 00000000 */  nop
/* 8558E0 80243770 4600D18D */  trunc.w.s $f6, $f26
/* 8558E4 80243774 44023000 */  mfc1      $v0, $f6
/* 8558E8 80243778 00000000 */  nop
/* 8558EC 8024377C A6620000 */  sh        $v0, ($s3)
/* 8558F0 80243780 86420002 */  lh        $v0, 2($s2)
/* 8558F4 80243784 4614C600 */  add.s     $f24, $f24, $f20
/* 8558F8 80243788 44820000 */  mtc1      $v0, $f0
/* 8558FC 8024378C 00000000 */  nop
/* 855900 80243790 46800020 */  cvt.s.w   $f0, $f0
/* 855904 80243794 46180000 */  add.s     $f0, $f0, $f24
/* 855908 80243798 4600018D */  trunc.w.s $f6, $f0
/* 85590C 8024379C 44023000 */  mfc1      $v0, $f6
/* 855910 802437A0 00000000 */  nop
/* 855914 802437A4 A6620002 */  sh        $v0, 2($s3)
/* 855918 802437A8 26730010 */  addiu     $s3, $s3, 0x10
.L802437AC:
/* 85591C 802437AC 26940001 */  addiu     $s4, $s4, 1
/* 855920 802437B0 0297102A */  slt       $v0, $s4, $s7
/* 855924 802437B4 1440FFA2 */  bnez      $v0, .L80243640
/* 855928 802437B8 26520010 */   addiu    $s2, $s2, 0x10
.L802437BC:
/* 85592C 802437BC 8FBF0030 */  lw        $ra, 0x30($sp)
/* 855930 802437C0 8FB7002C */  lw        $s7, 0x2c($sp)
/* 855934 802437C4 8FB60028 */  lw        $s6, 0x28($sp)
/* 855938 802437C8 8FB50024 */  lw        $s5, 0x24($sp)
/* 85593C 802437CC 8FB40020 */  lw        $s4, 0x20($sp)
/* 855940 802437D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 855944 802437D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 855948 802437D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 85594C 802437DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 855950 802437E0 D7BE0060 */  ldc1      $f30, 0x60($sp)
/* 855954 802437E4 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* 855958 802437E8 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 85595C 802437EC D7B80048 */  ldc1      $f24, 0x48($sp)
/* 855960 802437F0 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 855964 802437F4 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 855968 802437F8 03E00008 */  jr        $ra
/* 85596C 802437FC 27BD0068 */   addiu    $sp, $sp, 0x68
