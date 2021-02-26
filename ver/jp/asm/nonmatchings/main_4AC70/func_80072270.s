.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072270
/* 4D670 80072270 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D674 80072274 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D678 80072278 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D67C 8007227C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D680 80072280 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D684 80072284 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D688 80072288 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D68C 8007228C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D690 80072290 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D694 80072294 0C016885 */  jal       func_8005A214
/* 4D698 80072298 24040070 */   addiu    $a0, $zero, 0x70
/* 4D69C 8007229C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D6A0 800722A0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D6A4 800722A4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D6A8 800722A8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D6AC 800722AC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D6B0 800722B0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D6B4 800722B4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D6B8 800722B8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D6BC 800722BC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D6C0 800722C0 3C018008 */  lui       $at, %hi(D_8007FC60)
/* 4D6C4 800722C4 8C21FC60 */  lw        $at, %lo(D_8007FC60)($at)
/* 4D6C8 800722C8 00200008 */  jr        $at
/* 4D6CC 800722CC 00000000 */   nop
