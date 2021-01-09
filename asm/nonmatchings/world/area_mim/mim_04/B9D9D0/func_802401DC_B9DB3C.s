.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401DC_B9DB3C
/* B9DB3C 802401DC 3C038024 */  lui       $v1, %hi(func_80241530_8ED350)
/* B9DB40 802401E0 24631530 */  addiu     $v1, $v1, %lo(func_80241530_8ED350)
/* B9DB44 802401E4 8C620000 */  lw        $v0, ($v1)
/* B9DB48 802401E8 14400002 */  bnez      $v0, .L802401F4
/* B9DB4C 802401EC 24020001 */   addiu    $v0, $zero, 1
/* B9DB50 802401F0 AC620000 */  sw        $v0, ($v1)
.L802401F4:
/* B9DB54 802401F4 03E00008 */  jr        $ra
/* B9DB58 802401F8 24020002 */   addiu    $v0, $zero, 2
/* B9DB5C 802401FC 00000000 */  nop       
