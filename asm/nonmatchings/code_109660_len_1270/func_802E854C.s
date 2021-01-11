.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E854C
/* 109DCC 802E854C 27BDFE80 */  addiu     $sp, $sp, -0x180
/* 109DD0 802E8550 AFBE0148 */  sw        $fp, 0x148($sp)
/* 109DD4 802E8554 0000F02D */  daddu     $fp, $zero, $zero
/* 109DD8 802E8558 27A80098 */  addiu     $t0, $sp, 0x98
/* 109DDC 802E855C AFB5013C */  sw        $s5, 0x13c($sp)
/* 109DE0 802E8560 27B500D8 */  addiu     $s5, $sp, 0xd8
/* 109DE4 802E8564 AFB40138 */  sw        $s4, 0x138($sp)
/* 109DE8 802E8568 27B40058 */  addiu     $s4, $sp, 0x58
/* 109DEC 802E856C AFA8011C */  sw        $t0, 0x11c($sp)
/* 109DF0 802E8570 3C080001 */  lui       $t0, 1
/* 109DF4 802E8574 AFB1012C */  sw        $s1, 0x12c($sp)
/* 109DF8 802E8578 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 109DFC 802E857C 8E31A66C */  lw        $s1, %lo(gMasterGfxPos)($s1)
/* 109E00 802E8580 35081630 */  ori       $t0, $t0, 0x1630
/* 109E04 802E8584 AFBF014C */  sw        $ra, 0x14c($sp)
/* 109E08 802E8588 AFB70144 */  sw        $s7, 0x144($sp)
/* 109E0C 802E858C AFB60140 */  sw        $s6, 0x140($sp)
/* 109E10 802E8590 AFB30134 */  sw        $s3, 0x134($sp)
/* 109E14 802E8594 AFB20130 */  sw        $s2, 0x130($sp)
/* 109E18 802E8598 AFB00128 */  sw        $s0, 0x128($sp)
/* 109E1C 802E859C F7BE0178 */  sdc1      $f30, 0x178($sp)
/* 109E20 802E85A0 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* 109E24 802E85A4 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* 109E28 802E85A8 F7B80160 */  sdc1      $f24, 0x160($sp)
/* 109E2C 802E85AC F7B60158 */  sdc1      $f22, 0x158($sp)
/* 109E30 802E85B0 F7B40150 */  sdc1      $f20, 0x150($sp)
/* 109E34 802E85B4 0C04417A */  jal       get_entity_by_index
/* 109E38 802E85B8 AFA80120 */   sw       $t0, 0x120($sp)
/* 109E3C 802E85BC 0040B82D */  daddu     $s7, $v0, $zero
/* 109E40 802E85C0 3C0143B4 */  lui       $at, 0x43b4
/* 109E44 802E85C4 4481D000 */  mtc1      $at, $f26
/* 109E48 802E85C8 3C013B80 */  lui       $at, 0x3b80
/* 109E4C 802E85CC 4481C000 */  mtc1      $at, $f24
/* 109E50 802E85D0 3C013F80 */  lui       $at, 0x3f80
/* 109E54 802E85D4 4481B000 */  mtc1      $at, $f22
/* 109E58 802E85D8 8EE20040 */  lw        $v0, 0x40($s7)
/* 109E5C 802E85DC 4480A000 */  mtc1      $zero, $f20
/* 109E60 802E85E0 C6E00048 */  lwc1      $f0, 0x48($s7)
/* 109E64 802E85E4 0040902D */  daddu     $s2, $v0, $zero
/* 109E68 802E85E8 0240982D */  daddu     $s3, $s2, $zero
/* 109E6C 802E85EC 2630FFFC */  addiu     $s0, $s1, -4
/* 109E70 802E85F0 46000007 */  neg.s     $f0, $f0
/* 109E74 802E85F4 E7A00118 */  swc1      $f0, 0x118($sp)
/* 109E78 802E85F8 C6E0004C */  lwc1      $f0, 0x4c($s7)
/* 109E7C 802E85FC C6E20050 */  lwc1      $f2, 0x50($s7)
/* 109E80 802E8600 8E560008 */  lw        $s6, 8($s2)
/* 109E84 802E8604 46000787 */  neg.s     $f30, $f0
/* 109E88 802E8608 46001707 */  neg.s     $f28, $f2
.L802E860C:
/* 109E8C 802E860C 82420010 */  lb        $v0, 0x10($s2)
/* 109E90 802E8610 28420002 */  slti      $v0, $v0, 2
/* 109E94 802E8614 1040000F */  beqz      $v0, .L802E8654
/* 109E98 802E8618 3C03E200 */   lui      $v1, 0xe200
/* 109E9C 802E861C 26100008 */  addiu     $s0, $s0, 8
/* 109EA0 802E8620 3463001C */  ori       $v1, $v1, 0x1c
/* 109EA4 802E8624 3C020055 */  lui       $v0, 0x55
/* 109EA8 802E8628 34422078 */  ori       $v0, $v0, 0x2078
/* 109EAC 802E862C AE03FFFC */  sw        $v1, -4($s0)
/* 109EB0 802E8630 AE020000 */  sw        $v0, ($s0)
/* 109EB4 802E8634 26100008 */  addiu     $s0, $s0, 8
/* 109EB8 802E8638 26310010 */  addiu     $s1, $s1, 0x10
/* 109EBC 802E863C 3C03FC12 */  lui       $v1, 0xfc12
/* 109EC0 802E8640 34631824 */  ori       $v1, $v1, 0x1824
/* 109EC4 802E8644 3C02FF33 */  lui       $v0, 0xff33
/* 109EC8 802E8648 3442FFFF */  ori       $v0, $v0, 0xffff
/* 109ECC 802E864C 080BA1A1 */  j         .L802E8684
/* 109ED0 802E8650 AE03FFFC */   sw       $v1, -4($s0)
.L802E8654:
/* 109ED4 802E8654 26100008 */  addiu     $s0, $s0, 8
/* 109ED8 802E8658 3C03FCFF */  lui       $v1, 0xfcff
/* 109EDC 802E865C 3463C3FF */  ori       $v1, $v1, 0xc3ff
/* 109EE0 802E8660 3C02FF30 */  lui       $v0, 0xff30
/* 109EE4 802E8664 3442FE7F */  ori       $v0, $v0, 0xfe7f
/* 109EE8 802E8668 AE03FFFC */  sw        $v1, -4($s0)
/* 109EEC 802E866C AE020000 */  sw        $v0, ($s0)
/* 109EF0 802E8670 26100008 */  addiu     $s0, $s0, 8
/* 109EF4 802E8674 3C02FA00 */  lui       $v0, 0xfa00
/* 109EF8 802E8678 AE02FFFC */  sw        $v0, -4($s0)
/* 109EFC 802E867C 92420034 */  lbu       $v0, 0x34($s2)
/* 109F00 802E8680 26310010 */  addiu     $s1, $s1, 0x10
.L802E8684:
/* 109F04 802E8684 AE020000 */  sw        $v0, ($s0)
/* 109F08 802E8688 8FA50118 */  lw        $a1, 0x118($sp)
/* 109F0C 802E868C 4406F000 */  mfc1      $a2, $f30
/* 109F10 802E8690 4407E000 */  mfc1      $a3, $f28
/* 109F14 802E8694 0C019E40 */  jal       guTranslateF
/* 109F18 802E8698 27A40018 */   addiu    $a0, $sp, 0x18
/* 109F1C 802E869C 92420058 */  lbu       $v0, 0x58($s2)
/* 109F20 802E86A0 44820000 */  mtc1      $v0, $f0
/* 109F24 802E86A4 00000000 */  nop       
/* 109F28 802E86A8 46800020 */  cvt.s.w   $f0, $f0
/* 109F2C 802E86AC 461A0002 */  mul.s     $f0, $f0, $f26
/* 109F30 802E86B0 00000000 */  nop       
/* 109F34 802E86B4 46180002 */  mul.s     $f0, $f0, $f24
/* 109F38 802E86B8 00000000 */  nop       
/* 109F3C 802E86BC 4406B000 */  mfc1      $a2, $f22
/* 109F40 802E86C0 4407A000 */  mfc1      $a3, $f20
/* 109F44 802E86C4 8FA4011C */  lw        $a0, 0x11c($sp)
/* 109F48 802E86C8 44050000 */  mfc1      $a1, $f0
/* 109F4C 802E86CC 0C019EC8 */  jal       guRotateF
/* 109F50 802E86D0 E7B40010 */   swc1     $f20, 0x10($sp)
/* 109F54 802E86D4 9242007C */  lbu       $v0, 0x7c($s2)
/* 109F58 802E86D8 44820000 */  mtc1      $v0, $f0
/* 109F5C 802E86DC 00000000 */  nop       
/* 109F60 802E86E0 46800020 */  cvt.s.w   $f0, $f0
/* 109F64 802E86E4 461A0002 */  mul.s     $f0, $f0, $f26
/* 109F68 802E86E8 00000000 */  nop       
/* 109F6C 802E86EC 26100008 */  addiu     $s0, $s0, 8
/* 109F70 802E86F0 26310018 */  addiu     $s1, $s1, 0x18
/* 109F74 802E86F4 46180002 */  mul.s     $f0, $f0, $f24
/* 109F78 802E86F8 00000000 */  nop       
/* 109F7C 802E86FC 27DE0001 */  addiu     $fp, $fp, 1
/* 109F80 802E8700 02A0202D */  daddu     $a0, $s5, $zero
/* 109F84 802E8704 4406A000 */  mfc1      $a2, $f20
/* 109F88 802E8708 4407B000 */  mfc1      $a3, $f22
/* 109F8C 802E870C 44050000 */  mfc1      $a1, $f0
/* 109F90 802E8710 26520001 */  addiu     $s2, $s2, 1
/* 109F94 802E8714 0C019EC8 */  jal       guRotateF
/* 109F98 802E8718 E7B40010 */   swc1     $f20, 0x10($sp)
/* 109F9C 802E871C 02A0282D */  daddu     $a1, $s5, $zero
/* 109FA0 802E8720 8FA4011C */  lw        $a0, 0x11c($sp)
/* 109FA4 802E8724 0C019D80 */  jal       guMtxCatF
/* 109FA8 802E8728 02A0302D */   daddu    $a2, $s5, $zero
/* 109FAC 802E872C 02A0202D */  daddu     $a0, $s5, $zero
/* 109FB0 802E8730 27A50018 */  addiu     $a1, $sp, 0x18
/* 109FB4 802E8734 0C019D80 */  jal       guMtxCatF
/* 109FB8 802E8738 00A0302D */   daddu    $a2, $a1, $zero
/* 109FBC 802E873C 0280202D */  daddu     $a0, $s4, $zero
/* 109FC0 802E8740 8E650154 */  lw        $a1, 0x154($s3)
/* 109FC4 802E8744 8E6601E4 */  lw        $a2, 0x1e4($s3)
/* 109FC8 802E8748 8E670274 */  lw        $a3, 0x274($s3)
/* 109FCC 802E874C 0C019E40 */  jal       guTranslateF
/* 109FD0 802E8750 26730004 */   addiu    $s3, $s3, 4
/* 109FD4 802E8754 27A40018 */  addiu     $a0, $sp, 0x18
/* 109FD8 802E8758 0280282D */  daddu     $a1, $s4, $zero
/* 109FDC 802E875C 0C019D80 */  jal       guMtxCatF
/* 109FE0 802E8760 0280302D */   daddu    $a2, $s4, $zero
/* 109FE4 802E8764 0280202D */  daddu     $a0, $s4, $zero
/* 109FE8 802E8768 3C058007 */  lui       $a1, %hi(gMatrixListPos)
/* 109FEC 802E876C 94A541F0 */  lhu       $a1, %lo(gMatrixListPos)($a1)
/* 109FF0 802E8770 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* 109FF4 802E8774 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* 109FF8 802E8778 8FA80120 */  lw        $t0, 0x120($sp)
/* 109FFC 802E877C 00052980 */  sll       $a1, $a1, 6
/* 10A000 802E8780 00A82821 */  addu      $a1, $a1, $t0
/* 10A004 802E8784 0C019D40 */  jal       guMtxF2L
/* 10A008 802E8788 00452821 */   addu     $a1, $v0, $a1
/* 10A00C 802E878C 3C05D838 */  lui       $a1, 0xd838
/* 10A010 802E8790 34A50002 */  ori       $a1, $a1, 2
/* 10A014 802E8794 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* 10A018 802E8798 944241F0 */  lhu       $v0, %lo(gMatrixListPos)($v0)
/* 10A01C 802E879C 3C03DA38 */  lui       $v1, 0xda38
/* 10A020 802E87A0 AE03FFFC */  sw        $v1, -4($s0)
/* 10A024 802E87A4 8FA80120 */  lw        $t0, 0x120($sp)
/* 10A028 802E87A8 24430001 */  addiu     $v1, $v0, 1
/* 10A02C 802E87AC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 10A030 802E87B0 00021180 */  sll       $v0, $v0, 6
/* 10A034 802E87B4 3C018007 */  lui       $at, %hi(gMatrixListPos)
/* 10A038 802E87B8 A42341F0 */  sh        $v1, %lo(gMatrixListPos)($at)
/* 10A03C 802E87BC 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* 10A040 802E87C0 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* 10A044 802E87C4 00481021 */  addu      $v0, $v0, $t0
/* 10A048 802E87C8 00621821 */  addu      $v1, $v1, $v0
/* 10A04C 802E87CC AE030000 */  sw        $v1, ($s0)
/* 10A050 802E87D0 96C40002 */  lhu       $a0, 2($s6)
/* 10A054 802E87D4 26D60004 */  addiu     $s6, $s6, 4
/* 10A058 802E87D8 26100008 */  addiu     $s0, $s0, 8
/* 10A05C 802E87DC 8EE30044 */  lw        $v1, 0x44($s7)
/* 10A060 802E87E0 3C02DE00 */  lui       $v0, 0xde00
/* 10A064 802E87E4 AE02FFFC */  sw        $v0, -4($s0)
/* 10A068 802E87E8 24020040 */  addiu     $v0, $zero, 0x40
/* 10A06C 802E87EC 00641821 */  addu      $v1, $v1, $a0
/* 10A070 802E87F0 AE030000 */  sw        $v1, ($s0)
/* 10A074 802E87F4 26100008 */  addiu     $s0, $s0, 8
/* 10A078 802E87F8 AE020000 */  sw        $v0, ($s0)
/* 10A07C 802E87FC 2BC20023 */  slti      $v0, $fp, 0x23
/* 10A080 802E8800 1440FF82 */  bnez      $v0, .L802E860C
/* 10A084 802E8804 AE05FFFC */   sw       $a1, -4($s0)
/* 10A088 802E8808 8FBF014C */  lw        $ra, 0x14c($sp)
/* 10A08C 802E880C 8FBE0148 */  lw        $fp, 0x148($sp)
/* 10A090 802E8810 8FB70144 */  lw        $s7, 0x144($sp)
/* 10A094 802E8814 8FB60140 */  lw        $s6, 0x140($sp)
/* 10A098 802E8818 8FB5013C */  lw        $s5, 0x13c($sp)
/* 10A09C 802E881C 8FB40138 */  lw        $s4, 0x138($sp)
/* 10A0A0 802E8820 8FB30134 */  lw        $s3, 0x134($sp)
/* 10A0A4 802E8824 8FB20130 */  lw        $s2, 0x130($sp)
/* 10A0A8 802E8828 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* 10A0AC 802E882C AC31A66C */  sw        $s1, %lo(gMasterGfxPos)($at)
/* 10A0B0 802E8830 8FB1012C */  lw        $s1, 0x12c($sp)
/* 10A0B4 802E8834 8FB00128 */  lw        $s0, 0x128($sp)
/* 10A0B8 802E8838 D7BE0178 */  ldc1      $f30, 0x178($sp)
/* 10A0BC 802E883C D7BC0170 */  ldc1      $f28, 0x170($sp)
/* 10A0C0 802E8840 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* 10A0C4 802E8844 D7B80160 */  ldc1      $f24, 0x160($sp)
/* 10A0C8 802E8848 D7B60158 */  ldc1      $f22, 0x158($sp)
/* 10A0CC 802E884C D7B40150 */  ldc1      $f20, 0x150($sp)
/* 10A0D0 802E8850 03E00008 */  jr        $ra
/* 10A0D4 802E8854 27BD0180 */   addiu    $sp, $sp, 0x180
