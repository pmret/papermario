.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024093C_8756FC
/* 8756FC 8024093C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 875700 80240940 AFBF0010 */  sw        $ra, 0x10($sp)
/* 875704 80240944 8C82000C */  lw        $v0, 0xc($a0)
/* 875708 80240948 0C0B1EAF */  jal       evt_get_variable
/* 87570C 8024094C 8C450000 */   lw       $a1, ($v0)
/* 875710 80240950 0C04417A */  jal       get_entity_by_index
/* 875714 80240954 0040202D */   daddu    $a0, $v0, $zero
/* 875718 80240958 50400007 */  beql      $v0, $zero, .L80240978
/* 87571C 8024095C 0000102D */   daddu    $v0, $zero, $zero
/* 875720 80240960 84440014 */  lh        $a0, 0x14($v0)
/* 875724 80240964 3C050000 */  lui       $a1, 0
/* 875728 80240968 24A501E4 */  addiu     $a1, $a1, 0x1e4
/* 87572C 8024096C 0C048052 */  jal       play_model_animation
/* 875730 80240970 00000000 */   nop
/* 875734 80240974 24020002 */  addiu     $v0, $zero, 2
.L80240978:
/* 875738 80240978 8FBF0010 */  lw        $ra, 0x10($sp)
/* 87573C 8024097C 03E00008 */  jr        $ra
/* 875740 80240980 27BD0018 */   addiu    $sp, $sp, 0x18
