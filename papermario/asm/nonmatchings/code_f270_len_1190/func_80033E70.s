.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80033E70
/* 00F270 80033E70 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 00F274 80033E74 AFBF0024 */  sw    $ra, 0x24($sp)
/* 00F278 80033E78 AFB20020 */  sw    $s2, 0x20($sp)
/* 00F27C 80033E7C AFB1001C */  sw    $s1, 0x1c($sp)
/* 00F280 80033E80 AFB00018 */  sw    $s0, 0x18($sp)
/* 00F284 80033E84 0C00AB00 */  jal   general_heap_create
/* 00F288 80033E88 F7B40028 */   sdc1  $f20, 0x28($sp)
/* 00F28C 80033E8C 3C128007 */  lui   $s2, 0x8007
/* 00F290 80033E90 2652419C */  addiu $s2, $s2, 0x419c
/* 00F294 80033E94 8E420000 */  lw    $v0, ($s2)
/* 00F298 80033E98 A04000AC */  sb    $zero, 0xac($v0)
/* 00F29C 80033E9C 8E420000 */  lw    $v0, ($s2)
/* 00F2A0 80033EA0 A04000AD */  sb    $zero, 0xad($v0)
/* 00F2A4 80033EA4 8E420000 */  lw    $v0, ($s2)
/* 00F2A8 80033EA8 240400FF */  addiu $a0, $zero, 0xff
/* 00F2AC 80033EAC 0C00CDF4 */  jal   func_800337D0
/* 00F2B0 80033EB0 A04000AE */   sb    $zero, 0xae($v0)
/* 00F2B4 80033EB4 0C00CDF8 */  jal   func_800337E0
/* 00F2B8 80033EB8 0000202D */   daddu $a0, $zero, $zero
/* 00F2BC 80033EBC 3C110022 */  lui   $s1, 0x22
/* 00F2C0 80033EC0 263191B0 */  addiu $s1, $s1, -0x6e50
/* 00F2C4 80033EC4 3C100020 */  lui   $s0, 0x20
/* 00F2C8 80033EC8 2610E1B0 */  addiu $s0, $s0, -0x1e50
/* 00F2CC 80033ECC 0C00AB39 */  jal   heap_malloc
/* 00F2D0 80033ED0 02302023 */   subu  $a0, $s1, $s0
/* 00F2D4 80033ED4 0200202D */  daddu $a0, $s0, $zero
/* 00F2D8 80033ED8 0220282D */  daddu $a1, $s1, $zero
/* 00F2DC 80033EDC 0040302D */  daddu $a2, $v0, $zero
/* 00F2E0 80033EE0 3C10800A */  lui   $s0, 0x800a
/* 00F2E4 80033EE4 26100910 */  addiu $s0, $s0, 0x910
/* 00F2E8 80033EE8 0C00A5CF */  jal   dma_copy
/* 00F2EC 80033EEC AE060000 */   sw    $a2, ($s0)
/* 00F2F0 80033EF0 3C040001 */  lui   $a0, 1
/* 00F2F4 80033EF4 8E020000 */  lw    $v0, ($s0)
/* 00F2F8 80033EF8 34845000 */  ori   $a0, $a0, 0x5000
/* 00F2FC 80033EFC 24437000 */  addiu $v1, $v0, 0x7000
/* 00F300 80033F00 3C01800A */  lui   $at, 0x800a
/* 00F304 80033F04 AC220918 */  sw    $v0, 0x918($at)
/* 00F308 80033F08 00441021 */  addu  $v0, $v0, $a0
/* 00F30C 80033F0C 3C01800A */  lui   $at, 0x800a
/* 00F310 80033F10 AC230914 */  sw    $v1, 0x914($at)
/* 00F314 80033F14 3C01800A */  lui   $at, 0x800a
/* 00F318 80033F18 AC22091C */  sw    $v0, 0x91c($at)
/* 00F31C 80033F1C 0C018028 */  jal   nuContRmbForceStop
/* 00F320 80033F20 00000000 */   nop   
/* 00F324 80033F24 0C00B7BD */  jal   create_cameras_a
/* 00F328 80033F28 00000000 */   nop   
/* 00F32C 80033F2C 0000202D */  daddu $a0, $zero, $zero
/* 00F330 80033F30 2405000C */  addiu $a1, $zero, 0xc
/* 00F334 80033F34 2406001C */  addiu $a2, $zero, 0x1c
/* 00F338 80033F38 3C10800B */  lui   $s0, 0x800b
/* 00F33C 80033F3C 26101D80 */  addiu $s0, $s0, 0x1d80
/* 00F340 80033F40 24020006 */  addiu $v0, $zero, 6
/* 00F344 80033F44 A6020004 */  sh    $v0, 4($s0)
/* 00F348 80033F48 24020001 */  addiu $v0, $zero, 1
/* 00F34C 80033F4C A6020006 */  sh    $v0, 6($s0)
/* 00F350 80033F50 24020010 */  addiu $v0, $zero, 0x10
/* 00F354 80033F54 A6020012 */  sh    $v0, 0x12($s0)
/* 00F358 80033F58 24021000 */  addiu $v0, $zero, 0x1000
/* 00F35C 80033F5C A6020014 */  sh    $v0, 0x14($s0)
/* 00F360 80033F60 240200B8 */  addiu $v0, $zero, 0xb8
/* 00F364 80033F64 3C0141C8 */  lui   $at, 0x41c8
/* 00F368 80033F68 4481A000 */  mtc1  $at, $f20
/* 00F36C 80033F6C 24070128 */  addiu $a3, $zero, 0x128
/* 00F370 80033F70 3C018007 */  lui   $at, 0x8007
/* 00F374 80033F74 AC207410 */  sw    $zero, 0x7410($at)
/* 00F378 80033F78 E6140018 */  swc1  $f20, 0x18($s0)
/* 00F37C 80033F7C AFA20010 */  sw    $v0, 0x10($sp)
/* 00F380 80033F80 96020000 */  lhu   $v0, ($s0)
/* 00F384 80033F84 96030558 */  lhu   $v1, 0x558($s0)
/* 00F388 80033F88 34420002 */  ori   $v0, $v0, 2
/* 00F38C 80033F8C A6020000 */  sh    $v0, ($s0)
/* 00F390 80033F90 96020AB0 */  lhu   $v0, 0xab0($s0)
/* 00F394 80033F94 34630002 */  ori   $v1, $v1, 2
/* 00F398 80033F98 A6030558 */  sh    $v1, 0x558($s0)
/* 00F39C 80033F9C 96031008 */  lhu   $v1, 0x1008($s0)
/* 00F3A0 80033FA0 34420002 */  ori   $v0, $v0, 2
/* 00F3A4 80033FA4 34630002 */  ori   $v1, $v1, 2
/* 00F3A8 80033FA8 A6020AB0 */  sh    $v0, 0xab0($s0)
/* 00F3AC 80033FAC 0C00B8C5 */  jal   set_cam_viewport
/* 00F3B0 80033FB0 A6031008 */   sh    $v1, 0x1008($s0)
/* 00F3B4 80033FB4 3C0143FA */  lui   $at, 0x43fa
/* 00F3B8 80033FB8 44810000 */  mtc1  $at, $f0
/* 00F3BC 80033FBC 3C01447A */  lui   $at, 0x447a
/* 00F3C0 80033FC0 44811000 */  mtc1  $at, $f2
/* 00F3C4 80033FC4 3C0144BB */  lui   $at, 0x44bb
/* 00F3C8 80033FC8 34218000 */  ori   $at, $at, 0x8000
/* 00F3CC 80033FCC 44812000 */  mtc1  $at, $f4
/* 00F3D0 80033FD0 3C014316 */  lui   $at, 0x4316
/* 00F3D4 80033FD4 44813000 */  mtc1  $at, $f6
/* 00F3D8 80033FD8 24020028 */  addiu $v0, $zero, 0x28
/* 00F3DC 80033FDC A602001E */  sh    $v0, 0x1e($s0)
/* 00F3E0 80033FE0 24020064 */  addiu $v0, $zero, 0x64
/* 00F3E4 80033FE4 A600002C */  sh    $zero, 0x2c($s0)
/* 00F3E8 80033FE8 A600002E */  sh    $zero, 0x2e($s0)
/* 00F3EC 80033FEC A6000030 */  sh    $zero, 0x30($s0)
/* 00F3F0 80033FF0 E6140054 */  swc1  $f20, 0x54($s0)
/* 00F3F4 80033FF4 E6140058 */  swc1  $f20, 0x58($s0)
/* 00F3F8 80033FF8 A600001C */  sh    $zero, 0x1c($s0)
/* 00F3FC 80033FFC A6020020 */  sh    $v0, 0x20($s0)
/* 00F400 80034000 A6000022 */  sh    $zero, 0x22($s0)
/* 00F404 80034004 E600003C */  swc1  $f0, 0x3c($s0)
/* 00F408 80034008 E6020040 */  swc1  $f2, 0x40($s0)
/* 00F40C 8003400C E6040044 */  swc1  $f4, 0x44($s0)
/* 00F410 80034010 0C0B0C77 */  jal   clear_script_list
/* 00F414 80034014 E606005C */   swc1  $f6, 0x5c($s0)
/* 00F418 80034018 0C048C2E */  jal   func_801230B8
/* 00F41C 8003401C 00000000 */   nop   
/* 00F420 80034020 0C047624 */  jal   func_8011D890
/* 00F424 80034024 00000000 */   nop   
/* 00F428 80034028 0C0B763E */  jal   func_802DD8F8
/* 00F42C 8003402C 0000202D */   daddu $a0, $zero, $zero
/* 00F430 80034030 0C047889 */  jal   func_8011E224
/* 00F434 80034034 00000000 */   nop   
/* 00F438 80034038 0C0482EC */  jal   func_80120BB0
/* 00F43C 8003403C 00000000 */   nop   
/* 00F440 80034040 0C00E12F */  jal   func_800384BC
/* 00F444 80034044 00000000 */   nop   
/* 00F448 80034048 0C050440 */  jal   func_80141100
/* 00F44C 8003404C 00000000 */   nop   
/* 00F450 80034050 0C05177E */  jal   func_80145DF8
/* 00F454 80034054 00000000 */   nop   
/* 00F458 80034058 0C04432E */  jal   func_80110CB8
/* 00F45C 8003405C 24040001 */   addiu $a0, $zero, 1
/* 00F460 80034060 0C016727 */  jal   func_80059C9C
/* 00F464 80034064 00000000 */   nop   
/* 00F468 80034068 3C03800A */  lui   $v1, 0x800a
/* 00F46C 8003406C 2463A650 */  addiu $v1, $v1, -0x59b0
/* 00F470 80034070 8C620000 */  lw    $v0, ($v1)
/* 00F474 80034074 34420002 */  ori   $v0, $v0, 2
/* 00F478 80034078 0C00CE1D */  jal   func_80033874
/* 00F47C 8003407C AC620000 */   sw    $v0, ($v1)
/* 00F480 80034080 8E420000 */  lw    $v0, ($s2)
/* 00F484 80034084 A4400148 */  sh    $zero, 0x148($v0)
/* 00F488 80034088 8FBF0024 */  lw    $ra, 0x24($sp)
/* 00F48C 8003408C 8FB20020 */  lw    $s2, 0x20($sp)
/* 00F490 80034090 8FB1001C */  lw    $s1, 0x1c($sp)
/* 00F494 80034094 8FB00018 */  lw    $s0, 0x18($sp)
/* 00F498 80034098 D7B40028 */  ldc1  $f20, 0x28($sp)
/* 00F49C 8003409C 03E00008 */  jr    $ra
/* 00F4A0 800340A0 27BD0030 */   addiu $sp, $sp, 0x30

