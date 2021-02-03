.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_715A8C
/* 715A8C 802A123C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 715A90 802A1240 AFB10014 */  sw        $s1, 0x14($sp)
/* 715A94 802A1244 0080882D */  daddu     $s1, $a0, $zero
/* 715A98 802A1248 AFBF0020 */  sw        $ra, 0x20($sp)
/* 715A9C 802A124C AFB3001C */  sw        $s3, 0x1c($sp)
/* 715AA0 802A1250 AFB20018 */  sw        $s2, 0x18($sp)
/* 715AA4 802A1254 AFB00010 */  sw        $s0, 0x10($sp)
/* 715AA8 802A1258 8E30000C */  lw        $s0, 0xc($s1)
/* 715AAC 802A125C 8E050000 */  lw        $a1, ($s0)
/* 715AB0 802A1260 0C0B1EAF */  jal       get_variable
/* 715AB4 802A1264 26100004 */   addiu    $s0, $s0, 4
/* 715AB8 802A1268 8E050000 */  lw        $a1, ($s0)
/* 715ABC 802A126C 26100004 */  addiu     $s0, $s0, 4
/* 715AC0 802A1270 0220202D */  daddu     $a0, $s1, $zero
/* 715AC4 802A1274 0C0B1EAF */  jal       get_variable
/* 715AC8 802A1278 0040982D */   daddu    $s3, $v0, $zero
/* 715ACC 802A127C 0220202D */  daddu     $a0, $s1, $zero
/* 715AD0 802A1280 8E050000 */  lw        $a1, ($s0)
/* 715AD4 802A1284 0C0B1EAF */  jal       get_variable
/* 715AD8 802A1288 0040902D */   daddu    $s2, $v0, $zero
/* 715ADC 802A128C 8E2400BC */  lw        $a0, 0xbc($s1)
/* 715AE0 802A1290 0C04C3D6 */  jal       get_item_entity
/* 715AE4 802A1294 0040802D */   daddu    $s0, $v0, $zero
/* 715AE8 802A1298 0040182D */  daddu     $v1, $v0, $zero
/* 715AEC 802A129C 44930000 */  mtc1      $s3, $f0
/* 715AF0 802A12A0 00000000 */  nop
/* 715AF4 802A12A4 46800020 */  cvt.s.w   $f0, $f0
/* 715AF8 802A12A8 E4600008 */  swc1      $f0, 8($v1)
/* 715AFC 802A12AC 44920000 */  mtc1      $s2, $f0
/* 715B00 802A12B0 00000000 */  nop
/* 715B04 802A12B4 46800020 */  cvt.s.w   $f0, $f0
/* 715B08 802A12B8 E460000C */  swc1      $f0, 0xc($v1)
/* 715B0C 802A12BC 44900000 */  mtc1      $s0, $f0
/* 715B10 802A12C0 00000000 */  nop
/* 715B14 802A12C4 46800020 */  cvt.s.w   $f0, $f0
/* 715B18 802A12C8 E4600010 */  swc1      $f0, 0x10($v1)
/* 715B1C 802A12CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 715B20 802A12D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 715B24 802A12D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 715B28 802A12D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 715B2C 802A12DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 715B30 802A12E0 24020002 */  addiu     $v0, $zero, 2
/* 715B34 802A12E4 03E00008 */  jr        $ra
/* 715B38 802A12E8 27BD0028 */   addiu    $sp, $sp, 0x28
