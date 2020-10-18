.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BE070
/* 31DBE0 802BE070 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* 31DBE4 802BE074 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* 31DBE8 802BE078 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 31DBEC 802BE07C AFBF0024 */  sw        $ra, 0x24($sp)
/* 31DBF0 802BE080 AFB40020 */  sw        $s4, 0x20($sp)
/* 31DBF4 802BE084 AFB3001C */  sw        $s3, 0x1c($sp)
/* 31DBF8 802BE088 AFB20018 */  sw        $s2, 0x18($sp)
/* 31DBFC 802BE08C AFB10014 */  sw        $s1, 0x14($sp)
/* 31DC00 802BE090 AFB00010 */  sw        $s0, 0x10($sp)
/* 31DC04 802BE094 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 31DC08 802BE098 10400060 */  beqz      $v0, .L802BE21C
/* 31DC0C 802BE09C F7B40028 */   sdc1     $f20, 0x28($sp)
/* 31DC10 802BE0A0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 31DC14 802BE0A4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 31DC18 802BE0A8 3C0142B4 */  lui       $at, 0x42b4
/* 31DC1C 802BE0AC 44810000 */  mtc1      $at, $f0
/* 31DC20 802BE0B0 C44200A8 */  lwc1      $f2, 0xa8($v0)
/* 31DC24 802BE0B4 4600103C */  c.lt.s    $f2, $f0
/* 31DC28 802BE0B8 00000000 */  nop       
/* 31DC2C 802BE0BC 45010008 */  bc1t      .L802BE0E0
/* 31DC30 802BE0C0 00000000 */   nop      
/* 31DC34 802BE0C4 3C014387 */  lui       $at, 0x4387
/* 31DC38 802BE0C8 44810000 */  mtc1      $at, $f0
/* 31DC3C 802BE0CC 00000000 */  nop       
/* 31DC40 802BE0D0 4602003C */  c.lt.s    $f0, $f2
/* 31DC44 802BE0D4 00000000 */  nop       
/* 31DC48 802BE0D8 45000008 */  bc1f      .L802BE0FC
/* 31DC4C 802BE0DC 3C030100 */   lui      $v1, 0x100
.L802BE0E0:
/* 31DC50 802BE0E0 8C4200A4 */  lw        $v0, 0xa4($v0)
/* 31DC54 802BE0E4 3C030100 */  lui       $v1, 0x100
/* 31DC58 802BE0E8 00431024 */  and       $v0, $v0, $v1
/* 31DC5C 802BE0EC 10400007 */  beqz      $v0, .L802BE10C
/* 31DC60 802BE0F0 24030005 */   addiu    $v1, $zero, 5
/* 31DC64 802BE0F4 080AF844 */  j         .L802BE110
/* 31DC68 802BE0F8 00000000 */   nop      
.L802BE0FC:
/* 31DC6C 802BE0FC 8C4200A4 */  lw        $v0, 0xa4($v0)
/* 31DC70 802BE100 00431024 */  and       $v0, $v0, $v1
/* 31DC74 802BE104 10400002 */  beqz      $v0, .L802BE110
/* 31DC78 802BE108 24030005 */   addiu    $v1, $zero, 5
.L802BE10C:
/* 31DC7C 802BE10C 2403FFFB */  addiu     $v1, $zero, -5
.L802BE110:
/* 31DC80 802BE110 3C013F19 */  lui       $at, 0x3f19
/* 31DC84 802BE114 3421999A */  ori       $at, $at, 0x999a
/* 31DC88 802BE118 4481B000 */  mtc1      $at, $f22
/* 31DC8C 802BE11C 3C11800F */  lui       $s1, %hi(gPlayerStatusPtr)
/* 31DC90 802BE120 26317B30 */  addiu     $s1, $s1, %lo(gPlayerStatusPtr)
/* 31DC94 802BE124 3C02800B */  lui       $v0, %hi(gCameras)
/* 31DC98 802BE128 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 31DC9C 802BE12C C454006C */  lwc1      $f20, 0x6c($v0)
/* 31DCA0 802BE130 3C014387 */  lui       $at, 0x4387
/* 31DCA4 802BE134 44810000 */  mtc1      $at, $f0
/* 31DCA8 802BE138 8E340000 */  lw        $s4, ($s1)
/* 31DCAC 802BE13C 4600A500 */  add.s     $f20, $f20, $f0
/* 31DCB0 802BE140 C68000A8 */  lwc1      $f0, 0xa8($s4)
/* 31DCB4 802BE144 4600A501 */  sub.s     $f20, $f20, $f0
/* 31DCB8 802BE148 44830000 */  mtc1      $v1, $f0
/* 31DCBC 802BE14C 00000000 */  nop       
/* 31DCC0 802BE150 46800020 */  cvt.s.w   $f0, $f0
/* 31DCC4 802BE154 4600A500 */  add.s     $f20, $f20, $f0
/* 31DCC8 802BE158 3C0140C9 */  lui       $at, 0x40c9
/* 31DCCC 802BE15C 34210FD0 */  ori       $at, $at, 0xfd0
/* 31DCD0 802BE160 44810000 */  mtc1      $at, $f0
/* 31DCD4 802BE164 00000000 */  nop       
/* 31DCD8 802BE168 4600A502 */  mul.s     $f20, $f20, $f0
/* 31DCDC 802BE16C 00000000 */  nop       
/* 31DCE0 802BE170 3C108011 */  lui       $s0, 0x8011
/* 31DCE4 802BE174 2610C930 */  addiu     $s0, $s0, -0x36d0
/* 31DCE8 802BE178 3C0143B4 */  lui       $at, 0x43b4
/* 31DCEC 802BE17C 44810000 */  mtc1      $at, $f0
/* 31DCF0 802BE180 8E120000 */  lw        $s2, ($s0)
/* 31DCF4 802BE184 4600A503 */  div.s     $f20, $f20, $f0
/* 31DCF8 802BE188 0C00A85B */  jal       sin_rad
/* 31DCFC 802BE18C 4600A306 */   mov.s    $f12, $f20
/* 31DD00 802BE190 8E330000 */  lw        $s3, ($s1)
/* 31DD04 802BE194 866200B2 */  lh        $v0, 0xb2($s3)
/* 31DD08 802BE198 44821000 */  mtc1      $v0, $f2
/* 31DD0C 802BE19C 00000000 */  nop       
/* 31DD10 802BE1A0 468010A0 */  cvt.s.w   $f2, $f2
/* 31DD14 802BE1A4 46020002 */  mul.s     $f0, $f0, $f2
/* 31DD18 802BE1A8 00000000 */  nop       
/* 31DD1C 802BE1AC 46160002 */  mul.s     $f0, $f0, $f22
/* 31DD20 802BE1B0 00000000 */  nop       
/* 31DD24 802BE1B4 C6820028 */  lwc1      $f2, 0x28($s4)
/* 31DD28 802BE1B8 46001080 */  add.s     $f2, $f2, $f0
/* 31DD2C 802BE1BC E6420038 */  swc1      $f2, 0x38($s2)
/* 31DD30 802BE1C0 8E120000 */  lw        $s2, ($s0)
/* 31DD34 802BE1C4 0C00A874 */  jal       cos_rad
/* 31DD38 802BE1C8 4600A306 */   mov.s    $f12, $f20
/* 31DD3C 802BE1CC 8E230000 */  lw        $v1, ($s1)
/* 31DD40 802BE1D0 846200B2 */  lh        $v0, 0xb2($v1)
/* 31DD44 802BE1D4 44821000 */  mtc1      $v0, $f2
/* 31DD48 802BE1D8 00000000 */  nop       
/* 31DD4C 802BE1DC 468010A0 */  cvt.s.w   $f2, $f2
/* 31DD50 802BE1E0 46020002 */  mul.s     $f0, $f0, $f2
/* 31DD54 802BE1E4 00000000 */  nop       
/* 31DD58 802BE1E8 46160002 */  mul.s     $f0, $f0, $f22
/* 31DD5C 802BE1EC 00000000 */  nop       
/* 31DD60 802BE1F0 C6620030 */  lwc1      $f2, 0x30($s3)
/* 31DD64 802BE1F4 46001081 */  sub.s     $f2, $f2, $f0
/* 31DD68 802BE1F8 E6420040 */  swc1      $f2, 0x40($s2)
/* 31DD6C 802BE1FC 8E020000 */  lw        $v0, ($s0)
/* 31DD70 802BE200 C4600080 */  lwc1      $f0, 0x80($v1)
/* 31DD74 802BE204 3C0140A0 */  lui       $at, 0x40a0
/* 31DD78 802BE208 44811000 */  mtc1      $at, $f2
/* 31DD7C 802BE20C E440000C */  swc1      $f0, 0xc($v0)
/* 31DD80 802BE210 C460002C */  lwc1      $f0, 0x2c($v1)
/* 31DD84 802BE214 46020000 */  add.s     $f0, $f0, $f2
/* 31DD88 802BE218 E440003C */  swc1      $f0, 0x3c($v0)
.L802BE21C:
/* 31DD8C 802BE21C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 31DD90 802BE220 8FB40020 */  lw        $s4, 0x20($sp)
/* 31DD94 802BE224 8FB3001C */  lw        $s3, 0x1c($sp)
/* 31DD98 802BE228 8FB20018 */  lw        $s2, 0x18($sp)
/* 31DD9C 802BE22C 8FB10014 */  lw        $s1, 0x14($sp)
/* 31DDA0 802BE230 8FB00010 */  lw        $s0, 0x10($sp)
/* 31DDA4 802BE234 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 31DDA8 802BE238 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 31DDAC 802BE23C 03E00008 */  jr        $ra
/* 31DDB0 802BE240 27BD0038 */   addiu    $sp, $sp, 0x38
/* 31DDB4 802BE244 00000000 */  nop       
/* 31DDB8 802BE248 00000000 */  nop       
/* 31DDBC 802BE24C 00000000 */  nop       
