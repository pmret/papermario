.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800721B0
/* 4D5B0 800721B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D5B4 800721B4 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D5B8 800721B8 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D5BC 800721BC AFA60018 */  sw        $a2, 0x18($sp)
/* 4D5C0 800721C0 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D5C4 800721C4 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D5C8 800721C8 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D5CC 800721CC E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D5D0 800721D0 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D5D4 800721D4 0C016885 */  jal       func_8005A214
/* 4D5D8 800721D8 2404006E */   addiu    $a0, $zero, 0x6e
/* 4D5DC 800721DC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D5E0 800721E0 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D5E4 800721E4 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D5E8 800721E8 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D5EC 800721EC C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D5F0 800721F0 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D5F4 800721F4 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D5F8 800721F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D5FC 800721FC 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D600 80072200 3C018008 */  lui       $at, %hi(D_8007FC30)
/* 4D604 80072204 8C21FC30 */  lw        $at, %lo(D_8007FC30)($at)
/* 4D608 80072208 00200008 */  jr        $at
/* 4D60C 8007220C 00000000 */   nop
