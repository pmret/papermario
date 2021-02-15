.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel initialize_collision
/* 36394 8005AF94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 36398 8005AF98 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3639C 8005AF9C 3C01800B */  lui       $at, %hi(D_800B42EC)
/* 363A0 8005AFA0 A42042EC */  sh        $zero, %lo(D_800B42EC)($at)
/* 363A4 8005AFA4 3C01800E */  lui       $at, %hi(D_800D91DC)
/* 363A8 8005AFA8 A42091DC */  sh        $zero, %lo(D_800D91DC)($at)
/* 363AC 8005AFAC 0C00AB5D */  jal       collision_heap_create
/* 363B0 8005AFB0 00000000 */   nop
/* 363B4 8005AFB4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 363B8 8005AFB8 03E00008 */  jr        $ra
/* 363BC 8005AFBC 27BD0018 */   addiu    $sp, $sp, 0x18
