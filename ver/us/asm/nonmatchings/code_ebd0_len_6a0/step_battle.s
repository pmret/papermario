.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel step_battle
/* ECE4 800338E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ECE8 800338E8 AFB00010 */  sw        $s0, 0x10($sp)
/* ECEC 800338EC 3C10800A */  lui       $s0, %hi(D_800A0900)
/* ECF0 800338F0 26100900 */  addiu     $s0, $s0, %lo(D_800A0900)
/* ECF4 800338F4 24030005 */  addiu     $v1, $zero, 5
/* ECF8 800338F8 AFBF0014 */  sw        $ra, 0x14($sp)
/* ECFC 800338FC 82020000 */  lb        $v0, ($s0)
/* ED00 80033900 1443000F */  bne       $v0, $v1, .L80033940
/* ED04 80033904 92040000 */   lbu      $a0, ($s0)
/* ED08 80033908 3C02800A */  lui       $v0, %hi(D_8009A658)
/* ED0C 8003390C 8C42A658 */  lw        $v0, %lo(D_8009A658)($v0)
/* ED10 80033910 8C430004 */  lw        $v1, 4($v0)
/* ED14 80033914 3C02800A */  lui       $v0, %hi(D_8009A64C)
/* ED18 80033918 8C42A64C */  lw        $v0, %lo(D_8009A64C)($v0)
/* ED1C 8003391C 14620089 */  bne       $v1, $v0, .L80033B44
/* ED20 80033920 2484FFFF */   addiu    $a0, $a0, -1
/* ED24 80033924 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* ED28 80033928 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* ED2C 8003392C 8C430000 */  lw        $v1, ($v0)
/* ED30 80033930 A2040000 */  sb        $a0, ($s0)
/* ED34 80033934 34630008 */  ori       $v1, $v1, 8
/* ED38 80033938 0C018028 */  jal       nuContRmbForceStop
/* ED3C 8003393C AC430000 */   sw       $v1, ($v0)
.L80033940:
/* ED40 80033940 82030000 */  lb        $v1, ($s0)
/* ED44 80033944 04600071 */  bltz      $v1, .L80033B0C
/* ED48 80033948 92020000 */   lbu      $v0, ($s0)
/* ED4C 8003394C 18600003 */  blez      $v1, .L8003395C
/* ED50 80033950 2442FFFF */   addiu    $v0, $v0, -1
/* ED54 80033954 0800CED1 */  j         .L80033B44
/* ED58 80033958 A2020000 */   sb       $v0, ($s0)
.L8003395C:
/* ED5C 8003395C 3C048007 */  lui       $a0, %hi(D_800778A0)
/* ED60 80033960 248478A0 */  addiu     $a0, $a0, %lo(D_800778A0)
/* ED64 80033964 24050002 */  addiu     $a1, $zero, 2
/* ED68 80033968 2402FFFF */  addiu     $v0, $zero, -1
/* ED6C 8003396C 0C017CBC */  jal       nuGfxSetCfb
/* ED70 80033970 A2020000 */   sb       $v0, ($s0)
/* ED74 80033974 0C018030 */  jal       nuContRmbForceStopEnd
/* ED78 80033978 00000000 */   nop
/* ED7C 8003397C 0C05260E */  jal       sfx_stop_env_sounds
/* ED80 80033980 00000000 */   nop
/* ED84 80033984 0C00EC6A */  jal       func_8003B1A8
/* ED88 80033988 00000000 */   nop
/* ED8C 8003398C 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* ED90 80033990 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* ED94 80033994 8E030000 */  lw        $v1, ($s0)
/* ED98 80033998 24020001 */  addiu     $v0, $zero, 1
/* ED9C 8003399C 0C016BA8 */  jal       allocate_hit_tables
/* EDA0 800339A0 A0620070 */   sb       $v0, 0x70($v1)
/* EDA4 800339A4 0C00B458 */  jal       func_8002D160
/* EDA8 800339A8 00000000 */   nop
/* EDAC 800339AC 0C0AC82D */  jal       func_802B20B4
/* EDB0 800339B0 00000000 */   nop
/* EDB4 800339B4 0C05259C */  jal       func_80149670
/* EDB8 800339B8 0000202D */   daddu    $a0, $zero, $zero
/* EDBC 800339BC 8E100000 */  lw        $s0, ($s0)
/* EDC0 800339C0 3C03800E */  lui       $v1, %hi(gBattleStatus+0x47A)
/* EDC4 800339C4 9063C4EA */  lbu       $v1, %lo(gBattleStatus+0x47A)($v1)
/* EDC8 800339C8 9205007E */  lbu       $a1, 0x7e($s0)
/* EDCC 800339CC 3C04800E */  lui       $a0, %hi(gBattleStatus+0x47B)
/* EDD0 800339D0 9084C4EB */  lbu       $a0, %lo(gBattleStatus+0x47B)($a0)
/* EDD4 800339D4 30A20001 */  andi      $v0, $a1, 1
/* EDD8 800339D8 14400007 */  bnez      $v0, .L800339F8
/* EDDC 800339DC 34A20001 */   ori      $v0, $a1, 1
/* EDE0 800339E0 24020026 */  addiu     $v0, $zero, 0x26
/* EDE4 800339E4 54620006 */  bnel      $v1, $v0, .L80033A00
/* EDE8 800339E8 24040005 */   addiu    $a0, $zero, 5
/* EDEC 800339EC 54800004 */  bnel      $a0, $zero, .L80033A00
/* EDF0 800339F0 24040005 */   addiu    $a0, $zero, 5
/* EDF4 800339F4 34A20001 */  ori       $v0, $a1, 1
.L800339F8:
/* EDF8 800339F8 A202007E */  sb        $v0, 0x7e($s0)
/* EDFC 800339FC 24040006 */  addiu     $a0, $zero, 6
.L80033A00:
/* EE00 80033A00 0C0B763E */  jal       func_802DD8F8
/* EE04 80033A04 00000000 */   nop
/* EE08 80033A08 0C045751 */  jal       clear_model_data
/* EE0C 80033A0C 00000000 */   nop
/* EE10 80033A10 0C052010 */  jal       func_80148040
/* EE14 80033A14 00000000 */   nop
/* EE18 80033A18 0C05177E */  jal       use_default_background_settings
/* EE1C 80033A1C 00000000 */   nop
/* EE20 80033A20 0C0482EC */  jal       clear_entity_models
/* EE24 80033A24 00000000 */   nop
/* EE28 80033A28 0C047889 */  jal       func_8011E224
/* EE2C 80033A2C 00000000 */   nop
/* EE30 80033A30 0C048C2E */  jal       clear_dynamic_entity_list
/* EE34 80033A34 00000000 */   nop
/* EE38 80033A38 0000202D */  daddu     $a0, $zero, $zero
/* EE3C 80033A3C 0C0514BA */  jal       func_801452E8
/* EE40 80033A40 0080282D */   daddu    $a1, $a0, $zero
/* EE44 80033A44 0C050440 */  jal       func_80141100
/* EE48 80033A48 00000000 */   nop
/* EE4C 80033A4C 0C03A6EC */  jal       reset_status_menu
/* EE50 80033A50 00000000 */   nop
/* EE54 80033A54 0C04C3FC */  jal       clear_item_entity_data
/* EE58 80033A58 00000000 */   nop
/* EE5C 80033A5C 0C0B0C77 */  jal       clear_script_list
/* EE60 80033A60 00000000 */   nop
/* EE64 80033A64 0C00E12F */  jal       clear_npcs
/* EE68 80033A68 00000000 */   nop
/* EE6C 80033A6C 0C04432E */  jal       clear_entity_data
/* EE70 80033A70 24040001 */   addiu    $a0, $zero, 1
/* EE74 80033A74 0C0515A0 */  jal       clear_trigger_data
/* EE78 80033A78 00000000 */   nop
/* EE7C 80033A7C 3C040017 */  lui       $a0, 0x17
/* EE80 80033A80 2484C8E0 */  addiu     $a0, $a0, -0x3720
/* EE84 80033A84 3C05001D */  lui       $a1, 0x1d
/* EE88 80033A88 24A5C310 */  addiu     $a1, $a1, -0x3cf0
/* EE8C 80033A8C 3C068024 */  lui       $a2, %hi(get_dpad_input_radial)
/* EE90 80033A90 24C6E000 */  addiu     $a2, $a2, %lo(get_dpad_input_radial)
/* EE94 80033A94 0C00A5CF */  jal       dma_copy
/* EE98 80033A98 00000000 */   nop
/* EE9C 80033A9C 0C08F84C */  jal       initialize_battle
/* EEA0 80033AA0 00000000 */   nop
/* EEA4 80033AA4 0C09027D */  jal       func_802409F4
/* EEA8 80033AA8 00000000 */   nop
/* EEAC 80033AAC 0C01CAF7 */  jal       load_battle_section
/* EEB0 80033AB0 00000000 */   nop
/* EEB4 80033AB4 3C04800F */  lui       $a0, %hi(gPlayerStatusPtr)
/* EEB8 80033AB8 8C847B30 */  lw        $a0, %lo(gPlayerStatusPtr)($a0)
/* EEBC 80033ABC 8C820004 */  lw        $v0, 4($a0)
/* EEC0 80033AC0 2403FFBF */  addiu     $v1, $zero, -0x41
/* EEC4 80033AC4 3C01800A */  lui       $at, %hi(D_800A0904)
/* EEC8 80033AC8 AC220904 */  sw        $v0, %lo(D_800A0904)($at)
/* EECC 80033ACC 00431024 */  and       $v0, $v0, $v1
/* EED0 80033AD0 0C009C64 */  jal       func_80027190
/* EED4 80033AD4 AC820004 */   sw       $v0, 4($a0)
/* EED8 80033AD8 3C01800A */  lui       $at, %hi(D_800A0908)
/* EEDC 80033ADC AC220908 */  sw        $v0, %lo(D_800A0908)($at)
/* EEE0 80033AE0 0C009C22 */  jal       func_80027088
/* EEE4 80033AE4 0000202D */   daddu    $a0, $zero, $zero
/* EEE8 80033AE8 3C05800A */  lui       $a1, %hi(gOverrideFlags)
/* EEEC 80033AEC 24A5A650 */  addiu     $a1, $a1, %lo(gOverrideFlags)
/* EEF0 80033AF0 2403FFF7 */  addiu     $v1, $zero, -9
/* EEF4 80033AF4 8CA20000 */  lw        $v0, ($a1)
/* EEF8 80033AF8 3C04800A */  lui       $a0, %hi(D_800A0900)
/* EEFC 80033AFC 80840900 */  lb        $a0, %lo(D_800A0900)($a0)
/* EF00 80033B00 00431024 */  and       $v0, $v0, $v1
/* EF04 80033B04 0481000F */  bgez      $a0, .L80033B44
/* EF08 80033B08 ACA20000 */   sw       $v0, ($a1)
.L80033B0C:
/* EF0C 80033B0C 0C00F949 */  jal       update_counters
/* EF10 80033B10 00000000 */   nop
/* EF14 80033B14 0C08F90E */  jal       update_battle_state
/* EF18 80033B18 00000000 */   nop
/* EF1C 80033B1C 0C00E64C */  jal       update_npcs
/* EF20 80033B20 00000000 */   nop
/* EF24 80033B24 0C04C7BB */  jal       update_item_entities
/* EF28 80033B28 00000000 */   nop
/* EF2C 80033B2C 0C016754 */  jal       update_effects
/* EF30 80033B30 00000000 */   nop
/* EF34 80033B34 0C04599D */  jal       func_80116674
/* EF38 80033B38 00000000 */   nop
/* EF3C 80033B3C 0C00B500 */  jal       update_cameras
/* EF40 80033B40 00000000 */   nop
.L80033B44:
/* EF44 80033B44 8FBF0014 */  lw        $ra, 0x14($sp)
/* EF48 80033B48 8FB00010 */  lw        $s0, 0x10($sp)
/* EF4C 80033B4C 03E00008 */  jr        $ra
/* EF50 80033B50 27BD0018 */   addiu    $sp, $sp, 0x18
