.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F10
/* 9125C0 80242F10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9125C4 80242F14 AFB00010 */  sw        $s0, 0x10($sp)
/* 9125C8 80242F18 0080802D */  daddu     $s0, $a0, $zero
/* 9125CC 80242F1C AFBF0014 */  sw        $ra, 0x14($sp)
/* 9125D0 80242F20 8E020148 */  lw        $v0, 0x148($s0)
/* 9125D4 80242F24 0C00EABB */  jal       get_npc_unsafe
/* 9125D8 80242F28 84440008 */   lh       $a0, 8($v0)
/* 9125DC 80242F2C 9443008E */  lhu       $v1, 0x8e($v0)
/* 9125E0 80242F30 2463FFFF */  addiu     $v1, $v1, -1
/* 9125E4 80242F34 A443008E */  sh        $v1, 0x8e($v0)
/* 9125E8 80242F38 00031C00 */  sll       $v1, $v1, 0x10
/* 9125EC 80242F3C 58600001 */  blezl     $v1, .L80242F44
/* 9125F0 80242F40 AE000070 */   sw       $zero, 0x70($s0)
.L80242F44:
/* 9125F4 80242F44 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9125F8 80242F48 8FB00010 */  lw        $s0, 0x10($sp)
/* 9125FC 80242F4C 03E00008 */  jr        $ra
/* 912600 80242F50 27BD0018 */   addiu    $sp, $sp, 0x18
