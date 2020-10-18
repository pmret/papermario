.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD5F4
/* 31B614 802BD5F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31B618 802BD5F8 3C058011 */  lui       $a1, 0x8011
/* 31B61C 802BD5FC 24A5C954 */  addiu     $a1, $a1, -0x36ac
/* 31B620 802BD600 AFBF0010 */  sw        $ra, 0x10($sp)
/* 31B624 802BD604 8CA20000 */  lw        $v0, ($a1)
/* 31B628 802BD608 10400008 */  beqz      $v0, .L802BD62C
/* 31B62C 802BD60C 00000000 */   nop      
/* 31B630 802BD610 3C03802C */  lui       $v1, 0x802c
/* 31B634 802BD614 8C63EB60 */  lw        $v1, -0x14a0($v1)
/* 31B638 802BD618 8C620008 */  lw        $v0, 8($v1)
/* 31B63C 802BD61C ACA00000 */  sw        $zero, ($a1)
/* 31B640 802BD620 AC820000 */  sw        $v0, ($a0)
/* 31B644 802BD624 0C03BD17 */  jal       clear_partner_move_history
/* 31B648 802BD628 AC600004 */   sw       $zero, 4($v1)
.L802BD62C:
/* 31B64C 802BD62C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31B650 802BD630 03E00008 */  jr        $ra
/* 31B654 802BD634 27BD0018 */   addiu    $sp, $sp, 0x18
