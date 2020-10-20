.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802435F8
/* 96C7B8 802435F8 3C028011 */  lui       $v0, 0x8011
/* 96C7BC 802435FC 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* 96C7C0 80243600 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96C7C4 80243604 10400003 */  beqz      $v0, .L80243614
/* 96C7C8 80243608 AFBF0010 */   sw       $ra, 0x10($sp)
/* 96C7CC 8024360C 0C03AE06 */  jal       partner_suspend_ability_script
/* 96C7D0 80243610 00000000 */   nop      
.L80243614:
/* 96C7D4 80243614 24020002 */  addiu     $v0, $zero, 2
/* 96C7D8 80243618 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96C7DC 8024361C 03E00008 */  jr        $ra
/* 96C7E0 80243620 27BD0018 */   addiu    $sp, $sp, 0x18
