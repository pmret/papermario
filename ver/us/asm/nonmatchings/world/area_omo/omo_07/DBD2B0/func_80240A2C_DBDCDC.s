.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel omo_07_UnkFunc14
/* DBDCDC 80240A2C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* DBDCE0 80240A30 AFB40040 */  sw        $s4, 0x40($sp)
/* DBDCE4 80240A34 0080A02D */  daddu     $s4, $a0, $zero
/* DBDCE8 80240A38 AFBF0044 */  sw        $ra, 0x44($sp)
/* DBDCEC 80240A3C AFB3003C */  sw        $s3, 0x3c($sp)
/* DBDCF0 80240A40 AFB20038 */  sw        $s2, 0x38($sp)
/* DBDCF4 80240A44 AFB10034 */  sw        $s1, 0x34($sp)
/* DBDCF8 80240A48 AFB00030 */  sw        $s0, 0x30($sp)
/* DBDCFC 80240A4C 8E910148 */  lw        $s1, 0x148($s4)
/* DBDD00 80240A50 00A0902D */  daddu     $s2, $a1, $zero
/* DBDD04 80240A54 86240008 */  lh        $a0, 8($s1)
/* DBDD08 80240A58 0C00EABB */  jal       get_npc_unsafe
/* DBDD0C 80240A5C 00C0982D */   daddu    $s3, $a2, $zero
/* DBDD10 80240A60 8E430014 */  lw        $v1, 0x14($s2)
/* DBDD14 80240A64 04600031 */  bltz      $v1, .L80240B2C
/* DBDD18 80240A68 0040802D */   daddu    $s0, $v0, $zero
/* DBDD1C 80240A6C 0260202D */  daddu     $a0, $s3, $zero
/* DBDD20 80240A70 AFA00010 */  sw        $zero, 0x10($sp)
/* DBDD24 80240A74 8E460024 */  lw        $a2, 0x24($s2)
/* DBDD28 80240A78 8E470028 */  lw        $a3, 0x28($s2)
/* DBDD2C 80240A7C 0C01242D */  jal       func_800490B4
/* DBDD30 80240A80 0220282D */   daddu    $a1, $s1, $zero
/* DBDD34 80240A84 10400029 */  beqz      $v0, .L80240B2C
/* DBDD38 80240A88 0000202D */   daddu    $a0, $zero, $zero
/* DBDD3C 80240A8C 0200282D */  daddu     $a1, $s0, $zero
/* DBDD40 80240A90 0000302D */  daddu     $a2, $zero, $zero
/* DBDD44 80240A94 860300A8 */  lh        $v1, 0xa8($s0)
/* DBDD48 80240A98 3C013F80 */  lui       $at, 0x3f80
/* DBDD4C 80240A9C 44810000 */  mtc1      $at, $f0
/* DBDD50 80240AA0 3C014000 */  lui       $at, 0x4000
/* DBDD54 80240AA4 44811000 */  mtc1      $at, $f2
/* DBDD58 80240AA8 3C01C1A0 */  lui       $at, 0xc1a0
/* DBDD5C 80240AAC 44812000 */  mtc1      $at, $f4
/* DBDD60 80240AB0 2402000F */  addiu     $v0, $zero, 0xf
/* DBDD64 80240AB4 AFA2001C */  sw        $v0, 0x1c($sp)
/* DBDD68 80240AB8 44833000 */  mtc1      $v1, $f6
/* DBDD6C 80240ABC 00000000 */  nop
/* DBDD70 80240AC0 468031A0 */  cvt.s.w   $f6, $f6
/* DBDD74 80240AC4 44073000 */  mfc1      $a3, $f6
/* DBDD78 80240AC8 27A20028 */  addiu     $v0, $sp, 0x28
/* DBDD7C 80240ACC AFA20020 */  sw        $v0, 0x20($sp)
/* DBDD80 80240AD0 E7A00010 */  swc1      $f0, 0x10($sp)
/* DBDD84 80240AD4 E7A20014 */  swc1      $f2, 0x14($sp)
/* DBDD88 80240AD8 0C01BFA4 */  jal       fx_emote
/* DBDD8C 80240ADC E7A40018 */   swc1     $f4, 0x18($sp)
/* DBDD90 80240AE0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DBDD94 80240AE4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DBDD98 80240AE8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DBDD9C 80240AEC C60E0040 */  lwc1      $f14, 0x40($s0)
/* DBDDA0 80240AF0 8C460028 */  lw        $a2, 0x28($v0)
/* DBDDA4 80240AF4 0C00A720 */  jal       atan2
/* DBDDA8 80240AF8 8C470030 */   lw       $a3, 0x30($v0)
/* DBDDAC 80240AFC 0200202D */  daddu     $a0, $s0, $zero
/* DBDDB0 80240B00 240502F4 */  addiu     $a1, $zero, 0x2f4
/* DBDDB4 80240B04 3C060020 */  lui       $a2, 0x20
/* DBDDB8 80240B08 0C012530 */  jal       func_800494C0
/* DBDDBC 80240B0C E480000C */   swc1     $f0, 0xc($a0)
/* DBDDC0 80240B10 8E220018 */  lw        $v0, 0x18($s1)
/* DBDDC4 80240B14 9442002A */  lhu       $v0, 0x2a($v0)
/* DBDDC8 80240B18 30420001 */  andi      $v0, $v0, 1
/* DBDDCC 80240B1C 14400029 */  bnez      $v0, .L80240BC4
/* DBDDD0 80240B20 2402000A */   addiu    $v0, $zero, 0xa
/* DBDDD4 80240B24 080902F1 */  j         .L80240BC4
/* DBDDD8 80240B28 2402000C */   addiu    $v0, $zero, 0xc
.L80240B2C:
/* DBDDDC 80240B2C 8602008C */  lh        $v0, 0x8c($s0)
/* DBDDE0 80240B30 14400025 */  bnez      $v0, .L80240BC8
/* DBDDE4 80240B34 00000000 */   nop
/* DBDDE8 80240B38 9602008E */  lhu       $v0, 0x8e($s0)
/* DBDDEC 80240B3C 2442FFFF */  addiu     $v0, $v0, -1
/* DBDDF0 80240B40 A602008E */  sh        $v0, 0x8e($s0)
/* DBDDF4 80240B44 00021400 */  sll       $v0, $v0, 0x10
/* DBDDF8 80240B48 1440001F */  bnez      $v0, .L80240BC8
/* DBDDFC 80240B4C 00000000 */   nop
/* DBDE00 80240B50 8E820074 */  lw        $v0, 0x74($s4)
/* DBDE04 80240B54 2442FFFF */  addiu     $v0, $v0, -1
/* DBDE08 80240B58 10400019 */  beqz      $v0, .L80240BC0
/* DBDE0C 80240B5C AE820074 */   sw       $v0, 0x74($s4)
/* DBDE10 80240B60 8E220018 */  lw        $v0, 0x18($s1)
/* DBDE14 80240B64 9442002A */  lhu       $v0, 0x2a($v0)
/* DBDE18 80240B68 30420010 */  andi      $v0, $v0, 0x10
/* DBDE1C 80240B6C 14400007 */  bnez      $v0, .L80240B8C
/* DBDE20 80240B70 00000000 */   nop
/* DBDE24 80240B74 C600000C */  lwc1      $f0, 0xc($s0)
/* DBDE28 80240B78 3C014334 */  lui       $at, 0x4334
/* DBDE2C 80240B7C 44816000 */  mtc1      $at, $f12
/* DBDE30 80240B80 0C00A6C9 */  jal       clamp_angle
/* DBDE34 80240B84 460C0300 */   add.s    $f12, $f0, $f12
/* DBDE38 80240B88 E600000C */  swc1      $f0, 0xc($s0)
.L80240B8C:
/* DBDE3C 80240B8C 8E440008 */  lw        $a0, 8($s2)
/* DBDE40 80240B90 000417C2 */  srl       $v0, $a0, 0x1f
/* DBDE44 80240B94 00822021 */  addu      $a0, $a0, $v0
/* DBDE48 80240B98 00042043 */  sra       $a0, $a0, 1
/* DBDE4C 80240B9C 0C00A67F */  jal       rand_int
/* DBDE50 80240BA0 24840001 */   addiu    $a0, $a0, 1
/* DBDE54 80240BA4 8E430008 */  lw        $v1, 8($s2)
/* DBDE58 80240BA8 000327C2 */  srl       $a0, $v1, 0x1f
/* DBDE5C 80240BAC 00641821 */  addu      $v1, $v1, $a0
/* DBDE60 80240BB0 00031843 */  sra       $v1, $v1, 1
/* DBDE64 80240BB4 00621821 */  addu      $v1, $v1, $v0
/* DBDE68 80240BB8 080902F2 */  j         .L80240BC8
/* DBDE6C 80240BBC A603008E */   sh       $v1, 0x8e($s0)
.L80240BC0:
/* DBDE70 80240BC0 24020004 */  addiu     $v0, $zero, 4
.L80240BC4:
/* DBDE74 80240BC4 AE820070 */  sw        $v0, 0x70($s4)
.L80240BC8:
/* DBDE78 80240BC8 8FBF0044 */  lw        $ra, 0x44($sp)
/* DBDE7C 80240BCC 8FB40040 */  lw        $s4, 0x40($sp)
/* DBDE80 80240BD0 8FB3003C */  lw        $s3, 0x3c($sp)
/* DBDE84 80240BD4 8FB20038 */  lw        $s2, 0x38($sp)
/* DBDE88 80240BD8 8FB10034 */  lw        $s1, 0x34($sp)
/* DBDE8C 80240BDC 8FB00030 */  lw        $s0, 0x30($sp)
/* DBDE90 80240BE0 03E00008 */  jr        $ra
/* DBDE94 80240BE4 27BD0048 */   addiu    $sp, $sp, 0x48
