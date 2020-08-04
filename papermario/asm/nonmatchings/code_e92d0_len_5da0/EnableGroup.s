.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel EnableGroup
/* 0EE548 802C9B98 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EE54C 802C9B9C AFB20018 */  sw    $s2, 0x18($sp)
/* 0EE550 802C9BA0 0080902D */  daddu $s2, $a0, $zero
/* 0EE554 802C9BA4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EE558 802C9BA8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EE55C 802C9BAC AFB00010 */  sw    $s0, 0x10($sp)
/* 0EE560 802C9BB0 8E51000C */  lw    $s1, 0xc($s2)
/* 0EE564 802C9BB4 0C0B1EAF */  jal   get_variable
/* 0EE568 802C9BB8 8E250000 */   lw    $a1, ($s1)
/* 0EE56C 802C9BBC 0C046C24 */  jal   func_8011B090
/* 0EE570 802C9BC0 0040202D */   daddu $a0, $v0, $zero
/* 0EE574 802C9BC4 0040802D */  daddu $s0, $v0, $zero
/* 0EE578 802C9BC8 2402FFFF */  addiu $v0, $zero, -1
/* 0EE57C 802C9BCC 16020007 */  bne   $s0, $v0, .L802C9BEC
/* 0EE580 802C9BD0 00000000 */   nop   
/* 0EE584 802C9BD4 3C04802D */  lui   $a0, 0x802d
/* 0EE588 802C9BD8 24849288 */  addiu $a0, $a0, -0x6d78
/* 0EE58C 802C9BDC 0C0B2568 */  jal   func_802C95A0
/* 0EE590 802C9BE0 0240282D */   daddu $a1, $s2, $zero
/* 0EE594 802C9BE4 080B2716 */  j     .L802C9C58
/* 0EE598 802C9BE8 24020002 */   addiu $v0, $zero, 2

.L802C9BEC:
/* 0EE59C 802C9BEC 8E250004 */  lw    $a1, 4($s1)
/* 0EE5A0 802C9BF0 0C0B1EAF */  jal   get_variable
/* 0EE5A4 802C9BF4 0240202D */   daddu $a0, $s2, $zero
/* 0EE5A8 802C9BF8 0200202D */  daddu $a0, $s0, $zero
/* 0EE5AC 802C9BFC 0C046C70 */  jal   func_8011B1C0
/* 0EE5B0 802C9C00 0040902D */   daddu $s2, $v0, $zero
/* 0EE5B4 802C9C04 0040882D */  daddu $s1, $v0, $zero
/* 0EE5B8 802C9C08 9230009C */  lbu   $s0, 0x9c($s1)
/* 0EE5BC 802C9C0C 9222009D */  lbu   $v0, 0x9d($s1)
/* 0EE5C0 802C9C10 0050102A */  slt   $v0, $v0, $s0
/* 0EE5C4 802C9C14 14400010 */  bnez  $v0, .L802C9C58
/* 0EE5C8 802C9C18 24020002 */   addiu $v0, $zero, 2
.L802C9C1C:
/* 0EE5CC 802C9C1C 0C046B4C */  jal   get_model_from_list_index
/* 0EE5D0 802C9C20 0200202D */   daddu $a0, $s0, $zero
/* 0EE5D4 802C9C24 12400004 */  beqz  $s2, .L802C9C38
/* 0EE5D8 802C9C28 0040182D */   daddu $v1, $v0, $zero
/* 0EE5DC 802C9C2C 94620000 */  lhu   $v0, ($v1)
/* 0EE5E0 802C9C30 080B2710 */  j     .L802C9C40
/* 0EE5E4 802C9C34 3042FFFD */   andi  $v0, $v0, 0xfffd

.L802C9C38:
/* 0EE5E8 802C9C38 94620000 */  lhu   $v0, ($v1)
/* 0EE5EC 802C9C3C 34420002 */  ori   $v0, $v0, 2
.L802C9C40:
/* 0EE5F0 802C9C40 A4620000 */  sh    $v0, ($v1)
/* 0EE5F4 802C9C44 9222009D */  lbu   $v0, 0x9d($s1)
/* 0EE5F8 802C9C48 26100001 */  addiu $s0, $s0, 1
/* 0EE5FC 802C9C4C 0050102A */  slt   $v0, $v0, $s0
/* 0EE600 802C9C50 1040FFF2 */  beqz  $v0, .L802C9C1C
/* 0EE604 802C9C54 24020002 */   addiu $v0, $zero, 2
.L802C9C58:
/* 0EE608 802C9C58 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EE60C 802C9C5C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EE610 802C9C60 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EE614 802C9C64 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EE618 802C9C68 03E00008 */  jr    $ra
/* 0EE61C 802C9C6C 27BD0020 */   addiu $sp, $sp, 0x20

/* 0EE620 802C9C70 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EE624 802C9C74 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EE628 802C9C78 0080882D */  daddu $s1, $a0, $zero
/* 0EE62C 802C9C7C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EE630 802C9C80 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EE634 802C9C84 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EE638 802C9C88 8E30000C */  lw    $s0, 0xc($s1)
/* 0EE63C 802C9C8C 8E050000 */  lw    $a1, ($s0)
/* 0EE640 802C9C90 0C0B1EAF */  jal   get_variable
/* 0EE644 802C9C94 26100004 */   addiu $s0, $s0, 4
/* 0EE648 802C9C98 8E050000 */  lw    $a1, ($s0)
/* 0EE64C 802C9C9C 26100004 */  addiu $s0, $s0, 4
/* 0EE650 802C9CA0 0220202D */  daddu $a0, $s1, $zero
/* 0EE654 802C9CA4 0C0B1EAF */  jal   get_variable
/* 0EE658 802C9CA8 0040902D */   daddu $s2, $v0, $zero
/* 0EE65C 802C9CAC 0220202D */  daddu $a0, $s1, $zero
/* 0EE660 802C9CB0 8E050000 */  lw    $a1, ($s0)
/* 0EE664 802C9CB4 0C0B1EAF */  jal   get_variable
/* 0EE668 802C9CB8 0040802D */   daddu $s0, $v0, $zero
/* 0EE66C 802C9CBC 0240202D */  daddu $a0, $s2, $zero
/* 0EE670 802C9CC0 3205FFFF */  andi  $a1, $s0, 0xffff
/* 0EE674 802C9CC4 0C047059 */  jal   func_8011C164
/* 0EE678 802C9CC8 0040302D */   daddu $a2, $v0, $zero
/* 0EE67C 802C9CCC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EE680 802C9CD0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EE684 802C9CD4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EE688 802C9CD8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EE68C 802C9CDC 24020002 */  addiu $v0, $zero, 2
/* 0EE690 802C9CE0 03E00008 */  jr    $ra
/* 0EE694 802C9CE4 27BD0020 */   addiu $sp, $sp, 0x20

