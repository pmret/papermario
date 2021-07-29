.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006E850
/* 49C50 8006E850 27BDFFF8 */  addiu     $sp, $sp, -8
/* 49C54 8006E854 00E0402D */  daddu     $t0, $a3, $zero
/* 49C58 8006E858 00C0482D */  daddu     $t1, $a2, $zero
/* 49C5C 8006E85C 00A0582D */  daddu     $t3, $a1, $zero
/* 49C60 8006E860 0080502D */  daddu     $t2, $a0, $zero
/* 49C64 8006E864 152000A6 */  bnez      $t1, .L8006EB00
/* 49C68 8006E868 03A0C82D */   daddu    $t9, $sp, $zero
/* 49C6C 8006E86C 0148102B */  sltu      $v0, $t2, $t0
/* 49C70 8006E870 1040001D */  beqz      $v0, .L8006E8E8
/* 49C74 8006E874 3402FFFF */   ori      $v0, $zero, 0xffff
/* 49C78 8006E878 0048102B */  sltu      $v0, $v0, $t0
/* 49C7C 8006E87C 14400005 */  bnez      $v0, .L8006E894
/* 49C80 8006E880 00E0302D */   daddu    $a2, $a3, $zero
/* 49C84 8006E884 2D020100 */  sltiu     $v0, $t0, 0x100
/* 49C88 8006E888 38420001 */  xori      $v0, $v0, 1
/* 49C8C 8006E88C 0801BA2B */  j         .L8006E8AC
/* 49C90 8006E890 000218C0 */   sll      $v1, $v0, 3
.L8006E894:
/* 49C94 8006E894 3C0200FF */  lui       $v0, 0xff
/* 49C98 8006E898 3442FFFF */  ori       $v0, $v0, 0xffff
/* 49C9C 8006E89C 0048102B */  sltu      $v0, $v0, $t0
/* 49CA0 8006E8A0 14400002 */  bnez      $v0, .L8006E8AC
/* 49CA4 8006E8A4 24030018 */   addiu    $v1, $zero, 0x18
/* 49CA8 8006E8A8 24030010 */  addiu     $v1, $zero, 0x10
.L8006E8AC:
/* 49CAC 8006E8AC 00661006 */  srlv      $v0, $a2, $v1
/* 49CB0 8006E8B0 3C01800A */  lui       $at, %hi(D_8009A120)
/* 49CB4 8006E8B4 00220821 */  addu      $at, $at, $v0
/* 49CB8 8006E8B8 9022A120 */  lbu       $v0, %lo(D_8009A120)($at)
/* 49CBC 8006E8BC 24040020 */  addiu     $a0, $zero, 0x20
/* 49CC0 8006E8C0 00431021 */  addu      $v0, $v0, $v1
/* 49CC4 8006E8C4 00826823 */  subu      $t5, $a0, $v0
/* 49CC8 8006E8C8 11A0005B */  beqz      $t5, .L8006EA38
/* 49CCC 8006E8CC 01AA1804 */   sllv     $v1, $t2, $t5
/* 49CD0 8006E8D0 01A84004 */  sllv      $t0, $t0, $t5
/* 49CD4 8006E8D4 008D1023 */  subu      $v0, $a0, $t5
/* 49CD8 8006E8D8 004B1006 */  srlv      $v0, $t3, $v0
/* 49CDC 8006E8DC 00625025 */  or        $t2, $v1, $v0
/* 49CE0 8006E8E0 0801BA8E */  j         .L8006EA38
/* 49CE4 8006E8E4 01AB5804 */   sllv     $t3, $t3, $t5
.L8006E8E8:
/* 49CE8 8006E8E8 15000008 */  bnez      $t0, .L8006E90C
/* 49CEC 8006E8EC 0048102B */   sltu     $v0, $v0, $t0
/* 49CF0 8006E8F0 24020001 */  addiu     $v0, $zero, 1
/* 49CF4 8006E8F4 15200002 */  bnez      $t1, .L8006E900
/* 49CF8 8006E8F8 0049001B */   divu     $zero, $v0, $t1
/* 49CFC 8006E8FC 0007000D */  break     7
.L8006E900:
/* 49D00 8006E900 00004012 */   mflo     $t0
/* 49D04 8006E904 3402FFFF */  ori       $v0, $zero, 0xffff
/* 49D08 8006E908 0048102B */  sltu      $v0, $v0, $t0
.L8006E90C:
/* 49D0C 8006E90C 14400005 */  bnez      $v0, .L8006E924
/* 49D10 8006E910 0100202D */   daddu    $a0, $t0, $zero
/* 49D14 8006E914 2D020100 */  sltiu     $v0, $t0, 0x100
/* 49D18 8006E918 38420001 */  xori      $v0, $v0, 1
/* 49D1C 8006E91C 0801BA4F */  j         .L8006E93C
/* 49D20 8006E920 000218C0 */   sll      $v1, $v0, 3
.L8006E924:
/* 49D24 8006E924 3C0200FF */  lui       $v0, 0xff
/* 49D28 8006E928 3442FFFF */  ori       $v0, $v0, 0xffff
/* 49D2C 8006E92C 0048102B */  sltu      $v0, $v0, $t0
/* 49D30 8006E930 14400002 */  bnez      $v0, .L8006E93C
/* 49D34 8006E934 24030018 */   addiu    $v1, $zero, 0x18
/* 49D38 8006E938 24030010 */  addiu     $v1, $zero, 0x10
.L8006E93C:
/* 49D3C 8006E93C 00641006 */  srlv      $v0, $a0, $v1
/* 49D40 8006E940 3C01800A */  lui       $at, %hi(D_8009A120)
/* 49D44 8006E944 00220821 */  addu      $at, $at, $v0
/* 49D48 8006E948 9022A120 */  lbu       $v0, %lo(D_8009A120)($at)
/* 49D4C 8006E94C 00431021 */  addu      $v0, $v0, $v1
/* 49D50 8006E950 24030020 */  addiu     $v1, $zero, 0x20
/* 49D54 8006E954 00626823 */  subu      $t5, $v1, $v0
/* 49D58 8006E958 15A00003 */  bnez      $t5, .L8006E968
/* 49D5C 8006E95C 006DC023 */   subu     $t8, $v1, $t5
/* 49D60 8006E960 0801BA8E */  j         .L8006EA38
/* 49D64 8006E964 01485023 */   subu     $t2, $t2, $t0
.L8006E968:
/* 49D68 8006E968 01A84004 */  sllv      $t0, $t0, $t5
/* 49D6C 8006E96C 030A2006 */  srlv      $a0, $t2, $t8
/* 49D70 8006E970 01AA1804 */  sllv      $v1, $t2, $t5
/* 49D74 8006E974 030B1006 */  srlv      $v0, $t3, $t8
/* 49D78 8006E978 00625025 */  or        $t2, $v1, $v0
/* 49D7C 8006E97C 00082C02 */  srl       $a1, $t0, 0x10
/* 49D80 8006E980 14A00002 */  bnez      $a1, .L8006E98C
/* 49D84 8006E984 0085001B */   divu     $zero, $a0, $a1
/* 49D88 8006E988 0007000D */  break     7
.L8006E98C:
/* 49D8C 8006E98C 00001012 */   mflo     $v0
/* 49D90 8006E990 00001810 */  mfhi      $v1
/* 49D94 8006E994 3106FFFF */  andi      $a2, $t0, 0xffff
/* 49D98 8006E998 00000000 */  nop
/* 49D9C 8006E99C 00460018 */  mult      $v0, $a2
/* 49DA0 8006E9A0 00031C00 */  sll       $v1, $v1, 0x10
/* 49DA4 8006E9A4 000A1402 */  srl       $v0, $t2, 0x10
/* 49DA8 8006E9A8 00621825 */  or        $v1, $v1, $v0
/* 49DAC 8006E9AC 00002012 */  mflo      $a0
/* 49DB0 8006E9B0 0064102B */  sltu      $v0, $v1, $a0
/* 49DB4 8006E9B4 10400008 */  beqz      $v0, .L8006E9D8
/* 49DB8 8006E9B8 01AB5804 */   sllv     $t3, $t3, $t5
/* 49DBC 8006E9BC 00681821 */  addu      $v1, $v1, $t0
/* 49DC0 8006E9C0 0068102B */  sltu      $v0, $v1, $t0
/* 49DC4 8006E9C4 54400005 */  bnel      $v0, $zero, .L8006E9DC
/* 49DC8 8006E9C8 00641823 */   subu     $v1, $v1, $a0
/* 49DCC 8006E9CC 0064102B */  sltu      $v0, $v1, $a0
/* 49DD0 8006E9D0 54400001 */  bnel      $v0, $zero, .L8006E9D8
/* 49DD4 8006E9D4 00681821 */   addu     $v1, $v1, $t0
.L8006E9D8:
/* 49DD8 8006E9D8 00641823 */  subu      $v1, $v1, $a0
.L8006E9DC:
/* 49DDC 8006E9DC 14A00002 */  bnez      $a1, .L8006E9E8
/* 49DE0 8006E9E0 0065001B */   divu     $zero, $v1, $a1
/* 49DE4 8006E9E4 0007000D */  break     7
.L8006E9E8:
/* 49DE8 8006E9E8 00001012 */   mflo     $v0
/* 49DEC 8006E9EC 00001810 */  mfhi      $v1
/* 49DF0 8006E9F0 00000000 */  nop
/* 49DF4 8006E9F4 00000000 */  nop
/* 49DF8 8006E9F8 00460018 */  mult      $v0, $a2
/* 49DFC 8006E9FC 00031C00 */  sll       $v1, $v1, 0x10
/* 49E00 8006EA00 3142FFFF */  andi      $v0, $t2, 0xffff
/* 49E04 8006EA04 00621825 */  or        $v1, $v1, $v0
/* 49E08 8006EA08 00002012 */  mflo      $a0
/* 49E0C 8006EA0C 0064102B */  sltu      $v0, $v1, $a0
/* 49E10 8006EA10 50400009 */  beql      $v0, $zero, .L8006EA38
/* 49E14 8006EA14 00645023 */   subu     $t2, $v1, $a0
/* 49E18 8006EA18 00681821 */  addu      $v1, $v1, $t0
/* 49E1C 8006EA1C 0068102B */  sltu      $v0, $v1, $t0
/* 49E20 8006EA20 14400005 */  bnez      $v0, .L8006EA38
/* 49E24 8006EA24 00645023 */   subu     $t2, $v1, $a0
/* 49E28 8006EA28 0064102B */  sltu      $v0, $v1, $a0
/* 49E2C 8006EA2C 54400001 */  bnel      $v0, $zero, .L8006EA34
/* 49E30 8006EA30 00681821 */   addu     $v1, $v1, $t0
.L8006EA34:
/* 49E34 8006EA34 00645023 */  subu      $t2, $v1, $a0
.L8006EA38:
/* 49E38 8006EA38 00082C02 */  srl       $a1, $t0, 0x10
/* 49E3C 8006EA3C 14A00002 */  bnez      $a1, .L8006EA48
/* 49E40 8006EA40 0145001B */   divu     $zero, $t2, $a1
/* 49E44 8006EA44 0007000D */  break     7
.L8006EA48:
/* 49E48 8006EA48 00001012 */   mflo     $v0
/* 49E4C 8006EA4C 00001810 */  mfhi      $v1
/* 49E50 8006EA50 3106FFFF */  andi      $a2, $t0, 0xffff
/* 49E54 8006EA54 00000000 */  nop
/* 49E58 8006EA58 00460018 */  mult      $v0, $a2
/* 49E5C 8006EA5C 00031C00 */  sll       $v1, $v1, 0x10
/* 49E60 8006EA60 000B1402 */  srl       $v0, $t3, 0x10
/* 49E64 8006EA64 00621825 */  or        $v1, $v1, $v0
/* 49E68 8006EA68 00002012 */  mflo      $a0
/* 49E6C 8006EA6C 0064102B */  sltu      $v0, $v1, $a0
/* 49E70 8006EA70 50400009 */  beql      $v0, $zero, .L8006EA98
/* 49E74 8006EA74 00641823 */   subu     $v1, $v1, $a0
/* 49E78 8006EA78 00681821 */  addu      $v1, $v1, $t0
/* 49E7C 8006EA7C 0068102B */  sltu      $v0, $v1, $t0
/* 49E80 8006EA80 54400005 */  bnel      $v0, $zero, .L8006EA98
/* 49E84 8006EA84 00641823 */   subu     $v1, $v1, $a0
/* 49E88 8006EA88 0064102B */  sltu      $v0, $v1, $a0
/* 49E8C 8006EA8C 54400001 */  bnel      $v0, $zero, .L8006EA94
/* 49E90 8006EA90 00681821 */   addu     $v1, $v1, $t0
.L8006EA94:
/* 49E94 8006EA94 00641823 */  subu      $v1, $v1, $a0
.L8006EA98:
/* 49E98 8006EA98 14A00002 */  bnez      $a1, .L8006EAA4
/* 49E9C 8006EA9C 0065001B */   divu     $zero, $v1, $a1
/* 49EA0 8006EAA0 0007000D */  break     7
.L8006EAA4:
/* 49EA4 8006EAA4 00001012 */   mflo     $v0
/* 49EA8 8006EAA8 00001810 */  mfhi      $v1
/* 49EAC 8006EAAC 00000000 */  nop
/* 49EB0 8006EAB0 00000000 */  nop
/* 49EB4 8006EAB4 00460018 */  mult      $v0, $a2
/* 49EB8 8006EAB8 00031C00 */  sll       $v1, $v1, 0x10
/* 49EBC 8006EABC 3162FFFF */  andi      $v0, $t3, 0xffff
/* 49EC0 8006EAC0 00621825 */  or        $v1, $v1, $v0
/* 49EC4 8006EAC4 00002012 */  mflo      $a0
/* 49EC8 8006EAC8 0064102B */  sltu      $v0, $v1, $a0
/* 49ECC 8006EACC 10400007 */  beqz      $v0, .L8006EAEC
/* 49ED0 8006EAD0 00000000 */   nop
/* 49ED4 8006EAD4 00681821 */  addu      $v1, $v1, $t0
/* 49ED8 8006EAD8 0068102B */  sltu      $v0, $v1, $t0
/* 49EDC 8006EADC 14400003 */  bnez      $v0, .L8006EAEC
/* 49EE0 8006EAE0 0064102B */   sltu     $v0, $v1, $a0
/* 49EE4 8006EAE4 54400001 */  bnel      $v0, $zero, .L8006EAEC
/* 49EE8 8006EAE8 00681821 */   addu     $v1, $v1, $t0
.L8006EAEC:
/* 49EEC 8006EAEC 13200087 */  beqz      $t9, .L8006ED0C
/* 49EF0 8006EAF0 00645823 */   subu     $t3, $v1, $a0
/* 49EF4 8006EAF4 01AB7806 */  srlv      $t7, $t3, $t5
/* 49EF8 8006EAF8 0801BB41 */  j         .L8006ED04
/* 49EFC 8006EAFC 0000702D */   daddu    $t6, $zero, $zero
.L8006EB00:
/* 49F00 8006EB00 0149102B */  sltu      $v0, $t2, $t1
/* 49F04 8006EB04 10400007 */  beqz      $v0, .L8006EB24
/* 49F08 8006EB08 3402FFFF */   ori      $v0, $zero, 0xffff
/* 49F0C 8006EB0C 00A0782D */  daddu     $t7, $a1, $zero
/* 49F10 8006EB10 0140702D */  daddu     $t6, $t2, $zero
/* 49F14 8006EB14 AFAE0000 */  sw        $t6, ($sp)
/* 49F18 8006EB18 AFAF0004 */  sw        $t7, 4($sp)
/* 49F1C 8006EB1C 0801BB43 */  j         .L8006ED0C
/* 49F20 8006EB20 00000000 */   nop
.L8006EB24:
/* 49F24 8006EB24 0049102B */  sltu      $v0, $v0, $t1
/* 49F28 8006EB28 14400005 */  bnez      $v0, .L8006EB40
/* 49F2C 8006EB2C 0120202D */   daddu    $a0, $t1, $zero
/* 49F30 8006EB30 2D220100 */  sltiu     $v0, $t1, 0x100
/* 49F34 8006EB34 38420001 */  xori      $v0, $v0, 1
/* 49F38 8006EB38 0801BAD6 */  j         .L8006EB58
/* 49F3C 8006EB3C 000218C0 */   sll      $v1, $v0, 3
.L8006EB40:
/* 49F40 8006EB40 3C0200FF */  lui       $v0, 0xff
/* 49F44 8006EB44 3442FFFF */  ori       $v0, $v0, 0xffff
/* 49F48 8006EB48 0049102B */  sltu      $v0, $v0, $t1
/* 49F4C 8006EB4C 14400002 */  bnez      $v0, .L8006EB58
/* 49F50 8006EB50 24030018 */   addiu    $v1, $zero, 0x18
/* 49F54 8006EB54 24030010 */  addiu     $v1, $zero, 0x10
.L8006EB58:
/* 49F58 8006EB58 00641006 */  srlv      $v0, $a0, $v1
/* 49F5C 8006EB5C 3C01800A */  lui       $at, %hi(D_8009A120)
/* 49F60 8006EB60 00220821 */  addu      $at, $at, $v0
/* 49F64 8006EB64 9022A120 */  lbu       $v0, %lo(D_8009A120)($at)
/* 49F68 8006EB68 00431021 */  addu      $v0, $v0, $v1
/* 49F6C 8006EB6C 24030020 */  addiu     $v1, $zero, 0x20
/* 49F70 8006EB70 00626823 */  subu      $t5, $v1, $v0
/* 49F74 8006EB74 15A0000F */  bnez      $t5, .L8006EBB4
/* 49F78 8006EB78 006DC023 */   subu     $t8, $v1, $t5
/* 49F7C 8006EB7C 012A102B */  sltu      $v0, $t1, $t2
/* 49F80 8006EB80 14400004 */  bnez      $v0, .L8006EB94
/* 49F84 8006EB84 01682023 */   subu     $a0, $t3, $t0
/* 49F88 8006EB88 0168102B */  sltu      $v0, $t3, $t0
/* 49F8C 8006EB8C 14400005 */  bnez      $v0, .L8006EBA4
/* 49F90 8006EB90 00000000 */   nop
.L8006EB94:
/* 49F94 8006EB94 01491823 */  subu      $v1, $t2, $t1
/* 49F98 8006EB98 0164102B */  sltu      $v0, $t3, $a0
/* 49F9C 8006EB9C 00625023 */  subu      $t2, $v1, $v0
/* 49FA0 8006EBA0 0080582D */  daddu     $t3, $a0, $zero
.L8006EBA4:
/* 49FA4 8006EBA4 13200059 */  beqz      $t9, .L8006ED0C
/* 49FA8 8006EBA8 0160782D */   daddu    $t7, $t3, $zero
/* 49FAC 8006EBAC 0801BB41 */  j         .L8006ED04
/* 49FB0 8006EBB0 0140702D */   daddu    $t6, $t2, $zero
.L8006EBB4:
/* 49FB4 8006EBB4 01A91804 */  sllv      $v1, $t1, $t5
/* 49FB8 8006EBB8 03081006 */  srlv      $v0, $t0, $t8
/* 49FBC 8006EBBC 00624825 */  or        $t1, $v1, $v0
/* 49FC0 8006EBC0 01A84004 */  sllv      $t0, $t0, $t5
/* 49FC4 8006EBC4 030A2006 */  srlv      $a0, $t2, $t8
/* 49FC8 8006EBC8 01AA1804 */  sllv      $v1, $t2, $t5
/* 49FCC 8006EBCC 030B1006 */  srlv      $v0, $t3, $t8
/* 49FD0 8006EBD0 00625025 */  or        $t2, $v1, $v0
/* 49FD4 8006EBD4 00093402 */  srl       $a2, $t1, 0x10
/* 49FD8 8006EBD8 14C00002 */  bnez      $a2, .L8006EBE4
/* 49FDC 8006EBDC 0086001B */   divu     $zero, $a0, $a2
/* 49FE0 8006EBE0 0007000D */  break     7
.L8006EBE4:
/* 49FE4 8006EBE4 00003812 */   mflo     $a3
/* 49FE8 8006EBE8 00001810 */  mfhi      $v1
/* 49FEC 8006EBEC 312CFFFF */  andi      $t4, $t1, 0xffff
/* 49FF0 8006EBF0 00000000 */  nop
/* 49FF4 8006EBF4 00EC0018 */  mult      $a3, $t4
/* 49FF8 8006EBF8 000A1402 */  srl       $v0, $t2, 0x10
/* 49FFC 8006EBFC 00031C00 */  sll       $v1, $v1, 0x10
/* 4A000 8006EC00 00621825 */  or        $v1, $v1, $v0
/* 4A004 8006EC04 00002812 */  mflo      $a1
/* 4A008 8006EC08 0065102B */  sltu      $v0, $v1, $a1
/* 4A00C 8006EC0C 1040000A */  beqz      $v0, .L8006EC38
/* 4A010 8006EC10 01AB5804 */   sllv     $t3, $t3, $t5
/* 4A014 8006EC14 00691821 */  addu      $v1, $v1, $t1
/* 4A018 8006EC18 0069102B */  sltu      $v0, $v1, $t1
/* 4A01C 8006EC1C 14400006 */  bnez      $v0, .L8006EC38
/* 4A020 8006EC20 24E7FFFF */   addiu    $a3, $a3, -1
/* 4A024 8006EC24 0065102B */  sltu      $v0, $v1, $a1
/* 4A028 8006EC28 50400004 */  beql      $v0, $zero, .L8006EC3C
/* 4A02C 8006EC2C 00651823 */   subu     $v1, $v1, $a1
/* 4A030 8006EC30 24E7FFFF */  addiu     $a3, $a3, -1
/* 4A034 8006EC34 00691821 */  addu      $v1, $v1, $t1
.L8006EC38:
/* 4A038 8006EC38 00651823 */  subu      $v1, $v1, $a1
.L8006EC3C:
/* 4A03C 8006EC3C 14C00002 */  bnez      $a2, .L8006EC48
/* 4A040 8006EC40 0066001B */   divu     $zero, $v1, $a2
/* 4A044 8006EC44 0007000D */  break     7
.L8006EC48:
/* 4A048 8006EC48 00002012 */   mflo     $a0
/* 4A04C 8006EC4C 00001810 */  mfhi      $v1
/* 4A050 8006EC50 00000000 */  nop
/* 4A054 8006EC54 00000000 */  nop
/* 4A058 8006EC58 008C0018 */  mult      $a0, $t4
/* 4A05C 8006EC5C 3142FFFF */  andi      $v0, $t2, 0xffff
/* 4A060 8006EC60 00031C00 */  sll       $v1, $v1, 0x10
/* 4A064 8006EC64 00621825 */  or        $v1, $v1, $v0
/* 4A068 8006EC68 00002812 */  mflo      $a1
/* 4A06C 8006EC6C 0065102B */  sltu      $v0, $v1, $a1
/* 4A070 8006EC70 5040000B */  beql      $v0, $zero, .L8006ECA0
/* 4A074 8006EC74 00655023 */   subu     $t2, $v1, $a1
/* 4A078 8006EC78 00691821 */  addu      $v1, $v1, $t1
/* 4A07C 8006EC7C 0069102B */  sltu      $v0, $v1, $t1
/* 4A080 8006EC80 14400006 */  bnez      $v0, .L8006EC9C
/* 4A084 8006EC84 2484FFFF */   addiu    $a0, $a0, -1
/* 4A088 8006EC88 0065102B */  sltu      $v0, $v1, $a1
/* 4A08C 8006EC8C 10400004 */  beqz      $v0, .L8006ECA0
/* 4A090 8006EC90 00655023 */   subu     $t2, $v1, $a1
/* 4A094 8006EC94 2484FFFF */  addiu     $a0, $a0, -1
/* 4A098 8006EC98 00691821 */  addu      $v1, $v1, $t1
.L8006EC9C:
/* 4A09C 8006EC9C 00655023 */  subu      $t2, $v1, $a1
.L8006ECA0:
/* 4A0A0 8006ECA0 00071400 */  sll       $v0, $a3, 0x10
/* 4A0A4 8006ECA4 00441025 */  or        $v0, $v0, $a0
/* 4A0A8 8006ECA8 00480019 */  multu     $v0, $t0
/* 4A0AC 8006ECAC 00003010 */  mfhi      $a2
/* 4A0B0 8006ECB0 0146102B */  sltu      $v0, $t2, $a2
/* 4A0B4 8006ECB4 00002812 */  mflo      $a1
/* 4A0B8 8006ECB8 54400005 */  bnel      $v0, $zero, .L8006ECD0
/* 4A0BC 8006ECBC 00A82023 */   subu     $a0, $a1, $t0
/* 4A0C0 8006ECC0 14CA0007 */  bne       $a2, $t2, .L8006ECE0
/* 4A0C4 8006ECC4 0165102B */   sltu     $v0, $t3, $a1
/* 4A0C8 8006ECC8 10400005 */  beqz      $v0, .L8006ECE0
/* 4A0CC 8006ECCC 00A82023 */   subu     $a0, $a1, $t0
.L8006ECD0:
/* 4A0D0 8006ECD0 00C91823 */  subu      $v1, $a2, $t1
/* 4A0D4 8006ECD4 00A4102B */  sltu      $v0, $a1, $a0
/* 4A0D8 8006ECD8 00623023 */  subu      $a2, $v1, $v0
/* 4A0DC 8006ECDC 0080282D */  daddu     $a1, $a0, $zero
.L8006ECE0:
/* 4A0E0 8006ECE0 1320000A */  beqz      $t9, .L8006ED0C
/* 4A0E4 8006ECE4 01651823 */   subu     $v1, $t3, $a1
/* 4A0E8 8006ECE8 01462023 */  subu      $a0, $t2, $a2
/* 4A0EC 8006ECEC 0163102B */  sltu      $v0, $t3, $v1
/* 4A0F0 8006ECF0 00825023 */  subu      $t2, $a0, $v0
/* 4A0F4 8006ECF4 030A1004 */  sllv      $v0, $t2, $t8
/* 4A0F8 8006ECF8 01A31806 */  srlv      $v1, $v1, $t5
/* 4A0FC 8006ECFC 00437825 */  or        $t7, $v0, $v1
/* 4A100 8006ED00 01AA7006 */  srlv      $t6, $t2, $t5
.L8006ED04:
/* 4A104 8006ED04 AF2E0000 */  sw        $t6, ($t9)
/* 4A108 8006ED08 AF2F0004 */  sw        $t7, 4($t9)
.L8006ED0C:
/* 4A10C 8006ED0C 8FA20000 */  lw        $v0, ($sp)
/* 4A110 8006ED10 8FA30004 */  lw        $v1, 4($sp)
/* 4A114 8006ED14 03E00008 */  jr        $ra
/* 4A118 8006ED18 27BD0008 */   addiu    $sp, $sp, 8
/* 4A11C 8006ED1C 00000000 */  nop
