.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80248F9C
/* 13C2DC 80248F9C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 13C2E0 80248FA0 8FB10014 */  lw    $s1, 0x14($sp)
/* 13C2E4 80248FA4 8FB00010 */  lw    $s0, 0x10($sp)
/* 13C2E8 80248FA8 3C018027 */  lui   $at, 0x8027
/* 13C2EC 80248FAC AC22038C */  sw    $v0, 0x38c($at)
/* 13C2F0 80248FB0 3C018027 */  lui   $at, 0x8027
/* 13C2F4 80248FB4 AC220390 */  sw    $v0, 0x390($at)
/* 13C2F8 80248FB8 03E00008 */  jr    $ra
/* 13C2FC 80248FBC 27BD0020 */   addiu $sp, $sp, 0x20

/* 13C300 80248FC0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 13C304 80248FC4 AFB3001C */  sw    $s3, 0x1c($sp)
/* 13C308 80248FC8 0080982D */  daddu $s3, $a0, $zero
/* 13C30C 80248FCC AFBF0020 */  sw    $ra, 0x20($sp)
/* 13C310 80248FD0 AFB20018 */  sw    $s2, 0x18($sp)
/* 13C314 80248FD4 AFB10014 */  sw    $s1, 0x14($sp)
/* 13C318 80248FD8 0C091C15 */  jal   func_80247054
/* 13C31C 80248FDC AFB00010 */   sw    $s0, 0x10($sp)
/* 13C320 80248FE0 3C018027 */  lui   $at, 0x8027
/* 13C324 80248FE4 AC200398 */  sw    $zero, 0x398($at)
/* 13C328 80248FE8 3C018027 */  lui   $at, 0x8027
/* 13C32C 80248FEC AC20039C */  sw    $zero, 0x39c($at)
/* 13C330 80248FF0 3C018027 */  lui   $at, 0x8027
/* 13C334 80248FF4 AC2003A0 */  sw    $zero, 0x3a0($at)
/* 13C338 80248FF8 0C092363 */  jal   func_80248D8C
/* 13C33C 80248FFC 0000202D */   daddu $a0, $zero, $zero
/* 13C340 80249000 3C038027 */  lui   $v1, 0x8027
/* 13C344 80249004 84630180 */  lh    $v1, 0x180($v1)
