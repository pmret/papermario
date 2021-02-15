.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_716E9C
/* 716E9C 802A123C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 716EA0 802A1240 AFB1001C */  sw        $s1, 0x1c($sp)
/* 716EA4 802A1244 0080882D */  daddu     $s1, $a0, $zero
/* 716EA8 802A1248 AFBF0024 */  sw        $ra, 0x24($sp)
/* 716EAC 802A124C AFB20020 */  sw        $s2, 0x20($sp)
/* 716EB0 802A1250 AFB00018 */  sw        $s0, 0x18($sp)
/* 716EB4 802A1254 8E30000C */  lw        $s0, 0xc($s1)
/* 716EB8 802A1258 8E050000 */  lw        $a1, ($s0)
/* 716EBC 802A125C 0C0B1EAF */  jal       get_variable
/* 716EC0 802A1260 26100004 */   addiu    $s0, $s0, 4
/* 716EC4 802A1264 8E050000 */  lw        $a1, ($s0)
/* 716EC8 802A1268 26100004 */  addiu     $s0, $s0, 4
/* 716ECC 802A126C 0220202D */  daddu     $a0, $s1, $zero
/* 716ED0 802A1270 0C0B1EAF */  jal       get_variable
/* 716ED4 802A1274 0040902D */   daddu    $s2, $v0, $zero
/* 716ED8 802A1278 0220202D */  daddu     $a0, $s1, $zero
/* 716EDC 802A127C 8E050000 */  lw        $a1, ($s0)
/* 716EE0 802A1280 0C0B1EAF */  jal       get_variable
/* 716EE4 802A1284 0040802D */   daddu    $s0, $v0, $zero
/* 716EE8 802A1288 44920000 */  mtc1      $s2, $f0
/* 716EEC 802A128C 00000000 */  nop
/* 716EF0 802A1290 46800020 */  cvt.s.w   $f0, $f0
/* 716EF4 802A1294 44050000 */  mfc1      $a1, $f0
/* 716EF8 802A1298 44900000 */  mtc1      $s0, $f0
/* 716EFC 802A129C 00000000 */  nop
/* 716F00 802A12A0 46800020 */  cvt.s.w   $f0, $f0
/* 716F04 802A12A4 44060000 */  mfc1      $a2, $f0
/* 716F08 802A12A8 44820000 */  mtc1      $v0, $f0
/* 716F0C 802A12AC 00000000 */  nop
/* 716F10 802A12B0 46800020 */  cvt.s.w   $f0, $f0
/* 716F14 802A12B4 44070000 */  mfc1      $a3, $f0
/* 716F18 802A12B8 0000202D */  daddu     $a0, $zero, $zero
/* 716F1C 802A12BC 0C01C40C */  jal       func_80071030
/* 716F20 802A12C0 AFA00010 */   sw       $zero, 0x10($sp)
/* 716F24 802A12C4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 716F28 802A12C8 8FB20020 */  lw        $s2, 0x20($sp)
/* 716F2C 802A12CC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 716F30 802A12D0 8FB00018 */  lw        $s0, 0x18($sp)
/* 716F34 802A12D4 24020002 */  addiu     $v0, $zero, 2
/* 716F38 802A12D8 03E00008 */  jr        $ra
/* 716F3C 802A12DC 27BD0028 */   addiu    $sp, $sp, 0x28
