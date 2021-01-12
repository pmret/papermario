.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_73330C
/* 73330C 802A123C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 733310 802A1240 AFB10014 */  sw        $s1, 0x14($sp)
/* 733314 802A1244 0080882D */  daddu     $s1, $a0, $zero
/* 733318 802A1248 AFBF0020 */  sw        $ra, 0x20($sp)
/* 73331C 802A124C AFB3001C */  sw        $s3, 0x1c($sp)
/* 733320 802A1250 AFB20018 */  sw        $s2, 0x18($sp)
/* 733324 802A1254 AFB00010 */  sw        $s0, 0x10($sp)
/* 733328 802A1258 8E30000C */  lw        $s0, 0xc($s1)
/* 73332C 802A125C 8E050000 */  lw        $a1, ($s0)
/* 733330 802A1260 0C0B1EAF */  jal       get_variable
/* 733334 802A1264 26100004 */   addiu    $s0, $s0, 4
/* 733338 802A1268 8E050000 */  lw        $a1, ($s0)
/* 73333C 802A126C 26100004 */  addiu     $s0, $s0, 4
/* 733340 802A1270 0220202D */  daddu     $a0, $s1, $zero
/* 733344 802A1274 0C0B1EAF */  jal       get_variable
/* 733348 802A1278 0040982D */   daddu    $s3, $v0, $zero
/* 73334C 802A127C 0220202D */  daddu     $a0, $s1, $zero
/* 733350 802A1280 8E050000 */  lw        $a1, ($s0)
/* 733354 802A1284 0C0B1EAF */  jal       get_variable
/* 733358 802A1288 0040902D */   daddu    $s2, $v0, $zero
/* 73335C 802A128C 8E2400BC */  lw        $a0, 0xbc($s1)
/* 733360 802A1290 0C04C3D6 */  jal       get_item_entity
/* 733364 802A1294 0040802D */   daddu    $s0, $v0, $zero
/* 733368 802A1298 0040182D */  daddu     $v1, $v0, $zero
/* 73336C 802A129C 44930000 */  mtc1      $s3, $f0
/* 733370 802A12A0 00000000 */  nop
/* 733374 802A12A4 46800020 */  cvt.s.w   $f0, $f0
/* 733378 802A12A8 E4600008 */  swc1      $f0, 8($v1)
/* 73337C 802A12AC 44920000 */  mtc1      $s2, $f0
/* 733380 802A12B0 00000000 */  nop
/* 733384 802A12B4 46800020 */  cvt.s.w   $f0, $f0
/* 733388 802A12B8 E460000C */  swc1      $f0, 0xc($v1)
/* 73338C 802A12BC 44900000 */  mtc1      $s0, $f0
/* 733390 802A12C0 00000000 */  nop
/* 733394 802A12C4 46800020 */  cvt.s.w   $f0, $f0
/* 733398 802A12C8 E4600010 */  swc1      $f0, 0x10($v1)
/* 73339C 802A12CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7333A0 802A12D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7333A4 802A12D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 7333A8 802A12D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 7333AC 802A12DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 7333B0 802A12E0 24020002 */  addiu     $v0, $zero, 2
/* 7333B4 802A12E4 03E00008 */  jr        $ra
/* 7333B8 802A12E8 27BD0028 */   addiu    $sp, $sp, 0x28
