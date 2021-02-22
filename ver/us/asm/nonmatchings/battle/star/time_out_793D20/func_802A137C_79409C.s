.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A137C_79409C
/* 79409C 802A137C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7940A0 802A1380 AFB00010 */  sw        $s0, 0x10($sp)
/* 7940A4 802A1384 0080802D */  daddu     $s0, $a0, $zero
/* 7940A8 802A1388 10A0000D */  beqz      $a1, .L802A13C0
/* 7940AC 802A138C AFBF0014 */   sw       $ra, 0x14($sp)
/* 7940B0 802A1390 0C04760B */  jal       func_8011D82C
/* 7940B4 802A1394 24040001 */   addiu    $a0, $zero, 1
/* 7940B8 802A1398 0000202D */  daddu     $a0, $zero, $zero
/* 7940BC 802A139C 0080282D */  daddu     $a1, $a0, $zero
/* 7940C0 802A13A0 0080302D */  daddu     $a2, $a0, $zero
/* 7940C4 802A13A4 0080382D */  daddu     $a3, $a0, $zero
/* 7940C8 802A13A8 3C038015 */  lui       $v1, %hi(D_801512F0)
/* 7940CC 802A13AC 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* 7940D0 802A13B0 24020001 */  addiu     $v0, $zero, 1
/* 7940D4 802A13B4 0C046F97 */  jal       set_background_color_blend
/* 7940D8 802A13B8 A0620000 */   sb       $v0, ($v1)
/* 7940DC 802A13BC AE000070 */  sw        $zero, 0x70($s0)
.L802A13C0:
/* 7940E0 802A13C0 0000202D */  daddu     $a0, $zero, $zero
/* 7940E4 802A13C4 0080282D */  daddu     $a1, $a0, $zero
/* 7940E8 802A13C8 92070073 */  lbu       $a3, 0x73($s0)
/* 7940EC 802A13CC 0C046F97 */  jal       set_background_color_blend
/* 7940F0 802A13D0 0080302D */   daddu    $a2, $a0, $zero
/* 7940F4 802A13D4 8E020070 */  lw        $v0, 0x70($s0)
/* 7940F8 802A13D8 2442000A */  addiu     $v0, $v0, 0xa
/* 7940FC 802A13DC AE020070 */  sw        $v0, 0x70($s0)
/* 794100 802A13E0 284200E6 */  slti      $v0, $v0, 0xe6
/* 794104 802A13E4 14400007 */  bnez      $v0, .L802A1404
/* 794108 802A13E8 0000102D */   daddu    $v0, $zero, $zero
/* 79410C 802A13EC 0000202D */  daddu     $a0, $zero, $zero
/* 794110 802A13F0 0080282D */  daddu     $a1, $a0, $zero
/* 794114 802A13F4 0080302D */  daddu     $a2, $a0, $zero
/* 794118 802A13F8 0C046F97 */  jal       set_background_color_blend
/* 79411C 802A13FC 240700E6 */   addiu    $a3, $zero, 0xe6
/* 794120 802A1400 24020002 */  addiu     $v0, $zero, 2
.L802A1404:
/* 794124 802A1404 8FBF0014 */  lw        $ra, 0x14($sp)
/* 794128 802A1408 8FB00010 */  lw        $s0, 0x10($sp)
/* 79412C 802A140C 03E00008 */  jr        $ra
/* 794130 802A1410 27BD0018 */   addiu    $sp, $sp, 0x18
