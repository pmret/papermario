.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F8C_919B3C
/* 919B3C 80240F8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 919B40 80240F90 AFB00010 */  sw        $s0, 0x10($sp)
/* 919B44 80240F94 0080802D */  daddu     $s0, $a0, $zero
/* 919B48 80240F98 AFBF0014 */  sw        $ra, 0x14($sp)
/* 919B4C 80240F9C 8E020148 */  lw        $v0, 0x148($s0)
/* 919B50 80240FA0 0C00EABB */  jal       get_npc_unsafe
/* 919B54 80240FA4 84440008 */   lh       $a0, 8($v0)
/* 919B58 80240FA8 9443008E */  lhu       $v1, 0x8e($v0)
/* 919B5C 80240FAC 2463FFFF */  addiu     $v1, $v1, -1
/* 919B60 80240FB0 A443008E */  sh        $v1, 0x8e($v0)
/* 919B64 80240FB4 00031C00 */  sll       $v1, $v1, 0x10
/* 919B68 80240FB8 58600001 */  blezl     $v1, .L80240FC0
/* 919B6C 80240FBC AE000070 */   sw       $zero, 0x70($s0)
.L80240FC0:
/* 919B70 80240FC0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 919B74 80240FC4 8FB00010 */  lw        $s0, 0x10($sp)
/* 919B78 80240FC8 03E00008 */  jr        $ra
/* 919B7C 80240FCC 27BD0018 */   addiu    $sp, $sp, 0x18
