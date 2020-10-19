.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240970_A64A00
/* A64A00 80240970 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A64A04 80240974 AFB10014 */  sw        $s1, 0x14($sp)
/* A64A08 80240978 0080882D */  daddu     $s1, $a0, $zero
/* A64A0C 8024097C AFBF0018 */  sw        $ra, 0x18($sp)
/* A64A10 80240980 AFB00010 */  sw        $s0, 0x10($sp)
/* A64A14 80240984 8E220148 */  lw        $v0, 0x148($s1)
/* A64A18 80240988 0C00EABB */  jal       get_npc_unsafe
/* A64A1C 8024098C 84440008 */   lh       $a0, 8($v0)
/* A64A20 80240990 0040802D */  daddu     $s0, $v0, $zero
/* A64A24 80240994 8E050018 */  lw        $a1, 0x18($s0)
/* A64A28 80240998 8E06000C */  lw        $a2, 0xc($s0)
/* A64A2C 8024099C 0C00EA95 */  jal       npc_move_heading
/* A64A30 802409A0 0200202D */   daddu    $a0, $s0, $zero
/* A64A34 802409A4 9602008E */  lhu       $v0, 0x8e($s0)
/* A64A38 802409A8 2442FFFF */  addiu     $v0, $v0, -1
/* A64A3C 802409AC A602008E */  sh        $v0, 0x8e($s0)
/* A64A40 802409B0 00021400 */  sll       $v0, $v0, 0x10
/* A64A44 802409B4 1C400002 */  bgtz      $v0, .L802409C0
/* A64A48 802409B8 2402000A */   addiu    $v0, $zero, 0xa
/* A64A4C 802409BC AE220070 */  sw        $v0, 0x70($s1)
.L802409C0:
/* A64A50 802409C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* A64A54 802409C4 8FB10014 */  lw        $s1, 0x14($sp)
/* A64A58 802409C8 8FB00010 */  lw        $s0, 0x10($sp)
/* A64A5C 802409CC 03E00008 */  jr        $ra
/* A64A60 802409D0 27BD0020 */   addiu    $sp, $sp, 0x20
