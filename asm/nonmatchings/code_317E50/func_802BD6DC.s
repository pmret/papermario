.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD6DC
/* 31842C 802BD6DC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 318430 802BD6E0 3C058011 */  lui       $a1, 0x8011
/* 318434 802BD6E4 24A5C954 */  addiu     $a1, $a1, -0x36ac
/* 318438 802BD6E8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 31843C 802BD6EC 8CA20000 */  lw        $v0, ($a1)
/* 318440 802BD6F0 10400008 */  beqz      $v0, .L802BD714
/* 318444 802BD6F4 00000000 */   nop      
/* 318448 802BD6F8 3C03802C */  lui       $v1, 0x802c
/* 31844C 802BD6FC 8C63E89C */  lw        $v1, -0x1764($v1)
/* 318450 802BD700 8C620008 */  lw        $v0, 8($v1)
/* 318454 802BD704 ACA00000 */  sw        $zero, ($a1)
/* 318458 802BD708 AC820000 */  sw        $v0, ($a0)
/* 31845C 802BD70C 0C03BD17 */  jal       clear_partner_move_history
/* 318460 802BD710 AC600004 */   sw       $zero, 4($v1)
.L802BD714:
/* 318464 802BD714 8FBF0010 */  lw        $ra, 0x10($sp)
/* 318468 802BD718 03E00008 */  jr        $ra
/* 31846C 802BD71C 27BD0018 */   addiu    $sp, $sp, 0x18
