.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802C94A0
/* EDE50 802C94A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EDE54 802C94A4 AFB10014 */  sw        $s1, 0x14($sp)
/* EDE58 802C94A8 0080882D */  daddu     $s1, $a0, $zero
/* EDE5C 802C94AC AFBF001C */  sw        $ra, 0x1c($sp)
/* EDE60 802C94B0 AFB20018 */  sw        $s2, 0x18($sp)
/* EDE64 802C94B4 AFB00010 */  sw        $s0, 0x10($sp)
/* EDE68 802C94B8 8E30000C */  lw        $s0, 0xc($s1)
/* EDE6C 802C94BC 8E050000 */  lw        $a1, ($s0)
/* EDE70 802C94C0 0C0B1EAF */  jal       get_variable
/* EDE74 802C94C4 26100004 */   addiu    $s0, $s0, 4
/* EDE78 802C94C8 8E050000 */  lw        $a1, ($s0)
/* EDE7C 802C94CC 26100004 */  addiu     $s0, $s0, 4
/* EDE80 802C94D0 0220202D */  daddu     $a0, $s1, $zero
/* EDE84 802C94D4 0C0B1EAF */  jal       get_variable
/* EDE88 802C94D8 0040902D */   daddu    $s2, $v0, $zero
/* EDE8C 802C94DC 0220202D */  daddu     $a0, $s1, $zero
/* EDE90 802C94E0 8E050000 */  lw        $a1, ($s0)
/* EDE94 802C94E4 0C0B1EAF */  jal       get_variable
/* EDE98 802C94E8 0040802D */   daddu    $s0, $v0, $zero
/* EDE9C 802C94EC 0240202D */  daddu     $a0, $s2, $zero
/* EDEA0 802C94F0 0200282D */  daddu     $a1, $s0, $zero
/* EDEA4 802C94F4 0C046F34 */  jal       func_8011BCD0
/* EDEA8 802C94F8 0040302D */   daddu    $a2, $v0, $zero
/* EDEAC 802C94FC 8FBF001C */  lw        $ra, 0x1c($sp)
/* EDEB0 802C9500 8FB20018 */  lw        $s2, 0x18($sp)
/* EDEB4 802C9504 8FB10014 */  lw        $s1, 0x14($sp)
/* EDEB8 802C9508 8FB00010 */  lw        $s0, 0x10($sp)
/* EDEBC 802C950C 24020002 */  addiu     $v0, $zero, 2
/* EDEC0 802C9510 03E00008 */  jr        $ra
/* EDEC4 802C9514 27BD0020 */   addiu    $sp, $sp, 0x20
