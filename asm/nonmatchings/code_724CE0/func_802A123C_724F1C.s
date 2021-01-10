.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_724F1C
/* 724F1C 802A123C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 724F20 802A1240 AFB10014 */  sw        $s1, 0x14($sp)
/* 724F24 802A1244 0080882D */  daddu     $s1, $a0, $zero
/* 724F28 802A1248 AFBF0020 */  sw        $ra, 0x20($sp)
/* 724F2C 802A124C AFB3001C */  sw        $s3, 0x1c($sp)
/* 724F30 802A1250 AFB20018 */  sw        $s2, 0x18($sp)
/* 724F34 802A1254 AFB00010 */  sw        $s0, 0x10($sp)
/* 724F38 802A1258 8E30000C */  lw        $s0, 0xc($s1)
/* 724F3C 802A125C 8E050000 */  lw        $a1, ($s0)
/* 724F40 802A1260 0C0B1EAF */  jal       get_variable
/* 724F44 802A1264 26100004 */   addiu    $s0, $s0, 4
/* 724F48 802A1268 8E050000 */  lw        $a1, ($s0)
/* 724F4C 802A126C 26100004 */  addiu     $s0, $s0, 4
/* 724F50 802A1270 0220202D */  daddu     $a0, $s1, $zero
/* 724F54 802A1274 0C0B1EAF */  jal       get_variable
/* 724F58 802A1278 0040982D */   daddu    $s3, $v0, $zero
/* 724F5C 802A127C 0220202D */  daddu     $a0, $s1, $zero
/* 724F60 802A1280 8E050000 */  lw        $a1, ($s0)
/* 724F64 802A1284 0C0B1EAF */  jal       get_variable
/* 724F68 802A1288 0040902D */   daddu    $s2, $v0, $zero
/* 724F6C 802A128C 8E2400BC */  lw        $a0, 0xbc($s1)
/* 724F70 802A1290 0C04C3D6 */  jal       get_item_entity
/* 724F74 802A1294 0040802D */   daddu    $s0, $v0, $zero
/* 724F78 802A1298 0040182D */  daddu     $v1, $v0, $zero
/* 724F7C 802A129C 44930000 */  mtc1      $s3, $f0
/* 724F80 802A12A0 00000000 */  nop       
/* 724F84 802A12A4 46800020 */  cvt.s.w   $f0, $f0
/* 724F88 802A12A8 E4600008 */  swc1      $f0, 8($v1)
/* 724F8C 802A12AC 44920000 */  mtc1      $s2, $f0
/* 724F90 802A12B0 00000000 */  nop       
/* 724F94 802A12B4 46800020 */  cvt.s.w   $f0, $f0
/* 724F98 802A12B8 E460000C */  swc1      $f0, 0xc($v1)
/* 724F9C 802A12BC 44900000 */  mtc1      $s0, $f0
/* 724FA0 802A12C0 00000000 */  nop       
/* 724FA4 802A12C4 46800020 */  cvt.s.w   $f0, $f0
/* 724FA8 802A12C8 E4600010 */  swc1      $f0, 0x10($v1)
/* 724FAC 802A12CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 724FB0 802A12D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 724FB4 802A12D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 724FB8 802A12D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 724FBC 802A12DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 724FC0 802A12E0 24020002 */  addiu     $v0, $zero, 2
/* 724FC4 802A12E4 03E00008 */  jr        $ra
/* 724FC8 802A12E8 27BD0028 */   addiu    $sp, $sp, 0x28
