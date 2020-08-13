.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802AA0B8
/* 41EE48 802AA0B8 3C03800E */  lui   $v1, 0x800e
/* 41EE4C 802AA0BC 8C63C4DC */  lw    $v1, -0x3b24($v1)
/* 41EE50 802AA0C0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 41EE54 802AA0C4 AFB20018 */  sw    $s2, 0x18($sp)
/* 41EE58 802AA0C8 3C12800E */  lui   $s2, 0x800e
/* 41EE5C 802AA0CC 2652C070 */  addiu $s2, $s2, -0x3f90
/* 41EE60 802AA0D0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 41EE64 802AA0D4 AFB10014 */  sw    $s1, 0x14($sp)
