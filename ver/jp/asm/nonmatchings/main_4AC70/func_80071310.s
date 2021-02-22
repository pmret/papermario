.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071310
/* 4C710 80071310 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C714 80071314 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C718 80071318 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C71C 8007131C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C720 80071320 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C724 80071324 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C728 80071328 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C72C 8007132C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C730 80071330 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C734 80071334 0C016885 */  jal       func_8005A214
/* 4C738 80071338 24040047 */   addiu    $a0, $zero, 0x47
/* 4C73C 8007133C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C740 80071340 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C744 80071344 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C748 80071348 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C74C 8007134C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C750 80071350 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C754 80071354 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C758 80071358 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C75C 8007135C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C760 80071360 3C018008 */  lui       $at, %hi(D_8007F888)
/* 4C764 80071364 8C21F888 */  lw        $at, %lo(D_8007F888)($at)
/* 4C768 80071368 00200008 */  jr        $at
/* 4C76C 8007136C 00000000 */   nop
