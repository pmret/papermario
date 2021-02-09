.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802439C0_804240
/* 804240 802439C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 804244 802439C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 804248 802439C8 0080882D */  daddu     $s1, $a0, $zero
/* 80424C 802439CC AFBF001C */  sw        $ra, 0x1c($sp)
/* 804250 802439D0 AFB20018 */  sw        $s2, 0x18($sp)
/* 804254 802439D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 804258 802439D8 8E30000C */  lw        $s0, 0xc($s1)
/* 80425C 802439DC 8E050000 */  lw        $a1, ($s0)
/* 804260 802439E0 0C0B1EAF */  jal       get_variable
/* 804264 802439E4 26100004 */   addiu    $s0, $s0, 4
/* 804268 802439E8 8E050000 */  lw        $a1, ($s0)
/* 80426C 802439EC 26100004 */  addiu     $s0, $s0, 4
/* 804270 802439F0 0220202D */  daddu     $a0, $s1, $zero
/* 804274 802439F4 0C0B1EAF */  jal       get_variable
/* 804278 802439F8 0040902D */   daddu    $s2, $v0, $zero
/* 80427C 802439FC 0220202D */  daddu     $a0, $s1, $zero
/* 804280 80243A00 8E050000 */  lw        $a1, ($s0)
/* 804284 80243A04 0C0B1EAF */  jal       get_variable
/* 804288 80243A08 0040802D */   daddu    $s0, $v0, $zero
/* 80428C 80243A0C 0000202D */  daddu     $a0, $zero, $zero
/* 804290 80243A10 324500FF */  andi      $a1, $s2, 0xff
/* 804294 80243A14 320600FF */  andi      $a2, $s0, 0xff
/* 804298 80243A18 0C04DF84 */  jal       set_transition_stencil_color
/* 80429C 80243A1C 304700FF */   andi     $a3, $v0, 0xff
/* 8042A0 80243A20 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8042A4 80243A24 8FB20018 */  lw        $s2, 0x18($sp)
/* 8042A8 80243A28 8FB10014 */  lw        $s1, 0x14($sp)
/* 8042AC 80243A2C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8042B0 80243A30 24020002 */  addiu     $v0, $zero, 2
/* 8042B4 80243A34 03E00008 */  jr        $ra
/* 8042B8 80243A38 27BD0020 */   addiu    $sp, $sp, 0x20
