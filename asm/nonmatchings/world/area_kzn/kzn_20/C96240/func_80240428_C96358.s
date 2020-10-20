.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240428_C96358
/* C96358 80240428 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C9635C 8024042C AFB10014 */  sw        $s1, 0x14($sp)
/* C96360 80240430 0080882D */  daddu     $s1, $a0, $zero
/* C96364 80240434 AFBF0018 */  sw        $ra, 0x18($sp)
/* C96368 80240438 AFB00010 */  sw        $s0, 0x10($sp)
/* C9636C 8024043C 8E30000C */  lw        $s0, 0xc($s1)
/* C96370 80240440 8E050000 */  lw        $a1, ($s0)
/* C96374 80240444 0C0B1EAF */  jal       get_variable
/* C96378 80240448 26100004 */   addiu    $s0, $s0, 4
/* C9637C 8024044C 0C00EAD2 */  jal       get_npc_safe
/* C96380 80240450 0040202D */   daddu    $a0, $v0, $zero
/* C96384 80240454 10400005 */  beqz      $v0, .L8024046C
/* C96388 80240458 00000000 */   nop      
/* C9638C 8024045C 8E050000 */  lw        $a1, ($s0)
/* C96390 80240460 844600A8 */  lh        $a2, 0xa8($v0)
/* C96394 80240464 0C0B2026 */  jal       set_variable
/* C96398 80240468 0220202D */   daddu    $a0, $s1, $zero
.L8024046C:
/* C9639C 8024046C 8FBF0018 */  lw        $ra, 0x18($sp)
/* C963A0 80240470 8FB10014 */  lw        $s1, 0x14($sp)
/* C963A4 80240474 8FB00010 */  lw        $s0, 0x10($sp)
/* C963A8 80240478 24020002 */  addiu     $v0, $zero, 2
/* C963AC 8024047C 03E00008 */  jr        $ra
/* C963B0 80240480 27BD0020 */   addiu    $sp, $sp, 0x20
