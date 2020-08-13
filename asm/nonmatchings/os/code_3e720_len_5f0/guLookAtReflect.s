.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel guLookAtReflect
/* 03EC98 80063898 27BDFF88 */  addiu $sp, $sp, -0x78
/* 03EC9C 8006389C C7A00088 */  lwc1  $f0, 0x88($sp)
/* 03ECA0 800638A0 C7A2008C */  lwc1  $f2, 0x8c($sp)
/* 03ECA4 800638A4 C7A40090 */  lwc1  $f4, 0x90($sp)
/* 03ECA8 800638A8 C7A60094 */  lwc1  $f6, 0x94($sp)
/* 03ECAC 800638AC C7A80098 */  lwc1  $f8, 0x98($sp)
/* 03ECB0 800638B0 C7AA009C */  lwc1  $f10, 0x9c($sp)
/* 03ECB4 800638B4 C7AC00A0 */  lwc1  $f12, 0xa0($sp)
/* 03ECB8 800638B8 AFB00070 */  sw    $s0, 0x70($sp)
/* 03ECBC 800638BC 00808021 */  addu  $s0, $a0, $zero
/* 03ECC0 800638C0 27A40030 */  addiu $a0, $sp, 0x30
/* 03ECC4 800638C4 AFBF0074 */  sw    $ra, 0x74($sp)
/* 03ECC8 800638C8 E7A00010 */  swc1  $f0, 0x10($sp)
/* 03ECCC 800638CC E7A20014 */  swc1  $f2, 0x14($sp)
/* 03ECD0 800638D0 E7A40018 */  swc1  $f4, 0x18($sp)
/* 03ECD4 800638D4 E7A6001C */  swc1  $f6, 0x1c($sp)
/* 03ECD8 800638D8 E7A80020 */  swc1  $f8, 0x20($sp)
/* 03ECDC 800638DC E7AA0024 */  swc1  $f10, 0x24($sp)
/* 03ECE0 800638E0 0C018CC8 */  jal   guLookAtReflectF
/* 03ECE4 800638E4 E7AC0028 */   swc1  $f12, 0x28($sp)
/* 03ECE8 800638E8 27A40030 */  addiu $a0, $sp, 0x30
/* 03ECEC 800638EC 0C019D40 */  jal   guMtxF2L
/* 03ECF0 800638F0 02002821 */   addu  $a1, $s0, $zero
/* 03ECF4 800638F4 8FBF0074 */  lw    $ra, 0x74($sp)
/* 03ECF8 800638F8 8FB00070 */  lw    $s0, 0x70($sp)
/* 03ECFC 800638FC 03E00008 */  jr    $ra
/* 03ED00 80063900 27BD0078 */   addiu $sp, $sp, 0x78

/* 03ED04 80063904 00000000 */  nop   
/* 03ED08 80063908 00000000 */  nop   
/* 03ED0C 8006390C 00000000 */  nop   


