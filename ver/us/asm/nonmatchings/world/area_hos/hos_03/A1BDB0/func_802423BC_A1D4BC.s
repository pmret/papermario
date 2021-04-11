.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel hos_03_UnkFunc35
/* A1D4BC 802423BC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A1D4C0 802423C0 AFB10014 */  sw        $s1, 0x14($sp)
/* A1D4C4 802423C4 0080882D */  daddu     $s1, $a0, $zero
/* A1D4C8 802423C8 AFBF001C */  sw        $ra, 0x1c($sp)
/* A1D4CC 802423CC AFB20018 */  sw        $s2, 0x18($sp)
/* A1D4D0 802423D0 AFB00010 */  sw        $s0, 0x10($sp)
/* A1D4D4 802423D4 8E30000C */  lw        $s0, 0xc($s1)
/* A1D4D8 802423D8 8E050000 */  lw        $a1, ($s0)
/* A1D4DC 802423DC 0C0B1EAF */  jal       get_variable
/* A1D4E0 802423E0 26100004 */   addiu    $s0, $s0, 4
/* A1D4E4 802423E4 8E050000 */  lw        $a1, ($s0)
/* A1D4E8 802423E8 26100004 */  addiu     $s0, $s0, 4
/* A1D4EC 802423EC 0220202D */  daddu     $a0, $s1, $zero
/* A1D4F0 802423F0 0C0B1EAF */  jal       get_variable
/* A1D4F4 802423F4 0040902D */   daddu    $s2, $v0, $zero
/* A1D4F8 802423F8 0220202D */  daddu     $a0, $s1, $zero
/* A1D4FC 802423FC 8E050000 */  lw        $a1, ($s0)
/* A1D500 80242400 0C0B1EAF */  jal       get_variable
/* A1D504 80242404 0040802D */   daddu    $s0, $v0, $zero
/* A1D508 80242408 0000202D */  daddu     $a0, $zero, $zero
/* A1D50C 8024240C 324500FF */  andi      $a1, $s2, 0xff
/* A1D510 80242410 320600FF */  andi      $a2, $s0, 0xff
/* A1D514 80242414 0C04DF84 */  jal       set_transition_stencil_color
/* A1D518 80242418 304700FF */   andi     $a3, $v0, 0xff
/* A1D51C 8024241C 8FBF001C */  lw        $ra, 0x1c($sp)
/* A1D520 80242420 8FB20018 */  lw        $s2, 0x18($sp)
/* A1D524 80242424 8FB10014 */  lw        $s1, 0x14($sp)
/* A1D528 80242428 8FB00010 */  lw        $s0, 0x10($sp)
/* A1D52C 8024242C 24020002 */  addiu     $v0, $zero, 2
/* A1D530 80242430 03E00008 */  jr        $ra
/* A1D534 80242434 27BD0020 */   addiu    $sp, $sp, 0x20
