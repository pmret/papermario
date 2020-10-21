.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241738_8ED558
/* 8ED558 80241738 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8ED55C 8024173C AFBF0010 */  sw        $ra, 0x10($sp)
/* 8ED560 80241740 0C04417A */  jal       get_entity_by_index
/* 8ED564 80241744 0000202D */   daddu    $a0, $zero, $zero
/* 8ED568 80241748 50400007 */  beql      $v0, $zero, .L80241768
/* 8ED56C 8024174C 0000102D */   daddu    $v0, $zero, $zero
/* 8ED570 80241750 84440014 */  lh        $a0, 0x14($v0)
/* 8ED574 80241754 3C050000 */  lui       $a1, 0
/* 8ED578 80241758 24A501E4 */  addiu     $a1, $a1, 0x1e4
/* 8ED57C 8024175C 0C048052 */  jal       play_model_animation
/* 8ED580 80241760 00000000 */   nop      
/* 8ED584 80241764 24020002 */  addiu     $v0, $zero, 2
.L80241768:
/* 8ED588 80241768 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8ED58C 8024176C 03E00008 */  jr        $ra
/* 8ED590 80241770 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8ED594 80241774 00000000 */  nop       
/* 8ED598 80241778 00000000 */  nop       
/* 8ED59C 8024177C 00000000 */  nop       
