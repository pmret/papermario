.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240270_AED680
/* AED680 80240270 27BDFF80 */  addiu     $sp, $sp, -0x80
/* AED684 80240274 F7B40060 */  sdc1      $f20, 0x60($sp)
/* AED688 80240278 4485A000 */  mtc1      $a1, $f20
/* AED68C 8024027C F7B60068 */  sdc1      $f22, 0x68($sp)
/* AED690 80240280 4486B000 */  mtc1      $a2, $f22
/* AED694 80240284 F7B80070 */  sdc1      $f24, 0x70($sp)
/* AED698 80240288 4487C000 */  mtc1      $a3, $f24
/* AED69C 8024028C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* AED6A0 80240290 C7BA0090 */  lwc1      $f26, 0x90($sp)
/* AED6A4 80240294 AFBF0058 */  sw        $ra, 0x58($sp)
/* AED6A8 80240298 AFB10054 */  sw        $s1, 0x54($sp)
/* AED6AC 8024029C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* AED6B0 802402A0 AFB00050 */   sw       $s0, 0x50($sp)
/* AED6B4 802402A4 0C046B4C */  jal       get_model_from_list_index
/* AED6B8 802402A8 0040202D */   daddu    $a0, $v0, $zero
/* AED6BC 802402AC 0040802D */  daddu     $s0, $v0, $zero
/* AED6C0 802402B0 26110058 */  addiu     $s1, $s0, 0x58
/* AED6C4 802402B4 4405A000 */  mfc1      $a1, $f20
/* AED6C8 802402B8 4406B000 */  mfc1      $a2, $f22
/* AED6CC 802402BC 4407C000 */  mfc1      $a3, $f24
/* AED6D0 802402C0 0C019E40 */  jal       guTranslateF
/* AED6D4 802402C4 0220202D */   daddu    $a0, $s1, $zero
/* AED6D8 802402C8 27A40010 */  addiu     $a0, $sp, 0x10
/* AED6DC 802402CC 4405D000 */  mfc1      $a1, $f26
/* AED6E0 802402D0 3C063F80 */  lui       $a2, 0x3f80
/* AED6E4 802402D4 0C019DF0 */  jal       guScaleF
/* AED6E8 802402D8 00A0382D */   daddu    $a3, $a1, $zero
/* AED6EC 802402DC 27A40010 */  addiu     $a0, $sp, 0x10
/* AED6F0 802402E0 0220282D */  daddu     $a1, $s1, $zero
/* AED6F4 802402E4 0C019D80 */  jal       guMtxCatF
/* AED6F8 802402E8 00A0302D */   daddu    $a2, $a1, $zero
/* AED6FC 802402EC 96020000 */  lhu       $v0, ($s0)
/* AED700 802402F0 34421400 */  ori       $v0, $v0, 0x1400
/* AED704 802402F4 A6020000 */  sh        $v0, ($s0)
/* AED708 802402F8 8FBF0058 */  lw        $ra, 0x58($sp)
/* AED70C 802402FC 8FB10054 */  lw        $s1, 0x54($sp)
/* AED710 80240300 8FB00050 */  lw        $s0, 0x50($sp)
/* AED714 80240304 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* AED718 80240308 D7B80070 */  ldc1      $f24, 0x70($sp)
/* AED71C 8024030C D7B60068 */  ldc1      $f22, 0x68($sp)
/* AED720 80240310 D7B40060 */  ldc1      $f20, 0x60($sp)
/* AED724 80240314 03E00008 */  jr        $ra
/* AED728 80240318 27BD0080 */   addiu    $sp, $sp, 0x80
