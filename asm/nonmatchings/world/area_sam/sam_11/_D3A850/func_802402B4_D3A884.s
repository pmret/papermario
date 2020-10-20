.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402B4_D3A884
/* D3A884 802402B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D3A888 802402B8 AFB20018 */  sw        $s2, 0x18($sp)
/* D3A88C 802402BC 0080902D */  daddu     $s2, $a0, $zero
/* D3A890 802402C0 AFBF001C */  sw        $ra, 0x1c($sp)
/* D3A894 802402C4 AFB10014 */  sw        $s1, 0x14($sp)
/* D3A898 802402C8 AFB00010 */  sw        $s0, 0x10($sp)
/* D3A89C 802402CC 8E50000C */  lw        $s0, 0xc($s2)
/* D3A8A0 802402D0 8E050000 */  lw        $a1, ($s0)
/* D3A8A4 802402D4 0C0B1EAF */  jal       get_variable
/* D3A8A8 802402D8 26100004 */   addiu    $s0, $s0, 4
/* D3A8AC 802402DC 0C04417A */  jal       get_entity_by_index
/* D3A8B0 802402E0 0040202D */   daddu    $a0, $v0, $zero
/* D3A8B4 802402E4 8E050000 */  lw        $a1, ($s0)
/* D3A8B8 802402E8 26100004 */  addiu     $s0, $s0, 4
/* D3A8BC 802402EC 0040882D */  daddu     $s1, $v0, $zero
/* D3A8C0 802402F0 C6200048 */  lwc1      $f0, 0x48($s1)
/* D3A8C4 802402F4 4600008D */  trunc.w.s $f2, $f0
/* D3A8C8 802402F8 44061000 */  mfc1      $a2, $f2
/* D3A8CC 802402FC 0C0B2026 */  jal       set_variable
/* D3A8D0 80240300 0240202D */   daddu    $a0, $s2, $zero
/* D3A8D4 80240304 8E050000 */  lw        $a1, ($s0)
/* D3A8D8 80240308 26100004 */  addiu     $s0, $s0, 4
/* D3A8DC 8024030C C620004C */  lwc1      $f0, 0x4c($s1)
/* D3A8E0 80240310 4600008D */  trunc.w.s $f2, $f0
/* D3A8E4 80240314 44061000 */  mfc1      $a2, $f2
/* D3A8E8 80240318 0C0B2026 */  jal       set_variable
/* D3A8EC 8024031C 0240202D */   daddu    $a0, $s2, $zero
/* D3A8F0 80240320 C6200050 */  lwc1      $f0, 0x50($s1)
/* D3A8F4 80240324 8E050000 */  lw        $a1, ($s0)
/* D3A8F8 80240328 4600008D */  trunc.w.s $f2, $f0
/* D3A8FC 8024032C 44061000 */  mfc1      $a2, $f2
/* D3A900 80240330 0C0B2026 */  jal       set_variable
/* D3A904 80240334 0240202D */   daddu    $a0, $s2, $zero
/* D3A908 80240338 8FBF001C */  lw        $ra, 0x1c($sp)
/* D3A90C 8024033C 8FB20018 */  lw        $s2, 0x18($sp)
/* D3A910 80240340 8FB10014 */  lw        $s1, 0x14($sp)
/* D3A914 80240344 8FB00010 */  lw        $s0, 0x10($sp)
/* D3A918 80240348 24020002 */  addiu     $v0, $zero, 2
/* D3A91C 8024034C 03E00008 */  jr        $ra
/* D3A920 80240350 27BD0020 */   addiu    $sp, $sp, 0x20
/* D3A924 80240354 00000000 */  nop       
/* D3A928 80240358 00000000 */  nop       
/* D3A92C 8024035C 00000000 */  nop       
