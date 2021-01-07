.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802435D0_CC6DE0
/* CC6DE0 802435D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CC6DE4 802435D4 3C048024 */  lui       $a0, %hi(D_80247AF0)
/* CC6DE8 802435D8 24847AF0 */  addiu     $a0, $a0, %lo(D_80247AF0)
/* CC6DEC 802435DC 27A50010 */  addiu     $a1, $sp, 0x10
/* CC6DF0 802435E0 AFBF0020 */  sw        $ra, 0x20($sp)
/* CC6DF4 802435E4 AFB1001C */  sw        $s1, 0x1c($sp)
/* CC6DF8 802435E8 0C016B3A */  jal       load_asset_by_name
/* CC6DFC 802435EC AFB00018 */   sw       $s0, 0x18($sp)
/* CC6E00 802435F0 0040802D */  daddu     $s0, $v0, $zero
/* CC6E04 802435F4 0200202D */  daddu     $a0, $s0, $zero
/* CC6E08 802435F8 3C118024 */  lui       $s1, %hi(D_80247B00)
/* CC6E0C 802435FC 26317B00 */  addiu     $s1, $s1, %lo(D_80247B00)
/* CC6E10 80243600 0C01BB7C */  jal       decode_yay0
/* CC6E14 80243604 0220282D */   daddu    $a1, $s1, $zero
/* CC6E18 80243608 0C00AB1E */  jal       general_heap_free
/* CC6E1C 8024360C 0200202D */   daddu    $a0, $s0, $zero
/* CC6E20 80243610 3C048025 */  lui       $a0, %hi(D_8024BA90)
/* CC6E24 80243614 2484BA90 */  addiu     $a0, $a0, %lo(D_8024BA90)
/* CC6E28 80243618 3C028024 */  lui       $v0, %hi(D_80247D00)
/* CC6E2C 8024361C 24427D00 */  addiu     $v0, $v0, %lo(D_80247D00)
/* CC6E30 80243620 AC820000 */  sw        $v0, ($a0)
/* CC6E34 80243624 24020096 */  addiu     $v0, $zero, 0x96
/* CC6E38 80243628 A4820008 */  sh        $v0, 8($a0)
/* CC6E3C 8024362C 24020069 */  addiu     $v0, $zero, 0x69
/* CC6E40 80243630 A482000A */  sh        $v0, 0xa($a0)
/* CC6E44 80243634 24020002 */  addiu     $v0, $zero, 2
/* CC6E48 80243638 AC82000C */  sw        $v0, 0xc($a0)
/* CC6E4C 8024363C 24020001 */  addiu     $v0, $zero, 1
/* CC6E50 80243640 AC910004 */  sw        $s1, 4($a0)
/* CC6E54 80243644 0C0496CB */  jal       set_message_images
/* CC6E58 80243648 AC820010 */   sw       $v0, 0x10($a0)
/* CC6E5C 8024364C 8FBF0020 */  lw        $ra, 0x20($sp)
/* CC6E60 80243650 8FB1001C */  lw        $s1, 0x1c($sp)
/* CC6E64 80243654 8FB00018 */  lw        $s0, 0x18($sp)
/* CC6E68 80243658 24020002 */  addiu     $v0, $zero, 2
/* CC6E6C 8024365C 03E00008 */  jr        $ra
/* CC6E70 80243660 27BD0028 */   addiu    $sp, $sp, 0x28
/* CC6E74 80243664 00000000 */  nop       
/* CC6E78 80243668 00000000 */  nop       
/* CC6E7C 8024366C 00000000 */  nop       
