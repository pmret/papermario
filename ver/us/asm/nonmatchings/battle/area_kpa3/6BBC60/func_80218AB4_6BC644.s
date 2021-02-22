.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218AB4_6BC644
/* 6BC644 80218AB4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6BC648 80218AB8 AFB00010 */  sw        $s0, 0x10($sp)
/* 6BC64C 80218ABC 0080802D */  daddu     $s0, $a0, $zero
/* 6BC650 80218AC0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 6BC654 80218AC4 0C09A75B */  jal       get_actor
/* 6BC658 80218AC8 8E040148 */   lw       $a0, 0x148($s0)
/* 6BC65C 80218ACC 0C09A75B */  jal       get_actor
/* 6BC660 80218AD0 84440428 */   lh       $a0, 0x428($v0)
/* 6BC664 80218AD4 0040202D */  daddu     $a0, $v0, $zero
/* 6BC668 80218AD8 8C820000 */  lw        $v0, ($a0)
/* 6BC66C 80218ADC 30420800 */  andi      $v0, $v0, 0x800
/* 6BC670 80218AE0 1440000A */  bnez      $v0, .L80218B0C
/* 6BC674 80218AE4 00000000 */   nop
/* 6BC678 80218AE8 90820191 */  lbu       $v0, 0x191($a0)
/* 6BC67C 80218AEC 8E030088 */  lw        $v1, 0x88($s0)
/* 6BC680 80218AF0 00021042 */  srl       $v0, $v0, 1
/* 6BC684 80218AF4 00621821 */  addu      $v1, $v1, $v0
/* 6BC688 80218AF8 AE030088 */  sw        $v1, 0x88($s0)
/* 6BC68C 80218AFC 90820191 */  lbu       $v0, 0x191($a0)
/* 6BC690 80218B00 00021082 */  srl       $v0, $v0, 2
/* 6BC694 80218B04 080862CB */  j         .L80218B2C
/* 6BC698 80218B08 00621821 */   addu     $v1, $v1, $v0
.L80218B0C:
/* 6BC69C 80218B0C 90820191 */  lbu       $v0, 0x191($a0)
/* 6BC6A0 80218B10 8E030088 */  lw        $v1, 0x88($s0)
/* 6BC6A4 80218B14 00021042 */  srl       $v0, $v0, 1
/* 6BC6A8 80218B18 00621823 */  subu      $v1, $v1, $v0
/* 6BC6AC 80218B1C AE030088 */  sw        $v1, 0x88($s0)
/* 6BC6B0 80218B20 90820191 */  lbu       $v0, 0x191($a0)
/* 6BC6B4 80218B24 00021082 */  srl       $v0, $v0, 2
/* 6BC6B8 80218B28 00621823 */  subu      $v1, $v1, $v0
.L80218B2C:
/* 6BC6BC 80218B2C AE030088 */  sw        $v1, 0x88($s0)
/* 6BC6C0 80218B30 90830191 */  lbu       $v1, 0x191($a0)
/* 6BC6C4 80218B34 90840190 */  lbu       $a0, 0x190($a0)
/* 6BC6C8 80218B38 0064102A */  slt       $v0, $v1, $a0
/* 6BC6CC 80218B3C 54400001 */  bnel      $v0, $zero, .L80218B44
/* 6BC6D0 80218B40 0080182D */   daddu    $v1, $a0, $zero
.L80218B44:
/* 6BC6D4 80218B44 2462007E */  addiu     $v0, $v1, 0x7e
/* 6BC6D8 80218B48 AE020090 */  sw        $v0, 0x90($s0)
/* 6BC6DC 80218B4C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6BC6E0 80218B50 8FB00010 */  lw        $s0, 0x10($sp)
/* 6BC6E4 80218B54 24020002 */  addiu     $v0, $zero, 2
/* 6BC6E8 80218B58 03E00008 */  jr        $ra
/* 6BC6EC 80218B5C 27BD0018 */   addiu    $sp, $sp, 0x18
