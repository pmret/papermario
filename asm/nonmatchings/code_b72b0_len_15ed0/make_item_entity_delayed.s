.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel make_item_entity_delayed
/* 0C81C8 80131AC8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C81CC 80131ACC 8FA30038 */  lw    $v1, 0x38($sp)
/* 0C81D0 80131AD0 8FA8003C */  lw    $t0, 0x3c($sp)
/* 0C81D4 80131AD4 8FA90040 */  lw    $t1, 0x40($sp)
/* 0C81D8 80131AD8 2402FFFF */  addiu $v0, $zero, -1
/* 0C81DC 80131ADC AFBF0020 */  sw    $ra, 0x20($sp)
/* 0C81E0 80131AE0 AFA20018 */  sw    $v0, 0x18($sp)
/* 0C81E4 80131AE4 AFA30010 */  sw    $v1, 0x10($sp)
/* 0C81E8 80131AE8 AFA80014 */  sw    $t0, 0x14($sp)
/* 0C81EC 80131AEC 0C04C4FD */  jal   make_item_entity
/* 0C81F0 80131AF0 AFA9001C */   sw    $t1, 0x1c($sp)
/* 0C81F4 80131AF4 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0C81F8 80131AF8 03E00008 */  jr    $ra
/* 0C81FC 80131AFC 27BD0028 */   addiu $sp, $sp, 0x28

