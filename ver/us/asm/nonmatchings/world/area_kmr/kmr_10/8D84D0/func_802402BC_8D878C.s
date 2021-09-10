.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402BC_8D878C
/* 8D878C 802402BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8D8790 802402C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8D8794 802402C4 8C82000C */  lw        $v0, 0xc($a0)
/* 8D8798 802402C8 0C0B1EAF */  jal       evt_get_variable
/* 8D879C 802402CC 8C450000 */   lw       $a1, ($v0)
/* 8D87A0 802402D0 0C04417A */  jal       get_entity_by_index
/* 8D87A4 802402D4 0040202D */   daddu    $a0, $v0, $zero
/* 8D87A8 802402D8 50400007 */  beql      $v0, $zero, .L802402F8
/* 8D87AC 802402DC 0000102D */   daddu    $v0, $zero, $zero
/* 8D87B0 802402E0 84440014 */  lh        $a0, 0x14($v0)
/* 8D87B4 802402E4 3C050000 */  lui       $a1, 0
/* 8D87B8 802402E8 24A501E4 */  addiu     $a1, $a1, 0x1e4
/* 8D87BC 802402EC 0C048052 */  jal       play_model_animation
/* 8D87C0 802402F0 00000000 */   nop      
/* 8D87C4 802402F4 24020002 */  addiu     $v0, $zero, 2
.L802402F8:
/* 8D87C8 802402F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8D87CC 802402FC 03E00008 */  jr        $ra
/* 8D87D0 80240300 27BD0018 */   addiu    $sp, $sp, 0x18
