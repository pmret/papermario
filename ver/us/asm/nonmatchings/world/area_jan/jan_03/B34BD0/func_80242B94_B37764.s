.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242B94_B37764
/* B37764 80242B94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B37768 80242B98 3C058025 */  lui       $a1, %hi(D_8024FEF0)
/* B3776C 80242B9C 8CA5FEF0 */  lw        $a1, %lo(D_8024FEF0)($a1)
/* B37770 80242BA0 AFBF0010 */  sw        $ra, 0x10($sp)
/* B37774 80242BA4 0C0B1EAF */  jal       evt_get_variable
/* B37778 80242BA8 0000202D */   daddu    $a0, $zero, $zero
/* B3777C 80242BAC 0040182D */  daddu     $v1, $v0, $zero
/* B37780 80242BB0 24020001 */  addiu     $v0, $zero, 1
/* B37784 80242BB4 14620006 */  bne       $v1, $v0, .L80242BD0
/* B37788 80242BB8 24020002 */   addiu    $v0, $zero, 2
/* B3778C 80242BBC 44800000 */  mtc1      $zero, $f0
/* B37790 80242BC0 00000000 */  nop
/* B37794 80242BC4 44050000 */  mfc1      $a1, $f0
/* B37798 80242BC8 08090AFA */  j         .L80242BE8
/* B3779C 80242BCC 0000202D */   daddu    $a0, $zero, $zero
.L80242BD0:
/* B377A0 80242BD0 14620008 */  bne       $v1, $v0, .L80242BF4
/* B377A4 80242BD4 24040001 */   addiu    $a0, $zero, 1
/* B377A8 80242BD8 44800000 */  mtc1      $zero, $f0
/* B377AC 80242BDC 00000000 */  nop
/* B377B0 80242BE0 44050000 */  mfc1      $a1, $f0
/* B377B4 80242BE4 00000000 */  nop
.L80242BE8:
/* B377B8 80242BE8 00A0302D */  daddu     $a2, $a1, $zero
/* B377BC 80242BEC 0C01C5A4 */  jal       playFX_50
/* B377C0 80242BF0 00A0382D */   daddu    $a3, $a1, $zero
.L80242BF4:
/* B377C4 80242BF4 8FBF0010 */  lw        $ra, 0x10($sp)
/* B377C8 80242BF8 03E00008 */  jr        $ra
/* B377CC 80242BFC 27BD0018 */   addiu    $sp, $sp, 0x18
