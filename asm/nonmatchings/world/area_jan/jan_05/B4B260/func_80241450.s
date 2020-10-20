.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241450
/* B4BEC0 80241450 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B4BEC4 80241454 AFB00010 */  sw        $s0, 0x10($sp)
/* B4BEC8 80241458 0080802D */  daddu     $s0, $a0, $zero
/* B4BECC 8024145C AFBF0014 */  sw        $ra, 0x14($sp)
/* B4BED0 80241460 8E020148 */  lw        $v0, 0x148($s0)
/* B4BED4 80241464 0C00EABB */  jal       get_npc_unsafe
/* B4BED8 80241468 84440008 */   lh       $a0, 8($v0)
/* B4BEDC 8024146C 9443008E */  lhu       $v1, 0x8e($v0)
/* B4BEE0 80241470 2463FFFF */  addiu     $v1, $v1, -1
/* B4BEE4 80241474 A443008E */  sh        $v1, 0x8e($v0)
/* B4BEE8 80241478 00031C00 */  sll       $v1, $v1, 0x10
/* B4BEEC 8024147C 58600001 */  blezl     $v1, .L80241484
/* B4BEF0 80241480 AE000070 */   sw       $zero, 0x70($s0)
.L80241484:
/* B4BEF4 80241484 8FBF0014 */  lw        $ra, 0x14($sp)
/* B4BEF8 80241488 8FB00010 */  lw        $s0, 0x10($sp)
/* B4BEFC 8024148C 03E00008 */  jr        $ra
/* B4BF00 80241490 27BD0018 */   addiu    $sp, $sp, 0x18
