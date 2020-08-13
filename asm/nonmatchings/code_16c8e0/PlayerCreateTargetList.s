.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel PlayerCreateTargetList
/* 19CBAC 8026E2CC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19CBB0 8026E2D0 0080102D */  daddu $v0, $a0, $zero
/* 19CBB4 8026E2D4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 19CBB8 8026E2D8 AFB00010 */  sw    $s0, 0x10($sp)
/* 19CBBC 8026E2DC 8C440148 */  lw    $a0, 0x148($v0)
/* 19CBC0 8026E2E0 0C09A75B */  jal   get_actor
/* 19CBC4 8026E2E4 8C50000C */   lw    $s0, 0xc($v0)
/* 19CBC8 8026E2E8 8E030000 */  lw    $v1, ($s0)
/* 19CBCC 8026E2EC 3C01800E */  lui   $at, 0x800e
/* 19CBD0 8026E2F0 AC23C1F4 */  sw    $v1, -0x3e0c($at)
/* 19CBD4 8026E2F4 0C098C0B */  jal   player_create_target_list
/* 19CBD8 8026E2F8 0040202D */   daddu $a0, $v0, $zero
/* 19CBDC 8026E2FC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 19CBE0 8026E300 8FB00010 */  lw    $s0, 0x10($sp)
/* 19CBE4 8026E304 24020002 */  addiu $v0, $zero, 2
/* 19CBE8 8026E308 03E00008 */  jr    $ra
/* 19CBEC 8026E30C 27BD0018 */   addiu $sp, $sp, 0x18

