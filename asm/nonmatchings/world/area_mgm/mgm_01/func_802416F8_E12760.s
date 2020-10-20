.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416F8_E13E58
/* E13E58 802416F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E13E5C 802416FC 0000202D */  daddu     $a0, $zero, $zero
/* E13E60 80241700 AFBF0014 */  sw        $ra, 0x14($sp)
/* E13E64 80241704 0C00FB3A */  jal       get_enemy
/* E13E68 80241708 AFB00010 */   sw       $s0, 0x10($sp)
/* E13E6C 8024170C 8C50007C */  lw        $s0, 0x7c($v0)
/* E13E70 80241710 8C420074 */  lw        $v0, 0x74($v0)
/* E13E74 80241714 0000282D */  daddu     $a1, $zero, $zero
/* E13E78 80241718 02028023 */  subu      $s0, $s0, $v0
/* E13E7C 8024171C 26100001 */  addiu     $s0, $s0, 1
/* E13E80 80241720 0C0496FA */  jal       set_message_value
/* E13E84 80241724 0200202D */   daddu    $a0, $s0, $zero
/* E13E88 80241728 3C048015 */  lui       $a0, 0x8015
/* E13E8C 8024172C 2484C290 */  addiu     $a0, $a0, -0x3d70
/* E13E90 80241730 24020001 */  addiu     $v0, $zero, 1
/* E13E94 80241734 16020003 */  bne       $s0, $v0, .L80241744
/* E13E98 80241738 00000000 */   nop      
/* E13E9C 8024173C 3C048015 */  lui       $a0, 0x8015
/* E13EA0 80241740 2484C294 */  addiu     $a0, $a0, -0x3d6c
.L80241744:
/* E13EA4 80241744 0C0496CF */  jal       set_message_string
/* E13EA8 80241748 24050001 */   addiu    $a1, $zero, 1
/* E13EAC 8024174C 8FBF0014 */  lw        $ra, 0x14($sp)
/* E13EB0 80241750 8FB00010 */  lw        $s0, 0x10($sp)
/* E13EB4 80241754 24020002 */  addiu     $v0, $zero, 2
/* E13EB8 80241758 03E00008 */  jr        $ra
/* E13EBC 8024175C 27BD0018 */   addiu    $sp, $sp, 0x18
