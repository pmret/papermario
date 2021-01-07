.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011FA54
/* B6154 8011FA54 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B6158 8011FA58 AFB60030 */  sw        $s6, 0x30($sp)
/* B615C 8011FA5C 00A0B02D */  daddu     $s6, $a1, $zero
/* B6160 8011FA60 AFBF003C */  sw        $ra, 0x3c($sp)
/* B6164 8011FA64 AFBE0038 */  sw        $fp, 0x38($sp)
/* B6168 8011FA68 AFB70034 */  sw        $s7, 0x34($sp)
/* B616C 8011FA6C AFB5002C */  sw        $s5, 0x2c($sp)
/* B6170 8011FA70 AFB40028 */  sw        $s4, 0x28($sp)
/* B6174 8011FA74 AFB30024 */  sw        $s3, 0x24($sp)
/* B6178 8011FA78 AFB20020 */  sw        $s2, 0x20($sp)
/* B617C 8011FA7C AFB1001C */  sw        $s1, 0x1c($sp)
/* B6180 8011FA80 AFB00018 */  sw        $s0, 0x18($sp)
/* B6184 8011FA84 AFA40040 */  sw        $a0, 0x40($sp)
/* B6188 8011FA88 96C200F4 */  lhu       $v0, 0xf4($s6)
/* B618C 8011FA8C 30420080 */  andi      $v0, $v0, 0x80
/* B6190 8011FA90 10400015 */  beqz      $v0, .L8011FAE8
/* B6194 8011FA94 00C0982D */   daddu    $s3, $a2, $zero
/* B6198 8011FA98 0000882D */  daddu     $s1, $zero, $zero
/* B619C 8011FA9C 26D200B4 */  addiu     $s2, $s6, 0xb4
/* B61A0 8011FAA0 02C0802D */  daddu     $s0, $s6, $zero
.L8011FAA4:
/* B61A4 8011FAA4 8E020004 */  lw        $v0, 4($s0)
/* B61A8 8011FAA8 5040000A */  beql      $v0, $zero, .L8011FAD4
/* B61AC 8011FAAC 26310001 */   addiu    $s1, $s1, 1
/* B61B0 8011FAB0 0240202D */  daddu     $a0, $s2, $zero
/* B61B4 8011FAB4 0260282D */  daddu     $a1, $s3, $zero
/* B61B8 8011FAB8 0C019D80 */  jal       guMtxCatF
/* B61BC 8011FABC 0240302D */   daddu    $a2, $s2, $zero
/* B61C0 8011FAC0 8FA40040 */  lw        $a0, 0x40($sp)
/* B61C4 8011FAC4 8E050004 */  lw        $a1, 4($s0)
/* B61C8 8011FAC8 0C047E95 */  jal       func_8011FA54
/* B61CC 8011FACC 0240302D */   daddu    $a2, $s2, $zero
/* B61D0 8011FAD0 26310001 */  addiu     $s1, $s1, 1
.L8011FAD4:
/* B61D4 8011FAD4 2A220020 */  slti      $v0, $s1, 0x20
/* B61D8 8011FAD8 1440FFF2 */  bnez      $v0, .L8011FAA4
/* B61DC 8011FADC 26100004 */   addiu    $s0, $s0, 4
/* B61E0 8011FAE0 08047FD1 */  j         .L8011FF44
/* B61E4 8011FAE4 00000000 */   nop      
.L8011FAE8:
/* B61E8 8011FAE8 26D000B4 */  addiu     $s0, $s6, 0xb4
/* B61EC 8011FAEC 0200202D */  daddu     $a0, $s0, $zero
/* B61F0 8011FAF0 0260282D */  daddu     $a1, $s3, $zero
/* B61F4 8011FAF4 0C019D80 */  jal       guMtxCatF
/* B61F8 8011FAF8 0200302D */   daddu    $a2, $s0, $zero
/* B61FC 8011FAFC 3C120001 */  lui       $s2, 1
/* B6200 8011FB00 36521630 */  ori       $s2, $s2, 0x1630
/* B6204 8011FB04 0200202D */  daddu     $a0, $s0, $zero
/* B6208 8011FB08 3C108007 */  lui       $s0, %hi(D_800741F0)
/* B620C 8011FB0C 261041F0 */  addiu     $s0, $s0, %lo(D_800741F0)
/* B6210 8011FB10 3C11800A */  lui       $s1, %hi(D_8009A674)
/* B6214 8011FB14 2631A674 */  addiu     $s1, $s1, %lo(D_8009A674)
/* B6218 8011FB18 96050000 */  lhu       $a1, ($s0)
/* B621C 8011FB1C 8E220000 */  lw        $v0, ($s1)
/* B6220 8011FB20 00052980 */  sll       $a1, $a1, 6
/* B6224 8011FB24 00B22821 */  addu      $a1, $a1, $s2
/* B6228 8011FB28 0C019D40 */  jal       guMtxF2L
/* B622C 8011FB2C 00452821 */   addu     $a1, $v0, $a1
/* B6230 8011FB30 3C03DA38 */  lui       $v1, 0xda38
/* B6234 8011FB34 34630003 */  ori       $v1, $v1, 3
/* B6238 8011FB38 3C05E300 */  lui       $a1, 0xe300
/* B623C 8011FB3C 34A50F00 */  ori       $a1, $a1, 0xf00
/* B6240 8011FB40 3C06E300 */  lui       $a2, 0xe300
/* B6244 8011FB44 34C61001 */  ori       $a2, $a2, 0x1001
/* B6248 8011FB48 3C07D9FD */  lui       $a3, 0xd9fd
/* B624C 8011FB4C 3C09800A */  lui       $t1, %hi(D_8009A66C)
/* B6250 8011FB50 2529A66C */  addiu     $t1, $t1, %lo(D_8009A66C)
/* B6254 8011FB54 34E7FFFF */  ori       $a3, $a3, 0xffff
/* B6258 8011FB58 8D280000 */  lw        $t0, ($t1)
/* B625C 8011FB5C 96020000 */  lhu       $v0, ($s0)
/* B6260 8011FB60 0100202D */  daddu     $a0, $t0, $zero
/* B6264 8011FB64 25080008 */  addiu     $t0, $t0, 8
/* B6268 8011FB68 AD280000 */  sw        $t0, ($t1)
/* B626C 8011FB6C AC830000 */  sw        $v1, ($a0)
/* B6270 8011FB70 24430001 */  addiu     $v1, $v0, 1
/* B6274 8011FB74 3042FFFF */  andi      $v0, $v0, 0xffff
/* B6278 8011FB78 00021180 */  sll       $v0, $v0, 6
/* B627C 8011FB7C A6030000 */  sh        $v1, ($s0)
/* B6280 8011FB80 8E230000 */  lw        $v1, ($s1)
/* B6284 8011FB84 00521021 */  addu      $v0, $v0, $s2
/* B6288 8011FB88 00621821 */  addu      $v1, $v1, $v0
/* B628C 8011FB8C 25020008 */  addiu     $v0, $t0, 8
/* B6290 8011FB90 AC830004 */  sw        $v1, 4($a0)
/* B6294 8011FB94 AD220000 */  sw        $v0, ($t1)
/* B6298 8011FB98 3C02E700 */  lui       $v0, 0xe700
/* B629C 8011FB9C AD020000 */  sw        $v0, ($t0)
/* B62A0 8011FBA0 25020010 */  addiu     $v0, $t0, 0x10
/* B62A4 8011FBA4 AD000004 */  sw        $zero, 4($t0)
/* B62A8 8011FBA8 AD220000 */  sw        $v0, ($t1)
/* B62AC 8011FBAC 3C02D700 */  lui       $v0, 0xd700
/* B62B0 8011FBB0 AD020008 */  sw        $v0, 8($t0)
/* B62B4 8011FBB4 25020018 */  addiu     $v0, $t0, 0x18
/* B62B8 8011FBB8 AD00000C */  sw        $zero, 0xc($t0)
/* B62BC 8011FBBC AD220000 */  sw        $v0, ($t1)
/* B62C0 8011FBC0 25020020 */  addiu     $v0, $t0, 0x20
/* B62C4 8011FBC4 AD050010 */  sw        $a1, 0x10($t0)
/* B62C8 8011FBC8 AD000014 */  sw        $zero, 0x14($t0)
/* B62CC 8011FBCC AD220000 */  sw        $v0, ($t1)
/* B62D0 8011FBD0 25020028 */  addiu     $v0, $t0, 0x28
/* B62D4 8011FBD4 AD060018 */  sw        $a2, 0x18($t0)
/* B62D8 8011FBD8 AD00001C */  sw        $zero, 0x1c($t0)
/* B62DC 8011FBDC AD220000 */  sw        $v0, ($t1)
/* B62E0 8011FBE0 AD070020 */  sw        $a3, 0x20($t0)
/* B62E4 8011FBE4 AD000024 */  sw        $zero, 0x24($t0)
/* B62E8 8011FBE8 8FAA0040 */  lw        $t2, 0x40($sp)
/* B62EC 8011FBEC 8D420000 */  lw        $v0, ($t2)
/* B62F0 8011FBF0 3C030001 */  lui       $v1, 1
/* B62F4 8011FBF4 00431024 */  and       $v0, $v0, $v1
/* B62F8 8011FBF8 10400007 */  beqz      $v0, .L8011FC18
/* B62FC 8011FBFC 3C02D9FF */   lui      $v0, 0xd9ff
/* B6300 8011FC00 3442FFFF */  ori       $v0, $v0, 0xffff
/* B6304 8011FC04 25030030 */  addiu     $v1, $t0, 0x30
/* B6308 8011FC08 AD230000 */  sw        $v1, ($t1)
/* B630C 8011FC0C AD020028 */  sw        $v0, 0x28($t0)
/* B6310 8011FC10 24020400 */  addiu     $v0, $zero, 0x400
/* B6314 8011FC14 AD02002C */  sw        $v0, 0x2c($t0)
.L8011FC18:
/* B6318 8011FC18 3C028015 */  lui       $v0, %hi(D_80153A44)
/* B631C 8011FC1C 8C423A44 */  lw        $v0, %lo(D_80153A44)($v0)
/* B6320 8011FC20 1440000C */  bnez      $v0, .L8011FC54
/* B6324 8011FC24 3C04FC12 */   lui      $a0, 0xfc12
/* B6328 8011FC28 3C05FCFF */  lui       $a1, 0xfcff
/* B632C 8011FC2C 34A5FFFF */  ori       $a1, $a1, 0xffff
/* B6330 8011FC30 3C04FFFC */  lui       $a0, 0xfffc
/* B6334 8011FC34 8D220000 */  lw        $v0, ($t1)
/* B6338 8011FC38 3484F279 */  ori       $a0, $a0, 0xf279
/* B633C 8011FC3C 0040182D */  daddu     $v1, $v0, $zero
/* B6340 8011FC40 24420008 */  addiu     $v0, $v0, 8
/* B6344 8011FC44 AD220000 */  sw        $v0, ($t1)
/* B6348 8011FC48 AC650000 */  sw        $a1, ($v1)
/* B634C 8011FC4C 08047F1D */  j         .L8011FC74
/* B6350 8011FC50 AC640004 */   sw       $a0, 4($v1)
.L8011FC54:
/* B6354 8011FC54 8D220000 */  lw        $v0, ($t1)
/* B6358 8011FC58 34841E04 */  ori       $a0, $a0, 0x1e04
/* B635C 8011FC5C 0040182D */  daddu     $v1, $v0, $zero
/* B6360 8011FC60 24420008 */  addiu     $v0, $v0, 8
/* B6364 8011FC64 AD220000 */  sw        $v0, ($t1)
/* B6368 8011FC68 2402F3F8 */  addiu     $v0, $zero, -0xc08
/* B636C 8011FC6C AC640000 */  sw        $a0, ($v1)
/* B6370 8011FC70 AC620004 */  sw        $v0, 4($v1)
.L8011FC74:
/* B6374 8011FC74 3C10800A */  lui       $s0, %hi(D_8009A66C)
/* B6378 8011FC78 2610A66C */  addiu     $s0, $s0, %lo(D_8009A66C)
/* B637C 8011FC7C 8E020000 */  lw        $v0, ($s0)
/* B6380 8011FC80 3C11E700 */  lui       $s1, 0xe700
/* B6384 8011FC84 0040182D */  daddu     $v1, $v0, $zero
/* B6388 8011FC88 AC710000 */  sw        $s1, ($v1)
/* B638C 8011FC8C AC600004 */  sw        $zero, 4($v1)
/* B6390 8011FC90 8FAA0040 */  lw        $t2, 0x40($sp)
/* B6394 8011FC94 8D4302D4 */  lw        $v1, 0x2d4($t2)
/* B6398 8011FC98 24420008 */  addiu     $v0, $v0, 8
/* B639C 8011FC9C 10600004 */  beqz      $v1, .L8011FCB0
/* B63A0 8011FCA0 AE020000 */   sw       $v0, ($s0)
/* B63A4 8011FCA4 8D4402D8 */  lw        $a0, 0x2d8($t2)
/* B63A8 8011FCA8 0060F809 */  jalr      $v1
/* B63AC 8011FCAC 00000000 */   nop      
.L8011FCB0:
/* B63B0 8011FCB0 8E040000 */  lw        $a0, ($s0)
/* B63B4 8011FCB4 0080102D */  daddu     $v0, $a0, $zero
/* B63B8 8011FCB8 AC510000 */  sw        $s1, ($v0)
/* B63BC 8011FCBC AC400004 */  sw        $zero, 4($v0)
/* B63C0 8011FCC0 8EC50000 */  lw        $a1, ($s6)
/* B63C4 8011FCC4 24840008 */  addiu     $a0, $a0, 8
/* B63C8 8011FCC8 10A00089 */  beqz      $a1, .L8011FEF0
/* B63CC 8011FCCC AE040000 */   sw       $a0, ($s0)
/* B63D0 8011FCD0 86C200F8 */  lh        $v0, 0xf8($s6)
/* B63D4 8011FCD4 04410008 */  bgez      $v0, .L8011FCF8
/* B63D8 8011FCD8 240200DF */   addiu    $v0, $zero, 0xdf
/* B63DC 8011FCDC 3C02DE00 */  lui       $v0, 0xde00
/* B63E0 8011FCE0 AC820000 */  sw        $v0, ($a0)
/* B63E4 8011FCE4 8EC30000 */  lw        $v1, ($s6)
/* B63E8 8011FCE8 24820008 */  addiu     $v0, $a0, 8
/* B63EC 8011FCEC AE020000 */  sw        $v0, ($s0)
/* B63F0 8011FCF0 08047FBC */  j         .L8011FEF0
/* B63F4 8011FCF4 AC830004 */   sw       $v1, 4($a0)
.L8011FCF8:
/* B63F8 8011FCF8 90A30000 */  lbu       $v1, ($a1)
/* B63FC 8011FCFC 10620008 */  beq       $v1, $v0, .L8011FD20
/* B6400 8011FD00 0000202D */   daddu    $a0, $zero, $zero
/* B6404 8011FD04 0040302D */  daddu     $a2, $v0, $zero
/* B6408 8011FD08 24A20008 */  addiu     $v0, $a1, 8
.L8011FD0C:
/* B640C 8011FD0C 24840001 */  addiu     $a0, $a0, 1
/* B6410 8011FD10 8C450000 */  lw        $a1, ($v0)
/* B6414 8011FD14 00051E02 */  srl       $v1, $a1, 0x18
/* B6418 8011FD18 1466FFFC */  bne       $v1, $a2, .L8011FD0C
/* B641C 8011FD1C 24420008 */   addiu    $v0, $v0, 8
.L8011FD20:
/* B6420 8011FD20 24840001 */  addiu     $a0, $a0, 1
/* B6424 8011FD24 0000182D */  daddu     $v1, $zero, $zero
/* B6428 8011FD28 3C058015 */  lui       $a1, %hi(D_801536C0)
/* B642C 8011FD2C 24A536C0 */  addiu     $a1, $a1, %lo(D_801536C0)
/* B6430 8011FD30 000310C0 */  sll       $v0, $v1, 3
.L8011FD34:
/* B6434 8011FD34 0045B821 */  addu      $s7, $v0, $a1
/* B6438 8011FD38 8EE20000 */  lw        $v0, ($s7)
/* B643C 8011FD3C 04400006 */  bltz      $v0, .L8011FD58
/* B6440 8011FD40 28620060 */   slti     $v0, $v1, 0x60
/* B6444 8011FD44 24630001 */  addiu     $v1, $v1, 1
/* B6448 8011FD48 28620060 */  slti      $v0, $v1, 0x60
/* B644C 8011FD4C 1440FFF9 */  bnez      $v0, .L8011FD34
/* B6450 8011FD50 000310C0 */   sll      $v0, $v1, 3
/* B6454 8011FD54 28620060 */  slti      $v0, $v1, 0x60
.L8011FD58:
/* B6458 8011FD58 14400003 */  bnez      $v0, .L8011FD68
/* B645C 8011FD5C 00000000 */   nop      
.L8011FD60:
/* B6460 8011FD60 08047F58 */  j         .L8011FD60
/* B6464 8011FD64 00000000 */   nop      
.L8011FD68:
/* B6468 8011FD68 0C00AB0A */  jal       general_heap_malloc
/* B646C 8011FD6C 000420C0 */   sll      $a0, $a0, 3
/* B6470 8011FD70 0040982D */  daddu     $s3, $v0, $zero
/* B6474 8011FD74 16600003 */  bnez      $s3, .L8011FD84
/* B6478 8011FD78 AEF30004 */   sw       $s3, 4($s7)
.L8011FD7C:
/* B647C 8011FD7C 08047F5F */  j         .L8011FD7C
/* B6480 8011FD80 00000000 */   nop      
.L8011FD84:
/* B6484 8011FD84 0000A82D */  daddu     $s5, $zero, $zero
/* B6488 8011FD88 24020003 */  addiu     $v0, $zero, 3
/* B648C 8011FD8C AEE20000 */  sw        $v0, ($s7)
/* B6490 8011FD90 8EC20000 */  lw        $v0, ($s6)
/* B6494 8011FD94 8C450000 */  lw        $a1, ($v0)
/* B6498 8011FD98 8C470004 */  lw        $a3, 4($v0)
/* B649C 8011FD9C 240200DF */  addiu     $v0, $zero, 0xdf
/* B64A0 8011FDA0 00051E02 */  srl       $v1, $a1, 0x18
/* B64A4 8011FDA4 10620044 */  beq       $v1, $v0, .L8011FEB8
/* B64A8 8011FDA8 24140002 */   addiu    $s4, $zero, 2
/* B64AC 8011FDAC 3C1E0100 */  lui       $fp, 0x100
/* B64B0 8011FDB0 2672FFFC */  addiu     $s2, $s3, -4
.L8011FDB4:
/* B64B4 8011FDB4 24020001 */  addiu     $v0, $zero, 1
/* B64B8 8011FDB8 5462002F */  bnel      $v1, $v0, .L8011FE78
/* B64BC 8011FDBC 0260102D */   daddu    $v0, $s3, $zero
/* B64C0 8011FDC0 00451006 */  srlv      $v0, $a1, $v0
/* B64C4 8011FDC4 3051007F */  andi      $s1, $v0, 0x7f
/* B64C8 8011FDC8 00051302 */  srl       $v0, $a1, 0xc
/* B64CC 8011FDCC 305000FF */  andi      $s0, $v0, 0xff
/* B64D0 8011FDD0 8EC200FC */  lw        $v0, 0xfc($s6)
/* B64D4 8011FDD4 14400010 */  bnez      $v0, .L8011FE18
/* B64D8 8011FDD8 02308823 */   subu     $s1, $s1, $s0
/* B64DC 8011FDDC 26520008 */  addiu     $s2, $s2, 8
/* B64E0 8011FDE0 26730008 */  addiu     $s3, $s3, 8
/* B64E4 8011FDE4 00101300 */  sll       $v0, $s0, 0xc
/* B64E8 8011FDE8 02301821 */  addu      $v1, $s1, $s0
/* B64EC 8011FDEC 3063007F */  andi      $v1, $v1, 0x7f
/* B64F0 8011FDF0 00031840 */  sll       $v1, $v1, 1
/* B64F4 8011FDF4 007E1825 */  or        $v1, $v1, $fp
/* B64F8 8011FDF8 86C400F8 */  lh        $a0, 0xf8($s6)
/* B64FC 8011FDFC 00431025 */  or        $v0, $v0, $v1
/* B6500 8011FE00 AE42FFFC */  sw        $v0, -4($s2)
/* B6504 8011FE04 00952021 */  addu      $a0, $a0, $s5
/* B6508 8011FE08 00042100 */  sll       $a0, $a0, 4
/* B650C 8011FE0C 00E41821 */  addu      $v1, $a3, $a0
/* B6510 8011FE10 08047F9C */  j         .L8011FE70
/* B6514 8011FE14 AE430000 */   sw       $v1, ($s2)
.L8011FE18:
/* B6518 8011FE18 02C0282D */  daddu     $a1, $s6, $zero
/* B651C 8011FE1C 26520008 */  addiu     $s2, $s2, 8
/* B6520 8011FE20 8FA40040 */  lw        $a0, 0x40($sp)
/* B6524 8011FE24 86C200F8 */  lh        $v0, 0xf8($s6)
/* B6528 8011FE28 26730008 */  addiu     $s3, $s3, 8
/* B652C 8011FE2C AFB10010 */  sw        $s1, 0x10($sp)
/* B6530 8011FE30 AFB50014 */  sw        $s5, 0x14($sp)
/* B6534 8011FE34 00551021 */  addu      $v0, $v0, $s5
/* B6538 8011FE38 00023040 */  sll       $a2, $v0, 1
/* B653C 8011FE3C 00C23021 */  addu      $a2, $a2, $v0
/* B6540 8011FE40 00063040 */  sll       $a2, $a2, 1
/* B6544 8011FE44 00E63021 */  addu      $a2, $a3, $a2
/* B6548 8011FE48 0C0477A0 */  jal       func_8011DE80
/* B654C 8011FE4C 0200382D */   daddu    $a3, $s0, $zero
/* B6550 8011FE50 00102300 */  sll       $a0, $s0, 0xc
/* B6554 8011FE54 02301821 */  addu      $v1, $s1, $s0
/* B6558 8011FE58 3063007F */  andi      $v1, $v1, 0x7f
/* B655C 8011FE5C 00031840 */  sll       $v1, $v1, 1
/* B6560 8011FE60 007E1825 */  or        $v1, $v1, $fp
/* B6564 8011FE64 00832025 */  or        $a0, $a0, $v1
/* B6568 8011FE68 AE44FFFC */  sw        $a0, -4($s2)
/* B656C 8011FE6C AE420000 */  sw        $v0, ($s2)
.L8011FE70:
/* B6570 8011FE70 08047FA2 */  j         .L8011FE88
/* B6574 8011FE74 02B0A821 */   addu     $s5, $s5, $s0
.L8011FE78:
/* B6578 8011FE78 26520008 */  addiu     $s2, $s2, 8
/* B657C 8011FE7C 26730008 */  addiu     $s3, $s3, 8
/* B6580 8011FE80 AC450000 */  sw        $a1, ($v0)
/* B6584 8011FE84 AC470004 */  sw        $a3, 4($v0)
.L8011FE88:
/* B6588 8011FE88 00141080 */  sll       $v0, $s4, 2
/* B658C 8011FE8C 26940001 */  addiu     $s4, $s4, 1
/* B6590 8011FE90 00141880 */  sll       $v1, $s4, 2
/* B6594 8011FE94 8EC40000 */  lw        $a0, ($s6)
/* B6598 8011FE98 00441021 */  addu      $v0, $v0, $a0
/* B659C 8011FE9C 00641821 */  addu      $v1, $v1, $a0
/* B65A0 8011FEA0 8C450000 */  lw        $a1, ($v0)
/* B65A4 8011FEA4 240200DF */  addiu     $v0, $zero, 0xdf
/* B65A8 8011FEA8 8C670000 */  lw        $a3, ($v1)
/* B65AC 8011FEAC 00051E02 */  srl       $v1, $a1, 0x18
/* B65B0 8011FEB0 1462FFC0 */  bne       $v1, $v0, .L8011FDB4
/* B65B4 8011FEB4 26940001 */   addiu    $s4, $s4, 1
.L8011FEB8:
/* B65B8 8011FEB8 3C05800A */  lui       $a1, %hi(D_8009A66C)
/* B65BC 8011FEBC 24A5A66C */  addiu     $a1, $a1, %lo(D_8009A66C)
/* B65C0 8011FEC0 0260202D */  daddu     $a0, $s3, $zero
/* B65C4 8011FEC4 8CA30000 */  lw        $v1, ($a1)
/* B65C8 8011FEC8 3C02DF00 */  lui       $v0, 0xdf00
/* B65CC 8011FECC AC820000 */  sw        $v0, ($a0)
/* B65D0 8011FED0 3C02DE00 */  lui       $v0, 0xde00
/* B65D4 8011FED4 AC800004 */  sw        $zero, 4($a0)
/* B65D8 8011FED8 0060202D */  daddu     $a0, $v1, $zero
/* B65DC 8011FEDC AC820000 */  sw        $v0, ($a0)
/* B65E0 8011FEE0 8EE20004 */  lw        $v0, 4($s7)
/* B65E4 8011FEE4 24630008 */  addiu     $v1, $v1, 8
/* B65E8 8011FEE8 ACA30000 */  sw        $v1, ($a1)
/* B65EC 8011FEEC AC820004 */  sw        $v0, 4($a0)
.L8011FEF0:
/* B65F0 8011FEF0 0000882D */  daddu     $s1, $zero, $zero
/* B65F4 8011FEF4 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* B65F8 8011FEF8 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* B65FC 8011FEFC 8C620000 */  lw        $v0, ($v1)
/* B6600 8011FF00 02C0802D */  daddu     $s0, $s6, $zero
/* B6604 8011FF04 0040202D */  daddu     $a0, $v0, $zero
/* B6608 8011FF08 24420008 */  addiu     $v0, $v0, 8
/* B660C 8011FF0C AC620000 */  sw        $v0, ($v1)
/* B6610 8011FF10 3C02E700 */  lui       $v0, 0xe700
/* B6614 8011FF14 AC820000 */  sw        $v0, ($a0)
/* B6618 8011FF18 AC800004 */  sw        $zero, 4($a0)
.L8011FF1C:
/* B661C 8011FF1C 8E050004 */  lw        $a1, 4($s0)
/* B6620 8011FF20 50A00005 */  beql      $a1, $zero, .L8011FF38
/* B6624 8011FF24 26310001 */   addiu    $s1, $s1, 1
/* B6628 8011FF28 8FA40040 */  lw        $a0, 0x40($sp)
/* B662C 8011FF2C 0C047E95 */  jal       func_8011FA54
/* B6630 8011FF30 26C600B4 */   addiu    $a2, $s6, 0xb4
/* B6634 8011FF34 26310001 */  addiu     $s1, $s1, 1
.L8011FF38:
/* B6638 8011FF38 2A220020 */  slti      $v0, $s1, 0x20
/* B663C 8011FF3C 1440FFF7 */  bnez      $v0, .L8011FF1C
/* B6640 8011FF40 26100004 */   addiu    $s0, $s0, 4
.L8011FF44:
/* B6644 8011FF44 8FBF003C */  lw        $ra, 0x3c($sp)
/* B6648 8011FF48 8FBE0038 */  lw        $fp, 0x38($sp)
/* B664C 8011FF4C 8FB70034 */  lw        $s7, 0x34($sp)
/* B6650 8011FF50 8FB60030 */  lw        $s6, 0x30($sp)
/* B6654 8011FF54 8FB5002C */  lw        $s5, 0x2c($sp)
/* B6658 8011FF58 8FB40028 */  lw        $s4, 0x28($sp)
/* B665C 8011FF5C 8FB30024 */  lw        $s3, 0x24($sp)
/* B6660 8011FF60 8FB20020 */  lw        $s2, 0x20($sp)
/* B6664 8011FF64 8FB1001C */  lw        $s1, 0x1c($sp)
/* B6668 8011FF68 8FB00018 */  lw        $s0, 0x18($sp)
/* B666C 8011FF6C 03E00008 */  jr        $ra
/* B6670 8011FF70 27BD0040 */   addiu    $sp, $sp, 0x40
