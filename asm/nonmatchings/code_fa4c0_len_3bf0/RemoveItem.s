.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel RemoveItem
/* 0FB54C 802D6B9C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FB550 802D6BA0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FB554 802D6BA4 0080882D */  daddu $s1, $a0, $zero
/* 0FB558 802D6BA8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0FB55C 802D6BAC AFB20018 */  sw    $s2, 0x18($sp)
/* 0FB560 802D6BB0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FB564 802D6BB4 8E30000C */  lw    $s0, 0xc($s1)
/* 0FB568 802D6BB8 8E050000 */  lw    $a1, ($s0)
/* 0FB56C 802D6BBC 0C0B1EAF */  jal   get_variable
/* 0FB570 802D6BC0 26100004 */   addiu $s0, $s0, 4
/* 0FB574 802D6BC4 0040282D */  daddu $a1, $v0, $zero
/* 0FB578 802D6BC8 0000182D */  daddu $v1, $zero, $zero
/* 0FB57C 802D6BCC 3C068011 */  lui   $a2, 0x8011
/* 0FB580 802D6BD0 24C6F290 */  addiu $a2, $a2, -0xd70
/* 0FB584 802D6BD4 00C0202D */  daddu $a0, $a2, $zero
/* 0FB588 802D6BD8 8E120000 */  lw    $s2, ($s0)
.L802D6BDC:
/* 0FB58C 802D6BDC 848201B4 */  lh    $v0, 0x1b4($a0)
/* 0FB590 802D6BE0 10450006 */  beq   $v0, $a1, .L802D6BFC
/* 0FB594 802D6BE4 2402000A */   addiu $v0, $zero, 0xa
/* 0FB598 802D6BE8 24630001 */  addiu $v1, $v1, 1
/* 0FB59C 802D6BEC 2862000A */  slti  $v0, $v1, 0xa
/* 0FB5A0 802D6BF0 1440FFFA */  bnez  $v0, .L802D6BDC
/* 0FB5A4 802D6BF4 24840002 */   addiu $a0, $a0, 2
/* 0FB5A8 802D6BF8 2402000A */  addiu $v0, $zero, 0xa
.L802D6BFC:
/* 0FB5AC 802D6BFC 10620002 */  beq   $v1, $v0, .L802D6C08
/* 0FB5B0 802D6C00 2410FFFF */   addiu $s0, $zero, -1
/* 0FB5B4 802D6C04 0060802D */  daddu $s0, $v1, $zero
.L802D6C08:
/* 0FB5B8 802D6C08 06000003 */  bltz  $s0, .L802D6C18
/* 0FB5BC 802D6C0C 00031040 */   sll   $v0, $v1, 1
/* 0FB5C0 802D6C10 00461021 */  addu  $v0, $v0, $a2
/* 0FB5C4 802D6C14 A44001B4 */  sh    $zero, 0x1b4($v0)
.L802D6C18:
/* 0FB5C8 802D6C18 0C039DB3 */  jal   sort_items
/* 0FB5CC 802D6C1C 00000000 */   nop   
/* 0FB5D0 802D6C20 0220202D */  daddu $a0, $s1, $zero
/* 0FB5D4 802D6C24 0240282D */  daddu $a1, $s2, $zero
/* 0FB5D8 802D6C28 0C0B2026 */  jal   set_variable
/* 0FB5DC 802D6C2C 0200302D */   daddu $a2, $s0, $zero
/* 0FB5E0 802D6C30 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0FB5E4 802D6C34 8FB20018 */  lw    $s2, 0x18($sp)
/* 0FB5E8 802D6C38 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FB5EC 802D6C3C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FB5F0 802D6C40 24020002 */  addiu $v0, $zero, 2
/* 0FB5F4 802D6C44 03E00008 */  jr    $ra
/* 0FB5F8 802D6C48 27BD0020 */   addiu $sp, $sp, 0x20

