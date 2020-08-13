.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel fx_sleep_bubble
/* 04BBF0 800707F0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04BBF4 800707F4 AFA40010 */  sw    $a0, 0x10($sp)
/* 04BBF8 800707F8 AFA50014 */  sw    $a1, 0x14($sp)
/* 04BBFC 800707FC AFA60018 */  sw    $a2, 0x18($sp)
/* 04BC00 80070800 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04BC04 80070804 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04BC08 80070808 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04BC0C 8007080C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04BC10 80070810 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04BC14 80070814 0C016959 */  jal   play_effect
/* 04BC18 80070818 24040029 */   addiu $a0, $zero, 0x29
/* 04BC1C 8007081C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04BC20 80070820 8FA50014 */  lw    $a1, 0x14($sp)
/* 04BC24 80070824 8FA60018 */  lw    $a2, 0x18($sp)
/* 04BC28 80070828 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04BC2C 8007082C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04BC30 80070830 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04BC34 80070834 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04BC38 80070838 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04BC3C 8007083C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04BC40 80070840 3C018008 */  lui   $at, 0x8008
/* 04BC44 80070844 8C21F5E8 */  lw    $at, -0xa18($at)
/* 04BC48 80070848 00200008 */  jr    $at
/* 04BC4C 8007084C 00000000 */   nop   
/* 04BC50 80070850 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 04BC54 80070854 AFA40010 */  sw    $a0, 0x10($sp)
/* 04BC58 80070858 AFA50014 */  sw    $a1, 0x14($sp)
/* 04BC5C 8007085C AFA60018 */  sw    $a2, 0x18($sp)
/* 04BC60 80070860 AFA7001C */  sw    $a3, 0x1c($sp)
/* 04BC64 80070864 E7AC0020 */  swc1  $f12, 0x20($sp)
/* 04BC68 80070868 E7AE0024 */  swc1  $f14, 0x24($sp)
/* 04BC6C 8007086C E7B00028 */  swc1  $f16, 0x28($sp)
/* 04BC70 80070870 AFBF002C */  sw    $ra, 0x2c($sp)
/* 04BC74 80070874 0C016959 */  jal   play_effect
/* 04BC78 80070878 2404002A */   addiu $a0, $zero, 0x2a
/* 04BC7C 8007087C 8FA40010 */  lw    $a0, 0x10($sp)
/* 04BC80 80070880 8FA50014 */  lw    $a1, 0x14($sp)
/* 04BC84 80070884 8FA60018 */  lw    $a2, 0x18($sp)
/* 04BC88 80070888 8FA7001C */  lw    $a3, 0x1c($sp)
/* 04BC8C 8007088C C7AC0020 */  lwc1  $f12, 0x20($sp)
/* 04BC90 80070890 C7AE0024 */  lwc1  $f14, 0x24($sp)
/* 04BC94 80070894 C7B00028 */  lwc1  $f16, 0x28($sp)
/* 04BC98 80070898 8FBF002C */  lw    $ra, 0x2c($sp)
/* 04BC9C 8007089C 27BD0030 */  addiu $sp, $sp, 0x30
/* 04BCA0 800708A0 3C018008 */  lui   $at, 0x8008
/* 04BCA4 800708A4 8C21F600 */  lw    $at, -0xa00($at)
/* 04BCA8 800708A8 00200008 */  jr    $at
/* 04BCAC 800708AC 00000000 */   nop   
