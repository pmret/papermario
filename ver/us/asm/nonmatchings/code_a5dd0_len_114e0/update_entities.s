.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_entities
/* A5DD0 8010F6D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A5DD4 8010F6D4 AFB10014 */  sw        $s1, 0x14($sp)
/* A5DD8 8010F6D8 0000882D */  daddu     $s1, $zero, $zero
/* A5DDC 8010F6DC AFB3001C */  sw        $s3, 0x1c($sp)
/* A5DE0 8010F6E0 3C130200 */  lui       $s3, 0x200
/* A5DE4 8010F6E4 3C038015 */  lui       $v1, %hi(D_80151330)
/* A5DE8 8010F6E8 24631330 */  addiu     $v1, $v1, %lo(D_80151330)
/* A5DEC 8010F6EC AFBF0020 */  sw        $ra, 0x20($sp)
/* A5DF0 8010F6F0 AFB20018 */  sw        $s2, 0x18($sp)
/* A5DF4 8010F6F4 AFB00010 */  sw        $s0, 0x10($sp)
/* A5DF8 8010F6F8 8C620000 */  lw        $v0, ($v1)
/* A5DFC 8010F6FC 3C12800B */  lui       $s2, %hi(gCameras)
/* A5E00 8010F700 26521D80 */  addiu     $s2, $s2, %lo(gCameras)
/* A5E04 8010F704 3C018015 */  lui       $at, %hi(D_801512BC)
/* A5E08 8010F708 AC2012BC */  sw        $zero, %lo(D_801512BC)($at)
/* A5E0C 8010F70C 3C018015 */  lui       $at, %hi(D_801512C0)
/* A5E10 8010F710 AC2012C0 */  sw        $zero, %lo(D_801512C0)($at)
/* A5E14 8010F714 24420001 */  addiu     $v0, $v0, 1
/* A5E18 8010F718 AC620000 */  sw        $v0, ($v1)
.L8010F71C:
/* A5E1C 8010F71C 0C04417A */  jal       get_entity_by_index
/* A5E20 8010F720 0220202D */   daddu    $a0, $s1, $zero
/* A5E24 8010F724 0040802D */  daddu     $s0, $v0, $zero
/* A5E28 8010F728 520000CD */  beql      $s0, $zero, .L8010FA60
/* A5E2C 8010F72C 26310001 */   addiu    $s1, $s1, 1
/* A5E30 8010F730 3C028015 */  lui       $v0, %hi(D_801512C0)
/* A5E34 8010F734 244212C0 */  addiu     $v0, $v0, %lo(D_801512C0)
/* A5E38 8010F738 8C430000 */  lw        $v1, ($v0)
/* A5E3C 8010F73C 24630001 */  addiu     $v1, $v1, 1
/* A5E40 8010F740 AC430000 */  sw        $v1, ($v0)
/* A5E44 8010F744 8E030000 */  lw        $v1, ($s0)
/* A5E48 8010F748 3C024000 */  lui       $v0, 0x4000
/* A5E4C 8010F74C 00621024 */  and       $v0, $v1, $v0
/* A5E50 8010F750 544000C3 */  bnel      $v0, $zero, .L8010FA60
/* A5E54 8010F754 26310001 */   addiu    $s1, $s1, 1
/* A5E58 8010F758 3C020100 */  lui       $v0, 0x100
/* A5E5C 8010F75C 00621024 */  and       $v0, $v1, $v0
/* A5E60 8010F760 1040000D */  beqz      $v0, .L8010F798
/* A5E64 8010F764 3C02FEFF */   lui      $v0, 0xfeff
/* A5E68 8010F768 3442FFFF */  ori       $v0, $v0, 0xffff
/* A5E6C 8010F76C 00622024 */  and       $a0, $v1, $v0
/* A5E70 8010F770 30628000 */  andi      $v0, $v1, 0x8000
/* A5E74 8010F774 14400003 */  bnez      $v0, .L8010F784
/* A5E78 8010F778 AE040000 */   sw       $a0, ($s0)
/* A5E7C 8010F77C 00931025 */  or        $v0, $a0, $s3
/* A5E80 8010F780 AE020000 */  sw        $v0, ($s0)
.L8010F784:
/* A5E84 8010F784 2405000A */  addiu     $a1, $zero, 0xa
/* A5E88 8010F788 8E040028 */  lw        $a0, 0x28($s0)
/* A5E8C 8010F78C 0C0B0CF8 */  jal       start_script
/* A5E90 8010F790 24060020 */   addiu    $a2, $zero, 0x20
/* A5E94 8010F794 AE020024 */  sw        $v0, 0x24($s0)
.L8010F798:
/* A5E98 8010F798 8E020000 */  lw        $v0, ($s0)
/* A5E9C 8010F79C 00531024 */  and       $v0, $v0, $s3
/* A5EA0 8010F7A0 1040002D */  beqz      $v0, .L8010F858
/* A5EA4 8010F7A4 00000000 */   nop
/* A5EA8 8010F7A8 8E020024 */  lw        $v0, 0x24($s0)
/* A5EAC 8010F7AC 0C0B1059 */  jal       does_script_exist
/* A5EB0 8010F7B0 8C440144 */   lw       $a0, 0x144($v0)
/* A5EB4 8010F7B4 10400024 */  beqz      $v0, .L8010F848
/* A5EB8 8010F7B8 3C03FDFF */   lui      $v1, 0xfdff
/* A5EBC 8010F7BC 8E020000 */  lw        $v0, ($s0)
/* A5EC0 8010F7C0 30420008 */  andi      $v0, $v0, 8
/* A5EC4 8010F7C4 10400005 */  beqz      $v0, .L8010F7DC
/* A5EC8 8010F7C8 00000000 */   nop
/* A5ECC 8010F7CC 0C047A2F */  jal       func_8011E8BC
/* A5ED0 8010F7D0 86040014 */   lh       $a0, 0x14($s0)
/* A5ED4 8010F7D4 08043DF9 */  j         .L8010F7E4
/* A5ED8 8010F7D8 00000000 */   nop
.L8010F7DC:
/* A5EDC 8010F7DC 0C0483C1 */  jal       update_entity_rendercmd
/* A5EE0 8010F7E0 86040014 */   lh       $a0, 0x14($s0)
.L8010F7E4:
/* A5EE4 8010F7E4 8E020000 */  lw        $v0, ($s0)
/* A5EE8 8010F7E8 30422000 */  andi      $v0, $v0, 0x2000
/* A5EEC 8010F7EC 1040000E */  beqz      $v0, .L8010F828
/* A5EF0 8010F7F0 00000000 */   nop
/* A5EF4 8010F7F4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A5EF8 8010F7F8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A5EFC 8010F7FC 00031080 */  sll       $v0, $v1, 2
/* A5F00 8010F800 00431021 */  addu      $v0, $v0, $v1
/* A5F04 8010F804 00021080 */  sll       $v0, $v0, 2
/* A5F08 8010F808 00431023 */  subu      $v0, $v0, $v1
/* A5F0C 8010F80C 000218C0 */  sll       $v1, $v0, 3
/* A5F10 8010F810 00431021 */  addu      $v0, $v0, $v1
/* A5F14 8010F814 000210C0 */  sll       $v0, $v0, 3
/* A5F18 8010F818 00521021 */  addu      $v0, $v0, $s2
/* A5F1C 8010F81C C440006C */  lwc1      $f0, 0x6c($v0)
/* A5F20 8010F820 46000007 */  neg.s     $f0, $f0
/* A5F24 8010F824 E6000064 */  swc1      $f0, 0x64($s0)
.L8010F828:
/* A5F28 8010F828 8E020000 */  lw        $v0, ($s0)
/* A5F2C 8010F82C 30420010 */  andi      $v0, $v0, 0x10
/* A5F30 8010F830 5440008B */  bnel      $v0, $zero, .L8010FA60
/* A5F34 8010F834 26310001 */   addiu    $s1, $s1, 1
/* A5F38 8010F838 0C04408B */  jal       update_entity_transform_matrix
/* A5F3C 8010F83C 0200202D */   daddu    $a0, $s0, $zero
/* A5F40 8010F840 08043E98 */  j         .L8010FA60
/* A5F44 8010F844 26310001 */   addiu    $s1, $s1, 1
.L8010F848:
/* A5F48 8010F848 8E020000 */  lw        $v0, ($s0)
/* A5F4C 8010F84C 3463FFFF */  ori       $v1, $v1, 0xffff
/* A5F50 8010F850 00431024 */  and       $v0, $v0, $v1
/* A5F54 8010F854 AE020000 */  sw        $v0, ($s0)
.L8010F858:
/* A5F58 8010F858 82020007 */  lb        $v0, 7($s0)
/* A5F5C 8010F85C 92030007 */  lbu       $v1, 7($s0)
/* A5F60 8010F860 14400015 */  bnez      $v0, .L8010F8B8
/* A5F64 8010F864 2463FFFF */   addiu    $v1, $v1, -1
/* A5F68 8010F868 0C04422E */  jal       entity_get_collision_flags
/* A5F6C 8010F86C 0200202D */   daddu    $a0, $s0, $zero
/* A5F70 8010F870 A2020006 */  sb        $v0, 6($s0)
/* A5F74 8010F874 304200FF */  andi      $v0, $v0, 0xff
/* A5F78 8010F878 10400026 */  beqz      $v0, .L8010F914
/* A5F7C 8010F87C 00000000 */   nop
/* A5F80 8010F880 8E020038 */  lw        $v0, 0x38($s0)
/* A5F84 8010F884 8C420014 */  lw        $v0, 0x14($v0)
/* A5F88 8010F888 10400022 */  beqz      $v0, .L8010F914
/* A5F8C 8010F88C 00000000 */   nop
/* A5F90 8010F890 0040F809 */  jalr      $v0
/* A5F94 8010F894 0200202D */   daddu    $a0, $s0, $zero
/* A5F98 8010F898 1040001E */  beqz      $v0, .L8010F914
/* A5F9C 8010F89C 2402000A */   addiu    $v0, $zero, 0xa
/* A5FA0 8010F8A0 A2020007 */  sb        $v0, 7($s0)
/* A5FA4 8010F8A4 8E020000 */  lw        $v0, ($s0)
/* A5FA8 8010F8A8 3C030001 */  lui       $v1, 1
/* A5FAC 8010F8AC 00431025 */  or        $v0, $v0, $v1
/* A5FB0 8010F8B0 08043E45 */  j         .L8010F914
/* A5FB4 8010F8B4 AE020000 */   sw       $v0, ($s0)
.L8010F8B8:
/* A5FB8 8010F8B8 8E040000 */  lw        $a0, ($s0)
/* A5FBC 8010F8BC 30820040 */  andi      $v0, $a0, 0x40
/* A5FC0 8010F8C0 1040000A */  beqz      $v0, .L8010F8EC
/* A5FC4 8010F8C4 A2030007 */   sb       $v1, 7($s0)
/* A5FC8 8010F8C8 00031600 */  sll       $v0, $v1, 0x18
/* A5FCC 8010F8CC 14400005 */  bnez      $v0, .L8010F8E4
/* A5FD0 8010F8D0 34820020 */   ori      $v0, $a0, 0x20
/* A5FD4 8010F8D4 2402FF9F */  addiu     $v0, $zero, -0x61
/* A5FD8 8010F8D8 00821024 */  and       $v0, $a0, $v0
/* A5FDC 8010F8DC 08043E45 */  j         .L8010F914
/* A5FE0 8010F8E0 AE020000 */   sw       $v0, ($s0)
.L8010F8E4:
/* A5FE4 8010F8E4 08043E45 */  j         .L8010F914
/* A5FE8 8010F8E8 AE020000 */   sw       $v0, ($s0)
.L8010F8EC:
/* A5FEC 8010F8EC 00031600 */  sll       $v0, $v1, 0x18
/* A5FF0 8010F8F0 14400008 */  bnez      $v0, .L8010F914
/* A5FF4 8010F8F4 3C02FFFE */   lui      $v0, 0xfffe
/* A5FF8 8010F8F8 3442FFFF */  ori       $v0, $v0, 0xffff
/* A5FFC 8010F8FC 3C03FFFD */  lui       $v1, 0xfffd
/* A6000 8010F900 3463FFFF */  ori       $v1, $v1, 0xffff
/* A6004 8010F904 00821024 */  and       $v0, $a0, $v0
/* A6008 8010F908 00431024 */  and       $v0, $v0, $v1
/* A600C 8010F90C AE020000 */  sw        $v0, ($s0)
/* A6010 8010F910 A2000006 */  sb        $zero, 6($s0)
.L8010F914:
/* A6014 8010F914 8E020000 */  lw        $v0, ($s0)
/* A6018 8010F918 30422000 */  andi      $v0, $v0, 0x2000
/* A601C 8010F91C 1040000E */  beqz      $v0, .L8010F958
/* A6020 8010F920 00000000 */   nop
/* A6024 8010F924 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A6028 8010F928 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A602C 8010F92C 00031080 */  sll       $v0, $v1, 2
/* A6030 8010F930 00431021 */  addu      $v0, $v0, $v1
/* A6034 8010F934 00021080 */  sll       $v0, $v0, 2
/* A6038 8010F938 00431023 */  subu      $v0, $v0, $v1
/* A603C 8010F93C 000218C0 */  sll       $v1, $v0, 3
/* A6040 8010F940 00431021 */  addu      $v0, $v0, $v1
/* A6044 8010F944 000210C0 */  sll       $v0, $v0, 3
/* A6048 8010F948 00521021 */  addu      $v0, $v0, $s2
/* A604C 8010F94C C440006C */  lwc1      $f0, 0x6c($v0)
/* A6050 8010F950 46000007 */  neg.s     $f0, $f0
/* A6054 8010F954 E6000064 */  swc1      $f0, 0x64($s0)
.L8010F958:
/* A6058 8010F958 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A605C 8010F95C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A6060 8010F960 80420078 */  lb        $v0, 0x78($v0)
/* A6064 8010F964 14400014 */  bnez      $v0, .L8010F9B8
/* A6068 8010F968 00000000 */   nop
/* A606C 8010F96C 8E02001C */  lw        $v0, 0x1c($s0)
/* A6070 8010F970 10400003 */  beqz      $v0, .L8010F980
/* A6074 8010F974 00000000 */   nop
/* A6078 8010F978 0040F809 */  jalr      $v0
/* A607C 8010F97C 0200202D */   daddu    $a0, $s0, $zero
.L8010F980:
/* A6080 8010F980 8E020018 */  lw        $v0, 0x18($s0)
/* A6084 8010F984 1040000C */  beqz      $v0, .L8010F9B8
/* A6088 8010F988 00000000 */   nop
/* A608C 8010F98C 92020009 */  lbu       $v0, 9($s0)
/* A6090 8010F990 10400009 */  beqz      $v0, .L8010F9B8
/* A6094 8010F994 2442FFFF */   addiu    $v0, $v0, -1
/* A6098 8010F998 A2020009 */  sb        $v0, 9($s0)
/* A609C 8010F99C 304200FF */  andi      $v0, $v0, 0xff
/* A60A0 8010F9A0 14400005 */  bnez      $v0, .L8010F9B8
/* A60A4 8010F9A4 00000000 */   nop
.L8010F9A8:
/* A60A8 8010F9A8 0C043EF6 */  jal       step_entity_updatecmd
/* A60AC 8010F9AC 0200202D */   daddu    $a0, $s0, $zero
/* A60B0 8010F9B0 1440FFFD */  bnez      $v0, .L8010F9A8
/* A60B4 8010F9B4 00000000 */   nop
.L8010F9B8:
/* A60B8 8010F9B8 8E020000 */  lw        $v0, ($s0)
/* A60BC 8010F9BC 30420010 */  andi      $v0, $v0, 0x10
/* A60C0 8010F9C0 14400003 */  bnez      $v0, .L8010F9D0
/* A60C4 8010F9C4 00000000 */   nop
/* A60C8 8010F9C8 0C04408B */  jal       update_entity_transform_matrix
/* A60CC 8010F9CC 0200202D */   daddu    $a0, $s0, $zero
.L8010F9D0:
/* A60D0 8010F9D0 8E020000 */  lw        $v0, ($s0)
/* A60D4 8010F9D4 30420020 */  andi      $v0, $v0, 0x20
/* A60D8 8010F9D8 14400003 */  bnez      $v0, .L8010F9E8
/* A60DC 8010F9DC 00000000 */   nop
/* A60E0 8010F9E0 0C044129 */  jal       update_entity_inverse_rotation_matrix
/* A60E4 8010F9E4 0200202D */   daddu    $a0, $s0, $zero
.L8010F9E8:
/* A60E8 8010F9E8 8E020000 */  lw        $v0, ($s0)
/* A60EC 8010F9EC 30420008 */  andi      $v0, $v0, 8
/* A60F0 8010F9F0 10400005 */  beqz      $v0, .L8010FA08
/* A60F4 8010F9F4 00000000 */   nop
/* A60F8 8010F9F8 0C047A2F */  jal       func_8011E8BC
/* A60FC 8010F9FC 86040014 */   lh       $a0, 0x14($s0)
/* A6100 8010FA00 08043E84 */  j         .L8010FA10
/* A6104 8010FA04 00000000 */   nop
.L8010FA08:
/* A6108 8010FA08 0C0483C1 */  jal       update_entity_rendercmd
/* A610C 8010FA0C 86040014 */   lh       $a0, 0x14($s0)
.L8010FA10:
/* A6110 8010FA10 86020016 */  lh        $v0, 0x16($s0)
/* A6114 8010FA14 04400003 */  bltz      $v0, .L8010FA24
/* A6118 8010FA18 00000000 */   nop
/* A611C 8010FA1C 0C0448D1 */  jal       func_80112344
/* A6120 8010FA20 0200202D */   daddu    $a0, $s0, $zero
.L8010FA24:
/* A6124 8010FA24 8E020000 */  lw        $v0, ($s0)
/* A6128 8010FA28 3C032000 */  lui       $v1, 0x2000
/* A612C 8010FA2C 00431024 */  and       $v0, $v0, $v1
/* A6130 8010FA30 10400003 */  beqz      $v0, .L8010FA40
/* A6134 8010FA34 00000000 */   nop
/* A6138 8010FA38 0C0441B4 */  jal       delete_entity
/* A613C 8010FA3C 92040004 */   lbu      $a0, 4($s0)
.L8010FA40:
/* A6140 8010FA40 8E020000 */  lw        $v0, ($s0)
/* A6144 8010FA44 3C030400 */  lui       $v1, 0x400
/* A6148 8010FA48 00431024 */  and       $v0, $v0, $v1
/* A614C 8010FA4C 10400004 */  beqz      $v0, .L8010FA60
/* A6150 8010FA50 26310001 */   addiu    $s1, $s1, 1
/* A6154 8010FA54 92040004 */  lbu       $a0, 4($s0)
/* A6158 8010FA58 0C0441E4 */  jal       delete_entity_and_unload_data
/* A615C 8010FA5C 00000000 */   nop
.L8010FA60:
/* A6160 8010FA60 2A22001E */  slti      $v0, $s1, 0x1e
/* A6164 8010FA64 1440FF2D */  bnez      $v0, .L8010F71C
/* A6168 8010FA68 00000000 */   nop
/* A616C 8010FA6C 0C043EA6 */  jal       update_shadows
/* A6170 8010FA70 00000000 */   nop
/* A6174 8010FA74 8FBF0020 */  lw        $ra, 0x20($sp)
/* A6178 8010FA78 8FB3001C */  lw        $s3, 0x1c($sp)
/* A617C 8010FA7C 8FB20018 */  lw        $s2, 0x18($sp)
/* A6180 8010FA80 8FB10014 */  lw        $s1, 0x14($sp)
/* A6184 8010FA84 8FB00010 */  lw        $s0, 0x10($sp)
/* A6188 8010FA88 3C018016 */  lui       $at, %hi(D_8015A578)
/* A618C 8010FA8C A020A578 */  sb        $zero, %lo(D_8015A578)($at)
/* A6190 8010FA90 03E00008 */  jr        $ra
/* A6194 8010FA94 27BD0028 */   addiu    $sp, $sp, 0x28
