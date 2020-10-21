.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240888_B66338
/* B66338 80240888 27BDFF98 */  addiu     $sp, $sp, -0x68
/* B6633C 8024088C AFB10054 */  sw        $s1, 0x54($sp)
/* B66340 80240890 0080882D */  daddu     $s1, $a0, $zero
/* B66344 80240894 AFBF0058 */  sw        $ra, 0x58($sp)
/* B66348 80240898 AFB00050 */  sw        $s0, 0x50($sp)
/* B6634C 8024089C F7B40060 */  sdc1      $f20, 0x60($sp)
/* B66350 802408A0 8E30000C */  lw        $s0, 0xc($s1)
/* B66354 802408A4 8E050000 */  lw        $a1, ($s0)
/* B66358 802408A8 0C0B1EAF */  jal       get_variable
/* B6635C 802408AC 26100004 */   addiu    $s0, $s0, 4
/* B66360 802408B0 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B66364 802408B4 0040202D */   daddu    $a0, $v0, $zero
/* B66368 802408B8 0220202D */  daddu     $a0, $s1, $zero
/* B6636C 802408BC 8E050000 */  lw        $a1, ($s0)
/* B66370 802408C0 0C0B210B */  jal       get_float_variable
/* B66374 802408C4 0040802D */   daddu    $s0, $v0, $zero
/* B66378 802408C8 0200202D */  daddu     $a0, $s0, $zero
/* B6637C 802408CC 0C046B4C */  jal       get_model_from_list_index
/* B66380 802408D0 46000506 */   mov.s    $f20, $f0
/* B66384 802408D4 0040802D */  daddu     $s0, $v0, $zero
/* B66388 802408D8 96020000 */  lhu       $v0, ($s0)
/* B6638C 802408DC 30420400 */  andi      $v0, $v0, 0x400
/* B66390 802408E0 14400008 */  bnez      $v0, .L80240904
/* B66394 802408E4 00000000 */   nop      
/* B66398 802408E8 4405A000 */  mfc1      $a1, $f20
/* B6639C 802408EC 0C09020B */  jal       func_8024082C_B662DC
/* B663A0 802408F0 26040058 */   addiu    $a0, $s0, 0x58
/* B663A4 802408F4 96020000 */  lhu       $v0, ($s0)
/* B663A8 802408F8 34421400 */  ori       $v0, $v0, 0x1400
/* B663AC 802408FC 08090248 */  j         .L80240920
/* B663B0 80240900 A6020000 */   sh       $v0, ($s0)
.L80240904:
/* B663B4 80240904 4405A000 */  mfc1      $a1, $f20
/* B663B8 80240908 0C09020B */  jal       func_8024082C_B662DC
/* B663BC 8024090C 27A40010 */   addiu    $a0, $sp, 0x10
/* B663C0 80240910 27A40010 */  addiu     $a0, $sp, 0x10
/* B663C4 80240914 26050058 */  addiu     $a1, $s0, 0x58
/* B663C8 80240918 0C019D80 */  jal       guMtxCatF
/* B663CC 8024091C 00A0302D */   daddu    $a2, $a1, $zero
.L80240920:
/* B663D0 80240920 8FBF0058 */  lw        $ra, 0x58($sp)
/* B663D4 80240924 8FB10054 */  lw        $s1, 0x54($sp)
/* B663D8 80240928 8FB00050 */  lw        $s0, 0x50($sp)
/* B663DC 8024092C D7B40060 */  ldc1      $f20, 0x60($sp)
/* B663E0 80240930 24020002 */  addiu     $v0, $zero, 2
/* B663E4 80240934 03E00008 */  jr        $ra
/* B663E8 80240938 27BD0068 */   addiu    $sp, $sp, 0x68
/* B663EC 8024093C 00000000 */  nop       
