.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414B4
/* 8ED2D4 802414B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8ED2D8 802414B8 AFB10014 */  sw        $s1, 0x14($sp)
/* 8ED2DC 802414BC 0080882D */  daddu     $s1, $a0, $zero
/* 8ED2E0 802414C0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8ED2E4 802414C4 AFB20018 */  sw        $s2, 0x18($sp)
/* 8ED2E8 802414C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8ED2EC 802414CC 8E30000C */  lw        $s0, 0xc($s1)
/* 8ED2F0 802414D0 8E050000 */  lw        $a1, ($s0)
/* 8ED2F4 802414D4 0C0B1EAF */  jal       get_variable
/* 8ED2F8 802414D8 26100004 */   addiu    $s0, $s0, 4
/* 8ED2FC 802414DC 8E050000 */  lw        $a1, ($s0)
/* 8ED300 802414E0 26100004 */  addiu     $s0, $s0, 4
/* 8ED304 802414E4 0220202D */  daddu     $a0, $s1, $zero
/* 8ED308 802414E8 0C0B1EAF */  jal       get_variable
/* 8ED30C 802414EC 0040902D */   daddu    $s2, $v0, $zero
/* 8ED310 802414F0 0220202D */  daddu     $a0, $s1, $zero
/* 8ED314 802414F4 8E050000 */  lw        $a1, ($s0)
/* 8ED318 802414F8 0C0B1EAF */  jal       get_variable
/* 8ED31C 802414FC 0040802D */   daddu    $s0, $v0, $zero
/* 8ED320 80241500 0000202D */  daddu     $a0, $zero, $zero
/* 8ED324 80241504 324500FF */  andi      $a1, $s2, 0xff
/* 8ED328 80241508 320600FF */  andi      $a2, $s0, 0xff
/* 8ED32C 8024150C 0C04DF84 */  jal       func_80137E10
/* 8ED330 80241510 304700FF */   andi     $a3, $v0, 0xff
/* 8ED334 80241514 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8ED338 80241518 8FB20018 */  lw        $s2, 0x18($sp)
/* 8ED33C 8024151C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8ED340 80241520 8FB00010 */  lw        $s0, 0x10($sp)
/* 8ED344 80241524 24020002 */  addiu     $v0, $zero, 2
/* 8ED348 80241528 03E00008 */  jr        $ra
/* 8ED34C 8024152C 27BD0020 */   addiu    $sp, $sp, 0x20
