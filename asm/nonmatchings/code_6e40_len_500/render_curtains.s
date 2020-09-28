.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel render_curtains
/* 6E80 8002BA80 3C01800A */  lui       $at, 0x800a
/* 6E84 8002BA84 C420BA94 */  lwc1      $f0, -0x456c($at)
/* 6E88 8002BA88 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 6E8C 8002BA8C AFB20068 */  sw        $s2, 0x68($sp)
/* 6E90 8002BA90 3C12800A */  lui       $s2, %hi(D_8009BA90)
/* 6E94 8002BA94 2652BA90 */  addiu     $s2, $s2, %lo(D_8009BA90)
/* 6E98 8002BA98 AFBF0078 */  sw        $ra, 0x78($sp)
/* 6E9C 8002BA9C AFB50074 */  sw        $s5, 0x74($sp)
/* 6EA0 8002BAA0 AFB40070 */  sw        $s4, 0x70($sp)
/* 6EA4 8002BAA4 AFB3006C */  sw        $s3, 0x6c($sp)
/* 6EA8 8002BAA8 AFB10064 */  sw        $s1, 0x64($sp)
/* 6EAC 8002BAAC AFB00060 */  sw        $s0, 0x60($sp)
/* 6EB0 8002BAB0 F7B40080 */  sdc1      $f20, 0x80($sp)
/* 6EB4 8002BAB4 C6440000 */  lwc1      $f4, ($s2)
/* 6EB8 8002BAB8 46040032 */  c.eq.s    $f0, $f4
/* 6EBC 8002BABC 00000000 */  nop       
/* 6EC0 8002BAC0 4501000B */  bc1t      .L8002BAF0
/* 6EC4 8002BAC4 00000000 */   nop      
/* 6EC8 8002BAC8 46040001 */  sub.s     $f0, $f0, $f4
/* 6ECC 8002BACC 3C018009 */  lui       $at, 0x8009
/* 6ED0 8002BAD0 D4227E00 */  ldc1      $f2, 0x7e00($at)
/* 6ED4 8002BAD4 46000021 */  cvt.d.s   $f0, $f0
/* 6ED8 8002BAD8 46220002 */  mul.d     $f0, $f0, $f2
/* 6EDC 8002BADC 00000000 */  nop       
/* 6EE0 8002BAE0 460020A1 */  cvt.d.s   $f2, $f4
/* 6EE4 8002BAE4 46201080 */  add.d     $f2, $f2, $f0
/* 6EE8 8002BAE8 462010A0 */  cvt.s.d   $f2, $f2
/* 6EEC 8002BAEC E6420000 */  swc1      $f2, ($s2)
.L8002BAF0:
/* 6EF0 8002BAF0 3C13800A */  lui       $s3, %hi(D_8009BA98)
/* 6EF4 8002BAF4 2673BA98 */  addiu     $s3, $s3, %lo(D_8009BA98)
/* 6EF8 8002BAF8 3C01800A */  lui       $at, 0x800a
/* 6EFC 8002BAFC C420BA9C */  lwc1      $f0, -0x4564($at)
/* 6F00 8002BB00 C6640000 */  lwc1      $f4, ($s3)
/* 6F04 8002BB04 46040032 */  c.eq.s    $f0, $f4
/* 6F08 8002BB08 00000000 */  nop       
/* 6F0C 8002BB0C 4501000B */  bc1t      .L8002BB3C
/* 6F10 8002BB10 00000000 */   nop      
/* 6F14 8002BB14 46040001 */  sub.s     $f0, $f0, $f4
/* 6F18 8002BB18 3C018009 */  lui       $at, 0x8009
/* 6F1C 8002BB1C D4227E08 */  ldc1      $f2, 0x7e08($at)
/* 6F20 8002BB20 46000021 */  cvt.d.s   $f0, $f0
/* 6F24 8002BB24 46220002 */  mul.d     $f0, $f0, $f2
/* 6F28 8002BB28 00000000 */  nop       
/* 6F2C 8002BB2C 460020A1 */  cvt.d.s   $f2, $f4
/* 6F30 8002BB30 46201080 */  add.d     $f2, $f2, $f0
/* 6F34 8002BB34 462010A0 */  cvt.s.d   $f2, $f2
/* 6F38 8002BB38 E6620000 */  swc1      $f2, ($s3)
.L8002BB3C:
/* 6F3C 8002BB3C C6400000 */  lwc1      $f0, ($s2)
/* 6F40 8002BB40 3C018009 */  lui       $at, 0x8009
/* 6F44 8002BB44 D4227E10 */  ldc1      $f2, 0x7e10($at)
/* 6F48 8002BB48 46000021 */  cvt.d.s   $f0, $f0
/* 6F4C 8002BB4C 4622003C */  c.lt.d    $f0, $f2
/* 6F50 8002BB50 00000000 */  nop       
/* 6F54 8002BB54 45000087 */  bc1f      .L8002BD74
/* 6F58 8002BB58 3C03FF10 */   lui      $v1, 0xff10
/* 6F5C 8002BB5C 3463013F */  ori       $v1, $v1, 0x13f
/* 6F60 8002BB60 3C11800A */  lui       $s1, 0x800a
/* 6F64 8002BB64 2631A66C */  addiu     $s1, $s1, -0x5994
/* 6F68 8002BB68 3C15E700 */  lui       $s5, 0xe700
/* 6F6C 8002BB6C 8E300000 */  lw        $s0, ($s1)
/* 6F70 8002BB70 3C04800A */  lui       $a0, 0x800a
/* 6F74 8002BB74 8C84A64C */  lw        $a0, -0x59b4($a0)
/* 6F78 8002BB78 0200102D */  daddu     $v0, $s0, $zero
/* 6F7C 8002BB7C 26100008 */  addiu     $s0, $s0, 8
/* 6F80 8002BB80 AE300000 */  sw        $s0, ($s1)
/* 6F84 8002BB84 AC550000 */  sw        $s5, ($v0)
/* 6F88 8002BB88 AC400004 */  sw        $zero, 4($v0)
/* 6F8C 8002BB8C 26020008 */  addiu     $v0, $s0, 8
/* 6F90 8002BB90 AE220000 */  sw        $v0, ($s1)
/* 6F94 8002BB94 0C0187A4 */  jal       osVirtualToPhysical
/* 6F98 8002BB98 AE030000 */   sw       $v1, ($s0)
/* 6F9C 8002BB9C 27A40020 */  addiu     $a0, $sp, 0x20
/* 6FA0 8002BBA0 8E230000 */  lw        $v1, ($s1)
/* 6FA4 8002BBA4 3C14DE00 */  lui       $s4, 0xde00
/* 6FA8 8002BBA8 AE020004 */  sw        $v0, 4($s0)
/* 6FAC 8002BBAC 3C028007 */  lui       $v0, 0x8007
/* 6FB0 8002BBB0 244260C0 */  addiu     $v0, $v0, 0x60c0
/* 6FB4 8002BBB4 3C05C2A0 */  lui       $a1, 0xc2a0
/* 6FB8 8002BBB8 3C0642A0 */  lui       $a2, 0x42a0
/* 6FBC 8002BBBC 3C07C270 */  lui       $a3, 0xc270
/* 6FC0 8002BBC0 3C014270 */  lui       $at, 0x4270
/* 6FC4 8002BBC4 44810000 */  mtc1      $at, $f0
/* 6FC8 8002BBC8 3C014320 */  lui       $at, 0x4320
/* 6FCC 8002BBCC 44811000 */  mtc1      $at, $f2
/* 6FD0 8002BBD0 3C014420 */  lui       $at, 0x4420
/* 6FD4 8002BBD4 44812000 */  mtc1      $at, $f4
/* 6FD8 8002BBD8 3C013F80 */  lui       $at, 0x3f80
/* 6FDC 8002BBDC 4481A000 */  mtc1      $at, $f20
/* 6FE0 8002BBE0 0060402D */  daddu     $t0, $v1, $zero
/* 6FE4 8002BBE4 24630008 */  addiu     $v1, $v1, 8
/* 6FE8 8002BBE8 AE230000 */  sw        $v1, ($s1)
/* 6FEC 8002BBEC AD140000 */  sw        $s4, ($t0)
/* 6FF0 8002BBF0 AD020004 */  sw        $v0, 4($t0)
/* 6FF4 8002BBF4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6FF8 8002BBF8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 6FFC 8002BBFC E7A40018 */  swc1      $f4, 0x18($sp)
/* 7000 8002BC00 0C0187CC */  jal       guFrustumF
/* 7004 8002BC04 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 7008 8002BC08 27A40020 */  addiu     $a0, $sp, 0x20
/* 700C 8002BC0C 3C10800A */  lui       $s0, 0x800a
/* 7010 8002BC10 2610BAA8 */  addiu     $s0, $s0, -0x4558
/* 7014 8002BC14 0C019D40 */  jal       guMtxF2L
/* 7018 8002BC18 0200282D */   daddu    $a1, $s0, $zero
/* 701C 8002BC1C 3C04DA38 */  lui       $a0, 0xda38
/* 7020 8002BC20 8E220000 */  lw        $v0, ($s1)
/* 7024 8002BC24 34840007 */  ori       $a0, $a0, 7
/* 7028 8002BC28 0040182D */  daddu     $v1, $v0, $zero
/* 702C 8002BC2C 24420008 */  addiu     $v0, $v0, 8
/* 7030 8002BC30 AE220000 */  sw        $v0, ($s1)
/* 7034 8002BC34 C6400000 */  lwc1      $f0, ($s2)
/* 7038 8002BC38 3C018009 */  lui       $at, 0x8009
/* 703C 8002BC3C D4227E18 */  ldc1      $f2, 0x7e18($at)
/* 7040 8002BC40 46000021 */  cvt.d.s   $f0, $f0
/* 7044 8002BC44 46220001 */  sub.d     $f0, $f0, $f2
/* 7048 8002BC48 AC640000 */  sw        $a0, ($v1)
/* 704C 8002BC4C 46200120 */  cvt.s.d   $f4, $f0
/* 7050 8002BC50 4614203C */  c.lt.s    $f4, $f20
/* 7054 8002BC54 00000000 */  nop       
/* 7058 8002BC58 45000002 */  bc1f      .L8002BC64
/* 705C 8002BC5C AC700004 */   sw       $s0, 4($v1)
/* 7060 8002BC60 4600A106 */  mov.s     $f4, $f20
.L8002BC64:
/* 7064 8002BC64 44800000 */  mtc1      $zero, $f0
/* 7068 8002BC68 3C018009 */  lui       $at, 0x8009
/* 706C 8002BC6C D4227E20 */  ldc1      $f2, 0x7e20($at)
/* 7070 8002BC70 44050000 */  mfc1      $a1, $f0
/* 7074 8002BC74 46002021 */  cvt.d.s   $f0, $f4
/* 7078 8002BC78 46220002 */  mul.d     $f0, $f0, $f2
/* 707C 8002BC7C 00000000 */  nop       
/* 7080 8002BC80 27A40020 */  addiu     $a0, $sp, 0x20
/* 7084 8002BC84 3C01C3A0 */  lui       $at, 0xc3a0
/* 7088 8002BC88 44811000 */  mtc1      $at, $f2
/* 708C 8002BC8C 00A0302D */  daddu     $a2, $a1, $zero
/* 7090 8002BC90 00A0382D */  daddu     $a3, $a1, $zero
/* 7094 8002BC94 AFA50014 */  sw        $a1, 0x14($sp)
/* 7098 8002BC98 AFA50018 */  sw        $a1, 0x18($sp)
/* 709C 8002BC9C E7A2001C */  swc1      $f2, 0x1c($sp)
/* 70A0 8002BCA0 46200020 */  cvt.s.d   $f0, $f0
/* 70A4 8002BCA4 0C018FC4 */  jal       guPositionF
/* 70A8 8002BCA8 E7A00010 */   swc1     $f0, 0x10($sp)
/* 70AC 8002BCAC 27A40020 */  addiu     $a0, $sp, 0x20
/* 70B0 8002BCB0 26100040 */  addiu     $s0, $s0, 0x40
/* 70B4 8002BCB4 0C019D40 */  jal       guMtxF2L
/* 70B8 8002BCB8 0200282D */   daddu    $a1, $s0, $zero
/* 70BC 8002BCBC 3C03DA38 */  lui       $v1, 0xda38
/* 70C0 8002BCC0 34630002 */  ori       $v1, $v1, 2
/* 70C4 8002BCC4 3C04D838 */  lui       $a0, 0xd838
/* 70C8 8002BCC8 34840002 */  ori       $a0, $a0, 2
/* 70CC 8002BCCC 8E250000 */  lw        $a1, ($s1)
/* 70D0 8002BCD0 3C01437F */  lui       $at, 0x437f
/* 70D4 8002BCD4 44810000 */  mtc1      $at, $f0
/* 70D8 8002BCD8 00A0102D */  daddu     $v0, $a1, $zero
/* 70DC 8002BCDC 24A50008 */  addiu     $a1, $a1, 8
/* 70E0 8002BCE0 AE250000 */  sw        $a1, ($s1)
/* 70E4 8002BCE4 AC430000 */  sw        $v1, ($v0)
/* 70E8 8002BCE8 AC500004 */  sw        $s0, 4($v0)
/* 70EC 8002BCEC 24A20008 */  addiu     $v0, $a1, 8
/* 70F0 8002BCF0 AE220000 */  sw        $v0, ($s1)
/* 70F4 8002BCF4 3C02FA00 */  lui       $v0, 0xfa00
/* 70F8 8002BCF8 ACA20000 */  sw        $v0, ($a1)
/* 70FC 8002BCFC 24A20010 */  addiu     $v0, $a1, 0x10
/* 7100 8002BD00 AE220000 */  sw        $v0, ($s1)
/* 7104 8002BD04 3C028007 */  lui       $v0, 0x8007
/* 7108 8002BD08 24426078 */  addiu     $v0, $v0, 0x6078
/* 710C 8002BD0C ACB40008 */  sw        $s4, 8($a1)
/* 7110 8002BD10 ACA2000C */  sw        $v0, 0xc($a1)
/* 7114 8002BD14 C6620000 */  lwc1      $f2, ($s3)
/* 7118 8002BD18 24A20018 */  addiu     $v0, $a1, 0x18
/* 711C 8002BD1C AE220000 */  sw        $v0, ($s1)
/* 7120 8002BD20 24020040 */  addiu     $v0, $zero, 0x40
/* 7124 8002BD24 46001082 */  mul.s     $f2, $f2, $f0
/* 7128 8002BD28 00000000 */  nop       
/* 712C 8002BD2C ACA20014 */  sw        $v0, 0x14($a1)
/* 7130 8002BD30 24A20020 */  addiu     $v0, $a1, 0x20
/* 7134 8002BD34 ACA40010 */  sw        $a0, 0x10($a1)
/* 7138 8002BD38 AE220000 */  sw        $v0, ($s1)
/* 713C 8002BD3C 46020001 */  sub.s     $f0, $f0, $f2
/* 7140 8002BD40 ACB50018 */  sw        $s5, 0x18($a1)
/* 7144 8002BD44 ACA0001C */  sw        $zero, 0x1c($a1)
/* 7148 8002BD48 4600018D */  trunc.w.s $f6, $f0
/* 714C 8002BD4C 44023000 */  mfc1      $v0, $f6
/* 7150 8002BD50 00000000 */  nop       
/* 7154 8002BD54 304200FF */  andi      $v0, $v0, 0xff
/* 7158 8002BD58 00021E00 */  sll       $v1, $v0, 0x18
/* 715C 8002BD5C 00022400 */  sll       $a0, $v0, 0x10
/* 7160 8002BD60 00641825 */  or        $v1, $v1, $a0
/* 7164 8002BD64 00021200 */  sll       $v0, $v0, 8
/* 7168 8002BD68 00621825 */  or        $v1, $v1, $v0
/* 716C 8002BD6C 346300FF */  ori       $v1, $v1, 0xff
/* 7170 8002BD70 ACA30004 */  sw        $v1, 4($a1)
.L8002BD74:
/* 7174 8002BD74 3C02800A */  lui       $v0, %hi(D_8009BAA0)
/* 7178 8002BD78 8C42BAA0 */  lw        $v0, %lo(D_8009BAA0)($v0)
/* 717C 8002BD7C 10400003 */  beqz      $v0, .L8002BD8C
/* 7180 8002BD80 00000000 */   nop      
/* 7184 8002BD84 0040F809 */  jalr      $v0
/* 7188 8002BD88 00000000 */   nop      
.L8002BD8C:
/* 718C 8002BD8C 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 7190 8002BD90 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 7194 8002BD94 8E020000 */  lw        $v0, ($s0)
/* 7198 8002BD98 90420073 */  lbu       $v0, 0x73($v0)
/* 719C 8002BD9C 30420001 */  andi      $v0, $v0, 1
/* 71A0 8002BDA0 14400044 */  bnez      $v0, .L8002BEB4
/* 71A4 8002BDA4 00000000 */   nop      
/* 71A8 8002BDA8 0C00CD4A */  jal       get_game_mode
/* 71AC 8002BDAC 00000000 */   nop      
/* 71B0 8002BDB0 00021400 */  sll       $v0, $v0, 0x10
/* 71B4 8002BDB4 00021403 */  sra       $v0, $v0, 0x10
/* 71B8 8002BDB8 24030010 */  addiu     $v1, $zero, 0x10
/* 71BC 8002BDBC 1043000C */  beq       $v0, $v1, .L8002BDF0
/* 71C0 8002BDC0 00000000 */   nop      
/* 71C4 8002BDC4 0C00CD4A */  jal       get_game_mode
/* 71C8 8002BDC8 00000000 */   nop      
/* 71CC 8002BDCC 00021400 */  sll       $v0, $v0, 0x10
/* 71D0 8002BDD0 00021403 */  sra       $v0, $v0, 0x10
/* 71D4 8002BDD4 24030002 */  addiu     $v1, $zero, 2
/* 71D8 8002BDD8 10430005 */  beq       $v0, $v1, .L8002BDF0
/* 71DC 8002BDDC 00000000 */   nop      
/* 71E0 8002BDE0 8E020000 */  lw        $v0, ($s0)
/* 71E4 8002BDE4 80420071 */  lb        $v0, 0x71($v0)
/* 71E8 8002BDE8 10400032 */  beqz      $v0, .L8002BEB4
/* 71EC 8002BDEC 00000000 */   nop      
.L8002BDF0:
/* 71F0 8002BDF0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 71F4 8002BDF4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 71F8 8002BDF8 94430134 */  lhu       $v1, 0x134($v0)
/* 71FC 8002BDFC 3C02AAAA */  lui       $v0, 0xaaaa
/* 7200 8002BE00 3442AAAB */  ori       $v0, $v0, 0xaaab
/* 7204 8002BE04 00620019 */  multu     $v1, $v0
/* 7208 8002BE08 00004810 */  mfhi      $t1
/* 720C 8002BE0C 00092102 */  srl       $a0, $t1, 4
/* 7210 8002BE10 00041040 */  sll       $v0, $a0, 1
/* 7214 8002BE14 00441021 */  addu      $v0, $v0, $a0
/* 7218 8002BE18 000210C0 */  sll       $v0, $v0, 3
/* 721C 8002BE1C 00621823 */  subu      $v1, $v1, $v0
/* 7220 8002BE20 3063FFFF */  andi      $v1, $v1, 0xffff
/* 7224 8002BE24 00034140 */  sll       $t0, $v1, 5
/* 7228 8002BE28 29020100 */  slti      $v0, $t0, 0x100
/* 722C 8002BE2C 50400001 */  beql      $v0, $zero, .L8002BE34
/* 7230 8002BE30 240800FF */   addiu    $t0, $zero, 0xff
.L8002BE34:
/* 7234 8002BE34 3C07FF20 */  lui       $a3, 0xff20
/* 7238 8002BE38 3C04800A */  lui       $a0, 0x800a
/* 723C 8002BE3C 2484A66C */  addiu     $a0, $a0, -0x5994
/* 7240 8002BE40 34E71000 */  ori       $a3, $a3, 0x1000
/* 7244 8002BE44 3C06DE00 */  lui       $a2, 0xde00
/* 7248 8002BE48 8C830000 */  lw        $v1, ($a0)
/* 724C 8002BE4C 3C028007 */  lui       $v0, 0x8007
/* 7250 8002BE50 244260C0 */  addiu     $v0, $v0, 0x60c0
/* 7254 8002BE54 0060282D */  daddu     $a1, $v1, $zero
/* 7258 8002BE58 24630008 */  addiu     $v1, $v1, 8
/* 725C 8002BE5C AC830000 */  sw        $v1, ($a0)
/* 7260 8002BE60 ACA20004 */  sw        $v0, 4($a1)
/* 7264 8002BE64 24620008 */  addiu     $v0, $v1, 8
/* 7268 8002BE68 ACA60000 */  sw        $a2, ($a1)
/* 726C 8002BE6C AC820000 */  sw        $v0, ($a0)
/* 7270 8002BE70 3C028007 */  lui       $v0, 0x8007
/* 7274 8002BE74 24427140 */  addiu     $v0, $v0, 0x7140
/* 7278 8002BE78 AC620004 */  sw        $v0, 4($v1)
/* 727C 8002BE7C 24620010 */  addiu     $v0, $v1, 0x10
/* 7280 8002BE80 AC660000 */  sw        $a2, ($v1)
/* 7284 8002BE84 AC820000 */  sw        $v0, ($a0)
/* 7288 8002BE88 3C02FA00 */  lui       $v0, 0xfa00
/* 728C 8002BE8C AC620008 */  sw        $v0, 8($v1)
/* 7290 8002BE90 310200FF */  andi      $v0, $t0, 0xff
/* 7294 8002BE94 00471025 */  or        $v0, $v0, $a3
/* 7298 8002BE98 AC62000C */  sw        $v0, 0xc($v1)
/* 729C 8002BE9C 24620018 */  addiu     $v0, $v1, 0x18
/* 72A0 8002BEA0 AC820000 */  sw        $v0, ($a0)
/* 72A4 8002BEA4 3C028007 */  lui       $v0, 0x8007
/* 72A8 8002BEA8 244271E8 */  addiu     $v0, $v0, 0x71e8
/* 72AC 8002BEAC AC660010 */  sw        $a2, 0x10($v1)
/* 72B0 8002BEB0 AC620014 */  sw        $v0, 0x14($v1)
.L8002BEB4:
/* 72B4 8002BEB4 8FBF0078 */  lw        $ra, 0x78($sp)
/* 72B8 8002BEB8 8FB50074 */  lw        $s5, 0x74($sp)
/* 72BC 8002BEBC 8FB40070 */  lw        $s4, 0x70($sp)
/* 72C0 8002BEC0 8FB3006C */  lw        $s3, 0x6c($sp)
/* 72C4 8002BEC4 8FB20068 */  lw        $s2, 0x68($sp)
/* 72C8 8002BEC8 8FB10064 */  lw        $s1, 0x64($sp)
/* 72CC 8002BECC 8FB00060 */  lw        $s0, 0x60($sp)
/* 72D0 8002BED0 D7B40080 */  ldc1      $f20, 0x80($sp)
/* 72D4 8002BED4 03E00008 */  jr        $ra
/* 72D8 8002BED8 27BD0088 */   addiu    $sp, $sp, 0x88
