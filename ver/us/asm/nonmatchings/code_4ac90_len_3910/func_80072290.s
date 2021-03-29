.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072290
/* 4D690 80072290 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D694 80072294 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D698 80072298 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D69C 8007229C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D6A0 800722A0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D6A4 800722A4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D6A8 800722A8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D6AC 800722AC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D6B0 800722B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D6B4 800722B4 0C016959 */  jal       load_effect
/* 4D6B8 800722B8 24040070 */   addiu    $a0, $zero, 0x70
/* 4D6BC 800722BC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D6C0 800722C0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D6C4 800722C4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D6C8 800722C8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D6CC 800722CC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D6D0 800722D0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D6D4 800722D4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D6D8 800722D8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D6DC 800722DC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D6E0 800722E0 3C018008 */  lui       $at, %hi(gEffectTable+0xA80)
/* 4D6E4 800722E4 8C21FC90 */  lw        $at, %lo(gEffectTable+0xA80)($at)
/* 4D6E8 800722E8 00200008 */  jr        $at
/* 4D6EC 800722EC 00000000 */   nop
