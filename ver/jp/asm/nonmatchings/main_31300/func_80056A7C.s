.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056A7C
/* 31E7C 80056A7C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 31E80 80056A80 00A0302D */  daddu     $a2, $a1, $zero
/* 31E84 80056A84 308400FF */  andi      $a0, $a0, 0xff
/* 31E88 80056A88 00041040 */  sll       $v0, $a0, 1
/* 31E8C 80056A8C 00441021 */  addu      $v0, $v0, $a0
/* 31E90 80056A90 3C038008 */  lui       $v1, %hi(D_80078E24)
/* 31E94 80056A94 8C638E24 */  lw        $v1, %lo(D_80078E24)($v1)
/* 31E98 80056A98 000210C0 */  sll       $v0, $v0, 3
/* 31E9C 80056A9C AFBF0018 */  sw        $ra, 0x18($sp)
/* 31EA0 80056AA0 AFB10014 */  sw        $s1, 0x14($sp)
/* 31EA4 80056AA4 AFB00010 */  sw        $s0, 0x10($sp)
/* 31EA8 80056AA8 8C700020 */  lw        $s0, 0x20($v1)
/* 31EAC 80056AAC 30D100FF */  andi      $s1, $a2, 0xff
/* 31EB0 80056AB0 02028021 */  addu      $s0, $s0, $v0
/* 31EB4 80056AB4 8E040004 */  lw        $a0, 4($s0)
/* 31EB8 80056AB8 0220282D */  daddu     $a1, $s1, $zero
/* 31EBC 80056ABC 0C01633F */  jal       func_80058CFC
/* 31EC0 80056AC0 A206000C */   sb       $a2, 0xc($s0)
/* 31EC4 80056AC4 8E040008 */  lw        $a0, 8($s0)
/* 31EC8 80056AC8 0C01633F */  jal       func_80058CFC
/* 31ECC 80056ACC 0220282D */   daddu    $a1, $s1, $zero
/* 31ED0 80056AD0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 31ED4 80056AD4 8FB10014 */  lw        $s1, 0x14($sp)
/* 31ED8 80056AD8 8FB00010 */  lw        $s0, 0x10($sp)
/* 31EDC 80056ADC 03E00008 */  jr        $ra
/* 31EE0 80056AE0 27BD0020 */   addiu    $sp, $sp, 0x20
