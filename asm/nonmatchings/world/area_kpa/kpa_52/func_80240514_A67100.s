.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240514_A67614
/* A67614 80240514 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A67618 80240518 AFB10014 */  sw        $s1, 0x14($sp)
/* A6761C 8024051C 0080882D */  daddu     $s1, $a0, $zero
/* A67620 80240520 AFBF0018 */  sw        $ra, 0x18($sp)
/* A67624 80240524 AFB00010 */  sw        $s0, 0x10($sp)
/* A67628 80240528 8E300148 */  lw        $s0, 0x148($s1)
/* A6762C 8024052C 0C00EABB */  jal       get_npc_unsafe
/* A67630 80240530 86040008 */   lh       $a0, 8($s0)
/* A67634 80240534 96030076 */  lhu       $v1, 0x76($s0)
/* A67638 80240538 A443008E */  sh        $v1, 0x8e($v0)
/* A6763C 8024053C 24020021 */  addiu     $v0, $zero, 0x21
/* A67640 80240540 AE220070 */  sw        $v0, 0x70($s1)
/* A67644 80240544 8FBF0018 */  lw        $ra, 0x18($sp)
/* A67648 80240548 8FB10014 */  lw        $s1, 0x14($sp)
/* A6764C 8024054C 8FB00010 */  lw        $s0, 0x10($sp)
/* A67650 80240550 03E00008 */  jr        $ra
/* A67654 80240554 27BD0020 */   addiu    $sp, $sp, 0x20
