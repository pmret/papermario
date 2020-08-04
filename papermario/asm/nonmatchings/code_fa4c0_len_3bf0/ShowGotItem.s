.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ShowGotItem
/* 0FBD54 802D73A4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FBD58 802D73A8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0FBD5C 802D73AC 0080902D */  daddu $s2, $a0, $zero
/* 0FBD60 802D73B0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0FBD64 802D73B4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FBD68 802D73B8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FBD6C 802D73BC 8E51000C */  lw    $s1, 0xc($s2)
/* 0FBD70 802D73C0 54A00001 */  bnel  $a1, $zero, .L802D73C8
/* 0FBD74 802D73C4 AE400070 */   sw    $zero, 0x70($s2)
.L802D73C8:
/* 0FBD78 802D73C8 8E430070 */  lw    $v1, 0x70($s2)
/* 0FBD7C 802D73CC 10600005 */  beqz  $v1, .L802D73E4
/* 0FBD80 802D73D0 24020001 */   addiu $v0, $zero, 1
/* 0FBD84 802D73D4 10620014 */  beq   $v1, $v0, .L802D7428
/* 0FBD88 802D73D8 00000000 */   nop   
/* 0FBD8C 802D73DC 080B5D11 */  j     .L802D7444
/* 0FBD90 802D73E0 0000102D */   daddu $v0, $zero, $zero

.L802D73E4:
/* 0FBD94 802D73E4 8E250000 */  lw    $a1, ($s1)
/* 0FBD98 802D73E8 26310004 */  addiu $s1, $s1, 4
/* 0FBD9C 802D73EC 0C0B1EAF */  jal   get_variable
/* 0FBDA0 802D73F0 0240202D */   daddu $a0, $s2, $zero
/* 0FBDA4 802D73F4 8E250000 */  lw    $a1, ($s1)
/* 0FBDA8 802D73F8 26310004 */  addiu $s1, $s1, 4
/* 0FBDAC 802D73FC 0240202D */  daddu $a0, $s2, $zero
/* 0FBDB0 802D7400 0C0B1EAF */  jal   get_variable
/* 0FBDB4 802D7404 0040802D */   daddu $s0, $v0, $zero
/* 0FBDB8 802D7408 0200202D */  daddu $a0, $s0, $zero
/* 0FBDBC 802D740C 8E260000 */  lw    $a2, ($s1)
/* 0FBDC0 802D7410 0C04C6C0 */  jal   init_got_item
/* 0FBDC4 802D7414 0040282D */   daddu $a1, $v0, $zero
/* 0FBDC8 802D7418 AE420074 */  sw    $v0, 0x74($s2)
/* 0FBDCC 802D741C 24020001 */  addiu $v0, $zero, 1
/* 0FBDD0 802D7420 080B5D10 */  j     .L802D7440
/* 0FBDD4 802D7424 AE420070 */   sw    $v0, 0x70($s2)

.L802D7428:
/* 0FBDD8 802D7428 8E440074 */  lw    $a0, 0x74($s2)
/* 0FBDDC 802D742C 0C04C3D6 */  jal   get_item_entity
/* 0FBDE0 802D7430 00000000 */   nop   
/* 0FBDE4 802D7434 0040182D */  daddu $v1, $v0, $zero
/* 0FBDE8 802D7438 10600002 */  beqz  $v1, .L802D7444
/* 0FBDEC 802D743C 24020002 */   addiu $v0, $zero, 2
.L802D7440:
/* 0FBDF0 802D7440 0000102D */  daddu $v0, $zero, $zero
.L802D7444:
/* 0FBDF4 802D7444 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0FBDF8 802D7448 8FB20018 */  lw    $s2, 0x18($sp)
/* 0FBDFC 802D744C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FBE00 802D7450 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FBE04 802D7454 03E00008 */  jr    $ra
/* 0FBE08 802D7458 27BD0020 */   addiu $sp, $sp, 0x20

/* 0FBE0C 802D745C 00000000 */  nop   
