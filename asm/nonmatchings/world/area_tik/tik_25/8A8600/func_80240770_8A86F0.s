.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240770_8A86F0
/* 8A86F0 80240770 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8A86F4 80240774 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8A86F8 80240778 8C82000C */  lw        $v0, 0xc($a0)
/* 8A86FC 8024077C 0C0B1EAF */  jal       get_variable
/* 8A8700 80240780 8C450000 */   lw       $a1, ($v0)
/* 8A8704 80240784 0C04417A */  jal       get_entity_by_index
/* 8A8708 80240788 0040202D */   daddu    $a0, $v0, $zero
/* 8A870C 8024078C 50400007 */  beql      $v0, $zero, .L802407AC
/* 8A8710 80240790 0000102D */   daddu    $v0, $zero, $zero
/* 8A8714 80240794 84440014 */  lh        $a0, 0x14($v0)
/* 8A8718 80240798 3C050000 */  lui       $a1, 0
/* 8A871C 8024079C 24A501E4 */  addiu     $a1, $a1, 0x1e4
/* 8A8720 802407A0 0C048052 */  jal       play_model_animation
/* 8A8724 802407A4 00000000 */   nop      
/* 8A8728 802407A8 24020002 */  addiu     $v0, $zero, 2
.L802407AC:
/* 8A872C 802407AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8A8730 802407B0 03E00008 */  jr        $ra
/* 8A8734 802407B4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8A8738 802407B8 00000000 */  nop       
/* 8A873C 802407BC 00000000 */  nop       
