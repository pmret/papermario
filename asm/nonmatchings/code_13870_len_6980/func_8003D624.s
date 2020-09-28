.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003D624
/* 18A24 8003D624 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18A28 8003D628 8FA20028 */  lw        $v0, 0x28($sp)
/* 18A2C 8003D62C 8FA3002C */  lw        $v1, 0x2c($sp)
/* 18A30 8003D630 8FA80030 */  lw        $t0, 0x30($sp)
/* 18A34 8003D634 AFBF0010 */  sw        $ra, 0x10($sp)
/* 18A38 8003D638 A4850098 */  sh        $a1, 0x98($a0)
/* 18A3C 8003D63C A486009A */  sh        $a2, 0x9a($a0)
/* 18A40 8003D640 A487009C */  sh        $a3, 0x9c($a0)
/* 18A44 8003D644 A482009E */  sh        $v0, 0x9e($a0)
/* 18A48 8003D648 A48300A0 */  sh        $v1, 0xa0($a0)
/* 18A4C 8003D64C 0C00F4EF */  jal       func_8003D3BC
/* 18A50 8003D650 A48800A2 */   sh       $t0, 0xa2($a0)
/* 18A54 8003D654 8FBF0010 */  lw        $ra, 0x10($sp)
/* 18A58 8003D658 03E00008 */  jr        $ra
/* 18A5C 8003D65C 27BD0018 */   addiu    $sp, $sp, 0x18
