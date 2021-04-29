.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802189DC_447E1C
/* 447E1C 802189DC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 447E20 802189E0 AFB20018 */  sw        $s2, 0x18($sp)
/* 447E24 802189E4 0080902D */  daddu     $s2, $a0, $zero
/* 447E28 802189E8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 447E2C 802189EC AFB10014 */  sw        $s1, 0x14($sp)
/* 447E30 802189F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 447E34 802189F4 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 447E38 802189F8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 447E3C 802189FC 8E50000C */  lw        $s0, 0xc($s2)
/* 447E40 80218A00 8E050000 */  lw        $a1, ($s0)
/* 447E44 80218A04 0C0B210B */  jal       get_float_variable
/* 447E48 80218A08 26100004 */   addiu    $s0, $s0, 4
/* 447E4C 80218A0C 8E050000 */  lw        $a1, ($s0)
/* 447E50 80218A10 26100004 */  addiu     $s0, $s0, 4
/* 447E54 80218A14 0240202D */  daddu     $a0, $s2, $zero
/* 447E58 80218A18 0C0B210B */  jal       get_float_variable
/* 447E5C 80218A1C 46000586 */   mov.s    $f22, $f0
/* 447E60 80218A20 3C048010 */  lui       $a0, %hi(D_80104A28)
/* 447E64 80218A24 24844A28 */  addiu     $a0, $a0, %lo(D_80104A28)
/* 447E68 80218A28 0C050529 */  jal       create_icon
/* 447E6C 80218A2C 46000506 */   mov.s    $f20, $f0
/* 447E70 80218A30 0040882D */  daddu     $s1, $v0, $zero
/* 447E74 80218A34 4600B08D */  trunc.w.s $f2, $f22
/* 447E78 80218A38 44051000 */  mfc1      $a1, $f2
/* 447E7C 80218A3C 4600A08D */  trunc.w.s $f2, $f20
/* 447E80 80218A40 44061000 */  mfc1      $a2, $f2
/* 447E84 80218A44 0C051261 */  jal       set_icon_render_pos
/* 447E88 80218A48 0220202D */   daddu    $a0, $s1, $zero
/* 447E8C 80218A4C 3C053FC0 */  lui       $a1, 0x3fc0
/* 447E90 80218A50 0C051308 */  jal       set_hud_element_scale
/* 447E94 80218A54 0220202D */   daddu    $a0, $s1, $zero
/* 447E98 80218A58 0220202D */  daddu     $a0, $s1, $zero
/* 447E9C 80218A5C 3C050020 */  lui       $a1, 0x20
/* 447EA0 80218A60 0C05128B */  jal       clear_icon_flags
/* 447EA4 80218A64 34A50002 */   ori      $a1, $a1, 2
/* 447EA8 80218A68 0240202D */  daddu     $a0, $s2, $zero
/* 447EAC 80218A6C 8E050000 */  lw        $a1, ($s0)
/* 447EB0 80218A70 0C0B2026 */  jal       set_variable
/* 447EB4 80218A74 0220302D */   daddu    $a2, $s1, $zero
/* 447EB8 80218A78 0C094F9E */  jal       load_tattle_flags
/* 447EBC 80218A7C 2404008B */   addiu    $a0, $zero, 0x8b
/* 447EC0 80218A80 8FBF001C */  lw        $ra, 0x1c($sp)
/* 447EC4 80218A84 8FB20018 */  lw        $s2, 0x18($sp)
/* 447EC8 80218A88 8FB10014 */  lw        $s1, 0x14($sp)
/* 447ECC 80218A8C 8FB00010 */  lw        $s0, 0x10($sp)
/* 447ED0 80218A90 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 447ED4 80218A94 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 447ED8 80218A98 24020002 */  addiu     $v0, $zero, 2
/* 447EDC 80218A9C 03E00008 */  jr        $ra
/* 447EE0 80218AA0 27BD0030 */   addiu    $sp, $sp, 0x30
