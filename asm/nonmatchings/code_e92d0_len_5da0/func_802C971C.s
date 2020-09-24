.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802C971C
/* EE0CC 802C971C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EE0D0 802C9720 AFBF0010 */  sw        $ra, 0x10($sp)
/* EE0D4 802C9724 8C82000C */  lw        $v0, 0xc($a0)
/* EE0D8 802C9728 0C0B1EAF */  jal       get_variable
/* EE0DC 802C972C 8C450000 */   lw       $a1, ($v0)
/* EE0E0 802C9730 0C046CDF */  jal       func_8011B37C
/* EE0E4 802C9734 3044FFFF */   andi     $a0, $v0, 0xffff
/* EE0E8 802C9738 8FBF0010 */  lw        $ra, 0x10($sp)
/* EE0EC 802C973C 24020002 */  addiu     $v0, $zero, 2
/* EE0F0 802C9740 03E00008 */  jr        $ra
/* EE0F4 802C9744 27BD0018 */   addiu    $sp, $sp, 0x18
