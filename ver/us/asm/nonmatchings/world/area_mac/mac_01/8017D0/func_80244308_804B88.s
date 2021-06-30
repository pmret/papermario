.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244308_804B88
/* 804B88 80244308 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 804B8C 8024430C AFB00018 */  sw        $s0, 0x18($sp)
/* 804B90 80244310 0080802D */  daddu     $s0, $a0, $zero
/* 804B94 80244314 10A00003 */  beqz      $a1, .L80244324
/* 804B98 80244318 AFBF001C */   sw       $ra, 0x1c($sp)
/* 804B9C 8024431C 24020040 */  addiu     $v0, $zero, 0x40
/* 804BA0 80244320 AE020070 */  sw        $v0, 0x70($s0)
.L80244324:
/* 804BA4 80244324 8E020070 */  lw        $v0, 0x70($s0)
/* 804BA8 80244328 24420004 */  addiu     $v0, $v0, 4
/* 804BAC 8024432C AE020070 */  sw        $v0, 0x70($s0)
/* 804BB0 80244330 28420100 */  slti      $v0, $v0, 0x100
/* 804BB4 80244334 14400002 */  bnez      $v0, .L80244340
/* 804BB8 80244338 240200FF */   addiu    $v0, $zero, 0xff
/* 804BBC 8024433C AE020070 */  sw        $v0, 0x70($s0)
.L80244340:
/* 804BC0 80244340 92040073 */  lbu       $a0, 0x73($s0)
/* 804BC4 80244344 0000382D */  daddu     $a3, $zero, $zero
/* 804BC8 80244348 AFA00010 */  sw        $zero, 0x10($sp)
/* 804BCC 8024434C AFA00014 */  sw        $zero, 0x14($sp)
/* 804BD0 80244350 0080282D */  daddu     $a1, $a0, $zero
/* 804BD4 80244354 0C046FE6 */  jal       set_model_env_color_parameters
/* 804BD8 80244358 0080302D */   daddu    $a2, $a0, $zero
/* 804BDC 8024435C 8E030070 */  lw        $v1, 0x70($s0)
/* 804BE0 80244360 240200FF */  addiu     $v0, $zero, 0xff
/* 804BE4 80244364 1462001A */  bne       $v1, $v0, .L802443D0
/* 804BE8 80244368 0000102D */   daddu    $v0, $zero, $zero
/* 804BEC 8024436C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 804BF0 80244370 2404002B */   addiu    $a0, $zero, 0x2b
/* 804BF4 80244374 0C046B4C */  jal       get_model_from_list_index
/* 804BF8 80244378 0040202D */   daddu    $a0, $v0, $zero
/* 804BFC 8024437C 0040202D */  daddu     $a0, $v0, $zero
/* 804C00 80244380 2405FFFF */  addiu     $a1, $zero, -1
/* 804C04 80244384 0C046F1F */  jal       set_mdl_custom_gfx_set
/* 804C08 80244388 0000302D */   daddu    $a2, $zero, $zero
/* 804C0C 8024438C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 804C10 80244390 2404002A */   addiu    $a0, $zero, 0x2a
/* 804C14 80244394 0C046B4C */  jal       get_model_from_list_index
/* 804C18 80244398 0040202D */   daddu    $a0, $v0, $zero
/* 804C1C 8024439C 0040202D */  daddu     $a0, $v0, $zero
/* 804C20 802443A0 2405FFFF */  addiu     $a1, $zero, -1
/* 804C24 802443A4 0C046F1F */  jal       set_mdl_custom_gfx_set
/* 804C28 802443A8 0000302D */   daddu    $a2, $zero, $zero
/* 804C2C 802443AC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 804C30 802443B0 24040029 */   addiu    $a0, $zero, 0x29
/* 804C34 802443B4 0C046B4C */  jal       get_model_from_list_index
/* 804C38 802443B8 0040202D */   daddu    $a0, $v0, $zero
/* 804C3C 802443BC 0040202D */  daddu     $a0, $v0, $zero
/* 804C40 802443C0 2405FFFF */  addiu     $a1, $zero, -1
/* 804C44 802443C4 0C046F1F */  jal       set_mdl_custom_gfx_set
/* 804C48 802443C8 0000302D */   daddu    $a2, $zero, $zero
/* 804C4C 802443CC 24020002 */  addiu     $v0, $zero, 2
.L802443D0:
/* 804C50 802443D0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 804C54 802443D4 8FB00018 */  lw        $s0, 0x18($sp)
/* 804C58 802443D8 03E00008 */  jr        $ra
/* 804C5C 802443DC 27BD0020 */   addiu    $sp, $sp, 0x20
