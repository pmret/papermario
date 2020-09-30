.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800722F0
/* 4D6F0 800722F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D6F4 800722F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D6F8 800722F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D6FC 800722FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4D700 80072300 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D704 80072304 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D708 80072308 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D70C 8007230C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D710 80072310 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D714 80072314 0C016959 */  jal       play_effect
/* 4D718 80072318 24040071 */   addiu    $a0, $zero, 0x71
/* 4D71C 8007231C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D720 80072320 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D724 80072324 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D728 80072328 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D72C 8007232C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D730 80072330 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D734 80072334 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D738 80072338 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D73C 8007233C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D740 80072340 3C018008 */  lui       $at, 0x8008
/* 4D744 80072344 8C21FCA8 */  lw        $at, -0x358($at)
/* 4D748 80072348 00200008 */  jr        $at
/* 4D74C 8007234C 00000000 */   nop      
