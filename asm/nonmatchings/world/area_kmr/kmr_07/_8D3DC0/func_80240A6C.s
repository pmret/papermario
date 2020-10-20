.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A6C
/* 8D482C 80240A6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8D4830 80240A70 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8D4834 80240A74 0000202D */  daddu     $a0, $zero, $zero
/* 8D4838 80240A78 3C05FD05 */  lui       $a1, 0xfd05
/* 8D483C 80240A7C 0C0B1EAF */  jal       get_variable
/* 8D4840 80240A80 34A50F80 */   ori      $a1, $a1, 0xf80
/* 8D4844 80240A84 0C04417A */  jal       get_entity_by_index
/* 8D4848 80240A88 0040202D */   daddu    $a0, $v0, $zero
/* 8D484C 80240A8C 50400007 */  beql      $v0, $zero, .L80240AAC
/* 8D4850 80240A90 0000102D */   daddu    $v0, $zero, $zero
/* 8D4854 80240A94 84440014 */  lh        $a0, 0x14($v0)
/* 8D4858 80240A98 3C050000 */  lui       $a1, 0
/* 8D485C 80240A9C 24A501E4 */  addiu     $a1, $a1, 0x1e4
/* 8D4860 80240AA0 0C048052 */  jal       play_model_animation
/* 8D4864 80240AA4 00000000 */   nop      
/* 8D4868 80240AA8 24020002 */  addiu     $v0, $zero, 2
.L80240AAC:
/* 8D486C 80240AAC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8D4870 80240AB0 03E00008 */  jr        $ra
/* 8D4874 80240AB4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8D4878 80240AB8 00000000 */  nop       
/* 8D487C 80240ABC 00000000 */  nop       
