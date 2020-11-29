.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242468_95D668
/* 95D668 80242468 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95D66C 8024246C 3C058025 */  lui       $a1, %hi(D_8024DFD8)
/* 95D670 80242470 8CA5DFD8 */  lw        $a1, %lo(D_8024DFD8)($a1)
/* 95D674 80242474 AFBF0010 */  sw        $ra, 0x10($sp)
/* 95D678 80242478 0C0B1EAF */  jal       get_variable
/* 95D67C 8024247C 0000202D */   daddu    $a0, $zero, $zero
/* 95D680 80242480 0040182D */  daddu     $v1, $v0, $zero
/* 95D684 80242484 24020001 */  addiu     $v0, $zero, 1
/* 95D688 80242488 14620006 */  bne       $v1, $v0, .L802424A4
/* 95D68C 8024248C 24020002 */   addiu    $v0, $zero, 2
/* 95D690 80242490 44800000 */  mtc1      $zero, $f0
/* 95D694 80242494 00000000 */  nop       
/* 95D698 80242498 44050000 */  mfc1      $a1, $f0
/* 95D69C 8024249C 0809092F */  j         .L802424BC
/* 95D6A0 802424A0 0000202D */   daddu    $a0, $zero, $zero
.L802424A4:
/* 95D6A4 802424A4 14620008 */  bne       $v1, $v0, .L802424C8
/* 95D6A8 802424A8 24040001 */   addiu    $a0, $zero, 1
/* 95D6AC 802424AC 44800000 */  mtc1      $zero, $f0
/* 95D6B0 802424B0 00000000 */  nop       
/* 95D6B4 802424B4 44050000 */  mfc1      $a1, $f0
/* 95D6B8 802424B8 00000000 */  nop       
.L802424BC:
/* 95D6BC 802424BC 00A0302D */  daddu     $a2, $a1, $zero
/* 95D6C0 802424C0 0C01C5A4 */  jal       func_80071690
/* 95D6C4 802424C4 00A0382D */   daddu    $a3, $a1, $zero
.L802424C8:
/* 95D6C8 802424C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95D6CC 802424CC 03E00008 */  jr        $ra
/* 95D6D0 802424D0 27BD0018 */   addiu    $sp, $sp, 0x18
