.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003B720
/* 16B20 8003B720 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 16B24 8003B724 AFB30024 */  sw        $s3, 0x24($sp)
/* 16B28 8003B728 0080982D */  daddu     $s3, $a0, $zero
/* 16B2C 8003B72C AFB60030 */  sw        $s6, 0x30($sp)
/* 16B30 8003B730 00A0B02D */  daddu     $s6, $a1, $zero
/* 16B34 8003B734 AFB40028 */  sw        $s4, 0x28($sp)
/* 16B38 8003B738 00C0A02D */  daddu     $s4, $a2, $zero
/* 16B3C 8003B73C AFBF0038 */  sw        $ra, 0x38($sp)
/* 16B40 8003B740 AFB70034 */  sw        $s7, 0x34($sp)
/* 16B44 8003B744 AFB5002C */  sw        $s5, 0x2c($sp)
/* 16B48 8003B748 AFB20020 */  sw        $s2, 0x20($sp)
/* 16B4C 8003B74C AFB1001C */  sw        $s1, 0x1c($sp)
/* 16B50 8003B750 AFB00018 */  sw        $s0, 0x18($sp)
/* 16B54 8003B754 826200B6 */  lb        $v0, 0xb6($s3)
/* 16B58 8003B758 10400049 */  beqz      $v0, .L8003B880
/* 16B5C 8003B75C 00E0B82D */   daddu    $s7, $a3, $zero
/* 16B60 8003B760 8E620000 */  lw        $v0, ($s3)
/* 16B64 8003B764 3C034000 */  lui       $v1, 0x4000
/* 16B68 8003B768 00431024 */  and       $v0, $v0, $v1
/* 16B6C 8003B76C 14400004 */  bnez      $v0, .L8003B780
/* 16B70 8003B770 00000000 */   nop
/* 16B74 8003B774 0C044964 */  jal       func_80112590
/* 16B78 8003B778 96640028 */   lhu      $a0, 0x28($s3)
/* 16B7C 8003B77C AE6200C4 */  sw        $v0, 0xc4($s3)
.L8003B780:
/* 16B80 8003B780 8E6400C4 */  lw        $a0, 0xc4($s3)
/* 16B84 8003B784 A26000C1 */  sb        $zero, 0xc1($s3)
/* 16B88 8003B788 8C830000 */  lw        $v1, ($a0)
/* 16B8C 8003B78C 2402FFFF */  addiu     $v0, $zero, -1
/* 16B90 8003B790 1062000B */  beq       $v1, $v0, .L8003B7C0
/* 16B94 8003B794 0080182D */   daddu    $v1, $a0, $zero
/* 16B98 8003B798 0040202D */  daddu     $a0, $v0, $zero
.L8003B79C:
/* 16B9C 8003B79C 926200C1 */  lbu       $v0, 0xc1($s3)
/* 16BA0 8003B7A0 24420001 */  addiu     $v0, $v0, 1
/* 16BA4 8003B7A4 A26200C1 */  sb        $v0, 0xc1($s3)
/* 16BA8 8003B7A8 00021600 */  sll       $v0, $v0, 0x18
/* 16BAC 8003B7AC 00021583 */  sra       $v0, $v0, 0x16
/* 16BB0 8003B7B0 00431021 */  addu      $v0, $v0, $v1
/* 16BB4 8003B7B4 8C420000 */  lw        $v0, ($v0)
/* 16BB8 8003B7B8 1444FFF8 */  bne       $v0, $a0, .L8003B79C
/* 16BBC 8003B7BC 00000000 */   nop
.L8003B7C0:
/* 16BC0 8003B7C0 826300B6 */  lb        $v1, 0xb6($s3)
/* 16BC4 8003B7C4 24020001 */  addiu     $v0, $zero, 1
/* 16BC8 8003B7C8 14620004 */  bne       $v1, $v0, .L8003B7DC
/* 16BCC 8003B7CC 240200FF */   addiu    $v0, $zero, 0xff
/* 16BD0 8003B7D0 A26000B7 */  sb        $zero, 0xb7($s3)
/* 16BD4 8003B7D4 0800EDF9 */  j         .L8003B7E4
/* 16BD8 8003B7D8 A66000BE */   sh       $zero, 0xbe($s3)
.L8003B7DC:
/* 16BDC 8003B7DC A26000B7 */  sb        $zero, 0xb7($s3)
/* 16BE0 8003B7E0 A66200BE */  sh        $v0, 0xbe($s3)
.L8003B7E4:
/* 16BE4 8003B7E4 826200C1 */  lb        $v0, 0xc1($s3)
/* 16BE8 8003B7E8 18400018 */  blez      $v0, .L8003B84C
/* 16BEC 8003B7EC 0000202D */   daddu    $a0, $zero, $zero
/* 16BF0 8003B7F0 0260302D */  daddu     $a2, $s3, $zero
/* 16BF4 8003B7F4 240500C8 */  addiu     $a1, $zero, 0xc8
.L8003B7F8:
/* 16BF8 8003B7F8 8E6300C4 */  lw        $v1, 0xc4($s3)
/* 16BFC 8003B7FC 00041080 */  sll       $v0, $a0, 2
/* 16C00 8003B800 00431021 */  addu      $v0, $v0, $v1
/* 16C04 8003B804 8C520000 */  lw        $s2, ($v0)
/* 16C08 8003B808 02658821 */  addu      $s1, $s3, $a1
/* 16C0C 8003B80C 12400009 */  beqz      $s2, .L8003B834
/* 16C10 8003B810 ACD102C8 */   sw       $s1, 0x2c8($a2)
/* 16C14 8003B814 0000802D */  daddu     $s0, $zero, $zero
.L8003B818:
/* 16C18 8003B818 96420000 */  lhu       $v0, ($s2)
/* 16C1C 8003B81C 26520002 */  addiu     $s2, $s2, 2
/* 16C20 8003B820 26100001 */  addiu     $s0, $s0, 1
/* 16C24 8003B824 A6220000 */  sh        $v0, ($s1)
/* 16C28 8003B828 2A020010 */  slti      $v0, $s0, 0x10
/* 16C2C 8003B82C 1440FFFA */  bnez      $v0, .L8003B818
/* 16C30 8003B830 26310002 */   addiu    $s1, $s1, 2
.L8003B834:
/* 16C34 8003B834 24C60004 */  addiu     $a2, $a2, 4
/* 16C38 8003B838 826200C1 */  lb        $v0, 0xc1($s3)
/* 16C3C 8003B83C 24840001 */  addiu     $a0, $a0, 1
/* 16C40 8003B840 0082102A */  slt       $v0, $a0, $v0
/* 16C44 8003B844 1440FFEC */  bnez      $v0, .L8003B7F8
/* 16C48 8003B848 24A50020 */   addiu    $a1, $a1, 0x20
.L8003B84C:
/* 16C4C 8003B84C 16800007 */  bnez      $s4, .L8003B86C
/* 16C50 8003B850 00000000 */   nop
/* 16C54 8003B854 9662030C */  lhu       $v0, 0x30c($s3)
/* 16C58 8003B858 A660030C */  sh        $zero, 0x30c($s3)
/* 16C5C 8003B85C A662030E */  sh        $v0, 0x30e($s3)
/* 16C60 8003B860 0040182D */  daddu     $v1, $v0, $zero
/* 16C64 8003B864 A6620310 */  sh        $v0, 0x310($s3)
/* 16C68 8003B868 A6630312 */  sh        $v1, 0x312($s3)
.L8003B86C:
/* 16C6C 8003B86C 9662030C */  lhu       $v0, 0x30c($s3)
/* 16C70 8003B870 A66000BE */  sh        $zero, 0xbe($s3)
/* 16C74 8003B874 A26000B7 */  sb        $zero, 0xb7($s3)
/* 16C78 8003B878 A26000B6 */  sb        $zero, 0xb6($s3)
/* 16C7C 8003B87C A66200BC */  sh        $v0, 0xbc($s3)
.L8003B880:
/* 16C80 8003B880 826300B7 */  lb        $v1, 0xb7($s3)
/* 16C84 8003B884 10600005 */  beqz      $v1, .L8003B89C
/* 16C88 8003B888 24020001 */   addiu    $v0, $zero, 1
/* 16C8C 8003B88C 1062000C */  beq       $v1, $v0, .L8003B8C0
/* 16C90 8003B890 24020002 */   addiu    $v0, $zero, 2
/* 16C94 8003B894 0800EE70 */  j         .L8003B9C0
/* 16C98 8003B898 00000000 */   nop
.L8003B89C:
/* 16C9C 8003B89C 866200BC */  lh        $v0, 0xbc($s3)
/* 16CA0 8003B8A0 966300BC */  lhu       $v1, 0xbc($s3)
/* 16CA4 8003B8A4 10400003 */  beqz      $v0, .L8003B8B4
/* 16CA8 8003B8A8 2462FFFF */   addiu    $v0, $v1, -1
/* 16CAC 8003B8AC 0800EE6E */  j         .L8003B9B8
/* 16CB0 8003B8B0 A66200BC */   sh       $v0, 0xbc($s3)
.L8003B8B4:
/* 16CB4 8003B8B4 24020001 */  addiu     $v0, $zero, 1
/* 16CB8 8003B8B8 A66000BE */  sh        $zero, 0xbe($s3)
/* 16CBC 8003B8BC A26200B7 */  sb        $v0, 0xb7($s3)
.L8003B8C0:
/* 16CC0 8003B8C0 8662030E */  lh        $v0, 0x30e($s3)
/* 16CC4 8003B8C4 24036400 */  addiu     $v1, $zero, 0x6400
/* 16CC8 8003B8C8 14400002 */  bnez      $v0, .L8003B8D4
/* 16CCC 8003B8CC 0062001A */   div      $zero, $v1, $v0
/* 16CD0 8003B8D0 0007000D */  break     7
.L8003B8D4:
/* 16CD4 8003B8D4 2401FFFF */   addiu    $at, $zero, -1
/* 16CD8 8003B8D8 14410004 */  bne       $v0, $at, .L8003B8EC
/* 16CDC 8003B8DC 3C018000 */   lui      $at, 0x8000
/* 16CE0 8003B8E0 14610002 */  bne       $v1, $at, .L8003B8EC
/* 16CE4 8003B8E4 00000000 */   nop
/* 16CE8 8003B8E8 0006000D */  break     6
.L8003B8EC:
/* 16CEC 8003B8EC 00001812 */   mflo     $v1
/* 16CF0 8003B8F0 966200BE */  lhu       $v0, 0xbe($s3)
/* 16CF4 8003B8F4 00431021 */  addu      $v0, $v0, $v1
/* 16CF8 8003B8F8 A66200BE */  sh        $v0, 0xbe($s3)
/* 16CFC 8003B8FC 00021400 */  sll       $v0, $v0, 0x10
/* 16D00 8003B900 00021403 */  sra       $v0, $v0, 0x10
/* 16D04 8003B904 2842639D */  slti      $v0, $v0, 0x639d
/* 16D08 8003B908 14400003 */  bnez      $v0, .L8003B918
/* 16D0C 8003B90C 3C0651EB */   lui      $a2, 0x51eb
/* 16D10 8003B910 2402639C */  addiu     $v0, $zero, 0x639c
/* 16D14 8003B914 A66200BE */  sh        $v0, 0xbe($s3)
.L8003B918:
/* 16D18 8003B918 34C6851F */  ori       $a2, $a2, 0x851f
/* 16D1C 8003B91C 267400C8 */  addiu     $s4, $s3, 0xc8
/* 16D20 8003B920 0000802D */  daddu     $s0, $zero, $zero
/* 16D24 8003B924 86620308 */  lh        $v0, 0x308($s3)
/* 16D28 8003B928 8E6500C4 */  lw        $a1, 0xc4($s3)
/* 16D2C 8003B92C 966300BE */  lhu       $v1, 0xbe($s3)
/* 16D30 8003B930 00021080 */  sll       $v0, $v0, 2
/* 16D34 8003B934 00451021 */  addu      $v0, $v0, $a1
/* 16D38 8003B938 00031C00 */  sll       $v1, $v1, 0x10
/* 16D3C 8003B93C 00032403 */  sra       $a0, $v1, 0x10
/* 16D40 8003B940 8C520000 */  lw        $s2, ($v0)
/* 16D44 8003B944 8662030A */  lh        $v0, 0x30a($s3)
/* 16D48 8003B948 00860018 */  mult      $a0, $a2
/* 16D4C 8003B94C 00021080 */  sll       $v0, $v0, 2
/* 16D50 8003B950 00451021 */  addu      $v0, $v0, $a1
/* 16D54 8003B954 8C510000 */  lw        $s1, ($v0)
/* 16D58 8003B958 00031FC3 */  sra       $v1, $v1, 0x1f
/* 16D5C 8003B95C AE7402C8 */  sw        $s4, 0x2c8($s3)
/* 16D60 8003B960 00004010 */  mfhi      $t0
/* 16D64 8003B964 00081143 */  sra       $v0, $t0, 5
/* 16D68 8003B968 00431023 */  subu      $v0, $v0, $v1
/* 16D6C 8003B96C 00021400 */  sll       $v0, $v0, 0x10
/* 16D70 8003B970 0002AC03 */  sra       $s5, $v0, 0x10
.L8003B974:
/* 16D74 8003B974 96440000 */  lhu       $a0, ($s2)
/* 16D78 8003B978 26520002 */  addiu     $s2, $s2, 2
/* 16D7C 8003B97C 96250000 */  lhu       $a1, ($s1)
/* 16D80 8003B980 26310002 */  addiu     $s1, $s1, 2
/* 16D84 8003B984 02A0302D */  daddu     $a2, $s5, $zero
/* 16D88 8003B988 0C00ED8B */  jal       func_8003B62C
/* 16D8C 8003B98C 26100001 */   addiu    $s0, $s0, 1
/* 16D90 8003B990 A6820000 */  sh        $v0, ($s4)
/* 16D94 8003B994 2A020010 */  slti      $v0, $s0, 0x10
/* 16D98 8003B998 1440FFF6 */  bnez      $v0, .L8003B974
/* 16D9C 8003B99C 26940002 */   addiu    $s4, $s4, 2
/* 16DA0 8003B9A0 240200FF */  addiu     $v0, $zero, 0xff
/* 16DA4 8003B9A4 16A20004 */  bne       $s5, $v0, .L8003B9B8
/* 16DA8 8003B9A8 24020002 */   addiu    $v0, $zero, 2
/* 16DAC 8003B9AC 96630310 */  lhu       $v1, 0x310($s3)
/* 16DB0 8003B9B0 A26200B7 */  sb        $v0, 0xb7($s3)
/* 16DB4 8003B9B4 A66300BC */  sh        $v1, 0xbc($s3)
.L8003B9B8:
/* 16DB8 8003B9B8 826300B7 */  lb        $v1, 0xb7($s3)
/* 16DBC 8003B9BC 24020002 */  addiu     $v0, $zero, 2
.L8003B9C0:
/* 16DC0 8003B9C0 10620005 */  beq       $v1, $v0, .L8003B9D8
/* 16DC4 8003B9C4 24020003 */   addiu    $v0, $zero, 3
/* 16DC8 8003B9C8 1062000A */  beq       $v1, $v0, .L8003B9F4
/* 16DCC 8003B9CC 00000000 */   nop
/* 16DD0 8003B9D0 0800EEBB */  j         .L8003BAEC
/* 16DD4 8003B9D4 00000000 */   nop
.L8003B9D8:
/* 16DD8 8003B9D8 866200BC */  lh        $v0, 0xbc($s3)
/* 16DDC 8003B9DC 966300BC */  lhu       $v1, 0xbc($s3)
/* 16DE0 8003B9E0 14400041 */  bnez      $v0, .L8003BAE8
/* 16DE4 8003B9E4 2462FFFF */   addiu    $v0, $v1, -1
/* 16DE8 8003B9E8 24020003 */  addiu     $v0, $zero, 3
/* 16DEC 8003B9EC A66000BE */  sh        $zero, 0xbe($s3)
/* 16DF0 8003B9F0 A26200B7 */  sb        $v0, 0xb7($s3)
.L8003B9F4:
/* 16DF4 8003B9F4 86620312 */  lh        $v0, 0x312($s3)
/* 16DF8 8003B9F8 24036400 */  addiu     $v1, $zero, 0x6400
/* 16DFC 8003B9FC 14400002 */  bnez      $v0, .L8003BA08
/* 16E00 8003BA00 0062001A */   div      $zero, $v1, $v0
/* 16E04 8003BA04 0007000D */  break     7
.L8003BA08:
/* 16E08 8003BA08 2401FFFF */   addiu    $at, $zero, -1
/* 16E0C 8003BA0C 14410004 */  bne       $v0, $at, .L8003BA20
/* 16E10 8003BA10 3C018000 */   lui      $at, 0x8000
/* 16E14 8003BA14 14610002 */  bne       $v1, $at, .L8003BA20
/* 16E18 8003BA18 00000000 */   nop
/* 16E1C 8003BA1C 0006000D */  break     6
.L8003BA20:
/* 16E20 8003BA20 00001812 */   mflo     $v1
/* 16E24 8003BA24 966200BE */  lhu       $v0, 0xbe($s3)
/* 16E28 8003BA28 00431021 */  addu      $v0, $v0, $v1
/* 16E2C 8003BA2C A66200BE */  sh        $v0, 0xbe($s3)
/* 16E30 8003BA30 00021400 */  sll       $v0, $v0, 0x10
/* 16E34 8003BA34 00021403 */  sra       $v0, $v0, 0x10
/* 16E38 8003BA38 2842639D */  slti      $v0, $v0, 0x639d
/* 16E3C 8003BA3C 14400003 */  bnez      $v0, .L8003BA4C
/* 16E40 8003BA40 3C0651EB */   lui      $a2, 0x51eb
/* 16E44 8003BA44 2402639C */  addiu     $v0, $zero, 0x639c
/* 16E48 8003BA48 A66200BE */  sh        $v0, 0xbe($s3)
.L8003BA4C:
/* 16E4C 8003BA4C 34C6851F */  ori       $a2, $a2, 0x851f
/* 16E50 8003BA50 267400C8 */  addiu     $s4, $s3, 0xc8
/* 16E54 8003BA54 0000802D */  daddu     $s0, $zero, $zero
/* 16E58 8003BA58 8662030A */  lh        $v0, 0x30a($s3)
/* 16E5C 8003BA5C 8E6500C4 */  lw        $a1, 0xc4($s3)
/* 16E60 8003BA60 966300BE */  lhu       $v1, 0xbe($s3)
/* 16E64 8003BA64 00021080 */  sll       $v0, $v0, 2
/* 16E68 8003BA68 00451021 */  addu      $v0, $v0, $a1
/* 16E6C 8003BA6C 00031C00 */  sll       $v1, $v1, 0x10
/* 16E70 8003BA70 00032403 */  sra       $a0, $v1, 0x10
/* 16E74 8003BA74 8C520000 */  lw        $s2, ($v0)
/* 16E78 8003BA78 86620308 */  lh        $v0, 0x308($s3)
/* 16E7C 8003BA7C 00860018 */  mult      $a0, $a2
/* 16E80 8003BA80 00021080 */  sll       $v0, $v0, 2
/* 16E84 8003BA84 00451021 */  addu      $v0, $v0, $a1
/* 16E88 8003BA88 8C510000 */  lw        $s1, ($v0)
/* 16E8C 8003BA8C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 16E90 8003BA90 AE7402C8 */  sw        $s4, 0x2c8($s3)
/* 16E94 8003BA94 00004010 */  mfhi      $t0
/* 16E98 8003BA98 00081143 */  sra       $v0, $t0, 5
/* 16E9C 8003BA9C 00431023 */  subu      $v0, $v0, $v1
/* 16EA0 8003BAA0 00021400 */  sll       $v0, $v0, 0x10
/* 16EA4 8003BAA4 0002AC03 */  sra       $s5, $v0, 0x10
.L8003BAA8:
/* 16EA8 8003BAA8 96440000 */  lhu       $a0, ($s2)
/* 16EAC 8003BAAC 26520002 */  addiu     $s2, $s2, 2
/* 16EB0 8003BAB0 96250000 */  lhu       $a1, ($s1)
/* 16EB4 8003BAB4 26310002 */  addiu     $s1, $s1, 2
/* 16EB8 8003BAB8 02A0302D */  daddu     $a2, $s5, $zero
/* 16EBC 8003BABC 0C00ED8B */  jal       func_8003B62C
/* 16EC0 8003BAC0 26100001 */   addiu    $s0, $s0, 1
/* 16EC4 8003BAC4 A6820000 */  sh        $v0, ($s4)
/* 16EC8 8003BAC8 2A020010 */  slti      $v0, $s0, 0x10
/* 16ECC 8003BACC 1440FFF6 */  bnez      $v0, .L8003BAA8
/* 16ED0 8003BAD0 26940002 */   addiu    $s4, $s4, 2
/* 16ED4 8003BAD4 240200FF */  addiu     $v0, $zero, 0xff
/* 16ED8 8003BAD8 16A20004 */  bne       $s5, $v0, .L8003BAEC
/* 16EDC 8003BADC 00000000 */   nop
/* 16EE0 8003BAE0 9662030C */  lhu       $v0, 0x30c($s3)
/* 16EE4 8003BAE4 A26000B7 */  sb        $zero, 0xb7($s3)
.L8003BAE8:
/* 16EE8 8003BAE8 A66200BC */  sh        $v0, 0xbc($s3)
.L8003BAEC:
/* 16EEC 8003BAEC 826300B7 */  lb        $v1, 0xb7($s3)
/* 16EF0 8003BAF0 28620004 */  slti      $v0, $v1, 4
/* 16EF4 8003BAF4 1040001D */  beqz      $v0, .L8003BB6C
/* 16EF8 8003BAF8 00000000 */   nop
/* 16EFC 8003BAFC 0460001B */  bltz      $v1, .L8003BB6C
/* 16F00 8003BB00 3C034000 */   lui      $v1, 0x4000
/* 16F04 8003BB04 8E620000 */  lw        $v0, ($s3)
/* 16F08 8003BB08 00431024 */  and       $v0, $v0, $v1
/* 16F0C 8003BB0C 14400017 */  bnez      $v0, .L8003BB6C
/* 16F10 8003BB10 02C0282D */   daddu    $a1, $s6, $zero
/* 16F14 8003BB14 926300AC */  lbu       $v1, 0xac($s3)
/* 16F18 8003BB18 926200AD */  lbu       $v0, 0xad($s3)
/* 16F1C 8003BB1C 00620018 */  mult      $v1, $v0
/* 16F20 8003BB20 00001812 */  mflo      $v1
/* 16F24 8003BB24 3C028080 */  lui       $v0, 0x8080
/* 16F28 8003BB28 34428081 */  ori       $v0, $v0, 0x8081
/* 16F2C 8003BB2C 00620018 */  mult      $v1, $v0
/* 16F30 8003BB30 8E660024 */  lw        $a2, 0x24($s3)
/* 16F34 8003BB34 266702C8 */  addiu     $a3, $s3, 0x2c8
/* 16F38 8003BB38 AFB70010 */  sw        $s7, 0x10($sp)
/* 16F3C 8003BB3C 00004810 */  mfhi      $t1
/* 16F40 8003BB40 01231021 */  addu      $v0, $t1, $v1
/* 16F44 8003BB44 000211C3 */  sra       $v0, $v0, 7
/* 16F48 8003BB48 00031FC3 */  sra       $v1, $v1, 0x1f
/* 16F4C 8003BB4C 0043A823 */  subu      $s5, $v0, $v1
/* 16F50 8003BB50 2AA400FF */  slti      $a0, $s5, 0xff
/* 16F54 8003BB54 000427C0 */  sll       $a0, $a0, 0x1f
/* 16F58 8003BB58 3C022000 */  lui       $v0, 0x2000
/* 16F5C 8003BB5C 00822025 */  or        $a0, $a0, $v0
/* 16F60 8003BB60 00C42025 */  or        $a0, $a2, $a0
/* 16F64 8003BB64 0C0447CA */  jal       func_80111F28
/* 16F68 8003BB68 02A0302D */   daddu    $a2, $s5, $zero
.L8003BB6C:
/* 16F6C 8003BB6C 8FBF0038 */  lw        $ra, 0x38($sp)
/* 16F70 8003BB70 8FB70034 */  lw        $s7, 0x34($sp)
/* 16F74 8003BB74 8FB60030 */  lw        $s6, 0x30($sp)
/* 16F78 8003BB78 8FB5002C */  lw        $s5, 0x2c($sp)
/* 16F7C 8003BB7C 8FB40028 */  lw        $s4, 0x28($sp)
/* 16F80 8003BB80 8FB30024 */  lw        $s3, 0x24($sp)
/* 16F84 8003BB84 8FB20020 */  lw        $s2, 0x20($sp)
/* 16F88 8003BB88 8FB1001C */  lw        $s1, 0x1c($sp)
/* 16F8C 8003BB8C 8FB00018 */  lw        $s0, 0x18($sp)
/* 16F90 8003BB90 03E00008 */  jr        $ra
/* 16F94 8003BB94 27BD0040 */   addiu    $sp, $sp, 0x40
