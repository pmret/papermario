.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024253C_C739BC
/* C739BC 8024253C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C739C0 80242540 AFB10014 */  sw        $s1, 0x14($sp)
/* C739C4 80242544 0080882D */  daddu     $s1, $a0, $zero
/* C739C8 80242548 AFBF0018 */  sw        $ra, 0x18($sp)
/* C739CC 8024254C AFB00010 */  sw        $s0, 0x10($sp)
/* C739D0 80242550 8E300148 */  lw        $s0, 0x148($s1)
/* C739D4 80242554 0C00EABB */  jal       get_npc_unsafe
/* C739D8 80242558 86040008 */   lh       $a0, 8($s0)
/* C739DC 8024255C 24030001 */  addiu     $v1, $zero, 1
/* C739E0 80242560 0040202D */  daddu     $a0, $v0, $zero
/* C739E4 80242564 AE03006C */  sw        $v1, 0x6c($s0)
/* C739E8 80242568 8482008C */  lh        $v0, 0x8c($a0)
/* C739EC 8024256C 14400009 */  bnez      $v0, .L80242594
/* C739F0 80242570 24020002 */   addiu    $v0, $zero, 2
/* C739F4 80242574 96030072 */  lhu       $v1, 0x72($s0)
/* C739F8 80242578 AE02006C */  sw        $v0, 0x6c($s0)
/* C739FC 8024257C A483008E */  sh        $v1, 0x8e($a0)
/* C73A00 80242580 8E0200CC */  lw        $v0, 0xcc($s0)
/* C73A04 80242584 8C420020 */  lw        $v0, 0x20($v0)
/* C73A08 80242588 AC820028 */  sw        $v0, 0x28($a0)
/* C73A0C 8024258C 2402001F */  addiu     $v0, $zero, 0x1f
/* C73A10 80242590 AE220070 */  sw        $v0, 0x70($s1)
.L80242594:
/* C73A14 80242594 8FBF0018 */  lw        $ra, 0x18($sp)
/* C73A18 80242598 8FB10014 */  lw        $s1, 0x14($sp)
/* C73A1C 8024259C 8FB00010 */  lw        $s0, 0x10($sp)
/* C73A20 802425A0 03E00008 */  jr        $ra
/* C73A24 802425A4 27BD0020 */   addiu    $sp, $sp, 0x20
