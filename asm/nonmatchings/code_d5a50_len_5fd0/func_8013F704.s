.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013F704
/* D5E04 8013F704 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* D5E08 8013F708 AFB3009C */  sw        $s3, 0x9c($sp)
/* D5E0C 8013F70C 0080982D */  daddu     $s3, $a0, $zero
/* D5E10 8013F710 AFBE00B0 */  sw        $fp, 0xb0($sp)
/* D5E14 8013F714 AFB700AC */  sw        $s7, 0xac($sp)
/* D5E18 8013F718 AFB600A8 */  sw        $s6, 0xa8($sp)
/* D5E1C 8013F71C AFB500A4 */  sw        $s5, 0xa4($sp)
/* D5E20 8013F720 AFB400A0 */  sw        $s4, 0xa0($sp)
/* D5E24 8013F724 AFB20098 */  sw        $s2, 0x98($sp)
/* D5E28 8013F728 AFB10094 */  sw        $s1, 0x94($sp)
/* D5E2C 8013F72C AFB00090 */  sw        $s0, 0x90($sp)
/* D5E30 8013F730 82680040 */  lb        $t0, 0x40($s3)
/* D5E34 8013F734 8E760034 */  lw        $s6, 0x34($s3)
/* D5E38 8013F738 00084280 */  sll       $t0, $t0, 0xa
/* D5E3C 8013F73C AFA8008C */  sw        $t0, 0x8c($sp)
/* D5E40 8013F740 16C00002 */  bnez      $s6, .L8013F74C
/* D5E44 8013F744 0116001A */   div      $zero, $t0, $s6
/* D5E48 8013F748 0007000D */  break     7
.L8013F74C:
/* D5E4C 8013F74C 2401FFFF */   addiu    $at, $zero, -1
/* D5E50 8013F750 16C10004 */  bne       $s6, $at, .L8013F764
/* D5E54 8013F754 3C018000 */   lui      $at, 0x8000
/* D5E58 8013F758 15010002 */  bne       $t0, $at, .L8013F764
/* D5E5C 8013F75C 00000000 */   nop
/* D5E60 8013F760 0006000D */  break     6
.L8013F764:
/* D5E64 8013F764 00004012 */   mflo     $t0
/* D5E68 8013F768 AFB6000C */  sw        $s6, 0xc($sp)
/* D5E6C 8013F76C AFA8008C */  sw        $t0, 0x8c($sp)
/* D5E70 8013F770 82690041 */  lb        $t1, 0x41($s3)
/* D5E74 8013F774 8E760038 */  lw        $s6, 0x38($s3)
/* D5E78 8013F778 00094A80 */  sll       $t1, $t1, 0xa
/* D5E7C 8013F77C 16C00002 */  bnez      $s6, .L8013F788
/* D5E80 8013F780 0136001A */   div      $zero, $t1, $s6
/* D5E84 8013F784 0007000D */  break     7
.L8013F788:
/* D5E88 8013F788 2401FFFF */   addiu    $at, $zero, -1
/* D5E8C 8013F78C 16C10004 */  bne       $s6, $at, .L8013F7A0
/* D5E90 8013F790 3C018000 */   lui      $at, 0x8000
/* D5E94 8013F794 15210002 */  bne       $t1, $at, .L8013F7A0
/* D5E98 8013F798 00000000 */   nop
/* D5E9C 8013F79C 0006000D */  break     6
.L8013F7A0:
/* D5EA0 8013F7A0 00004812 */   mflo     $t1
/* D5EA4 8013F7A4 00A0782D */  daddu     $t7, $a1, $zero
/* D5EA8 8013F7A8 00C0702D */  daddu     $t6, $a2, $zero
/* D5EAC 8013F7AC 97AB00CA */  lhu       $t3, 0xca($sp)
/* D5EB0 8013F7B0 00E0602D */  daddu     $t4, $a3, $zero
/* D5EB4 8013F7B4 AFB60010 */  sw        $s6, 0x10($sp)
/* D5EB8 8013F7B8 92620042 */  lbu       $v0, 0x42($s3)
/* D5EBC 8013F7BC 92640043 */  lbu       $a0, 0x43($s3)
/* D5EC0 8013F7C0 9663003C */  lhu       $v1, 0x3c($s3)
/* D5EC4 8013F7C4 8E700010 */  lw        $s0, 0x10($s3)
/* D5EC8 8013F7C8 8FB600D8 */  lw        $s6, 0xd8($sp)
/* D5ECC 8013F7CC 00021600 */  sll       $v0, $v0, 0x18
/* D5ED0 8013F7D0 00021603 */  sra       $v0, $v0, 0x18
/* D5ED4 8013F7D4 00042600 */  sll       $a0, $a0, 0x18
/* D5ED8 8013F7D8 00042603 */  sra       $a0, $a0, 0x18
/* D5EDC 8013F7DC 00681821 */  addu      $v1, $v1, $t0
/* D5EE0 8013F7E0 00431021 */  addu      $v0, $v0, $v1
/* D5EE4 8013F7E4 8FA800CC */  lw        $t0, 0xcc($sp)
/* D5EE8 8013F7E8 8FA300D0 */  lw        $v1, 0xd0($sp)
/* D5EEC 8013F7EC 01028821 */  addu      $s1, $t0, $v0
/* D5EF0 8013F7F0 9662003E */  lhu       $v0, 0x3e($s3)
/* D5EF4 8013F7F4 0220682D */  daddu     $t5, $s1, $zero
/* D5EF8 8013F7F8 00491021 */  addu      $v0, $v0, $t1
/* D5EFC 8013F7FC 00822021 */  addu      $a0, $a0, $v0
/* D5F00 8013F800 00641821 */  addu      $v1, $v1, $a0
/* D5F04 8013F804 8E690014 */  lw        $t1, 0x14($s3)
/* D5F08 8013F808 12C00003 */  beqz      $s6, .L8013F818
/* D5F0C 8013F80C 0060502D */   daddu    $t2, $v1, $zero
/* D5F10 8013F810 262D0002 */  addiu     $t5, $s1, 2
/* D5F14 8013F814 246A0002 */  addiu     $t2, $v1, 2
.L8013F818:
/* D5F18 8013F818 8E630000 */  lw        $v1, ($s3)
/* D5F1C 8013F81C AFA00008 */  sw        $zero, 8($sp)
/* D5F20 8013F820 30624000 */  andi      $v0, $v1, 0x4000
/* D5F24 8013F824 0002202B */  sltu      $a0, $zero, $v0
/* D5F28 8013F828 3C020008 */  lui       $v0, 8
/* D5F2C 8013F82C 00621024 */  and       $v0, $v1, $v0
/* D5F30 8013F830 0002282B */  sltu      $a1, $zero, $v0
/* D5F34 8013F834 30621000 */  andi      $v0, $v1, 0x1000
/* D5F38 8013F838 0002102B */  sltu      $v0, $zero, $v0
/* D5F3C 8013F83C 30632000 */  andi      $v1, $v1, 0x2000
/* D5F40 8013F840 0003182B */  sltu      $v1, $zero, $v1
/* D5F44 8013F844 AFA20000 */  sw        $v0, ($sp)
/* D5F48 8013F848 24020001 */  addiu     $v0, $zero, 1
/* D5F4C 8013F84C 14820003 */  bne       $a0, $v0, .L8013F85C
/* D5F50 8013F850 AFA30004 */   sw       $v1, 4($sp)
/* D5F54 8013F854 00A2402B */  sltu      $t0, $a1, $v0
/* D5F58 8013F858 AFA80008 */  sw        $t0, 8($sp)
.L8013F85C:
/* D5F5C 8013F85C 54800005 */  bnel      $a0, $zero, .L8013F874
/* D5F60 8013F860 24020001 */   addiu    $v0, $zero, 1
/* D5F64 8013F864 14A20003 */  bne       $a1, $v0, .L8013F874
/* D5F68 8013F868 24020001 */   addiu    $v0, $zero, 1
/* D5F6C 8013F86C 24160002 */  addiu     $s6, $zero, 2
/* D5F70 8013F870 AFB60008 */  sw        $s6, 8($sp)
.L8013F874:
/* D5F74 8013F874 14820006 */  bne       $a0, $v0, .L8013F890
/* D5F78 8013F878 24160006 */   addiu    $s6, $zero, 6
/* D5F7C 8013F87C 54A40005 */  bnel      $a1, $a0, .L8013F894
/* D5F80 8013F880 AFB60034 */   sw       $s6, 0x34($sp)
/* D5F84 8013F884 24080002 */  addiu     $t0, $zero, 2
/* D5F88 8013F888 AFA80008 */  sw        $t0, 8($sp)
/* D5F8C 8013F88C 24160006 */  addiu     $s6, $zero, 6
.L8013F890:
/* D5F90 8013F890 AFB60034 */  sw        $s6, 0x34($sp)
.L8013F894:
/* D5F94 8013F894 8E620000 */  lw        $v0, ($s3)
/* D5F98 8013F898 24080005 */  addiu     $t0, $zero, 5
/* D5F9C 8013F89C 30420010 */  andi      $v0, $v0, 0x10
/* D5FA0 8013F8A0 1440002C */  bnez      $v0, .L8013F954
/* D5FA4 8013F8A4 AFA80038 */   sw       $t0, 0x38($sp)
/* D5FA8 8013F8A8 000C1400 */  sll       $v0, $t4, 0x10
/* D5FAC 8013F8AC 00021C03 */  sra       $v1, $v0, 0x10
/* D5FB0 8013F8B0 24020010 */  addiu     $v0, $zero, 0x10
/* D5FB4 8013F8B4 1062000E */  beq       $v1, $v0, .L8013F8F0
/* D5FB8 8013F8B8 28620011 */   slti     $v0, $v1, 0x11
/* D5FBC 8013F8BC 10400005 */  beqz      $v0, .L8013F8D4
/* D5FC0 8013F8C0 24020008 */   addiu    $v0, $zero, 8
/* D5FC4 8013F8C4 10620008 */  beq       $v1, $v0, .L8013F8E8
/* D5FC8 8013F8C8 000B1400 */   sll      $v0, $t3, 0x10
/* D5FCC 8013F8CC 0804FE43 */  j         .L8013F90C
/* D5FD0 8013F8D0 00021C03 */   sra      $v1, $v0, 0x10
.L8013F8D4:
/* D5FD4 8013F8D4 24020020 */  addiu     $v0, $zero, 0x20
/* D5FD8 8013F8D8 10620008 */  beq       $v1, $v0, .L8013F8FC
/* D5FDC 8013F8DC 000B1400 */   sll      $v0, $t3, 0x10
/* D5FE0 8013F8E0 0804FE43 */  j         .L8013F90C
/* D5FE4 8013F8E4 00021C03 */   sra      $v1, $v0, 0x10
.L8013F8E8:
/* D5FE8 8013F8E8 0804FE40 */  j         .L8013F900
/* D5FEC 8013F8EC 24160003 */   addiu    $s6, $zero, 3
.L8013F8F0:
/* D5FF0 8013F8F0 24080004 */  addiu     $t0, $zero, 4
/* D5FF4 8013F8F4 0804FE41 */  j         .L8013F904
/* D5FF8 8013F8F8 AFA80034 */   sw       $t0, 0x34($sp)
.L8013F8FC:
/* D5FFC 8013F8FC 24160005 */  addiu     $s6, $zero, 5
.L8013F900:
/* D6000 8013F900 AFB60034 */  sw        $s6, 0x34($sp)
.L8013F904:
/* D6004 8013F904 000B1400 */  sll       $v0, $t3, 0x10
/* D6008 8013F908 00021C03 */  sra       $v1, $v0, 0x10
.L8013F90C:
/* D600C 8013F90C 24020010 */  addiu     $v0, $zero, 0x10
/* D6010 8013F910 1062000C */  beq       $v1, $v0, .L8013F944
/* D6014 8013F914 28620011 */   slti     $v0, $v1, 0x11
/* D6018 8013F918 10400005 */  beqz      $v0, .L8013F930
/* D601C 8013F91C 24020008 */   addiu    $v0, $zero, 8
/* D6020 8013F920 1062000B */  beq       $v1, $v0, .L8013F950
/* D6024 8013F924 24080003 */   addiu    $t0, $zero, 3
/* D6028 8013F928 0804FE55 */  j         .L8013F954
/* D602C 8013F92C 00000000 */   nop
.L8013F930:
/* D6030 8013F930 24020020 */  addiu     $v0, $zero, 0x20
/* D6034 8013F934 10620006 */  beq       $v1, $v0, .L8013F950
/* D6038 8013F938 24080005 */   addiu    $t0, $zero, 5
/* D603C 8013F93C 0804FE55 */  j         .L8013F954
/* D6040 8013F940 00000000 */   nop
.L8013F944:
/* D6044 8013F944 24160004 */  addiu     $s6, $zero, 4
/* D6048 8013F948 0804FE55 */  j         .L8013F954
/* D604C 8013F94C AFB60038 */   sw       $s6, 0x38($sp)
.L8013F950:
/* D6050 8013F950 AFA80038 */  sw        $t0, 0x38($sp)
.L8013F954:
/* D6054 8013F954 8FB60008 */  lw        $s6, 8($sp)
/* D6058 8013F958 24020001 */  addiu     $v0, $zero, 1
/* D605C 8013F95C 12C2000C */  beq       $s6, $v0, .L8013F990
/* D6060 8013F960 2AC20002 */   slti     $v0, $s6, 2
/* D6064 8013F964 10400005 */  beqz      $v0, .L8013F97C
/* D6068 8013F968 24020002 */   addiu    $v0, $zero, 2
/* D606C 8013F96C 12C00060 */  beqz      $s6, .L8013FAF0
/* D6070 8013F970 3C06E200 */   lui      $a2, 0xe200
/* D6074 8013F974 0804FECD */  j         .L8013FB34
/* D6078 8013F978 00000000 */   nop
.L8013F97C:
/* D607C 8013F97C 8FA80008 */  lw        $t0, 8($sp)
/* D6080 8013F980 1102005B */  beq       $t0, $v0, .L8013FAF0
/* D6084 8013F984 3C06E200 */   lui      $a2, 0xe200
/* D6088 8013F988 0804FECD */  j         .L8013FB34
/* D608C 8013F98C 00000000 */   nop
.L8013F990:
/* D6090 8013F990 8E630000 */  lw        $v1, ($s3)
/* D6094 8013F994 30620020 */  andi      $v0, $v1, 0x20
/* D6098 8013F998 14400012 */  bnez      $v0, .L8013F9E4
/* D609C 8013F99C 3C020080 */   lui      $v0, 0x80
/* D60A0 8013F9A0 00621024 */  and       $v0, $v1, $v0
/* D60A4 8013F9A4 14400008 */  bnez      $v0, .L8013F9C8
/* D60A8 8013F9A8 3C06E200 */   lui      $a2, 0xe200
/* D60AC 8013F9AC 34C6001C */  ori       $a2, $a2, 0x1c
/* D60B0 8013F9B0 3C050F0A */  lui       $a1, 0xf0a
/* D60B4 8013F9B4 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* D60B8 8013F9B8 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* D60BC 8013F9BC 8C820000 */  lw        $v0, ($a0)
/* D60C0 8013F9C0 0804FE89 */  j         .L8013FA24
/* D60C4 8013F9C4 34A57008 */   ori      $a1, $a1, 0x7008
.L8013F9C8:
/* D60C8 8013F9C8 34C6001C */  ori       $a2, $a2, 0x1c
/* D60CC 8013F9CC 3C050055 */  lui       $a1, 0x55
/* D60D0 8013F9D0 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* D60D4 8013F9D4 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* D60D8 8013F9D8 8C820000 */  lw        $v0, ($a0)
/* D60DC 8013F9DC 0804FE89 */  j         .L8013FA24
/* D60E0 8013F9E0 34A53048 */   ori      $a1, $a1, 0x3048
.L8013F9E4:
/* D60E4 8013F9E4 00621024 */  and       $v0, $v1, $v0
/* D60E8 8013F9E8 14400008 */  bnez      $v0, .L8013FA0C
/* D60EC 8013F9EC 3C06E200 */   lui      $a2, 0xe200
/* D60F0 8013F9F0 34C6001C */  ori       $a2, $a2, 0x1c
/* D60F4 8013F9F4 3C050050 */  lui       $a1, 0x50
/* D60F8 8013F9F8 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* D60FC 8013F9FC 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* D6100 8013FA00 8C820000 */  lw        $v0, ($a0)
/* D6104 8013FA04 0804FE89 */  j         .L8013FA24
/* D6108 8013FA08 34A54340 */   ori      $a1, $a1, 0x4340
.L8013FA0C:
/* D610C 8013FA0C 34C6001C */  ori       $a2, $a2, 0x1c
/* D6110 8013FA10 3C050050 */  lui       $a1, 0x50
/* D6114 8013FA14 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* D6118 8013FA18 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* D611C 8013FA1C 8C820000 */  lw        $v0, ($a0)
/* D6120 8013FA20 34A54348 */  ori       $a1, $a1, 0x4348
.L8013FA24:
/* D6124 8013FA24 0040182D */  daddu     $v1, $v0, $zero
/* D6128 8013FA28 24420008 */  addiu     $v0, $v0, 8
/* D612C 8013FA2C AC820000 */  sw        $v0, ($a0)
/* D6130 8013FA30 AC660000 */  sw        $a2, ($v1)
/* D6134 8013FA34 AC650004 */  sw        $a1, 4($v1)
/* D6138 8013FA38 3C03E300 */  lui       $v1, 0xe300
/* D613C 8013FA3C 34631001 */  ori       $v1, $v1, 0x1001
/* D6140 8013FA40 3C06F500 */  lui       $a2, 0xf500
/* D6144 8013FA44 34C60100 */  ori       $a2, $a2, 0x100
/* D6148 8013FA48 3C070703 */  lui       $a3, 0x703
/* D614C 8013FA4C 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* D6150 8013FA50 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* D6154 8013FA54 8C820000 */  lw        $v0, ($a0)
/* D6158 8013FA58 34E7C000 */  ori       $a3, $a3, 0xc000
/* D615C 8013FA5C 0040282D */  daddu     $a1, $v0, $zero
/* D6160 8013FA60 24420008 */  addiu     $v0, $v0, 8
/* D6164 8013FA64 AC820000 */  sw        $v0, ($a0)
/* D6168 8013FA68 ACA30000 */  sw        $v1, ($a1)
/* D616C 8013FA6C 34038000 */  ori       $v1, $zero, 0x8000
/* D6170 8013FA70 ACA30004 */  sw        $v1, 4($a1)
/* D6174 8013FA74 24430008 */  addiu     $v1, $v0, 8
/* D6178 8013FA78 AC830000 */  sw        $v1, ($a0)
/* D617C 8013FA7C 3C03FD10 */  lui       $v1, 0xfd10
/* D6180 8013FA80 AC430000 */  sw        $v1, ($v0)
/* D6184 8013FA84 24430010 */  addiu     $v1, $v0, 0x10
/* D6188 8013FA88 AC490004 */  sw        $t1, 4($v0)
/* D618C 8013FA8C AC830000 */  sw        $v1, ($a0)
/* D6190 8013FA90 3C03E800 */  lui       $v1, 0xe800
/* D6194 8013FA94 AC430008 */  sw        $v1, 8($v0)
/* D6198 8013FA98 24430018 */  addiu     $v1, $v0, 0x18
/* D619C 8013FA9C AC40000C */  sw        $zero, 0xc($v0)
/* D61A0 8013FAA0 AC830000 */  sw        $v1, ($a0)
/* D61A4 8013FAA4 3C030700 */  lui       $v1, 0x700
/* D61A8 8013FAA8 AC430014 */  sw        $v1, 0x14($v0)
/* D61AC 8013FAAC 24430020 */  addiu     $v1, $v0, 0x20
/* D61B0 8013FAB0 AC460010 */  sw        $a2, 0x10($v0)
/* D61B4 8013FAB4 AC830000 */  sw        $v1, ($a0)
/* D61B8 8013FAB8 3C03E600 */  lui       $v1, 0xe600
/* D61BC 8013FABC AC430018 */  sw        $v1, 0x18($v0)
/* D61C0 8013FAC0 24430028 */  addiu     $v1, $v0, 0x28
/* D61C4 8013FAC4 AC40001C */  sw        $zero, 0x1c($v0)
/* D61C8 8013FAC8 AC830000 */  sw        $v1, ($a0)
/* D61CC 8013FACC 3C03F000 */  lui       $v1, 0xf000
/* D61D0 8013FAD0 AC430020 */  sw        $v1, 0x20($v0)
/* D61D4 8013FAD4 24430030 */  addiu     $v1, $v0, 0x30
/* D61D8 8013FAD8 AC470024 */  sw        $a3, 0x24($v0)
/* D61DC 8013FADC AC830000 */  sw        $v1, ($a0)
/* D61E0 8013FAE0 3C03E700 */  lui       $v1, 0xe700
/* D61E4 8013FAE4 AC430028 */  sw        $v1, 0x28($v0)
/* D61E8 8013FAE8 0804FECD */  j         .L8013FB34
/* D61EC 8013FAEC AC40002C */   sw       $zero, 0x2c($v0)
.L8013FAF0:
/* D61F0 8013FAF0 34C6001C */  ori       $a2, $a2, 0x1c
/* D61F4 8013FAF4 3C050050 */  lui       $a1, 0x50
/* D61F8 8013FAF8 34A54240 */  ori       $a1, $a1, 0x4240
/* D61FC 8013FAFC 3C07E300 */  lui       $a3, 0xe300
/* D6200 8013FB00 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* D6204 8013FB04 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* D6208 8013FB08 8C820000 */  lw        $v0, ($a0)
/* D620C 8013FB0C 34E71001 */  ori       $a3, $a3, 0x1001
/* D6210 8013FB10 0040182D */  daddu     $v1, $v0, $zero
/* D6214 8013FB14 24420008 */  addiu     $v0, $v0, 8
/* D6218 8013FB18 AC820000 */  sw        $v0, ($a0)
/* D621C 8013FB1C AC660000 */  sw        $a2, ($v1)
/* D6220 8013FB20 AC650004 */  sw        $a1, 4($v1)
/* D6224 8013FB24 24430008 */  addiu     $v1, $v0, 8
/* D6228 8013FB28 AC830000 */  sw        $v1, ($a0)
/* D622C 8013FB2C AC470000 */  sw        $a3, ($v0)
/* D6230 8013FB30 AC400004 */  sw        $zero, 4($v0)
.L8013FB34:
/* D6234 8013FB34 8E620000 */  lw        $v0, ($s3)
/* D6238 8013FB38 30428000 */  andi      $v0, $v0, 0x8000
/* D623C 8013FB3C 1040000C */  beqz      $v0, .L8013FB70
/* D6240 8013FB40 3C05E300 */   lui      $a1, 0xe300
/* D6244 8013FB44 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* D6248 8013FB48 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* D624C 8013FB4C 8C620000 */  lw        $v0, ($v1)
/* D6250 8013FB50 34A51201 */  ori       $a1, $a1, 0x1201
/* D6254 8013FB54 0040202D */  daddu     $a0, $v0, $zero
/* D6258 8013FB58 24420008 */  addiu     $v0, $v0, 8
/* D625C 8013FB5C AC620000 */  sw        $v0, ($v1)
/* D6260 8013FB60 24023000 */  addiu     $v0, $zero, 0x3000
/* D6264 8013FB64 AC850000 */  sw        $a1, ($a0)
/* D6268 8013FB68 0804FEE5 */  j         .L8013FB94
/* D626C 8013FB6C AC820004 */   sw       $v0, 4($a0)
.L8013FB70:
/* D6270 8013FB70 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* D6274 8013FB74 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* D6278 8013FB78 8C820000 */  lw        $v0, ($a0)
/* D627C 8013FB7C 34A51201 */  ori       $a1, $a1, 0x1201
/* D6280 8013FB80 0040182D */  daddu     $v1, $v0, $zero
/* D6284 8013FB84 24420008 */  addiu     $v0, $v0, 8
/* D6288 8013FB88 AC820000 */  sw        $v0, ($a0)
/* D628C 8013FB8C AC650000 */  sw        $a1, ($v1)
/* D6290 8013FB90 AC600004 */  sw        $zero, 4($v1)
.L8013FB94:
/* D6294 8013FB94 000A1400 */  sll       $v0, $t2, 0x10
/* D6298 8013FB98 00021403 */  sra       $v0, $v0, 0x10
/* D629C 8013FB9C 0040B02D */  daddu     $s6, $v0, $zero
/* D62A0 8013FBA0 000E7400 */  sll       $t6, $t6, 0x10
/* D62A4 8013FBA4 000E4403 */  sra       $t0, $t6, 0x10
/* D62A8 8013FBA8 AFB60040 */  sw        $s6, 0x40($sp)
/* D62AC 8013FBAC 29160011 */  slti      $s6, $t0, 0x11
/* D62B0 8013FBB0 AFA20028 */  sw        $v0, 0x28($sp)
/* D62B4 8013FBB4 000B1400 */  sll       $v0, $t3, 0x10
/* D62B8 8013FBB8 00021403 */  sra       $v0, $v0, 0x10
/* D62BC 8013FBBC 3C014090 */  lui       $at, 0x4090
/* D62C0 8013FBC0 44812800 */  mtc1      $at, $f5
/* D62C4 8013FBC4 44802000 */  mtc1      $zero, $f4
/* D62C8 8013FBC8 000D6C00 */  sll       $t5, $t5, 0x10
/* D62CC 8013FBCC AFB60048 */  sw        $s6, 0x48($sp)
/* D62D0 8013FBD0 000DB403 */  sra       $s6, $t5, 0x10
/* D62D4 8013FBD4 AFA80044 */  sw        $t0, 0x44($sp)
/* D62D8 8013FBD8 8FA80028 */  lw        $t0, 0x28($sp)
/* D62DC 8013FBDC 000F7C00 */  sll       $t7, $t7, 0x10
/* D62E0 8013FBE0 AFA00024 */  sw        $zero, 0x24($sp)
/* D62E4 8013FBE4 AFA00020 */  sw        $zero, 0x20($sp)
/* D62E8 8013FBE8 AFAE003C */  sw        $t6, 0x3c($sp)
/* D62EC 8013FBEC AFA2004C */  sw        $v0, 0x4c($sp)
/* D62F0 8013FBF0 AFAD0054 */  sw        $t5, 0x54($sp)
/* D62F4 8013FBF4 AFB6005C */  sw        $s6, 0x5c($sp)
/* D62F8 8013FBF8 AFAF0058 */  sw        $t7, 0x58($sp)
/* D62FC 8013FBFC 01024021 */  addu      $t0, $t0, $v0
/* D6300 8013FC00 AFA80050 */  sw        $t0, 0x50($sp)
/* D6304 8013FC04 000F4403 */  sra       $t0, $t7, 0x10
/* D6308 8013FC08 29160011 */  slti      $s6, $t0, 0x11
/* D630C 8013FC0C 000C1400 */  sll       $v0, $t4, 0x10
/* D6310 8013FC10 00021403 */  sra       $v0, $v0, 0x10
/* D6314 8013FC14 AFA80060 */  sw        $t0, 0x60($sp)
/* D6318 8013FC18 AFB60064 */  sw        $s6, 0x64($sp)
/* D631C 8013FC1C AFA20068 */  sw        $v0, 0x68($sp)
.L8013FC20:
/* D6320 8013FC20 C7A00010 */  lwc1      $f0, 0x10($sp)
/* D6324 8013FC24 46800021 */  cvt.d.w   $f0, $f0
/* D6328 8013FC28 3C014040 */  lui       $at, 0x4040
/* D632C 8013FC2C 44811800 */  mtc1      $at, $f3
/* D6330 8013FC30 44801000 */  mtc1      $zero, $f2
/* D6334 8013FC34 46202003 */  div.d     $f0, $f4, $f0
/* D6338 8013FC38 46220002 */  mul.d     $f0, $f0, $f2
/* D633C 8013FC3C 00000000 */  nop
/* D6340 8013FC40 8FA80024 */  lw        $t0, 0x24($sp)
/* D6344 8013FC44 8FB60004 */  lw        $s6, 4($sp)
/* D6348 8013FC48 C7A20028 */  lwc1      $f2, 0x28($sp)
/* D634C 8013FC4C 468010A1 */  cvt.d.w   $f2, $f2
/* D6350 8013FC50 46201080 */  add.d     $f2, $f2, $f0
/* D6354 8013FC54 AFA00018 */  sw        $zero, 0x18($sp)
/* D6358 8013FC58 2505001F */  addiu     $a1, $t0, 0x1f
/* D635C 8013FC5C 4620118D */  trunc.w.d $f6, $f2
/* D6360 8013FC60 12C00004 */  beqz      $s6, .L8013FC74
/* D6364 8013FC64 E7A6002C */   swc1     $f6, 0x2c($sp)
/* D6368 8013FC68 8FA8003C */  lw        $t0, 0x3c($sp)
/* D636C 8013FC6C 00084403 */  sra       $t0, $t0, 0x10
/* D6370 8013FC70 AFA80018 */  sw        $t0, 0x18($sp)
.L8013FC74:
/* D6374 8013FC74 8FB6002C */  lw        $s6, 0x2c($sp)
/* D6378 8013FC78 06C0050D */  bltz      $s6, .L801410B0
/* D637C 8013FC7C 00000000 */   nop
/* D6380 8013FC80 8FA80028 */  lw        $t0, 0x28($sp)
/* D6384 8013FC84 290200F1 */  slti      $v0, $t0, 0xf1
/* D6388 8013FC88 10400509 */  beqz      $v0, .L801410B0
/* D638C 8013FC8C 2AC200F0 */   slti     $v0, $s6, 0xf0
/* D6390 8013FC90 1440000B */  bnez      $v0, .L8013FCC0
/* D6394 8013FC94 00000000 */   nop
/* D6398 8013FC98 8FB60024 */  lw        $s6, 0x24($sp)
/* D639C 8013FC9C 26C2010F */  addiu     $v0, $s6, 0x10f
/* D63A0 8013FCA0 8FA80040 */  lw        $t0, 0x40($sp)
/* D63A4 8013FCA4 241600F0 */  addiu     $s6, $zero, 0xf0
/* D63A8 8013FCA8 AFB6002C */  sw        $s6, 0x2c($sp)
/* D63AC 8013FCAC 01051821 */  addu      $v1, $t0, $a1
/* D63B0 8013FCB0 00431023 */  subu      $v0, $v0, $v1
/* D63B4 8013FCB4 2445FFFF */  addiu     $a1, $v0, -1
/* D63B8 8013FCB8 24080001 */  addiu     $t0, $zero, 1
/* D63BC 8013FCBC AFA80020 */  sw        $t0, 0x20($sp)
.L8013FCC0:
/* D63C0 8013FCC0 8FB60044 */  lw        $s6, 0x44($sp)
/* D63C4 8013FCC4 24A20001 */  addiu     $v0, $a1, 1
/* D63C8 8013FCC8 0056102A */  slt       $v0, $v0, $s6
/* D63CC 8013FCCC 1440000F */  bnez      $v0, .L8013FD0C
/* D63D0 8013FCD0 0000602D */   daddu    $t4, $zero, $zero
/* D63D4 8013FCD4 8FA80048 */  lw        $t0, 0x48($sp)
/* D63D8 8013FCD8 15000005 */  bnez      $t0, .L8013FCF0
/* D63DC 8013FCDC 26C5FFFF */   addiu    $a1, $s6, -1
/* D63E0 8013FCE0 8FB60050 */  lw        $s6, 0x50($sp)
/* D63E4 8013FCE4 26D6FFFF */  addiu     $s6, $s6, -1
/* D63E8 8013FCE8 0804FF40 */  j         .L8013FD00
/* D63EC 8013FCEC AFB6002C */   sw       $s6, 0x2c($sp)
.L8013FCF0:
/* D63F0 8013FCF0 8FA80040 */  lw        $t0, 0x40($sp)
/* D63F4 8013FCF4 8FB6004C */  lw        $s6, 0x4c($sp)
/* D63F8 8013FCF8 01164021 */  addu      $t0, $t0, $s6
/* D63FC 8013FCFC AFA8002C */  sw        $t0, 0x2c($sp)
.L8013FD00:
/* D6400 8013FD00 24080001 */  addiu     $t0, $zero, 1
/* D6404 8013FD04 AFA80020 */  sw        $t0, 0x20($sp)
/* D6408 8013FD08 0000602D */  daddu     $t4, $zero, $zero
.L8013FD0C:
/* D640C 8013FD0C 3C0A800A */  lui       $t2, %hi(gMasterGfxPos)
/* D6410 8013FD10 254AA66C */  addiu     $t2, $t2, %lo(gMasterGfxPos)
/* D6414 8013FD14 3C17E700 */  lui       $s7, 0xe700
/* D6418 8013FD18 3C040700 */  lui       $a0, 0x700
/* D641C 8013FD1C 3C1EE600 */  lui       $fp, 0xe600
/* D6420 8013FD20 8FB60054 */  lw        $s6, 0x54($sp)
/* D6424 8013FD24 8FA8005C */  lw        $t0, 0x5c($sp)
/* D6428 8013FD28 0016B403 */  sra       $s6, $s6, 0x10
/* D642C 8013FD2C AFB60030 */  sw        $s6, 0x30($sp)
/* D6430 8013FD30 8FB60068 */  lw        $s6, 0x68($sp)
/* D6434 8013FD34 0180682D */  daddu     $t5, $t4, $zero
/* D6438 8013FD38 AFA0001C */  sw        $zero, 0x1c($sp)
/* D643C 8013FD3C AFA00080 */  sw        $zero, 0x80($sp)
/* D6440 8013FD40 01164021 */  addu      $t0, $t0, $s6
/* D6444 8013FD44 AFA8006C */  sw        $t0, 0x6c($sp)
/* D6448 8013FD48 8FA80060 */  lw        $t0, 0x60($sp)
/* D644C 8013FD4C 8FB60038 */  lw        $s6, 0x38($sp)
/* D6450 8013FD50 2502FFFF */  addiu     $v0, $t0, -1
/* D6454 8013FD54 0016AB80 */  sll       $s5, $s6, 0xe
/* D6458 8013FD58 8FA80034 */  lw        $t0, 0x34($sp)
/* D645C 8013FD5C 8FB60024 */  lw        $s6, 0x24($sp)
/* D6460 8013FD60 30420FFF */  andi      $v0, $v0, 0xfff
/* D6464 8013FD64 AFA20070 */  sw        $v0, 0x70($sp)
/* D6468 8013FD68 0008A100 */  sll       $s4, $t0, 4
/* D646C 8013FD6C 02841025 */  or        $v0, $s4, $a0
/* D6470 8013FD70 02A29025 */  or        $s2, $s5, $v0
/* D6474 8013FD74 00161880 */  sll       $v1, $s6, 2
/* D6478 8013FD78 30630FFF */  andi      $v1, $v1, 0xfff
/* D647C 8013FD7C 3C02F400 */  lui       $v0, 0xf400
/* D6480 8013FD80 0062C825 */  or        $t9, $v1, $v0
/* D6484 8013FD84 00051080 */  sll       $v0, $a1, 2
/* D6488 8013FD88 304E0FFF */  andi      $t6, $v0, 0xfff
/* D648C 8013FD8C 01C4C025 */  or        $t8, $t6, $a0
/* D6490 8013FD90 02B48825 */  or        $s1, $s5, $s4
/* D6494 8013FD94 3C02F200 */  lui       $v0, %hi(D_F1FFFFFF)
/* D6498 8013FD98 00627825 */  or        $t7, $v1, $v0
/* D649C 8013FD9C 8FA80058 */  lw        $t0, 0x58($sp)
/* D64A0 8013FDA0 8FB60028 */  lw        $s6, 0x28($sp)
/* D64A4 8013FDA4 00081443 */  sra       $v0, $t0, 0x11
/* D64A8 8013FDA8 2442FFFF */  addiu     $v0, $v0, %lo(D_F1FFFFFF)
/* D64AC 8013FDAC 30420FFF */  andi      $v0, $v0, 0xfff
/* D64B0 8013FDB0 AFA20074 */  sw        $v0, 0x74($sp)
/* D64B4 8013FDB4 00161480 */  sll       $v0, $s6, 0x12
/* D64B8 8013FDB8 00021403 */  sra       $v0, $v0, 0x10
/* D64BC 8013FDBC 30480FFF */  andi      $t0, $v0, 0xfff
/* D64C0 8013FDC0 AFA20078 */  sw        $v0, 0x78($sp)
/* D64C4 8013FDC4 AFA8007C */  sw        $t0, 0x7c($sp)
.L8013FDC8:
/* D64C8 8013FDC8 C7A0000C */  lwc1      $f0, 0xc($sp)
/* D64CC 8013FDCC 46800021 */  cvt.d.w   $f0, $f0
/* D64D0 8013FDD0 3C014050 */  lui       $at, 0x4050
/* D64D4 8013FDD4 44811800 */  mtc1      $at, $f3
/* D64D8 8013FDD8 44801000 */  mtc1      $zero, $f2
/* D64DC 8013FDDC 46202003 */  div.d     $f0, $f4, $f0
/* D64E0 8013FDE0 46220002 */  mul.d     $f0, $f0, $f2
/* D64E4 8013FDE4 00000000 */  nop
/* D64E8 8013FDE8 8FB60000 */  lw        $s6, ($sp)
/* D64EC 8013FDEC C7A20030 */  lwc1      $f2, 0x30($sp)
/* D64F0 8013FDF0 468010A1 */  cvt.d.w   $f2, $f2
/* D64F4 8013FDF4 46201080 */  add.d     $f2, $f2, $f0
/* D64F8 8013FDF8 AFA00014 */  sw        $zero, 0x14($sp)
/* D64FC 8013FDFC 4620118D */  trunc.w.d $f6, $f2
/* D6500 8013FE00 E7A60088 */  swc1      $f6, 0x88($sp)
/* D6504 8013FE04 12C00004 */  beqz      $s6, .L8013FE18
/* D6508 8013FE08 258B003F */   addiu    $t3, $t4, 0x3f
/* D650C 8013FE0C 8FA80058 */  lw        $t0, 0x58($sp)
/* D6510 8013FE10 00084403 */  sra       $t0, $t0, 0x10
/* D6514 8013FE14 AFA80014 */  sw        $t0, 0x14($sp)
.L8013FE18:
/* D6518 8013FE18 8FB60088 */  lw        $s6, 0x88($sp)
/* D651C 8013FE1C 06C00490 */  bltz      $s6, .L80141060
/* D6520 8013FE20 00000000 */   nop
/* D6524 8013FE24 8FA80030 */  lw        $t0, 0x30($sp)
/* D6528 8013FE28 29020141 */  slti      $v0, $t0, 0x141
/* D652C 8013FE2C 1040048C */  beqz      $v0, .L80141060
/* D6530 8013FE30 2AC20140 */   slti     $v0, $s6, 0x140
/* D6534 8013FE34 14400009 */  bnez      $v0, .L8013FE5C
/* D6538 8013FE38 2582017F */   addiu    $v0, $t4, 0x17f
/* D653C 8013FE3C 8FB6005C */  lw        $s6, 0x5c($sp)
/* D6540 8013FE40 24080140 */  addiu     $t0, $zero, 0x140
/* D6544 8013FE44 AFA80088 */  sw        $t0, 0x88($sp)
/* D6548 8013FE48 02CB1821 */  addu      $v1, $s6, $t3
/* D654C 8013FE4C 00431023 */  subu      $v0, $v0, $v1
/* D6550 8013FE50 244BFFFF */  addiu     $t3, $v0, -1
/* D6554 8013FE54 24160001 */  addiu     $s6, $zero, 1
/* D6558 8013FE58 AFB6001C */  sw        $s6, 0x1c($sp)
.L8013FE5C:
/* D655C 8013FE5C 8FA80060 */  lw        $t0, 0x60($sp)
/* D6560 8013FE60 25620001 */  addiu     $v0, $t3, 1
/* D6564 8013FE64 0048102A */  slt       $v0, $v0, $t0
/* D6568 8013FE68 1440000E */  bnez      $v0, .L8013FEA4
/* D656C 8013FE6C 00000000 */   nop
/* D6570 8013FE70 8FB60064 */  lw        $s6, 0x64($sp)
/* D6574 8013FE74 16C00005 */  bnez      $s6, .L8013FE8C
/* D6578 8013FE78 250BFFFF */   addiu    $t3, $t0, -1
/* D657C 8013FE7C 8FA8006C */  lw        $t0, 0x6c($sp)
/* D6580 8013FE80 2508FFFF */  addiu     $t0, $t0, -1
/* D6584 8013FE84 0804FFA7 */  j         .L8013FE9C
/* D6588 8013FE88 AFA80088 */   sw       $t0, 0x88($sp)
.L8013FE8C:
/* D658C 8013FE8C 8FB6005C */  lw        $s6, 0x5c($sp)
/* D6590 8013FE90 8FA80068 */  lw        $t0, 0x68($sp)
/* D6594 8013FE94 02C8B021 */  addu      $s6, $s6, $t0
/* D6598 8013FE98 AFB60088 */  sw        $s6, 0x88($sp)
.L8013FE9C:
/* D659C 8013FE9C 24160001 */  addiu     $s6, $zero, 1
/* D65A0 8013FEA0 AFB6001C */  sw        $s6, 0x1c($sp)
.L8013FEA4:
/* D65A4 8013FEA4 8D420000 */  lw        $v0, ($t2)
/* D65A8 8013FEA8 0040182D */  daddu     $v1, $v0, $zero
/* D65AC 8013FEAC 24420008 */  addiu     $v0, $v0, 8
/* D65B0 8013FEB0 AD420000 */  sw        $v0, ($t2)
/* D65B4 8013FEB4 AC770000 */  sw        $s7, ($v1)
/* D65B8 8013FEB8 AC600004 */  sw        $zero, 4($v1)
/* D65BC 8013FEBC 8FA8001C */  lw        $t0, 0x1c($sp)
/* D65C0 8013FEC0 11000004 */  beqz      $t0, .L8013FED4
/* D65C4 8013FEC4 00000000 */   nop
/* D65C8 8013FEC8 8FB60020 */  lw        $s6, 0x20($sp)
/* D65CC 8013FECC 0804FFBC */  j         .L8013FEF0
/* D65D0 8013FED0 2EC90001 */   sltiu    $t1, $s6, 1
.L8013FED4:
/* D65D4 8013FED4 8FA80020 */  lw        $t0, 0x20($sp)
/* D65D8 8013FED8 15000007 */  bnez      $t0, .L8013FEF8
/* D65DC 8013FEDC 24090002 */   addiu    $t1, $zero, 2
/* D65E0 8013FEE0 11000005 */  beqz      $t0, .L8013FEF8
/* D65E4 8013FEE4 0000482D */   daddu    $t1, $zero, $zero
/* D65E8 8013FEE8 0804FFBE */  j         .L8013FEF8
/* D65EC 8013FEEC 24090002 */   addiu    $t1, $zero, 2
.L8013FEF0:
/* D65F0 8013FEF0 56C00001 */  bnel      $s6, $zero, .L8013FEF8
/* D65F4 8013FEF4 24090003 */   addiu    $t1, $zero, 3
.L8013FEF8:
/* D65F8 8013FEF8 8FA80008 */  lw        $t0, 8($sp)
/* D65FC 8013FEFC 24160001 */  addiu     $s6, $zero, 1
/* D6600 8013FF00 1116007C */  beq       $t0, $s6, .L801400F4
/* D6604 8013FF04 29020002 */   slti     $v0, $t0, 2
/* D6608 8013FF08 10400005 */  beqz      $v0, .L8013FF20
/* D660C 8013FF0C 24020002 */   addiu    $v0, $zero, 2
/* D6610 8013FF10 11000007 */  beqz      $t0, .L8013FF30
/* D6614 8013FF14 3C04FCFF */   lui      $a0, 0xfcff
/* D6618 8013FF18 0805032C */  j         .L80140CB0
/* D661C 8013FF1C 00000000 */   nop
.L8013FF20:
/* D6620 8013FF20 11020211 */  beq       $t0, $v0, .L80140768
/* D6624 8013FF24 3C04FC11 */   lui      $a0, 0xfc11
/* D6628 8013FF28 0805032C */  j         .L80140CB0
/* D662C 8013FF2C 00000000 */   nop
.L8013FF30:
/* D6630 8013FF30 3484FFFF */  ori       $a0, $a0, 0xffff
/* D6634 8013FF34 3C03FFFC */  lui       $v1, 0xfffc
/* D6638 8013FF38 8D450000 */  lw        $a1, ($t2)
/* D663C 8013FF3C 3463F279 */  ori       $v1, $v1, 0xf279
/* D6640 8013FF40 00A0102D */  daddu     $v0, $a1, $zero
/* D6644 8013FF44 AC440000 */  sw        $a0, ($v0)
/* D6648 8013FF48 AC430004 */  sw        $v1, 4($v0)
/* D664C 8013FF4C 8E620000 */  lw        $v0, ($s3)
/* D6650 8013FF50 24A50008 */  addiu     $a1, $a1, 8
/* D6654 8013FF54 30420020 */  andi      $v0, $v0, 0x20
/* D6658 8013FF58 10400005 */  beqz      $v0, .L8013FF70
/* D665C 8013FF5C AD450000 */   sw       $a1, ($t2)
/* D6660 8013FF60 3C04FCFF */  lui       $a0, 0xfcff
/* D6664 8013FF64 3484B3FF */  ori       $a0, $a0, 0xb3ff
/* D6668 8013FF68 3C03FF2C */  lui       $v1, 0xff2c
/* D666C 8013FF6C 3463FE7F */  ori       $v1, $v1, 0xfe7f
.L8013FF70:
/* D6670 8013FF70 24A20008 */  addiu     $v0, $a1, 8
/* D6674 8013FF74 AD420000 */  sw        $v0, ($t2)
/* D6678 8013FF78 ACA40000 */  sw        $a0, ($a1)
/* D667C 8013FF7C ACA30004 */  sw        $v1, 4($a1)
/* D6680 8013FF80 8E620000 */  lw        $v0, ($s3)
/* D6684 8013FF84 30420020 */  andi      $v0, $v0, 0x20
/* D6688 8013FF88 10400008 */  beqz      $v0, .L8013FFAC
/* D668C 8013FF8C 3C16FA00 */   lui      $s6, 0xfa00
/* D6690 8013FF90 8D420000 */  lw        $v0, ($t2)
/* D6694 8013FF94 0040182D */  daddu     $v1, $v0, $zero
/* D6698 8013FF98 24420008 */  addiu     $v0, $v0, 8
/* D669C 8013FF9C AD420000 */  sw        $v0, ($t2)
/* D66A0 8013FFA0 AC760000 */  sw        $s6, ($v1)
/* D66A4 8013FFA4 9262004A */  lbu       $v0, 0x4a($s3)
/* D66A8 8013FFA8 AC620004 */  sw        $v0, 4($v1)
.L8013FFAC:
/* D66AC 8013FFAC 8FA80000 */  lw        $t0, ($sp)
/* D66B0 8013FFB0 15000034 */  bnez      $t0, .L80140084
/* D66B4 8013FFB4 3C050704 */   lui      $a1, 0x704
/* D66B8 8013FFB8 8FB60004 */  lw        $s6, 4($sp)
/* D66BC 8013FFBC 16C00032 */  bnez      $s6, .L80140088
/* D66C0 8013FFC0 34A50100 */   ori      $a1, $a1, 0x100
/* D66C4 8013FFC4 3C02FD18 */  lui       $v0, 0xfd18
/* D66C8 8013FFC8 31A60FFF */  andi      $a2, $t5, 0xfff
/* D66CC 8013FFCC 00063300 */  sll       $a2, $a2, 0xc
/* D66D0 8013FFD0 000B2880 */  sll       $a1, $t3, 2
/* D66D4 8013FFD4 8D430000 */  lw        $v1, ($t2)
/* D66D8 8013FFD8 30A50FFF */  andi      $a1, $a1, 0xfff
/* D66DC 8013FFDC 0060202D */  daddu     $a0, $v1, $zero
/* D66E0 8013FFE0 24630008 */  addiu     $v1, $v1, 8
/* D66E4 8013FFE4 AD430000 */  sw        $v1, ($t2)
/* D66E8 8013FFE8 8FA80070 */  lw        $t0, 0x70($sp)
/* D66EC 8013FFEC 00052B00 */  sll       $a1, $a1, 0xc
/* D66F0 8013FFF0 AC900004 */  sw        $s0, 4($a0)
/* D66F4 8013FFF4 01021025 */  or        $v0, $t0, $v0
/* D66F8 8013FFF8 AC820000 */  sw        $v0, ($a0)
/* D66FC 8013FFFC 24620008 */  addiu     $v0, $v1, 8
/* D6700 80140000 016C2023 */  subu      $a0, $t3, $t4
/* D6704 80140004 00042040 */  sll       $a0, $a0, 1
/* D6708 80140008 24840009 */  addiu     $a0, $a0, 9
/* D670C 8014000C 000420C3 */  sra       $a0, $a0, 3
/* D6710 80140010 308401FF */  andi      $a0, $a0, 0x1ff
/* D6714 80140014 00042240 */  sll       $a0, $a0, 9
/* D6718 80140018 AD420000 */  sw        $v0, ($t2)
/* D671C 8014001C 3C02F518 */  lui       $v0, 0xf518
/* D6720 80140020 00822025 */  or        $a0, $a0, $v0
/* D6724 80140024 24620010 */  addiu     $v0, $v1, 0x10
/* D6728 80140028 AC640000 */  sw        $a0, ($v1)
/* D672C 8014002C AC720004 */  sw        $s2, 4($v1)
/* D6730 80140030 AD420000 */  sw        $v0, ($t2)
/* D6734 80140034 24620018 */  addiu     $v0, $v1, 0x18
/* D6738 80140038 AC7E0008 */  sw        $fp, 8($v1)
/* D673C 8014003C AC60000C */  sw        $zero, 0xc($v1)
/* D6740 80140040 AD420000 */  sw        $v0, ($t2)
/* D6744 80140044 00D91025 */  or        $v0, $a2, $t9
/* D6748 80140048 AC620010 */  sw        $v0, 0x10($v1)
/* D674C 8014004C 00B81025 */  or        $v0, $a1, $t8
/* D6750 80140050 AC620014 */  sw        $v0, 0x14($v1)
/* D6754 80140054 24620020 */  addiu     $v0, $v1, 0x20
/* D6758 80140058 AD420000 */  sw        $v0, ($t2)
/* D675C 8014005C 24620028 */  addiu     $v0, $v1, 0x28
/* D6760 80140060 AC770018 */  sw        $s7, 0x18($v1)
/* D6764 80140064 AC60001C */  sw        $zero, 0x1c($v1)
/* D6768 80140068 AD420000 */  sw        $v0, ($t2)
/* D676C 8014006C 24620030 */  addiu     $v0, $v1, 0x30
/* D6770 80140070 00CF3025 */  or        $a2, $a2, $t7
/* D6774 80140074 00AE2825 */  or        $a1, $a1, $t6
/* D6778 80140078 AC640020 */  sw        $a0, 0x20($v1)
/* D677C 8014007C 08050329 */  j         .L80140CA4
/* D6780 80140080 AC710024 */   sw       $s1, 0x24($v1)
.L80140084:
/* D6784 80140084 34A50100 */  ori       $a1, $a1, 0x100
.L80140088:
/* D6788 80140088 3C070004 */  lui       $a3, 4
/* D678C 8014008C 34E70100 */  ori       $a3, $a3, 0x100
/* D6790 80140090 3C02FD18 */  lui       $v0, 0xfd18
/* D6794 80140094 02852825 */  or        $a1, $s4, $a1
/* D6798 80140098 02A52825 */  or        $a1, $s5, $a1
/* D679C 8014009C 31A60FFF */  andi      $a2, $t5, 0xfff
/* D67A0 801400A0 00063300 */  sll       $a2, $a2, 0xc
/* D67A4 801400A4 8D430000 */  lw        $v1, ($t2)
/* D67A8 801400A8 02873825 */  or        $a3, $s4, $a3
/* D67AC 801400AC 0060202D */  daddu     $a0, $v1, $zero
/* D67B0 801400B0 24630008 */  addiu     $v1, $v1, 8
/* D67B4 801400B4 AD430000 */  sw        $v1, ($t2)
/* D67B8 801400B8 8FB60070 */  lw        $s6, 0x70($sp)
/* D67BC 801400BC 02A73825 */  or        $a3, $s5, $a3
/* D67C0 801400C0 AC900004 */  sw        $s0, 4($a0)
/* D67C4 801400C4 02C21025 */  or        $v0, $s6, $v0
/* D67C8 801400C8 AC820000 */  sw        $v0, ($a0)
/* D67CC 801400CC 24620008 */  addiu     $v0, $v1, 8
/* D67D0 801400D0 016C2023 */  subu      $a0, $t3, $t4
/* D67D4 801400D4 00042040 */  sll       $a0, $a0, 1
/* D67D8 801400D8 24840009 */  addiu     $a0, $a0, 9
/* D67DC 801400DC 000420C3 */  sra       $a0, $a0, 3
/* D67E0 801400E0 308401FF */  andi      $a0, $a0, 0x1ff
/* D67E4 801400E4 00042240 */  sll       $a0, $a0, 9
/* D67E8 801400E8 AD420000 */  sw        $v0, ($t2)
/* D67EC 801400EC 0805030E */  j         .L80140C38
/* D67F0 801400F0 3C02F518 */   lui      $v0, 0xf518
.L801400F4:
/* D67F4 801400F4 8FA800D8 */  lw        $t0, 0xd8($sp)
/* D67F8 801400F8 15000031 */  bnez      $t0, .L801401C0
/* D67FC 801400FC 3C06E200 */   lui      $a2, 0xe200
/* D6800 80140100 3C05FC30 */  lui       $a1, 0xfc30
/* D6804 80140104 34A5B261 */  ori       $a1, $a1, 0xb261
/* D6808 80140108 3C04FF2F */  lui       $a0, 0xff2f
/* D680C 8014010C 8D420000 */  lw        $v0, ($t2)
/* D6810 80140110 3484FFFF */  ori       $a0, $a0, 0xffff
/* D6814 80140114 0040182D */  daddu     $v1, $v0, $zero
/* D6818 80140118 24420008 */  addiu     $v0, $v0, 8
/* D681C 8014011C AD420000 */  sw        $v0, ($t2)
/* D6820 80140120 AC650000 */  sw        $a1, ($v1)
/* D6824 80140124 AC640004 */  sw        $a0, 4($v1)
/* D6828 80140128 8E620000 */  lw        $v0, ($s3)
/* D682C 8014012C 30420020 */  andi      $v0, $v0, 0x20
/* D6830 80140130 10400012 */  beqz      $v0, .L8014017C
/* D6834 80140134 3C16FA00 */   lui      $s6, 0xfa00
/* D6838 80140138 8D420000 */  lw        $v0, ($t2)
/* D683C 8014013C 0040282D */  daddu     $a1, $v0, $zero
/* D6840 80140140 24420008 */  addiu     $v0, $v0, 8
/* D6844 80140144 AD420000 */  sw        $v0, ($t2)
/* D6848 80140148 ACB60000 */  sw        $s6, ($a1)
/* D684C 8014014C 9262004B */  lbu       $v0, 0x4b($s3)
/* D6850 80140150 9263004C */  lbu       $v1, 0x4c($s3)
/* D6854 80140154 9264004D */  lbu       $a0, 0x4d($s3)
/* D6858 80140158 00021600 */  sll       $v0, $v0, 0x18
/* D685C 8014015C 00031C00 */  sll       $v1, $v1, 0x10
/* D6860 80140160 00431025 */  or        $v0, $v0, $v1
/* D6864 80140164 00042200 */  sll       $a0, $a0, 8
/* D6868 80140168 9263004A */  lbu       $v1, 0x4a($s3)
/* D686C 8014016C 00441025 */  or        $v0, $v0, $a0
/* D6870 80140170 00431025 */  or        $v0, $v0, $v1
/* D6874 80140174 08050088 */  j         .L80140220
/* D6878 80140178 ACA20004 */   sw       $v0, 4($a1)
.L8014017C:
/* D687C 8014017C 8D420000 */  lw        $v0, ($t2)
/* D6880 80140180 0040282D */  daddu     $a1, $v0, $zero
/* D6884 80140184 24420008 */  addiu     $v0, $v0, 8
/* D6888 80140188 3C08FA00 */  lui       $t0, 0xfa00
/* D688C 8014018C AD420000 */  sw        $v0, ($t2)
/* D6890 80140190 ACA80000 */  sw        $t0, ($a1)
/* D6894 80140194 9262004B */  lbu       $v0, 0x4b($s3)
/* D6898 80140198 9264004C */  lbu       $a0, 0x4c($s3)
/* D689C 8014019C 9263004D */  lbu       $v1, 0x4d($s3)
/* D68A0 801401A0 00021600 */  sll       $v0, $v0, 0x18
/* D68A4 801401A4 00042400 */  sll       $a0, $a0, 0x10
/* D68A8 801401A8 00441025 */  or        $v0, $v0, $a0
/* D68AC 801401AC 00031A00 */  sll       $v1, $v1, 8
/* D68B0 801401B0 00431025 */  or        $v0, $v0, $v1
/* D68B4 801401B4 344200FF */  ori       $v0, $v0, 0xff
/* D68B8 801401B8 08050088 */  j         .L80140220
/* D68BC 801401BC ACA20004 */   sw       $v0, 4($a1)
.L801401C0:
/* D68C0 801401C0 34C6001C */  ori       $a2, $a2, 0x1c
/* D68C4 801401C4 3C040050 */  lui       $a0, 0x50
/* D68C8 801401C8 34844240 */  ori       $a0, $a0, 0x4240
/* D68CC 801401CC 3C07FCFF */  lui       $a3, 0xfcff
/* D68D0 801401D0 34E797FF */  ori       $a3, $a3, 0x97ff
/* D68D4 801401D4 3C05FF2D */  lui       $a1, 0xff2d
/* D68D8 801401D8 34A5FEFF */  ori       $a1, $a1, 0xfeff
/* D68DC 801401DC 3C162828 */  lui       $s6, 0x2828
/* D68E0 801401E0 8D430000 */  lw        $v1, ($t2)
/* D68E4 801401E4 36D62848 */  ori       $s6, $s6, 0x2848
/* D68E8 801401E8 0060102D */  daddu     $v0, $v1, $zero
/* D68EC 801401EC 24630008 */  addiu     $v1, $v1, 8
/* D68F0 801401F0 AD430000 */  sw        $v1, ($t2)
/* D68F4 801401F4 AC460000 */  sw        $a2, ($v0)
/* D68F8 801401F8 AC440004 */  sw        $a0, 4($v0)
/* D68FC 801401FC 24620008 */  addiu     $v0, $v1, 8
/* D6900 80140200 AD420000 */  sw        $v0, ($t2)
/* D6904 80140204 24620010 */  addiu     $v0, $v1, 0x10
/* D6908 80140208 3C08FA00 */  lui       $t0, 0xfa00
/* D690C 8014020C AC670000 */  sw        $a3, ($v1)
/* D6910 80140210 AC650004 */  sw        $a1, 4($v1)
/* D6914 80140214 AD420000 */  sw        $v0, ($t2)
/* D6918 80140218 AC680008 */  sw        $t0, 8($v1)
/* D691C 8014021C AC76000C */  sw        $s6, 0xc($v1)
.L80140220:
/* D6920 80140220 8FB60000 */  lw        $s6, ($sp)
/* D6924 80140224 16C0010D */  bnez      $s6, .L8014065C
/* D6928 80140228 3C050704 */   lui      $a1, 0x704
/* D692C 8014022C 8FA80004 */  lw        $t0, 4($sp)
/* D6930 80140230 1500010B */  bnez      $t0, .L80140660
/* D6934 80140234 34A50100 */   ori      $a1, $a1, 0x100
/* D6938 80140238 8FB600D4 */  lw        $s6, 0xd4($sp)
/* D693C 8014023C 16C00033 */  bnez      $s6, .L8014030C
/* D6940 80140240 24080001 */   addiu    $t0, $zero, 1
/* D6944 80140244 8D440000 */  lw        $a0, ($t2)
/* D6948 80140248 0080182D */  daddu     $v1, $a0, $zero
/* D694C 8014024C 24840008 */  addiu     $a0, $a0, 8
/* D6950 80140250 AD440000 */  sw        $a0, ($t2)
/* D6954 80140254 8FA80074 */  lw        $t0, 0x74($sp)
/* D6958 80140258 3C02FD48 */  lui       $v0, 0xfd48
/* D695C 8014025C AC700004 */  sw        $s0, 4($v1)
/* D6960 80140260 01021025 */  or        $v0, $t0, $v0
/* D6964 80140264 AC620000 */  sw        $v0, ($v1)
/* D6968 80140268 24820008 */  addiu     $v0, $a0, 8
/* D696C 8014026C 016C1823 */  subu      $v1, $t3, $t4
/* D6970 80140270 24630001 */  addiu     $v1, $v1, 1
/* D6974 80140274 00031843 */  sra       $v1, $v1, 1
/* D6978 80140278 24630007 */  addiu     $v1, $v1, 7
/* D697C 8014027C 000318C3 */  sra       $v1, $v1, 3
/* D6980 80140280 306301FF */  andi      $v1, $v1, 0x1ff
/* D6984 80140284 00031A40 */  sll       $v1, $v1, 9
/* D6988 80140288 AD420000 */  sw        $v0, ($t2)
/* D698C 8014028C 3C02F548 */  lui       $v0, 0xf548
/* D6990 80140290 00621025 */  or        $v0, $v1, $v0
/* D6994 80140294 AC820000 */  sw        $v0, ($a0)
/* D6998 80140298 24820010 */  addiu     $v0, $a0, 0x10
/* D699C 8014029C AC920004 */  sw        $s2, 4($a0)
/* D69A0 801402A0 AD420000 */  sw        $v0, ($t2)
/* D69A4 801402A4 24820018 */  addiu     $v0, $a0, 0x18
/* D69A8 801402A8 AC9E0008 */  sw        $fp, 8($a0)
/* D69AC 801402AC AC80000C */  sw        $zero, 0xc($a0)
/* D69B0 801402B0 AD420000 */  sw        $v0, ($t2)
/* D69B4 801402B4 8FB60080 */  lw        $s6, 0x80($sp)
/* D69B8 801402B8 32C20FFF */  andi      $v0, $s6, 0xfff
/* D69BC 801402BC 00021300 */  sll       $v0, $v0, 0xc
/* D69C0 801402C0 00591025 */  or        $v0, $v0, $t9
/* D69C4 801402C4 AC820010 */  sw        $v0, 0x10($a0)
/* D69C8 801402C8 000B1040 */  sll       $v0, $t3, 1
/* D69CC 801402CC 30420FFF */  andi      $v0, $v0, 0xfff
/* D69D0 801402D0 00021300 */  sll       $v0, $v0, 0xc
/* D69D4 801402D4 00581025 */  or        $v0, $v0, $t8
/* D69D8 801402D8 AC820014 */  sw        $v0, 0x14($a0)
/* D69DC 801402DC 24820020 */  addiu     $v0, $a0, 0x20
/* D69E0 801402E0 AD420000 */  sw        $v0, ($t2)
/* D69E4 801402E4 24820028 */  addiu     $v0, $a0, 0x28
/* D69E8 801402E8 AC970018 */  sw        $s7, 0x18($a0)
/* D69EC 801402EC AC80001C */  sw        $zero, 0x1c($a0)
/* D69F0 801402F0 AD420000 */  sw        $v0, ($t2)
/* D69F4 801402F4 3C02F540 */  lui       $v0, 0xf540
/* D69F8 801402F8 00621825 */  or        $v1, $v1, $v0
/* D69FC 801402FC 24820030 */  addiu     $v0, $a0, 0x30
/* D6A00 80140300 AC830020 */  sw        $v1, 0x20($a0)
/* D6A04 80140304 080501CF */  j         .L8014073C
/* D6A08 80140308 AC910024 */   sw       $s1, 0x24($a0)
.L8014030C:
/* D6A0C 8014030C 1128003E */  beq       $t1, $t0, .L80140408
/* D6A10 80140310 29220002 */   slti     $v0, $t1, 2
/* D6A14 80140314 10400005 */  beqz      $v0, .L8014032C
/* D6A18 80140318 24020002 */   addiu    $v0, $zero, 2
/* D6A1C 8014031C 11200009 */  beqz      $t1, .L80140344
/* D6A20 80140320 3C02FD48 */   lui      $v0, 0xfd48
/* D6A24 80140324 0805032C */  j         .L80140CB0
/* D6A28 80140328 00000000 */   nop
.L8014032C:
/* D6A2C 8014032C 11220068 */  beq       $t1, $v0, .L801404D0
/* D6A30 80140330 24020003 */   addiu    $v0, $zero, 3
/* D6A34 80140334 11220098 */  beq       $t1, $v0, .L80140598
/* D6A38 80140338 3C02FD48 */   lui      $v0, 0xfd48
/* D6A3C 8014033C 0805032C */  j         .L80140CB0
/* D6A40 80140340 00000000 */   nop
.L80140344:
/* D6A44 80140344 8D440000 */  lw        $a0, ($t2)
/* D6A48 80140348 0080182D */  daddu     $v1, $a0, $zero
/* D6A4C 8014034C 24840008 */  addiu     $a0, $a0, 8
/* D6A50 80140350 AD440000 */  sw        $a0, ($t2)
/* D6A54 80140354 8FB60074 */  lw        $s6, 0x74($sp)
/* D6A58 80140358 AC700004 */  sw        $s0, 4($v1)
/* D6A5C 8014035C 02C21025 */  or        $v0, $s6, $v0
/* D6A60 80140360 AC620000 */  sw        $v0, ($v1)
/* D6A64 80140364 24820008 */  addiu     $v0, $a0, 8
/* D6A68 80140368 016C1823 */  subu      $v1, $t3, $t4
/* D6A6C 8014036C 24630001 */  addiu     $v1, $v1, 1
/* D6A70 80140370 00031843 */  sra       $v1, $v1, 1
/* D6A74 80140374 24630007 */  addiu     $v1, $v1, 7
/* D6A78 80140378 000318C3 */  sra       $v1, $v1, 3
/* D6A7C 8014037C 306301FF */  andi      $v1, $v1, 0x1ff
/* D6A80 80140380 00031A40 */  sll       $v1, $v1, 9
/* D6A84 80140384 AD420000 */  sw        $v0, ($t2)
/* D6A88 80140388 3C02F548 */  lui       $v0, 0xf548
/* D6A8C 8014038C 00621025 */  or        $v0, $v1, $v0
/* D6A90 80140390 AC820000 */  sw        $v0, ($a0)
/* D6A94 80140394 24820010 */  addiu     $v0, $a0, 0x10
/* D6A98 80140398 AC920004 */  sw        $s2, 4($a0)
/* D6A9C 8014039C AD420000 */  sw        $v0, ($t2)
/* D6AA0 801403A0 24820018 */  addiu     $v0, $a0, 0x18
/* D6AA4 801403A4 AC9E0008 */  sw        $fp, 8($a0)
/* D6AA8 801403A8 AC80000C */  sw        $zero, 0xc($a0)
/* D6AAC 801403AC AD420000 */  sw        $v0, ($t2)
/* D6AB0 801403B0 8FA80080 */  lw        $t0, 0x80($sp)
/* D6AB4 801403B4 31020FFF */  andi      $v0, $t0, 0xfff
/* D6AB8 801403B8 00021300 */  sll       $v0, $v0, 0xc
/* D6ABC 801403BC 00591025 */  or        $v0, $v0, $t9
/* D6AC0 801403C0 AC820010 */  sw        $v0, 0x10($a0)
/* D6AC4 801403C4 000B1040 */  sll       $v0, $t3, 1
/* D6AC8 801403C8 30420FFF */  andi      $v0, $v0, 0xfff
/* D6ACC 801403CC 00021300 */  sll       $v0, $v0, 0xc
/* D6AD0 801403D0 00581025 */  or        $v0, $v0, $t8
/* D6AD4 801403D4 AC820014 */  sw        $v0, 0x14($a0)
/* D6AD8 801403D8 24820020 */  addiu     $v0, $a0, 0x20
/* D6ADC 801403DC AD420000 */  sw        $v0, ($t2)
/* D6AE0 801403E0 24820028 */  addiu     $v0, $a0, 0x28
/* D6AE4 801403E4 AC970018 */  sw        $s7, 0x18($a0)
/* D6AE8 801403E8 AC80001C */  sw        $zero, 0x1c($a0)
/* D6AEC 801403EC AD420000 */  sw        $v0, ($t2)
/* D6AF0 801403F0 3C02F540 */  lui       $v0, 0xf540
/* D6AF4 801403F4 00621825 */  or        $v1, $v1, $v0
/* D6AF8 801403F8 24820030 */  addiu     $v0, $a0, 0x30
/* D6AFC 801403FC AC830020 */  sw        $v1, 0x20($a0)
/* D6B00 80140400 080501CF */  j         .L8014073C
/* D6B04 80140404 AC910024 */   sw       $s1, 0x24($a0)
.L80140408:
/* D6B08 80140408 8D440000 */  lw        $a0, ($t2)
/* D6B0C 8014040C 0080182D */  daddu     $v1, $a0, $zero
/* D6B10 80140410 24840008 */  addiu     $a0, $a0, 8
/* D6B14 80140414 AD440000 */  sw        $a0, ($t2)
/* D6B18 80140418 8FB60074 */  lw        $s6, 0x74($sp)
/* D6B1C 8014041C 3C02FD48 */  lui       $v0, 0xfd48
/* D6B20 80140420 AC700004 */  sw        $s0, 4($v1)
/* D6B24 80140424 02C21025 */  or        $v0, $s6, $v0
/* D6B28 80140428 AC620000 */  sw        $v0, ($v1)
/* D6B2C 8014042C 24820008 */  addiu     $v0, $a0, 8
/* D6B30 80140430 016C1823 */  subu      $v1, $t3, $t4
/* D6B34 80140434 24630001 */  addiu     $v1, $v1, 1
/* D6B38 80140438 00031843 */  sra       $v1, $v1, 1
/* D6B3C 8014043C 24630007 */  addiu     $v1, $v1, 7
/* D6B40 80140440 000318C3 */  sra       $v1, $v1, 3
/* D6B44 80140444 306301FF */  andi      $v1, $v1, 0x1ff
/* D6B48 80140448 00031A40 */  sll       $v1, $v1, 9
/* D6B4C 8014044C AD420000 */  sw        $v0, ($t2)
/* D6B50 80140450 3C02F548 */  lui       $v0, 0xf548
/* D6B54 80140454 00621025 */  or        $v0, $v1, $v0
/* D6B58 80140458 AC820000 */  sw        $v0, ($a0)
/* D6B5C 8014045C 24820010 */  addiu     $v0, $a0, 0x10
/* D6B60 80140460 AC920004 */  sw        $s2, 4($a0)
/* D6B64 80140464 AD420000 */  sw        $v0, ($t2)
/* D6B68 80140468 24820018 */  addiu     $v0, $a0, 0x18
/* D6B6C 8014046C AC9E0008 */  sw        $fp, 8($a0)
/* D6B70 80140470 AC80000C */  sw        $zero, 0xc($a0)
/* D6B74 80140474 AD420000 */  sw        $v0, ($t2)
/* D6B78 80140478 8FA80080 */  lw        $t0, 0x80($sp)
/* D6B7C 8014047C 31020FFF */  andi      $v0, $t0, 0xfff
/* D6B80 80140480 00021300 */  sll       $v0, $v0, 0xc
/* D6B84 80140484 00591025 */  or        $v0, $v0, $t9
/* D6B88 80140488 AC820010 */  sw        $v0, 0x10($a0)
/* D6B8C 8014048C 000B1040 */  sll       $v0, $t3, 1
/* D6B90 80140490 30420FFF */  andi      $v0, $v0, 0xfff
/* D6B94 80140494 00021300 */  sll       $v0, $v0, 0xc
/* D6B98 80140498 00581025 */  or        $v0, $v0, $t8
/* D6B9C 8014049C AC820014 */  sw        $v0, 0x14($a0)
/* D6BA0 801404A0 24820020 */  addiu     $v0, $a0, 0x20
/* D6BA4 801404A4 AD420000 */  sw        $v0, ($t2)
/* D6BA8 801404A8 24820028 */  addiu     $v0, $a0, 0x28
/* D6BAC 801404AC AC970018 */  sw        $s7, 0x18($a0)
/* D6BB0 801404B0 AC80001C */  sw        $zero, 0x1c($a0)
/* D6BB4 801404B4 AD420000 */  sw        $v0, ($t2)
/* D6BB8 801404B8 3C02F540 */  lui       $v0, 0xf540
/* D6BBC 801404BC 00621825 */  or        $v1, $v1, $v0
/* D6BC0 801404C0 24820030 */  addiu     $v0, $a0, 0x30
/* D6BC4 801404C4 AC830020 */  sw        $v1, 0x20($a0)
/* D6BC8 801404C8 080501CF */  j         .L8014073C
/* D6BCC 801404CC AC910024 */   sw       $s1, 0x24($a0)
.L801404D0:
/* D6BD0 801404D0 8D440000 */  lw        $a0, ($t2)
/* D6BD4 801404D4 0080182D */  daddu     $v1, $a0, $zero
/* D6BD8 801404D8 24840008 */  addiu     $a0, $a0, 8
/* D6BDC 801404DC AD440000 */  sw        $a0, ($t2)
/* D6BE0 801404E0 8FB60074 */  lw        $s6, 0x74($sp)
/* D6BE4 801404E4 3C02FD48 */  lui       $v0, 0xfd48
/* D6BE8 801404E8 AC700004 */  sw        $s0, 4($v1)
/* D6BEC 801404EC 02C21025 */  or        $v0, $s6, $v0
/* D6BF0 801404F0 AC620000 */  sw        $v0, ($v1)
/* D6BF4 801404F4 24820008 */  addiu     $v0, $a0, 8
/* D6BF8 801404F8 016C1823 */  subu      $v1, $t3, $t4
/* D6BFC 801404FC 24630001 */  addiu     $v1, $v1, 1
/* D6C00 80140500 00031843 */  sra       $v1, $v1, 1
/* D6C04 80140504 24630007 */  addiu     $v1, $v1, 7
/* D6C08 80140508 000318C3 */  sra       $v1, $v1, 3
/* D6C0C 8014050C 306301FF */  andi      $v1, $v1, 0x1ff
/* D6C10 80140510 00031A40 */  sll       $v1, $v1, 9
/* D6C14 80140514 AD420000 */  sw        $v0, ($t2)
/* D6C18 80140518 3C02F548 */  lui       $v0, 0xf548
/* D6C1C 8014051C 00621025 */  or        $v0, $v1, $v0
/* D6C20 80140520 AC820000 */  sw        $v0, ($a0)
/* D6C24 80140524 24820010 */  addiu     $v0, $a0, 0x10
/* D6C28 80140528 AC920004 */  sw        $s2, 4($a0)
/* D6C2C 8014052C AD420000 */  sw        $v0, ($t2)
/* D6C30 80140530 24820018 */  addiu     $v0, $a0, 0x18
/* D6C34 80140534 AC9E0008 */  sw        $fp, 8($a0)
/* D6C38 80140538 AC80000C */  sw        $zero, 0xc($a0)
/* D6C3C 8014053C AD420000 */  sw        $v0, ($t2)
/* D6C40 80140540 8FA80080 */  lw        $t0, 0x80($sp)
/* D6C44 80140544 31020FFF */  andi      $v0, $t0, 0xfff
/* D6C48 80140548 00021300 */  sll       $v0, $v0, 0xc
/* D6C4C 8014054C 00591025 */  or        $v0, $v0, $t9
/* D6C50 80140550 AC820010 */  sw        $v0, 0x10($a0)
/* D6C54 80140554 000B1040 */  sll       $v0, $t3, 1
/* D6C58 80140558 30420FFF */  andi      $v0, $v0, 0xfff
/* D6C5C 8014055C 00021300 */  sll       $v0, $v0, 0xc
/* D6C60 80140560 00581025 */  or        $v0, $v0, $t8
/* D6C64 80140564 AC820014 */  sw        $v0, 0x14($a0)
/* D6C68 80140568 24820020 */  addiu     $v0, $a0, 0x20
/* D6C6C 8014056C AD420000 */  sw        $v0, ($t2)
/* D6C70 80140570 24820028 */  addiu     $v0, $a0, 0x28
/* D6C74 80140574 AC970018 */  sw        $s7, 0x18($a0)
/* D6C78 80140578 AC80001C */  sw        $zero, 0x1c($a0)
/* D6C7C 8014057C AD420000 */  sw        $v0, ($t2)
/* D6C80 80140580 3C02F540 */  lui       $v0, 0xf540
/* D6C84 80140584 00621825 */  or        $v1, $v1, $v0
/* D6C88 80140588 24820030 */  addiu     $v0, $a0, 0x30
/* D6C8C 8014058C AC830020 */  sw        $v1, 0x20($a0)
/* D6C90 80140590 080501CF */  j         .L8014073C
/* D6C94 80140594 AC910024 */   sw       $s1, 0x24($a0)
.L80140598:
/* D6C98 80140598 8D440000 */  lw        $a0, ($t2)
/* D6C9C 8014059C 0080182D */  daddu     $v1, $a0, $zero
/* D6CA0 801405A0 24840008 */  addiu     $a0, $a0, 8
/* D6CA4 801405A4 AD440000 */  sw        $a0, ($t2)
/* D6CA8 801405A8 8FB60074 */  lw        $s6, 0x74($sp)
/* D6CAC 801405AC AC700004 */  sw        $s0, 4($v1)
/* D6CB0 801405B0 02C21025 */  or        $v0, $s6, $v0
/* D6CB4 801405B4 AC620000 */  sw        $v0, ($v1)
/* D6CB8 801405B8 24820008 */  addiu     $v0, $a0, 8
/* D6CBC 801405BC 016C1823 */  subu      $v1, $t3, $t4
/* D6CC0 801405C0 24630001 */  addiu     $v1, $v1, 1
/* D6CC4 801405C4 00031843 */  sra       $v1, $v1, 1
/* D6CC8 801405C8 24630007 */  addiu     $v1, $v1, 7
/* D6CCC 801405CC 000318C3 */  sra       $v1, $v1, 3
/* D6CD0 801405D0 306301FF */  andi      $v1, $v1, 0x1ff
/* D6CD4 801405D4 00031A40 */  sll       $v1, $v1, 9
/* D6CD8 801405D8 AD420000 */  sw        $v0, ($t2)
/* D6CDC 801405DC 3C02F548 */  lui       $v0, 0xf548
/* D6CE0 801405E0 00621025 */  or        $v0, $v1, $v0
/* D6CE4 801405E4 AC820000 */  sw        $v0, ($a0)
/* D6CE8 801405E8 24820010 */  addiu     $v0, $a0, 0x10
/* D6CEC 801405EC AC920004 */  sw        $s2, 4($a0)
/* D6CF0 801405F0 AD420000 */  sw        $v0, ($t2)
/* D6CF4 801405F4 24820018 */  addiu     $v0, $a0, 0x18
/* D6CF8 801405F8 AC9E0008 */  sw        $fp, 8($a0)
/* D6CFC 801405FC AC80000C */  sw        $zero, 0xc($a0)
/* D6D00 80140600 AD420000 */  sw        $v0, ($t2)
/* D6D04 80140604 8FA80080 */  lw        $t0, 0x80($sp)
/* D6D08 80140608 31020FFF */  andi      $v0, $t0, 0xfff
/* D6D0C 8014060C 00021300 */  sll       $v0, $v0, 0xc
/* D6D10 80140610 00591025 */  or        $v0, $v0, $t9
/* D6D14 80140614 AC820010 */  sw        $v0, 0x10($a0)
/* D6D18 80140618 000B1040 */  sll       $v0, $t3, 1
/* D6D1C 8014061C 30420FFF */  andi      $v0, $v0, 0xfff
/* D6D20 80140620 00021300 */  sll       $v0, $v0, 0xc
/* D6D24 80140624 00581025 */  or        $v0, $v0, $t8
/* D6D28 80140628 AC820014 */  sw        $v0, 0x14($a0)
/* D6D2C 8014062C 24820020 */  addiu     $v0, $a0, 0x20
/* D6D30 80140630 AD420000 */  sw        $v0, ($t2)
/* D6D34 80140634 24820028 */  addiu     $v0, $a0, 0x28
/* D6D38 80140638 AC970018 */  sw        $s7, 0x18($a0)
/* D6D3C 8014063C AC80001C */  sw        $zero, 0x1c($a0)
/* D6D40 80140640 AD420000 */  sw        $v0, ($t2)
/* D6D44 80140644 3C02F540 */  lui       $v0, 0xf540
/* D6D48 80140648 00621825 */  or        $v1, $v1, $v0
/* D6D4C 8014064C 24820030 */  addiu     $v0, $a0, 0x30
/* D6D50 80140650 AC830020 */  sw        $v1, 0x20($a0)
/* D6D54 80140654 080501CF */  j         .L8014073C
/* D6D58 80140658 AC910024 */   sw       $s1, 0x24($a0)
.L8014065C:
/* D6D5C 8014065C 34A50100 */  ori       $a1, $a1, 0x100
.L80140660:
/* D6D60 80140660 3C060004 */  lui       $a2, 4
/* D6D64 80140664 34C60100 */  ori       $a2, $a2, 0x100
/* D6D68 80140668 3C02FD48 */  lui       $v0, 0xfd48
/* D6D6C 8014066C 02852825 */  or        $a1, $s4, $a1
/* D6D70 80140670 8D440000 */  lw        $a0, ($t2)
/* D6D74 80140674 02A52825 */  or        $a1, $s5, $a1
/* D6D78 80140678 0080182D */  daddu     $v1, $a0, $zero
/* D6D7C 8014067C 24840008 */  addiu     $a0, $a0, 8
/* D6D80 80140680 AD440000 */  sw        $a0, ($t2)
/* D6D84 80140684 8FB60074 */  lw        $s6, 0x74($sp)
/* D6D88 80140688 02863025 */  or        $a2, $s4, $a2
/* D6D8C 8014068C AC700004 */  sw        $s0, 4($v1)
/* D6D90 80140690 02C21025 */  or        $v0, $s6, $v0
/* D6D94 80140694 AC620000 */  sw        $v0, ($v1)
/* D6D98 80140698 24820008 */  addiu     $v0, $a0, 8
/* D6D9C 8014069C 016C1823 */  subu      $v1, $t3, $t4
/* D6DA0 801406A0 24630001 */  addiu     $v1, $v1, 1
/* D6DA4 801406A4 00031843 */  sra       $v1, $v1, 1
/* D6DA8 801406A8 24630007 */  addiu     $v1, $v1, 7
/* D6DAC 801406AC 000318C3 */  sra       $v1, $v1, 3
/* D6DB0 801406B0 306301FF */  andi      $v1, $v1, 0x1ff
/* D6DB4 801406B4 00031A40 */  sll       $v1, $v1, 9
/* D6DB8 801406B8 AD420000 */  sw        $v0, ($t2)
/* D6DBC 801406BC 3C02F548 */  lui       $v0, 0xf548
/* D6DC0 801406C0 00621025 */  or        $v0, $v1, $v0
/* D6DC4 801406C4 AC820000 */  sw        $v0, ($a0)
/* D6DC8 801406C8 24820010 */  addiu     $v0, $a0, 0x10
/* D6DCC 801406CC AC850004 */  sw        $a1, 4($a0)
/* D6DD0 801406D0 AD420000 */  sw        $v0, ($t2)
/* D6DD4 801406D4 24820018 */  addiu     $v0, $a0, 0x18
/* D6DD8 801406D8 AC9E0008 */  sw        $fp, 8($a0)
/* D6DDC 801406DC AC80000C */  sw        $zero, 0xc($a0)
/* D6DE0 801406E0 AD420000 */  sw        $v0, ($t2)
/* D6DE4 801406E4 8FA80080 */  lw        $t0, 0x80($sp)
/* D6DE8 801406E8 02A63025 */  or        $a2, $s5, $a2
/* D6DEC 801406EC 31020FFF */  andi      $v0, $t0, 0xfff
/* D6DF0 801406F0 00021300 */  sll       $v0, $v0, 0xc
/* D6DF4 801406F4 00591025 */  or        $v0, $v0, $t9
/* D6DF8 801406F8 AC820010 */  sw        $v0, 0x10($a0)
/* D6DFC 801406FC 000B1040 */  sll       $v0, $t3, 1
/* D6E00 80140700 30420FFF */  andi      $v0, $v0, 0xfff
/* D6E04 80140704 00021300 */  sll       $v0, $v0, 0xc
/* D6E08 80140708 00581025 */  or        $v0, $v0, $t8
/* D6E0C 8014070C AC820014 */  sw        $v0, 0x14($a0)
/* D6E10 80140710 24820020 */  addiu     $v0, $a0, 0x20
/* D6E14 80140714 AD420000 */  sw        $v0, ($t2)
/* D6E18 80140718 24820028 */  addiu     $v0, $a0, 0x28
/* D6E1C 8014071C AC970018 */  sw        $s7, 0x18($a0)
/* D6E20 80140720 AC80001C */  sw        $zero, 0x1c($a0)
/* D6E24 80140724 AD420000 */  sw        $v0, ($t2)
/* D6E28 80140728 3C02F540 */  lui       $v0, 0xf540
/* D6E2C 8014072C 00621825 */  or        $v1, $v1, $v0
/* D6E30 80140730 24820030 */  addiu     $v0, $a0, 0x30
/* D6E34 80140734 AC830020 */  sw        $v1, 0x20($a0)
/* D6E38 80140738 AC860024 */  sw        $a2, 0x24($a0)
.L8014073C:
/* D6E3C 8014073C AD420000 */  sw        $v0, ($t2)
/* D6E40 80140740 31A20FFF */  andi      $v0, $t5, 0xfff
/* D6E44 80140744 00021300 */  sll       $v0, $v0, 0xc
/* D6E48 80140748 004F1025 */  or        $v0, $v0, $t7
/* D6E4C 8014074C AC820028 */  sw        $v0, 0x28($a0)
/* D6E50 80140750 000B1080 */  sll       $v0, $t3, 2
/* D6E54 80140754 30420FFF */  andi      $v0, $v0, 0xfff
/* D6E58 80140758 00021300 */  sll       $v0, $v0, 0xc
/* D6E5C 8014075C 004E1025 */  or        $v0, $v0, $t6
/* D6E60 80140760 0805032C */  j         .L80140CB0
/* D6E64 80140764 AC82002C */   sw       $v0, 0x2c($a0)
.L80140768:
/* D6E68 80140768 3484B223 */  ori       $a0, $a0, 0xb223
/* D6E6C 8014076C 3C03FF67 */  lui       $v1, 0xff67
/* D6E70 80140770 8D470000 */  lw        $a3, ($t2)
/* D6E74 80140774 3463FFFF */  ori       $v1, $v1, 0xffff
/* D6E78 80140778 00E0102D */  daddu     $v0, $a3, $zero
/* D6E7C 8014077C 24E70008 */  addiu     $a3, $a3, 8
/* D6E80 80140780 AD470000 */  sw        $a3, ($t2)
/* D6E84 80140784 AC440000 */  sw        $a0, ($v0)
/* D6E88 80140788 AC430004 */  sw        $v1, 4($v0)
/* D6E8C 8014078C 24E20008 */  addiu     $v0, $a3, 8
/* D6E90 80140790 3C16FA00 */  lui       $s6, 0xfa00
/* D6E94 80140794 AD420000 */  sw        $v0, ($t2)
/* D6E98 80140798 ACF60000 */  sw        $s6, ($a3)
/* D6E9C 8014079C 9262004B */  lbu       $v0, 0x4b($s3)
/* D6EA0 801407A0 9263004C */  lbu       $v1, 0x4c($s3)
/* D6EA4 801407A4 9264004D */  lbu       $a0, 0x4d($s3)
/* D6EA8 801407A8 00021600 */  sll       $v0, $v0, 0x18
/* D6EAC 801407AC 00031C00 */  sll       $v1, $v1, 0x10
/* D6EB0 801407B0 00431025 */  or        $v0, $v0, $v1
/* D6EB4 801407B4 00042200 */  sll       $a0, $a0, 8
/* D6EB8 801407B8 9263004A */  lbu       $v1, 0x4a($s3)
/* D6EBC 801407BC 00441025 */  or        $v0, $v0, $a0
/* D6EC0 801407C0 00431025 */  or        $v0, $v0, $v1
/* D6EC4 801407C4 ACE20004 */  sw        $v0, 4($a3)
/* D6EC8 801407C8 8FA80000 */  lw        $t0, ($sp)
/* D6ECC 801407CC 15000100 */  bnez      $t0, .L80140BD0
/* D6ED0 801407D0 3C050704 */   lui      $a1, 0x704
/* D6ED4 801407D4 8FB60004 */  lw        $s6, 4($sp)
/* D6ED8 801407D8 16C000FE */  bnez      $s6, .L80140BD4
/* D6EDC 801407DC 34A50100 */   ori      $a1, $a1, 0x100
/* D6EE0 801407E0 8FA800D4 */  lw        $t0, 0xd4($sp)
/* D6EE4 801407E4 550000C3 */  bnel      $t0, $zero, .L80140AF4
/* D6EE8 801407E8 3C040708 */   lui      $a0, 0x708
/* D6EEC 801407EC 24160001 */  addiu     $s6, $zero, 1
/* D6EF0 801407F0 1136003A */  beq       $t1, $s6, .L801408DC
/* D6EF4 801407F4 29220002 */   slti     $v0, $t1, 2
/* D6EF8 801407F8 10400005 */  beqz      $v0, .L80140810
/* D6EFC 801407FC 00000000 */   nop
/* D6F00 80140800 1120000A */  beqz      $t1, .L8014082C
/* D6F04 80140804 24E20010 */   addiu    $v0, $a3, 0x10
/* D6F08 80140808 0805032C */  j         .L80140CB0
/* D6F0C 8014080C 00000000 */   nop
.L80140810:
/* D6F10 80140810 8FA80008 */  lw        $t0, 8($sp)
/* D6F14 80140814 1128005E */  beq       $t1, $t0, .L80140990
/* D6F18 80140818 24020003 */   addiu    $v0, $zero, 3
/* D6F1C 8014081C 11220089 */  beq       $t1, $v0, .L80140A44
/* D6F20 80140820 24E20010 */   addiu    $v0, $a3, 0x10
/* D6F24 80140824 0805032C */  j         .L80140CB0
/* D6F28 80140828 00000000 */   nop
.L8014082C:
/* D6F2C 8014082C AD420000 */  sw        $v0, ($t2)
/* D6F30 80140830 3C02FD68 */  lui       $v0, 0xfd68
/* D6F34 80140834 016C1823 */  subu      $v1, $t3, $t4
/* D6F38 80140838 24630008 */  addiu     $v1, $v1, 8
/* D6F3C 8014083C 000318C3 */  sra       $v1, $v1, 3
/* D6F40 80140840 306301FF */  andi      $v1, $v1, 0x1ff
/* D6F44 80140844 00031A40 */  sll       $v1, $v1, 9
/* D6F48 80140848 31A50FFF */  andi      $a1, $t5, 0xfff
/* D6F4C 8014084C 00052B00 */  sll       $a1, $a1, 0xc
/* D6F50 80140850 000B2080 */  sll       $a0, $t3, 2
/* D6F54 80140854 30840FFF */  andi      $a0, $a0, 0xfff
/* D6F58 80140858 8FB60070 */  lw        $s6, 0x70($sp)
/* D6F5C 8014085C 00042300 */  sll       $a0, $a0, 0xc
/* D6F60 80140860 ACF0000C */  sw        $s0, 0xc($a3)
/* D6F64 80140864 02C21025 */  or        $v0, $s6, $v0
/* D6F68 80140868 ACE20008 */  sw        $v0, 8($a3)
/* D6F6C 8014086C 24E20018 */  addiu     $v0, $a3, 0x18
/* D6F70 80140870 AD420000 */  sw        $v0, ($t2)
/* D6F74 80140874 3C02F568 */  lui       $v0, 0xf568
/* D6F78 80140878 00621825 */  or        $v1, $v1, $v0
/* D6F7C 8014087C 24E20020 */  addiu     $v0, $a3, 0x20
/* D6F80 80140880 ACE30010 */  sw        $v1, 0x10($a3)
/* D6F84 80140884 ACF20014 */  sw        $s2, 0x14($a3)
/* D6F88 80140888 AD420000 */  sw        $v0, ($t2)
/* D6F8C 8014088C 24E20028 */  addiu     $v0, $a3, 0x28
/* D6F90 80140890 ACFE0018 */  sw        $fp, 0x18($a3)
/* D6F94 80140894 ACE0001C */  sw        $zero, 0x1c($a3)
/* D6F98 80140898 AD420000 */  sw        $v0, ($t2)
/* D6F9C 8014089C 00B91025 */  or        $v0, $a1, $t9
/* D6FA0 801408A0 ACE20020 */  sw        $v0, 0x20($a3)
/* D6FA4 801408A4 00981025 */  or        $v0, $a0, $t8
/* D6FA8 801408A8 ACE20024 */  sw        $v0, 0x24($a3)
/* D6FAC 801408AC 24E20030 */  addiu     $v0, $a3, 0x30
/* D6FB0 801408B0 AD420000 */  sw        $v0, ($t2)
/* D6FB4 801408B4 24E20038 */  addiu     $v0, $a3, 0x38
/* D6FB8 801408B8 ACF70028 */  sw        $s7, 0x28($a3)
/* D6FBC 801408BC ACE0002C */  sw        $zero, 0x2c($a3)
/* D6FC0 801408C0 AD420000 */  sw        $v0, ($t2)
/* D6FC4 801408C4 24E20040 */  addiu     $v0, $a3, 0x40
/* D6FC8 801408C8 00AF2825 */  or        $a1, $a1, $t7
/* D6FCC 801408CC 008E2025 */  or        $a0, $a0, $t6
/* D6FD0 801408D0 ACE30030 */  sw        $v1, 0x30($a3)
/* D6FD4 801408D4 080502F0 */  j         .L80140BC0
/* D6FD8 801408D8 ACF10034 */   sw       $s1, 0x34($a3)
.L801408DC:
/* D6FDC 801408DC 24E20010 */  addiu     $v0, $a3, 0x10
/* D6FE0 801408E0 AD420000 */  sw        $v0, ($t2)
/* D6FE4 801408E4 3C02FD68 */  lui       $v0, 0xfd68
/* D6FE8 801408E8 016C1823 */  subu      $v1, $t3, $t4
/* D6FEC 801408EC 24630008 */  addiu     $v1, $v1, 8
/* D6FF0 801408F0 000318C3 */  sra       $v1, $v1, 3
/* D6FF4 801408F4 306301FF */  andi      $v1, $v1, 0x1ff
/* D6FF8 801408F8 00031A40 */  sll       $v1, $v1, 9
/* D6FFC 801408FC 31A50FFF */  andi      $a1, $t5, 0xfff
/* D7000 80140900 00052B00 */  sll       $a1, $a1, 0xc
/* D7004 80140904 000B2080 */  sll       $a0, $t3, 2
/* D7008 80140908 30840FFF */  andi      $a0, $a0, 0xfff
/* D700C 8014090C 8FA80070 */  lw        $t0, 0x70($sp)
/* D7010 80140910 00042300 */  sll       $a0, $a0, 0xc
/* D7014 80140914 ACF0000C */  sw        $s0, 0xc($a3)
/* D7018 80140918 01021025 */  or        $v0, $t0, $v0
/* D701C 8014091C ACE20008 */  sw        $v0, 8($a3)
/* D7020 80140920 24E20018 */  addiu     $v0, $a3, 0x18
/* D7024 80140924 AD420000 */  sw        $v0, ($t2)
/* D7028 80140928 3C02F568 */  lui       $v0, 0xf568
/* D702C 8014092C 00621825 */  or        $v1, $v1, $v0
/* D7030 80140930 24E20020 */  addiu     $v0, $a3, 0x20
/* D7034 80140934 ACE30010 */  sw        $v1, 0x10($a3)
/* D7038 80140938 ACF20014 */  sw        $s2, 0x14($a3)
/* D703C 8014093C AD420000 */  sw        $v0, ($t2)
/* D7040 80140940 24E20028 */  addiu     $v0, $a3, 0x28
/* D7044 80140944 ACFE0018 */  sw        $fp, 0x18($a3)
/* D7048 80140948 ACE0001C */  sw        $zero, 0x1c($a3)
/* D704C 8014094C AD420000 */  sw        $v0, ($t2)
/* D7050 80140950 00B91025 */  or        $v0, $a1, $t9
/* D7054 80140954 ACE20020 */  sw        $v0, 0x20($a3)
/* D7058 80140958 00981025 */  or        $v0, $a0, $t8
/* D705C 8014095C ACE20024 */  sw        $v0, 0x24($a3)
/* D7060 80140960 24E20030 */  addiu     $v0, $a3, 0x30
/* D7064 80140964 AD420000 */  sw        $v0, ($t2)
/* D7068 80140968 24E20038 */  addiu     $v0, $a3, 0x38
/* D706C 8014096C ACF70028 */  sw        $s7, 0x28($a3)
/* D7070 80140970 ACE0002C */  sw        $zero, 0x2c($a3)
/* D7074 80140974 AD420000 */  sw        $v0, ($t2)
/* D7078 80140978 24E20040 */  addiu     $v0, $a3, 0x40
/* D707C 8014097C 00AF2825 */  or        $a1, $a1, $t7
/* D7080 80140980 008E2025 */  or        $a0, $a0, $t6
/* D7084 80140984 ACE30030 */  sw        $v1, 0x30($a3)
/* D7088 80140988 080502F0 */  j         .L80140BC0
/* D708C 8014098C ACF10034 */   sw       $s1, 0x34($a3)
.L80140990:
/* D7090 80140990 24E20010 */  addiu     $v0, $a3, 0x10
/* D7094 80140994 AD420000 */  sw        $v0, ($t2)
/* D7098 80140998 3C02FD68 */  lui       $v0, 0xfd68
/* D709C 8014099C 016C1823 */  subu      $v1, $t3, $t4
/* D70A0 801409A0 24630008 */  addiu     $v1, $v1, 8
/* D70A4 801409A4 000318C3 */  sra       $v1, $v1, 3
/* D70A8 801409A8 306301FF */  andi      $v1, $v1, 0x1ff
/* D70AC 801409AC 00031A40 */  sll       $v1, $v1, 9
/* D70B0 801409B0 31A50FFF */  andi      $a1, $t5, 0xfff
/* D70B4 801409B4 00052B00 */  sll       $a1, $a1, 0xc
/* D70B8 801409B8 000B2080 */  sll       $a0, $t3, 2
/* D70BC 801409BC 30840FFF */  andi      $a0, $a0, 0xfff
/* D70C0 801409C0 8FB60070 */  lw        $s6, 0x70($sp)
/* D70C4 801409C4 00042300 */  sll       $a0, $a0, 0xc
/* D70C8 801409C8 ACF0000C */  sw        $s0, 0xc($a3)
/* D70CC 801409CC 02C21025 */  or        $v0, $s6, $v0
/* D70D0 801409D0 ACE20008 */  sw        $v0, 8($a3)
/* D70D4 801409D4 24E20018 */  addiu     $v0, $a3, 0x18
/* D70D8 801409D8 AD420000 */  sw        $v0, ($t2)
/* D70DC 801409DC 3C02F568 */  lui       $v0, 0xf568
/* D70E0 801409E0 00621825 */  or        $v1, $v1, $v0
/* D70E4 801409E4 24E20020 */  addiu     $v0, $a3, 0x20
/* D70E8 801409E8 ACE30010 */  sw        $v1, 0x10($a3)
/* D70EC 801409EC ACF20014 */  sw        $s2, 0x14($a3)
/* D70F0 801409F0 AD420000 */  sw        $v0, ($t2)
/* D70F4 801409F4 24E20028 */  addiu     $v0, $a3, 0x28
/* D70F8 801409F8 ACFE0018 */  sw        $fp, 0x18($a3)
/* D70FC 801409FC ACE0001C */  sw        $zero, 0x1c($a3)
/* D7100 80140A00 AD420000 */  sw        $v0, ($t2)
/* D7104 80140A04 00B91025 */  or        $v0, $a1, $t9
/* D7108 80140A08 ACE20020 */  sw        $v0, 0x20($a3)
/* D710C 80140A0C 00981025 */  or        $v0, $a0, $t8
/* D7110 80140A10 ACE20024 */  sw        $v0, 0x24($a3)
/* D7114 80140A14 24E20030 */  addiu     $v0, $a3, 0x30
/* D7118 80140A18 AD420000 */  sw        $v0, ($t2)
/* D711C 80140A1C 24E20038 */  addiu     $v0, $a3, 0x38
/* D7120 80140A20 ACF70028 */  sw        $s7, 0x28($a3)
/* D7124 80140A24 ACE0002C */  sw        $zero, 0x2c($a3)
/* D7128 80140A28 AD420000 */  sw        $v0, ($t2)
/* D712C 80140A2C 24E20040 */  addiu     $v0, $a3, 0x40
/* D7130 80140A30 00AF2825 */  or        $a1, $a1, $t7
/* D7134 80140A34 008E2025 */  or        $a0, $a0, $t6
/* D7138 80140A38 ACE30030 */  sw        $v1, 0x30($a3)
/* D713C 80140A3C 080502F0 */  j         .L80140BC0
/* D7140 80140A40 ACF10034 */   sw       $s1, 0x34($a3)
.L80140A44:
/* D7144 80140A44 AD420000 */  sw        $v0, ($t2)
/* D7148 80140A48 3C02FD68 */  lui       $v0, 0xfd68
/* D714C 80140A4C 016C1823 */  subu      $v1, $t3, $t4
/* D7150 80140A50 24630008 */  addiu     $v1, $v1, 8
/* D7154 80140A54 000318C3 */  sra       $v1, $v1, 3
/* D7158 80140A58 306301FF */  andi      $v1, $v1, 0x1ff
/* D715C 80140A5C 00031A40 */  sll       $v1, $v1, 9
/* D7160 80140A60 31A50FFF */  andi      $a1, $t5, 0xfff
/* D7164 80140A64 00052B00 */  sll       $a1, $a1, 0xc
/* D7168 80140A68 000B2080 */  sll       $a0, $t3, 2
/* D716C 80140A6C 30840FFF */  andi      $a0, $a0, 0xfff
/* D7170 80140A70 8FA80070 */  lw        $t0, 0x70($sp)
/* D7174 80140A74 00042300 */  sll       $a0, $a0, 0xc
/* D7178 80140A78 ACF0000C */  sw        $s0, 0xc($a3)
/* D717C 80140A7C 01021025 */  or        $v0, $t0, $v0
/* D7180 80140A80 ACE20008 */  sw        $v0, 8($a3)
/* D7184 80140A84 24E20018 */  addiu     $v0, $a3, 0x18
/* D7188 80140A88 AD420000 */  sw        $v0, ($t2)
/* D718C 80140A8C 3C02F568 */  lui       $v0, 0xf568
/* D7190 80140A90 00621825 */  or        $v1, $v1, $v0
/* D7194 80140A94 24E20020 */  addiu     $v0, $a3, 0x20
/* D7198 80140A98 ACE30010 */  sw        $v1, 0x10($a3)
/* D719C 80140A9C ACF20014 */  sw        $s2, 0x14($a3)
/* D71A0 80140AA0 AD420000 */  sw        $v0, ($t2)
/* D71A4 80140AA4 24E20028 */  addiu     $v0, $a3, 0x28
/* D71A8 80140AA8 ACFE0018 */  sw        $fp, 0x18($a3)
/* D71AC 80140AAC ACE0001C */  sw        $zero, 0x1c($a3)
/* D71B0 80140AB0 AD420000 */  sw        $v0, ($t2)
/* D71B4 80140AB4 00B91025 */  or        $v0, $a1, $t9
/* D71B8 80140AB8 ACE20020 */  sw        $v0, 0x20($a3)
/* D71BC 80140ABC 00981025 */  or        $v0, $a0, $t8
/* D71C0 80140AC0 ACE20024 */  sw        $v0, 0x24($a3)
/* D71C4 80140AC4 24E20030 */  addiu     $v0, $a3, 0x30
/* D71C8 80140AC8 AD420000 */  sw        $v0, ($t2)
/* D71CC 80140ACC 24E20038 */  addiu     $v0, $a3, 0x38
/* D71D0 80140AD0 ACF70028 */  sw        $s7, 0x28($a3)
/* D71D4 80140AD4 ACE0002C */  sw        $zero, 0x2c($a3)
/* D71D8 80140AD8 AD420000 */  sw        $v0, ($t2)
/* D71DC 80140ADC 24E20040 */  addiu     $v0, $a3, 0x40
/* D71E0 80140AE0 00AF2825 */  or        $a1, $a1, $t7
/* D71E4 80140AE4 008E2025 */  or        $a0, $a0, $t6
/* D71E8 80140AE8 ACE30030 */  sw        $v1, 0x30($a3)
/* D71EC 80140AEC 080502F0 */  j         .L80140BC0
/* D71F0 80140AF0 ACF10034 */   sw       $s1, 0x34($a3)
.L80140AF4:
/* D71F4 80140AF4 34840200 */  ori       $a0, $a0, 0x200
/* D71F8 80140AF8 3C060008 */  lui       $a2, 8
/* D71FC 80140AFC 34C60200 */  ori       $a2, $a2, 0x200
/* D7200 80140B00 24E20010 */  addiu     $v0, $a3, 0x10
/* D7204 80140B04 AD420000 */  sw        $v0, ($t2)
/* D7208 80140B08 3C02FD68 */  lui       $v0, 0xfd68
/* D720C 80140B0C 016C1823 */  subu      $v1, $t3, $t4
/* D7210 80140B10 24630008 */  addiu     $v1, $v1, 8
/* D7214 80140B14 000318C3 */  sra       $v1, $v1, 3
/* D7218 80140B18 306301FF */  andi      $v1, $v1, 0x1ff
/* D721C 80140B1C 00031A40 */  sll       $v1, $v1, 9
/* D7220 80140B20 02842025 */  or        $a0, $s4, $a0
/* D7224 80140B24 02A42025 */  or        $a0, $s5, $a0
/* D7228 80140B28 31A50FFF */  andi      $a1, $t5, 0xfff
/* D722C 80140B2C 00052B00 */  sll       $a1, $a1, 0xc
/* D7230 80140B30 02863025 */  or        $a2, $s4, $a2
/* D7234 80140B34 8FB60070 */  lw        $s6, 0x70($sp)
/* D7238 80140B38 02A63025 */  or        $a2, $s5, $a2
/* D723C 80140B3C ACF0000C */  sw        $s0, 0xc($a3)
/* D7240 80140B40 02C21025 */  or        $v0, $s6, $v0
/* D7244 80140B44 ACE20008 */  sw        $v0, 8($a3)
/* D7248 80140B48 24E20018 */  addiu     $v0, $a3, 0x18
/* D724C 80140B4C AD420000 */  sw        $v0, ($t2)
/* D7250 80140B50 3C02F568 */  lui       $v0, 0xf568
/* D7254 80140B54 00621825 */  or        $v1, $v1, $v0
/* D7258 80140B58 24E20020 */  addiu     $v0, $a3, 0x20
/* D725C 80140B5C ACE30010 */  sw        $v1, 0x10($a3)
/* D7260 80140B60 ACE40014 */  sw        $a0, 0x14($a3)
/* D7264 80140B64 AD420000 */  sw        $v0, ($t2)
/* D7268 80140B68 24E20028 */  addiu     $v0, $a3, 0x28
/* D726C 80140B6C ACFE0018 */  sw        $fp, 0x18($a3)
/* D7270 80140B70 ACE0001C */  sw        $zero, 0x1c($a3)
/* D7274 80140B74 AD420000 */  sw        $v0, ($t2)
/* D7278 80140B78 00B91025 */  or        $v0, $a1, $t9
/* D727C 80140B7C 000B2080 */  sll       $a0, $t3, 2
/* D7280 80140B80 30840FFF */  andi      $a0, $a0, 0xfff
/* D7284 80140B84 00042300 */  sll       $a0, $a0, 0xc
/* D7288 80140B88 ACE20020 */  sw        $v0, 0x20($a3)
/* D728C 80140B8C 00981025 */  or        $v0, $a0, $t8
/* D7290 80140B90 ACE20024 */  sw        $v0, 0x24($a3)
/* D7294 80140B94 24E20030 */  addiu     $v0, $a3, 0x30
/* D7298 80140B98 AD420000 */  sw        $v0, ($t2)
/* D729C 80140B9C 24E20038 */  addiu     $v0, $a3, 0x38
/* D72A0 80140BA0 ACF70028 */  sw        $s7, 0x28($a3)
/* D72A4 80140BA4 ACE0002C */  sw        $zero, 0x2c($a3)
/* D72A8 80140BA8 AD420000 */  sw        $v0, ($t2)
/* D72AC 80140BAC 24E20040 */  addiu     $v0, $a3, 0x40
/* D72B0 80140BB0 00AF2825 */  or        $a1, $a1, $t7
/* D72B4 80140BB4 008E2025 */  or        $a0, $a0, $t6
/* D72B8 80140BB8 ACE30030 */  sw        $v1, 0x30($a3)
/* D72BC 80140BBC ACE60034 */  sw        $a2, 0x34($a3)
.L80140BC0:
/* D72C0 80140BC0 AD420000 */  sw        $v0, ($t2)
/* D72C4 80140BC4 ACE50038 */  sw        $a1, 0x38($a3)
/* D72C8 80140BC8 0805032C */  j         .L80140CB0
/* D72CC 80140BCC ACE4003C */   sw       $a0, 0x3c($a3)
.L80140BD0:
/* D72D0 80140BD0 34A50100 */  ori       $a1, $a1, 0x100
.L80140BD4:
/* D72D4 80140BD4 3C070004 */  lui       $a3, 4
/* D72D8 80140BD8 34E70100 */  ori       $a3, $a3, 0x100
/* D72DC 80140BDC 3C02FD68 */  lui       $v0, 0xfd68
/* D72E0 80140BE0 02852825 */  or        $a1, $s4, $a1
/* D72E4 80140BE4 02A52825 */  or        $a1, $s5, $a1
/* D72E8 80140BE8 31A60FFF */  andi      $a2, $t5, 0xfff
/* D72EC 80140BEC 00063300 */  sll       $a2, $a2, 0xc
/* D72F0 80140BF0 8D430000 */  lw        $v1, ($t2)
/* D72F4 80140BF4 02873825 */  or        $a3, $s4, $a3
/* D72F8 80140BF8 0060202D */  daddu     $a0, $v1, $zero
/* D72FC 80140BFC 24630008 */  addiu     $v1, $v1, 8
/* D7300 80140C00 AD430000 */  sw        $v1, ($t2)
/* D7304 80140C04 8FA80070 */  lw        $t0, 0x70($sp)
/* D7308 80140C08 02A73825 */  or        $a3, $s5, $a3
/* D730C 80140C0C AC900004 */  sw        $s0, 4($a0)
/* D7310 80140C10 01021025 */  or        $v0, $t0, $v0
/* D7314 80140C14 AC820000 */  sw        $v0, ($a0)
/* D7318 80140C18 24620008 */  addiu     $v0, $v1, 8
/* D731C 80140C1C 016C2023 */  subu      $a0, $t3, $t4
/* D7320 80140C20 24840008 */  addiu     $a0, $a0, 8
/* D7324 80140C24 000420C3 */  sra       $a0, $a0, 3
/* D7328 80140C28 308401FF */  andi      $a0, $a0, 0x1ff
/* D732C 80140C2C 00042240 */  sll       $a0, $a0, 9
/* D7330 80140C30 AD420000 */  sw        $v0, ($t2)
/* D7334 80140C34 3C02F568 */  lui       $v0, 0xf568
.L80140C38:
/* D7338 80140C38 00822025 */  or        $a0, $a0, $v0
/* D733C 80140C3C 24620010 */  addiu     $v0, $v1, 0x10
/* D7340 80140C40 AC640000 */  sw        $a0, ($v1)
/* D7344 80140C44 AC650004 */  sw        $a1, 4($v1)
/* D7348 80140C48 AD420000 */  sw        $v0, ($t2)
/* D734C 80140C4C 24620018 */  addiu     $v0, $v1, 0x18
/* D7350 80140C50 AC7E0008 */  sw        $fp, 8($v1)
/* D7354 80140C54 AC60000C */  sw        $zero, 0xc($v1)
/* D7358 80140C58 AD420000 */  sw        $v0, ($t2)
/* D735C 80140C5C 00D91025 */  or        $v0, $a2, $t9
/* D7360 80140C60 000B2880 */  sll       $a1, $t3, 2
/* D7364 80140C64 30A50FFF */  andi      $a1, $a1, 0xfff
/* D7368 80140C68 00052B00 */  sll       $a1, $a1, 0xc
/* D736C 80140C6C AC620010 */  sw        $v0, 0x10($v1)
/* D7370 80140C70 00B81025 */  or        $v0, $a1, $t8
/* D7374 80140C74 AC620014 */  sw        $v0, 0x14($v1)
/* D7378 80140C78 24620020 */  addiu     $v0, $v1, 0x20
/* D737C 80140C7C AD420000 */  sw        $v0, ($t2)
/* D7380 80140C80 24620028 */  addiu     $v0, $v1, 0x28
/* D7384 80140C84 AC770018 */  sw        $s7, 0x18($v1)
/* D7388 80140C88 AC60001C */  sw        $zero, 0x1c($v1)
/* D738C 80140C8C AD420000 */  sw        $v0, ($t2)
/* D7390 80140C90 24620030 */  addiu     $v0, $v1, 0x30
/* D7394 80140C94 00CF3025 */  or        $a2, $a2, $t7
/* D7398 80140C98 00AE2825 */  or        $a1, $a1, $t6
/* D739C 80140C9C AC640020 */  sw        $a0, 0x20($v1)
/* D73A0 80140CA0 AC670024 */  sw        $a3, 0x24($v1)
.L80140CA4:
/* D73A4 80140CA4 AD420000 */  sw        $v0, ($t2)
/* D73A8 80140CA8 AC660028 */  sw        $a2, 0x28($v1)
/* D73AC 80140CAC AC65002C */  sw        $a1, 0x2c($v1)
.L80140CB0:
/* D73B0 80140CB0 8E620000 */  lw        $v0, ($s3)
/* D73B4 80140CB4 30428000 */  andi      $v0, $v0, 0x8000
/* D73B8 80140CB8 10400065 */  beqz      $v0, .L80140E50
/* D73BC 80140CBC 00000000 */   nop
/* D73C0 80140CC0 8D440000 */  lw        $a0, ($t2)
/* D73C4 80140CC4 24820008 */  addiu     $v0, $a0, 8
/* D73C8 80140CC8 AD420000 */  sw        $v0, ($t2)
/* D73CC 80140CCC 8FB60088 */  lw        $s6, 0x88($sp)
/* D73D0 80140CD0 00161480 */  sll       $v0, $s6, 0x12
/* D73D4 80140CD4 00021403 */  sra       $v0, $v0, 0x10
/* D73D8 80140CD8 18400005 */  blez      $v0, .L80140CF0
/* D73DC 80140CDC 30420FFF */   andi     $v0, $v0, 0xfff
/* D73E0 80140CE0 00021300 */  sll       $v0, $v0, 0xc
/* D73E4 80140CE4 3C03E400 */  lui       $v1, 0xe400
/* D73E8 80140CE8 0805033D */  j         .L80140CF4
/* D73EC 80140CEC 00431825 */   or       $v1, $v0, $v1
.L80140CF0:
/* D73F0 80140CF0 3C03E400 */  lui       $v1, 0xe400
.L80140CF4:
/* D73F4 80140CF4 AC830000 */  sw        $v1, ($a0)
/* D73F8 80140CF8 8FA8002C */  lw        $t0, 0x2c($sp)
/* D73FC 80140CFC 00081480 */  sll       $v0, $t0, 0x12
/* D7400 80140D00 00021403 */  sra       $v0, $v0, 0x10
/* D7404 80140D04 18400003 */  blez      $v0, .L80140D14
/* D7408 80140D08 30420FFF */   andi     $v0, $v0, 0xfff
/* D740C 80140D0C 00621025 */  or        $v0, $v1, $v0
/* D7410 80140D10 AC820000 */  sw        $v0, ($a0)
.L80140D14:
/* D7414 80140D14 8FB60030 */  lw        $s6, 0x30($sp)
/* D7418 80140D18 00161480 */  sll       $v0, $s6, 0x12
/* D741C 80140D1C 00021403 */  sra       $v0, $v0, 0x10
/* D7420 80140D20 18400004 */  blez      $v0, .L80140D34
/* D7424 80140D24 24830004 */   addiu    $v1, $a0, 4
/* D7428 80140D28 30420FFF */  andi      $v0, $v0, 0xfff
/* D742C 80140D2C 0805034E */  j         .L80140D38
/* D7430 80140D30 00021300 */   sll      $v0, $v0, 0xc
.L80140D34:
/* D7434 80140D34 0000102D */  daddu     $v0, $zero, $zero
.L80140D38:
/* D7438 80140D38 AC620000 */  sw        $v0, ($v1)
/* D743C 80140D3C 8FA80078 */  lw        $t0, 0x78($sp)
/* D7440 80140D40 19000004 */  blez      $t0, .L80140D54
/* D7444 80140D44 00000000 */   nop
/* D7448 80140D48 8FB6007C */  lw        $s6, 0x7c($sp)
/* D744C 80140D4C 00561025 */  or        $v0, $v0, $s6
/* D7450 80140D50 AC620000 */  sw        $v0, ($v1)
.L80140D54:
/* D7454 80140D54 8D420000 */  lw        $v0, ($t2)
/* D7458 80140D58 0040182D */  daddu     $v1, $v0, $zero
/* D745C 80140D5C 24420008 */  addiu     $v0, $v0, 8
/* D7460 80140D60 AD420000 */  sw        $v0, ($t2)
/* D7464 80140D64 3C02E100 */  lui       $v0, %hi(D_E1000010)
/* D7468 80140D68 AC620000 */  sw        $v0, ($v1)
/* D746C 80140D6C 8FA80018 */  lw        $t0, 0x18($sp)
/* D7470 80140D70 8FB60014 */  lw        $s6, 0x14($sp)
/* D7474 80140D74 00081140 */  sll       $v0, $t0, 5
/* D7478 80140D78 24460010 */  addiu     $a2, $v0, %lo(D_E1000010)
/* D747C 80140D7C 00161140 */  sll       $v0, $s6, 5
/* D7480 80140D80 8FA80030 */  lw        $t0, 0x30($sp)
/* D7484 80140D84 24450010 */  addiu     $a1, $v0, 0x10
/* D7488 80140D88 00081480 */  sll       $v0, $t0, 0x12
/* D748C 80140D8C 00022403 */  sra       $a0, $v0, 0x10
/* D7490 80140D90 04810013 */  bgez      $a0, .L80140DE0
/* D7494 80140D94 24630004 */   addiu    $v1, $v1, 4
/* D7498 80140D98 8FB6000C */  lw        $s6, 0xc($sp)
/* D749C 80140D9C 00161400 */  sll       $v0, $s6, 0x10
/* D74A0 80140DA0 00021403 */  sra       $v0, $v0, 0x10
/* D74A4 80140DA4 04410007 */  bgez      $v0, .L80140DC4
/* D74A8 80140DA8 00820018 */   mult     $a0, $v0
/* D74AC 80140DAC 00004012 */  mflo      $t0
/* D74B0 80140DB0 000811C3 */  sra       $v0, $t0, 7
/* D74B4 80140DB4 04410008 */  bgez      $v0, .L80140DD8
/* D74B8 80140DB8 00A21023 */   subu     $v0, $a1, $v0
/* D74BC 80140DBC 08050375 */  j         .L80140DD4
/* D74C0 80140DC0 0000102D */   daddu    $v0, $zero, $zero
.L80140DC4:
/* D74C4 80140DC4 00004012 */  mflo      $t0
/* D74C8 80140DC8 000811C3 */  sra       $v0, $t0, 7
/* D74CC 80140DCC 5C400001 */  bgtzl     $v0, .L80140DD4
/* D74D0 80140DD0 0000102D */   daddu    $v0, $zero, $zero
.L80140DD4:
/* D74D4 80140DD4 00A21023 */  subu      $v0, $a1, $v0
.L80140DD8:
/* D74D8 80140DD8 08050379 */  j         .L80140DE4
/* D74DC 80140DDC 00022400 */   sll      $a0, $v0, 0x10
.L80140DE0:
/* D74E0 80140DE0 00052400 */  sll       $a0, $a1, 0x10
.L80140DE4:
/* D74E4 80140DE4 8FB60028 */  lw        $s6, 0x28($sp)
/* D74E8 80140DE8 00161080 */  sll       $v0, $s6, 2
/* D74EC 80140DEC 04410079 */  bgez      $v0, .L80140FD4
/* D74F0 80140DF0 30C2FFFF */   andi     $v0, $a2, 0xffff
/* D74F4 80140DF4 8FA80010 */  lw        $t0, 0x10($sp)
/* D74F8 80140DF8 00081400 */  sll       $v0, $t0, 0x10
/* D74FC 80140DFC 00021403 */  sra       $v0, $v0, 0x10
/* D7500 80140E00 0441000A */  bgez      $v0, .L80140E2C
/* D7504 80140E04 00000000 */   nop
/* D7508 80140E08 8FA80078 */  lw        $t0, 0x78($sp)
/* D750C 80140E0C 01020018 */  mult      $t0, $v0
/* D7510 80140E10 0000B012 */  mflo      $s6
/* D7514 80140E14 001611C3 */  sra       $v0, $s6, 7
/* D7518 80140E18 04420001 */  bltzl     $v0, .L80140E20
/* D751C 80140E1C 0000102D */   daddu    $v0, $zero, $zero
.L80140E20:
/* D7520 80140E20 00C21023 */  subu      $v0, $a2, $v0
/* D7524 80140E24 080503F5 */  j         .L80140FD4
/* D7528 80140E28 3042FFFF */   andi     $v0, $v0, 0xffff
.L80140E2C:
/* D752C 80140E2C 8FA80078 */  lw        $t0, 0x78($sp)
/* D7530 80140E30 01020018 */  mult      $t0, $v0
/* D7534 80140E34 0000B012 */  mflo      $s6
/* D7538 80140E38 001611C3 */  sra       $v0, $s6, 7
/* D753C 80140E3C 5C400001 */  bgtzl     $v0, .L80140E44
/* D7540 80140E40 0000102D */   daddu    $v0, $zero, $zero
.L80140E44:
/* D7544 80140E44 00C21023 */  subu      $v0, $a2, $v0
/* D7548 80140E48 080503F5 */  j         .L80140FD4
/* D754C 80140E4C 3042FFFF */   andi     $v0, $v0, 0xffff
.L80140E50:
/* D7550 80140E50 8D440000 */  lw        $a0, ($t2)
/* D7554 80140E54 24820008 */  addiu     $v0, $a0, 8
/* D7558 80140E58 AD420000 */  sw        $v0, ($t2)
/* D755C 80140E5C 8FA80088 */  lw        $t0, 0x88($sp)
/* D7560 80140E60 00081480 */  sll       $v0, $t0, 0x12
/* D7564 80140E64 00021403 */  sra       $v0, $v0, 0x10
/* D7568 80140E68 18400005 */  blez      $v0, .L80140E80
/* D756C 80140E6C 30420FFF */   andi     $v0, $v0, 0xfff
/* D7570 80140E70 00021300 */  sll       $v0, $v0, 0xc
/* D7574 80140E74 3C03E400 */  lui       $v1, 0xe400
/* D7578 80140E78 080503A1 */  j         .L80140E84
/* D757C 80140E7C 00431825 */   or       $v1, $v0, $v1
.L80140E80:
/* D7580 80140E80 3C03E400 */  lui       $v1, 0xe400
.L80140E84:
/* D7584 80140E84 AC830000 */  sw        $v1, ($a0)
/* D7588 80140E88 8FB6002C */  lw        $s6, 0x2c($sp)
/* D758C 80140E8C 00161480 */  sll       $v0, $s6, 0x12
/* D7590 80140E90 00021403 */  sra       $v0, $v0, 0x10
/* D7594 80140E94 18400003 */  blez      $v0, .L80140EA4
/* D7598 80140E98 30420FFF */   andi     $v0, $v0, 0xfff
/* D759C 80140E9C 00621025 */  or        $v0, $v1, $v0
/* D75A0 80140EA0 AC820000 */  sw        $v0, ($a0)
.L80140EA4:
/* D75A4 80140EA4 8FA80030 */  lw        $t0, 0x30($sp)
/* D75A8 80140EA8 00081480 */  sll       $v0, $t0, 0x12
/* D75AC 80140EAC 00021403 */  sra       $v0, $v0, 0x10
/* D75B0 80140EB0 18400004 */  blez      $v0, .L80140EC4
/* D75B4 80140EB4 24830004 */   addiu    $v1, $a0, 4
/* D75B8 80140EB8 30420FFF */  andi      $v0, $v0, 0xfff
/* D75BC 80140EBC 080503B2 */  j         .L80140EC8
/* D75C0 80140EC0 00021300 */   sll      $v0, $v0, 0xc
.L80140EC4:
/* D75C4 80140EC4 0000102D */  daddu     $v0, $zero, $zero
.L80140EC8:
/* D75C8 80140EC8 AC620000 */  sw        $v0, ($v1)
/* D75CC 80140ECC 8FB60078 */  lw        $s6, 0x78($sp)
/* D75D0 80140ED0 1AC00004 */  blez      $s6, .L80140EE4
/* D75D4 80140ED4 00000000 */   nop
/* D75D8 80140ED8 8FA8007C */  lw        $t0, 0x7c($sp)
/* D75DC 80140EDC 00481025 */  or        $v0, $v0, $t0
/* D75E0 80140EE0 AC620000 */  sw        $v0, ($v1)
.L80140EE4:
/* D75E4 80140EE4 8D420000 */  lw        $v0, ($t2)
/* D75E8 80140EE8 0040182D */  daddu     $v1, $v0, $zero
/* D75EC 80140EEC 24420008 */  addiu     $v0, $v0, 8
/* D75F0 80140EF0 AD420000 */  sw        $v0, ($t2)
/* D75F4 80140EF4 3C02E100 */  lui       $v0, 0xe100
/* D75F8 80140EF8 AC620000 */  sw        $v0, ($v1)
/* D75FC 80140EFC 24630004 */  addiu     $v1, $v1, 4
/* D7600 80140F00 8FB60018 */  lw        $s6, 0x18($sp)
/* D7604 80140F04 8FA80014 */  lw        $t0, 0x14($sp)
/* D7608 80140F08 00163140 */  sll       $a2, $s6, 5
/* D760C 80140F0C 8FB60030 */  lw        $s6, 0x30($sp)
/* D7610 80140F10 00161480 */  sll       $v0, $s6, 0x12
/* D7614 80140F14 00022403 */  sra       $a0, $v0, 0x10
/* D7618 80140F18 04810013 */  bgez      $a0, .L80140F68
/* D761C 80140F1C 00082940 */   sll      $a1, $t0, 5
/* D7620 80140F20 8FA8000C */  lw        $t0, 0xc($sp)
/* D7624 80140F24 00081400 */  sll       $v0, $t0, 0x10
/* D7628 80140F28 00021403 */  sra       $v0, $v0, 0x10
/* D762C 80140F2C 04410007 */  bgez      $v0, .L80140F4C
/* D7630 80140F30 00820018 */   mult     $a0, $v0
/* D7634 80140F34 00004012 */  mflo      $t0
/* D7638 80140F38 000811C3 */  sra       $v0, $t0, 7
/* D763C 80140F3C 04410008 */  bgez      $v0, .L80140F60
/* D7640 80140F40 00A21023 */   subu     $v0, $a1, $v0
/* D7644 80140F44 080503D7 */  j         .L80140F5C
/* D7648 80140F48 0000102D */   daddu    $v0, $zero, $zero
.L80140F4C:
/* D764C 80140F4C 00004012 */  mflo      $t0
/* D7650 80140F50 000811C3 */  sra       $v0, $t0, 7
/* D7654 80140F54 5C400001 */  bgtzl     $v0, .L80140F5C
/* D7658 80140F58 0000102D */   daddu    $v0, $zero, $zero
.L80140F5C:
/* D765C 80140F5C 00A21023 */  subu      $v0, $a1, $v0
.L80140F60:
/* D7660 80140F60 080503DB */  j         .L80140F6C
/* D7664 80140F64 00022400 */   sll      $a0, $v0, 0x10
.L80140F68:
/* D7668 80140F68 00052400 */  sll       $a0, $a1, 0x10
.L80140F6C:
/* D766C 80140F6C 8FB60028 */  lw        $s6, 0x28($sp)
/* D7670 80140F70 00161080 */  sll       $v0, $s6, 2
/* D7674 80140F74 04410017 */  bgez      $v0, .L80140FD4
/* D7678 80140F78 30C2FFFF */   andi     $v0, $a2, 0xffff
/* D767C 80140F7C 8FA80010 */  lw        $t0, 0x10($sp)
/* D7680 80140F80 00081400 */  sll       $v0, $t0, 0x10
/* D7684 80140F84 00021403 */  sra       $v0, $v0, 0x10
/* D7688 80140F88 0441000A */  bgez      $v0, .L80140FB4
/* D768C 80140F8C 00000000 */   nop
/* D7690 80140F90 8FA80078 */  lw        $t0, 0x78($sp)
/* D7694 80140F94 01020018 */  mult      $t0, $v0
/* D7698 80140F98 0000B012 */  mflo      $s6
/* D769C 80140F9C 001611C3 */  sra       $v0, $s6, 7
/* D76A0 80140FA0 04420001 */  bltzl     $v0, .L80140FA8
/* D76A4 80140FA4 0000102D */   daddu    $v0, $zero, $zero
.L80140FA8:
/* D76A8 80140FA8 00C21023 */  subu      $v0, $a2, $v0
/* D76AC 80140FAC 080503F5 */  j         .L80140FD4
/* D76B0 80140FB0 3042FFFF */   andi     $v0, $v0, 0xffff
.L80140FB4:
/* D76B4 80140FB4 8FA80078 */  lw        $t0, 0x78($sp)
/* D76B8 80140FB8 01020018 */  mult      $t0, $v0
/* D76BC 80140FBC 0000B012 */  mflo      $s6
/* D76C0 80140FC0 001611C3 */  sra       $v0, $s6, 7
/* D76C4 80140FC4 5C400001 */  bgtzl     $v0, .L80140FCC
/* D76C8 80140FC8 0000102D */   daddu    $v0, $zero, $zero
.L80140FCC:
/* D76CC 80140FCC 00C21023 */  subu      $v0, $a2, $v0
/* D76D0 80140FD0 3042FFFF */  andi      $v0, $v0, 0xffff
.L80140FD4:
/* D76D4 80140FD4 00821025 */  or        $v0, $a0, $v0
/* D76D8 80140FD8 AC620000 */  sw        $v0, ($v1)
/* D76DC 80140FDC 8D420000 */  lw        $v0, ($t2)
/* D76E0 80140FE0 0040202D */  daddu     $a0, $v0, $zero
/* D76E4 80140FE4 24420008 */  addiu     $v0, $v0, 8
/* D76E8 80140FE8 AD420000 */  sw        $v0, ($t2)
/* D76EC 80140FEC 3C02F100 */  lui       $v0, 0xf100
/* D76F0 80140FF0 AC820000 */  sw        $v0, ($a0)
/* D76F4 80140FF4 8FA8000C */  lw        $t0, 0xc($sp)
/* D76F8 80140FF8 8FB60010 */  lw        $s6, 0x10($sp)
/* D76FC 80140FFC 00081400 */  sll       $v0, $t0, 0x10
/* D7700 80141000 32C3FFFF */  andi      $v1, $s6, 0xffff
/* D7704 80141004 00431025 */  or        $v0, $v0, $v1
/* D7708 80141008 AC820004 */  sw        $v0, 4($a0)
/* D770C 8014100C 8FA8001C */  lw        $t0, 0x1c($sp)
/* D7710 80141010 15000013 */  bnez      $t0, .L80141060
/* D7714 80141014 25AD0100 */   addiu    $t5, $t5, 0x100
/* D7718 80141018 C7A0000C */  lwc1      $f0, 0xc($sp)
/* D771C 8014101C 46800021 */  cvt.d.w   $f0, $f0
/* D7720 80141020 3C014050 */  lui       $at, 0x4050
/* D7724 80141024 44811800 */  mtc1      $at, $f3
/* D7728 80141028 44801000 */  mtc1      $zero, $f2
/* D772C 8014102C 46202003 */  div.d     $f0, $f4, $f0
/* D7730 80141030 46220002 */  mul.d     $f0, $f0, $f2
/* D7734 80141034 00000000 */  nop
/* D7738 80141038 8FB60080 */  lw        $s6, 0x80($sp)
/* D773C 8014103C C7A20030 */  lwc1      $f2, 0x30($sp)
/* D7740 80141040 468010A1 */  cvt.d.w   $f2, $f2
/* D7744 80141044 46201080 */  add.d     $f2, $f2, $f0
/* D7748 80141048 26D60080 */  addiu     $s6, $s6, 0x80
/* D774C 8014104C AFB60080 */  sw        $s6, 0x80($sp)
/* D7750 80141050 4620118D */  trunc.w.d $f6, $f2
/* D7754 80141054 E7A60030 */  swc1      $f6, 0x30($sp)
/* D7758 80141058 0804FF72 */  j         .L8013FDC8
/* D775C 8014105C 258C0040 */   addiu    $t4, $t4, 0x40
.L80141060:
/* D7760 80141060 8FB60020 */  lw        $s6, 0x20($sp)
/* D7764 80141064 16C00012 */  bnez      $s6, .L801410B0
/* D7768 80141068 00000000 */   nop
/* D776C 8014106C C7A20010 */  lwc1      $f2, 0x10($sp)
/* D7770 80141070 468010A1 */  cvt.d.w   $f2, $f2
/* D7774 80141074 3C014040 */  lui       $at, 0x4040
/* D7778 80141078 44810800 */  mtc1      $at, $f1
/* D777C 8014107C 44800000 */  mtc1      $zero, $f0
/* D7780 80141080 46222083 */  div.d     $f2, $f4, $f2
/* D7784 80141084 46201082 */  mul.d     $f2, $f2, $f0
/* D7788 80141088 00000000 */  nop
/* D778C 8014108C 8FA80024 */  lw        $t0, 0x24($sp)
/* D7790 80141090 C7A00028 */  lwc1      $f0, 0x28($sp)
/* D7794 80141094 46800021 */  cvt.d.w   $f0, $f0
/* D7798 80141098 46220000 */  add.d     $f0, $f0, $f2
/* D779C 8014109C 25080020 */  addiu     $t0, $t0, 0x20
/* D77A0 801410A0 AFA80024 */  sw        $t0, 0x24($sp)
/* D77A4 801410A4 4620018D */  trunc.w.d $f6, $f0
/* D77A8 801410A8 0804FF08 */  j         .L8013FC20
/* D77AC 801410AC E7A60028 */   swc1     $f6, 0x28($sp)
.L801410B0:
/* D77B0 801410B0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* D77B4 801410B4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* D77B8 801410B8 8C620000 */  lw        $v0, ($v1)
/* D77BC 801410BC 0040202D */  daddu     $a0, $v0, $zero
/* D77C0 801410C0 24420008 */  addiu     $v0, $v0, 8
/* D77C4 801410C4 AC620000 */  sw        $v0, ($v1)
/* D77C8 801410C8 3C02E700 */  lui       $v0, 0xe700
/* D77CC 801410CC AC820000 */  sw        $v0, ($a0)
/* D77D0 801410D0 AC800004 */  sw        $zero, 4($a0)
/* D77D4 801410D4 8FBE00B0 */  lw        $fp, 0xb0($sp)
/* D77D8 801410D8 8FB700AC */  lw        $s7, 0xac($sp)
/* D77DC 801410DC 8FB600A8 */  lw        $s6, 0xa8($sp)
/* D77E0 801410E0 8FB500A4 */  lw        $s5, 0xa4($sp)
/* D77E4 801410E4 8FB400A0 */  lw        $s4, 0xa0($sp)
/* D77E8 801410E8 8FB3009C */  lw        $s3, 0x9c($sp)
/* D77EC 801410EC 8FB20098 */  lw        $s2, 0x98($sp)
/* D77F0 801410F0 8FB10094 */  lw        $s1, 0x94($sp)
/* D77F4 801410F4 8FB00090 */  lw        $s0, 0x90($sp)
/* D77F8 801410F8 03E00008 */  jr        $ra
/* D77FC 801410FC 27BD00B8 */   addiu    $sp, $sp, 0xb8
