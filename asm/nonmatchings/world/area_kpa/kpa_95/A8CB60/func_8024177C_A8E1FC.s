.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024177C_A8E1FC
/* A8E1FC 8024177C 3C028011 */  lui       $v0, 0x8011
/* A8E200 80241780 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* A8E204 80241784 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A8E208 80241788 10400003 */  beqz      $v0, .L80241798
/* A8E20C 8024178C AFBF0010 */   sw       $ra, 0x10($sp)
/* A8E210 80241790 0C03AE06 */  jal       partner_suspend_ability_script
/* A8E214 80241794 00000000 */   nop      
.L80241798:
/* A8E218 80241798 24020002 */  addiu     $v0, $zero, 2
/* A8E21C 8024179C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A8E220 802417A0 03E00008 */  jr        $ra
/* A8E224 802417A4 27BD0018 */   addiu    $sp, $sp, 0x18
