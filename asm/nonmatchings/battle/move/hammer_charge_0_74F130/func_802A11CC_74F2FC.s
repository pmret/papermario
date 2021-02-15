.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A11CC_74F2FC
/* 74F2FC 802A11CC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 74F300 802A11D0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 74F304 802A11D4 0080882D */  daddu     $s1, $a0, $zero
/* 74F308 802A11D8 AFBF0028 */  sw        $ra, 0x28($sp)
/* 74F30C 802A11DC AFB30024 */  sw        $s3, 0x24($sp)
/* 74F310 802A11E0 AFB20020 */  sw        $s2, 0x20($sp)
/* 74F314 802A11E4 AFB00018 */  sw        $s0, 0x18($sp)
/* 74F318 802A11E8 8E30000C */  lw        $s0, 0xc($s1)
/* 74F31C 802A11EC 8E050000 */  lw        $a1, ($s0)
/* 74F320 802A11F0 0C0B1EAF */  jal       get_variable
/* 74F324 802A11F4 26100004 */   addiu    $s0, $s0, 4
/* 74F328 802A11F8 8E050000 */  lw        $a1, ($s0)
/* 74F32C 802A11FC 26100004 */  addiu     $s0, $s0, 4
/* 74F330 802A1200 0220202D */  daddu     $a0, $s1, $zero
/* 74F334 802A1204 0C0B1EAF */  jal       get_variable
/* 74F338 802A1208 0040982D */   daddu    $s3, $v0, $zero
/* 74F33C 802A120C 8E050000 */  lw        $a1, ($s0)
/* 74F340 802A1210 26100004 */  addiu     $s0, $s0, 4
/* 74F344 802A1214 0220202D */  daddu     $a0, $s1, $zero
/* 74F348 802A1218 0C0B1EAF */  jal       get_variable
/* 74F34C 802A121C 0040902D */   daddu    $s2, $v0, $zero
/* 74F350 802A1220 0220202D */  daddu     $a0, $s1, $zero
/* 74F354 802A1224 8E050000 */  lw        $a1, ($s0)
/* 74F358 802A1228 0C0B210B */  jal       get_float_variable
/* 74F35C 802A122C 0040802D */   daddu    $s0, $v0, $zero
/* 74F360 802A1230 24040006 */  addiu     $a0, $zero, 6
/* 74F364 802A1234 2673000A */  addiu     $s3, $s3, 0xa
/* 74F368 802A1238 44931000 */  mtc1      $s3, $f2
/* 74F36C 802A123C 00000000 */  nop
/* 74F370 802A1240 468010A0 */  cvt.s.w   $f2, $f2
/* 74F374 802A1244 26520012 */  addiu     $s2, $s2, 0x12
/* 74F378 802A1248 44051000 */  mfc1      $a1, $f2
/* 74F37C 802A124C 44921000 */  mtc1      $s2, $f2
/* 74F380 802A1250 00000000 */  nop
/* 74F384 802A1254 468010A0 */  cvt.s.w   $f2, $f2
/* 74F388 802A1258 44061000 */  mfc1      $a2, $f2
/* 74F38C 802A125C 44901000 */  mtc1      $s0, $f2
/* 74F390 802A1260 00000000 */  nop
/* 74F394 802A1264 468010A0 */  cvt.s.w   $f2, $f2
/* 74F398 802A1268 44071000 */  mfc1      $a3, $f2
/* 74F39C 802A126C 2402002D */  addiu     $v0, $zero, 0x2d
/* 74F3A0 802A1270 E7A00010 */  swc1      $f0, 0x10($sp)
/* 74F3A4 802A1274 0C01C82C */  jal       func_800720B0
/* 74F3A8 802A1278 AFA20014 */   sw       $v0, 0x14($sp)
/* 74F3AC 802A127C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 74F3B0 802A1280 8FB30024 */  lw        $s3, 0x24($sp)
/* 74F3B4 802A1284 8FB20020 */  lw        $s2, 0x20($sp)
/* 74F3B8 802A1288 8FB1001C */  lw        $s1, 0x1c($sp)
/* 74F3BC 802A128C 8FB00018 */  lw        $s0, 0x18($sp)
/* 74F3C0 802A1290 24020002 */  addiu     $v0, $zero, 2
/* 74F3C4 802A1294 03E00008 */  jr        $ra
/* 74F3C8 802A1298 27BD0030 */   addiu    $sp, $sp, 0x30
/* 74F3CC 802A129C 00000000 */  nop
