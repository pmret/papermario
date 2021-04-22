.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072510
/* 4D910 80072510 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D914 80072514 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D918 80072518 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D91C 8007251C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D920 80072520 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D924 80072524 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D928 80072528 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D92C 8007252C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D930 80072530 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D934 80072534 0C016885 */  jal       func_8005A214
/* 4D938 80072538 24040077 */   addiu    $a0, $zero, 0x77
/* 4D93C 8007253C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D940 80072540 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D944 80072544 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D948 80072548 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D94C 8007254C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D950 80072550 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D954 80072554 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D958 80072558 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D95C 8007255C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D960 80072560 3C018008 */  lui       $at, %hi(D_8007FD08)
/* 4D964 80072564 8C21FD08 */  lw        $at, %lo(D_8007FD08)($at)
/* 4D968 80072568 00200008 */  jr        $at
/* 4D96C 8007256C 00000000 */   nop
