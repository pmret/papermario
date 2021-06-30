.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240430_B9DD90
/* B9DD90 80240430 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* B9DD94 80240434 AFB3004C */  sw        $s3, 0x4c($sp)
/* B9DD98 80240438 0080982D */  daddu     $s3, $a0, $zero
/* B9DD9C 8024043C AFBF0054 */  sw        $ra, 0x54($sp)
/* B9DDA0 80240440 AFB40050 */  sw        $s4, 0x50($sp)
/* B9DDA4 80240444 AFB20048 */  sw        $s2, 0x48($sp)
/* B9DDA8 80240448 AFB10044 */  sw        $s1, 0x44($sp)
/* B9DDAC 8024044C AFB00040 */  sw        $s0, 0x40($sp)
/* B9DDB0 80240450 F7B40058 */  sdc1      $f20, 0x58($sp)
/* B9DDB4 80240454 8E710148 */  lw        $s1, 0x148($s3)
/* B9DDB8 80240458 00A0A02D */  daddu     $s4, $a1, $zero
/* B9DDBC 8024045C 86240008 */  lh        $a0, 8($s1)
/* B9DDC0 80240460 0C00EABB */  jal       get_npc_unsafe
/* B9DDC4 80240464 00C0902D */   daddu    $s2, $a2, $zero
/* B9DDC8 80240468 8E830014 */  lw        $v1, 0x14($s4)
/* B9DDCC 8024046C 04600034 */  bltz      $v1, .L80240540
/* B9DDD0 80240470 0040802D */   daddu    $s0, $v0, $zero
/* B9DDD4 80240474 8E620074 */  lw        $v0, 0x74($s3)
/* B9DDD8 80240478 1C400030 */  bgtz      $v0, .L8024053C
/* B9DDDC 8024047C 2442FFFF */   addiu    $v0, $v0, -1
/* B9DDE0 80240480 0240202D */  daddu     $a0, $s2, $zero
/* B9DDE4 80240484 AE630074 */  sw        $v1, 0x74($s3)
/* B9DDE8 80240488 AFA00010 */  sw        $zero, 0x10($sp)
/* B9DDEC 8024048C 8E86000C */  lw        $a2, 0xc($s4)
/* B9DDF0 80240490 8E870010 */  lw        $a3, 0x10($s4)
/* B9DDF4 80240494 0C01242D */  jal       func_800490B4
/* B9DDF8 80240498 0220282D */   daddu    $a1, $s1, $zero
/* B9DDFC 8024049C 10400025 */  beqz      $v0, .L80240534
/* B9DE00 802404A0 0000202D */   daddu    $a0, $zero, $zero
/* B9DE04 802404A4 0200282D */  daddu     $a1, $s0, $zero
/* B9DE08 802404A8 0000302D */  daddu     $a2, $zero, $zero
/* B9DE0C 802404AC 860300A8 */  lh        $v1, 0xa8($s0)
/* B9DE10 802404B0 3C013F80 */  lui       $at, 0x3f80
/* B9DE14 802404B4 44810000 */  mtc1      $at, $f0
/* B9DE18 802404B8 3C014000 */  lui       $at, 0x4000
/* B9DE1C 802404BC 44811000 */  mtc1      $at, $f2
/* B9DE20 802404C0 3C01C1A0 */  lui       $at, 0xc1a0
/* B9DE24 802404C4 44812000 */  mtc1      $at, $f4
/* B9DE28 802404C8 2402000F */  addiu     $v0, $zero, 0xf
/* B9DE2C 802404CC AFA2001C */  sw        $v0, 0x1c($sp)
/* B9DE30 802404D0 44835000 */  mtc1      $v1, $f10
/* B9DE34 802404D4 00000000 */  nop
/* B9DE38 802404D8 468052A0 */  cvt.s.w   $f10, $f10
/* B9DE3C 802404DC 44075000 */  mfc1      $a3, $f10
/* B9DE40 802404E0 27A20028 */  addiu     $v0, $sp, 0x28
/* B9DE44 802404E4 AFA20020 */  sw        $v0, 0x20($sp)
/* B9DE48 802404E8 E7A00010 */  swc1      $f0, 0x10($sp)
/* B9DE4C 802404EC E7A20014 */  swc1      $f2, 0x14($sp)
/* B9DE50 802404F0 0C01BFA4 */  jal       fx_emote
/* B9DE54 802404F4 E7A40018 */   swc1     $f4, 0x18($sp)
/* B9DE58 802404F8 0200202D */  daddu     $a0, $s0, $zero
/* B9DE5C 802404FC 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B9DE60 80240500 0C012530 */  jal       ai_enemy_play_sound
/* B9DE64 80240504 3C060020 */   lui      $a2, 0x20
/* B9DE68 80240508 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B9DE6C 8024050C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B9DE70 80240510 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B9DE74 80240514 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B9DE78 80240518 8C460028 */  lw        $a2, 0x28($v0)
/* B9DE7C 8024051C 0C00A720 */  jal       atan2
/* B9DE80 80240520 8C470030 */   lw       $a3, 0x30($v0)
/* B9DE84 80240524 2402000C */  addiu     $v0, $zero, 0xc
/* B9DE88 80240528 E600000C */  swc1      $f0, 0xc($s0)
/* B9DE8C 8024052C 080901D1 */  j         .L80240744
/* B9DE90 80240530 AE620070 */   sw       $v0, 0x70($s3)
.L80240534:
/* B9DE94 80240534 8E620074 */  lw        $v0, 0x74($s3)
/* B9DE98 80240538 2442FFFF */  addiu     $v0, $v0, -1
.L8024053C:
/* B9DE9C 8024053C AE620074 */  sw        $v0, 0x74($s3)
.L80240540:
/* B9DEA0 80240540 C6000018 */  lwc1      $f0, 0x18($s0)
/* B9DEA4 80240544 44801000 */  mtc1      $zero, $f2
/* B9DEA8 80240548 44801800 */  mtc1      $zero, $f3
/* B9DEAC 8024054C 46000021 */  cvt.d.s   $f0, $f0
/* B9DEB0 80240550 4620103C */  c.lt.d    $f2, $f0
/* B9DEB4 80240554 00000000 */  nop
/* B9DEB8 80240558 45000025 */  bc1f      .L802405F0
/* B9DEBC 8024055C 27A5002C */   addiu    $a1, $sp, 0x2c
/* B9DEC0 80240560 C6000038 */  lwc1      $f0, 0x38($s0)
/* B9DEC4 80240564 860200A6 */  lh        $v0, 0xa6($s0)
/* B9DEC8 80240568 3C018024 */  lui       $at, %hi(D_80242D80_BA06E0)
/* B9DECC 8024056C D4222D80 */  ldc1      $f2, %lo(D_80242D80_BA06E0)($at)
/* B9DED0 80240570 27A60030 */  addiu     $a2, $sp, 0x30
/* B9DED4 80240574 E7A0002C */  swc1      $f0, 0x2c($sp)
/* B9DED8 80240578 44820000 */  mtc1      $v0, $f0
/* B9DEDC 8024057C 00000000 */  nop
/* B9DEE0 80240580 46800020 */  cvt.s.w   $f0, $f0
/* B9DEE4 80240584 46000021 */  cvt.d.s   $f0, $f0
/* B9DEE8 80240588 C604003C */  lwc1      $f4, 0x3c($s0)
/* B9DEEC 8024058C C6060040 */  lwc1      $f6, 0x40($s0)
/* B9DEF0 80240590 C6080018 */  lwc1      $f8, 0x18($s0)
/* B9DEF4 80240594 860200A8 */  lh        $v0, 0xa8($s0)
/* B9DEF8 80240598 46220002 */  mul.d     $f0, $f0, $f2
/* B9DEFC 8024059C 00000000 */  nop
/* B9DF00 802405A0 E7A40030 */  swc1      $f4, 0x30($sp)
/* B9DF04 802405A4 E7A60034 */  swc1      $f6, 0x34($sp)
/* B9DF08 802405A8 E7A80010 */  swc1      $f8, 0x10($sp)
/* B9DF0C 802405AC C604000C */  lwc1      $f4, 0xc($s0)
/* B9DF10 802405B0 44821000 */  mtc1      $v0, $f2
/* B9DF14 802405B4 00000000 */  nop
/* B9DF18 802405B8 468010A0 */  cvt.s.w   $f2, $f2
/* B9DF1C 802405BC E7A20018 */  swc1      $f2, 0x18($sp)
/* B9DF20 802405C0 E7A40014 */  swc1      $f4, 0x14($sp)
/* B9DF24 802405C4 46200020 */  cvt.s.d   $f0, $f0
/* B9DF28 802405C8 E7A0001C */  swc1      $f0, 0x1c($sp)
/* B9DF2C 802405CC 8E040080 */  lw        $a0, 0x80($s0)
/* B9DF30 802405D0 0C037711 */  jal       npc_test_move_simple_with_slipping
/* B9DF34 802405D4 27A70034 */   addiu    $a3, $sp, 0x34
/* B9DF38 802405D8 54400005 */  bnel      $v0, $zero, .L802405F0
/* B9DF3C 802405DC AE000018 */   sw       $zero, 0x18($s0)
/* B9DF40 802405E0 8E050018 */  lw        $a1, 0x18($s0)
/* B9DF44 802405E4 8E06000C */  lw        $a2, 0xc($s0)
/* B9DF48 802405E8 0C00EA95 */  jal       npc_move_heading
/* B9DF4C 802405EC 0200202D */   daddu    $a0, $s0, $zero
.L802405F0:
/* B9DF50 802405F0 C600001C */  lwc1      $f0, 0x1c($s0)
/* B9DF54 802405F4 44801000 */  mtc1      $zero, $f2
/* B9DF58 802405F8 44801800 */  mtc1      $zero, $f3
/* B9DF5C 802405FC 46000021 */  cvt.d.s   $f0, $f0
/* B9DF60 80240600 4622003C */  c.lt.d    $f0, $f2
/* B9DF64 80240604 00000000 */  nop
/* B9DF68 80240608 45000047 */  bc1f      .L80240728
/* B9DF6C 8024060C 27A5002C */   addiu    $a1, $sp, 0x2c
/* B9DF70 80240610 27A60030 */  addiu     $a2, $sp, 0x30
/* B9DF74 80240614 27A20038 */  addiu     $v0, $sp, 0x38
/* B9DF78 80240618 C602003C */  lwc1      $f2, 0x3c($s0)
/* B9DF7C 8024061C C6060038 */  lwc1      $f6, 0x38($s0)
/* B9DF80 80240620 3C01402A */  lui       $at, 0x402a
/* B9DF84 80240624 4481A800 */  mtc1      $at, $f21
/* B9DF88 80240628 4480A000 */  mtc1      $zero, $f20
/* B9DF8C 8024062C 460010A1 */  cvt.d.s   $f2, $f2
/* B9DF90 80240630 46341080 */  add.d     $f2, $f2, $f20
/* B9DF94 80240634 C600001C */  lwc1      $f0, 0x1c($s0)
/* B9DF98 80240638 C6040040 */  lwc1      $f4, 0x40($s0)
/* B9DF9C 8024063C 46000005 */  abs.s     $f0, $f0
/* B9DFA0 80240640 E7A40034 */  swc1      $f4, 0x34($sp)
/* B9DFA4 80240644 3C014030 */  lui       $at, 0x4030
/* B9DFA8 80240648 44812800 */  mtc1      $at, $f5
/* B9DFAC 8024064C 44802000 */  mtc1      $zero, $f4
/* B9DFB0 80240650 46000021 */  cvt.d.s   $f0, $f0
/* B9DFB4 80240654 E7A6002C */  swc1      $f6, 0x2c($sp)
/* B9DFB8 80240658 46240000 */  add.d     $f0, $f0, $f4
/* B9DFBC 8024065C 462010A0 */  cvt.s.d   $f2, $f2
/* B9DFC0 80240660 E7A20030 */  swc1      $f2, 0x30($sp)
/* B9DFC4 80240664 46200020 */  cvt.s.d   $f0, $f0
/* B9DFC8 80240668 E7A00038 */  swc1      $f0, 0x38($sp)
/* B9DFCC 8024066C AFA20010 */  sw        $v0, 0x10($sp)
/* B9DFD0 80240670 8E040080 */  lw        $a0, 0x80($s0)
/* B9DFD4 80240674 0C0372DF */  jal       npc_raycast_down_sides
/* B9DFD8 80240678 27A70034 */   addiu    $a3, $sp, 0x34
/* B9DFDC 8024067C 1040002A */  beqz      $v0, .L80240728
/* B9DFE0 80240680 00000000 */   nop
/* B9DFE4 80240684 C600001C */  lwc1      $f0, 0x1c($s0)
/* B9DFE8 80240688 C7A20038 */  lwc1      $f2, 0x38($sp)
/* B9DFEC 8024068C 46000005 */  abs.s     $f0, $f0
/* B9DFF0 80240690 46000021 */  cvt.d.s   $f0, $f0
/* B9DFF4 80240694 46340000 */  add.d     $f0, $f0, $f20
/* B9DFF8 80240698 460010A1 */  cvt.d.s   $f2, $f2
/* B9DFFC 8024069C 4620103E */  c.le.d    $f2, $f0
/* B9E000 802406A0 00000000 */  nop
/* B9E004 802406A4 45000020 */  bc1f      .L80240728
/* B9E008 802406A8 240403E8 */   addiu    $a0, $zero, 0x3e8
/* B9E00C 802406AC C7A00030 */  lwc1      $f0, 0x30($sp)
/* B9E010 802406B0 8E020000 */  lw        $v0, ($s0)
/* B9E014 802406B4 2403F7FF */  addiu     $v1, $zero, -0x801
/* B9E018 802406B8 AE00001C */  sw        $zero, 0x1c($s0)
/* B9E01C 802406BC 00431024 */  and       $v0, $v0, $v1
/* B9E020 802406C0 AE020000 */  sw        $v0, ($s0)
/* B9E024 802406C4 24020002 */  addiu     $v0, $zero, 2
/* B9E028 802406C8 E600003C */  swc1      $f0, 0x3c($s0)
/* B9E02C 802406CC 0C00A67F */  jal       rand_int
/* B9E030 802406D0 AE620070 */   sw       $v0, 0x70($s3)
/* B9E034 802406D4 3C035555 */  lui       $v1, 0x5555
/* B9E038 802406D8 34635556 */  ori       $v1, $v1, 0x5556
/* B9E03C 802406DC 00430018 */  mult      $v0, $v1
/* B9E040 802406E0 000227C3 */  sra       $a0, $v0, 0x1f
/* B9E044 802406E4 00004010 */  mfhi      $t0
/* B9E048 802406E8 01042023 */  subu      $a0, $t0, $a0
/* B9E04C 802406EC 00041840 */  sll       $v1, $a0, 1
/* B9E050 802406F0 00641821 */  addu      $v1, $v1, $a0
/* B9E054 802406F4 00431023 */  subu      $v0, $v0, $v1
/* B9E058 802406F8 24430002 */  addiu     $v1, $v0, 2
/* B9E05C 802406FC AE630074 */  sw        $v1, 0x74($s3)
/* B9E060 80240700 8E82002C */  lw        $v0, 0x2c($s4)
/* B9E064 80240704 5840000F */  blezl     $v0, .L80240744
/* B9E068 80240708 AE600070 */   sw       $zero, 0x70($s3)
/* B9E06C 8024070C 8E820004 */  lw        $v0, 4($s4)
/* B9E070 80240710 5840000C */  blezl     $v0, .L80240744
/* B9E074 80240714 AE600070 */   sw       $zero, 0x70($s3)
/* B9E078 80240718 1460000A */  bnez      $v1, .L80240744
/* B9E07C 8024071C 00000000 */   nop
/* B9E080 80240720 080901D1 */  j         .L80240744
/* B9E084 80240724 AE600070 */   sw       $zero, 0x70($s3)
.L80240728:
/* B9E088 80240728 C604003C */  lwc1      $f4, 0x3c($s0)
/* B9E08C 8024072C C600001C */  lwc1      $f0, 0x1c($s0)
/* B9E090 80240730 46002100 */  add.s     $f4, $f4, $f0
/* B9E094 80240734 C6020014 */  lwc1      $f2, 0x14($s0)
/* B9E098 80240738 46020001 */  sub.s     $f0, $f0, $f2
/* B9E09C 8024073C E604003C */  swc1      $f4, 0x3c($s0)
/* B9E0A0 80240740 E600001C */  swc1      $f0, 0x1c($s0)
.L80240744:
/* B9E0A4 80240744 8FBF0054 */  lw        $ra, 0x54($sp)
/* B9E0A8 80240748 8FB40050 */  lw        $s4, 0x50($sp)
/* B9E0AC 8024074C 8FB3004C */  lw        $s3, 0x4c($sp)
/* B9E0B0 80240750 8FB20048 */  lw        $s2, 0x48($sp)
/* B9E0B4 80240754 8FB10044 */  lw        $s1, 0x44($sp)
/* B9E0B8 80240758 8FB00040 */  lw        $s0, 0x40($sp)
/* B9E0BC 8024075C D7B40058 */  ldc1      $f20, 0x58($sp)
/* B9E0C0 80240760 03E00008 */  jr        $ra
/* B9E0C4 80240764 27BD0060 */   addiu    $sp, $sp, 0x60
