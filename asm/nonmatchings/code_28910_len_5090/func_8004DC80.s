.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8004DC80
/* 029080 8004DC80 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 029084 8004DC84 AFA40010 */  sw    $a0, 0x10($sp)
/* 029088 8004DC88 27A40010 */  addiu $a0, $sp, 0x10
/* 02908C 8004DC8C 0000282D */  daddu $a1, $zero, $zero
/* 029090 8004DC90 AFBF0030 */  sw    $ra, 0x30($sp)
/* 029094 8004DC94 AFA00014 */  sw    $zero, 0x14($sp)
/* 029098 8004DC98 AFA00018 */  sw    $zero, 0x18($sp)
/* 02909C 8004DC9C AFA0001C */  sw    $zero, 0x1c($sp)
/* 0290A0 8004DCA0 AFA00020 */  sw    $zero, 0x20($sp)
/* 0290A4 8004DCA4 0C01372E */  jal   func_8004DCB8
/* 0290A8 8004DCA8 AFA00024 */   sw    $zero, 0x24($sp)
/* 0290AC 8004DCAC 8FBF0030 */  lw    $ra, 0x30($sp)
/* 0290B0 8004DCB0 03E00008 */  jr    $ra
/* 0290B4 8004DCB4 27BD0038 */   addiu $sp, $sp, 0x38

