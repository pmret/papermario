.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_add
/* 0EA1B4 802C5804 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA1B8 802C5808 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA1BC 802C580C 0080882D */  daddu $s1, $a0, $zero
/* 0EA1C0 802C5810 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EA1C4 802C5814 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EA1C8 802C5818 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA1CC 802C581C 8E22000C */  lw    $v0, 0xc($s1)
/* 0EA1D0 802C5820 8C450004 */  lw    $a1, 4($v0)
/* 0EA1D4 802C5824 0C0B1EAF */  jal   get_variable
/* 0EA1D8 802C5828 8C520000 */   lw    $s2, ($v0)
/* 0EA1DC 802C582C 0040802D */  daddu $s0, $v0, $zero
/* 0EA1E0 802C5830 0220202D */  daddu $a0, $s1, $zero
/* 0EA1E4 802C5834 0C0B1EAF */  jal   get_variable
/* 0EA1E8 802C5838 0240282D */   daddu $a1, $s2, $zero
/* 0EA1EC 802C583C 0220202D */  daddu $a0, $s1, $zero
/* 0EA1F0 802C5840 0240282D */  daddu $a1, $s2, $zero
/* 0EA1F4 802C5844 0C0B2026 */  jal   set_variable
/* 0EA1F8 802C5848 02023021 */   addu  $a2, $s0, $v0
/* 0EA1FC 802C584C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EA200 802C5850 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EA204 802C5854 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA208 802C5858 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA20C 802C585C 24020002 */  addiu $v0, $zero, 2
/* 0EA210 802C5860 03E00008 */  jr    $ra
/* 0EA214 802C5864 27BD0020 */   addiu $sp, $sp, 0x20

