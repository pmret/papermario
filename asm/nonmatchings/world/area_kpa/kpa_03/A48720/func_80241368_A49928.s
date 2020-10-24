.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241368_A49928
/* A49928 80241368 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A4992C 8024136C AFB10014 */  sw        $s1, 0x14($sp)
/* A49930 80241370 0080882D */  daddu     $s1, $a0, $zero
/* A49934 80241374 AFBF0018 */  sw        $ra, 0x18($sp)
/* A49938 80241378 AFB00010 */  sw        $s0, 0x10($sp)
/* A4993C 8024137C 8E220148 */  lw        $v0, 0x148($s1)
/* A49940 80241380 0C00EABB */  jal       get_npc_unsafe
/* A49944 80241384 84440008 */   lh       $a0, 8($v0)
/* A49948 80241388 0040802D */  daddu     $s0, $v0, $zero
/* A4994C 8024138C 8E050018 */  lw        $a1, 0x18($s0)
/* A49950 80241390 8E06000C */  lw        $a2, 0xc($s0)
/* A49954 80241394 0C00EA95 */  jal       npc_move_heading
/* A49958 80241398 0200202D */   daddu    $a0, $s0, $zero
/* A4995C 8024139C 9602008E */  lhu       $v0, 0x8e($s0)
/* A49960 802413A0 2442FFFF */  addiu     $v0, $v0, -1
/* A49964 802413A4 A602008E */  sh        $v0, 0x8e($s0)
/* A49968 802413A8 00021400 */  sll       $v0, $v0, 0x10
/* A4996C 802413AC 1C400002 */  bgtz      $v0, .L802413B8
/* A49970 802413B0 2402000A */   addiu    $v0, $zero, 0xa
/* A49974 802413B4 AE220070 */  sw        $v0, 0x70($s1)
.L802413B8:
/* A49978 802413B8 8FBF0018 */  lw        $ra, 0x18($sp)
/* A4997C 802413BC 8FB10014 */  lw        $s1, 0x14($sp)
/* A49980 802413C0 8FB00010 */  lw        $s0, 0x10($sp)
/* A49984 802413C4 03E00008 */  jr        $ra
/* A49988 802413C8 27BD0020 */   addiu    $sp, $sp, 0x20
