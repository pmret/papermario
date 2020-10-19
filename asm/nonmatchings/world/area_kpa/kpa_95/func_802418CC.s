.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418CC
/* A8E34C 802418CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A8E350 802418D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* A8E354 802418D4 8C82000C */  lw        $v0, 0xc($a0)
/* A8E358 802418D8 0C0B1EAF */  jal       get_variable
/* A8E35C 802418DC 8C450000 */   lw       $a1, ($v0)
/* A8E360 802418E0 00021600 */  sll       $v0, $v0, 0x18
/* A8E364 802418E4 0C03AC5A */  jal       func_800EB168
/* A8E368 802418E8 00022603 */   sra      $a0, $v0, 0x18
/* A8E36C 802418EC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A8E370 802418F0 24020002 */  addiu     $v0, $zero, 2
/* A8E374 802418F4 03E00008 */  jr        $ra
/* A8E378 802418F8 27BD0018 */   addiu    $sp, $sp, 0x18
