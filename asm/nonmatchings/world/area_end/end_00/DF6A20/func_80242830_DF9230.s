.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242830_DF9230
/* DF9230 80242830 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DF9234 80242834 AFB10014 */  sw        $s1, 0x14($sp)
/* DF9238 80242838 0080882D */  daddu     $s1, $a0, $zero
/* DF923C 8024283C AFBF0018 */  sw        $ra, 0x18($sp)
/* DF9240 80242840 AFB00010 */  sw        $s0, 0x10($sp)
/* DF9244 80242844 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DF9248 80242848 8E30000C */  lw        $s0, 0xc($s1)
/* DF924C 8024284C 8E050000 */  lw        $a1, ($s0)
/* DF9250 80242850 0C0B1EAF */  jal       get_variable
/* DF9254 80242854 26100004 */   addiu    $s0, $s0, 4
/* DF9258 80242858 0220202D */  daddu     $a0, $s1, $zero
/* DF925C 8024285C 8E050000 */  lw        $a1, ($s0)
/* DF9260 80242860 0C0B210B */  jal       get_float_variable
/* DF9264 80242864 0040802D */   daddu    $s0, $v0, $zero
/* DF9268 80242868 0220202D */  daddu     $a0, $s1, $zero
/* DF926C 8024286C 0200282D */  daddu     $a1, $s0, $zero
/* DF9270 80242870 0C0B36B0 */  jal       resolve_npc
/* DF9274 80242874 46000506 */   mov.s    $f20, $f0
/* DF9278 80242878 E454007C */  swc1      $f20, 0x7c($v0)
/* DF927C 8024287C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DF9280 80242880 8FB10014 */  lw        $s1, 0x14($sp)
/* DF9284 80242884 8FB00010 */  lw        $s0, 0x10($sp)
/* DF9288 80242888 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DF928C 8024288C 24020002 */  addiu     $v0, $zero, 2
/* DF9290 80242890 03E00008 */  jr        $ra
/* DF9294 80242894 27BD0028 */   addiu    $sp, $sp, 0x28
