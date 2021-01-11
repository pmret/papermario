.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BAE00_E2F750
/* E2F750 802BAE00 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* E2F754 802BAE04 AFBF00A4 */  sw        $ra, 0xa4($sp)
/* E2F758 802BAE08 AFB200A0 */  sw        $s2, 0xa0($sp)
/* E2F75C 802BAE0C AFB1009C */  sw        $s1, 0x9c($sp)
/* E2F760 802BAE10 0C04417A */  jal       get_entity_by_index
/* E2F764 802BAE14 AFB00098 */   sw       $s0, 0x98($sp)
/* E2F768 802BAE18 27A40018 */  addiu     $a0, $sp, 0x18
/* E2F76C 802BAE1C 0040902D */  daddu     $s2, $v0, $zero
/* E2F770 802BAE20 3C050A00 */  lui       $a1, 0xa00
/* E2F774 802BAE24 24A51968 */  addiu     $a1, $a1, 0x1968
/* E2F778 802BAE28 30A5FFFF */  andi      $a1, $a1, 0xffff
/* E2F77C 802BAE2C 8E420044 */  lw        $v0, 0x44($s2)
/* E2F780 802BAE30 8E510040 */  lw        $s1, 0x40($s2)
/* E2F784 802BAE34 0C019D60 */  jal       guMtxL2F
/* E2F788 802BAE38 00452821 */   addu     $a1, $v0, $a1
/* E2F78C 802BAE3C 44800000 */  mtc1      $zero, $f0
/* E2F790 802BAE40 3C073F80 */  lui       $a3, 0x3f80
/* E2F794 802BAE44 27B00058 */  addiu     $s0, $sp, 0x58
/* E2F798 802BAE48 E7A00010 */  swc1      $f0, 0x10($sp)
/* E2F79C 802BAE4C 8E250008 */  lw        $a1, 8($s1)
/* E2F7A0 802BAE50 44060000 */  mfc1      $a2, $f0
/* E2F7A4 802BAE54 0C019EC8 */  jal       guRotateF
/* E2F7A8 802BAE58 0200202D */   daddu    $a0, $s0, $zero
/* E2F7AC 802BAE5C 0200202D */  daddu     $a0, $s0, $zero
/* E2F7B0 802BAE60 27A50018 */  addiu     $a1, $sp, 0x18
/* E2F7B4 802BAE64 0C019D80 */  jal       guMtxCatF
/* E2F7B8 802BAE68 00A0302D */   daddu    $a2, $a1, $zero
/* E2F7BC 802BAE6C 27A40018 */  addiu     $a0, $sp, 0x18
/* E2F7C0 802BAE70 26300010 */  addiu     $s0, $s1, 0x10
/* E2F7C4 802BAE74 0C019D40 */  jal       guMtxF2L
/* E2F7C8 802BAE78 0200282D */   daddu    $a1, $s0, $zero
/* E2F7CC 802BAE7C 3C040001 */  lui       $a0, 1
/* E2F7D0 802BAE80 34841630 */  ori       $a0, $a0, 0x1630
/* E2F7D4 802BAE84 26310050 */  addiu     $s1, $s1, 0x50
/* E2F7D8 802BAE88 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* E2F7DC 802BAE8C 944241F0 */  lhu       $v0, %lo(gMatrixListPos)($v0)
/* E2F7E0 802BAE90 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* E2F7E4 802BAE94 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* E2F7E8 802BAE98 00021180 */  sll       $v0, $v0, 6
/* E2F7EC 802BAE9C 00621821 */  addu      $v1, $v1, $v0
/* E2F7F0 802BAEA0 00641821 */  addu      $v1, $v1, $a0
.L802BAEA4:
/* E2F7F4 802BAEA4 8E0A0000 */  lw        $t2, ($s0)
/* E2F7F8 802BAEA8 8E0B0004 */  lw        $t3, 4($s0)
/* E2F7FC 802BAEAC 8E0C0008 */  lw        $t4, 8($s0)
/* E2F800 802BAEB0 8E0D000C */  lw        $t5, 0xc($s0)
/* E2F804 802BAEB4 AC6A0000 */  sw        $t2, ($v1)
/* E2F808 802BAEB8 AC6B0004 */  sw        $t3, 4($v1)
/* E2F80C 802BAEBC AC6C0008 */  sw        $t4, 8($v1)
/* E2F810 802BAEC0 AC6D000C */  sw        $t5, 0xc($v1)
/* E2F814 802BAEC4 26100010 */  addiu     $s0, $s0, 0x10
/* E2F818 802BAEC8 1611FFF6 */  bne       $s0, $s1, .L802BAEA4
/* E2F81C 802BAECC 24630010 */   addiu    $v1, $v1, 0x10
/* E2F820 802BAED0 3C080001 */  lui       $t0, 1
/* E2F824 802BAED4 35081630 */  ori       $t0, $t0, 0x1630
/* E2F828 802BAED8 3C09D838 */  lui       $t1, 0xd838
/* E2F82C 802BAEDC 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* E2F830 802BAEE0 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* E2F834 802BAEE4 35290002 */  ori       $t1, $t1, 2
/* E2F838 802BAEE8 8CC40000 */  lw        $a0, ($a2)
/* E2F83C 802BAEEC 3C058007 */  lui       $a1, %hi(gMatrixListPos)
/* E2F840 802BAEF0 24A541F0 */  addiu     $a1, $a1, %lo(gMatrixListPos)
/* E2F844 802BAEF4 0080382D */  daddu     $a3, $a0, $zero
/* E2F848 802BAEF8 24840008 */  addiu     $a0, $a0, 8
/* E2F84C 802BAEFC ACC40000 */  sw        $a0, ($a2)
/* E2F850 802BAF00 94A20000 */  lhu       $v0, ($a1)
/* E2F854 802BAF04 3C03DA38 */  lui       $v1, 0xda38
/* E2F858 802BAF08 ACE30000 */  sw        $v1, ($a3)
/* E2F85C 802BAF0C 24430001 */  addiu     $v1, $v0, 1
/* E2F860 802BAF10 3042FFFF */  andi      $v0, $v0, 0xffff
/* E2F864 802BAF14 00021180 */  sll       $v0, $v0, 6
/* E2F868 802BAF18 A4A30000 */  sh        $v1, ($a1)
/* E2F86C 802BAF1C 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* E2F870 802BAF20 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* E2F874 802BAF24 00481021 */  addu      $v0, $v0, $t0
/* E2F878 802BAF28 00621821 */  addu      $v1, $v1, $v0
/* E2F87C 802BAF2C 24820008 */  addiu     $v0, $a0, 8
/* E2F880 802BAF30 ACE30004 */  sw        $v1, 4($a3)
/* E2F884 802BAF34 ACC20000 */  sw        $v0, ($a2)
/* E2F888 802BAF38 8E430044 */  lw        $v1, 0x44($s2)
/* E2F88C 802BAF3C 3C02DE00 */  lui       $v0, 0xde00
/* E2F890 802BAF40 AC820000 */  sw        $v0, ($a0)
/* E2F894 802BAF44 24820010 */  addiu     $v0, $a0, 0x10
/* E2F898 802BAF48 ACC20000 */  sw        $v0, ($a2)
/* E2F89C 802BAF4C 24020040 */  addiu     $v0, $zero, 0x40
/* E2F8A0 802BAF50 AC82000C */  sw        $v0, 0xc($a0)
/* E2F8A4 802BAF54 3C020A00 */  lui       $v0, 0xa00
/* E2F8A8 802BAF58 24421CF0 */  addiu     $v0, $v0, 0x1cf0
/* E2F8AC 802BAF5C 3042FFFF */  andi      $v0, $v0, 0xffff
/* E2F8B0 802BAF60 AC890008 */  sw        $t1, 8($a0)
/* E2F8B4 802BAF64 00621821 */  addu      $v1, $v1, $v0
/* E2F8B8 802BAF68 AC830004 */  sw        $v1, 4($a0)
/* E2F8BC 802BAF6C 8FBF00A4 */  lw        $ra, 0xa4($sp)
/* E2F8C0 802BAF70 8FB200A0 */  lw        $s2, 0xa0($sp)
/* E2F8C4 802BAF74 8FB1009C */  lw        $s1, 0x9c($sp)
/* E2F8C8 802BAF78 8FB00098 */  lw        $s0, 0x98($sp)
/* E2F8CC 802BAF7C 03E00008 */  jr        $ra
/* E2F8D0 802BAF80 27BD00A8 */   addiu    $sp, $sp, 0xa8
