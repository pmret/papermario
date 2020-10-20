.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240280_AD4310
/* AD4310 80240280 27BDFF80 */  addiu     $sp, $sp, -0x80
/* AD4314 80240284 F7B40060 */  sdc1      $f20, 0x60($sp)
/* AD4318 80240288 4485A000 */  mtc1      $a1, $f20
/* AD431C 8024028C F7B60068 */  sdc1      $f22, 0x68($sp)
/* AD4320 80240290 4486B000 */  mtc1      $a2, $f22
/* AD4324 80240294 F7B80070 */  sdc1      $f24, 0x70($sp)
/* AD4328 80240298 4487C000 */  mtc1      $a3, $f24
/* AD432C 8024029C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* AD4330 802402A0 C7BA0090 */  lwc1      $f26, 0x90($sp)
/* AD4334 802402A4 AFBF0058 */  sw        $ra, 0x58($sp)
/* AD4338 802402A8 AFB10054 */  sw        $s1, 0x54($sp)
/* AD433C 802402AC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* AD4340 802402B0 AFB00050 */   sw       $s0, 0x50($sp)
/* AD4344 802402B4 0C046B4C */  jal       get_model_from_list_index
/* AD4348 802402B8 0040202D */   daddu    $a0, $v0, $zero
/* AD434C 802402BC 0040802D */  daddu     $s0, $v0, $zero
/* AD4350 802402C0 26110058 */  addiu     $s1, $s0, 0x58
/* AD4354 802402C4 4405A000 */  mfc1      $a1, $f20
/* AD4358 802402C8 4406B000 */  mfc1      $a2, $f22
/* AD435C 802402CC 4407C000 */  mfc1      $a3, $f24
/* AD4360 802402D0 0C019E40 */  jal       guTranslateF
/* AD4364 802402D4 0220202D */   daddu    $a0, $s1, $zero
/* AD4368 802402D8 27A40010 */  addiu     $a0, $sp, 0x10
/* AD436C 802402DC 4405D000 */  mfc1      $a1, $f26
/* AD4370 802402E0 3C063F80 */  lui       $a2, 0x3f80
/* AD4374 802402E4 0C019DF0 */  jal       guScaleF
/* AD4378 802402E8 00A0382D */   daddu    $a3, $a1, $zero
/* AD437C 802402EC 27A40010 */  addiu     $a0, $sp, 0x10
/* AD4380 802402F0 0220282D */  daddu     $a1, $s1, $zero
/* AD4384 802402F4 0C019D80 */  jal       guMtxCatF
/* AD4388 802402F8 00A0302D */   daddu    $a2, $a1, $zero
/* AD438C 802402FC 96020000 */  lhu       $v0, ($s0)
/* AD4390 80240300 34421400 */  ori       $v0, $v0, 0x1400
/* AD4394 80240304 A6020000 */  sh        $v0, ($s0)
/* AD4398 80240308 8FBF0058 */  lw        $ra, 0x58($sp)
/* AD439C 8024030C 8FB10054 */  lw        $s1, 0x54($sp)
/* AD43A0 80240310 8FB00050 */  lw        $s0, 0x50($sp)
/* AD43A4 80240314 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* AD43A8 80240318 D7B80070 */  ldc1      $f24, 0x70($sp)
/* AD43AC 8024031C D7B60068 */  ldc1      $f22, 0x68($sp)
/* AD43B0 80240320 D7B40060 */  ldc1      $f20, 0x60($sp)
/* AD43B4 80240324 03E00008 */  jr        $ra
/* AD43B8 80240328 27BD0080 */   addiu    $sp, $sp, 0x80
