.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242554_DBF804
/* DBF804 80242554 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DBF808 80242558 AFB20018 */  sw        $s2, 0x18($sp)
/* DBF80C 8024255C 0080902D */  daddu     $s2, $a0, $zero
/* DBF810 80242560 AFBF001C */  sw        $ra, 0x1c($sp)
/* DBF814 80242564 AFB10014 */  sw        $s1, 0x14($sp)
/* DBF818 80242568 AFB00010 */  sw        $s0, 0x10($sp)
/* DBF81C 8024256C 8E510148 */  lw        $s1, 0x148($s2)
/* DBF820 80242570 0C00EABB */  jal       get_npc_unsafe
/* DBF824 80242574 86240008 */   lh       $a0, 8($s1)
/* DBF828 80242578 0040802D */  daddu     $s0, $v0, $zero
/* DBF82C 8024257C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DBF830 80242580 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DBF834 80242584 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DBF838 80242588 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DBF83C 8024258C A600008E */  sh        $zero, 0x8e($s0)
/* DBF840 80242590 8C460028 */  lw        $a2, 0x28($v0)
/* DBF844 80242594 0C00A720 */  jal       atan2
/* DBF848 80242598 8C470030 */   lw       $a3, 0x30($v0)
/* DBF84C 8024259C E600000C */  swc1      $f0, 0xc($s0)
/* DBF850 802425A0 8E2200CC */  lw        $v0, 0xcc($s1)
/* DBF854 802425A4 8C420020 */  lw        $v0, 0x20($v0)
/* DBF858 802425A8 AE020028 */  sw        $v0, 0x28($s0)
/* DBF85C 802425AC 2402000B */  addiu     $v0, $zero, 0xb
/* DBF860 802425B0 AE420070 */  sw        $v0, 0x70($s2)
/* DBF864 802425B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* DBF868 802425B8 8FB20018 */  lw        $s2, 0x18($sp)
/* DBF86C 802425BC 8FB10014 */  lw        $s1, 0x14($sp)
/* DBF870 802425C0 8FB00010 */  lw        $s0, 0x10($sp)
/* DBF874 802425C4 03E00008 */  jr        $ra
/* DBF878 802425C8 27BD0020 */   addiu    $sp, $sp, 0x20
