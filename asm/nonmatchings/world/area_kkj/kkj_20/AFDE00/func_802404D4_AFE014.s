.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404D4_AFE014
/* AFE014 802404D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AFE018 802404D8 AFB10014 */  sw        $s1, 0x14($sp)
/* AFE01C 802404DC 0080882D */  daddu     $s1, $a0, $zero
/* AFE020 802404E0 AFBF001C */  sw        $ra, 0x1c($sp)
/* AFE024 802404E4 AFB20018 */  sw        $s2, 0x18($sp)
/* AFE028 802404E8 AFB00010 */  sw        $s0, 0x10($sp)
/* AFE02C 802404EC 8E30000C */  lw        $s0, 0xc($s1)
/* AFE030 802404F0 8E050000 */  lw        $a1, ($s0)
/* AFE034 802404F4 0C0B1EAF */  jal       get_variable
/* AFE038 802404F8 26100004 */   addiu    $s0, $s0, 4
/* AFE03C 802404FC 8E050000 */  lw        $a1, ($s0)
/* AFE040 80240500 26100004 */  addiu     $s0, $s0, 4
/* AFE044 80240504 0220202D */  daddu     $a0, $s1, $zero
/* AFE048 80240508 0C0B1EAF */  jal       get_variable
/* AFE04C 8024050C 0040902D */   daddu    $s2, $v0, $zero
/* AFE050 80240510 0220202D */  daddu     $a0, $s1, $zero
/* AFE054 80240514 8E050000 */  lw        $a1, ($s0)
/* AFE058 80240518 0C0B1EAF */  jal       get_variable
/* AFE05C 8024051C 0040802D */   daddu    $s0, $v0, $zero
/* AFE060 80240520 0000202D */  daddu     $a0, $zero, $zero
/* AFE064 80240524 324500FF */  andi      $a1, $s2, 0xff
/* AFE068 80240528 320600FF */  andi      $a2, $s0, 0xff
/* AFE06C 8024052C 0C04DF84 */  jal       set_transition_stencil_color
/* AFE070 80240530 304700FF */   andi     $a3, $v0, 0xff
/* AFE074 80240534 8FBF001C */  lw        $ra, 0x1c($sp)
/* AFE078 80240538 8FB20018 */  lw        $s2, 0x18($sp)
/* AFE07C 8024053C 8FB10014 */  lw        $s1, 0x14($sp)
/* AFE080 80240540 8FB00010 */  lw        $s0, 0x10($sp)
/* AFE084 80240544 24020002 */  addiu     $v0, $zero, 2
/* AFE088 80240548 03E00008 */  jr        $ra
/* AFE08C 8024054C 27BD0020 */   addiu    $sp, $sp, 0x20
