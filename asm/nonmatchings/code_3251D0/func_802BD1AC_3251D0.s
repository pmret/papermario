.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD1AC_3251D0
/* 32527C 802BD1AC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 325280 802BD1B0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 325284 802BD1B4 0080882D */  daddu     $s1, $a0, $zero
/* 325288 802BD1B8 AFBF0028 */  sw        $ra, 0x28($sp)
/* 32528C 802BD1BC AFB30024 */  sw        $s3, 0x24($sp)
/* 325290 802BD1C0 AFB20020 */  sw        $s2, 0x20($sp)
/* 325294 802BD1C4 AFB00018 */  sw        $s0, 0x18($sp)
/* 325298 802BD1C8 8E30000C */  lw        $s0, 0xc($s1)
/* 32529C 802BD1CC 8E050000 */  lw        $a1, ($s0)
/* 3252A0 802BD1D0 0C0B1EAF */  jal       get_variable
/* 3252A4 802BD1D4 26100004 */   addiu    $s0, $s0, 4
/* 3252A8 802BD1D8 8E050000 */  lw        $a1, ($s0)
/* 3252AC 802BD1DC 26100004 */  addiu     $s0, $s0, 4
/* 3252B0 802BD1E0 0220202D */  daddu     $a0, $s1, $zero
/* 3252B4 802BD1E4 0C0B1EAF */  jal       get_variable
/* 3252B8 802BD1E8 0040982D */   daddu    $s3, $v0, $zero
/* 3252BC 802BD1EC 8E050000 */  lw        $a1, ($s0)
/* 3252C0 802BD1F0 26100004 */  addiu     $s0, $s0, 4
/* 3252C4 802BD1F4 0220202D */  daddu     $a0, $s1, $zero
/* 3252C8 802BD1F8 0C0B1EAF */  jal       get_variable
/* 3252CC 802BD1FC 0040902D */   daddu    $s2, $v0, $zero
/* 3252D0 802BD200 0220202D */  daddu     $a0, $s1, $zero
/* 3252D4 802BD204 8E050000 */  lw        $a1, ($s0)
/* 3252D8 802BD208 0C0B1EAF */  jal       get_variable
/* 3252DC 802BD20C 0040802D */   daddu    $s0, $v0, $zero
/* 3252E0 802BD210 44930000 */  mtc1      $s3, $f0
/* 3252E4 802BD214 00000000 */  nop       
/* 3252E8 802BD218 46800020 */  cvt.s.w   $f0, $f0
/* 3252EC 802BD21C 44050000 */  mfc1      $a1, $f0
/* 3252F0 802BD220 44920000 */  mtc1      $s2, $f0
/* 3252F4 802BD224 00000000 */  nop       
/* 3252F8 802BD228 46800020 */  cvt.s.w   $f0, $f0
/* 3252FC 802BD22C 44060000 */  mfc1      $a2, $f0
/* 325300 802BD230 44900000 */  mtc1      $s0, $f0
/* 325304 802BD234 00000000 */  nop       
/* 325308 802BD238 46800020 */  cvt.s.w   $f0, $f0
/* 32530C 802BD23C 44070000 */  mfc1      $a3, $f0
/* 325310 802BD240 0000202D */  daddu     $a0, $zero, $zero
/* 325314 802BD244 0C01C424 */  jal       func_80071090
/* 325318 802BD248 AFA20010 */   sw       $v0, 0x10($sp)
/* 32531C 802BD24C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 325320 802BD250 8FB30024 */  lw        $s3, 0x24($sp)
/* 325324 802BD254 8FB20020 */  lw        $s2, 0x20($sp)
/* 325328 802BD258 8FB1001C */  lw        $s1, 0x1c($sp)
/* 32532C 802BD25C 8FB00018 */  lw        $s0, 0x18($sp)
/* 325330 802BD260 24020002 */  addiu     $v0, $zero, 2
/* 325334 802BD264 03E00008 */  jr        $ra
/* 325338 802BD268 27BD0030 */   addiu    $sp, $sp, 0x30
