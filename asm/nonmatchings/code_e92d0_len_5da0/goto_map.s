.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel goto_map
/* EECB4 802CA304 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EECB8 802CA308 AFB20020 */  sw        $s2, 0x20($sp)
/* EECBC 802CA30C 0080902D */  daddu     $s2, $a0, $zero
/* EECC0 802CA310 AFB40028 */  sw        $s4, 0x28($sp)
/* EECC4 802CA314 00A0A02D */  daddu     $s4, $a1, $zero
/* EECC8 802CA318 AFB30024 */  sw        $s3, 0x24($sp)
/* EECCC 802CA31C 24020002 */  addiu     $v0, $zero, 2
/* EECD0 802CA320 AFBF002C */  sw        $ra, 0x2c($sp)
/* EECD4 802CA324 AFB1001C */  sw        $s1, 0x1c($sp)
/* EECD8 802CA328 AFB00018 */  sw        $s0, 0x18($sp)
/* EECDC 802CA32C 8E51000C */  lw        $s1, 0xc($s2)
/* EECE0 802CA330 1682000B */  bne       $s4, $v0, .L802CA360
/* EECE4 802CA334 0000982D */   daddu    $s3, $zero, $zero
/* EECE8 802CA338 8E250000 */  lw        $a1, ($s1)
/* EECEC 802CA33C 0C0B1EAF */  jal       get_variable
/* EECF0 802CA340 26310004 */   addiu    $s1, $s1, 4
/* EECF4 802CA344 A7A20010 */  sh        $v0, 0x10($sp)
/* EECF8 802CA348 8E250000 */  lw        $a1, ($s1)
/* EECFC 802CA34C 26310004 */  addiu     $s1, $s1, 4
/* EED00 802CA350 0C0B1EAF */  jal       get_variable
/* EED04 802CA354 0240202D */   daddu    $a0, $s2, $zero
/* EED08 802CA358 080B28E0 */  j         .L802CA380
/* EED0C 802CA35C A7A20012 */   sh       $v0, 0x12($sp)
.L802CA360:
/* EED10 802CA360 8E250000 */  lw        $a1, ($s1)
/* EED14 802CA364 26310004 */  addiu     $s1, $s1, 4
/* EED18 802CA368 0C0B1EAF */  jal       get_variable
/* EED1C 802CA36C 0240202D */   daddu    $a0, $s2, $zero
/* EED20 802CA370 0040202D */  daddu     $a0, $v0, $zero
/* EED24 802CA374 27A50010 */  addiu     $a1, $sp, 0x10
/* EED28 802CA378 0C016AFE */  jal       get_map_IDs_by_name
/* EED2C 802CA37C 27A60012 */   addiu    $a2, $sp, 0x12
.L802CA380:
/* EED30 802CA380 3C108007 */  lui       $s0, 0x8007
/* EED34 802CA384 2610419C */  addiu     $s0, $s0, 0x419c
/* EED38 802CA388 8E040000 */  lw        $a0, ($s0)
/* EED3C 802CA38C 97A20010 */  lhu       $v0, 0x10($sp)
/* EED40 802CA390 97A30012 */  lhu       $v1, 0x12($sp)
/* EED44 802CA394 A4820086 */  sh        $v0, 0x86($a0)
/* EED48 802CA398 A483008C */  sh        $v1, 0x8c($a0)
/* EED4C 802CA39C 8E250000 */  lw        $a1, ($s1)
/* EED50 802CA3A0 0C0B1EAF */  jal       get_variable
/* EED54 802CA3A4 0240202D */   daddu    $a0, $s2, $zero
/* EED58 802CA3A8 8E030000 */  lw        $v1, ($s0)
/* EED5C 802CA3AC A462008E */  sh        $v0, 0x8e($v1)
/* EED60 802CA3B0 24020001 */  addiu     $v0, $zero, 1
/* EED64 802CA3B4 16820005 */  bne       $s4, $v0, .L802CA3CC
/* EED68 802CA3B8 26310004 */   addiu    $s1, $s1, 4
/* EED6C 802CA3BC 8E250000 */  lw        $a1, ($s1)
/* EED70 802CA3C0 0C0B1EAF */  jal       get_variable
/* EED74 802CA3C4 0240202D */   daddu    $a0, $s2, $zero
/* EED78 802CA3C8 0040982D */  daddu     $s3, $v0, $zero
.L802CA3CC:
/* EED7C 802CA3CC 00132400 */  sll       $a0, $s3, 0x10
/* EED80 802CA3D0 0C04E0A8 */  jal       set_map_transition_effect
/* EED84 802CA3D4 00042403 */   sra      $a0, $a0, 0x10
/* EED88 802CA3D8 0C00CD3C */  jal       set_game_mode
/* EED8C 802CA3DC 24040005 */   addiu    $a0, $zero, 5
/* EED90 802CA3E0 8FBF002C */  lw        $ra, 0x2c($sp)
/* EED94 802CA3E4 8FB40028 */  lw        $s4, 0x28($sp)
/* EED98 802CA3E8 8FB30024 */  lw        $s3, 0x24($sp)
/* EED9C 802CA3EC 8FB20020 */  lw        $s2, 0x20($sp)
/* EEDA0 802CA3F0 8FB1001C */  lw        $s1, 0x1c($sp)
/* EEDA4 802CA3F4 8FB00018 */  lw        $s0, 0x18($sp)
/* EEDA8 802CA3F8 03E00008 */  jr        $ra
/* EEDAC 802CA3FC 27BD0030 */   addiu    $sp, $sp, 0x30
