.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel step_intro
/* 11C54 80036854 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 11C58 80036858 AFB10014 */  sw        $s1, 0x14($sp)
/* 11C5C 8003685C 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 11C60 80036860 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 11C64 80036864 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 11C68 80036868 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 11C6C 8003686C 2404FFFF */  addiu     $a0, $zero, -1
/* 11C70 80036870 AFBF0018 */  sw        $ra, 0x18($sp)
/* 11C74 80036874 AFB00010 */  sw        $s0, 0x10($sp)
/* 11C78 80036878 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 11C7C 8003687C 804300A8 */  lb        $v1, 0xa8($v0)
/* 11C80 80036880 1064002F */  beq       $v1, $a0, .L80036940
/* 11C84 80036884 8C450010 */   lw       $a1, 0x10($v0)
/* 11C88 80036888 3C03800A */  lui       $v1, %hi(D_800A0964)
/* 11C8C 8003688C 24630964 */  addiu     $v1, $v1, %lo(D_800A0964)
/* 11C90 80036890 8C620000 */  lw        $v0, ($v1)
/* 11C94 80036894 14400004 */  bnez      $v0, .L800368A8
/* 11C98 80036898 30A2F000 */   andi     $v0, $a1, 0xf000
/* 11C9C 8003689C 10400002 */  beqz      $v0, .L800368A8
/* 11CA0 800368A0 24020001 */   addiu    $v0, $zero, 1
/* 11CA4 800368A4 AC620000 */  sw        $v0, ($v1)
.L800368A8:
/* 11CA8 800368A8 3C03800A */  lui       $v1, %hi(D_800A0964)
/* 11CAC 800368AC 8C630964 */  lw        $v1, %lo(D_800A0964)($v1)
/* 11CB0 800368B0 24020001 */  addiu     $v0, $zero, 1
/* 11CB4 800368B4 14620010 */  bne       $v1, $v0, .L800368F8
/* 11CB8 800368B8 24020002 */   addiu    $v0, $zero, 2
/* 11CBC 800368BC 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 11CC0 800368C0 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* 11CC4 800368C4 908300AC */  lbu       $v1, 0xac($a0)
/* 11CC8 800368C8 2C620002 */  sltiu     $v0, $v1, 2
/* 11CCC 800368CC 14400018 */  bnez      $v0, .L80036930
/* 11CD0 800368D0 24020064 */   addiu    $v0, $zero, 0x64
/* 11CD4 800368D4 00031600 */  sll       $v0, $v1, 0x18
/* 11CD8 800368D8 00021603 */  sra       $v0, $v0, 0x18
/* 11CDC 800368DC 24030004 */  addiu     $v1, $zero, 4
/* 11CE0 800368E0 14430003 */  bne       $v0, $v1, .L800368F0
/* 11CE4 800368E4 24020002 */   addiu    $v0, $zero, 2
/* 11CE8 800368E8 0800DA4C */  j         .L80036930
/* 11CEC 800368EC 24020064 */   addiu    $v0, $zero, 0x64
.L800368F0:
/* 11CF0 800368F0 3C03800A */  lui       $v1, %hi(D_800A0964)
/* 11CF4 800368F4 8C630964 */  lw        $v1, %lo(D_800A0964)($v1)
.L800368F8:
/* 11CF8 800368F8 14620011 */  bne       $v1, $v0, .L80036940
/* 11CFC 800368FC 00000000 */   nop
/* 11D00 80036900 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 11D04 80036904 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* 11D08 80036908 908300AC */  lbu       $v1, 0xac($a0)
/* 11D0C 8003690C 2C620002 */  sltiu     $v0, $v1, 2
/* 11D10 80036910 14400005 */  bnez      $v0, .L80036928
/* 11D14 80036914 00031600 */   sll      $v0, $v1, 0x18
/* 11D18 80036918 00021603 */  sra       $v0, $v0, 0x18
/* 11D1C 8003691C 24030004 */  addiu     $v1, $zero, 4
/* 11D20 80036920 14430007 */  bne       $v0, $v1, .L80036940
/* 11D24 80036924 00000000 */   nop
.L80036928:
/* 11D28 80036928 908200A8 */  lbu       $v0, 0xa8($a0)
/* 11D2C 8003692C 24420001 */  addiu     $v0, $v0, 1
.L80036930:
/* 11D30 80036930 0C00D994 */  jal       begin_state_intro
/* 11D34 80036934 A08200A8 */   sb       $v0, 0xa8($a0)
/* 11D38 80036938 0800DB72 */  j         .L80036DC8
/* 11D3C 8003693C 00000000 */   nop
.L80036940:
/* 11D40 80036940 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 11D44 80036944 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 11D48 80036948 804300AC */  lb        $v1, 0xac($v0)
/* 11D4C 8003694C 2C620016 */  sltiu     $v0, $v1, 0x16
/* 11D50 80036950 10400109 */  beqz      $v0, .L80036D78
/* 11D54 80036954 00031080 */   sll      $v0, $v1, 2
/* 11D58 80036958 3C01800A */  lui       $at, %hi(jtbl_80098338)
/* 11D5C 8003695C 00220821 */  addu      $at, $at, $v0
/* 11D60 80036960 8C228338 */  lw        $v0, %lo(jtbl_80098338)($at)
/* 11D64 80036964 00400008 */  jr        $v0
/* 11D68 80036968 00000000 */   nop
glabel L8003696C_11D6C
/* 11D6C 8003696C 0C016754 */  jal       func_80059D50
/* 11D70 80036970 00000000 */   nop
/* 11D74 80036974 0C00B500 */  jal       update_cameras
/* 11D78 80036978 00000000 */   nop
/* 11D7C 8003697C 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 11D80 80036980 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 11D84 80036984 8E060000 */  lw        $a2, ($s0)
/* 11D88 80036988 80C300A8 */  lb        $v1, 0xa8($a2)
/* 11D8C 8003698C 2402FFFF */  addiu     $v0, $zero, -1
/* 11D90 80036990 14620010 */  bne       $v1, $v0, .L800369D4
/* 11D94 80036994 00000000 */   nop
/* 11D98 80036998 44806000 */  mtc1      $zero, $f12
/* 11D9C 8003699C 0C00AFC5 */  jal       set_curtain_fade_goal
/* 11DA0 800369A0 00000000 */   nop
/* 11DA4 800369A4 3C04800A */  lui       $a0, %hi(D_800A0956)
/* 11DA8 800369A8 84840956 */  lh        $a0, %lo(D_800A0956)($a0)
/* 11DAC 800369AC 0C00CE0C */  jal       intro_logos_fade_out
/* 11DB0 800369B0 00000000 */   nop
/* 11DB4 800369B4 104000F0 */  beqz      $v0, .L80036D78
/* 11DB8 800369B8 24020001 */   addiu    $v0, $zero, 1
/* 11DBC 800369BC 0000202D */  daddu     $a0, $zero, $zero
/* 11DC0 800369C0 8E030000 */  lw        $v1, ($s0)
/* 11DC4 800369C4 0C00AFC1 */  jal       set_curtain_draw_callback
/* 11DC8 800369C8 A06200AC */   sb       $v0, 0xac($v1)
/* 11DCC 800369CC 0800DB5E */  j         .L80036D78
/* 11DD0 800369D0 00000000 */   nop
.L800369D4:
/* 11DD4 800369D4 3C05800A */  lui       $a1, %hi(D_800A0954)
/* 11DD8 800369D8 24A50954 */  addiu     $a1, $a1, %lo(D_800A0954)
/* 11DDC 800369DC 94A20000 */  lhu       $v0, ($a1)
/* 11DE0 800369E0 3C03800A */  lui       $v1, %hi(D_800A0956)
/* 11DE4 800369E4 94630956 */  lhu       $v1, %lo(D_800A0956)($v1)
/* 11DE8 800369E8 00431021 */  addu      $v0, $v0, $v1
/* 11DEC 800369EC A4A20000 */  sh        $v0, ($a1)
/* 11DF0 800369F0 00021400 */  sll       $v0, $v0, 0x10
/* 11DF4 800369F4 00021403 */  sra       $v0, $v0, 0x10
/* 11DF8 800369F8 284200FF */  slti      $v0, $v0, 0xff
/* 11DFC 800369FC 144000DE */  bnez      $v0, .L80036D78
/* 11E00 80036A00 240200FF */   addiu    $v0, $zero, 0xff
/* 11E04 80036A04 0000202D */  daddu     $a0, $zero, $zero
/* 11E08 80036A08 A4A20000 */  sh        $v0, ($a1)
/* 11E0C 80036A0C 24020001 */  addiu     $v0, $zero, 1
/* 11E10 80036A10 0C00AFC1 */  jal       set_curtain_draw_callback
/* 11E14 80036A14 A0C200AC */   sb       $v0, 0xac($a2)
/* 11E18 80036A18 0800DB5E */  j         .L80036D78
/* 11E1C 80036A1C 00000000 */   nop
glabel L80036A20_11E20
/* 11E20 80036A20 3C04800A */  lui       $a0, %hi(D_8009A650)
/* 11E24 80036A24 2484A650 */  addiu     $a0, $a0, %lo(D_8009A650)
/* 11E28 80036A28 8C820000 */  lw        $v0, ($a0)
/* 11E2C 80036A2C 24030004 */  addiu     $v1, $zero, 4
/* 11E30 80036A30 3C01800A */  lui       $at, %hi(D_800A0950)
/* 11E34 80036A34 AC230950 */  sw        $v1, %lo(D_800A0950)($at)
/* 11E38 80036A38 34420008 */  ori       $v0, $v0, 8
/* 11E3C 80036A3C AC820000 */  sw        $v0, ($a0)
/* 11E40 80036A40 3C03800A */  lui       $v1, %hi(D_800A0960)
/* 11E44 80036A44 8C630960 */  lw        $v1, %lo(D_800A0960)($v1)
/* 11E48 80036A48 2402000E */  addiu     $v0, $zero, 0xe
/* 11E4C 80036A4C 106200CA */  beq       $v1, $v0, .L80036D78
/* 11E50 80036A50 00000000 */   nop
/* 11E54 80036A54 0800DAA3 */  j         .L80036A8C
/* 11E58 80036A58 00000000 */   nop
glabel L80036A5C_11E5C
/* 11E5C 80036A5C 3C03800A */  lui       $v1, %hi(D_800A0950)
/* 11E60 80036A60 24630950 */  addiu     $v1, $v1, %lo(D_800A0950)
/* 11E64 80036A64 8C620000 */  lw        $v0, ($v1)
/* 11E68 80036A68 2442FFFF */  addiu     $v0, $v0, -1
/* 11E6C 80036A6C 1C4000C2 */  bgtz      $v0, .L80036D78
/* 11E70 80036A70 AC620000 */   sw       $v0, ($v1)
/* 11E74 80036A74 3C04800A */  lui       $a0, %hi(D_8009A650)
/* 11E78 80036A78 2484A650 */  addiu     $a0, $a0, %lo(D_8009A650)
/* 11E7C 80036A7C 8C820000 */  lw        $v0, ($a0)
/* 11E80 80036A80 2403FFF7 */  addiu     $v1, $zero, -9
/* 11E84 80036A84 00431024 */  and       $v0, $v0, $v1
/* 11E88 80036A88 AC820000 */  sw        $v0, ($a0)
.L80036A8C:
/* 11E8C 80036A8C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 11E90 80036A90 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 11E94 80036A94 24020002 */  addiu     $v0, $zero, 2
/* 11E98 80036A98 0800DB5E */  j         .L80036D78
/* 11E9C 80036A9C A06200AC */   sb       $v0, 0xac($v1)
glabel L80036AA0_11EA0
/* 11EA0 80036AA0 0C00AFC1 */  jal       set_curtain_draw_callback
/* 11EA4 80036AA4 0000202D */   daddu    $a0, $zero, $zero
/* 11EA8 80036AA8 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 11EAC 80036AAC 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 11EB0 80036AB0 8C620000 */  lw        $v0, ($v1)
/* 11EB4 80036AB4 A0400070 */  sb        $zero, 0x70($v0)
/* 11EB8 80036AB8 8C620000 */  lw        $v0, ($v1)
/* 11EBC 80036ABC A0400076 */  sb        $zero, 0x76($v0)
/* 11EC0 80036AC0 8C620000 */  lw        $v0, ($v1)
/* 11EC4 80036AC4 A0400078 */  sb        $zero, 0x78($v0)
/* 11EC8 80036AC8 8C620000 */  lw        $v0, ($v1)
/* 11ECC 80036ACC A040007D */  sb        $zero, 0x7d($v0)
/* 11ED0 80036AD0 8C620000 */  lw        $v0, ($v1)
/* 11ED4 80036AD4 804200A8 */  lb        $v0, 0xa8($v0)
/* 11ED8 80036AD8 2405FFFF */  addiu     $a1, $zero, -1
/* 11EDC 80036ADC 14450037 */  bne       $v0, $a1, .L80036BBC
/* 11EE0 80036AE0 2404000B */   addiu    $a0, $zero, 0xb
/* 11EE4 80036AE4 0C00AB00 */  jal       general_heap_create
/* 11EE8 80036AE8 00000000 */   nop
/* 11EEC 80036AEC 0C047624 */  jal       func_8011D890
/* 11EF0 80036AF0 00000000 */   nop
/* 11EF4 80036AF4 0C048C2E */  jal       clear_dynamic_entity_list
/* 11EF8 80036AF8 00000000 */   nop
/* 11EFC 80036AFC 0C0B0C77 */  jal       clear_script_list
/* 11F00 80036B00 00000000 */   nop
/* 11F04 80036B04 0C00B7BD */  jal       create_cameras_a
/* 11F08 80036B08 00000000 */   nop
/* 11F0C 80036B0C 0C0B763E */  jal       func_802DD8F8
/* 11F10 80036B10 0000202D */   daddu    $a0, $zero, $zero
/* 11F14 80036B14 0C0482EC */  jal       clear_entity_models
/* 11F18 80036B18 00000000 */   nop
/* 11F1C 80036B1C 0C047889 */  jal       func_8011E224
/* 11F20 80036B20 00000000 */   nop
/* 11F24 80036B24 0C045751 */  jal       clear_model_data
/* 11F28 80036B28 00000000 */   nop
/* 11F2C 80036B2C 0C052010 */  jal       func_80148040
/* 11F30 80036B30 00000000 */   nop
/* 11F34 80036B34 0C05177E */  jal       func_80145DF8
/* 11F38 80036B38 00000000 */   nop
/* 11F3C 80036B3C 0C050440 */  jal       func_80141100
/* 11F40 80036B40 00000000 */   nop
/* 11F44 80036B44 0C0515A0 */  jal       clear_trigger_data
/* 11F48 80036B48 00000000 */   nop
/* 11F4C 80036B4C 0C048D9D */  jal       clear_printers
/* 11F50 80036B50 00000000 */   nop
/* 11F54 80036B54 0C04432E */  jal       clear_entity_data
/* 11F58 80036B58 0000202D */   daddu    $a0, $zero, $zero
/* 11F5C 80036B5C 0C04E042 */  jal       func_80138108
/* 11F60 80036B60 00000000 */   nop
/* 11F64 80036B64 0C037F14 */  jal       clear_player_status
/* 11F68 80036B68 00000000 */   nop
/* 11F6C 80036B6C 0C00E12F */  jal       clear_npcs
/* 11F70 80036B70 00000000 */   nop
/* 11F74 80036B74 0C039CE8 */  jal       clear_player_data
/* 11F78 80036B78 00000000 */   nop
/* 11F7C 80036B7C 0C01CACC */  jal       func_80072B30
/* 11F80 80036B80 00000000 */   nop
/* 11F84 80036B84 0C00F8CE */  jal       func_8003E338
/* 11F88 80036B88 00000000 */   nop
/* 11F8C 80036B8C 0C016727 */  jal       func_80059C9C
/* 11F90 80036B90 00000000 */   nop
/* 11F94 80036B94 0C04C3FC */  jal       clear_item_entity_data
/* 11F98 80036B98 00000000 */   nop
/* 11F9C 80036B9C 0C0514C8 */  jal       clear_saved_variables
/* 11FA0 80036BA0 00000000 */   nop
/* 11FA4 80036BA4 0C016BE5 */  jal       initialize_collision
/* 11FA8 80036BA8 00000000 */   nop
/* 11FAC 80036BAC 0C00CD3C */  jal       set_game_mode
/* 11FB0 80036BB0 24040002 */   addiu    $a0, $zero, 2
/* 11FB4 80036BB4 0800DB72 */  j         .L80036DC8
/* 11FB8 80036BB8 00000000 */   nop
.L80036BBC:
/* 11FBC 80036BBC 26230058 */  addiu     $v1, $s1, 0x58
/* 11FC0 80036BC0 2402000A */  addiu     $v0, $zero, 0xa
/* 11FC4 80036BC4 A2220002 */  sb        $v0, 2($s1)
/* 11FC8 80036BC8 A2220003 */  sb        $v0, 3($s1)
/* 11FCC 80036BCC A2220004 */  sb        $v0, 4($s1)
/* 11FD0 80036BD0 24020005 */  addiu     $v0, $zero, 5
/* 11FD4 80036BD4 A2220005 */  sb        $v0, 5($s1)
/* 11FD8 80036BD8 A2220006 */  sb        $v0, 6($s1)
/* 11FDC 80036BDC A2220007 */  sb        $v0, 7($s1)
/* 11FE0 80036BE0 24020002 */  addiu     $v0, $zero, 2
/* 11FE4 80036BE4 A2220008 */  sb        $v0, 8($s1)
/* 11FE8 80036BE8 A2200000 */  sb        $zero, ($s1)
/* 11FEC 80036BEC A2250001 */  sb        $a1, 1($s1)
/* 11FF0 80036BF0 A220000E */  sb        $zero, 0xe($s1)
/* 11FF4 80036BF4 A2200009 */  sb        $zero, 9($s1)
.L80036BF8:
/* 11FF8 80036BF8 A0600014 */  sb        $zero, 0x14($v1)
/* 11FFC 80036BFC 2484FFFF */  addiu     $a0, $a0, -1
/* 12000 80036C00 0481FFFD */  bgez      $a0, .L80036BF8
/* 12004 80036C04 2463FFF8 */   addiu    $v1, $v1, -8
/* 12008 80036C08 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 1200C 80036C0C 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 12010 80036C10 8E020000 */  lw        $v0, ($s0)
/* 12014 80036C14 A2200012 */  sb        $zero, 0x12($s1)
/* 12018 80036C18 84440086 */  lh        $a0, 0x86($v0)
/* 1201C 80036C1C 8445008C */  lh        $a1, 0x8c($v0)
/* 12020 80036C20 0C0169BD */  jal       load_map_by_IDs
/* 12024 80036C24 0000302D */   daddu    $a2, $zero, $zero
/* 12028 80036C28 8E030000 */  lw        $v1, ($s0)
/* 1202C 80036C2C 24020003 */  addiu     $v0, $zero, 3
/* 12030 80036C30 0C03805E */  jal       disable_player_input
/* 12034 80036C34 A06200AC */   sb       $v0, 0xac($v1)
/* 12038 80036C38 0800DB5E */  j         .L80036D78
/* 1203C 80036C3C 00000000 */   nop
glabel L80036C40_12040
/* 12040 80036C40 3C04800A */  lui       $a0, %hi(D_800A0960)
/* 12044 80036C44 24840960 */  addiu     $a0, $a0, %lo(D_800A0960)
/* 12048 80036C48 8C830000 */  lw        $v1, ($a0)
/* 1204C 80036C4C 2402000E */  addiu     $v0, $zero, 0xe
/* 12050 80036C50 14620004 */  bne       $v1, $v0, .L80036C64
/* 12054 80036C54 240200FF */   addiu    $v0, $zero, 0xff
/* 12058 80036C58 2402000F */  addiu     $v0, $zero, 0xf
/* 1205C 80036C5C AC820000 */  sw        $v0, ($a0)
/* 12060 80036C60 240200FF */  addiu     $v0, $zero, 0xff
.L80036C64:
/* 12064 80036C64 3C04800A */  lui       $a0, %hi(D_8009A650)
/* 12068 80036C68 2484A650 */  addiu     $a0, $a0, %lo(D_8009A650)
/* 1206C 80036C6C 2405FFF7 */  addiu     $a1, $zero, -9
/* 12070 80036C70 3C03800A */  lui       $v1, %hi(D_800A0958)
/* 12074 80036C74 94630958 */  lhu       $v1, %lo(D_800A0958)($v1)
/* 12078 80036C78 3C06800B */  lui       $a2, %hi(gCameras)
/* 1207C 80036C7C 24C61D80 */  addiu     $a2, $a2, %lo(gCameras)
/* 12080 80036C80 00431023 */  subu      $v0, $v0, $v1
/* 12084 80036C84 3C01800A */  lui       $at, %hi(D_800A0954)
/* 12088 80036C88 A4220954 */  sh        $v0, %lo(D_800A0954)($at)
/* 1208C 80036C8C 8C830000 */  lw        $v1, ($a0)
/* 12090 80036C90 94C20000 */  lhu       $v0, ($a2)
/* 12094 80036C94 00651824 */  and       $v1, $v1, $a1
/* 12098 80036C98 3042FFFD */  andi      $v0, $v0, 0xfffd
/* 1209C 80036C9C AC830000 */  sw        $v1, ($a0)
/* 120A0 80036CA0 A4C20000 */  sh        $v0, ($a2)
/* 120A4 80036CA4 2402FFFD */  addiu     $v0, $zero, -3
/* 120A8 80036CA8 00621824 */  and       $v1, $v1, $v0
/* 120AC 80036CAC 0C037DD0 */  jal       update_player
/* 120B0 80036CB0 AC830000 */   sw       $v1, ($a0)
/* 120B4 80036CB4 0C00F949 */  jal       func_8003E524
/* 120B8 80036CB8 00000000 */   nop
/* 120BC 80036CBC 0C00E64C */  jal       update_npcs
/* 120C0 80036CC0 00000000 */   nop
/* 120C4 80036CC4 0C016754 */  jal       func_80059D50
/* 120C8 80036CC8 00000000 */   nop
/* 120CC 80036CCC 0C00B500 */  jal       update_cameras
/* 120D0 80036CD0 00000000 */   nop
/* 120D4 80036CD4 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 120D8 80036CD8 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 120DC 80036CDC 8E020000 */  lw        $v0, ($s0)
/* 120E0 80036CE0 0C0B1059 */  jal       does_script_exist
/* 120E4 80036CE4 8C44006C */   lw       $a0, 0x6c($v0)
/* 120E8 80036CE8 14400037 */  bnez      $v0, .L80036DC8
/* 120EC 80036CEC 24030004 */   addiu    $v1, $zero, 4
/* 120F0 80036CF0 8E020000 */  lw        $v0, ($s0)
/* 120F4 80036CF4 94440086 */  lhu       $a0, 0x86($v0)
/* 120F8 80036CF8 A04300AC */  sb        $v1, 0xac($v0)
/* 120FC 80036CFC 0800DB5E */  j         .L80036D78
/* 12100 80036D00 A4440088 */   sh       $a0, 0x88($v0)
glabel L80036D04_12104
/* 12104 80036D04 0C016754 */  jal       func_80059D50
/* 12108 80036D08 00000000 */   nop
/* 1210C 80036D0C 0C00B500 */  jal       update_cameras
/* 12110 80036D10 00000000 */   nop
/* 12114 80036D14 0C00E64C */  jal       update_npcs
/* 12118 80036D18 00000000 */   nop
/* 1211C 80036D1C 3C04800A */  lui       $a0, %hi(D_800A0954)
/* 12120 80036D20 24840954 */  addiu     $a0, $a0, %lo(D_800A0954)
/* 12124 80036D24 84820000 */  lh        $v0, ($a0)
/* 12128 80036D28 1440000C */  bnez      $v0, .L80036D5C
/* 1212C 80036D2C 94830000 */   lhu      $v1, ($a0)
/* 12130 80036D30 3C01BF80 */  lui       $at, 0xbf80
/* 12134 80036D34 4481A000 */  mtc1      $at, $f20
/* 12138 80036D38 00000000 */  nop
/* 1213C 80036D3C 4405A000 */  mfc1      $a1, $f20
/* 12140 80036D40 0C04DF62 */  jal       func_80137D88
/* 12144 80036D44 240400FF */   addiu    $a0, $zero, 0xff
/* 12148 80036D48 4405A000 */  mfc1      $a1, $f20
/* 1214C 80036D4C 0C04DF69 */  jal       func_80137DA4
/* 12150 80036D50 240400FF */   addiu    $a0, $zero, 0xff
/* 12154 80036D54 0800DB5E */  j         .L80036D78
/* 12158 80036D58 00000000 */   nop
.L80036D5C:
/* 1215C 80036D5C 3C02800A */  lui       $v0, %hi(D_800A0958)
/* 12160 80036D60 94420958 */  lhu       $v0, %lo(D_800A0958)($v0)
/* 12164 80036D64 00621023 */  subu      $v0, $v1, $v0
/* 12168 80036D68 A4820000 */  sh        $v0, ($a0)
/* 1216C 80036D6C 00021400 */  sll       $v0, $v0, 0x10
/* 12170 80036D70 04420001 */  bltzl     $v0, .L80036D78
/* 12174 80036D74 A4800000 */   sh       $zero, ($a0)
.L80036D78:
glabel L80036D78_12178
/* 12178 80036D78 3C02800A */  lui       $v0, %hi(D_800A0954)
/* 1217C 80036D7C 84420954 */  lh        $v0, %lo(D_800A0954)($v0)
/* 12180 80036D80 3C04800A */  lui       $a0, %hi(D_800A0963)
/* 12184 80036D84 90840963 */  lbu       $a0, %lo(D_800A0963)($a0)
/* 12188 80036D88 44820000 */  mtc1      $v0, $f0
/* 1218C 80036D8C 00000000 */  nop
/* 12190 80036D90 46800020 */  cvt.s.w   $f0, $f0
/* 12194 80036D94 44050000 */  mfc1      $a1, $f0
/* 12198 80036D98 0C04DF69 */  jal       func_80137DA4
/* 1219C 80036D9C 00000000 */   nop
/* 121A0 80036DA0 3C05800A */  lui       $a1, %hi(D_800A095B)
/* 121A4 80036DA4 90A5095B */  lbu       $a1, %lo(D_800A095B)($a1)
/* 121A8 80036DA8 3C06800A */  lui       $a2, %hi(D_800A095D)
/* 121AC 80036DAC 90C6095D */  lbu       $a2, %lo(D_800A095D)($a2)
/* 121B0 80036DB0 3C07800A */  lui       $a3, %hi(D_800A095F)
/* 121B4 80036DB4 90E7095F */  lbu       $a3, %lo(D_800A095F)($a3)
/* 121B8 80036DB8 0C04DF84 */  jal       func_80137E10
/* 121BC 80036DBC 24040001 */   addiu    $a0, $zero, 1
/* 121C0 80036DC0 0C00CE1D */  jal       intro_logos_update_fade
/* 121C4 80036DC4 00000000 */   nop
.L80036DC8:
/* 121C8 80036DC8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 121CC 80036DCC 8FB10014 */  lw        $s1, 0x14($sp)
/* 121D0 80036DD0 8FB00010 */  lw        $s0, 0x10($sp)
/* 121D4 80036DD4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 121D8 80036DD8 03E00008 */  jr        $ra
/* 121DC 80036DDC 27BD0028 */   addiu    $sp, $sp, 0x28
