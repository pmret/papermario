.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417EC_A8823C
/* A8823C 802417EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A88240 802417F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* A88244 802417F4 8C82000C */  lw        $v0, 0xc($a0)
/* A88248 802417F8 0C0B1EAF */  jal       get_variable
/* A8824C 802417FC 8C450000 */   lw       $a1, ($v0)
/* A88250 80241800 00021600 */  sll       $v0, $v0, 0x18
/* A88254 80241804 0C03AC5A */  jal       func_800EB168
/* A88258 80241808 00022603 */   sra      $a0, $v0, 0x18
/* A8825C 8024180C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A88260 80241810 24020002 */  addiu     $v0, $zero, 2
/* A88264 80241814 03E00008 */  jr        $ra
/* A88268 80241818 27BD0018 */   addiu    $sp, $sp, 0x18
