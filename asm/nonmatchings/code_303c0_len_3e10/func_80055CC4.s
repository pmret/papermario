.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80055CC4
/* 0310C4 80055CC4 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0310C8 80055CC8 AFA40010 */  sw    $a0, 0x10($sp)
/* 0310CC 80055CCC 27A40010 */  addiu $a0, $sp, 0x10
/* 0310D0 80055CD0 AFBF0030 */  sw    $ra, 0x30($sp)
/* 0310D4 80055CD4 0C01425C */  jal   func_80050970
/* 0310D8 80055CD8 AFA50020 */   sw    $a1, 0x20($sp)
/* 0310DC 80055CDC 8FBF0030 */  lw    $ra, 0x30($sp)
/* 0310E0 80055CE0 03E00008 */  jr    $ra
/* 0310E4 80055CE4 27BD0038 */   addiu $sp, $sp, 0x38

