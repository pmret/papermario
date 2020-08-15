.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetNpcEffect
/* 0F4AC8 802D0118 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F4ACC 802D011C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F4AD0 802D0120 0080882D */  daddu $s1, $a0, $zero
/* 0F4AD4 802D0124 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F4AD8 802D0128 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F4ADC 802D012C AFB20018 */  sw    $s2, 0x18($sp)
/* 0F4AE0 802D0130 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F4AE4 802D0134 8E30000C */  lw    $s0, 0xc($s1)
/* 0F4AE8 802D0138 8E050000 */  lw    $a1, ($s0)
/* 0F4AEC 802D013C 0C0B1EAF */  jal   get_variable
/* 0F4AF0 802D0140 26100004 */   addiu $s0, $s0, 4
/* 0F4AF4 802D0144 8E050000 */  lw    $a1, ($s0)
/* 0F4AF8 802D0148 26100004 */  addiu $s0, $s0, 4
/* 0F4AFC 802D014C 0220202D */  daddu $a0, $s1, $zero
/* 0F4B00 802D0150 0C0B1EAF */  jal   get_variable
/* 0F4B04 802D0154 0040902D */   daddu $s2, $v0, $zero
/* 0F4B08 802D0158 0220202D */  daddu $a0, $s1, $zero
/* 0F4B0C 802D015C 8E050000 */  lw    $a1, ($s0)
/* 0F4B10 802D0160 0C0B1EAF */  jal   get_variable
/* 0F4B14 802D0164 0040982D */   daddu $s3, $v0, $zero
/* 0F4B18 802D0168 0220202D */  daddu $a0, $s1, $zero
/* 0F4B1C 802D016C 0240282D */  daddu $a1, $s2, $zero
/* 0F4B20 802D0170 0C0B36B0 */  jal   resolve_npc
/* 0F4B24 802D0174 0040802D */   daddu $s0, $v0, $zero
/* 0F4B28 802D0178 10400004 */  beqz  $v0, .L802D018C
/* 0F4B2C 802D017C 0040202D */   daddu $a0, $v0, $zero
/* 0F4B30 802D0180 0260282D */  daddu $a1, $s3, $zero
/* 0F4B34 802D0184 0C00F0F6 */  jal   func_8003C3D8
/* 0F4B38 802D0188 0200302D */   daddu $a2, $s0, $zero
.L802D018C:
/* 0F4B3C 802D018C 24020002 */  addiu $v0, $zero, 2
/* 0F4B40 802D0190 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F4B44 802D0194 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F4B48 802D0198 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F4B4C 802D019C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F4B50 802D01A0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F4B54 802D01A4 03E00008 */  jr    $ra
/* 0F4B58 802D01A8 27BD0028 */   addiu $sp, $sp, 0x28

