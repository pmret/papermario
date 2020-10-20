.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802424E8_BE5C98
/* BE5C98 802424E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE5C9C 802424EC AFB10014 */  sw        $s1, 0x14($sp)
/* BE5CA0 802424F0 0080882D */  daddu     $s1, $a0, $zero
/* BE5CA4 802424F4 AFBF001C */  sw        $ra, 0x1c($sp)
/* BE5CA8 802424F8 AFB20018 */  sw        $s2, 0x18($sp)
/* BE5CAC 802424FC AFB00010 */  sw        $s0, 0x10($sp)
/* BE5CB0 80242500 8E320148 */  lw        $s2, 0x148($s1)
/* BE5CB4 80242504 0C00EABB */  jal       get_npc_unsafe
/* BE5CB8 80242508 86440008 */   lh       $a0, 8($s2)
/* BE5CBC 8024250C 0040802D */  daddu     $s0, $v0, $zero
/* BE5CC0 80242510 0C00EAFF */  jal       disable_npc_shadow
/* BE5CC4 80242514 0200202D */   daddu    $a0, $s0, $zero
/* BE5CC8 80242518 24020016 */  addiu     $v0, $zero, 0x16
/* BE5CCC 8024251C A60200A8 */  sh        $v0, 0xa8($s0)
/* BE5CD0 80242520 24020018 */  addiu     $v0, $zero, 0x18
/* BE5CD4 80242524 A60200A6 */  sh        $v0, 0xa6($s0)
/* BE5CD8 80242528 AE200074 */  sw        $zero, 0x74($s1)
/* BE5CDC 8024252C A600008E */  sh        $zero, 0x8e($s0)
/* BE5CE0 80242530 8E4200CC */  lw        $v0, 0xcc($s2)
/* BE5CE4 80242534 8C420020 */  lw        $v0, 0x20($v0)
/* BE5CE8 80242538 AE020028 */  sw        $v0, 0x28($s0)
/* BE5CEC 8024253C 24020001 */  addiu     $v0, $zero, 1
/* BE5CF0 80242540 AE220070 */  sw        $v0, 0x70($s1)
/* BE5CF4 80242544 8FBF001C */  lw        $ra, 0x1c($sp)
/* BE5CF8 80242548 8FB20018 */  lw        $s2, 0x18($sp)
/* BE5CFC 8024254C 8FB10014 */  lw        $s1, 0x14($sp)
/* BE5D00 80242550 8FB00010 */  lw        $s0, 0x10($sp)
/* BE5D04 80242554 03E00008 */  jr        $ra
/* BE5D08 80242558 27BD0020 */   addiu    $sp, $sp, 0x20
