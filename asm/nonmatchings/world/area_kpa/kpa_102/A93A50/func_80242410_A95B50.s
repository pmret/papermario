.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242410_A95B50
/* A95B50 80242410 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A95B54 80242414 AFB00010 */  sw        $s0, 0x10($sp)
/* A95B58 80242418 0080802D */  daddu     $s0, $a0, $zero
/* A95B5C 8024241C AFBF0014 */  sw        $ra, 0x14($sp)
/* A95B60 80242420 8E020148 */  lw        $v0, 0x148($s0)
/* A95B64 80242424 0C00EABB */  jal       get_npc_unsafe
/* A95B68 80242428 84440008 */   lh       $a0, 8($v0)
/* A95B6C 8024242C 2403001E */  addiu     $v1, $zero, 0x1e
/* A95B70 80242430 A443008E */  sh        $v1, 0x8e($v0)
/* A95B74 80242434 2402000B */  addiu     $v0, $zero, 0xb
/* A95B78 80242438 AE020070 */  sw        $v0, 0x70($s0)
/* A95B7C 8024243C 8FBF0014 */  lw        $ra, 0x14($sp)
/* A95B80 80242440 8FB00010 */  lw        $s0, 0x10($sp)
/* A95B84 80242444 03E00008 */  jr        $ra
/* A95B88 80242448 27BD0018 */   addiu    $sp, $sp, 0x18
