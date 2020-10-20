.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240428_A39908
/* A39908 80240428 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A3990C 8024042C AFB10014 */  sw        $s1, 0x14($sp)
/* A39910 80240430 0080882D */  daddu     $s1, $a0, $zero
/* A39914 80240434 AFBF0018 */  sw        $ra, 0x18($sp)
/* A39918 80240438 AFB00010 */  sw        $s0, 0x10($sp)
/* A3991C 8024043C 8E30000C */  lw        $s0, 0xc($s1)
/* A39920 80240440 8E050000 */  lw        $a1, ($s0)
/* A39924 80240444 0C0B1EAF */  jal       get_variable
/* A39928 80240448 26100004 */   addiu    $s0, $s0, 4
/* A3992C 8024044C 0C00EAD2 */  jal       get_npc_safe
/* A39930 80240450 0040202D */   daddu    $a0, $v0, $zero
/* A39934 80240454 10400005 */  beqz      $v0, .L8024046C
/* A39938 80240458 00000000 */   nop      
/* A3993C 8024045C 8E050000 */  lw        $a1, ($s0)
/* A39940 80240460 844600A8 */  lh        $a2, 0xa8($v0)
/* A39944 80240464 0C0B2026 */  jal       set_variable
/* A39948 80240468 0220202D */   daddu    $a0, $s1, $zero
.L8024046C:
/* A3994C 8024046C 8FBF0018 */  lw        $ra, 0x18($sp)
/* A39950 80240470 8FB10014 */  lw        $s1, 0x14($sp)
/* A39954 80240474 8FB00010 */  lw        $s0, 0x10($sp)
/* A39958 80240478 24020002 */  addiu     $v0, $zero, 2
/* A3995C 8024047C 03E00008 */  jr        $ra
/* A39960 80240480 27BD0020 */   addiu    $sp, $sp, 0x20
