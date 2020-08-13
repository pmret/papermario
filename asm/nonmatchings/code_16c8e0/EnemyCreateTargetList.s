.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel EnemyCreateTargetList
/* 19CBF0 8026E310 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19CBF4 8026E314 0080102D */  daddu $v0, $a0, $zero
/* 19CBF8 8026E318 AFBF0014 */  sw    $ra, 0x14($sp)
/* 19CBFC 8026E31C AFB00010 */  sw    $s0, 0x10($sp)
/* 19CC00 8026E320 8C440148 */  lw    $a0, 0x148($v0)
/* 19CC04 8026E324 0C09A75B */  jal   get_actor
/* 19CC08 8026E328 8C50000C */   lw    $s0, 0xc($v0)
/* 19CC0C 8026E32C 8E030000 */  lw    $v1, ($s0)
/* 19CC10 8026E330 3C01800E */  lui   $at, 0x800e
/* 19CC14 8026E334 AC23C1F4 */  sw    $v1, -0x3e0c($at)
/* 19CC18 8026E338 0C098C12 */  jal   enemy_create_target_list
/* 19CC1C 8026E33C 0040202D */   daddu $a0, $v0, $zero
/* 19CC20 8026E340 8FBF0014 */  lw    $ra, 0x14($sp)
/* 19CC24 8026E344 8FB00010 */  lw    $s0, 0x10($sp)
/* 19CC28 8026E348 24020002 */  addiu $v0, $zero, 2
/* 19CC2C 8026E34C 03E00008 */  jr    $ra
/* 19CC30 8026E350 27BD0018 */   addiu $sp, $sp, 0x18

