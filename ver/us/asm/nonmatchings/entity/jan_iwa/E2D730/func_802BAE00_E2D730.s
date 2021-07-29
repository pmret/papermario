.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BAE00_E2D730
/* E2D730 802BAE00 27BDFF00 */  addiu     $sp, $sp, -0x100
/* E2D734 802BAE04 AFBF00EC */  sw        $ra, 0xec($sp)
/* E2D738 802BAE08 AFB400E8 */  sw        $s4, 0xe8($sp)
/* E2D73C 802BAE0C AFB300E4 */  sw        $s3, 0xe4($sp)
/* E2D740 802BAE10 AFB200E0 */  sw        $s2, 0xe0($sp)
/* E2D744 802BAE14 AFB100DC */  sw        $s1, 0xdc($sp)
/* E2D748 802BAE18 AFB000D8 */  sw        $s0, 0xd8($sp)
/* E2D74C 802BAE1C F7B600F8 */  sdc1      $f22, 0xf8($sp)
/* E2D750 802BAE20 0C04417A */  jal       get_entity_by_index
/* E2D754 802BAE24 F7B400F0 */   sdc1     $f20, 0xf0($sp)
/* E2D758 802BAE28 27A40018 */  addiu     $a0, $sp, 0x18
/* E2D75C 802BAE2C 0040A02D */  daddu     $s4, $v0, $zero
/* E2D760 802BAE30 3C050A00 */  lui       $a1, 0xa00
/* E2D764 802BAE34 24A50B70 */  addiu     $a1, $a1, 0xb70
/* E2D768 802BAE38 30A5FFFF */  andi      $a1, $a1, 0xffff
/* E2D76C 802BAE3C 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* E2D770 802BAE40 8E73A66C */  lw        $s3, %lo(gMasterGfxPos)($s3)
/* E2D774 802BAE44 8E820044 */  lw        $v0, 0x44($s4)
/* E2D778 802BAE48 8E920040 */  lw        $s2, 0x40($s4)
/* E2D77C 802BAE4C 4480A000 */  mtc1      $zero, $f20
/* E2D780 802BAE50 0C019D60 */  jal       guMtxL2F
/* E2D784 802BAE54 00452821 */   addu     $a1, $v0, $a1
/* E2D788 802BAE58 3C013F80 */  lui       $at, 0x3f80
/* E2D78C 802BAE5C 4481B000 */  mtc1      $at, $f22
/* E2D790 802BAE60 27B10058 */  addiu     $s1, $sp, 0x58
/* E2D794 802BAE64 E7B40010 */  swc1      $f20, 0x10($sp)
/* E2D798 802BAE68 8E450004 */  lw        $a1, 4($s2)
/* E2D79C 802BAE6C 4407A000 */  mfc1      $a3, $f20
/* E2D7A0 802BAE70 4406B000 */  mfc1      $a2, $f22
/* E2D7A4 802BAE74 0C019EC8 */  jal       guRotateF
/* E2D7A8 802BAE78 0220202D */   daddu    $a0, $s1, $zero
/* E2D7AC 802BAE7C 27B00098 */  addiu     $s0, $sp, 0x98
/* E2D7B0 802BAE80 E7B60010 */  swc1      $f22, 0x10($sp)
/* E2D7B4 802BAE84 8E45000C */  lw        $a1, 0xc($s2)
/* E2D7B8 802BAE88 4406A000 */  mfc1      $a2, $f20
/* E2D7BC 802BAE8C 4407A000 */  mfc1      $a3, $f20
/* E2D7C0 802BAE90 0C019EC8 */  jal       guRotateF
/* E2D7C4 802BAE94 0200202D */   daddu    $a0, $s0, $zero
/* E2D7C8 802BAE98 0220202D */  daddu     $a0, $s1, $zero
/* E2D7CC 802BAE9C 0200282D */  daddu     $a1, $s0, $zero
/* E2D7D0 802BAEA0 0C019D80 */  jal       guMtxCatF
/* E2D7D4 802BAEA4 0200302D */   daddu    $a2, $s0, $zero
/* E2D7D8 802BAEA8 E7B40010 */  swc1      $f20, 0x10($sp)
/* E2D7DC 802BAEAC 8E450008 */  lw        $a1, 8($s2)
/* E2D7E0 802BAEB0 4406A000 */  mfc1      $a2, $f20
/* E2D7E4 802BAEB4 4407B000 */  mfc1      $a3, $f22
/* E2D7E8 802BAEB8 0C019EC8 */  jal       guRotateF
/* E2D7EC 802BAEBC 0220202D */   daddu    $a0, $s1, $zero
/* E2D7F0 802BAEC0 0200202D */  daddu     $a0, $s0, $zero
/* E2D7F4 802BAEC4 0220282D */  daddu     $a1, $s1, $zero
/* E2D7F8 802BAEC8 0C019D80 */  jal       guMtxCatF
/* E2D7FC 802BAECC 0220302D */   daddu    $a2, $s1, $zero
/* E2D800 802BAED0 0220202D */  daddu     $a0, $s1, $zero
/* E2D804 802BAED4 27A50018 */  addiu     $a1, $sp, 0x18
/* E2D808 802BAED8 0C019D80 */  jal       guMtxCatF
/* E2D80C 802BAEDC 00A0302D */   daddu    $a2, $a1, $zero
/* E2D810 802BAEE0 27A40018 */  addiu     $a0, $sp, 0x18
/* E2D814 802BAEE4 26500030 */  addiu     $s0, $s2, 0x30
/* E2D818 802BAEE8 0C019D40 */  jal       guMtxF2L
/* E2D81C 802BAEEC 0200282D */   daddu    $a1, $s0, $zero
/* E2D820 802BAEF0 3C040001 */  lui       $a0, 1
/* E2D824 802BAEF4 34841630 */  ori       $a0, $a0, 0x1630
/* E2D828 802BAEF8 26520070 */  addiu     $s2, $s2, 0x70
/* E2D82C 802BAEFC 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* E2D830 802BAF00 944241F0 */  lhu       $v0, %lo(gMatrixListPos)($v0)
/* E2D834 802BAF04 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* E2D838 802BAF08 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* E2D83C 802BAF0C 00021180 */  sll       $v0, $v0, 6
/* E2D840 802BAF10 00621821 */  addu      $v1, $v1, $v0
/* E2D844 802BAF14 00641821 */  addu      $v1, $v1, $a0
.L802BAF18:
/* E2D848 802BAF18 8E0A0000 */  lw        $t2, ($s0)
/* E2D84C 802BAF1C 8E0B0004 */  lw        $t3, 4($s0)
/* E2D850 802BAF20 8E0C0008 */  lw        $t4, 8($s0)
/* E2D854 802BAF24 8E0D000C */  lw        $t5, 0xc($s0)
/* E2D858 802BAF28 AC6A0000 */  sw        $t2, ($v1)
/* E2D85C 802BAF2C AC6B0004 */  sw        $t3, 4($v1)
/* E2D860 802BAF30 AC6C0008 */  sw        $t4, 8($v1)
/* E2D864 802BAF34 AC6D000C */  sw        $t5, 0xc($v1)
/* E2D868 802BAF38 26100010 */  addiu     $s0, $s0, 0x10
/* E2D86C 802BAF3C 1612FFF6 */  bne       $s0, $s2, .L802BAF18
/* E2D870 802BAF40 24630010 */   addiu    $v1, $v1, 0x10
/* E2D874 802BAF44 0260282D */  daddu     $a1, $s3, $zero
/* E2D878 802BAF48 26730008 */  addiu     $s3, $s3, 8
/* E2D87C 802BAF4C 3C080001 */  lui       $t0, 1
/* E2D880 802BAF50 35081630 */  ori       $t0, $t0, 0x1630
/* E2D884 802BAF54 0260302D */  daddu     $a2, $s3, $zero
/* E2D888 802BAF58 26730008 */  addiu     $s3, $s3, 8
/* E2D88C 802BAF5C 0260382D */  daddu     $a3, $s3, $zero
/* E2D890 802BAF60 26730008 */  addiu     $s3, $s3, 8
/* E2D894 802BAF64 3C09D838 */  lui       $t1, 0xd838
/* E2D898 802BAF68 35290002 */  ori       $t1, $t1, 2
/* E2D89C 802BAF6C 3C048007 */  lui       $a0, %hi(gMatrixListPos)
/* E2D8A0 802BAF70 248441F0 */  addiu     $a0, $a0, %lo(gMatrixListPos)
/* E2D8A4 802BAF74 94820000 */  lhu       $v0, ($a0)
/* E2D8A8 802BAF78 3C03DA38 */  lui       $v1, 0xda38
/* E2D8AC 802BAF7C ACA30000 */  sw        $v1, ($a1)
/* E2D8B0 802BAF80 3C01800A */  lui       $at, %hi(gMasterGfxPos)
/* E2D8B4 802BAF84 AC33A66C */  sw        $s3, %lo(gMasterGfxPos)($at)
/* E2D8B8 802BAF88 24430001 */  addiu     $v1, $v0, 1
/* E2D8BC 802BAF8C 3042FFFF */  andi      $v0, $v0, 0xffff
/* E2D8C0 802BAF90 00021180 */  sll       $v0, $v0, 6
/* E2D8C4 802BAF94 A4830000 */  sh        $v1, ($a0)
/* E2D8C8 802BAF98 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* E2D8CC 802BAF9C 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* E2D8D0 802BAFA0 00481021 */  addu      $v0, $v0, $t0
/* E2D8D4 802BAFA4 00621821 */  addu      $v1, $v1, $v0
/* E2D8D8 802BAFA8 ACA30004 */  sw        $v1, 4($a1)
/* E2D8DC 802BAFAC 8E830044 */  lw        $v1, 0x44($s4)
/* E2D8E0 802BAFB0 3C02DE00 */  lui       $v0, 0xde00
/* E2D8E4 802BAFB4 ACC20000 */  sw        $v0, ($a2)
/* E2D8E8 802BAFB8 3C020A00 */  lui       $v0, 0xa00
/* E2D8EC 802BAFBC 24420D18 */  addiu     $v0, $v0, 0xd18
/* E2D8F0 802BAFC0 3042FFFF */  andi      $v0, $v0, 0xffff
/* E2D8F4 802BAFC4 00621821 */  addu      $v1, $v1, $v0
/* E2D8F8 802BAFC8 24020040 */  addiu     $v0, $zero, 0x40
/* E2D8FC 802BAFCC ACC30004 */  sw        $v1, 4($a2)
/* E2D900 802BAFD0 ACE90000 */  sw        $t1, ($a3)
/* E2D904 802BAFD4 ACE20004 */  sw        $v0, 4($a3)
/* E2D908 802BAFD8 8FBF00EC */  lw        $ra, 0xec($sp)
/* E2D90C 802BAFDC 8FB400E8 */  lw        $s4, 0xe8($sp)
/* E2D910 802BAFE0 8FB300E4 */  lw        $s3, 0xe4($sp)
/* E2D914 802BAFE4 8FB200E0 */  lw        $s2, 0xe0($sp)
/* E2D918 802BAFE8 8FB100DC */  lw        $s1, 0xdc($sp)
/* E2D91C 802BAFEC 8FB000D8 */  lw        $s0, 0xd8($sp)
/* E2D920 802BAFF0 D7B600F8 */  ldc1      $f22, 0xf8($sp)
/* E2D924 802BAFF4 D7B400F0 */  ldc1      $f20, 0xf0($sp)
/* E2D928 802BAFF8 03E00008 */  jr        $ra
/* E2D92C 802BAFFC 27BD0100 */   addiu    $sp, $sp, 0x100
