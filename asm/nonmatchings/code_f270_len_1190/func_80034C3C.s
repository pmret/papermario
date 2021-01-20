.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80034C3C
/* 1003C 80034C3C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 10040 80034C40 AFB00018 */  sw        $s0, 0x18($sp)
/* 10044 80034C44 3C10800A */  lui       $s0, %hi(D_800A0921)
/* 10048 80034C48 26100921 */  addiu     $s0, $s0, %lo(D_800A0921)
/* 1004C 80034C4C AFBF0024 */  sw        $ra, 0x24($sp)
/* 10050 80034C50 AFB20020 */  sw        $s2, 0x20($sp)
/* 10054 80034C54 AFB1001C */  sw        $s1, 0x1c($sp)
/* 10058 80034C58 82030000 */  lb        $v1, ($s0)
/* 1005C 80034C5C 24020003 */  addiu     $v0, $zero, 3
/* 10060 80034C60 106200B8 */  beq       $v1, $v0, .L80034F44
/* 10064 80034C64 28620004 */   slti     $v0, $v1, 4
/* 10068 80034C68 14400006 */  bnez      $v0, .L80034C84
/* 1006C 80034C6C 28620002 */   slti     $v0, $v1, 2
/* 10070 80034C70 24020004 */  addiu     $v0, $zero, 4
/* 10074 80034C74 106200CA */  beq       $v1, $v0, .L80034FA0
/* 10078 80034C78 00000000 */   nop
/* 1007C 80034C7C 0800D3F6 */  j         .L80034FD8
/* 10080 80034C80 00000000 */   nop
.L80034C84:
/* 10084 80034C84 104000D4 */  beqz      $v0, .L80034FD8
/* 10088 80034C88 00000000 */   nop
/* 1008C 80034C8C 046000D2 */  bltz      $v1, .L80034FD8
/* 10090 80034C90 24020004 */   addiu    $v0, $zero, 4
/* 10094 80034C94 3C06800A */  lui       $a2, %hi(D_800A0920)
/* 10098 80034C98 24C60920 */  addiu     $a2, $a2, %lo(D_800A0920)
/* 1009C 80034C9C 80C30000 */  lb        $v1, ($a2)
/* 100A0 80034CA0 14620007 */  bne       $v1, $v0, .L80034CC0
/* 100A4 80034CA4 00000000 */   nop
/* 100A8 80034CA8 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 100AC 80034CAC 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 100B0 80034CB0 8C620000 */  lw        $v0, ($v1)
/* 100B4 80034CB4 34420008 */  ori       $v0, $v0, 8
/* 100B8 80034CB8 AC620000 */  sw        $v0, ($v1)
/* 100BC 80034CBC 80C30000 */  lb        $v1, ($a2)
.L80034CC0:
/* 100C0 80034CC0 046000C5 */  bltz      $v1, .L80034FD8
/* 100C4 80034CC4 90C20000 */   lbu      $v0, ($a2)
/* 100C8 80034CC8 10600005 */  beqz      $v1, .L80034CE0
/* 100CC 80034CCC 2442FFFF */   addiu    $v0, $v0, -1
/* 100D0 80034CD0 A0C20000 */  sb        $v0, ($a2)
/* 100D4 80034CD4 00021600 */  sll       $v0, $v0, 0x18
/* 100D8 80034CD8 144000BF */  bnez      $v0, .L80034FD8
/* 100DC 80034CDC 00000000 */   nop
.L80034CE0:
/* 100E0 80034CE0 3C048007 */  lui       $a0, %hi(D_80077950)
/* 100E4 80034CE4 24847950 */  addiu     $a0, $a0, %lo(D_80077950)
/* 100E8 80034CE8 24050003 */  addiu     $a1, $zero, 3
/* 100EC 80034CEC 2402FFFF */  addiu     $v0, $zero, -1
/* 100F0 80034CF0 0C017CBC */  jal       nuGfxSetCfb
/* 100F4 80034CF4 A0C20000 */   sb       $v0, ($a2)
/* 100F8 80034CF8 0C0911C2 */  jal       pause_cleanup
/* 100FC 80034CFC 00000000 */   nop
/* 10100 80034D00 3C04800A */  lui       $a0, %hi(D_8009A650)
/* 10104 80034D04 2484A650 */  addiu     $a0, $a0, %lo(D_8009A650)
/* 10108 80034D08 8C820000 */  lw        $v0, ($a0)
/* 1010C 80034D0C 2403FFF7 */  addiu     $v1, $zero, -9
/* 10110 80034D10 00431024 */  and       $v0, $v0, $v1
/* 10114 80034D14 0C016AFA */  jal       get_current_map_header
/* 10118 80034D18 AC820000 */   sw       $v0, ($a0)
/* 1011C 80034D1C 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 10120 80034D20 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 10124 80034D24 8E040000 */  lw        $a0, ($s0)
/* 10128 80034D28 84830086 */  lh        $v1, 0x86($a0)
/* 1012C 80034D2C 00031900 */  sll       $v1, $v1, 4
/* 10130 80034D30 3C068009 */  lui       $a2, %hi(D_800934F4)
/* 10134 80034D34 00C33021 */  addu      $a2, $a2, $v1
/* 10138 80034D38 8CC634F4 */  lw        $a2, %lo(D_800934F4)($a2)
/* 1013C 80034D3C 0040902D */  daddu     $s2, $v0, $zero
/* 10140 80034D40 A0800070 */  sb        $zero, 0x70($a0)
/* 10144 80034D44 8484008C */  lh        $a0, 0x8c($a0)
/* 10148 80034D48 8E050000 */  lw        $a1, ($s0)
/* 1014C 80034D4C 00042140 */  sll       $a0, $a0, 5
/* 10150 80034D50 94A30148 */  lhu       $v1, 0x148($a1)
/* 10154 80034D54 00C48821 */  addu      $s1, $a2, $a0
/* 10158 80034D58 3063FF0F */  andi      $v1, $v1, 0xff0f
/* 1015C 80034D5C 0C016BE1 */  jal       func_8005AF84
/* 10160 80034D60 A4A30148 */   sh       $v1, 0x148($a1)
/* 10164 80034D64 0C00AB37 */  jal       func_8002ACDC
/* 10168 80034D68 00000000 */   nop
/* 1016C 80034D6C 0C018030 */  jal       nuContRmbForceStopEnd
/* 10170 80034D70 00000000 */   nop
/* 10174 80034D74 0C05259C */  jal       func_80149670
/* 10178 80034D78 24040001 */   addiu    $a0, $zero, 1
/* 1017C 80034D7C 8E020000 */  lw        $v0, ($s0)
/* 10180 80034D80 0C0B763E */  jal       func_802DD8F8
/* 10184 80034D84 80440084 */   lb       $a0, 0x84($v0)
/* 10188 80034D88 0C0457FA */  jal       init_model_data
/* 1018C 80034D8C 00000000 */   nop
/* 10190 80034D90 0C05203C */  jal       func_801480F0
/* 10194 80034D94 00000000 */   nop
/* 10198 80034D98 0C048316 */  jal       init_entity_models
/* 1019C 80034D9C 00000000 */   nop
/* 101A0 80034DA0 0C0478C4 */  jal       func_8011E310
/* 101A4 80034DA4 00000000 */   nop
/* 101A8 80034DA8 0C048C45 */  jal       init_dynamic_entity_list
/* 101AC 80034DAC 00000000 */   nop
/* 101B0 80034DB0 0000202D */  daddu     $a0, $zero, $zero
/* 101B4 80034DB4 0C0514BA */  jal       func_801452E8
/* 101B8 80034DB8 0080282D */   daddu    $a1, $a0, $zero
/* 101BC 80034DBC 0C0504C0 */  jal       init_menu_icon_list
/* 101C0 80034DC0 00000000 */   nop
/* 101C4 80034DC4 0C04C433 */  jal       init_item_entity_list
/* 101C8 80034DC8 00000000 */   nop
/* 101CC 80034DCC 0C0B0CBB */  jal       init_script_list
/* 101D0 80034DD0 00000000 */   nop
/* 101D4 80034DD4 0C00E14B */  jal       init_npc_list
/* 101D8 80034DD8 00000000 */   nop
/* 101DC 80034DDC 0C044396 */  jal       func_80110E58
/* 101E0 80034DE0 00000000 */   nop
/* 101E4 80034DE4 0C0515CA */  jal       init_trigger_list
/* 101E8 80034DE8 00000000 */   nop
/* 101EC 80034DEC 3C04800A */  lui       $a0, %hi(D_800A0924)
/* 101F0 80034DF0 8C840924 */  lw        $a0, %lo(D_800A0924)($a0)
/* 101F4 80034DF4 0C0525FF */  jal       func_801497FC
/* 101F8 80034DF8 00000000 */   nop
/* 101FC 80034DFC 0C052B1C */  jal       func_8014AC70
/* 10200 80034E00 00000000 */   nop
/* 10204 80034E04 0C0169B0 */  jal       load_world_script_api
/* 10208 80034E08 00000000 */   nop
/* 1020C 80034E0C 3C04800E */  lui       $a0, %hi(D_800D9230)
/* 10210 80034E10 24849230 */  addiu     $a0, $a0, %lo(D_800D9230)
/* 10214 80034E14 0C016B3A */  jal       load_asset_by_name
/* 10218 80034E18 27A50010 */   addiu    $a1, $sp, 0x10
/* 1021C 80034E1C 0040802D */  daddu     $s0, $v0, $zero
/* 10220 80034E20 3C058021 */  lui       $a1, %hi(D_80210000)
/* 10224 80034E24 24A50000 */  addiu     $a1, $a1, %lo(D_80210000)
/* 10228 80034E28 0C01BB7C */  jal       decode_yay0
/* 1022C 80034E2C 0200202D */   daddu    $a0, $s0, $zero
/* 10230 80034E30 0C00AB1E */  jal       general_heap_free
/* 10234 80034E34 0200202D */   daddu    $a0, $s0, $zero
/* 10238 80034E38 0C016BE5 */  jal       initialize_collision
/* 1023C 80034E3C 00000000 */   nop
/* 10240 80034E40 0C016C16 */  jal       load_collision
/* 10244 80034E44 00000000 */   nop
/* 10248 80034E48 8E240008 */  lw        $a0, 8($s1)
/* 1024C 80034E4C 10800004 */  beqz      $a0, .L80034E60
/* 10250 80034E50 00000000 */   nop
/* 10254 80034E54 8E25000C */  lw        $a1, 0xc($s1)
/* 10258 80034E58 0C00A5CF */  jal       dma_copy
/* 1025C 80034E5C 8E260010 */   lw       $a2, 0x10($s1)
.L80034E60:
/* 10260 80034E60 0C05175C */  jal       load_map_bg
/* 10264 80034E64 8E240014 */   lw       $a0, 0x14($s1)
/* 10268 80034E68 8E440038 */  lw        $a0, 0x38($s2)
/* 1026C 80034E6C 50800005 */  beql      $a0, $zero, .L80034E84
/* 10270 80034E70 24040128 */   addiu    $a0, $zero, 0x128
/* 10274 80034E74 0C05178A */  jal       read_background_size
/* 10278 80034E78 00000000 */   nop
/* 1027C 80034E7C 0800D3A5 */  j         .L80034E94
/* 10280 80034E80 00000000 */   nop
.L80034E84:
/* 10284 80034E84 240500C8 */  addiu     $a1, $zero, 0xc8
/* 10288 80034E88 2406000C */  addiu     $a2, $zero, 0xc
/* 1028C 80034E8C 0C05179C */  jal       set_background_size
/* 10290 80034E90 24070014 */   addiu    $a3, $zero, 0x14
.L80034E94:
/* 10294 80034E94 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 10298 80034E98 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 1029C 80034E9C 9462015E */  lhu       $v0, 0x15e($v1)
/* 102A0 80034EA0 0C04584B */  jal       calculate_model_sizes
/* 102A4 80034EA4 A462015C */   sh       $v0, 0x15c($v1)
/* 102A8 80034EA8 0C00EC6C */  jal       func_8003B1B0
/* 102AC 80034EAC 00000000 */   nop
/* 102B0 80034EB0 0C051FB1 */  jal       func_80147EC4
/* 102B4 80034EB4 0000202D */   daddu    $a0, $zero, $zero
/* 102B8 80034EB8 0C03A631 */  jal       func_800E98C4
/* 102BC 80034EBC 00000000 */   nop
/* 102C0 80034EC0 0C009C22 */  jal       func_80027088
/* 102C4 80034EC4 24040001 */   addiu    $a0, $zero, 1
/* 102C8 80034EC8 24020003 */  addiu     $v0, $zero, 3
/* 102CC 80034ECC 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* 102D0 80034ED0 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* 102D4 80034ED4 3C01800A */  lui       $at, %hi(D_800A0921)
/* 102D8 80034ED8 A0220921 */  sb        $v0, %lo(D_800A0921)($at)
/* 102DC 80034EDC 9082000E */  lbu       $v0, 0xe($a0)
/* 102E0 80034EE0 3C03802E */  lui       $v1, %hi(D_802D9D70)
/* 102E4 80034EE4 90639D70 */  lbu       $v1, %lo(D_802D9D70)($v1)
/* 102E8 80034EE8 2442FFFF */  addiu     $v0, $v0, -1
/* 102EC 80034EEC 24630001 */  addiu     $v1, $v1, 1
/* 102F0 80034EF0 A082000F */  sb        $v0, 0xf($a0)
/* 102F4 80034EF4 3C01802E */  lui       $at, %hi(D_802D9D71)
/* 102F8 80034EF8 A0239D71 */  sb        $v1, %lo(D_802D9D71)($at)
/* 102FC 80034EFC 0C00F949 */  jal       func_8003E524
/* 10300 80034F00 00000000 */   nop
/* 10304 80034F04 0C00E64C */  jal       update_npcs
/* 10308 80034F08 00000000 */   nop
/* 1030C 80034F0C 0C037DD0 */  jal       update_player
/* 10310 80034F10 00000000 */   nop
/* 10314 80034F14 0C016754 */  jal       func_80059D50
/* 10318 80034F18 00000000 */   nop
/* 1031C 80034F1C 3C03800A */  lui       $v1, %hi(D_800A0922)
/* 10320 80034F20 24630922 */  addiu     $v1, $v1, %lo(D_800A0922)
/* 10324 80034F24 94620000 */  lhu       $v0, ($v1)
/* 10328 80034F28 2442FFEC */  addiu     $v0, $v0, -0x14
/* 1032C 80034F2C A4620000 */  sh        $v0, ($v1)
/* 10330 80034F30 00021400 */  sll       $v0, $v0, 0x10
/* 10334 80034F34 04420028 */  bltzl     $v0, .L80034FD8
/* 10338 80034F38 A4600000 */   sh       $zero, ($v1)
/* 1033C 80034F3C 0800D3F6 */  j         .L80034FD8
/* 10340 80034F40 00000000 */   nop
.L80034F44:
/* 10344 80034F44 0C00F949 */  jal       func_8003E524
/* 10348 80034F48 00000000 */   nop
/* 1034C 80034F4C 0C00E64C */  jal       update_npcs
/* 10350 80034F50 00000000 */   nop
/* 10354 80034F54 0C037DD0 */  jal       update_player
/* 10358 80034F58 00000000 */   nop
/* 1035C 80034F5C 0C016754 */  jal       func_80059D50
/* 10360 80034F60 00000000 */   nop
/* 10364 80034F64 3C04800A */  lui       $a0, %hi(D_800A0922)
/* 10368 80034F68 24840922 */  addiu     $a0, $a0, %lo(D_800A0922)
/* 1036C 80034F6C 84820000 */  lh        $v0, ($a0)
/* 10370 80034F70 94830000 */  lhu       $v1, ($a0)
/* 10374 80034F74 14400004 */  bnez      $v0, .L80034F88
/* 10378 80034F78 2462FFEC */   addiu    $v0, $v1, -0x14
/* 1037C 80034F7C 24020004 */  addiu     $v0, $zero, 4
/* 10380 80034F80 0800D3F6 */  j         .L80034FD8
/* 10384 80034F84 A2020000 */   sb       $v0, ($s0)
.L80034F88:
/* 10388 80034F88 A4820000 */  sh        $v0, ($a0)
/* 1038C 80034F8C 00021400 */  sll       $v0, $v0, 0x10
/* 10390 80034F90 04420011 */  bltzl     $v0, .L80034FD8
/* 10394 80034F94 A4800000 */   sh       $zero, ($a0)
/* 10398 80034F98 0800D3F6 */  j         .L80034FD8
/* 1039C 80034F9C 00000000 */   nop
.L80034FA0:
/* 103A0 80034FA0 0C009C22 */  jal       func_80027088
/* 103A4 80034FA4 0000202D */   daddu    $a0, $zero, $zero
/* 103A8 80034FA8 0C00F949 */  jal       func_8003E524
/* 103AC 80034FAC 00000000 */   nop
/* 103B0 80034FB0 0C00E64C */  jal       update_npcs
/* 103B4 80034FB4 00000000 */   nop
/* 103B8 80034FB8 0C037DD0 */  jal       update_player
/* 103BC 80034FBC 00000000 */   nop
/* 103C0 80034FC0 0C016754 */  jal       func_80059D50
/* 103C4 80034FC4 00000000 */   nop
/* 103C8 80034FC8 0C038069 */  jal       enable_player_input
/* 103CC 80034FCC 00000000 */   nop
/* 103D0 80034FD0 0C00CD3C */  jal       set_game_mode
/* 103D4 80034FD4 24040004 */   addiu    $a0, $zero, 4
.L80034FD8:
/* 103D8 80034FD8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 103DC 80034FDC 8FB20020 */  lw        $s2, 0x20($sp)
/* 103E0 80034FE0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 103E4 80034FE4 8FB00018 */  lw        $s0, 0x18($sp)
/* 103E8 80034FE8 03E00008 */  jr        $ra
/* 103EC 80034FEC 27BD0028 */   addiu    $sp, $sp, 0x28
