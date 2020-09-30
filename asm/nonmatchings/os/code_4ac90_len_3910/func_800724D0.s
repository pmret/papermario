.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800724D0
/* 4D8D0 800724D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D8D4 800724D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D8D8 800724D8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D8DC 800724DC AFA60018 */  sw        $a2, 0x18($sp)
/* 4D8E0 800724E0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D8E4 800724E4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D8E8 800724E8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D8EC 800724EC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D8F0 800724F0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D8F4 800724F4 0C016959 */  jal       play_effect
/* 4D8F8 800724F8 24040076 */   addiu    $a0, $zero, 0x76
/* 4D8FC 800724FC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D900 80072500 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D904 80072504 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D908 80072508 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D90C 8007250C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D910 80072510 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D914 80072514 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D918 80072518 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D91C 8007251C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D920 80072520 3C018008 */  lui       $at, 0x8008
/* 4D924 80072524 8C21FD20 */  lw        $at, -0x2e0($at)
/* 4D928 80072528 00200008 */  jr        $at
/* 4D92C 8007252C 00000000 */   nop      
