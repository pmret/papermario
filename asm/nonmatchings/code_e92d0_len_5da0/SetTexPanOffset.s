.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetTexPanOffset
/* 0EDD14 802C9364 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EDD18 802C9368 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EDD1C 802C936C 0080882D */  daddu $s1, $a0, $zero
/* 0EDD20 802C9370 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0EDD24 802C9374 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0EDD28 802C9378 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EDD2C 802C937C AFB00010 */  sw    $s0, 0x10($sp)
/* 0EDD30 802C9380 8E30000C */  lw    $s0, 0xc($s1)
/* 0EDD34 802C9384 8E050000 */  lw    $a1, ($s0)
/* 0EDD38 802C9388 0C0B1EAF */  jal   get_variable
/* 0EDD3C 802C938C 26100004 */   addiu $s0, $s0, 4
/* 0EDD40 802C9390 8E050000 */  lw    $a1, ($s0)
/* 0EDD44 802C9394 26100004 */  addiu $s0, $s0, 4
/* 0EDD48 802C9398 0220202D */  daddu $a0, $s1, $zero
/* 0EDD4C 802C939C 0C0B1EAF */  jal   get_variable
/* 0EDD50 802C93A0 0040982D */   daddu $s3, $v0, $zero
/* 0EDD54 802C93A4 8E050000 */  lw    $a1, ($s0)
/* 0EDD58 802C93A8 26100004 */  addiu $s0, $s0, 4
/* 0EDD5C 802C93AC 0220202D */  daddu $a0, $s1, $zero
/* 0EDD60 802C93B0 0C0B1EAF */  jal   get_variable
/* 0EDD64 802C93B4 0040902D */   daddu $s2, $v0, $zero
/* 0EDD68 802C93B8 0220202D */  daddu $a0, $s1, $zero
/* 0EDD6C 802C93BC 8E050000 */  lw    $a1, ($s0)
/* 0EDD70 802C93C0 0C0B1EAF */  jal   get_variable
/* 0EDD74 802C93C4 0040802D */   daddu $s0, $v0, $zero
/* 0EDD78 802C93C8 16400009 */  bnez  $s2, .L802C93F0
/* 0EDD7C 802C93CC 0040882D */   daddu $s1, $v0, $zero
/* 0EDD80 802C93D0 0260202D */  daddu $a0, $s3, $zero
/* 0EDD84 802C93D4 0C046F07 */  jal   set_main_pan_u
/* 0EDD88 802C93D8 0200282D */   daddu $a1, $s0, $zero
/* 0EDD8C 802C93DC 0260202D */  daddu $a0, $s3, $zero
/* 0EDD90 802C93E0 0C046F0D */  jal   set_main_pan_v
/* 0EDD94 802C93E4 0220282D */   daddu $a1, $s1, $zero
/* 0EDD98 802C93E8 080B2502 */  j     .L802C9408
/* 0EDD9C 802C93EC 00000000 */   nop   

.L802C93F0:
/* 0EDDA0 802C93F0 0260202D */  daddu $a0, $s3, $zero
/* 0EDDA4 802C93F4 0C046F13 */  jal   set_aux_pan_u
/* 0EDDA8 802C93F8 0200282D */   daddu $a1, $s0, $zero
/* 0EDDAC 802C93FC 0260202D */  daddu $a0, $s3, $zero
/* 0EDDB0 802C9400 0C046F19 */  jal   set_aux_pan_v
/* 0EDDB4 802C9404 0220282D */   daddu $a1, $s1, $zero
.L802C9408:
/* 0EDDB8 802C9408 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0EDDBC 802C940C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0EDDC0 802C9410 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EDDC4 802C9414 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EDDC8 802C9418 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EDDCC 802C941C 24020002 */  addiu $v0, $zero, 2
/* 0EDDD0 802C9420 03E00008 */  jr    $ra
/* 0EDDD4 802C9424 27BD0028 */   addiu $sp, $sp, 0x28

