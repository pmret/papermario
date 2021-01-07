.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004BA74
/* 26E74 8004BA74 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 26E78 8004BA78 AFB40028 */  sw        $s4, 0x28($sp)
/* 26E7C 8004BA7C 0080A02D */  daddu     $s4, $a0, $zero
/* 26E80 8004BA80 AFB70034 */  sw        $s7, 0x34($sp)
/* 26E84 8004BA84 00A0B82D */  daddu     $s7, $a1, $zero
/* 26E88 8004BA88 AFBF003C */  sw        $ra, 0x3c($sp)
/* 26E8C 8004BA8C AFBE0038 */  sw        $fp, 0x38($sp)
/* 26E90 8004BA90 AFB60030 */  sw        $s6, 0x30($sp)
/* 26E94 8004BA94 AFB5002C */  sw        $s5, 0x2c($sp)
/* 26E98 8004BA98 AFB30024 */  sw        $s3, 0x24($sp)
/* 26E9C 8004BA9C AFB20020 */  sw        $s2, 0x20($sp)
/* 26EA0 8004BAA0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 26EA4 8004BAA4 AFB00018 */  sw        $s0, 0x18($sp)
/* 26EA8 8004BAA8 96E20000 */  lhu       $v0, ($s7)
/* 26EAC 8004BAAC 0000402D */  daddu     $t0, $zero, $zero
/* 26EB0 8004BAB0 2445FFFF */  addiu     $a1, $v0, -1
/* 26EB4 8004BAB4 304923FF */  andi      $t1, $v0, 0x23ff
/* 26EB8 8004BAB8 0040182D */  daddu     $v1, $v0, $zero
/* 26EBC 8004BABC 30422000 */  andi      $v0, $v0, 0x2000
/* 26EC0 8004BAC0 10400020 */  beqz      $v0, .L8004BB44
/* 26EC4 8004BAC4 30A400FF */   andi     $a0, $a1, 0xff
/* 26EC8 8004BAC8 30A401FF */  andi      $a0, $a1, 0x1ff
/* 26ECC 8004BACC 2C820140 */  sltiu     $v0, $a0, 0x140
/* 26ED0 8004BAD0 10400178 */  beqz      $v0, .L8004C0B4
/* 26ED4 8004BAD4 00041880 */   sll      $v1, $a0, 2
/* 26ED8 8004BAD8 8E82002C */  lw        $v0, 0x2c($s4)
/* 26EDC 8004BADC 00439021 */  addu      $s2, $v0, $v1
/* 26EE0 8004BAE0 96420000 */  lhu       $v0, ($s2)
/* 26EE4 8004BAE4 10400173 */  beqz      $v0, .L8004C0B4
/* 26EE8 8004BAE8 24100007 */   addiu    $s0, $zero, 7
/* 26EEC 8004BAEC 3124FFFF */  andi      $a0, $t1, 0xffff
/* 26EF0 8004BAF0 24030620 */  addiu     $v1, $zero, 0x620
.L8004BAF4:
/* 26EF4 8004BAF4 02833821 */  addu      $a3, $s4, $v1
/* 26EF8 8004BAF8 94E20096 */  lhu       $v0, 0x96($a3)
/* 26EFC 8004BAFC 1044000F */  beq       $v0, $a0, .L8004BB3C
/* 26F00 8004BB00 2610FFFF */   addiu    $s0, $s0, -1
/* 26F04 8004BB04 0601FFFB */  bgez      $s0, .L8004BAF4
/* 26F08 8004BB08 2463FF54 */   addiu    $v1, $v1, -0xac
.L8004BB0C:
/* 26F0C 8004BB0C 55000038 */  bnel      $t0, $zero, .L8004BBF0
/* 26F10 8004BB10 0280202D */   daddu    $a0, $s4, $zero
/* 26F14 8004BB14 24100007 */  addiu     $s0, $zero, 7
/* 26F18 8004BB18 24030620 */  addiu     $v1, $zero, 0x620
.L8004BB1C:
/* 26F1C 8004BB1C 02833821 */  addu      $a3, $s4, $v1
/* 26F20 8004BB20 8CE20000 */  lw        $v0, ($a3)
/* 26F24 8004BB24 10400010 */  beqz      $v0, .L8004BB68
/* 26F28 8004BB28 2610FFFF */   addiu    $s0, $s0, -1
/* 26F2C 8004BB2C 0601FFFB */  bgez      $s0, .L8004BB1C
/* 26F30 8004BB30 2463FF54 */   addiu    $v1, $v1, -0xac
/* 26F34 8004BB34 08012EFA */  j         .L8004BBE8
/* 26F38 8004BB38 00000000 */   nop      
.L8004BB3C:
/* 26F3C 8004BB3C 08012EC3 */  j         .L8004BB0C
/* 26F40 8004BB40 24080001 */   addiu    $t0, $zero, 1
.L8004BB44:
/* 26F44 8004BB44 2C8200C0 */  sltiu     $v0, $a0, 0xc0
/* 26F48 8004BB48 14400031 */  bnez      $v0, .L8004BC10
/* 26F4C 8004BB4C 00000000 */   nop      
/* 26F50 8004BB50 10C00007 */  beqz      $a2, .L8004BB70
/* 26F54 8004BB54 00C0902D */   daddu    $s2, $a2, $zero
/* 26F58 8004BB58 08012EE5 */  j         .L8004BB94
/* 26F5C 8004BB5C 00000000 */   nop      
.L8004BB60:
/* 26F60 8004BB60 08012EF0 */  j         .L8004BBC0
/* 26F64 8004BB64 24080001 */   addiu    $t0, $zero, 1
.L8004BB68:
/* 26F68 8004BB68 08012EFA */  j         .L8004BBE8
/* 26F6C 8004BB6C 24080001 */   addiu    $t0, $zero, 1
.L8004BB70:
/* 26F70 8004BB70 2522FFFF */  addiu     $v0, $t1, -1
/* 26F74 8004BB74 00021203 */  sra       $v0, $v0, 8
/* 26F78 8004BB78 24420004 */  addiu     $v0, $v0, 4
/* 26F7C 8004BB7C 00021080 */  sll       $v0, $v0, 2
/* 26F80 8004BB80 02821021 */  addu      $v0, $s4, $v0
/* 26F84 8004BB84 2483FF40 */  addiu     $v1, $a0, -0xc0
/* 26F88 8004BB88 8C42000C */  lw        $v0, 0xc($v0)
/* 26F8C 8004BB8C 00031880 */  sll       $v1, $v1, 2
/* 26F90 8004BB90 00439021 */  addu      $s2, $v0, $v1
.L8004BB94:
/* 26F94 8004BB94 96420000 */  lhu       $v0, ($s2)
/* 26F98 8004BB98 10400146 */  beqz      $v0, .L8004C0B4
/* 26F9C 8004BB9C 24100007 */   addiu    $s0, $zero, 7
/* 26FA0 8004BBA0 3124FFFF */  andi      $a0, $t1, 0xffff
/* 26FA4 8004BBA4 24030620 */  addiu     $v1, $zero, 0x620
.L8004BBA8:
/* 26FA8 8004BBA8 02833821 */  addu      $a3, $s4, $v1
/* 26FAC 8004BBAC 94E20096 */  lhu       $v0, 0x96($a3)
/* 26FB0 8004BBB0 1044FFEB */  beq       $v0, $a0, .L8004BB60
/* 26FB4 8004BBB4 2610FFFF */   addiu    $s0, $s0, -1
/* 26FB8 8004BBB8 0601FFFB */  bgez      $s0, .L8004BBA8
/* 26FBC 8004BBBC 2463FF54 */   addiu    $v1, $v1, -0xac
.L8004BBC0:
/* 26FC0 8004BBC0 5500000B */  bnel      $t0, $zero, .L8004BBF0
/* 26FC4 8004BBC4 0280202D */   daddu    $a0, $s4, $zero
/* 26FC8 8004BBC8 24100007 */  addiu     $s0, $zero, 7
/* 26FCC 8004BBCC 24030620 */  addiu     $v1, $zero, 0x620
.L8004BBD0:
/* 26FD0 8004BBD0 02833821 */  addu      $a3, $s4, $v1
/* 26FD4 8004BBD4 8CE20000 */  lw        $v0, ($a3)
/* 26FD8 8004BBD8 1040FFE3 */  beqz      $v0, .L8004BB68
/* 26FDC 8004BBDC 2610FFFF */   addiu    $s0, $s0, -1
/* 26FE0 8004BBE0 0601FFFB */  bgez      $s0, .L8004BBD0
/* 26FE4 8004BBE4 2463FF54 */   addiu    $v1, $v1, -0xac
.L8004BBE8:
/* 26FE8 8004BBE8 11000132 */  beqz      $t0, .L8004C0B4
/* 26FEC 8004BBEC 0280202D */   daddu    $a0, $s4, $zero
.L8004BBF0:
/* 26FF0 8004BBF0 00E0282D */  daddu     $a1, $a3, $zero
/* 26FF4 8004BBF4 0240302D */  daddu     $a2, $s2, $zero
/* 26FF8 8004BBF8 02E0382D */  daddu     $a3, $s7, $zero
/* 26FFC 8004BBFC AFA00010 */  sw        $zero, 0x10($sp)
/* 27000 8004BC00 0C013039 */  jal       func_8004C0E4
/* 27004 8004BC04 AFA00014 */   sw       $zero, 0x14($sp)
/* 27008 8004BC08 0801302D */  j         .L8004C0B4
/* 2700C 8004BC0C 00000000 */   nop      
.L8004BC10:
/* 27010 8004BC10 10C00005 */  beqz      $a2, .L8004BC28
/* 27014 8004BC14 00C0902D */   daddu    $s2, $a2, $zero
/* 27018 8004BC18 08012F10 */  j         .L8004BC40
/* 2701C 8004BC1C 00000000 */   nop      
.L8004BC20:
/* 27020 8004BC20 08012F28 */  j         .L8004BCA0
/* 27024 8004BC24 24080001 */   addiu    $t0, $zero, 1
.L8004BC28:
/* 27028 8004BC28 00031182 */  srl       $v0, $v1, 6
/* 2702C 8004BC2C 3042000C */  andi      $v0, $v0, 0xc
/* 27030 8004BC30 02821021 */  addu      $v0, $s4, $v0
/* 27034 8004BC34 8C43000C */  lw        $v1, 0xc($v0)
/* 27038 8004BC38 00041080 */  sll       $v0, $a0, 2
/* 2703C 8004BC3C 00629021 */  addu      $s2, $v1, $v0
.L8004BC40:
/* 27040 8004BC40 96420000 */  lhu       $v0, ($s2)
/* 27044 8004BC44 1040011B */  beqz      $v0, .L8004C0B4
/* 27048 8004BC48 00000000 */   nop      
/* 2704C 8004BC4C 96440002 */  lhu       $a0, 2($s2)
/* 27050 8004BC50 30820300 */  andi      $v0, $a0, 0x300
/* 27054 8004BC54 0002AA02 */  srl       $s5, $v0, 8
/* 27058 8004BC58 30820060 */  andi      $v0, $a0, 0x60
/* 2705C 8004BC5C 00028142 */  srl       $s0, $v0, 5
/* 27060 8004BC60 30820080 */  andi      $v0, $a0, 0x80
/* 27064 8004BC64 1600007F */  bnez      $s0, .L8004BE64
/* 27068 8004BC68 000299C2 */   srl      $s3, $v0, 7
/* 2706C 8004BC6C 96E20002 */  lhu       $v0, 2($s7)
/* 27070 8004BC70 1040000B */  beqz      $v0, .L8004BCA0
/* 27074 8004BC74 00000000 */   nop      
/* 27078 8004BC78 0000802D */  daddu     $s0, $zero, $zero
/* 2707C 8004BC7C 0040282D */  daddu     $a1, $v0, $zero
/* 27080 8004BC80 2403016C */  addiu     $v1, $zero, 0x16c
.L8004BC84:
/* 27084 8004BC84 02833821 */  addu      $a3, $s4, $v1
/* 27088 8004BC88 94E20096 */  lhu       $v0, 0x96($a3)
/* 2708C 8004BC8C 1045FFE4 */  beq       $v0, $a1, .L8004BC20
/* 27090 8004BC90 26100001 */   addiu    $s0, $s0, 1
/* 27094 8004BC94 2A020008 */  slti      $v0, $s0, 8
/* 27098 8004BC98 1440FFFA */  bnez      $v0, .L8004BC84
/* 2709C 8004BC9C 246300AC */   addiu    $v1, $v1, 0xac
.L8004BCA0:
/* 270A0 8004BCA0 1660001C */  bnez      $s3, .L8004BD14
/* 270A4 8004BCA4 00000000 */   nop      
/* 270A8 8004BCA8 55000064 */  bnel      $t0, $zero, .L8004BE3C
/* 270AC 8004BCAC 0280202D */   daddu    $a0, $s4, $zero
/* 270B0 8004BCB0 30900007 */  andi      $s0, $a0, 7
/* 270B4 8004BCB4 00101040 */  sll       $v0, $s0, 1
/* 270B8 8004BCB8 00501021 */  addu      $v0, $v0, $s0
/* 270BC 8004BCBC 00021080 */  sll       $v0, $v0, 2
/* 270C0 8004BCC0 00501023 */  subu      $v0, $v0, $s0
/* 270C4 8004BCC4 00021080 */  sll       $v0, $v0, 2
/* 270C8 8004BCC8 00501023 */  subu      $v0, $v0, $s0
/* 270CC 8004BCCC 00021080 */  sll       $v0, $v0, 2
/* 270D0 8004BCD0 2442016C */  addiu     $v0, $v0, 0x16c
/* 270D4 8004BCD4 02823821 */  addu      $a3, $s4, $v0
/* 270D8 8004BCD8 8CE20000 */  lw        $v0, ($a3)
/* 270DC 8004BCDC 10400057 */  beqz      $v0, .L8004BE3C
/* 270E0 8004BCE0 0280202D */   daddu    $a0, $s4, $zero
/* 270E4 8004BCE4 90E20098 */  lbu       $v0, 0x98($a3)
/* 270E8 8004BCE8 02A2102B */  sltu      $v0, $s5, $v0
/* 270EC 8004BCEC 10400054 */  beqz      $v0, .L8004BE40
/* 270F0 8004BCF0 00E0282D */   daddu    $a1, $a3, $zero
/* 270F4 8004BCF4 0801302D */  j         .L8004C0B4
/* 270F8 8004BCF8 00000000 */   nop      
.L8004BCFC:
/* 270FC 8004BCFC 08012F58 */  j         .L8004BD60
/* 27100 8004BD00 24080001 */   addiu    $t0, $zero, 1
.L8004BD04:
/* 27104 8004BD04 08012F6A */  j         .L8004BDA8
/* 27108 8004BD08 24080001 */   addiu    $t0, $zero, 1
.L8004BD0C:
/* 2710C 8004BD0C 08012F7D */  j         .L8004BDF4
/* 27110 8004BD10 24080001 */   addiu    $t0, $zero, 1
.L8004BD14:
/* 27114 8004BD14 55000049 */  bnel      $t0, $zero, .L8004BE3C
/* 27118 8004BD18 0280202D */   daddu    $a0, $s4, $zero
/* 2711C 8004BD1C 30900007 */  andi      $s0, $a0, 7
/* 27120 8004BD20 0600000F */  bltz      $s0, .L8004BD60
/* 27124 8004BD24 00101040 */   sll      $v0, $s0, 1
/* 27128 8004BD28 3125FFFF */  andi      $a1, $t1, 0xffff
/* 2712C 8004BD2C 00501021 */  addu      $v0, $v0, $s0
/* 27130 8004BD30 00021080 */  sll       $v0, $v0, 2
/* 27134 8004BD34 00501023 */  subu      $v0, $v0, $s0
/* 27138 8004BD38 00021080 */  sll       $v0, $v0, 2
/* 2713C 8004BD3C 00501023 */  subu      $v0, $v0, $s0
/* 27140 8004BD40 00021080 */  sll       $v0, $v0, 2
/* 27144 8004BD44 2443016C */  addiu     $v1, $v0, 0x16c
.L8004BD48:
/* 27148 8004BD48 02833821 */  addu      $a3, $s4, $v1
/* 2714C 8004BD4C 94E20096 */  lhu       $v0, 0x96($a3)
/* 27150 8004BD50 1045FFEA */  beq       $v0, $a1, .L8004BCFC
/* 27154 8004BD54 2610FFFF */   addiu    $s0, $s0, -1
/* 27158 8004BD58 0601FFFB */  bgez      $s0, .L8004BD48
/* 2715C 8004BD5C 2463FF54 */   addiu    $v1, $v1, -0xac
.L8004BD60:
/* 27160 8004BD60 55000036 */  bnel      $t0, $zero, .L8004BE3C
/* 27164 8004BD64 0280202D */   daddu    $a0, $s4, $zero
/* 27168 8004BD68 30900007 */  andi      $s0, $a0, 7
/* 2716C 8004BD6C 0600000E */  bltz      $s0, .L8004BDA8
/* 27170 8004BD70 00101040 */   sll      $v0, $s0, 1
/* 27174 8004BD74 00501021 */  addu      $v0, $v0, $s0
/* 27178 8004BD78 00021080 */  sll       $v0, $v0, 2
/* 2717C 8004BD7C 00501023 */  subu      $v0, $v0, $s0
/* 27180 8004BD80 00021080 */  sll       $v0, $v0, 2
/* 27184 8004BD84 00501023 */  subu      $v0, $v0, $s0
/* 27188 8004BD88 00021080 */  sll       $v0, $v0, 2
/* 2718C 8004BD8C 2443016C */  addiu     $v1, $v0, 0x16c
.L8004BD90:
/* 27190 8004BD90 02833821 */  addu      $a3, $s4, $v1
/* 27194 8004BD94 8CE20000 */  lw        $v0, ($a3)
/* 27198 8004BD98 1040FFDA */  beqz      $v0, .L8004BD04
/* 2719C 8004BD9C 2610FFFF */   addiu    $s0, $s0, -1
/* 271A0 8004BDA0 0601FFFB */  bgez      $s0, .L8004BD90
/* 271A4 8004BDA4 2463FF54 */   addiu    $v1, $v1, -0xac
.L8004BDA8:
/* 271A8 8004BDA8 55000024 */  bnel      $t0, $zero, .L8004BE3C
/* 271AC 8004BDAC 0280202D */   daddu    $a0, $s4, $zero
/* 271B0 8004BDB0 30900007 */  andi      $s0, $a0, 7
/* 271B4 8004BDB4 0600000F */  bltz      $s0, .L8004BDF4
/* 271B8 8004BDB8 00101040 */   sll      $v0, $s0, 1
/* 271BC 8004BDBC 00501021 */  addu      $v0, $v0, $s0
/* 271C0 8004BDC0 00021080 */  sll       $v0, $v0, 2
/* 271C4 8004BDC4 00501023 */  subu      $v0, $v0, $s0
/* 271C8 8004BDC8 00021080 */  sll       $v0, $v0, 2
/* 271CC 8004BDCC 00501023 */  subu      $v0, $v0, $s0
/* 271D0 8004BDD0 00021080 */  sll       $v0, $v0, 2
/* 271D4 8004BDD4 2443016C */  addiu     $v1, $v0, 0x16c
.L8004BDD8:
/* 271D8 8004BDD8 02833821 */  addu      $a3, $s4, $v1
/* 271DC 8004BDDC 90E20098 */  lbu       $v0, 0x98($a3)
/* 271E0 8004BDE0 0055102B */  sltu      $v0, $v0, $s5
/* 271E4 8004BDE4 1440FFC9 */  bnez      $v0, .L8004BD0C
/* 271E8 8004BDE8 2610FFFF */   addiu    $s0, $s0, -1
/* 271EC 8004BDEC 0601FFFA */  bgez      $s0, .L8004BDD8
/* 271F0 8004BDF0 2463FF54 */   addiu    $v1, $v1, -0xac
.L8004BDF4:
/* 271F4 8004BDF4 55000011 */  bnel      $t0, $zero, .L8004BE3C
/* 271F8 8004BDF8 0280202D */   daddu    $a0, $s4, $zero
/* 271FC 8004BDFC 30900007 */  andi      $s0, $a0, 7
/* 27200 8004BE00 00101040 */  sll       $v0, $s0, 1
/* 27204 8004BE04 00501021 */  addu      $v0, $v0, $s0
/* 27208 8004BE08 00021080 */  sll       $v0, $v0, 2
/* 2720C 8004BE0C 00501023 */  subu      $v0, $v0, $s0
/* 27210 8004BE10 00021080 */  sll       $v0, $v0, 2
/* 27214 8004BE14 00501023 */  subu      $v0, $v0, $s0
/* 27218 8004BE18 00021080 */  sll       $v0, $v0, 2
/* 2721C 8004BE1C 2442016C */  addiu     $v0, $v0, 0x16c
/* 27220 8004BE20 02823821 */  addu      $a3, $s4, $v0
/* 27224 8004BE24 90E20098 */  lbu       $v0, 0x98($a3)
/* 27228 8004BE28 02A2102B */  sltu      $v0, $s5, $v0
/* 2722C 8004BE2C 50400001 */  beql      $v0, $zero, .L8004BE34
/* 27230 8004BE30 24080001 */   addiu    $t0, $zero, 1
.L8004BE34:
/* 27234 8004BE34 1100009F */  beqz      $t0, .L8004C0B4
/* 27238 8004BE38 0280202D */   daddu    $a0, $s4, $zero
.L8004BE3C:
/* 2723C 8004BE3C 00E0282D */  daddu     $a1, $a3, $zero
.L8004BE40:
/* 27240 8004BE40 96420000 */  lhu       $v0, ($s2)
/* 27244 8004BE44 8C860008 */  lw        $a2, 8($a0)
/* 27248 8004BE48 02E0382D */  daddu     $a3, $s7, $zero
/* 2724C 8004BE4C AFB50010 */  sw        $s5, 0x10($sp)
/* 27250 8004BE50 AFA00014 */  sw        $zero, 0x14($sp)
/* 27254 8004BE54 0C013039 */  jal       func_8004C0E4
/* 27258 8004BE58 00463021 */   addu     $a2, $v0, $a2
/* 2725C 8004BE5C 0801302D */  j         .L8004C0B4
/* 27260 8004BE60 00000000 */   nop      
.L8004BE64:
/* 27264 8004BE64 96420000 */  lhu       $v0, ($s2)
/* 27268 8004BE68 8E830008 */  lw        $v1, 8($s4)
/* 2726C 8004BE6C 00439021 */  addu      $s2, $v0, $v1
/* 27270 8004BE70 30821800 */  andi      $v0, $a0, 0x1800
/* 27274 8004BE74 0002B2C2 */  srl       $s6, $v0, 0xb
/* 27278 8004BE78 12C00005 */  beqz      $s6, .L8004BE90
/* 2727C 8004BE7C 0280202D */   daddu    $a0, $s4, $zero
/* 27280 8004BE80 0C0130C0 */  jal       func_8004C300
/* 27284 8004BE84 02C0282D */   daddu    $a1, $s6, $zero
/* 27288 8004BE88 08012FA8 */  j         .L8004BEA0
/* 2728C 8004BE8C 2603FFFF */   addiu    $v1, $s0, -1
.L8004BE90:
/* 27290 8004BE90 96E50000 */  lhu       $a1, ($s7)
/* 27294 8004BE94 0C0130A9 */  jal       func_8004C2A4
/* 27298 8004BE98 0280202D */   daddu    $a0, $s4, $zero
/* 2729C 8004BE9C 2603FFFF */  addiu     $v1, $s0, -1
.L8004BEA0:
/* 272A0 8004BEA0 24020002 */  addiu     $v0, $zero, 2
/* 272A4 8004BEA4 1260005D */  beqz      $s3, .L8004C01C
/* 272A8 8004BEA8 00628804 */   sllv     $s1, $v0, $v1
/* 272AC 8004BEAC 24100007 */  addiu     $s0, $zero, 7
/* 272B0 8004BEB0 3C1E8008 */  lui       $fp, %hi(D_80078464)
/* 272B4 8004BEB4 27DE8464 */  addiu     $fp, $fp, %lo(D_80078464)
/* 272B8 8004BEB8 24130620 */  addiu     $s3, $zero, 0x620
.L8004BEBC:
/* 272BC 8004BEBC 96420000 */  lhu       $v0, ($s2)
/* 272C0 8004BEC0 10400010 */  beqz      $v0, .L8004BF04
/* 272C4 8004BEC4 02933821 */   addu     $a3, $s4, $s3
/* 272C8 8004BEC8 8CE20000 */  lw        $v0, ($a3)
/* 272CC 8004BECC 545E0011 */  bnel      $v0, $fp, .L8004BF14
/* 272D0 8004BED0 2610FFFF */   addiu    $s0, $s0, -1
/* 272D4 8004BED4 0280202D */  daddu     $a0, $s4, $zero
/* 272D8 8004BED8 00E0282D */  daddu     $a1, $a3, $zero
/* 272DC 8004BEDC 02E0382D */  daddu     $a3, $s7, $zero
/* 272E0 8004BEE0 96420000 */  lhu       $v0, ($s2)
/* 272E4 8004BEE4 8E860008 */  lw        $a2, 8($s4)
/* 272E8 8004BEE8 2631FFFF */  addiu     $s1, $s1, -1
/* 272EC 8004BEEC AFB50010 */  sw        $s5, 0x10($sp)
/* 272F0 8004BEF0 AFB60014 */  sw        $s6, 0x14($sp)
/* 272F4 8004BEF4 0C013039 */  jal       func_8004C0E4
/* 272F8 8004BEF8 00463021 */   addu     $a2, $v0, $a2
/* 272FC 8004BEFC 08012FC2 */  j         .L8004BF08
/* 27300 8004BF00 00000000 */   nop      
.L8004BF04:
/* 27304 8004BF04 2631FFFF */  addiu     $s1, $s1, -1
.L8004BF08:
/* 27308 8004BF08 1A200004 */  blez      $s1, .L8004BF1C
/* 2730C 8004BF0C 2610FFFF */   addiu    $s0, $s0, -1
/* 27310 8004BF10 26520004 */  addiu     $s2, $s2, 4
.L8004BF14:
/* 27314 8004BF14 0601FFE9 */  bgez      $s0, .L8004BEBC
/* 27318 8004BF18 2673FF54 */   addiu    $s3, $s3, -0xac
.L8004BF1C:
/* 2731C 8004BF1C 12200065 */  beqz      $s1, .L8004C0B4
/* 27320 8004BF20 24100007 */   addiu    $s0, $zero, 7
/* 27324 8004BF24 24130620 */  addiu     $s3, $zero, 0x620
.L8004BF28:
/* 27328 8004BF28 96420000 */  lhu       $v0, ($s2)
/* 2732C 8004BF2C 10400013 */  beqz      $v0, .L8004BF7C
/* 27330 8004BF30 02933821 */   addu     $a3, $s4, $s3
/* 27334 8004BF34 8CE20000 */  lw        $v0, ($a3)
/* 27338 8004BF38 5440000E */  bnel      $v0, $zero, .L8004BF74
/* 2733C 8004BF3C 2673FF54 */   addiu    $s3, $s3, -0xac
/* 27340 8004BF40 0280202D */  daddu     $a0, $s4, $zero
/* 27344 8004BF44 00E0282D */  daddu     $a1, $a3, $zero
/* 27348 8004BF48 02E0382D */  daddu     $a3, $s7, $zero
/* 2734C 8004BF4C 96420000 */  lhu       $v0, ($s2)
/* 27350 8004BF50 8E860008 */  lw        $a2, 8($s4)
/* 27354 8004BF54 2631FFFF */  addiu     $s1, $s1, -1
/* 27358 8004BF58 AFB50010 */  sw        $s5, 0x10($sp)
/* 2735C 8004BF5C AFB60014 */  sw        $s6, 0x14($sp)
/* 27360 8004BF60 0C013039 */  jal       func_8004C0E4
/* 27364 8004BF64 00463021 */   addu     $a2, $v0, $a2
/* 27368 8004BF68 1A20000A */  blez      $s1, .L8004BF94
/* 2736C 8004BF6C 2673FF54 */   addiu    $s3, $s3, -0xac
/* 27370 8004BF70 26520004 */  addiu     $s2, $s2, 4
.L8004BF74:
/* 27374 8004BF74 08012FE3 */  j         .L8004BF8C
/* 27378 8004BF78 2610FFFF */   addiu    $s0, $s0, -1
.L8004BF7C:
/* 2737C 8004BF7C 2631FFFF */  addiu     $s1, $s1, -1
/* 27380 8004BF80 1A200004 */  blez      $s1, .L8004BF94
/* 27384 8004BF84 00000000 */   nop      
/* 27388 8004BF88 26520004 */  addiu     $s2, $s2, 4
.L8004BF8C:
/* 2738C 8004BF8C 0601FFE6 */  bgez      $s0, .L8004BF28
/* 27390 8004BF90 00000000 */   nop      
.L8004BF94:
/* 27394 8004BF94 12200047 */  beqz      $s1, .L8004C0B4
/* 27398 8004BF98 24100007 */   addiu    $s0, $zero, 7
/* 2739C 8004BF9C 24130620 */  addiu     $s3, $zero, 0x620
.L8004BFA0:
/* 273A0 8004BFA0 96420000 */  lhu       $v0, ($s2)
/* 273A4 8004BFA4 10400015 */  beqz      $v0, .L8004BFFC
/* 273A8 8004BFA8 02933821 */   addu     $a3, $s4, $s3
/* 273AC 8004BFAC 90E20099 */  lbu       $v0, 0x99($a3)
/* 273B0 8004BFB0 0056102B */  sltu      $v0, $v0, $s6
/* 273B4 8004BFB4 50400015 */  beql      $v0, $zero, .L8004C00C
/* 273B8 8004BFB8 2610FFFF */   addiu    $s0, $s0, -1
/* 273BC 8004BFBC 90E20098 */  lbu       $v0, 0x98($a3)
/* 273C0 8004BFC0 02A2102B */  sltu      $v0, $s5, $v0
/* 273C4 8004BFC4 54400011 */  bnel      $v0, $zero, .L8004C00C
/* 273C8 8004BFC8 2610FFFF */   addiu    $s0, $s0, -1
/* 273CC 8004BFCC 0280202D */  daddu     $a0, $s4, $zero
/* 273D0 8004BFD0 00E0282D */  daddu     $a1, $a3, $zero
/* 273D4 8004BFD4 02E0382D */  daddu     $a3, $s7, $zero
/* 273D8 8004BFD8 96420000 */  lhu       $v0, ($s2)
/* 273DC 8004BFDC 8E860008 */  lw        $a2, 8($s4)
/* 273E0 8004BFE0 2631FFFF */  addiu     $s1, $s1, -1
/* 273E4 8004BFE4 AFB50010 */  sw        $s5, 0x10($sp)
/* 273E8 8004BFE8 AFB60014 */  sw        $s6, 0x14($sp)
/* 273EC 8004BFEC 0C013039 */  jal       func_8004C0E4
/* 273F0 8004BFF0 00463021 */   addu     $a2, $v0, $a2
/* 273F4 8004BFF4 08013000 */  j         .L8004C000
/* 273F8 8004BFF8 00000000 */   nop      
.L8004BFFC:
/* 273FC 8004BFFC 2631FFFF */  addiu     $s1, $s1, -1
.L8004C000:
/* 27400 8004C000 1A20002C */  blez      $s1, .L8004C0B4
/* 27404 8004C004 26520004 */   addiu    $s2, $s2, 4
/* 27408 8004C008 2610FFFF */  addiu     $s0, $s0, -1
.L8004C00C:
/* 2740C 8004C00C 0601FFE4 */  bgez      $s0, .L8004BFA0
/* 27410 8004C010 2673FF54 */   addiu    $s3, $s3, -0xac
/* 27414 8004C014 0801302D */  j         .L8004C0B4
/* 27418 8004C018 00000000 */   nop      
.L8004C01C:
/* 2741C 8004C01C 1A200025 */  blez      $s1, .L8004C0B4
/* 27420 8004C020 0000982D */   daddu    $s3, $zero, $zero
.L8004C024:
/* 27424 8004C024 96420000 */  lhu       $v0, ($s2)
/* 27428 8004C028 5040001F */  beql      $v0, $zero, .L8004C0A8
/* 2742C 8004C02C 26730001 */   addiu    $s3, $s3, 1
/* 27430 8004C030 96440002 */  lhu       $a0, 2($s2)
/* 27434 8004C034 30900007 */  andi      $s0, $a0, 7
/* 27438 8004C038 00101040 */  sll       $v0, $s0, 1
/* 2743C 8004C03C 00501021 */  addu      $v0, $v0, $s0
/* 27440 8004C040 00021080 */  sll       $v0, $v0, 2
/* 27444 8004C044 00501023 */  subu      $v0, $v0, $s0
/* 27448 8004C048 00021080 */  sll       $v0, $v0, 2
/* 2744C 8004C04C 00501023 */  subu      $v0, $v0, $s0
/* 27450 8004C050 00021080 */  sll       $v0, $v0, 2
/* 27454 8004C054 2442016C */  addiu     $v0, $v0, 0x16c
/* 27458 8004C058 02823821 */  addu      $a3, $s4, $v0
/* 2745C 8004C05C 30820300 */  andi      $v0, $a0, 0x300
/* 27460 8004C060 8CE30000 */  lw        $v1, ($a3)
/* 27464 8004C064 10600005 */  beqz      $v1, .L8004C07C
/* 27468 8004C068 0002AA02 */   srl      $s5, $v0, 8
/* 2746C 8004C06C 90E20098 */  lbu       $v0, 0x98($a3)
/* 27470 8004C070 02A2102B */  sltu      $v0, $s5, $v0
/* 27474 8004C074 5440000B */  bnel      $v0, $zero, .L8004C0A4
/* 27478 8004C078 26520004 */   addiu    $s2, $s2, 4
.L8004C07C:
/* 2747C 8004C07C 0280202D */  daddu     $a0, $s4, $zero
/* 27480 8004C080 00E0282D */  daddu     $a1, $a3, $zero
/* 27484 8004C084 96420000 */  lhu       $v0, ($s2)
/* 27488 8004C088 8E860008 */  lw        $a2, 8($s4)
/* 2748C 8004C08C 02E0382D */  daddu     $a3, $s7, $zero
/* 27490 8004C090 AFB50010 */  sw        $s5, 0x10($sp)
/* 27494 8004C094 AFB60014 */  sw        $s6, 0x14($sp)
/* 27498 8004C098 0C013039 */  jal       func_8004C0E4
/* 2749C 8004C09C 00463021 */   addu     $a2, $v0, $a2
/* 274A0 8004C0A0 26520004 */  addiu     $s2, $s2, 4
.L8004C0A4:
/* 274A4 8004C0A4 26730001 */  addiu     $s3, $s3, 1
.L8004C0A8:
/* 274A8 8004C0A8 0271102A */  slt       $v0, $s3, $s1
/* 274AC 8004C0AC 1440FFDD */  bnez      $v0, .L8004C024
/* 274B0 8004C0B0 00000000 */   nop      
.L8004C0B4:
/* 274B4 8004C0B4 8FBF003C */  lw        $ra, 0x3c($sp)
/* 274B8 8004C0B8 8FBE0038 */  lw        $fp, 0x38($sp)
/* 274BC 8004C0BC 8FB70034 */  lw        $s7, 0x34($sp)
/* 274C0 8004C0C0 8FB60030 */  lw        $s6, 0x30($sp)
/* 274C4 8004C0C4 8FB5002C */  lw        $s5, 0x2c($sp)
/* 274C8 8004C0C8 8FB40028 */  lw        $s4, 0x28($sp)
/* 274CC 8004C0CC 8FB30024 */  lw        $s3, 0x24($sp)
/* 274D0 8004C0D0 8FB20020 */  lw        $s2, 0x20($sp)
/* 274D4 8004C0D4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 274D8 8004C0D8 8FB00018 */  lw        $s0, 0x18($sp)
/* 274DC 8004C0DC 03E00008 */  jr        $ra
/* 274E0 8004C0E0 27BD0040 */   addiu    $sp, $sp, 0x40
