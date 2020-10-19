.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240444_A54D94
/* A54D94 80240444 3C038011 */  lui       $v1, 0x8011
/* A54D98 80240448 8063EBB3 */  lb        $v1, -0x144d($v1)
/* A54D9C 8024044C 24020008 */  addiu     $v0, $zero, 8
/* A54DA0 80240450 54620003 */  bnel      $v1, $v0, .L80240460
/* A54DA4 80240454 AC8000A8 */   sw       $zero, 0xa8($a0)
/* A54DA8 80240458 24020001 */  addiu     $v0, $zero, 1
/* A54DAC 8024045C AC8200A8 */  sw        $v0, 0xa8($a0)
.L80240460:
/* A54DB0 80240460 03E00008 */  jr        $ra
/* A54DB4 80240464 24020002 */   addiu    $v0, $zero, 2
/* A54DB8 80240468 00000000 */  nop       
/* A54DBC 8024046C 00000000 */  nop       
