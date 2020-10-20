.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413D4_D9E8A4
/* D9E8A4 802413D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D9E8A8 802413D8 AFB00010 */  sw        $s0, 0x10($sp)
/* D9E8AC 802413DC 0080802D */  daddu     $s0, $a0, $zero
/* D9E8B0 802413E0 AFBF0014 */  sw        $ra, 0x14($sp)
/* D9E8B4 802413E4 8E020148 */  lw        $v0, 0x148($s0)
/* D9E8B8 802413E8 0C00EABB */  jal       get_npc_unsafe
/* D9E8BC 802413EC 84440008 */   lh       $a0, 8($v0)
/* D9E8C0 802413F0 9443008E */  lhu       $v1, 0x8e($v0)
/* D9E8C4 802413F4 2463FFFF */  addiu     $v1, $v1, -1
/* D9E8C8 802413F8 A443008E */  sh        $v1, 0x8e($v0)
/* D9E8CC 802413FC 00031C00 */  sll       $v1, $v1, 0x10
/* D9E8D0 80241400 14600002 */  bnez      $v1, .L8024140C
/* D9E8D4 80241404 2402000F */   addiu    $v0, $zero, 0xf
/* D9E8D8 80241408 AE020070 */  sw        $v0, 0x70($s0)
.L8024140C:
/* D9E8DC 8024140C 8FBF0014 */  lw        $ra, 0x14($sp)
/* D9E8E0 80241410 8FB00010 */  lw        $s0, 0x10($sp)
/* D9E8E4 80241414 03E00008 */  jr        $ra
/* D9E8E8 80241418 27BD0018 */   addiu    $sp, $sp, 0x18
