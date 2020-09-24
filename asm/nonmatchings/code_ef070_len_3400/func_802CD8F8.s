.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CD8F8
/* F22A8 802CD8F8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F22AC 802CD8FC AFB20018 */  sw        $s2, 0x18($sp)
/* F22B0 802CD900 0080902D */  daddu     $s2, $a0, $zero
/* F22B4 802CD904 AFBF0028 */  sw        $ra, 0x28($sp)
/* F22B8 802CD908 AFB50024 */  sw        $s5, 0x24($sp)
/* F22BC 802CD90C AFB40020 */  sw        $s4, 0x20($sp)
/* F22C0 802CD910 AFB3001C */  sw        $s3, 0x1c($sp)
/* F22C4 802CD914 AFB10014 */  sw        $s1, 0x14($sp)
/* F22C8 802CD918 AFB00010 */  sw        $s0, 0x10($sp)
/* F22CC 802CD91C 8E50000C */  lw        $s0, 0xc($s2)
/* F22D0 802CD920 8E050000 */  lw        $a1, ($s0)
/* F22D4 802CD924 0C0B1EAF */  jal       get_variable
/* F22D8 802CD928 26100004 */   addiu    $s0, $s0, 4
/* F22DC 802CD92C 8E050000 */  lw        $a1, ($s0)
/* F22E0 802CD930 26100004 */  addiu     $s0, $s0, 4
/* F22E4 802CD934 0240202D */  daddu     $a0, $s2, $zero
/* F22E8 802CD938 0C0B1EAF */  jal       get_variable
/* F22EC 802CD93C 0040882D */   daddu    $s1, $v0, $zero
/* F22F0 802CD940 00118880 */  sll       $s1, $s1, 2
/* F22F4 802CD944 8E130000 */  lw        $s3, ($s0)
/* F22F8 802CD948 26100004 */  addiu     $s0, $s0, 4
/* F22FC 802CD94C 3C03802E */  lui       $v1, 0x802e
/* F2300 802CD950 8C63AE30 */  lw        $v1, -0x51d0($v1)
/* F2304 802CD954 8E140000 */  lw        $s4, ($s0)
/* F2308 802CD958 02238821 */  addu      $s1, $s1, $v1
/* F230C 802CD95C 8E230000 */  lw        $v1, ($s1)
/* F2310 802CD960 8E150004 */  lw        $s5, 4($s0)
/* F2314 802CD964 8C640000 */  lw        $a0, ($v1)
/* F2318 802CD968 0C047FF8 */  jal       func_8011FFE0
/* F231C 802CD96C 0040882D */   daddu    $s1, $v0, $zero
/* F2320 802CD970 0040202D */  daddu     $a0, $v0, $zero
/* F2324 802CD974 0C047FDD */  jal       func_8011FF74
/* F2328 802CD978 0220282D */   daddu    $a1, $s1, $zero
/* F232C 802CD97C 0240202D */  daddu     $a0, $s2, $zero
/* F2330 802CD980 0040802D */  daddu     $s0, $v0, $zero
/* F2334 802CD984 C600009C */  lwc1      $f0, 0x9c($s0)
/* F2338 802CD988 4600008D */  trunc.w.s $f2, $f0
/* F233C 802CD98C 44061000 */  mfc1      $a2, $f2
/* F2340 802CD990 0C0B2026 */  jal       set_variable
/* F2344 802CD994 0260282D */   daddu    $a1, $s3, $zero
/* F2348 802CD998 0240202D */  daddu     $a0, $s2, $zero
/* F234C 802CD99C C60000A0 */  lwc1      $f0, 0xa0($s0)
/* F2350 802CD9A0 4600008D */  trunc.w.s $f2, $f0
/* F2354 802CD9A4 44061000 */  mfc1      $a2, $f2
/* F2358 802CD9A8 0C0B2026 */  jal       set_variable
/* F235C 802CD9AC 0280282D */   daddu    $a1, $s4, $zero
/* F2360 802CD9B0 0240202D */  daddu     $a0, $s2, $zero
/* F2364 802CD9B4 C60000A4 */  lwc1      $f0, 0xa4($s0)
/* F2368 802CD9B8 4600008D */  trunc.w.s $f2, $f0
/* F236C 802CD9BC 44061000 */  mfc1      $a2, $f2
/* F2370 802CD9C0 0C0B2026 */  jal       set_variable
/* F2374 802CD9C4 02A0282D */   daddu    $a1, $s5, $zero
/* F2378 802CD9C8 8FBF0028 */  lw        $ra, 0x28($sp)
/* F237C 802CD9CC 8FB50024 */  lw        $s5, 0x24($sp)
/* F2380 802CD9D0 8FB40020 */  lw        $s4, 0x20($sp)
/* F2384 802CD9D4 8FB3001C */  lw        $s3, 0x1c($sp)
/* F2388 802CD9D8 8FB20018 */  lw        $s2, 0x18($sp)
/* F238C 802CD9DC 8FB10014 */  lw        $s1, 0x14($sp)
/* F2390 802CD9E0 8FB00010 */  lw        $s0, 0x10($sp)
/* F2394 802CD9E4 24020002 */  addiu     $v0, $zero, 2
/* F2398 802CD9E8 03E00008 */  jr        $ra
/* F239C 802CD9EC 27BD0030 */   addiu    $sp, $sp, 0x30
