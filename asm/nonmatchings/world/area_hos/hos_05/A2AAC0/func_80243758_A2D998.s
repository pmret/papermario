.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243758_A2D998
/* A2D998 80243758 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2D99C 8024375C 0080C82D */  daddu     $t9, $a0, $zero
/* A2D9A0 80243760 AFB40010 */  sw        $s4, 0x10($sp)
/* A2D9A4 80243764 00A0A02D */  daddu     $s4, $a1, $zero
/* A2D9A8 80243768 AFB00000 */  sw        $s0, ($sp)
/* A2D9AC 8024376C 00C0802D */  daddu     $s0, $a2, $zero
/* A2D9B0 80243770 AFB50014 */  sw        $s5, 0x14($sp)
/* A2D9B4 80243774 24150001 */  addiu     $s5, $zero, 1
/* A2D9B8 80243778 3C05F500 */  lui       $a1, 0xf500
/* A2D9BC 8024377C 34A50100 */  ori       $a1, $a1, 0x100
/* A2D9C0 80243780 3C06073F */  lui       $a2, 0x73f
/* A2D9C4 80243784 34C6C000 */  ori       $a2, $a2, 0xc000
/* A2D9C8 80243788 0000502D */  daddu     $t2, $zero, $zero
/* A2D9CC 8024378C 3C02800A */  lui       $v0, 0x800a
/* A2D9D0 80243790 2442A66C */  addiu     $v0, $v0, -0x5994
/* A2D9D4 80243794 0040402D */  daddu     $t0, $v0, $zero
/* A2D9D8 80243798 3C0FF548 */  lui       $t7, 0xf548
/* A2D9DC 8024379C 35EF4200 */  ori       $t7, $t7, 0x4200
/* A2D9E0 802437A0 27220108 */  addiu     $v0, $t9, 0x108
/* A2D9E4 802437A4 00021480 */  sll       $v0, $v0, 0x12
/* A2D9E8 802437A8 0002C403 */  sra       $t8, $v0, 0x10
/* A2D9EC 802437AC 33020FFF */  andi      $v0, $t8, 0xfff
/* A2D9F0 802437B0 AFB3000C */  sw        $s3, 0xc($sp)
/* A2D9F4 802437B4 00029B00 */  sll       $s3, $v0, 0xc
/* A2D9F8 802437B8 00191480 */  sll       $v0, $t9, 0x12
/* A2D9FC 802437BC 00027403 */  sra       $t6, $v0, 0x10
/* A2DA00 802437C0 AFB20008 */  sw        $s2, 8($sp)
/* A2DA04 802437C4 31D20FFF */  andi      $s2, $t6, 0xfff
/* A2DA08 802437C8 AFB10004 */  sw        $s1, 4($sp)
/* A2DA0C 802437CC 000E8A80 */  sll       $s1, $t6, 0xa
/* A2DA10 802437D0 0280482D */  daddu     $t1, $s4, $zero
/* A2DA14 802437D4 0140682D */  daddu     $t5, $t2, $zero
/* A2DA18 802437D8 240C0018 */  addiu     $t4, $zero, 0x18
/* A2DA1C 802437DC 0140582D */  daddu     $t3, $t2, $zero
/* A2DA20 802437E0 8D020000 */  lw        $v0, ($t0)
/* A2DA24 802437E4 3C04E700 */  lui       $a0, 0xe700
/* A2DA28 802437E8 0040182D */  daddu     $v1, $v0, $zero
/* A2DA2C 802437EC 24420008 */  addiu     $v0, $v0, 8
/* A2DA30 802437F0 AD020000 */  sw        $v0, ($t0)
/* A2DA34 802437F4 AC640000 */  sw        $a0, ($v1)
/* A2DA38 802437F8 AC600004 */  sw        $zero, 4($v1)
/* A2DA3C 802437FC 24430008 */  addiu     $v1, $v0, 8
/* A2DA40 80243800 AD030000 */  sw        $v1, ($t0)
/* A2DA44 80243804 3C03FD10 */  lui       $v1, 0xfd10
/* A2DA48 80243808 AC430000 */  sw        $v1, ($v0)
/* A2DA4C 8024380C 24430010 */  addiu     $v1, $v0, 0x10
/* A2DA50 80243810 AC470004 */  sw        $a3, 4($v0)
/* A2DA54 80243814 AD030000 */  sw        $v1, ($t0)
/* A2DA58 80243818 3C03E800 */  lui       $v1, 0xe800
/* A2DA5C 8024381C AC430008 */  sw        $v1, 8($v0)
/* A2DA60 80243820 004C1821 */  addu      $v1, $v0, $t4
/* A2DA64 80243824 AC40000C */  sw        $zero, 0xc($v0)
/* A2DA68 80243828 AD030000 */  sw        $v1, ($t0)
/* A2DA6C 8024382C 3C030700 */  lui       $v1, 0x700
/* A2DA70 80243830 AC430014 */  sw        $v1, 0x14($v0)
/* A2DA74 80243834 24430020 */  addiu     $v1, $v0, 0x20
/* A2DA78 80243838 AC450010 */  sw        $a1, 0x10($v0)
/* A2DA7C 8024383C AD030000 */  sw        $v1, ($t0)
/* A2DA80 80243840 3C03E600 */  lui       $v1, 0xe600
/* A2DA84 80243844 AC430018 */  sw        $v1, 0x18($v0)
/* A2DA88 80243848 24430028 */  addiu     $v1, $v0, 0x28
/* A2DA8C 8024384C AC40001C */  sw        $zero, 0x1c($v0)
/* A2DA90 80243850 AD030000 */  sw        $v1, ($t0)
/* A2DA94 80243854 3C03F000 */  lui       $v1, 0xf000
/* A2DA98 80243858 AC430020 */  sw        $v1, 0x20($v0)
/* A2DA9C 8024385C 24430030 */  addiu     $v1, $v0, 0x30
/* A2DAA0 80243860 AC460024 */  sw        $a2, 0x24($v0)
/* A2DAA4 80243864 AD030000 */  sw        $v1, ($t0)
/* A2DAA8 80243868 AC440028 */  sw        $a0, 0x28($v0)
/* A2DAAC 8024386C AC40002C */  sw        $zero, 0x2c($v0)
.L80243870:
/* A2DAB0 80243870 3C04FD48 */  lui       $a0, 0xfd48
/* A2DAB4 80243874 34840107 */  ori       $a0, $a0, 0x107
/* A2DAB8 80243878 3C060741 */  lui       $a2, 0x741
/* A2DABC 8024387C 34C6C000 */  ori       $a2, $a2, 0xc000
/* A2DAC0 80243880 3C070041 */  lui       $a3, 0x41
/* A2DAC4 80243884 34E7C000 */  ori       $a3, $a3, 0xc000
/* A2DAC8 80243888 8D030000 */  lw        $v1, ($t0)
/* A2DACC 8024388C 31650FFF */  andi      $a1, $t3, 0xfff
/* A2DAD0 80243890 0060102D */  daddu     $v0, $v1, $zero
/* A2DAD4 80243894 24630008 */  addiu     $v1, $v1, 8
/* A2DAD8 80243898 AD030000 */  sw        $v1, ($t0)
/* A2DADC 8024389C AC440000 */  sw        $a0, ($v0)
/* A2DAE0 802438A0 AC500004 */  sw        $s0, 4($v0)
/* A2DAE4 802438A4 24620008 */  addiu     $v0, $v1, 8
/* A2DAE8 802438A8 AD020000 */  sw        $v0, ($t0)
/* A2DAEC 802438AC 3C020700 */  lui       $v0, 0x700
/* A2DAF0 802438B0 AC620004 */  sw        $v0, 4($v1)
/* A2DAF4 802438B4 24620010 */  addiu     $v0, $v1, 0x10
/* A2DAF8 802438B8 AC6F0000 */  sw        $t7, ($v1)
/* A2DAFC 802438BC AD020000 */  sw        $v0, ($t0)
/* A2DB00 802438C0 3C02E600 */  lui       $v0, 0xe600
/* A2DB04 802438C4 AC620008 */  sw        $v0, 8($v1)
/* A2DB08 802438C8 24620018 */  addiu     $v0, $v1, 0x18
/* A2DB0C 802438CC AC60000C */  sw        $zero, 0xc($v1)
/* A2DB10 802438D0 AD020000 */  sw        $v0, ($t0)
/* A2DB14 802438D4 3C02F400 */  lui       $v0, 0xf400
/* A2DB18 802438D8 00A21025 */  or        $v0, $a1, $v0
/* A2DB1C 802438DC 31840FFF */  andi      $a0, $t4, 0xfff
/* A2DB20 802438E0 00863025 */  or        $a2, $a0, $a2
/* A2DB24 802438E4 AC620010 */  sw        $v0, 0x10($v1)
/* A2DB28 802438E8 24620020 */  addiu     $v0, $v1, 0x20
/* A2DB2C 802438EC AC660014 */  sw        $a2, 0x14($v1)
/* A2DB30 802438F0 AD020000 */  sw        $v0, ($t0)
/* A2DB34 802438F4 3C02E700 */  lui       $v0, 0xe700
/* A2DB38 802438F8 AC620018 */  sw        $v0, 0x18($v1)
/* A2DB3C 802438FC 24620028 */  addiu     $v0, $v1, 0x28
/* A2DB40 80243900 24660030 */  addiu     $a2, $v1, 0x30
/* A2DB44 80243904 AC60001C */  sw        $zero, 0x1c($v1)
/* A2DB48 80243908 AD020000 */  sw        $v0, ($t0)
/* A2DB4C 8024390C 3C02F200 */  lui       $v0, 0xf200
/* A2DB50 80243910 00A22825 */  or        $a1, $a1, $v0
/* A2DB54 80243914 00872025 */  or        $a0, $a0, $a3
/* A2DB58 80243918 AC6F0020 */  sw        $t7, 0x20($v1)
/* A2DB5C 8024391C AC600024 */  sw        $zero, 0x24($v1)
/* A2DB60 80243920 AD060000 */  sw        $a2, ($t0)
/* A2DB64 80243924 AC650028 */  sw        $a1, 0x28($v1)
/* A2DB68 80243928 AC64002C */  sw        $a0, 0x2c($v1)
/* A2DB6C 8024392C 24630038 */  addiu     $v1, $v1, 0x38
/* A2DB70 80243930 1B000004 */  blez      $t8, .L80243944
/* A2DB74 80243934 AD030000 */   sw       $v1, ($t0)
/* A2DB78 80243938 3C02E400 */  lui       $v0, 0xe400
/* A2DB7C 8024393C 08090E52 */  j         .L80243948
/* A2DB80 80243940 02621825 */   or       $v1, $s3, $v0
.L80243944:
/* A2DB84 80243944 3C03E400 */  lui       $v1, 0xe400
.L80243948:
/* A2DB88 80243948 25220007 */  addiu     $v0, $t1, 7
/* A2DB8C 8024394C 00021480 */  sll       $v0, $v0, 0x12
/* A2DB90 80243950 00021403 */  sra       $v0, $v0, 0x10
/* A2DB94 80243954 18400004 */  blez      $v0, .L80243968
/* A2DB98 80243958 ACC30000 */   sw       $v1, ($a2)
/* A2DB9C 8024395C 30420FFF */  andi      $v0, $v0, 0xfff
/* A2DBA0 80243960 00621025 */  or        $v0, $v1, $v0
/* A2DBA4 80243964 ACC20000 */  sw        $v0, ($a2)
.L80243968:
/* A2DBA8 80243968 19C00002 */  blez      $t6, .L80243974
/* A2DBAC 8024396C 0000182D */   daddu    $v1, $zero, $zero
/* A2DBB0 80243970 00121B00 */  sll       $v1, $s2, 0xc
.L80243974:
/* A2DBB4 80243974 00091480 */  sll       $v0, $t1, 0x12
/* A2DBB8 80243978 00021403 */  sra       $v0, $v0, 0x10
/* A2DBBC 8024397C 18400004 */  blez      $v0, .L80243990
/* A2DBC0 80243980 ACC30004 */   sw       $v1, 4($a2)
/* A2DBC4 80243984 30420FFF */  andi      $v0, $v0, 0xfff
/* A2DBC8 80243988 00621025 */  or        $v0, $v1, $v0
/* A2DBCC 8024398C ACC20004 */  sw        $v0, 4($a2)
.L80243990:
/* A2DBD0 80243990 8D020000 */  lw        $v0, ($t0)
/* A2DBD4 80243994 000D2940 */  sll       $a1, $t5, 5
/* A2DBD8 80243998 0040182D */  daddu     $v1, $v0, $zero
/* A2DBDC 8024399C 24420008 */  addiu     $v0, $v0, 8
/* A2DBE0 802439A0 AD020000 */  sw        $v0, ($t0)
/* A2DBE4 802439A4 3C02E100 */  lui       $v0, 0xe100
/* A2DBE8 802439A8 AC620000 */  sw        $v0, ($v1)
/* A2DBEC 802439AC 05C10007 */  bgez      $t6, .L802439CC
/* A2DBF0 802439B0 24630004 */   addiu    $v1, $v1, 4
/* A2DBF4 802439B4 001111C3 */  sra       $v0, $s1, 7
/* A2DBF8 802439B8 5C400001 */  bgtzl     $v0, .L802439C0
/* A2DBFC 802439BC 0000102D */   daddu    $v0, $zero, $zero
.L802439C0:
/* A2DC00 802439C0 00021023 */  negu      $v0, $v0
/* A2DC04 802439C4 08090E74 */  j         .L802439D0
/* A2DC08 802439C8 00022400 */   sll      $a0, $v0, 0x10
.L802439CC:
/* A2DC0C 802439CC 0000202D */  daddu     $a0, $zero, $zero
.L802439D0:
/* A2DC10 802439D0 00091080 */  sll       $v0, $t1, 2
/* A2DC14 802439D4 04410007 */  bgez      $v0, .L802439F4
/* A2DC18 802439D8 30A2FFFF */   andi     $v0, $a1, 0xffff
/* A2DC1C 802439DC 00091480 */  sll       $v0, $t1, 0x12
/* A2DC20 802439E0 00021343 */  sra       $v0, $v0, 0xd
/* A2DC24 802439E4 5C400001 */  bgtzl     $v0, .L802439EC
/* A2DC28 802439E8 0000102D */   daddu    $v0, $zero, $zero
.L802439EC:
/* A2DC2C 802439EC 00A21023 */  subu      $v0, $a1, $v0
/* A2DC30 802439F0 3042FFFF */  andi      $v0, $v0, 0xffff
.L802439F4:
/* A2DC34 802439F4 00821025 */  or        $v0, $a0, $v0
/* A2DC38 802439F8 AC620000 */  sw        $v0, ($v1)
/* A2DC3C 802439FC 3C040400 */  lui       $a0, 0x400
/* A2DC40 80243A00 34840400 */  ori       $a0, $a0, 0x400
/* A2DC44 80243A04 25290007 */  addiu     $t1, $t1, 7
/* A2DC48 80243A08 25AD0007 */  addiu     $t5, $t5, 7
/* A2DC4C 80243A0C 258C001C */  addiu     $t4, $t4, 0x1c
/* A2DC50 80243A10 256B001C */  addiu     $t3, $t3, 0x1c
/* A2DC54 80243A14 8D020000 */  lw        $v0, ($t0)
/* A2DC58 80243A18 254A0001 */  addiu     $t2, $t2, 1
/* A2DC5C 80243A1C 0040182D */  daddu     $v1, $v0, $zero
/* A2DC60 80243A20 24420008 */  addiu     $v0, $v0, 8
/* A2DC64 80243A24 AD020000 */  sw        $v0, ($t0)
/* A2DC68 80243A28 3C02F100 */  lui       $v0, 0xf100
/* A2DC6C 80243A2C AC620000 */  sw        $v0, ($v1)
/* A2DC70 80243A30 29420017 */  slti      $v0, $t2, 0x17
/* A2DC74 80243A34 1440FF8E */  bnez      $v0, .L80243870
/* A2DC78 80243A38 AC640004 */   sw       $a0, 4($v1)
/* A2DC7C 80243A3C 12A0008F */  beqz      $s5, .L80243C7C
/* A2DC80 80243A40 3C03FD48 */   lui      $v1, 0xfd48
/* A2DC84 80243A44 34630107 */  ori       $v1, $v1, 0x107
/* A2DC88 80243A48 3C08F548 */  lui       $t0, 0xf548
/* A2DC8C 80243A4C 35084200 */  ori       $t0, $t0, 0x4200
/* A2DC90 80243A50 3C070741 */  lui       $a3, 0x741
/* A2DC94 80243A54 34E7C000 */  ori       $a3, $a3, 0xc000
/* A2DC98 80243A58 3C090041 */  lui       $t1, 0x41
/* A2DC9C 80243A5C 3C05800A */  lui       $a1, 0x800a
/* A2DCA0 80243A60 24A5A66C */  addiu     $a1, $a1, -0x5994
/* A2DCA4 80243A64 8CA40000 */  lw        $a0, ($a1)
/* A2DCA8 80243A68 3529C000 */  ori       $t1, $t1, 0xc000
/* A2DCAC 80243A6C 0080102D */  daddu     $v0, $a0, $zero
/* A2DCB0 80243A70 24840008 */  addiu     $a0, $a0, 8
/* A2DCB4 80243A74 ACA40000 */  sw        $a0, ($a1)
/* A2DCB8 80243A78 AC430000 */  sw        $v1, ($v0)
/* A2DCBC 80243A7C AC500004 */  sw        $s0, 4($v0)
/* A2DCC0 80243A80 24820008 */  addiu     $v0, $a0, 8
/* A2DCC4 80243A84 ACA20000 */  sw        $v0, ($a1)
/* A2DCC8 80243A88 3C020700 */  lui       $v0, 0x700
/* A2DCCC 80243A8C AC820004 */  sw        $v0, 4($a0)
/* A2DCD0 80243A90 24820010 */  addiu     $v0, $a0, 0x10
/* A2DCD4 80243A94 AC880000 */  sw        $t0, ($a0)
/* A2DCD8 80243A98 ACA20000 */  sw        $v0, ($a1)
/* A2DCDC 80243A9C 3C02E600 */  lui       $v0, 0xe600
/* A2DCE0 80243AA0 AC820008 */  sw        $v0, 8($a0)
/* A2DCE4 80243AA4 24820018 */  addiu     $v0, $a0, 0x18
/* A2DCE8 80243AA8 000A18C0 */  sll       $v1, $t2, 3
/* A2DCEC 80243AAC 006A1823 */  subu      $v1, $v1, $t2
/* A2DCF0 80243AB0 00033080 */  sll       $a2, $v1, 2
/* A2DCF4 80243AB4 30C60FFF */  andi      $a2, $a2, 0xfff
/* A2DCF8 80243AB8 AC80000C */  sw        $zero, 0xc($a0)
/* A2DCFC 80243ABC ACA20000 */  sw        $v0, ($a1)
/* A2DD00 80243AC0 3C02F400 */  lui       $v0, 0xf400
/* A2DD04 80243AC4 00C21025 */  or        $v0, $a2, $v0
/* A2DD08 80243AC8 00751821 */  addu      $v1, $v1, $s5
/* A2DD0C 80243ACC 2463FFFF */  addiu     $v1, $v1, -1
/* A2DD10 80243AD0 00031880 */  sll       $v1, $v1, 2
/* A2DD14 80243AD4 30630FFF */  andi      $v1, $v1, 0xfff
/* A2DD18 80243AD8 00673825 */  or        $a3, $v1, $a3
/* A2DD1C 80243ADC AC820010 */  sw        $v0, 0x10($a0)
/* A2DD20 80243AE0 24820020 */  addiu     $v0, $a0, 0x20
/* A2DD24 80243AE4 AC870014 */  sw        $a3, 0x14($a0)
/* A2DD28 80243AE8 ACA20000 */  sw        $v0, ($a1)
/* A2DD2C 80243AEC 3C02E700 */  lui       $v0, 0xe700
/* A2DD30 80243AF0 AC820018 */  sw        $v0, 0x18($a0)
/* A2DD34 80243AF4 24820028 */  addiu     $v0, $a0, 0x28
/* A2DD38 80243AF8 24870030 */  addiu     $a3, $a0, 0x30
/* A2DD3C 80243AFC AC80001C */  sw        $zero, 0x1c($a0)
/* A2DD40 80243B00 ACA20000 */  sw        $v0, ($a1)
/* A2DD44 80243B04 3C02F200 */  lui       $v0, 0xf200
/* A2DD48 80243B08 00C23025 */  or        $a2, $a2, $v0
/* A2DD4C 80243B0C 00691825 */  or        $v1, $v1, $t1
/* A2DD50 80243B10 AC880020 */  sw        $t0, 0x20($a0)
/* A2DD54 80243B14 AC800024 */  sw        $zero, 0x24($a0)
/* A2DD58 80243B18 ACA70000 */  sw        $a3, ($a1)
/* A2DD5C 80243B1C AC860028 */  sw        $a2, 0x28($a0)
/* A2DD60 80243B20 AC83002C */  sw        $v1, 0x2c($a0)
/* A2DD64 80243B24 24840038 */  addiu     $a0, $a0, 0x38
/* A2DD68 80243B28 27220108 */  addiu     $v0, $t9, 0x108
/* A2DD6C 80243B2C 00021480 */  sll       $v0, $v0, 0x12
/* A2DD70 80243B30 00021403 */  sra       $v0, $v0, 0x10
/* A2DD74 80243B34 18400006 */  blez      $v0, .L80243B50
/* A2DD78 80243B38 ACA40000 */   sw       $a0, ($a1)
/* A2DD7C 80243B3C 30420FFF */  andi      $v0, $v0, 0xfff
/* A2DD80 80243B40 00021300 */  sll       $v0, $v0, 0xc
/* A2DD84 80243B44 3C03E400 */  lui       $v1, 0xe400
/* A2DD88 80243B48 08090ED5 */  j         .L80243B54
/* A2DD8C 80243B4C 00431825 */   or       $v1, $v0, $v1
.L80243B50:
/* A2DD90 80243B50 3C03E400 */  lui       $v1, 0xe400
.L80243B54:
/* A2DD94 80243B54 000A10C0 */  sll       $v0, $t2, 3
/* A2DD98 80243B58 004A1023 */  subu      $v0, $v0, $t2
/* A2DD9C 80243B5C 02821021 */  addu      $v0, $s4, $v0
/* A2DDA0 80243B60 00551021 */  addu      $v0, $v0, $s5
/* A2DDA4 80243B64 00021480 */  sll       $v0, $v0, 0x12
/* A2DDA8 80243B68 00021403 */  sra       $v0, $v0, 0x10
/* A2DDAC 80243B6C 18400004 */  blez      $v0, .L80243B80
/* A2DDB0 80243B70 ACE30000 */   sw       $v1, ($a3)
/* A2DDB4 80243B74 30420FFF */  andi      $v0, $v0, 0xfff
/* A2DDB8 80243B78 00621025 */  or        $v0, $v1, $v0
/* A2DDBC 80243B7C ACE20000 */  sw        $v0, ($a3)
.L80243B80:
/* A2DDC0 80243B80 00191480 */  sll       $v0, $t9, 0x12
/* A2DDC4 80243B84 00021403 */  sra       $v0, $v0, 0x10
/* A2DDC8 80243B88 18400004 */  blez      $v0, .L80243B9C
/* A2DDCC 80243B8C 24E70004 */   addiu    $a3, $a3, 4
/* A2DDD0 80243B90 30420FFF */  andi      $v0, $v0, 0xfff
/* A2DDD4 80243B94 08090EE8 */  j         .L80243BA0
/* A2DDD8 80243B98 00021B00 */   sll      $v1, $v0, 0xc
.L80243B9C:
/* A2DDDC 80243B9C 0000182D */  daddu     $v1, $zero, $zero
.L80243BA0:
/* A2DDE0 80243BA0 000A10C0 */  sll       $v0, $t2, 3
/* A2DDE4 80243BA4 004A2823 */  subu      $a1, $v0, $t2
/* A2DDE8 80243BA8 02851021 */  addu      $v0, $s4, $a1
/* A2DDEC 80243BAC 00021480 */  sll       $v0, $v0, 0x12
/* A2DDF0 80243BB0 00021403 */  sra       $v0, $v0, 0x10
/* A2DDF4 80243BB4 18400004 */  blez      $v0, .L80243BC8
/* A2DDF8 80243BB8 ACE30000 */   sw       $v1, ($a3)
/* A2DDFC 80243BBC 30420FFF */  andi      $v0, $v0, 0xfff
/* A2DE00 80243BC0 00621025 */  or        $v0, $v1, $v0
/* A2DE04 80243BC4 ACE20000 */  sw        $v0, ($a3)
.L80243BC8:
/* A2DE08 80243BC8 3C03800A */  lui       $v1, 0x800a
/* A2DE0C 80243BCC 2463A66C */  addiu     $v1, $v1, -0x5994
/* A2DE10 80243BD0 8C620000 */  lw        $v0, ($v1)
/* A2DE14 80243BD4 00053140 */  sll       $a2, $a1, 5
/* A2DE18 80243BD8 0040202D */  daddu     $a0, $v0, $zero
/* A2DE1C 80243BDC 24420008 */  addiu     $v0, $v0, 8
/* A2DE20 80243BE0 AC620000 */  sw        $v0, ($v1)
/* A2DE24 80243BE4 3C02E100 */  lui       $v0, 0xe100
/* A2DE28 80243BE8 AC820000 */  sw        $v0, ($a0)
/* A2DE2C 80243BEC 00191480 */  sll       $v0, $t9, 0x12
/* A2DE30 80243BF0 00021403 */  sra       $v0, $v0, 0x10
/* A2DE34 80243BF4 04410007 */  bgez      $v0, .L80243C14
/* A2DE38 80243BF8 24840004 */   addiu    $a0, $a0, 4
/* A2DE3C 80243BFC 000210C0 */  sll       $v0, $v0, 3
/* A2DE40 80243C00 5C400001 */  bgtzl     $v0, .L80243C08
/* A2DE44 80243C04 0000102D */   daddu    $v0, $zero, $zero
.L80243C08:
/* A2DE48 80243C08 00021023 */  negu      $v0, $v0
/* A2DE4C 80243C0C 08090F06 */  j         .L80243C18
/* A2DE50 80243C10 00021C00 */   sll      $v1, $v0, 0x10
.L80243C14:
/* A2DE54 80243C14 0000182D */  daddu     $v1, $zero, $zero
.L80243C18:
/* A2DE58 80243C18 000A10C0 */  sll       $v0, $t2, 3
/* A2DE5C 80243C1C 004A1023 */  subu      $v0, $v0, $t2
/* A2DE60 80243C20 02822821 */  addu      $a1, $s4, $v0
/* A2DE64 80243C24 00051080 */  sll       $v0, $a1, 2
/* A2DE68 80243C28 04410007 */  bgez      $v0, .L80243C48
/* A2DE6C 80243C2C 30C2FFFF */   andi     $v0, $a2, 0xffff
/* A2DE70 80243C30 00051480 */  sll       $v0, $a1, 0x12
/* A2DE74 80243C34 00021343 */  sra       $v0, $v0, 0xd
/* A2DE78 80243C38 5C400001 */  bgtzl     $v0, .L80243C40
/* A2DE7C 80243C3C 0000102D */   daddu    $v0, $zero, $zero
.L80243C40:
/* A2DE80 80243C40 00C21023 */  subu      $v0, $a2, $v0
/* A2DE84 80243C44 3042FFFF */  andi      $v0, $v0, 0xffff
.L80243C48:
/* A2DE88 80243C48 00621025 */  or        $v0, $v1, $v0
/* A2DE8C 80243C4C AC820000 */  sw        $v0, ($a0)
/* A2DE90 80243C50 3C050400 */  lui       $a1, 0x400
/* A2DE94 80243C54 3C03800A */  lui       $v1, 0x800a
/* A2DE98 80243C58 2463A66C */  addiu     $v1, $v1, -0x5994
/* A2DE9C 80243C5C 8C620000 */  lw        $v0, ($v1)
/* A2DEA0 80243C60 34A50400 */  ori       $a1, $a1, 0x400
/* A2DEA4 80243C64 0040202D */  daddu     $a0, $v0, $zero
/* A2DEA8 80243C68 24420008 */  addiu     $v0, $v0, 8
/* A2DEAC 80243C6C AC620000 */  sw        $v0, ($v1)
/* A2DEB0 80243C70 3C02F100 */  lui       $v0, 0xf100
/* A2DEB4 80243C74 AC820000 */  sw        $v0, ($a0)
/* A2DEB8 80243C78 AC850004 */  sw        $a1, 4($a0)
.L80243C7C:
/* A2DEBC 80243C7C 3C03800A */  lui       $v1, 0x800a
/* A2DEC0 80243C80 2463A66C */  addiu     $v1, $v1, -0x5994
/* A2DEC4 80243C84 8C620000 */  lw        $v0, ($v1)
/* A2DEC8 80243C88 0040202D */  daddu     $a0, $v0, $zero
/* A2DECC 80243C8C 24420008 */  addiu     $v0, $v0, 8
/* A2DED0 80243C90 AC620000 */  sw        $v0, ($v1)
/* A2DED4 80243C94 3C02E700 */  lui       $v0, 0xe700
/* A2DED8 80243C98 AC820000 */  sw        $v0, ($a0)
/* A2DEDC 80243C9C AC800004 */  sw        $zero, 4($a0)
/* A2DEE0 80243CA0 8FB50014 */  lw        $s5, 0x14($sp)
/* A2DEE4 80243CA4 8FB40010 */  lw        $s4, 0x10($sp)
/* A2DEE8 80243CA8 8FB3000C */  lw        $s3, 0xc($sp)
/* A2DEEC 80243CAC 8FB20008 */  lw        $s2, 8($sp)
/* A2DEF0 80243CB0 8FB10004 */  lw        $s1, 4($sp)
/* A2DEF4 80243CB4 8FB00000 */  lw        $s0, ($sp)
/* A2DEF8 80243CB8 03E00008 */  jr        $ra
/* A2DEFC 80243CBC 27BD0018 */   addiu    $sp, $sp, 0x18
