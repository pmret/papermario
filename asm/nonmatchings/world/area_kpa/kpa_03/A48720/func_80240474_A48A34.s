.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240474_A48A34
/* A48A34 80240474 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A48A38 80240478 AFB10014 */  sw        $s1, 0x14($sp)
/* A48A3C 8024047C 0080882D */  daddu     $s1, $a0, $zero
/* A48A40 80240480 AFBF0018 */  sw        $ra, 0x18($sp)
/* A48A44 80240484 AFB00010 */  sw        $s0, 0x10($sp)
/* A48A48 80240488 8E300148 */  lw        $s0, 0x148($s1)
/* A48A4C 8024048C 0C00EABB */  jal       get_npc_unsafe
/* A48A50 80240490 86040008 */   lh       $a0, 8($s0)
/* A48A54 80240494 0040202D */  daddu     $a0, $v0, $zero
/* A48A58 80240498 9482008E */  lhu       $v0, 0x8e($a0)
/* A48A5C 8024049C 24030003 */  addiu     $v1, $zero, 3
/* A48A60 802404A0 24420001 */  addiu     $v0, $v0, 1
/* A48A64 802404A4 A482008E */  sh        $v0, 0x8e($a0)
/* A48A68 802404A8 00021400 */  sll       $v0, $v0, 0x10
/* A48A6C 802404AC 00021403 */  sra       $v0, $v0, 0x10
/* A48A70 802404B0 14430003 */  bne       $v0, $v1, .L802404C0
/* A48A74 802404B4 00000000 */   nop      
/* A48A78 802404B8 96020086 */  lhu       $v0, 0x86($s0)
/* A48A7C 802404BC A48200A8 */  sh        $v0, 0xa8($a0)
.L802404C0:
/* A48A80 802404C0 8482008E */  lh        $v0, 0x8e($a0)
/* A48A84 802404C4 8E030080 */  lw        $v1, 0x80($s0)
/* A48A88 802404C8 0043102A */  slt       $v0, $v0, $v1
/* A48A8C 802404CC 14400004 */  bnez      $v0, .L802404E0
/* A48A90 802404D0 00000000 */   nop      
/* A48A94 802404D4 96020086 */  lhu       $v0, 0x86($s0)
/* A48A98 802404D8 A48200A8 */  sh        $v0, 0xa8($a0)
/* A48A9C 802404DC AE200070 */  sw        $zero, 0x70($s1)
.L802404E0:
/* A48AA0 802404E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* A48AA4 802404E4 8FB10014 */  lw        $s1, 0x14($sp)
/* A48AA8 802404E8 8FB00010 */  lw        $s0, 0x10($sp)
/* A48AAC 802404EC 03E00008 */  jr        $ra
/* A48AB0 802404F0 27BD0020 */   addiu    $sp, $sp, 0x20
