.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AB0_ACEBF0
/* ACEBF0 80240AB0 27BDFF80 */  addiu     $sp, $sp, -0x80
/* ACEBF4 80240AB4 F7B40060 */  sdc1      $f20, 0x60($sp)
/* ACEBF8 80240AB8 4485A000 */  mtc1      $a1, $f20
/* ACEBFC 80240ABC F7B60068 */  sdc1      $f22, 0x68($sp)
/* ACEC00 80240AC0 4486B000 */  mtc1      $a2, $f22
/* ACEC04 80240AC4 F7B80070 */  sdc1      $f24, 0x70($sp)
/* ACEC08 80240AC8 4487C000 */  mtc1      $a3, $f24
/* ACEC0C 80240ACC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* ACEC10 80240AD0 C7BA0090 */  lwc1      $f26, 0x90($sp)
/* ACEC14 80240AD4 AFBF0058 */  sw        $ra, 0x58($sp)
/* ACEC18 80240AD8 AFB10054 */  sw        $s1, 0x54($sp)
/* ACEC1C 80240ADC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* ACEC20 80240AE0 AFB00050 */   sw       $s0, 0x50($sp)
/* ACEC24 80240AE4 0C046B4C */  jal       get_model_from_list_index
/* ACEC28 80240AE8 0040202D */   daddu    $a0, $v0, $zero
/* ACEC2C 80240AEC 0040802D */  daddu     $s0, $v0, $zero
/* ACEC30 80240AF0 26110058 */  addiu     $s1, $s0, 0x58
/* ACEC34 80240AF4 4405A000 */  mfc1      $a1, $f20
/* ACEC38 80240AF8 4406B000 */  mfc1      $a2, $f22
/* ACEC3C 80240AFC 4407C000 */  mfc1      $a3, $f24
/* ACEC40 80240B00 0C019E40 */  jal       guTranslateF
/* ACEC44 80240B04 0220202D */   daddu    $a0, $s1, $zero
/* ACEC48 80240B08 27A40010 */  addiu     $a0, $sp, 0x10
/* ACEC4C 80240B0C 4405D000 */  mfc1      $a1, $f26
/* ACEC50 80240B10 3C063F80 */  lui       $a2, 0x3f80
/* ACEC54 80240B14 0C019DF0 */  jal       guScaleF
/* ACEC58 80240B18 00A0382D */   daddu    $a3, $a1, $zero
/* ACEC5C 80240B1C 27A40010 */  addiu     $a0, $sp, 0x10
/* ACEC60 80240B20 0220282D */  daddu     $a1, $s1, $zero
/* ACEC64 80240B24 0C019D80 */  jal       guMtxCatF
/* ACEC68 80240B28 00A0302D */   daddu    $a2, $a1, $zero
/* ACEC6C 80240B2C 96020000 */  lhu       $v0, ($s0)
/* ACEC70 80240B30 34421400 */  ori       $v0, $v0, 0x1400
/* ACEC74 80240B34 A6020000 */  sh        $v0, ($s0)
/* ACEC78 80240B38 8FBF0058 */  lw        $ra, 0x58($sp)
/* ACEC7C 80240B3C 8FB10054 */  lw        $s1, 0x54($sp)
/* ACEC80 80240B40 8FB00050 */  lw        $s0, 0x50($sp)
/* ACEC84 80240B44 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* ACEC88 80240B48 D7B80070 */  ldc1      $f24, 0x70($sp)
/* ACEC8C 80240B4C D7B60068 */  ldc1      $f22, 0x68($sp)
/* ACEC90 80240B50 D7B40060 */  ldc1      $f20, 0x60($sp)
/* ACEC94 80240B54 03E00008 */  jr        $ra
/* ACEC98 80240B58 27BD0080 */   addiu    $sp, $sp, 0x80
