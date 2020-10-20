.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241188_D62688
/* D62688 80241188 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D6268C 8024118C AFB00010 */  sw        $s0, 0x10($sp)
/* D62690 80241190 0080802D */  daddu     $s0, $a0, $zero
/* D62694 80241194 AFBF0014 */  sw        $ra, 0x14($sp)
/* D62698 80241198 8E02000C */  lw        $v0, 0xc($s0)
/* D6269C 8024119C 0C0B1EAF */  jal       get_variable
/* D626A0 802411A0 8C450000 */   lw       $a1, ($v0)
/* D626A4 802411A4 00021140 */  sll       $v0, $v0, 5
/* D626A8 802411A8 AE000084 */  sw        $zero, 0x84($s0)
/* D626AC 802411AC 3C018008 */  lui       $at, 0x8008
/* D626B0 802411B0 00220821 */  addu      $at, $at, $v0
/* D626B4 802411B4 942278F8 */  lhu       $v0, 0x78f8($at)
/* D626B8 802411B8 30420040 */  andi      $v0, $v0, 0x40
/* D626BC 802411BC 10400002 */  beqz      $v0, .L802411C8
/* D626C0 802411C0 24020001 */   addiu    $v0, $zero, 1
/* D626C4 802411C4 AE020084 */  sw        $v0, 0x84($s0)
.L802411C8:
/* D626C8 802411C8 8FBF0014 */  lw        $ra, 0x14($sp)
/* D626CC 802411CC 8FB00010 */  lw        $s0, 0x10($sp)
/* D626D0 802411D0 24020002 */  addiu     $v0, $zero, 2
/* D626D4 802411D4 03E00008 */  jr        $ra
/* D626D8 802411D8 27BD0018 */   addiu    $sp, $sp, 0x18
/* D626DC 802411DC 00000000 */  nop       
