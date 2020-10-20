.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240434_C805D4
/* C805D4 80240434 3C038011 */  lui       $v1, 0x8011
/* C805D8 80240438 8063EBB3 */  lb        $v1, -0x144d($v1)
/* C805DC 8024043C 24020008 */  addiu     $v0, $zero, 8
/* C805E0 80240440 54620003 */  bnel      $v1, $v0, .L80240450
/* C805E4 80240444 AC8000A8 */   sw       $zero, 0xa8($a0)
/* C805E8 80240448 24020001 */  addiu     $v0, $zero, 1
/* C805EC 8024044C AC8200A8 */  sw        $v0, 0xa8($a0)
.L80240450:
/* C805F0 80240450 03E00008 */  jr        $ra
/* C805F4 80240454 24020002 */   addiu    $v0, $zero, 2
/* C805F8 80240458 00000000 */  nop       
/* C805FC 8024045C 00000000 */  nop       
