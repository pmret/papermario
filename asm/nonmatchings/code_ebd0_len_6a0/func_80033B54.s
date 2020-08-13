.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"
glabel func_80033B54
/* 00EF54 80033B54 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 00EF58 80033B58 AFBF0010 */  sw    $ra, 0x10($sp)
/* 00EF5C 80033B5C 0C00F96C */  jal   func_8003E5B0
/* 00EF60 80033B60 00000000 */   nop   
/* 00EF64 80033B64 3C02800A */  lui   $v0, 0x800a
/* 00EF68 80033B68 80420900 */  lb    $v0, 0x900($v0)
/* 00EF6C 80033B6C 04410003 */  bgez  $v0, .L80033B7C
/* 00EF70 80033B70 00000000 */   nop   
/* 00EF74 80033B74 0C08FA9F */  jal   draw_main_battle_ui
/* 00EF78 80033B78 00000000 */   nop   
.L80033B7C:
/* 00EF7C 80033B7C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 00EF80 80033B80 03E00008 */  jr    $ra
/* 00EF84 80033B84 27BD0018 */   addiu $sp, $sp, 0x18