.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024013C_B1D89C
/* B1D89C 8024013C 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* B1D8A0 80240140 27A40010 */  addiu     $a0, $sp, 0x10
/* B1D8A4 80240144 0000302D */  daddu     $a2, $zero, $zero
/* B1D8A8 80240148 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* B1D8AC 8024014C 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* B1D8B0 80240150 AFB00090 */  sw        $s0, 0x90($sp)
/* B1D8B4 80240154 3C108024 */  lui       $s0, %hi(D_80242BF8_B20358)
/* B1D8B8 80240158 26102BF8 */  addiu     $s0, $s0, %lo(D_80242BF8_B20358)
/* B1D8BC 8024015C AFBF00A4 */  sw        $ra, 0xa4($sp)
/* B1D8C0 80240160 AFB400A0 */  sw        $s4, 0xa0($sp)
/* B1D8C4 80240164 AFB3009C */  sw        $s3, 0x9c($sp)
/* B1D8C8 80240168 AFB20098 */  sw        $s2, 0x98($sp)
/* B1D8CC 8024016C AFB10094 */  sw        $s1, 0x94($sp)
/* B1D8D0 80240170 F7BA00C0 */  sdc1      $f26, 0xc0($sp)
/* B1D8D4 80240174 F7B800B8 */  sdc1      $f24, 0xb8($sp)
/* B1D8D8 80240178 F7B600B0 */  sdc1      $f22, 0xb0($sp)
/* B1D8DC 8024017C F7B400A8 */  sdc1      $f20, 0xa8($sp)
/* B1D8E0 80240180 8C650028 */  lw        $a1, 0x28($v1)
/* B1D8E4 80240184 8E020000 */  lw        $v0, ($s0)
/* B1D8E8 80240188 8C670030 */  lw        $a3, 0x30($v1)
/* B1D8EC 8024018C 24420001 */  addiu     $v0, $v0, 1
/* B1D8F0 80240190 0C019E40 */  jal       guTranslateF
/* B1D8F4 80240194 AE020000 */   sw       $v0, ($s0)
/* B1D8F8 80240198 3C014248 */  lui       $at, 0x4248
/* B1D8FC 8024019C 4481D000 */  mtc1      $at, $f26
/* B1D900 802401A0 C60C0000 */  lwc1      $f12, ($s0)
/* B1D904 802401A4 46806320 */  cvt.s.w   $f12, $f12
/* B1D908 802401A8 0C00A85B */  jal       sin_rad
/* B1D90C 802401AC 461A6303 */   div.s    $f12, $f12, $f26
/* B1D910 802401B0 3C013FE0 */  lui       $at, 0x3fe0
/* B1D914 802401B4 4481C800 */  mtc1      $at, $f25
/* B1D918 802401B8 4480C000 */  mtc1      $zero, $f24
/* B1D91C 802401BC 460005A1 */  cvt.d.s   $f22, $f0
/* B1D920 802401C0 4638B582 */  mul.d     $f22, $f22, $f24
/* B1D924 802401C4 00000000 */  nop
/* B1D928 802401C8 4638B580 */  add.d     $f22, $f22, $f24
/* B1D92C 802401CC C60C0000 */  lwc1      $f12, ($s0)
/* B1D930 802401D0 46806320 */  cvt.s.w   $f12, $f12
/* B1D934 802401D4 461A6303 */  div.s     $f12, $f12, $f26
/* B1D938 802401D8 0C00A874 */  jal       cos_rad
/* B1D93C 802401DC 4620B5A0 */   cvt.s.d  $f22, $f22
/* B1D940 802401E0 C60C0000 */  lwc1      $f12, ($s0)
/* B1D944 802401E4 46806320 */  cvt.s.w   $f12, $f12
/* B1D948 802401E8 461A6303 */  div.s     $f12, $f12, $f26
/* B1D94C 802401EC 0C00A874 */  jal       cos_rad
/* B1D950 802401F0 46000506 */   mov.s    $f20, $f0
/* B1D954 802401F4 4600A502 */  mul.s     $f20, $f20, $f0
/* B1D958 802401F8 00000000 */  nop
/* B1D95C 802401FC 3C018024 */  lui       $at, %hi(D_80242D00_B20460)
/* B1D960 80240200 D4202D00 */  ldc1      $f0, %lo(D_80242D00_B20460)($at)
/* B1D964 80240204 4600A521 */  cvt.d.s   $f20, $f20
/* B1D968 80240208 4620A500 */  add.d     $f20, $f20, $f0
/* B1D96C 8024020C C60C0000 */  lwc1      $f12, ($s0)
/* B1D970 80240210 46806320 */  cvt.s.w   $f12, $f12
/* B1D974 80240214 461A6303 */  div.s     $f12, $f12, $f26
/* B1D978 80240218 0C00A85B */  jal       sin_rad
/* B1D97C 8024021C 4620A520 */   cvt.s.d  $f20, $f20
/* B1D980 80240220 46000021 */  cvt.d.s   $f0, $f0
/* B1D984 80240224 46380002 */  mul.d     $f0, $f0, $f24
/* B1D988 80240228 00000000 */  nop
/* B1D98C 8024022C 3C140001 */  lui       $s4, 1
/* B1D990 80240230 36941630 */  ori       $s4, $s4, 0x1630
/* B1D994 80240234 27B00050 */  addiu     $s0, $sp, 0x50
/* B1D998 80240238 46380000 */  add.d     $f0, $f0, $f24
/* B1D99C 8024023C 4405B000 */  mfc1      $a1, $f22
/* B1D9A0 80240240 4406A000 */  mfc1      $a2, $f20
/* B1D9A4 80240244 46200020 */  cvt.s.d   $f0, $f0
/* B1D9A8 80240248 44070000 */  mfc1      $a3, $f0
/* B1D9AC 8024024C 0C019DF0 */  jal       guScaleF
/* B1D9B0 80240250 0200202D */   daddu    $a0, $s0, $zero
/* B1D9B4 80240254 0200202D */  daddu     $a0, $s0, $zero
/* B1D9B8 80240258 27A50010 */  addiu     $a1, $sp, 0x10
/* B1D9BC 8024025C 0C019D80 */  jal       guMtxCatF
/* B1D9C0 80240260 00A0302D */   daddu    $a2, $a1, $zero
/* B1D9C4 80240264 27A40010 */  addiu     $a0, $sp, 0x10
/* B1D9C8 80240268 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* B1D9CC 8024026C 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* B1D9D0 80240270 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* B1D9D4 80240274 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* B1D9D8 80240278 96250000 */  lhu       $a1, ($s1)
/* B1D9DC 8024027C 8E420000 */  lw        $v0, ($s2)
/* B1D9E0 80240280 00052980 */  sll       $a1, $a1, 6
/* B1D9E4 80240284 00B42821 */  addu      $a1, $a1, $s4
/* B1D9E8 80240288 0C019D40 */  jal       guMtxF2L
/* B1D9EC 8024028C 00452821 */   addu     $a1, $v0, $a1
/* B1D9F0 80240290 24040001 */  addiu     $a0, $zero, 1
/* B1D9F4 80240294 3C138024 */  lui       $s3, %hi(D_80242860_B1FFC0)
/* B1D9F8 80240298 26732860 */  addiu     $s3, $s3, %lo(D_80242860_B1FFC0)
/* B1D9FC 8024029C 0260282D */  daddu     $a1, $s3, $zero
/* B1DA00 802402A0 27A60010 */  addiu     $a2, $sp, 0x10
/* B1DA04 802402A4 0C0470CB */  jal       mdl_project_tex_coords
/* B1DA08 802402A8 0000382D */   daddu    $a3, $zero, $zero
/* B1DA0C 802402AC 3C07E300 */  lui       $a3, 0xe300
/* B1DA10 802402B0 34E70A01 */  ori       $a3, $a3, 0xa01
/* B1DA14 802402B4 3C09E200 */  lui       $t1, 0xe200
/* B1DA18 802402B8 3529001C */  ori       $t1, $t1, 0x1c
/* B1DA1C 802402BC 3C080055 */  lui       $t0, 0x55
/* B1DA20 802402C0 35082078 */  ori       $t0, $t0, 0x2078
/* B1DA24 802402C4 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* B1DA28 802402C8 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* B1DA2C 802402CC 0200202D */  daddu     $a0, $s0, $zero
/* B1DA30 802402D0 24050001 */  addiu     $a1, $zero, 1
/* B1DA34 802402D4 8E020000 */  lw        $v0, ($s0)
/* B1DA38 802402D8 3C03E700 */  lui       $v1, 0xe700
/* B1DA3C 802402DC 0040302D */  daddu     $a2, $v0, $zero
/* B1DA40 802402E0 24420008 */  addiu     $v0, $v0, 8
/* B1DA44 802402E4 AE020000 */  sw        $v0, ($s0)
/* B1DA48 802402E8 ACC30000 */  sw        $v1, ($a2)
/* B1DA4C 802402EC 24430008 */  addiu     $v1, $v0, 8
/* B1DA50 802402F0 ACC00004 */  sw        $zero, 4($a2)
/* B1DA54 802402F4 AE030000 */  sw        $v1, ($s0)
/* B1DA58 802402F8 24430010 */  addiu     $v1, $v0, 0x10
/* B1DA5C 802402FC AC470000 */  sw        $a3, ($v0)
/* B1DA60 80240300 AC400004 */  sw        $zero, 4($v0)
/* B1DA64 80240304 AE030000 */  sw        $v1, ($s0)
/* B1DA68 80240308 AC490008 */  sw        $t1, 8($v0)
/* B1DA6C 8024030C 0C0475CB */  jal       mdl_draw_hidden_panel_surface
/* B1DA70 80240310 AC48000C */   sw       $t0, 0xc($v0)
/* B1DA74 80240314 3C03DA38 */  lui       $v1, 0xda38
/* B1DA78 80240318 34630002 */  ori       $v1, $v1, 2
/* B1DA7C 8024031C 3C06D838 */  lui       $a2, 0xd838
/* B1DA80 80240320 34C60002 */  ori       $a2, $a2, 2
/* B1DA84 80240324 8E040000 */  lw        $a0, ($s0)
/* B1DA88 80240328 96220000 */  lhu       $v0, ($s1)
/* B1DA8C 8024032C 0080282D */  daddu     $a1, $a0, $zero
/* B1DA90 80240330 24840008 */  addiu     $a0, $a0, 8
/* B1DA94 80240334 AE040000 */  sw        $a0, ($s0)
/* B1DA98 80240338 ACA30000 */  sw        $v1, ($a1)
/* B1DA9C 8024033C 24430001 */  addiu     $v1, $v0, 1
/* B1DAA0 80240340 3042FFFF */  andi      $v0, $v0, 0xffff
/* B1DAA4 80240344 00021180 */  sll       $v0, $v0, 6
/* B1DAA8 80240348 A6230000 */  sh        $v1, ($s1)
/* B1DAAC 8024034C 8E430000 */  lw        $v1, ($s2)
/* B1DAB0 80240350 00541021 */  addu      $v0, $v0, $s4
/* B1DAB4 80240354 00621821 */  addu      $v1, $v1, $v0
/* B1DAB8 80240358 24820008 */  addiu     $v0, $a0, 8
/* B1DABC 8024035C ACA30004 */  sw        $v1, 4($a1)
/* B1DAC0 80240360 AE020000 */  sw        $v0, ($s0)
/* B1DAC4 80240364 3C02DE00 */  lui       $v0, 0xde00
/* B1DAC8 80240368 AC820000 */  sw        $v0, ($a0)
/* B1DACC 8024036C 24820010 */  addiu     $v0, $a0, 0x10
/* B1DAD0 80240370 AC930004 */  sw        $s3, 4($a0)
/* B1DAD4 80240374 AE020000 */  sw        $v0, ($s0)
/* B1DAD8 80240378 24020040 */  addiu     $v0, $zero, 0x40
/* B1DADC 8024037C AC860008 */  sw        $a2, 8($a0)
/* B1DAE0 80240380 AC82000C */  sw        $v0, 0xc($a0)
/* B1DAE4 80240384 8FBF00A4 */  lw        $ra, 0xa4($sp)
/* B1DAE8 80240388 8FB400A0 */  lw        $s4, 0xa0($sp)
/* B1DAEC 8024038C 8FB3009C */  lw        $s3, 0x9c($sp)
/* B1DAF0 80240390 8FB20098 */  lw        $s2, 0x98($sp)
/* B1DAF4 80240394 8FB10094 */  lw        $s1, 0x94($sp)
/* B1DAF8 80240398 8FB00090 */  lw        $s0, 0x90($sp)
/* B1DAFC 8024039C D7BA00C0 */  ldc1      $f26, 0xc0($sp)
/* B1DB00 802403A0 D7B800B8 */  ldc1      $f24, 0xb8($sp)
/* B1DB04 802403A4 D7B600B0 */  ldc1      $f22, 0xb0($sp)
/* B1DB08 802403A8 D7B400A8 */  ldc1      $f20, 0xa8($sp)
/* B1DB0C 802403AC 03E00008 */  jr        $ra
/* B1DB10 802403B0 27BD00C8 */   addiu    $sp, $sp, 0xc8
/* B1DB14 802403B4 00000000 */  nop
/* B1DB18 802403B8 00000000 */  nop
/* B1DB1C 802403BC 00000000 */  nop
