.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BE0_9C5FC0
/* 9C5FC0 80240BE0 3C028011 */  lui       $v0, 0x8011
/* 9C5FC4 80240BE4 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* 9C5FC8 80240BE8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C5FCC 80240BEC 10400003 */  beqz      $v0, .L80240BFC
/* 9C5FD0 80240BF0 AFBF0010 */   sw       $ra, 0x10($sp)
/* 9C5FD4 80240BF4 0C03AE06 */  jal       partner_suspend_ability_script
/* 9C5FD8 80240BF8 00000000 */   nop      
.L80240BFC:
/* 9C5FDC 80240BFC 24020002 */  addiu     $v0, $zero, 2
/* 9C5FE0 80240C00 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C5FE4 80240C04 03E00008 */  jr        $ra
/* 9C5FE8 80240C08 27BD0018 */   addiu    $sp, $sp, 0x18
