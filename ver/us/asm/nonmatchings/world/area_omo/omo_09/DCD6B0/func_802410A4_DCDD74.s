.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel omo_09_UnkFunc13
/* DCDD74 802410A4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* DCDD78 802410A8 AFB20038 */  sw        $s2, 0x38($sp)
/* DCDD7C 802410AC 0080902D */  daddu     $s2, $a0, $zero
/* DCDD80 802410B0 AFBF0044 */  sw        $ra, 0x44($sp)
/* DCDD84 802410B4 AFB40040 */  sw        $s4, 0x40($sp)
/* DCDD88 802410B8 AFB3003C */  sw        $s3, 0x3c($sp)
/* DCDD8C 802410BC AFB10034 */  sw        $s1, 0x34($sp)
/* DCDD90 802410C0 AFB00030 */  sw        $s0, 0x30($sp)
/* DCDD94 802410C4 F7B60050 */  sdc1      $f22, 0x50($sp)
/* DCDD98 802410C8 F7B40048 */  sdc1      $f20, 0x48($sp)
/* DCDD9C 802410CC 8E510148 */  lw        $s1, 0x148($s2)
/* DCDDA0 802410D0 00A0982D */  daddu     $s3, $a1, $zero
/* DCDDA4 802410D4 86240008 */  lh        $a0, 8($s1)
/* DCDDA8 802410D8 0C00EABB */  jal       get_npc_unsafe
/* DCDDAC 802410DC 00C0A02D */   daddu    $s4, $a2, $zero
/* DCDDB0 802410E0 8E630014 */  lw        $v1, 0x14($s3)
/* DCDDB4 802410E4 04600030 */  bltz      $v1, .L802411A8
/* DCDDB8 802410E8 0040802D */   daddu    $s0, $v0, $zero
/* DCDDBC 802410EC 8E420074 */  lw        $v0, 0x74($s2)
/* DCDDC0 802410F0 1C40002C */  bgtz      $v0, .L802411A4
/* DCDDC4 802410F4 2442FFFF */   addiu    $v0, $v0, -1
/* DCDDC8 802410F8 0280202D */  daddu     $a0, $s4, $zero
/* DCDDCC 802410FC AE430074 */  sw        $v1, 0x74($s2)
/* DCDDD0 80241100 AFA00010 */  sw        $zero, 0x10($sp)
/* DCDDD4 80241104 8E66000C */  lw        $a2, 0xc($s3)
/* DCDDD8 80241108 8E670010 */  lw        $a3, 0x10($s3)
/* DCDDDC 8024110C 0C01242D */  jal       func_800490B4
/* DCDDE0 80241110 0220282D */   daddu    $a1, $s1, $zero
/* DCDDE4 80241114 10400021 */  beqz      $v0, .L8024119C
/* DCDDE8 80241118 0000202D */   daddu    $a0, $zero, $zero
/* DCDDEC 8024111C 0200282D */  daddu     $a1, $s0, $zero
/* DCDDF0 80241120 0000302D */  daddu     $a2, $zero, $zero
/* DCDDF4 80241124 860300A8 */  lh        $v1, 0xa8($s0)
/* DCDDF8 80241128 3C013F80 */  lui       $at, 0x3f80
/* DCDDFC 8024112C 44810000 */  mtc1      $at, $f0
/* DCDE00 80241130 3C014000 */  lui       $at, 0x4000
/* DCDE04 80241134 44811000 */  mtc1      $at, $f2
/* DCDE08 80241138 3C01C1A0 */  lui       $at, 0xc1a0
/* DCDE0C 8024113C 44812000 */  mtc1      $at, $f4
/* DCDE10 80241140 2402000F */  addiu     $v0, $zero, 0xf
/* DCDE14 80241144 AFA2001C */  sw        $v0, 0x1c($sp)
/* DCDE18 80241148 44833000 */  mtc1      $v1, $f6
/* DCDE1C 8024114C 00000000 */  nop
/* DCDE20 80241150 468031A0 */  cvt.s.w   $f6, $f6
/* DCDE24 80241154 44073000 */  mfc1      $a3, $f6
/* DCDE28 80241158 27A20028 */  addiu     $v0, $sp, 0x28
/* DCDE2C 8024115C AFA20020 */  sw        $v0, 0x20($sp)
/* DCDE30 80241160 E7A00010 */  swc1      $f0, 0x10($sp)
/* DCDE34 80241164 E7A20014 */  swc1      $f2, 0x14($sp)
/* DCDE38 80241168 0C01BFA4 */  jal       fx_emote
/* DCDE3C 8024116C E7A40018 */   swc1     $f4, 0x18($sp)
/* DCDE40 80241170 0200202D */  daddu     $a0, $s0, $zero
/* DCDE44 80241174 240502F4 */  addiu     $a1, $zero, 0x2f4
/* DCDE48 80241178 0C012530 */  jal       func_800494C0
/* DCDE4C 8024117C 3C060020 */   lui      $a2, 0x20
/* DCDE50 80241180 8E220018 */  lw        $v0, 0x18($s1)
/* DCDE54 80241184 9442002A */  lhu       $v0, 0x2a($v0)
/* DCDE58 80241188 30420001 */  andi      $v0, $v0, 1
/* DCDE5C 8024118C 14400064 */  bnez      $v0, .L80241320
/* DCDE60 80241190 2402000A */   addiu    $v0, $zero, 0xa
/* DCDE64 80241194 080904C8 */  j         .L80241320
/* DCDE68 80241198 2402000C */   addiu    $v0, $zero, 0xc
.L8024119C:
/* DCDE6C 8024119C 8E420074 */  lw        $v0, 0x74($s2)
/* DCDE70 802411A0 2442FFFF */  addiu     $v0, $v0, -1
.L802411A4:
/* DCDE74 802411A4 AE420074 */  sw        $v0, 0x74($s2)
.L802411A8:
/* DCDE78 802411A8 8602008C */  lh        $v0, 0x8c($s0)
/* DCDE7C 802411AC 1440005D */  bnez      $v0, .L80241324
/* DCDE80 802411B0 00000000 */   nop
/* DCDE84 802411B4 C6000018 */  lwc1      $f0, 0x18($s0)
/* DCDE88 802411B8 3C014010 */  lui       $at, 0x4010
/* DCDE8C 802411BC 44811800 */  mtc1      $at, $f3
/* DCDE90 802411C0 44801000 */  mtc1      $zero, $f2
/* DCDE94 802411C4 46000021 */  cvt.d.s   $f0, $f0
/* DCDE98 802411C8 4622003C */  c.lt.d    $f0, $f2
/* DCDE9C 802411CC 00000000 */  nop
/* DCDEA0 802411D0 45000003 */  bc1f      .L802411E0
/* DCDEA4 802411D4 0200202D */   daddu    $a0, $s0, $zero
/* DCDEA8 802411D8 08090479 */  j         .L802411E4
/* DCDEAC 802411DC 0000282D */   daddu    $a1, $zero, $zero
.L802411E0:
/* DCDEB0 802411E0 24050001 */  addiu     $a1, $zero, 1
.L802411E4:
/* DCDEB4 802411E4 0C00F598 */  jal       func_8003D660
/* DCDEB8 802411E8 00000000 */   nop
/* DCDEBC 802411EC C60C0038 */  lwc1      $f12, 0x38($s0)
/* DCDEC0 802411F0 8E430078 */  lw        $v1, 0x78($s2)
/* DCDEC4 802411F4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DCDEC8 802411F8 00031040 */  sll       $v0, $v1, 1
/* DCDECC 802411FC 00431021 */  addu      $v0, $v0, $v1
/* DCDED0 80241200 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DCDED4 80241204 00021080 */  sll       $v0, $v0, 2
/* DCDED8 80241208 00431021 */  addu      $v0, $v0, $v1
/* DCDEDC 8024120C C4560004 */  lwc1      $f22, 4($v0)
/* DCDEE0 80241210 4680B5A0 */  cvt.s.w   $f22, $f22
/* DCDEE4 80241214 C454000C */  lwc1      $f20, 0xc($v0)
/* DCDEE8 80241218 4680A520 */  cvt.s.w   $f20, $f20
/* DCDEEC 8024121C 4406B000 */  mfc1      $a2, $f22
/* DCDEF0 80241220 4407A000 */  mfc1      $a3, $f20
/* DCDEF4 80241224 0C00A720 */  jal       atan2
/* DCDEF8 80241228 00000000 */   nop
/* DCDEFC 8024122C 8E050018 */  lw        $a1, 0x18($s0)
/* DCDF00 80241230 44060000 */  mfc1      $a2, $f0
/* DCDF04 80241234 0200202D */  daddu     $a0, $s0, $zero
/* DCDF08 80241238 0C00EA95 */  jal       npc_move_heading
/* DCDF0C 8024123C AE06000C */   sw       $a2, 0xc($s0)
/* DCDF10 80241240 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DCDF14 80241244 C60E0040 */  lwc1      $f14, 0x40($s0)
/* DCDF18 80241248 4406B000 */  mfc1      $a2, $f22
/* DCDF1C 8024124C 4407A000 */  mfc1      $a3, $f20
/* DCDF20 80241250 0C00A7B5 */  jal       dist2D
/* DCDF24 80241254 00000000 */   nop
/* DCDF28 80241258 C6020018 */  lwc1      $f2, 0x18($s0)
/* DCDF2C 8024125C 4602003E */  c.le.s    $f0, $f2
/* DCDF30 80241260 00000000 */  nop
/* DCDF34 80241264 4500002F */  bc1f      .L80241324
/* DCDF38 80241268 240403E8 */   addiu    $a0, $zero, 0x3e8
/* DCDF3C 8024126C 24020002 */  addiu     $v0, $zero, 2
/* DCDF40 80241270 0C00A67F */  jal       rand_int
/* DCDF44 80241274 AE420070 */   sw       $v0, 0x70($s2)
/* DCDF48 80241278 3C035555 */  lui       $v1, 0x5555
/* DCDF4C 8024127C 34635556 */  ori       $v1, $v1, 0x5556
/* DCDF50 80241280 00430018 */  mult      $v0, $v1
/* DCDF54 80241284 000227C3 */  sra       $a0, $v0, 0x1f
/* DCDF58 80241288 00004010 */  mfhi      $t0
/* DCDF5C 8024128C 01042023 */  subu      $a0, $t0, $a0
/* DCDF60 80241290 00041840 */  sll       $v1, $a0, 1
/* DCDF64 80241294 00641821 */  addu      $v1, $v1, $a0
/* DCDF68 80241298 00431023 */  subu      $v0, $v0, $v1
/* DCDF6C 8024129C 24430002 */  addiu     $v1, $v0, 2
/* DCDF70 802412A0 AE430074 */  sw        $v1, 0x74($s2)
/* DCDF74 802412A4 8E62002C */  lw        $v0, 0x2c($s3)
/* DCDF78 802412A8 18400009 */  blez      $v0, .L802412D0
/* DCDF7C 802412AC 24020004 */   addiu    $v0, $zero, 4
/* DCDF80 802412B0 8E620004 */  lw        $v0, 4($s3)
/* DCDF84 802412B4 18400006 */  blez      $v0, .L802412D0
/* DCDF88 802412B8 24020004 */   addiu    $v0, $zero, 4
/* DCDF8C 802412BC 8E620008 */  lw        $v0, 8($s3)
/* DCDF90 802412C0 18400003 */  blez      $v0, .L802412D0
/* DCDF94 802412C4 24020004 */   addiu    $v0, $zero, 4
/* DCDF98 802412C8 14600002 */  bnez      $v1, .L802412D4
/* DCDF9C 802412CC 00000000 */   nop
.L802412D0:
/* DCDFA0 802412D0 AE420070 */  sw        $v0, 0x70($s2)
.L802412D4:
/* DCDFA4 802412D4 0C00A67F */  jal       rand_int
/* DCDFA8 802412D8 24042710 */   addiu    $a0, $zero, 0x2710
/* DCDFAC 802412DC 3C0351EB */  lui       $v1, 0x51eb
/* DCDFB0 802412E0 3463851F */  ori       $v1, $v1, 0x851f
/* DCDFB4 802412E4 00430018 */  mult      $v0, $v1
/* DCDFB8 802412E8 00021FC3 */  sra       $v1, $v0, 0x1f
/* DCDFBC 802412EC 00004010 */  mfhi      $t0
/* DCDFC0 802412F0 00082143 */  sra       $a0, $t0, 5
/* DCDFC4 802412F4 00832023 */  subu      $a0, $a0, $v1
/* DCDFC8 802412F8 00041840 */  sll       $v1, $a0, 1
/* DCDFCC 802412FC 00641821 */  addu      $v1, $v1, $a0
/* DCDFD0 80241300 000318C0 */  sll       $v1, $v1, 3
/* DCDFD4 80241304 00641821 */  addu      $v1, $v1, $a0
/* DCDFD8 80241308 00031880 */  sll       $v1, $v1, 2
/* DCDFDC 8024130C 8E640004 */  lw        $a0, 4($s3)
/* DCDFE0 80241310 00431023 */  subu      $v0, $v0, $v1
/* DCDFE4 80241314 0044102A */  slt       $v0, $v0, $a0
/* DCDFE8 80241318 10400002 */  beqz      $v0, .L80241324
/* DCDFEC 8024131C 24020004 */   addiu    $v0, $zero, 4
.L80241320:
/* DCDFF0 80241320 AE420070 */  sw        $v0, 0x70($s2)
.L80241324:
/* DCDFF4 80241324 8FBF0044 */  lw        $ra, 0x44($sp)
/* DCDFF8 80241328 8FB40040 */  lw        $s4, 0x40($sp)
/* DCDFFC 8024132C 8FB3003C */  lw        $s3, 0x3c($sp)
/* DCE000 80241330 8FB20038 */  lw        $s2, 0x38($sp)
/* DCE004 80241334 8FB10034 */  lw        $s1, 0x34($sp)
/* DCE008 80241338 8FB00030 */  lw        $s0, 0x30($sp)
/* DCE00C 8024133C D7B60050 */  ldc1      $f22, 0x50($sp)
/* DCE010 80241340 D7B40048 */  ldc1      $f20, 0x48($sp)
/* DCE014 80241344 03E00008 */  jr        $ra
/* DCE018 80241348 27BD0058 */   addiu    $sp, $sp, 0x58
