.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C78_C32158
/* C32158 80240C78 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* C3215C 80240C7C AFB20038 */  sw        $s2, 0x38($sp)
/* C32160 80240C80 0080902D */  daddu     $s2, $a0, $zero
/* C32164 80240C84 AFBF0044 */  sw        $ra, 0x44($sp)
/* C32168 80240C88 AFB40040 */  sw        $s4, 0x40($sp)
/* C3216C 80240C8C AFB3003C */  sw        $s3, 0x3c($sp)
/* C32170 80240C90 AFB10034 */  sw        $s1, 0x34($sp)
/* C32174 80240C94 AFB00030 */  sw        $s0, 0x30($sp)
/* C32178 80240C98 F7B60050 */  sdc1      $f22, 0x50($sp)
/* C3217C 80240C9C F7B40048 */  sdc1      $f20, 0x48($sp)
/* C32180 80240CA0 8E510148 */  lw        $s1, 0x148($s2)
/* C32184 80240CA4 00A0982D */  daddu     $s3, $a1, $zero
/* C32188 80240CA8 86240008 */  lh        $a0, 8($s1)
/* C3218C 80240CAC 0C00EABB */  jal       get_npc_unsafe
/* C32190 80240CB0 00C0A02D */   daddu    $s4, $a2, $zero
/* C32194 80240CB4 8E630014 */  lw        $v1, 0x14($s3)
/* C32198 80240CB8 04600030 */  bltz      $v1, .L80240D7C
/* C3219C 80240CBC 0040802D */   daddu    $s0, $v0, $zero
/* C321A0 80240CC0 8E420074 */  lw        $v0, 0x74($s2)
/* C321A4 80240CC4 1C40002C */  bgtz      $v0, .L80240D78
/* C321A8 80240CC8 2442FFFF */   addiu    $v0, $v0, -1
/* C321AC 80240CCC 0280202D */  daddu     $a0, $s4, $zero
/* C321B0 80240CD0 AE430074 */  sw        $v1, 0x74($s2)
/* C321B4 80240CD4 AFA00010 */  sw        $zero, 0x10($sp)
/* C321B8 80240CD8 8E66000C */  lw        $a2, 0xc($s3)
/* C321BC 80240CDC 8E670010 */  lw        $a3, 0x10($s3)
/* C321C0 80240CE0 0C01242D */  jal       func_800490B4
/* C321C4 80240CE4 0220282D */   daddu    $a1, $s1, $zero
/* C321C8 80240CE8 10400021 */  beqz      $v0, .L80240D70
/* C321CC 80240CEC 0000202D */   daddu    $a0, $zero, $zero
/* C321D0 80240CF0 0200282D */  daddu     $a1, $s0, $zero
/* C321D4 80240CF4 0000302D */  daddu     $a2, $zero, $zero
/* C321D8 80240CF8 860300A8 */  lh        $v1, 0xa8($s0)
/* C321DC 80240CFC 3C013F80 */  lui       $at, 0x3f80
/* C321E0 80240D00 44810000 */  mtc1      $at, $f0
/* C321E4 80240D04 3C014000 */  lui       $at, 0x4000
/* C321E8 80240D08 44811000 */  mtc1      $at, $f2
/* C321EC 80240D0C 3C01C1A0 */  lui       $at, 0xc1a0
/* C321F0 80240D10 44812000 */  mtc1      $at, $f4
/* C321F4 80240D14 2402000F */  addiu     $v0, $zero, 0xf
/* C321F8 80240D18 AFA2001C */  sw        $v0, 0x1c($sp)
/* C321FC 80240D1C 44833000 */  mtc1      $v1, $f6
/* C32200 80240D20 00000000 */  nop
/* C32204 80240D24 468031A0 */  cvt.s.w   $f6, $f6
/* C32208 80240D28 44073000 */  mfc1      $a3, $f6
/* C3220C 80240D2C 27A20028 */  addiu     $v0, $sp, 0x28
/* C32210 80240D30 AFA20020 */  sw        $v0, 0x20($sp)
/* C32214 80240D34 E7A00010 */  swc1      $f0, 0x10($sp)
/* C32218 80240D38 E7A20014 */  swc1      $f2, 0x14($sp)
/* C3221C 80240D3C 0C01BFA4 */  jal       fx_emote
/* C32220 80240D40 E7A40018 */   swc1     $f4, 0x18($sp)
/* C32224 80240D44 0200202D */  daddu     $a0, $s0, $zero
/* C32228 80240D48 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C3222C 80240D4C 0C012530 */  jal       func_800494C0
/* C32230 80240D50 3C060020 */   lui      $a2, 0x20
/* C32234 80240D54 8E220018 */  lw        $v0, 0x18($s1)
/* C32238 80240D58 9442002A */  lhu       $v0, 0x2a($v0)
/* C3223C 80240D5C 30420001 */  andi      $v0, $v0, 1
/* C32240 80240D60 14400064 */  bnez      $v0, .L80240EF4
/* C32244 80240D64 2402000A */   addiu    $v0, $zero, 0xa
/* C32248 80240D68 080903BD */  j         .L80240EF4
/* C3224C 80240D6C 2402000C */   addiu    $v0, $zero, 0xc
.L80240D70:
/* C32250 80240D70 8E420074 */  lw        $v0, 0x74($s2)
/* C32254 80240D74 2442FFFF */  addiu     $v0, $v0, -1
.L80240D78:
/* C32258 80240D78 AE420074 */  sw        $v0, 0x74($s2)
.L80240D7C:
/* C3225C 80240D7C 8602008C */  lh        $v0, 0x8c($s0)
/* C32260 80240D80 1440005D */  bnez      $v0, .L80240EF8
/* C32264 80240D84 00000000 */   nop
/* C32268 80240D88 C6000018 */  lwc1      $f0, 0x18($s0)
/* C3226C 80240D8C 3C014010 */  lui       $at, 0x4010
/* C32270 80240D90 44811800 */  mtc1      $at, $f3
/* C32274 80240D94 44801000 */  mtc1      $zero, $f2
/* C32278 80240D98 46000021 */  cvt.d.s   $f0, $f0
/* C3227C 80240D9C 4622003C */  c.lt.d    $f0, $f2
/* C32280 80240DA0 00000000 */  nop
/* C32284 80240DA4 45000003 */  bc1f      .L80240DB4
/* C32288 80240DA8 0200202D */   daddu    $a0, $s0, $zero
/* C3228C 80240DAC 0809036E */  j         .L80240DB8
/* C32290 80240DB0 0000282D */   daddu    $a1, $zero, $zero
.L80240DB4:
/* C32294 80240DB4 24050001 */  addiu     $a1, $zero, 1
.L80240DB8:
/* C32298 80240DB8 0C00F598 */  jal       func_8003D660
/* C3229C 80240DBC 00000000 */   nop
/* C322A0 80240DC0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C322A4 80240DC4 8E430078 */  lw        $v1, 0x78($s2)
/* C322A8 80240DC8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C322AC 80240DCC 00031040 */  sll       $v0, $v1, 1
/* C322B0 80240DD0 00431021 */  addu      $v0, $v0, $v1
/* C322B4 80240DD4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C322B8 80240DD8 00021080 */  sll       $v0, $v0, 2
/* C322BC 80240DDC 00431021 */  addu      $v0, $v0, $v1
/* C322C0 80240DE0 C4560004 */  lwc1      $f22, 4($v0)
/* C322C4 80240DE4 4680B5A0 */  cvt.s.w   $f22, $f22
/* C322C8 80240DE8 C454000C */  lwc1      $f20, 0xc($v0)
/* C322CC 80240DEC 4680A520 */  cvt.s.w   $f20, $f20
/* C322D0 80240DF0 4406B000 */  mfc1      $a2, $f22
/* C322D4 80240DF4 4407A000 */  mfc1      $a3, $f20
/* C322D8 80240DF8 0C00A720 */  jal       atan2
/* C322DC 80240DFC 00000000 */   nop
/* C322E0 80240E00 8E050018 */  lw        $a1, 0x18($s0)
/* C322E4 80240E04 44060000 */  mfc1      $a2, $f0
/* C322E8 80240E08 0200202D */  daddu     $a0, $s0, $zero
/* C322EC 80240E0C 0C00EA95 */  jal       npc_move_heading
/* C322F0 80240E10 AE06000C */   sw       $a2, 0xc($s0)
/* C322F4 80240E14 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C322F8 80240E18 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C322FC 80240E1C 4406B000 */  mfc1      $a2, $f22
/* C32300 80240E20 4407A000 */  mfc1      $a3, $f20
/* C32304 80240E24 0C00A7B5 */  jal       dist2D
/* C32308 80240E28 00000000 */   nop
/* C3230C 80240E2C C6020018 */  lwc1      $f2, 0x18($s0)
/* C32310 80240E30 4602003E */  c.le.s    $f0, $f2
/* C32314 80240E34 00000000 */  nop
/* C32318 80240E38 4500002F */  bc1f      .L80240EF8
/* C3231C 80240E3C 240403E8 */   addiu    $a0, $zero, 0x3e8
/* C32320 80240E40 24020002 */  addiu     $v0, $zero, 2
/* C32324 80240E44 0C00A67F */  jal       rand_int
/* C32328 80240E48 AE420070 */   sw       $v0, 0x70($s2)
/* C3232C 80240E4C 3C035555 */  lui       $v1, 0x5555
/* C32330 80240E50 34635556 */  ori       $v1, $v1, 0x5556
/* C32334 80240E54 00430018 */  mult      $v0, $v1
/* C32338 80240E58 000227C3 */  sra       $a0, $v0, 0x1f
/* C3233C 80240E5C 00004010 */  mfhi      $t0
/* C32340 80240E60 01042023 */  subu      $a0, $t0, $a0
/* C32344 80240E64 00041840 */  sll       $v1, $a0, 1
/* C32348 80240E68 00641821 */  addu      $v1, $v1, $a0
/* C3234C 80240E6C 00431023 */  subu      $v0, $v0, $v1
/* C32350 80240E70 24430002 */  addiu     $v1, $v0, 2
/* C32354 80240E74 AE430074 */  sw        $v1, 0x74($s2)
/* C32358 80240E78 8E62002C */  lw        $v0, 0x2c($s3)
/* C3235C 80240E7C 18400009 */  blez      $v0, .L80240EA4
/* C32360 80240E80 24020004 */   addiu    $v0, $zero, 4
/* C32364 80240E84 8E620004 */  lw        $v0, 4($s3)
/* C32368 80240E88 18400006 */  blez      $v0, .L80240EA4
/* C3236C 80240E8C 24020004 */   addiu    $v0, $zero, 4
/* C32370 80240E90 8E620008 */  lw        $v0, 8($s3)
/* C32374 80240E94 18400003 */  blez      $v0, .L80240EA4
/* C32378 80240E98 24020004 */   addiu    $v0, $zero, 4
/* C3237C 80240E9C 14600002 */  bnez      $v1, .L80240EA8
/* C32380 80240EA0 00000000 */   nop
.L80240EA4:
/* C32384 80240EA4 AE420070 */  sw        $v0, 0x70($s2)
.L80240EA8:
/* C32388 80240EA8 0C00A67F */  jal       rand_int
/* C3238C 80240EAC 24042710 */   addiu    $a0, $zero, 0x2710
/* C32390 80240EB0 3C0351EB */  lui       $v1, 0x51eb
/* C32394 80240EB4 3463851F */  ori       $v1, $v1, 0x851f
/* C32398 80240EB8 00430018 */  mult      $v0, $v1
/* C3239C 80240EBC 00021FC3 */  sra       $v1, $v0, 0x1f
/* C323A0 80240EC0 00004010 */  mfhi      $t0
/* C323A4 80240EC4 00082143 */  sra       $a0, $t0, 5
/* C323A8 80240EC8 00832023 */  subu      $a0, $a0, $v1
/* C323AC 80240ECC 00041840 */  sll       $v1, $a0, 1
/* C323B0 80240ED0 00641821 */  addu      $v1, $v1, $a0
/* C323B4 80240ED4 000318C0 */  sll       $v1, $v1, 3
/* C323B8 80240ED8 00641821 */  addu      $v1, $v1, $a0
/* C323BC 80240EDC 00031880 */  sll       $v1, $v1, 2
/* C323C0 80240EE0 8E640004 */  lw        $a0, 4($s3)
/* C323C4 80240EE4 00431023 */  subu      $v0, $v0, $v1
/* C323C8 80240EE8 0044102A */  slt       $v0, $v0, $a0
/* C323CC 80240EEC 10400002 */  beqz      $v0, .L80240EF8
/* C323D0 80240EF0 24020004 */   addiu    $v0, $zero, 4
.L80240EF4:
/* C323D4 80240EF4 AE420070 */  sw        $v0, 0x70($s2)
.L80240EF8:
/* C323D8 80240EF8 8FBF0044 */  lw        $ra, 0x44($sp)
/* C323DC 80240EFC 8FB40040 */  lw        $s4, 0x40($sp)
/* C323E0 80240F00 8FB3003C */  lw        $s3, 0x3c($sp)
/* C323E4 80240F04 8FB20038 */  lw        $s2, 0x38($sp)
/* C323E8 80240F08 8FB10034 */  lw        $s1, 0x34($sp)
/* C323EC 80240F0C 8FB00030 */  lw        $s0, 0x30($sp)
/* C323F0 80240F10 D7B60050 */  ldc1      $f22, 0x50($sp)
/* C323F4 80240F14 D7B40048 */  ldc1      $f20, 0x48($sp)
/* C323F8 80240F18 03E00008 */  jr        $ra
/* C323FC 80240F1C 27BD0058 */   addiu    $sp, $sp, 0x58
