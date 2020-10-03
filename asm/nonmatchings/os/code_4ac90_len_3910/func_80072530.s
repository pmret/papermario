.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072530
/* 4D930 80072530 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D934 80072534 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D938 80072538 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D93C 8007253C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D940 80072540 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D944 80072544 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D948 80072548 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D94C 8007254C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D950 80072550 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D954 80072554 0C016959 */  jal       play_effect
/* 4D958 80072558 24040077 */   addiu    $a0, $zero, 0x77
/* 4D95C 8007255C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D960 80072560 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D964 80072564 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D968 80072568 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D96C 8007256C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D970 80072570 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D974 80072574 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D978 80072578 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D97C 8007257C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D980 80072580 3C018008 */  lui       $at, 0x8008
/* 4D984 80072584 8C21FD38 */  lw        $at, -0x2c8($at)
/* 4D988 80072588 00200008 */  jr        $at
/* 4D98C 8007258C 00000000 */   nop      
