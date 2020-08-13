.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetBattleCamTarget
/* 17D1EC 8024E90C 3C028028 */  lui   $v0, 0x8028
/* 17D1F0 8024E910 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17D1F4 8024E914 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 17D1F8 8024E918 AFB10014 */  sw    $s1, 0x14($sp)
/* 17D1FC 8024E91C 0080882D */  daddu $s1, $a0, $zero
/* 17D200 8024E920 AFBF0018 */  sw    $ra, 0x18($sp)
/* 17D204 8024E924 AFB00010 */  sw    $s0, 0x10($sp)
/* 17D208 8024E928 8E30000C */  lw    $s0, 0xc($s1)
/* 17D20C 8024E92C 5440001B */  bnezl $v0, .L8024E99C
/* 17D210 8024E930 24020002 */   addiu $v0, $zero, 2
/* 17D214 8024E934 8E050000 */  lw    $a1, ($s0)
/* 17D218 8024E938 0C0B1EAF */  jal   get_variable
/* 17D21C 8024E93C 26100004 */   addiu $s0, $s0, 4
/* 17D220 8024E940 44820000 */  mtc1  $v0, $f0
/* 17D224 8024E944 00000000 */  nop   
/* 17D228 8024E948 46800020 */  cvt.s.w $f0, $f0
/* 17D22C 8024E94C 3C01802A */  lui   $at, 0x802a
/* 17D230 8024E950 E420F270 */  swc1  $f0, -0xd90($at)
/* 17D234 8024E954 8E050000 */  lw    $a1, ($s0)
/* 17D238 8024E958 26100004 */  addiu $s0, $s0, 4
/* 17D23C 8024E95C 0C0B1EAF */  jal   get_variable
/* 17D240 8024E960 0220202D */   daddu $a0, $s1, $zero
/* 17D244 8024E964 44820000 */  mtc1  $v0, $f0
/* 17D248 8024E968 00000000 */  nop   
/* 17D24C 8024E96C 46800020 */  cvt.s.w $f0, $f0
/* 17D250 8024E970 3C01802A */  lui   $at, 0x802a
/* 17D254 8024E974 E420F274 */  swc1  $f0, -0xd8c($at)
/* 17D258 8024E978 8E050000 */  lw    $a1, ($s0)
/* 17D25C 8024E97C 0C0B1EAF */  jal   get_variable
/* 17D260 8024E980 0220202D */   daddu $a0, $s1, $zero
/* 17D264 8024E984 44820000 */  mtc1  $v0, $f0
/* 17D268 8024E988 00000000 */  nop   
/* 17D26C 8024E98C 46800020 */  cvt.s.w $f0, $f0
/* 17D270 8024E990 3C01802A */  lui   $at, 0x802a
/* 17D274 8024E994 E420F278 */  swc1  $f0, -0xd88($at)
/* 17D278 8024E998 24020002 */  addiu $v0, $zero, 2
.L8024E99C:
/* 17D27C 8024E99C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 17D280 8024E9A0 8FB10014 */  lw    $s1, 0x14($sp)
/* 17D284 8024E9A4 8FB00010 */  lw    $s0, 0x10($sp)
/* 17D288 8024E9A8 03E00008 */  jr    $ra
/* 17D28C 8024E9AC 27BD0020 */   addiu $sp, $sp, 0x20

/* 17D290 8024E9B0 3C028028 */  lui   $v0, 0x8028
/* 17D294 8024E9B4 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17D298 8024E9B8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 17D29C 8024E9BC AFB10014 */  sw    $s1, 0x14($sp)
/* 17D2A0 8024E9C0 0080882D */  daddu $s1, $a0, $zero
/* 17D2A4 8024E9C4 AFB20018 */  sw    $s2, 0x18($sp)
/* 17D2A8 8024E9C8 3C12800B */  lui   $s2, 0x800b
/* 17D2AC 8024E9CC 265222D8 */  addiu $s2, $s2, 0x22d8
/* 17D2B0 8024E9D0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 17D2B4 8024E9D4 AFB00010 */  sw    $s0, 0x10($sp)
/* 17D2B8 8024E9D8 8E30000C */  lw    $s0, 0xc($s1)
/* 17D2BC 8024E9DC 14400018 */  bnez  $v0, .L8024EA40
/* 17D2C0 8024E9E0 24020002 */   addiu $v0, $zero, 2
/* 17D2C4 8024E9E4 8E050000 */  lw    $a1, ($s0)
/* 17D2C8 8024E9E8 0C0B1EAF */  jal   get_variable
/* 17D2CC 8024E9EC 26100004 */   addiu $s0, $s0, 4
/* 17D2D0 8024E9F0 44820000 */  mtc1  $v0, $f0
/* 17D2D4 8024E9F4 00000000 */  nop   
/* 17D2D8 8024E9F8 46800020 */  cvt.s.w $f0, $f0
/* 17D2DC 8024E9FC E6400054 */  swc1  $f0, 0x54($s2)
/* 17D2E0 8024EA00 8E050000 */  lw    $a1, ($s0)
/* 17D2E4 8024EA04 26100004 */  addiu $s0, $s0, 4
/* 17D2E8 8024EA08 0C0B1EAF */  jal   get_variable
/* 17D2EC 8024EA0C 0220202D */   daddu $a0, $s1, $zero
/* 17D2F0 8024EA10 44820000 */  mtc1  $v0, $f0
/* 17D2F4 8024EA14 00000000 */  nop   
/* 17D2F8 8024EA18 46800020 */  cvt.s.w $f0, $f0
/* 17D2FC 8024EA1C E6400058 */  swc1  $f0, 0x58($s2)
/* 17D300 8024EA20 8E050000 */  lw    $a1, ($s0)
/* 17D304 8024EA24 0C0B1EAF */  jal   get_variable
/* 17D308 8024EA28 0220202D */   daddu $a0, $s1, $zero
/* 17D30C 8024EA2C 44820000 */  mtc1  $v0, $f0
/* 17D310 8024EA30 00000000 */  nop   
/* 17D314 8024EA34 46800020 */  cvt.s.w $f0, $f0
/* 17D318 8024EA38 24020002 */  addiu $v0, $zero, 2
/* 17D31C 8024EA3C E640005C */  swc1  $f0, 0x5c($s2)
.L8024EA40:
/* 17D320 8024EA40 8FBF001C */  lw    $ra, 0x1c($sp)
/* 17D324 8024EA44 8FB20018 */  lw    $s2, 0x18($sp)
/* 17D328 8024EA48 8FB10014 */  lw    $s1, 0x14($sp)
/* 17D32C 8024EA4C 8FB00010 */  lw    $s0, 0x10($sp)
/* 17D330 8024EA50 03E00008 */  jr    $ra
/* 17D334 8024EA54 27BD0020 */   addiu $sp, $sp, 0x20

