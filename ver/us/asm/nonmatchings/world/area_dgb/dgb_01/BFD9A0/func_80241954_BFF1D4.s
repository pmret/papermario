.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241954_BFF1D4
/* BFF1D4 80241954 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BFF1D8 80241958 AFB40040 */  sw        $s4, 0x40($sp)
/* BFF1DC 8024195C 0080A02D */  daddu     $s4, $a0, $zero
/* BFF1E0 80241960 AFBF0044 */  sw        $ra, 0x44($sp)
/* BFF1E4 80241964 AFB3003C */  sw        $s3, 0x3c($sp)
/* BFF1E8 80241968 AFB20038 */  sw        $s2, 0x38($sp)
/* BFF1EC 8024196C AFB10034 */  sw        $s1, 0x34($sp)
/* BFF1F0 80241970 AFB00030 */  sw        $s0, 0x30($sp)
/* BFF1F4 80241974 8E930148 */  lw        $s3, 0x148($s4)
/* BFF1F8 80241978 00A0802D */  daddu     $s0, $a1, $zero
/* BFF1FC 8024197C 86640008 */  lh        $a0, 8($s3)
/* BFF200 80241980 0C00EABB */  jal       get_npc_unsafe
/* BFF204 80241984 00C0882D */   daddu    $s1, $a2, $zero
/* BFF208 80241988 3C048000 */  lui       $a0, 0x8000
/* BFF20C 8024198C 0040902D */  daddu     $s2, $v0, $zero
/* BFF210 80241990 C6400040 */  lwc1      $f0, 0x40($s2)
/* BFF214 80241994 34840011 */  ori       $a0, $a0, 0x11
/* BFF218 80241998 E7A00010 */  swc1      $f0, 0x10($sp)
/* BFF21C 8024199C 8E460038 */  lw        $a2, 0x38($s2)
/* BFF220 802419A0 8E47003C */  lw        $a3, 0x3c($s2)
/* BFF224 802419A4 0C05267B */  jal       sfx_adjust_env_sound_pos
/* BFF228 802419A8 24050002 */   addiu    $a1, $zero, 2
/* BFF22C 802419AC 0220202D */  daddu     $a0, $s1, $zero
/* BFF230 802419B0 24020001 */  addiu     $v0, $zero, 1
/* BFF234 802419B4 AFA20010 */  sw        $v0, 0x10($sp)
/* BFF238 802419B8 8E060024 */  lw        $a2, 0x24($s0)
/* BFF23C 802419BC 8E070028 */  lw        $a3, 0x28($s0)
/* BFF240 802419C0 0C01242D */  jal       func_800490B4
/* BFF244 802419C4 0260282D */   daddu    $a1, $s3, $zero
/* BFF248 802419C8 1440000B */  bnez      $v0, .L802419F8
/* BFF24C 802419CC 3C04FFDF */   lui      $a0, 0xffdf
/* BFF250 802419D0 8E62006C */  lw        $v0, 0x6c($s3)
/* BFF254 802419D4 2403FEFF */  addiu     $v1, $zero, -0x101
/* BFF258 802419D8 00431024 */  and       $v0, $v0, $v1
/* BFF25C 802419DC AE62006C */  sw        $v0, 0x6c($s3)
/* BFF260 802419E0 8E420000 */  lw        $v0, ($s2)
/* BFF264 802419E4 3484FFFF */  ori       $a0, $a0, 0xffff
/* BFF268 802419E8 AE400048 */  sw        $zero, 0x48($s2)
/* BFF26C 802419EC 00441024 */  and       $v0, $v0, $a0
/* BFF270 802419F0 080906F2 */  j         .L80241BC8
/* BFF274 802419F4 AE420000 */   sw       $v0, ($s2)
.L802419F8:
/* BFF278 802419F8 3C10800F */  lui       $s0, %hi(gPlayerStatusPtr)
/* BFF27C 802419FC 26107B30 */  addiu     $s0, $s0, %lo(gPlayerStatusPtr)
/* BFF280 80241A00 C6440048 */  lwc1      $f4, 0x48($s2)
/* BFF284 80241A04 3C0141C8 */  lui       $at, 0x41c8
/* BFF288 80241A08 44810000 */  mtc1      $at, $f0
/* BFF28C 80241A0C 8E020000 */  lw        $v0, ($s0)
/* BFF290 80241A10 46002100 */  add.s     $f4, $f4, $f0
/* BFF294 80241A14 C4420028 */  lwc1      $f2, 0x28($v0)
/* BFF298 80241A18 3C014000 */  lui       $at, 0x4000
/* BFF29C 80241A1C 44810000 */  mtc1      $at, $f0
/* BFF2A0 80241A20 E6420038 */  swc1      $f2, 0x38($s2)
/* BFF2A4 80241A24 C4420030 */  lwc1      $f2, 0x30($v0)
/* BFF2A8 80241A28 46001080 */  add.s     $f2, $f2, $f0
/* BFF2AC 80241A2C 3C018026 */  lui       $at, %hi(D_80263478_C20CF8)
/* BFF2B0 80241A30 D4263478 */  ldc1      $f6, %lo(D_80263478_C20CF8)($at)
/* BFF2B4 80241A34 46002021 */  cvt.d.s   $f0, $f4
/* BFF2B8 80241A38 4620303C */  c.lt.d    $f6, $f0
/* BFF2BC 80241A3C E6440048 */  swc1      $f4, 0x48($s2)
/* BFF2C0 80241A40 45000004 */  bc1f      .L80241A54
/* BFF2C4 80241A44 E6420040 */   swc1     $f2, 0x40($s2)
/* BFF2C8 80241A48 46260001 */  sub.d     $f0, $f0, $f6
/* BFF2CC 80241A4C 46200020 */  cvt.s.d   $f0, $f0
/* BFF2D0 80241A50 E6400048 */  swc1      $f0, 0x48($s2)
.L80241A54:
/* BFF2D4 80241A54 3C02B60B */  lui       $v0, 0xb60b
/* BFF2D8 80241A58 C6400048 */  lwc1      $f0, 0x48($s2)
/* BFF2DC 80241A5C 344260B7 */  ori       $v0, $v0, 0x60b7
/* BFF2E0 80241A60 4600020D */  trunc.w.s $f8, $f0
/* BFF2E4 80241A64 44044000 */  mfc1      $a0, $f8
/* BFF2E8 80241A68 00000000 */  nop
/* BFF2EC 80241A6C 00820018 */  mult      $a0, $v0
/* BFF2F0 80241A70 00041FC3 */  sra       $v1, $a0, 0x1f
/* BFF2F4 80241A74 00004010 */  mfhi      $t0
/* BFF2F8 80241A78 01041021 */  addu      $v0, $t0, $a0
/* BFF2FC 80241A7C 000211C3 */  sra       $v0, $v0, 7
/* BFF300 80241A80 00431023 */  subu      $v0, $v0, $v1
/* BFF304 80241A84 00021840 */  sll       $v1, $v0, 1
/* BFF308 80241A88 00621821 */  addu      $v1, $v1, $v0
/* BFF30C 80241A8C 00031100 */  sll       $v0, $v1, 4
/* BFF310 80241A90 00431023 */  subu      $v0, $v0, $v1
/* BFF314 80241A94 00021080 */  sll       $v0, $v0, 2
/* BFF318 80241A98 00822023 */  subu      $a0, $a0, $v0
/* BFF31C 80241A9C 00042400 */  sll       $a0, $a0, 0x10
/* BFF320 80241AA0 0C00A4F5 */  jal       cosine
/* BFF324 80241AA4 00042403 */   sra      $a0, $a0, 0x10
/* BFF328 80241AA8 3C014260 */  lui       $at, 0x4260
/* BFF32C 80241AAC 44811000 */  mtc1      $at, $f2
/* BFF330 80241AB0 00000000 */  nop
/* BFF334 80241AB4 46020002 */  mul.s     $f0, $f0, $f2
/* BFF338 80241AB8 00000000 */  nop
/* BFF33C 80241ABC 24050006 */  addiu     $a1, $zero, 6
/* BFF340 80241AC0 3C01437F */  lui       $at, 0x437f
/* BFF344 80241AC4 44811000 */  mtc1      $at, $f2
/* BFF348 80241AC8 240200FF */  addiu     $v0, $zero, 0xff
/* BFF34C 80241ACC 46001081 */  sub.s     $f2, $f2, $f0
/* BFF350 80241AD0 AFA20014 */  sw        $v0, 0x14($sp)
/* BFF354 80241AD4 AFA00018 */  sw        $zero, 0x18($sp)
/* BFF358 80241AD8 4600120D */  trunc.w.s $f8, $f2
/* BFF35C 80241ADC 44064000 */  mfc1      $a2, $f8
/* BFF360 80241AE0 00000000 */  nop
/* BFF364 80241AE4 AFA60010 */  sw        $a2, 0x10($sp)
/* BFF368 80241AE8 8E440024 */  lw        $a0, 0x24($s2)
/* BFF36C 80241AEC 0C0B7A25 */  jal       func_802DE894
/* BFF370 80241AF0 00C0382D */   daddu    $a3, $a2, $zero
/* BFF374 80241AF4 27A50020 */  addiu     $a1, $sp, 0x20
/* BFF378 80241AF8 27A60024 */  addiu     $a2, $sp, 0x24
/* BFF37C 80241AFC 8E020000 */  lw        $v0, ($s0)
/* BFF380 80241B00 3C01447A */  lui       $at, 0x447a
/* BFF384 80241B04 44810000 */  mtc1      $at, $f0
/* BFF388 80241B08 C4420028 */  lwc1      $f2, 0x28($v0)
/* BFF38C 80241B0C C444002C */  lwc1      $f4, 0x2c($v0)
/* BFF390 80241B10 C4460030 */  lwc1      $f6, 0x30($v0)
/* BFF394 80241B14 27A2002C */  addiu     $v0, $sp, 0x2c
/* BFF398 80241B18 E7A0002C */  swc1      $f0, 0x2c($sp)
/* BFF39C 80241B1C E7A20020 */  swc1      $f2, 0x20($sp)
/* BFF3A0 80241B20 E7A40024 */  swc1      $f4, 0x24($sp)
/* BFF3A4 80241B24 E7A60028 */  swc1      $f6, 0x28($sp)
/* BFF3A8 80241B28 AFA20010 */  sw        $v0, 0x10($sp)
/* BFF3AC 80241B2C 8E440080 */  lw        $a0, 0x80($s2)
/* BFF3B0 80241B30 0C0372DF */  jal       func_800DCB7C
/* BFF3B4 80241B34 27A70028 */   addiu    $a3, $sp, 0x28
/* BFF3B8 80241B38 C644003C */  lwc1      $f4, 0x3c($s2)
/* BFF3BC 80241B3C C7A00024 */  lwc1      $f0, 0x24($sp)
/* BFF3C0 80241B40 46002001 */  sub.s     $f0, $f4, $f0
/* BFF3C4 80241B44 3C014038 */  lui       $at, 0x4038
/* BFF3C8 80241B48 44811800 */  mtc1      $at, $f3
/* BFF3CC 80241B4C 44801000 */  mtc1      $zero, $f2
/* BFF3D0 80241B50 46000005 */  abs.s     $f0, $f0
/* BFF3D4 80241B54 46000021 */  cvt.d.s   $f0, $f0
/* BFF3D8 80241B58 4620103C */  c.lt.d    $f2, $f0
/* BFF3DC 80241B5C 00000000 */  nop
/* BFF3E0 80241B60 45000008 */  bc1f      .L80241B84
/* BFF3E4 80241B64 3C03FFDF */   lui      $v1, 0xffdf
/* BFF3E8 80241B68 3C018026 */  lui       $at, %hi(D_80263480_C20D00)
/* BFF3EC 80241B6C D4223480 */  ldc1      $f2, %lo(D_80263480_C20D00)($at)
/* BFF3F0 80241B70 46002021 */  cvt.d.s   $f0, $f4
/* BFF3F4 80241B74 46220001 */  sub.d     $f0, $f0, $f2
/* BFF3F8 80241B78 46200020 */  cvt.s.d   $f0, $f0
/* BFF3FC 80241B7C 080906F4 */  j         .L80241BD0
/* BFF400 80241B80 E640003C */   swc1     $f0, 0x3c($s2)
.L80241B84:
/* BFF404 80241B84 8E420000 */  lw        $v0, ($s2)
/* BFF408 80241B88 3463FFFF */  ori       $v1, $v1, 0xffff
/* BFF40C 80241B8C AE400048 */  sw        $zero, 0x48($s2)
/* BFF410 80241B90 00431024 */  and       $v0, $v0, $v1
/* BFF414 80241B94 AE420000 */  sw        $v0, ($s2)
/* BFF418 80241B98 3C038011 */  lui       $v1, %hi(D_8010EBB0+0x3)
/* BFF41C 80241B9C 8063EBB3 */  lb        $v1, %lo(D_8010EBB0+0x3)($v1)
/* BFF420 80241BA0 24020009 */  addiu     $v0, $zero, 9
/* BFF424 80241BA4 10620009 */  beq       $v1, $v0, .L80241BCC
/* BFF428 80241BA8 24020010 */   addiu    $v0, $zero, 0x10
/* BFF42C 80241BAC 0C03805E */  jal       disable_player_input
/* BFF430 80241BB0 00000000 */   nop
/* BFF434 80241BB4 0C03BD8A */  jal       func_800EF628
/* BFF438 80241BB8 00000000 */   nop
/* BFF43C 80241BBC 24020014 */  addiu     $v0, $zero, 0x14
/* BFF440 80241BC0 080906F3 */  j         .L80241BCC
/* BFF444 80241BC4 A640008E */   sh       $zero, 0x8e($s2)
.L80241BC8:
/* BFF448 80241BC8 24020010 */  addiu     $v0, $zero, 0x10
.L80241BCC:
/* BFF44C 80241BCC AE820070 */  sw        $v0, 0x70($s4)
.L80241BD0:
/* BFF450 80241BD0 8FBF0044 */  lw        $ra, 0x44($sp)
/* BFF454 80241BD4 8FB40040 */  lw        $s4, 0x40($sp)
/* BFF458 80241BD8 8FB3003C */  lw        $s3, 0x3c($sp)
/* BFF45C 80241BDC 8FB20038 */  lw        $s2, 0x38($sp)
/* BFF460 80241BE0 8FB10034 */  lw        $s1, 0x34($sp)
/* BFF464 80241BE4 8FB00030 */  lw        $s0, 0x30($sp)
/* BFF468 80241BE8 03E00008 */  jr        $ra
/* BFF46C 80241BEC 27BD0048 */   addiu    $sp, $sp, 0x48
