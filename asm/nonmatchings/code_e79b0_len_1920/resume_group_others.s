.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel resume_group_others
/* 0E90CC 802C471C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E90D0 802C4720 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E90D4 802C4724 0080882D */  daddu $s1, $a0, $zero
/* 0E90D8 802C4728 AFB20018 */  sw    $s2, 0x18($sp)
/* 0E90DC 802C472C 00A0902D */  daddu $s2, $a1, $zero
/* 0E90E0 802C4730 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E90E4 802C4734 0000802D */  daddu $s0, $zero, $zero
/* 0E90E8 802C4738 AFBF001C */  sw    $ra, 0x1c($sp)
.L802C473C:
/* 0E90EC 802C473C 3C03802E */  lui   $v1, 0x802e
/* 0E90F0 802C4740 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E90F4 802C4744 00101080 */  sll   $v0, $s0, 2
/* 0E90F8 802C4748 00431021 */  addu  $v0, $v0, $v1
/* 0E90FC 802C474C 8C440000 */  lw    $a0, ($v0)
/* 0E9100 802C4750 50800006 */  beql  $a0, $zero, .L802C476C
/* 0E9104 802C4754 26100001 */   addiu $s0, $s0, 1
/* 0E9108 802C4758 50910004 */  beql  $a0, $s1, .L802C476C
/* 0E910C 802C475C 26100001 */   addiu $s0, $s0, 1
/* 0E9110 802C4760 0C0B10DF */  jal   resume_group_script
/* 0E9114 802C4764 0240282D */   daddu $a1, $s2, $zero
/* 0E9118 802C4768 26100001 */  addiu $s0, $s0, 1
.L802C476C:
/* 0E911C 802C476C 2A020080 */  slti  $v0, $s0, 0x80
/* 0E9120 802C4770 1440FFF2 */  bnez  $v0, .L802C473C
/* 0E9124 802C4774 00000000 */   nop   
/* 0E9128 802C4778 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E912C 802C477C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0E9130 802C4780 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E9134 802C4784 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E9138 802C4788 03E00008 */  jr    $ra
/* 0E913C 802C478C 27BD0020 */   addiu $sp, $sp, 0x20

