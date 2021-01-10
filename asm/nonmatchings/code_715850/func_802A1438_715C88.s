.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1438_715C88
/* 715C88 802A1438 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 715C8C 802A143C AFB1001C */  sw        $s1, 0x1c($sp)
/* 715C90 802A1440 0080882D */  daddu     $s1, $a0, $zero
/* 715C94 802A1444 AFBF0028 */  sw        $ra, 0x28($sp)
/* 715C98 802A1448 AFB30024 */  sw        $s3, 0x24($sp)
/* 715C9C 802A144C AFB20020 */  sw        $s2, 0x20($sp)
/* 715CA0 802A1450 AFB00018 */  sw        $s0, 0x18($sp)
/* 715CA4 802A1454 8E30000C */  lw        $s0, 0xc($s1)
/* 715CA8 802A1458 8E050000 */  lw        $a1, ($s0)
/* 715CAC 802A145C 0C0B1EAF */  jal       get_variable
/* 715CB0 802A1460 26100004 */   addiu    $s0, $s0, 4
/* 715CB4 802A1464 8E050000 */  lw        $a1, ($s0)
/* 715CB8 802A1468 26100004 */  addiu     $s0, $s0, 4
/* 715CBC 802A146C 0220202D */  daddu     $a0, $s1, $zero
/* 715CC0 802A1470 0C0B1EAF */  jal       get_variable
/* 715CC4 802A1474 0040982D */   daddu    $s3, $v0, $zero
/* 715CC8 802A1478 8E050000 */  lw        $a1, ($s0)
/* 715CCC 802A147C 26100004 */  addiu     $s0, $s0, 4
/* 715CD0 802A1480 0220202D */  daddu     $a0, $s1, $zero
/* 715CD4 802A1484 0C0B1EAF */  jal       get_variable
/* 715CD8 802A1488 0040902D */   daddu    $s2, $v0, $zero
/* 715CDC 802A148C 0220202D */  daddu     $a0, $s1, $zero
/* 715CE0 802A1490 8E050000 */  lw        $a1, ($s0)
/* 715CE4 802A1494 0C0B1EAF */  jal       get_variable
/* 715CE8 802A1498 0040802D */   daddu    $s0, $v0, $zero
/* 715CEC 802A149C 44930000 */  mtc1      $s3, $f0
/* 715CF0 802A14A0 00000000 */  nop       
/* 715CF4 802A14A4 46800020 */  cvt.s.w   $f0, $f0
/* 715CF8 802A14A8 44050000 */  mfc1      $a1, $f0
/* 715CFC 802A14AC 44920000 */  mtc1      $s2, $f0
/* 715D00 802A14B0 00000000 */  nop       
/* 715D04 802A14B4 46800020 */  cvt.s.w   $f0, $f0
/* 715D08 802A14B8 44060000 */  mfc1      $a2, $f0
/* 715D0C 802A14BC 44900000 */  mtc1      $s0, $f0
/* 715D10 802A14C0 00000000 */  nop       
/* 715D14 802A14C4 46800020 */  cvt.s.w   $f0, $f0
/* 715D18 802A14C8 44070000 */  mfc1      $a3, $f0
/* 715D1C 802A14CC 24040001 */  addiu     $a0, $zero, 1
/* 715D20 802A14D0 0C01C424 */  jal       func_80071090
/* 715D24 802A14D4 AFA20010 */   sw       $v0, 0x10($sp)
/* 715D28 802A14D8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 715D2C 802A14DC 8FB30024 */  lw        $s3, 0x24($sp)
/* 715D30 802A14E0 8FB20020 */  lw        $s2, 0x20($sp)
/* 715D34 802A14E4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 715D38 802A14E8 8FB00018 */  lw        $s0, 0x18($sp)
/* 715D3C 802A14EC 24020002 */  addiu     $v0, $zero, 2
/* 715D40 802A14F0 03E00008 */  jr        $ra
/* 715D44 802A14F4 27BD0030 */   addiu    $sp, $sp, 0x30
