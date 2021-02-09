.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_map_by_IDs
/* 35AF4 8005A6F4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 35AF8 8005A6F8 AFB00038 */  sw        $s0, 0x38($sp)
/* 35AFC 8005A6FC 00C0802D */  daddu     $s0, $a2, $zero
/* 35B00 8005A700 AFB1003C */  sw        $s1, 0x3c($sp)
/* 35B04 8005A704 0080882D */  daddu     $s1, $a0, $zero
/* 35B08 8005A708 AFB30044 */  sw        $s3, 0x44($sp)
/* 35B0C 8005A70C 00A0982D */  daddu     $s3, $a1, $zero
/* 35B10 8005A710 AFB40048 */  sw        $s4, 0x48($sp)
/* 35B14 8005A714 0000A02D */  daddu     $s4, $zero, $zero
/* 35B18 8005A718 AFBF004C */  sw        $ra, 0x4c($sp)
/* 35B1C 8005A71C 0C05260E */  jal       func_80149838
/* 35B20 8005A720 AFB20040 */   sw       $s2, 0x40($sp)
/* 35B24 8005A724 3C05800A */  lui       $a1, %hi(D_8009A650)
/* 35B28 8005A728 24A5A650 */  addiu     $a1, $a1, %lo(D_8009A650)
/* 35B2C 8005A72C 2402FFBF */  addiu     $v0, $zero, -0x41
/* 35B30 8005A730 3C128007 */  lui       $s2, %hi(gGameStatusPtr)
/* 35B34 8005A734 2652419C */  addiu     $s2, $s2, %lo(gGameStatusPtr)
/* 35B38 8005A738 8CA30000 */  lw        $v1, ($a1)
/* 35B3C 8005A73C 8E440000 */  lw        $a0, ($s2)
/* 35B40 8005A740 00621824 */  and       $v1, $v1, $v0
/* 35B44 8005A744 2402FF7F */  addiu     $v0, $zero, -0x81
/* 35B48 8005A748 00621824 */  and       $v1, $v1, $v0
/* 35B4C 8005A74C ACA30000 */  sw        $v1, ($a1)
/* 35B50 8005A750 0C00B458 */  jal       func_8002D160
/* 35B54 8005A754 A0800084 */   sb       $zero, 0x84($a0)
/* 35B58 8005A758 0C0AC81E */  jal       func_802B2078
/* 35B5C 8005A75C 00108400 */   sll      $s0, $s0, 0x10
/* 35B60 8005A760 0C047624 */  jal       func_8011D890
/* 35B64 8005A764 00108403 */   sra      $s0, $s0, 0x10
/* 35B68 8005A768 0C048C2E */  jal       clear_dynamic_entity_list
/* 35B6C 8005A76C 00000000 */   nop
/* 35B70 8005A770 0C0B0C77 */  jal       clear_script_list
/* 35B74 8005A774 00000000 */   nop
/* 35B78 8005A778 12000005 */  beqz      $s0, .L8005A790
/* 35B7C 8005A77C 24020001 */   addiu    $v0, $zero, 1
/* 35B80 8005A780 12020008 */  beq       $s0, $v0, .L8005A7A4
/* 35B84 8005A784 00000000 */   nop
/* 35B88 8005A788 080169F0 */  j         .L8005A7C0
/* 35B8C 8005A78C 00000000 */   nop
.L8005A790:
/* 35B90 8005A790 0C0514E4 */  jal       clear_area_flags
/* 35B94 8005A794 00000000 */   nop
/* 35B98 8005A798 8E420000 */  lw        $v0, ($s2)
/* 35B9C 8005A79C 080169F0 */  j         .L8005A7C0
/* 35BA0 8005A7A0 A0400167 */   sb       $zero, 0x167($v0)
.L8005A7A4:
/* 35BA4 8005A7A4 0C00AD24 */  jal       fio_deserialize_state
/* 35BA8 8005A7A8 00000000 */   nop
/* 35BAC 8005A7AC 8E420000 */  lw        $v0, ($s2)
/* 35BB0 8005A7B0 94510086 */  lhu       $s1, 0x86($v0)
/* 35BB4 8005A7B4 9453008C */  lhu       $s3, 0x8c($v0)
/* 35BB8 8005A7B8 A0500167 */  sb        $s0, 0x167($v0)
/* 35BBC 8005A7BC A4510088 */  sh        $s1, 0x88($v0)
.L8005A7C0:
/* 35BC0 8005A7C0 3C04800E */  lui       $a0, %hi(D_800D9230)
/* 35BC4 8005A7C4 24849230 */  addiu     $a0, $a0, %lo(D_800D9230)
/* 35BC8 8005A7C8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 35BCC 8005A7CC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 35BD0 8005A7D0 00131C00 */  sll       $v1, $s3, 0x10
/* 35BD4 8005A7D4 AC400144 */  sw        $zero, 0x144($v0)
/* 35BD8 8005A7D8 00111400 */  sll       $v0, $s1, 0x10
/* 35BDC 8005A7DC 00021303 */  sra       $v0, $v0, 0xc
/* 35BE0 8005A7E0 3C018009 */  lui       $at, %hi(gAreas+0x4)
/* 35BE4 8005A7E4 00220821 */  addu      $at, $at, $v0
/* 35BE8 8005A7E8 8C2234F4 */  lw        $v0, %lo(gAreas+0x4)($at)
/* 35BEC 8005A7EC 00031AC3 */  sra       $v1, $v1, 0xb
/* 35BF0 8005A7F0 00439021 */  addu      $s2, $v0, $v1
/* 35BF4 8005A7F4 8E460000 */  lw        $a2, ($s2)
/* 35BF8 8005A7F8 3C05800A */  lui       $a1, %hi(D_80098A10)
/* 35BFC 8005A7FC 0C01953C */  jal       sprintf
/* 35C00 8005A800 24A58A10 */   addiu    $a1, $a1, %lo(D_80098A10)
/* 35C04 8005A804 3C04800E */  lui       $a0, %hi(D_800D91E0)
/* 35C08 8005A808 248491E0 */  addiu     $a0, $a0, %lo(D_800D91E0)
/* 35C0C 8005A80C 8E460000 */  lw        $a2, ($s2)
/* 35C10 8005A810 3C05800A */  lui       $a1, %hi(D_80098A1C)
/* 35C14 8005A814 0C01953C */  jal       sprintf
/* 35C18 8005A818 24A58A1C */   addiu    $a1, $a1, %lo(D_80098A1C)
/* 35C1C 8005A81C 8E450000 */  lw        $a1, ($s2)
/* 35C20 8005A820 0C01BB50 */  jal       strcpy
/* 35C24 8005A824 27A40018 */   addiu    $a0, $sp, 0x18
/* 35C28 8005A828 3C04800B */  lui       $a0, %hi(D_800B0CF0)
/* 35C2C 8005A82C 24840CF0 */  addiu     $a0, $a0, %lo(D_800B0CF0)
/* 35C30 8005A830 3C05800A */  lui       $a1, %hi(D_80098A24)
/* 35C34 8005A834 24A58A24 */  addiu     $a1, $a1, %lo(D_80098A24)
/* 35C38 8005A838 27A60018 */  addiu     $a2, $sp, 0x18
/* 35C3C 8005A83C 0C01953C */  jal       sprintf
/* 35C40 8005A840 A3A0001B */   sb       $zero, 0x1b($sp)
/* 35C44 8005A844 8E450014 */  lw        $a1, 0x14($s2)
/* 35C48 8005A848 3C01800A */  lui       $at, %hi(D_800A41E0)
/* 35C4C 8005A84C AC3241E0 */  sw        $s2, %lo(D_800A41E0)($at)
/* 35C50 8005A850 10A00005 */  beqz      $a1, .L8005A868
/* 35C54 8005A854 00000000 */   nop
/* 35C58 8005A858 3C04800E */  lui       $a0, %hi(D_800D9668)
/* 35C5C 8005A85C 24849668 */  addiu     $a0, $a0, %lo(D_800D9668)
/* 35C60 8005A860 0C01BB50 */  jal       strcpy
/* 35C64 8005A864 00000000 */   nop
.L8005A868:
/* 35C68 8005A868 0C0169B0 */  jal       load_world_script_api
/* 35C6C 8005A86C 00000000 */   nop
/* 35C70 8005A870 8E440008 */  lw        $a0, 8($s2)
/* 35C74 8005A874 10800004 */  beqz      $a0, .L8005A888
/* 35C78 8005A878 00000000 */   nop
/* 35C7C 8005A87C 8E45000C */  lw        $a1, 0xc($s2)
/* 35C80 8005A880 0C00A5CF */  jal       dma_copy
/* 35C84 8005A884 8E460010 */   lw       $a2, 0x10($s2)
.L8005A888:
/* 35C88 8005A888 8E420004 */  lw        $v0, 4($s2)
/* 35C8C 8005A88C 3C03800A */  lui       $v1, %hi(D_800A41E8)
/* 35C90 8005A890 246341E8 */  addiu     $v1, $v1, %lo(D_800A41E8)
/* 35C94 8005A894 24440040 */  addiu     $a0, $v0, 0x40
.L8005A898:
/* 35C98 8005A898 8C480000 */  lw        $t0, ($v0)
/* 35C9C 8005A89C 8C490004 */  lw        $t1, 4($v0)
/* 35CA0 8005A8A0 8C4A0008 */  lw        $t2, 8($v0)
/* 35CA4 8005A8A4 8C4B000C */  lw        $t3, 0xc($v0)
/* 35CA8 8005A8A8 AC680000 */  sw        $t0, ($v1)
/* 35CAC 8005A8AC AC690004 */  sw        $t1, 4($v1)
/* 35CB0 8005A8B0 AC6A0008 */  sw        $t2, 8($v1)
/* 35CB4 8005A8B4 AC6B000C */  sw        $t3, 0xc($v1)
/* 35CB8 8005A8B8 24420010 */  addiu     $v0, $v0, 0x10
/* 35CBC 8005A8BC 1444FFF6 */  bne       $v0, $a0, .L8005A898
/* 35CC0 8005A8C0 24630010 */   addiu    $v1, $v1, 0x10
/* 35CC4 8005A8C4 8E420018 */  lw        $v0, 0x18($s2)
/* 35CC8 8005A8C8 3C13800A */  lui       $s3, %hi(D_800A41E8)
/* 35CCC 8005A8CC 267341E8 */  addiu     $s3, $s3, %lo(D_800A41E8)
/* 35CD0 8005A8D0 10400004 */  beqz      $v0, .L8005A8E4
/* 35CD4 8005A8D4 00000000 */   nop
/* 35CD8 8005A8D8 0040F809 */  jalr      $v0
/* 35CDC 8005A8DC 00000000 */   nop
/* 35CE0 8005A8E0 0040A02D */  daddu     $s4, $v0, $zero
.L8005A8E4:
/* 35CE4 8005A8E4 16800015 */  bnez      $s4, .L8005A93C
/* 35CE8 8005A8E8 00000000 */   nop
/* 35CEC 8005A8EC 3C04800E */  lui       $a0, %hi(D_800D9230)
/* 35CF0 8005A8F0 24849230 */  addiu     $a0, $a0, %lo(D_800D9230)
/* 35CF4 8005A8F4 0C016B3A */  jal       load_asset_by_name
/* 35CF8 8005A8F8 27A50030 */   addiu    $a1, $sp, 0x30
/* 35CFC 8005A8FC 0040882D */  daddu     $s1, $v0, $zero
/* 35D00 8005A900 0220202D */  daddu     $a0, $s1, $zero
/* 35D04 8005A904 3C108021 */  lui       $s0, %hi(D_80210000)
/* 35D08 8005A908 26100000 */  addiu     $s0, $s0, %lo(D_80210000)
/* 35D0C 8005A90C 0C01BB7C */  jal       decode_yay0
/* 35D10 8005A910 0200282D */   daddu    $a1, $s0, $zero
/* 35D14 8005A914 0C00AB1E */  jal       general_heap_free
/* 35D18 8005A918 0220202D */   daddu    $a0, $s1, $zero
/* 35D1C 8005A91C 8E020000 */  lw        $v0, ($s0)
/* 35D20 8005A920 8E030008 */  lw        $v1, 8($s0)
/* 35D24 8005A924 8E04000C */  lw        $a0, 0xc($s0)
/* 35D28 8005A928 8E050010 */  lw        $a1, 0x10($s0)
/* 35D2C 8005A92C AE620000 */  sw        $v0, ($s3)
/* 35D30 8005A930 AE630028 */  sw        $v1, 0x28($s3)
/* 35D34 8005A934 AE64002C */  sw        $a0, 0x2c($s3)
/* 35D38 8005A938 AE650030 */  sw        $a1, 0x30($s3)
.L8005A93C:
/* 35D3C 8005A93C 8E420014 */  lw        $v0, 0x14($s2)
/* 35D40 8005A940 10400005 */  beqz      $v0, .L8005A958
/* 35D44 8005A944 00000000 */   nop
/* 35D48 8005A948 3C04800E */  lui       $a0, %hi(D_800D9668)
/* 35D4C 8005A94C 24849668 */  addiu     $a0, $a0, %lo(D_800D9668)
/* 35D50 8005A950 0C05175C */  jal       load_map_bg
/* 35D54 8005A954 00000000 */   nop
.L8005A958:
/* 35D58 8005A958 0C00B458 */  jal       func_8002D160
/* 35D5C 8005A95C 00000000 */   nop
/* 35D60 8005A960 0C0AC81E */  jal       func_802B2078
/* 35D64 8005A964 00000000 */   nop
/* 35D68 8005A968 0C05259C */  jal       func_80149670
/* 35D6C 8005A96C 0000202D */   daddu    $a0, $zero, $zero
/* 35D70 8005A970 0C048C2E */  jal       clear_dynamic_entity_list
/* 35D74 8005A974 00000000 */   nop
/* 35D78 8005A978 0C0B0C77 */  jal       clear_script_list
/* 35D7C 8005A97C 00000000 */   nop
/* 35D80 8005A980 0C00B7BD */  jal       create_cameras_a
/* 35D84 8005A984 00000000 */   nop
/* 35D88 8005A988 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 35D8C 8005A98C 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 35D90 8005A990 8E020000 */  lw        $v0, ($s0)
/* 35D94 8005A994 0C0B763E */  jal       func_802DD8F8
/* 35D98 8005A998 80440084 */   lb       $a0, 0x84($v0)
/* 35D9C 8005A99C 0C047889 */  jal       func_8011E224
/* 35DA0 8005A9A0 00000000 */   nop
/* 35DA4 8005A9A4 0C0482EC */  jal       clear_entity_models
/* 35DA8 8005A9A8 00000000 */   nop
/* 35DAC 8005A9AC 0C00E12F */  jal       clear_npcs
/* 35DB0 8005A9B0 00000000 */   nop
/* 35DB4 8005A9B4 0C050440 */  jal       func_80141100
/* 35DB8 8005A9B8 00000000 */   nop
/* 35DBC 8005A9BC 0C0515A0 */  jal       clear_trigger_data
/* 35DC0 8005A9C0 00000000 */   nop
/* 35DC4 8005A9C4 0C045751 */  jal       clear_model_data
/* 35DC8 8005A9C8 00000000 */   nop
/* 35DCC 8005A9CC 0C052010 */  jal       func_80148040
/* 35DD0 8005A9D0 00000000 */   nop
/* 35DD4 8005A9D4 0C05177E */  jal       func_80145DF8
/* 35DD8 8005A9D8 00000000 */   nop
/* 35DDC 8005A9DC 8E020000 */  lw        $v0, ($s0)
/* 35DE0 8005A9E0 804300A8 */  lb        $v1, 0xa8($v0)
/* 35DE4 8005A9E4 2402FFFF */  addiu     $v0, $zero, -1
/* 35DE8 8005A9E8 14620003 */  bne       $v1, $v0, .L8005A9F8
/* 35DEC 8005A9EC 00000000 */   nop
/* 35DF0 8005A9F0 0C04E062 */  jal       func_80138188
/* 35DF4 8005A9F4 00000000 */   nop
.L8005A9F8:
/* 35DF8 8005A9F8 16800005 */  bnez      $s4, .L8005AA10
/* 35DFC 8005A9FC 00000000 */   nop
/* 35E00 8005AA00 0C016BE5 */  jal       initialize_collision
/* 35E04 8005AA04 00000000 */   nop
/* 35E08 8005AA08 0C016BF0 */  jal       load_hit_asset
/* 35E0C 8005AA0C 00000000 */   nop
.L8005AA10:
/* 35E10 8005AA10 0C01CACC */  jal       func_80072B30
/* 35E14 8005AA14 00000000 */   nop
/* 35E18 8005AA18 0C00F900 */  jal       clear_encounter_status
/* 35E1C 8005AA1C 00000000 */   nop
/* 35E20 8005AA20 0C04432E */  jal       clear_entity_data
/* 35E24 8005AA24 24040001 */   addiu    $a0, $zero, 1
/* 35E28 8005AA28 0C016727 */  jal       func_80059C9C
/* 35E2C 8005AA2C 00000000 */   nop
/* 35E30 8005AA30 0C037F14 */  jal       clear_player_status
/* 35E34 8005AA34 00000000 */   nop
/* 35E38 8005AA38 0C037F1D */  jal       func_800DFC74
/* 35E3C 8005AA3C 00000000 */   nop
/* 35E40 8005AA40 0C03AD1D */  jal       partner_reset_data
/* 35E44 8005AA44 00000000 */   nop
/* 35E48 8005AA48 0C048D9D */  jal       clear_printers
/* 35E4C 8005AA4C 00000000 */   nop
/* 35E50 8005AA50 0C04C3FC */  jal       clear_item_entity_data
/* 35E54 8005AA54 00000000 */   nop
/* 35E58 8005AA58 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 35E5C 8005AA5C 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 35E60 8005AA60 C4400084 */  lwc1      $f0, 0x84($v0)
/* 35E64 8005AA64 E4400080 */  swc1      $f0, 0x80($v0)
/* 35E68 8005AA68 8E42001C */  lw        $v0, 0x1c($s2)
/* 35E6C 8005AA6C 30420003 */  andi      $v0, $v0, 3
/* 35E70 8005AA70 00021080 */  sll       $v0, $v0, 2
/* 35E74 8005AA74 3C048009 */  lui       $a0, %hi(D_8008FF60)
/* 35E78 8005AA78 00822021 */  addu      $a0, $a0, $v0
/* 35E7C 8005AA7C 0C0525FF */  jal       func_801497FC
/* 35E80 8005AA80 8C84FF60 */   lw       $a0, %lo(D_8008FF60)($a0)
/* 35E84 8005AA84 0C052580 */  jal       func_80149600
/* 35E88 8005AA88 00000000 */   nop
/* 35E8C 8005AA8C 1680000B */  bnez      $s4, .L8005AABC
/* 35E90 8005AA90 00000000 */   nop
/* 35E94 8005AA94 3C04800B */  lui       $a0, %hi(D_800B0CF0)
/* 35E98 8005AA98 24840CF0 */  addiu     $a0, $a0, %lo(D_800B0CF0)
/* 35E9C 8005AA9C 0C016B74 */  jal       get_asset_offset
/* 35EA0 8005AAA0 27A50030 */   addiu    $a1, $sp, 0x30
/* 35EA4 8005AAA4 8E640000 */  lw        $a0, ($s3)
/* 35EA8 8005AAA8 10800004 */  beqz      $a0, .L8005AABC
/* 35EAC 8005AAAC 00000000 */   nop
/* 35EB0 8005AAB0 8FA60030 */  lw        $a2, 0x30($sp)
/* 35EB4 8005AAB4 0C046B52 */  jal       load_data_for_models
/* 35EB8 8005AAB8 0040282D */   daddu    $a1, $v0, $zero
.L8005AABC:
/* 35EBC 8005AABC 8E640038 */  lw        $a0, 0x38($s3)
/* 35EC0 8005AAC0 50800005 */  beql      $a0, $zero, .L8005AAD8
/* 35EC4 8005AAC4 24040128 */   addiu    $a0, $zero, 0x128
/* 35EC8 8005AAC8 0C05178A */  jal       read_background_size
/* 35ECC 8005AACC 00000000 */   nop
/* 35ED0 8005AAD0 08016ABA */  j         .L8005AAE8
/* 35ED4 8005AAD4 00000000 */   nop
.L8005AAD8:
/* 35ED8 8005AAD8 240500C8 */  addiu     $a1, $zero, 0xc8
/* 35EDC 8005AADC 2406000C */  addiu     $a2, $zero, 0xc
/* 35EE0 8005AAE0 0C05179C */  jal       set_background_size
/* 35EE4 8005AAE4 24070014 */   addiu    $a3, $zero, 0x14
.L8005AAE8:
/* 35EE8 8005AAE8 3C04800B */  lui       $a0, %hi(gCameras)
/* 35EEC 8005AAEC 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 35EF0 8005AAF0 94820000 */  lhu       $v0, ($a0)
/* 35EF4 8005AAF4 94830AB0 */  lhu       $v1, 0xab0($a0)
/* 35EF8 8005AAF8 3C018007 */  lui       $at, %hi(gCurrentCameraID)
/* 35EFC 8005AAFC AC207410 */  sw        $zero, %lo(gCurrentCameraID)($at)
/* 35F00 8005AB00 34420002 */  ori       $v0, $v0, 2
/* 35F04 8005AB04 A4820000 */  sh        $v0, ($a0)
/* 35F08 8005AB08 94820558 */  lhu       $v0, 0x558($a0)
/* 35F0C 8005AB0C 34630002 */  ori       $v1, $v1, 2
/* 35F10 8005AB10 A4830AB0 */  sh        $v1, 0xab0($a0)
/* 35F14 8005AB14 34420002 */  ori       $v0, $v0, 2
/* 35F18 8005AB18 A4820558 */  sh        $v0, 0x558($a0)
/* 35F1C 8005AB1C 94821008 */  lhu       $v0, 0x1008($a0)
/* 35F20 8005AB20 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 35F24 8005AB24 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 35F28 8005AB28 34420002 */  ori       $v0, $v0, 2
/* 35F2C 8005AB2C A4821008 */  sh        $v0, 0x1008($a0)
/* 35F30 8005AB30 806300A8 */  lb        $v1, 0xa8($v1)
/* 35F34 8005AB34 2402FFFF */  addiu     $v0, $zero, -1
/* 35F38 8005AB38 14620008 */  bne       $v1, $v0, .L8005AB5C
/* 35F3C 8005AB3C 240200A2 */   addiu    $v0, $zero, 0xa2
/* 35F40 8005AB40 240200C8 */  addiu     $v0, $zero, 0xc8
/* 35F44 8005AB44 AFA20010 */  sw        $v0, 0x10($sp)
/* 35F48 8005AB48 0000202D */  daddu     $a0, $zero, $zero
/* 35F4C 8005AB4C 2405000C */  addiu     $a1, $zero, 0xc
/* 35F50 8005AB50 24060014 */  addiu     $a2, $zero, 0x14
/* 35F54 8005AB54 08016ADC */  j         .L8005AB70
/* 35F58 8005AB58 24070128 */   addiu    $a3, $zero, 0x128
.L8005AB5C:
/* 35F5C 8005AB5C AFA20010 */  sw        $v0, 0x10($sp)
/* 35F60 8005AB60 0000202D */  daddu     $a0, $zero, $zero
/* 35F64 8005AB64 2405001D */  addiu     $a1, $zero, 0x1d
/* 35F68 8005AB68 2406001C */  addiu     $a2, $zero, 0x1c
/* 35F6C 8005AB6C 24070106 */  addiu     $a3, $zero, 0x106
.L8005AB70:
/* 35F70 8005AB70 0C00B8C5 */  jal       set_cam_viewport
/* 35F74 8005AB74 00000000 */   nop
/* 35F78 8005AB78 0C039E4D */  jal       initialize_status_menu
/* 35F7C 8005AB7C 00000000 */   nop
/* 35F80 8005AB80 0000282D */  daddu     $a1, $zero, $zero
/* 35F84 8005AB84 00A0302D */  daddu     $a2, $a1, $zero
/* 35F88 8005AB88 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 35F8C 8005AB8C 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 35F90 8005AB90 8E030000 */  lw        $v1, ($s0)
/* 35F94 8005AB94 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 35F98 8005AB98 A4620090 */  sh        $v0, 0x90($v1)
/* 35F9C 8005AB9C A4620092 */  sh        $v0, 0x92($v1)
/* 35FA0 8005ABA0 8E640010 */  lw        $a0, 0x10($s3)
/* 35FA4 8005ABA4 0C0B0D74 */  jal       start_script_in_group
/* 35FA8 8005ABA8 00A0382D */   daddu    $a3, $a1, $zero
/* 35FAC 8005ABAC 8E030000 */  lw        $v1, ($s0)
/* 35FB0 8005ABB0 8C420144 */  lw        $v0, 0x144($v0)
/* 35FB4 8005ABB4 AC62006C */  sw        $v0, 0x6c($v1)
/* 35FB8 8005ABB8 8FBF004C */  lw        $ra, 0x4c($sp)
/* 35FBC 8005ABBC 8FB40048 */  lw        $s4, 0x48($sp)
/* 35FC0 8005ABC0 8FB30044 */  lw        $s3, 0x44($sp)
/* 35FC4 8005ABC4 8FB20040 */  lw        $s2, 0x40($sp)
/* 35FC8 8005ABC8 8FB1003C */  lw        $s1, 0x3c($sp)
/* 35FCC 8005ABCC 8FB00038 */  lw        $s0, 0x38($sp)
/* 35FD0 8005ABD0 03E00008 */  jr        $ra
/* 35FD4 8005ABD4 27BD0050 */   addiu    $sp, $sp, 0x50
