.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416F8_CF9268
/* CF9268 802416F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF926C 802416FC 3C058025 */  lui       $a1, 0x8025
/* CF9270 80241700 8CA5DF10 */  lw        $a1, -0x20f0($a1)
/* CF9274 80241704 AFBF0010 */  sw        $ra, 0x10($sp)
/* CF9278 80241708 0C0B1EAF */  jal       get_variable
/* CF927C 8024170C 0000202D */   daddu    $a0, $zero, $zero
/* CF9280 80241710 0040182D */  daddu     $v1, $v0, $zero
/* CF9284 80241714 24020001 */  addiu     $v0, $zero, 1
/* CF9288 80241718 14620006 */  bne       $v1, $v0, .L80241734
/* CF928C 8024171C 24020002 */   addiu    $v0, $zero, 2
/* CF9290 80241720 44800000 */  mtc1      $zero, $f0
/* CF9294 80241724 00000000 */  nop       
/* CF9298 80241728 44050000 */  mfc1      $a1, $f0
/* CF929C 8024172C 080905D3 */  j         .L8024174C
/* CF92A0 80241730 0000202D */   daddu    $a0, $zero, $zero
.L80241734:
/* CF92A4 80241734 14620008 */  bne       $v1, $v0, .L80241758
/* CF92A8 80241738 24040001 */   addiu    $a0, $zero, 1
/* CF92AC 8024173C 44800000 */  mtc1      $zero, $f0
/* CF92B0 80241740 00000000 */  nop       
/* CF92B4 80241744 44050000 */  mfc1      $a1, $f0
/* CF92B8 80241748 00000000 */  nop       
.L8024174C:
/* CF92BC 8024174C 00A0302D */  daddu     $a2, $a1, $zero
/* CF92C0 80241750 0C01C5A4 */  jal       func_80071690
/* CF92C4 80241754 00A0382D */   daddu    $a3, $a1, $zero
.L80241758:
/* CF92C8 80241758 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF92CC 8024175C 03E00008 */  jr        $ra
/* CF92D0 80241760 27BD0018 */   addiu    $sp, $sp, 0x18
