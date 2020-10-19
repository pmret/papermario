.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418F0_C785D0
/* C785D0 802418F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C785D4 802418F4 AFB10014 */  sw        $s1, 0x14($sp)
/* C785D8 802418F8 0080882D */  daddu     $s1, $a0, $zero
/* C785DC 802418FC AFBF0018 */  sw        $ra, 0x18($sp)
/* C785E0 80241900 AFB00010 */  sw        $s0, 0x10($sp)
/* C785E4 80241904 8E300148 */  lw        $s0, 0x148($s1)
/* C785E8 80241908 0C00EABB */  jal       get_npc_unsafe
/* C785EC 8024190C 86040008 */   lh       $a0, 8($s0)
/* C785F0 80241910 0040202D */  daddu     $a0, $v0, $zero
/* C785F4 80241914 8482008E */  lh        $v0, 0x8e($a0)
/* C785F8 80241918 9483008E */  lhu       $v1, 0x8e($a0)
/* C785FC 8024191C 18400003 */  blez      $v0, .L8024192C
/* C78600 80241920 2462FFFF */   addiu    $v0, $v1, -1
/* C78604 80241924 08090652 */  j         .L80241948
/* C78608 80241928 A482008E */   sh       $v0, 0x8e($a0)
.L8024192C:
/* C7860C 8024192C 8E0200CC */  lw        $v0, 0xcc($s0)
/* C78610 80241930 AE00006C */  sw        $zero, 0x6c($s0)
/* C78614 80241934 8C420000 */  lw        $v0, ($v0)
/* C78618 80241938 AC820028 */  sw        $v0, 0x28($a0)
/* C7861C 8024193C 24020001 */  addiu     $v0, $zero, 1
/* C78620 80241940 AE200074 */  sw        $zero, 0x74($s1)
/* C78624 80241944 AE220070 */  sw        $v0, 0x70($s1)
.L80241948:
/* C78628 80241948 8FBF0018 */  lw        $ra, 0x18($sp)
/* C7862C 8024194C 8FB10014 */  lw        $s1, 0x14($sp)
/* C78630 80241950 8FB00010 */  lw        $s0, 0x10($sp)
/* C78634 80241954 03E00008 */  jr        $ra
/* C78638 80241958 27BD0020 */   addiu    $sp, $sp, 0x20
