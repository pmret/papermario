.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802C9428
/* EDDD8 802C9428 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EDDDC 802C942C AFB10014 */  sw        $s1, 0x14($sp)
/* EDDE0 802C9430 0080882D */  daddu     $s1, $a0, $zero
/* EDDE4 802C9434 AFBF001C */  sw        $ra, 0x1c($sp)
/* EDDE8 802C9438 AFB20018 */  sw        $s2, 0x18($sp)
/* EDDEC 802C943C AFB00010 */  sw        $s0, 0x10($sp)
/* EDDF0 802C9440 8E30000C */  lw        $s0, 0xc($s1)
/* EDDF4 802C9444 8E050000 */  lw        $a1, ($s0)
/* EDDF8 802C9448 0C0B1EAF */  jal       get_variable
/* EDDFC 802C944C 26100004 */   addiu    $s0, $s0, 4
/* EDE00 802C9450 8E050000 */  lw        $a1, ($s0)
/* EDE04 802C9454 26100004 */  addiu     $s0, $s0, 4
/* EDE08 802C9458 0220202D */  daddu     $a0, $s1, $zero
/* EDE0C 802C945C 0C0B1EAF */  jal       get_variable
/* EDE10 802C9460 0040902D */   daddu    $s2, $v0, $zero
/* EDE14 802C9464 0220202D */  daddu     $a0, $s1, $zero
/* EDE18 802C9468 8E050000 */  lw        $a1, ($s0)
/* EDE1C 802C946C 0C0B1EAF */  jal       get_variable
/* EDE20 802C9470 0040802D */   daddu    $s0, $v0, $zero
/* EDE24 802C9474 0240202D */  daddu     $a0, $s2, $zero
/* EDE28 802C9478 0200282D */  daddu     $a1, $s0, $zero
/* EDE2C 802C947C 0C046F2D */  jal       func_8011BCB4
/* EDE30 802C9480 0040302D */   daddu    $a2, $v0, $zero
/* EDE34 802C9484 8FBF001C */  lw        $ra, 0x1c($sp)
/* EDE38 802C9488 8FB20018 */  lw        $s2, 0x18($sp)
/* EDE3C 802C948C 8FB10014 */  lw        $s1, 0x14($sp)
/* EDE40 802C9490 8FB00010 */  lw        $s0, 0x10($sp)
/* EDE44 802C9494 24020002 */  addiu     $v0, $zero, 2
/* EDE48 802C9498 03E00008 */  jr        $ra
/* EDE4C 802C949C 27BD0020 */   addiu    $sp, $sp, 0x20
