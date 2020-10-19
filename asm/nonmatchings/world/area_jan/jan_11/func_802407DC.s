.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407DC
/* B7103C 802407DC 3C038011 */  lui       $v1, 0x8011
/* B71040 802407E0 8063EBB3 */  lb        $v1, -0x144d($v1)
/* B71044 802407E4 24020006 */  addiu     $v0, $zero, 6
/* B71048 802407E8 54620003 */  bnel      $v1, $v0, .L802407F8
/* B7104C 802407EC AC8000A8 */   sw       $zero, 0xa8($a0)
/* B71050 802407F0 24020001 */  addiu     $v0, $zero, 1
/* B71054 802407F4 AC8200A8 */  sw        $v0, 0xa8($a0)
.L802407F8:
/* B71058 802407F8 03E00008 */  jr        $ra
/* B7105C 802407FC 24020002 */   addiu    $v0, $zero, 2
