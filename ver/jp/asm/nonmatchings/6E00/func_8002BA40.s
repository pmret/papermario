.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002BA40
/* 6E40 8002BA40 3C01800A */  lui       $at, %hi(D_8009BA74)
/* 6E44 8002BA44 C420BA74 */  lwc1      $f0, %lo(D_8009BA74)($at)
/* 6E48 8002BA48 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 6E4C 8002BA4C AFB20068 */  sw        $s2, 0x68($sp)
/* 6E50 8002BA50 3C12800A */  lui       $s2, %hi(D_8009BA70)
/* 6E54 8002BA54 2652BA70 */  addiu     $s2, $s2, %lo(D_8009BA70)
/* 6E58 8002BA58 AFBF0078 */  sw        $ra, 0x78($sp)
/* 6E5C 8002BA5C AFB50074 */  sw        $s5, 0x74($sp)
/* 6E60 8002BA60 AFB40070 */  sw        $s4, 0x70($sp)
/* 6E64 8002BA64 AFB3006C */  sw        $s3, 0x6c($sp)
/* 6E68 8002BA68 AFB10064 */  sw        $s1, 0x64($sp)
/* 6E6C 8002BA6C AFB00060 */  sw        $s0, 0x60($sp)
/* 6E70 8002BA70 F7B40080 */  sdc1      $f20, 0x80($sp)
/* 6E74 8002BA74 C6440000 */  lwc1      $f4, ($s2)
/* 6E78 8002BA78 46040032 */  c.eq.s    $f0, $f4
/* 6E7C 8002BA7C 00000000 */  nop
/* 6E80 8002BA80 4501000B */  bc1t      .L8002BAB0
/* 6E84 8002BA84 00000000 */   nop
/* 6E88 8002BA88 46040001 */  sub.s     $f0, $f0, $f4
/* 6E8C 8002BA8C 3C018009 */  lui       $at, %hi(D_80097DE0)
/* 6E90 8002BA90 D4227DE0 */  ldc1      $f2, %lo(D_80097DE0)($at)
/* 6E94 8002BA94 46000021 */  cvt.d.s   $f0, $f0
/* 6E98 8002BA98 46220002 */  mul.d     $f0, $f0, $f2
/* 6E9C 8002BA9C 00000000 */  nop
/* 6EA0 8002BAA0 460020A1 */  cvt.d.s   $f2, $f4
/* 6EA4 8002BAA4 46201080 */  add.d     $f2, $f2, $f0
/* 6EA8 8002BAA8 462010A0 */  cvt.s.d   $f2, $f2
/* 6EAC 8002BAAC E6420000 */  swc1      $f2, ($s2)
.L8002BAB0:
/* 6EB0 8002BAB0 3C13800A */  lui       $s3, %hi(D_8009BA78)
/* 6EB4 8002BAB4 2673BA78 */  addiu     $s3, $s3, %lo(D_8009BA78)
/* 6EB8 8002BAB8 3C01800A */  lui       $at, %hi(D_8009BA7C)
/* 6EBC 8002BABC C420BA7C */  lwc1      $f0, %lo(D_8009BA7C)($at)
/* 6EC0 8002BAC0 C6640000 */  lwc1      $f4, ($s3)
/* 6EC4 8002BAC4 46040032 */  c.eq.s    $f0, $f4
/* 6EC8 8002BAC8 00000000 */  nop
/* 6ECC 8002BACC 4501000B */  bc1t      .L8002BAFC
/* 6ED0 8002BAD0 00000000 */   nop
/* 6ED4 8002BAD4 46040001 */  sub.s     $f0, $f0, $f4
/* 6ED8 8002BAD8 3C018009 */  lui       $at, %hi(D_80097DE8)
/* 6EDC 8002BADC D4227DE8 */  ldc1      $f2, %lo(D_80097DE8)($at)
/* 6EE0 8002BAE0 46000021 */  cvt.d.s   $f0, $f0
/* 6EE4 8002BAE4 46220002 */  mul.d     $f0, $f0, $f2
/* 6EE8 8002BAE8 00000000 */  nop
/* 6EEC 8002BAEC 460020A1 */  cvt.d.s   $f2, $f4
/* 6EF0 8002BAF0 46201080 */  add.d     $f2, $f2, $f0
/* 6EF4 8002BAF4 462010A0 */  cvt.s.d   $f2, $f2
/* 6EF8 8002BAF8 E6620000 */  swc1      $f2, ($s3)
.L8002BAFC:
/* 6EFC 8002BAFC C6400000 */  lwc1      $f0, ($s2)
/* 6F00 8002BB00 3C018009 */  lui       $at, %hi(D_80097DF0)
/* 6F04 8002BB04 D4227DF0 */  ldc1      $f2, %lo(D_80097DF0)($at)
/* 6F08 8002BB08 46000021 */  cvt.d.s   $f0, $f0
/* 6F0C 8002BB0C 4622003C */  c.lt.d    $f0, $f2
/* 6F10 8002BB10 00000000 */  nop
/* 6F14 8002BB14 45000087 */  bc1f      .L8002BD34
/* 6F18 8002BB18 3C03FF10 */   lui      $v1, 0xff10
/* 6F1C 8002BB1C 3463013F */  ori       $v1, $v1, 0x13f
/* 6F20 8002BB20 3C11800A */  lui       $s1, %hi(D_8009A64C)
/* 6F24 8002BB24 2631A64C */  addiu     $s1, $s1, %lo(D_8009A64C)
/* 6F28 8002BB28 3C15E700 */  lui       $s5, 0xe700
/* 6F2C 8002BB2C 8E300000 */  lw        $s0, ($s1)
/* 6F30 8002BB30 3C04800A */  lui       $a0, %hi(D_8009A62C)
/* 6F34 8002BB34 8C84A62C */  lw        $a0, %lo(D_8009A62C)($a0)
/* 6F38 8002BB38 0200102D */  daddu     $v0, $s0, $zero
/* 6F3C 8002BB3C 26100008 */  addiu     $s0, $s0, 8
/* 6F40 8002BB40 AE300000 */  sw        $s0, ($s1)
/* 6F44 8002BB44 AC550000 */  sw        $s5, ($v0)
/* 6F48 8002BB48 AC400004 */  sw        $zero, 4($v0)
/* 6F4C 8002BB4C 26020008 */  addiu     $v0, $s0, 8
/* 6F50 8002BB50 AE220000 */  sw        $v0, ($s1)
/* 6F54 8002BB54 0C018798 */  jal       func_80061E60
/* 6F58 8002BB58 AE030000 */   sw       $v1, ($s0)
/* 6F5C 8002BB5C 27A40020 */  addiu     $a0, $sp, 0x20
/* 6F60 8002BB60 8E230000 */  lw        $v1, ($s1)
/* 6F64 8002BB64 3C14DE00 */  lui       $s4, 0xde00
/* 6F68 8002BB68 AE020004 */  sw        $v0, 4($s0)
/* 6F6C 8002BB6C 3C028007 */  lui       $v0, %hi(D_800760A0)
/* 6F70 8002BB70 244260A0 */  addiu     $v0, $v0, %lo(D_800760A0)
/* 6F74 8002BB74 3C05C2A0 */  lui       $a1, 0xc2a0
/* 6F78 8002BB78 3C0642A0 */  lui       $a2, 0x42a0
/* 6F7C 8002BB7C 3C07C270 */  lui       $a3, 0xc270
/* 6F80 8002BB80 3C014270 */  lui       $at, 0x4270
/* 6F84 8002BB84 44810000 */  mtc1      $at, $f0
/* 6F88 8002BB88 3C014320 */  lui       $at, 0x4320
/* 6F8C 8002BB8C 44811000 */  mtc1      $at, $f2
/* 6F90 8002BB90 3C014420 */  lui       $at, 0x4420
/* 6F94 8002BB94 44812000 */  mtc1      $at, $f4
/* 6F98 8002BB98 3C013F80 */  lui       $at, 0x3f80
/* 6F9C 8002BB9C 4481A000 */  mtc1      $at, $f20
/* 6FA0 8002BBA0 0060402D */  daddu     $t0, $v1, $zero
/* 6FA4 8002BBA4 24630008 */  addiu     $v1, $v1, 8
/* 6FA8 8002BBA8 AE230000 */  sw        $v1, ($s1)
/* 6FAC 8002BBAC AD140000 */  sw        $s4, ($t0)
/* 6FB0 8002BBB0 AD020004 */  sw        $v0, 4($t0)
/* 6FB4 8002BBB4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6FB8 8002BBB8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 6FBC 8002BBBC E7A40018 */  swc1      $f4, 0x18($sp)
/* 6FC0 8002BBC0 0C0187C0 */  jal       func_80061F00
/* 6FC4 8002BBC4 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 6FC8 8002BBC8 27A40020 */  addiu     $a0, $sp, 0x20
/* 6FCC 8002BBCC 3C10800A */  lui       $s0, %hi(D_8009BA88)
/* 6FD0 8002BBD0 2610BA88 */  addiu     $s0, $s0, %lo(D_8009BA88)
/* 6FD4 8002BBD4 0C019D38 */  jal       func_800674E0
/* 6FD8 8002BBD8 0200282D */   daddu    $a1, $s0, $zero
/* 6FDC 8002BBDC 3C04DA38 */  lui       $a0, 0xda38
/* 6FE0 8002BBE0 8E220000 */  lw        $v0, ($s1)
/* 6FE4 8002BBE4 34840007 */  ori       $a0, $a0, 7
/* 6FE8 8002BBE8 0040182D */  daddu     $v1, $v0, $zero
/* 6FEC 8002BBEC 24420008 */  addiu     $v0, $v0, 8
/* 6FF0 8002BBF0 AE220000 */  sw        $v0, ($s1)
/* 6FF4 8002BBF4 C6400000 */  lwc1      $f0, ($s2)
/* 6FF8 8002BBF8 3C018009 */  lui       $at, %hi(D_80097DF8)
/* 6FFC 8002BBFC D4227DF8 */  ldc1      $f2, %lo(D_80097DF8)($at)
/* 7000 8002BC00 46000021 */  cvt.d.s   $f0, $f0
/* 7004 8002BC04 46220001 */  sub.d     $f0, $f0, $f2
/* 7008 8002BC08 AC640000 */  sw        $a0, ($v1)
/* 700C 8002BC0C 46200120 */  cvt.s.d   $f4, $f0
/* 7010 8002BC10 4614203C */  c.lt.s    $f4, $f20
/* 7014 8002BC14 00000000 */  nop
/* 7018 8002BC18 45000002 */  bc1f      .L8002BC24
/* 701C 8002BC1C AC700004 */   sw       $s0, 4($v1)
/* 7020 8002BC20 4600A106 */  mov.s     $f4, $f20
.L8002BC24:
/* 7024 8002BC24 44800000 */  mtc1      $zero, $f0
/* 7028 8002BC28 3C018009 */  lui       $at, %hi(D_80097E00)
/* 702C 8002BC2C D4227E00 */  ldc1      $f2, %lo(D_80097E00)($at)
/* 7030 8002BC30 44050000 */  mfc1      $a1, $f0
/* 7034 8002BC34 46002021 */  cvt.d.s   $f0, $f4
/* 7038 8002BC38 46220002 */  mul.d     $f0, $f0, $f2
/* 703C 8002BC3C 00000000 */  nop
/* 7040 8002BC40 27A40020 */  addiu     $a0, $sp, 0x20
/* 7044 8002BC44 3C01C3A0 */  lui       $at, 0xc3a0
/* 7048 8002BC48 44811000 */  mtc1      $at, $f2
/* 704C 8002BC4C 00A0302D */  daddu     $a2, $a1, $zero
/* 7050 8002BC50 00A0382D */  daddu     $a3, $a1, $zero
/* 7054 8002BC54 AFA50014 */  sw        $a1, 0x14($sp)
/* 7058 8002BC58 AFA50018 */  sw        $a1, 0x18($sp)
/* 705C 8002BC5C E7A2001C */  swc1      $f2, 0x1c($sp)
/* 7060 8002BC60 46200020 */  cvt.s.d   $f0, $f0
/* 7064 8002BC64 0C018FB8 */  jal       func_80063EE0
/* 7068 8002BC68 E7A00010 */   swc1     $f0, 0x10($sp)
/* 706C 8002BC6C 27A40020 */  addiu     $a0, $sp, 0x20
/* 7070 8002BC70 26100040 */  addiu     $s0, $s0, 0x40
/* 7074 8002BC74 0C019D38 */  jal       func_800674E0
/* 7078 8002BC78 0200282D */   daddu    $a1, $s0, $zero
/* 707C 8002BC7C 3C03DA38 */  lui       $v1, 0xda38
/* 7080 8002BC80 34630002 */  ori       $v1, $v1, 2
/* 7084 8002BC84 3C04D838 */  lui       $a0, 0xd838
/* 7088 8002BC88 34840002 */  ori       $a0, $a0, 2
/* 708C 8002BC8C 8E250000 */  lw        $a1, ($s1)
/* 7090 8002BC90 3C01437F */  lui       $at, 0x437f
/* 7094 8002BC94 44810000 */  mtc1      $at, $f0
/* 7098 8002BC98 00A0102D */  daddu     $v0, $a1, $zero
/* 709C 8002BC9C 24A50008 */  addiu     $a1, $a1, 8
/* 70A0 8002BCA0 AE250000 */  sw        $a1, ($s1)
/* 70A4 8002BCA4 AC430000 */  sw        $v1, ($v0)
/* 70A8 8002BCA8 AC500004 */  sw        $s0, 4($v0)
/* 70AC 8002BCAC 24A20008 */  addiu     $v0, $a1, 8
/* 70B0 8002BCB0 AE220000 */  sw        $v0, ($s1)
/* 70B4 8002BCB4 3C02FA00 */  lui       $v0, 0xfa00
/* 70B8 8002BCB8 ACA20000 */  sw        $v0, ($a1)
/* 70BC 8002BCBC 24A20010 */  addiu     $v0, $a1, 0x10
/* 70C0 8002BCC0 AE220000 */  sw        $v0, ($s1)
/* 70C4 8002BCC4 3C028007 */  lui       $v0, %hi(D_80076058)
/* 70C8 8002BCC8 24426058 */  addiu     $v0, $v0, %lo(D_80076058)
/* 70CC 8002BCCC ACB40008 */  sw        $s4, 8($a1)
/* 70D0 8002BCD0 ACA2000C */  sw        $v0, 0xc($a1)
/* 70D4 8002BCD4 C6620000 */  lwc1      $f2, ($s3)
/* 70D8 8002BCD8 24A20018 */  addiu     $v0, $a1, 0x18
/* 70DC 8002BCDC AE220000 */  sw        $v0, ($s1)
/* 70E0 8002BCE0 24020040 */  addiu     $v0, $zero, 0x40
/* 70E4 8002BCE4 46001082 */  mul.s     $f2, $f2, $f0
/* 70E8 8002BCE8 00000000 */  nop
/* 70EC 8002BCEC ACA20014 */  sw        $v0, 0x14($a1)
/* 70F0 8002BCF0 24A20020 */  addiu     $v0, $a1, 0x20
/* 70F4 8002BCF4 ACA40010 */  sw        $a0, 0x10($a1)
/* 70F8 8002BCF8 AE220000 */  sw        $v0, ($s1)
/* 70FC 8002BCFC 46020001 */  sub.s     $f0, $f0, $f2
/* 7100 8002BD00 ACB50018 */  sw        $s5, 0x18($a1)
/* 7104 8002BD04 ACA0001C */  sw        $zero, 0x1c($a1)
/* 7108 8002BD08 4600018D */  trunc.w.s $f6, $f0
/* 710C 8002BD0C 44023000 */  mfc1      $v0, $f6
/* 7110 8002BD10 00000000 */  nop
/* 7114 8002BD14 304200FF */  andi      $v0, $v0, 0xff
/* 7118 8002BD18 00021E00 */  sll       $v1, $v0, 0x18
/* 711C 8002BD1C 00022400 */  sll       $a0, $v0, 0x10
/* 7120 8002BD20 00641825 */  or        $v1, $v1, $a0
/* 7124 8002BD24 00021200 */  sll       $v0, $v0, 8
/* 7128 8002BD28 00621825 */  or        $v1, $v1, $v0
/* 712C 8002BD2C 346300FF */  ori       $v1, $v1, 0xff
/* 7130 8002BD30 ACA30004 */  sw        $v1, 4($a1)
.L8002BD34:
/* 7134 8002BD34 3C02800A */  lui       $v0, %hi(D_8009BA80)
/* 7138 8002BD38 8C42BA80 */  lw        $v0, %lo(D_8009BA80)($v0)
/* 713C 8002BD3C 10400003 */  beqz      $v0, .L8002BD4C
/* 7140 8002BD40 00000000 */   nop
/* 7144 8002BD44 0040F809 */  jalr      $v0
/* 7148 8002BD48 00000000 */   nop
.L8002BD4C:
/* 714C 8002BD4C 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 7150 8002BD50 2610417C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 7154 8002BD54 8E020000 */  lw        $v0, ($s0)
/* 7158 8002BD58 90420073 */  lbu       $v0, 0x73($v0)
/* 715C 8002BD5C 30420001 */  andi      $v0, $v0, 1
/* 7160 8002BD60 14400044 */  bnez      $v0, .L8002BE74
/* 7164 8002BD64 00000000 */   nop
/* 7168 8002BD68 0C00CC6E */  jal       func_800331B8
/* 716C 8002BD6C 00000000 */   nop
/* 7170 8002BD70 00021400 */  sll       $v0, $v0, 0x10
/* 7174 8002BD74 00021403 */  sra       $v0, $v0, 0x10
/* 7178 8002BD78 24030010 */  addiu     $v1, $zero, 0x10
/* 717C 8002BD7C 1043000C */  beq       $v0, $v1, .L8002BDB0
/* 7180 8002BD80 00000000 */   nop
/* 7184 8002BD84 0C00CC6E */  jal       func_800331B8
/* 7188 8002BD88 00000000 */   nop
/* 718C 8002BD8C 00021400 */  sll       $v0, $v0, 0x10
/* 7190 8002BD90 00021403 */  sra       $v0, $v0, 0x10
/* 7194 8002BD94 24030002 */  addiu     $v1, $zero, 2
/* 7198 8002BD98 10430005 */  beq       $v0, $v1, .L8002BDB0
/* 719C 8002BD9C 00000000 */   nop
/* 71A0 8002BDA0 8E020000 */  lw        $v0, ($s0)
/* 71A4 8002BDA4 80420071 */  lb        $v0, 0x71($v0)
/* 71A8 8002BDA8 10400032 */  beqz      $v0, .L8002BE74
/* 71AC 8002BDAC 00000000 */   nop
.L8002BDB0:
/* 71B0 8002BDB0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 71B4 8002BDB4 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 71B8 8002BDB8 94430134 */  lhu       $v1, 0x134($v0)
/* 71BC 8002BDBC 3C02AAAA */  lui       $v0, 0xaaaa
/* 71C0 8002BDC0 3442AAAB */  ori       $v0, $v0, 0xaaab
/* 71C4 8002BDC4 00620019 */  multu     $v1, $v0
/* 71C8 8002BDC8 00004810 */  mfhi      $t1
/* 71CC 8002BDCC 00092102 */  srl       $a0, $t1, 4
/* 71D0 8002BDD0 00041040 */  sll       $v0, $a0, 1
/* 71D4 8002BDD4 00441021 */  addu      $v0, $v0, $a0
/* 71D8 8002BDD8 000210C0 */  sll       $v0, $v0, 3
/* 71DC 8002BDDC 00621823 */  subu      $v1, $v1, $v0
/* 71E0 8002BDE0 3063FFFF */  andi      $v1, $v1, 0xffff
/* 71E4 8002BDE4 00034140 */  sll       $t0, $v1, 5
/* 71E8 8002BDE8 29020100 */  slti      $v0, $t0, 0x100
/* 71EC 8002BDEC 50400001 */  beql      $v0, $zero, .L8002BDF4
/* 71F0 8002BDF0 240800FF */   addiu    $t0, $zero, 0xff
.L8002BDF4:
/* 71F4 8002BDF4 3C07FF20 */  lui       $a3, 0xff20
/* 71F8 8002BDF8 3C04800A */  lui       $a0, %hi(D_8009A64C)
/* 71FC 8002BDFC 2484A64C */  addiu     $a0, $a0, %lo(D_8009A64C)
/* 7200 8002BE00 34E71000 */  ori       $a3, $a3, 0x1000
/* 7204 8002BE04 3C06DE00 */  lui       $a2, 0xde00
/* 7208 8002BE08 8C830000 */  lw        $v1, ($a0)
/* 720C 8002BE0C 3C028007 */  lui       $v0, %hi(D_800760A0)
/* 7210 8002BE10 244260A0 */  addiu     $v0, $v0, %lo(D_800760A0)
/* 7214 8002BE14 0060282D */  daddu     $a1, $v1, $zero
/* 7218 8002BE18 24630008 */  addiu     $v1, $v1, 8
/* 721C 8002BE1C AC830000 */  sw        $v1, ($a0)
/* 7220 8002BE20 ACA20004 */  sw        $v0, 4($a1)
/* 7224 8002BE24 24620008 */  addiu     $v0, $v1, 8
/* 7228 8002BE28 ACA60000 */  sw        $a2, ($a1)
/* 722C 8002BE2C AC820000 */  sw        $v0, ($a0)
/* 7230 8002BE30 3C028007 */  lui       $v0, %hi(D_80077120)
/* 7234 8002BE34 24427120 */  addiu     $v0, $v0, %lo(D_80077120)
/* 7238 8002BE38 AC620004 */  sw        $v0, 4($v1)
/* 723C 8002BE3C 24620010 */  addiu     $v0, $v1, 0x10
/* 7240 8002BE40 AC660000 */  sw        $a2, ($v1)
/* 7244 8002BE44 AC820000 */  sw        $v0, ($a0)
/* 7248 8002BE48 3C02FA00 */  lui       $v0, 0xfa00
/* 724C 8002BE4C AC620008 */  sw        $v0, 8($v1)
/* 7250 8002BE50 310200FF */  andi      $v0, $t0, 0xff
/* 7254 8002BE54 00471025 */  or        $v0, $v0, $a3
/* 7258 8002BE58 AC62000C */  sw        $v0, 0xc($v1)
/* 725C 8002BE5C 24620018 */  addiu     $v0, $v1, 0x18
/* 7260 8002BE60 AC820000 */  sw        $v0, ($a0)
/* 7264 8002BE64 3C028007 */  lui       $v0, %hi(D_800771C8)
/* 7268 8002BE68 244271C8 */  addiu     $v0, $v0, %lo(D_800771C8)
/* 726C 8002BE6C AC660010 */  sw        $a2, 0x10($v1)
/* 7270 8002BE70 AC620014 */  sw        $v0, 0x14($v1)
.L8002BE74:
/* 7274 8002BE74 8FBF0078 */  lw        $ra, 0x78($sp)
/* 7278 8002BE78 8FB50074 */  lw        $s5, 0x74($sp)
/* 727C 8002BE7C 8FB40070 */  lw        $s4, 0x70($sp)
/* 7280 8002BE80 8FB3006C */  lw        $s3, 0x6c($sp)
/* 7284 8002BE84 8FB20068 */  lw        $s2, 0x68($sp)
/* 7288 8002BE88 8FB10064 */  lw        $s1, 0x64($sp)
/* 728C 8002BE8C 8FB00060 */  lw        $s0, 0x60($sp)
/* 7290 8002BE90 D7B40080 */  ldc1      $f20, 0x80($sp)
/* 7294 8002BE94 03E00008 */  jr        $ra
/* 7298 8002BE98 27BD0088 */   addiu    $sp, $sp, 0x88
