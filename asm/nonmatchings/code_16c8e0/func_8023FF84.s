.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8023FF84
/* 16E864 8023FF84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 16E868 8023FF88 AFBF0010 */  sw        $ra, 0x10($sp)
/* 16E86C 8023FF8C 0C099F12 */  jal       show_foreground_models_unchecked
/* 16E870 8023FF90 00000000 */   nop      
/* 16E874 8023FF94 8FBF0010 */  lw        $ra, 0x10($sp)
/* 16E878 8023FF98 03E00008 */  jr        $ra
/* 16E87C 8023FF9C 27BD0018 */   addiu    $sp, $sp, 0x18
