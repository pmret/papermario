.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072210
/* 4D610 80072210 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4D614 80072214 AFA40010 */  sw        $a0, 0x10($sp)
/* 4D618 80072218 AFA50014 */  sw        $a1, 0x14($sp)
/* 4D61C 8007221C AFA60018 */  sw        $a2, 0x18($sp)
/* 4D620 80072220 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4D624 80072224 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4D628 80072228 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4D62C 8007222C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4D630 80072230 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4D634 80072234 0C016885 */  jal       func_8005A214
/* 4D638 80072238 2404006F */   addiu    $a0, $zero, 0x6f
/* 4D63C 8007223C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4D640 80072240 8FA50014 */  lw        $a1, 0x14($sp)
/* 4D644 80072244 8FA60018 */  lw        $a2, 0x18($sp)
/* 4D648 80072248 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4D64C 8007224C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4D650 80072250 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4D654 80072254 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4D658 80072258 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4D65C 8007225C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4D660 80072260 3C018008 */  lui       $at, %hi(D_8007FC48)
/* 4D664 80072264 8C21FC48 */  lw        $at, %lo(D_8007FC48)($at)
/* 4D668 80072268 00200008 */  jr        $at
/* 4D66C 8007226C 00000000 */   nop
