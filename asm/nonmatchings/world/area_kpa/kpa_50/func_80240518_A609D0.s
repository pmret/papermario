.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240518_A60EE8
/* A60EE8 80240518 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A60EEC 8024051C AFB00010 */  sw        $s0, 0x10($sp)
/* A60EF0 80240520 0080802D */  daddu     $s0, $a0, $zero
/* A60EF4 80240524 AFBF0014 */  sw        $ra, 0x14($sp)
/* A60EF8 80240528 8E020148 */  lw        $v0, 0x148($s0)
/* A60EFC 8024052C 0C00EABB */  jal       get_npc_unsafe
/* A60F00 80240530 84440008 */   lh       $a0, 8($v0)
/* A60F04 80240534 9443008E */  lhu       $v1, 0x8e($v0)
/* A60F08 80240538 2463FFFF */  addiu     $v1, $v1, -1
/* A60F0C 8024053C A443008E */  sh        $v1, 0x8e($v0)
/* A60F10 80240540 00031C00 */  sll       $v1, $v1, 0x10
/* A60F14 80240544 58600001 */  blezl     $v1, .L8024054C
/* A60F18 80240548 AE000070 */   sw       $zero, 0x70($s0)
.L8024054C:
/* A60F1C 8024054C 8FBF0014 */  lw        $ra, 0x14($sp)
/* A60F20 80240550 8FB00010 */  lw        $s0, 0x10($sp)
/* A60F24 80240554 03E00008 */  jr        $ra
/* A60F28 80240558 27BD0018 */   addiu    $sp, $sp, 0x18
