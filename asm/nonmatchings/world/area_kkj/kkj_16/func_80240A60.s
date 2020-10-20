.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A60
/* AEDE70 80240A60 27BDFF80 */  addiu     $sp, $sp, -0x80
/* AEDE74 80240A64 F7B40060 */  sdc1      $f20, 0x60($sp)
/* AEDE78 80240A68 4485A000 */  mtc1      $a1, $f20
/* AEDE7C 80240A6C F7B60068 */  sdc1      $f22, 0x68($sp)
/* AEDE80 80240A70 4486B000 */  mtc1      $a2, $f22
/* AEDE84 80240A74 F7B80070 */  sdc1      $f24, 0x70($sp)
/* AEDE88 80240A78 4487C000 */  mtc1      $a3, $f24
/* AEDE8C 80240A7C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* AEDE90 80240A80 C7BA0090 */  lwc1      $f26, 0x90($sp)
/* AEDE94 80240A84 AFBF0058 */  sw        $ra, 0x58($sp)
/* AEDE98 80240A88 AFB10054 */  sw        $s1, 0x54($sp)
/* AEDE9C 80240A8C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* AEDEA0 80240A90 AFB00050 */   sw       $s0, 0x50($sp)
/* AEDEA4 80240A94 0C046B4C */  jal       get_model_from_list_index
/* AEDEA8 80240A98 0040202D */   daddu    $a0, $v0, $zero
/* AEDEAC 80240A9C 0040802D */  daddu     $s0, $v0, $zero
/* AEDEB0 80240AA0 26110058 */  addiu     $s1, $s0, 0x58
/* AEDEB4 80240AA4 4405A000 */  mfc1      $a1, $f20
/* AEDEB8 80240AA8 4406B000 */  mfc1      $a2, $f22
/* AEDEBC 80240AAC 4407C000 */  mfc1      $a3, $f24
/* AEDEC0 80240AB0 0C019E40 */  jal       guTranslateF
/* AEDEC4 80240AB4 0220202D */   daddu    $a0, $s1, $zero
/* AEDEC8 80240AB8 27A40010 */  addiu     $a0, $sp, 0x10
/* AEDECC 80240ABC 4405D000 */  mfc1      $a1, $f26
/* AEDED0 80240AC0 3C063F80 */  lui       $a2, 0x3f80
/* AEDED4 80240AC4 0C019DF0 */  jal       guScaleF
/* AEDED8 80240AC8 00A0382D */   daddu    $a3, $a1, $zero
/* AEDEDC 80240ACC 27A40010 */  addiu     $a0, $sp, 0x10
/* AEDEE0 80240AD0 0220282D */  daddu     $a1, $s1, $zero
/* AEDEE4 80240AD4 0C019D80 */  jal       guMtxCatF
/* AEDEE8 80240AD8 00A0302D */   daddu    $a2, $a1, $zero
/* AEDEEC 80240ADC 96020000 */  lhu       $v0, ($s0)
/* AEDEF0 80240AE0 34421400 */  ori       $v0, $v0, 0x1400
/* AEDEF4 80240AE4 A6020000 */  sh        $v0, ($s0)
/* AEDEF8 80240AE8 8FBF0058 */  lw        $ra, 0x58($sp)
/* AEDEFC 80240AEC 8FB10054 */  lw        $s1, 0x54($sp)
/* AEDF00 80240AF0 8FB00050 */  lw        $s0, 0x50($sp)
/* AEDF04 80240AF4 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* AEDF08 80240AF8 D7B80070 */  ldc1      $f24, 0x70($sp)
/* AEDF0C 80240AFC D7B60068 */  ldc1      $f22, 0x68($sp)
/* AEDF10 80240B00 D7B40060 */  ldc1      $f20, 0x60($sp)
/* AEDF14 80240B04 03E00008 */  jr        $ra
/* AEDF18 80240B08 27BD0080 */   addiu    $sp, $sp, 0x80
