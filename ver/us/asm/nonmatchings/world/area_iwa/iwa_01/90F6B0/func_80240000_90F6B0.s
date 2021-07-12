.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80246370_915A20
.double 0.98

glabel D_80246378_915A28
.double -0.1

.section .text

glabel func_80240000_90F6B0
/* 90F6B0 80240000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 90F6B4 80240004 0000202D */  daddu     $a0, $zero, $zero
/* 90F6B8 80240008 3C05FD05 */  lui       $a1, 0xfd05
/* 90F6BC 8024000C AFBF003C */  sw        $ra, 0x3c($sp)
/* 90F6C0 80240010 AFB60038 */  sw        $s6, 0x38($sp)
/* 90F6C4 80240014 AFB50034 */  sw        $s5, 0x34($sp)
/* 90F6C8 80240018 AFB40030 */  sw        $s4, 0x30($sp)
/* 90F6CC 8024001C AFB3002C */  sw        $s3, 0x2c($sp)
/* 90F6D0 80240020 AFB20028 */  sw        $s2, 0x28($sp)
/* 90F6D4 80240024 AFB10024 */  sw        $s1, 0x24($sp)
/* 90F6D8 80240028 AFB00020 */  sw        $s0, 0x20($sp)
/* 90F6DC 8024002C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 90F6E0 80240030 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 90F6E4 80240034 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 90F6E8 80240038 0C0B1EAF */  jal       get_variable
/* 90F6EC 8024003C 34A50F8F */   ori      $a1, $a1, 0xf8f
/* 90F6F0 80240040 0040882D */  daddu     $s1, $v0, $zero
/* 90F6F4 80240044 0000982D */  daddu     $s3, $zero, $zero
/* 90F6F8 80240048 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 90F6FC 8024004C 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 90F700 80240050 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 90F704 80240054 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 90F708 80240058 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 90F70C 8024005C 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 90F710 80240060 3C140001 */  lui       $s4, 1
/* 90F714 80240064 36941630 */  ori       $s4, $s4, 0x1630
/* 90F718 80240068 26300018 */  addiu     $s0, $s1, 0x18
/* 90F71C 8024006C 3C01C1F0 */  lui       $at, 0xc1f0
/* 90F720 80240070 4481C000 */  mtc1      $at, $f24
/* 90F724 80240074 3C014120 */  lui       $at, 0x4120
/* 90F728 80240078 4481B000 */  mtc1      $at, $f22
/* 90F72C 8024007C 3C018024 */  lui       $at, %hi(D_80246370_915A20)
/* 90F730 80240080 D4346370 */  ldc1      $f20, %lo(D_80246370_915A20)($at)
.L80240084:
/* 90F734 80240084 C600FFEC */  lwc1      $f0, -0x14($s0)
/* 90F738 80240088 4618003C */  c.lt.s    $f0, $f24
/* 90F73C 8024008C 00000000 */  nop
/* 90F740 80240090 4500002F */  bc1f      .L80240150
/* 90F744 80240094 24040008 */   addiu    $a0, $zero, 8
/* 90F748 80240098 3C0140A0 */  lui       $at, 0x40a0
/* 90F74C 8024009C 44810000 */  mtc1      $at, $f0
/* 90F750 802400A0 3C01C1A0 */  lui       $at, 0xc1a0
/* 90F754 802400A4 44811000 */  mtc1      $at, $f2
/* 90F758 802400A8 AE200000 */  sw        $zero, ($s1)
/* 90F75C 802400AC E600FFEC */  swc1      $f0, -0x14($s0)
/* 90F760 802400B0 0C00A67F */  jal       rand_int
/* 90F764 802400B4 E602FFF0 */   swc1     $f2, -0x10($s0)
/* 90F768 802400B8 2404000A */  addiu     $a0, $zero, 0xa
/* 90F76C 802400BC 2442FFFC */  addiu     $v0, $v0, -4
/* 90F770 802400C0 44820000 */  mtc1      $v0, $f0
/* 90F774 802400C4 00000000 */  nop
/* 90F778 802400C8 46800020 */  cvt.s.w   $f0, $f0
/* 90F77C 802400CC 46160003 */  div.s     $f0, $f0, $f22
/* 90F780 802400D0 0C00A67F */  jal       rand_int
/* 90F784 802400D4 E6000004 */   swc1     $f0, 4($s0)
/* 90F788 802400D8 2404000A */  addiu     $a0, $zero, 0xa
/* 90F78C 802400DC 44820000 */  mtc1      $v0, $f0
/* 90F790 802400E0 00000000 */  nop
/* 90F794 802400E4 46800020 */  cvt.s.w   $f0, $f0
/* 90F798 802400E8 46160003 */  div.s     $f0, $f0, $f22
/* 90F79C 802400EC 0C00A67F */  jal       rand_int
/* 90F7A0 802400F0 E6000008 */   swc1     $f0, 8($s0)
/* 90F7A4 802400F4 24040014 */  addiu     $a0, $zero, 0x14
/* 90F7A8 802400F8 2442001E */  addiu     $v0, $v0, 0x1e
/* 90F7AC 802400FC 44820000 */  mtc1      $v0, $f0
/* 90F7B0 80240100 00000000 */  nop
/* 90F7B4 80240104 46800020 */  cvt.s.w   $f0, $f0
/* 90F7B8 80240108 3C013F80 */  lui       $at, 0x3f80
/* 90F7BC 8024010C 44811000 */  mtc1      $at, $f2
/* 90F7C0 80240110 46160003 */  div.s     $f0, $f0, $f22
/* 90F7C4 80240114 E600000C */  swc1      $f0, 0xc($s0)
/* 90F7C8 80240118 0C00A67F */  jal       rand_int
/* 90F7CC 8024011C E602FFF4 */   swc1     $f2, -0xc($s0)
/* 90F7D0 80240120 24040167 */  addiu     $a0, $zero, 0x167
/* 90F7D4 80240124 24420050 */  addiu     $v0, $v0, 0x50
/* 90F7D8 80240128 44820000 */  mtc1      $v0, $f0
/* 90F7DC 8024012C 00000000 */  nop
/* 90F7E0 80240130 46800020 */  cvt.s.w   $f0, $f0
/* 90F7E4 80240134 0C00A67F */  jal       rand_int
/* 90F7E8 80240138 E600FFF8 */   swc1     $f0, -8($s0)
/* 90F7EC 8024013C 44820000 */  mtc1      $v0, $f0
/* 90F7F0 80240140 00000000 */  nop
/* 90F7F4 80240144 46800020 */  cvt.s.w   $f0, $f0
/* 90F7F8 80240148 E600FFFC */  swc1      $f0, -4($s0)
/* 90F7FC 8024014C AE000000 */  sw        $zero, ($s0)
.L80240150:
/* 90F800 80240150 C6040004 */  lwc1      $f4, 4($s0)
/* 90F804 80240154 46002121 */  cvt.d.s   $f4, $f4
/* 90F808 80240158 46342102 */  mul.d     $f4, $f4, $f20
/* 90F80C 8024015C 00000000 */  nop
/* 90F810 80240160 C602000C */  lwc1      $f2, 0xc($s0)
/* 90F814 80240164 460010A1 */  cvt.d.s   $f2, $f2
/* 90F818 80240168 46341082 */  mul.d     $f2, $f2, $f20
/* 90F81C 8024016C 00000000 */  nop
/* 90F820 80240170 C6000008 */  lwc1      $f0, 8($s0)
/* 90F824 80240174 3C018024 */  lui       $at, %hi(D_80246378_915A28)
/* 90F828 80240178 D4266378 */  ldc1      $f6, %lo(D_80246378_915A28)($at)
/* 90F82C 8024017C 46000021 */  cvt.d.s   $f0, $f0
/* 90F830 80240180 46260000 */  add.d     $f0, $f0, $f6
/* 90F834 80240184 46200020 */  cvt.s.d   $f0, $f0
/* 90F838 80240188 E6000008 */  swc1      $f0, 8($s0)
/* 90F83C 8024018C 46202120 */  cvt.s.d   $f4, $f4
/* 90F840 80240190 462010A0 */  cvt.s.d   $f2, $f2
/* 90F844 80240194 E6040004 */  swc1      $f4, 4($s0)
/* 90F848 80240198 E602000C */  swc1      $f2, 0xc($s0)
/* 90F84C 8024019C C6200000 */  lwc1      $f0, ($s1)
/* 90F850 802401A0 46002086 */  mov.s     $f2, $f4
/* 90F854 802401A4 46020000 */  add.s     $f0, $f0, $f2
/* 90F858 802401A8 E6200000 */  swc1      $f0, ($s1)
/* 90F85C 802401AC C600FFEC */  lwc1      $f0, -0x14($s0)
/* 90F860 802401B0 C6020008 */  lwc1      $f2, 8($s0)
/* 90F864 802401B4 46020000 */  add.s     $f0, $f0, $f2
/* 90F868 802401B8 E600FFEC */  swc1      $f0, -0x14($s0)
/* 90F86C 802401BC 46000186 */  mov.s     $f6, $f0
/* 90F870 802401C0 3C01437F */  lui       $at, 0x437f
/* 90F874 802401C4 44810000 */  mtc1      $at, $f0
/* 90F878 802401C8 00000000 */  nop
/* 90F87C 802401CC 46003182 */  mul.s     $f6, $f6, $f0
/* 90F880 802401D0 00000000 */  nop
/* 90F884 802401D4 C604FFF0 */  lwc1      $f4, -0x10($s0)
/* 90F888 802401D8 C600000C */  lwc1      $f0, 0xc($s0)
/* 90F88C 802401DC C602FFF8 */  lwc1      $f2, -8($s0)
/* 90F890 802401E0 46002100 */  add.s     $f4, $f4, $f0
/* 90F894 802401E4 3C014000 */  lui       $at, 0x4000
/* 90F898 802401E8 44810000 */  mtc1      $at, $f0
/* 90F89C 802401EC 00000000 */  nop
/* 90F8A0 802401F0 46001080 */  add.s     $f2, $f2, $f0
/* 90F8A4 802401F4 E604FFF0 */  swc1      $f4, -0x10($s0)
/* 90F8A8 802401F8 46183183 */  div.s     $f6, $f6, $f24
/* 90F8AC 802401FC 4600320D */  trunc.w.s $f8, $f6
/* 90F8B0 80240200 44064000 */  mfc1      $a2, $f8
/* 90F8B4 80240204 00000000 */  nop
/* 90F8B8 80240208 04C10002 */  bgez      $a2, .L80240214
/* 90F8BC 8024020C E602FFF8 */   swc1     $f2, -8($s0)
/* 90F8C0 80240210 0000302D */  daddu     $a2, $zero, $zero
.L80240214:
/* 90F8C4 80240214 28C20100 */  slti      $v0, $a2, 0x100
/* 90F8C8 80240218 50400001 */  beql      $v0, $zero, .L80240220
/* 90F8CC 8024021C 240600FF */   addiu    $a2, $zero, 0xff
.L80240220:
/* 90F8D0 80240220 3C05E6FF */  lui       $a1, 0xe6ff
/* 90F8D4 80240224 34A5FFFF */  ori       $a1, $a1, 0xffff
/* 90F8D8 80240228 3C02FA00 */  lui       $v0, 0xfa00
/* 90F8DC 8024022C 8E430000 */  lw        $v1, ($s2)
/* 90F8E0 80240230 26730001 */  addiu     $s3, $s3, 1
/* 90F8E4 80240234 0060202D */  daddu     $a0, $v1, $zero
/* 90F8E8 80240238 24630008 */  addiu     $v1, $v1, 8
/* 90F8EC 8024023C AC820000 */  sw        $v0, ($a0)
/* 90F8F0 80240240 3C02F900 */  lui       $v0, 0xf900
/* 90F8F4 80240244 AC850004 */  sw        $a1, 4($a0)
/* 90F8F8 80240248 AC620000 */  sw        $v0, ($v1)
/* 90F8FC 8024024C 30C200FF */  andi      $v0, $a2, 0xff
/* 90F900 80240250 AC620004 */  sw        $v0, 4($v1)
/* 90F904 80240254 96A40000 */  lhu       $a0, ($s5)
/* 90F908 80240258 C600FFF4 */  lwc1      $f0, -0xc($s0)
/* 90F90C 8024025C 00042180 */  sll       $a0, $a0, 6
/* 90F910 80240260 E7A00010 */  swc1      $f0, 0x10($sp)
/* 90F914 80240264 8EC20000 */  lw        $v0, ($s6)
/* 90F918 80240268 C6200000 */  lwc1      $f0, ($s1)
/* 90F91C 8024026C 00942021 */  addu      $a0, $a0, $s4
/* 90F920 80240270 AE430000 */  sw        $v1, ($s2)
/* 90F924 80240274 24630008 */  addiu     $v1, $v1, 8
/* 90F928 80240278 E7A00014 */  swc1      $f0, 0x14($sp)
/* 90F92C 8024027C C600FFEC */  lwc1      $f0, -0x14($s0)
/* 90F930 80240280 26310028 */  addiu     $s1, $s1, 0x28
/* 90F934 80240284 AE430000 */  sw        $v1, ($s2)
/* 90F938 80240288 E7A00018 */  swc1      $f0, 0x18($sp)
/* 90F93C 8024028C C600FFF0 */  lwc1      $f0, -0x10($s0)
/* 90F940 80240290 00442021 */  addu      $a0, $v0, $a0
/* 90F944 80240294 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 90F948 80240298 8E05FFF8 */  lw        $a1, -8($s0)
/* 90F94C 8024029C 8E06FFFC */  lw        $a2, -4($s0)
/* 90F950 802402A0 8E070000 */  lw        $a3, ($s0)
/* 90F954 802402A4 0C01903A */  jal       guPosition
/* 90F958 802402A8 26100028 */   addiu    $s0, $s0, 0x28
/* 90F95C 802402AC 3C06D838 */  lui       $a2, 0xd838
/* 90F960 802402B0 8E440000 */  lw        $a0, ($s2)
/* 90F964 802402B4 34C60002 */  ori       $a2, $a2, 2
/* 90F968 802402B8 0080282D */  daddu     $a1, $a0, $zero
/* 90F96C 802402BC 24840008 */  addiu     $a0, $a0, 8
/* 90F970 802402C0 AE440000 */  sw        $a0, ($s2)
/* 90F974 802402C4 96A20000 */  lhu       $v0, ($s5)
/* 90F978 802402C8 3C03DA38 */  lui       $v1, 0xda38
/* 90F97C 802402CC ACA30000 */  sw        $v1, ($a1)
/* 90F980 802402D0 24430001 */  addiu     $v1, $v0, 1
/* 90F984 802402D4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 90F988 802402D8 00021180 */  sll       $v0, $v0, 6
/* 90F98C 802402DC A6A30000 */  sh        $v1, ($s5)
/* 90F990 802402E0 8EC30000 */  lw        $v1, ($s6)
/* 90F994 802402E4 00541021 */  addu      $v0, $v0, $s4
/* 90F998 802402E8 00621821 */  addu      $v1, $v1, $v0
/* 90F99C 802402EC 24820008 */  addiu     $v0, $a0, 8
/* 90F9A0 802402F0 ACA30004 */  sw        $v1, 4($a1)
/* 90F9A4 802402F4 AE420000 */  sw        $v0, ($s2)
/* 90F9A8 802402F8 3C02DE00 */  lui       $v0, 0xde00
/* 90F9AC 802402FC AC820000 */  sw        $v0, ($a0)
/* 90F9B0 80240300 3C028024 */  lui       $v0, %hi(D_80243E00_9134B0)
/* 90F9B4 80240304 24423E00 */  addiu     $v0, $v0, %lo(D_80243E00_9134B0)
/* 90F9B8 80240308 AC820004 */  sw        $v0, 4($a0)
/* 90F9BC 8024030C 24820010 */  addiu     $v0, $a0, 0x10
/* 90F9C0 80240310 AE420000 */  sw        $v0, ($s2)
/* 90F9C4 80240314 24020040 */  addiu     $v0, $zero, 0x40
/* 90F9C8 80240318 AC82000C */  sw        $v0, 0xc($a0)
/* 90F9CC 8024031C 2A620014 */  slti      $v0, $s3, 0x14
/* 90F9D0 80240320 1440FF58 */  bnez      $v0, .L80240084
/* 90F9D4 80240324 AC860008 */   sw       $a2, 8($a0)
/* 90F9D8 80240328 3C05E200 */  lui       $a1, 0xe200
/* 90F9DC 8024032C 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 90F9E0 80240330 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 90F9E4 80240334 8C820000 */  lw        $v0, ($a0)
/* 90F9E8 80240338 34A51E01 */  ori       $a1, $a1, 0x1e01
/* 90F9EC 8024033C 0040182D */  daddu     $v1, $v0, $zero
/* 90F9F0 80240340 24420008 */  addiu     $v0, $v0, 8
/* 90F9F4 80240344 AC820000 */  sw        $v0, ($a0)
/* 90F9F8 80240348 AC650000 */  sw        $a1, ($v1)
/* 90F9FC 8024034C AC600004 */  sw        $zero, 4($v1)
/* 90FA00 80240350 24430008 */  addiu     $v1, $v0, 8
/* 90FA04 80240354 AC830000 */  sw        $v1, ($a0)
/* 90FA08 80240358 3C03E700 */  lui       $v1, 0xe700
/* 90FA0C 8024035C AC430000 */  sw        $v1, ($v0)
/* 90FA10 80240360 AC400004 */  sw        $zero, 4($v0)
/* 90FA14 80240364 8FBF003C */  lw        $ra, 0x3c($sp)
/* 90FA18 80240368 8FB60038 */  lw        $s6, 0x38($sp)
/* 90FA1C 8024036C 8FB50034 */  lw        $s5, 0x34($sp)
/* 90FA20 80240370 8FB40030 */  lw        $s4, 0x30($sp)
/* 90FA24 80240374 8FB3002C */  lw        $s3, 0x2c($sp)
/* 90FA28 80240378 8FB20028 */  lw        $s2, 0x28($sp)
/* 90FA2C 8024037C 8FB10024 */  lw        $s1, 0x24($sp)
/* 90FA30 80240380 8FB00020 */  lw        $s0, 0x20($sp)
/* 90FA34 80240384 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 90FA38 80240388 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 90FA3C 8024038C D7B40040 */  ldc1      $f20, 0x40($sp)
/* 90FA40 80240390 03E00008 */  jr        $ra
/* 90FA44 80240394 27BD0058 */   addiu    $sp, $sp, 0x58
