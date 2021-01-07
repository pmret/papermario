.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800725F0
/* 4D9F0 800725F0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D9F4 800725F4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D9F8 800725F8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D9FC 800725FC AFA60018 */  sw        $a2, 0x18($sp)
/* 4DA00 80072600 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4DA04 80072604 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4DA08 80072608 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4DA0C 8007260C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4DA10 80072610 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4DA14 80072614 0C016959 */  jal       play_effect
/* 4DA18 80072618 24040079 */   addiu    $a0, $zero, 0x79
/* 4DA1C 8007261C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4DA20 80072620 8FA50014 */  lw        $a1, 0x14($sp)
/* 4DA24 80072624 8FA60018 */  lw        $a2, 0x18($sp)
/* 4DA28 80072628 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4DA2C 8007262C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4DA30 80072630 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4DA34 80072634 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4DA38 80072638 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4DA3C 8007263C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4DA40 80072640 3C018008 */  lui       $at, %hi(D_8007FD68)
/* 4DA44 80072644 8C21FD68 */  lw        $at, %lo(D_8007FD68)($at)
/* 4DA48 80072648 00200008 */  jr        $at
/* 4DA4C 8007264C 00000000 */   nop      
