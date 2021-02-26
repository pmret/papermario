.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003D2E4
/* 186E4 8003D2E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 186E8 8003D2E8 8FA20028 */  lw        $v0, 0x28($sp)
/* 186EC 8003D2EC 8FA3002C */  lw        $v1, 0x2c($sp)
/* 186F0 8003D2F0 8FA80030 */  lw        $t0, 0x30($sp)
/* 186F4 8003D2F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 186F8 8003D2F8 A4850098 */  sh        $a1, 0x98($a0)
/* 186FC 8003D2FC A486009A */  sh        $a2, 0x9a($a0)
/* 18700 8003D300 A487009C */  sh        $a3, 0x9c($a0)
/* 18704 8003D304 A482009E */  sh        $v0, 0x9e($a0)
/* 18708 8003D308 A48300A0 */  sh        $v1, 0xa0($a0)
/* 1870C 8003D30C 0C00F41F */  jal       func_8003D07C
/* 18710 8003D310 A48800A2 */   sh       $t0, 0xa2($a0)
/* 18714 8003D314 8FBF0010 */  lw        $ra, 0x10($sp)
/* 18718 8003D318 03E00008 */  jr        $ra
/* 1871C 8003D31C 27BD0018 */   addiu    $sp, $sp, 0x18
