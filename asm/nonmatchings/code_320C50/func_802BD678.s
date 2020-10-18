.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD678
/* 3211C8 802BD678 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3211CC 802BD67C 3C058011 */  lui       $a1, 0x8011
/* 3211D0 802BD680 24A5C954 */  addiu     $a1, $a1, -0x36ac
/* 3211D4 802BD684 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3211D8 802BD688 8CA20000 */  lw        $v0, ($a1)
/* 3211DC 802BD68C 10400008 */  beqz      $v0, .L802BD6B0
/* 3211E0 802BD690 00000000 */   nop      
/* 3211E4 802BD694 3C03802C */  lui       $v1, 0x802c
/* 3211E8 802BD698 8C63FE7C */  lw        $v1, -0x184($v1)
/* 3211EC 802BD69C 8C620008 */  lw        $v0, 8($v1)
/* 3211F0 802BD6A0 ACA00000 */  sw        $zero, ($a1)
/* 3211F4 802BD6A4 AC820000 */  sw        $v0, ($a0)
/* 3211F8 802BD6A8 0C03BD17 */  jal       clear_partner_move_history
/* 3211FC 802BD6AC AC600004 */   sw       $zero, 4($v1)
.L802BD6B0:
/* 321200 802BD6B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 321204 802BD6B4 03E00008 */  jr        $ra
/* 321208 802BD6B8 27BD0018 */   addiu    $sp, $sp, 0x18
