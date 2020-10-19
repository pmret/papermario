.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C64
/* 91C544 80240C64 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91C548 80240C68 AFB10014 */  sw        $s1, 0x14($sp)
/* 91C54C 80240C6C 0080882D */  daddu     $s1, $a0, $zero
/* 91C550 80240C70 AFBF0018 */  sw        $ra, 0x18($sp)
/* 91C554 80240C74 AFB00010 */  sw        $s0, 0x10($sp)
/* 91C558 80240C78 8E300148 */  lw        $s0, 0x148($s1)
/* 91C55C 80240C7C 0C00EABB */  jal       get_npc_unsafe
/* 91C560 80240C80 86040008 */   lh       $a0, 8($s0)
/* 91C564 80240C84 0040182D */  daddu     $v1, $v0, $zero
/* 91C568 80240C88 9462008E */  lhu       $v0, 0x8e($v1)
/* 91C56C 80240C8C 2442FFFF */  addiu     $v0, $v0, -1
/* 91C570 80240C90 A462008E */  sh        $v0, 0x8e($v1)
/* 91C574 80240C94 00021400 */  sll       $v0, $v0, 0x10
/* 91C578 80240C98 1C400007 */  bgtz      $v0, .L80240CB8
/* 91C57C 80240C9C 24020008 */   addiu    $v0, $zero, 8
/* 91C580 80240CA0 A462008E */  sh        $v0, 0x8e($v1)
/* 91C584 80240CA4 8E0200CC */  lw        $v0, 0xcc($s0)
/* 91C588 80240CA8 8C420038 */  lw        $v0, 0x38($v0)
/* 91C58C 80240CAC AC620028 */  sw        $v0, 0x28($v1)
/* 91C590 80240CB0 24020034 */  addiu     $v0, $zero, 0x34
/* 91C594 80240CB4 AE220070 */  sw        $v0, 0x70($s1)
.L80240CB8:
/* 91C598 80240CB8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 91C59C 80240CBC 8FB10014 */  lw        $s1, 0x14($sp)
/* 91C5A0 80240CC0 8FB00010 */  lw        $s0, 0x10($sp)
/* 91C5A4 80240CC4 03E00008 */  jr        $ra
/* 91C5A8 80240CC8 27BD0020 */   addiu    $sp, $sp, 0x20
