.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel begin_state_logos
/* F270 80033E70 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F274 80033E74 AFBF0024 */  sw        $ra, 0x24($sp)
/* F278 80033E78 AFB20020 */  sw        $s2, 0x20($sp)
/* F27C 80033E7C AFB1001C */  sw        $s1, 0x1c($sp)
/* F280 80033E80 AFB00018 */  sw        $s0, 0x18($sp)
/* F284 80033E84 0C00AB00 */  jal       general_heap_create
/* F288 80033E88 F7B40028 */   sdc1     $f20, 0x28($sp)
/* F28C 80033E8C 3C128007 */  lui       $s2, %hi(gGameStatusPtr)
/* F290 80033E90 2652419C */  addiu     $s2, $s2, %lo(gGameStatusPtr)
/* F294 80033E94 8E420000 */  lw        $v0, ($s2)
/* F298 80033E98 A04000AC */  sb        $zero, 0xac($v0)
/* F29C 80033E9C 8E420000 */  lw        $v0, ($s2)
/* F2A0 80033EA0 A04000AD */  sb        $zero, 0xad($v0)
/* F2A4 80033EA4 8E420000 */  lw        $v0, ($s2)
/* F2A8 80033EA8 240400FF */  addiu     $a0, $zero, 0xff
/* F2AC 80033EAC 0C00CDF4 */  jal       intro_logos_set_fade_alpha
/* F2B0 80033EB0 A04000AE */   sb       $zero, 0xae($v0)
/* F2B4 80033EB4 0C00CDF8 */  jal       intro_logos_set_fade_color
/* F2B8 80033EB8 0000202D */   daddu    $a0, $zero, $zero
/* F2BC 80033EBC 3C110022 */  lui       $s1, 0x22
/* F2C0 80033EC0 263191B0 */  addiu     $s1, $s1, -0x6e50
/* F2C4 80033EC4 3C100020 */  lui       $s0, 0x20
/* F2C8 80033EC8 2610E1B0 */  addiu     $s0, $s0, -0x1e50
/* F2CC 80033ECC 0C00AB39 */  jal       heap_malloc
/* F2D0 80033ED0 02302023 */   subu     $a0, $s1, $s0
/* F2D4 80033ED4 0200202D */  daddu     $a0, $s0, $zero
/* F2D8 80033ED8 0220282D */  daddu     $a1, $s1, $zero
/* F2DC 80033EDC 0040302D */  daddu     $a2, $v0, $zero
/* F2E0 80033EE0 3C10800A */  lui       $s0, 0x800a
/* F2E4 80033EE4 26100910 */  addiu     $s0, $s0, 0x910
/* F2E8 80033EE8 0C00A5CF */  jal       dma_copy
/* F2EC 80033EEC AE060000 */   sw       $a2, ($s0)
/* F2F0 80033EF0 3C040001 */  lui       $a0, 1
/* F2F4 80033EF4 8E020000 */  lw        $v0, ($s0)
/* F2F8 80033EF8 34845000 */  ori       $a0, $a0, 0x5000
/* F2FC 80033EFC 24437000 */  addiu     $v1, $v0, 0x7000
/* F300 80033F00 3C01800A */  lui       $at, 0x800a
/* F304 80033F04 AC220918 */  sw        $v0, 0x918($at)
/* F308 80033F08 00441021 */  addu      $v0, $v0, $a0
/* F30C 80033F0C 3C01800A */  lui       $at, 0x800a
/* F310 80033F10 AC230914 */  sw        $v1, 0x914($at)
/* F314 80033F14 3C01800A */  lui       $at, 0x800a
/* F318 80033F18 AC22091C */  sw        $v0, 0x91c($at)
/* F31C 80033F1C 0C018028 */  jal       nuContRmbForceStop
/* F320 80033F20 00000000 */   nop      
/* F324 80033F24 0C00B7BD */  jal       create_cameras_a
/* F328 80033F28 00000000 */   nop      
/* F32C 80033F2C 0000202D */  daddu     $a0, $zero, $zero
/* F330 80033F30 2405000C */  addiu     $a1, $zero, 0xc
/* F334 80033F34 2406001C */  addiu     $a2, $zero, 0x1c
/* F338 80033F38 3C10800B */  lui       $s0, %hi(gCameras)
/* F33C 80033F3C 26101D80 */  addiu     $s0, $s0, %lo(gCameras)
/* F340 80033F40 24020006 */  addiu     $v0, $zero, 6
/* F344 80033F44 A6020004 */  sh        $v0, 4($s0)
/* F348 80033F48 24020001 */  addiu     $v0, $zero, 1
/* F34C 80033F4C A6020006 */  sh        $v0, 6($s0)
/* F350 80033F50 24020010 */  addiu     $v0, $zero, 0x10
/* F354 80033F54 A6020012 */  sh        $v0, 0x12($s0)
/* F358 80033F58 24021000 */  addiu     $v0, $zero, 0x1000
/* F35C 80033F5C A6020014 */  sh        $v0, 0x14($s0)
/* F360 80033F60 240200B8 */  addiu     $v0, $zero, 0xb8
/* F364 80033F64 3C0141C8 */  lui       $at, 0x41c8
/* F368 80033F68 4481A000 */  mtc1      $at, $f20
/* F36C 80033F6C 24070128 */  addiu     $a3, $zero, 0x128
/* F370 80033F70 3C018007 */  lui       $at, %hi(gCurrentCameraID)
/* F374 80033F74 AC207410 */  sw        $zero, %lo(gCurrentCameraID)($at)
/* F378 80033F78 E6140018 */  swc1      $f20, 0x18($s0)
/* F37C 80033F7C AFA20010 */  sw        $v0, 0x10($sp)
/* F380 80033F80 96020000 */  lhu       $v0, ($s0)
/* F384 80033F84 96030558 */  lhu       $v1, 0x558($s0)
/* F388 80033F88 34420002 */  ori       $v0, $v0, 2
/* F38C 80033F8C A6020000 */  sh        $v0, ($s0)
/* F390 80033F90 96020AB0 */  lhu       $v0, 0xab0($s0)
/* F394 80033F94 34630002 */  ori       $v1, $v1, 2
/* F398 80033F98 A6030558 */  sh        $v1, 0x558($s0)
/* F39C 80033F9C 96031008 */  lhu       $v1, 0x1008($s0)
/* F3A0 80033FA0 34420002 */  ori       $v0, $v0, 2
/* F3A4 80033FA4 34630002 */  ori       $v1, $v1, 2
/* F3A8 80033FA8 A6020AB0 */  sh        $v0, 0xab0($s0)
/* F3AC 80033FAC 0C00B8C5 */  jal       set_cam_viewport
/* F3B0 80033FB0 A6031008 */   sh       $v1, 0x1008($s0)
/* F3B4 80033FB4 3C0143FA */  lui       $at, 0x43fa
/* F3B8 80033FB8 44810000 */  mtc1      $at, $f0
/* F3BC 80033FBC 3C01447A */  lui       $at, 0x447a
/* F3C0 80033FC0 44811000 */  mtc1      $at, $f2
/* F3C4 80033FC4 3C0144BB */  lui       $at, 0x44bb
/* F3C8 80033FC8 34218000 */  ori       $at, $at, 0x8000
/* F3CC 80033FCC 44812000 */  mtc1      $at, $f4
/* F3D0 80033FD0 3C014316 */  lui       $at, 0x4316
/* F3D4 80033FD4 44813000 */  mtc1      $at, $f6
/* F3D8 80033FD8 24020028 */  addiu     $v0, $zero, 0x28
/* F3DC 80033FDC A602001E */  sh        $v0, 0x1e($s0)
/* F3E0 80033FE0 24020064 */  addiu     $v0, $zero, 0x64
/* F3E4 80033FE4 A600002C */  sh        $zero, 0x2c($s0)
/* F3E8 80033FE8 A600002E */  sh        $zero, 0x2e($s0)
/* F3EC 80033FEC A6000030 */  sh        $zero, 0x30($s0)
/* F3F0 80033FF0 E6140054 */  swc1      $f20, 0x54($s0)
/* F3F4 80033FF4 E6140058 */  swc1      $f20, 0x58($s0)
/* F3F8 80033FF8 A600001C */  sh        $zero, 0x1c($s0)
/* F3FC 80033FFC A6020020 */  sh        $v0, 0x20($s0)
/* F400 80034000 A6000022 */  sh        $zero, 0x22($s0)
/* F404 80034004 E600003C */  swc1      $f0, 0x3c($s0)
/* F408 80034008 E6020040 */  swc1      $f2, 0x40($s0)
/* F40C 8003400C E6040044 */  swc1      $f4, 0x44($s0)
/* F410 80034010 0C0B0C77 */  jal       clear_script_list
/* F414 80034014 E606005C */   swc1     $f6, 0x5c($s0)
/* F418 80034018 0C048C2E */  jal       clear_dynamic_entity_list
/* F41C 8003401C 00000000 */   nop      
/* F420 80034020 0C047624 */  jal       func_8011D890
/* F424 80034024 00000000 */   nop      
/* F428 80034028 0C0B763E */  jal       func_802DD8F8
/* F42C 8003402C 0000202D */   daddu    $a0, $zero, $zero
/* F430 80034030 0C047889 */  jal       func_8011E224
/* F434 80034034 00000000 */   nop      
/* F438 80034038 0C0482EC */  jal       clear_virtual_models
/* F43C 8003403C 00000000 */   nop      
/* F440 80034040 0C00E12F */  jal       clear_npcs
/* F444 80034044 00000000 */   nop      
/* F448 80034048 0C050440 */  jal       func_80141100
/* F44C 8003404C 00000000 */   nop      
/* F450 80034050 0C05177E */  jal       func_80145DF8
/* F454 80034054 00000000 */   nop      
/* F458 80034058 0C04432E */  jal       clear_entity_data
/* F45C 8003405C 24040001 */   addiu    $a0, $zero, 1
/* F460 80034060 0C016727 */  jal       func_80059C9C
/* F464 80034064 00000000 */   nop      
/* F468 80034068 3C03800A */  lui       $v1, %hi(D_8009A650)
/* F46C 8003406C 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* F470 80034070 8C620000 */  lw        $v0, ($v1)
/* F474 80034074 34420002 */  ori       $v0, $v0, 2
/* F478 80034078 0C00CE1D */  jal       intro_logos_update_fade
/* F47C 8003407C AC620000 */   sw       $v0, ($v1)
/* F480 80034080 8E420000 */  lw        $v0, ($s2)
/* F484 80034084 A4400148 */  sh        $zero, 0x148($v0)
/* F488 80034088 8FBF0024 */  lw        $ra, 0x24($sp)
/* F48C 8003408C 8FB20020 */  lw        $s2, 0x20($sp)
/* F490 80034090 8FB1001C */  lw        $s1, 0x1c($sp)
/* F494 80034094 8FB00018 */  lw        $s0, 0x18($sp)
/* F498 80034098 D7B40028 */  ldc1      $f20, 0x28($sp)
/* F49C 8003409C 03E00008 */  jr        $ra
/* F4A0 800340A0 27BD0030 */   addiu    $sp, $sp, 0x30
