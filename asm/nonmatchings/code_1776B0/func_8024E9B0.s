.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024E9B0
/* 17D290 8024E9B0 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17D294 8024E9B4 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17D298 8024E9B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17D29C 8024E9BC AFB10014 */  sw        $s1, 0x14($sp)
/* 17D2A0 8024E9C0 0080882D */  daddu     $s1, $a0, $zero
/* 17D2A4 8024E9C4 AFB20018 */  sw        $s2, 0x18($sp)
/* 17D2A8 8024E9C8 3C12800B */  lui       $s2, %hi(gCameras+0x558)
/* 17D2AC 8024E9CC 265222D8 */  addiu     $s2, $s2, %lo(gCameras+0x558)
/* 17D2B0 8024E9D0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 17D2B4 8024E9D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 17D2B8 8024E9D8 8E30000C */  lw        $s0, 0xc($s1)
/* 17D2BC 8024E9DC 14400018 */  bnez      $v0, .L8024EA40
/* 17D2C0 8024E9E0 24020002 */   addiu    $v0, $zero, 2
/* 17D2C4 8024E9E4 8E050000 */  lw        $a1, ($s0)
/* 17D2C8 8024E9E8 0C0B1EAF */  jal       get_variable
/* 17D2CC 8024E9EC 26100004 */   addiu    $s0, $s0, 4
/* 17D2D0 8024E9F0 44820000 */  mtc1      $v0, $f0
/* 17D2D4 8024E9F4 00000000 */  nop
/* 17D2D8 8024E9F8 46800020 */  cvt.s.w   $f0, $f0
/* 17D2DC 8024E9FC E6400054 */  swc1      $f0, 0x54($s2)
/* 17D2E0 8024EA00 8E050000 */  lw        $a1, ($s0)
/* 17D2E4 8024EA04 26100004 */  addiu     $s0, $s0, 4
/* 17D2E8 8024EA08 0C0B1EAF */  jal       get_variable
/* 17D2EC 8024EA0C 0220202D */   daddu    $a0, $s1, $zero
/* 17D2F0 8024EA10 44820000 */  mtc1      $v0, $f0
/* 17D2F4 8024EA14 00000000 */  nop
/* 17D2F8 8024EA18 46800020 */  cvt.s.w   $f0, $f0
/* 17D2FC 8024EA1C E6400058 */  swc1      $f0, 0x58($s2)
/* 17D300 8024EA20 8E050000 */  lw        $a1, ($s0)
/* 17D304 8024EA24 0C0B1EAF */  jal       get_variable
/* 17D308 8024EA28 0220202D */   daddu    $a0, $s1, $zero
/* 17D30C 8024EA2C 44820000 */  mtc1      $v0, $f0
/* 17D310 8024EA30 00000000 */  nop
/* 17D314 8024EA34 46800020 */  cvt.s.w   $f0, $f0
/* 17D318 8024EA38 24020002 */  addiu     $v0, $zero, 2
/* 17D31C 8024EA3C E640005C */  swc1      $f0, 0x5c($s2)
.L8024EA40:
/* 17D320 8024EA40 8FBF001C */  lw        $ra, 0x1c($sp)
/* 17D324 8024EA44 8FB20018 */  lw        $s2, 0x18($sp)
/* 17D328 8024EA48 8FB10014 */  lw        $s1, 0x14($sp)
/* 17D32C 8024EA4C 8FB00010 */  lw        $s0, 0x10($sp)
/* 17D330 8024EA50 03E00008 */  jr        $ra
/* 17D334 8024EA54 27BD0020 */   addiu    $sp, $sp, 0x20
