.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1418_7250F8
/* 7250F8 802A1418 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 7250FC 802A141C AFB1001C */  sw        $s1, 0x1c($sp)
/* 725100 802A1420 0080882D */  daddu     $s1, $a0, $zero
/* 725104 802A1424 AFBF0028 */  sw        $ra, 0x28($sp)
/* 725108 802A1428 AFB30024 */  sw        $s3, 0x24($sp)
/* 72510C 802A142C AFB20020 */  sw        $s2, 0x20($sp)
/* 725110 802A1430 AFB00018 */  sw        $s0, 0x18($sp)
/* 725114 802A1434 8E30000C */  lw        $s0, 0xc($s1)
/* 725118 802A1438 8E050000 */  lw        $a1, ($s0)
/* 72511C 802A143C 0C0B1EAF */  jal       get_variable
/* 725120 802A1440 26100004 */   addiu    $s0, $s0, 4
/* 725124 802A1444 8E050000 */  lw        $a1, ($s0)
/* 725128 802A1448 26100004 */  addiu     $s0, $s0, 4
/* 72512C 802A144C 0220202D */  daddu     $a0, $s1, $zero
/* 725130 802A1450 0C0B1EAF */  jal       get_variable
/* 725134 802A1454 0040982D */   daddu    $s3, $v0, $zero
/* 725138 802A1458 8E050000 */  lw        $a1, ($s0)
/* 72513C 802A145C 26100004 */  addiu     $s0, $s0, 4
/* 725140 802A1460 0220202D */  daddu     $a0, $s1, $zero
/* 725144 802A1464 0C0B1EAF */  jal       get_variable
/* 725148 802A1468 0040902D */   daddu    $s2, $v0, $zero
/* 72514C 802A146C 0220202D */  daddu     $a0, $s1, $zero
/* 725150 802A1470 8E050000 */  lw        $a1, ($s0)
/* 725154 802A1474 0C0B1EAF */  jal       get_variable
/* 725158 802A1478 0040802D */   daddu    $s0, $v0, $zero
/* 72515C 802A147C 44930000 */  mtc1      $s3, $f0
/* 725160 802A1480 00000000 */  nop       
/* 725164 802A1484 46800020 */  cvt.s.w   $f0, $f0
/* 725168 802A1488 44050000 */  mfc1      $a1, $f0
/* 72516C 802A148C 44920000 */  mtc1      $s2, $f0
/* 725170 802A1490 00000000 */  nop       
/* 725174 802A1494 46800020 */  cvt.s.w   $f0, $f0
/* 725178 802A1498 44060000 */  mfc1      $a2, $f0
/* 72517C 802A149C 44900000 */  mtc1      $s0, $f0
/* 725180 802A14A0 00000000 */  nop       
/* 725184 802A14A4 46800020 */  cvt.s.w   $f0, $f0
/* 725188 802A14A8 44070000 */  mfc1      $a3, $f0
/* 72518C 802A14AC 24040001 */  addiu     $a0, $zero, 1
/* 725190 802A14B0 0C01C424 */  jal       func_80071090
/* 725194 802A14B4 AFA20010 */   sw       $v0, 0x10($sp)
/* 725198 802A14B8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 72519C 802A14BC 8FB30024 */  lw        $s3, 0x24($sp)
/* 7251A0 802A14C0 8FB20020 */  lw        $s2, 0x20($sp)
/* 7251A4 802A14C4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7251A8 802A14C8 8FB00018 */  lw        $s0, 0x18($sp)
/* 7251AC 802A14CC 24020002 */  addiu     $v0, $zero, 2
/* 7251B0 802A14D0 03E00008 */  jr        $ra
/* 7251B4 802A14D4 27BD0030 */   addiu    $sp, $sp, 0x30
