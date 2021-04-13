.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006D7E0
/* 48BE0 8006D7E0 04810008 */  bgez      $a0, .L8006D804
/* 48BE4 8006D7E4 0000C02D */   daddu    $t8, $zero, $zero
/* 48BE8 8006D7E8 2418FFFF */  addiu     $t8, $zero, -1
/* 48BEC 8006D7EC 00054823 */  negu      $t1, $a1
/* 48BF0 8006D7F0 00041823 */  negu      $v1, $a0
/* 48BF4 8006D7F4 0009102B */  sltu      $v0, $zero, $t1
/* 48BF8 8006D7F8 00624023 */  subu      $t0, $v1, $v0
/* 48BFC 8006D7FC 0100202D */  daddu     $a0, $t0, $zero
/* 48C00 8006D800 0120282D */  daddu     $a1, $t1, $zero
.L8006D804:
/* 48C04 8006D804 04C10009 */  bgez      $a2, .L8006D82C
/* 48C08 8006D808 00E0482D */   daddu    $t1, $a3, $zero
/* 48C0C 8006D80C 0018C027 */  nor       $t8, $zero, $t8
/* 48C10 8006D810 00075823 */  negu      $t3, $a3
/* 48C14 8006D814 00061823 */  negu      $v1, $a2
/* 48C18 8006D818 000B102B */  sltu      $v0, $zero, $t3
/* 48C1C 8006D81C 00625023 */  subu      $t2, $v1, $v0
/* 48C20 8006D820 0140302D */  daddu     $a2, $t2, $zero
/* 48C24 8006D824 0160382D */  daddu     $a3, $t3, $zero
/* 48C28 8006D828 00E0482D */  daddu     $t1, $a3, $zero
.L8006D82C:
/* 48C2C 8006D82C 00C0402D */  daddu     $t0, $a2, $zero
/* 48C30 8006D830 150000DF */  bnez      $t0, .L8006DBB0
/* 48C34 8006D834 00A0582D */   daddu    $t3, $a1, $zero
/* 48C38 8006D838 0089102B */  sltu      $v0, $a0, $t1
/* 48C3C 8006D83C 1040004E */  beqz      $v0, .L8006D978
/* 48C40 8006D840 3402FFFF */   ori      $v0, $zero, 0xffff
/* 48C44 8006D844 0049102B */  sltu      $v0, $v0, $t1
/* 48C48 8006D848 14400005 */  bnez      $v0, .L8006D860
/* 48C4C 8006D84C 00E0182D */   daddu    $v1, $a3, $zero
/* 48C50 8006D850 2D220100 */  sltiu     $v0, $t1, 0x100
/* 48C54 8006D854 38420001 */  xori      $v0, $v0, 1
/* 48C58 8006D858 0801B61E */  j         .L8006D878
/* 48C5C 8006D85C 000240C0 */   sll      $t0, $v0, 3
.L8006D860:
/* 48C60 8006D860 3C0200FF */  lui       $v0, 0xff
/* 48C64 8006D864 3442FFFF */  ori       $v0, $v0, 0xffff
/* 48C68 8006D868 0049102B */  sltu      $v0, $v0, $t1
/* 48C6C 8006D86C 14400002 */  bnez      $v0, .L8006D878
/* 48C70 8006D870 24080018 */   addiu    $t0, $zero, 0x18
/* 48C74 8006D874 24080010 */  addiu     $t0, $zero, 0x10
.L8006D878:
/* 48C78 8006D878 01031006 */  srlv      $v0, $v1, $t0
/* 48C7C 8006D87C 3C01800A */  lui       $at, %hi(D_80099E20)
/* 48C80 8006D880 00220821 */  addu      $at, $at, $v0
/* 48C84 8006D884 90229E20 */  lbu       $v0, %lo(D_80099E20)($at)
/* 48C88 8006D888 24050020 */  addiu     $a1, $zero, 0x20
/* 48C8C 8006D88C 00481021 */  addu      $v0, $v0, $t0
/* 48C90 8006D890 00A23023 */  subu      $a2, $a1, $v0
/* 48C94 8006D894 10C00006 */  beqz      $a2, .L8006D8B0
/* 48C98 8006D898 00C41804 */   sllv     $v1, $a0, $a2
/* 48C9C 8006D89C 00C94804 */  sllv      $t1, $t1, $a2
/* 48CA0 8006D8A0 00A61023 */  subu      $v0, $a1, $a2
/* 48CA4 8006D8A4 004B1006 */  srlv      $v0, $t3, $v0
/* 48CA8 8006D8A8 00622025 */  or        $a0, $v1, $v0
/* 48CAC 8006D8AC 00CB5804 */  sllv      $t3, $t3, $a2
.L8006D8B0:
/* 48CB0 8006D8B0 00093402 */  srl       $a2, $t1, 0x10
/* 48CB4 8006D8B4 14C00002 */  bnez      $a2, .L8006D8C0
/* 48CB8 8006D8B8 0086001B */   divu     $zero, $a0, $a2
/* 48CBC 8006D8BC 0007000D */  break     7
.L8006D8C0:
/* 48CC0 8006D8C0 00003812 */   mflo     $a3
/* 48CC4 8006D8C4 00001810 */  mfhi      $v1
/* 48CC8 8006D8C8 3128FFFF */  andi      $t0, $t1, 0xffff
/* 48CCC 8006D8CC 00000000 */  nop
/* 48CD0 8006D8D0 00E80018 */  mult      $a3, $t0
/* 48CD4 8006D8D4 000B1402 */  srl       $v0, $t3, 0x10
/* 48CD8 8006D8D8 00031C00 */  sll       $v1, $v1, 0x10
/* 48CDC 8006D8DC 00621825 */  or        $v1, $v1, $v0
/* 48CE0 8006D8E0 00002812 */  mflo      $a1
/* 48CE4 8006D8E4 0065102B */  sltu      $v0, $v1, $a1
/* 48CE8 8006D8E8 5040000B */  beql      $v0, $zero, .L8006D918
/* 48CEC 8006D8EC 00651823 */   subu     $v1, $v1, $a1
/* 48CF0 8006D8F0 00691821 */  addu      $v1, $v1, $t1
/* 48CF4 8006D8F4 0069102B */  sltu      $v0, $v1, $t1
/* 48CF8 8006D8F8 14400006 */  bnez      $v0, .L8006D914
/* 48CFC 8006D8FC 24E7FFFF */   addiu    $a3, $a3, -1
/* 48D00 8006D900 0065102B */  sltu      $v0, $v1, $a1
/* 48D04 8006D904 50400004 */  beql      $v0, $zero, .L8006D918
/* 48D08 8006D908 00651823 */   subu     $v1, $v1, $a1
/* 48D0C 8006D90C 24E7FFFF */  addiu     $a3, $a3, -1
/* 48D10 8006D910 00691821 */  addu      $v1, $v1, $t1
.L8006D914:
/* 48D14 8006D914 00651823 */  subu      $v1, $v1, $a1
.L8006D918:
/* 48D18 8006D918 14C00002 */  bnez      $a2, .L8006D924
/* 48D1C 8006D91C 0066001B */   divu     $zero, $v1, $a2
/* 48D20 8006D920 0007000D */  break     7
.L8006D924:
/* 48D24 8006D924 00002012 */   mflo     $a0
/* 48D28 8006D928 00001810 */  mfhi      $v1
/* 48D2C 8006D92C 00000000 */  nop
/* 48D30 8006D930 00000000 */  nop
/* 48D34 8006D934 00880018 */  mult      $a0, $t0
/* 48D38 8006D938 3162FFFF */  andi      $v0, $t3, 0xffff
/* 48D3C 8006D93C 00031C00 */  sll       $v1, $v1, 0x10
/* 48D40 8006D940 00621825 */  or        $v1, $v1, $v0
/* 48D44 8006D944 00002812 */  mflo      $a1
/* 48D48 8006D948 0065102B */  sltu      $v0, $v1, $a1
/* 48D4C 8006D94C 10400007 */  beqz      $v0, .L8006D96C
/* 48D50 8006D950 00691821 */   addu     $v1, $v1, $t1
/* 48D54 8006D954 0069102B */  sltu      $v0, $v1, $t1
/* 48D58 8006D958 14400004 */  bnez      $v0, .L8006D96C
/* 48D5C 8006D95C 2484FFFF */   addiu    $a0, $a0, -1
/* 48D60 8006D960 0065102B */  sltu      $v0, $v1, $a1
/* 48D64 8006D964 54400001 */  bnel      $v0, $zero, .L8006D96C
/* 48D68 8006D968 2484FFFF */   addiu    $a0, $a0, -1
.L8006D96C:
/* 48D6C 8006D96C 00071400 */  sll       $v0, $a3, 0x10
/* 48D70 8006D970 0801B759 */  j         .L8006DD64
/* 48D74 8006D974 00443025 */   or       $a2, $v0, $a0
.L8006D978:
/* 48D78 8006D978 15200008 */  bnez      $t1, .L8006D99C
/* 48D7C 8006D97C 0049102B */   sltu     $v0, $v0, $t1
/* 48D80 8006D980 24020001 */  addiu     $v0, $zero, 1
/* 48D84 8006D984 15000002 */  bnez      $t0, .L8006D990
/* 48D88 8006D988 0048001B */   divu     $zero, $v0, $t0
/* 48D8C 8006D98C 0007000D */  break     7
.L8006D990:
/* 48D90 8006D990 00004812 */   mflo     $t1
/* 48D94 8006D994 3402FFFF */  ori       $v0, $zero, 0xffff
/* 48D98 8006D998 0049102B */  sltu      $v0, $v0, $t1
.L8006D99C:
/* 48D9C 8006D99C 14400005 */  bnez      $v0, .L8006D9B4
/* 48DA0 8006D9A0 0120282D */   daddu    $a1, $t1, $zero
/* 48DA4 8006D9A4 2D220100 */  sltiu     $v0, $t1, 0x100
/* 48DA8 8006D9A8 38420001 */  xori      $v0, $v0, 1
/* 48DAC 8006D9AC 0801B673 */  j         .L8006D9CC
/* 48DB0 8006D9B0 000218C0 */   sll      $v1, $v0, 3
.L8006D9B4:
/* 48DB4 8006D9B4 3C0200FF */  lui       $v0, 0xff
/* 48DB8 8006D9B8 3442FFFF */  ori       $v0, $v0, 0xffff
/* 48DBC 8006D9BC 0049102B */  sltu      $v0, $v0, $t1
/* 48DC0 8006D9C0 14400002 */  bnez      $v0, .L8006D9CC
/* 48DC4 8006D9C4 24030018 */   addiu    $v1, $zero, 0x18
/* 48DC8 8006D9C8 24030010 */  addiu     $v1, $zero, 0x10
.L8006D9CC:
/* 48DCC 8006D9CC 00651006 */  srlv      $v0, $a1, $v1
/* 48DD0 8006D9D0 3C01800A */  lui       $at, %hi(D_80099E20)
/* 48DD4 8006D9D4 00220821 */  addu      $at, $at, $v0
/* 48DD8 8006D9D8 90229E20 */  lbu       $v0, %lo(D_80099E20)($at)
/* 48DDC 8006D9DC 00431021 */  addu      $v0, $v0, $v1
/* 48DE0 8006D9E0 24030020 */  addiu     $v1, $zero, 0x20
/* 48DE4 8006D9E4 00623023 */  subu      $a2, $v1, $v0
/* 48DE8 8006D9E8 14C00004 */  bnez      $a2, .L8006D9FC
/* 48DEC 8006D9EC 00662823 */   subu     $a1, $v1, $a2
/* 48DF0 8006D9F0 00892023 */  subu      $a0, $a0, $t1
/* 48DF4 8006D9F4 0801B6BA */  j         .L8006DAE8
/* 48DF8 8006D9F8 240A0001 */   addiu    $t2, $zero, 1
.L8006D9FC:
/* 48DFC 8006D9FC 00C94804 */  sllv      $t1, $t1, $a2
/* 48E00 8006DA00 00A43806 */  srlv      $a3, $a0, $a1
/* 48E04 8006DA04 00C41804 */  sllv      $v1, $a0, $a2
/* 48E08 8006DA08 00AB1006 */  srlv      $v0, $t3, $a1
/* 48E0C 8006DA0C 00622025 */  or        $a0, $v1, $v0
/* 48E10 8006DA10 00CB5804 */  sllv      $t3, $t3, $a2
/* 48E14 8006DA14 00093402 */  srl       $a2, $t1, 0x10
/* 48E18 8006DA18 14C00002 */  bnez      $a2, .L8006DA24
/* 48E1C 8006DA1C 00E6001B */   divu     $zero, $a3, $a2
/* 48E20 8006DA20 0007000D */  break     7
.L8006DA24:
/* 48E24 8006DA24 00004012 */   mflo     $t0
/* 48E28 8006DA28 00001810 */  mfhi      $v1
/* 48E2C 8006DA2C 3125FFFF */  andi      $a1, $t1, 0xffff
/* 48E30 8006DA30 00000000 */  nop
/* 48E34 8006DA34 01050018 */  mult      $t0, $a1
/* 48E38 8006DA38 00041402 */  srl       $v0, $a0, 0x10
/* 48E3C 8006DA3C 00031C00 */  sll       $v1, $v1, 0x10
/* 48E40 8006DA40 00621825 */  or        $v1, $v1, $v0
/* 48E44 8006DA44 00003812 */  mflo      $a3
/* 48E48 8006DA48 0067102B */  sltu      $v0, $v1, $a3
/* 48E4C 8006DA4C 5040000B */  beql      $v0, $zero, .L8006DA7C
/* 48E50 8006DA50 00671823 */   subu     $v1, $v1, $a3
/* 48E54 8006DA54 00691821 */  addu      $v1, $v1, $t1
/* 48E58 8006DA58 0069102B */  sltu      $v0, $v1, $t1
/* 48E5C 8006DA5C 14400006 */  bnez      $v0, .L8006DA78
/* 48E60 8006DA60 2508FFFF */   addiu    $t0, $t0, -1
/* 48E64 8006DA64 0067102B */  sltu      $v0, $v1, $a3
/* 48E68 8006DA68 50400004 */  beql      $v0, $zero, .L8006DA7C
/* 48E6C 8006DA6C 00671823 */   subu     $v1, $v1, $a3
/* 48E70 8006DA70 2508FFFF */  addiu     $t0, $t0, -1
/* 48E74 8006DA74 00691821 */  addu      $v1, $v1, $t1
.L8006DA78:
/* 48E78 8006DA78 00671823 */  subu      $v1, $v1, $a3
.L8006DA7C:
/* 48E7C 8006DA7C 14C00002 */  bnez      $a2, .L8006DA88
/* 48E80 8006DA80 0066001B */   divu     $zero, $v1, $a2
/* 48E84 8006DA84 0007000D */  break     7
.L8006DA88:
/* 48E88 8006DA88 00003012 */   mflo     $a2
/* 48E8C 8006DA8C 00001810 */  mfhi      $v1
/* 48E90 8006DA90 00000000 */  nop
/* 48E94 8006DA94 00000000 */  nop
/* 48E98 8006DA98 00C50018 */  mult      $a2, $a1
/* 48E9C 8006DA9C 3082FFFF */  andi      $v0, $a0, 0xffff
/* 48EA0 8006DAA0 00031C00 */  sll       $v1, $v1, 0x10
/* 48EA4 8006DAA4 00621825 */  or        $v1, $v1, $v0
/* 48EA8 8006DAA8 00003812 */  mflo      $a3
/* 48EAC 8006DAAC 0067102B */  sltu      $v0, $v1, $a3
/* 48EB0 8006DAB0 1040000B */  beqz      $v0, .L8006DAE0
/* 48EB4 8006DAB4 00081400 */   sll      $v0, $t0, 0x10
/* 48EB8 8006DAB8 00691821 */  addu      $v1, $v1, $t1
/* 48EBC 8006DABC 0069102B */  sltu      $v0, $v1, $t1
/* 48EC0 8006DAC0 14400006 */  bnez      $v0, .L8006DADC
/* 48EC4 8006DAC4 24C6FFFF */   addiu    $a2, $a2, -1
/* 48EC8 8006DAC8 0067102B */  sltu      $v0, $v1, $a3
/* 48ECC 8006DACC 10400004 */  beqz      $v0, .L8006DAE0
/* 48ED0 8006DAD0 00081400 */   sll      $v0, $t0, 0x10
/* 48ED4 8006DAD4 24C6FFFF */  addiu     $a2, $a2, -1
/* 48ED8 8006DAD8 00691821 */  addu      $v1, $v1, $t1
.L8006DADC:
/* 48EDC 8006DADC 00081400 */  sll       $v0, $t0, 0x10
.L8006DAE0:
/* 48EE0 8006DAE0 00465025 */  or        $t2, $v0, $a2
/* 48EE4 8006DAE4 00672023 */  subu      $a0, $v1, $a3
.L8006DAE8:
/* 48EE8 8006DAE8 00093402 */  srl       $a2, $t1, 0x10
/* 48EEC 8006DAEC 14C00002 */  bnez      $a2, .L8006DAF8
/* 48EF0 8006DAF0 0086001B */   divu     $zero, $a0, $a2
/* 48EF4 8006DAF4 0007000D */  break     7
.L8006DAF8:
/* 48EF8 8006DAF8 00003812 */   mflo     $a3
/* 48EFC 8006DAFC 00001810 */  mfhi      $v1
/* 48F00 8006DB00 3128FFFF */  andi      $t0, $t1, 0xffff
/* 48F04 8006DB04 00000000 */  nop
/* 48F08 8006DB08 00E80018 */  mult      $a3, $t0
/* 48F0C 8006DB0C 000B1402 */  srl       $v0, $t3, 0x10
/* 48F10 8006DB10 00031C00 */  sll       $v1, $v1, 0x10
/* 48F14 8006DB14 00621825 */  or        $v1, $v1, $v0
/* 48F18 8006DB18 00002812 */  mflo      $a1
/* 48F1C 8006DB1C 0065102B */  sltu      $v0, $v1, $a1
/* 48F20 8006DB20 5040000B */  beql      $v0, $zero, .L8006DB50
/* 48F24 8006DB24 00651823 */   subu     $v1, $v1, $a1
/* 48F28 8006DB28 00691821 */  addu      $v1, $v1, $t1
/* 48F2C 8006DB2C 0069102B */  sltu      $v0, $v1, $t1
/* 48F30 8006DB30 14400006 */  bnez      $v0, .L8006DB4C
/* 48F34 8006DB34 24E7FFFF */   addiu    $a3, $a3, -1
/* 48F38 8006DB38 0065102B */  sltu      $v0, $v1, $a1
/* 48F3C 8006DB3C 50400004 */  beql      $v0, $zero, .L8006DB50
/* 48F40 8006DB40 00651823 */   subu     $v1, $v1, $a1
/* 48F44 8006DB44 24E7FFFF */  addiu     $a3, $a3, -1
/* 48F48 8006DB48 00691821 */  addu      $v1, $v1, $t1
.L8006DB4C:
/* 48F4C 8006DB4C 00651823 */  subu      $v1, $v1, $a1
.L8006DB50:
/* 48F50 8006DB50 14C00002 */  bnez      $a2, .L8006DB5C
/* 48F54 8006DB54 0066001B */   divu     $zero, $v1, $a2
/* 48F58 8006DB58 0007000D */  break     7
.L8006DB5C:
/* 48F5C 8006DB5C 00002012 */   mflo     $a0
/* 48F60 8006DB60 00001810 */  mfhi      $v1
/* 48F64 8006DB64 00000000 */  nop
/* 48F68 8006DB68 00000000 */  nop
/* 48F6C 8006DB6C 00880018 */  mult      $a0, $t0
/* 48F70 8006DB70 3162FFFF */  andi      $v0, $t3, 0xffff
/* 48F74 8006DB74 00031C00 */  sll       $v1, $v1, 0x10
/* 48F78 8006DB78 00621825 */  or        $v1, $v1, $v0
/* 48F7C 8006DB7C 00002812 */  mflo      $a1
/* 48F80 8006DB80 0065102B */  sltu      $v0, $v1, $a1
/* 48F84 8006DB84 10400007 */  beqz      $v0, .L8006DBA4
/* 48F88 8006DB88 00691821 */   addu     $v1, $v1, $t1
/* 48F8C 8006DB8C 0069102B */  sltu      $v0, $v1, $t1
/* 48F90 8006DB90 14400004 */  bnez      $v0, .L8006DBA4
/* 48F94 8006DB94 2484FFFF */   addiu    $a0, $a0, -1
/* 48F98 8006DB98 0065102B */  sltu      $v0, $v1, $a1
/* 48F9C 8006DB9C 54400001 */  bnel      $v0, $zero, .L8006DBA4
/* 48FA0 8006DBA0 2484FFFF */   addiu    $a0, $a0, -1
.L8006DBA4:
/* 48FA4 8006DBA4 00071400 */  sll       $v0, $a3, 0x10
/* 48FA8 8006DBA8 0801B75A */  j         .L8006DD68
/* 48FAC 8006DBAC 00443025 */   or       $a2, $v0, $a0
.L8006DBB0:
/* 48FB0 8006DBB0 0088102B */  sltu      $v0, $a0, $t0
/* 48FB4 8006DBB4 10400003 */  beqz      $v0, .L8006DBC4
/* 48FB8 8006DBB8 3402FFFF */   ori      $v0, $zero, 0xffff
/* 48FBC 8006DBBC 0801B759 */  j         .L8006DD64
/* 48FC0 8006DBC0 0000302D */   daddu    $a2, $zero, $zero
.L8006DBC4:
/* 48FC4 8006DBC4 0048102B */  sltu      $v0, $v0, $t0
/* 48FC8 8006DBC8 14400005 */  bnez      $v0, .L8006DBE0
/* 48FCC 8006DBCC 0100282D */   daddu    $a1, $t0, $zero
/* 48FD0 8006DBD0 2D020100 */  sltiu     $v0, $t0, 0x100
/* 48FD4 8006DBD4 38420001 */  xori      $v0, $v0, 1
/* 48FD8 8006DBD8 0801B6FE */  j         .L8006DBF8
/* 48FDC 8006DBDC 000218C0 */   sll      $v1, $v0, 3
.L8006DBE0:
/* 48FE0 8006DBE0 3C0200FF */  lui       $v0, 0xff
/* 48FE4 8006DBE4 3442FFFF */  ori       $v0, $v0, 0xffff
/* 48FE8 8006DBE8 0048102B */  sltu      $v0, $v0, $t0
/* 48FEC 8006DBEC 14400002 */  bnez      $v0, .L8006DBF8
/* 48FF0 8006DBF0 24030018 */   addiu    $v1, $zero, 0x18
/* 48FF4 8006DBF4 24030010 */  addiu     $v1, $zero, 0x10
.L8006DBF8:
/* 48FF8 8006DBF8 00651006 */  srlv      $v0, $a1, $v1
/* 48FFC 8006DBFC 3C01800A */  lui       $at, %hi(D_80099E20)
/* 49000 8006DC00 00220821 */  addu      $at, $at, $v0
/* 49004 8006DC04 90229E20 */  lbu       $v0, %lo(D_80099E20)($at)
/* 49008 8006DC08 00431021 */  addu      $v0, $v0, $v1
/* 4900C 8006DC0C 24030020 */  addiu     $v1, $zero, 0x20
/* 49010 8006DC10 00623023 */  subu      $a2, $v1, $v0
/* 49014 8006DC14 54C00009 */  bnel      $a2, $zero, .L8006DC3C
/* 49018 8006DC18 00662823 */   subu     $a1, $v1, $a2
/* 4901C 8006DC1C 0104102B */  sltu      $v0, $t0, $a0
/* 49020 8006DC20 14400050 */  bnez      $v0, .L8006DD64
/* 49024 8006DC24 24060001 */   addiu    $a2, $zero, 1
/* 49028 8006DC28 0169102B */  sltu      $v0, $t3, $t1
/* 4902C 8006DC2C 1440004D */  bnez      $v0, .L8006DD64
/* 49030 8006DC30 0000302D */   daddu    $a2, $zero, $zero
/* 49034 8006DC34 0801B759 */  j         .L8006DD64
/* 49038 8006DC38 24060001 */   addiu    $a2, $zero, 1
.L8006DC3C:
/* 4903C 8006DC3C 00C81804 */  sllv      $v1, $t0, $a2
/* 49040 8006DC40 00A91006 */  srlv      $v0, $t1, $a1
/* 49044 8006DC44 00624025 */  or        $t0, $v1, $v0
/* 49048 8006DC48 00C94804 */  sllv      $t1, $t1, $a2
/* 4904C 8006DC4C 00A43806 */  srlv      $a3, $a0, $a1
/* 49050 8006DC50 00C41804 */  sllv      $v1, $a0, $a2
/* 49054 8006DC54 00AB1006 */  srlv      $v0, $t3, $a1
/* 49058 8006DC58 00622025 */  or        $a0, $v1, $v0
/* 4905C 8006DC5C 00CB5804 */  sllv      $t3, $t3, $a2
/* 49060 8006DC60 00083402 */  srl       $a2, $t0, 0x10
/* 49064 8006DC64 14C00002 */  bnez      $a2, .L8006DC70
/* 49068 8006DC68 00E6001B */   divu     $zero, $a3, $a2
/* 4906C 8006DC6C 0007000D */  break     7
.L8006DC70:
/* 49070 8006DC70 00005012 */   mflo     $t2
/* 49074 8006DC74 00001810 */  mfhi      $v1
/* 49078 8006DC78 3105FFFF */  andi      $a1, $t0, 0xffff
/* 4907C 8006DC7C 00000000 */  nop
/* 49080 8006DC80 01450018 */  mult      $t2, $a1
/* 49084 8006DC84 00041402 */  srl       $v0, $a0, 0x10
/* 49088 8006DC88 00031C00 */  sll       $v1, $v1, 0x10
/* 4908C 8006DC8C 00621825 */  or        $v1, $v1, $v0
/* 49090 8006DC90 00003812 */  mflo      $a3
/* 49094 8006DC94 0067102B */  sltu      $v0, $v1, $a3
/* 49098 8006DC98 5040000B */  beql      $v0, $zero, .L8006DCC8
/* 4909C 8006DC9C 00671823 */   subu     $v1, $v1, $a3
/* 490A0 8006DCA0 00681821 */  addu      $v1, $v1, $t0
/* 490A4 8006DCA4 0068102B */  sltu      $v0, $v1, $t0
/* 490A8 8006DCA8 14400006 */  bnez      $v0, .L8006DCC4
/* 490AC 8006DCAC 254AFFFF */   addiu    $t2, $t2, -1
/* 490B0 8006DCB0 0067102B */  sltu      $v0, $v1, $a3
/* 490B4 8006DCB4 50400004 */  beql      $v0, $zero, .L8006DCC8
/* 490B8 8006DCB8 00671823 */   subu     $v1, $v1, $a3
/* 490BC 8006DCBC 254AFFFF */  addiu     $t2, $t2, -1
/* 490C0 8006DCC0 00681821 */  addu      $v1, $v1, $t0
.L8006DCC4:
/* 490C4 8006DCC4 00671823 */  subu      $v1, $v1, $a3
.L8006DCC8:
/* 490C8 8006DCC8 14C00002 */  bnez      $a2, .L8006DCD4
/* 490CC 8006DCCC 0066001B */   divu     $zero, $v1, $a2
/* 490D0 8006DCD0 0007000D */  break     7
.L8006DCD4:
/* 490D4 8006DCD4 00003012 */   mflo     $a2
/* 490D8 8006DCD8 00001810 */  mfhi      $v1
/* 490DC 8006DCDC 00000000 */  nop
/* 490E0 8006DCE0 00000000 */  nop
/* 490E4 8006DCE4 00C50018 */  mult      $a2, $a1
/* 490E8 8006DCE8 3082FFFF */  andi      $v0, $a0, 0xffff
/* 490EC 8006DCEC 00031C00 */  sll       $v1, $v1, 0x10
/* 490F0 8006DCF0 00621825 */  or        $v1, $v1, $v0
/* 490F4 8006DCF4 00003812 */  mflo      $a3
/* 490F8 8006DCF8 0067102B */  sltu      $v0, $v1, $a3
/* 490FC 8006DCFC 1040000B */  beqz      $v0, .L8006DD2C
/* 49100 8006DD00 000A1400 */   sll      $v0, $t2, 0x10
/* 49104 8006DD04 00681821 */  addu      $v1, $v1, $t0
/* 49108 8006DD08 0068102B */  sltu      $v0, $v1, $t0
/* 4910C 8006DD0C 14400006 */  bnez      $v0, .L8006DD28
/* 49110 8006DD10 24C6FFFF */   addiu    $a2, $a2, -1
/* 49114 8006DD14 0067102B */  sltu      $v0, $v1, $a3
/* 49118 8006DD18 10400004 */  beqz      $v0, .L8006DD2C
/* 4911C 8006DD1C 000A1400 */   sll      $v0, $t2, 0x10
/* 49120 8006DD20 24C6FFFF */  addiu     $a2, $a2, -1
/* 49124 8006DD24 00681821 */  addu      $v1, $v1, $t0
.L8006DD28:
/* 49128 8006DD28 000A1400 */  sll       $v0, $t2, 0x10
.L8006DD2C:
/* 4912C 8006DD2C 00463025 */  or        $a2, $v0, $a2
/* 49130 8006DD30 00672023 */  subu      $a0, $v1, $a3
/* 49134 8006DD34 00C90019 */  multu     $a2, $t1
/* 49138 8006DD38 00001810 */  mfhi      $v1
/* 4913C 8006DD3C 0083102B */  sltu      $v0, $a0, $v1
/* 49140 8006DD40 00004012 */  mflo      $t0
/* 49144 8006DD44 54400007 */  bnel      $v0, $zero, .L8006DD64
/* 49148 8006DD48 24C6FFFF */   addiu    $a2, $a2, -1
/* 4914C 8006DD4C 14640006 */  bne       $v1, $a0, .L8006DD68
/* 49150 8006DD50 0000502D */   daddu    $t2, $zero, $zero
/* 49154 8006DD54 0168102B */  sltu      $v0, $t3, $t0
/* 49158 8006DD58 10400004 */  beqz      $v0, .L8006DD6C
/* 4915C 8006DD5C 00C0782D */   daddu    $t7, $a2, $zero
/* 49160 8006DD60 24C6FFFF */  addiu     $a2, $a2, -1
.L8006DD64:
/* 49164 8006DD64 0000502D */  daddu     $t2, $zero, $zero
.L8006DD68:
/* 49168 8006DD68 00C0782D */  daddu     $t7, $a2, $zero
.L8006DD6C:
/* 4916C 8006DD6C 0140702D */  daddu     $t6, $t2, $zero
/* 49170 8006DD70 01C0102D */  daddu     $v0, $t6, $zero
/* 49174 8006DD74 13000007 */  beqz      $t8, .L8006DD94
/* 49178 8006DD78 01E0182D */   daddu    $v1, $t7, $zero
/* 4917C 8006DD7C 00036823 */  negu      $t5, $v1
/* 49180 8006DD80 00021823 */  negu      $v1, $v0
/* 49184 8006DD84 000D102B */  sltu      $v0, $zero, $t5
/* 49188 8006DD88 00626023 */  subu      $t4, $v1, $v0
/* 4918C 8006DD8C 0180102D */  daddu     $v0, $t4, $zero
/* 49190 8006DD90 01A0182D */  daddu     $v1, $t5, $zero
.L8006DD94:
/* 49194 8006DD94 03E00008 */  jr        $ra
/* 49198 8006DD98 00000000 */   nop
/* 4919C 8006DD9C 00000000 */  nop
