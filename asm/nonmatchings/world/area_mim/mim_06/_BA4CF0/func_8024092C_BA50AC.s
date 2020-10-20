.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024092C_BA50AC
/* BA50AC 8024092C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BA50B0 80240930 AFB40028 */  sw        $s4, 0x28($sp)
/* BA50B4 80240934 0080A02D */  daddu     $s4, $a0, $zero
/* BA50B8 80240938 AFBF002C */  sw        $ra, 0x2c($sp)
/* BA50BC 8024093C AFB30024 */  sw        $s3, 0x24($sp)
/* BA50C0 80240940 AFB20020 */  sw        $s2, 0x20($sp)
/* BA50C4 80240944 AFB1001C */  sw        $s1, 0x1c($sp)
/* BA50C8 80240948 AFB00018 */  sw        $s0, 0x18($sp)
/* BA50CC 8024094C 8E910148 */  lw        $s1, 0x148($s4)
/* BA50D0 80240950 86240008 */  lh        $a0, 8($s1)
/* BA50D4 80240954 0C00EABB */  jal       get_npc_unsafe
/* BA50D8 80240958 00A0802D */   daddu    $s0, $a1, $zero
/* BA50DC 8024095C 16000005 */  bnez      $s0, .L80240974
/* BA50E0 80240960 0040902D */   daddu    $s2, $v0, $zero
/* BA50E4 80240964 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA50E8 80240968 30420004 */  andi      $v0, $v0, 4
/* BA50EC 8024096C 10400015 */  beqz      $v0, .L802409C4
/* BA50F0 80240970 00000000 */   nop      
.L80240974:
/* BA50F4 80240974 AE800070 */  sw        $zero, 0x70($s4)
/* BA50F8 80240978 8E420000 */  lw        $v0, ($s2)
/* BA50FC 8024097C 3C031F30 */  lui       $v1, 0x1f30
/* BA5100 80240980 A640008E */  sh        $zero, 0x8e($s2)
/* BA5104 80240984 34420102 */  ori       $v0, $v0, 0x102
/* BA5108 80240988 AE420000 */  sw        $v0, ($s2)
/* BA510C 8024098C 8E220000 */  lw        $v0, ($s1)
/* BA5110 80240990 3C01C47A */  lui       $at, 0xc47a
/* BA5114 80240994 44810000 */  mtc1      $at, $f0
/* BA5118 80240998 00431025 */  or        $v0, $v0, $v1
/* BA511C 8024099C AE220000 */  sw        $v0, ($s1)
/* BA5120 802409A0 AE400038 */  sw        $zero, 0x38($s2)
/* BA5124 802409A4 E640003C */  swc1      $f0, 0x3c($s2)
/* BA5128 802409A8 AE400040 */  sw        $zero, 0x40($s2)
/* BA512C 802409AC 8E2300B0 */  lw        $v1, 0xb0($s1)
/* BA5130 802409B0 30620004 */  andi      $v0, $v1, 4
/* BA5134 802409B4 10400003 */  beqz      $v0, .L802409C4
/* BA5138 802409B8 2402FFFB */   addiu    $v0, $zero, -5
/* BA513C 802409BC 00621024 */  and       $v0, $v1, $v0
/* BA5140 802409C0 AE2200B0 */  sw        $v0, 0xb0($s1)
.L802409C4:
/* BA5144 802409C4 8E930070 */  lw        $s3, 0x70($s4)
/* BA5148 802409C8 12600005 */  beqz      $s3, .L802409E0
/* BA514C 802409CC 24020001 */   addiu    $v0, $zero, 1
/* BA5150 802409D0 12620048 */  beq       $s3, $v0, .L80240AF4
/* BA5154 802409D4 00000000 */   nop      
/* BA5158 802409D8 080902DA */  j         .L80240B68
/* BA515C 802409DC 00000000 */   nop      
.L802409E0:
/* BA5160 802409E0 86240008 */  lh        $a0, 8($s1)
/* BA5164 802409E4 0C00FB3A */  jal       get_enemy
/* BA5168 802409E8 2484FFFF */   addiu    $a0, $a0, -1
/* BA516C 802409EC 0040802D */  daddu     $s0, $v0, $zero
/* BA5170 802409F0 0C00EABB */  jal       get_npc_unsafe
/* BA5174 802409F4 86040008 */   lh       $a0, 8($s0)
/* BA5178 802409F8 24030001 */  addiu     $v1, $zero, 1
/* BA517C 802409FC 0040982D */  daddu     $s3, $v0, $zero
/* BA5180 80240A00 A2230007 */  sb        $v1, 7($s1)
/* BA5184 80240A04 8E03006C */  lw        $v1, 0x6c($s0)
/* BA5188 80240A08 24020003 */  addiu     $v0, $zero, 3
/* BA518C 80240A0C 14620056 */  bne       $v1, $v0, .L80240B68
/* BA5190 80240A10 00000000 */   nop      
/* BA5194 80240A14 8E2500A8 */  lw        $a1, 0xa8($s1)
/* BA5198 80240A18 10A00003 */  beqz      $a1, .L80240A28
/* BA519C 80240A1C 0260202D */   daddu    $a0, $s3, $zero
/* BA51A0 80240A20 0C012530 */  jal       func_800494C0
/* BA51A4 80240A24 0000302D */   daddu    $a2, $zero, $zero
.L80240A28:
/* BA51A8 80240A28 27A40010 */  addiu     $a0, $sp, 0x10
/* BA51AC 80240A2C C6280070 */  lwc1      $f8, 0x70($s1)
/* BA51B0 80240A30 46804220 */  cvt.s.w   $f8, $f8
/* BA51B4 80240A34 C6620034 */  lwc1      $f2, 0x34($s3)
/* BA51B8 80240A38 3C014387 */  lui       $at, 0x4387
/* BA51BC 80240A3C 44810000 */  mtc1      $at, $f0
/* BA51C0 80240A40 44064000 */  mfc1      $a2, $f8
/* BA51C4 80240A44 46020001 */  sub.s     $f0, $f0, $f2
/* BA51C8 80240A48 C6660038 */  lwc1      $f6, 0x38($s3)
/* BA51CC 80240A4C C6640040 */  lwc1      $f4, 0x40($s3)
/* BA51D0 80240A50 44070000 */  mfc1      $a3, $f0
/* BA51D4 80240A54 27A50014 */  addiu     $a1, $sp, 0x14
/* BA51D8 80240A58 E7A60010 */  swc1      $f6, 0x10($sp)
/* BA51DC 80240A5C 0C00A7E7 */  jal       add_vec2D_polar
/* BA51E0 80240A60 E7A40014 */   swc1     $f4, 0x14($sp)
/* BA51E4 80240A64 C7A00010 */  lwc1      $f0, 0x10($sp)
/* BA51E8 80240A68 4600020D */  trunc.w.s $f8, $f0
/* BA51EC 80240A6C 44024000 */  mfc1      $v0, $f8
/* BA51F0 80240A70 E6400038 */  swc1      $f0, 0x38($s2)
/* BA51F4 80240A74 A6220010 */  sh        $v0, 0x10($s1)
/* BA51F8 80240A78 C660003C */  lwc1      $f0, 0x3c($s3)
/* BA51FC 80240A7C C622006C */  lwc1      $f2, 0x6c($s1)
/* BA5200 80240A80 468010A0 */  cvt.s.w   $f2, $f2
/* BA5204 80240A84 46020000 */  add.s     $f0, $f0, $f2
/* BA5208 80240A88 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* BA520C 80240A8C 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* BA5210 80240A90 E640003C */  swc1      $f0, 0x3c($s2)
/* BA5214 80240A94 C7A20014 */  lwc1      $f2, 0x14($sp)
/* BA5218 80240A98 4600020D */  trunc.w.s $f8, $f0
/* BA521C 80240A9C 44024000 */  mfc1      $v0, $f8
/* BA5220 80240AA0 00000000 */  nop       
/* BA5224 80240AA4 A6220012 */  sh        $v0, 0x12($s1)
/* BA5228 80240AA8 4600120D */  trunc.w.s $f8, $f2
/* BA522C 80240AAC 44024000 */  mfc1      $v0, $f8
/* BA5230 80240AB0 E6420040 */  swc1      $f2, 0x40($s2)
/* BA5234 80240AB4 A6220014 */  sh        $v0, 0x14($s1)
/* BA5238 80240AB8 8C660028 */  lw        $a2, 0x28($v1)
/* BA523C 80240ABC 8C670030 */  lw        $a3, 0x30($v1)
/* BA5240 80240AC0 C64C0038 */  lwc1      $f12, 0x38($s2)
/* BA5244 80240AC4 0C00A720 */  jal       atan2
/* BA5248 80240AC8 C64E0040 */   lwc1     $f14, 0x40($s2)
/* BA524C 80240ACC 3C03E0EF */  lui       $v1, 0xe0ef
/* BA5250 80240AD0 E640000C */  swc1      $f0, 0xc($s2)
/* BA5254 80240AD4 8E220000 */  lw        $v0, ($s1)
/* BA5258 80240AD8 3463FFFF */  ori       $v1, $v1, 0xffff
/* BA525C 80240ADC 00431024 */  and       $v0, $v0, $v1
/* BA5260 80240AE0 AE220000 */  sw        $v0, ($s1)
/* BA5264 80240AE4 24020001 */  addiu     $v0, $zero, 1
/* BA5268 80240AE8 A640008E */  sh        $zero, 0x8e($s2)
/* BA526C 80240AEC 080902DA */  j         .L80240B68
/* BA5270 80240AF0 AE820070 */   sw       $v0, 0x70($s4)
.L80240AF4:
/* BA5274 80240AF4 86240008 */  lh        $a0, 8($s1)
/* BA5278 80240AF8 0C00FB3A */  jal       get_enemy
/* BA527C 80240AFC 2484FFFF */   addiu    $a0, $a0, -1
/* BA5280 80240B00 0040802D */  daddu     $s0, $v0, $zero
/* BA5284 80240B04 0C00EABB */  jal       get_npc_unsafe
/* BA5288 80240B08 86040008 */   lh       $a0, 8($s0)
/* BA528C 80240B0C 9642008E */  lhu       $v0, 0x8e($s2)
/* BA5290 80240B10 24420001 */  addiu     $v0, $v0, 1
/* BA5294 80240B14 A642008E */  sh        $v0, 0x8e($s2)
/* BA5298 80240B18 00021400 */  sll       $v0, $v0, 0x10
/* BA529C 80240B1C 8E23007C */  lw        $v1, 0x7c($s1)
/* BA52A0 80240B20 00021403 */  sra       $v0, $v0, 0x10
/* BA52A4 80240B24 0043102A */  slt       $v0, $v0, $v1
/* BA52A8 80240B28 50400001 */  beql      $v0, $zero, .L80240B30
/* BA52AC 80240B2C A2200007 */   sb       $zero, 7($s1)
.L80240B30:
/* BA52B0 80240B30 8E03006C */  lw        $v1, 0x6c($s0)
/* BA52B4 80240B34 24020004 */  addiu     $v0, $zero, 4
/* BA52B8 80240B38 1462000B */  bne       $v1, $v0, .L80240B68
/* BA52BC 80240B3C 3C021F10 */   lui      $v0, 0x1f10
/* BA52C0 80240B40 8E230000 */  lw        $v1, ($s1)
/* BA52C4 80240B44 3C01C47A */  lui       $at, 0xc47a
/* BA52C8 80240B48 44810000 */  mtc1      $at, $f0
/* BA52CC 80240B4C 00621825 */  or        $v1, $v1, $v0
/* BA52D0 80240B50 AE230000 */  sw        $v1, ($s1)
/* BA52D4 80240B54 AE400038 */  sw        $zero, 0x38($s2)
/* BA52D8 80240B58 E640003C */  swc1      $f0, 0x3c($s2)
/* BA52DC 80240B5C AE400040 */  sw        $zero, 0x40($s2)
/* BA52E0 80240B60 A2330007 */  sb        $s3, 7($s1)
/* BA52E4 80240B64 AE800070 */  sw        $zero, 0x70($s4)
.L80240B68:
/* BA52E8 80240B68 8FBF002C */  lw        $ra, 0x2c($sp)
/* BA52EC 80240B6C 8FB40028 */  lw        $s4, 0x28($sp)
/* BA52F0 80240B70 8FB30024 */  lw        $s3, 0x24($sp)
/* BA52F4 80240B74 8FB20020 */  lw        $s2, 0x20($sp)
/* BA52F8 80240B78 8FB1001C */  lw        $s1, 0x1c($sp)
/* BA52FC 80240B7C 8FB00018 */  lw        $s0, 0x18($sp)
/* BA5300 80240B80 0000102D */  daddu     $v0, $zero, $zero
/* BA5304 80240B84 03E00008 */  jr        $ra
/* BA5308 80240B88 27BD0030 */   addiu    $sp, $sp, 0x30
