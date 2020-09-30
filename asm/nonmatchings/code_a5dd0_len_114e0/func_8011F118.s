.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011F118
/* B5818 8011F118 27BDFF80 */  addiu     $sp, $sp, -0x80
/* B581C 8011F11C AFB40060 */  sw        $s4, 0x60($sp)
/* B5820 8011F120 0080A02D */  daddu     $s4, $a0, $zero
/* B5824 8011F124 AFB60068 */  sw        $s6, 0x68($sp)
/* B5828 8011F128 00A0B02D */  daddu     $s6, $a1, $zero
/* B582C 8011F12C AFB3005C */  sw        $s3, 0x5c($sp)
/* B5830 8011F130 00C0982D */  daddu     $s3, $a2, $zero
/* B5834 8011F134 AFBF006C */  sw        $ra, 0x6c($sp)
/* B5838 8011F138 AFB50064 */  sw        $s5, 0x64($sp)
/* B583C 8011F13C AFB20058 */  sw        $s2, 0x58($sp)
/* B5840 8011F140 AFB10054 */  sw        $s1, 0x54($sp)
/* B5844 8011F144 AFB00050 */  sw        $s0, 0x50($sp)
/* B5848 8011F148 F7B60078 */  sdc1      $f22, 0x78($sp)
/* B584C 8011F14C F7B40070 */  sdc1      $f20, 0x70($sp)
/* B5850 8011F150 C66C009C */  lwc1      $f12, 0x9c($s3)
/* B5854 8011F154 0C00A6C9 */  jal       clamp_angle
/* B5858 8011F158 00E0A82D */   daddu    $s5, $a3, $zero
/* B585C 8011F15C C66C00A0 */  lwc1      $f12, 0xa0($s3)
/* B5860 8011F160 0C00A6C9 */  jal       clamp_angle
/* B5864 8011F164 46000586 */   mov.s    $f22, $f0
/* B5868 8011F168 C66C00A4 */  lwc1      $f12, 0xa4($s3)
/* B586C 8011F16C 0C00A6C9 */  jal       clamp_angle
/* B5870 8011F170 46000506 */   mov.s    $f20, $f0
/* B5874 8011F174 3C128015 */  lui       $s2, 0x8015
/* B5878 8011F178 26523A68 */  addiu     $s2, $s2, 0x3a68
/* B587C 8011F17C 4405B000 */  mfc1      $a1, $f22
/* B5880 8011F180 4406A000 */  mfc1      $a2, $f20
/* B5884 8011F184 44070000 */  mfc1      $a3, $f0
/* B5888 8011F188 0C0190B4 */  jal       guRotateAnglesF
/* B588C 8011F18C 0240202D */   daddu    $a0, $s2, $zero
/* B5890 8011F190 3C108015 */  lui       $s0, 0x8015
/* B5894 8011F194 26103AA8 */  addiu     $s0, $s0, 0x3aa8
/* B5898 8011F198 8E6500A8 */  lw        $a1, 0xa8($s3)
/* B589C 8011F19C 8E6600AC */  lw        $a2, 0xac($s3)
/* B58A0 8011F1A0 8E6700B0 */  lw        $a3, 0xb0($s3)
/* B58A4 8011F1A4 0C019DF0 */  jal       guScaleF
/* B58A8 8011F1A8 0200202D */   daddu    $a0, $s0, $zero
/* B58AC 8011F1AC C6620084 */  lwc1      $f2, 0x84($s3)
/* B58B0 8011F1B0 C6600090 */  lwc1      $f0, 0x90($s3)
/* B58B4 8011F1B4 46001080 */  add.s     $f2, $f2, $f0
/* B58B8 8011F1B8 C6600094 */  lwc1      $f0, 0x94($s3)
/* B58BC 8011F1BC 44051000 */  mfc1      $a1, $f2
/* B58C0 8011F1C0 C6620088 */  lwc1      $f2, 0x88($s3)
/* B58C4 8011F1C4 46001080 */  add.s     $f2, $f2, $f0
/* B58C8 8011F1C8 C6600098 */  lwc1      $f0, 0x98($s3)
/* B58CC 8011F1CC 44061000 */  mfc1      $a2, $f2
/* B58D0 8011F1D0 C662008C */  lwc1      $f2, 0x8c($s3)
/* B58D4 8011F1D4 46001080 */  add.s     $f2, $f2, $f0
/* B58D8 8011F1D8 3C118015 */  lui       $s1, 0x8015
/* B58DC 8011F1DC 26313AE8 */  addiu     $s1, $s1, 0x3ae8
/* B58E0 8011F1E0 44071000 */  mfc1      $a3, $f2
/* B58E4 8011F1E4 0C019E40 */  jal       guTranslateF
/* B58E8 8011F1E8 0220202D */   daddu    $a0, $s1, $zero
/* B58EC 8011F1EC 0200202D */  daddu     $a0, $s0, $zero
/* B58F0 8011F1F0 0240282D */  daddu     $a1, $s2, $zero
/* B58F4 8011F1F4 3C108015 */  lui       $s0, 0x8015
/* B58F8 8011F1F8 26103B28 */  addiu     $s0, $s0, 0x3b28
/* B58FC 8011F1FC 0C019D80 */  jal       guMtxCatF
/* B5900 8011F200 0200302D */   daddu    $a2, $s0, $zero
/* B5904 8011F204 0200202D */  daddu     $a0, $s0, $zero
/* B5908 8011F208 0220282D */  daddu     $a1, $s1, $zero
/* B590C 8011F20C 0C019D80 */  jal       guMtxCatF
/* B5910 8011F210 27A60010 */   addiu    $a2, $sp, 0x10
/* B5914 8011F214 8E820000 */  lw        $v0, ($s4)
/* B5918 8011F218 3C030002 */  lui       $v1, 2
/* B591C 8011F21C 00431024 */  and       $v0, $v0, $v1
/* B5920 8011F220 14400005 */  bnez      $v0, .L8011F238
/* B5924 8011F224 27A40010 */   addiu    $a0, $sp, 0x10
/* B5928 8011F228 02C0282D */  daddu     $a1, $s6, $zero
/* B592C 8011F22C 0C019D80 */  jal       guMtxCatF
/* B5930 8011F230 0080302D */   daddu    $a2, $a0, $zero
/* B5934 8011F234 27A40010 */  addiu     $a0, $sp, 0x10
.L8011F238:
/* B5938 8011F238 0C00A5C8 */  jal       copy_matrix
/* B593C 8011F23C 266500B4 */   addiu    $a1, $s3, 0xb4
/* B5940 8011F240 966200F4 */  lhu       $v0, 0xf4($s3)
/* B5944 8011F244 30421000 */  andi      $v0, $v0, 0x1000
/* B5948 8011F248 10400016 */  beqz      $v0, .L8011F2A4
/* B594C 8011F24C 0000882D */   daddu    $s1, $zero, $zero
/* B5950 8011F250 8E6400FC */  lw        $a0, 0xfc($s3)
/* B5954 8011F254 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B5958 8011F258 00000000 */   nop      
/* B595C 8011F25C 0C046B4C */  jal       get_model_from_list_index
/* B5960 8011F260 0040202D */   daddu    $a0, $v0, $zero
/* B5964 8011F264 27A40010 */  addiu     $a0, $sp, 0x10
/* B5968 8011F268 0040802D */  daddu     $s0, $v0, $zero
/* B596C 8011F26C 26110058 */  addiu     $s1, $s0, 0x58
/* B5970 8011F270 0C00A5C8 */  jal       copy_matrix
/* B5974 8011F274 0220282D */   daddu    $a1, $s1, $zero
/* B5978 8011F278 27A40010 */  addiu     $a0, $sp, 0x10
/* B597C 8011F27C 0C019D60 */  jal       guMtxL2F
/* B5980 8011F280 02A0282D */   daddu    $a1, $s5, $zero
/* B5984 8011F284 0220202D */  daddu     $a0, $s1, $zero
/* B5988 8011F288 27A50010 */  addiu     $a1, $sp, 0x10
/* B598C 8011F28C 0C019D80 */  jal       guMtxCatF
/* B5990 8011F290 0080302D */   daddu    $a2, $a0, $zero
/* B5994 8011F294 96020000 */  lhu       $v0, ($s0)
/* B5998 8011F298 34421000 */  ori       $v0, $v0, 0x1000
/* B599C 8011F29C A6020000 */  sh        $v0, ($s0)
/* B59A0 8011F2A0 0000882D */  daddu     $s1, $zero, $zero
.L8011F2A4:
/* B59A4 8011F2A4 0260802D */  daddu     $s0, $s3, $zero
.L8011F2A8:
/* B59A8 8011F2A8 8E060004 */  lw        $a2, 4($s0)
/* B59AC 8011F2AC 50C00006 */  beql      $a2, $zero, .L8011F2C8
/* B59B0 8011F2B0 26310001 */   addiu    $s1, $s1, 1
/* B59B4 8011F2B4 0280202D */  daddu     $a0, $s4, $zero
/* B59B8 8011F2B8 27A50010 */  addiu     $a1, $sp, 0x10
/* B59BC 8011F2BC 0C047C46 */  jal       func_8011F118
/* B59C0 8011F2C0 02A0382D */   daddu    $a3, $s5, $zero
/* B59C4 8011F2C4 26310001 */  addiu     $s1, $s1, 1
.L8011F2C8:
/* B59C8 8011F2C8 2A220020 */  slti      $v0, $s1, 0x20
/* B59CC 8011F2CC 1440FFF6 */  bnez      $v0, .L8011F2A8
/* B59D0 8011F2D0 26100004 */   addiu    $s0, $s0, 4
/* B59D4 8011F2D4 8FBF006C */  lw        $ra, 0x6c($sp)
/* B59D8 8011F2D8 8FB60068 */  lw        $s6, 0x68($sp)
/* B59DC 8011F2DC 8FB50064 */  lw        $s5, 0x64($sp)
/* B59E0 8011F2E0 8FB40060 */  lw        $s4, 0x60($sp)
/* B59E4 8011F2E4 8FB3005C */  lw        $s3, 0x5c($sp)
/* B59E8 8011F2E8 8FB20058 */  lw        $s2, 0x58($sp)
/* B59EC 8011F2EC 8FB10054 */  lw        $s1, 0x54($sp)
/* B59F0 8011F2F0 8FB00050 */  lw        $s0, 0x50($sp)
/* B59F4 8011F2F4 D7B60078 */  ldc1      $f22, 0x78($sp)
/* B59F8 8011F2F8 D7B40070 */  ldc1      $f20, 0x70($sp)
/* B59FC 8011F2FC 03E00008 */  jr        $ra
/* B5A00 8011F300 27BD0080 */   addiu    $sp, $sp, 0x80
