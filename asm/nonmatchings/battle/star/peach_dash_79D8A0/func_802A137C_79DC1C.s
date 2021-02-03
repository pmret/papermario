.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A137C_79DC1C
/* 79DC1C 802A137C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 79DC20 802A1380 AFB00010 */  sw        $s0, 0x10($sp)
/* 79DC24 802A1384 0080802D */  daddu     $s0, $a0, $zero
/* 79DC28 802A1388 10A0000D */  beqz      $a1, .L802A13C0
/* 79DC2C 802A138C AFBF0014 */   sw       $ra, 0x14($sp)
/* 79DC30 802A1390 0C04760B */  jal       func_8011D82C
/* 79DC34 802A1394 24040001 */   addiu    $a0, $zero, 1
/* 79DC38 802A1398 0000202D */  daddu     $a0, $zero, $zero
/* 79DC3C 802A139C 0080282D */  daddu     $a1, $a0, $zero
/* 79DC40 802A13A0 0080302D */  daddu     $a2, $a0, $zero
/* 79DC44 802A13A4 0080382D */  daddu     $a3, $a0, $zero
/* 79DC48 802A13A8 3C038015 */  lui       $v1, %hi(D_801512F0)
/* 79DC4C 802A13AC 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* 79DC50 802A13B0 24020001 */  addiu     $v0, $zero, 1
/* 79DC54 802A13B4 0C046F97 */  jal       set_background_color_blend
/* 79DC58 802A13B8 A0620000 */   sb       $v0, ($v1)
/* 79DC5C 802A13BC AE000070 */  sw        $zero, 0x70($s0)
.L802A13C0:
/* 79DC60 802A13C0 0000202D */  daddu     $a0, $zero, $zero
/* 79DC64 802A13C4 0080282D */  daddu     $a1, $a0, $zero
/* 79DC68 802A13C8 92070073 */  lbu       $a3, 0x73($s0)
/* 79DC6C 802A13CC 0C046F97 */  jal       set_background_color_blend
/* 79DC70 802A13D0 0080302D */   daddu    $a2, $a0, $zero
/* 79DC74 802A13D4 8E020070 */  lw        $v0, 0x70($s0)
/* 79DC78 802A13D8 2442000A */  addiu     $v0, $v0, 0xa
/* 79DC7C 802A13DC AE020070 */  sw        $v0, 0x70($s0)
/* 79DC80 802A13E0 284200E6 */  slti      $v0, $v0, 0xe6
/* 79DC84 802A13E4 14400007 */  bnez      $v0, .L802A1404
/* 79DC88 802A13E8 0000102D */   daddu    $v0, $zero, $zero
/* 79DC8C 802A13EC 0000202D */  daddu     $a0, $zero, $zero
/* 79DC90 802A13F0 0080282D */  daddu     $a1, $a0, $zero
/* 79DC94 802A13F4 0080302D */  daddu     $a2, $a0, $zero
/* 79DC98 802A13F8 0C046F97 */  jal       set_background_color_blend
/* 79DC9C 802A13FC 240700E6 */   addiu    $a3, $zero, 0xe6
/* 79DCA0 802A1400 24020002 */  addiu     $v0, $zero, 2
.L802A1404:
/* 79DCA4 802A1404 8FBF0014 */  lw        $ra, 0x14($sp)
/* 79DCA8 802A1408 8FB00010 */  lw        $s0, 0x10($sp)
/* 79DCAC 802A140C 03E00008 */  jr        $ra
/* 79DCB0 802A1410 27BD0018 */   addiu    $sp, $sp, 0x18
