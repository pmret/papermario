.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel NpcMoveTo
/* 0F2BDC 802CE22C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F2BE0 802CE230 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F2BE4 802CE234 0080902D */  daddu $s2, $a0, $zero
/* 0F2BE8 802CE238 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F2BEC 802CE23C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F2BF0 802CE240 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F2BF4 802CE244 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F2BF8 802CE248 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F2BFC 802CE24C 8E51000C */  lw    $s1, 0xc($s2)
/* 0F2C00 802CE250 54A00001 */  bnel  $a1, $zero, .L802CE258
/* 0F2C04 802CE254 AE400070 */   sw    $zero, 0x70($s2)
.L802CE258:
/* 0F2C08 802CE258 8E420070 */  lw    $v0, 0x70($s2)
/* 0F2C0C 802CE25C 1440003D */  bnez  $v0, .L802CE354
/* 0F2C10 802CE260 00000000 */   nop   
/* 0F2C14 802CE264 8E250000 */  lw    $a1, ($s1)
/* 0F2C18 802CE268 26310004 */  addiu $s1, $s1, 4
/* 0F2C1C 802CE26C 0C0B1EAF */  jal   get_variable
/* 0F2C20 802CE270 0240202D */   daddu $a0, $s2, $zero
/* 0F2C24 802CE274 8E250000 */  lw    $a1, ($s1)
/* 0F2C28 802CE278 26310004 */  addiu $s1, $s1, 4
/* 0F2C2C 802CE27C 0240202D */  daddu $a0, $s2, $zero
/* 0F2C30 802CE280 0C0B1EAF */  jal   get_variable
/* 0F2C34 802CE284 0040802D */   daddu $s0, $v0, $zero
/* 0F2C38 802CE288 8E250000 */  lw    $a1, ($s1)
/* 0F2C3C 802CE28C 26310004 */  addiu $s1, $s1, 4
/* 0F2C40 802CE290 4482B000 */  mtc1  $v0, $f22
/* 0F2C44 802CE294 00000000 */  nop   
/* 0F2C48 802CE298 4680B5A0 */  cvt.s.w $f22, $f22
/* 0F2C4C 802CE29C 0C0B1EAF */  jal   get_variable
/* 0F2C50 802CE2A0 0240202D */   daddu $a0, $s2, $zero
/* 0F2C54 802CE2A4 8E250000 */  lw    $a1, ($s1)
/* 0F2C58 802CE2A8 4482A000 */  mtc1  $v0, $f20
/* 0F2C5C 802CE2AC 00000000 */  nop   
/* 0F2C60 802CE2B0 4680A520 */  cvt.s.w $f20, $f20
/* 0F2C64 802CE2B4 0C0B1EAF */  jal   get_variable
/* 0F2C68 802CE2B8 0240202D */   daddu $a0, $s2, $zero
/* 0F2C6C 802CE2BC 0240202D */  daddu $a0, $s2, $zero
/* 0F2C70 802CE2C0 0200282D */  daddu $a1, $s0, $zero
/* 0F2C74 802CE2C4 0C0B36B0 */  jal   func_802CDAC0
/* 0F2C78 802CE2C8 0040882D */   daddu $s1, $v0, $zero
/* 0F2C7C 802CE2CC 0040802D */  daddu $s0, $v0, $zero
/* 0F2C80 802CE2D0 56000003 */  bnel  $s0, $zero, .L802CE2E0
/* 0F2C84 802CE2D4 AE500074 */   sw    $s0, 0x74($s2)
/* 0F2C88 802CE2D8 080B3905 */  j     .L802CE414
/* 0F2C8C 802CE2DC 24020002 */   addiu $v0, $zero, 2

.L802CE2E0:
/* 0F2C90 802CE2E0 C60C0038 */  lwc1  $f12, 0x38($s0)
/* 0F2C94 802CE2E4 C60E0040 */  lwc1  $f14, 0x40($s0)
/* 0F2C98 802CE2E8 E6160060 */  swc1  $f22, 0x60($s0)
/* 0F2C9C 802CE2EC 4406B000 */  mfc1  $a2, $f22
/* 0F2CA0 802CE2F0 E6140068 */  swc1  $f20, 0x68($s0)
/* 0F2CA4 802CE2F4 4407A000 */  mfc1  $a3, $f20
/* 0F2CA8 802CE2F8 0C00A7B5 */  jal   dist2D
/* 0F2CAC 802CE2FC A611008E */   sh    $s1, 0x8e($s0)
/* 0F2CB0 802CE300 8602008E */  lh    $v0, 0x8e($s0)
/* 0F2CB4 802CE304 14400007 */  bnez  $v0, .L802CE324
/* 0F2CB8 802CE308 46000186 */   mov.s $f6, $f0
/* 0F2CBC 802CE30C C6000018 */  lwc1  $f0, 0x18($s0)
/* 0F2CC0 802CE310 46003003 */  div.s $f0, $f6, $f0
/* 0F2CC4 802CE314 4600020D */  trunc.w.s $f8, $f0
/* 0F2CC8 802CE318 44024000 */  mfc1  $v0, $f8
/* 0F2CCC 802CE31C 080B38CE */  j     .L802CE338
/* 0F2CD0 802CE320 A602008E */   sh    $v0, 0x8e($s0)

