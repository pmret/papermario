.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel dro_01_UnkFunc14
/* 95BCA0 80240AA0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 95BCA4 80240AA4 AFB40040 */  sw        $s4, 0x40($sp)
/* 95BCA8 80240AA8 0080A02D */  daddu     $s4, $a0, $zero
/* 95BCAC 80240AAC AFBF0044 */  sw        $ra, 0x44($sp)
/* 95BCB0 80240AB0 AFB3003C */  sw        $s3, 0x3c($sp)
/* 95BCB4 80240AB4 AFB20038 */  sw        $s2, 0x38($sp)
/* 95BCB8 80240AB8 AFB10034 */  sw        $s1, 0x34($sp)
/* 95BCBC 80240ABC AFB00030 */  sw        $s0, 0x30($sp)
/* 95BCC0 80240AC0 8E910148 */  lw        $s1, 0x148($s4)
/* 95BCC4 80240AC4 00A0902D */  daddu     $s2, $a1, $zero
/* 95BCC8 80240AC8 86240008 */  lh        $a0, 8($s1)
/* 95BCCC 80240ACC 0C00EABB */  jal       get_npc_unsafe
/* 95BCD0 80240AD0 00C0982D */   daddu    $s3, $a2, $zero
/* 95BCD4 80240AD4 8E430014 */  lw        $v1, 0x14($s2)
/* 95BCD8 80240AD8 04600031 */  bltz      $v1, .L80240BA0
/* 95BCDC 80240ADC 0040802D */   daddu    $s0, $v0, $zero
/* 95BCE0 80240AE0 0260202D */  daddu     $a0, $s3, $zero
/* 95BCE4 80240AE4 AFA00010 */  sw        $zero, 0x10($sp)
/* 95BCE8 80240AE8 8E460024 */  lw        $a2, 0x24($s2)
/* 95BCEC 80240AEC 8E470028 */  lw        $a3, 0x28($s2)
/* 95BCF0 80240AF0 0C01242D */  jal       func_800490B4
/* 95BCF4 80240AF4 0220282D */   daddu    $a1, $s1, $zero
/* 95BCF8 80240AF8 10400029 */  beqz      $v0, .L80240BA0
/* 95BCFC 80240AFC 0000202D */   daddu    $a0, $zero, $zero
/* 95BD00 80240B00 0200282D */  daddu     $a1, $s0, $zero
/* 95BD04 80240B04 0000302D */  daddu     $a2, $zero, $zero
/* 95BD08 80240B08 860300A8 */  lh        $v1, 0xa8($s0)
/* 95BD0C 80240B0C 3C013F80 */  lui       $at, 0x3f80
/* 95BD10 80240B10 44810000 */  mtc1      $at, $f0
/* 95BD14 80240B14 3C014000 */  lui       $at, 0x4000
/* 95BD18 80240B18 44811000 */  mtc1      $at, $f2
/* 95BD1C 80240B1C 3C01C1A0 */  lui       $at, 0xc1a0
/* 95BD20 80240B20 44812000 */  mtc1      $at, $f4
/* 95BD24 80240B24 2402000F */  addiu     $v0, $zero, 0xf
/* 95BD28 80240B28 AFA2001C */  sw        $v0, 0x1c($sp)
/* 95BD2C 80240B2C 44833000 */  mtc1      $v1, $f6
/* 95BD30 80240B30 00000000 */  nop
/* 95BD34 80240B34 468031A0 */  cvt.s.w   $f6, $f6
/* 95BD38 80240B38 44073000 */  mfc1      $a3, $f6
/* 95BD3C 80240B3C 27A20028 */  addiu     $v0, $sp, 0x28
/* 95BD40 80240B40 AFA20020 */  sw        $v0, 0x20($sp)
/* 95BD44 80240B44 E7A00010 */  swc1      $f0, 0x10($sp)
/* 95BD48 80240B48 E7A20014 */  swc1      $f2, 0x14($sp)
/* 95BD4C 80240B4C 0C01BFA4 */  jal       fx_emote
/* 95BD50 80240B50 E7A40018 */   swc1     $f4, 0x18($sp)
/* 95BD54 80240B54 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 95BD58 80240B58 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 95BD5C 80240B5C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 95BD60 80240B60 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 95BD64 80240B64 8C460028 */  lw        $a2, 0x28($v0)
/* 95BD68 80240B68 0C00A720 */  jal       atan2
/* 95BD6C 80240B6C 8C470030 */   lw       $a3, 0x30($v0)
/* 95BD70 80240B70 0200202D */  daddu     $a0, $s0, $zero
/* 95BD74 80240B74 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 95BD78 80240B78 3C060020 */  lui       $a2, 0x20
/* 95BD7C 80240B7C 0C012530 */  jal       func_800494C0
/* 95BD80 80240B80 E480000C */   swc1     $f0, 0xc($a0)
/* 95BD84 80240B84 8E220018 */  lw        $v0, 0x18($s1)
/* 95BD88 80240B88 9442002A */  lhu       $v0, 0x2a($v0)
/* 95BD8C 80240B8C 30420001 */  andi      $v0, $v0, 1
/* 95BD90 80240B90 14400029 */  bnez      $v0, .L80240C38
/* 95BD94 80240B94 2402000A */   addiu    $v0, $zero, 0xa
/* 95BD98 80240B98 0809030E */  j         .L80240C38
/* 95BD9C 80240B9C 2402000C */   addiu    $v0, $zero, 0xc
.L80240BA0:
/* 95BDA0 80240BA0 8602008C */  lh        $v0, 0x8c($s0)
/* 95BDA4 80240BA4 14400025 */  bnez      $v0, .L80240C3C
/* 95BDA8 80240BA8 00000000 */   nop
/* 95BDAC 80240BAC 9602008E */  lhu       $v0, 0x8e($s0)
/* 95BDB0 80240BB0 2442FFFF */  addiu     $v0, $v0, -1
/* 95BDB4 80240BB4 A602008E */  sh        $v0, 0x8e($s0)
/* 95BDB8 80240BB8 00021400 */  sll       $v0, $v0, 0x10
/* 95BDBC 80240BBC 1440001F */  bnez      $v0, .L80240C3C
/* 95BDC0 80240BC0 00000000 */   nop
/* 95BDC4 80240BC4 8E820074 */  lw        $v0, 0x74($s4)
/* 95BDC8 80240BC8 2442FFFF */  addiu     $v0, $v0, -1
/* 95BDCC 80240BCC 10400019 */  beqz      $v0, .L80240C34
/* 95BDD0 80240BD0 AE820074 */   sw       $v0, 0x74($s4)
/* 95BDD4 80240BD4 8E220018 */  lw        $v0, 0x18($s1)
/* 95BDD8 80240BD8 9442002A */  lhu       $v0, 0x2a($v0)
/* 95BDDC 80240BDC 30420010 */  andi      $v0, $v0, 0x10
/* 95BDE0 80240BE0 14400007 */  bnez      $v0, .L80240C00
/* 95BDE4 80240BE4 00000000 */   nop
/* 95BDE8 80240BE8 C600000C */  lwc1      $f0, 0xc($s0)
/* 95BDEC 80240BEC 3C014334 */  lui       $at, 0x4334
/* 95BDF0 80240BF0 44816000 */  mtc1      $at, $f12
/* 95BDF4 80240BF4 0C00A6C9 */  jal       clamp_angle
/* 95BDF8 80240BF8 460C0300 */   add.s    $f12, $f0, $f12
/* 95BDFC 80240BFC E600000C */  swc1      $f0, 0xc($s0)
.L80240C00:
/* 95BE00 80240C00 8E440008 */  lw        $a0, 8($s2)
/* 95BE04 80240C04 000417C2 */  srl       $v0, $a0, 0x1f
/* 95BE08 80240C08 00822021 */  addu      $a0, $a0, $v0
/* 95BE0C 80240C0C 00042043 */  sra       $a0, $a0, 1
/* 95BE10 80240C10 0C00A67F */  jal       rand_int
/* 95BE14 80240C14 24840001 */   addiu    $a0, $a0, 1
/* 95BE18 80240C18 8E430008 */  lw        $v1, 8($s2)
/* 95BE1C 80240C1C 000327C2 */  srl       $a0, $v1, 0x1f
/* 95BE20 80240C20 00641821 */  addu      $v1, $v1, $a0
/* 95BE24 80240C24 00031843 */  sra       $v1, $v1, 1
/* 95BE28 80240C28 00621821 */  addu      $v1, $v1, $v0
/* 95BE2C 80240C2C 0809030F */  j         .L80240C3C
/* 95BE30 80240C30 A603008E */   sh       $v1, 0x8e($s0)
.L80240C34:
/* 95BE34 80240C34 24020004 */  addiu     $v0, $zero, 4
.L80240C38:
/* 95BE38 80240C38 AE820070 */  sw        $v0, 0x70($s4)
.L80240C3C:
/* 95BE3C 80240C3C 8FBF0044 */  lw        $ra, 0x44($sp)
/* 95BE40 80240C40 8FB40040 */  lw        $s4, 0x40($sp)
/* 95BE44 80240C44 8FB3003C */  lw        $s3, 0x3c($sp)
/* 95BE48 80240C48 8FB20038 */  lw        $s2, 0x38($sp)
/* 95BE4C 80240C4C 8FB10034 */  lw        $s1, 0x34($sp)
/* 95BE50 80240C50 8FB00030 */  lw        $s0, 0x30($sp)
/* 95BE54 80240C54 03E00008 */  jr        $ra
/* 95BE58 80240C58 27BD0048 */   addiu    $sp, $sp, 0x48
