.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418E8_A3ADC8
/* A3ADC8 802418E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A3ADCC 802418EC AFB00018 */  sw        $s0, 0x18($sp)
/* A3ADD0 802418F0 0080802D */  daddu     $s0, $a0, $zero
/* A3ADD4 802418F4 10A00042 */  beqz      $a1, .L80241A00
/* A3ADD8 802418F8 AFBF001C */   sw       $ra, 0x1c($sp)
/* A3ADDC 802418FC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3ADE0 80241900 24040079 */   addiu    $a0, $zero, 0x79
/* A3ADE4 80241904 0C046B4C */  jal       get_model_from_list_index
/* A3ADE8 80241908 0040202D */   daddu    $a0, $v0, $zero
/* A3ADEC 8024190C 0040202D */  daddu     $a0, $v0, $zero
/* A3ADF0 80241910 2405FFFF */  addiu     $a1, $zero, -1
/* A3ADF4 80241914 0C046F1F */  jal       func_8011BC7C
/* A3ADF8 80241918 24060003 */   addiu    $a2, $zero, 3
/* A3ADFC 8024191C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3AE00 80241920 2404007A */   addiu    $a0, $zero, 0x7a
/* A3AE04 80241924 0C046B4C */  jal       get_model_from_list_index
/* A3AE08 80241928 0040202D */   daddu    $a0, $v0, $zero
/* A3AE0C 8024192C 0040202D */  daddu     $a0, $v0, $zero
/* A3AE10 80241930 2405FFFF */  addiu     $a1, $zero, -1
/* A3AE14 80241934 0C046F1F */  jal       func_8011BC7C
/* A3AE18 80241938 24060003 */   addiu    $a2, $zero, 3
/* A3AE1C 8024193C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3AE20 80241940 2404007B */   addiu    $a0, $zero, 0x7b
/* A3AE24 80241944 0C046B4C */  jal       get_model_from_list_index
/* A3AE28 80241948 0040202D */   daddu    $a0, $v0, $zero
/* A3AE2C 8024194C 0040202D */  daddu     $a0, $v0, $zero
/* A3AE30 80241950 2405FFFF */  addiu     $a1, $zero, -1
/* A3AE34 80241954 0C046F1F */  jal       func_8011BC7C
/* A3AE38 80241958 24060003 */   addiu    $a2, $zero, 3
/* A3AE3C 8024195C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3AE40 80241960 2404007C */   addiu    $a0, $zero, 0x7c
/* A3AE44 80241964 0C046B4C */  jal       get_model_from_list_index
/* A3AE48 80241968 0040202D */   daddu    $a0, $v0, $zero
/* A3AE4C 8024196C 0040202D */  daddu     $a0, $v0, $zero
/* A3AE50 80241970 2405FFFF */  addiu     $a1, $zero, -1
/* A3AE54 80241974 0C046F1F */  jal       func_8011BC7C
/* A3AE58 80241978 24060003 */   addiu    $a2, $zero, 3
/* A3AE5C 8024197C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3AE60 80241980 2404007D */   addiu    $a0, $zero, 0x7d
/* A3AE64 80241984 0C046B4C */  jal       get_model_from_list_index
/* A3AE68 80241988 0040202D */   daddu    $a0, $v0, $zero
/* A3AE6C 8024198C 0040202D */  daddu     $a0, $v0, $zero
/* A3AE70 80241990 2405FFFF */  addiu     $a1, $zero, -1
/* A3AE74 80241994 0C046F1F */  jal       func_8011BC7C
/* A3AE78 80241998 24060003 */   addiu    $a2, $zero, 3
/* A3AE7C 8024199C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3AE80 802419A0 2404007F */   addiu    $a0, $zero, 0x7f
/* A3AE84 802419A4 0C046B4C */  jal       get_model_from_list_index
/* A3AE88 802419A8 0040202D */   daddu    $a0, $v0, $zero
/* A3AE8C 802419AC 0040202D */  daddu     $a0, $v0, $zero
/* A3AE90 802419B0 2405FFFF */  addiu     $a1, $zero, -1
/* A3AE94 802419B4 0C046F1F */  jal       func_8011BC7C
/* A3AE98 802419B8 24060003 */   addiu    $a2, $zero, 3
/* A3AE9C 802419BC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3AEA0 802419C0 240400D0 */   addiu    $a0, $zero, 0xd0
/* A3AEA4 802419C4 0C046B4C */  jal       get_model_from_list_index
/* A3AEA8 802419C8 0040202D */   daddu    $a0, $v0, $zero
/* A3AEAC 802419CC 0040202D */  daddu     $a0, $v0, $zero
/* A3AEB0 802419D0 2405FFFF */  addiu     $a1, $zero, -1
/* A3AEB4 802419D4 0C046F1F */  jal       func_8011BC7C
/* A3AEB8 802419D8 24060003 */   addiu    $a2, $zero, 3
/* A3AEBC 802419DC 240400FF */  addiu     $a0, $zero, 0xff
/* A3AEC0 802419E0 0080282D */  daddu     $a1, $a0, $zero
/* A3AEC4 802419E4 0080302D */  daddu     $a2, $a0, $zero
/* A3AEC8 802419E8 0000382D */  daddu     $a3, $zero, $zero
/* A3AECC 802419EC AFA00010 */  sw        $zero, 0x10($sp)
/* A3AED0 802419F0 0C046FE6 */  jal       func_8011BF98
/* A3AED4 802419F4 AFA00014 */   sw       $zero, 0x14($sp)
/* A3AED8 802419F8 240200FF */  addiu     $v0, $zero, 0xff
/* A3AEDC 802419FC AE020070 */  sw        $v0, 0x70($s0)
.L80241A00:
/* A3AEE0 80241A00 8E020070 */  lw        $v0, 0x70($s0)
/* A3AEE4 80241A04 2442FFFC */  addiu     $v0, $v0, -4
/* A3AEE8 80241A08 AE020070 */  sw        $v0, 0x70($s0)
/* A3AEEC 80241A0C 28420040 */  slti      $v0, $v0, 0x40
/* A3AEF0 80241A10 10400002 */  beqz      $v0, .L80241A1C
/* A3AEF4 80241A14 24020040 */   addiu    $v0, $zero, 0x40
/* A3AEF8 80241A18 AE020070 */  sw        $v0, 0x70($s0)
.L80241A1C:
/* A3AEFC 80241A1C 92040073 */  lbu       $a0, 0x73($s0)
/* A3AF00 80241A20 0000382D */  daddu     $a3, $zero, $zero
/* A3AF04 80241A24 AFA00010 */  sw        $zero, 0x10($sp)
/* A3AF08 80241A28 AFA00014 */  sw        $zero, 0x14($sp)
/* A3AF0C 80241A2C 0080282D */  daddu     $a1, $a0, $zero
/* A3AF10 80241A30 0C046FE6 */  jal       func_8011BF98
/* A3AF14 80241A34 0080302D */   daddu    $a2, $a0, $zero
/* A3AF18 80241A38 8E020070 */  lw        $v0, 0x70($s0)
/* A3AF1C 80241A3C 8FBF001C */  lw        $ra, 0x1c($sp)
/* A3AF20 80241A40 8FB00018 */  lw        $s0, 0x18($sp)
/* A3AF24 80241A44 38420040 */  xori      $v0, $v0, 0x40
/* A3AF28 80241A48 2C420001 */  sltiu     $v0, $v0, 1
/* A3AF2C 80241A4C 00021040 */  sll       $v0, $v0, 1
/* A3AF30 80241A50 03E00008 */  jr        $ra
/* A3AF34 80241A54 27BD0020 */   addiu    $sp, $sp, 0x20
