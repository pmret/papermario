.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070C50
/* 4C050 80070C50 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C054 80070C54 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C058 80070C58 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C05C 80070C5C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C060 80070C60 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C064 80070C64 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C068 80070C68 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C06C 80070C6C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C070 80070C70 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C074 80070C74 0C016885 */  jal       func_8005A214
/* 4C078 80070C78 24040035 */   addiu    $a0, $zero, 0x35
/* 4C07C 80070C7C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C080 80070C80 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C084 80070C84 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C088 80070C88 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C08C 80070C8C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C090 80070C90 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C094 80070C94 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C098 80070C98 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C09C 80070C9C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C0A0 80070CA0 3C018008 */  lui       $at, %hi(D_8007F6D8)
/* 4C0A4 80070CA4 8C21F6D8 */  lw        $at, %lo(D_8007F6D8)($at)
/* 4C0A8 80070CA8 00200008 */  jr        $at
/* 4C0AC 80070CAC 00000000 */   nop
