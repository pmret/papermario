.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C4C
/* 9169BC 80240C4C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9169C0 80240C50 AFB00010 */  sw        $s0, 0x10($sp)
/* 9169C4 80240C54 0080802D */  daddu     $s0, $a0, $zero
/* 9169C8 80240C58 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9169CC 80240C5C 8E020148 */  lw        $v0, 0x148($s0)
/* 9169D0 80240C60 0C00EABB */  jal       get_npc_unsafe
/* 9169D4 80240C64 84440008 */   lh       $a0, 8($v0)
/* 9169D8 80240C68 9443008E */  lhu       $v1, 0x8e($v0)
/* 9169DC 80240C6C 2463FFFF */  addiu     $v1, $v1, -1
/* 9169E0 80240C70 A443008E */  sh        $v1, 0x8e($v0)
/* 9169E4 80240C74 00031C00 */  sll       $v1, $v1, 0x10
/* 9169E8 80240C78 58600001 */  blezl     $v1, .L80240C80
/* 9169EC 80240C7C AE000070 */   sw       $zero, 0x70($s0)
.L80240C80:
/* 9169F0 80240C80 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9169F4 80240C84 8FB00010 */  lw        $s0, 0x10($sp)
/* 9169F8 80240C88 03E00008 */  jr        $ra
/* 9169FC 80240C8C 27BD0018 */   addiu    $sp, $sp, 0x18
