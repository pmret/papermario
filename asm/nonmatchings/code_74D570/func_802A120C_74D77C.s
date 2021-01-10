.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A120C_74D77C
/* 74D77C 802A120C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 74D780 802A1210 AFB1001C */  sw        $s1, 0x1c($sp)
/* 74D784 802A1214 0080882D */  daddu     $s1, $a0, $zero
/* 74D788 802A1218 AFBF0028 */  sw        $ra, 0x28($sp)
/* 74D78C 802A121C AFB30024 */  sw        $s3, 0x24($sp)
/* 74D790 802A1220 AFB20020 */  sw        $s2, 0x20($sp)
/* 74D794 802A1224 AFB00018 */  sw        $s0, 0x18($sp)
/* 74D798 802A1228 8E30000C */  lw        $s0, 0xc($s1)
/* 74D79C 802A122C 8E050000 */  lw        $a1, ($s0)
/* 74D7A0 802A1230 0C0B1EAF */  jal       get_variable
/* 74D7A4 802A1234 26100004 */   addiu    $s0, $s0, 4
/* 74D7A8 802A1238 8E050000 */  lw        $a1, ($s0)
/* 74D7AC 802A123C 26100004 */  addiu     $s0, $s0, 4
/* 74D7B0 802A1240 0220202D */  daddu     $a0, $s1, $zero
/* 74D7B4 802A1244 0C0B1EAF */  jal       get_variable
/* 74D7B8 802A1248 0040982D */   daddu    $s3, $v0, $zero
/* 74D7BC 802A124C 8E050000 */  lw        $a1, ($s0)
/* 74D7C0 802A1250 26100004 */  addiu     $s0, $s0, 4
/* 74D7C4 802A1254 0220202D */  daddu     $a0, $s1, $zero
/* 74D7C8 802A1258 0C0B1EAF */  jal       get_variable
/* 74D7CC 802A125C 0040902D */   daddu    $s2, $v0, $zero
/* 74D7D0 802A1260 0220202D */  daddu     $a0, $s1, $zero
/* 74D7D4 802A1264 8E050000 */  lw        $a1, ($s0)
/* 74D7D8 802A1268 0C0B210B */  jal       get_float_variable
/* 74D7DC 802A126C 0040802D */   daddu    $s0, $v0, $zero
/* 74D7E0 802A1270 24040006 */  addiu     $a0, $zero, 6
/* 74D7E4 802A1274 2673000A */  addiu     $s3, $s3, 0xa
/* 74D7E8 802A1278 44931000 */  mtc1      $s3, $f2
/* 74D7EC 802A127C 00000000 */  nop       
/* 74D7F0 802A1280 468010A0 */  cvt.s.w   $f2, $f2
/* 74D7F4 802A1284 26520012 */  addiu     $s2, $s2, 0x12
/* 74D7F8 802A1288 44051000 */  mfc1      $a1, $f2
/* 74D7FC 802A128C 44921000 */  mtc1      $s2, $f2
/* 74D800 802A1290 00000000 */  nop       
/* 74D804 802A1294 468010A0 */  cvt.s.w   $f2, $f2
/* 74D808 802A1298 44061000 */  mfc1      $a2, $f2
/* 74D80C 802A129C 44901000 */  mtc1      $s0, $f2
/* 74D810 802A12A0 00000000 */  nop       
/* 74D814 802A12A4 468010A0 */  cvt.s.w   $f2, $f2
/* 74D818 802A12A8 44071000 */  mfc1      $a3, $f2
/* 74D81C 802A12AC 2402002D */  addiu     $v0, $zero, 0x2d
/* 74D820 802A12B0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 74D824 802A12B4 0C01C82C */  jal       func_800720B0
/* 74D828 802A12B8 AFA20014 */   sw       $v0, 0x14($sp)
/* 74D82C 802A12BC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 74D830 802A12C0 8FB30024 */  lw        $s3, 0x24($sp)
/* 74D834 802A12C4 8FB20020 */  lw        $s2, 0x20($sp)
/* 74D838 802A12C8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 74D83C 802A12CC 8FB00018 */  lw        $s0, 0x18($sp)
/* 74D840 802A12D0 24020002 */  addiu     $v0, $zero, 2
/* 74D844 802A12D4 03E00008 */  jr        $ra
/* 74D848 802A12D8 27BD0030 */   addiu    $sp, $sp, 0x30
/* 74D84C 802A12DC 00000000 */  nop       
