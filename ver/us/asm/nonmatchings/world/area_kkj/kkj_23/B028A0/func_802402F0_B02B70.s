.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_B02B70
/* B02B70 802402F0 27BDFF80 */  addiu     $sp, $sp, -0x80
/* B02B74 802402F4 F7B40060 */  sdc1      $f20, 0x60($sp)
/* B02B78 802402F8 4485A000 */  mtc1      $a1, $f20
/* B02B7C 802402FC F7B60068 */  sdc1      $f22, 0x68($sp)
/* B02B80 80240300 4486B000 */  mtc1      $a2, $f22
/* B02B84 80240304 F7B80070 */  sdc1      $f24, 0x70($sp)
/* B02B88 80240308 4487C000 */  mtc1      $a3, $f24
/* B02B8C 8024030C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* B02B90 80240310 C7BA0090 */  lwc1      $f26, 0x90($sp)
/* B02B94 80240314 AFBF0058 */  sw        $ra, 0x58($sp)
/* B02B98 80240318 AFB10054 */  sw        $s1, 0x54($sp)
/* B02B9C 8024031C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B02BA0 80240320 AFB00050 */   sw       $s0, 0x50($sp)
/* B02BA4 80240324 0C046B4C */  jal       get_model_from_list_index
/* B02BA8 80240328 0040202D */   daddu    $a0, $v0, $zero
/* B02BAC 8024032C 0040802D */  daddu     $s0, $v0, $zero
/* B02BB0 80240330 26110058 */  addiu     $s1, $s0, 0x58
/* B02BB4 80240334 4405A000 */  mfc1      $a1, $f20
/* B02BB8 80240338 4406B000 */  mfc1      $a2, $f22
/* B02BBC 8024033C 4407C000 */  mfc1      $a3, $f24
/* B02BC0 80240340 0C019E40 */  jal       guTranslateF
/* B02BC4 80240344 0220202D */   daddu    $a0, $s1, $zero
/* B02BC8 80240348 27A40010 */  addiu     $a0, $sp, 0x10
/* B02BCC 8024034C 4405D000 */  mfc1      $a1, $f26
/* B02BD0 80240350 3C063F80 */  lui       $a2, 0x3f80
/* B02BD4 80240354 0C019DF0 */  jal       guScaleF
/* B02BD8 80240358 00A0382D */   daddu    $a3, $a1, $zero
/* B02BDC 8024035C 27A40010 */  addiu     $a0, $sp, 0x10
/* B02BE0 80240360 0220282D */  daddu     $a1, $s1, $zero
/* B02BE4 80240364 0C019D80 */  jal       guMtxCatF
/* B02BE8 80240368 00A0302D */   daddu    $a2, $a1, $zero
/* B02BEC 8024036C 96020000 */  lhu       $v0, ($s0)
/* B02BF0 80240370 34421400 */  ori       $v0, $v0, 0x1400
/* B02BF4 80240374 A6020000 */  sh        $v0, ($s0)
/* B02BF8 80240378 8FBF0058 */  lw        $ra, 0x58($sp)
/* B02BFC 8024037C 8FB10054 */  lw        $s1, 0x54($sp)
/* B02C00 80240380 8FB00050 */  lw        $s0, 0x50($sp)
/* B02C04 80240384 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* B02C08 80240388 D7B80070 */  ldc1      $f24, 0x70($sp)
/* B02C0C 8024038C D7B60068 */  ldc1      $f22, 0x68($sp)
/* B02C10 80240390 D7B40060 */  ldc1      $f20, 0x60($sp)
/* B02C14 80240394 03E00008 */  jr        $ra
/* B02C18 80240398 27BD0080 */   addiu    $sp, $sp, 0x80
