.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80098390
.ascii "title_data\0\0"

glabel D_8009839C
.word 0x7469746C, 0x655F6267, 0x00000000

.section .text

glabel begin_state_title_screen
/* 121F0 80036DF0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 121F4 80036DF4 AFB20028 */  sw        $s2, 0x28($sp)
/* 121F8 80036DF8 3C12800A */  lui       $s2, %hi(gOverrideFlags)
/* 121FC 80036DFC 2652A650 */  addiu     $s2, $s2, %lo(gOverrideFlags)
/* 12200 80036E00 24020001 */  addiu     $v0, $zero, 1
/* 12204 80036E04 AFBF002C */  sw        $ra, 0x2c($sp)
/* 12208 80036E08 AFB10024 */  sw        $s1, 0x24($sp)
/* 1220C 80036E0C AFB00020 */  sw        $s0, 0x20($sp)
/* 12210 80036E10 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 12214 80036E14 AE400000 */  sw        $zero, ($s2)
/* 12218 80036E18 3C01800A */  lui       $at, %hi(D_8009A5D8)
/* 1221C 80036E1C AC20A5D8 */  sw        $zero, %lo(D_8009A5D8)($at)
/* 12220 80036E20 3C018015 */  lui       $at, %hi(D_8014C248)
/* 12224 80036E24 A022C248 */  sb        $v0, %lo(D_8014C248)($at)
/* 12228 80036E28 0C00AB00 */  jal       general_heap_create
/* 1222C 80036E2C 00000000 */   nop
/* 12230 80036E30 0C048D9D */  jal       clear_printers
/* 12234 80036E34 00000000 */   nop
/* 12238 80036E38 0C0525FF */  jal       func_801497FC
/* 1223C 80036E3C 0000202D */   daddu    $a0, $zero, $zero
/* 12240 80036E40 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 12244 80036E44 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 12248 80036E48 8C620000 */  lw        $v0, ($v1)
/* 1224C 80036E4C A04000AC */  sb        $zero, 0xac($v0)
/* 12250 80036E50 8C620000 */  lw        $v0, ($v1)
/* 12254 80036E54 A04000AD */  sb        $zero, 0xad($v0)
/* 12258 80036E58 8C620000 */  lw        $v0, ($v1)
/* 1225C 80036E5C A0400070 */  sb        $zero, 0x70($v0)
/* 12260 80036E60 8C630000 */  lw        $v1, ($v1)
/* 12264 80036E64 2402FFFF */  addiu     $v0, $zero, -1
/* 12268 80036E68 0C00CE1D */  jal       intro_logos_update_fade
/* 1226C 80036E6C A06200A8 */   sb       $v0, 0xa8($v1)
/* 12270 80036E70 3C04800A */  lui       $a0, %hi(D_80098390)
/* 12274 80036E74 24848390 */  addiu     $a0, $a0, %lo(D_80098390)
/* 12278 80036E78 0C016B3A */  jal       load_asset_by_name
/* 1227C 80036E7C 27A50018 */   addiu    $a1, $sp, 0x18
/* 12280 80036E80 8FA40018 */  lw        $a0, 0x18($sp)
/* 12284 80036E84 0C00AB39 */  jal       heap_malloc
/* 12288 80036E88 0040882D */   daddu    $s1, $v0, $zero
/* 1228C 80036E8C 0220202D */  daddu     $a0, $s1, $zero
/* 12290 80036E90 0040282D */  daddu     $a1, $v0, $zero
/* 12294 80036E94 3C10800A */  lui       $s0, %hi(D_800A0974)
/* 12298 80036E98 26100974 */  addiu     $s0, $s0, %lo(D_800A0974)
/* 1229C 80036E9C 0C01BB7C */  jal       decode_yay0
/* 122A0 80036EA0 AE050000 */   sw       $a1, ($s0)
/* 122A4 80036EA4 0C00AB1E */  jal       general_heap_free
/* 122A8 80036EA8 0220202D */   daddu    $a0, $s1, $zero
/* 122AC 80036EAC 8E040000 */  lw        $a0, ($s0)
/* 122B0 80036EB0 8C820000 */  lw        $v0, ($a0)
/* 122B4 80036EB4 8C830008 */  lw        $v1, 8($a0)
/* 122B8 80036EB8 00441021 */  addu      $v0, $v0, $a0
/* 122BC 80036EBC 3C01800A */  lui       $at, %hi(D_800A0978)
/* 122C0 80036EC0 AC220978 */  sw        $v0, %lo(D_800A0978)($at)
/* 122C4 80036EC4 8C820004 */  lw        $v0, 4($a0)
/* 122C8 80036EC8 00641821 */  addu      $v1, $v1, $a0
/* 122CC 80036ECC 3C01800A */  lui       $at, %hi(D_800A0980)
/* 122D0 80036ED0 AC230980 */  sw        $v1, %lo(D_800A0980)($at)
/* 122D4 80036ED4 00441021 */  addu      $v0, $v0, $a0
/* 122D8 80036ED8 3C01800A */  lui       $at, %hi(D_800A097C)
/* 122DC 80036EDC AC22097C */  sw        $v0, %lo(D_800A097C)($at)
/* 122E0 80036EE0 0C00B7BD */  jal       create_cameras_a
/* 122E4 80036EE4 00000000 */   nop
/* 122E8 80036EE8 0000202D */  daddu     $a0, $zero, $zero
/* 122EC 80036EEC 2405000C */  addiu     $a1, $zero, 0xc
/* 122F0 80036EF0 2406001C */  addiu     $a2, $zero, 0x1c
/* 122F4 80036EF4 24070128 */  addiu     $a3, $zero, 0x128
/* 122F8 80036EF8 3C10800B */  lui       $s0, %hi(gCameras)
/* 122FC 80036EFC 26101D80 */  addiu     $s0, $s0, %lo(gCameras)
/* 12300 80036F00 3C0141C8 */  lui       $at, 0x41c8
/* 12304 80036F04 4481A000 */  mtc1      $at, $f20
/* 12308 80036F08 24020006 */  addiu     $v0, $zero, 6
/* 1230C 80036F0C A6020004 */  sh        $v0, 4($s0)
/* 12310 80036F10 24020001 */  addiu     $v0, $zero, 1
/* 12314 80036F14 A6020006 */  sh        $v0, 6($s0)
/* 12318 80036F18 24020010 */  addiu     $v0, $zero, 0x10
/* 1231C 80036F1C A6020012 */  sh        $v0, 0x12($s0)
/* 12320 80036F20 24021000 */  addiu     $v0, $zero, 0x1000
/* 12324 80036F24 A6020014 */  sh        $v0, 0x14($s0)
/* 12328 80036F28 240200B8 */  addiu     $v0, $zero, 0xb8
/* 1232C 80036F2C 3C018007 */  lui       $at, %hi(gCurrentCameraID)
/* 12330 80036F30 AC207410 */  sw        $zero, %lo(gCurrentCameraID)($at)
/* 12334 80036F34 E6140018 */  swc1      $f20, 0x18($s0)
/* 12338 80036F38 AFA20010 */  sw        $v0, 0x10($sp)
/* 1233C 80036F3C 96020000 */  lhu       $v0, ($s0)
/* 12340 80036F40 96030558 */  lhu       $v1, 0x558($s0)
/* 12344 80036F44 34420002 */  ori       $v0, $v0, 2
/* 12348 80036F48 A6020000 */  sh        $v0, ($s0)
/* 1234C 80036F4C 96020AB0 */  lhu       $v0, 0xab0($s0)
/* 12350 80036F50 34630002 */  ori       $v1, $v1, 2
/* 12354 80036F54 A6030558 */  sh        $v1, 0x558($s0)
/* 12358 80036F58 96031008 */  lhu       $v1, 0x1008($s0)
/* 1235C 80036F5C 34420002 */  ori       $v0, $v0, 2
/* 12360 80036F60 34630002 */  ori       $v1, $v1, 2
/* 12364 80036F64 A6020AB0 */  sh        $v0, 0xab0($s0)
/* 12368 80036F68 0C00B8C5 */  jal       set_cam_viewport
/* 1236C 80036F6C A6031008 */   sh       $v1, 0x1008($s0)
/* 12370 80036F70 3C0143FA */  lui       $at, 0x43fa
/* 12374 80036F74 44810000 */  mtc1      $at, $f0
/* 12378 80036F78 3C01447A */  lui       $at, 0x447a
/* 1237C 80036F7C 44811000 */  mtc1      $at, $f2
/* 12380 80036F80 3C0144BB */  lui       $at, 0x44bb
/* 12384 80036F84 34218000 */  ori       $at, $at, 0x8000
/* 12388 80036F88 44812000 */  mtc1      $at, $f4
/* 1238C 80036F8C 3C014316 */  lui       $at, 0x4316
/* 12390 80036F90 44813000 */  mtc1      $at, $f6
/* 12394 80036F94 24020028 */  addiu     $v0, $zero, 0x28
/* 12398 80036F98 A602001E */  sh        $v0, 0x1e($s0)
/* 1239C 80036F9C 24020064 */  addiu     $v0, $zero, 0x64
/* 123A0 80036FA0 A600002C */  sh        $zero, 0x2c($s0)
/* 123A4 80036FA4 A600002E */  sh        $zero, 0x2e($s0)
/* 123A8 80036FA8 A6000030 */  sh        $zero, 0x30($s0)
/* 123AC 80036FAC E6140054 */  swc1      $f20, 0x54($s0)
/* 123B0 80036FB0 E6140058 */  swc1      $f20, 0x58($s0)
/* 123B4 80036FB4 A600001C */  sh        $zero, 0x1c($s0)
/* 123B8 80036FB8 A6020020 */  sh        $v0, 0x20($s0)
/* 123BC 80036FBC A6000022 */  sh        $zero, 0x22($s0)
/* 123C0 80036FC0 E600003C */  swc1      $f0, 0x3c($s0)
/* 123C4 80036FC4 E6020040 */  swc1      $f2, 0x40($s0)
/* 123C8 80036FC8 E6040044 */  swc1      $f4, 0x44($s0)
/* 123CC 80036FCC 0C0B0C77 */  jal       clear_script_list
/* 123D0 80036FD0 E606005C */   swc1     $f6, 0x5c($s0)
/* 123D4 80036FD4 0C048C2E */  jal       clear_dynamic_entity_list
/* 123D8 80036FD8 00000000 */   nop
/* 123DC 80036FDC 0C047624 */  jal       func_8011D890
/* 123E0 80036FE0 00000000 */   nop
/* 123E4 80036FE4 0C0B763E */  jal       func_802DD8F8
/* 123E8 80036FE8 0000202D */   daddu    $a0, $zero, $zero
/* 123EC 80036FEC 0C047889 */  jal       func_8011E224
/* 123F0 80036FF0 00000000 */   nop
/* 123F4 80036FF4 0C0482EC */  jal       clear_entity_models
/* 123F8 80036FF8 00000000 */   nop
/* 123FC 80036FFC 0C00E12F */  jal       npc_list_clear
/* 12400 80037000 00000000 */   nop
/* 12404 80037004 0C050440 */  jal       func_80141100
/* 12408 80037008 00000000 */   nop
/* 1240C 8003700C 0C05177E */  jal       use_default_background_settings
/* 12410 80037010 00000000 */   nop
/* 12414 80037014 0C04432E */  jal       clear_entity_data
/* 12418 80037018 24040001 */   addiu    $a0, $zero, 1
/* 1241C 8003701C 0C016727 */  jal       clear_effect_data
/* 12420 80037020 00000000 */   nop
/* 12424 80037024 8E420000 */  lw        $v0, ($s2)
/* 12428 80037028 34420002 */  ori       $v0, $v0, 2
/* 1242C 8003702C 0C039CE8 */  jal       clear_player_data
/* 12430 80037030 AE420000 */   sw       $v0, ($s2)
/* 12434 80037034 0000202D */  daddu     $a0, $zero, $zero
/* 12438 80037038 3C058003 */  lui       $a1, %hi(title_append_gfx)
/* 1243C 8003703C 24A57638 */  addiu     $a1, $a1, %lo(title_append_gfx)
/* 12440 80037040 8E420000 */  lw        $v0, ($s2)
/* 12444 80037044 2403FFF7 */  addiu     $v1, $zero, -9
/* 12448 80037048 00431024 */  and       $v0, $v0, $v1
/* 1244C 8003704C 0C044B61 */  jal       func_80112D84
/* 12450 80037050 AE420000 */   sw       $v0, ($s2)
/* 12454 80037054 3C04800A */  lui       $a0, %hi(D_8009839C)
/* 12458 80037058 0C05175C */  jal       load_map_bg
/* 1245C 8003705C 2484839C */   addiu    $a0, $a0, %lo(D_8009839C)
/* 12460 80037060 3C048020 */  lui       $a0, %hi(func_80200000)
/* 12464 80037064 24840000 */  addiu     $a0, $a0, %lo(func_80200000)
/* 12468 80037068 0C05178A */  jal       read_background_size
/* 1246C 8003706C 00000000 */   nop
/* 12470 80037070 0000202D */  daddu     $a0, $zero, $zero
/* 12474 80037074 2405006A */  addiu     $a1, $zero, 0x6a
/* 12478 80037078 0080302D */  daddu     $a2, $a0, $zero
/* 1247C 8003707C 240701F4 */  addiu     $a3, $zero, 0x1f4
/* 12480 80037080 24020008 */  addiu     $v0, $zero, 8
/* 12484 80037084 0C052A46 */  jal       bgm_set_song
/* 12488 80037088 AFA20010 */   sw       $v0, 0x10($sp)
/* 1248C 8003708C 8FBF002C */  lw        $ra, 0x2c($sp)
/* 12490 80037090 8FB20028 */  lw        $s2, 0x28($sp)
/* 12494 80037094 8FB10024 */  lw        $s1, 0x24($sp)
/* 12498 80037098 8FB00020 */  lw        $s0, 0x20($sp)
/* 1249C 8003709C D7B40030 */  ldc1      $f20, 0x30($sp)
/* 124A0 800370A0 240201E0 */  addiu     $v0, $zero, 0x1e0
/* 124A4 800370A4 3C01800A */  lui       $at, %hi(D_800A0988)
/* 124A8 800370A8 A4220988 */  sh        $v0, %lo(D_800A0988)($at)
/* 124AC 800370AC 03E00008 */  jr        $ra
/* 124B0 800370B0 27BD0038 */   addiu    $sp, $sp, 0x38
