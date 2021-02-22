.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80071C10
/* 4D010 80071C10 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D014 80071C14 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D018 80071C18 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D01C 80071C1C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D020 80071C20 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D024 80071C24 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D028 80071C28 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D02C 80071C2C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D030 80071C30 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D034 80071C34 0C016885 */  jal       func_8005A214
/* 4D038 80071C38 2404005F */   addiu    $a0, $zero, 0x5f
/* 4D03C 80071C3C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D040 80071C40 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D044 80071C44 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D048 80071C48 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D04C 80071C4C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D050 80071C50 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D054 80071C54 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D058 80071C58 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D05C 80071C5C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D060 80071C60 3C018008 */  lui       $at, %hi(D_8007FAC8)
/* 4D064 80071C64 8C21FAC8 */  lw        $at, %lo(D_8007FAC8)($at)
/* 4D068 80071C68 00200008 */  jr        $at
/* 4D06C 80071C6C 00000000 */   nop
