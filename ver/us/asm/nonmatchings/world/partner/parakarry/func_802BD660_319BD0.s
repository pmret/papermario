.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802BEB18_31B088
.word L802BDAF8_31A068, L802BE210_31A780, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE764_31ACD4, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BE78C_31ACFC, L802BD848_319DB8, L802BD904_319E74, 0

glabel D_802BEB98_31B108
.double 1.3

glabel D_802BEBA0_31B110
.double 0.1

glabel D_802BEBA8_31B118
.double 0.05

.section .text

glabel func_802BD660_319BD0
/* 319BD0 802BD660 3C02800B */  lui       $v0, %hi(gCurrentEncounter+0x8)
/* 319BD4 802BD664 80420F18 */  lb        $v0, %lo(gCurrentEncounter+0x8)($v0)
/* 319BD8 802BD668 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 319BDC 802BD66C AFB20040 */  sw        $s2, 0x40($sp)
/* 319BE0 802BD670 0080902D */  daddu     $s2, $a0, $zero
/* 319BE4 802BD674 AFB1003C */  sw        $s1, 0x3c($sp)
/* 319BE8 802BD678 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 319BEC 802BD67C 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 319BF0 802BD680 AFB70054 */  sw        $s7, 0x54($sp)
/* 319BF4 802BD684 3C178011 */  lui       $s7, %hi(D_8010EBB0)
/* 319BF8 802BD688 26F7EBB0 */  addiu     $s7, $s7, %lo(D_8010EBB0)
/* 319BFC 802BD68C AFBF005C */  sw        $ra, 0x5c($sp)
/* 319C00 802BD690 AFBE0058 */  sw        $fp, 0x58($sp)
/* 319C04 802BD694 AFB60050 */  sw        $s6, 0x50($sp)
/* 319C08 802BD698 AFB5004C */  sw        $s5, 0x4c($sp)
/* 319C0C 802BD69C AFB40048 */  sw        $s4, 0x48($sp)
/* 319C10 802BD6A0 AFB30044 */  sw        $s3, 0x44($sp)
/* 319C14 802BD6A4 AFB00038 */  sw        $s0, 0x38($sp)
/* 319C18 802BD6A8 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* 319C1C 802BD6AC F7B80070 */  sdc1      $f24, 0x70($sp)
/* 319C20 802BD6B0 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 319C24 802BD6B4 F7B40060 */  sdc1      $f20, 0x60($sp)
/* 319C28 802BD6B8 8E50014C */  lw        $s0, 0x14c($s2)
/* 319C2C 802BD6BC 14400475 */  bnez      $v0, .L802BE894
/* 319C30 802BD6C0 0000102D */   daddu    $v0, $zero, $zero
/* 319C34 802BD6C4 10A0002E */  beqz      $a1, .L802BD780
/* 319C38 802BD6C8 00000000 */   nop
/* 319C3C 802BD6CC 0C0AF545 */  jal       func_802BD514_319A84
/* 319C40 802BD6D0 0200202D */   daddu    $a0, $s0, $zero
/* 319C44 802BD6D4 8E220004 */  lw        $v0, 4($s1)
/* 319C48 802BD6D8 3C030010 */  lui       $v1, 0x10
/* 319C4C 802BD6DC 00431024 */  and       $v0, $v0, $v1
/* 319C50 802BD6E0 1440046C */  bnez      $v0, .L802BE894
/* 319C54 802BD6E4 24020002 */   addiu    $v0, $zero, 2
/* 319C58 802BD6E8 82E20001 */  lb        $v0, 1($s7)
/* 319C5C 802BD6EC 1440000B */  bnez      $v0, .L802BD71C
/* 319C60 802BD6F0 24040021 */   addiu    $a0, $zero, 0x21
/* 319C64 802BD6F4 0C03A94B */  jal       func_800EA52C
/* 319C68 802BD6F8 24040004 */   addiu    $a0, $zero, 4
/* 319C6C 802BD6FC 14400003 */  bnez      $v0, .L802BD70C
/* 319C70 802BD700 24020028 */   addiu    $v0, $zero, 0x28
.L802BD704:
/* 319C74 802BD704 080AFA25 */  j         .L802BE894
/* 319C78 802BD708 24020002 */   addiu    $v0, $zero, 2
.L802BD70C:
/* 319C7C 802BD70C 3C01802C */  lui       $at, %hi(D_802BEBC0_31CBE0)
/* 319C80 802BD710 AC22EBC0 */  sw        $v0, %lo(D_802BEBC0_31CBE0)($at)
/* 319C84 802BD714 080AF5DB */  j         .L802BD76C
/* 319C88 802BD718 00000000 */   nop
.L802BD71C:
/* 319C8C 802BD71C 0C039769 */  jal       set_action_state
/* 319C90 802BD720 A2E00001 */   sb       $zero, 1($s7)
/* 319C94 802BD724 3C050004 */  lui       $a1, 4
/* 319C98 802BD728 34A50009 */  ori       $a1, $a1, 9
/* 319C9C 802BD72C 8E020000 */  lw        $v0, ($s0)
/* 319CA0 802BD730 2403F5FF */  addiu     $v1, $zero, -0xa01
/* 319CA4 802BD734 00431024 */  and       $v0, $v0, $v1
/* 319CA8 802BD738 3C03800B */  lui       $v1, %hi(gCameras)
/* 319CAC 802BD73C 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 319CB0 802BD740 AE020000 */  sw        $v0, ($s0)
/* 319CB4 802BD744 94620002 */  lhu       $v0, 2($v1)
/* 319CB8 802BD748 24040001 */  addiu     $a0, $zero, 1
/* 319CBC 802BD74C 3C01802C */  lui       $at, %hi(D_802BEBB0)
/* 319CC0 802BD750 AC24EBB0 */  sw        $a0, %lo(D_802BEBB0)($at)
/* 319CC4 802BD754 00441025 */  or        $v0, $v0, $a0
/* 319CC8 802BD758 A4620002 */  sh        $v0, 2($v1)
/* 319CCC 802BD75C 24020004 */  addiu     $v0, $zero, 4
/* 319CD0 802BD760 AE050028 */  sw        $a1, 0x28($s0)
/* 319CD4 802BD764 A2E20003 */  sb        $v0, 3($s7)
/* 319CD8 802BD768 A2E40000 */  sb        $a0, ($s7)
.L802BD76C:
/* 319CDC 802BD76C 8E020000 */  lw        $v0, ($s0)
/* 319CE0 802BD770 2403BFFF */  addiu     $v1, $zero, -0x4001
/* 319CE4 802BD774 00431024 */  and       $v0, $v0, $v1
/* 319CE8 802BD778 34422000 */  ori       $v0, $v0, 0x2000
/* 319CEC 802BD77C AE020000 */  sw        $v0, ($s0)
.L802BD780:
/* 319CF0 802BD780 3C04802C */  lui       $a0, %hi(D_802BEBC0_31CBE0)
/* 319CF4 802BD784 2484EBC0 */  addiu     $a0, $a0, %lo(D_802BEBC0_31CBE0)
/* 319CF8 802BD788 8C830000 */  lw        $v1, ($a0)
/* 319CFC 802BD78C 24020028 */  addiu     $v0, $zero, 0x28
/* 319D00 802BD790 10620005 */  beq       $v1, $v0, .L802BD7A8
/* 319D04 802BD794 24020029 */   addiu    $v0, $zero, 0x29
/* 319D08 802BD798 1062000D */  beq       $v1, $v0, .L802BD7D0
/* 319D0C 802BD79C 00000000 */   nop
/* 319D10 802BD7A0 080AF607 */  j         .L802BD81C
/* 319D14 802BD7A4 00000000 */   nop
.L802BD7A8:
/* 319D18 802BD7A8 82220015 */  lb        $v0, 0x15($s1)
/* 319D1C 802BD7AC 14400439 */  bnez      $v0, .L802BE894
/* 319D20 802BD7B0 24020002 */   addiu    $v0, $zero, 2
/* 319D24 802BD7B4 24020003 */  addiu     $v0, $zero, 3
/* 319D28 802BD7B8 3C01802C */  lui       $at, %hi(D_802BEBC4)
/* 319D2C 802BD7BC AC22EBC4 */  sw        $v0, %lo(D_802BEBC4)($at)
/* 319D30 802BD7C0 82230015 */  lb        $v1, 0x15($s1)
/* 319D34 802BD7C4 24020029 */  addiu     $v0, $zero, 0x29
/* 319D38 802BD7C8 AC820000 */  sw        $v0, ($a0)
/* 319D3C 802BD7CC AE430078 */  sw        $v1, 0x78($s2)
.L802BD7D0:
/* 319D40 802BD7D0 3C03802C */  lui       $v1, %hi(D_802BEBC4)
/* 319D44 802BD7D4 2463EBC4 */  addiu     $v1, $v1, %lo(D_802BEBC4)
/* 319D48 802BD7D8 8C620000 */  lw        $v0, ($v1)
/* 319D4C 802BD7DC 1440000E */  bnez      $v0, .L802BD818
/* 319D50 802BD7E0 2442FFFF */   addiu    $v0, $v0, -1
/* 319D54 802BD7E4 82230015 */  lb        $v1, 0x15($s1)
/* 319D58 802BD7E8 8E420078 */  lw        $v0, 0x78($s2)
/* 319D5C 802BD7EC 0043102A */  slt       $v0, $v0, $v1
/* 319D60 802BD7F0 14400428 */  bnez      $v0, .L802BE894
/* 319D64 802BD7F4 24020002 */   addiu    $v0, $zero, 2
/* 319D68 802BD7F8 0C03A94B */  jal       func_800EA52C
/* 319D6C 802BD7FC 24040004 */   addiu    $a0, $zero, 4
/* 319D70 802BD800 1040FFC0 */  beqz      $v0, .L802BD704
/* 319D74 802BD804 2402001E */   addiu    $v0, $zero, 0x1e
/* 319D78 802BD808 3C01802C */  lui       $at, %hi(D_802BEBC0_31CBE0)
/* 319D7C 802BD80C AC22EBC0 */  sw        $v0, %lo(D_802BEBC0_31CBE0)($at)
/* 319D80 802BD810 080AF607 */  j         .L802BD81C
/* 319D84 802BD814 00000000 */   nop
.L802BD818:
/* 319D88 802BD818 AC620000 */  sw        $v0, ($v1)
.L802BD81C:
/* 319D8C 802BD81C 3C02802C */  lui       $v0, %hi(D_802BEBC0_31CBE0)
/* 319D90 802BD820 8C42EBC0 */  lw        $v0, %lo(D_802BEBC0_31CBE0)($v0)
/* 319D94 802BD824 2443FFFF */  addiu     $v1, $v0, -1
/* 319D98 802BD828 2C62001F */  sltiu     $v0, $v1, 0x1f
/* 319D9C 802BD82C 104003D7 */  beqz      $v0, L802BE78C_31ACFC
/* 319DA0 802BD830 00031080 */   sll      $v0, $v1, 2
/* 319DA4 802BD834 3C01802C */  lui       $at, %hi(jtbl_802BEB18_31B088)
/* 319DA8 802BD838 00220821 */  addu      $at, $at, $v0
/* 319DAC 802BD83C 8C22EB18 */  lw        $v0, %lo(jtbl_802BEB18_31B088)($at)
/* 319DB0 802BD840 00400008 */  jr        $v0
/* 319DB4 802BD844 00000000 */   nop
glabel L802BD848_319DB8
/* 319DB8 802BD848 0C039769 */  jal       set_action_state
/* 319DBC 802BD84C 24040021 */   addiu    $a0, $zero, 0x21
/* 319DC0 802BD850 0C03805E */  jal       disable_player_input
/* 319DC4 802BD854 00000000 */   nop
/* 319DC8 802BD858 0C038045 */  jal       disable_player_static_collisions
/* 319DCC 802BD85C 00000000 */   nop
/* 319DD0 802BD860 82220015 */  lb        $v0, 0x15($s1)
/* 319DD4 802BD864 3C03800B */  lui       $v1, %hi(gCameras)
/* 319DD8 802BD868 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 319DDC 802BD86C AE420078 */  sw        $v0, 0x78($s2)
/* 319DE0 802BD870 94620002 */  lhu       $v0, 2($v1)
/* 319DE4 802BD874 24040001 */  addiu     $a0, $zero, 1
/* 319DE8 802BD878 3C01802C */  lui       $at, %hi(D_802BEBB4)
/* 319DEC 802BD87C AC24EBB4 */  sw        $a0, %lo(D_802BEBB4)($at)
/* 319DF0 802BD880 3C01802C */  lui       $at, %hi(D_802BEBB8)
/* 319DF4 802BD884 AC24EBB8 */  sw        $a0, %lo(D_802BEBB8)($at)
/* 319DF8 802BD888 3C01802C */  lui       $at, %hi(D_802BEBB0)
/* 319DFC 802BD88C AC24EBB0 */  sw        $a0, %lo(D_802BEBB0)($at)
/* 319E00 802BD890 00441025 */  or        $v0, $v0, $a0
/* 319E04 802BD894 A4620002 */  sh        $v0, 2($v1)
/* 319E08 802BD898 8E020000 */  lw        $v0, ($s0)
/* 319E0C 802BD89C 2403F5FF */  addiu     $v1, $zero, -0xa01
/* 319E10 802BD8A0 00431024 */  and       $v0, $v0, $v1
/* 319E14 802BD8A4 34420048 */  ori       $v0, $v0, 0x48
/* 319E18 802BD8A8 AE020000 */  sw        $v0, ($s0)
/* 319E1C 802BD8AC 24020004 */  addiu     $v0, $zero, 4
/* 319E20 802BD8B0 A2E20003 */  sb        $v0, 3($s7)
/* 319E24 802BD8B4 0C03BD38 */  jal       func_800EF4E0
/* 319E28 802BD8B8 A2E40000 */   sb       $a0, ($s7)
/* 319E2C 802BD8BC 3C01802C */  lui       $at, %hi(D_802BEBBC)
/* 319E30 802BD8C0 AC22EBBC */  sw        $v0, %lo(D_802BEBBC)($at)
/* 319E34 802BD8C4 0C00EB49 */  jal       enable_npc_blur
/* 319E38 802BD8C8 0200202D */   daddu    $a0, $s0, $zero
/* 319E3C 802BD8CC C60C0038 */  lwc1      $f12, 0x38($s0)
/* 319E40 802BD8D0 8E260028 */  lw        $a2, 0x28($s1)
/* 319E44 802BD8D4 8E270030 */  lw        $a3, 0x30($s1)
/* 319E48 802BD8D8 0C00A720 */  jal       atan2
/* 319E4C 802BD8DC C60E0040 */   lwc1     $f14, 0x40($s0)
/* 319E50 802BD8E0 3C04802C */  lui       $a0, %hi(D_802BEBC0_31CBE0)
/* 319E54 802BD8E4 2484EBC0 */  addiu     $a0, $a0, %lo(D_802BEBC0_31CBE0)
/* 319E58 802BD8E8 E600000C */  swc1      $f0, 0xc($s0)
/* 319E5C 802BD8EC 8C820000 */  lw        $v0, ($a0)
/* 319E60 802BD8F0 24030004 */  addiu     $v1, $zero, 4
/* 319E64 802BD8F4 A603008E */  sh        $v1, 0x8e($s0)
/* 319E68 802BD8F8 24420001 */  addiu     $v0, $v0, 1
/* 319E6C 802BD8FC 080AF9E3 */  j         L802BE78C_31ACFC
/* 319E70 802BD900 AC820000 */   sw       $v0, ($a0)
glabel L802BD904_319E74
/* 319E74 802BD904 822300B4 */  lb        $v1, 0xb4($s1)
/* 319E78 802BD908 24020015 */  addiu     $v0, $zero, 0x15
/* 319E7C 802BD90C 10620009 */  beq       $v1, $v0, .L802BD934
/* 319E80 802BD910 24020017 */   addiu    $v0, $zero, 0x17
/* 319E84 802BD914 10620007 */  beq       $v1, $v0, .L802BD934
/* 319E88 802BD918 24020016 */   addiu    $v0, $zero, 0x16
/* 319E8C 802BD91C 10620005 */  beq       $v1, $v0, .L802BD934
/* 319E90 802BD920 24020003 */   addiu    $v0, $zero, 3
/* 319E94 802BD924 10620003 */  beq       $v1, $v0, .L802BD934
/* 319E98 802BD928 24020005 */   addiu    $v0, $zero, 5
/* 319E9C 802BD92C 14620005 */  bne       $v1, $v0, .L802BD944
/* 319EA0 802BD930 3C040001 */   lui      $a0, 1
.L802BD934:
/* 319EA4 802BD934 0C00EB6B */  jal       disable_npc_blur
/* 319EA8 802BD938 0200202D */   daddu    $a0, $s0, $zero
/* 319EAC 802BD93C 080AF9E1 */  j         .L802BE784
/* 319EB0 802BD940 24020015 */   addiu    $v0, $zero, 0x15
.L802BD944:
/* 319EB4 802BD944 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* 319EB8 802BD948 34840002 */   ori      $a0, $a0, 2
/* 319EBC 802BD94C C6200028 */  lwc1      $f0, 0x28($s1)
/* 319EC0 802BD950 3C014200 */  lui       $at, 0x4200
/* 319EC4 802BD954 44811000 */  mtc1      $at, $f2
/* 319EC8 802BD958 E6000060 */  swc1      $f0, 0x60($s0)
/* 319ECC 802BD95C C620002C */  lwc1      $f0, 0x2c($s1)
/* 319ED0 802BD960 3C020004 */  lui       $v0, 4
/* 319ED4 802BD964 46020000 */  add.s     $f0, $f0, $f2
/* 319ED8 802BD968 34420003 */  ori       $v0, $v0, 3
/* 319EDC 802BD96C 26040060 */  addiu     $a0, $s0, 0x60
/* 319EE0 802BD970 E6000064 */  swc1      $f0, 0x64($s0)
/* 319EE4 802BD974 C6200030 */  lwc1      $f0, 0x30($s1)
/* 319EE8 802BD978 26050068 */  addiu     $a1, $s0, 0x68
/* 319EEC 802BD97C AE020028 */  sw        $v0, 0x28($s0)
/* 319EF0 802BD980 E6000068 */  swc1      $f0, 0x68($s0)
/* 319EF4 802BD984 8E270080 */  lw        $a3, 0x80($s1)
/* 319EF8 802BD988 0C00A7E7 */  jal       add_vec2D_polar
/* 319EFC 802BD98C 0000302D */   daddu    $a2, $zero, $zero
/* 319F00 802BD990 3C02802C */  lui       $v0, %hi(D_802BEBBC)
/* 319F04 802BD994 8C42EBBC */  lw        $v0, %lo(D_802BEBBC)($v0)
/* 319F08 802BD998 C62C0080 */  lwc1      $f12, 0x80($s1)
/* 319F0C 802BD99C 3C01C2B4 */  lui       $at, 0xc2b4
/* 319F10 802BD9A0 44810000 */  mtc1      $at, $f0
/* 319F14 802BD9A4 14400003 */  bnez      $v0, .L802BD9B4
/* 319F18 802BD9A8 00000000 */   nop
/* 319F1C 802BD9AC 3C0142B4 */  lui       $at, 0x42b4
/* 319F20 802BD9B0 44810000 */  mtc1      $at, $f0
.L802BD9B4:
/* 319F24 802BD9B4 0C00A6C9 */  jal       clamp_angle
/* 319F28 802BD9B8 46006300 */   add.s    $f12, $f12, $f0
/* 319F2C 802BD9BC 26040060 */  addiu     $a0, $s0, 0x60
/* 319F30 802BD9C0 3C0640A0 */  lui       $a2, 0x40a0
/* 319F34 802BD9C4 44070000 */  mfc1      $a3, $f0
/* 319F38 802BD9C8 0C00A7E7 */  jal       add_vec2D_polar
/* 319F3C 802BD9CC 26050068 */   addiu    $a1, $s0, 0x68
/* 319F40 802BD9D0 C6000060 */  lwc1      $f0, 0x60($s0)
/* 319F44 802BD9D4 C60A0038 */  lwc1      $f10, 0x38($s0)
/* 319F48 802BD9D8 8602008E */  lh        $v0, 0x8e($s0)
/* 319F4C 802BD9DC C6040064 */  lwc1      $f4, 0x64($s0)
/* 319F50 802BD9E0 C608003C */  lwc1      $f8, 0x3c($s0)
/* 319F54 802BD9E4 C6060040 */  lwc1      $f6, 0x40($s0)
/* 319F58 802BD9E8 44821000 */  mtc1      $v0, $f2
/* 319F5C 802BD9EC 00000000 */  nop
/* 319F60 802BD9F0 468010A0 */  cvt.s.w   $f2, $f2
/* 319F64 802BD9F4 0040202D */  daddu     $a0, $v0, $zero
/* 319F68 802BD9F8 460A0001 */  sub.s     $f0, $f0, $f10
/* 319F6C 802BD9FC 0080182D */  daddu     $v1, $a0, $zero
/* 319F70 802BDA00 9602008E */  lhu       $v0, 0x8e($s0)
/* 319F74 802BDA04 46082101 */  sub.s     $f4, $f4, $f8
/* 319F78 802BDA08 2442FFFF */  addiu     $v0, $v0, -1
/* 319F7C 802BDA0C A602008E */  sh        $v0, 0x8e($s0)
/* 319F80 802BDA10 46020003 */  div.s     $f0, $f0, $f2
/* 319F84 802BDA14 46005280 */  add.s     $f10, $f10, $f0
/* 319F88 802BDA18 C6020068 */  lwc1      $f2, 0x68($s0)
/* 319F8C 802BDA1C 00021400 */  sll       $v0, $v0, 0x10
/* 319F90 802BDA20 46061081 */  sub.s     $f2, $f2, $f6
/* 319F94 802BDA24 44840000 */  mtc1      $a0, $f0
/* 319F98 802BDA28 00000000 */  nop
/* 319F9C 802BDA2C 46800020 */  cvt.s.w   $f0, $f0
/* 319FA0 802BDA30 46002103 */  div.s     $f4, $f4, $f0
/* 319FA4 802BDA34 46044200 */  add.s     $f8, $f8, $f4
/* 319FA8 802BDA38 44830000 */  mtc1      $v1, $f0
/* 319FAC 802BDA3C 00000000 */  nop
/* 319FB0 802BDA40 46800020 */  cvt.s.w   $f0, $f0
/* 319FB4 802BDA44 46001083 */  div.s     $f2, $f2, $f0
/* 319FB8 802BDA48 46023180 */  add.s     $f6, $f6, $f2
/* 319FBC 802BDA4C E60A0038 */  swc1      $f10, 0x38($s0)
/* 319FC0 802BDA50 E608003C */  swc1      $f8, 0x3c($s0)
/* 319FC4 802BDA54 1040000A */  beqz      $v0, .L802BDA80
/* 319FC8 802BDA58 E6060040 */   swc1     $f6, 0x40($s0)
/* 319FCC 802BDA5C 82230015 */  lb        $v1, 0x15($s1)
/* 319FD0 802BDA60 8E420078 */  lw        $v0, 0x78($s2)
/* 319FD4 802BDA64 0043102A */  slt       $v0, $v0, $v1
/* 319FD8 802BDA68 10400348 */  beqz      $v0, L802BE78C_31ACFC
/* 319FDC 802BDA6C 00000000 */   nop
/* 319FE0 802BDA70 0C00EB6B */  jal       disable_npc_blur
/* 319FE4 802BDA74 0200202D */   daddu    $a0, $s0, $zero
/* 319FE8 802BDA78 080AF9E1 */  j         .L802BE784
/* 319FEC 802BDA7C 24020016 */   addiu    $v0, $zero, 0x16
.L802BDA80:
/* 319FF0 802BDA80 0C00EB6B */  jal       disable_npc_blur
/* 319FF4 802BDA84 0200202D */   daddu    $a0, $s0, $zero
/* 319FF8 802BDA88 3C020004 */  lui       $v0, 4
/* 319FFC 802BDA8C 3442000A */  ori       $v0, $v0, 0xa
/* 31A000 802BDA90 3C040008 */  lui       $a0, 8
/* 31A004 802BDA94 C6200080 */  lwc1      $f0, 0x80($s1)
/* 31A008 802BDA98 3C013E4C */  lui       $at, 0x3e4c
/* 31A00C 802BDA9C 3421CCCD */  ori       $at, $at, 0xcccd
/* 31A010 802BDAA0 44811000 */  mtc1      $at, $f2
/* 31A014 802BDAA4 3484000D */  ori       $a0, $a0, 0xd
/* 31A018 802BDAA8 AE020028 */  sw        $v0, 0x28($s0)
/* 31A01C 802BDAAC AE000010 */  sw        $zero, 0x10($s0)
/* 31A020 802BDAB0 E600000C */  swc1      $f0, 0xc($s0)
/* 31A024 802BDAB4 0C037FDE */  jal       suggest_player_anim_setUnkFlag
/* 31A028 802BDAB8 E6020018 */   swc1     $f2, 0x18($s0)
/* 31A02C 802BDABC 24042009 */  addiu     $a0, $zero, 0x2009
/* 31A030 802BDAC0 0000282D */  daddu     $a1, $zero, $zero
/* 31A034 802BDAC4 0C052742 */  jal       sfx_play_sound_at_npc
/* 31A038 802BDAC8 2406FFFC */   addiu    $a2, $zero, -4
/* 31A03C 802BDACC 3C038016 */  lui       $v1, %hi(gCollisionStatus)
/* 31A040 802BDAD0 2463A550 */  addiu     $v1, $v1, %lo(gCollisionStatus)
/* 31A044 802BDAD4 2402FFFF */  addiu     $v0, $zero, -1
/* 31A048 802BDAD8 A4620004 */  sh        $v0, 4($v1)
/* 31A04C 802BDADC A4620002 */  sh        $v0, 2($v1)
/* 31A050 802BDAE0 A6020084 */  sh        $v0, 0x84($s0)
/* 31A054 802BDAE4 24020014 */  addiu     $v0, $zero, 0x14
/* 31A058 802BDAE8 3C01802C */  lui       $at, %hi(D_802BEBC4)
/* 31A05C 802BDAEC AC22EBC4 */  sw        $v0, %lo(D_802BEBC4)($at)
/* 31A060 802BDAF0 080AF9E1 */  j         .L802BE784
/* 31A064 802BDAF4 24020001 */   addiu    $v0, $zero, 1
glabel L802BDAF8_31A068
/* 31A068 802BDAF8 822300B4 */  lb        $v1, 0xb4($s1)
/* 31A06C 802BDAFC 24020015 */  addiu     $v0, $zero, 0x15
/* 31A070 802BDB00 1062031F */  beq       $v1, $v0, .L802BE780
/* 31A074 802BDB04 24020017 */   addiu    $v0, $zero, 0x17
/* 31A078 802BDB08 1062031D */  beq       $v1, $v0, .L802BE780
/* 31A07C 802BDB0C 24020016 */   addiu    $v0, $zero, 0x16
/* 31A080 802BDB10 1062031C */  beq       $v1, $v0, .L802BE784
/* 31A084 802BDB14 24020015 */   addiu    $v0, $zero, 0x15
/* 31A088 802BDB18 8EE3000C */  lw        $v1, 0xc($s7)
/* 31A08C 802BDB1C 3062C004 */  andi      $v0, $v1, 0xc004
/* 31A090 802BDB20 1040000B */  beqz      $v0, .L802BDB50
/* 31A094 802BDB24 30628000 */   andi     $v0, $v1, 0x8000
/* 31A098 802BDB28 10400002 */  beqz      $v0, .L802BDB34
/* 31A09C 802BDB2C 24040015 */   addiu    $a0, $zero, 0x15
/* 31A0A0 802BDB30 24040014 */  addiu     $a0, $zero, 0x14
.L802BDB34:
/* 31A0A4 802BDB34 3C01802C */  lui       $at, %hi(D_802BEBC0_31CBE0)
/* 31A0A8 802BDB38 AC24EBC0 */  sw        $a0, %lo(D_802BEBC0_31CBE0)($at)
/* 31A0AC 802BDB3C 3C040001 */  lui       $a0, 1
/* 31A0B0 802BDB40 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* 31A0B4 802BDB44 34840002 */   ori      $a0, $a0, 2
/* 31A0B8 802BDB48 080AF9E3 */  j         L802BE78C_31ACFC
/* 31A0BC 802BDB4C 00000000 */   nop
.L802BDB50:
/* 31A0C0 802BDB50 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 31A0C4 802BDB54 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 31A0C8 802BDB58 94430134 */  lhu       $v1, 0x134($v0)
/* 31A0CC 802BDB5C 3C02AAAA */  lui       $v0, 0xaaaa
/* 31A0D0 802BDB60 3442AAAB */  ori       $v0, $v0, 0xaaab
/* 31A0D4 802BDB64 00620019 */  multu     $v1, $v0
/* 31A0D8 802BDB68 00004010 */  mfhi      $t0
/* 31A0DC 802BDB6C 00082082 */  srl       $a0, $t0, 2
/* 31A0E0 802BDB70 00041040 */  sll       $v0, $a0, 1
/* 31A0E4 802BDB74 00441021 */  addu      $v0, $v0, $a0
/* 31A0E8 802BDB78 00021040 */  sll       $v0, $v0, 1
/* 31A0EC 802BDB7C 00621823 */  subu      $v1, $v1, $v0
/* 31A0F0 802BDB80 3063FFFF */  andi      $v1, $v1, 0xffff
/* 31A0F4 802BDB84 14600004 */  bnez      $v1, .L802BDB98
/* 31A0F8 802BDB88 24042009 */   addiu    $a0, $zero, 0x2009
/* 31A0FC 802BDB8C 0000282D */  daddu     $a1, $zero, $zero
/* 31A100 802BDB90 0C052742 */  jal       sfx_play_sound_at_npc
/* 31A104 802BDB94 2406FFFC */   addiu    $a2, $zero, -4
.L802BDB98:
/* 31A108 802BDB98 3C12802C */  lui       $s2, %hi(D_802BEBC4)
/* 31A10C 802BDB9C 2652EBC4 */  addiu     $s2, $s2, %lo(D_802BEBC4)
/* 31A110 802BDBA0 24020014 */  addiu     $v0, $zero, 0x14
/* 31A114 802BDBA4 8E430000 */  lw        $v1, ($s2)
/* 31A118 802BDBA8 3C0140C9 */  lui       $at, 0x40c9
/* 31A11C 802BDBAC 34210FD0 */  ori       $at, $at, 0xfd0
/* 31A120 802BDBB0 44810000 */  mtc1      $at, $f0
/* 31A124 802BDBB4 00431023 */  subu      $v0, $v0, $v1
/* 31A128 802BDBB8 000218C0 */  sll       $v1, $v0, 3
/* 31A12C 802BDBBC 00621821 */  addu      $v1, $v1, $v0
/* 31A130 802BDBC0 00031840 */  sll       $v1, $v1, 1
/* 31A134 802BDBC4 44836000 */  mtc1      $v1, $f12
/* 31A138 802BDBC8 00000000 */  nop
/* 31A13C 802BDBCC 46806320 */  cvt.s.w   $f12, $f12
/* 31A140 802BDBD0 46006302 */  mul.s     $f12, $f12, $f0
/* 31A144 802BDBD4 00000000 */  nop
/* 31A148 802BDBD8 3C0143B4 */  lui       $at, 0x43b4
/* 31A14C 802BDBDC 44810000 */  mtc1      $at, $f0
/* 31A150 802BDBE0 0C00A85B */  jal       sin_rad
/* 31A154 802BDBE4 46006303 */   div.s    $f12, $f12, $f0
/* 31A158 802BDBE8 46000005 */  abs.s     $f0, $f0
/* 31A15C 802BDBEC 3C01802C */  lui       $at, %hi(D_802BEB98_31B108)
/* 31A160 802BDBF0 D422EB98 */  ldc1      $f2, %lo(D_802BEB98_31B108)($at)
/* 31A164 802BDBF4 46000021 */  cvt.d.s   $f0, $f0
/* 31A168 802BDBF8 46220002 */  mul.d     $f0, $f0, $f2
/* 31A16C 802BDBFC 00000000 */  nop
/* 31A170 802BDC00 C622002C */  lwc1      $f2, 0x2c($s1)
/* 31A174 802BDC04 46200020 */  cvt.s.d   $f0, $f0
/* 31A178 802BDC08 46001080 */  add.s     $f2, $f2, $f0
/* 31A17C 802BDC0C 3C040001 */  lui       $a0, 1
/* 31A180 802BDC10 E622002C */  swc1      $f2, 0x2c($s1)
/* 31A184 802BDC14 860200A8 */  lh        $v0, 0xa8($s0)
/* 31A188 802BDC18 3C013F00 */  lui       $at, 0x3f00
/* 31A18C 802BDC1C 44814000 */  mtc1      $at, $f8
/* 31A190 802BDC20 44823000 */  mtc1      $v0, $f6
/* 31A194 802BDC24 00000000 */  nop
/* 31A198 802BDC28 468031A0 */  cvt.s.w   $f6, $f6
/* 31A19C 802BDC2C 46083182 */  mul.s     $f6, $f6, $f8
/* 31A1A0 802BDC30 00000000 */  nop
/* 31A1A4 802BDC34 27A50020 */  addiu     $a1, $sp, 0x20
/* 31A1A8 802BDC38 27A60024 */  addiu     $a2, $sp, 0x24
/* 31A1AC 802BDC3C C602003C */  lwc1      $f2, 0x3c($s0)
/* 31A1B0 802BDC40 27A70028 */  addiu     $a3, $sp, 0x28
/* 31A1B4 802BDC44 46001080 */  add.s     $f2, $f2, $f0
/* 31A1B8 802BDC48 C60A0038 */  lwc1      $f10, 0x38($s0)
/* 31A1BC 802BDC4C 44822000 */  mtc1      $v0, $f4
/* 31A1C0 802BDC50 00000000 */  nop
/* 31A1C4 802BDC54 46802120 */  cvt.s.w   $f4, $f4
/* 31A1C8 802BDC58 46082102 */  mul.s     $f4, $f4, $f8
/* 31A1CC 802BDC5C 00000000 */  nop
/* 31A1D0 802BDC60 C6080040 */  lwc1      $f8, 0x40($s0)
/* 31A1D4 802BDC64 27A2002C */  addiu     $v0, $sp, 0x2c
/* 31A1D8 802BDC68 E602003C */  swc1      $f2, 0x3c($s0)
/* 31A1DC 802BDC6C E7A0002C */  swc1      $f0, 0x2c($sp)
/* 31A1E0 802BDC70 E7AA0020 */  swc1      $f10, 0x20($sp)
/* 31A1E4 802BDC74 E7A80028 */  swc1      $f8, 0x28($sp)
/* 31A1E8 802BDC78 46061080 */  add.s     $f2, $f2, $f6
/* 31A1EC 802BDC7C 46002506 */  mov.s     $f20, $f4
/* 31A1F0 802BDC80 E7B4002C */  swc1      $f20, 0x2c($sp)
/* 31A1F4 802BDC84 E7A20024 */  swc1      $f2, 0x24($sp)
/* 31A1F8 802BDC88 0C03739C */  jal       npc_raycast_up
/* 31A1FC 802BDC8C AFA20010 */   sw       $v0, 0x10($sp)
/* 31A200 802BDC90 10400007 */  beqz      $v0, .L802BDCB0
/* 31A204 802BDC94 0220202D */   daddu    $a0, $s1, $zero
/* 31A208 802BDC98 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 31A20C 802BDC9C 4614003C */  c.lt.s    $f0, $f20
/* 31A210 802BDCA0 00000000 */  nop
/* 31A214 802BDCA4 45030002 */  bc1tl     .L802BDCB0
/* 31A218 802BDCA8 AE400000 */   sw       $zero, ($s2)
/* 31A21C 802BDCAC 0220202D */  daddu     $a0, $s1, $zero
.L802BDCB0:
/* 31A220 802BDCB0 27B40020 */  addiu     $s4, $sp, 0x20
/* 31A224 802BDCB4 0280282D */  daddu     $a1, $s4, $zero
/* 31A228 802BDCB8 27B30024 */  addiu     $s3, $sp, 0x24
/* 31A22C 802BDCBC 0260302D */  daddu     $a2, $s3, $zero
/* 31A230 802BDCC0 27B20028 */  addiu     $s2, $sp, 0x28
/* 31A234 802BDCC4 0240382D */  daddu     $a3, $s2, $zero
/* 31A238 802BDCC8 263E0028 */  addiu     $fp, $s1, 0x28
/* 31A23C 802BDCCC 26280030 */  addiu     $t0, $s1, 0x30
/* 31A240 802BDCD0 862200B0 */  lh        $v0, 0xb0($s1)
/* 31A244 802BDCD4 3C013F00 */  lui       $at, 0x3f00
/* 31A248 802BDCD8 44811000 */  mtc1      $at, $f2
/* 31A24C 802BDCDC C624002C */  lwc1      $f4, 0x2c($s1)
/* 31A250 802BDCE0 44824000 */  mtc1      $v0, $f8
/* 31A254 802BDCE4 00000000 */  nop
/* 31A258 802BDCE8 46804220 */  cvt.s.w   $f8, $f8
/* 31A25C 802BDCEC 46024202 */  mul.s     $f8, $f8, $f2
/* 31A260 802BDCF0 00000000 */  nop
/* 31A264 802BDCF4 C62A0028 */  lwc1      $f10, 0x28($s1)
/* 31A268 802BDCF8 C62C0030 */  lwc1      $f12, 0x30($s1)
/* 31A26C 802BDCFC 0040182D */  daddu     $v1, $v0, $zero
/* 31A270 802BDD00 44830000 */  mtc1      $v1, $f0
/* 31A274 802BDD04 00000000 */  nop
/* 31A278 802BDD08 46800020 */  cvt.s.w   $f0, $f0
/* 31A27C 802BDD0C 46020002 */  mul.s     $f0, $f0, $f2
/* 31A280 802BDD10 00000000 */  nop
/* 31A284 802BDD14 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 31A288 802BDD18 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 31A28C 802BDD1C 3C0142B4 */  lui       $at, 0x42b4
/* 31A290 802BDD20 44811000 */  mtc1      $at, $f2
/* 31A294 802BDD24 00031080 */  sll       $v0, $v1, 2
/* 31A298 802BDD28 00431021 */  addu      $v0, $v0, $v1
/* 31A29C 802BDD2C 00021080 */  sll       $v0, $v0, 2
/* 31A2A0 802BDD30 00431023 */  subu      $v0, $v0, $v1
/* 31A2A4 802BDD34 000218C0 */  sll       $v1, $v0, 3
/* 31A2A8 802BDD38 00431021 */  addu      $v0, $v0, $v1
/* 31A2AC 802BDD3C 000210C0 */  sll       $v0, $v0, 3
/* 31A2B0 802BDD40 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 31A2B4 802BDD44 00220821 */  addu      $at, $at, $v0
/* 31A2B8 802BDD48 C4261DEC */  lwc1      $f6, %lo(gCameras+0x6C)($at)
/* 31A2BC 802BDD4C 46002100 */  add.s     $f4, $f4, $f0
/* 31A2C0 802BDD50 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* 31A2C4 802BDD54 27A2002C */  addiu     $v0, $sp, 0x2c
/* 31A2C8 802BDD58 E7AA0020 */  swc1      $f10, 0x20($sp)
/* 31A2CC 802BDD5C E7AC0028 */  swc1      $f12, 0x28($sp)
/* 31A2D0 802BDD60 46020001 */  sub.s     $f0, $f0, $f2
/* 31A2D4 802BDD64 E7A8002C */  swc1      $f8, 0x2c($sp)
/* 31A2D8 802BDD68 AFA80030 */  sw        $t0, 0x30($sp)
/* 31A2DC 802BDD6C 46060500 */  add.s     $f20, $f0, $f6
/* 31A2E0 802BDD70 E7A40024 */  swc1      $f4, 0x24($sp)
/* 31A2E4 802BDD74 AFA20010 */  sw        $v0, 0x10($sp)
/* 31A2E8 802BDD78 0C0379F9 */  jal       player_raycast_up_corners
/* 31A2EC 802BDD7C E7B40014 */   swc1     $f20, 0x14($sp)
/* 31A2F0 802BDD80 04400006 */  bltz      $v0, .L802BDD9C
/* 31A2F4 802BDD84 3C040001 */   lui      $a0, 1
.L802BDD88:
/* 31A2F8 802BDD88 3C040001 */  lui       $a0, 1
.L802BDD8C:
/* 31A2FC 802BDD8C 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* 31A300 802BDD90 34840002 */   ori      $a0, $a0, 2
/* 31A304 802BDD94 080AF9E1 */  j         .L802BE784
/* 31A308 802BDD98 24020015 */   addiu    $v0, $zero, 0x15
.L802BDD9C:
/* 31A30C 802BDD9C 0280282D */  daddu     $a1, $s4, $zero
/* 31A310 802BDDA0 0260302D */  daddu     $a2, $s3, $zero
/* 31A314 802BDDA4 C6200028 */  lwc1      $f0, 0x28($s1)
/* 31A318 802BDDA8 C622002C */  lwc1      $f2, 0x2c($s1)
/* 31A31C 802BDDAC C6240030 */  lwc1      $f4, 0x30($s1)
/* 31A320 802BDDB0 C6060018 */  lwc1      $f6, 0x18($s0)
/* 31A324 802BDDB4 0240382D */  daddu     $a3, $s2, $zero
/* 31A328 802BDDB8 E7A00020 */  swc1      $f0, 0x20($sp)
/* 31A32C 802BDDBC E7A20024 */  swc1      $f2, 0x24($sp)
/* 31A330 802BDDC0 E7A40028 */  swc1      $f4, 0x28($sp)
/* 31A334 802BDDC4 E7A60010 */  swc1      $f6, 0x10($sp)
/* 31A338 802BDDC8 C602000C */  lwc1      $f2, 0xc($s0)
/* 31A33C 802BDDCC 862200B0 */  lh        $v0, 0xb0($s1)
/* 31A340 802BDDD0 862300B2 */  lh        $v1, 0xb2($s1)
/* 31A344 802BDDD4 44820000 */  mtc1      $v0, $f0
/* 31A348 802BDDD8 00000000 */  nop
/* 31A34C 802BDDDC 46800020 */  cvt.s.w   $f0, $f0
/* 31A350 802BDDE0 E7A00018 */  swc1      $f0, 0x18($sp)
/* 31A354 802BDDE4 44830000 */  mtc1      $v1, $f0
/* 31A358 802BDDE8 00000000 */  nop
/* 31A35C 802BDDEC 46800020 */  cvt.s.w   $f0, $f0
/* 31A360 802BDDF0 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 31A364 802BDDF4 0C037765 */  jal       npc_test_move_complex_with_slipping
/* 31A368 802BDDF8 E7A20014 */   swc1     $f2, 0x14($sp)
/* 31A36C 802BDDFC 28420002 */  slti      $v0, $v0, 2
/* 31A370 802BDE00 1440001E */  bnez      $v0, .L802BDE7C
/* 31A374 802BDE04 00000000 */   nop
/* 31A378 802BDE08 C7AA0020 */  lwc1      $f10, 0x20($sp)
/* 31A37C 802BDE0C C6260028 */  lwc1      $f6, 0x28($s1)
/* 31A380 802BDE10 46065101 */  sub.s     $f4, $f10, $f6
/* 31A384 802BDE14 3C013E00 */  lui       $at, 0x3e00
/* 31A388 802BDE18 44816000 */  mtc1      $at, $f12
/* 31A38C 802BDE1C 00000000 */  nop
/* 31A390 802BDE20 460C2102 */  mul.s     $f4, $f4, $f12
/* 31A394 802BDE24 00000000 */  nop
/* 31A398 802BDE28 C7A80028 */  lwc1      $f8, 0x28($sp)
/* 31A39C 802BDE2C C6220030 */  lwc1      $f2, 0x30($s1)
/* 31A3A0 802BDE30 46024001 */  sub.s     $f0, $f8, $f2
/* 31A3A4 802BDE34 460C0002 */  mul.s     $f0, $f0, $f12
/* 31A3A8 802BDE38 00000000 */  nop
/* 31A3AC 802BDE3C 46043180 */  add.s     $f6, $f6, $f4
/* 31A3B0 802BDE40 46001080 */  add.s     $f2, $f2, $f0
/* 31A3B4 802BDE44 E6260028 */  swc1      $f6, 0x28($s1)
/* 31A3B8 802BDE48 E6220030 */  swc1      $f2, 0x30($s1)
/* 31A3BC 802BDE4C C6020038 */  lwc1      $f2, 0x38($s0)
/* 31A3C0 802BDE50 46025281 */  sub.s     $f10, $f10, $f2
/* 31A3C4 802BDE54 460C5282 */  mul.s     $f10, $f10, $f12
/* 31A3C8 802BDE58 00000000 */  nop
/* 31A3CC 802BDE5C C6000040 */  lwc1      $f0, 0x40($s0)
/* 31A3D0 802BDE60 46004201 */  sub.s     $f8, $f8, $f0
/* 31A3D4 802BDE64 460C4202 */  mul.s     $f8, $f8, $f12
/* 31A3D8 802BDE68 00000000 */  nop
/* 31A3DC 802BDE6C 460A1080 */  add.s     $f2, $f2, $f10
/* 31A3E0 802BDE70 46080000 */  add.s     $f0, $f0, $f8
/* 31A3E4 802BDE74 E6020038 */  swc1      $f2, 0x38($s0)
/* 31A3E8 802BDE78 E6000040 */  swc1      $f0, 0x40($s0)
.L802BDE7C:
/* 31A3EC 802BDE7C C6000038 */  lwc1      $f0, 0x38($s0)
/* 31A3F0 802BDE80 C602003C */  lwc1      $f2, 0x3c($s0)
/* 31A3F4 802BDE84 C6040040 */  lwc1      $f4, 0x40($s0)
/* 31A3F8 802BDE88 C6060018 */  lwc1      $f6, 0x18($s0)
/* 31A3FC 802BDE8C 3C040001 */  lui       $a0, 1
/* 31A400 802BDE90 E7A00020 */  swc1      $f0, 0x20($sp)
/* 31A404 802BDE94 E7A20024 */  swc1      $f2, 0x24($sp)
/* 31A408 802BDE98 E7A40028 */  swc1      $f4, 0x28($sp)
/* 31A40C 802BDE9C E7A60010 */  swc1      $f6, 0x10($sp)
/* 31A410 802BDEA0 C600000C */  lwc1      $f0, 0xc($s0)
/* 31A414 802BDEA4 0280282D */  daddu     $a1, $s4, $zero
/* 31A418 802BDEA8 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31A41C 802BDEAC 860200A8 */  lh        $v0, 0xa8($s0)
/* 31A420 802BDEB0 0260302D */  daddu     $a2, $s3, $zero
/* 31A424 802BDEB4 44820000 */  mtc1      $v0, $f0
/* 31A428 802BDEB8 00000000 */  nop
/* 31A42C 802BDEBC 46800020 */  cvt.s.w   $f0, $f0
/* 31A430 802BDEC0 E7A00018 */  swc1      $f0, 0x18($sp)
/* 31A434 802BDEC4 860200A6 */  lh        $v0, 0xa6($s0)
/* 31A438 802BDEC8 0240382D */  daddu     $a3, $s2, $zero
/* 31A43C 802BDECC 44820000 */  mtc1      $v0, $f0
/* 31A440 802BDED0 00000000 */  nop
/* 31A444 802BDED4 46800020 */  cvt.s.w   $f0, $f0
/* 31A448 802BDED8 0C037765 */  jal       npc_test_move_complex_with_slipping
/* 31A44C 802BDEDC E7A0001C */   swc1     $f0, 0x1c($sp)
/* 31A450 802BDEE0 0040182D */  daddu     $v1, $v0, $zero
/* 31A454 802BDEE4 26150038 */  addiu     $s5, $s0, 0x38
/* 31A458 802BDEE8 28620002 */  slti      $v0, $v1, 2
/* 31A45C 802BDEEC 14400043 */  bnez      $v0, .L802BDFFC
/* 31A460 802BDEF0 26160040 */   addiu    $s6, $s0, 0x40
/* 31A464 802BDEF4 C7A60020 */  lwc1      $f6, 0x20($sp)
/* 31A468 802BDEF8 C6020038 */  lwc1      $f2, 0x38($s0)
/* 31A46C 802BDEFC 46023001 */  sub.s     $f0, $f6, $f2
/* 31A470 802BDF00 3C013E00 */  lui       $at, 0x3e00
/* 31A474 802BDF04 44817000 */  mtc1      $at, $f14
/* 31A478 802BDF08 00000000 */  nop
/* 31A47C 802BDF0C 460E0682 */  mul.s     $f26, $f0, $f14
/* 31A480 802BDF10 00000000 */  nop
/* 31A484 802BDF14 3C040001 */  lui       $a0, 1
/* 31A488 802BDF18 C7A80028 */  lwc1      $f8, 0x28($sp)
/* 31A48C 802BDF1C C6000040 */  lwc1      $f0, 0x40($s0)
/* 31A490 802BDF20 0280282D */  daddu     $a1, $s4, $zero
/* 31A494 802BDF24 46004001 */  sub.s     $f0, $f8, $f0
/* 31A498 802BDF28 0260302D */  daddu     $a2, $s3, $zero
/* 31A49C 802BDF2C 0240382D */  daddu     $a3, $s2, $zero
/* 31A4A0 802BDF30 460E0602 */  mul.s     $f24, $f0, $f14
/* 31A4A4 802BDF34 00000000 */  nop
/* 31A4A8 802BDF38 C6100038 */  lwc1      $f16, 0x38($s0)
/* 31A4AC 802BDF3C C604003C */  lwc1      $f4, 0x3c($s0)
/* 31A4B0 802BDF40 C60C0018 */  lwc1      $f12, 0x18($s0)
/* 31A4B4 802BDF44 C6000040 */  lwc1      $f0, 0x40($s0)
/* 31A4B8 802BDF48 461A1080 */  add.s     $f2, $f2, $f26
/* 31A4BC 802BDF4C E7A40024 */  swc1      $f4, 0x24($sp)
/* 31A4C0 802BDF50 46000286 */  mov.s     $f10, $f0
/* 31A4C4 802BDF54 46180000 */  add.s     $f0, $f0, $f24
/* 31A4C8 802BDF58 E7A20020 */  swc1      $f2, 0x20($sp)
/* 31A4CC 802BDF5C E7B00020 */  swc1      $f16, 0x20($sp)
/* 31A4D0 802BDF60 E7A00028 */  swc1      $f0, 0x28($sp)
/* 31A4D4 802BDF64 E7AA0028 */  swc1      $f10, 0x28($sp)
/* 31A4D8 802BDF68 E7AC0010 */  swc1      $f12, 0x10($sp)
/* 31A4DC 802BDF6C C6200028 */  lwc1      $f0, 0x28($s1)
/* 31A4E0 802BDF70 C602000C */  lwc1      $f2, 0xc($s0)
/* 31A4E4 802BDF74 46003181 */  sub.s     $f6, $f6, $f0
/* 31A4E8 802BDF78 E7A20014 */  swc1      $f2, 0x14($sp)
/* 31A4EC 802BDF7C 860200A8 */  lh        $v0, 0xa8($s0)
/* 31A4F0 802BDF80 460E3582 */  mul.s     $f22, $f6, $f14
/* 31A4F4 802BDF84 00000000 */  nop
/* 31A4F8 802BDF88 44820000 */  mtc1      $v0, $f0
/* 31A4FC 802BDF8C 00000000 */  nop
/* 31A500 802BDF90 46800020 */  cvt.s.w   $f0, $f0
/* 31A504 802BDF94 E7A00018 */  swc1      $f0, 0x18($sp)
/* 31A508 802BDF98 C6200030 */  lwc1      $f0, 0x30($s1)
/* 31A50C 802BDF9C 860200A6 */  lh        $v0, 0xa6($s0)
/* 31A510 802BDFA0 46004201 */  sub.s     $f8, $f8, $f0
/* 31A514 802BDFA4 44820000 */  mtc1      $v0, $f0
/* 31A518 802BDFA8 00000000 */  nop
/* 31A51C 802BDFAC 46800020 */  cvt.s.w   $f0, $f0
/* 31A520 802BDFB0 460E4502 */  mul.s     $f20, $f8, $f14
/* 31A524 802BDFB4 00000000 */  nop
/* 31A528 802BDFB8 0C037765 */  jal       npc_test_move_complex_with_slipping
/* 31A52C 802BDFBC E7A0001C */   swc1     $f0, 0x1c($sp)
/* 31A530 802BDFC0 0040182D */  daddu     $v1, $v0, $zero
/* 31A534 802BDFC4 14600020 */  bnez      $v1, .L802BE048
/* 31A538 802BDFC8 00000000 */   nop
/* 31A53C 802BDFCC C6220028 */  lwc1      $f2, 0x28($s1)
/* 31A540 802BDFD0 46161080 */  add.s     $f2, $f2, $f22
/* 31A544 802BDFD4 C6200030 */  lwc1      $f0, 0x30($s1)
/* 31A548 802BDFD8 46140000 */  add.s     $f0, $f0, $f20
/* 31A54C 802BDFDC E6220028 */  swc1      $f2, 0x28($s1)
/* 31A550 802BDFE0 E6200030 */  swc1      $f0, 0x30($s1)
/* 31A554 802BDFE4 C6020038 */  lwc1      $f2, 0x38($s0)
/* 31A558 802BDFE8 461A1080 */  add.s     $f2, $f2, $f26
/* 31A55C 802BDFEC C6000040 */  lwc1      $f0, 0x40($s0)
/* 31A560 802BDFF0 46180000 */  add.s     $f0, $f0, $f24
/* 31A564 802BDFF4 E6020038 */  swc1      $f2, 0x38($s0)
/* 31A568 802BDFF8 E6000040 */  swc1      $f0, 0x40($s0)
.L802BDFFC:
/* 31A56C 802BDFFC 14600012 */  bnez      $v1, .L802BE048
/* 31A570 802BE000 00000000 */   nop
/* 31A574 802BE004 8E220004 */  lw        $v0, 4($s1)
/* 31A578 802BE008 30428000 */  andi      $v0, $v0, 0x8000
/* 31A57C 802BE00C 1440000E */  bnez      $v0, .L802BE048
/* 31A580 802BE010 02A0202D */   daddu    $a0, $s5, $zero
/* 31A584 802BE014 8E060018 */  lw        $a2, 0x18($s0)
/* 31A588 802BE018 8E07000C */  lw        $a3, 0xc($s0)
/* 31A58C 802BE01C 0C00A7E7 */  jal       add_vec2D_polar
/* 31A590 802BE020 02C0282D */   daddu    $a1, $s6, $zero
/* 31A594 802BE024 8E060018 */  lw        $a2, 0x18($s0)
/* 31A598 802BE028 8E07000C */  lw        $a3, 0xc($s0)
/* 31A59C 802BE02C 8FA50030 */  lw        $a1, 0x30($sp)
/* 31A5A0 802BE030 0C00A7E7 */  jal       add_vec2D_polar
/* 31A5A4 802BE034 03C0202D */   daddu    $a0, $fp, $zero
/* 31A5A8 802BE038 C6000010 */  lwc1      $f0, 0x10($s0)
/* 31A5AC 802BE03C C6020018 */  lwc1      $f2, 0x18($s0)
/* 31A5B0 802BE040 46020000 */  add.s     $f0, $f0, $f2
/* 31A5B4 802BE044 E6000010 */  swc1      $f0, 0x10($s0)
.L802BE048:
/* 31A5B8 802BE048 862200B0 */  lh        $v0, 0xb0($s1)
/* 31A5BC 802BE04C 3C013F00 */  lui       $at, 0x3f00
/* 31A5C0 802BE050 44810000 */  mtc1      $at, $f0
/* 31A5C4 802BE054 44823000 */  mtc1      $v0, $f6
/* 31A5C8 802BE058 00000000 */  nop
/* 31A5CC 802BE05C 468031A0 */  cvt.s.w   $f6, $f6
/* 31A5D0 802BE060 46003182 */  mul.s     $f6, $f6, $f0
/* 31A5D4 802BE064 00000000 */  nop
/* 31A5D8 802BE068 3C040001 */  lui       $a0, 1
/* 31A5DC 802BE06C 27A50020 */  addiu     $a1, $sp, 0x20
/* 31A5E0 802BE070 44822000 */  mtc1      $v0, $f4
/* 31A5E4 802BE074 00000000 */  nop
/* 31A5E8 802BE078 46802120 */  cvt.s.w   $f4, $f4
/* 31A5EC 802BE07C 46002102 */  mul.s     $f4, $f4, $f0
/* 31A5F0 802BE080 00000000 */  nop
/* 31A5F4 802BE084 C6200028 */  lwc1      $f0, 0x28($s1)
/* 31A5F8 802BE088 27A2002C */  addiu     $v0, $sp, 0x2c
/* 31A5FC 802BE08C E7A00020 */  swc1      $f0, 0x20($sp)
/* 31A600 802BE090 C620002C */  lwc1      $f0, 0x2c($s1)
/* 31A604 802BE094 C6220030 */  lwc1      $f2, 0x30($s1)
/* 31A608 802BE098 46060000 */  add.s     $f0, $f0, $f6
/* 31A60C 802BE09C E7A20028 */  swc1      $f2, 0x28($sp)
/* 31A610 802BE0A0 E7A4002C */  swc1      $f4, 0x2c($sp)
/* 31A614 802BE0A4 E7A00024 */  swc1      $f0, 0x24($sp)
/* 31A618 802BE0A8 AFA20010 */  sw        $v0, 0x10($sp)
/* 31A61C 802BE0AC C600000C */  lwc1      $f0, 0xc($s0)
/* 31A620 802BE0B0 27A60024 */  addiu     $a2, $sp, 0x24
/* 31A624 802BE0B4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31A628 802BE0B8 860200A6 */  lh        $v0, 0xa6($s0)
/* 31A62C 802BE0BC 27A70028 */  addiu     $a3, $sp, 0x28
/* 31A630 802BE0C0 44820000 */  mtc1      $v0, $f0
/* 31A634 802BE0C4 00000000 */  nop
/* 31A638 802BE0C8 46800020 */  cvt.s.w   $f0, $f0
/* 31A63C 802BE0CC 0C0371DE */  jal       npc_raycast_down_ahead
/* 31A640 802BE0D0 E7A00018 */   swc1     $f0, 0x18($sp)
/* 31A644 802BE0D4 10400020 */  beqz      $v0, .L802BE158
/* 31A648 802BE0D8 00000000 */   nop
/* 31A64C 802BE0DC 3C048011 */  lui       $a0, %hi(D_8010C978)
/* 31A650 802BE0E0 8C84C978 */  lw        $a0, %lo(D_8010C978)($a0)
/* 31A654 802BE0E4 0C016F6A */  jal       get_collider_type_by_id
/* 31A658 802BE0E8 00000000 */   nop
/* 31A65C 802BE0EC 304200FF */  andi      $v0, $v0, 0xff
/* 31A660 802BE0F0 2442FFFE */  addiu     $v0, $v0, -2
/* 31A664 802BE0F4 2C420002 */  sltiu     $v0, $v0, 2
/* 31A668 802BE0F8 10400008 */  beqz      $v0, .L802BE11C
/* 31A66C 802BE0FC 24020002 */   addiu    $v0, $zero, 2
/* 31A670 802BE100 A22200BF */  sb        $v0, 0xbf($s1)
/* 31A674 802BE104 8E220000 */  lw        $v0, ($s1)
/* 31A678 802BE108 24030015 */  addiu     $v1, $zero, 0x15
/* 31A67C 802BE10C 3C01802C */  lui       $at, %hi(D_802BEBC0_31CBE0)
/* 31A680 802BE110 AC23EBC0 */  sw        $v1, %lo(D_802BEBC0_31CBE0)($at)
/* 31A684 802BE114 34420800 */  ori       $v0, $v0, 0x800
/* 31A688 802BE118 AE220000 */  sw        $v0, ($s1)
.L802BE11C:
/* 31A68C 802BE11C C7A00024 */  lwc1      $f0, 0x24($sp)
/* 31A690 802BE120 C624002C */  lwc1      $f4, 0x2c($s1)
/* 31A694 802BE124 46040001 */  sub.s     $f0, $f0, $f4
/* 31A698 802BE128 3C013E80 */  lui       $at, 0x3e80
/* 31A69C 802BE12C 44811000 */  mtc1      $at, $f2
/* 31A6A0 802BE130 00000000 */  nop
/* 31A6A4 802BE134 46020002 */  mul.s     $f0, $f0, $f2
/* 31A6A8 802BE138 00000000 */  nop
/* 31A6AC 802BE13C 46002100 */  add.s     $f4, $f4, $f0
/* 31A6B0 802BE140 3C014200 */  lui       $at, 0x4200
/* 31A6B4 802BE144 44810000 */  mtc1      $at, $f0
/* 31A6B8 802BE148 00000000 */  nop
/* 31A6BC 802BE14C 46002000 */  add.s     $f0, $f4, $f0
/* 31A6C0 802BE150 E624002C */  swc1      $f4, 0x2c($s1)
/* 31A6C4 802BE154 E600003C */  swc1      $f0, 0x3c($s0)
.L802BE158:
/* 31A6C8 802BE158 8E020000 */  lw        $v0, ($s0)
/* 31A6CC 802BE15C 30424000 */  andi      $v0, $v0, 0x4000
/* 31A6D0 802BE160 1440FF0A */  bnez      $v0, .L802BDD8C
/* 31A6D4 802BE164 3C040001 */   lui      $a0, 1
/* 31A6D8 802BE168 3C04802C */  lui       $a0, %hi(D_802BEBC4)
/* 31A6DC 802BE16C 2484EBC4 */  addiu     $a0, $a0, %lo(D_802BEBC4)
/* 31A6E0 802BE170 C6200028 */  lwc1      $f0, 0x28($s1)
/* 31A6E4 802BE174 C622002C */  lwc1      $f2, 0x2c($s1)
/* 31A6E8 802BE178 C6240030 */  lwc1      $f4, 0x30($s1)
/* 31A6EC 802BE17C 8C830000 */  lw        $v1, ($a0)
/* 31A6F0 802BE180 3C02800B */  lui       $v0, %hi(gCameras)
/* 31A6F4 802BE184 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 31A6F8 802BE188 E4400060 */  swc1      $f0, 0x60($v0)
/* 31A6FC 802BE18C E4420064 */  swc1      $f2, 0x64($v0)
/* 31A700 802BE190 10600004 */  beqz      $v1, .L802BE1A4
/* 31A704 802BE194 E4440068 */   swc1     $f4, 0x68($v0)
/* 31A708 802BE198 2462FFFF */  addiu     $v0, $v1, -1
/* 31A70C 802BE19C 080AF9E3 */  j         L802BE78C_31ACFC
/* 31A710 802BE1A0 AC820000 */   sw       $v0, ($a0)
.L802BE1A4:
/* 31A714 802BE1A4 3C040004 */  lui       $a0, 4
/* 31A718 802BE1A8 3C01BF00 */  lui       $at, 0xbf00
/* 31A71C 802BE1AC 44810000 */  mtc1      $at, $f0
/* 31A720 802BE1B0 3C01BC23 */  lui       $at, 0xbc23
/* 31A724 802BE1B4 3421D70A */  ori       $at, $at, 0xd70a
/* 31A728 802BE1B8 44811000 */  mtc1      $at, $f2
/* 31A72C 802BE1BC 3C03802C */  lui       $v1, %hi(D_802BEBC0_31CBE0)
/* 31A730 802BE1C0 2463EBC0 */  addiu     $v1, $v1, %lo(D_802BEBC0_31CBE0)
/* 31A734 802BE1C4 E600001C */  swc1      $f0, 0x1c($s0)
/* 31A738 802BE1C8 E6020014 */  swc1      $f2, 0x14($s0)
/* 31A73C 802BE1CC C622002C */  lwc1      $f2, 0x2c($s1)
/* 31A740 802BE1D0 3C013FE6 */  lui       $at, 0x3fe6
/* 31A744 802BE1D4 34216666 */  ori       $at, $at, 0x6666
/* 31A748 802BE1D8 44810000 */  mtc1      $at, $f0
/* 31A74C 802BE1DC 8C620000 */  lw        $v0, ($v1)
/* 31A750 802BE1E0 3484000A */  ori       $a0, $a0, 0xa
/* 31A754 802BE1E4 A600008E */  sh        $zero, 0x8e($s0)
/* 31A758 802BE1E8 AE040028 */  sw        $a0, 0x28($s0)
/* 31A75C 802BE1EC 24420001 */  addiu     $v0, $v0, 1
/* 31A760 802BE1F0 E6000030 */  swc1      $f0, 0x30($s0)
/* 31A764 802BE1F4 AC620000 */  sw        $v0, ($v1)
/* 31A768 802BE1F8 2402FFFF */  addiu     $v0, $zero, -1
/* 31A76C 802BE1FC E6020064 */  swc1      $f2, 0x64($s0)
/* 31A770 802BE200 3C018016 */  lui       $at, %hi(gCollisionStatus+0x2)
/* 31A774 802BE204 A422A552 */  sh        $v0, %lo(gCollisionStatus+0x2)($at)
/* 31A778 802BE208 080AF9E3 */  j         L802BE78C_31ACFC
/* 31A77C 802BE20C 00000000 */   nop
glabel L802BE210_31A780
/* 31A780 802BE210 0C0AF556 */  jal       func_802BD558_319AC8
/* 31A784 802BE214 24150015 */   addiu    $s5, $zero, 0x15
/* 31A788 802BE218 3C018016 */  lui       $at, %hi(gCollisionStatus+0x2)
/* 31A78C 802BE21C A422A552 */  sh        $v0, %lo(gCollisionStatus+0x2)($at)
/* 31A790 802BE220 822300B4 */  lb        $v1, 0xb4($s1)
/* 31A794 802BE224 10750156 */  beq       $v1, $s5, .L802BE780
/* 31A798 802BE228 24020017 */   addiu    $v0, $zero, 0x17
/* 31A79C 802BE22C 10620154 */  beq       $v1, $v0, .L802BE780
/* 31A7A0 802BE230 24020016 */   addiu    $v0, $zero, 0x16
/* 31A7A4 802BE234 10620152 */  beq       $v1, $v0, .L802BE780
/* 31A7A8 802BE238 3C040008 */   lui      $a0, 8
/* 31A7AC 802BE23C 0C037FDE */  jal       suggest_player_anim_setUnkFlag
/* 31A7B0 802BE240 3484000D */   ori      $a0, $a0, 0xd
/* 31A7B4 802BE244 8E220000 */  lw        $v0, ($s1)
/* 31A7B8 802BE248 30420800 */  andi      $v0, $v0, 0x800
/* 31A7BC 802BE24C 1440014D */  bnez      $v0, .L802BE784
/* 31A7C0 802BE250 24020014 */   addiu    $v0, $zero, 0x14
/* 31A7C4 802BE254 8EE3000C */  lw        $v1, 0xc($s7)
/* 31A7C8 802BE258 3062C004 */  andi      $v0, $v1, 0xc004
/* 31A7CC 802BE25C 10400008 */  beqz      $v0, .L802BE280
/* 31A7D0 802BE260 30628000 */   andi     $v0, $v1, 0x8000
/* 31A7D4 802BE264 10400002 */  beqz      $v0, .L802BE270
/* 31A7D8 802BE268 24040015 */   addiu    $a0, $zero, 0x15
/* 31A7DC 802BE26C 24040014 */  addiu     $a0, $zero, 0x14
.L802BE270:
/* 31A7E0 802BE270 3C01802C */  lui       $at, %hi(D_802BEBC0_31CBE0)
/* 31A7E4 802BE274 AC24EBC0 */  sw        $a0, %lo(D_802BEBC0_31CBE0)($at)
/* 31A7E8 802BE278 080AF9E3 */  j         L802BE78C_31ACFC
/* 31A7EC 802BE27C 00000000 */   nop
.L802BE280:
/* 31A7F0 802BE280 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 31A7F4 802BE284 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 31A7F8 802BE288 94430134 */  lhu       $v1, 0x134($v0)
/* 31A7FC 802BE28C 3C02AAAA */  lui       $v0, 0xaaaa
/* 31A800 802BE290 3442AAAB */  ori       $v0, $v0, 0xaaab
/* 31A804 802BE294 00620019 */  multu     $v1, $v0
/* 31A808 802BE298 00004010 */  mfhi      $t0
/* 31A80C 802BE29C 00082082 */  srl       $a0, $t0, 2
/* 31A810 802BE2A0 00041040 */  sll       $v0, $a0, 1
/* 31A814 802BE2A4 00441021 */  addu      $v0, $v0, $a0
/* 31A818 802BE2A8 00021040 */  sll       $v0, $v0, 1
/* 31A81C 802BE2AC 00621823 */  subu      $v1, $v1, $v0
/* 31A820 802BE2B0 3063FFFF */  andi      $v1, $v1, 0xffff
/* 31A824 802BE2B4 14600004 */  bnez      $v1, .L802BE2C8
/* 31A828 802BE2B8 24042009 */   addiu    $a0, $zero, 0x2009
/* 31A82C 802BE2BC 0000282D */  daddu     $a1, $zero, $zero
/* 31A830 802BE2C0 0C052742 */  jal       sfx_play_sound_at_npc
/* 31A834 802BE2C4 2406FFFC */   addiu    $a2, $zero, -4
.L802BE2C8:
/* 31A838 802BE2C8 C604001C */  lwc1      $f4, 0x1c($s0)
/* 31A83C 802BE2CC C6000014 */  lwc1      $f0, 0x14($s0)
/* 31A840 802BE2D0 46002101 */  sub.s     $f4, $f4, $f0
/* 31A844 802BE2D4 44801000 */  mtc1      $zero, $f2
/* 31A848 802BE2D8 44801800 */  mtc1      $zero, $f3
/* 31A84C 802BE2DC 46002021 */  cvt.d.s   $f0, $f4
/* 31A850 802BE2E0 4620103C */  c.lt.d    $f2, $f0
/* 31A854 802BE2E4 00000000 */  nop
/* 31A858 802BE2E8 45000002 */  bc1f      .L802BE2F4
/* 31A85C 802BE2EC E604001C */   swc1     $f4, 0x1c($s0)
/* 31A860 802BE2F0 AE00001C */  sw        $zero, 0x1c($s0)
.L802BE2F4:
/* 31A864 802BE2F4 C600003C */  lwc1      $f0, 0x3c($s0)
/* 31A868 802BE2F8 C602001C */  lwc1      $f2, 0x1c($s0)
/* 31A86C 802BE2FC 46020000 */  add.s     $f0, $f0, $f2
/* 31A870 802BE300 E600003C */  swc1      $f0, 0x3c($s0)
/* 31A874 802BE304 C620002C */  lwc1      $f0, 0x2c($s1)
/* 31A878 802BE308 8E220004 */  lw        $v0, 4($s1)
/* 31A87C 802BE30C 46020000 */  add.s     $f0, $f0, $f2
/* 31A880 802BE310 30428000 */  andi      $v0, $v0, 0x8000
/* 31A884 802BE314 1440FE9C */  bnez      $v0, .L802BDD88
/* 31A888 802BE318 E620002C */   swc1     $f0, 0x2c($s1)
/* 31A88C 802BE31C C6000018 */  lwc1      $f0, 0x18($s0)
/* 31A890 802BE320 3C01802C */  lui       $at, %hi(D_802BEBA0_31B110)
/* 31A894 802BE324 D422EBA0 */  ldc1      $f2, %lo(D_802BEBA0_31B110)($at)
/* 31A898 802BE328 46000021 */  cvt.d.s   $f0, $f0
/* 31A89C 802BE32C 46220000 */  add.d     $f0, $f0, $f2
/* 31A8A0 802BE330 3C014000 */  lui       $at, 0x4000
/* 31A8A4 802BE334 44812800 */  mtc1      $at, $f5
/* 31A8A8 802BE338 44802000 */  mtc1      $zero, $f4
/* 31A8AC 802BE33C 46200020 */  cvt.s.d   $f0, $f0
/* 31A8B0 802BE340 460000A1 */  cvt.d.s   $f2, $f0
/* 31A8B4 802BE344 4622203C */  c.lt.d    $f4, $f2
/* 31A8B8 802BE348 00000000 */  nop
/* 31A8BC 802BE34C 45000005 */  bc1f      .L802BE364
/* 31A8C0 802BE350 E6000018 */   swc1     $f0, 0x18($s0)
/* 31A8C4 802BE354 3C014000 */  lui       $at, 0x4000
/* 31A8C8 802BE358 44810000 */  mtc1      $at, $f0
/* 31A8CC 802BE35C 00000000 */  nop
/* 31A8D0 802BE360 E6000018 */  swc1      $f0, 0x18($s0)
.L802BE364:
/* 31A8D4 802BE364 26040038 */  addiu     $a0, $s0, 0x38
/* 31A8D8 802BE368 8E060018 */  lw        $a2, 0x18($s0)
/* 31A8DC 802BE36C 8E07000C */  lw        $a3, 0xc($s0)
/* 31A8E0 802BE370 0C00A7E7 */  jal       add_vec2D_polar
/* 31A8E4 802BE374 26050040 */   addiu    $a1, $s0, 0x40
/* 31A8E8 802BE378 26240028 */  addiu     $a0, $s1, 0x28
/* 31A8EC 802BE37C 8E060018 */  lw        $a2, 0x18($s0)
/* 31A8F0 802BE380 8E07000C */  lw        $a3, 0xc($s0)
/* 31A8F4 802BE384 0C00A7E7 */  jal       add_vec2D_polar
/* 31A8F8 802BE388 26250030 */   addiu    $a1, $s1, 0x30
/* 31A8FC 802BE38C C6000030 */  lwc1      $f0, 0x30($s0)
/* 31A900 802BE390 3C01802C */  lui       $at, %hi(D_802BEBA8_31B118)
/* 31A904 802BE394 D422EBA8 */  ldc1      $f2, %lo(D_802BEBA8_31B118)($at)
/* 31A908 802BE398 C6060010 */  lwc1      $f6, 0x10($s0)
/* 31A90C 802BE39C 46000021 */  cvt.d.s   $f0, $f0
/* 31A910 802BE3A0 46220001 */  sub.d     $f0, $f0, $f2
/* 31A914 802BE3A4 C6020018 */  lwc1      $f2, 0x18($s0)
/* 31A918 802BE3A8 3C013FF8 */  lui       $at, 0x3ff8
/* 31A91C 802BE3AC 44812800 */  mtc1      $at, $f5
/* 31A920 802BE3B0 44802000 */  mtc1      $zero, $f4
/* 31A924 802BE3B4 46023180 */  add.s     $f6, $f6, $f2
/* 31A928 802BE3B8 46200020 */  cvt.s.d   $f0, $f0
/* 31A92C 802BE3BC 460000A1 */  cvt.d.s   $f2, $f0
/* 31A930 802BE3C0 4624103C */  c.lt.d    $f2, $f4
/* 31A934 802BE3C4 E6000030 */  swc1      $f0, 0x30($s0)
/* 31A938 802BE3C8 45000005 */  bc1f      .L802BE3E0
/* 31A93C 802BE3CC E6060010 */   swc1     $f6, 0x10($s0)
/* 31A940 802BE3D0 3C013FC0 */  lui       $at, 0x3fc0
/* 31A944 802BE3D4 44810000 */  mtc1      $at, $f0
/* 31A948 802BE3D8 00000000 */  nop
/* 31A94C 802BE3DC E6000030 */  swc1      $f0, 0x30($s0)
.L802BE3E0:
/* 31A950 802BE3E0 C6020010 */  lwc1      $f2, 0x10($s0)
/* 31A954 802BE3E4 3C0142A0 */  lui       $at, 0x42a0
/* 31A958 802BE3E8 44810000 */  mtc1      $at, $f0
/* 31A95C 802BE3EC 00000000 */  nop
/* 31A960 802BE3F0 4602003C */  c.lt.s    $f0, $f2
/* 31A964 802BE3F4 00000000 */  nop
/* 31A968 802BE3F8 45000009 */  bc1f      .L802BE420
/* 31A96C 802BE3FC 00000000 */   nop
/* 31A970 802BE400 C6000030 */  lwc1      $f0, 0x30($s0)
/* 31A974 802BE404 3C013FE0 */  lui       $at, 0x3fe0
/* 31A978 802BE408 44811800 */  mtc1      $at, $f3
/* 31A97C 802BE40C 44801000 */  mtc1      $zero, $f2
/* 31A980 802BE410 46000021 */  cvt.d.s   $f0, $f0
/* 31A984 802BE414 46220000 */  add.d     $f0, $f0, $f2
/* 31A988 802BE418 46200020 */  cvt.s.d   $f0, $f0
/* 31A98C 802BE41C E6000030 */  swc1      $f0, 0x30($s0)
.L802BE420:
/* 31A990 802BE420 8E220004 */  lw        $v0, 4($s1)
/* 31A994 802BE424 30428000 */  andi      $v0, $v0, 0x8000
/* 31A998 802BE428 1440FE58 */  bnez      $v0, .L802BDD8C
/* 31A99C 802BE42C 3C040001 */   lui      $a0, 1
/* 31A9A0 802BE430 27B20020 */  addiu     $s2, $sp, 0x20
/* 31A9A4 802BE434 0240282D */  daddu     $a1, $s2, $zero
/* 31A9A8 802BE438 27B30024 */  addiu     $s3, $sp, 0x24
/* 31A9AC 802BE43C 0260302D */  daddu     $a2, $s3, $zero
/* 31A9B0 802BE440 27B40028 */  addiu     $s4, $sp, 0x28
/* 31A9B4 802BE444 C6200028 */  lwc1      $f0, 0x28($s1)
/* 31A9B8 802BE448 C622002C */  lwc1      $f2, 0x2c($s1)
/* 31A9BC 802BE44C C6240030 */  lwc1      $f4, 0x30($s1)
/* 31A9C0 802BE450 C6060018 */  lwc1      $f6, 0x18($s0)
/* 31A9C4 802BE454 0280382D */  daddu     $a3, $s4, $zero
/* 31A9C8 802BE458 E7A00020 */  swc1      $f0, 0x20($sp)
/* 31A9CC 802BE45C E7A20024 */  swc1      $f2, 0x24($sp)
/* 31A9D0 802BE460 E7A40028 */  swc1      $f4, 0x28($sp)
/* 31A9D4 802BE464 E7A60010 */  swc1      $f6, 0x10($sp)
/* 31A9D8 802BE468 C602000C */  lwc1      $f2, 0xc($s0)
/* 31A9DC 802BE46C 862200B0 */  lh        $v0, 0xb0($s1)
/* 31A9E0 802BE470 862300B2 */  lh        $v1, 0xb2($s1)
/* 31A9E4 802BE474 44820000 */  mtc1      $v0, $f0
/* 31A9E8 802BE478 00000000 */  nop
/* 31A9EC 802BE47C 46800020 */  cvt.s.w   $f0, $f0
/* 31A9F0 802BE480 E7A00018 */  swc1      $f0, 0x18($sp)
/* 31A9F4 802BE484 44830000 */  mtc1      $v1, $f0
/* 31A9F8 802BE488 00000000 */  nop
/* 31A9FC 802BE48C 46800020 */  cvt.s.w   $f0, $f0
/* 31AA00 802BE490 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 31AA04 802BE494 0C037765 */  jal       npc_test_move_complex_with_slipping
/* 31AA08 802BE498 E7A20014 */   swc1     $f2, 0x14($sp)
/* 31AA0C 802BE49C 10400007 */  beqz      $v0, .L802BE4BC
/* 31AA10 802BE4A0 3C040001 */   lui      $a0, 1
/* 31AA14 802BE4A4 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* 31AA18 802BE4A8 34840002 */   ori      $a0, $a0, 2
/* 31AA1C 802BE4AC 3C01802C */  lui       $at, %hi(D_802BEBC0_31CBE0)
/* 31AA20 802BE4B0 AC35EBC0 */  sw        $s5, %lo(D_802BEBC0_31CBE0)($at)
/* 31AA24 802BE4B4 080AF9E3 */  j         L802BE78C_31ACFC
/* 31AA28 802BE4B8 00000000 */   nop
.L802BE4BC:
/* 31AA2C 802BE4BC C6000038 */  lwc1      $f0, 0x38($s0)
/* 31AA30 802BE4C0 C602003C */  lwc1      $f2, 0x3c($s0)
/* 31AA34 802BE4C4 C6040040 */  lwc1      $f4, 0x40($s0)
/* 31AA38 802BE4C8 C6060018 */  lwc1      $f6, 0x18($s0)
/* 31AA3C 802BE4CC E7A00020 */  swc1      $f0, 0x20($sp)
/* 31AA40 802BE4D0 E7A20024 */  swc1      $f2, 0x24($sp)
/* 31AA44 802BE4D4 E7A40028 */  swc1      $f4, 0x28($sp)
/* 31AA48 802BE4D8 E7A60010 */  swc1      $f6, 0x10($sp)
/* 31AA4C 802BE4DC C600000C */  lwc1      $f0, 0xc($s0)
/* 31AA50 802BE4E0 0240282D */  daddu     $a1, $s2, $zero
/* 31AA54 802BE4E4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31AA58 802BE4E8 860200A8 */  lh        $v0, 0xa8($s0)
/* 31AA5C 802BE4EC 0260302D */  daddu     $a2, $s3, $zero
/* 31AA60 802BE4F0 44820000 */  mtc1      $v0, $f0
/* 31AA64 802BE4F4 00000000 */  nop
/* 31AA68 802BE4F8 46800020 */  cvt.s.w   $f0, $f0
/* 31AA6C 802BE4FC E7A00018 */  swc1      $f0, 0x18($sp)
/* 31AA70 802BE500 860200A6 */  lh        $v0, 0xa6($s0)
/* 31AA74 802BE504 0280382D */  daddu     $a3, $s4, $zero
/* 31AA78 802BE508 44820000 */  mtc1      $v0, $f0
/* 31AA7C 802BE50C 00000000 */  nop
/* 31AA80 802BE510 46800020 */  cvt.s.w   $f0, $f0
/* 31AA84 802BE514 0C037765 */  jal       npc_test_move_complex_with_slipping
/* 31AA88 802BE518 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 31AA8C 802BE51C 1440FE1B */  bnez      $v0, .L802BDD8C
/* 31AA90 802BE520 3C040001 */   lui      $a0, 1
/* 31AA94 802BE524 0000A82D */  daddu     $s5, $zero, $zero
/* 31AA98 802BE528 0240282D */  daddu     $a1, $s2, $zero
/* 31AA9C 802BE52C 0260302D */  daddu     $a2, $s3, $zero
/* 31AAA0 802BE530 860200A8 */  lh        $v0, 0xa8($s0)
/* 31AAA4 802BE534 3C013F00 */  lui       $at, 0x3f00
/* 31AAA8 802BE538 44810000 */  mtc1      $at, $f0
/* 31AAAC 802BE53C 44823000 */  mtc1      $v0, $f6
/* 31AAB0 802BE540 00000000 */  nop
/* 31AAB4 802BE544 468031A0 */  cvt.s.w   $f6, $f6
/* 31AAB8 802BE548 46003182 */  mul.s     $f6, $f6, $f0
/* 31AABC 802BE54C 00000000 */  nop
/* 31AAC0 802BE550 0280382D */  daddu     $a3, $s4, $zero
/* 31AAC4 802BE554 C6080038 */  lwc1      $f8, 0x38($s0)
/* 31AAC8 802BE558 C6040040 */  lwc1      $f4, 0x40($s0)
/* 31AACC 802BE55C 44821000 */  mtc1      $v0, $f2
/* 31AAD0 802BE560 00000000 */  nop
/* 31AAD4 802BE564 468010A0 */  cvt.s.w   $f2, $f2
/* 31AAD8 802BE568 46001082 */  mul.s     $f2, $f2, $f0
/* 31AADC 802BE56C 00000000 */  nop
/* 31AAE0 802BE570 C600003C */  lwc1      $f0, 0x3c($s0)
/* 31AAE4 802BE574 27A2002C */  addiu     $v0, $sp, 0x2c
/* 31AAE8 802BE578 E7A80020 */  swc1      $f8, 0x20($sp)
/* 31AAEC 802BE57C E7A40028 */  swc1      $f4, 0x28($sp)
/* 31AAF0 802BE580 46060000 */  add.s     $f0, $f0, $f6
/* 31AAF4 802BE584 46001506 */  mov.s     $f20, $f2
/* 31AAF8 802BE588 E7B4002C */  swc1      $f20, 0x2c($sp)
/* 31AAFC 802BE58C E7A00024 */  swc1      $f0, 0x24($sp)
/* 31AB00 802BE590 0C03739C */  jal       npc_raycast_up
/* 31AB04 802BE594 AFA20010 */   sw       $v0, 0x10($sp)
/* 31AB08 802BE598 10400013 */  beqz      $v0, .L802BE5E8
/* 31AB0C 802BE59C 00000000 */   nop
/* 31AB10 802BE5A0 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 31AB14 802BE5A4 4614003C */  c.lt.s    $f0, $f20
/* 31AB18 802BE5A8 00000000 */  nop
/* 31AB1C 802BE5AC 4500000E */  bc1f      .L802BE5E8
/* 31AB20 802BE5B0 00000000 */   nop
/* 31AB24 802BE5B4 860200A8 */  lh        $v0, 0xa8($s0)
/* 31AB28 802BE5B8 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 31AB2C 802BE5BC 44820000 */  mtc1      $v0, $f0
/* 31AB30 802BE5C0 00000000 */  nop
/* 31AB34 802BE5C4 46800020 */  cvt.s.w   $f0, $f0
/* 31AB38 802BE5C8 46001081 */  sub.s     $f2, $f2, $f0
/* 31AB3C 802BE5CC 3C014200 */  lui       $at, 0x4200
/* 31AB40 802BE5D0 44810000 */  mtc1      $at, $f0
/* 31AB44 802BE5D4 00000000 */  nop
/* 31AB48 802BE5D8 46001001 */  sub.s     $f0, $f2, $f0
/* 31AB4C 802BE5DC 24150001 */  addiu     $s5, $zero, 1
/* 31AB50 802BE5E0 E602003C */  swc1      $f2, 0x3c($s0)
/* 31AB54 802BE5E4 E620002C */  swc1      $f0, 0x2c($s1)
.L802BE5E8:
/* 31AB58 802BE5E8 862200B0 */  lh        $v0, 0xb0($s1)
/* 31AB5C 802BE5EC 3C013F00 */  lui       $at, 0x3f00
/* 31AB60 802BE5F0 44810000 */  mtc1      $at, $f0
/* 31AB64 802BE5F4 44823000 */  mtc1      $v0, $f6
/* 31AB68 802BE5F8 00000000 */  nop
/* 31AB6C 802BE5FC 468031A0 */  cvt.s.w   $f6, $f6
/* 31AB70 802BE600 46003182 */  mul.s     $f6, $f6, $f0
/* 31AB74 802BE604 00000000 */  nop
/* 31AB78 802BE608 3C040001 */  lui       $a0, 1
/* 31AB7C 802BE60C 27A50020 */  addiu     $a1, $sp, 0x20
/* 31AB80 802BE610 44822000 */  mtc1      $v0, $f4
/* 31AB84 802BE614 00000000 */  nop
/* 31AB88 802BE618 46802120 */  cvt.s.w   $f4, $f4
/* 31AB8C 802BE61C 46002102 */  mul.s     $f4, $f4, $f0
/* 31AB90 802BE620 00000000 */  nop
/* 31AB94 802BE624 C6200028 */  lwc1      $f0, 0x28($s1)
/* 31AB98 802BE628 27A2002C */  addiu     $v0, $sp, 0x2c
/* 31AB9C 802BE62C E7A00020 */  swc1      $f0, 0x20($sp)
/* 31ABA0 802BE630 C620002C */  lwc1      $f0, 0x2c($s1)
/* 31ABA4 802BE634 C6220030 */  lwc1      $f2, 0x30($s1)
/* 31ABA8 802BE638 46060000 */  add.s     $f0, $f0, $f6
/* 31ABAC 802BE63C E7A20028 */  swc1      $f2, 0x28($sp)
/* 31ABB0 802BE640 E7A4002C */  swc1      $f4, 0x2c($sp)
/* 31ABB4 802BE644 E7A00024 */  swc1      $f0, 0x24($sp)
/* 31ABB8 802BE648 AFA20010 */  sw        $v0, 0x10($sp)
/* 31ABBC 802BE64C C600000C */  lwc1      $f0, 0xc($s0)
/* 31ABC0 802BE650 27A60024 */  addiu     $a2, $sp, 0x24
/* 31ABC4 802BE654 E7A00014 */  swc1      $f0, 0x14($sp)
/* 31ABC8 802BE658 860200A6 */  lh        $v0, 0xa6($s0)
/* 31ABCC 802BE65C 27A70028 */  addiu     $a3, $sp, 0x28
/* 31ABD0 802BE660 44820000 */  mtc1      $v0, $f0
/* 31ABD4 802BE664 00000000 */  nop
/* 31ABD8 802BE668 46800020 */  cvt.s.w   $f0, $f0
/* 31ABDC 802BE66C 0C0371DE */  jal       npc_raycast_down_ahead
/* 31ABE0 802BE670 E7A00018 */   swc1     $f0, 0x18($sp)
/* 31ABE4 802BE674 10400018 */  beqz      $v0, .L802BE6D8
/* 31ABE8 802BE678 0200202D */   daddu    $a0, $s0, $zero
/* 31ABEC 802BE67C C7A00024 */  lwc1      $f0, 0x24($sp)
/* 31ABF0 802BE680 C624002C */  lwc1      $f4, 0x2c($s1)
/* 31ABF4 802BE684 46040001 */  sub.s     $f0, $f0, $f4
/* 31ABF8 802BE688 3C013E80 */  lui       $at, 0x3e80
/* 31ABFC 802BE68C 44811000 */  mtc1      $at, $f2
/* 31AC00 802BE690 00000000 */  nop
/* 31AC04 802BE694 46020002 */  mul.s     $f0, $f0, $f2
/* 31AC08 802BE698 00000000 */  nop
/* 31AC0C 802BE69C 46002100 */  add.s     $f4, $f4, $f0
/* 31AC10 802BE6A0 3C014200 */  lui       $at, 0x4200
/* 31AC14 802BE6A4 44810000 */  mtc1      $at, $f0
/* 31AC18 802BE6A8 00000000 */  nop
/* 31AC1C 802BE6AC 46002000 */  add.s     $f0, $f4, $f0
/* 31AC20 802BE6B0 E624002C */  swc1      $f4, 0x2c($s1)
/* 31AC24 802BE6B4 E600003C */  swc1      $f0, 0x3c($s0)
/* 31AC28 802BE6B8 C622002C */  lwc1      $f2, 0x2c($s1)
/* 31AC2C 802BE6BC 0000282D */  daddu     $a1, $zero, $zero
/* 31AC30 802BE6C0 E7A00024 */  swc1      $f0, 0x24($sp)
/* 31AC34 802BE6C4 0C00F598 */  jal       func_8003D660
/* 31AC38 802BE6C8 E602003C */   swc1     $f2, 0x3c($s0)
/* 31AC3C 802BE6CC C7A00024 */  lwc1      $f0, 0x24($sp)
/* 31AC40 802BE6D0 16A0002B */  bnez      $s5, .L802BE780
/* 31AC44 802BE6D4 E600003C */   swc1     $f0, 0x3c($s0)
.L802BE6D8:
/* 31AC48 802BE6D8 0C03954C */  jal       phys_adjust_cam_on_landing
/* 31AC4C 802BE6DC 00000000 */   nop
/* 31AC50 802BE6E0 14400006 */  bnez      $v0, .L802BE6FC
/* 31AC54 802BE6E4 00000000 */   nop
/* 31AC58 802BE6E8 3C03800B */  lui       $v1, %hi(gCameras)
/* 31AC5C 802BE6EC 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 31AC60 802BE6F0 94620002 */  lhu       $v0, 2($v1)
/* 31AC64 802BE6F4 3042FFFD */  andi      $v0, $v0, 0xfffd
/* 31AC68 802BE6F8 A4620002 */  sh        $v0, 2($v1)
.L802BE6FC:
/* 31AC6C 802BE6FC C6200028 */  lwc1      $f0, 0x28($s1)
/* 31AC70 802BE700 C622002C */  lwc1      $f2, 0x2c($s1)
/* 31AC74 802BE704 C6240030 */  lwc1      $f4, 0x30($s1)
/* 31AC78 802BE708 3C02800B */  lui       $v0, %hi(gCameras)
/* 31AC7C 802BE70C 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 31AC80 802BE710 E4400060 */  swc1      $f0, 0x60($v0)
/* 31AC84 802BE714 E4420064 */  swc1      $f2, 0x64($v0)
/* 31AC88 802BE718 E4440068 */  swc1      $f4, 0x68($v0)
/* 31AC8C 802BE71C 8E020000 */  lw        $v0, ($s0)
/* 31AC90 802BE720 30424000 */  andi      $v0, $v0, 0x4000
/* 31AC94 802BE724 1440FD99 */  bnez      $v0, .L802BDD8C
/* 31AC98 802BE728 3C040001 */   lui      $a0, 1
/* 31AC9C 802BE72C C6020010 */  lwc1      $f2, 0x10($s0)
/* 31ACA0 802BE730 9602008E */  lhu       $v0, 0x8e($s0)
/* 31ACA4 802BE734 3C0142C8 */  lui       $at, 0x42c8
/* 31ACA8 802BE738 44810000 */  mtc1      $at, $f0
/* 31ACAC 802BE73C 24420001 */  addiu     $v0, $v0, 1
/* 31ACB0 802BE740 4600103C */  c.lt.s    $f2, $f0
/* 31ACB4 802BE744 00000000 */  nop
/* 31ACB8 802BE748 45010010 */  bc1t      L802BE78C_31ACFC
/* 31ACBC 802BE74C A602008E */   sh       $v0, 0x8e($s0)
/* 31ACC0 802BE750 24020005 */  addiu     $v0, $zero, 5
/* 31ACC4 802BE754 3C01802C */  lui       $at, %hi(D_802BEBC4)
/* 31ACC8 802BE758 AC22EBC4 */  sw        $v0, %lo(D_802BEBC4)($at)
/* 31ACCC 802BE75C 080AF9E1 */  j         .L802BE784
/* 31ACD0 802BE760 24020006 */   addiu    $v0, $zero, 6
glabel L802BE764_31ACD4
/* 31ACD4 802BE764 3C03802C */  lui       $v1, %hi(D_802BEBC4)
/* 31ACD8 802BE768 2463EBC4 */  addiu     $v1, $v1, %lo(D_802BEBC4)
/* 31ACDC 802BE76C 8C620000 */  lw        $v0, ($v1)
/* 31ACE0 802BE770 10400003 */  beqz      $v0, .L802BE780
/* 31ACE4 802BE774 2442FFFF */   addiu    $v0, $v0, -1
/* 31ACE8 802BE778 080AF9E3 */  j         L802BE78C_31ACFC
/* 31ACEC 802BE77C AC620000 */   sw       $v0, ($v1)
.L802BE780:
/* 31ACF0 802BE780 24020015 */  addiu     $v0, $zero, 0x15
.L802BE784:
/* 31ACF4 802BE784 3C01802C */  lui       $at, %hi(D_802BEBC0_31CBE0)
/* 31ACF8 802BE788 AC22EBC0 */  sw        $v0, %lo(D_802BEBC0_31CBE0)($at)
glabel L802BE78C_31ACFC
/* 31ACFC 802BE78C 3C12802C */  lui       $s2, %hi(D_802BEBC0_31CBE0)
/* 31AD00 802BE790 2652EBC0 */  addiu     $s2, $s2, %lo(D_802BEBC0_31CBE0)
/* 31AD04 802BE794 8E420000 */  lw        $v0, ($s2)
/* 31AD08 802BE798 2442FFEC */  addiu     $v0, $v0, -0x14
/* 31AD0C 802BE79C 2C420003 */  sltiu     $v0, $v0, 3
/* 31AD10 802BE7A0 1040003B */  beqz      $v0, .L802BE890
/* 31AD14 802BE7A4 3C020004 */   lui      $v0, 4
/* 31AD18 802BE7A8 34420001 */  ori       $v0, $v0, 1
/* 31AD1C 802BE7AC 0200202D */  daddu     $a0, $s0, $zero
/* 31AD20 802BE7B0 AC820028 */  sw        $v0, 0x28($a0)
/* 31AD24 802BE7B4 8C820000 */  lw        $v0, ($a0)
/* 31AD28 802BE7B8 3C013F80 */  lui       $at, 0x3f80
/* 31AD2C 802BE7BC 44810000 */  mtc1      $at, $f0
/* 31AD30 802BE7C0 2403F7FF */  addiu     $v1, $zero, -0x801
/* 31AD34 802BE7C4 3C01802C */  lui       $at, %hi(D_802BEBB0)
/* 31AD38 802BE7C8 AC20EBB0 */  sw        $zero, %lo(D_802BEBB0)($at)
/* 31AD3C 802BE7CC AC80001C */  sw        $zero, 0x1c($a0)
/* 31AD40 802BE7D0 00431024 */  and       $v0, $v0, $v1
/* 31AD44 802BE7D4 AC820000 */  sw        $v0, ($a0)
/* 31AD48 802BE7D8 0C03BD17 */  jal       partner_clear_player_tracking
/* 31AD4C 802BE7DC E4800030 */   swc1     $f0, 0x30($a0)
/* 31AD50 802BE7E0 A2E00003 */  sb        $zero, 3($s7)
/* 31AD54 802BE7E4 0C03BCCA */  jal       enable_partner_ai
/* 31AD58 802BE7E8 A2E00000 */   sb       $zero, ($s7)
/* 31AD5C 802BE7EC 0C05271B */  jal       sfx_stop_sound
/* 31AD60 802BE7F0 24042009 */   addiu    $a0, $zero, 0x2009
/* 31AD64 802BE7F4 3C02802C */  lui       $v0, %hi(D_802BEBB4)
/* 31AD68 802BE7F8 8C42EBB4 */  lw        $v0, %lo(D_802BEBB4)($v0)
/* 31AD6C 802BE7FC 10400003 */  beqz      $v0, .L802BE80C
/* 31AD70 802BE800 00000000 */   nop
/* 31AD74 802BE804 0C038069 */  jal       enable_player_input
/* 31AD78 802BE808 00000000 */   nop
.L802BE80C:
/* 31AD7C 802BE80C 3C02802C */  lui       $v0, %hi(D_802BEBB8)
/* 31AD80 802BE810 8C42EBB8 */  lw        $v0, %lo(D_802BEBB8)($v0)
/* 31AD84 802BE814 10400003 */  beqz      $v0, .L802BE824
/* 31AD88 802BE818 00000000 */   nop
/* 31AD8C 802BE81C 0C038050 */  jal       enable_player_static_collisions
/* 31AD90 802BE820 00000000 */   nop
.L802BE824:
/* 31AD94 802BE824 8E220000 */  lw        $v0, ($s1)
/* 31AD98 802BE828 30420800 */  andi      $v0, $v0, 0x800
/* 31AD9C 802BE82C 14400014 */  bnez      $v0, .L802BE880
/* 31ADA0 802BE830 24040017 */   addiu    $a0, $zero, 0x17
/* 31ADA4 802BE834 8E430000 */  lw        $v1, ($s2)
/* 31ADA8 802BE838 24020014 */  addiu     $v0, $zero, 0x14
/* 31ADAC 802BE83C 14620005 */  bne       $v1, $v0, .L802BE854
/* 31ADB0 802BE840 24020015 */   addiu    $v0, $zero, 0x15
/* 31ADB4 802BE844 0C039823 */  jal       start_bounce_b
/* 31ADB8 802BE848 00000000 */   nop
/* 31ADBC 802BE84C 080AFA25 */  j         .L802BE894
/* 31ADC0 802BE850 24020002 */   addiu    $v0, $zero, 2
.L802BE854:
/* 31ADC4 802BE854 1462000A */  bne       $v1, $v0, .L802BE880
/* 31ADC8 802BE858 0000202D */   daddu    $a0, $zero, $zero
/* 31ADCC 802BE85C 0C0397F4 */  jal       start_falling
/* 31ADD0 802BE860 00000000 */   nop
/* 31ADD4 802BE864 0C038C1B */  jal       gravity_use_fall_parms
/* 31ADD8 802BE868 00000000 */   nop
/* 31ADDC 802BE86C 8E220000 */  lw        $v0, ($s1)
/* 31ADE0 802BE870 3C030080 */  lui       $v1, 0x80
/* 31ADE4 802BE874 00431025 */  or        $v0, $v0, $v1
/* 31ADE8 802BE878 080AF5C1 */  j         .L802BD704
/* 31ADEC 802BE87C AE220000 */   sw       $v0, ($s1)
.L802BE880:
/* 31ADF0 802BE880 0C039769 */  jal       set_action_state
/* 31ADF4 802BE884 00000000 */   nop
/* 31ADF8 802BE888 080AFA25 */  j         .L802BE894
/* 31ADFC 802BE88C 24020002 */   addiu    $v0, $zero, 2
.L802BE890:
/* 31AE00 802BE890 0000102D */  daddu     $v0, $zero, $zero
.L802BE894:
/* 31AE04 802BE894 8FBF005C */  lw        $ra, 0x5c($sp)
/* 31AE08 802BE898 8FBE0058 */  lw        $fp, 0x58($sp)
/* 31AE0C 802BE89C 8FB70054 */  lw        $s7, 0x54($sp)
/* 31AE10 802BE8A0 8FB60050 */  lw        $s6, 0x50($sp)
/* 31AE14 802BE8A4 8FB5004C */  lw        $s5, 0x4c($sp)
/* 31AE18 802BE8A8 8FB40048 */  lw        $s4, 0x48($sp)
/* 31AE1C 802BE8AC 8FB30044 */  lw        $s3, 0x44($sp)
/* 31AE20 802BE8B0 8FB20040 */  lw        $s2, 0x40($sp)
/* 31AE24 802BE8B4 8FB1003C */  lw        $s1, 0x3c($sp)
/* 31AE28 802BE8B8 8FB00038 */  lw        $s0, 0x38($sp)
/* 31AE2C 802BE8BC D7BA0078 */  ldc1      $f26, 0x78($sp)
/* 31AE30 802BE8C0 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 31AE34 802BE8C4 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 31AE38 802BE8C8 D7B40060 */  ldc1      $f20, 0x60($sp)
/* 31AE3C 802BE8CC 03E00008 */  jr        $ra
/* 31AE40 802BE8D0 27BD0080 */   addiu    $sp, $sp, 0x80
