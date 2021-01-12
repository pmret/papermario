.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_71CF1C
/* 71CF1C 802A123C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 71CF20 802A1240 AFB1001C */  sw        $s1, 0x1c($sp)
/* 71CF24 802A1244 0080882D */  daddu     $s1, $a0, $zero
/* 71CF28 802A1248 AFBF0028 */  sw        $ra, 0x28($sp)
/* 71CF2C 802A124C AFB30024 */  sw        $s3, 0x24($sp)
/* 71CF30 802A1250 AFB20020 */  sw        $s2, 0x20($sp)
/* 71CF34 802A1254 AFB00018 */  sw        $s0, 0x18($sp)
/* 71CF38 802A1258 8E30000C */  lw        $s0, 0xc($s1)
/* 71CF3C 802A125C 8E050000 */  lw        $a1, ($s0)
/* 71CF40 802A1260 0C0B1EAF */  jal       get_variable
/* 71CF44 802A1264 26100004 */   addiu    $s0, $s0, 4
/* 71CF48 802A1268 8E050000 */  lw        $a1, ($s0)
/* 71CF4C 802A126C 26100004 */  addiu     $s0, $s0, 4
/* 71CF50 802A1270 0220202D */  daddu     $a0, $s1, $zero
/* 71CF54 802A1274 0C0B1EAF */  jal       get_variable
/* 71CF58 802A1278 0040982D */   daddu    $s3, $v0, $zero
/* 71CF5C 802A127C 8E050000 */  lw        $a1, ($s0)
/* 71CF60 802A1280 26100004 */  addiu     $s0, $s0, 4
/* 71CF64 802A1284 0220202D */  daddu     $a0, $s1, $zero
/* 71CF68 802A1288 0C0B1EAF */  jal       get_variable
/* 71CF6C 802A128C 0040902D */   daddu    $s2, $v0, $zero
/* 71CF70 802A1290 0220202D */  daddu     $a0, $s1, $zero
/* 71CF74 802A1294 8E050000 */  lw        $a1, ($s0)
/* 71CF78 802A1298 0C0B1EAF */  jal       get_variable
/* 71CF7C 802A129C 0040802D */   daddu    $s0, $v0, $zero
/* 71CF80 802A12A0 44930000 */  mtc1      $s3, $f0
/* 71CF84 802A12A4 00000000 */  nop       
/* 71CF88 802A12A8 46800020 */  cvt.s.w   $f0, $f0
/* 71CF8C 802A12AC 44050000 */  mfc1      $a1, $f0
/* 71CF90 802A12B0 44920000 */  mtc1      $s2, $f0
/* 71CF94 802A12B4 00000000 */  nop       
/* 71CF98 802A12B8 46800020 */  cvt.s.w   $f0, $f0
/* 71CF9C 802A12BC 44060000 */  mfc1      $a2, $f0
/* 71CFA0 802A12C0 44900000 */  mtc1      $s0, $f0
/* 71CFA4 802A12C4 00000000 */  nop       
/* 71CFA8 802A12C8 46800020 */  cvt.s.w   $f0, $f0
/* 71CFAC 802A12CC 44070000 */  mfc1      $a3, $f0
/* 71CFB0 802A12D0 0000202D */  daddu     $a0, $zero, $zero
/* 71CFB4 802A12D4 0C01C424 */  jal       func_80071090
/* 71CFB8 802A12D8 AFA20010 */   sw       $v0, 0x10($sp)
/* 71CFBC 802A12DC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 71CFC0 802A12E0 8FB30024 */  lw        $s3, 0x24($sp)
/* 71CFC4 802A12E4 8FB20020 */  lw        $s2, 0x20($sp)
/* 71CFC8 802A12E8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 71CFCC 802A12EC 8FB00018 */  lw        $s0, 0x18($sp)
/* 71CFD0 802A12F0 24020002 */  addiu     $v0, $zero, 2
/* 71CFD4 802A12F4 03E00008 */  jr        $ra
/* 71CFD8 802A12F8 27BD0030 */   addiu    $sp, $sp, 0x30
