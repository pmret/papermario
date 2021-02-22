.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D00_A96440
/* A96440 80242D00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A96444 80242D04 AFB00010 */  sw        $s0, 0x10($sp)
/* A96448 80242D08 0080802D */  daddu     $s0, $a0, $zero
/* A9644C 80242D0C AFBF0014 */  sw        $ra, 0x14($sp)
/* A96450 80242D10 8E020148 */  lw        $v0, 0x148($s0)
/* A96454 80242D14 0C00EABB */  jal       get_npc_unsafe
/* A96458 80242D18 84440008 */   lh       $a0, 8($v0)
/* A9645C 80242D1C 24030028 */  addiu     $v1, $zero, 0x28
/* A96460 80242D20 A443008E */  sh        $v1, 0x8e($v0)
/* A96464 80242D24 24020015 */  addiu     $v0, $zero, 0x15
/* A96468 80242D28 AE020070 */  sw        $v0, 0x70($s0)
/* A9646C 80242D2C 8FBF0014 */  lw        $ra, 0x14($sp)
/* A96470 80242D30 8FB00010 */  lw        $s0, 0x10($sp)
/* A96474 80242D34 03E00008 */  jr        $ra
/* A96478 80242D38 27BD0018 */   addiu    $sp, $sp, 0x18
