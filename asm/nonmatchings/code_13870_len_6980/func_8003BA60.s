.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003BA60
/* 16E60 8003BA60 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 16E64 8003BA64 AFB30024 */  sw        $s3, 0x24($sp)
/* 16E68 8003BA68 0080982D */  daddu     $s3, $a0, $zero
/* 16E6C 8003BA6C AFB60030 */  sw        $s6, 0x30($sp)
/* 16E70 8003BA70 00A0B02D */  daddu     $s6, $a1, $zero
/* 16E74 8003BA74 AFB40028 */  sw        $s4, 0x28($sp)
/* 16E78 8003BA78 00C0A02D */  daddu     $s4, $a2, $zero
/* 16E7C 8003BA7C AFBF0038 */  sw        $ra, 0x38($sp)
/* 16E80 8003BA80 AFB70034 */  sw        $s7, 0x34($sp)
/* 16E84 8003BA84 AFB5002C */  sw        $s5, 0x2c($sp)
/* 16E88 8003BA88 AFB20020 */  sw        $s2, 0x20($sp)
/* 16E8C 8003BA8C AFB1001C */  sw        $s1, 0x1c($sp)
/* 16E90 8003BA90 AFB00018 */  sw        $s0, 0x18($sp)
/* 16E94 8003BA94 826200B6 */  lb        $v0, 0xb6($s3)
/* 16E98 8003BA98 10400049 */  beqz      $v0, .L8003BBC0
/* 16E9C 8003BA9C 00E0B82D */   daddu    $s7, $a3, $zero
/* 16EA0 8003BAA0 8E620000 */  lw        $v0, ($s3)
/* 16EA4 8003BAA4 3C034000 */  lui       $v1, 0x4000
/* 16EA8 8003BAA8 00431024 */  and       $v0, $v0, $v1
/* 16EAC 8003BAAC 14400004 */  bnez      $v0, .L8003BAC0
/* 16EB0 8003BAB0 00000000 */   nop
/* 16EB4 8003BAB4 0C0B7A90 */  jal       func_802DEA40
/* 16EB8 8003BAB8 96640028 */   lhu      $a0, 0x28($s3)
/* 16EBC 8003BABC AE6200C4 */  sw        $v0, 0xc4($s3)
.L8003BAC0:
/* 16EC0 8003BAC0 8E6400C4 */  lw        $a0, 0xc4($s3)
/* 16EC4 8003BAC4 A26000C1 */  sb        $zero, 0xc1($s3)
/* 16EC8 8003BAC8 8C830000 */  lw        $v1, ($a0)
/* 16ECC 8003BACC 2402FFFF */  addiu     $v0, $zero, -1
/* 16ED0 8003BAD0 1062000B */  beq       $v1, $v0, .L8003BB00
/* 16ED4 8003BAD4 0080182D */   daddu    $v1, $a0, $zero
/* 16ED8 8003BAD8 0040202D */  daddu     $a0, $v0, $zero
.L8003BADC:
/* 16EDC 8003BADC 926200C1 */  lbu       $v0, 0xc1($s3)
/* 16EE0 8003BAE0 24420001 */  addiu     $v0, $v0, 1
/* 16EE4 8003BAE4 A26200C1 */  sb        $v0, 0xc1($s3)
/* 16EE8 8003BAE8 00021600 */  sll       $v0, $v0, 0x18
/* 16EEC 8003BAEC 00021583 */  sra       $v0, $v0, 0x16
/* 16EF0 8003BAF0 00431021 */  addu      $v0, $v0, $v1
/* 16EF4 8003BAF4 8C420000 */  lw        $v0, ($v0)
/* 16EF8 8003BAF8 1444FFF8 */  bne       $v0, $a0, .L8003BADC
/* 16EFC 8003BAFC 00000000 */   nop
.L8003BB00:
/* 16F00 8003BB00 826300B6 */  lb        $v1, 0xb6($s3)
/* 16F04 8003BB04 24020001 */  addiu     $v0, $zero, 1
/* 16F08 8003BB08 14620004 */  bne       $v1, $v0, .L8003BB1C
/* 16F0C 8003BB0C 240200FF */   addiu    $v0, $zero, 0xff
/* 16F10 8003BB10 A26000B7 */  sb        $zero, 0xb7($s3)
/* 16F14 8003BB14 0800EEC9 */  j         .L8003BB24
/* 16F18 8003BB18 A66000BE */   sh       $zero, 0xbe($s3)
.L8003BB1C:
/* 16F1C 8003BB1C A26000B7 */  sb        $zero, 0xb7($s3)
/* 16F20 8003BB20 A66200BE */  sh        $v0, 0xbe($s3)
.L8003BB24:
/* 16F24 8003BB24 826200C1 */  lb        $v0, 0xc1($s3)
/* 16F28 8003BB28 18400018 */  blez      $v0, .L8003BB8C
/* 16F2C 8003BB2C 0000202D */   daddu    $a0, $zero, $zero
/* 16F30 8003BB30 0260302D */  daddu     $a2, $s3, $zero
/* 16F34 8003BB34 240500C8 */  addiu     $a1, $zero, 0xc8
.L8003BB38:
/* 16F38 8003BB38 8E6300C4 */  lw        $v1, 0xc4($s3)
/* 16F3C 8003BB3C 00041080 */  sll       $v0, $a0, 2
/* 16F40 8003BB40 00431021 */  addu      $v0, $v0, $v1
/* 16F44 8003BB44 8C520000 */  lw        $s2, ($v0)
/* 16F48 8003BB48 02658821 */  addu      $s1, $s3, $a1
/* 16F4C 8003BB4C 12400009 */  beqz      $s2, .L8003BB74
/* 16F50 8003BB50 ACD102C8 */   sw       $s1, 0x2c8($a2)
/* 16F54 8003BB54 0000802D */  daddu     $s0, $zero, $zero
.L8003BB58:
/* 16F58 8003BB58 96420000 */  lhu       $v0, ($s2)
/* 16F5C 8003BB5C 26520002 */  addiu     $s2, $s2, 2
/* 16F60 8003BB60 26100001 */  addiu     $s0, $s0, 1
/* 16F64 8003BB64 A6220000 */  sh        $v0, ($s1)
/* 16F68 8003BB68 2A020010 */  slti      $v0, $s0, 0x10
/* 16F6C 8003BB6C 1440FFFA */  bnez      $v0, .L8003BB58
/* 16F70 8003BB70 26310002 */   addiu    $s1, $s1, 2
.L8003BB74:
/* 16F74 8003BB74 24C60004 */  addiu     $a2, $a2, 4
/* 16F78 8003BB78 826200C1 */  lb        $v0, 0xc1($s3)
/* 16F7C 8003BB7C 24840001 */  addiu     $a0, $a0, 1
/* 16F80 8003BB80 0082102A */  slt       $v0, $a0, $v0
/* 16F84 8003BB84 1440FFEC */  bnez      $v0, .L8003BB38
/* 16F88 8003BB88 24A50020 */   addiu    $a1, $a1, 0x20
.L8003BB8C:
/* 16F8C 8003BB8C 16800007 */  bnez      $s4, .L8003BBAC
/* 16F90 8003BB90 00000000 */   nop
/* 16F94 8003BB94 9662030C */  lhu       $v0, 0x30c($s3)
/* 16F98 8003BB98 A660030C */  sh        $zero, 0x30c($s3)
/* 16F9C 8003BB9C A662030E */  sh        $v0, 0x30e($s3)
/* 16FA0 8003BBA0 0040182D */  daddu     $v1, $v0, $zero
/* 16FA4 8003BBA4 A6620310 */  sh        $v0, 0x310($s3)
/* 16FA8 8003BBA8 A6630312 */  sh        $v1, 0x312($s3)
.L8003BBAC:
/* 16FAC 8003BBAC 9662030C */  lhu       $v0, 0x30c($s3)
/* 16FB0 8003BBB0 A66000BE */  sh        $zero, 0xbe($s3)
/* 16FB4 8003BBB4 A26000B7 */  sb        $zero, 0xb7($s3)
/* 16FB8 8003BBB8 A26000B6 */  sb        $zero, 0xb6($s3)
/* 16FBC 8003BBBC A66200BC */  sh        $v0, 0xbc($s3)
.L8003BBC0:
/* 16FC0 8003BBC0 826300B7 */  lb        $v1, 0xb7($s3)
/* 16FC4 8003BBC4 10600005 */  beqz      $v1, .L8003BBDC
/* 16FC8 8003BBC8 24020001 */   addiu    $v0, $zero, 1
/* 16FCC 8003BBCC 1062000C */  beq       $v1, $v0, .L8003BC00
/* 16FD0 8003BBD0 24020002 */   addiu    $v0, $zero, 2
/* 16FD4 8003BBD4 0800EF40 */  j         .L8003BD00
/* 16FD8 8003BBD8 00000000 */   nop
.L8003BBDC:
/* 16FDC 8003BBDC 866200BC */  lh        $v0, 0xbc($s3)
/* 16FE0 8003BBE0 966300BC */  lhu       $v1, 0xbc($s3)
/* 16FE4 8003BBE4 10400003 */  beqz      $v0, .L8003BBF4
/* 16FE8 8003BBE8 2462FFFF */   addiu    $v0, $v1, -1
/* 16FEC 8003BBEC 0800EF3E */  j         .L8003BCF8
/* 16FF0 8003BBF0 A66200BC */   sh       $v0, 0xbc($s3)
.L8003BBF4:
/* 16FF4 8003BBF4 24020001 */  addiu     $v0, $zero, 1
/* 16FF8 8003BBF8 A66000BE */  sh        $zero, 0xbe($s3)
/* 16FFC 8003BBFC A26200B7 */  sb        $v0, 0xb7($s3)
.L8003BC00:
/* 17000 8003BC00 8662030E */  lh        $v0, 0x30e($s3)
/* 17004 8003BC04 24036400 */  addiu     $v1, $zero, 0x6400
/* 17008 8003BC08 14400002 */  bnez      $v0, .L8003BC14
/* 1700C 8003BC0C 0062001A */   div      $zero, $v1, $v0
/* 17010 8003BC10 0007000D */  break     7
.L8003BC14:
/* 17014 8003BC14 2401FFFF */   addiu    $at, $zero, -1
/* 17018 8003BC18 14410004 */  bne       $v0, $at, .L8003BC2C
/* 1701C 8003BC1C 3C018000 */   lui      $at, 0x8000
/* 17020 8003BC20 14610002 */  bne       $v1, $at, .L8003BC2C
/* 17024 8003BC24 00000000 */   nop
/* 17028 8003BC28 0006000D */  break     6
.L8003BC2C:
/* 1702C 8003BC2C 00001812 */   mflo     $v1
/* 17030 8003BC30 966200BE */  lhu       $v0, 0xbe($s3)
/* 17034 8003BC34 00431021 */  addu      $v0, $v0, $v1
/* 17038 8003BC38 A66200BE */  sh        $v0, 0xbe($s3)
/* 1703C 8003BC3C 00021400 */  sll       $v0, $v0, 0x10
/* 17040 8003BC40 00021403 */  sra       $v0, $v0, 0x10
/* 17044 8003BC44 2842639D */  slti      $v0, $v0, 0x639d
/* 17048 8003BC48 14400003 */  bnez      $v0, .L8003BC58
/* 1704C 8003BC4C 3C0651EB */   lui      $a2, 0x51eb
/* 17050 8003BC50 2402639C */  addiu     $v0, $zero, 0x639c
/* 17054 8003BC54 A66200BE */  sh        $v0, 0xbe($s3)
.L8003BC58:
/* 17058 8003BC58 34C6851F */  ori       $a2, $a2, 0x851f
/* 1705C 8003BC5C 267400C8 */  addiu     $s4, $s3, 0xc8
/* 17060 8003BC60 0000802D */  daddu     $s0, $zero, $zero
/* 17064 8003BC64 86620308 */  lh        $v0, 0x308($s3)
/* 17068 8003BC68 8E6500C4 */  lw        $a1, 0xc4($s3)
/* 1706C 8003BC6C 966300BE */  lhu       $v1, 0xbe($s3)
/* 17070 8003BC70 00021080 */  sll       $v0, $v0, 2
/* 17074 8003BC74 00451021 */  addu      $v0, $v0, $a1
/* 17078 8003BC78 00031C00 */  sll       $v1, $v1, 0x10
/* 1707C 8003BC7C 00032403 */  sra       $a0, $v1, 0x10
/* 17080 8003BC80 8C520000 */  lw        $s2, ($v0)
/* 17084 8003BC84 8662030A */  lh        $v0, 0x30a($s3)
/* 17088 8003BC88 00860018 */  mult      $a0, $a2
/* 1708C 8003BC8C 00021080 */  sll       $v0, $v0, 2
/* 17090 8003BC90 00451021 */  addu      $v0, $v0, $a1
/* 17094 8003BC94 8C510000 */  lw        $s1, ($v0)
/* 17098 8003BC98 00031FC3 */  sra       $v1, $v1, 0x1f
/* 1709C 8003BC9C AE7402C8 */  sw        $s4, 0x2c8($s3)
/* 170A0 8003BCA0 00004010 */  mfhi      $t0
/* 170A4 8003BCA4 00081143 */  sra       $v0, $t0, 5
/* 170A8 8003BCA8 00431023 */  subu      $v0, $v0, $v1
/* 170AC 8003BCAC 00021400 */  sll       $v0, $v0, 0x10
/* 170B0 8003BCB0 0002AC03 */  sra       $s5, $v0, 0x10
.L8003BCB4:
/* 170B4 8003BCB4 96440000 */  lhu       $a0, ($s2)
/* 170B8 8003BCB8 26520002 */  addiu     $s2, $s2, 2
/* 170BC 8003BCBC 96250000 */  lhu       $a1, ($s1)
/* 170C0 8003BCC0 26310002 */  addiu     $s1, $s1, 2
/* 170C4 8003BCC4 02A0302D */  daddu     $a2, $s5, $zero
/* 170C8 8003BCC8 0C00EE5B */  jal       func_8003B96C
/* 170CC 8003BCCC 26100001 */   addiu    $s0, $s0, 1
/* 170D0 8003BCD0 A6820000 */  sh        $v0, ($s4)
/* 170D4 8003BCD4 2A020010 */  slti      $v0, $s0, 0x10
/* 170D8 8003BCD8 1440FFF6 */  bnez      $v0, .L8003BCB4
/* 170DC 8003BCDC 26940002 */   addiu    $s4, $s4, 2
/* 170E0 8003BCE0 240200FF */  addiu     $v0, $zero, 0xff
/* 170E4 8003BCE4 16A20004 */  bne       $s5, $v0, .L8003BCF8
/* 170E8 8003BCE8 24020002 */   addiu    $v0, $zero, 2
/* 170EC 8003BCEC 96630310 */  lhu       $v1, 0x310($s3)
/* 170F0 8003BCF0 A26200B7 */  sb        $v0, 0xb7($s3)
/* 170F4 8003BCF4 A66300BC */  sh        $v1, 0xbc($s3)
.L8003BCF8:
/* 170F8 8003BCF8 826300B7 */  lb        $v1, 0xb7($s3)
/* 170FC 8003BCFC 24020002 */  addiu     $v0, $zero, 2
.L8003BD00:
/* 17100 8003BD00 10620005 */  beq       $v1, $v0, .L8003BD18
/* 17104 8003BD04 24020003 */   addiu    $v0, $zero, 3
/* 17108 8003BD08 1062000A */  beq       $v1, $v0, .L8003BD34
/* 1710C 8003BD0C 00000000 */   nop
/* 17110 8003BD10 0800EF8B */  j         .L8003BE2C
/* 17114 8003BD14 00000000 */   nop
.L8003BD18:
/* 17118 8003BD18 866200BC */  lh        $v0, 0xbc($s3)
/* 1711C 8003BD1C 966300BC */  lhu       $v1, 0xbc($s3)
/* 17120 8003BD20 14400041 */  bnez      $v0, .L8003BE28
/* 17124 8003BD24 2462FFFF */   addiu    $v0, $v1, -1
/* 17128 8003BD28 24020003 */  addiu     $v0, $zero, 3
/* 1712C 8003BD2C A66000BE */  sh        $zero, 0xbe($s3)
/* 17130 8003BD30 A26200B7 */  sb        $v0, 0xb7($s3)
.L8003BD34:
/* 17134 8003BD34 86620312 */  lh        $v0, 0x312($s3)
/* 17138 8003BD38 24036400 */  addiu     $v1, $zero, 0x6400
/* 1713C 8003BD3C 14400002 */  bnez      $v0, .L8003BD48
/* 17140 8003BD40 0062001A */   div      $zero, $v1, $v0
/* 17144 8003BD44 0007000D */  break     7
.L8003BD48:
/* 17148 8003BD48 2401FFFF */   addiu    $at, $zero, -1
/* 1714C 8003BD4C 14410004 */  bne       $v0, $at, .L8003BD60
/* 17150 8003BD50 3C018000 */   lui      $at, 0x8000
/* 17154 8003BD54 14610002 */  bne       $v1, $at, .L8003BD60
/* 17158 8003BD58 00000000 */   nop
/* 1715C 8003BD5C 0006000D */  break     6
.L8003BD60:
/* 17160 8003BD60 00001812 */   mflo     $v1
/* 17164 8003BD64 966200BE */  lhu       $v0, 0xbe($s3)
/* 17168 8003BD68 00431021 */  addu      $v0, $v0, $v1
/* 1716C 8003BD6C A66200BE */  sh        $v0, 0xbe($s3)
/* 17170 8003BD70 00021400 */  sll       $v0, $v0, 0x10
/* 17174 8003BD74 00021403 */  sra       $v0, $v0, 0x10
/* 17178 8003BD78 2842639D */  slti      $v0, $v0, 0x639d
/* 1717C 8003BD7C 14400003 */  bnez      $v0, .L8003BD8C
/* 17180 8003BD80 3C0651EB */   lui      $a2, 0x51eb
/* 17184 8003BD84 2402639C */  addiu     $v0, $zero, 0x639c
/* 17188 8003BD88 A66200BE */  sh        $v0, 0xbe($s3)
.L8003BD8C:
/* 1718C 8003BD8C 34C6851F */  ori       $a2, $a2, 0x851f
/* 17190 8003BD90 267400C8 */  addiu     $s4, $s3, 0xc8
/* 17194 8003BD94 0000802D */  daddu     $s0, $zero, $zero
/* 17198 8003BD98 8662030A */  lh        $v0, 0x30a($s3)
/* 1719C 8003BD9C 8E6500C4 */  lw        $a1, 0xc4($s3)
/* 171A0 8003BDA0 966300BE */  lhu       $v1, 0xbe($s3)
/* 171A4 8003BDA4 00021080 */  sll       $v0, $v0, 2
/* 171A8 8003BDA8 00451021 */  addu      $v0, $v0, $a1
/* 171AC 8003BDAC 00031C00 */  sll       $v1, $v1, 0x10
/* 171B0 8003BDB0 00032403 */  sra       $a0, $v1, 0x10
/* 171B4 8003BDB4 8C520000 */  lw        $s2, ($v0)
/* 171B8 8003BDB8 86620308 */  lh        $v0, 0x308($s3)
/* 171BC 8003BDBC 00860018 */  mult      $a0, $a2
/* 171C0 8003BDC0 00021080 */  sll       $v0, $v0, 2
/* 171C4 8003BDC4 00451021 */  addu      $v0, $v0, $a1
/* 171C8 8003BDC8 8C510000 */  lw        $s1, ($v0)
/* 171CC 8003BDCC 00031FC3 */  sra       $v1, $v1, 0x1f
/* 171D0 8003BDD0 AE7402C8 */  sw        $s4, 0x2c8($s3)
/* 171D4 8003BDD4 00004010 */  mfhi      $t0
/* 171D8 8003BDD8 00081143 */  sra       $v0, $t0, 5
/* 171DC 8003BDDC 00431023 */  subu      $v0, $v0, $v1
/* 171E0 8003BDE0 00021400 */  sll       $v0, $v0, 0x10
/* 171E4 8003BDE4 0002AC03 */  sra       $s5, $v0, 0x10
.L8003BDE8:
/* 171E8 8003BDE8 96440000 */  lhu       $a0, ($s2)
/* 171EC 8003BDEC 26520002 */  addiu     $s2, $s2, 2
/* 171F0 8003BDF0 96250000 */  lhu       $a1, ($s1)
/* 171F4 8003BDF4 26310002 */  addiu     $s1, $s1, 2
/* 171F8 8003BDF8 02A0302D */  daddu     $a2, $s5, $zero
/* 171FC 8003BDFC 0C00EE5B */  jal       func_8003B96C
/* 17200 8003BE00 26100001 */   addiu    $s0, $s0, 1
/* 17204 8003BE04 A6820000 */  sh        $v0, ($s4)
/* 17208 8003BE08 2A020010 */  slti      $v0, $s0, 0x10
/* 1720C 8003BE0C 1440FFF6 */  bnez      $v0, .L8003BDE8
/* 17210 8003BE10 26940002 */   addiu    $s4, $s4, 2
/* 17214 8003BE14 240200FF */  addiu     $v0, $zero, 0xff
/* 17218 8003BE18 16A20004 */  bne       $s5, $v0, .L8003BE2C
/* 1721C 8003BE1C 00000000 */   nop
/* 17220 8003BE20 9662030C */  lhu       $v0, 0x30c($s3)
/* 17224 8003BE24 A26000B7 */  sb        $zero, 0xb7($s3)
.L8003BE28:
/* 17228 8003BE28 A66200BC */  sh        $v0, 0xbc($s3)
.L8003BE2C:
/* 1722C 8003BE2C 826300B7 */  lb        $v1, 0xb7($s3)
/* 17230 8003BE30 28620004 */  slti      $v0, $v1, 4
/* 17234 8003BE34 1040001D */  beqz      $v0, .L8003BEAC
/* 17238 8003BE38 00000000 */   nop
/* 1723C 8003BE3C 0460001B */  bltz      $v1, .L8003BEAC
/* 17240 8003BE40 3C034000 */   lui      $v1, 0x4000
/* 17244 8003BE44 8E620000 */  lw        $v0, ($s3)
/* 17248 8003BE48 00431024 */  and       $v0, $v0, $v1
/* 1724C 8003BE4C 14400017 */  bnez      $v0, .L8003BEAC
/* 17250 8003BE50 02C0282D */   daddu    $a1, $s6, $zero
/* 17254 8003BE54 926300AC */  lbu       $v1, 0xac($s3)
/* 17258 8003BE58 926200AD */  lbu       $v0, 0xad($s3)
/* 1725C 8003BE5C 00620018 */  mult      $v1, $v0
/* 17260 8003BE60 00001812 */  mflo      $v1
/* 17264 8003BE64 3C028080 */  lui       $v0, 0x8080
/* 17268 8003BE68 34428081 */  ori       $v0, $v0, 0x8081
/* 1726C 8003BE6C 00620018 */  mult      $v1, $v0
/* 17270 8003BE70 8E660024 */  lw        $a2, 0x24($s3)
/* 17274 8003BE74 266702C8 */  addiu     $a3, $s3, 0x2c8
/* 17278 8003BE78 AFB70010 */  sw        $s7, 0x10($sp)
/* 1727C 8003BE7C 00004810 */  mfhi      $t1
/* 17280 8003BE80 01231021 */  addu      $v0, $t1, $v1
/* 17284 8003BE84 000211C3 */  sra       $v0, $v0, 7
/* 17288 8003BE88 00031FC3 */  sra       $v1, $v1, 0x1f
/* 1728C 8003BE8C 0043A823 */  subu      $s5, $v0, $v1
/* 17290 8003BE90 2AA400FF */  slti      $a0, $s5, 0xff
/* 17294 8003BE94 000427C0 */  sll       $a0, $a0, 0x1f
/* 17298 8003BE98 3C022000 */  lui       $v0, 0x2000
/* 1729C 8003BE9C 00822025 */  or        $a0, $a0, $v0
/* 172A0 8003BEA0 00C42025 */  or        $a0, $a2, $a0
/* 172A4 8003BEA4 0C0B78F6 */  jal       func_802DE3D8
/* 172A8 8003BEA8 02A0302D */   daddu    $a2, $s5, $zero
.L8003BEAC:
/* 172AC 8003BEAC 8FBF0038 */  lw        $ra, 0x38($sp)
/* 172B0 8003BEB0 8FB70034 */  lw        $s7, 0x34($sp)
/* 172B4 8003BEB4 8FB60030 */  lw        $s6, 0x30($sp)
/* 172B8 8003BEB8 8FB5002C */  lw        $s5, 0x2c($sp)
/* 172BC 8003BEBC 8FB40028 */  lw        $s4, 0x28($sp)
/* 172C0 8003BEC0 8FB30024 */  lw        $s3, 0x24($sp)
/* 172C4 8003BEC4 8FB20020 */  lw        $s2, 0x20($sp)
/* 172C8 8003BEC8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 172CC 8003BECC 8FB00018 */  lw        $s0, 0x18($sp)
/* 172D0 8003BED0 03E00008 */  jr        $ra
/* 172D4 8003BED4 27BD0040 */   addiu    $sp, $sp, 0x40
