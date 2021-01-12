.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A137C_79565C
/* 79565C 802A137C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 795660 802A1380 AFB00010 */  sw        $s0, 0x10($sp)
/* 795664 802A1384 0080802D */  daddu     $s0, $a0, $zero
/* 795668 802A1388 10A0000D */  beqz      $a1, .L802A13C0
/* 79566C 802A138C AFBF0014 */   sw       $ra, 0x14($sp)
/* 795670 802A1390 0C04760B */  jal       func_8011D82C
/* 795674 802A1394 24040001 */   addiu    $a0, $zero, 1
/* 795678 802A1398 0000202D */  daddu     $a0, $zero, $zero
/* 79567C 802A139C 0080282D */  daddu     $a1, $a0, $zero
/* 795680 802A13A0 0080302D */  daddu     $a2, $a0, $zero
/* 795684 802A13A4 0080382D */  daddu     $a3, $a0, $zero
/* 795688 802A13A8 3C038015 */  lui       $v1, %hi(D_801512F0)
/* 79568C 802A13AC 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* 795690 802A13B0 24020001 */  addiu     $v0, $zero, 1
/* 795694 802A13B4 0C046F97 */  jal       set_background_color_blend
/* 795698 802A13B8 A0620000 */   sb       $v0, ($v1)
/* 79569C 802A13BC AE000070 */  sw        $zero, 0x70($s0)
.L802A13C0:
/* 7956A0 802A13C0 0000202D */  daddu     $a0, $zero, $zero
/* 7956A4 802A13C4 0080282D */  daddu     $a1, $a0, $zero
/* 7956A8 802A13C8 92070073 */  lbu       $a3, 0x73($s0)
/* 7956AC 802A13CC 0C046F97 */  jal       set_background_color_blend
/* 7956B0 802A13D0 0080302D */   daddu    $a2, $a0, $zero
/* 7956B4 802A13D4 8E020070 */  lw        $v0, 0x70($s0)
/* 7956B8 802A13D8 2442000A */  addiu     $v0, $v0, 0xa
/* 7956BC 802A13DC AE020070 */  sw        $v0, 0x70($s0)
/* 7956C0 802A13E0 284200E6 */  slti      $v0, $v0, 0xe6
/* 7956C4 802A13E4 14400007 */  bnez      $v0, .L802A1404
/* 7956C8 802A13E8 0000102D */   daddu    $v0, $zero, $zero
/* 7956CC 802A13EC 0000202D */  daddu     $a0, $zero, $zero
/* 7956D0 802A13F0 0080282D */  daddu     $a1, $a0, $zero
/* 7956D4 802A13F4 0080302D */  daddu     $a2, $a0, $zero
/* 7956D8 802A13F8 0C046F97 */  jal       set_background_color_blend
/* 7956DC 802A13FC 240700E6 */   addiu    $a3, $zero, 0xe6
/* 7956E0 802A1400 24020002 */  addiu     $v0, $zero, 2
.L802A1404:
/* 7956E4 802A1404 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7956E8 802A1408 8FB00010 */  lw        $s0, 0x10($sp)
/* 7956EC 802A140C 03E00008 */  jr        $ra
/* 7956F0 802A1410 27BD0018 */   addiu    $sp, $sp, 0x18
