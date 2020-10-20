.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401E0
/* 8FF850 802401E0 3C014000 */  lui       $at, 0x4000
/* 8FF854 802401E4 44816000 */  mtc1      $at, $f12
/* 8FF858 802401E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8FF85C 802401EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 8FF860 802401F0 0C00AFB7 */  jal       set_curtain_scale_goal
/* 8FF864 802401F4 00000000 */   nop      
/* 8FF868 802401F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8FF86C 802401FC 24020002 */  addiu     $v0, $zero, 2
/* 8FF870 80240200 03E00008 */  jr        $ra
/* 8FF874 80240204 27BD0018 */   addiu    $sp, $sp, 0x18
