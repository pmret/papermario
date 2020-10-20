.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024280C
/* 8B287C 8024280C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B2880 80242810 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B2884 80242814 0080802D */  daddu     $s0, $a0, $zero
/* 8B2888 80242818 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8B288C 8024281C AFB10014 */  sw        $s1, 0x14($sp)
/* 8B2890 80242820 8E11000C */  lw        $s1, 0xc($s0)
/* 8B2894 80242824 0C0B36B0 */  jal       resolve_npc
/* 8B2898 80242828 0000282D */   daddu    $a1, $zero, $zero
/* 8B289C 8024282C 0200202D */  daddu     $a0, $s0, $zero
/* 8B28A0 80242830 8E250000 */  lw        $a1, ($s1)
/* 8B28A4 80242834 0C0B210B */  jal       get_float_variable
/* 8B28A8 80242838 0040802D */   daddu    $s0, $v0, $zero
/* 8B28AC 8024283C C6020034 */  lwc1      $f2, 0x34($s0)
/* 8B28B0 80242840 46001080 */  add.s     $f2, $f2, $f0
/* 8B28B4 80242844 E6020034 */  swc1      $f2, 0x34($s0)
/* 8B28B8 80242848 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8B28BC 8024284C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B28C0 80242850 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B28C4 80242854 24020002 */  addiu     $v0, $zero, 2
/* 8B28C8 80242858 03E00008 */  jr        $ra
/* 8B28CC 8024285C 27BD0020 */   addiu    $sp, $sp, 0x20
