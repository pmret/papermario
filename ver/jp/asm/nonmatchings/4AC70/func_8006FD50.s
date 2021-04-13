.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006FD50
/* 4B150 8006FD50 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4B154 8006FD54 AFA40010 */  sw        $a0, 0x10($sp)
/* 4B158 8006FD58 AFA50014 */  sw        $a1, 0x14($sp)
/* 4B15C 8006FD5C AFA60018 */  sw        $a2, 0x18($sp)
/* 4B160 8006FD60 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4B164 8006FD64 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4B168 8006FD68 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4B16C 8006FD6C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4B170 8006FD70 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4B174 8006FD74 0C016885 */  jal       func_8005A214
/* 4B178 8006FD78 2404000D */   addiu    $a0, $zero, 0xd
/* 4B17C 8006FD7C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4B180 8006FD80 8FA50014 */  lw        $a1, 0x14($sp)
/* 4B184 8006FD84 8FA60018 */  lw        $a2, 0x18($sp)
/* 4B188 8006FD88 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4B18C 8006FD8C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4B190 8006FD90 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4B194 8006FD94 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4B198 8006FD98 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4B19C 8006FD9C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4B1A0 8006FDA0 3C018008 */  lui       $at, %hi(D_8007F318)
/* 4B1A4 8006FDA4 8C21F318 */  lw        $at, %lo(D_8007F318)($at)
/* 4B1A8 8006FDA8 00200008 */  jr        $at
/* 4B1AC 8006FDAC 00000000 */   nop
