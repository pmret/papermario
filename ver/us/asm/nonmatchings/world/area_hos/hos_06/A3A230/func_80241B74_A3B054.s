.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B74_A3B054
/* A3B054 80241B74 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A3B058 80241B78 AFB00018 */  sw        $s0, 0x18($sp)
/* A3B05C 80241B7C 0080802D */  daddu     $s0, $a0, $zero
/* A3B060 80241B80 10A00003 */  beqz      $a1, .L80241B90
/* A3B064 80241B84 AFBF001C */   sw       $ra, 0x1c($sp)
/* A3B068 80241B88 24020040 */  addiu     $v0, $zero, 0x40
/* A3B06C 80241B8C AE020070 */  sw        $v0, 0x70($s0)
.L80241B90:
/* A3B070 80241B90 8E020070 */  lw        $v0, 0x70($s0)
/* A3B074 80241B94 24420004 */  addiu     $v0, $v0, 4
/* A3B078 80241B98 AE020070 */  sw        $v0, 0x70($s0)
/* A3B07C 80241B9C 28420100 */  slti      $v0, $v0, 0x100
/* A3B080 80241BA0 14400002 */  bnez      $v0, .L80241BAC
/* A3B084 80241BA4 240200FF */   addiu    $v0, $zero, 0xff
/* A3B088 80241BA8 AE020070 */  sw        $v0, 0x70($s0)
.L80241BAC:
/* A3B08C 80241BAC 92040073 */  lbu       $a0, 0x73($s0)
/* A3B090 80241BB0 0000382D */  daddu     $a3, $zero, $zero
/* A3B094 80241BB4 AFA00010 */  sw        $zero, 0x10($sp)
/* A3B098 80241BB8 AFA00014 */  sw        $zero, 0x14($sp)
/* A3B09C 80241BBC 0080282D */  daddu     $a1, $a0, $zero
/* A3B0A0 80241BC0 0C046FE6 */  jal       set_model_env_color_parameters
/* A3B0A4 80241BC4 0080302D */   daddu    $a2, $a0, $zero
/* A3B0A8 80241BC8 8E030070 */  lw        $v1, 0x70($s0)
/* A3B0AC 80241BCC 240200FF */  addiu     $v0, $zero, 0xff
/* A3B0B0 80241BD0 1462003A */  bne       $v1, $v0, .L80241CBC
/* A3B0B4 80241BD4 0000102D */   daddu    $v0, $zero, $zero
/* A3B0B8 80241BD8 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3B0BC 80241BDC 24040079 */   addiu    $a0, $zero, 0x79
/* A3B0C0 80241BE0 0C046B4C */  jal       get_model_from_list_index
/* A3B0C4 80241BE4 0040202D */   daddu    $a0, $v0, $zero
/* A3B0C8 80241BE8 0040202D */  daddu     $a0, $v0, $zero
/* A3B0CC 80241BEC 2405FFFF */  addiu     $a1, $zero, -1
/* A3B0D0 80241BF0 0C046F1F */  jal       set_mdl_custom_gfx_set
/* A3B0D4 80241BF4 0000302D */   daddu    $a2, $zero, $zero
/* A3B0D8 80241BF8 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3B0DC 80241BFC 2404007A */   addiu    $a0, $zero, 0x7a
/* A3B0E0 80241C00 0C046B4C */  jal       get_model_from_list_index
/* A3B0E4 80241C04 0040202D */   daddu    $a0, $v0, $zero
/* A3B0E8 80241C08 0040202D */  daddu     $a0, $v0, $zero
/* A3B0EC 80241C0C 2405FFFF */  addiu     $a1, $zero, -1
/* A3B0F0 80241C10 0C046F1F */  jal       set_mdl_custom_gfx_set
/* A3B0F4 80241C14 0000302D */   daddu    $a2, $zero, $zero
/* A3B0F8 80241C18 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3B0FC 80241C1C 2404007B */   addiu    $a0, $zero, 0x7b
/* A3B100 80241C20 0C046B4C */  jal       get_model_from_list_index
/* A3B104 80241C24 0040202D */   daddu    $a0, $v0, $zero
/* A3B108 80241C28 0040202D */  daddu     $a0, $v0, $zero
/* A3B10C 80241C2C 2405FFFF */  addiu     $a1, $zero, -1
/* A3B110 80241C30 0C046F1F */  jal       set_mdl_custom_gfx_set
/* A3B114 80241C34 0000302D */   daddu    $a2, $zero, $zero
/* A3B118 80241C38 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3B11C 80241C3C 2404007C */   addiu    $a0, $zero, 0x7c
/* A3B120 80241C40 0C046B4C */  jal       get_model_from_list_index
/* A3B124 80241C44 0040202D */   daddu    $a0, $v0, $zero
/* A3B128 80241C48 0040202D */  daddu     $a0, $v0, $zero
/* A3B12C 80241C4C 2405FFFF */  addiu     $a1, $zero, -1
/* A3B130 80241C50 0C046F1F */  jal       set_mdl_custom_gfx_set
/* A3B134 80241C54 0000302D */   daddu    $a2, $zero, $zero
/* A3B138 80241C58 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3B13C 80241C5C 2404007D */   addiu    $a0, $zero, 0x7d
/* A3B140 80241C60 0C046B4C */  jal       get_model_from_list_index
/* A3B144 80241C64 0040202D */   daddu    $a0, $v0, $zero
/* A3B148 80241C68 0040202D */  daddu     $a0, $v0, $zero
/* A3B14C 80241C6C 2405FFFF */  addiu     $a1, $zero, -1
/* A3B150 80241C70 0C046F1F */  jal       set_mdl_custom_gfx_set
/* A3B154 80241C74 0000302D */   daddu    $a2, $zero, $zero
/* A3B158 80241C78 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3B15C 80241C7C 2404007F */   addiu    $a0, $zero, 0x7f
/* A3B160 80241C80 0C046B4C */  jal       get_model_from_list_index
/* A3B164 80241C84 0040202D */   daddu    $a0, $v0, $zero
/* A3B168 80241C88 0040202D */  daddu     $a0, $v0, $zero
/* A3B16C 80241C8C 2405FFFF */  addiu     $a1, $zero, -1
/* A3B170 80241C90 0C046F1F */  jal       set_mdl_custom_gfx_set
/* A3B174 80241C94 0000302D */   daddu    $a2, $zero, $zero
/* A3B178 80241C98 0C046C04 */  jal       get_model_list_index_from_tree_index
/* A3B17C 80241C9C 240400D0 */   addiu    $a0, $zero, 0xd0
/* A3B180 80241CA0 0C046B4C */  jal       get_model_from_list_index
/* A3B184 80241CA4 0040202D */   daddu    $a0, $v0, $zero
/* A3B188 80241CA8 0040202D */  daddu     $a0, $v0, $zero
/* A3B18C 80241CAC 2405FFFF */  addiu     $a1, $zero, -1
/* A3B190 80241CB0 0C046F1F */  jal       set_mdl_custom_gfx_set
/* A3B194 80241CB4 0000302D */   daddu    $a2, $zero, $zero
/* A3B198 80241CB8 24020002 */  addiu     $v0, $zero, 2
.L80241CBC:
/* A3B19C 80241CBC 8FBF001C */  lw        $ra, 0x1c($sp)
/* A3B1A0 80241CC0 8FB00018 */  lw        $s0, 0x18($sp)
/* A3B1A4 80241CC4 03E00008 */  jr        $ra
/* A3B1A8 80241CC8 27BD0020 */   addiu    $sp, $sp, 0x20
