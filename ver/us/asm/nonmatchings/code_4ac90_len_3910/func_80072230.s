.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072230
/* 4D630 80072230 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D634 80072234 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D638 80072238 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D63C 8007223C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D640 80072240 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D644 80072244 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D648 80072248 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D64C 8007224C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D650 80072250 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D654 80072254 0C016959 */  jal       load_effect
/* 4D658 80072258 2404006F */   addiu    $a0, $zero, 0x6f
/* 4D65C 8007225C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D660 80072260 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D664 80072264 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D668 80072268 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D66C 8007226C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D670 80072270 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D674 80072274 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D678 80072278 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D67C 8007227C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D680 80072280 3C018008 */  lui       $at, %hi(gEffectTable+0xA68)
/* 4D684 80072284 8C21FC78 */  lw        $at, %lo(gEffectTable+0xA68)($at)
/* 4D688 80072288 00200008 */  jr        $at
/* 4D68C 8007228C 00000000 */   nop
