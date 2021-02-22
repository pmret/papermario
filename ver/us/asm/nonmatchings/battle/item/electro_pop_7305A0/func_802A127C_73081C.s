.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A127C_73081C
/* 73081C 802A127C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 730820 802A1280 AFB1001C */  sw        $s1, 0x1c($sp)
/* 730824 802A1284 0080882D */  daddu     $s1, $a0, $zero
/* 730828 802A1288 AFBF0028 */  sw        $ra, 0x28($sp)
/* 73082C 802A128C AFB30024 */  sw        $s3, 0x24($sp)
/* 730830 802A1290 AFB20020 */  sw        $s2, 0x20($sp)
/* 730834 802A1294 AFB00018 */  sw        $s0, 0x18($sp)
/* 730838 802A1298 8E30000C */  lw        $s0, 0xc($s1)
/* 73083C 802A129C 8E050000 */  lw        $a1, ($s0)
/* 730840 802A12A0 0C0B1EAF */  jal       get_variable
/* 730844 802A12A4 26100004 */   addiu    $s0, $s0, 4
/* 730848 802A12A8 8E050000 */  lw        $a1, ($s0)
/* 73084C 802A12AC 26100004 */  addiu     $s0, $s0, 4
/* 730850 802A12B0 0220202D */  daddu     $a0, $s1, $zero
/* 730854 802A12B4 0C0B1EAF */  jal       get_variable
/* 730858 802A12B8 0040982D */   daddu    $s3, $v0, $zero
/* 73085C 802A12BC 8E050000 */  lw        $a1, ($s0)
/* 730860 802A12C0 26100004 */  addiu     $s0, $s0, 4
/* 730864 802A12C4 0220202D */  daddu     $a0, $s1, $zero
/* 730868 802A12C8 0C0B1EAF */  jal       get_variable
/* 73086C 802A12CC 0040902D */   daddu    $s2, $v0, $zero
/* 730870 802A12D0 0220202D */  daddu     $a0, $s1, $zero
/* 730874 802A12D4 8E050000 */  lw        $a1, ($s0)
/* 730878 802A12D8 0C0B1EAF */  jal       get_variable
/* 73087C 802A12DC 0040802D */   daddu    $s0, $v0, $zero
/* 730880 802A12E0 44930000 */  mtc1      $s3, $f0
/* 730884 802A12E4 00000000 */  nop
/* 730888 802A12E8 46800020 */  cvt.s.w   $f0, $f0
/* 73088C 802A12EC 44050000 */  mfc1      $a1, $f0
/* 730890 802A12F0 44920000 */  mtc1      $s2, $f0
/* 730894 802A12F4 00000000 */  nop
/* 730898 802A12F8 46800020 */  cvt.s.w   $f0, $f0
/* 73089C 802A12FC 44060000 */  mfc1      $a2, $f0
/* 7308A0 802A1300 44900000 */  mtc1      $s0, $f0
/* 7308A4 802A1304 00000000 */  nop
/* 7308A8 802A1308 46800020 */  cvt.s.w   $f0, $f0
/* 7308AC 802A130C 44070000 */  mfc1      $a3, $f0
/* 7308B0 802A1310 0000202D */  daddu     $a0, $zero, $zero
/* 7308B4 802A1314 0C01C424 */  jal       func_80071090
/* 7308B8 802A1318 AFA20010 */   sw       $v0, 0x10($sp)
/* 7308BC 802A131C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 7308C0 802A1320 8FB30024 */  lw        $s3, 0x24($sp)
/* 7308C4 802A1324 8FB20020 */  lw        $s2, 0x20($sp)
/* 7308C8 802A1328 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7308CC 802A132C 8FB00018 */  lw        $s0, 0x18($sp)
/* 7308D0 802A1330 24020002 */  addiu     $v0, $zero, 2
/* 7308D4 802A1334 03E00008 */  jr        $ra
/* 7308D8 802A1338 27BD0030 */   addiu    $sp, $sp, 0x30
