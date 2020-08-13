.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel initialize_collision
/* 036394 8005AF94 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 036398 8005AF98 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03639C 8005AF9C 3C01800B */  lui   $at, 0x800b
/* 0363A0 8005AFA0 A42042EC */  sh    $zero, 0x42ec($at)
/* 0363A4 8005AFA4 3C01800E */  lui   $at, 0x800e
/* 0363A8 8005AFA8 A42091DC */  sh    $zero, -0x6e24($at)
/* 0363AC 8005AFAC 0C00AB5D */  jal   collision_heap_create
/* 0363B0 8005AFB0 00000000 */   nop   
/* 0363B4 8005AFB4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0363B8 8005AFB8 03E00008 */  jr    $ra
/* 0363BC 8005AFBC 27BD0018 */   addiu $sp, $sp, 0x18

