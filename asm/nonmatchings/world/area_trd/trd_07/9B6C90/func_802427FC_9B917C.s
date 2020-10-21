.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427FC_9B917C
/* 9B917C 802427FC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 9B9180 80242800 AFB1001C */  sw        $s1, 0x1c($sp)
/* 9B9184 80242804 0080882D */  daddu     $s1, $a0, $zero
/* 9B9188 80242808 AFBF0028 */  sw        $ra, 0x28($sp)
/* 9B918C 8024280C AFB30024 */  sw        $s3, 0x24($sp)
/* 9B9190 80242810 AFB20020 */  sw        $s2, 0x20($sp)
/* 9B9194 80242814 AFB00018 */  sw        $s0, 0x18($sp)
/* 9B9198 80242818 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 9B919C 8024281C 8E30000C */  lw        $s0, 0xc($s1)
/* 9B91A0 80242820 8E050000 */  lw        $a1, ($s0)
/* 9B91A4 80242824 0C0B1EAF */  jal       get_variable
/* 9B91A8 80242828 26100004 */   addiu    $s0, $s0, 4
/* 9B91AC 8024282C 8E050000 */  lw        $a1, ($s0)
/* 9B91B0 80242830 26100004 */  addiu     $s0, $s0, 4
/* 9B91B4 80242834 0220202D */  daddu     $a0, $s1, $zero
/* 9B91B8 80242838 0C0B1EAF */  jal       get_variable
/* 9B91BC 8024283C 0040982D */   daddu    $s3, $v0, $zero
/* 9B91C0 80242840 8E050000 */  lw        $a1, ($s0)
/* 9B91C4 80242844 26100004 */  addiu     $s0, $s0, 4
/* 9B91C8 80242848 0220202D */  daddu     $a0, $s1, $zero
/* 9B91CC 8024284C 0C0B1EAF */  jal       get_variable
/* 9B91D0 80242850 0040902D */   daddu    $s2, $v0, $zero
/* 9B91D4 80242854 0220202D */  daddu     $a0, $s1, $zero
/* 9B91D8 80242858 8E050000 */  lw        $a1, ($s0)
/* 9B91DC 8024285C 0C0B1EAF */  jal       get_variable
/* 9B91E0 80242860 0040802D */   daddu    $s0, $v0, $zero
/* 9B91E4 80242864 4482A000 */  mtc1      $v0, $f20
/* 9B91E8 80242868 00000000 */  nop       
/* 9B91EC 8024286C 4680A520 */  cvt.s.w   $f20, $f20
/* 9B91F0 80242870 0C00A8BB */  jal       sin_deg
/* 9B91F4 80242874 4600A306 */   mov.s    $f12, $f20
/* 9B91F8 80242878 4600A306 */  mov.s     $f12, $f20
/* 9B91FC 8024287C 0C00A8D4 */  jal       cos_deg
/* 9B9200 80242880 46000506 */   mov.s    $f20, $f0
/* 9B9204 80242884 24040001 */  addiu     $a0, $zero, 1
/* 9B9208 80242888 44931000 */  mtc1      $s3, $f2
/* 9B920C 8024288C 00000000 */  nop       
/* 9B9210 80242890 468010A0 */  cvt.s.w   $f2, $f2
/* 9B9214 80242894 2652000A */  addiu     $s2, $s2, 0xa
/* 9B9218 80242898 44051000 */  mfc1      $a1, $f2
/* 9B921C 8024289C 44921000 */  mtc1      $s2, $f2
/* 9B9220 802428A0 00000000 */  nop       
/* 9B9224 802428A4 468010A0 */  cvt.s.w   $f2, $f2
/* 9B9228 802428A8 44061000 */  mfc1      $a2, $f2
/* 9B922C 802428AC 44901000 */  mtc1      $s0, $f2
/* 9B9230 802428B0 00000000 */  nop       
/* 9B9234 802428B4 468010A0 */  cvt.s.w   $f2, $f2
/* 9B9238 802428B8 44071000 */  mfc1      $a3, $f2
/* 9B923C 802428BC 46000007 */  neg.s     $f0, $f0
/* 9B9240 802428C0 E7B40010 */  swc1      $f20, 0x10($sp)
/* 9B9244 802428C4 0C01BECC */  jal       fx_walk_normal
/* 9B9248 802428C8 E7A00014 */   swc1     $f0, 0x14($sp)
/* 9B924C 802428CC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 9B9250 802428D0 8FB30024 */  lw        $s3, 0x24($sp)
/* 9B9254 802428D4 8FB20020 */  lw        $s2, 0x20($sp)
/* 9B9258 802428D8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 9B925C 802428DC 8FB00018 */  lw        $s0, 0x18($sp)
/* 9B9260 802428E0 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 9B9264 802428E4 24020002 */  addiu     $v0, $zero, 2
/* 9B9268 802428E8 03E00008 */  jr        $ra
/* 9B926C 802428EC 27BD0038 */   addiu    $sp, $sp, 0x38
