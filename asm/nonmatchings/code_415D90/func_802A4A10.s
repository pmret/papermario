.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802A4A10
/* 4197A0 802A4A10 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 4197A4 802A4A14 24040006 */  addiu $a0, $zero, 6
/* 4197A8 802A4A18 AFBF0010 */  sw    $ra, 0x10($sp)
/* 4197AC 802A4A1C 0C051F9F */  jal   func_80147E7C
/* 4197B0 802A4A20 24050005 */   addiu $a1, $zero, 5
/* 4197B4 802A4A24 24040007 */  addiu $a0, $zero, 7
/* 4197B8 802A4A28 0C051F9F */  jal   func_80147E7C
/* 4197BC 802A4A2C 24050005 */   addiu $a1, $zero, 5
/* 4197C0 802A4A30 24040008 */  addiu $a0, $zero, 8
/* 4197C4 802A4A34 0C051F9F */  jal   func_80147E7C
/* 4197C8 802A4A38 24050001 */   addiu $a1, $zero, 1
/* 4197CC 802A4A3C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 4197D0 802A4A40 2402001E */  addiu $v0, $zero, 0x1e
/* 4197D4 802A4A44 3C01802B */  lui   $at, 0x802b
/* 4197D8 802A4A48 A022D604 */  sb    $v0, -0x29fc($at)
/* 4197DC 802A4A4C 03E00008 */  jr    $ra
/* 4197E0 802A4A50 27BD0018 */   addiu $sp, $sp, 0x18

