.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A15B4_795894
/* 795894 802A15B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 795898 802A15B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 79589C 802A15BC 0080802D */  daddu     $s0, $a0, $zero
/* 7958A0 802A15C0 10A00003 */  beqz      $a1, .L802A15D0
/* 7958A4 802A15C4 AFBF0014 */   sw       $ra, 0x14($sp)
/* 7958A8 802A15C8 240200FE */  addiu     $v0, $zero, 0xfe
/* 7958AC 802A15CC AE020070 */  sw        $v0, 0x70($s0)
.L802A15D0:
/* 7958B0 802A15D0 0000202D */  daddu     $a0, $zero, $zero
/* 7958B4 802A15D4 0080282D */  daddu     $a1, $a0, $zero
/* 7958B8 802A15D8 92070073 */  lbu       $a3, 0x73($s0)
/* 7958BC 802A15DC 0C046F97 */  jal       set_background_color_blend
/* 7958C0 802A15E0 0080302D */   daddu    $a2, $a0, $zero
/* 7958C4 802A15E4 8E020070 */  lw        $v0, 0x70($s0)
/* 7958C8 802A15E8 2442FFFB */  addiu     $v0, $v0, -5
/* 7958CC 802A15EC AE020070 */  sw        $v0, 0x70($s0)
/* 7958D0 802A15F0 284200C9 */  slti      $v0, $v0, 0xc9
/* 7958D4 802A15F4 14400003 */  bnez      $v0, .L802A1604
/* 7958D8 802A15F8 0000202D */   daddu    $a0, $zero, $zero
/* 7958DC 802A15FC 080A8586 */  j         .L802A1618
/* 7958E0 802A1600 0000102D */   daddu    $v0, $zero, $zero
.L802A1604:
/* 7958E4 802A1604 0080282D */  daddu     $a1, $a0, $zero
/* 7958E8 802A1608 0080302D */  daddu     $a2, $a0, $zero
/* 7958EC 802A160C 0C046F97 */  jal       set_background_color_blend
/* 7958F0 802A1610 240700C8 */   addiu    $a3, $zero, 0xc8
/* 7958F4 802A1614 24020002 */  addiu     $v0, $zero, 2
.L802A1618:
/* 7958F8 802A1618 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7958FC 802A161C 8FB00010 */  lw        $s0, 0x10($sp)
/* 795900 802A1620 03E00008 */  jr        $ra
/* 795904 802A1624 27BD0018 */   addiu    $sp, $sp, 0x18
