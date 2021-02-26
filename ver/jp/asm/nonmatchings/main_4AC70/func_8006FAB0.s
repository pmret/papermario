.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FAB0
/* 4AEB0 8006FAB0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4AEB4 8006FAB4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4AEB8 8006FAB8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4AEBC 8006FABC AFA60018 */  sw        $a2, 0x18($sp)
/* 4AEC0 8006FAC0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4AEC4 8006FAC4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4AEC8 8006FAC8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4AECC 8006FACC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4AED0 8006FAD0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4AED4 8006FAD4 0C016885 */  jal       func_8005A214
/* 4AED8 8006FAD8 24040006 */   addiu    $a0, $zero, 6
/* 4AEDC 8006FADC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4AEE0 8006FAE0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4AEE4 8006FAE4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4AEE8 8006FAE8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4AEEC 8006FAEC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4AEF0 8006FAF0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4AEF4 8006FAF4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4AEF8 8006FAF8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4AEFC 8006FAFC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4AF00 8006FB00 3C018008 */  lui       $at, %hi(D_8007F270)
/* 4AF04 8006FB04 8C21F270 */  lw        $at, %lo(D_8007F270)($at)
/* 4AF08 8006FB08 00200008 */  jr        $at
/* 4AF0C 8006FB0C 00000000 */   nop
