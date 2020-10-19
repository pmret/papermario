.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412AC
/* 865DEC 802412AC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 865DF0 802412B0 AFB10014 */  sw        $s1, 0x14($sp)
/* 865DF4 802412B4 0080882D */  daddu     $s1, $a0, $zero
/* 865DF8 802412B8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 865DFC 802412BC AFB3001C */  sw        $s3, 0x1c($sp)
/* 865E00 802412C0 AFB20018 */  sw        $s2, 0x18($sp)
/* 865E04 802412C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 865E08 802412C8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 865E0C 802412CC F7B40028 */  sdc1      $f20, 0x28($sp)
/* 865E10 802412D0 8E30000C */  lw        $s0, 0xc($s1)
/* 865E14 802412D4 8E050000 */  lw        $a1, ($s0)
/* 865E18 802412D8 0C0B1EAF */  jal       get_variable
/* 865E1C 802412DC 26100004 */   addiu    $s0, $s0, 4
/* 865E20 802412E0 8E120000 */  lw        $s2, ($s0)
/* 865E24 802412E4 26100004 */  addiu     $s0, $s0, 4
/* 865E28 802412E8 8E130000 */  lw        $s3, ($s0)
/* 865E2C 802412EC 8E100004 */  lw        $s0, 4($s0)
/* 865E30 802412F0 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 865E34 802412F4 0040202D */   daddu    $a0, $v0, $zero
/* 865E38 802412F8 0C046B4C */  jal       get_model_from_list_index
/* 865E3C 802412FC 0040202D */   daddu    $a0, $v0, $zero
/* 865E40 80241300 0040302D */  daddu     $a2, $v0, $zero
/* 865E44 80241304 94C20000 */  lhu       $v0, ($a2)
/* 865E48 80241308 30420400 */  andi      $v0, $v0, 0x400
/* 865E4C 8024130C 10400005 */  beqz      $v0, .L80241324
/* 865E50 80241310 0220202D */   daddu    $a0, $s1, $zero
/* 865E54 80241314 C4C00088 */  lwc1      $f0, 0x88($a2)
/* 865E58 80241318 C4D6008C */  lwc1      $f22, 0x8c($a2)
/* 865E5C 8024131C 080904CD */  j         .L80241334
/* 865E60 80241320 C4D40090 */   lwc1     $f20, 0x90($a2)
.L80241324:
/* 865E64 80241324 4480A000 */  mtc1      $zero, $f20
/* 865E68 80241328 00000000 */  nop       
/* 865E6C 8024132C 4600A586 */  mov.s     $f22, $f20
/* 865E70 80241330 4600A006 */  mov.s     $f0, $f20
.L80241334:
/* 865E74 80241334 44060000 */  mfc1      $a2, $f0
/* 865E78 80241338 0C0B2190 */  jal       set_float_variable
/* 865E7C 8024133C 0240282D */   daddu    $a1, $s2, $zero
/* 865E80 80241340 0220202D */  daddu     $a0, $s1, $zero
/* 865E84 80241344 4406B000 */  mfc1      $a2, $f22
/* 865E88 80241348 0C0B2190 */  jal       set_float_variable
/* 865E8C 8024134C 0260282D */   daddu    $a1, $s3, $zero
/* 865E90 80241350 0220202D */  daddu     $a0, $s1, $zero
/* 865E94 80241354 4406A000 */  mfc1      $a2, $f20
/* 865E98 80241358 0C0B2190 */  jal       set_float_variable
/* 865E9C 8024135C 0200282D */   daddu    $a1, $s0, $zero
/* 865EA0 80241360 8FBF0020 */  lw        $ra, 0x20($sp)
/* 865EA4 80241364 8FB3001C */  lw        $s3, 0x1c($sp)
/* 865EA8 80241368 8FB20018 */  lw        $s2, 0x18($sp)
/* 865EAC 8024136C 8FB10014 */  lw        $s1, 0x14($sp)
/* 865EB0 80241370 8FB00010 */  lw        $s0, 0x10($sp)
/* 865EB4 80241374 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 865EB8 80241378 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 865EBC 8024137C 24020002 */  addiu     $v0, $zero, 2
/* 865EC0 80241380 03E00008 */  jr        $ra
/* 865EC4 80241384 27BD0038 */   addiu    $sp, $sp, 0x38
