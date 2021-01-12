.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BBE3C_E2C56C
/* E2C56C 802BBE3C 27BDFE80 */  addiu     $sp, $sp, -0x180
/* E2C570 802BBE40 AFBE0148 */  sw        $fp, 0x148($sp)
/* E2C574 802BBE44 0000F02D */  daddu     $fp, $zero, $zero
/* E2C578 802BBE48 27A80098 */  addiu     $t0, $sp, 0x98
/* E2C57C 802BBE4C AFB5013C */  sw        $s5, 0x13c($sp)
/* E2C580 802BBE50 27B500D8 */  addiu     $s5, $sp, 0xd8
/* E2C584 802BBE54 AFB40138 */  sw        $s4, 0x138($sp)
/* E2C588 802BBE58 27B40058 */  addiu     $s4, $sp, 0x58
/* E2C58C 802BBE5C AFA8011C */  sw        $t0, 0x11c($sp)
/* E2C590 802BBE60 3C080001 */  lui       $t0, 1
/* E2C594 802BBE64 AFB1012C */  sw        $s1, 0x12c($sp)
/* E2C598 802BBE68 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* E2C59C 802BBE6C 8E31A66C */  lw        $s1, %lo(gMasterGfxPos)($s1)
/* E2C5A0 802BBE70 35081630 */  ori       $t0, $t0, 0x1630
/* E2C5A4 802BBE74 AFBF014C */  sw        $ra, 0x14c($sp)
/* E2C5A8 802BBE78 AFB70144 */  sw        $s7, 0x144($sp)
/* E2C5AC 802BBE7C AFB60140 */  sw        $s6, 0x140($sp)
/* E2C5B0 802BBE80 AFB30134 */  sw        $s3, 0x134($sp)
/* E2C5B4 802BBE84 AFB20130 */  sw        $s2, 0x130($sp)
/* E2C5B8 802BBE88 AFB00128 */  sw        $s0, 0x128($sp)
/* E2C5BC 802BBE8C F7BE0178 */  sdc1      $f30, 0x178($sp)
/* E2C5C0 802BBE90 F7BC0170 */  sdc1      $f28, 0x170($sp)
/* E2C5C4 802BBE94 F7BA0168 */  sdc1      $f26, 0x168($sp)
/* E2C5C8 802BBE98 F7B80160 */  sdc1      $f24, 0x160($sp)
/* E2C5CC 802BBE9C F7B60158 */  sdc1      $f22, 0x158($sp)
/* E2C5D0 802BBEA0 F7B40150 */  sdc1      $f20, 0x150($sp)
/* E2C5D4 802BBEA4 0C04417A */  jal       get_entity_by_index
/* E2C5D8 802BBEA8 AFA80120 */   sw       $t0, 0x120($sp)
/* E2C5DC 802BBEAC 0040B82D */  daddu     $s7, $v0, $zero
/* E2C5E0 802BBEB0 3C0143B4 */  lui       $at, 0x43b4
/* E2C5E4 802BBEB4 4481D000 */  mtc1      $at, $f26
/* E2C5E8 802BBEB8 3C013B80 */  lui       $at, 0x3b80
/* E2C5EC 802BBEBC 4481C000 */  mtc1      $at, $f24
/* E2C5F0 802BBEC0 3C013F80 */  lui       $at, 0x3f80
/* E2C5F4 802BBEC4 4481B000 */  mtc1      $at, $f22
/* E2C5F8 802BBEC8 8EE20040 */  lw        $v0, 0x40($s7)
/* E2C5FC 802BBECC 4480A000 */  mtc1      $zero, $f20
/* E2C600 802BBED0 C6E00048 */  lwc1      $f0, 0x48($s7)
/* E2C604 802BBED4 0040902D */  daddu     $s2, $v0, $zero
/* E2C608 802BBED8 0240982D */  daddu     $s3, $s2, $zero
/* E2C60C 802BBEDC 2630FFFC */  addiu     $s0, $s1, -4
/* E2C610 802BBEE0 46000007 */  neg.s     $f0, $f0
/* E2C614 802BBEE4 E7A00118 */  swc1      $f0, 0x118($sp)
/* E2C618 802BBEE8 C6E0004C */  lwc1      $f0, 0x4c($s7)
/* E2C61C 802BBEEC C6E20050 */  lwc1      $f2, 0x50($s7)
/* E2C620 802BBEF0 8E560000 */  lw        $s6, ($s2)
/* E2C624 802BBEF4 46000787 */  neg.s     $f30, $f0
/* E2C628 802BBEF8 46001707 */  neg.s     $f28, $f2
.L802BBEFC:
/* E2C62C 802BBEFC 82420008 */  lb        $v0, 8($s2)
/* E2C630 802BBF00 28420002 */  slti      $v0, $v0, 2
/* E2C634 802BBF04 1040000F */  beqz      $v0, .L802BBF44
/* E2C638 802BBF08 3C03E200 */   lui      $v1, 0xe200
/* E2C63C 802BBF0C 26100008 */  addiu     $s0, $s0, 8
/* E2C640 802BBF10 3463001C */  ori       $v1, $v1, 0x1c
/* E2C644 802BBF14 3C020055 */  lui       $v0, 0x55
/* E2C648 802BBF18 34422078 */  ori       $v0, $v0, 0x2078
/* E2C64C 802BBF1C AE03FFFC */  sw        $v1, -4($s0)
/* E2C650 802BBF20 AE020000 */  sw        $v0, ($s0)
/* E2C654 802BBF24 26100008 */  addiu     $s0, $s0, 8
/* E2C658 802BBF28 26310010 */  addiu     $s1, $s1, 0x10
/* E2C65C 802BBF2C 3C03FC12 */  lui       $v1, 0xfc12
/* E2C660 802BBF30 34631824 */  ori       $v1, $v1, 0x1824
/* E2C664 802BBF34 3C02FF33 */  lui       $v0, 0xff33
/* E2C668 802BBF38 3442FFFF */  ori       $v0, $v0, 0xffff
/* E2C66C 802BBF3C 080AEFDD */  j         .L802BBF74
/* E2C670 802BBF40 AE03FFFC */   sw       $v1, -4($s0)
.L802BBF44:
/* E2C674 802BBF44 26100008 */  addiu     $s0, $s0, 8
/* E2C678 802BBF48 3C03FCFF */  lui       $v1, 0xfcff
/* E2C67C 802BBF4C 3463C3FF */  ori       $v1, $v1, 0xc3ff
/* E2C680 802BBF50 3C02FF30 */  lui       $v0, 0xff30
/* E2C684 802BBF54 3442FE7F */  ori       $v0, $v0, 0xfe7f
/* E2C688 802BBF58 AE03FFFC */  sw        $v1, -4($s0)
/* E2C68C 802BBF5C AE020000 */  sw        $v0, ($s0)
/* E2C690 802BBF60 26100008 */  addiu     $s0, $s0, 8
/* E2C694 802BBF64 3C02FA00 */  lui       $v0, 0xfa00
/* E2C698 802BBF68 AE02FFFC */  sw        $v0, -4($s0)
/* E2C69C 802BBF6C 92420015 */  lbu       $v0, 0x15($s2)
/* E2C6A0 802BBF70 26310010 */  addiu     $s1, $s1, 0x10
.L802BBF74:
/* E2C6A4 802BBF74 AE020000 */  sw        $v0, ($s0)
/* E2C6A8 802BBF78 8FA50118 */  lw        $a1, 0x118($sp)
/* E2C6AC 802BBF7C 4406F000 */  mfc1      $a2, $f30
/* E2C6B0 802BBF80 4407E000 */  mfc1      $a3, $f28
/* E2C6B4 802BBF84 0C019E40 */  jal       guTranslateF
/* E2C6B8 802BBF88 27A40018 */   addiu    $a0, $sp, 0x18
/* E2C6BC 802BBF8C 92420022 */  lbu       $v0, 0x22($s2)
/* E2C6C0 802BBF90 44820000 */  mtc1      $v0, $f0
/* E2C6C4 802BBF94 00000000 */  nop       
/* E2C6C8 802BBF98 46800020 */  cvt.s.w   $f0, $f0
/* E2C6CC 802BBF9C 461A0002 */  mul.s     $f0, $f0, $f26
/* E2C6D0 802BBFA0 00000000 */  nop       
/* E2C6D4 802BBFA4 46180002 */  mul.s     $f0, $f0, $f24
/* E2C6D8 802BBFA8 00000000 */  nop       
/* E2C6DC 802BBFAC 4406B000 */  mfc1      $a2, $f22
/* E2C6E0 802BBFB0 4407A000 */  mfc1      $a3, $f20
/* E2C6E4 802BBFB4 8FA4011C */  lw        $a0, 0x11c($sp)
/* E2C6E8 802BBFB8 44050000 */  mfc1      $a1, $f0
/* E2C6EC 802BBFBC 0C019EC8 */  jal       guRotateF
/* E2C6F0 802BBFC0 E7B40010 */   swc1     $f20, 0x10($sp)
/* E2C6F4 802BBFC4 9242002F */  lbu       $v0, 0x2f($s2)
/* E2C6F8 802BBFC8 44820000 */  mtc1      $v0, $f0
/* E2C6FC 802BBFCC 00000000 */  nop       
/* E2C700 802BBFD0 46800020 */  cvt.s.w   $f0, $f0
/* E2C704 802BBFD4 461A0002 */  mul.s     $f0, $f0, $f26
/* E2C708 802BBFD8 00000000 */  nop       
/* E2C70C 802BBFDC 26100008 */  addiu     $s0, $s0, 8
/* E2C710 802BBFE0 26310018 */  addiu     $s1, $s1, 0x18
/* E2C714 802BBFE4 46180002 */  mul.s     $f0, $f0, $f24
/* E2C718 802BBFE8 00000000 */  nop       
/* E2C71C 802BBFEC 27DE0001 */  addiu     $fp, $fp, 1
/* E2C720 802BBFF0 02A0202D */  daddu     $a0, $s5, $zero
/* E2C724 802BBFF4 4406A000 */  mfc1      $a2, $f20
/* E2C728 802BBFF8 4407B000 */  mfc1      $a3, $f22
/* E2C72C 802BBFFC 44050000 */  mfc1      $a1, $f0
/* E2C730 802BC000 26520001 */  addiu     $s2, $s2, 1
/* E2C734 802BC004 0C019EC8 */  jal       guRotateF
/* E2C738 802BC008 E7B40010 */   swc1     $f20, 0x10($sp)
/* E2C73C 802BC00C 02A0282D */  daddu     $a1, $s5, $zero
/* E2C740 802BC010 8FA4011C */  lw        $a0, 0x11c($sp)
/* E2C744 802BC014 0C019D80 */  jal       guMtxCatF
/* E2C748 802BC018 02A0302D */   daddu    $a2, $s5, $zero
/* E2C74C 802BC01C 02A0202D */  daddu     $a0, $s5, $zero
/* E2C750 802BC020 27A50018 */  addiu     $a1, $sp, 0x18
/* E2C754 802BC024 0C019D80 */  jal       guMtxCatF
/* E2C758 802BC028 00A0302D */   daddu    $a2, $a1, $zero
/* E2C75C 802BC02C 0280202D */  daddu     $a0, $s4, $zero
/* E2C760 802BC030 8E650080 */  lw        $a1, 0x80($s3)
/* E2C764 802BC034 8E6600B4 */  lw        $a2, 0xb4($s3)
/* E2C768 802BC038 8E6700E8 */  lw        $a3, 0xe8($s3)
/* E2C76C 802BC03C 0C019E40 */  jal       guTranslateF
/* E2C770 802BC040 26730004 */   addiu    $s3, $s3, 4
/* E2C774 802BC044 27A40018 */  addiu     $a0, $sp, 0x18
/* E2C778 802BC048 0280282D */  daddu     $a1, $s4, $zero
/* E2C77C 802BC04C 0C019D80 */  jal       guMtxCatF
/* E2C780 802BC050 0280302D */   daddu    $a2, $s4, $zero
/* E2C784 802BC054 0280202D */  daddu     $a0, $s4, $zero
/* E2C788 802BC058 3C058007 */  lui       $a1, %hi(gMatrixListPos)
/* E2C78C 802BC05C 94A541F0 */  lhu       $a1, %lo(gMatrixListPos)($a1)
/* E2C790 802BC060 3C02800A */  lui       $v0, %hi(gDisplayContext)
/* E2C794 802BC064 8C42A674 */  lw        $v0, %lo(gDisplayContext)($v0)
/* E2C798 802BC068 8FA80120 */  lw        $t0, 0x120($sp)
/* E2C79C 802BC06C 00052980 */  sll       $a1, $a1, 6
/* E2C7A0 802BC070 00A82821 */  addu      $a1, $a1, $t0
/* E2C7A4 802BC074 0C019D40 */  jal       guMtxF2L
/* E2C7A8 802BC078 00452821 */   addu     $a1, $v0, $a1
/* E2C7AC 802BC07C 3C05D838 */  lui       $a1, 0xd838
/* E2C7B0 802BC080 34A50002 */  ori       $a1, $a1, 2
/* E2C7B4 802BC084 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* E2C7B8 802BC088 944241F0 */  lhu       $v0, %lo(gMatrixListPos)($v0)
/* E2C7BC 802BC08C 3C03DA38 */  lui       $v1, 0xda38
/* E2C7C0 802BC090 AE03FFFC */  sw        $v1, -4($s0)
/* E2C7C4 802BC094 8FA80120 */  lw        $t0, 0x120($sp)
/* E2C7C8 802BC098 24430001 */  addiu     $v1, $v0, 1
/* E2C7CC 802BC09C 3042FFFF */  andi      $v0, $v0, 0xffff
/* E2C7D0 802BC0A0 00021180 */  sll       $v0, $v0, 6
/* E2C7D4 802BC0A4 3C018007 */  lui       $at, %hi(gMatrixListPos)
/* E2C7D8 802BC0A8 A42341F0 */  sh        $v1, %lo(gMatrixListPos)($at)
/* E2C7DC 802BC0AC 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* E2C7E0 802BC0B0 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* E2C7E4 802BC0B4 00481021 */  addu      $v0, $v0, $t0
/* E2C7E8 802BC0B8 00621821 */  addu      $v1, $v1, $v0
/* E2C7EC 802BC0BC AE030000 */  sw        $v1, ($s0)
/* E2C7F0 802BC0C0 96C40002 */  lhu       $a0, 2($s6)
/* E2C7F4 802BC0C4 26D60004 */  addiu     $s6, $s6, 4
/* E2C7F8 802BC0C8 26100008 */  addiu     $s0, $s0, 8
/* E2C7FC 802BC0CC 8EE30044 */  lw        $v1, 0x44($s7)
/* E2C800 802BC0D0 3C02DE00 */  lui       $v0, 0xde00
/* E2C804 802BC0D4 AE02FFFC */  sw        $v0, -4($s0)
/* E2C808 802BC0D8 24020040 */  addiu     $v0, $zero, 0x40
/* E2C80C 802BC0DC 00641821 */  addu      $v1, $v1, $a0
/* E2C810 802BC0E0 AE030000 */  sw        $v1, ($s0)
/* E2C814 802BC0E4 26100008 */  addiu     $s0, $s0, 8
/* E2C818 802BC0E8 AE020000 */  sw        $v0, ($s0)
/* E2C81C 802BC0EC 2BC2000C */  slti      $v0, $fp, 0xc
/* E2C820 802BC0F0 1440FF82 */  bnez      $v0, .L802BBEFC
/* E2C824 802BC0F4 AE05FFFC */   sw       $a1, -4($s0)
/* E2C828 802BC0F8 8FBF014C */  lw        $ra, 0x14c($sp)
/* E2C82C 802BC0FC 8FBE0148 */  lw        $fp, 0x148($sp)
/* E2C830 802BC100 8FB70144 */  lw        $s7, 0x144($sp)
/* E2C834 802BC104 8FB60140 */  lw        $s6, 0x140($sp)
/* E2C838 802BC108 8FB5013C */  lw        $s5, 0x13c($sp)
/* E2C83C 802BC10C 8FB40138 */  lw        $s4, 0x138($sp)
/* E2C840 802BC110 8FB30134 */  lw        $s3, 0x134($sp)
/* E2C844 802BC114 8FB20130 */  lw        $s2, 0x130($sp)
/* E2C848 802BC118 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* E2C84C 802BC11C AC31A66C */  sw        $s1, %lo(gMasterGfxPos)($at)
/* E2C850 802BC120 8FB1012C */  lw        $s1, 0x12c($sp)
/* E2C854 802BC124 8FB00128 */  lw        $s0, 0x128($sp)
/* E2C858 802BC128 D7BE0178 */  ldc1      $f30, 0x178($sp)
/* E2C85C 802BC12C D7BC0170 */  ldc1      $f28, 0x170($sp)
/* E2C860 802BC130 D7BA0168 */  ldc1      $f26, 0x168($sp)
/* E2C864 802BC134 D7B80160 */  ldc1      $f24, 0x160($sp)
/* E2C868 802BC138 D7B60158 */  ldc1      $f22, 0x158($sp)
/* E2C86C 802BC13C D7B40150 */  ldc1      $f20, 0x150($sp)
/* E2C870 802BC140 03E00008 */  jr        $ra
/* E2C874 802BC144 27BD0180 */   addiu    $sp, $sp, 0x180
