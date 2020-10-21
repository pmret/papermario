.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024260C_B2EA7C
/* B2EA7C 8024260C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2EA80 80242610 3C058025 */  lui       $a1, 0x8025
/* B2EA84 80242614 8CA58938 */  lw        $a1, -0x76c8($a1)
/* B2EA88 80242618 AFBF0010 */  sw        $ra, 0x10($sp)
/* B2EA8C 8024261C 0C0B1EAF */  jal       get_variable
/* B2EA90 80242620 0000202D */   daddu    $a0, $zero, $zero
/* B2EA94 80242624 0040182D */  daddu     $v1, $v0, $zero
/* B2EA98 80242628 24020001 */  addiu     $v0, $zero, 1
/* B2EA9C 8024262C 14620006 */  bne       $v1, $v0, .L80242648
/* B2EAA0 80242630 24020002 */   addiu    $v0, $zero, 2
/* B2EAA4 80242634 44800000 */  mtc1      $zero, $f0
/* B2EAA8 80242638 00000000 */  nop       
/* B2EAAC 8024263C 44050000 */  mfc1      $a1, $f0
/* B2EAB0 80242640 08090998 */  j         .L80242660
/* B2EAB4 80242644 0000202D */   daddu    $a0, $zero, $zero
.L80242648:
/* B2EAB8 80242648 14620008 */  bne       $v1, $v0, .L8024266C
/* B2EABC 8024264C 24040001 */   addiu    $a0, $zero, 1
/* B2EAC0 80242650 44800000 */  mtc1      $zero, $f0
/* B2EAC4 80242654 00000000 */  nop       
/* B2EAC8 80242658 44050000 */  mfc1      $a1, $f0
/* B2EACC 8024265C 00000000 */  nop       
.L80242660:
/* B2EAD0 80242660 00A0302D */  daddu     $a2, $a1, $zero
/* B2EAD4 80242664 0C01C5A4 */  jal       func_80071690
/* B2EAD8 80242668 00A0382D */   daddu    $a3, $a1, $zero
.L8024266C:
/* B2EADC 8024266C 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2EAE0 80242670 03E00008 */  jr        $ra
/* B2EAE4 80242674 27BD0018 */   addiu    $sp, $sp, 0x18
