.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_7239BC
/* 7239BC 802A123C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 7239C0 802A1240 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7239C4 802A1244 0080882D */  daddu     $s1, $a0, $zero
/* 7239C8 802A1248 AFBF0028 */  sw        $ra, 0x28($sp)
/* 7239CC 802A124C AFB30024 */  sw        $s3, 0x24($sp)
/* 7239D0 802A1250 AFB20020 */  sw        $s2, 0x20($sp)
/* 7239D4 802A1254 AFB00018 */  sw        $s0, 0x18($sp)
/* 7239D8 802A1258 8E30000C */  lw        $s0, 0xc($s1)
/* 7239DC 802A125C 8E050000 */  lw        $a1, ($s0)
/* 7239E0 802A1260 0C0B1EAF */  jal       get_variable
/* 7239E4 802A1264 26100004 */   addiu    $s0, $s0, 4
/* 7239E8 802A1268 8E050000 */  lw        $a1, ($s0)
/* 7239EC 802A126C 26100004 */  addiu     $s0, $s0, 4
/* 7239F0 802A1270 0220202D */  daddu     $a0, $s1, $zero
/* 7239F4 802A1274 0C0B1EAF */  jal       get_variable
/* 7239F8 802A1278 0040982D */   daddu    $s3, $v0, $zero
/* 7239FC 802A127C 8E050000 */  lw        $a1, ($s0)
/* 723A00 802A1280 26100004 */  addiu     $s0, $s0, 4
/* 723A04 802A1284 0220202D */  daddu     $a0, $s1, $zero
/* 723A08 802A1288 0C0B1EAF */  jal       get_variable
/* 723A0C 802A128C 0040902D */   daddu    $s2, $v0, $zero
/* 723A10 802A1290 0220202D */  daddu     $a0, $s1, $zero
/* 723A14 802A1294 8E050000 */  lw        $a1, ($s0)
/* 723A18 802A1298 0C0B1EAF */  jal       get_variable
/* 723A1C 802A129C 0040802D */   daddu    $s0, $v0, $zero
/* 723A20 802A12A0 44930000 */  mtc1      $s3, $f0
/* 723A24 802A12A4 00000000 */  nop       
/* 723A28 802A12A8 46800020 */  cvt.s.w   $f0, $f0
/* 723A2C 802A12AC 44050000 */  mfc1      $a1, $f0
/* 723A30 802A12B0 44920000 */  mtc1      $s2, $f0
/* 723A34 802A12B4 00000000 */  nop       
/* 723A38 802A12B8 46800020 */  cvt.s.w   $f0, $f0
/* 723A3C 802A12BC 44060000 */  mfc1      $a2, $f0
/* 723A40 802A12C0 44900000 */  mtc1      $s0, $f0
/* 723A44 802A12C4 00000000 */  nop       
/* 723A48 802A12C8 46800020 */  cvt.s.w   $f0, $f0
/* 723A4C 802A12CC 44070000 */  mfc1      $a3, $f0
/* 723A50 802A12D0 0000202D */  daddu     $a0, $zero, $zero
/* 723A54 802A12D4 0C01C424 */  jal       func_80071090
/* 723A58 802A12D8 AFA20010 */   sw       $v0, 0x10($sp)
/* 723A5C 802A12DC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 723A60 802A12E0 8FB30024 */  lw        $s3, 0x24($sp)
/* 723A64 802A12E4 8FB20020 */  lw        $s2, 0x20($sp)
/* 723A68 802A12E8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 723A6C 802A12EC 8FB00018 */  lw        $s0, 0x18($sp)
/* 723A70 802A12F0 24020002 */  addiu     $v0, $zero, 2
/* 723A74 802A12F4 03E00008 */  jr        $ra
/* 723A78 802A12F8 27BD0030 */   addiu    $sp, $sp, 0x30
