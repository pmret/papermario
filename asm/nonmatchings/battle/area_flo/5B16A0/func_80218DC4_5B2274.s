.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218DC4_5B2274
/* 5B2274 80218DC4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5B2278 80218DC8 AFB10014 */  sw        $s1, 0x14($sp)
/* 5B227C 80218DCC 0080882D */  daddu     $s1, $a0, $zero
/* 5B2280 80218DD0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 5B2284 80218DD4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5B2288 80218DD8 AFB20018 */  sw        $s2, 0x18($sp)
/* 5B228C 80218DDC AFB00010 */  sw        $s0, 0x10($sp)
/* 5B2290 80218DE0 8E30000C */  lw        $s0, 0xc($s1)
/* 5B2294 80218DE4 8E050000 */  lw        $a1, ($s0)
/* 5B2298 80218DE8 0C0B1EAF */  jal       get_variable
/* 5B229C 80218DEC 26100004 */   addiu    $s0, $s0, 4
/* 5B22A0 80218DF0 8E050000 */  lw        $a1, ($s0)
/* 5B22A4 80218DF4 26100004 */  addiu     $s0, $s0, 4
/* 5B22A8 80218DF8 0220202D */  daddu     $a0, $s1, $zero
/* 5B22AC 80218DFC 0C0B1EAF */  jal       get_variable
/* 5B22B0 80218E00 0040982D */   daddu    $s3, $v0, $zero
/* 5B22B4 80218E04 8E050000 */  lw        $a1, ($s0)
/* 5B22B8 80218E08 26100004 */  addiu     $s0, $s0, 4
/* 5B22BC 80218E0C 0220202D */  daddu     $a0, $s1, $zero
/* 5B22C0 80218E10 0C0B1EAF */  jal       get_variable
/* 5B22C4 80218E14 0040902D */   daddu    $s2, $v0, $zero
/* 5B22C8 80218E18 0220202D */  daddu     $a0, $s1, $zero
/* 5B22CC 80218E1C 8E050000 */  lw        $a1, ($s0)
/* 5B22D0 80218E20 0C0B1EAF */  jal       get_variable
/* 5B22D4 80218E24 0040802D */   daddu    $s0, $v0, $zero
/* 5B22D8 80218E28 8E240148 */  lw        $a0, 0x148($s1)
/* 5B22DC 80218E2C 0C09A75B */  jal       get_actor
/* 5B22E0 80218E30 0040882D */   daddu    $s1, $v0, $zero
/* 5B22E4 80218E34 0040182D */  daddu     $v1, $v0, $zero
/* 5B22E8 80218E38 8C620008 */  lw        $v0, 8($v1)
/* 5B22EC 80218E3C 90420024 */  lbu       $v0, 0x24($v0)
/* 5B22F0 80218E40 8C640008 */  lw        $a0, 8($v1)
/* 5B22F4 80218E44 02629823 */  subu      $s3, $s3, $v0
/* 5B22F8 80218E48 A0730194 */  sb        $s3, 0x194($v1)
/* 5B22FC 80218E4C 90820025 */  lbu       $v0, 0x25($a0)
/* 5B2300 80218E50 02429023 */  subu      $s2, $s2, $v0
/* 5B2304 80218E54 A0720195 */  sb        $s2, 0x195($v1)
/* 5B2308 80218E58 90820026 */  lbu       $v0, 0x26($a0)
/* 5B230C 80218E5C 02028023 */  subu      $s0, $s0, $v0
/* 5B2310 80218E60 A0700196 */  sb        $s0, 0x196($v1)
/* 5B2314 80218E64 90840027 */  lbu       $a0, 0x27($a0)
/* 5B2318 80218E68 02248823 */  subu      $s1, $s1, $a0
/* 5B231C 80218E6C A0710197 */  sb        $s1, 0x197($v1)
/* 5B2320 80218E70 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5B2324 80218E74 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5B2328 80218E78 8FB20018 */  lw        $s2, 0x18($sp)
/* 5B232C 80218E7C 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B2330 80218E80 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B2334 80218E84 24020002 */  addiu     $v0, $zero, 2
/* 5B2338 80218E88 03E00008 */  jr        $ra
/* 5B233C 80218E8C 27BD0028 */   addiu    $sp, $sp, 0x28
