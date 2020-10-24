.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A30_7ED740
/* 7ED740 80242A30 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 7ED744 80242A34 AFB40040 */  sw        $s4, 0x40($sp)
/* 7ED748 80242A38 0080A02D */  daddu     $s4, $a0, $zero
/* 7ED74C 80242A3C AFBF0044 */  sw        $ra, 0x44($sp)
/* 7ED750 80242A40 AFB3003C */  sw        $s3, 0x3c($sp)
/* 7ED754 80242A44 AFB20038 */  sw        $s2, 0x38($sp)
/* 7ED758 80242A48 AFB10034 */  sw        $s1, 0x34($sp)
/* 7ED75C 80242A4C AFB00030 */  sw        $s0, 0x30($sp)
/* 7ED760 80242A50 8E910148 */  lw        $s1, 0x148($s4)
/* 7ED764 80242A54 00A0902D */  daddu     $s2, $a1, $zero
/* 7ED768 80242A58 86240008 */  lh        $a0, 8($s1)
/* 7ED76C 80242A5C 0C00EABB */  jal       get_npc_unsafe
/* 7ED770 80242A60 00C0982D */   daddu    $s3, $a2, $zero
/* 7ED774 80242A64 8E430014 */  lw        $v1, 0x14($s2)
/* 7ED778 80242A68 04600031 */  bltz      $v1, .L80242B30
/* 7ED77C 80242A6C 0040802D */   daddu    $s0, $v0, $zero
/* 7ED780 80242A70 0260202D */  daddu     $a0, $s3, $zero
/* 7ED784 80242A74 AFA00010 */  sw        $zero, 0x10($sp)
/* 7ED788 80242A78 8E460024 */  lw        $a2, 0x24($s2)
/* 7ED78C 80242A7C 8E470028 */  lw        $a3, 0x28($s2)
/* 7ED790 80242A80 0C01242D */  jal       func_800490B4
/* 7ED794 80242A84 0220282D */   daddu    $a1, $s1, $zero
/* 7ED798 80242A88 10400029 */  beqz      $v0, .L80242B30
/* 7ED79C 80242A8C 0000202D */   daddu    $a0, $zero, $zero
/* 7ED7A0 80242A90 0200282D */  daddu     $a1, $s0, $zero
/* 7ED7A4 80242A94 0000302D */  daddu     $a2, $zero, $zero
/* 7ED7A8 80242A98 860300A8 */  lh        $v1, 0xa8($s0)
/* 7ED7AC 80242A9C 3C013F80 */  lui       $at, 0x3f80
/* 7ED7B0 80242AA0 44810000 */  mtc1      $at, $f0
/* 7ED7B4 80242AA4 3C014000 */  lui       $at, 0x4000
/* 7ED7B8 80242AA8 44811000 */  mtc1      $at, $f2
/* 7ED7BC 80242AAC 3C01C1A0 */  lui       $at, 0xc1a0
/* 7ED7C0 80242AB0 44812000 */  mtc1      $at, $f4
/* 7ED7C4 80242AB4 2402000F */  addiu     $v0, $zero, 0xf
/* 7ED7C8 80242AB8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 7ED7CC 80242ABC 44833000 */  mtc1      $v1, $f6
/* 7ED7D0 80242AC0 00000000 */  nop       
/* 7ED7D4 80242AC4 468031A0 */  cvt.s.w   $f6, $f6
/* 7ED7D8 80242AC8 44073000 */  mfc1      $a3, $f6
/* 7ED7DC 80242ACC 27A20028 */  addiu     $v0, $sp, 0x28
/* 7ED7E0 80242AD0 AFA20020 */  sw        $v0, 0x20($sp)
/* 7ED7E4 80242AD4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 7ED7E8 80242AD8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 7ED7EC 80242ADC 0C01BFA4 */  jal       fx_emote
/* 7ED7F0 80242AE0 E7A40018 */   swc1     $f4, 0x18($sp)
/* 7ED7F4 80242AE4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 7ED7F8 80242AE8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 7ED7FC 80242AEC C60C0038 */  lwc1      $f12, 0x38($s0)
/* 7ED800 80242AF0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 7ED804 80242AF4 8C460028 */  lw        $a2, 0x28($v0)
/* 7ED808 80242AF8 0C00A720 */  jal       atan2
/* 7ED80C 80242AFC 8C470030 */   lw       $a3, 0x30($v0)
/* 7ED810 80242B00 0200202D */  daddu     $a0, $s0, $zero
/* 7ED814 80242B04 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 7ED818 80242B08 3C060020 */  lui       $a2, 0x20
/* 7ED81C 80242B0C 0C012530 */  jal       func_800494C0
/* 7ED820 80242B10 E480000C */   swc1     $f0, 0xc($a0)
/* 7ED824 80242B14 8E220018 */  lw        $v0, 0x18($s1)
/* 7ED828 80242B18 9442002A */  lhu       $v0, 0x2a($v0)
/* 7ED82C 80242B1C 30420001 */  andi      $v0, $v0, 1
/* 7ED830 80242B20 14400029 */  bnez      $v0, .L80242BC8
/* 7ED834 80242B24 2402000A */   addiu    $v0, $zero, 0xa
/* 7ED838 80242B28 08090AF2 */  j         .L80242BC8
/* 7ED83C 80242B2C 2402000C */   addiu    $v0, $zero, 0xc
.L80242B30:
/* 7ED840 80242B30 8602008C */  lh        $v0, 0x8c($s0)
/* 7ED844 80242B34 14400025 */  bnez      $v0, .L80242BCC
/* 7ED848 80242B38 00000000 */   nop      
/* 7ED84C 80242B3C 9602008E */  lhu       $v0, 0x8e($s0)
/* 7ED850 80242B40 2442FFFF */  addiu     $v0, $v0, -1
/* 7ED854 80242B44 A602008E */  sh        $v0, 0x8e($s0)
/* 7ED858 80242B48 00021400 */  sll       $v0, $v0, 0x10
/* 7ED85C 80242B4C 1440001F */  bnez      $v0, .L80242BCC
/* 7ED860 80242B50 00000000 */   nop      
/* 7ED864 80242B54 8E820074 */  lw        $v0, 0x74($s4)
/* 7ED868 80242B58 2442FFFF */  addiu     $v0, $v0, -1
/* 7ED86C 80242B5C 10400019 */  beqz      $v0, .L80242BC4
/* 7ED870 80242B60 AE820074 */   sw       $v0, 0x74($s4)
/* 7ED874 80242B64 8E220018 */  lw        $v0, 0x18($s1)
/* 7ED878 80242B68 9442002A */  lhu       $v0, 0x2a($v0)
/* 7ED87C 80242B6C 30420010 */  andi      $v0, $v0, 0x10
/* 7ED880 80242B70 14400007 */  bnez      $v0, .L80242B90
/* 7ED884 80242B74 00000000 */   nop      
/* 7ED888 80242B78 C600000C */  lwc1      $f0, 0xc($s0)
/* 7ED88C 80242B7C 3C014334 */  lui       $at, 0x4334
/* 7ED890 80242B80 44816000 */  mtc1      $at, $f12
/* 7ED894 80242B84 0C00A6C9 */  jal       clamp_angle
/* 7ED898 80242B88 460C0300 */   add.s    $f12, $f0, $f12
/* 7ED89C 80242B8C E600000C */  swc1      $f0, 0xc($s0)
.L80242B90:
/* 7ED8A0 80242B90 8E440008 */  lw        $a0, 8($s2)
/* 7ED8A4 80242B94 000417C2 */  srl       $v0, $a0, 0x1f
/* 7ED8A8 80242B98 00822021 */  addu      $a0, $a0, $v0
/* 7ED8AC 80242B9C 00042043 */  sra       $a0, $a0, 1
/* 7ED8B0 80242BA0 0C00A67F */  jal       rand_int
/* 7ED8B4 80242BA4 24840001 */   addiu    $a0, $a0, 1
/* 7ED8B8 80242BA8 8E430008 */  lw        $v1, 8($s2)
/* 7ED8BC 80242BAC 000327C2 */  srl       $a0, $v1, 0x1f
/* 7ED8C0 80242BB0 00641821 */  addu      $v1, $v1, $a0
/* 7ED8C4 80242BB4 00031843 */  sra       $v1, $v1, 1
/* 7ED8C8 80242BB8 00621821 */  addu      $v1, $v1, $v0
/* 7ED8CC 80242BBC 08090AF3 */  j         .L80242BCC
/* 7ED8D0 80242BC0 A603008E */   sh       $v1, 0x8e($s0)
.L80242BC4:
/* 7ED8D4 80242BC4 24020004 */  addiu     $v0, $zero, 4
.L80242BC8:
/* 7ED8D8 80242BC8 AE820070 */  sw        $v0, 0x70($s4)
.L80242BCC:
/* 7ED8DC 80242BCC 8FBF0044 */  lw        $ra, 0x44($sp)
/* 7ED8E0 80242BD0 8FB40040 */  lw        $s4, 0x40($sp)
/* 7ED8E4 80242BD4 8FB3003C */  lw        $s3, 0x3c($sp)
/* 7ED8E8 80242BD8 8FB20038 */  lw        $s2, 0x38($sp)
/* 7ED8EC 80242BDC 8FB10034 */  lw        $s1, 0x34($sp)
/* 7ED8F0 80242BE0 8FB00030 */  lw        $s0, 0x30($sp)
/* 7ED8F4 80242BE4 03E00008 */  jr        $ra
/* 7ED8F8 80242BE8 27BD0048 */   addiu    $sp, $sp, 0x48
