.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416F8_E0FE98
/* E0FE98 802416F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E0FE9C 802416FC AFB10014 */  sw        $s1, 0x14($sp)
/* E0FEA0 80241700 0080882D */  daddu     $s1, $a0, $zero
/* E0FEA4 80241704 AFBF001C */  sw        $ra, 0x1c($sp)
/* E0FEA8 80241708 AFB20018 */  sw        $s2, 0x18($sp)
/* E0FEAC 8024170C AFB00010 */  sw        $s0, 0x10($sp)
/* E0FEB0 80241710 8E22000C */  lw        $v0, 0xc($s1)
/* E0FEB4 80241714 00A0802D */  daddu     $s0, $a1, $zero
/* E0FEB8 80241718 0C0B1EAF */  jal       get_variable
/* E0FEBC 8024171C 8C450000 */   lw       $a1, ($v0)
/* E0FEC0 80241720 12000013 */  beqz      $s0, .L80241770
/* E0FEC4 80241724 0040902D */   daddu    $s2, $v0, $zero
/* E0FEC8 80241728 0C00AB39 */  jal       heap_malloc
/* E0FECC 8024172C 24040018 */   addiu    $a0, $zero, 0x18
/* E0FED0 80241730 0040802D */  daddu     $s0, $v0, $zero
/* E0FED4 80241734 0000202D */  daddu     $a0, $zero, $zero
/* E0FED8 80241738 3C058024 */  lui       $a1, %hi(func_802416C0_E0F948)
/* E0FEDC 8024173C 24A516C0 */  addiu     $a1, $a1, %lo(func_802416C0_E0F948)
/* E0FEE0 80241740 240200FF */  addiu     $v0, $zero, 0xff
/* E0FEE4 80241744 AE300070 */  sw        $s0, 0x70($s1)
/* E0FEE8 80241748 AE000000 */  sw        $zero, ($s0)
/* E0FEEC 8024174C 0C048C56 */  jal       bind_dynamic_entity_3
/* E0FEF0 80241750 AE02000C */   sw       $v0, 0xc($s0)
/* E0FEF4 80241754 0220202D */  daddu     $a0, $s1, $zero
/* E0FEF8 80241758 3C05FD05 */  lui       $a1, 0xfd05
/* E0FEFC 8024175C 34A50F8A */  ori       $a1, $a1, 0xf8a
/* E0FF00 80241760 0200302D */  daddu     $a2, $s0, $zero
/* E0FF04 80241764 AE020014 */  sw        $v0, 0x14($s0)
/* E0FF08 80241768 0C0B2026 */  jal       set_variable
/* E0FF0C 8024176C AE120008 */   sw       $s2, 8($s0)
.L80241770:
/* E0FF10 80241770 8E300070 */  lw        $s0, 0x70($s1)
/* E0FF14 80241774 8E030000 */  lw        $v1, ($s0)
/* E0FF18 80241778 24020005 */  addiu     $v0, $zero, 5
/* E0FF1C 8024177C 14620007 */  bne       $v1, $v0, .L8024179C
/* E0FF20 80241780 0000102D */   daddu    $v0, $zero, $zero
/* E0FF24 80241784 8E040014 */  lw        $a0, 0x14($s0)
/* E0FF28 80241788 0C048D70 */  jal       func_801235C0
/* E0FF2C 8024178C 00000000 */   nop      
/* E0FF30 80241790 0C00AB4B */  jal       heap_free
/* E0FF34 80241794 0200202D */   daddu    $a0, $s0, $zero
/* E0FF38 80241798 24020001 */  addiu     $v0, $zero, 1
.L8024179C:
/* E0FF3C 8024179C 8FBF001C */  lw        $ra, 0x1c($sp)
/* E0FF40 802417A0 8FB20018 */  lw        $s2, 0x18($sp)
/* E0FF44 802417A4 8FB10014 */  lw        $s1, 0x14($sp)
/* E0FF48 802417A8 8FB00010 */  lw        $s0, 0x10($sp)
/* E0FF4C 802417AC 03E00008 */  jr        $ra
/* E0FF50 802417B0 27BD0020 */   addiu    $sp, $sp, 0x20
/* E0FF54 802417B4 00000000 */  nop       
/* E0FF58 802417B8 00000000 */  nop       
/* E0FF5C 802417BC 00000000 */  nop       
