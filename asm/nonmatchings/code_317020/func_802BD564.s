.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD564
/* 317484 802BD564 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 317488 802BD568 3C058011 */  lui       $a1, 0x8011
/* 31748C 802BD56C 24A5C954 */  addiu     $a1, $a1, -0x36ac
/* 317490 802BD570 AFBF0010 */  sw        $ra, 0x10($sp)
/* 317494 802BD574 8CA20000 */  lw        $v0, ($a1)
/* 317498 802BD578 10400008 */  beqz      $v0, .L802BD59C
/* 31749C 802BD57C 00000000 */   nop      
/* 3174A0 802BD580 3C03802C */  lui       $v1, 0x802c
/* 3174A4 802BD584 8C63DD88 */  lw        $v1, -0x2278($v1)
/* 3174A8 802BD588 8C620008 */  lw        $v0, 8($v1)
/* 3174AC 802BD58C ACA00000 */  sw        $zero, ($a1)
/* 3174B0 802BD590 AC820000 */  sw        $v0, ($a0)
/* 3174B4 802BD594 0C03BD17 */  jal       clear_partner_move_history
/* 3174B8 802BD598 AC600004 */   sw       $zero, 4($v1)
.L802BD59C:
/* 3174BC 802BD59C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3174C0 802BD5A0 03E00008 */  jr        $ra
/* 3174C4 802BD5A4 27BD0018 */   addiu    $sp, $sp, 0x18
