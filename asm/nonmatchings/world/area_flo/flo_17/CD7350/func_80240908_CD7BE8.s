.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240908_CD7BE8
/* CD7BE8 80240908 27BDFF88 */  addiu     $sp, $sp, -0x78
/* CD7BEC 8024090C AFB3004C */  sw        $s3, 0x4c($sp)
/* CD7BF0 80240910 0080982D */  daddu     $s3, $a0, $zero
/* CD7BF4 80240914 AFBF0054 */  sw        $ra, 0x54($sp)
/* CD7BF8 80240918 AFB40050 */  sw        $s4, 0x50($sp)
/* CD7BFC 8024091C AFB20048 */  sw        $s2, 0x48($sp)
/* CD7C00 80240920 AFB10044 */  sw        $s1, 0x44($sp)
/* CD7C04 80240924 AFB00040 */  sw        $s0, 0x40($sp)
/* CD7C08 80240928 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* CD7C0C 8024092C F7B80068 */  sdc1      $f24, 0x68($sp)
/* CD7C10 80240930 F7B60060 */  sdc1      $f22, 0x60($sp)
/* CD7C14 80240934 F7B40058 */  sdc1      $f20, 0x58($sp)
/* CD7C18 80240938 8E710148 */  lw        $s1, 0x148($s3)
/* CD7C1C 8024093C 00A0902D */  daddu     $s2, $a1, $zero
/* CD7C20 80240940 86240008 */  lh        $a0, 8($s1)
/* CD7C24 80240944 0C00EABB */  jal       get_npc_unsafe
/* CD7C28 80240948 00C0A02D */   daddu    $s4, $a2, $zero
/* CD7C2C 8024094C 0040802D */  daddu     $s0, $v0, $zero
/* CD7C30 80240950 C6200078 */  lwc1      $f0, 0x78($s1)
/* CD7C34 80240954 46800020 */  cvt.s.w   $f0, $f0
/* CD7C38 80240958 46000021 */  cvt.d.s   $f0, $f0
/* CD7C3C 8024095C 3C014059 */  lui       $at, 0x4059
/* CD7C40 80240960 44811800 */  mtc1      $at, $f3
/* CD7C44 80240964 44801000 */  mtc1      $zero, $f2
/* CD7C48 80240968 8602008E */  lh        $v0, 0x8e($s0)
/* CD7C4C 8024096C 9603008E */  lhu       $v1, 0x8e($s0)
/* CD7C50 80240970 46220003 */  div.d     $f0, $f0, $f2
/* CD7C54 80240974 46200620 */  cvt.s.d   $f24, $f0
/* CD7C58 80240978 C6200088 */  lwc1      $f0, 0x88($s1)
/* CD7C5C 8024097C 46800020 */  cvt.s.w   $f0, $f0
/* CD7C60 80240980 46000021 */  cvt.d.s   $f0, $f0
/* CD7C64 80240984 46220003 */  div.d     $f0, $f0, $f2
/* CD7C68 80240988 46200020 */  cvt.s.d   $f0, $f0
/* CD7C6C 8024098C 18400003 */  blez      $v0, .L8024099C
/* CD7C70 80240990 4600C680 */   add.s    $f26, $f24, $f0
/* CD7C74 80240994 2462FFFF */  addiu     $v0, $v1, -1
/* CD7C78 80240998 A602008E */  sh        $v0, 0x8e($s0)
.L8024099C:
/* CD7C7C 8024099C 8E220070 */  lw        $v0, 0x70($s1)
/* CD7C80 802409A0 18400034 */  blez      $v0, .L80240A74
/* CD7C84 802409A4 00000000 */   nop
/* CD7C88 802409A8 C62C0074 */  lwc1      $f12, 0x74($s1)
/* CD7C8C 802409AC 46806320 */  cvt.s.w   $f12, $f12
/* CD7C90 802409B0 44820000 */  mtc1      $v0, $f0
/* CD7C94 802409B4 00000000 */  nop
/* CD7C98 802409B8 46800020 */  cvt.s.w   $f0, $f0
/* CD7C9C 802409BC 46000021 */  cvt.d.s   $f0, $f0
/* CD7CA0 802409C0 46220003 */  div.d     $f0, $f0, $f2
/* CD7CA4 802409C4 0C00A8BB */  jal       sin_deg
/* CD7CA8 802409C8 462005A0 */   cvt.s.d  $f22, $f0
/* CD7CAC 802409CC 8E020000 */  lw        $v0, ($s0)
/* CD7CB0 802409D0 30420008 */  andi      $v0, $v0, 8
/* CD7CB4 802409D4 10400003 */  beqz      $v0, .L802409E4
/* CD7CB8 802409D8 46000506 */   mov.s    $f20, $f0
/* CD7CBC 802409DC 08090289 */  j         .L80240A24
/* CD7CC0 802409E0 0000102D */   daddu    $v0, $zero, $zero
.L802409E4:
/* CD7CC4 802409E4 27A50028 */  addiu     $a1, $sp, 0x28
/* CD7CC8 802409E8 27A6002C */  addiu     $a2, $sp, 0x2c
/* CD7CCC 802409EC C6000038 */  lwc1      $f0, 0x38($s0)
/* CD7CD0 802409F0 C602003C */  lwc1      $f2, 0x3c($s0)
/* CD7CD4 802409F4 C6040040 */  lwc1      $f4, 0x40($s0)
/* CD7CD8 802409F8 3C01447A */  lui       $at, 0x447a
/* CD7CDC 802409FC 44813000 */  mtc1      $at, $f6
/* CD7CE0 80240A00 27A20034 */  addiu     $v0, $sp, 0x34
/* CD7CE4 80240A04 E7A00028 */  swc1      $f0, 0x28($sp)
/* CD7CE8 80240A08 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CD7CEC 80240A0C E7A40030 */  swc1      $f4, 0x30($sp)
/* CD7CF0 80240A10 E7A60034 */  swc1      $f6, 0x34($sp)
/* CD7CF4 80240A14 AFA20010 */  sw        $v0, 0x10($sp)
/* CD7CF8 80240A18 8E040080 */  lw        $a0, 0x80($s0)
/* CD7CFC 80240A1C 0C0372DF */  jal       func_800DCB7C
/* CD7D00 80240A20 27A70030 */   addiu    $a3, $sp, 0x30
.L80240A24:
/* CD7D04 80240A24 10400007 */  beqz      $v0, .L80240A44
/* CD7D08 80240A28 00000000 */   nop
/* CD7D0C 80240A2C 4616A082 */  mul.s     $f2, $f20, $f22
/* CD7D10 80240A30 00000000 */  nop
/* CD7D14 80240A34 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CD7D18 80240A38 46180000 */  add.s     $f0, $f0, $f24
/* CD7D1C 80240A3C 08090294 */  j         .L80240A50
/* CD7D20 80240A40 46020000 */   add.s    $f0, $f0, $f2
.L80240A44:
/* CD7D24 80240A44 4616A002 */  mul.s     $f0, $f20, $f22
/* CD7D28 80240A48 00000000 */  nop
/* CD7D2C 80240A4C 4600D000 */  add.s     $f0, $f26, $f0
.L80240A50:
/* CD7D30 80240A50 E600003C */  swc1      $f0, 0x3c($s0)
/* CD7D34 80240A54 8E220074 */  lw        $v0, 0x74($s1)
/* CD7D38 80240A58 2442000A */  addiu     $v0, $v0, 0xa
/* CD7D3C 80240A5C 44826000 */  mtc1      $v0, $f12
/* CD7D40 80240A60 00000000 */  nop
/* CD7D44 80240A64 0C00A6C9 */  jal       clamp_angle
/* CD7D48 80240A68 46806320 */   cvt.s.w  $f12, $f12
/* CD7D4C 80240A6C 4600020D */  trunc.w.s $f8, $f0
/* CD7D50 80240A70 E6280074 */  swc1      $f8, 0x74($s1)
.L80240A74:
/* CD7D54 80240A74 8E220090 */  lw        $v0, 0x90($s1)
/* CD7D58 80240A78 1C400040 */  bgtz      $v0, .L80240B7C
/* CD7D5C 80240A7C 2442FFFF */   addiu    $v0, $v0, -1
/* CD7D60 80240A80 860200A8 */  lh        $v0, 0xa8($s0)
/* CD7D64 80240A84 C600003C */  lwc1      $f0, 0x3c($s0)
/* CD7D68 80240A88 44821000 */  mtc1      $v0, $f2
/* CD7D6C 80240A8C 00000000 */  nop
/* CD7D70 80240A90 468010A0 */  cvt.s.w   $f2, $f2
/* CD7D74 80240A94 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CD7D78 80240A98 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CD7D7C 80240A9C 46020000 */  add.s     $f0, $f0, $f2
/* CD7D80 80240AA0 3C014024 */  lui       $at, 0x4024
/* CD7D84 80240AA4 44812800 */  mtc1      $at, $f5
/* CD7D88 80240AA8 44802000 */  mtc1      $zero, $f4
/* CD7D8C 80240AAC C442002C */  lwc1      $f2, 0x2c($v0)
/* CD7D90 80240AB0 46000021 */  cvt.d.s   $f0, $f0
/* CD7D94 80240AB4 46240000 */  add.d     $f0, $f0, $f4
/* CD7D98 80240AB8 460010A1 */  cvt.d.s   $f2, $f2
/* CD7D9C 80240ABC 4620103C */  c.lt.d    $f2, $f0
/* CD7DA0 80240AC0 00000000 */  nop
/* CD7DA4 80240AC4 4500002E */  bc1f      .L80240B80
/* CD7DA8 80240AC8 0280202D */   daddu    $a0, $s4, $zero
/* CD7DAC 80240ACC 24020001 */  addiu     $v0, $zero, 1
/* CD7DB0 80240AD0 AFA20010 */  sw        $v0, 0x10($sp)
/* CD7DB4 80240AD4 8E460024 */  lw        $a2, 0x24($s2)
/* CD7DB8 80240AD8 8E470028 */  lw        $a3, 0x28($s2)
/* CD7DBC 80240ADC 0C01242D */  jal       func_800490B4
/* CD7DC0 80240AE0 0220282D */   daddu    $a1, $s1, $zero
/* CD7DC4 80240AE4 10400026 */  beqz      $v0, .L80240B80
/* CD7DC8 80240AE8 0000202D */   daddu    $a0, $zero, $zero
/* CD7DCC 80240AEC 0200282D */  daddu     $a1, $s0, $zero
/* CD7DD0 80240AF0 0000302D */  daddu     $a2, $zero, $zero
/* CD7DD4 80240AF4 2412000C */  addiu     $s2, $zero, 0xc
/* CD7DD8 80240AF8 860300A8 */  lh        $v1, 0xa8($s0)
/* CD7DDC 80240AFC 3C013F80 */  lui       $at, 0x3f80
/* CD7DE0 80240B00 44810000 */  mtc1      $at, $f0
/* CD7DE4 80240B04 3C014000 */  lui       $at, 0x4000
/* CD7DE8 80240B08 44811000 */  mtc1      $at, $f2
/* CD7DEC 80240B0C 3C01C1A0 */  lui       $at, 0xc1a0
/* CD7DF0 80240B10 44812000 */  mtc1      $at, $f4
/* CD7DF4 80240B14 44834000 */  mtc1      $v1, $f8
/* CD7DF8 80240B18 00000000 */  nop
/* CD7DFC 80240B1C 46804220 */  cvt.s.w   $f8, $f8
/* CD7E00 80240B20 44074000 */  mfc1      $a3, $f8
/* CD7E04 80240B24 27A20038 */  addiu     $v0, $sp, 0x38
/* CD7E08 80240B28 AFB2001C */  sw        $s2, 0x1c($sp)
/* CD7E0C 80240B2C AFA20020 */  sw        $v0, 0x20($sp)
/* CD7E10 80240B30 E7A00010 */  swc1      $f0, 0x10($sp)
/* CD7E14 80240B34 E7A20014 */  swc1      $f2, 0x14($sp)
/* CD7E18 80240B38 0C01BFA4 */  jal       fx_emote
/* CD7E1C 80240B3C E7A40018 */   swc1     $f4, 0x18($sp)
/* CD7E20 80240B40 0200202D */  daddu     $a0, $s0, $zero
/* CD7E24 80240B44 240502F4 */  addiu     $a1, $zero, 0x2f4
/* CD7E28 80240B48 C480003C */  lwc1      $f0, 0x3c($a0)
/* CD7E2C 80240B4C 3C060020 */  lui       $a2, 0x20
/* CD7E30 80240B50 0C012530 */  jal       func_800494C0
/* CD7E34 80240B54 E4800064 */   swc1     $f0, 0x64($a0)
/* CD7E38 80240B58 8E220018 */  lw        $v0, 0x18($s1)
/* CD7E3C 80240B5C 9442002A */  lhu       $v0, 0x2a($v0)
/* CD7E40 80240B60 30420001 */  andi      $v0, $v0, 1
/* CD7E44 80240B64 10400003 */  beqz      $v0, .L80240B74
/* CD7E48 80240B68 2402000A */   addiu    $v0, $zero, 0xa
/* CD7E4C 80240B6C 08090307 */  j         .L80240C1C
/* CD7E50 80240B70 AE620070 */   sw       $v0, 0x70($s3)
.L80240B74:
/* CD7E54 80240B74 08090307 */  j         .L80240C1C
/* CD7E58 80240B78 AE720070 */   sw       $s2, 0x70($s3)
.L80240B7C:
/* CD7E5C 80240B7C AE220090 */  sw        $v0, 0x90($s1)
.L80240B80:
/* CD7E60 80240B80 8602008C */  lh        $v0, 0x8c($s0)
/* CD7E64 80240B84 14400025 */  bnez      $v0, .L80240C1C
/* CD7E68 80240B88 00000000 */   nop
/* CD7E6C 80240B8C 8602008E */  lh        $v0, 0x8e($s0)
/* CD7E70 80240B90 1C400022 */  bgtz      $v0, .L80240C1C
/* CD7E74 80240B94 00000000 */   nop
/* CD7E78 80240B98 8E620074 */  lw        $v0, 0x74($s3)
/* CD7E7C 80240B9C 2442FFFF */  addiu     $v0, $v0, -1
/* CD7E80 80240BA0 1840001D */  blez      $v0, .L80240C18
/* CD7E84 80240BA4 AE620074 */   sw       $v0, 0x74($s3)
/* CD7E88 80240BA8 8E220018 */  lw        $v0, 0x18($s1)
/* CD7E8C 80240BAC 9442002A */  lhu       $v0, 0x2a($v0)
/* CD7E90 80240BB0 30420010 */  andi      $v0, $v0, 0x10
/* CD7E94 80240BB4 14400007 */  bnez      $v0, .L80240BD4
/* CD7E98 80240BB8 00000000 */   nop
/* CD7E9C 80240BBC C600000C */  lwc1      $f0, 0xc($s0)
/* CD7EA0 80240BC0 3C014334 */  lui       $at, 0x4334
/* CD7EA4 80240BC4 44816000 */  mtc1      $at, $f12
/* CD7EA8 80240BC8 0C00A6C9 */  jal       clamp_angle
/* CD7EAC 80240BCC 460C0300 */   add.s    $f12, $f0, $f12
/* CD7EB0 80240BD0 E600000C */  swc1      $f0, 0xc($s0)
.L80240BD4:
/* CD7EB4 80240BD4 0C00A67F */  jal       rand_int
/* CD7EB8 80240BD8 240403E8 */   addiu    $a0, $zero, 0x3e8
/* CD7EBC 80240BDC 3C032E8B */  lui       $v1, 0x2e8b
/* CD7EC0 80240BE0 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* CD7EC4 80240BE4 00430018 */  mult      $v0, $v1
/* CD7EC8 80240BE8 00021FC3 */  sra       $v1, $v0, 0x1f
/* CD7ECC 80240BEC 00004010 */  mfhi      $t0
/* CD7ED0 80240BF0 00082043 */  sra       $a0, $t0, 1
/* CD7ED4 80240BF4 00832023 */  subu      $a0, $a0, $v1
/* CD7ED8 80240BF8 00041840 */  sll       $v1, $a0, 1
/* CD7EDC 80240BFC 00641821 */  addu      $v1, $v1, $a0
/* CD7EE0 80240C00 00031880 */  sll       $v1, $v1, 2
/* CD7EE4 80240C04 00641823 */  subu      $v1, $v1, $a0
/* CD7EE8 80240C08 00431023 */  subu      $v0, $v0, $v1
/* CD7EEC 80240C0C 24420005 */  addiu     $v0, $v0, 5
/* CD7EF0 80240C10 08090307 */  j         .L80240C1C
/* CD7EF4 80240C14 A602008E */   sh       $v0, 0x8e($s0)
.L80240C18:
/* CD7EF8 80240C18 AE600070 */  sw        $zero, 0x70($s3)
.L80240C1C:
/* CD7EFC 80240C1C 8FBF0054 */  lw        $ra, 0x54($sp)
/* CD7F00 80240C20 8FB40050 */  lw        $s4, 0x50($sp)
/* CD7F04 80240C24 8FB3004C */  lw        $s3, 0x4c($sp)
/* CD7F08 80240C28 8FB20048 */  lw        $s2, 0x48($sp)
/* CD7F0C 80240C2C 8FB10044 */  lw        $s1, 0x44($sp)
/* CD7F10 80240C30 8FB00040 */  lw        $s0, 0x40($sp)
/* CD7F14 80240C34 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* CD7F18 80240C38 D7B80068 */  ldc1      $f24, 0x68($sp)
/* CD7F1C 80240C3C D7B60060 */  ldc1      $f22, 0x60($sp)
/* CD7F20 80240C40 D7B40058 */  ldc1      $f20, 0x58($sp)
/* CD7F24 80240C44 03E00008 */  jr        $ra
/* CD7F28 80240C48 27BD0078 */   addiu    $sp, $sp, 0x78
