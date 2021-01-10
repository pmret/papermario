.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A137C_78EB4C
/* 78EB4C 802A137C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 78EB50 802A1380 AFB00010 */  sw        $s0, 0x10($sp)
/* 78EB54 802A1384 0080802D */  daddu     $s0, $a0, $zero
/* 78EB58 802A1388 10A0000D */  beqz      $a1, .L802A13C0
/* 78EB5C 802A138C AFBF0014 */   sw       $ra, 0x14($sp)
/* 78EB60 802A1390 0C04760B */  jal       func_8011D82C
/* 78EB64 802A1394 24040001 */   addiu    $a0, $zero, 1
/* 78EB68 802A1398 0000202D */  daddu     $a0, $zero, $zero
/* 78EB6C 802A139C 0080282D */  daddu     $a1, $a0, $zero
/* 78EB70 802A13A0 0080302D */  daddu     $a2, $a0, $zero
/* 78EB74 802A13A4 0080382D */  daddu     $a3, $a0, $zero
/* 78EB78 802A13A8 3C038015 */  lui       $v1, %hi(D_801512F0)
/* 78EB7C 802A13AC 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* 78EB80 802A13B0 24020001 */  addiu     $v0, $zero, 1
/* 78EB84 802A13B4 0C046F97 */  jal       set_background_color_blend
/* 78EB88 802A13B8 A0620000 */   sb       $v0, ($v1)
/* 78EB8C 802A13BC AE000070 */  sw        $zero, 0x70($s0)
.L802A13C0:
/* 78EB90 802A13C0 0000202D */  daddu     $a0, $zero, $zero
/* 78EB94 802A13C4 0080282D */  daddu     $a1, $a0, $zero
/* 78EB98 802A13C8 92070073 */  lbu       $a3, 0x73($s0)
/* 78EB9C 802A13CC 0C046F97 */  jal       set_background_color_blend
/* 78EBA0 802A13D0 0080302D */   daddu    $a2, $a0, $zero
/* 78EBA4 802A13D4 8E020070 */  lw        $v0, 0x70($s0)
/* 78EBA8 802A13D8 2442000A */  addiu     $v0, $v0, 0xa
/* 78EBAC 802A13DC AE020070 */  sw        $v0, 0x70($s0)
/* 78EBB0 802A13E0 284200E6 */  slti      $v0, $v0, 0xe6
/* 78EBB4 802A13E4 14400007 */  bnez      $v0, .L802A1404
/* 78EBB8 802A13E8 0000102D */   daddu    $v0, $zero, $zero
/* 78EBBC 802A13EC 0000202D */  daddu     $a0, $zero, $zero
/* 78EBC0 802A13F0 0080282D */  daddu     $a1, $a0, $zero
/* 78EBC4 802A13F4 0080302D */  daddu     $a2, $a0, $zero
/* 78EBC8 802A13F8 0C046F97 */  jal       set_background_color_blend
/* 78EBCC 802A13FC 240700E6 */   addiu    $a3, $zero, 0xe6
/* 78EBD0 802A1400 24020002 */  addiu     $v0, $zero, 2
.L802A1404:
/* 78EBD4 802A1404 8FBF0014 */  lw        $ra, 0x14($sp)
/* 78EBD8 802A1408 8FB00010 */  lw        $s0, 0x10($sp)
/* 78EBDC 802A140C 03E00008 */  jr        $ra
/* 78EBE0 802A1410 27BD0018 */   addiu    $sp, $sp, 0x18
