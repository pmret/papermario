.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802182E0_4FED30
/* 4FED30 802182E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4FED34 802182E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 4FED38 802182E8 0080882D */  daddu     $s1, $a0, $zero
/* 4FED3C 802182EC AFBF0018 */  sw        $ra, 0x18($sp)
/* 4FED40 802182F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 4FED44 802182F4 8E30000C */  lw        $s0, 0xc($s1)
/* 4FED48 802182F8 8E050000 */  lw        $a1, ($s0)
/* 4FED4C 802182FC 0C0B1EAF */  jal       get_variable
/* 4FED50 80218300 26100004 */   addiu    $s0, $s0, 4
/* 4FED54 80218304 0220202D */  daddu     $a0, $s1, $zero
/* 4FED58 80218308 8E050000 */  lw        $a1, ($s0)
/* 4FED5C 8021830C 0C0B1EAF */  jal       get_variable
/* 4FED60 80218310 0040802D */   daddu    $s0, $v0, $zero
/* 4FED64 80218314 0200202D */  daddu     $a0, $s0, $zero
/* 4FED68 80218318 0C00A3C2 */  jal       start_rumble
/* 4FED6C 8021831C 0040282D */   daddu    $a1, $v0, $zero
/* 4FED70 80218320 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4FED74 80218324 8FB10014 */  lw        $s1, 0x14($sp)
/* 4FED78 80218328 8FB00010 */  lw        $s0, 0x10($sp)
/* 4FED7C 8021832C 24020002 */  addiu     $v0, $zero, 2
/* 4FED80 80218330 03E00008 */  jr        $ra
/* 4FED84 80218334 27BD0020 */   addiu    $sp, $sp, 0x20
