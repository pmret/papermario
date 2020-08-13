.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel FindItem
/* 0FB4C8 802D6B18 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FB4CC 802D6B1C AFB10014 */  sw    $s1, 0x14($sp)
/* 0FB4D0 802D6B20 0080882D */  daddu $s1, $a0, $zero
/* 0FB4D4 802D6B24 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FB4D8 802D6B28 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FB4DC 802D6B2C 8E30000C */  lw    $s0, 0xc($s1)
/* 0FB4E0 802D6B30 8E050000 */  lw    $a1, ($s0)
/* 0FB4E4 802D6B34 0C0B1EAF */  jal   get_variable
/* 0FB4E8 802D6B38 26100004 */   addiu $s0, $s0, 4
/* 0FB4EC 802D6B3C 0040302D */  daddu $a2, $v0, $zero
/* 0FB4F0 802D6B40 0000182D */  daddu $v1, $zero, $zero
/* 0FB4F4 802D6B44 3C048011 */  lui   $a0, 0x8011
/* 0FB4F8 802D6B48 2484F290 */  addiu $a0, $a0, -0xd70
/* 0FB4FC 802D6B4C 8E050000 */  lw    $a1, ($s0)
.L802D6B50:
/* 0FB500 802D6B50 848201B4 */  lh    $v0, 0x1b4($a0)
/* 0FB504 802D6B54 10460006 */  beq   $v0, $a2, .L802D6B70
/* 0FB508 802D6B58 2402000A */   addiu $v0, $zero, 0xa
/* 0FB50C 802D6B5C 24630001 */  addiu $v1, $v1, 1
/* 0FB510 802D6B60 2862000A */  slti  $v0, $v1, 0xa
/* 0FB514 802D6B64 1440FFFA */  bnez  $v0, .L802D6B50
/* 0FB518 802D6B68 24840002 */   addiu $a0, $a0, 2
/* 0FB51C 802D6B6C 2402000A */  addiu $v0, $zero, 0xa
.L802D6B70:
/* 0FB520 802D6B70 10620002 */  beq   $v1, $v0, .L802D6B7C
/* 0FB524 802D6B74 2406FFFF */   addiu $a2, $zero, -1
/* 0FB528 802D6B78 0060302D */  daddu $a2, $v1, $zero
.L802D6B7C:
/* 0FB52C 802D6B7C 0C0B2026 */  jal   set_variable
/* 0FB530 802D6B80 0220202D */   daddu $a0, $s1, $zero
/* 0FB534 802D6B84 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FB538 802D6B88 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FB53C 802D6B8C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FB540 802D6B90 24020002 */  addiu $v0, $zero, 2
/* 0FB544 802D6B94 03E00008 */  jr    $ra
/* 0FB548 802D6B98 27BD0020 */   addiu $sp, $sp, 0x20

