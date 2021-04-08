.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC4B0_E2EDE0
/* E2EDE0 802BC4B0 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* E2EDE4 802BC4B4 AFB500AC */  sw        $s5, 0xac($sp)
/* E2EDE8 802BC4B8 3C15800A */  lui       $s5, %hi(gMasterGfxPos)
/* E2EDEC 802BC4BC 26B5A66C */  addiu     $s5, $s5, %lo(gMasterGfxPos)
/* E2EDF0 802BC4C0 AFBF00B0 */  sw        $ra, 0xb0($sp)
/* E2EDF4 802BC4C4 AFB400A8 */  sw        $s4, 0xa8($sp)
/* E2EDF8 802BC4C8 AFB300A4 */  sw        $s3, 0xa4($sp)
/* E2EDFC 802BC4CC AFB200A0 */  sw        $s2, 0xa0($sp)
/* E2EE00 802BC4D0 AFB1009C */  sw        $s1, 0x9c($sp)
/* E2EE04 802BC4D4 AFB00098 */  sw        $s0, 0x98($sp)
/* E2EE08 802BC4D8 8EB10000 */  lw        $s1, ($s5)
/* E2EE0C 802BC4DC 0C04417A */  jal       get_entity_by_index
/* E2EE10 802BC4E0 3C140001 */   lui      $s4, 1
/* E2EE14 802BC4E4 27A40018 */  addiu     $a0, $sp, 0x18
/* E2EE18 802BC4E8 0040902D */  daddu     $s2, $v0, $zero
/* E2EE1C 802BC4EC 3C050A00 */  lui       $a1, 0xa00
/* E2EE20 802BC4F0 24A50B28 */  addiu     $a1, $a1, 0xb28
/* E2EE24 802BC4F4 30A5FFFF */  andi      $a1, $a1, 0xffff
/* E2EE28 802BC4F8 8E420044 */  lw        $v0, 0x44($s2)
/* E2EE2C 802BC4FC 8E500040 */  lw        $s0, 0x40($s2)
/* E2EE30 802BC500 0C019D60 */  jal       guMtxL2F
/* E2EE34 802BC504 00452821 */   addu     $a1, $v0, $a1
/* E2EE38 802BC508 C6000004 */  lwc1      $f0, 4($s0)
/* E2EE3C 802BC50C 3C0142B4 */  lui       $at, 0x42b4
/* E2EE40 802BC510 44816000 */  mtc1      $at, $f12
/* E2EE44 802BC514 00000000 */  nop
/* E2EE48 802BC518 460C0301 */  sub.s     $f12, $f0, $f12
/* E2EE4C 802BC51C 0C00A6C9 */  jal       clamp_angle
/* E2EE50 802BC520 36941630 */   ori      $s4, $s4, 0x1630
/* E2EE54 802BC524 27B00058 */  addiu     $s0, $sp, 0x58
/* E2EE58 802BC528 44801000 */  mtc1      $zero, $f2
/* E2EE5C 802BC52C 44050000 */  mfc1      $a1, $f0
/* E2EE60 802BC530 3C013F80 */  lui       $at, 0x3f80
/* E2EE64 802BC534 44810000 */  mtc1      $at, $f0
/* E2EE68 802BC538 44061000 */  mfc1      $a2, $f2
/* E2EE6C 802BC53C 0200202D */  daddu     $a0, $s0, $zero
/* E2EE70 802BC540 E7A00010 */  swc1      $f0, 0x10($sp)
/* E2EE74 802BC544 0C019EC8 */  jal       guRotateF
/* E2EE78 802BC548 00C0382D */   daddu    $a3, $a2, $zero
/* E2EE7C 802BC54C 0200202D */  daddu     $a0, $s0, $zero
/* E2EE80 802BC550 27A50018 */  addiu     $a1, $sp, 0x18
/* E2EE84 802BC554 0C019D80 */  jal       guMtxCatF
/* E2EE88 802BC558 00A0302D */   daddu    $a2, $a1, $zero
/* E2EE8C 802BC55C 27A40018 */  addiu     $a0, $sp, 0x18
/* E2EE90 802BC560 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* E2EE94 802BC564 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* E2EE98 802BC568 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* E2EE9C 802BC56C 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* E2EEA0 802BC570 96050000 */  lhu       $a1, ($s0)
/* E2EEA4 802BC574 8E620000 */  lw        $v0, ($s3)
/* E2EEA8 802BC578 00052980 */  sll       $a1, $a1, 6
/* E2EEAC 802BC57C 00B42821 */  addu      $a1, $a1, $s4
/* E2EEB0 802BC580 0C019D40 */  jal       guMtxF2L
/* E2EEB4 802BC584 00452821 */   addu     $a1, $v0, $a1
/* E2EEB8 802BC588 0220202D */  daddu     $a0, $s1, $zero
/* E2EEBC 802BC58C 26310008 */  addiu     $s1, $s1, 8
/* E2EEC0 802BC590 0220282D */  daddu     $a1, $s1, $zero
/* E2EEC4 802BC594 26310008 */  addiu     $s1, $s1, 8
/* E2EEC8 802BC598 0220302D */  daddu     $a2, $s1, $zero
/* E2EECC 802BC59C 26310008 */  addiu     $s1, $s1, 8
/* E2EED0 802BC5A0 3C07D838 */  lui       $a3, 0xd838
/* E2EED4 802BC5A4 34E70002 */  ori       $a3, $a3, 2
/* E2EED8 802BC5A8 96020000 */  lhu       $v0, ($s0)
/* E2EEDC 802BC5AC 3C03DA38 */  lui       $v1, 0xda38
/* E2EEE0 802BC5B0 AC830000 */  sw        $v1, ($a0)
/* E2EEE4 802BC5B4 AEB10000 */  sw        $s1, ($s5)
/* E2EEE8 802BC5B8 24430001 */  addiu     $v1, $v0, 1
/* E2EEEC 802BC5BC 3042FFFF */  andi      $v0, $v0, 0xffff
/* E2EEF0 802BC5C0 00021180 */  sll       $v0, $v0, 6
/* E2EEF4 802BC5C4 A6030000 */  sh        $v1, ($s0)
/* E2EEF8 802BC5C8 8E630000 */  lw        $v1, ($s3)
/* E2EEFC 802BC5CC 00541021 */  addu      $v0, $v0, $s4
/* E2EF00 802BC5D0 00621821 */  addu      $v1, $v1, $v0
/* E2EF04 802BC5D4 AC830004 */  sw        $v1, 4($a0)
/* E2EF08 802BC5D8 8E430044 */  lw        $v1, 0x44($s2)
/* E2EF0C 802BC5DC 3C02DE00 */  lui       $v0, 0xde00
/* E2EF10 802BC5E0 ACA20000 */  sw        $v0, ($a1)
/* E2EF14 802BC5E4 3C020A00 */  lui       $v0, 0xa00
/* E2EF18 802BC5E8 24420BC8 */  addiu     $v0, $v0, 0xbc8
/* E2EF1C 802BC5EC 3042FFFF */  andi      $v0, $v0, 0xffff
/* E2EF20 802BC5F0 00621821 */  addu      $v1, $v1, $v0
/* E2EF24 802BC5F4 24020040 */  addiu     $v0, $zero, 0x40
/* E2EF28 802BC5F8 ACA30004 */  sw        $v1, 4($a1)
/* E2EF2C 802BC5FC ACC70000 */  sw        $a3, ($a2)
/* E2EF30 802BC600 ACC20004 */  sw        $v0, 4($a2)
/* E2EF34 802BC604 8FBF00B0 */  lw        $ra, 0xb0($sp)
/* E2EF38 802BC608 8FB500AC */  lw        $s5, 0xac($sp)
/* E2EF3C 802BC60C 8FB400A8 */  lw        $s4, 0xa8($sp)
/* E2EF40 802BC610 8FB300A4 */  lw        $s3, 0xa4($sp)
/* E2EF44 802BC614 8FB200A0 */  lw        $s2, 0xa0($sp)
/* E2EF48 802BC618 8FB1009C */  lw        $s1, 0x9c($sp)
/* E2EF4C 802BC61C 8FB00098 */  lw        $s0, 0x98($sp)
/* E2EF50 802BC620 03E00008 */  jr        $ra
/* E2EF54 802BC624 27BD00B8 */   addiu    $sp, $sp, 0xb8
