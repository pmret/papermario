.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_800982E8
.word L80035740_10B40, L800357A4_10BA4, L80035814_10C14, L80035A68_10E68, L80035AE0_10EE0, 0

.section .text

glabel state_step_exit_language_select
/* 10B04 80035704 3C03800A */  lui       $v1, %hi(D_800A0931)
/* 10B08 80035708 80630931 */  lb        $v1, %lo(D_800A0931)($v1)
/* 10B0C 8003570C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 10B10 80035710 AFBF0024 */  sw        $ra, 0x24($sp)
/* 10B14 80035714 AFB20020 */  sw        $s2, 0x20($sp)
/* 10B18 80035718 AFB1001C */  sw        $s1, 0x1c($sp)
/* 10B1C 8003571C 2C620005 */  sltiu     $v0, $v1, 5
/* 10B20 80035720 10400101 */  beqz      $v0, .L80035B28
/* 10B24 80035724 AFB00018 */   sw       $s0, 0x18($sp)
/* 10B28 80035728 00031080 */  sll       $v0, $v1, 2
/* 10B2C 8003572C 3C01800A */  lui       $at, %hi(jtbl_800982E8)
/* 10B30 80035730 00220821 */  addu      $at, $at, $v0
/* 10B34 80035734 8C2282E8 */  lw        $v0, %lo(jtbl_800982E8)($at)
/* 10B38 80035738 00400008 */  jr        $v0
/* 10B3C 8003573C 00000000 */   nop
glabel L80035740_10B40
/* 10B40 80035740 3C10800A */  lui       $s0, %hi(D_800A0932)
/* 10B44 80035744 26100932 */  addiu     $s0, $s0, %lo(D_800A0932)
/* 10B48 80035748 86020000 */  lh        $v0, ($s0)
/* 10B4C 8003574C 96030000 */  lhu       $v1, ($s0)
/* 10B50 80035750 1040000F */  beqz      $v0, .L80035790
/* 10B54 80035754 2462FFEC */   addiu    $v0, $v1, -0x14
/* 10B58 80035758 A6020000 */  sh        $v0, ($s0)
/* 10B5C 8003575C 00021400 */  sll       $v0, $v0, 0x10
/* 10B60 80035760 04420001 */  bltzl     $v0, .L80035768
/* 10B64 80035764 A6000000 */   sh       $zero, ($s0)
.L80035768:
/* 10B68 80035768 86020000 */  lh        $v0, ($s0)
/* 10B6C 8003576C 44820000 */  mtc1      $v0, $f0
/* 10B70 80035770 00000000 */  nop
/* 10B74 80035774 46800020 */  cvt.s.w   $f0, $f0
/* 10B78 80035778 44050000 */  mfc1      $a1, $f0
/* 10B7C 8003577C 0C04DF62 */  jal       set_screen_overlay_params_front
/* 10B80 80035780 0000202D */   daddu    $a0, $zero, $zero
/* 10B84 80035784 86020000 */  lh        $v0, ($s0)
/* 10B88 80035788 144000E7 */  bnez      $v0, .L80035B28
/* 10B8C 8003578C 00000000 */   nop
.L80035790:
/* 10B90 80035790 24020001 */  addiu     $v0, $zero, 1
/* 10B94 80035794 3C01800A */  lui       $at, %hi(D_800A0931)
/* 10B98 80035798 A0220931 */  sb        $v0, %lo(D_800A0931)($at)
/* 10B9C 8003579C 0800D6CA */  j         .L80035B28
/* 10BA0 800357A0 00000000 */   nop
glabel L800357A4_10BA4
/* 10BA4 800357A4 3C10800A */  lui       $s0, %hi(D_800A0932)
/* 10BA8 800357A8 26100932 */  addiu     $s0, $s0, %lo(D_800A0932)
/* 10BAC 800357AC 241100FF */  addiu     $s1, $zero, 0xff
/* 10BB0 800357B0 86020000 */  lh        $v0, ($s0)
/* 10BB4 800357B4 96030000 */  lhu       $v1, ($s0)
/* 10BB8 800357B8 10510011 */  beq       $v0, $s1, .L80035800
/* 10BBC 800357BC 24620014 */   addiu    $v0, $v1, 0x14
/* 10BC0 800357C0 A6020000 */  sh        $v0, ($s0)
/* 10BC4 800357C4 00021400 */  sll       $v0, $v0, 0x10
/* 10BC8 800357C8 00021403 */  sra       $v0, $v0, 0x10
/* 10BCC 800357CC 28420100 */  slti      $v0, $v0, 0x100
/* 10BD0 800357D0 50400001 */  beql      $v0, $zero, .L800357D8
/* 10BD4 800357D4 A6110000 */   sh       $s1, ($s0)
.L800357D8:
/* 10BD8 800357D8 86020000 */  lh        $v0, ($s0)
/* 10BDC 800357DC 44820000 */  mtc1      $v0, $f0
/* 10BE0 800357E0 00000000 */  nop
/* 10BE4 800357E4 46800020 */  cvt.s.w   $f0, $f0
/* 10BE8 800357E8 44050000 */  mfc1      $a1, $f0
/* 10BEC 800357EC 0C04DF62 */  jal       set_screen_overlay_params_front
/* 10BF0 800357F0 0000202D */   daddu    $a0, $zero, $zero
/* 10BF4 800357F4 86020000 */  lh        $v0, ($s0)
/* 10BF8 800357F8 145100CB */  bne       $v0, $s1, .L80035B28
/* 10BFC 800357FC 00000000 */   nop
.L80035800:
/* 10C00 80035800 24020002 */  addiu     $v0, $zero, 2
/* 10C04 80035804 3C01800A */  lui       $at, %hi(D_800A0931)
/* 10C08 80035808 A0220931 */  sb        $v0, %lo(D_800A0931)($at)
/* 10C0C 8003580C 0800D6CA */  j         .L80035B28
/* 10C10 80035810 00000000 */   nop
glabel L80035814_10C14
/* 10C14 80035814 3C06800A */  lui       $a2, %hi(D_800A0930)
/* 10C18 80035818 24C60930 */  addiu     $a2, $a2, %lo(D_800A0930)
/* 10C1C 8003581C 80C30000 */  lb        $v1, ($a2)
/* 10C20 80035820 24020003 */  addiu     $v0, $zero, 3
/* 10C24 80035824 14620006 */  bne       $v1, $v0, .L80035840
/* 10C28 80035828 00000000 */   nop
/* 10C2C 8003582C 3C03800A */  lui       $v1, %hi(gOverrideFlags)
/* 10C30 80035830 2463A650 */  addiu     $v1, $v1, %lo(gOverrideFlags)
/* 10C34 80035834 8C620000 */  lw        $v0, ($v1)
/* 10C38 80035838 34420008 */  ori       $v0, $v0, 8
/* 10C3C 8003583C AC620000 */  sw        $v0, ($v1)
.L80035840:
/* 10C40 80035840 80C20000 */  lb        $v0, ($a2)
/* 10C44 80035844 90C30000 */  lbu       $v1, ($a2)
/* 10C48 80035848 044000B7 */  bltz      $v0, .L80035B28
/* 10C4C 8003584C 2462FFFF */   addiu    $v0, $v1, -1
/* 10C50 80035850 A0C20000 */  sb        $v0, ($a2)
/* 10C54 80035854 00021600 */  sll       $v0, $v0, 0x18
/* 10C58 80035858 14400067 */  bnez      $v0, .L800359F8
/* 10C5C 8003585C 24050003 */   addiu    $a1, $zero, 3
/* 10C60 80035860 3C048007 */  lui       $a0, %hi(D_80077980)
/* 10C64 80035864 24847980 */  addiu     $a0, $a0, %lo(D_80077980)
/* 10C68 80035868 2402FFFF */  addiu     $v0, $zero, -1
/* 10C6C 8003586C 0C017CBC */  jal       nuGfxSetCfb
/* 10C70 80035870 A0C20000 */   sb       $v0, ($a2)
/* 10C74 80035874 0C0912C0 */  jal       filemenu_cleanup
/* 10C78 80035878 00000000 */   nop
/* 10C7C 8003587C 3C04800A */  lui       $a0, %hi(gOverrideFlags)
/* 10C80 80035880 2484A650 */  addiu     $a0, $a0, %lo(gOverrideFlags)
/* 10C84 80035884 8C820000 */  lw        $v0, ($a0)
/* 10C88 80035888 2403FFF7 */  addiu     $v1, $zero, -9
/* 10C8C 8003588C 00431024 */  and       $v0, $v0, $v1
/* 10C90 80035890 0C016AFA */  jal       get_current_map_header
/* 10C94 80035894 AC820000 */   sw       $v0, ($a0)
/* 10C98 80035898 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 10C9C 8003589C 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 10CA0 800358A0 8E040000 */  lw        $a0, ($s0)
/* 10CA4 800358A4 84830086 */  lh        $v1, 0x86($a0)
/* 10CA8 800358A8 00031900 */  sll       $v1, $v1, 4
/* 10CAC 800358AC 3C058009 */  lui       $a1, %hi(gAreas+0x4)
/* 10CB0 800358B0 00A32821 */  addu      $a1, $a1, $v1
/* 10CB4 800358B4 8CA534F4 */  lw        $a1, %lo(gAreas+0x4)($a1)
/* 10CB8 800358B8 8483008C */  lh        $v1, 0x8c($a0)
/* 10CBC 800358BC 0040902D */  daddu     $s2, $v0, $zero
/* 10CC0 800358C0 A0800070 */  sb        $zero, 0x70($a0)
/* 10CC4 800358C4 00031940 */  sll       $v1, $v1, 5
/* 10CC8 800358C8 0C016BE1 */  jal       func_8005AF84
/* 10CCC 800358CC 00A38821 */   addu     $s1, $a1, $v1
/* 10CD0 800358D0 0C00AB37 */  jal       func_8002ACDC
/* 10CD4 800358D4 00000000 */   nop
/* 10CD8 800358D8 0C05259C */  jal       sfx_clear_env_sounds
/* 10CDC 800358DC 24040001 */   addiu    $a0, $zero, 1
/* 10CE0 800358E0 8E020000 */  lw        $v0, ($s0)
/* 10CE4 800358E4 0C0B763E */  jal       spr_init_sprites
/* 10CE8 800358E8 80440084 */   lb       $a0, 0x84($v0)
/* 10CEC 800358EC 0C0457FA */  jal       init_model_data
/* 10CF0 800358F0 00000000 */   nop
/* 10CF4 800358F4 0C05203C */  jal       init_sprite_shading_data
/* 10CF8 800358F8 00000000 */   nop
/* 10CFC 800358FC 0C048316 */  jal       init_entity_models
/* 10D00 80035900 00000000 */   nop
/* 10D04 80035904 0C0478C4 */  jal       reset_animator_list
/* 10D08 80035908 00000000 */   nop
/* 10D0C 8003590C 0C048C45 */  jal       init_generic_entity_list
/* 10D10 80035910 00000000 */   nop
/* 10D14 80035914 0000202D */  daddu     $a0, $zero, $zero
/* 10D18 80035918 0C0514BA */  jal       set_hud_element_nonworld_cache
/* 10D1C 8003591C 0080282D */   daddu    $a1, $a0, $zero
/* 10D20 80035920 0C0504C0 */  jal       init_hud_element_list
/* 10D24 80035924 00000000 */   nop
/* 10D28 80035928 0C04C433 */  jal       init_item_entity_list
/* 10D2C 8003592C 00000000 */   nop
/* 10D30 80035930 0C0B0CBB */  jal       init_script_list
/* 10D34 80035934 00000000 */   nop
/* 10D38 80035938 0C00E14B */  jal       init_npc_list
/* 10D3C 8003593C 00000000 */   nop
/* 10D40 80035940 0C044396 */  jal       func_80110E58
/* 10D44 80035944 00000000 */   nop
/* 10D48 80035948 0C0515CA */  jal       init_trigger_list
/* 10D4C 8003594C 00000000 */   nop
/* 10D50 80035950 3C04800E */  lui       $a0, %hi(mapShapeName)
/* 10D54 80035954 24849230 */  addiu     $a0, $a0, %lo(mapShapeName)
/* 10D58 80035958 0C016B3A */  jal       load_asset_by_name
/* 10D5C 8003595C 27A50010 */   addiu    $a1, $sp, 0x10
/* 10D60 80035960 0040802D */  daddu     $s0, $v0, $zero
/* 10D64 80035964 3C058021 */  lui       $a1, %hi(D_80210000)
/* 10D68 80035968 24A50000 */  addiu     $a1, $a1, %lo(D_80210000)
/* 10D6C 8003596C 0C01BB7C */  jal       decode_yay0
/* 10D70 80035970 0200202D */   daddu    $a0, $s0, $zero
/* 10D74 80035974 0C00AB1E */  jal       general_heap_free
/* 10D78 80035978 0200202D */   daddu    $a0, $s0, $zero
/* 10D7C 8003597C 0C016BE5 */  jal       initialize_collision
/* 10D80 80035980 00000000 */   nop
/* 10D84 80035984 0C016C16 */  jal       load_collision
/* 10D88 80035988 00000000 */   nop
/* 10D8C 8003598C 8E240008 */  lw        $a0, 8($s1)
/* 10D90 80035990 10800004 */  beqz      $a0, .L800359A4
/* 10D94 80035994 00000000 */   nop
/* 10D98 80035998 8E25000C */  lw        $a1, 0xc($s1)
/* 10D9C 8003599C 0C00A5CF */  jal       dma_copy
/* 10DA0 800359A0 8E260010 */   lw       $a2, 0x10($s1)
.L800359A4:
/* 10DA4 800359A4 0C05175C */  jal       load_map_bg
/* 10DA8 800359A8 8E240014 */   lw       $a0, 0x14($s1)
/* 10DAC 800359AC 8E440038 */  lw        $a0, 0x38($s2)
/* 10DB0 800359B0 50800005 */  beql      $a0, $zero, .L800359C8
/* 10DB4 800359B4 24040128 */   addiu    $a0, $zero, 0x128
/* 10DB8 800359B8 0C05178A */  jal       read_background_size
/* 10DBC 800359BC 00000000 */   nop
/* 10DC0 800359C0 0800D676 */  j         .L800359D8
/* 10DC4 800359C4 00000000 */   nop
.L800359C8:
/* 10DC8 800359C8 240500C8 */  addiu     $a1, $zero, 0xc8
/* 10DCC 800359CC 2406000C */  addiu     $a2, $zero, 0xc
/* 10DD0 800359D0 0C05179C */  jal       set_background_size
/* 10DD4 800359D4 24070014 */   addiu    $a3, $zero, 0x14
.L800359D8:
/* 10DD8 800359D8 0C04584B */  jal       calculate_model_sizes
/* 10DDC 800359DC 00000000 */   nop
/* 10DE0 800359E0 0C00EC6C */  jal       npc_reload_all
/* 10DE4 800359E4 00000000 */   nop
/* 10DE8 800359E8 0C03A631 */  jal       func_800E98C4
/* 10DEC 800359EC 00000000 */   nop
/* 10DF0 800359F0 0C009C22 */  jal       set_time_freeze_mode
/* 10DF4 800359F4 24040001 */   addiu    $a0, $zero, 1
.L800359F8:
/* 10DF8 800359F8 0C051FB1 */  jal       set_windows_visible
/* 10DFC 800359FC 0000202D */   daddu    $a0, $zero, $zero
/* 10E00 80035A00 24020003 */  addiu     $v0, $zero, 3
/* 10E04 80035A04 3C01800A */  lui       $at, %hi(D_800A0931)
/* 10E08 80035A08 A0220931 */  sb        $v0, %lo(D_800A0931)($at)
/* 10E0C 80035A0C 0C037DD0 */  jal       update_player
/* 10E10 80035A10 00000000 */   nop
/* 10E14 80035A14 0C00E64C */  jal       update_npcs
/* 10E18 80035A18 00000000 */   nop
/* 10E1C 80035A1C 0C00F949 */  jal       update_encounters
/* 10E20 80035A20 00000000 */   nop
/* 10E24 80035A24 0C016754 */  jal       update_effects
/* 10E28 80035A28 00000000 */   nop
/* 10E2C 80035A2C 3C03800A */  lui       $v1, %hi(D_800A0932)
/* 10E30 80035A30 24630932 */  addiu     $v1, $v1, %lo(D_800A0932)
/* 10E34 80035A34 94620000 */  lhu       $v0, ($v1)
/* 10E38 80035A38 2442FFEC */  addiu     $v0, $v0, -0x14
/* 10E3C 80035A3C A4620000 */  sh        $v0, ($v1)
/* 10E40 80035A40 00021400 */  sll       $v0, $v0, 0x10
/* 10E44 80035A44 04420001 */  bltzl     $v0, .L80035A4C
/* 10E48 80035A48 A4600000 */   sh       $zero, ($v1)
.L80035A4C:
/* 10E4C 80035A4C 84620000 */  lh        $v0, ($v1)
/* 10E50 80035A50 44820000 */  mtc1      $v0, $f0
/* 10E54 80035A54 00000000 */  nop
/* 10E58 80035A58 46800020 */  cvt.s.w   $f0, $f0
/* 10E5C 80035A5C 44050000 */  mfc1      $a1, $f0
/* 10E60 80035A60 0800D6C8 */  j         .L80035B20
/* 10E64 80035A64 0000202D */   daddu    $a0, $zero, $zero
glabel L80035A68_10E68
/* 10E68 80035A68 0C037DD0 */  jal       update_player
/* 10E6C 80035A6C 00000000 */   nop
/* 10E70 80035A70 0C00E64C */  jal       update_npcs
/* 10E74 80035A74 00000000 */   nop
/* 10E78 80035A78 0C00F949 */  jal       update_encounters
/* 10E7C 80035A7C 00000000 */   nop
/* 10E80 80035A80 0C016754 */  jal       update_effects
/* 10E84 80035A84 00000000 */   nop
/* 10E88 80035A88 3C04800A */  lui       $a0, %hi(D_800A0932)
/* 10E8C 80035A8C 24840932 */  addiu     $a0, $a0, %lo(D_800A0932)
/* 10E90 80035A90 84820000 */  lh        $v0, ($a0)
/* 10E94 80035A94 94830000 */  lhu       $v1, ($a0)
/* 10E98 80035A98 14400006 */  bnez      $v0, .L80035AB4
/* 10E9C 80035A9C 2462FFEC */   addiu    $v0, $v1, -0x14
/* 10EA0 80035AA0 24020004 */  addiu     $v0, $zero, 4
/* 10EA4 80035AA4 3C01800A */  lui       $at, %hi(D_800A0931)
/* 10EA8 80035AA8 A0220931 */  sb        $v0, %lo(D_800A0931)($at)
/* 10EAC 80035AAC 0800D6CA */  j         .L80035B28
/* 10EB0 80035AB0 00000000 */   nop
.L80035AB4:
/* 10EB4 80035AB4 A4820000 */  sh        $v0, ($a0)
/* 10EB8 80035AB8 00021400 */  sll       $v0, $v0, 0x10
/* 10EBC 80035ABC 04420001 */  bltzl     $v0, .L80035AC4
/* 10EC0 80035AC0 A4800000 */   sh       $zero, ($a0)
.L80035AC4:
/* 10EC4 80035AC4 84820000 */  lh        $v0, ($a0)
/* 10EC8 80035AC8 44820000 */  mtc1      $v0, $f0
/* 10ECC 80035ACC 00000000 */  nop
/* 10ED0 80035AD0 46800020 */  cvt.s.w   $f0, $f0
/* 10ED4 80035AD4 44050000 */  mfc1      $a1, $f0
/* 10ED8 80035AD8 0800D6C8 */  j         .L80035B20
/* 10EDC 80035ADC 0000202D */   daddu    $a0, $zero, $zero
glabel L80035AE0_10EE0
/* 10EE0 80035AE0 0C009C22 */  jal       set_time_freeze_mode
/* 10EE4 80035AE4 0000202D */   daddu    $a0, $zero, $zero
/* 10EE8 80035AE8 0C037DD0 */  jal       update_player
/* 10EEC 80035AEC 00000000 */   nop
/* 10EF0 80035AF0 0C00E64C */  jal       update_npcs
/* 10EF4 80035AF4 00000000 */   nop
/* 10EF8 80035AF8 0C00F949 */  jal       update_encounters
/* 10EFC 80035AFC 00000000 */   nop
/* 10F00 80035B00 0C016754 */  jal       update_effects
/* 10F04 80035B04 00000000 */   nop
/* 10F08 80035B08 0C038069 */  jal       enable_player_input
/* 10F0C 80035B0C 00000000 */   nop
/* 10F10 80035B10 0C00CD3C */  jal       set_game_mode
/* 10F14 80035B14 24040004 */   addiu    $a0, $zero, 4
/* 10F18 80035B18 3C05BF80 */  lui       $a1, 0xbf80
/* 10F1C 80035B1C 240400FF */  addiu     $a0, $zero, 0xff
.L80035B20:
/* 10F20 80035B20 0C04DF62 */  jal       set_screen_overlay_params_front
/* 10F24 80035B24 00000000 */   nop
.L80035B28:
/* 10F28 80035B28 8FBF0024 */  lw        $ra, 0x24($sp)
/* 10F2C 80035B2C 8FB20020 */  lw        $s2, 0x20($sp)
/* 10F30 80035B30 8FB1001C */  lw        $s1, 0x1c($sp)
/* 10F34 80035B34 8FB00018 */  lw        $s0, 0x18($sp)
/* 10F38 80035B38 03E00008 */  jr        $ra
/* 10F3C 80035B3C 27BD0028 */   addiu    $sp, $sp, 0x28
