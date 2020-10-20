.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E60
/* D9F330 80241E60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D9F334 80241E64 AFB00010 */  sw        $s0, 0x10($sp)
/* D9F338 80241E68 0080802D */  daddu     $s0, $a0, $zero
/* D9F33C 80241E6C AFBF0014 */  sw        $ra, 0x14($sp)
/* D9F340 80241E70 8E020148 */  lw        $v0, 0x148($s0)
/* D9F344 80241E74 0C00EABB */  jal       get_npc_unsafe
/* D9F348 80241E78 84440008 */   lh       $a0, 8($v0)
/* D9F34C 80241E7C 9443008E */  lhu       $v1, 0x8e($v0)
/* D9F350 80241E80 2463FFFF */  addiu     $v1, $v1, -1
/* D9F354 80241E84 A443008E */  sh        $v1, 0x8e($v0)
/* D9F358 80241E88 00031C00 */  sll       $v1, $v1, 0x10
/* D9F35C 80241E8C 58600001 */  blezl     $v1, .L80241E94
/* D9F360 80241E90 AE000070 */   sw       $zero, 0x70($s0)
.L80241E94:
/* D9F364 80241E94 8FBF0014 */  lw        $ra, 0x14($sp)
/* D9F368 80241E98 8FB00010 */  lw        $s0, 0x10($sp)
/* D9F36C 80241E9C 03E00008 */  jr        $ra
/* D9F370 80241EA0 27BD0018 */   addiu    $sp, $sp, 0x18
