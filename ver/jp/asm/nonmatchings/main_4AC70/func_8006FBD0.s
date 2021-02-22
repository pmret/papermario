.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FBD0
/* 4AFD0 8006FBD0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4AFD4 8006FBD4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4AFD8 8006FBD8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4AFDC 8006FBDC AFA60018 */  sw        $a2, 0x18($sp)
/* 4AFE0 8006FBE0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4AFE4 8006FBE4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4AFE8 8006FBE8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4AFEC 8006FBEC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4AFF0 8006FBF0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4AFF4 8006FBF4 0C016885 */  jal       func_8005A214
/* 4AFF8 8006FBF8 24040009 */   addiu    $a0, $zero, 9
/* 4AFFC 8006FBFC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B000 8006FC00 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B004 8006FC04 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B008 8006FC08 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B00C 8006FC0C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B010 8006FC10 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B014 8006FC14 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B018 8006FC18 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B01C 8006FC1C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B020 8006FC20 3C018008 */  lui       $at, %hi(D_8007F2B8)
/* 4B024 8006FC24 8C21F2B8 */  lw        $at, %lo(D_8007F2B8)($at)
/* 4B028 8006FC28 00200008 */  jr        $at
/* 4B02C 8006FC2C 00000000 */   nop
