.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071C70
/* 4D070 80071C70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D074 80071C74 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D078 80071C78 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D07C 80071C7C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D080 80071C80 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D084 80071C84 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D088 80071C88 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D08C 80071C8C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D090 80071C90 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D094 80071C94 0C016885 */  jal       func_8005A214
/* 4D098 80071C98 24040060 */   addiu    $a0, $zero, 0x60
/* 4D09C 80071C9C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D0A0 80071CA0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D0A4 80071CA4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D0A8 80071CA8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D0AC 80071CAC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D0B0 80071CB0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D0B4 80071CB4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D0B8 80071CB8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D0BC 80071CBC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D0C0 80071CC0 3C018008 */  lui       $at, %hi(D_8007FAE0)
/* 4D0C4 80071CC4 8C21FAE0 */  lw        $at, %lo(D_8007FAE0)($at)
/* 4D0C8 80071CC8 00200008 */  jr        $at
/* 4D0CC 80071CCC 00000000 */   nop
