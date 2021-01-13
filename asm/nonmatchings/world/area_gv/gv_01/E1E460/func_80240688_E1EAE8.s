.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240688_E1EAE8
/* E1EAE8 80240688 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E1EAEC 8024068C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* E1EAF0 80240690 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* E1EAF4 80240694 AFBF0010 */  sw        $ra, 0x10($sp)
/* E1EAF8 80240698 8C620000 */  lw        $v0, ($v1)
/* E1EAFC 8024069C A0400070 */  sb        $zero, 0x70($v0)
/* E1EB00 802406A0 8C620000 */  lw        $v0, ($v1)
/* E1EB04 802406A4 A0400076 */  sb        $zero, 0x76($v0)
/* E1EB08 802406A8 8C620000 */  lw        $v0, ($v1)
/* E1EB0C 802406AC A0400078 */  sb        $zero, 0x78($v0)
/* E1EB10 802406B0 8C620000 */  lw        $v0, ($v1)
/* E1EB14 802406B4 3C04800A */  lui       $a0, %hi(D_8009A650)
/* E1EB18 802406B8 2484A650 */  addiu     $a0, $a0, %lo(D_8009A650)
/* E1EB1C 802406BC A040007D */  sb        $zero, 0x7d($v0)
/* E1EB20 802406C0 8C820000 */  lw        $v0, ($a0)
/* E1EB24 802406C4 2403FFF7 */  addiu     $v1, $zero, -9
/* E1EB28 802406C8 00431024 */  and       $v0, $v0, $v1
/* E1EB2C 802406CC 0C00AB00 */  jal       general_heap_create
/* E1EB30 802406D0 AC820000 */   sw       $v0, ($a0)
/* E1EB34 802406D4 0C047624 */  jal       func_8011D890
/* E1EB38 802406D8 00000000 */   nop
/* E1EB3C 802406DC 0C048C2E */  jal       clear_dynamic_entity_list
/* E1EB40 802406E0 00000000 */   nop
/* E1EB44 802406E4 0C0B0C77 */  jal       clear_script_list
/* E1EB48 802406E8 00000000 */   nop
/* E1EB4C 802406EC 0C00B7BD */  jal       create_cameras_a
/* E1EB50 802406F0 00000000 */   nop
/* E1EB54 802406F4 0C0B763E */  jal       func_802DD8F8
/* E1EB58 802406F8 0000202D */   daddu    $a0, $zero, $zero
/* E1EB5C 802406FC 0C0482EC */  jal       clear_virtual_models
/* E1EB60 80240700 00000000 */   nop
/* E1EB64 80240704 0C047889 */  jal       func_8011E224
/* E1EB68 80240708 00000000 */   nop
/* E1EB6C 8024070C 0C045751 */  jal       clear_model_data
/* E1EB70 80240710 00000000 */   nop
/* E1EB74 80240714 0C052010 */  jal       func_80148040
/* E1EB78 80240718 00000000 */   nop
/* E1EB7C 8024071C 0C05177E */  jal       func_80145DF8
/* E1EB80 80240720 00000000 */   nop
/* E1EB84 80240724 0C050440 */  jal       func_80141100
/* E1EB88 80240728 00000000 */   nop
/* E1EB8C 8024072C 0C0515A0 */  jal       clear_trigger_data
/* E1EB90 80240730 00000000 */   nop
/* E1EB94 80240734 0C048D9D */  jal       clear_printers
/* E1EB98 80240738 00000000 */   nop
/* E1EB9C 8024073C 0C04432E */  jal       clear_entity_data
/* E1EBA0 80240740 0000202D */   daddu    $a0, $zero, $zero
/* E1EBA4 80240744 0C04E042 */  jal       func_80138108
/* E1EBA8 80240748 00000000 */   nop
/* E1EBAC 8024074C 0C037F14 */  jal       clear_player_status
/* E1EBB0 80240750 00000000 */   nop
/* E1EBB4 80240754 0C00E12F */  jal       clear_npcs
/* E1EBB8 80240758 00000000 */   nop
/* E1EBBC 8024075C 0C039CE8 */  jal       clear_player_data
/* E1EBC0 80240760 00000000 */   nop
/* E1EBC4 80240764 0C01CACC */  jal       func_80072B30
/* E1EBC8 80240768 00000000 */   nop
/* E1EBCC 8024076C 0C00F8CE */  jal       func_8003E338
/* E1EBD0 80240770 00000000 */   nop
/* E1EBD4 80240774 0C016727 */  jal       func_80059C9C
/* E1EBD8 80240778 00000000 */   nop
/* E1EBDC 8024077C 0C04C3FC */  jal       clear_item_entity_data
/* E1EBE0 80240780 00000000 */   nop
/* E1EBE4 80240784 0C0514C8 */  jal       clear_saved_variables
/* E1EBE8 80240788 00000000 */   nop
/* E1EBEC 8024078C 0C016BE5 */  jal       initialize_collision
/* E1EBF0 80240790 00000000 */   nop
/* E1EBF4 80240794 0C00CDF4 */  jal       intro_logos_set_fade_alpha
/* E1EBF8 80240798 240400FF */   addiu    $a0, $zero, 0xff
/* E1EBFC 8024079C 0C00CDF8 */  jal       intro_logos_set_fade_color
/* E1EC00 802407A0 240400D0 */   addiu    $a0, $zero, 0xd0
/* E1EC04 802407A4 0C00CD3C */  jal       set_game_mode
/* E1EC08 802407A8 24040002 */   addiu    $a0, $zero, 2
/* E1EC0C 802407AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* E1EC10 802407B0 240200FF */  addiu     $v0, $zero, 0xff
/* E1EC14 802407B4 03E00008 */  jr        $ra
/* E1EC18 802407B8 27BD0018 */   addiu    $sp, $sp, 0x18
/* E1EC1C 802407BC 00000000 */  nop
