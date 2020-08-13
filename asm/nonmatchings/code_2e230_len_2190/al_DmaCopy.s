.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel al_DmaCopy
/* 030200 80054E00 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 030204 80054E04 AFB3001C */  sw    $s3, 0x1c($sp)
/* 030208 80054E08 0080982D */  daddu $s3, $a0, $zero
/* 03020C 80054E0C AFB40020 */  sw    $s4, 0x20($sp)
/* 030210 80054E10 00A0A02D */  daddu $s4, $a1, $zero
/* 030214 80054E14 AFB20018 */  sw    $s2, 0x18($sp)
/* 030218 80054E18 00C0902D */  daddu $s2, $a2, $zero
/* 03021C 80054E1C AFB00010 */  sw    $s0, 0x10($sp)
/* 030220 80054E20 00128342 */  srl   $s0, $s2, 0xd
/* 030224 80054E24 AFB10014 */  sw    $s1, 0x14($sp)
/* 030228 80054E28 0000882D */  daddu $s1, $zero, $zero
/* 03022C 80054E2C 1200000A */  beqz  $s0, .L80054E58
/* 030230 80054E30 AFBF0024 */   sw    $ra, 0x24($sp)
/* 030234 80054E34 2610FFFF */  addiu $s0, $s0, -1
.L80054E38:
/* 030238 80054E38 02712021 */  addu  $a0, $s3, $s1
/* 03023C 80054E3C 02912821 */  addu  $a1, $s4, $s1
/* 030240 80054E40 0C017D24 */  jal   nuPiReadRom
/* 030244 80054E44 24062000 */   addiu $a2, $zero, 0x2000
/* 030248 80054E48 26312000 */  addiu $s1, $s1, 0x2000
/* 03024C 80054E4C 0200102D */  daddu $v0, $s0, $zero
/* 030250 80054E50 1440FFF9 */  bnez  $v0, .L80054E38
/* 030254 80054E54 2610FFFF */   addiu $s0, $s0, -1
.L80054E58:
/* 030258 80054E58 32521FFF */  andi  $s2, $s2, 0x1fff
/* 03025C 80054E5C 12400004 */  beqz  $s2, .L80054E70
/* 030260 80054E60 02712021 */   addu  $a0, $s3, $s1
/* 030264 80054E64 02912821 */  addu  $a1, $s4, $s1
/* 030268 80054E68 0C017D24 */  jal   nuPiReadRom
/* 03026C 80054E6C 0240302D */   daddu $a2, $s2, $zero
.L80054E70:
/* 030270 80054E70 8FBF0024 */  lw    $ra, 0x24($sp)
/* 030274 80054E74 8FB40020 */  lw    $s4, 0x20($sp)
/* 030278 80054E78 8FB3001C */  lw    $s3, 0x1c($sp)
/* 03027C 80054E7C 8FB20018 */  lw    $s2, 0x18($sp)
/* 030280 80054E80 8FB10014 */  lw    $s1, 0x14($sp)
/* 030284 80054E84 8FB00010 */  lw    $s0, 0x10($sp)
/* 030288 80054E88 03E00008 */  jr    $ra
/* 03028C 80054E8C 27BD0028 */   addiu $sp, $sp, 0x28

