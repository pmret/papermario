.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243284_8B32F4
/* 8B32F4 80243284 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B32F8 80243288 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B32FC 8024328C 0080882D */  daddu     $s1, $a0, $zero
/* 8B3300 80243290 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8B3304 80243294 AFB20018 */  sw        $s2, 0x18($sp)
/* 8B3308 80243298 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B330C 8024329C 8E30000C */  lw        $s0, 0xc($s1)
/* 8B3310 802432A0 8E050000 */  lw        $a1, ($s0)
/* 8B3314 802432A4 0C0B1EAF */  jal       get_variable
/* 8B3318 802432A8 26100004 */   addiu    $s0, $s0, 4
/* 8B331C 802432AC 8E050000 */  lw        $a1, ($s0)
/* 8B3320 802432B0 26100004 */  addiu     $s0, $s0, 4
/* 8B3324 802432B4 0220202D */  daddu     $a0, $s1, $zero
/* 8B3328 802432B8 0C0B1EAF */  jal       get_variable
/* 8B332C 802432BC 0040902D */   daddu    $s2, $v0, $zero
/* 8B3330 802432C0 0220202D */  daddu     $a0, $s1, $zero
/* 8B3334 802432C4 8E050000 */  lw        $a1, ($s0)
/* 8B3338 802432C8 0C0B1EAF */  jal       get_variable
/* 8B333C 802432CC 0040802D */   daddu    $s0, $v0, $zero
/* 8B3340 802432D0 0000202D */  daddu     $a0, $zero, $zero
/* 8B3344 802432D4 324500FF */  andi      $a1, $s2, 0xff
/* 8B3348 802432D8 320600FF */  andi      $a2, $s0, 0xff
/* 8B334C 802432DC 0C04DF84 */  jal       set_transition_stencil_color
/* 8B3350 802432E0 304700FF */   andi     $a3, $v0, 0xff
/* 8B3354 802432E4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8B3358 802432E8 8FB20018 */  lw        $s2, 0x18($sp)
/* 8B335C 802432EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B3360 802432F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B3364 802432F4 24020002 */  addiu     $v0, $zero, 2
/* 8B3368 802432F8 03E00008 */  jr        $ra
/* 8B336C 802432FC 27BD0020 */   addiu    $sp, $sp, 0x20
