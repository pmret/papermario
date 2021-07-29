.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel state_step_enter_world
/* 112EC 80035EEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 112F0 80035EF0 AFB00010 */  sw        $s0, 0x10($sp)
/* 112F4 80035EF4 3C10800A */  lui       $s0, %hi(D_800A0944)
/* 112F8 80035EF8 26100944 */  addiu     $s0, $s0, %lo(D_800A0944)
/* 112FC 80035EFC AFBF0014 */  sw        $ra, 0x14($sp)
/* 11300 80035F00 86030000 */  lh        $v1, ($s0)
/* 11304 80035F04 24020001 */  addiu     $v0, $zero, 1
/* 11308 80035F08 1062003D */  beq       $v1, $v0, .L80036000
/* 1130C 80035F0C 28620002 */   slti     $v0, $v1, 2
/* 11310 80035F10 50400005 */  beql      $v0, $zero, .L80035F28
/* 11314 80035F14 24020002 */   addiu    $v0, $zero, 2
/* 11318 80035F18 10600007 */  beqz      $v1, .L80035F38
/* 1131C 80035F1C 00000000 */   nop
/* 11320 80035F20 0800D83B */  j         .L800360EC
/* 11324 80035F24 00000000 */   nop
.L80035F28:
/* 11328 80035F28 10620055 */  beq       $v1, $v0, .L80036080
/* 1132C 80035F2C 00000000 */   nop
/* 11330 80035F30 0800D83B */  j         .L800360EC
/* 11334 80035F34 00000000 */   nop
.L80035F38:
/* 11338 80035F38 3C04800A */  lui       $a0, %hi(D_800A0946)
/* 1133C 80035F3C 24840946 */  addiu     $a0, $a0, %lo(D_800A0946)
/* 11340 80035F40 84820000 */  lh        $v0, ($a0)
/* 11344 80035F44 94830000 */  lhu       $v1, ($a0)
/* 11348 80035F48 1440003B */  bnez      $v0, .L80036038
/* 1134C 80035F4C 2462FFFF */   addiu    $v0, $v1, -1
/* 11350 80035F50 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 11354 80035F54 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 11358 80035F58 8C620000 */  lw        $v0, ($v1)
/* 1135C 80035F5C A0400070 */  sb        $zero, 0x70($v0)
/* 11360 80035F60 8C620000 */  lw        $v0, ($v1)
/* 11364 80035F64 A0400078 */  sb        $zero, 0x78($v0)
/* 11368 80035F68 3C02800A */  lui       $v0, %hi(D_800A0948)
/* 1136C 80035F6C 84420948 */  lh        $v0, %lo(D_800A0948)($v0)
/* 11370 80035F70 14400006 */  bnez      $v0, .L80035F8C
/* 11374 80035F74 24060001 */   addiu    $a2, $zero, 1
/* 11378 80035F78 8C620000 */  lw        $v0, ($v1)
/* 1137C 80035F7C 84440086 */  lh        $a0, 0x86($v0)
/* 11380 80035F80 8445008C */  lh        $a1, 0x8c($v0)
/* 11384 80035F84 0800D7E6 */  j         .L80035F98
/* 11388 80035F88 0000302D */   daddu    $a2, $zero, $zero
.L80035F8C:
/* 1138C 80035F8C 8C620000 */  lw        $v0, ($v1)
/* 11390 80035F90 84440086 */  lh        $a0, 0x86($v0)
/* 11394 80035F94 8445008C */  lh        $a1, 0x8c($v0)
.L80035F98:
/* 11398 80035F98 0C0169BD */  jal       load_map_by_IDs
/* 1139C 80035F9C 00000000 */   nop
/* 113A0 80035FA0 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 113A4 80035FA4 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 113A8 80035FA8 8E020000 */  lw        $v0, ($s0)
/* 113AC 80035FAC 94430086 */  lhu       $v1, 0x86($v0)
/* 113B0 80035FB0 0000202D */  daddu     $a0, $zero, $zero
/* 113B4 80035FB4 0C009C22 */  jal       set_time_freeze_mode
/* 113B8 80035FB8 A4430088 */   sh       $v1, 0x88($v0)
/* 113BC 80035FBC 8E020000 */  lw        $v0, ($s0)
/* 113C0 80035FC0 80420071 */  lb        $v0, 0x71($v0)
/* 113C4 80035FC4 14400003 */  bnez      $v0, .L80035FD4
/* 113C8 80035FC8 00000000 */   nop
/* 113CC 80035FCC 0C03805E */  jal       disable_player_input
/* 113D0 80035FD0 00000000 */   nop
.L80035FD4:
/* 113D4 80035FD4 0C00B500 */  jal       update_cameras
/* 113D8 80035FD8 00000000 */   nop
/* 113DC 80035FDC 3C02800A */  lui       $v0, %hi(D_800A0944)
/* 113E0 80035FE0 24420944 */  addiu     $v0, $v0, %lo(D_800A0944)
/* 113E4 80035FE4 94430000 */  lhu       $v1, ($v0)
/* 113E8 80035FE8 24040002 */  addiu     $a0, $zero, 2
/* 113EC 80035FEC 3C01800A */  lui       $at, %hi(D_800A0946)
/* 113F0 80035FF0 A4240946 */  sh        $a0, %lo(D_800A0946)($at)
/* 113F4 80035FF4 24630001 */  addiu     $v1, $v1, 1
/* 113F8 80035FF8 0800D83B */  j         .L800360EC
/* 113FC 80035FFC A4430000 */   sh       $v1, ($v0)
.L80036000:
/* 11400 80036000 0C00F949 */  jal       update_encounters
/* 11404 80036004 00000000 */   nop
/* 11408 80036008 0C00E64C */  jal       update_npcs
/* 1140C 8003600C 00000000 */   nop
/* 11410 80036010 0C037DD0 */  jal       update_player
/* 11414 80036014 00000000 */   nop
/* 11418 80036018 0C00B500 */  jal       update_cameras
/* 1141C 8003601C 00000000 */   nop
/* 11420 80036020 3C04800A */  lui       $a0, %hi(D_800A0946)
/* 11424 80036024 24840946 */  addiu     $a0, $a0, %lo(D_800A0946)
/* 11428 80036028 84820000 */  lh        $v0, ($a0)
/* 1142C 8003602C 94830000 */  lhu       $v1, ($a0)
/* 11430 80036030 10400003 */  beqz      $v0, .L80036040
/* 11434 80036034 2462FFFF */   addiu    $v0, $v1, -1
.L80036038:
/* 11438 80036038 0800D83B */  j         .L800360EC
/* 1143C 8003603C A4820000 */   sh       $v0, ($a0)
.L80036040:
/* 11440 80036040 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 11444 80036044 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 11448 80036048 0C0B1059 */  jal       does_script_exist
/* 1144C 8003604C 8C44006C */   lw       $a0, 0x6c($v0)
/* 11450 80036050 14400026 */  bnez      $v0, .L800360EC
/* 11454 80036054 00000000 */   nop
/* 11458 80036058 3C05800A */  lui       $a1, %hi(gOverrideFlags)
/* 1145C 8003605C 24A5A650 */  addiu     $a1, $a1, %lo(gOverrideFlags)
/* 11460 80036060 2404FFF7 */  addiu     $a0, $zero, -9
/* 11464 80036064 8CA20000 */  lw        $v0, ($a1)
/* 11468 80036068 96030000 */  lhu       $v1, ($s0)
/* 1146C 8003606C 00441024 */  and       $v0, $v0, $a0
/* 11470 80036070 24630001 */  addiu     $v1, $v1, 1
/* 11474 80036074 ACA20000 */  sw        $v0, ($a1)
/* 11478 80036078 0800D83B */  j         .L800360EC
/* 1147C 8003607C A6030000 */   sh       $v1, ($s0)
.L80036080:
/* 11480 80036080 0C00E64C */  jal       update_npcs
/* 11484 80036084 00000000 */   nop
/* 11488 80036088 0C037DD0 */  jal       update_player
/* 1148C 8003608C 00000000 */   nop
/* 11490 80036090 0C016754 */  jal       update_effects
/* 11494 80036094 00000000 */   nop
/* 11498 80036098 0C00B500 */  jal       update_cameras
/* 1149C 8003609C 00000000 */   nop
/* 114A0 800360A0 3C04800A */  lui       $a0, %hi(gMapTransitionAlpha)
/* 114A4 800360A4 24840940 */  addiu     $a0, $a0, %lo(gMapTransitionAlpha)
/* 114A8 800360A8 0C04E175 */  jal       update_enter_map_screen_overlay
/* 114AC 800360AC 00000000 */   nop
/* 114B0 800360B0 00021400 */  sll       $v0, $v0, 0x10
/* 114B4 800360B4 1040000D */  beqz      $v0, .L800360EC
/* 114B8 800360B8 00000000 */   nop
/* 114BC 800360BC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 114C0 800360C0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 114C4 800360C4 80420071 */  lb        $v0, 0x71($v0)
/* 114C8 800360C8 14400003 */  bnez      $v0, .L800360D8
/* 114CC 800360CC 00000000 */   nop
/* 114D0 800360D0 0C038069 */  jal       enable_player_input
/* 114D4 800360D4 00000000 */   nop
.L800360D8:
/* 114D8 800360D8 3C05BF80 */  lui       $a1, 0xbf80
/* 114DC 800360DC 0C04DF62 */  jal       set_screen_overlay_params_front
/* 114E0 800360E0 240400FF */   addiu    $a0, $zero, 0xff
/* 114E4 800360E4 0C00CD3C */  jal       set_game_mode
/* 114E8 800360E8 24040004 */   addiu    $a0, $zero, 4
.L800360EC:
/* 114EC 800360EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 114F0 800360F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 114F4 800360F4 03E00008 */  jr        $ra
/* 114F8 800360F8 27BD0018 */   addiu    $sp, $sp, 0x18
