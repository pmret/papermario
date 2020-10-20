.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408F0_B2CD60
/* B2CD60 802408F0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B2CD64 802408F4 AFB40040 */  sw        $s4, 0x40($sp)
/* B2CD68 802408F8 0080A02D */  daddu     $s4, $a0, $zero
/* B2CD6C 802408FC AFBF0044 */  sw        $ra, 0x44($sp)
/* B2CD70 80240900 AFB3003C */  sw        $s3, 0x3c($sp)
/* B2CD74 80240904 AFB20038 */  sw        $s2, 0x38($sp)
/* B2CD78 80240908 AFB10034 */  sw        $s1, 0x34($sp)
/* B2CD7C 8024090C AFB00030 */  sw        $s0, 0x30($sp)
/* B2CD80 80240910 8E910148 */  lw        $s1, 0x148($s4)
/* B2CD84 80240914 00A0902D */  daddu     $s2, $a1, $zero
/* B2CD88 80240918 86240008 */  lh        $a0, 8($s1)
/* B2CD8C 8024091C 0C00EABB */  jal       get_npc_unsafe
/* B2CD90 80240920 00C0982D */   daddu    $s3, $a2, $zero
/* B2CD94 80240924 8E430014 */  lw        $v1, 0x14($s2)
/* B2CD98 80240928 04600031 */  bltz      $v1, .L802409F0
/* B2CD9C 8024092C 0040802D */   daddu    $s0, $v0, $zero
/* B2CDA0 80240930 0260202D */  daddu     $a0, $s3, $zero
/* B2CDA4 80240934 AFA00010 */  sw        $zero, 0x10($sp)
/* B2CDA8 80240938 8E460024 */  lw        $a2, 0x24($s2)
/* B2CDAC 8024093C 8E470028 */  lw        $a3, 0x28($s2)
/* B2CDB0 80240940 0C01242D */  jal       func_800490B4
/* B2CDB4 80240944 0220282D */   daddu    $a1, $s1, $zero
/* B2CDB8 80240948 10400029 */  beqz      $v0, .L802409F0
/* B2CDBC 8024094C 0000202D */   daddu    $a0, $zero, $zero
/* B2CDC0 80240950 0200282D */  daddu     $a1, $s0, $zero
/* B2CDC4 80240954 0000302D */  daddu     $a2, $zero, $zero
/* B2CDC8 80240958 860300A8 */  lh        $v1, 0xa8($s0)
/* B2CDCC 8024095C 3C013F80 */  lui       $at, 0x3f80
/* B2CDD0 80240960 44810000 */  mtc1      $at, $f0
/* B2CDD4 80240964 3C014000 */  lui       $at, 0x4000
/* B2CDD8 80240968 44811000 */  mtc1      $at, $f2
/* B2CDDC 8024096C 3C01C1A0 */  lui       $at, 0xc1a0
/* B2CDE0 80240970 44812000 */  mtc1      $at, $f4
/* B2CDE4 80240974 2402000F */  addiu     $v0, $zero, 0xf
/* B2CDE8 80240978 AFA2001C */  sw        $v0, 0x1c($sp)
/* B2CDEC 8024097C 44833000 */  mtc1      $v1, $f6
/* B2CDF0 80240980 00000000 */  nop       
/* B2CDF4 80240984 468031A0 */  cvt.s.w   $f6, $f6
/* B2CDF8 80240988 44073000 */  mfc1      $a3, $f6
/* B2CDFC 8024098C 27A20028 */  addiu     $v0, $sp, 0x28
/* B2CE00 80240990 AFA20020 */  sw        $v0, 0x20($sp)
/* B2CE04 80240994 E7A00010 */  swc1      $f0, 0x10($sp)
/* B2CE08 80240998 E7A20014 */  swc1      $f2, 0x14($sp)
/* B2CE0C 8024099C 0C01BFA4 */  jal       fx_emote
/* B2CE10 802409A0 E7A40018 */   swc1     $f4, 0x18($sp)
/* B2CE14 802409A4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B2CE18 802409A8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B2CE1C 802409AC C60C0038 */  lwc1      $f12, 0x38($s0)
/* B2CE20 802409B0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B2CE24 802409B4 8C460028 */  lw        $a2, 0x28($v0)
/* B2CE28 802409B8 0C00A720 */  jal       atan2
/* B2CE2C 802409BC 8C470030 */   lw       $a3, 0x30($v0)
/* B2CE30 802409C0 0200202D */  daddu     $a0, $s0, $zero
/* B2CE34 802409C4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B2CE38 802409C8 3C060020 */  lui       $a2, 0x20
/* B2CE3C 802409CC 0C012530 */  jal       func_800494C0
/* B2CE40 802409D0 E480000C */   swc1     $f0, 0xc($a0)
/* B2CE44 802409D4 8E220018 */  lw        $v0, 0x18($s1)
/* B2CE48 802409D8 9442002A */  lhu       $v0, 0x2a($v0)
/* B2CE4C 802409DC 30420001 */  andi      $v0, $v0, 1
/* B2CE50 802409E0 14400029 */  bnez      $v0, .L80240A88
/* B2CE54 802409E4 2402000A */   addiu    $v0, $zero, 0xa
/* B2CE58 802409E8 080902A2 */  j         .L80240A88
/* B2CE5C 802409EC 2402000C */   addiu    $v0, $zero, 0xc
.L802409F0:
/* B2CE60 802409F0 8602008C */  lh        $v0, 0x8c($s0)
/* B2CE64 802409F4 14400025 */  bnez      $v0, .L80240A8C
/* B2CE68 802409F8 00000000 */   nop      
/* B2CE6C 802409FC 9602008E */  lhu       $v0, 0x8e($s0)
/* B2CE70 80240A00 2442FFFF */  addiu     $v0, $v0, -1
/* B2CE74 80240A04 A602008E */  sh        $v0, 0x8e($s0)
/* B2CE78 80240A08 00021400 */  sll       $v0, $v0, 0x10
/* B2CE7C 80240A0C 1440001F */  bnez      $v0, .L80240A8C
/* B2CE80 80240A10 00000000 */   nop      
/* B2CE84 80240A14 8E820074 */  lw        $v0, 0x74($s4)
/* B2CE88 80240A18 2442FFFF */  addiu     $v0, $v0, -1
/* B2CE8C 80240A1C 10400019 */  beqz      $v0, .L80240A84
/* B2CE90 80240A20 AE820074 */   sw       $v0, 0x74($s4)
/* B2CE94 80240A24 8E220018 */  lw        $v0, 0x18($s1)
/* B2CE98 80240A28 9442002A */  lhu       $v0, 0x2a($v0)
/* B2CE9C 80240A2C 30420010 */  andi      $v0, $v0, 0x10
/* B2CEA0 80240A30 14400007 */  bnez      $v0, .L80240A50
/* B2CEA4 80240A34 00000000 */   nop      
/* B2CEA8 80240A38 C600000C */  lwc1      $f0, 0xc($s0)
/* B2CEAC 80240A3C 3C014334 */  lui       $at, 0x4334
/* B2CEB0 80240A40 44816000 */  mtc1      $at, $f12
/* B2CEB4 80240A44 0C00A6C9 */  jal       clamp_angle
/* B2CEB8 80240A48 460C0300 */   add.s    $f12, $f0, $f12
/* B2CEBC 80240A4C E600000C */  swc1      $f0, 0xc($s0)
.L80240A50:
/* B2CEC0 80240A50 8E440008 */  lw        $a0, 8($s2)
/* B2CEC4 80240A54 000417C2 */  srl       $v0, $a0, 0x1f
/* B2CEC8 80240A58 00822021 */  addu      $a0, $a0, $v0
/* B2CECC 80240A5C 00042043 */  sra       $a0, $a0, 1
/* B2CED0 80240A60 0C00A67F */  jal       rand_int
/* B2CED4 80240A64 24840001 */   addiu    $a0, $a0, 1
/* B2CED8 80240A68 8E430008 */  lw        $v1, 8($s2)
/* B2CEDC 80240A6C 000327C2 */  srl       $a0, $v1, 0x1f
/* B2CEE0 80240A70 00641821 */  addu      $v1, $v1, $a0
/* B2CEE4 80240A74 00031843 */  sra       $v1, $v1, 1
/* B2CEE8 80240A78 00621821 */  addu      $v1, $v1, $v0
/* B2CEEC 80240A7C 080902A3 */  j         .L80240A8C
/* B2CEF0 80240A80 A603008E */   sh       $v1, 0x8e($s0)
.L80240A84:
/* B2CEF4 80240A84 24020004 */  addiu     $v0, $zero, 4
.L80240A88:
/* B2CEF8 80240A88 AE820070 */  sw        $v0, 0x70($s4)
.L80240A8C:
/* B2CEFC 80240A8C 8FBF0044 */  lw        $ra, 0x44($sp)
/* B2CF00 80240A90 8FB40040 */  lw        $s4, 0x40($sp)
/* B2CF04 80240A94 8FB3003C */  lw        $s3, 0x3c($sp)
/* B2CF08 80240A98 8FB20038 */  lw        $s2, 0x38($sp)
/* B2CF0C 80240A9C 8FB10034 */  lw        $s1, 0x34($sp)
/* B2CF10 80240AA0 8FB00030 */  lw        $s0, 0x30($sp)
/* B2CF14 80240AA4 03E00008 */  jr        $ra
/* B2CF18 80240AA8 27BD0048 */   addiu    $sp, $sp, 0x48