.L802CE324:
/* 0F2CD4 802CE324 44820000 */  mtc1  $v0, $f0
/* 0F2CD8 802CE328 00000000 */  nop   
/* 0F2CDC 802CE32C 46800020 */  cvt.s.w $f0, $f0
/* 0F2CE0 802CE330 46003003 */  div.s $f0, $f6, $f0
/* 0F2CE4 802CE334 E6000018 */  swc1  $f0, 0x18($s0)
.L802CE338:
/* 0F2CE8 802CE338 8602008E */  lh    $v0, 0x8e($s0)
/* 0F2CEC 802CE33C 14400004 */  bnez  $v0, .L802CE350
/* 0F2CF0 802CE340 24020001 */   addiu $v0, $zero, 1
/* 0F2CF4 802CE344 24020001 */  addiu $v0, $zero, 1
/* 0F2CF8 802CE348 A602008E */  sh    $v0, 0x8e($s0)
/* 0F2CFC 802CE34C 24020001 */  addiu $v0, $zero, 1
.L802CE350:
/* 0F2D00 802CE350 AE420070 */  sw    $v0, 0x70($s2)
.L802CE354:
/* 0F2D04 802CE354 8E500074 */  lw    $s0, 0x74($s2)
/* 0F2D08 802CE358 C60C0038 */  lwc1  $f12, 0x38($s0)
/* 0F2D0C 802CE35C C60E0040 */  lwc1  $f14, 0x40($s0)
/* 0F2D10 802CE360 8E060060 */  lw    $a2, 0x60($s0)
/* 0F2D14 802CE364 0C00A720 */  jal   atan2
/* 0F2D18 802CE368 8E070068 */   lw    $a3, 0x68($s0)
/* 0F2D1C 802CE36C 8E050018 */  lw    $a1, 0x18($s0)
/* 0F2D20 802CE370 44060000 */  mfc1  $a2, $f0
/* 0F2D24 802CE374 0200202D */  daddu $a0, $s0, $zero
/* 0F2D28 802CE378 0C00EA95 */  jal   npc_move_heading
/* 0F2D2C 802CE37C AE06000C */   sw    $a2, 0xc($s0)
/* 0F2D30 802CE380 C6000018 */  lwc1  $f0, 0x18($s0)
/* 0F2D34 802CE384 3C014010 */  lui   $at, 0x4010
/* 0F2D38 802CE388 44811800 */  mtc1  $at, $f3
/* 0F2D3C 802CE38C 44801000 */  mtc1  $zero, $f2
/* 0F2D40 802CE390 46000021 */  cvt.d.s $f0, $f0
/* 0F2D44 802CE394 4622003C */  c.lt.d $f0, $f2
/* 0F2D48 802CE398 00000000 */  nop   
/* 0F2D4C 802CE39C 45000003 */  bc1f  .L802CE3AC
/* 0F2D50 802CE3A0 0200202D */   daddu $a0, $s0, $zero
/* 0F2D54 802CE3A4 080B38EC */  j     .L802CE3B0
/* 0F2D58 802CE3A8 0000282D */   daddu $a1, $zero, $zero

.L802CE3AC:
/* 0F2D5C 802CE3AC 24050001 */  addiu $a1, $zero, 1
.L802CE3B0:
/* 0F2D60 802CE3B0 0C00F598 */  jal   func_8003D660
/* 0F2D64 802CE3B4 00000000 */   nop   
/* 0F2D68 802CE3B8 C60C0038 */  lwc1  $f12, 0x38($s0)
/* 0F2D6C 802CE3BC C60E0040 */  lwc1  $f14, 0x40($s0)
/* 0F2D70 802CE3C0 8E060060 */  lw    $a2, 0x60($s0)
/* 0F2D74 802CE3C4 0C00A7B5 */  jal   dist2D
/* 0F2D78 802CE3C8 8E070068 */   lw    $a3, 0x68($s0)
/* 0F2D7C 802CE3CC 46000186 */  mov.s $f6, $f0
/* 0F2D80 802CE3D0 C6040018 */  lwc1  $f4, 0x18($s0)
/* 0F2D84 802CE3D4 3C013FF0 */  lui   $at, 0x3ff0
/* 0F2D88 802CE3D8 44811800 */  mtc1  $at, $f3
/* 0F2D8C 802CE3DC 44801000 */  mtc1  $zero, $f2
/* 0F2D90 802CE3E0 46002021 */  cvt.d.s $f0, $f4
/* 0F2D94 802CE3E4 4622003C */  c.lt.d $f0, $f2
/* 0F2D98 802CE3E8 00000000 */  nop   
/* 0F2D9C 802CE3EC 45000004 */  bc1f  .L802CE400
/* 0F2DA0 802CE3F0 00000000 */   nop   
/* 0F2DA4 802CE3F4 3C013F80 */  lui   $at, 0x3f80
/* 0F2DA8 802CE3F8 44812000 */  mtc1  $at, $f4
/* 0F2DAC 802CE3FC 00000000 */  nop   
.L802CE400:
/* 0F2DB0 802CE400 4604303E */  c.le.s $f6, $f4
/* 0F2DB4 802CE404 00000000 */  nop   
/* 0F2DB8 802CE408 45010002 */  bc1t  .L802CE414
/* 0F2DBC 802CE40C 24020001 */   addiu $v0, $zero, 1
/* 0F2DC0 802CE410 0000102D */  daddu $v0, $zero, $zero
.L802CE414:
/* 0F2DC4 802CE414 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F2DC8 802CE418 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F2DCC 802CE41C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2DD0 802CE420 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F2DD4 802CE424 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F2DD8 802CE428 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F2DDC 802CE42C 03E00008 */  jr    $ra
/* 0F2DE0 802CE430 27BD0030 */   addiu $sp, $sp, 0x30

