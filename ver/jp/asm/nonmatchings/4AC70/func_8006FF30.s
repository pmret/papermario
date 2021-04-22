.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FF30
/* 4B330 8006FF30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B334 8006FF34 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B338 8006FF38 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B33C 8006FF3C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B340 8006FF40 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B344 8006FF44 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B348 8006FF48 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B34C 8006FF4C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B350 8006FF50 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B354 8006FF54 0C016885 */  jal       func_8005A214
/* 4B358 8006FF58 24040012 */   addiu    $a0, $zero, 0x12
/* 4B35C 8006FF5C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B360 8006FF60 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B364 8006FF64 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B368 8006FF68 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B36C 8006FF6C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B370 8006FF70 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B374 8006FF74 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B378 8006FF78 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B37C 8006FF7C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B380 8006FF80 3C018008 */  lui       $at, %hi(D_8007F390)
/* 4B384 8006FF84 8C21F390 */  lw        $at, %lo(D_8007F390)($at)
/* 4B388 8006FF88 00200008 */  jr        $at
/* 4B38C 8006FF8C 00000000 */   nop
