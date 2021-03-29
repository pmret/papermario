.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel step_pause_menu
/* FD7C 8003497C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* FD80 80034980 AFB00010 */  sw        $s0, 0x10($sp)
/* FD84 80034984 3C10800A */  lui       $s0, %hi(D_800A0921)
/* FD88 80034988 26100921 */  addiu     $s0, $s0, %lo(D_800A0921)
/* FD8C 8003498C AFBF0018 */  sw        $ra, 0x18($sp)
/* FD90 80034990 AFB10014 */  sw        $s1, 0x14($sp)
/* FD94 80034994 82110000 */  lb        $s1, ($s0)
/* FD98 80034998 12200005 */  beqz      $s1, .L800349B0
/* FD9C 8003499C 24020002 */   addiu    $v0, $zero, 2
/* FDA0 800349A0 12220022 */  beq       $s1, $v0, .L80034A2C
/* FDA4 800349A4 00000000 */   nop
/* FDA8 800349A8 0800D2F8 */  j         .L80034BE0
/* FDAC 800349AC 00000000 */   nop
.L800349B0:
/* FDB0 800349B0 0C00F949 */  jal       update_counters
/* FDB4 800349B4 00000000 */   nop
/* FDB8 800349B8 0C00E64C */  jal       update_npcs
/* FDBC 800349BC 00000000 */   nop
/* FDC0 800349C0 0C037DD0 */  jal       update_player
/* FDC4 800349C4 00000000 */   nop
/* FDC8 800349C8 0C016754 */  jal       update_effects
/* FDCC 800349CC 00000000 */   nop
/* FDD0 800349D0 3C02800A */  lui       $v0, %hi(D_8009A658)
/* FDD4 800349D4 8C42A658 */  lw        $v0, %lo(D_8009A658)($v0)
/* FDD8 800349D8 8C430004 */  lw        $v1, 4($v0)
/* FDDC 800349DC 3C02800A */  lui       $v0, %hi(D_8009A64C)
/* FDE0 800349E0 8C42A64C */  lw        $v0, %lo(D_8009A64C)($v0)
/* FDE4 800349E4 1462007E */  bne       $v1, $v0, .L80034BE0
/* FDE8 800349E8 24020004 */   addiu    $v0, $zero, 4
/* FDEC 800349EC 3C01800A */  lui       $at, %hi(D_800A0920)
/* FDF0 800349F0 A0220920 */  sb        $v0, %lo(D_800A0920)($at)
/* FDF4 800349F4 24020002 */  addiu     $v0, $zero, 2
/* FDF8 800349F8 3C04800A */  lui       $a0, %hi(gOverrideFlags)
/* FDFC 800349FC 2484A650 */  addiu     $a0, $a0, %lo(gOverrideFlags)
/* FE00 80034A00 A2020000 */  sb        $v0, ($s0)
/* FE04 80034A04 3C058007 */  lui       $a1, %hi(gGameStatusPtr)
/* FE08 80034A08 8CA5419C */  lw        $a1, %lo(gGameStatusPtr)($a1)
/* FE0C 80034A0C 8C820000 */  lw        $v0, ($a0)
/* FE10 80034A10 94A30148 */  lhu       $v1, 0x148($a1)
/* FE14 80034A14 34420008 */  ori       $v0, $v0, 8
/* FE18 80034A18 AC820000 */  sw        $v0, ($a0)
/* FE1C 80034A1C 3063FF0F */  andi      $v1, $v1, 0xff0f
/* FE20 80034A20 34630010 */  ori       $v1, $v1, 0x10
/* FE24 80034A24 0800D2F8 */  j         .L80034BE0
/* FE28 80034A28 A4A30148 */   sh       $v1, 0x148($a1)
.L80034A2C:
/* FE2C 80034A2C 3C06800A */  lui       $a2, %hi(D_800A0920)
/* FE30 80034A30 24C60920 */  addiu     $a2, $a2, %lo(D_800A0920)
/* FE34 80034A34 80C30000 */  lb        $v1, ($a2)
/* FE38 80034A38 04600056 */  bltz      $v1, .L80034B94
/* FE3C 80034A3C 90C20000 */   lbu      $v0, ($a2)
/* FE40 80034A40 10600005 */  beqz      $v1, .L80034A58
/* FE44 80034A44 2442FFFF */   addiu    $v0, $v0, -1
/* FE48 80034A48 A0C20000 */  sb        $v0, ($a2)
/* FE4C 80034A4C 00021600 */  sll       $v0, $v0, 0x18
/* FE50 80034A50 1440004C */  bnez      $v0, .L80034B84
/* FE54 80034A54 00000000 */   nop
.L80034A58:
/* FE58 80034A58 3C048007 */  lui       $a0, %hi(D_80077950)
/* FE5C 80034A5C 24847950 */  addiu     $a0, $a0, %lo(D_80077950)
/* FE60 80034A60 24050002 */  addiu     $a1, $zero, 2
/* FE64 80034A64 2402FFFF */  addiu     $v0, $zero, -1
/* FE68 80034A68 0C017CBC */  jal       nuGfxSetCfb
/* FE6C 80034A6C A0C20000 */   sb       $v0, ($a2)
/* FE70 80034A70 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* FE74 80034A74 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* FE78 80034A78 8E030000 */  lw        $v1, ($s0)
/* FE7C 80034A7C 9462015C */  lhu       $v0, 0x15c($v1)
/* FE80 80034A80 0C05260E */  jal       sfx_stop_env_sounds
/* FE84 80034A84 A462015E */   sh       $v0, 0x15e($v1)
/* FE88 80034A88 0C00EC6A */  jal       func_8003B1A8
/* FE8C 80034A8C 00000000 */   nop
/* FE90 80034A90 8E020000 */  lw        $v0, ($s0)
/* FE94 80034A94 0C016BA8 */  jal       allocate_hit_tables
/* FE98 80034A98 A0510070 */   sb       $s1, 0x70($v0)
/* FE9C 80034A9C 0C00AB28 */  jal       battle_heap_create
/* FEA0 80034AA0 00000000 */   nop
/* FEA4 80034AA4 0C018028 */  jal       nuContRmbForceStop
/* FEA8 80034AA8 00000000 */   nop
/* FEAC 80034AAC 0C05259C */  jal       func_80149670
/* FEB0 80034AB0 0000202D */   daddu    $a0, $zero, $zero
/* FEB4 80034AB4 0C0B763E */  jal       func_802DD8F8
/* FEB8 80034AB8 0000202D */   daddu    $a0, $zero, $zero
/* FEBC 80034ABC 0C045751 */  jal       clear_model_data
/* FEC0 80034AC0 00000000 */   nop
/* FEC4 80034AC4 0C052010 */  jal       func_80148040
/* FEC8 80034AC8 00000000 */   nop
/* FECC 80034ACC 0C05177E */  jal       use_default_background_settings
/* FED0 80034AD0 00000000 */   nop
/* FED4 80034AD4 0C0482EC */  jal       clear_entity_models
/* FED8 80034AD8 00000000 */   nop
/* FEDC 80034ADC 0C047889 */  jal       func_8011E224
/* FEE0 80034AE0 00000000 */   nop
/* FEE4 80034AE4 0C048C2E */  jal       clear_dynamic_entity_list
/* FEE8 80034AE8 00000000 */   nop
/* FEEC 80034AEC 3C048020 */  lui       $a0, %hi(func_80200000)
/* FEF0 80034AF0 24840000 */  addiu     $a0, $a0, %lo(func_80200000)
/* FEF4 80034AF4 3C050003 */  lui       $a1, 3
/* FEF8 80034AF8 0C0514BA */  jal       func_801452E8
/* FEFC 80034AFC 34A58000 */   ori      $a1, $a1, 0x8000
/* FF00 80034B00 0C050440 */  jal       func_80141100
/* FF04 80034B04 00000000 */   nop
/* FF08 80034B08 0C03A6EC */  jal       reset_status_menu
/* FF0C 80034B0C 00000000 */   nop
/* FF10 80034B10 0C04C3FC */  jal       clear_item_entity_data
/* FF14 80034B14 00000000 */   nop
/* FF18 80034B18 0C0B0C77 */  jal       clear_script_list
/* FF1C 80034B1C 00000000 */   nop
/* FF20 80034B20 0C00E12F */  jal       clear_npcs
/* FF24 80034B24 00000000 */   nop
/* FF28 80034B28 0C04432E */  jal       clear_entity_data
/* FF2C 80034B2C 0000202D */   daddu    $a0, $zero, $zero
/* FF30 80034B30 0C0515A0 */  jal       clear_trigger_data
/* FF34 80034B34 00000000 */   nop
/* FF38 80034B38 0C05260A */  jal       func_80149828
/* FF3C 80034B3C 00000000 */   nop
/* FF40 80034B40 3C01800A */  lui       $at, %hi(D_800A0924)
/* FF44 80034B44 AC220924 */  sw        $v0, %lo(D_800A0924)($at)
/* FF48 80034B48 0C0525FF */  jal       func_801497FC
/* FF4C 80034B4C 0000202D */   daddu    $a0, $zero, $zero
/* FF50 80034B50 0C052B17 */  jal       bgm_quiet_max_volume
/* FF54 80034B54 00000000 */   nop
/* FF58 80034B58 3C048007 */  lui       $a0, %hi(D_8007795C)
/* FF5C 80034B5C 0C018038 */  jal       nuPiReadRomOverlay
/* FF60 80034B60 2484795C */   addiu    $a0, $a0, %lo(D_8007795C)
/* FF64 80034B64 0C091018 */  jal       pause_init
/* FF68 80034B68 00000000 */   nop
/* FF6C 80034B6C 3C04800A */  lui       $a0, %hi(gOverrideFlags)
/* FF70 80034B70 2484A650 */  addiu     $a0, $a0, %lo(gOverrideFlags)
/* FF74 80034B74 8C820000 */  lw        $v0, ($a0)
/* FF78 80034B78 2403FFF7 */  addiu     $v1, $zero, -9
/* FF7C 80034B7C 00431024 */  and       $v0, $v0, $v1
/* FF80 80034B80 AC820000 */  sw        $v0, ($a0)
.L80034B84:
/* FF84 80034B84 3C02800A */  lui       $v0, %hi(D_800A0920)
/* FF88 80034B88 80420920 */  lb        $v0, %lo(D_800A0920)($v0)
/* FF8C 80034B8C 04410014 */  bgez      $v0, .L80034BE0
/* FF90 80034B90 00000000 */   nop
.L80034B94:
/* FF94 80034B94 3C10800A */  lui       $s0, %hi(D_800A0920)
/* FF98 80034B98 26100920 */  addiu     $s0, $s0, %lo(D_800A0920)
/* FF9C 80034B9C 82020000 */  lb        $v0, ($s0)
/* FFA0 80034BA0 2842FFF6 */  slti      $v0, $v0, -0xa
/* FFA4 80034BA4 14400007 */  bnez      $v0, .L80034BC4
/* FFA8 80034BA8 0000202D */   daddu    $a0, $zero, $zero
/* FFAC 80034BAC 0C091109 */  jal       pause_handle_input
/* FFB0 80034BB0 0080282D */   daddu    $a1, $a0, $zero
/* FFB4 80034BB4 92020000 */  lbu       $v0, ($s0)
/* FFB8 80034BB8 2442FFFF */  addiu     $v0, $v0, -1
/* FFBC 80034BBC 0800D2F6 */  j         .L80034BD8
/* FFC0 80034BC0 A2020000 */   sb       $v0, ($s0)
.L80034BC4:
/* FFC4 80034BC4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* FFC8 80034BC8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* FFCC 80034BCC 8C440010 */  lw        $a0, 0x10($v0)
/* FFD0 80034BD0 0C091109 */  jal       pause_handle_input
/* FFD4 80034BD4 8C450020 */   lw       $a1, 0x20($v0)
.L80034BD8:
/* FFD8 80034BD8 3C01800A */  lui       $at, %hi(D_800A0922)
/* FFDC 80034BDC A4200922 */  sh        $zero, %lo(D_800A0922)($at)
.L80034BE0:
/* FFE0 80034BE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* FFE4 80034BE4 8FB10014 */  lw        $s1, 0x14($sp)
/* FFE8 80034BE8 8FB00010 */  lw        $s0, 0x10($sp)
/* FFEC 80034BEC 03E00008 */  jr        $ra
/* FFF0 80034BF0 27BD0020 */   addiu    $sp, $sp, 0x20
