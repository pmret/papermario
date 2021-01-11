.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BAE00_E2B530
/* E2B530 802BAE00 27BDFEB8 */  addiu     $sp, $sp, -0x148
/* E2B534 802BAE04 AFBF0130 */  sw        $ra, 0x130($sp)
/* E2B538 802BAE08 AFB5012C */  sw        $s5, 0x12c($sp)
/* E2B53C 802BAE0C AFB40128 */  sw        $s4, 0x128($sp)
/* E2B540 802BAE10 AFB30124 */  sw        $s3, 0x124($sp)
/* E2B544 802BAE14 AFB20120 */  sw        $s2, 0x120($sp)
/* E2B548 802BAE18 AFB1011C */  sw        $s1, 0x11c($sp)
/* E2B54C 802BAE1C AFB00118 */  sw        $s0, 0x118($sp)
/* E2B550 802BAE20 F7B60140 */  sdc1      $f22, 0x140($sp)
/* E2B554 802BAE24 F7B40138 */  sdc1      $f20, 0x138($sp)
/* E2B558 802BAE28 0C04417A */  jal       get_entity_by_index
/* E2B55C 802BAE2C 3C150001 */   lui      $s5, 1
/* E2B560 802BAE30 27B30058 */  addiu     $s3, $sp, 0x58
/* E2B564 802BAE34 0040882D */  daddu     $s1, $v0, $zero
/* E2B568 802BAE38 8E340040 */  lw        $s4, 0x40($s1)
/* E2B56C 802BAE3C 0C019D28 */  jal       guMtxIdentF
/* E2B570 802BAE40 0260202D */   daddu    $a0, $s3, $zero
/* E2B574 802BAE44 27B20098 */  addiu     $s2, $sp, 0x98
/* E2B578 802BAE48 8E850014 */  lw        $a1, 0x14($s4)
/* E2B57C 802BAE4C 0C019D60 */  jal       guMtxL2F
/* E2B580 802BAE50 0240202D */   daddu    $a0, $s2, $zero
/* E2B584 802BAE54 0260202D */  daddu     $a0, $s3, $zero
/* E2B588 802BAE58 0240282D */  daddu     $a1, $s2, $zero
/* E2B58C 802BAE5C 0C019D80 */  jal       guMtxCatF
/* E2B590 802BAE60 0240302D */   daddu    $a2, $s2, $zero
/* E2B594 802BAE64 3C06BF80 */  lui       $a2, 0xbf80
/* E2B598 802BAE68 C7A000C8 */  lwc1      $f0, 0xc8($sp)
/* E2B59C 802BAE6C C6820004 */  lwc1      $f2, 4($s4)
/* E2B5A0 802BAE70 4480A000 */  mtc1      $zero, $f20
/* E2B5A4 802BAE74 46020000 */  add.s     $f0, $f0, $f2
/* E2B5A8 802BAE78 4407A000 */  mfc1      $a3, $f20
/* E2B5AC 802BAE7C 27B000D8 */  addiu     $s0, $sp, 0xd8
/* E2B5B0 802BAE80 E7A000C8 */  swc1      $f0, 0xc8($sp)
/* E2B5B4 802BAE84 E7B40010 */  swc1      $f20, 0x10($sp)
/* E2B5B8 802BAE88 8E250060 */  lw        $a1, 0x60($s1)
/* E2B5BC 802BAE8C 0C019EC8 */  jal       guRotateF
/* E2B5C0 802BAE90 0200202D */   daddu    $a0, $s0, $zero
/* E2B5C4 802BAE94 0200202D */  daddu     $a0, $s0, $zero
/* E2B5C8 802BAE98 0240282D */  daddu     $a1, $s2, $zero
/* E2B5CC 802BAE9C 0C019D80 */  jal       guMtxCatF
/* E2B5D0 802BAEA0 0240302D */   daddu    $a2, $s2, $zero
/* E2B5D4 802BAEA4 3C013F80 */  lui       $at, 0x3f80
/* E2B5D8 802BAEA8 4481B000 */  mtc1      $at, $f22
/* E2B5DC 802BAEAC 4406A000 */  mfc1      $a2, $f20
/* E2B5E0 802BAEB0 4407A000 */  mfc1      $a3, $f20
/* E2B5E4 802BAEB4 36B51630 */  ori       $s5, $s5, 0x1630
/* E2B5E8 802BAEB8 E7B60010 */  swc1      $f22, 0x10($sp)
/* E2B5EC 802BAEBC 8E250068 */  lw        $a1, 0x68($s1)
/* E2B5F0 802BAEC0 0C019EC8 */  jal       guRotateF
/* E2B5F4 802BAEC4 0200202D */   daddu    $a0, $s0, $zero
/* E2B5F8 802BAEC8 E7B40010 */  swc1      $f20, 0x10($sp)
/* E2B5FC 802BAECC 8E250060 */  lw        $a1, 0x60($s1)
/* E2B600 802BAED0 4406B000 */  mfc1      $a2, $f22
/* E2B604 802BAED4 4407A000 */  mfc1      $a3, $f20
/* E2B608 802BAED8 0C019EC8 */  jal       guRotateF
/* E2B60C 802BAEDC 27A40018 */   addiu    $a0, $sp, 0x18
/* E2B610 802BAEE0 0200202D */  daddu     $a0, $s0, $zero
/* E2B614 802BAEE4 27A50018 */  addiu     $a1, $sp, 0x18
/* E2B618 802BAEE8 0C019D80 */  jal       guMtxCatF
/* E2B61C 802BAEEC 00A0302D */   daddu    $a2, $a1, $zero
/* E2B620 802BAEF0 E7B40010 */  swc1      $f20, 0x10($sp)
/* E2B624 802BAEF4 8E250064 */  lw        $a1, 0x64($s1)
/* E2B628 802BAEF8 4406A000 */  mfc1      $a2, $f20
/* E2B62C 802BAEFC 4407B000 */  mfc1      $a3, $f22
/* E2B630 802BAF00 0C019EC8 */  jal       guRotateF
/* E2B634 802BAF04 0200202D */   daddu    $a0, $s0, $zero
/* E2B638 802BAF08 27A40018 */  addiu     $a0, $sp, 0x18
/* E2B63C 802BAF0C 0200282D */  daddu     $a1, $s0, $zero
/* E2B640 802BAF10 0C019D80 */  jal       guMtxCatF
/* E2B644 802BAF14 0200302D */   daddu    $a2, $s0, $zero
/* E2B648 802BAF18 0240202D */  daddu     $a0, $s2, $zero
/* E2B64C 802BAF1C 0200282D */  daddu     $a1, $s0, $zero
/* E2B650 802BAF20 0C019D80 */  jal       guMtxCatF
/* E2B654 802BAF24 0240302D */   daddu    $a2, $s2, $zero
/* E2B658 802BAF28 8E250054 */  lw        $a1, 0x54($s1)
/* E2B65C 802BAF2C 8E260058 */  lw        $a2, 0x58($s1)
/* E2B660 802BAF30 8E27005C */  lw        $a3, 0x5c($s1)
/* E2B664 802BAF34 0C019DF0 */  jal       guScaleF
/* E2B668 802BAF38 27A40018 */   addiu    $a0, $sp, 0x18
/* E2B66C 802BAF3C 0240202D */  daddu     $a0, $s2, $zero
/* E2B670 802BAF40 27A50018 */  addiu     $a1, $sp, 0x18
/* E2B674 802BAF44 0C019D80 */  jal       guMtxCatF
/* E2B678 802BAF48 00A0302D */   daddu    $a2, $a1, $zero
/* E2B67C 802BAF4C 8E250048 */  lw        $a1, 0x48($s1)
/* E2B680 802BAF50 8E26004C */  lw        $a2, 0x4c($s1)
/* E2B684 802BAF54 8E270050 */  lw        $a3, 0x50($s1)
/* E2B688 802BAF58 0C019E40 */  jal       guTranslateF
/* E2B68C 802BAF5C 0260202D */   daddu    $a0, $s3, $zero
/* E2B690 802BAF60 27A40018 */  addiu     $a0, $sp, 0x18
/* E2B694 802BAF64 0260282D */  daddu     $a1, $s3, $zero
/* E2B698 802BAF68 0C019D80 */  jal       guMtxCatF
/* E2B69C 802BAF6C 0260302D */   daddu    $a2, $s3, $zero
/* E2B6A0 802BAF70 0260202D */  daddu     $a0, $s3, $zero
/* E2B6A4 802BAF74 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* E2B6A8 802BAF78 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* E2B6AC 802BAF7C 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* E2B6B0 802BAF80 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* E2B6B4 802BAF84 96050000 */  lhu       $a1, ($s0)
/* E2B6B8 802BAF88 8E220000 */  lw        $v0, ($s1)
/* E2B6BC 802BAF8C 00052980 */  sll       $a1, $a1, 6
/* E2B6C0 802BAF90 00B52821 */  addu      $a1, $a1, $s5
/* E2B6C4 802BAF94 0C019D40 */  jal       guMtxF2L
/* E2B6C8 802BAF98 00452821 */   addu     $a1, $v0, $a1
/* E2B6CC 802BAF9C 3C03DA38 */  lui       $v1, 0xda38
/* E2B6D0 802BAFA0 34630002 */  ori       $v1, $v1, 2
/* E2B6D4 802BAFA4 3C07D838 */  lui       $a3, 0xd838
/* E2B6D8 802BAFA8 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* E2B6DC 802BAFAC 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* E2B6E0 802BAFB0 34E70002 */  ori       $a3, $a3, 2
/* E2B6E4 802BAFB4 8CA40000 */  lw        $a0, ($a1)
/* E2B6E8 802BAFB8 96020000 */  lhu       $v0, ($s0)
/* E2B6EC 802BAFBC 0080302D */  daddu     $a2, $a0, $zero
/* E2B6F0 802BAFC0 24840008 */  addiu     $a0, $a0, 8
/* E2B6F4 802BAFC4 ACA40000 */  sw        $a0, ($a1)
/* E2B6F8 802BAFC8 ACC30000 */  sw        $v1, ($a2)
/* E2B6FC 802BAFCC 24430001 */  addiu     $v1, $v0, 1
/* E2B700 802BAFD0 3042FFFF */  andi      $v0, $v0, 0xffff
/* E2B704 802BAFD4 00021180 */  sll       $v0, $v0, 6
/* E2B708 802BAFD8 A6030000 */  sh        $v1, ($s0)
/* E2B70C 802BAFDC 8E230000 */  lw        $v1, ($s1)
/* E2B710 802BAFE0 00551021 */  addu      $v0, $v0, $s5
/* E2B714 802BAFE4 00621821 */  addu      $v1, $v1, $v0
/* E2B718 802BAFE8 24820008 */  addiu     $v0, $a0, 8
/* E2B71C 802BAFEC ACC30004 */  sw        $v1, 4($a2)
/* E2B720 802BAFF0 ACA20000 */  sw        $v0, ($a1)
/* E2B724 802BAFF4 3C02DE00 */  lui       $v0, 0xde00
/* E2B728 802BAFF8 AC820000 */  sw        $v0, ($a0)
/* E2B72C 802BAFFC 8E830018 */  lw        $v1, 0x18($s4)
/* E2B730 802BB000 24820010 */  addiu     $v0, $a0, 0x10
/* E2B734 802BB004 ACA20000 */  sw        $v0, ($a1)
/* E2B738 802BB008 24020040 */  addiu     $v0, $zero, 0x40
/* E2B73C 802BB00C AC870008 */  sw        $a3, 8($a0)
/* E2B740 802BB010 AC82000C */  sw        $v0, 0xc($a0)
/* E2B744 802BB014 AC830004 */  sw        $v1, 4($a0)
/* E2B748 802BB018 8FBF0130 */  lw        $ra, 0x130($sp)
/* E2B74C 802BB01C 8FB5012C */  lw        $s5, 0x12c($sp)
/* E2B750 802BB020 8FB40128 */  lw        $s4, 0x128($sp)
/* E2B754 802BB024 8FB30124 */  lw        $s3, 0x124($sp)
/* E2B758 802BB028 8FB20120 */  lw        $s2, 0x120($sp)
/* E2B75C 802BB02C 8FB1011C */  lw        $s1, 0x11c($sp)
/* E2B760 802BB030 8FB00118 */  lw        $s0, 0x118($sp)
/* E2B764 802BB034 D7B60140 */  ldc1      $f22, 0x140($sp)
/* E2B768 802BB038 D7B40138 */  ldc1      $f20, 0x138($sp)
/* E2B76C 802BB03C 03E00008 */  jr        $ra
/* E2B770 802BB040 27BD0148 */   addiu    $sp, $sp, 0x148
