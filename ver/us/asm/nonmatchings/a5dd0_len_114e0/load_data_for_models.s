.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_data_for_models
/* B1448 8011AD48 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* B144C 8011AD4C AFB00050 */  sw        $s0, 0x50($sp)
/* B1450 8011AD50 0080802D */  daddu     $s0, $a0, $zero
/* B1454 8011AD54 AFB10054 */  sw        $s1, 0x54($sp)
/* B1458 8011AD58 00A0882D */  daddu     $s1, $a1, $zero
/* B145C 8011AD5C AFB20058 */  sw        $s2, 0x58($sp)
/* B1460 8011AD60 00C0902D */  daddu     $s2, $a2, $zero
/* B1464 8011AD64 AFBF005C */  sw        $ra, 0x5c($sp)
/* B1468 8011AD68 0C019D28 */  jal       guMtxIdentF
/* B146C 8011AD6C 27A40010 */   addiu    $a0, $sp, 0x10
/* B1470 8011AD70 12200004 */  beqz      $s1, .L8011AD84
/* B1474 8011AD74 0200202D */   daddu    $a0, $s0, $zero
/* B1478 8011AD78 0220282D */  daddu     $a1, $s1, $zero
/* B147C 8011AD7C 0C045709 */  jal       load_model_textures
/* B1480 8011AD80 0240302D */   daddu    $a2, $s2, $zero
.L8011AD84:
/* B1484 8011AD84 3C028015 */  lui       $v0, %hi(D_801512FC)
/* B1488 8011AD88 8C4212FC */  lw        $v0, %lo(D_801512FC)($v0)
/* B148C 8011AD8C AC500000 */  sw        $s0, ($v0)
/* B1490 8011AD90 3C018015 */  lui       $at, %hi(D_80153224)
/* B1494 8011AD94 AC203224 */  sw        $zero, %lo(D_80153224)($at)
/* B1498 8011AD98 12000005 */  beqz      $s0, .L8011ADB0
/* B149C 8011AD9C 0200202D */   daddu    $a0, $s0, $zero
/* B14A0 8011ADA0 0000282D */  daddu     $a1, $zero, $zero
/* B14A4 8011ADA4 27A60010 */  addiu     $a2, $sp, 0x10
/* B14A8 8011ADA8 0C046B72 */  jal       load_model_transforms
/* B14AC 8011ADAC 00A0382D */   daddu    $a3, $a1, $zero
.L8011ADB0:
/* B14B0 8011ADB0 8FBF005C */  lw        $ra, 0x5c($sp)
/* B14B4 8011ADB4 8FB20058 */  lw        $s2, 0x58($sp)
/* B14B8 8011ADB8 8FB10054 */  lw        $s1, 0x54($sp)
/* B14BC 8011ADBC 8FB00050 */  lw        $s0, 0x50($sp)
/* B14C0 8011ADC0 03E00008 */  jr        $ra
/* B14C4 8011ADC4 27BD0060 */   addiu    $sp, $sp, 0x60
