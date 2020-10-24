.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F80_96A140
/* 96A140 80240F80 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 96A144 80240F84 AFB20018 */  sw        $s2, 0x18($sp)
/* 96A148 80240F88 0080902D */  daddu     $s2, $a0, $zero
/* 96A14C 80240F8C AFBF0030 */  sw        $ra, 0x30($sp)
/* 96A150 80240F90 AFB7002C */  sw        $s7, 0x2c($sp)
/* 96A154 80240F94 AFB60028 */  sw        $s6, 0x28($sp)
/* 96A158 80240F98 AFB50024 */  sw        $s5, 0x24($sp)
/* 96A15C 80240F9C AFB40020 */  sw        $s4, 0x20($sp)
/* 96A160 80240FA0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 96A164 80240FA4 AFB10014 */  sw        $s1, 0x14($sp)
/* 96A168 80240FA8 AFB00010 */  sw        $s0, 0x10($sp)
/* 96A16C 80240FAC F7B60040 */  sdc1      $f22, 0x40($sp)
/* 96A170 80240FB0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 96A174 80240FB4 8E50000C */  lw        $s0, 0xc($s2)
/* 96A178 80240FB8 8E050000 */  lw        $a1, ($s0)
/* 96A17C 80240FBC 0C0B1EAF */  jal       get_variable
/* 96A180 80240FC0 26100004 */   addiu    $s0, $s0, 4
/* 96A184 80240FC4 8E050000 */  lw        $a1, ($s0)
/* 96A188 80240FC8 26100004 */  addiu     $s0, $s0, 4
/* 96A18C 80240FCC 0240202D */  daddu     $a0, $s2, $zero
/* 96A190 80240FD0 0C0B1EAF */  jal       get_variable
/* 96A194 80240FD4 0040B82D */   daddu    $s7, $v0, $zero
/* 96A198 80240FD8 8E050000 */  lw        $a1, ($s0)
/* 96A19C 80240FDC 26100004 */  addiu     $s0, $s0, 4
/* 96A1A0 80240FE0 0240202D */  daddu     $a0, $s2, $zero
/* 96A1A4 80240FE4 0C0B1EAF */  jal       get_variable
/* 96A1A8 80240FE8 0040B02D */   daddu    $s6, $v0, $zero
/* 96A1AC 80240FEC 0240202D */  daddu     $a0, $s2, $zero
/* 96A1B0 80240FF0 3C05F4AC */  lui       $a1, 0xf4ac
/* 96A1B4 80240FF4 34A5D481 */  ori       $a1, $a1, 0xd481
/* 96A1B8 80240FF8 3C068007 */  lui       $a2, %hi(gCurrentCameraID)
/* 96A1BC 80240FFC 8CC67410 */  lw        $a2, %lo(gCurrentCameraID)($a2)
/* 96A1C0 80241000 8E140000 */  lw        $s4, ($s0)
/* 96A1C4 80241004 00061880 */  sll       $v1, $a2, 2
/* 96A1C8 80241008 00661821 */  addu      $v1, $v1, $a2
/* 96A1CC 8024100C 00031880 */  sll       $v1, $v1, 2
/* 96A1D0 80241010 00661823 */  subu      $v1, $v1, $a2
/* 96A1D4 80241014 000330C0 */  sll       $a2, $v1, 3
/* 96A1D8 80241018 00661821 */  addu      $v1, $v1, $a2
/* 96A1DC 8024101C 000318C0 */  sll       $v1, $v1, 3
/* 96A1E0 80241020 3C01800B */  lui       $at, 0x800b
/* 96A1E4 80241024 00230821 */  addu      $at, $at, $v1
/* 96A1E8 80241028 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 96A1EC 8024102C 8E150004 */  lw        $s5, 4($s0)
/* 96A1F0 80241030 4600010D */  trunc.w.s $f4, $f0
/* 96A1F4 80241034 44112000 */  mfc1      $s1, $f4
/* 96A1F8 80241038 0C0B1EAF */  jal       get_variable
/* 96A1FC 8024103C 0040982D */   daddu    $s3, $v0, $zero
/* 96A200 80241040 4491B000 */  mtc1      $s1, $f22
/* 96A204 80241044 00000000 */  nop       
/* 96A208 80241048 4680B5A0 */  cvt.s.w   $f22, $f22
/* 96A20C 8024104C 4600B306 */  mov.s     $f12, $f22
/* 96A210 80241050 0C00A8D4 */  jal       cos_deg
/* 96A214 80241054 0040802D */   daddu    $s0, $v0, $zero
/* 96A218 80241058 4493A000 */  mtc1      $s3, $f20
/* 96A21C 8024105C 00000000 */  nop       
/* 96A220 80241060 4680A520 */  cvt.s.w   $f20, $f20
/* 96A224 80241064 4600A002 */  mul.s     $f0, $f20, $f0
/* 96A228 80241068 00000000 */  nop       
/* 96A22C 8024106C 0240202D */  daddu     $a0, $s2, $zero
/* 96A230 80241070 44901000 */  mtc1      $s0, $f2
/* 96A234 80241074 00000000 */  nop       
/* 96A238 80241078 468010A0 */  cvt.s.w   $f2, $f2
/* 96A23C 8024107C 46001081 */  sub.s     $f2, $f2, $f0
/* 96A240 80241080 3C05F4AC */  lui       $a1, 0xf4ac
/* 96A244 80241084 4600110D */  trunc.w.s $f4, $f2
/* 96A248 80241088 44102000 */  mfc1      $s0, $f4
/* 96A24C 8024108C 0C0B1EAF */  jal       get_variable
/* 96A250 80241090 34A5D483 */   ori      $a1, $a1, 0xd483
/* 96A254 80241094 4600B306 */  mov.s     $f12, $f22
/* 96A258 80241098 0C00A8BB */  jal       sin_deg
/* 96A25C 8024109C 0040882D */   daddu    $s1, $v0, $zero
/* 96A260 802410A0 4600A502 */  mul.s     $f20, $f20, $f0
/* 96A264 802410A4 00000000 */  nop       
/* 96A268 802410A8 0240202D */  daddu     $a0, $s2, $zero
/* 96A26C 802410AC 44910000 */  mtc1      $s1, $f0
/* 96A270 802410B0 00000000 */  nop       
/* 96A274 802410B4 46800020 */  cvt.s.w   $f0, $f0
/* 96A278 802410B8 46140001 */  sub.s     $f0, $f0, $f20
/* 96A27C 802410BC 0280282D */  daddu     $a1, $s4, $zero
/* 96A280 802410C0 02173023 */  subu      $a2, $s0, $s7
/* 96A284 802410C4 4600010D */  trunc.w.s $f4, $f0
/* 96A288 802410C8 44102000 */  mfc1      $s0, $f4
/* 96A28C 802410CC 0C0B2026 */  jal       set_variable
/* 96A290 802410D0 02168023 */   subu     $s0, $s0, $s6
/* 96A294 802410D4 0240202D */  daddu     $a0, $s2, $zero
/* 96A298 802410D8 02A0282D */  daddu     $a1, $s5, $zero
/* 96A29C 802410DC 0C0B2026 */  jal       set_variable
/* 96A2A0 802410E0 0200302D */   daddu    $a2, $s0, $zero
/* 96A2A4 802410E4 8FBF0030 */  lw        $ra, 0x30($sp)
/* 96A2A8 802410E8 8FB7002C */  lw        $s7, 0x2c($sp)
/* 96A2AC 802410EC 8FB60028 */  lw        $s6, 0x28($sp)
/* 96A2B0 802410F0 8FB50024 */  lw        $s5, 0x24($sp)
/* 96A2B4 802410F4 8FB40020 */  lw        $s4, 0x20($sp)
/* 96A2B8 802410F8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 96A2BC 802410FC 8FB20018 */  lw        $s2, 0x18($sp)
/* 96A2C0 80241100 8FB10014 */  lw        $s1, 0x14($sp)
/* 96A2C4 80241104 8FB00010 */  lw        $s0, 0x10($sp)
/* 96A2C8 80241108 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 96A2CC 8024110C D7B40038 */  ldc1      $f20, 0x38($sp)
/* 96A2D0 80241110 24020002 */  addiu     $v0, $zero, 2
/* 96A2D4 80241114 03E00008 */  jr        $ra
/* 96A2D8 80241118 27BD0048 */   addiu    $sp, $sp, 0x48