/* 0EDDD8 802C9428 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EDDDC 802C942C AFB10014 */  sw    $s1, 0x14($sp)
/* 0EDDE0 802C9430 0080882D */  daddu $s1, $a0, $zero
/* 0EDDE4 802C9434 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EDDE8 802C9438 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EDDEC 802C943C AFB00010 */  sw    $s0, 0x10($sp)
/* 0EDDF0 802C9440 8E30000C */  lw    $s0, 0xc($s1)
/* 0EDDF4 802C9444 8E050000 */  lw    $a1, ($s0)
/* 0EDDF8 802C9448 0C0B1EAF */  jal   get_variable
/* 0EDDFC 802C944C 26100004 */   addiu $s0, $s0, 4
/* 0EDE00 802C9450 8E050000 */  lw    $a1, ($s0)
/* 0EDE04 802C9454 26100004 */  addiu $s0, $s0, 4
/* 0EDE08 802C9458 0220202D */  daddu $a0, $s1, $zero
/* 0EDE0C 802C945C 0C0B1EAF */  jal   get_variable
/* 0EDE10 802C9460 0040902D */   daddu $s2, $v0, $zero
/* 0EDE14 802C9464 0220202D */  daddu $a0, $s1, $zero
/* 0EDE18 802C9468 8E050000 */  lw    $a1, ($s0)
/* 0EDE1C 802C946C 0C0B1EAF */  jal   get_variable
/* 0EDE20 802C9470 0040802D */   daddu $s0, $v0, $zero
/* 0EDE24 802C9474 0240202D */  daddu $a0, $s2, $zero
/* 0EDE28 802C9478 0200282D */  daddu $a1, $s0, $zero
/* 0EDE2C 802C947C 0C046F2D */  jal   func_8011BCB4
/* 0EDE30 802C9480 0040302D */   daddu $a2, $v0, $zero
/* 0EDE34 802C9484 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EDE38 802C9488 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EDE3C 802C948C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EDE40 802C9490 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EDE44 802C9494 24020002 */  addiu $v0, $zero, 2
/* 0EDE48 802C9498 03E00008 */  jr    $ra
/* 0EDE4C 802C949C 27BD0020 */   addiu $sp, $sp, 0x20

/* 0EDE50 802C94A0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EDE54 802C94A4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EDE58 802C94A8 0080882D */  daddu $s1, $a0, $zero
/* 0EDE5C 802C94AC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EDE60 802C94B0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EDE64 802C94B4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EDE68 802C94B8 8E30000C */  lw    $s0, 0xc($s1)
/* 0EDE6C 802C94BC 8E050000 */  lw    $a1, ($s0)
/* 0EDE70 802C94C0 0C0B1EAF */  jal   get_variable
/* 0EDE74 802C94C4 26100004 */   addiu $s0, $s0, 4
/* 0EDE78 802C94C8 8E050000 */  lw    $a1, ($s0)
/* 0EDE7C 802C94CC 26100004 */  addiu $s0, $s0, 4
/* 0EDE80 802C94D0 0220202D */  daddu $a0, $s1, $zero
/* 0EDE84 802C94D4 0C0B1EAF */  jal   get_variable
/* 0EDE88 802C94D8 0040902D */   daddu $s2, $v0, $zero
/* 0EDE8C 802C94DC 0220202D */  daddu $a0, $s1, $zero
/* 0EDE90 802C94E0 8E050000 */  lw    $a1, ($s0)
/* 0EDE94 802C94E4 0C0B1EAF */  jal   get_variable
/* 0EDE98 802C94E8 0040802D */   daddu $s0, $v0, $zero
/* 0EDE9C 802C94EC 0240202D */  daddu $a0, $s2, $zero
/* 0EDEA0 802C94F0 0200282D */  daddu $a1, $s0, $zero
/* 0EDEA4 802C94F4 0C046F34 */  jal   func_8011BCD0
/* 0EDEA8 802C94F8 0040302D */   daddu $a2, $v0, $zero
/* 0EDEAC 802C94FC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EDEB0 802C9500 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EDEB4 802C9504 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EDEB8 802C9508 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EDEBC 802C950C 24020002 */  addiu $v0, $zero, 2
/* 0EDEC0 802C9510 03E00008 */  jr    $ra
/* 0EDEC4 802C9514 27BD0020 */   addiu $sp, $sp, 0x20

