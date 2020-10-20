.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411C4_A6F5A4
/* A6F5A4 802411C4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A6F5A8 802411C8 AFB00010 */  sw        $s0, 0x10($sp)
/* A6F5AC 802411CC 0080802D */  daddu     $s0, $a0, $zero
/* A6F5B0 802411D0 AFBF0014 */  sw        $ra, 0x14($sp)
/* A6F5B4 802411D4 8E020148 */  lw        $v0, 0x148($s0)
/* A6F5B8 802411D8 0C00EABB */  jal       get_npc_unsafe
/* A6F5BC 802411DC 84440008 */   lh       $a0, 8($v0)
/* A6F5C0 802411E0 2403001E */  addiu     $v1, $zero, 0x1e
/* A6F5C4 802411E4 A443008E */  sh        $v1, 0x8e($v0)
/* A6F5C8 802411E8 2402000B */  addiu     $v0, $zero, 0xb
/* A6F5CC 802411EC AE020070 */  sw        $v0, 0x70($s0)
/* A6F5D0 802411F0 8FBF0014 */  lw        $ra, 0x14($sp)
/* A6F5D4 802411F4 8FB00010 */  lw        $s0, 0x10($sp)
/* A6F5D8 802411F8 03E00008 */  jr        $ra
/* A6F5DC 802411FC 27BD0018 */   addiu    $sp, $sp, 0x18
