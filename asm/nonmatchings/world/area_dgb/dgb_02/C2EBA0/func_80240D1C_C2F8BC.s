.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D1C_C2F8BC
/* C2F8BC 80240D1C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C2F8C0 80240D20 AFB20020 */  sw        $s2, 0x20($sp)
/* C2F8C4 80240D24 0080902D */  daddu     $s2, $a0, $zero
/* C2F8C8 80240D28 AFBF0028 */  sw        $ra, 0x28($sp)
/* C2F8CC 80240D2C AFB30024 */  sw        $s3, 0x24($sp)
/* C2F8D0 80240D30 AFB1001C */  sw        $s1, 0x1c($sp)
/* C2F8D4 80240D34 AFB00018 */  sw        $s0, 0x18($sp)
/* C2F8D8 80240D38 8E510148 */  lw        $s1, 0x148($s2)
/* C2F8DC 80240D3C 00A0982D */  daddu     $s3, $a1, $zero
/* C2F8E0 80240D40 86240008 */  lh        $a0, 8($s1)
/* C2F8E4 80240D44 0C00EABB */  jal       get_npc_unsafe
/* C2F8E8 80240D48 00C0802D */   daddu    $s0, $a2, $zero
/* C2F8EC 80240D4C 0200202D */  daddu     $a0, $s0, $zero
/* C2F8F0 80240D50 0040802D */  daddu     $s0, $v0, $zero
/* C2F8F4 80240D54 AFA00010 */  sw        $zero, 0x10($sp)
/* C2F8F8 80240D58 8E660024 */  lw        $a2, 0x24($s3)
/* C2F8FC 80240D5C 8E670028 */  lw        $a3, 0x28($s3)
/* C2F900 80240D60 0C01242D */  jal       func_800490B4
/* C2F904 80240D64 0220282D */   daddu    $a1, $s1, $zero
/* C2F908 80240D68 1040000C */  beqz      $v0, .L80240D9C
/* C2F90C 80240D6C 00000000 */   nop
/* C2F910 80240D70 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C2F914 80240D74 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C2F918 80240D78 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C2F91C 80240D7C C60E0040 */  lwc1      $f14, 0x40($s0)
/* C2F920 80240D80 8C460028 */  lw        $a2, 0x28($v0)
/* C2F924 80240D84 0C00A720 */  jal       atan2
/* C2F928 80240D88 8C470030 */   lw       $a3, 0x30($v0)
/* C2F92C 80240D8C 2402000C */  addiu     $v0, $zero, 0xc
/* C2F930 80240D90 E600000C */  swc1      $f0, 0xc($s0)
/* C2F934 80240D94 0809038E */  j         .L80240E38
/* C2F938 80240D98 AE420070 */   sw       $v0, 0x70($s2)
.L80240D9C:
/* C2F93C 80240D9C 9602008E */  lhu       $v0, 0x8e($s0)
/* C2F940 80240DA0 2442FFFF */  addiu     $v0, $v0, -1
/* C2F944 80240DA4 A602008E */  sh        $v0, 0x8e($s0)
/* C2F948 80240DA8 00021400 */  sll       $v0, $v0, 0x10
/* C2F94C 80240DAC 1C400022 */  bgtz      $v0, .L80240E38
/* C2F950 80240DB0 00000000 */   nop
/* C2F954 80240DB4 8E420074 */  lw        $v0, 0x74($s2)
/* C2F958 80240DB8 2442FFFF */  addiu     $v0, $v0, -1
/* C2F95C 80240DBC 18400014 */  blez      $v0, .L80240E10
/* C2F960 80240DC0 AE420074 */   sw       $v0, 0x74($s2)
/* C2F964 80240DC4 C600000C */  lwc1      $f0, 0xc($s0)
/* C2F968 80240DC8 3C014334 */  lui       $at, 0x4334
/* C2F96C 80240DCC 44816000 */  mtc1      $at, $f12
/* C2F970 80240DD0 0C00A6C9 */  jal       clamp_angle
/* C2F974 80240DD4 460C0300 */   add.s    $f12, $f0, $f12
/* C2F978 80240DD8 E600000C */  swc1      $f0, 0xc($s0)
/* C2F97C 80240DDC 8E640008 */  lw        $a0, 8($s3)
/* C2F980 80240DE0 000417C2 */  srl       $v0, $a0, 0x1f
/* C2F984 80240DE4 00822021 */  addu      $a0, $a0, $v0
/* C2F988 80240DE8 00042043 */  sra       $a0, $a0, 1
/* C2F98C 80240DEC 0C00A67F */  jal       rand_int
/* C2F990 80240DF0 24840001 */   addiu    $a0, $a0, 1
/* C2F994 80240DF4 8E630008 */  lw        $v1, 8($s3)
/* C2F998 80240DF8 000327C2 */  srl       $a0, $v1, 0x1f
/* C2F99C 80240DFC 00641821 */  addu      $v1, $v1, $a0
/* C2F9A0 80240E00 00031843 */  sra       $v1, $v1, 1
/* C2F9A4 80240E04 00621821 */  addu      $v1, $v1, $v0
/* C2F9A8 80240E08 0809038E */  j         .L80240E38
/* C2F9AC 80240E0C A603008E */   sh       $v1, 0x8e($s0)
.L80240E10:
/* C2F9B0 80240E10 8E250088 */  lw        $a1, 0x88($s1)
/* C2F9B4 80240E14 24020028 */  addiu     $v0, $zero, 0x28
/* C2F9B8 80240E18 14A20003 */  bne       $a1, $v0, .L80240E28
/* C2F9BC 80240E1C 24020032 */   addiu    $v0, $zero, 0x32
/* C2F9C0 80240E20 0809038C */  j         .L80240E30
/* C2F9C4 80240E24 24020014 */   addiu    $v0, $zero, 0x14
.L80240E28:
/* C2F9C8 80240E28 14A20003 */  bne       $a1, $v0, .L80240E38
/* C2F9CC 80240E2C 24020019 */   addiu    $v0, $zero, 0x19
.L80240E30:
/* C2F9D0 80240E30 A602008E */  sh        $v0, 0x8e($s0)
/* C2F9D4 80240E34 AE450070 */  sw        $a1, 0x70($s2)
.L80240E38:
/* C2F9D8 80240E38 8FBF0028 */  lw        $ra, 0x28($sp)
/* C2F9DC 80240E3C 8FB30024 */  lw        $s3, 0x24($sp)
/* C2F9E0 80240E40 8FB20020 */  lw        $s2, 0x20($sp)
/* C2F9E4 80240E44 8FB1001C */  lw        $s1, 0x1c($sp)
/* C2F9E8 80240E48 8FB00018 */  lw        $s0, 0x18($sp)
/* C2F9EC 80240E4C 03E00008 */  jr        $ra
/* C2F9F0 80240E50 27BD0030 */   addiu    $sp, $sp, 0x30
