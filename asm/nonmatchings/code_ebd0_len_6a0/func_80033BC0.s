.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033BC0
/* EFC0 80033BC0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EFC4 80033BC4 AFB30024 */  sw        $s3, 0x24($sp)
/* EFC8 80033BC8 3C138011 */  lui       $s3, %hi(gPlayerStatus)
/* EFCC 80033BCC 2673EFC8 */  addiu     $s3, $s3, %lo(gPlayerStatus)
/* EFD0 80033BD0 3C06800A */  lui       $a2, %hi(D_800A0900)
/* EFD4 80033BD4 24C60900 */  addiu     $a2, $a2, %lo(D_800A0900)
/* EFD8 80033BD8 AFBF0028 */  sw        $ra, 0x28($sp)
/* EFDC 80033BDC AFB20020 */  sw        $s2, 0x20($sp)
/* EFE0 80033BE0 AFB1001C */  sw        $s1, 0x1c($sp)
/* EFE4 80033BE4 AFB00018 */  sw        $s0, 0x18($sp)
/* EFE8 80033BE8 80C20000 */  lb        $v0, ($a2)
/* EFEC 80033BEC 90C30000 */  lbu       $v1, ($a2)
/* EFF0 80033BF0 04400095 */  bltz      $v0, .L80033E48
/* EFF4 80033BF4 2462FFFF */   addiu    $v0, $v1, -1
/* EFF8 80033BF8 A0C20000 */  sb        $v0, ($a2)
/* EFFC 80033BFC 00021600 */  sll       $v0, $v0, 0x18
/* F000 80033C00 14400091 */  bnez      $v0, .L80033E48
/* F004 80033C04 24050003 */   addiu    $a1, $zero, 3
/* F008 80033C08 3C048007 */  lui       $a0, 0x8007
/* F00C 80033C0C 248478A0 */  addiu     $a0, $a0, 0x78a0
/* F010 80033C10 2402FFFF */  addiu     $v0, $zero, -1
/* F014 80033C14 0C017CBC */  jal       nuGfxSetCfb
/* F018 80033C18 A0C20000 */   sb       $v0, ($a2)
/* F01C 80033C1C 3C04800A */  lui       $a0, %hi(D_8009A650)
/* F020 80033C20 2484A650 */  addiu     $a0, $a0, %lo(D_8009A650)
/* F024 80033C24 8C820000 */  lw        $v0, ($a0)
/* F028 80033C28 2403FFF7 */  addiu     $v1, $zero, -9
/* F02C 80033C2C 00431024 */  and       $v0, $v0, $v1
/* F030 80033C30 0C018030 */  jal       nuContRmbForceStopEnd
/* F034 80033C34 AC820000 */   sw       $v0, ($a0)
/* F038 80033C38 0C05260E */  jal       func_80149838
/* F03C 80033C3C 00000000 */   nop
/* F040 80033C40 0C016AFA */  jal       get_current_map_header
/* F044 80033C44 00000000 */   nop
/* F048 80033C48 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* F04C 80033C4C 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* F050 80033C50 8E040000 */  lw        $a0, ($s0)
/* F054 80033C54 0040902D */  daddu     $s2, $v0, $zero
/* F058 80033C58 84830086 */  lh        $v1, 0x86($a0)
/* F05C 80033C5C 8482008C */  lh        $v0, 0x8c($a0)
/* F060 80033C60 00031900 */  sll       $v1, $v1, 4
/* F064 80033C64 3C018009 */  lui       $at, 0x8009
/* F068 80033C68 00230821 */  addu      $at, $at, $v1
/* F06C 80033C6C 8C2334F4 */  lw        $v1, 0x34f4($at)
/* F070 80033C70 00021140 */  sll       $v0, $v0, 5
/* F074 80033C74 0C0902AA */  jal       func_80240AA8
/* F078 80033C78 00628821 */   addu     $s1, $v1, $v0
/* F07C 80033C7C 8E020000 */  lw        $v0, ($s0)
/* F080 80033C80 0C016BE1 */  jal       func_8005AF84
/* F084 80033C84 A0400070 */   sb       $zero, 0x70($v0)
/* F088 80033C88 0C00AB37 */  jal       func_8002ACDC
/* F08C 80033C8C 00000000 */   nop
/* F090 80033C90 0C05259C */  jal       func_80149670
/* F094 80033C94 24040001 */   addiu    $a0, $zero, 1
/* F098 80033C98 8E030000 */  lw        $v1, ($s0)
/* F09C 80033C9C 9062007E */  lbu       $v0, 0x7e($v1)
/* F0A0 80033CA0 304200FE */  andi      $v0, $v0, 0xfe
/* F0A4 80033CA4 0C00AB28 */  jal       battle_heap_create
/* F0A8 80033CA8 A062007E */   sb       $v0, 0x7e($v1)
/* F0AC 80033CAC 8E020000 */  lw        $v0, ($s0)
/* F0B0 80033CB0 0C0B763E */  jal       func_802DD8F8
/* F0B4 80033CB4 80440084 */   lb       $a0, 0x84($v0)
/* F0B8 80033CB8 0C0457FA */  jal       init_model_data
/* F0BC 80033CBC 00000000 */   nop
/* F0C0 80033CC0 0C05203C */  jal       func_801480F0
/* F0C4 80033CC4 00000000 */   nop
/* F0C8 80033CC8 0C048316 */  jal       init_virtual_models
/* F0CC 80033CCC 00000000 */   nop
/* F0D0 80033CD0 0C0478C4 */  jal       func_8011E310
/* F0D4 80033CD4 00000000 */   nop
/* F0D8 80033CD8 0C048C45 */  jal       init_dynamic_entity_list
/* F0DC 80033CDC 00000000 */   nop
/* F0E0 80033CE0 0000202D */  daddu     $a0, $zero, $zero
/* F0E4 80033CE4 0C0514BA */  jal       func_801452E8
/* F0E8 80033CE8 0080282D */   daddu    $a1, $a0, $zero
/* F0EC 80033CEC 0C0504C0 */  jal       init_menu_icon_list
/* F0F0 80033CF0 00000000 */   nop
/* F0F4 80033CF4 0C04C433 */  jal       init_item_entity_list
/* F0F8 80033CF8 00000000 */   nop
/* F0FC 80033CFC 0C0B0CBB */  jal       init_script_list
/* F100 80033D00 00000000 */   nop
/* F104 80033D04 0C00E14B */  jal       init_npc_list
/* F108 80033D08 00000000 */   nop
/* F10C 80033D0C 0C044396 */  jal       func_80110E58
/* F110 80033D10 00000000 */   nop
/* F114 80033D14 0C0515CA */  jal       init_trigger_list
/* F118 80033D18 00000000 */   nop
/* F11C 80033D1C 8E020000 */  lw        $v0, ($s0)
/* F120 80033D20 904200AA */  lbu       $v0, 0xaa($v0)
/* F124 80033D24 30420001 */  andi      $v0, $v0, 1
/* F128 80033D28 10400008 */  beqz      $v0, .L80033D4C
/* F12C 80033D2C 00000000 */   nop
/* F130 80033D30 0C00EC6C */  jal       func_8003B1B0
/* F134 80033D34 00000000 */   nop
/* F138 80033D38 3C02800A */  lui       $v0, 0x800a
/* F13C 80033D3C 8C420904 */  lw        $v0, 0x904($v0)
/* F140 80033D40 24040011 */  addiu     $a0, $zero, 0x11
/* F144 80033D44 0800CF90 */  j         .L80033E40
/* F148 80033D48 AE620004 */   sw       $v0, 4($s3)
.L80033D4C:
/* F14C 80033D4C 3C028011 */  lui       $v0, %hi(gPlayerData)
/* F150 80033D50 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* F154 80033D54 0C03AC80 */  jal       func_800EB200
/* F158 80033D58 80440012 */   lb       $a0, 0x12($v0)
/* F15C 80033D5C 0C0169B0 */  jal       load_world_script_api
/* F160 80033D60 00000000 */   nop
/* F164 80033D64 3C04800E */  lui       $a0, 0x800e
/* F168 80033D68 24849230 */  addiu     $a0, $a0, -0x6dd0
/* F16C 80033D6C 0C016B3A */  jal       load_asset_by_name
/* F170 80033D70 27A50010 */   addiu    $a1, $sp, 0x10
/* F174 80033D74 0040802D */  daddu     $s0, $v0, $zero
/* F178 80033D78 3C058021 */  lui       $a1, 0x8021
/* F17C 80033D7C 24A50000 */  addiu     $a1, $a1, 0
/* F180 80033D80 0C01BB7C */  jal       decode_yay0
/* F184 80033D84 0200202D */   daddu    $a0, $s0, $zero
/* F188 80033D88 0C00AB1E */  jal       general_heap_free
/* F18C 80033D8C 0200202D */   daddu    $a0, $s0, $zero
/* F190 80033D90 0C016BE5 */  jal       initialize_collision
/* F194 80033D94 00000000 */   nop
/* F198 80033D98 0C016C16 */  jal       load_collision
/* F19C 80033D9C 00000000 */   nop
/* F1A0 80033DA0 8E240008 */  lw        $a0, 8($s1)
/* F1A4 80033DA4 10800004 */  beqz      $a0, .L80033DB8
/* F1A8 80033DA8 00000000 */   nop
/* F1AC 80033DAC 8E25000C */  lw        $a1, 0xc($s1)
/* F1B0 80033DB0 0C00A5CF */  jal       dma_copy
/* F1B4 80033DB4 8E260010 */   lw       $a2, 0x10($s1)
.L80033DB8:
/* F1B8 80033DB8 0C05175C */  jal       load_map_bg
/* F1BC 80033DBC 8E240014 */   lw       $a0, 0x14($s1)
/* F1C0 80033DC0 8E440038 */  lw        $a0, 0x38($s2)
/* F1C4 80033DC4 50800005 */  beql      $a0, $zero, .L80033DDC
/* F1C8 80033DC8 24040128 */   addiu    $a0, $zero, 0x128
/* F1CC 80033DCC 0C05178A */  jal       read_background_size
/* F1D0 80033DD0 00000000 */   nop
/* F1D4 80033DD4 0800CF7B */  j         .L80033DEC
/* F1D8 80033DD8 00000000 */   nop
.L80033DDC:
/* F1DC 80033DDC 240500C8 */  addiu     $a1, $zero, 0xc8
/* F1E0 80033DE0 2406000C */  addiu     $a2, $zero, 0xc
/* F1E4 80033DE4 0C05179C */  jal       set_background_size
/* F1E8 80033DE8 24070014 */   addiu    $a3, $zero, 0x14
.L80033DEC:
/* F1EC 80033DEC 3C04800B */  lui       $a0, 0x800b
/* F1F0 80033DF0 24840CF0 */  addiu     $a0, $a0, 0xcf0
/* F1F4 80033DF4 0C016B74 */  jal       get_asset_offset
/* F1F8 80033DF8 27A50010 */   addiu    $a1, $sp, 0x10
/* F1FC 80033DFC 8E440000 */  lw        $a0, ($s2)
/* F200 80033E00 8FA60010 */  lw        $a2, 0x10($sp)
/* F204 80033E04 0C045709 */  jal       load_model_textures
/* F208 80033E08 0040282D */   daddu    $a1, $v0, $zero
/* F20C 80033E0C 0C04584B */  jal       calculate_model_sizes
/* F210 80033E10 00000000 */   nop
/* F214 80033E14 0C00EC6C */  jal       func_8003B1B0
/* F218 80033E18 00000000 */   nop
/* F21C 80033E1C 3C02800A */  lui       $v0, 0x800a
/* F220 80033E20 8C420904 */  lw        $v0, 0x904($v0)
/* F224 80033E24 3C04800A */  lui       $a0, 0x800a
/* F228 80033E28 8C840908 */  lw        $a0, 0x908($a0)
/* F22C 80033E2C 10800003 */  beqz      $a0, .L80033E3C
/* F230 80033E30 AE620004 */   sw       $v0, 4($s3)
/* F234 80033E34 0C009C22 */  jal       func_80027088
/* F238 80033E38 00000000 */   nop
.L80033E3C:
/* F23C 80033E3C 24040004 */  addiu     $a0, $zero, 4
.L80033E40:
/* F240 80033E40 0C00CD3C */  jal       set_game_mode
/* F244 80033E44 00000000 */   nop
.L80033E48:
/* F248 80033E48 8FBF0028 */  lw        $ra, 0x28($sp)
/* F24C 80033E4C 8FB30024 */  lw        $s3, 0x24($sp)
/* F250 80033E50 8FB20020 */  lw        $s2, 0x20($sp)
/* F254 80033E54 8FB1001C */  lw        $s1, 0x1c($sp)
/* F258 80033E58 8FB00018 */  lw        $s0, 0x18($sp)
/* F25C 80033E5C 03E00008 */  jr        $ra
/* F260 80033E60 27BD0030 */   addiu    $sp, $sp, 0x30
