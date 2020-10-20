.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409A4
/* D060D4 802409A4 3C028011 */  lui       $v0, 0x8011
/* D060D8 802409A8 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* D060DC 802409AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D060E0 802409B0 10400003 */  beqz      $v0, .L802409C0
/* D060E4 802409B4 AFBF0010 */   sw       $ra, 0x10($sp)
/* D060E8 802409B8 0C03AE06 */  jal       partner_suspend_ability_script
/* D060EC 802409BC 00000000 */   nop      
.L802409C0:
/* D060F0 802409C0 24020002 */  addiu     $v0, $zero, 2
/* D060F4 802409C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* D060F8 802409C8 03E00008 */  jr        $ra
/* D060FC 802409CC 27BD0018 */   addiu    $sp, $sp, 0x18
