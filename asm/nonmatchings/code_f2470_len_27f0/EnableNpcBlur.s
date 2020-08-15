.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel EnableNpcBlur
/* 0F3C9C 802CF2EC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F3CA0 802CF2F0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F3CA4 802CF2F4 0080882D */  daddu $s1, $a0, $zero
/* 0F3CA8 802CF2F8 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F3CAC 802CF2FC AFB00010 */  sw    $s0, 0x10($sp)
/* 0F3CB0 802CF300 8E30000C */  lw    $s0, 0xc($s1)
/* 0F3CB4 802CF304 8E050000 */  lw    $a1, ($s0)
/* 0F3CB8 802CF308 0C0B1EAF */  jal   get_variable
/* 0F3CBC 802CF30C 26100004 */   addiu $s0, $s0, 4
/* 0F3CC0 802CF310 0220202D */  daddu $a0, $s1, $zero
/* 0F3CC4 802CF314 8E050000 */  lw    $a1, ($s0)
/* 0F3CC8 802CF318 0C0B1EAF */  jal   get_variable
/* 0F3CCC 802CF31C 0040802D */   daddu $s0, $v0, $zero
/* 0F3CD0 802CF320 0220202D */  daddu $a0, $s1, $zero
/* 0F3CD4 802CF324 0200282D */  daddu $a1, $s0, $zero
/* 0F3CD8 802CF328 0C0B36B0 */  jal   resolve_npc
/* 0F3CDC 802CF32C 0040802D */   daddu $s0, $v0, $zero
/* 0F3CE0 802CF330 5040000A */  beql  $v0, $zero, .L802CF35C
/* 0F3CE4 802CF334 24020002 */   addiu $v0, $zero, 2
/* 0F3CE8 802CF338 12000005 */  beqz  $s0, .L802CF350
/* 0F3CEC 802CF33C 00000000 */   nop   
/* 0F3CF0 802CF340 0C00EB49 */  jal   enable_npc_blur
/* 0F3CF4 802CF344 0040202D */   daddu $a0, $v0, $zero
/* 0F3CF8 802CF348 080B3CD7 */  j     .L802CF35C
/* 0F3CFC 802CF34C 24020002 */   addiu $v0, $zero, 2

.L802CF350:
/* 0F3D00 802CF350 0C00EB6B */  jal   disable_npc_blur
/* 0F3D04 802CF354 0040202D */   daddu $a0, $v0, $zero
/* 0F3D08 802CF358 24020002 */  addiu $v0, $zero, 2
.L802CF35C:
/* 0F3D0C 802CF35C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F3D10 802CF360 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F3D14 802CF364 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F3D18 802CF368 03E00008 */  jr    $ra
/* 0F3D1C 802CF36C 27BD0020 */   addiu $sp, $sp, 0x20

