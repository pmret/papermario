.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418CC_B4C33C
/* B4C33C 802418CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B4C340 802418D0 AFB10014 */  sw        $s1, 0x14($sp)
/* B4C344 802418D4 0080882D */  daddu     $s1, $a0, $zero
/* B4C348 802418D8 AFBF0018 */  sw        $ra, 0x18($sp)
/* B4C34C 802418DC AFB00010 */  sw        $s0, 0x10($sp)
/* B4C350 802418E0 8E300148 */  lw        $s0, 0x148($s1)
/* B4C354 802418E4 0C00EABB */  jal       get_npc_unsafe
/* B4C358 802418E8 86040008 */   lh       $a0, 8($s0)
/* B4C35C 802418EC 24030001 */  addiu     $v1, $zero, 1
/* B4C360 802418F0 0040202D */  daddu     $a0, $v0, $zero
/* B4C364 802418F4 AE03006C */  sw        $v1, 0x6c($s0)
/* B4C368 802418F8 8482008C */  lh        $v0, 0x8c($a0)
/* B4C36C 802418FC 14400009 */  bnez      $v0, .L80241924
/* B4C370 80241900 24020002 */   addiu    $v0, $zero, 2
/* B4C374 80241904 96030072 */  lhu       $v1, 0x72($s0)
/* B4C378 80241908 AE02006C */  sw        $v0, 0x6c($s0)
/* B4C37C 8024190C A483008E */  sh        $v1, 0x8e($a0)
/* B4C380 80241910 8E0200CC */  lw        $v0, 0xcc($s0)
/* B4C384 80241914 8C420020 */  lw        $v0, 0x20($v0)
/* B4C388 80241918 AC820028 */  sw        $v0, 0x28($a0)
/* B4C38C 8024191C 2402001F */  addiu     $v0, $zero, 0x1f
/* B4C390 80241920 AE220070 */  sw        $v0, 0x70($s1)
.L80241924:
/* B4C394 80241924 8FBF0018 */  lw        $ra, 0x18($sp)
/* B4C398 80241928 8FB10014 */  lw        $s1, 0x14($sp)
/* B4C39C 8024192C 8FB00010 */  lw        $s0, 0x10($sp)
/* B4C3A0 80241930 03E00008 */  jr        $ra
/* B4C3A4 80241934 27BD0020 */   addiu    $sp, $sp, 0x20
