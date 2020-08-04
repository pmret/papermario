.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel bind_trigger_1
/* 0E8C58 802C42A8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0E8C5C 802C42AC 8FA20038 */  lw    $v0, 0x38($sp)
/* 0E8C60 802C42B0 8FA8003C */  lw    $t0, 0x3c($sp)
/* 0E8C64 802C42B4 24030001 */  addiu $v1, $zero, 1
/* 0E8C68 802C42B8 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0E8C6C 802C42BC AFA30018 */  sw    $v1, 0x18($sp)
/* 0E8C70 802C42C0 AFA20010 */  sw    $v0, 0x10($sp)
/* 0E8C74 802C42C4 0C0B1088 */  jal   bind_trigger
/* 0E8C78 802C42C8 AFA80014 */   sw    $t0, 0x14($sp)
/* 0E8C7C 802C42CC 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0E8C80 802C42D0 03E00008 */  jr    $ra
/* 0E8C84 802C42D4 27BD0028 */   addiu $sp, $sp, 0x28

