.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240010_907A40
/* 907A40 80240010 3C014000 */  lui       $at, 0x4000
/* 907A44 80240014 44816000 */  mtc1      $at, $f12
/* 907A48 80240018 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 907A4C 8024001C AFBF0010 */  sw        $ra, 0x10($sp)
/* 907A50 80240020 0C00AFB7 */  jal       set_curtain_scale_goal
/* 907A54 80240024 00000000 */   nop      
/* 907A58 80240028 0C00AFC1 */  jal       set_curtain_draw_callback
/* 907A5C 8024002C 0000202D */   daddu    $a0, $zero, $zero
/* 907A60 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* 907A64 80240034 24020002 */  addiu     $v0, $zero, 2
/* 907A68 80240038 03E00008 */  jr        $ra
/* 907A6C 8024003C 27BD0018 */   addiu    $sp, $sp, 0x18
