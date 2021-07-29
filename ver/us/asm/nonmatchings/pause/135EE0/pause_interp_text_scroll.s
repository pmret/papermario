.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_interp_text_scroll
/* 136758 80243418 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 13675C 8024341C AFB00010 */  sw        $s0, 0x10($sp)
/* 136760 80243420 04810002 */  bgez      $a0, .L8024342C
/* 136764 80243424 0080802D */   daddu    $s0, $a0, $zero
/* 136768 80243428 00108023 */  negu      $s0, $s0
.L8024342C:
/* 13676C 8024342C AFBF0014 */  sw        $ra, 0x14($sp)
/* 136770 80243430 0C00A52C */  jal       sign
/* 136774 80243434 00000000 */   nop
/* 136778 80243438 0040182D */  daddu     $v1, $v0, $zero
/* 13677C 8024343C 2A020010 */  slti      $v0, $s0, 0x10
/* 136780 80243440 10400004 */  beqz      $v0, .L80243454
/* 136784 80243444 24020008 */   addiu    $v0, $zero, 8
/* 136788 80243448 3C028025 */  lui       $v0, %hi(gPauseMenuTextScrollInterpEasingLUT)
/* 13678C 8024344C 00501021 */  addu      $v0, $v0, $s0
/* 136790 80243450 9042F0AC */  lbu       $v0, %lo(gPauseMenuTextScrollInterpEasingLUT)($v0)
.L80243454:
/* 136794 80243454 00430018 */  mult      $v0, $v1
/* 136798 80243458 8FBF0014 */  lw        $ra, 0x14($sp)
/* 13679C 8024345C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1367A0 80243460 00001012 */  mflo      $v0
/* 1367A4 80243464 03E00008 */  jr        $ra
/* 1367A8 80243468 27BD0018 */   addiu    $sp, $sp, 0x18
