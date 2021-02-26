.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FC30
/* 4B030 8006FC30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B034 8006FC34 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B038 8006FC38 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B03C 8006FC3C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B040 8006FC40 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B044 8006FC44 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B048 8006FC48 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B04C 8006FC4C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B050 8006FC50 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B054 8006FC54 0C016885 */  jal       func_8005A214
/* 4B058 8006FC58 2404000A */   addiu    $a0, $zero, 0xa
/* 4B05C 8006FC5C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B060 8006FC60 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B064 8006FC64 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B068 8006FC68 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B06C 8006FC6C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B070 8006FC70 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B074 8006FC74 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B078 8006FC78 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B07C 8006FC7C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B080 8006FC80 3C018008 */  lui       $at, %hi(D_8007F2D0)
/* 4B084 8006FC84 8C21F2D0 */  lw        $at, %lo(D_8007F2D0)($at)
/* 4B088 8006FC88 00200008 */  jr        $at
/* 4B08C 8006FC8C 00000000 */   nop
