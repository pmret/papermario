.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FA70
/* 4AE70 8006FA70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4AE74 8006FA74 AFA40010 */  sw        $a0, 0x10($sp)
/* 4AE78 8006FA78 AFA50014 */  sw        $a1, 0x14($sp)
/* 4AE7C 8006FA7C AFA60018 */  sw        $a2, 0x18($sp)
/* 4AE80 8006FA80 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4AE84 8006FA84 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4AE88 8006FA88 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4AE8C 8006FA8C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4AE90 8006FA90 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4AE94 8006FA94 0C016959 */  jal       play_effect
/* 4AE98 8006FA98 24040005 */   addiu    $a0, $zero, 5
/* 4AE9C 8006FA9C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4AEA0 8006FAA0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4AEA4 8006FAA4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4AEA8 8006FAA8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4AEAC 8006FAAC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4AEB0 8006FAB0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4AEB4 8006FAB4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4AEB8 8006FAB8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4AEBC 8006FABC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4AEC0 8006FAC0 3C018008 */  lui       $at, %hi(D_8007F288)
/* 4AEC4 8006FAC4 8C21F288 */  lw        $at, %lo(D_8007F288)($at)
/* 4AEC8 8006FAC8 00200008 */  jr        $at
/* 4AECC 8006FACC 00000000 */   nop
