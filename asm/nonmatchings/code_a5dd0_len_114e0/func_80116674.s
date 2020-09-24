.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80116674
/* ACD74 80116674 0000202D */  daddu     $a0, $zero, $zero
/* ACD78 80116678 3C038015 */  lui       $v1, 0x8015
/* ACD7C 8011667C 8C6312CC */  lw        $v1, 0x12cc($v1)
.L80116680:
/* ACD80 80116680 24840001 */  addiu     $a0, $a0, 1
/* ACD84 80116684 28820100 */  slti      $v0, $a0, 0x100
/* ACD88 80116688 1440FFFD */  bnez      $v0, .L80116680
/* ACD8C 8011668C 24630004 */   addiu    $v1, $v1, 4
/* ACD90 80116690 03E00008 */  jr        $ra
/* ACD94 80116694 00000000 */   nop      
