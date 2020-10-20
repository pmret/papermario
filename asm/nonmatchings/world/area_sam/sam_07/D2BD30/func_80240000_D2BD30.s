.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D2BD30
/* D2BD30 80240000 27BDFEB0 */  addiu     $sp, $sp, -0x150
/* D2BD34 80240004 AFB70134 */  sw        $s7, 0x134($sp)
/* D2BD38 80240008 AFBE0138 */  sw        $fp, 0x138($sp)
/* D2BD3C 8024000C 3C1E8011 */  lui       $fp, %hi(gPlayerStatus)
/* D2BD40 80240010 27DEEFC8 */  addiu     $fp, $fp, %lo(gPlayerStatus)
/* D2BD44 80240014 AFBF013C */  sw        $ra, 0x13c($sp)
/* D2BD48 80240018 AFB60130 */  sw        $s6, 0x130($sp)
/* D2BD4C 8024001C AFB5012C */  sw        $s5, 0x12c($sp)
/* D2BD50 80240020 AFB40128 */  sw        $s4, 0x128($sp)
/* D2BD54 80240024 AFB30124 */  sw        $s3, 0x124($sp)
/* D2BD58 80240028 AFB20120 */  sw        $s2, 0x120($sp)
/* D2BD5C 8024002C AFB1011C */  sw        $s1, 0x11c($sp)
/* D2BD60 80240030 AFB00118 */  sw        $s0, 0x118($sp)
/* D2BD64 80240034 F7B60148 */  sdc1      $f22, 0x148($sp)
/* D2BD68 80240038 F7B40140 */  sdc1      $f20, 0x140($sp)
/* D2BD6C 8024003C 10A00061 */  beqz      $a1, .L802401C4
/* D2BD70 80240040 0080B82D */   daddu    $s7, $a0, $zero
/* D2BD74 80240044 0C00AB39 */  jal       heap_malloc
/* D2BD78 80240048 24041B80 */   addiu    $a0, $zero, 0x1b80
/* D2BD7C 8024004C 0000982D */  daddu     $s3, $zero, $zero
/* D2BD80 80240050 AEE20070 */  sw        $v0, 0x70($s7)
/* D2BD84 80240054 0040882D */  daddu     $s1, $v0, $zero
/* D2BD88 80240058 3C148024 */  lui       $s4, 0x8024
/* D2BD8C 8024005C 269424C0 */  addiu     $s4, $s4, 0x24c0
/* D2BD90 80240060 2630003C */  addiu     $s0, $s1, 0x3c
/* D2BD94 80240064 AEE00074 */  sw        $zero, 0x74($s7)
.L80240068:
/* D2BD98 80240068 0C046C04 */  jal       get_model_list_index_from_tree_index
/* D2BD9C 8024006C 8E840000 */   lw       $a0, ($s4)
/* D2BDA0 80240070 0C046B4C */  jal       get_model_from_list_index
/* D2BDA4 80240074 0040202D */   daddu    $a0, $v0, $zero
/* D2BDA8 80240078 0040902D */  daddu     $s2, $v0, $zero
/* D2BDAC 8024007C AE200000 */  sw        $zero, ($s1)
/* D2BDB0 80240080 C6400098 */  lwc1      $f0, 0x98($s2)
/* D2BDB4 80240084 E600FFC8 */  swc1      $f0, -0x38($s0)
/* D2BDB8 80240088 C640009C */  lwc1      $f0, 0x9c($s2)
/* D2BDBC 8024008C E600FFCC */  swc1      $f0, -0x34($s0)
/* D2BDC0 80240090 C64000A0 */  lwc1      $f0, 0xa0($s2)
/* D2BDC4 80240094 C602FFCC */  lwc1      $f2, -0x34($s0)
/* D2BDC8 80240098 E600FFD0 */  swc1      $f0, -0x30($s0)
/* D2BDCC 8024009C C600FFC8 */  lwc1      $f0, -0x38($s0)
/* D2BDD0 802400A0 C604FFD0 */  lwc1      $f4, -0x30($s0)
/* D2BDD4 802400A4 24040014 */  addiu     $a0, $zero, 0x14
/* D2BDD8 802400A8 AE00FFE0 */  sw        $zero, -0x20($s0)
/* D2BDDC 802400AC AE00FFE4 */  sw        $zero, -0x1c($s0)
/* D2BDE0 802400B0 AE00FFE8 */  sw        $zero, -0x18($s0)
/* D2BDE4 802400B4 E602FFD8 */  swc1      $f2, -0x28($s0)
/* D2BDE8 802400B8 E600FFD4 */  swc1      $f0, -0x2c($s0)
/* D2BDEC 802400BC 0C00A67F */  jal       rand_int
/* D2BDF0 802400C0 E604FFDC */   swc1     $f4, -0x24($s0)
/* D2BDF4 802400C4 24040014 */  addiu     $a0, $zero, 0x14
/* D2BDF8 802400C8 2442FFF6 */  addiu     $v0, $v0, -0xa
/* D2BDFC 802400CC 44820000 */  mtc1      $v0, $f0
/* D2BE00 802400D0 00000000 */  nop       
/* D2BE04 802400D4 46800020 */  cvt.s.w   $f0, $f0
/* D2BE08 802400D8 0C00A67F */  jal       rand_int
/* D2BE0C 802400DC E600FFEC */   swc1     $f0, -0x14($s0)
/* D2BE10 802400E0 24040014 */  addiu     $a0, $zero, 0x14
/* D2BE14 802400E4 2442FFF6 */  addiu     $v0, $v0, -0xa
/* D2BE18 802400E8 44820000 */  mtc1      $v0, $f0
/* D2BE1C 802400EC 00000000 */  nop       
/* D2BE20 802400F0 46800020 */  cvt.s.w   $f0, $f0
/* D2BE24 802400F4 0C00A67F */  jal       rand_int
/* D2BE28 802400F8 E600FFF0 */   swc1     $f0, -0x10($s0)
/* D2BE2C 802400FC 24040005 */  addiu     $a0, $zero, 5
/* D2BE30 80240100 2442FFF6 */  addiu     $v0, $v0, -0xa
/* D2BE34 80240104 44820000 */  mtc1      $v0, $f0
/* D2BE38 80240108 00000000 */  nop       
/* D2BE3C 8024010C 46800020 */  cvt.s.w   $f0, $f0
/* D2BE40 80240110 0C00A67F */  jal       rand_int
/* D2BE44 80240114 E600FFF4 */   swc1     $f0, -0xc($s0)
/* D2BE48 80240118 3C0140A0 */  lui       $at, 0x40a0
/* D2BE4C 8024011C 44811000 */  mtc1      $at, $f2
/* D2BE50 80240120 44820000 */  mtc1      $v0, $f0
/* D2BE54 80240124 00000000 */  nop       
/* D2BE58 80240128 46800020 */  cvt.s.w   $f0, $f0
/* D2BE5C 8024012C 46020000 */  add.s     $f0, $f0, $f2
/* D2BE60 80240130 24040003 */  addiu     $a0, $zero, 3
/* D2BE64 80240134 0C00A67F */  jal       rand_int
/* D2BE68 80240138 E600FFF8 */   swc1     $f0, -8($s0)
/* D2BE6C 8024013C 3C013F80 */  lui       $at, 0x3f80
/* D2BE70 80240140 44811000 */  mtc1      $at, $f2
/* D2BE74 80240144 44820000 */  mtc1      $v0, $f0
/* D2BE78 80240148 00000000 */  nop       
/* D2BE7C 8024014C 46800020 */  cvt.s.w   $f0, $f0
/* D2BE80 80240150 46020000 */  add.s     $f0, $f0, $f2
/* D2BE84 80240154 24040168 */  addiu     $a0, $zero, 0x168
/* D2BE88 80240158 0C00A67F */  jal       rand_int
/* D2BE8C 8024015C E600FFFC */   swc1     $f0, -4($s0)
/* D2BE90 80240160 0000302D */  daddu     $a2, $zero, $zero
/* D2BE94 80240164 44820000 */  mtc1      $v0, $f0
/* D2BE98 80240168 00000000 */  nop       
/* D2BE9C 8024016C 46800020 */  cvt.s.w   $f0, $f0
/* D2BEA0 80240170 E6000000 */  swc1      $f0, ($s0)
/* D2BEA4 80240174 0000282D */  daddu     $a1, $zero, $zero
.L80240178:
/* D2BEA8 80240178 00062100 */  sll       $a0, $a2, 4
.L8024017C:
/* D2BEAC 8024017C 02241821 */  addu      $v1, $s1, $a0
/* D2BEB0 80240180 02441021 */  addu      $v0, $s2, $a0
/* D2BEB4 80240184 24840004 */  addiu     $a0, $a0, 4
/* D2BEB8 80240188 24A50001 */  addiu     $a1, $a1, 1
/* D2BEBC 8024018C C4400058 */  lwc1      $f0, 0x58($v0)
/* D2BEC0 80240190 28A20004 */  slti      $v0, $a1, 4
/* D2BEC4 80240194 1440FFF9 */  bnez      $v0, .L8024017C
/* D2BEC8 80240198 E4600040 */   swc1     $f0, 0x40($v1)
/* D2BECC 8024019C 24C60001 */  addiu     $a2, $a2, 1
/* D2BED0 802401A0 28C20004 */  slti      $v0, $a2, 4
/* D2BED4 802401A4 1440FFF4 */  bnez      $v0, .L80240178
/* D2BED8 802401A8 0000282D */   daddu    $a1, $zero, $zero
/* D2BEDC 802401AC 26940004 */  addiu     $s4, $s4, 4
/* D2BEE0 802401B0 26730001 */  addiu     $s3, $s3, 1
/* D2BEE4 802401B4 26100080 */  addiu     $s0, $s0, 0x80
/* D2BEE8 802401B8 2E620037 */  sltiu     $v0, $s3, 0x37
/* D2BEEC 802401BC 1440FFAA */  bnez      $v0, .L80240068
/* D2BEF0 802401C0 26310080 */   addiu    $s1, $s1, 0x80
.L802401C4:
/* D2BEF4 802401C4 0000982D */  daddu     $s3, $zero, $zero
/* D2BEF8 802401C8 27B50058 */  addiu     $s5, $sp, 0x58
/* D2BEFC 802401CC 27B40098 */  addiu     $s4, $sp, 0x98
/* D2BF00 802401D0 27B600D8 */  addiu     $s6, $sp, 0xd8
/* D2BF04 802401D4 8EF10070 */  lw        $s1, 0x70($s7)
/* D2BF08 802401D8 3C013F80 */  lui       $at, 0x3f80
/* D2BF0C 802401DC 4481B000 */  mtc1      $at, $f22
/* D2BF10 802401E0 4480A000 */  mtc1      $zero, $f20
/* D2BF14 802401E4 26300024 */  addiu     $s0, $s1, 0x24
/* D2BF18 802401E8 00131080 */  sll       $v0, $s3, 2
.L802401EC:
/* D2BF1C 802401EC 3C048024 */  lui       $a0, 0x8024
/* D2BF20 802401F0 00822021 */  addu      $a0, $a0, $v0
/* D2BF24 802401F4 0C046C04 */  jal       get_model_list_index_from_tree_index
/* D2BF28 802401F8 8C8424C0 */   lw       $a0, 0x24c0($a0)
/* D2BF2C 802401FC 0C046B4C */  jal       get_model_from_list_index
/* D2BF30 80240200 0040202D */   daddu    $a0, $v0, $zero
/* D2BF34 80240204 8E230000 */  lw        $v1, ($s1)
/* D2BF38 80240208 1460001C */  bnez      $v1, .L8024027C
/* D2BF3C 8024020C 0040902D */   daddu    $s2, $v0, $zero
/* D2BF40 80240210 26240004 */  addiu     $a0, $s1, 4
/* D2BF44 80240214 8E060014 */  lw        $a2, 0x14($s0)
/* D2BF48 80240218 8E070018 */  lw        $a3, 0x18($s0)
/* D2BF4C 8024021C 0C00A7E7 */  jal       add_vec2D_polar
/* D2BF50 80240220 2625000C */   addiu    $a1, $s1, 0xc
/* D2BF54 80240224 C6000010 */  lwc1      $f0, 0x10($s0)
/* D2BF58 80240228 46160001 */  sub.s     $f0, $f0, $f22
/* D2BF5C 8024022C C602FFE4 */  lwc1      $f2, -0x1c($s0)
/* D2BF60 80240230 46001100 */  add.s     $f4, $f2, $f0
/* D2BF64 80240234 4614003C */  c.lt.s    $f0, $f20
/* D2BF68 80240238 E6000010 */  swc1      $f0, 0x10($s0)
/* D2BF6C 8024023C 4500000F */  bc1f      .L8024027C
/* D2BF70 80240240 E604FFE4 */   swc1     $f4, -0x1c($s0)
/* D2BF74 80240244 C7C0002C */  lwc1      $f0, 0x2c($fp)
/* D2BF78 80240248 3C014316 */  lui       $at, 0x4316
/* D2BF7C 8024024C 44811000 */  mtc1      $at, $f2
/* D2BF80 80240250 00000000 */  nop       
/* D2BF84 80240254 46020001 */  sub.s     $f0, $f0, $f2
/* D2BF88 80240258 4600203C */  c.lt.s    $f4, $f0
/* D2BF8C 8024025C 00000000 */  nop       
/* D2BF90 80240260 45000007 */  bc1f      .L80240280
/* D2BF94 80240264 0000302D */   daddu    $a2, $zero, $zero
/* D2BF98 80240268 8EE20074 */  lw        $v0, 0x74($s7)
/* D2BF9C 8024026C 24420001 */  addiu     $v0, $v0, 1
/* D2BFA0 80240270 AEE20074 */  sw        $v0, 0x74($s7)
/* D2BFA4 80240274 24020065 */  addiu     $v0, $zero, 0x65
/* D2BFA8 80240278 AE220000 */  sw        $v0, ($s1)
.L8024027C:
/* D2BFAC 8024027C 0000302D */  daddu     $a2, $zero, $zero
.L80240280:
/* D2BFB0 80240280 0000282D */  daddu     $a1, $zero, $zero
.L80240284:
/* D2BFB4 80240284 00062100 */  sll       $a0, $a2, 4
.L80240288:
/* D2BFB8 80240288 02441821 */  addu      $v1, $s2, $a0
/* D2BFBC 8024028C 02241021 */  addu      $v0, $s1, $a0
/* D2BFC0 80240290 24840004 */  addiu     $a0, $a0, 4
/* D2BFC4 80240294 24A50001 */  addiu     $a1, $a1, 1
/* D2BFC8 80240298 C4400040 */  lwc1      $f0, 0x40($v0)
/* D2BFCC 8024029C 28A20004 */  slti      $v0, $a1, 4
/* D2BFD0 802402A0 1440FFF9 */  bnez      $v0, .L80240288
/* D2BFD4 802402A4 E4600058 */   swc1     $f0, 0x58($v1)
/* D2BFD8 802402A8 24C60001 */  addiu     $a2, $a2, 1
/* D2BFDC 802402AC 28C20004 */  slti      $v0, $a2, 4
/* D2BFE0 802402B0 1440FFF4 */  bnez      $v0, .L80240284
/* D2BFE4 802402B4 0000282D */   daddu    $a1, $zero, $zero
/* D2BFE8 802402B8 96420000 */  lhu       $v0, ($s2)
/* D2BFEC 802402BC 34421400 */  ori       $v0, $v0, 0x1400
/* D2BFF0 802402C0 A6420000 */  sh        $v0, ($s2)
/* D2BFF4 802402C4 C602FFE0 */  lwc1      $f2, -0x20($s0)
/* D2BFF8 802402C8 C600FFEC */  lwc1      $f0, -0x14($s0)
/* D2BFFC 802402CC 46001081 */  sub.s     $f2, $f2, $f0
/* D2C000 802402D0 C600FFF0 */  lwc1      $f0, -0x10($s0)
/* D2C004 802402D4 44051000 */  mfc1      $a1, $f2
/* D2C008 802402D8 C602FFE4 */  lwc1      $f2, -0x1c($s0)
/* D2C00C 802402DC 46001081 */  sub.s     $f2, $f2, $f0
/* D2C010 802402E0 C600FFF4 */  lwc1      $f0, -0xc($s0)
/* D2C014 802402E4 44061000 */  mfc1      $a2, $f2
/* D2C018 802402E8 C602FFE8 */  lwc1      $f2, -0x18($s0)
/* D2C01C 802402EC 46001081 */  sub.s     $f2, $f2, $f0
/* D2C020 802402F0 44071000 */  mfc1      $a3, $f2
/* D2C024 802402F4 0C019E40 */  jal       guTranslateF
/* D2C028 802402F8 27A40018 */   addiu    $a0, $sp, 0x18
/* D2C02C 802402FC C602FFF8 */  lwc1      $f2, -8($s0)
/* D2C030 80240300 C6000004 */  lwc1      $f0, 4($s0)
/* D2C034 80240304 C604FFFC */  lwc1      $f4, -4($s0)
/* D2C038 80240308 46001080 */  add.s     $f2, $f2, $f0
/* D2C03C 8024030C C6000008 */  lwc1      $f0, 8($s0)
/* D2C040 80240310 46002100 */  add.s     $f4, $f4, $f0
/* D2C044 80240314 C6000000 */  lwc1      $f0, ($s0)
/* D2C048 80240318 E602FFF8 */  swc1      $f2, -8($s0)
/* D2C04C 8024031C C602000C */  lwc1      $f2, 0xc($s0)
/* D2C050 80240320 C60CFFF8 */  lwc1      $f12, -8($s0)
/* D2C054 80240324 46020000 */  add.s     $f0, $f0, $f2
/* D2C058 80240328 E604FFFC */  swc1      $f4, -4($s0)
/* D2C05C 8024032C 0C00A6C9 */  jal       clamp_angle
/* D2C060 80240330 E6000000 */   swc1     $f0, ($s0)
/* D2C064 80240334 C60CFFFC */  lwc1      $f12, -4($s0)
/* D2C068 80240338 26730001 */  addiu     $s3, $s3, 1
/* D2C06C 8024033C 0C00A6C9 */  jal       clamp_angle
/* D2C070 80240340 E600FFF8 */   swc1     $f0, -8($s0)
/* D2C074 80240344 C60C0000 */  lwc1      $f12, ($s0)
/* D2C078 80240348 26310080 */  addiu     $s1, $s1, 0x80
/* D2C07C 8024034C 0C00A6C9 */  jal       clamp_angle
/* D2C080 80240350 E600FFFC */   swc1     $f0, -4($s0)
/* D2C084 80240354 E6000000 */  swc1      $f0, ($s0)
/* D2C088 80240358 E7B40010 */  swc1      $f20, 0x10($sp)
/* D2C08C 8024035C 8E05FFF8 */  lw        $a1, -8($s0)
/* D2C090 80240360 4406B000 */  mfc1      $a2, $f22
/* D2C094 80240364 4407A000 */  mfc1      $a3, $f20
/* D2C098 80240368 0C019EC8 */  jal       guRotateF
/* D2C09C 8024036C 02A0202D */   daddu    $a0, $s5, $zero
/* D2C0A0 80240370 E7B40010 */  swc1      $f20, 0x10($sp)
/* D2C0A4 80240374 8E05FFFC */  lw        $a1, -4($s0)
/* D2C0A8 80240378 4406A000 */  mfc1      $a2, $f20
/* D2C0AC 8024037C 4407B000 */  mfc1      $a3, $f22
/* D2C0B0 80240380 0C019EC8 */  jal       guRotateF
/* D2C0B4 80240384 0280202D */   daddu    $a0, $s4, $zero
/* D2C0B8 80240388 02C0202D */  daddu     $a0, $s6, $zero
/* D2C0BC 8024038C E7B60010 */  swc1      $f22, 0x10($sp)
/* D2C0C0 80240390 8E050000 */  lw        $a1, ($s0)
/* D2C0C4 80240394 4406A000 */  mfc1      $a2, $f20
/* D2C0C8 80240398 4407A000 */  mfc1      $a3, $f20
/* D2C0CC 8024039C 0C019EC8 */  jal       guRotateF
/* D2C0D0 802403A0 26100080 */   addiu    $s0, $s0, 0x80
/* D2C0D4 802403A4 02C0202D */  daddu     $a0, $s6, $zero
/* D2C0D8 802403A8 02A0282D */  daddu     $a1, $s5, $zero
/* D2C0DC 802403AC 0C019D80 */  jal       guMtxCatF
/* D2C0E0 802403B0 02A0302D */   daddu    $a2, $s5, $zero
/* D2C0E4 802403B4 02A0202D */  daddu     $a0, $s5, $zero
/* D2C0E8 802403B8 0280282D */  daddu     $a1, $s4, $zero
/* D2C0EC 802403BC 0C019D80 */  jal       guMtxCatF
/* D2C0F0 802403C0 0280302D */   daddu    $a2, $s4, $zero
/* D2C0F4 802403C4 0280202D */  daddu     $a0, $s4, $zero
/* D2C0F8 802403C8 27A50018 */  addiu     $a1, $sp, 0x18
/* D2C0FC 802403CC 0C019D80 */  jal       guMtxCatF
/* D2C100 802403D0 00A0302D */   daddu    $a2, $a1, $zero
/* D2C104 802403D4 27A40018 */  addiu     $a0, $sp, 0x18
/* D2C108 802403D8 26450058 */  addiu     $a1, $s2, 0x58
/* D2C10C 802403DC 0C019D80 */  jal       guMtxCatF
/* D2C110 802403E0 00A0302D */   daddu    $a2, $a1, $zero
/* D2C114 802403E4 2E620037 */  sltiu     $v0, $s3, 0x37
/* D2C118 802403E8 1440FF80 */  bnez      $v0, .L802401EC
/* D2C11C 802403EC 00131080 */   sll      $v0, $s3, 2
/* D2C120 802403F0 8EE20074 */  lw        $v0, 0x74($s7)
/* D2C124 802403F4 2C420037 */  sltiu     $v0, $v0, 0x37
/* D2C128 802403F8 14400005 */  bnez      $v0, .L80240410
/* D2C12C 802403FC 0000102D */   daddu    $v0, $zero, $zero
/* D2C130 80240400 8EE40070 */  lw        $a0, 0x70($s7)
/* D2C134 80240404 0C00AB4B */  jal       heap_free
/* D2C138 80240408 00000000 */   nop      
/* D2C13C 8024040C 24020002 */  addiu     $v0, $zero, 2
.L80240410:
/* D2C140 80240410 8FBF013C */  lw        $ra, 0x13c($sp)
/* D2C144 80240414 8FBE0138 */  lw        $fp, 0x138($sp)
/* D2C148 80240418 8FB70134 */  lw        $s7, 0x134($sp)
/* D2C14C 8024041C 8FB60130 */  lw        $s6, 0x130($sp)
/* D2C150 80240420 8FB5012C */  lw        $s5, 0x12c($sp)
/* D2C154 80240424 8FB40128 */  lw        $s4, 0x128($sp)
/* D2C158 80240428 8FB30124 */  lw        $s3, 0x124($sp)
/* D2C15C 8024042C 8FB20120 */  lw        $s2, 0x120($sp)
/* D2C160 80240430 8FB1011C */  lw        $s1, 0x11c($sp)
/* D2C164 80240434 8FB00118 */  lw        $s0, 0x118($sp)
/* D2C168 80240438 D7B60148 */  ldc1      $f22, 0x148($sp)
/* D2C16C 8024043C D7B40140 */  ldc1      $f20, 0x140($sp)
/* D2C170 80240440 03E00008 */  jr        $ra
/* D2C174 80240444 27BD0150 */   addiu    $sp, $sp, 0x150
