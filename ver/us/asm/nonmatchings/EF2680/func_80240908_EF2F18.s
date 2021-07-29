.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240908_EF2F18
/* EF2F18 80240908 27BDFF88 */  addiu     $sp, $sp, -0x78
/* EF2F1C 8024090C AFB3004C */  sw        $s3, 0x4c($sp)
/* EF2F20 80240910 0080982D */  daddu     $s3, $a0, $zero
/* EF2F24 80240914 AFBF0054 */  sw        $ra, 0x54($sp)
/* EF2F28 80240918 AFB40050 */  sw        $s4, 0x50($sp)
/* EF2F2C 8024091C AFB20048 */  sw        $s2, 0x48($sp)
/* EF2F30 80240920 AFB10044 */  sw        $s1, 0x44($sp)
/* EF2F34 80240924 AFB00040 */  sw        $s0, 0x40($sp)
/* EF2F38 80240928 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* EF2F3C 8024092C F7B80068 */  sdc1      $f24, 0x68($sp)
/* EF2F40 80240930 F7B60060 */  sdc1      $f22, 0x60($sp)
/* EF2F44 80240934 F7B40058 */  sdc1      $f20, 0x58($sp)
/* EF2F48 80240938 8E710148 */  lw        $s1, 0x148($s3)
/* EF2F4C 8024093C 00A0902D */  daddu     $s2, $a1, $zero
/* EF2F50 80240940 86240008 */  lh        $a0, 8($s1)
/* EF2F54 80240944 0C00F92F */  jal       func_8003E4BC
/* EF2F58 80240948 00C0A02D */   daddu    $s4, $a2, $zero
/* EF2F5C 8024094C 0040802D */  daddu     $s0, $v0, $zero
/* EF2F60 80240950 C6200078 */  lwc1      $f0, 0x78($s1)
/* EF2F64 80240954 46800020 */  cvt.s.w   $f0, $f0
/* EF2F68 80240958 46000021 */  cvt.d.s   $f0, $f0
/* EF2F6C 8024095C 3C014059 */  lui       $at, 0x4059
/* EF2F70 80240960 44811800 */  mtc1      $at, $f3
/* EF2F74 80240964 44801000 */  mtc1      $zero, $f2
/* EF2F78 80240968 8602008E */  lh        $v0, 0x8e($s0)
/* EF2F7C 8024096C 9603008E */  lhu       $v1, 0x8e($s0)
/* EF2F80 80240970 46220003 */  div.d     $f0, $f0, $f2
/* EF2F84 80240974 46200620 */  cvt.s.d   $f24, $f0
/* EF2F88 80240978 C6200088 */  lwc1      $f0, 0x88($s1)
/* EF2F8C 8024097C 46800020 */  cvt.s.w   $f0, $f0
/* EF2F90 80240980 46000021 */  cvt.d.s   $f0, $f0
/* EF2F94 80240984 46220003 */  div.d     $f0, $f0, $f2
/* EF2F98 80240988 46200020 */  cvt.s.d   $f0, $f0
/* EF2F9C 8024098C 18400003 */  blez      $v0, .L8024099C
/* EF2FA0 80240990 4600C680 */   add.s    $f26, $f24, $f0
/* EF2FA4 80240994 2462FFFF */  addiu     $v0, $v1, -1
/* EF2FA8 80240998 A602008E */  sh        $v0, 0x8e($s0)
.L8024099C:
/* EF2FAC 8024099C 8E220070 */  lw        $v0, 0x70($s1)
/* EF2FB0 802409A0 18400034 */  blez      $v0, .L80240A74
/* EF2FB4 802409A4 00000000 */   nop
/* EF2FB8 802409A8 C62C0074 */  lwc1      $f12, 0x74($s1)
/* EF2FBC 802409AC 46806320 */  cvt.s.w   $f12, $f12
/* EF2FC0 802409B0 44820000 */  mtc1      $v0, $f0
/* EF2FC4 802409B4 00000000 */  nop
/* EF2FC8 802409B8 46800020 */  cvt.s.w   $f0, $f0
/* EF2FCC 802409BC 46000021 */  cvt.d.s   $f0, $f0
/* EF2FD0 802409C0 46220003 */  div.d     $f0, $f0, $f2
/* EF2FD4 802409C4 0C00AD77 */  jal       func_8002B5DC
/* EF2FD8 802409C8 462005A0 */   cvt.s.d  $f22, $f0
/* EF2FDC 802409CC 8E020000 */  lw        $v0, ($s0)
/* EF2FE0 802409D0 30420008 */  andi      $v0, $v0, 8
/* EF2FE4 802409D4 10400003 */  beqz      $v0, .L802409E4
/* EF2FE8 802409D8 46000506 */   mov.s    $f20, $f0
/* EF2FEC 802409DC 08090289 */  j         .L80240A24
/* EF2FF0 802409E0 0000102D */   daddu    $v0, $zero, $zero
.L802409E4:
/* EF2FF4 802409E4 27A50028 */  addiu     $a1, $sp, 0x28
/* EF2FF8 802409E8 27A6002C */  addiu     $a2, $sp, 0x2c
/* EF2FFC 802409EC C6000038 */  lwc1      $f0, 0x38($s0)
/* EF3000 802409F0 C602003C */  lwc1      $f2, 0x3c($s0)
/* EF3004 802409F4 C6040040 */  lwc1      $f4, 0x40($s0)
/* EF3008 802409F8 3C01447A */  lui       $at, 0x447a
/* EF300C 802409FC 44813000 */  mtc1      $at, $f6
/* EF3010 80240A00 27A20034 */  addiu     $v0, $sp, 0x34
/* EF3014 80240A04 E7A00028 */  swc1      $f0, 0x28($sp)
/* EF3018 80240A08 E7A2002C */  swc1      $f2, 0x2c($sp)
/* EF301C 80240A0C E7A40030 */  swc1      $f4, 0x30($sp)
/* EF3020 80240A10 E7A60034 */  swc1      $f6, 0x34($sp)
/* EF3024 80240A14 AFA20010 */  sw        $v0, 0x10($sp)
/* EF3028 80240A18 8E040080 */  lw        $a0, 0x80($s0)
/* EF302C 80240A1C 0C03908F */  jal       func_800E423C
/* EF3030 80240A20 27A70030 */   addiu    $a3, $sp, 0x30
.L80240A24:
/* EF3034 80240A24 10400007 */  beqz      $v0, .L80240A44
/* EF3038 80240A28 00000000 */   nop
/* EF303C 80240A2C 4616A082 */  mul.s     $f2, $f20, $f22
/* EF3040 80240A30 00000000 */  nop
/* EF3044 80240A34 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* EF3048 80240A38 46180000 */  add.s     $f0, $f0, $f24
/* EF304C 80240A3C 08090294 */  j         .L80240A50
/* EF3050 80240A40 46020000 */   add.s    $f0, $f0, $f2
.L80240A44:
/* EF3054 80240A44 4616A002 */  mul.s     $f0, $f20, $f22
/* EF3058 80240A48 00000000 */  nop
/* EF305C 80240A4C 4600D000 */  add.s     $f0, $f26, $f0
.L80240A50:
/* EF3060 80240A50 E600003C */  swc1      $f0, 0x3c($s0)
/* EF3064 80240A54 8E220074 */  lw        $v0, 0x74($s1)
/* EF3068 80240A58 2442000A */  addiu     $v0, $v0, 0xa
/* EF306C 80240A5C 44826000 */  mtc1      $v0, $f12
/* EF3070 80240A60 00000000 */  nop
/* EF3074 80240A64 0C00AB85 */  jal       func_8002AE14
/* EF3078 80240A68 46806320 */   cvt.s.w  $f12, $f12
/* EF307C 80240A6C 4600020D */  trunc.w.s $f8, $f0
/* EF3080 80240A70 E6280074 */  swc1      $f8, 0x74($s1)
.L80240A74:
/* EF3084 80240A74 8E220090 */  lw        $v0, 0x90($s1)
/* EF3088 80240A78 1C400040 */  bgtz      $v0, .L80240B7C
/* EF308C 80240A7C 2442FFFF */   addiu    $v0, $v0, -1
/* EF3090 80240A80 860200A8 */  lh        $v0, 0xa8($s0)
/* EF3094 80240A84 C600003C */  lwc1      $f0, 0x3c($s0)
/* EF3098 80240A88 44821000 */  mtc1      $v0, $f2
/* EF309C 80240A8C 00000000 */  nop
/* EF30A0 80240A90 468010A0 */  cvt.s.w   $f2, $f2
/* EF30A4 80240A94 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EF30A8 80240A98 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EF30AC 80240A9C 46020000 */  add.s     $f0, $f0, $f2
/* EF30B0 80240AA0 3C014024 */  lui       $at, 0x4024
/* EF30B4 80240AA4 44812800 */  mtc1      $at, $f5
/* EF30B8 80240AA8 44802000 */  mtc1      $zero, $f4
/* EF30BC 80240AAC C442002C */  lwc1      $f2, 0x2c($v0)
/* EF30C0 80240AB0 46000021 */  cvt.d.s   $f0, $f0
/* EF30C4 80240AB4 46240000 */  add.d     $f0, $f0, $f4
/* EF30C8 80240AB8 460010A1 */  cvt.d.s   $f2, $f2
/* EF30CC 80240ABC 4620103C */  c.lt.d    $f2, $f0
/* EF30D0 80240AC0 00000000 */  nop
/* EF30D4 80240AC4 4500002E */  bc1f      .L80240B80
/* EF30D8 80240AC8 0280202D */   daddu    $a0, $s4, $zero
/* EF30DC 80240ACC 24020001 */  addiu     $v0, $zero, 1
/* EF30E0 80240AD0 AFA20010 */  sw        $v0, 0x10($sp)
/* EF30E4 80240AD4 8E460024 */  lw        $a2, 0x24($s2)
/* EF30E8 80240AD8 8E470028 */  lw        $a3, 0x28($s2)
/* EF30EC 80240ADC 0C013469 */  jal       func_8004D1A4
/* EF30F0 80240AE0 0220282D */   daddu    $a1, $s1, $zero
/* EF30F4 80240AE4 10400026 */  beqz      $v0, .L80240B80
/* EF30F8 80240AE8 0000202D */   daddu    $a0, $zero, $zero
/* EF30FC 80240AEC 0200282D */  daddu     $a1, $s0, $zero
/* EF3100 80240AF0 0000302D */  daddu     $a2, $zero, $zero
/* EF3104 80240AF4 2412000C */  addiu     $s2, $zero, 0xc
/* EF3108 80240AF8 860300A8 */  lh        $v1, 0xa8($s0)
/* EF310C 80240AFC 3C013F80 */  lui       $at, 0x3f80
/* EF3110 80240B00 44810000 */  mtc1      $at, $f0
/* EF3114 80240B04 3C014000 */  lui       $at, 0x4000
/* EF3118 80240B08 44811000 */  mtc1      $at, $f2
/* EF311C 80240B0C 3C01C1A0 */  lui       $at, 0xc1a0
/* EF3120 80240B10 44812000 */  mtc1      $at, $f4
/* EF3124 80240B14 44834000 */  mtc1      $v1, $f8
/* EF3128 80240B18 00000000 */  nop
/* EF312C 80240B1C 46804220 */  cvt.s.w   $f8, $f8
/* EF3130 80240B20 44074000 */  mfc1      $a3, $f8
/* EF3134 80240B24 27A20038 */  addiu     $v0, $sp, 0x38
/* EF3138 80240B28 AFB2001C */  sw        $s2, 0x1c($sp)
/* EF313C 80240B2C AFA20020 */  sw        $v0, 0x20($sp)
/* EF3140 80240B30 E7A00010 */  swc1      $f0, 0x10($sp)
/* EF3144 80240B34 E7A20014 */  swc1      $f2, 0x14($sp)
/* EF3148 80240B38 0C01D444 */  jal       func_80075110
/* EF314C 80240B3C E7A40018 */   swc1     $f4, 0x18($sp)
/* EF3150 80240B40 0200202D */  daddu     $a0, $s0, $zero
/* EF3154 80240B44 240502F4 */  addiu     $a1, $zero, 0x2f4
/* EF3158 80240B48 C480003C */  lwc1      $f0, 0x3c($a0)
/* EF315C 80240B4C 3C060020 */  lui       $a2, 0x20
/* EF3160 80240B50 0C013600 */  jal       func_8004D800
/* EF3164 80240B54 E4800064 */   swc1     $f0, 0x64($a0)
/* EF3168 80240B58 8E220018 */  lw        $v0, 0x18($s1)
/* EF316C 80240B5C 9442002A */  lhu       $v0, 0x2a($v0)
/* EF3170 80240B60 30420001 */  andi      $v0, $v0, 1
/* EF3174 80240B64 10400003 */  beqz      $v0, .L80240B74
/* EF3178 80240B68 2402000A */   addiu    $v0, $zero, 0xa
/* EF317C 80240B6C 08090307 */  j         .L80240C1C
/* EF3180 80240B70 AE620070 */   sw       $v0, 0x70($s3)
.L80240B74:
/* EF3184 80240B74 08090307 */  j         .L80240C1C
/* EF3188 80240B78 AE720070 */   sw       $s2, 0x70($s3)
.L80240B7C:
/* EF318C 80240B7C AE220090 */  sw        $v0, 0x90($s1)
.L80240B80:
/* EF3190 80240B80 8602008C */  lh        $v0, 0x8c($s0)
/* EF3194 80240B84 14400025 */  bnez      $v0, .L80240C1C
/* EF3198 80240B88 00000000 */   nop
/* EF319C 80240B8C 8602008E */  lh        $v0, 0x8e($s0)
/* EF31A0 80240B90 1C400022 */  bgtz      $v0, .L80240C1C
/* EF31A4 80240B94 00000000 */   nop
/* EF31A8 80240B98 8E620074 */  lw        $v0, 0x74($s3)
/* EF31AC 80240B9C 2442FFFF */  addiu     $v0, $v0, -1
/* EF31B0 80240BA0 1840001D */  blez      $v0, .L80240C18
/* EF31B4 80240BA4 AE620074 */   sw       $v0, 0x74($s3)
/* EF31B8 80240BA8 8E220018 */  lw        $v0, 0x18($s1)
/* EF31BC 80240BAC 9442002A */  lhu       $v0, 0x2a($v0)
/* EF31C0 80240BB0 30420010 */  andi      $v0, $v0, 0x10
/* EF31C4 80240BB4 14400007 */  bnez      $v0, .L80240BD4
/* EF31C8 80240BB8 00000000 */   nop
/* EF31CC 80240BBC C600000C */  lwc1      $f0, 0xc($s0)
/* EF31D0 80240BC0 3C014334 */  lui       $at, 0x4334
/* EF31D4 80240BC4 44816000 */  mtc1      $at, $f12
/* EF31D8 80240BC8 0C00AB85 */  jal       func_8002AE14
/* EF31DC 80240BCC 460C0300 */   add.s    $f12, $f0, $f12
/* EF31E0 80240BD0 E600000C */  swc1      $f0, 0xc($s0)
.L80240BD4:
/* EF31E4 80240BD4 0C00AB3B */  jal       func_8002ACEC
/* EF31E8 80240BD8 240403E8 */   addiu    $a0, $zero, 0x3e8
/* EF31EC 80240BDC 3C032E8B */  lui       $v1, 0x2e8b
/* EF31F0 80240BE0 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* EF31F4 80240BE4 00430018 */  mult      $v0, $v1
/* EF31F8 80240BE8 00021FC3 */  sra       $v1, $v0, 0x1f
/* EF31FC 80240BEC 00004010 */  mfhi      $t0
/* EF3200 80240BF0 00082043 */  sra       $a0, $t0, 1
/* EF3204 80240BF4 00832023 */  subu      $a0, $a0, $v1
/* EF3208 80240BF8 00041840 */  sll       $v1, $a0, 1
/* EF320C 80240BFC 00641821 */  addu      $v1, $v1, $a0
/* EF3210 80240C00 00031880 */  sll       $v1, $v1, 2
/* EF3214 80240C04 00641823 */  subu      $v1, $v1, $a0
/* EF3218 80240C08 00431023 */  subu      $v0, $v0, $v1
/* EF321C 80240C0C 24420005 */  addiu     $v0, $v0, 5
/* EF3220 80240C10 08090307 */  j         .L80240C1C
/* EF3224 80240C14 A602008E */   sh       $v0, 0x8e($s0)
.L80240C18:
/* EF3228 80240C18 AE600070 */  sw        $zero, 0x70($s3)
.L80240C1C:
/* EF322C 80240C1C 8FBF0054 */  lw        $ra, 0x54($sp)
/* EF3230 80240C20 8FB40050 */  lw        $s4, 0x50($sp)
/* EF3234 80240C24 8FB3004C */  lw        $s3, 0x4c($sp)
/* EF3238 80240C28 8FB20048 */  lw        $s2, 0x48($sp)
/* EF323C 80240C2C 8FB10044 */  lw        $s1, 0x44($sp)
/* EF3240 80240C30 8FB00040 */  lw        $s0, 0x40($sp)
/* EF3244 80240C34 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* EF3248 80240C38 D7B80068 */  ldc1      $f24, 0x68($sp)
/* EF324C 80240C3C D7B60060 */  ldc1      $f22, 0x60($sp)
/* EF3250 80240C40 D7B40058 */  ldc1      $f20, 0x58($sp)
/* EF3254 80240C44 03E00008 */  jr        $ra
/* EF3258 80240C48 27BD0078 */   addiu    $sp, $sp, 0x78
