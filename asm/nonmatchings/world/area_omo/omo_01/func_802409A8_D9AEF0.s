.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409A8_D9B898
/* D9B898 802409A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D9B89C 802409AC AFB00010 */  sw        $s0, 0x10($sp)
/* D9B8A0 802409B0 0080802D */  daddu     $s0, $a0, $zero
/* D9B8A4 802409B4 AFBF0014 */  sw        $ra, 0x14($sp)
/* D9B8A8 802409B8 8E020148 */  lw        $v0, 0x148($s0)
/* D9B8AC 802409BC 0C00EABB */  jal       get_npc_unsafe
/* D9B8B0 802409C0 84440008 */   lh       $a0, 8($v0)
/* D9B8B4 802409C4 9443008E */  lhu       $v1, 0x8e($v0)
/* D9B8B8 802409C8 2463FFFF */  addiu     $v1, $v1, -1
/* D9B8BC 802409CC A443008E */  sh        $v1, 0x8e($v0)
/* D9B8C0 802409D0 00031C00 */  sll       $v1, $v1, 0x10
/* D9B8C4 802409D4 50600001 */  beql      $v1, $zero, .L802409DC
/* D9B8C8 802409D8 AE000070 */   sw       $zero, 0x70($s0)
.L802409DC:
/* D9B8CC 802409DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* D9B8D0 802409E0 8FB00010 */  lw        $s0, 0x10($sp)
/* D9B8D4 802409E4 03E00008 */  jr        $ra
/* D9B8D8 802409E8 27BD0018 */   addiu    $sp, $sp, 0x18
