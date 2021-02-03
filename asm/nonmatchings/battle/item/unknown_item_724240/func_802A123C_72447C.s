.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_72447C
/* 72447C 802A123C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 724480 802A1240 AFB1001C */  sw        $s1, 0x1c($sp)
/* 724484 802A1244 0080882D */  daddu     $s1, $a0, $zero
/* 724488 802A1248 AFBF0028 */  sw        $ra, 0x28($sp)
/* 72448C 802A124C AFB30024 */  sw        $s3, 0x24($sp)
/* 724490 802A1250 AFB20020 */  sw        $s2, 0x20($sp)
/* 724494 802A1254 AFB00018 */  sw        $s0, 0x18($sp)
/* 724498 802A1258 8E30000C */  lw        $s0, 0xc($s1)
/* 72449C 802A125C 8E050000 */  lw        $a1, ($s0)
/* 7244A0 802A1260 0C0B1EAF */  jal       get_variable
/* 7244A4 802A1264 26100004 */   addiu    $s0, $s0, 4
/* 7244A8 802A1268 8E050000 */  lw        $a1, ($s0)
/* 7244AC 802A126C 26100004 */  addiu     $s0, $s0, 4
/* 7244B0 802A1270 0220202D */  daddu     $a0, $s1, $zero
/* 7244B4 802A1274 0C0B1EAF */  jal       get_variable
/* 7244B8 802A1278 0040982D */   daddu    $s3, $v0, $zero
/* 7244BC 802A127C 8E050000 */  lw        $a1, ($s0)
/* 7244C0 802A1280 26100004 */  addiu     $s0, $s0, 4
/* 7244C4 802A1284 0220202D */  daddu     $a0, $s1, $zero
/* 7244C8 802A1288 0C0B1EAF */  jal       get_variable
/* 7244CC 802A128C 0040902D */   daddu    $s2, $v0, $zero
/* 7244D0 802A1290 0220202D */  daddu     $a0, $s1, $zero
/* 7244D4 802A1294 8E050000 */  lw        $a1, ($s0)
/* 7244D8 802A1298 0C0B1EAF */  jal       get_variable
/* 7244DC 802A129C 0040802D */   daddu    $s0, $v0, $zero
/* 7244E0 802A12A0 44930000 */  mtc1      $s3, $f0
/* 7244E4 802A12A4 00000000 */  nop
/* 7244E8 802A12A8 46800020 */  cvt.s.w   $f0, $f0
/* 7244EC 802A12AC 44050000 */  mfc1      $a1, $f0
/* 7244F0 802A12B0 44920000 */  mtc1      $s2, $f0
/* 7244F4 802A12B4 00000000 */  nop
/* 7244F8 802A12B8 46800020 */  cvt.s.w   $f0, $f0
/* 7244FC 802A12BC 44060000 */  mfc1      $a2, $f0
/* 724500 802A12C0 44900000 */  mtc1      $s0, $f0
/* 724504 802A12C4 00000000 */  nop
/* 724508 802A12C8 46800020 */  cvt.s.w   $f0, $f0
/* 72450C 802A12CC 44070000 */  mfc1      $a3, $f0
/* 724510 802A12D0 0000202D */  daddu     $a0, $zero, $zero
/* 724514 802A12D4 0C01C424 */  jal       func_80071090
/* 724518 802A12D8 AFA20010 */   sw       $v0, 0x10($sp)
/* 72451C 802A12DC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 724520 802A12E0 8FB30024 */  lw        $s3, 0x24($sp)
/* 724524 802A12E4 8FB20020 */  lw        $s2, 0x20($sp)
/* 724528 802A12E8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 72452C 802A12EC 8FB00018 */  lw        $s0, 0x18($sp)
/* 724530 802A12F0 24020002 */  addiu     $v0, $zero, 2
/* 724534 802A12F4 03E00008 */  jr        $ra
/* 724538 802A12F8 27BD0030 */   addiu    $sp, $sp, 0x30
