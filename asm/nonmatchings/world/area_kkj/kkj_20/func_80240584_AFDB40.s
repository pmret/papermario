.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240584_AFE0C4
/* AFE0C4 80240584 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AFE0C8 80240588 AFBF0010 */  sw        $ra, 0x10($sp)
/* AFE0CC 8024058C 8C82000C */  lw        $v0, 0xc($a0)
/* AFE0D0 80240590 0C0B1EAF */  jal       get_variable
/* AFE0D4 80240594 8C450000 */   lw       $a1, ($v0)
/* AFE0D8 80240598 00021600 */  sll       $v0, $v0, 0x18
/* AFE0DC 8024059C 0C03AC5A */  jal       func_800EB168
/* AFE0E0 802405A0 00022603 */   sra      $a0, $v0, 0x18
/* AFE0E4 802405A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* AFE0E8 802405A8 24020002 */  addiu     $v0, $zero, 2
/* AFE0EC 802405AC 03E00008 */  jr        $ra
/* AFE0F0 802405B0 27BD0018 */   addiu    $sp, $sp, 0x18
