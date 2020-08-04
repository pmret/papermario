.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80110374
/* 0A6A74 80110374 27BDFE00 */  addiu $sp, $sp, -0x200
/* 0A6A78 80110378 AFB201E0 */  sw    $s2, 0x1e0($sp)
/* 0A6A7C 8011037C 0080902D */  daddu $s2, $a0, $zero
/* 0A6A80 80110380 AFB401E8 */  sw    $s4, 0x1e8($sp)
/* 0A6A84 80110384 27B40058 */  addiu $s4, $sp, 0x58
/* 0A6A88 80110388 AFBF01EC */  sw    $ra, 0x1ec($sp)
/* 0A6A8C 8011038C AFB301E4 */  sw    $s3, 0x1e4($sp)
/* 0A6A90 80110390 AFB101DC */  sw    $s1, 0x1dc($sp)
/* 0A6A94 80110394 AFB001D8 */  sw    $s0, 0x1d8($sp)
/* 0A6A98 80110398 F7B601F8 */  sdc1  $f22, 0x1f8($sp)
/* 0A6A9C 8011039C F7B401F0 */  sdc1  $f20, 0x1f0($sp)
/* 0A6AA0 801103A0 8E450010 */  lw    $a1, 0x10($s2)
/* 0A6AA4 801103A4 8E460014 */  lw    $a2, 0x14($s2)
/* 0A6AA8 801103A8 8E470018 */  lw    $a3, 0x18($s2)
/* 0A6AAC 801103AC 4480A000 */  mtc1  $zero, $f20
/* 0A6AB0 801103B0 0C019E40 */  jal   guTranslateF
/* 0A6AB4 801103B4 0280202D */   daddu $a0, $s4, $zero
/* 0A6AB8 801103B8 3C013F80 */  lui   $at, 0x3f80
/* 0A6ABC 801103BC 4481B000 */  mtc1  $at, $f22
/* 0A6AC0 801103C0 27B10118 */  addiu $s1, $sp, 0x118
/* 0A6AC4 801103C4 E7B40010 */  swc1  $f20, 0x10($sp)
/* 0A6AC8 801103C8 8E450028 */  lw    $a1, 0x28($s2)
/* 0A6ACC 801103CC 4407A000 */  mfc1  $a3, $f20
/* 0A6AD0 801103D0 4406B000 */  mfc1  $a2, $f22
/* 0A6AD4 801103D4 0C019EC8 */  jal   guRotateF
/* 0A6AD8 801103D8 0220202D */   daddu $a0, $s1, $zero
/* 0A6ADC 801103DC 27B300D8 */  addiu $s3, $sp, 0xd8
/* 0A6AE0 801103E0 E7B40010 */  swc1  $f20, 0x10($sp)
/* 0A6AE4 801103E4 8E45002C */  lw    $a1, 0x2c($s2)
/* 0A6AE8 801103E8 4406A000 */  mfc1  $a2, $f20
/* 0A6AEC 801103EC 4407B000 */  mfc1  $a3, $f22
/* 0A6AF0 801103F0 0C019EC8 */  jal   guRotateF
/* 0A6AF4 801103F4 0260202D */   daddu $a0, $s3, $zero
/* 0A6AF8 801103F8 27B00158 */  addiu $s0, $sp, 0x158
/* 0A6AFC 801103FC 4406A000 */  mfc1  $a2, $f20
/* 0A6B00 80110400 0200202D */  daddu $a0, $s0, $zero
/* 0A6B04 80110404 E7B60010 */  swc1  $f22, 0x10($sp)
/* 0A6B08 80110408 8E450030 */  lw    $a1, 0x30($s2)
/* 0A6B0C 8011040C 0C019EC8 */  jal   guRotateF
/* 0A6B10 80110410 00C0382D */   daddu $a3, $a2, $zero
/* 0A6B14 80110414 0200202D */  daddu $a0, $s0, $zero
/* 0A6B18 80110418 0220282D */  daddu $a1, $s1, $zero
/* 0A6B1C 8011041C 27B10098 */  addiu $s1, $sp, 0x98
/* 0A6B20 80110420 0C019D80 */  jal   guMtxCatF
/* 0A6B24 80110424 0220302D */   daddu $a2, $s1, $zero
/* 0A6B28 80110428 0260202D */  daddu $a0, $s3, $zero
/* 0A6B2C 8011042C 0220282D */  daddu $a1, $s1, $zero
/* 0A6B30 80110430 0C019D80 */  jal   guMtxCatF
/* 0A6B34 80110434 0220302D */   daddu $a2, $s1, $zero
/* 0A6B38 80110438 27B00198 */  addiu $s0, $sp, 0x198
/* 0A6B3C 8011043C 8E45001C */  lw    $a1, 0x1c($s2)
/* 0A6B40 80110440 8E460020 */  lw    $a2, 0x20($s2)
/* 0A6B44 80110444 8E470024 */  lw    $a3, 0x24($s2)
/* 0A6B48 80110448 0C019DF0 */  jal   guScaleF
/* 0A6B4C 8011044C 0200202D */   daddu $a0, $s0, $zero
/* 0A6B50 80110450 0200202D */  daddu $a0, $s0, $zero
/* 0A6B54 80110454 0220282D */  daddu $a1, $s1, $zero
/* 0A6B58 80110458 0C019D80 */  jal   guMtxCatF
/* 0A6B5C 8011045C 27A60018 */   addiu $a2, $sp, 0x18
/* 0A6B60 80110460 27A40018 */  addiu $a0, $sp, 0x18
/* 0A6B64 80110464 0280282D */  daddu $a1, $s4, $zero
/* 0A6B68 80110468 0C019D80 */  jal   guMtxCatF
/* 0A6B6C 8011046C 0220302D */   daddu $a2, $s1, $zero
/* 0A6B70 80110470 0220202D */  daddu $a0, $s1, $zero
/* 0A6B74 80110474 0C019D40 */  jal   guMtxF2L
/* 0A6B78 80110478 26450038 */   addiu $a1, $s2, 0x38
/* 0A6B7C 8011047C 8FBF01EC */  lw    $ra, 0x1ec($sp)
/* 0A6B80 80110480 8FB401E8 */  lw    $s4, 0x1e8($sp)
/* 0A6B84 80110484 8FB301E4 */  lw    $s3, 0x1e4($sp)
/* 0A6B88 80110488 8FB201E0 */  lw    $s2, 0x1e0($sp)
/* 0A6B8C 8011048C 8FB101DC */  lw    $s1, 0x1dc($sp)
/* 0A6B90 80110490 8FB001D8 */  lw    $s0, 0x1d8($sp)
/* 0A6B94 80110494 D7B601F8 */  ldc1  $f22, 0x1f8($sp)
/* 0A6B98 80110498 D7B401F0 */  ldc1  $f20, 0x1f0($sp)
/* 0A6B9C 8011049C 03E00008 */  jr    $ra
/* 0A6BA0 801104A0 27BD0200 */   addiu $sp, $sp, 0x200

