.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427B8_825A78
/* 825A78 802427B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 825A7C 802427BC 3C058025 */  lui       $a1, %hi(D_8024E558)
/* 825A80 802427C0 8CA5E558 */  lw        $a1, %lo(D_8024E558)($a1)
/* 825A84 802427C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 825A88 802427C8 0C0B1EAF */  jal       get_variable
/* 825A8C 802427CC 0000202D */   daddu    $a0, $zero, $zero
/* 825A90 802427D0 0040182D */  daddu     $v1, $v0, $zero
/* 825A94 802427D4 24020001 */  addiu     $v0, $zero, 1
/* 825A98 802427D8 14620006 */  bne       $v1, $v0, .L802427F4
/* 825A9C 802427DC 24020002 */   addiu    $v0, $zero, 2
/* 825AA0 802427E0 44800000 */  mtc1      $zero, $f0
/* 825AA4 802427E4 00000000 */  nop
/* 825AA8 802427E8 44050000 */  mfc1      $a1, $f0
/* 825AAC 802427EC 08090A03 */  j         .L8024280C
/* 825AB0 802427F0 0000202D */   daddu    $a0, $zero, $zero
.L802427F4:
/* 825AB4 802427F4 14620008 */  bne       $v1, $v0, .L80242818
/* 825AB8 802427F8 24040001 */   addiu    $a0, $zero, 1
/* 825ABC 802427FC 44800000 */  mtc1      $zero, $f0
/* 825AC0 80242800 00000000 */  nop
/* 825AC4 80242804 44050000 */  mfc1      $a1, $f0
/* 825AC8 80242808 00000000 */  nop
.L8024280C:
/* 825ACC 8024280C 00A0302D */  daddu     $a2, $a1, $zero
/* 825AD0 80242810 0C01C5A4 */  jal       playFX_50
/* 825AD4 80242814 00A0382D */   daddu    $a3, $a1, $zero
.L80242818:
/* 825AD8 80242818 8FBF0010 */  lw        $ra, 0x10($sp)
/* 825ADC 8024281C 03E00008 */  jr        $ra
/* 825AE0 80242820 27BD0018 */   addiu    $sp, $sp, 0x18
