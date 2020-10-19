.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241774_B36344
/* B36344 80241774 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B36348 80241778 AFBF0010 */  sw        $ra, 0x10($sp)
/* B3634C 8024177C 8C82000C */  lw        $v0, 0xc($a0)
/* B36350 80241780 0C0B1EAF */  jal       get_variable
/* B36354 80241784 8C450000 */   lw       $a1, ($v0)
/* B36358 80241788 00021600 */  sll       $v0, $v0, 0x18
/* B3635C 8024178C 0C03AC5A */  jal       func_800EB168
/* B36360 80241790 00022603 */   sra      $a0, $v0, 0x18
/* B36364 80241794 8FBF0010 */  lw        $ra, 0x10($sp)
/* B36368 80241798 24020002 */  addiu     $v0, $zero, 2
/* B3636C 8024179C 03E00008 */  jr        $ra
/* B36370 802417A0 27BD0018 */   addiu    $sp, $sp, 0x18
