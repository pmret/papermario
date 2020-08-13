.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel osFlashWriteBuffer
/* 04A950 8006F550 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 04A954 8006F554 AFBF0014 */  sw    $ra, 0x14($sp)
/* 04A958 8006F558 AFA40020 */  sw    $a0, 0x20($sp)
/* 04A95C 8006F55C AFA50024 */  sw    $a1, 0x24($sp)
/* 04A960 8006F560 AFA60028 */  sw    $a2, 0x28($sp)
/* 04A964 8006F564 AFA7002C */  sw    $a3, 0x2c($sp)
/* 04A968 8006F568 3C04800B */  lui   $a0, 0x800b
/* 04A96C 8006F56C 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A970 8006F570 3C05800B */  lui   $a1, 0x800b
/* 04A974 8006F574 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04A978 8006F578 3C010001 */  lui   $at, 1
/* 04A97C 8006F57C 00A17025 */  or    $t6, $a1, $at
/* 04A980 8006F580 01C02825 */  or    $a1, $t6, $zero
/* 04A984 8006F584 3C06B400 */  lui   $a2, 0xb400
/* 04A988 8006F588 0C018358 */  jal   osEPiWriteIo
/* 04A98C 8006F58C 00000000 */   nop   
/* 04A990 8006F590 8FAF0024 */  lw    $t7, 0x24($sp)
/* 04A994 8006F594 8FB80020 */  lw    $t8, 0x20($sp)
/* 04A998 8006F598 00000000 */  nop   
/* 04A99C 8006F59C A30F0002 */  sb    $t7, 2($t8)
/* 04A9A0 8006F5A0 8FB9002C */  lw    $t9, 0x2c($sp)
/* 04A9A4 8006F5A4 8FA80020 */  lw    $t0, 0x20($sp)
/* 04A9A8 8006F5A8 00000000 */  nop   
/* 04A9AC 8006F5AC AD190004 */  sw    $t9, 4($t0)
/* 04A9B0 8006F5B0 8FA90028 */  lw    $t1, 0x28($sp)
/* 04A9B4 8006F5B4 8FAA0020 */  lw    $t2, 0x20($sp)
/* 04A9B8 8006F5B8 00000000 */  nop   
/* 04A9BC 8006F5BC AD490008 */  sw    $t1, 8($t2)
/* 04A9C0 8006F5C0 8FAB0020 */  lw    $t3, 0x20($sp)
/* 04A9C4 8006F5C4 00000000 */  nop   
/* 04A9C8 8006F5C8 AD60000C */  sw    $zero, 0xc($t3)
/* 04A9CC 8006F5CC 240C0080 */  addiu $t4, $zero, 0x80
/* 04A9D0 8006F5D0 8FAD0020 */  lw    $t5, 0x20($sp)
/* 04A9D4 8006F5D4 00000000 */  nop   
/* 04A9D8 8006F5D8 ADAC0010 */  sw    $t4, 0x10($t5)
/* 04A9DC 8006F5DC 3C04800B */  lui   $a0, 0x800b
/* 04A9E0 8006F5E0 24840C70 */  addiu $a0, $a0, 0xc70
/* 04A9E4 8006F5E4 8FA50020 */  lw    $a1, 0x20($sp)
/* 04A9E8 8006F5E8 24060001 */  addiu $a2, $zero, 1
/* 04A9EC 8006F5EC 0C018388 */  jal   osEPiStartDma
/* 04A9F0 8006F5F0 00000000 */   nop   
/* 04A9F4 8006F5F4 AFA2001C */  sw    $v0, 0x1c($sp)
/* 04A9F8 8006F5F8 8FA2001C */  lw    $v0, 0x1c($sp)
/* 04A9FC 8006F5FC 10000003 */  b     .L8006F60C
/* 04AA00 8006F600 00000000 */   nop   
/* 04AA04 8006F604 10000001 */  b     .L8006F60C
/* 04AA08 8006F608 00000000 */   nop   
.L8006F60C:
/* 04AA0C 8006F60C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 04AA10 8006F610 27BD0020 */  addiu $sp, $sp, 0x20
/* 04AA14 8006F614 03E00008 */  jr    $ra
/* 04AA18 8006F618 00000000 */   nop   

