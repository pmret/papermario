.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422D0_E18050
/* E18050 802422D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E18054 802422D4 0000202D */  daddu     $a0, $zero, $zero
/* E18058 802422D8 AFBF0014 */  sw        $ra, 0x14($sp)
/* E1805C 802422DC 0C00FB3A */  jal       get_enemy
/* E18060 802422E0 AFB00010 */   sw       $s0, 0x10($sp)
/* E18064 802422E4 8C50006C */  lw        $s0, 0x6c($v0)
/* E18068 802422E8 0C048D70 */  jal       free_dynamic_entity
/* E1806C 802422EC 8E040000 */   lw       $a0, ($s0)
/* E18070 802422F0 0C05123D */  jal       free_icon
/* E18074 802422F4 8E04000C */   lw       $a0, 0xc($s0)
/* E18078 802422F8 0C05123D */  jal       free_icon
/* E1807C 802422FC 8E040010 */   lw       $a0, 0x10($s0)
/* E18080 80242300 8FBF0014 */  lw        $ra, 0x14($sp)
/* E18084 80242304 8FB00010 */  lw        $s0, 0x10($sp)
/* E18088 80242308 24020002 */  addiu     $v0, $zero, 2
/* E1808C 8024230C 03E00008 */  jr        $ra
/* E18090 80242310 27BD0018 */   addiu    $sp, $sp, 0x18
