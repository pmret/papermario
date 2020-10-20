.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405B8
/* A4F5B8 802405B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A4F5BC 802405BC AFB00010 */  sw        $s0, 0x10($sp)
/* A4F5C0 802405C0 0080802D */  daddu     $s0, $a0, $zero
/* A4F5C4 802405C4 AFBF0014 */  sw        $ra, 0x14($sp)
/* A4F5C8 802405C8 8E020148 */  lw        $v0, 0x148($s0)
/* A4F5CC 802405CC 0C00EABB */  jal       get_npc_unsafe
/* A4F5D0 802405D0 84440008 */   lh       $a0, 8($v0)
/* A4F5D4 802405D4 9443008E */  lhu       $v1, 0x8e($v0)
/* A4F5D8 802405D8 2463FFFF */  addiu     $v1, $v1, -1
/* A4F5DC 802405DC A443008E */  sh        $v1, 0x8e($v0)
/* A4F5E0 802405E0 00031C00 */  sll       $v1, $v1, 0x10
/* A4F5E4 802405E4 58600001 */  blezl     $v1, .L802405EC
/* A4F5E8 802405E8 AE000070 */   sw       $zero, 0x70($s0)
.L802405EC:
/* A4F5EC 802405EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* A4F5F0 802405F0 8FB00010 */  lw        $s0, 0x10($sp)
/* A4F5F4 802405F4 03E00008 */  jr        $ra
/* A4F5F8 802405F8 27BD0018 */   addiu    $sp, $sp, 0x18
