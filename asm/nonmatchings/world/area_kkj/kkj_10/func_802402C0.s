.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402C0
/* ACADE0 802402C0 27BDFF80 */  addiu     $sp, $sp, -0x80
/* ACADE4 802402C4 F7B40060 */  sdc1      $f20, 0x60($sp)
/* ACADE8 802402C8 4485A000 */  mtc1      $a1, $f20
/* ACADEC 802402CC F7B60068 */  sdc1      $f22, 0x68($sp)
/* ACADF0 802402D0 4486B000 */  mtc1      $a2, $f22
/* ACADF4 802402D4 F7B80070 */  sdc1      $f24, 0x70($sp)
/* ACADF8 802402D8 4487C000 */  mtc1      $a3, $f24
/* ACADFC 802402DC F7BA0078 */  sdc1      $f26, 0x78($sp)
/* ACAE00 802402E0 C7BA0090 */  lwc1      $f26, 0x90($sp)
/* ACAE04 802402E4 AFBF0058 */  sw        $ra, 0x58($sp)
/* ACAE08 802402E8 AFB10054 */  sw        $s1, 0x54($sp)
/* ACAE0C 802402EC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* ACAE10 802402F0 AFB00050 */   sw       $s0, 0x50($sp)
/* ACAE14 802402F4 0C046B4C */  jal       get_model_from_list_index
/* ACAE18 802402F8 0040202D */   daddu    $a0, $v0, $zero
/* ACAE1C 802402FC 0040802D */  daddu     $s0, $v0, $zero
/* ACAE20 80240300 26110058 */  addiu     $s1, $s0, 0x58
/* ACAE24 80240304 4405A000 */  mfc1      $a1, $f20
/* ACAE28 80240308 4406B000 */  mfc1      $a2, $f22
/* ACAE2C 8024030C 4407C000 */  mfc1      $a3, $f24
/* ACAE30 80240310 0C019E40 */  jal       guTranslateF
/* ACAE34 80240314 0220202D */   daddu    $a0, $s1, $zero
/* ACAE38 80240318 27A40010 */  addiu     $a0, $sp, 0x10
/* ACAE3C 8024031C 4405D000 */  mfc1      $a1, $f26
/* ACAE40 80240320 3C063F80 */  lui       $a2, 0x3f80
/* ACAE44 80240324 0C019DF0 */  jal       guScaleF
/* ACAE48 80240328 00A0382D */   daddu    $a3, $a1, $zero
/* ACAE4C 8024032C 27A40010 */  addiu     $a0, $sp, 0x10
/* ACAE50 80240330 0220282D */  daddu     $a1, $s1, $zero
/* ACAE54 80240334 0C019D80 */  jal       guMtxCatF
/* ACAE58 80240338 00A0302D */   daddu    $a2, $a1, $zero
/* ACAE5C 8024033C 96020000 */  lhu       $v0, ($s0)
/* ACAE60 80240340 34421400 */  ori       $v0, $v0, 0x1400
/* ACAE64 80240344 A6020000 */  sh        $v0, ($s0)
/* ACAE68 80240348 8FBF0058 */  lw        $ra, 0x58($sp)
/* ACAE6C 8024034C 8FB10054 */  lw        $s1, 0x54($sp)
/* ACAE70 80240350 8FB00050 */  lw        $s0, 0x50($sp)
/* ACAE74 80240354 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* ACAE78 80240358 D7B80070 */  ldc1      $f24, 0x70($sp)
/* ACAE7C 8024035C D7B60068 */  ldc1      $f22, 0x68($sp)
/* ACAE80 80240360 D7B40060 */  ldc1      $f20, 0x60($sp)
/* ACAE84 80240364 03E00008 */  jr        $ra
/* ACAE88 80240368 27BD0080 */   addiu    $sp, $sp, 0x80
