.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetItemFlags
/* 0FBB44 802D7194 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FBB48 802D7198 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FBB4C 802D719C 0080882D */  daddu $s1, $a0, $zero
/* 0FBB50 802D71A0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0FBB54 802D71A4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0FBB58 802D71A8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FBB5C 802D71AC 8E30000C */  lw    $s0, 0xc($s1)
/* 0FBB60 802D71B0 8E050000 */  lw    $a1, ($s0)
/* 0FBB64 802D71B4 0C0B1EAF */  jal   get_variable
/* 0FBB68 802D71B8 26100004 */   addiu $s0, $s0, 4
/* 0FBB6C 802D71BC 0220202D */  daddu $a0, $s1, $zero
/* 0FBB70 802D71C0 8E050004 */  lw    $a1, 4($s0)
/* 0FBB74 802D71C4 8E120000 */  lw    $s2, ($s0)
/* 0FBB78 802D71C8 0C0B1EAF */  jal   get_variable
/* 0FBB7C 802D71CC 0040882D */   daddu $s1, $v0, $zero
/* 0FBB80 802D71D0 0220202D */  daddu $a0, $s1, $zero
/* 0FBB84 802D71D4 0C04C3D6 */  jal   get_item_entity
/* 0FBB88 802D71D8 0040802D */   daddu $s0, $v0, $zero
/* 0FBB8C 802D71DC 12000004 */  beqz  $s0, .L802D71F0
/* 0FBB90 802D71E0 0040202D */   daddu $a0, $v0, $zero
/* 0FBB94 802D71E4 8C820000 */  lw    $v0, ($a0)
/* 0FBB98 802D71E8 080B5C7F */  j     .L802D71FC
/* 0FBB9C 802D71EC 00521025 */   or    $v0, $v0, $s2

.L802D71F0:
/* 0FBBA0 802D71F0 8C820000 */  lw    $v0, ($a0)
/* 0FBBA4 802D71F4 00121827 */  nor   $v1, $zero, $s2
/* 0FBBA8 802D71F8 00431024 */  and   $v0, $v0, $v1
.L802D71FC:
/* 0FBBAC 802D71FC AC820000 */  sw    $v0, ($a0)
/* 0FBBB0 802D7200 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0FBBB4 802D7204 8FB20018 */  lw    $s2, 0x18($sp)
/* 0FBBB8 802D7208 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FBBBC 802D720C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FBBC0 802D7210 24020002 */  addiu $v0, $zero, 2
/* 0FBBC4 802D7214 03E00008 */  jr    $ra
/* 0FBBC8 802D7218 27BD0020 */   addiu $sp, $sp, 0x20

/* 0FBBCC 802D721C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FBBD0 802D7220 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FBBD4 802D7224 0080882D */  daddu $s1, $a0, $zero
/* 0FBBD8 802D7228 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FBBDC 802D722C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FBBE0 802D7230 8E30000C */  lw    $s0, 0xc($s1)
/* 0FBBE4 802D7234 8E050000 */  lw    $a1, ($s0)
/* 0FBBE8 802D7238 0C0B1EAF */  jal   get_variable
/* 0FBBEC 802D723C 26100004 */   addiu $s0, $s0, 4
/* 0FBBF0 802D7240 0220202D */  daddu $a0, $s1, $zero
/* 0FBBF4 802D7244 8E050000 */  lw    $a1, ($s0)
/* 0FBBF8 802D7248 0C0B1EAF */  jal   get_variable
/* 0FBBFC 802D724C 0040802D */   daddu $s0, $v0, $zero
/* 0FBC00 802D7250 0200202D */  daddu $a0, $s0, $zero
/* 0FBC04 802D7254 0C04C3D6 */  jal   get_item_entity
/* 0FBC08 802D7258 0040802D */   daddu $s0, $v0, $zero
/* 0FBC0C 802D725C A050002F */  sb    $s0, 0x2f($v0)
/* 0FBC10 802D7260 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FBC14 802D7264 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FBC18 802D7268 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FBC1C 802D726C 24020002 */  addiu $v0, $zero, 2
/* 0FBC20 802D7270 03E00008 */  jr    $ra
/* 0FBC24 802D7274 27BD0020 */   addiu $sp, $sp, 0x20

