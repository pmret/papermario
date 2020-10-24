.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241624_B361F4
/* B361F4 80241624 3C028011 */  lui       $v0, 0x8011
/* B361F8 80241628 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* B361FC 8024162C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B36200 80241630 10400003 */  beqz      $v0, .L80241640
/* B36204 80241634 AFBF0010 */   sw       $ra, 0x10($sp)
/* B36208 80241638 0C03AE06 */  jal       partner_suspend_ability_script
/* B3620C 8024163C 00000000 */   nop      
.L80241640:
/* B36210 80241640 24020002 */  addiu     $v0, $zero, 2
/* B36214 80241644 8FBF0010 */  lw        $ra, 0x10($sp)
/* B36218 80241648 03E00008 */  jr        $ra
/* B3621C 8024164C 27BD0018 */   addiu    $sp, $sp, 0x18
