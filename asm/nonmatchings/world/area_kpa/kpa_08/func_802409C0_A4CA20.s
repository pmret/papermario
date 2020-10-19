.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409C0_A4D3E0
/* A4D3E0 802409C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A4D3E4 802409C4 AFB10014 */  sw        $s1, 0x14($sp)
/* A4D3E8 802409C8 0080882D */  daddu     $s1, $a0, $zero
/* A4D3EC 802409CC AFBF0018 */  sw        $ra, 0x18($sp)
/* A4D3F0 802409D0 AFB00010 */  sw        $s0, 0x10($sp)
/* A4D3F4 802409D4 8E220148 */  lw        $v0, 0x148($s1)
/* A4D3F8 802409D8 0C00EABB */  jal       get_npc_unsafe
/* A4D3FC 802409DC 84440008 */   lh       $a0, 8($v0)
/* A4D400 802409E0 0040802D */  daddu     $s0, $v0, $zero
/* A4D404 802409E4 8E050018 */  lw        $a1, 0x18($s0)
/* A4D408 802409E8 8E06000C */  lw        $a2, 0xc($s0)
/* A4D40C 802409EC 0C00EA95 */  jal       npc_move_heading
/* A4D410 802409F0 0200202D */   daddu    $a0, $s0, $zero
/* A4D414 802409F4 9602008E */  lhu       $v0, 0x8e($s0)
/* A4D418 802409F8 2442FFFF */  addiu     $v0, $v0, -1
/* A4D41C 802409FC A602008E */  sh        $v0, 0x8e($s0)
/* A4D420 80240A00 00021400 */  sll       $v0, $v0, 0x10
/* A4D424 80240A04 1C400002 */  bgtz      $v0, .L80240A10
/* A4D428 80240A08 2402000A */   addiu    $v0, $zero, 0xa
/* A4D42C 80240A0C AE220070 */  sw        $v0, 0x70($s1)
.L80240A10:
/* A4D430 80240A10 8FBF0018 */  lw        $ra, 0x18($sp)
/* A4D434 80240A14 8FB10014 */  lw        $s1, 0x14($sp)
/* A4D438 80240A18 8FB00010 */  lw        $s0, 0x10($sp)
/* A4D43C 80240A1C 03E00008 */  jr        $ra
/* A4D440 80240A20 27BD0020 */   addiu    $sp, $sp, 0x20
