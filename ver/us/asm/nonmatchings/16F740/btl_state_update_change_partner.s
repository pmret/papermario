.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_8029CAD0
.word .L8024574C_17402C, .L80245AAC_17438C, .L80245828_174108, .L8024589C_17417C, .L80245938_174218, .L80245994_174274, .L80245A00_1742E0, .L80245A44_174324

.section .text

glabel btl_state_update_change_partner
/* 173FD8 802456F8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 173FDC 802456FC AFB20018 */  sw        $s2, 0x18($sp)
/* 173FE0 80245700 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 173FE4 80245704 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 173FE8 80245708 AFBF0020 */  sw        $ra, 0x20($sp)
/* 173FEC 8024570C AFB3001C */  sw        $s3, 0x1c($sp)
/* 173FF0 80245710 AFB10014 */  sw        $s1, 0x14($sp)
/* 173FF4 80245714 AFB00010 */  sw        $s0, 0x10($sp)
/* 173FF8 80245718 8E5000D8 */  lw        $s0, 0xd8($s2)
/* 173FFC 8024571C 8E5100DC */  lw        $s1, 0xdc($s2)
/* 174000 80245720 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 174004 80245724 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 174008 80245728 2C620008 */  sltiu     $v0, $v1, 8
/* 17400C 8024572C 104000DF */  beqz      $v0, .L80245AAC_17438C
/* 174010 80245730 2613000C */   addiu    $s3, $s0, 0xc
/* 174014 80245734 00031080 */  sll       $v0, $v1, 2
/* 174018 80245738 3C01802A */  lui       $at, %hi(jtbl_8029CAD0)
/* 17401C 8024573C 00220821 */  addu      $at, $at, $v0
/* 174020 80245740 8C22CAD0 */  lw        $v0, %lo(jtbl_8029CAD0)($at)
/* 174024 80245744 00400008 */  jr        $v0
/* 174028 80245748 00000000 */   nop
.L8024574C_17402C:
/* 17402C 8024574C 3C03F7FF */  lui       $v1, 0xf7ff
/* 174030 80245750 8E020000 */  lw        $v0, ($s0)
/* 174034 80245754 3463FFFF */  ori       $v1, $v1, 0xffff
/* 174038 80245758 00431024 */  and       $v0, $v0, $v1
/* 17403C 8024575C AE020000 */  sw        $v0, ($s0)
/* 174040 80245760 8E220000 */  lw        $v0, ($s1)
/* 174044 80245764 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 174048 80245768 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 17404C 8024576C 00431024 */  and       $v0, $v0, $v1
/* 174050 80245770 AE220000 */  sw        $v0, ($s1)
/* 174054 80245774 8E020004 */  lw        $v0, 4($s0)
/* 174058 80245778 24040013 */  addiu     $a0, $zero, 0x13
/* 17405C 8024577C A240008C */  sb        $zero, 0x8c($s2)
/* 174060 80245780 34420010 */  ori       $v0, $v0, 0x10
/* 174064 80245784 0C093903 */  jal       func_8024E40C
/* 174068 80245788 AE020004 */   sw       $v0, 4($s0)
/* 17406C 8024578C 3C06C2C6 */  lui       $a2, 0xc2c6
/* 174070 80245790 3C01C2B2 */  lui       $at, 0xc2b2
/* 174074 80245794 44816000 */  mtc1      $at, $f12
/* 174078 80245798 3C014220 */  lui       $at, 0x4220
/* 17407C 8024579C 44817000 */  mtc1      $at, $f14
/* 174080 802457A0 0C093948 */  jal       btl_cam_set_target_pos
/* 174084 802457A4 00000000 */   nop
/* 174088 802457A8 0C093965 */  jal       btl_cam_set_zoom
/* 17408C 802457AC 24040174 */   addiu    $a0, $zero, 0x174
/* 174090 802457B0 0C093978 */  jal       btl_cam_set_zoffset
/* 174094 802457B4 0000202D */   daddu    $a0, $zero, $zero
/* 174098 802457B8 0000282D */  daddu     $a1, $zero, $zero
/* 17409C 802457BC 3C07FFF7 */  lui       $a3, 0xfff7
/* 1740A0 802457C0 34E7FFFF */  ori       $a3, $a3, 0xffff
/* 1740A4 802457C4 3C06F7FF */  lui       $a2, 0xf7ff
/* 1740A8 802457C8 34C6FFFF */  ori       $a2, $a2, 0xffff
/* 1740AC 802457CC 0240202D */  daddu     $a0, $s2, $zero
/* 1740B0 802457D0 8E020000 */  lw        $v0, ($s0)
/* 1740B4 802457D4 2403FFFD */  addiu     $v1, $zero, -3
/* 1740B8 802457D8 00431024 */  and       $v0, $v0, $v1
/* 1740BC 802457DC AE020000 */  sw        $v0, ($s0)
.L802457E0:
/* 1740C0 802457E0 8C8300E0 */  lw        $v1, 0xe0($a0)
/* 1740C4 802457E4 10600005 */  beqz      $v1, .L802457FC
/* 1740C8 802457E8 24A50001 */   addiu    $a1, $a1, 1
/* 1740CC 802457EC 8C620000 */  lw        $v0, ($v1)
/* 1740D0 802457F0 00471024 */  and       $v0, $v0, $a3
/* 1740D4 802457F4 00461024 */  and       $v0, $v0, $a2
/* 1740D8 802457F8 AC620000 */  sw        $v0, ($v1)
.L802457FC:
/* 1740DC 802457FC 28A20018 */  slti      $v0, $a1, 0x18
/* 1740E0 80245800 1440FFF7 */  bnez      $v0, .L802457E0
/* 1740E4 80245804 24840004 */   addiu    $a0, $a0, 4
/* 1740E8 80245808 2402FFFF */  addiu     $v0, $zero, -1
/* 1740EC 8024580C A242005C */  sb        $v0, 0x5c($s2)
/* 1740F0 80245810 2402000A */  addiu     $v0, $zero, 0xa
/* 1740F4 80245814 3C01802A */  lui       $at, %hi(D_8029F248)
/* 1740F8 80245818 AC22F248 */  sw        $v0, %lo(D_8029F248)($at)
/* 1740FC 8024581C 24020002 */  addiu     $v0, $zero, 2
/* 174100 80245820 3C01800E */  lui       $at, %hi(gBattleState2)
/* 174104 80245824 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
.L80245828_174108:
/* 174108 80245828 3C03802A */  lui       $v1, %hi(D_8029F248)
/* 17410C 8024582C 2463F248 */  addiu     $v1, $v1, %lo(D_8029F248)
/* 174110 80245830 8C620000 */  lw        $v0, ($v1)
/* 174114 80245834 10400003 */  beqz      $v0, .L80245844
/* 174118 80245838 2442FFFF */   addiu    $v0, $v0, -1
/* 17411C 8024583C 080916AB */  j         .L80245AAC_17438C
/* 174120 80245840 AC620000 */   sw       $v0, ($v1)
.L80245844:
/* 174124 80245844 0C098EF2 */  jal       deduct_current_move_fp
/* 174128 80245848 00000000 */   nop
/* 17412C 8024584C 3C048028 */  lui       $a0, %hi(BtlPutPartnerAway)
/* 174130 80245850 24840A34 */  addiu     $a0, $a0, %lo(BtlPutPartnerAway)
/* 174134 80245854 2405000A */  addiu     $a1, $zero, 0xa
/* 174138 80245858 0C0B0CF8 */  jal       start_script
/* 17413C 8024585C 0000302D */   daddu    $a2, $zero, $zero
/* 174140 80245860 0040202D */  daddu     $a0, $v0, $zero
/* 174144 80245864 AE4400BC */  sw        $a0, 0xbc($s2)
/* 174148 80245868 8C820144 */  lw        $v0, 0x144($a0)
/* 17414C 8024586C AE4200C0 */  sw        $v0, 0xc0($s2)
/* 174150 80245870 24020100 */  addiu     $v0, $zero, 0x100
/* 174154 80245874 AC820148 */  sw        $v0, 0x148($a0)
/* 174158 80245878 C6200144 */  lwc1      $f0, 0x144($s1)
/* 17415C 8024587C AE60001C */  sw        $zero, 0x1c($s3)
/* 174160 80245880 E6600018 */  swc1      $f0, 0x18($s3)
/* 174164 80245884 C620014C */  lwc1      $f0, 0x14c($s1)
/* 174168 80245888 24020003 */  addiu     $v0, $zero, 3
/* 17416C 8024588C 3C01800E */  lui       $at, %hi(gBattleState2)
/* 174170 80245890 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 174174 80245894 080916AB */  j         .L80245AAC_17438C
/* 174178 80245898 E6600020 */   swc1     $f0, 0x20($s3)
.L8024589C_17417C:
/* 17417C 8024589C 8E4400C0 */  lw        $a0, 0xc0($s2)
/* 174180 802458A0 0C0B1059 */  jal       does_script_exist
/* 174184 802458A4 00000000 */   nop
/* 174188 802458A8 14400080 */  bnez      $v0, .L80245AAC_17438C
/* 17418C 802458AC 00000000 */   nop
/* 174190 802458B0 0C0902EF */  jal       btl_delete_actor
/* 174194 802458B4 0220202D */   daddu    $a0, $s1, $zero
/* 174198 802458B8 924301AC */  lbu       $v1, 0x1ac($s2)
/* 17419C 802458BC 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 1741A0 802458C0 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 1741A4 802458C4 0C0992DD */  jal       load_partner_actor
/* 1741A8 802458C8 A0430012 */   sb       $v1, 0x12($v0)
/* 1741AC 802458CC 8E5100DC */  lw        $s1, 0xdc($s2)
/* 1741B0 802458D0 3C013DCC */  lui       $at, 0x3dcc
/* 1741B4 802458D4 3421CCCD */  ori       $at, $at, 0xcccd
/* 1741B8 802458D8 44810000 */  mtc1      $at, $f0
/* 1741BC 802458DC 00000000 */  nop
/* 1741C0 802458E0 E6200170 */  swc1      $f0, 0x170($s1)
/* 1741C4 802458E4 E6200174 */  swc1      $f0, 0x174($s1)
/* 1741C8 802458E8 E6200178 */  swc1      $f0, 0x178($s1)
/* 1741CC 802458EC C6600018 */  lwc1      $f0, 0x18($s3)
/* 1741D0 802458F0 C6220148 */  lwc1      $f2, 0x148($s1)
/* 1741D4 802458F4 E6200018 */  swc1      $f0, 0x18($s1)
/* 1741D8 802458F8 E622001C */  swc1      $f2, 0x1c($s1)
/* 1741DC 802458FC C6600020 */  lwc1      $f0, 0x20($s3)
/* 1741E0 80245900 3C0141C8 */  lui       $at, 0x41c8
/* 1741E4 80245904 44811000 */  mtc1      $at, $f2
/* 1741E8 80245908 E6200020 */  swc1      $f0, 0x20($s1)
/* 1741EC 8024590C C6000144 */  lwc1      $f0, 0x144($s0)
/* 1741F0 80245910 E6200144 */  swc1      $f0, 0x144($s1)
/* 1741F4 80245914 C6000148 */  lwc1      $f0, 0x148($s0)
/* 1741F8 80245918 46020000 */  add.s     $f0, $f0, $f2
/* 1741FC 8024591C E6200148 */  swc1      $f0, 0x148($s1)
/* 174200 80245920 C600014C */  lwc1      $f0, 0x14c($s0)
/* 174204 80245924 24020004 */  addiu     $v0, $zero, 4
/* 174208 80245928 3C01800E */  lui       $at, %hi(gBattleState2)
/* 17420C 8024592C AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 174210 80245930 080916AB */  j         .L80245AAC_17438C
/* 174214 80245934 E620014C */   swc1     $f0, 0x14c($s1)
.L80245938_174218:
/* 174218 80245938 8E5100DC */  lw        $s1, 0xdc($s2)
/* 17421C 8024593C 12200006 */  beqz      $s1, .L80245958
/* 174220 80245940 00000000 */   nop
/* 174224 80245944 0C0B1059 */  jal       does_script_exist
/* 174228 80245948 8E2401E4 */   lw       $a0, 0x1e4($s1)
/* 17422C 8024594C 14400057 */  bnez      $v0, .L80245AAC_17438C
/* 174230 80245950 00000000 */   nop
/* 174234 80245954 AE2001D4 */  sw        $zero, 0x1d4($s1)
.L80245958:
/* 174238 80245958 3C048028 */  lui       $a0, %hi(BtlBringPartnerOut)
/* 17423C 8024595C 24840B6C */  addiu     $a0, $a0, %lo(BtlBringPartnerOut)
/* 174240 80245960 2405000A */  addiu     $a1, $zero, 0xa
/* 174244 80245964 0C0B0CF8 */  jal       start_script
/* 174248 80245968 0000302D */   daddu    $a2, $zero, $zero
/* 17424C 8024596C 0040202D */  daddu     $a0, $v0, $zero
/* 174250 80245970 AE4400BC */  sw        $a0, 0xbc($s2)
/* 174254 80245974 8C820144 */  lw        $v0, 0x144($a0)
/* 174258 80245978 24030005 */  addiu     $v1, $zero, 5
/* 17425C 8024597C 3C01800E */  lui       $at, %hi(gBattleState2)
/* 174260 80245980 AC23C4DC */  sw        $v1, %lo(gBattleState2)($at)
/* 174264 80245984 AE4200C0 */  sw        $v0, 0xc0($s2)
/* 174268 80245988 24020100 */  addiu     $v0, $zero, 0x100
/* 17426C 8024598C 080916AB */  j         .L80245AAC_17438C
/* 174270 80245990 AC820148 */   sw       $v0, 0x148($a0)
.L80245994_174274:
/* 174274 80245994 8E4400C0 */  lw        $a0, 0xc0($s2)
/* 174278 80245998 0C0B1059 */  jal       does_script_exist
/* 17427C 8024599C 00000000 */   nop
/* 174280 802459A0 14400042 */  bnez      $v0, .L80245AAC_17438C
/* 174284 802459A4 00000000 */   nop
/* 174288 802459A8 8E5100DC */  lw        $s1, 0xdc($s2)
/* 17428C 802459AC 12200010 */  beqz      $s1, .L802459F0
/* 174290 802459B0 24020006 */   addiu    $v0, $zero, 6
/* 174294 802459B4 8E2201CC */  lw        $v0, 0x1cc($s1)
/* 174298 802459B8 1040000C */  beqz      $v0, .L802459EC
/* 17429C 802459BC 2405000A */   addiu    $a1, $zero, 0xa
/* 1742A0 802459C0 00A0102D */  daddu     $v0, $a1, $zero
/* 1742A4 802459C4 A24201A7 */  sb        $v0, 0x1a7($s2)
/* 1742A8 802459C8 8E2401CC */  lw        $a0, 0x1cc($s1)
/* 1742AC 802459CC 0C0B0CF8 */  jal       start_script
/* 1742B0 802459D0 0000302D */   daddu    $a2, $zero, $zero
/* 1742B4 802459D4 0040202D */  daddu     $a0, $v0, $zero
/* 1742B8 802459D8 AE2401DC */  sw        $a0, 0x1dc($s1)
/* 1742BC 802459DC 8C820144 */  lw        $v0, 0x144($a0)
/* 1742C0 802459E0 AE2201EC */  sw        $v0, 0x1ec($s1)
/* 1742C4 802459E4 24020100 */  addiu     $v0, $zero, 0x100
/* 1742C8 802459E8 AC820148 */  sw        $v0, 0x148($a0)
.L802459EC:
/* 1742CC 802459EC 24020006 */  addiu     $v0, $zero, 6
.L802459F0:
/* 1742D0 802459F0 3C01800E */  lui       $at, %hi(gBattleState2)
/* 1742D4 802459F4 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 1742D8 802459F8 080916AB */  j         .L80245AAC_17438C
/* 1742DC 802459FC 00000000 */   nop
.L80245A00_1742E0:
/* 1742E0 80245A00 8E5100DC */  lw        $s1, 0xdc($s2)
/* 1742E4 80245A04 12200008 */  beqz      $s1, .L80245A28
/* 1742E8 80245A08 00000000 */   nop
/* 1742EC 80245A0C 8E2201CC */  lw        $v0, 0x1cc($s1)
/* 1742F0 80245A10 10400005 */  beqz      $v0, .L80245A28
/* 1742F4 80245A14 00000000 */   nop
/* 1742F8 80245A18 0C0B1059 */  jal       does_script_exist
/* 1742FC 80245A1C 8E2401EC */   lw       $a0, 0x1ec($s1)
/* 174300 80245A20 14400022 */  bnez      $v0, .L80245AAC_17438C
/* 174304 80245A24 00000000 */   nop
.L80245A28:
/* 174308 80245A28 0C093903 */  jal       func_8024E40C
/* 17430C 80245A2C 24040002 */   addiu    $a0, $zero, 2
/* 174310 80245A30 24020007 */  addiu     $v0, $zero, 7
/* 174314 80245A34 3C01800E */  lui       $at, %hi(gBattleState2)
/* 174318 80245A38 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 17431C 80245A3C 080916AB */  j         .L80245AAC_17438C
/* 174320 80245A40 00000000 */   nop
.L80245A44_174324:
/* 174324 80245A44 8242008C */  lb        $v0, 0x8c($s2)
/* 174328 80245A48 14400018 */  bnez      $v0, .L80245AAC_17438C
/* 17432C 80245A4C 2403FFEF */   addiu    $v1, $zero, -0x11
/* 174330 80245A50 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 174334 80245A54 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 174338 80245A58 8C820004 */  lw        $v0, 4($a0)
/* 17433C 80245A5C 00431024 */  and       $v0, $v0, $v1
/* 174340 80245A60 AC820004 */  sw        $v0, 4($a0)
/* 174344 80245A64 8C820000 */  lw        $v0, ($a0)
/* 174348 80245A68 3C030008 */  lui       $v1, 8
/* 17434C 80245A6C 00431024 */  and       $v0, $v0, $v1
/* 174350 80245A70 14400007 */  bnez      $v0, .L80245A90
/* 174354 80245A74 0200202D */   daddu    $a0, $s0, $zero
/* 174358 80245A78 0C099CAB */  jal       player_team_is_ability_active
/* 17435C 80245A7C 2405001A */   addiu    $a1, $zero, 0x1a
/* 174360 80245A80 14400008 */  bnez      $v0, .L80245AA4
/* 174364 80245A84 2404000C */   addiu    $a0, $zero, 0xc
/* 174368 80245A88 080916A9 */  j         .L80245AA4
/* 17436C 80245A8C 24040016 */   addiu    $a0, $zero, 0x16
.L80245A90:
/* 174370 80245A90 0C099CAB */  jal       player_team_is_ability_active
/* 174374 80245A94 2405001A */   addiu    $a1, $zero, 0x1a
/* 174378 80245A98 10400002 */  beqz      $v0, .L80245AA4
/* 17437C 80245A9C 24040017 */   addiu    $a0, $zero, 0x17
/* 174380 80245AA0 2404000C */  addiu     $a0, $zero, 0xc
.L80245AA4:
/* 174384 80245AA4 0C090464 */  jal       btl_set_state
/* 174388 80245AA8 00000000 */   nop
.L80245AAC_17438C:
/* 17438C 80245AAC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 174390 80245AB0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 174394 80245AB4 8FB20018 */  lw        $s2, 0x18($sp)
/* 174398 80245AB8 8FB10014 */  lw        $s1, 0x14($sp)
/* 17439C 80245ABC 8FB00010 */  lw        $s0, 0x10($sp)
/* 1743A0 80245AC0 03E00008 */  jr        $ra
/* 1743A4 80245AC4 27BD0028 */   addiu    $sp, $sp, 0x28
