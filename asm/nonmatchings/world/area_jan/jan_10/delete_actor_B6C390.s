.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel delete_actor_B6CF4C
/* B6CF4C 80240BBC 27BDFF90 */  addiu     $sp, $sp, -0x70
/* B6CF50 80240BC0 AFB40050 */  sw        $s4, 0x50($sp)
/* B6CF54 80240BC4 0080A02D */  daddu     $s4, $a0, $zero
/* B6CF58 80240BC8 AFBF0060 */  sw        $ra, 0x60($sp)
/* B6CF5C 80240BCC AFB7005C */  sw        $s7, 0x5c($sp)
/* B6CF60 80240BD0 AFB60058 */  sw        $s6, 0x58($sp)
/* B6CF64 80240BD4 AFB50054 */  sw        $s5, 0x54($sp)
/* B6CF68 80240BD8 AFB3004C */  sw        $s3, 0x4c($sp)
/* B6CF6C 80240BDC AFB20048 */  sw        $s2, 0x48($sp)
/* B6CF70 80240BE0 AFB10044 */  sw        $s1, 0x44($sp)
/* B6CF74 80240BE4 AFB00040 */  sw        $s0, 0x40($sp)
/* B6CF78 80240BE8 F7B40068 */  sdc1      $f20, 0x68($sp)
/* B6CF7C 80240BEC 8E950148 */  lw        $s5, 0x148($s4)
/* B6CF80 80240BF0 00A0B02D */  daddu     $s6, $a1, $zero
/* B6CF84 80240BF4 86A40008 */  lh        $a0, 8($s5)
/* B6CF88 80240BF8 0C00EABB */  jal       get_npc_unsafe
/* B6CF8C 80240BFC 00C0B82D */   daddu    $s7, $a2, $zero
/* B6CF90 80240C00 0040982D */  daddu     $s3, $v0, $zero
/* B6CF94 80240C04 C6600018 */  lwc1      $f0, 0x18($s3)
/* B6CF98 80240C08 44801000 */  mtc1      $zero, $f2
/* B6CF9C 80240C0C 44801800 */  mtc1      $zero, $f3
/* B6CFA0 80240C10 46000021 */  cvt.d.s   $f0, $f0
/* B6CFA4 80240C14 4620103C */  c.lt.d    $f2, $f0
/* B6CFA8 80240C18 00000000 */  nop       
/* B6CFAC 80240C1C 45000021 */  bc1f      .L80240CA4
/* B6CFB0 80240C20 27A50028 */   addiu    $a1, $sp, 0x28
/* B6CFB4 80240C24 C6600038 */  lwc1      $f0, 0x38($s3)
/* B6CFB8 80240C28 C662003C */  lwc1      $f2, 0x3c($s3)
/* B6CFBC 80240C2C C6640040 */  lwc1      $f4, 0x40($s3)
/* B6CFC0 80240C30 C6660018 */  lwc1      $f6, 0x18($s3)
/* B6CFC4 80240C34 E7A00028 */  swc1      $f0, 0x28($sp)
/* B6CFC8 80240C38 E7A2002C */  swc1      $f2, 0x2c($sp)
/* B6CFCC 80240C3C E7A40030 */  swc1      $f4, 0x30($sp)
/* B6CFD0 80240C40 E7A60010 */  swc1      $f6, 0x10($sp)
/* B6CFD4 80240C44 C660000C */  lwc1      $f0, 0xc($s3)
/* B6CFD8 80240C48 E7A00014 */  swc1      $f0, 0x14($sp)
/* B6CFDC 80240C4C 866200A8 */  lh        $v0, 0xa8($s3)
/* B6CFE0 80240C50 44820000 */  mtc1      $v0, $f0
/* B6CFE4 80240C54 00000000 */  nop       
/* B6CFE8 80240C58 46800020 */  cvt.s.w   $f0, $f0
/* B6CFEC 80240C5C E7A00018 */  swc1      $f0, 0x18($sp)
/* B6CFF0 80240C60 866200A6 */  lh        $v0, 0xa6($s3)
/* B6CFF4 80240C64 27A6002C */  addiu     $a2, $sp, 0x2c
/* B6CFF8 80240C68 44820000 */  mtc1      $v0, $f0
/* B6CFFC 80240C6C 00000000 */  nop       
/* B6D000 80240C70 46800020 */  cvt.s.w   $f0, $f0
/* B6D004 80240C74 E7A0001C */  swc1      $f0, 0x1c($sp)
/* B6D008 80240C78 8E640080 */  lw        $a0, 0x80($s3)
/* B6D00C 80240C7C 0C037711 */  jal       func_800DDC44
/* B6D010 80240C80 27A70030 */   addiu    $a3, $sp, 0x30
/* B6D014 80240C84 10400003 */  beqz      $v0, .L80240C94
/* B6D018 80240C88 00000000 */   nop      
/* B6D01C 80240C8C 08090329 */  j         .L80240CA4
/* B6D020 80240C90 AE600018 */   sw       $zero, 0x18($s3)
.L80240C94:
/* B6D024 80240C94 8E650018 */  lw        $a1, 0x18($s3)
/* B6D028 80240C98 8E66000C */  lw        $a2, 0xc($s3)
/* B6D02C 80240C9C 0C00EA95 */  jal       npc_move_heading
/* B6D030 80240CA0 0260202D */   daddu    $a0, $s3, $zero
.L80240CA4:
/* B6D034 80240CA4 C660001C */  lwc1      $f0, 0x1c($s3)
/* B6D038 80240CA8 44801000 */  mtc1      $zero, $f2
/* B6D03C 80240CAC 44801800 */  mtc1      $zero, $f3
/* B6D040 80240CB0 46000021 */  cvt.d.s   $f0, $f0
/* B6D044 80240CB4 4622003C */  c.lt.d    $f0, $f2
/* B6D048 80240CB8 00000000 */  nop       
/* B6D04C 80240CBC 4500006C */  bc1f      .L80240E70
/* B6D050 80240CC0 27B00028 */   addiu    $s0, $sp, 0x28
/* B6D054 80240CC4 0200282D */  daddu     $a1, $s0, $zero
/* B6D058 80240CC8 27A60034 */  addiu     $a2, $sp, 0x34
/* B6D05C 80240CCC 27B20038 */  addiu     $s2, $sp, 0x38
/* B6D060 80240CD0 C6600038 */  lwc1      $f0, 0x38($s3)
/* B6D064 80240CD4 3C0142C8 */  lui       $at, 0x42c8
/* B6D068 80240CD8 44811000 */  mtc1      $at, $f2
/* B6D06C 80240CDC C6640040 */  lwc1      $f4, 0x40($s3)
/* B6D070 80240CE0 3C01447A */  lui       $at, 0x447a
/* B6D074 80240CE4 44813000 */  mtc1      $at, $f6
/* B6D078 80240CE8 27B10030 */  addiu     $s1, $sp, 0x30
/* B6D07C 80240CEC E7A00028 */  swc1      $f0, 0x28($sp)
/* B6D080 80240CF0 E7A20034 */  swc1      $f2, 0x34($sp)
/* B6D084 80240CF4 E7A40030 */  swc1      $f4, 0x30($sp)
/* B6D088 80240CF8 E7A60038 */  swc1      $f6, 0x38($sp)
/* B6D08C 80240CFC AFB20010 */  sw        $s2, 0x10($sp)
/* B6D090 80240D00 8E640080 */  lw        $a0, 0x80($s3)
/* B6D094 80240D04 0C0372DF */  jal       func_800DCB7C
/* B6D098 80240D08 0220382D */   daddu    $a3, $s1, $zero
/* B6D09C 80240D0C 0200282D */  daddu     $a1, $s0, $zero
/* B6D0A0 80240D10 27A6002C */  addiu     $a2, $sp, 0x2c
/* B6D0A4 80240D14 C662003C */  lwc1      $f2, 0x3c($s3)
/* B6D0A8 80240D18 C6660038 */  lwc1      $f6, 0x38($s3)
/* B6D0AC 80240D1C 3C01402A */  lui       $at, 0x402a
/* B6D0B0 80240D20 4481A800 */  mtc1      $at, $f21
/* B6D0B4 80240D24 4480A000 */  mtc1      $zero, $f20
/* B6D0B8 80240D28 460010A1 */  cvt.d.s   $f2, $f2
/* B6D0BC 80240D2C 46341080 */  add.d     $f2, $f2, $f20
/* B6D0C0 80240D30 C660001C */  lwc1      $f0, 0x1c($s3)
/* B6D0C4 80240D34 C6640040 */  lwc1      $f4, 0x40($s3)
/* B6D0C8 80240D38 46000005 */  abs.s     $f0, $f0
/* B6D0CC 80240D3C E7A40030 */  swc1      $f4, 0x30($sp)
/* B6D0D0 80240D40 3C014030 */  lui       $at, 0x4030
/* B6D0D4 80240D44 44812800 */  mtc1      $at, $f5
/* B6D0D8 80240D48 44802000 */  mtc1      $zero, $f4
/* B6D0DC 80240D4C 46000021 */  cvt.d.s   $f0, $f0
/* B6D0E0 80240D50 E7A60028 */  swc1      $f6, 0x28($sp)
/* B6D0E4 80240D54 46240000 */  add.d     $f0, $f0, $f4
/* B6D0E8 80240D58 462010A0 */  cvt.s.d   $f2, $f2
/* B6D0EC 80240D5C E7A2002C */  swc1      $f2, 0x2c($sp)
/* B6D0F0 80240D60 46200020 */  cvt.s.d   $f0, $f0
/* B6D0F4 80240D64 E7A00038 */  swc1      $f0, 0x38($sp)
/* B6D0F8 80240D68 AFB20010 */  sw        $s2, 0x10($sp)
/* B6D0FC 80240D6C 8E640080 */  lw        $a0, 0x80($s3)
/* B6D100 80240D70 0C0372DF */  jal       func_800DCB7C
/* B6D104 80240D74 0220382D */   daddu    $a3, $s1, $zero
/* B6D108 80240D78 1040003D */  beqz      $v0, .L80240E70
/* B6D10C 80240D7C 00000000 */   nop      
/* B6D110 80240D80 C660001C */  lwc1      $f0, 0x1c($s3)
/* B6D114 80240D84 C7A20038 */  lwc1      $f2, 0x38($sp)
/* B6D118 80240D88 46000005 */  abs.s     $f0, $f0
/* B6D11C 80240D8C 46000021 */  cvt.d.s   $f0, $f0
/* B6D120 80240D90 46340000 */  add.d     $f0, $f0, $f20
/* B6D124 80240D94 460010A1 */  cvt.d.s   $f2, $f2
/* B6D128 80240D98 4620103E */  c.le.d    $f2, $f0
/* B6D12C 80240D9C 00000000 */  nop       
/* B6D130 80240DA0 45000033 */  bc1f      .L80240E70
/* B6D134 80240DA4 2403F7FF */   addiu    $v1, $zero, -0x801
/* B6D138 80240DA8 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* B6D13C 80240DAC 8E620000 */  lw        $v0, ($s3)
/* B6D140 80240DB0 AE60001C */  sw        $zero, 0x1c($s3)
/* B6D144 80240DB4 00431024 */  and       $v0, $v0, $v1
/* B6D148 80240DB8 E660003C */  swc1      $f0, 0x3c($s3)
/* B6D14C 80240DBC AE620000 */  sw        $v0, ($s3)
/* B6D150 80240DC0 AFA00010 */  sw        $zero, 0x10($sp)
/* B6D154 80240DC4 AFA00014 */  sw        $zero, 0x14($sp)
/* B6D158 80240DC8 8E650038 */  lw        $a1, 0x38($s3)
/* B6D15C 80240DCC 8E66003C */  lw        $a2, 0x3c($s3)
/* B6D160 80240DD0 8E670040 */  lw        $a3, 0x40($s3)
/* B6D164 80240DD4 0C01BECC */  jal       fx_walk_normal
/* B6D168 80240DD8 24040002 */   addiu    $a0, $zero, 2
/* B6D16C 80240DDC 02E0202D */  daddu     $a0, $s7, $zero
/* B6D170 80240DE0 2402000C */  addiu     $v0, $zero, 0xc
/* B6D174 80240DE4 AE820070 */  sw        $v0, 0x70($s4)
/* B6D178 80240DE8 24020001 */  addiu     $v0, $zero, 1
/* B6D17C 80240DEC AFA20010 */  sw        $v0, 0x10($sp)
/* B6D180 80240DF0 8EC60024 */  lw        $a2, 0x24($s6)
/* B6D184 80240DF4 8EC70028 */  lw        $a3, 0x28($s6)
/* B6D188 80240DF8 0C01242D */  jal       func_800490B4
/* B6D18C 80240DFC 02A0282D */   daddu    $a1, $s5, $zero
/* B6D190 80240E00 14400022 */  bnez      $v0, .L80240E8C
/* B6D194 80240E04 24040002 */   addiu    $a0, $zero, 2
/* B6D198 80240E08 0260282D */  daddu     $a1, $s3, $zero
/* B6D19C 80240E0C 0000302D */  daddu     $a2, $zero, $zero
/* B6D1A0 80240E10 866300A8 */  lh        $v1, 0xa8($s3)
/* B6D1A4 80240E14 3C013F80 */  lui       $at, 0x3f80
/* B6D1A8 80240E18 44810000 */  mtc1      $at, $f0
/* B6D1AC 80240E1C 3C014000 */  lui       $at, 0x4000
/* B6D1B0 80240E20 44811000 */  mtc1      $at, $f2
/* B6D1B4 80240E24 3C01C1A0 */  lui       $at, 0xc1a0
/* B6D1B8 80240E28 44812000 */  mtc1      $at, $f4
/* B6D1BC 80240E2C 2402000F */  addiu     $v0, $zero, 0xf
/* B6D1C0 80240E30 AFA2001C */  sw        $v0, 0x1c($sp)
/* B6D1C4 80240E34 44834000 */  mtc1      $v1, $f8
/* B6D1C8 80240E38 00000000 */  nop       
/* B6D1CC 80240E3C 46804220 */  cvt.s.w   $f8, $f8
/* B6D1D0 80240E40 44074000 */  mfc1      $a3, $f8
/* B6D1D4 80240E44 27A2003C */  addiu     $v0, $sp, 0x3c
/* B6D1D8 80240E48 AFA20020 */  sw        $v0, 0x20($sp)
/* B6D1DC 80240E4C E7A00010 */  swc1      $f0, 0x10($sp)
/* B6D1E0 80240E50 E7A20014 */  swc1      $f2, 0x14($sp)
/* B6D1E4 80240E54 0C01BFA4 */  jal       fx_emote
/* B6D1E8 80240E58 E7A40018 */   swc1     $f4, 0x18($sp)
/* B6D1EC 80240E5C 24020019 */  addiu     $v0, $zero, 0x19
/* B6D1F0 80240E60 A662008E */  sh        $v0, 0x8e($s3)
/* B6D1F4 80240E64 2402000E */  addiu     $v0, $zero, 0xe
/* B6D1F8 80240E68 080903A3 */  j         .L80240E8C
/* B6D1FC 80240E6C AE820070 */   sw       $v0, 0x70($s4)
.L80240E70:
/* B6D200 80240E70 C664003C */  lwc1      $f4, 0x3c($s3)
/* B6D204 80240E74 C660001C */  lwc1      $f0, 0x1c($s3)
/* B6D208 80240E78 46002100 */  add.s     $f4, $f4, $f0
/* B6D20C 80240E7C C6620014 */  lwc1      $f2, 0x14($s3)
/* B6D210 80240E80 46020001 */  sub.s     $f0, $f0, $f2
/* B6D214 80240E84 E664003C */  swc1      $f4, 0x3c($s3)
/* B6D218 80240E88 E660001C */  swc1      $f0, 0x1c($s3)
.L80240E8C:
/* B6D21C 80240E8C 8FBF0060 */  lw        $ra, 0x60($sp)
/* B6D220 80240E90 8FB7005C */  lw        $s7, 0x5c($sp)
/* B6D224 80240E94 8FB60058 */  lw        $s6, 0x58($sp)
/* B6D228 80240E98 8FB50054 */  lw        $s5, 0x54($sp)
/* B6D22C 80240E9C 8FB40050 */  lw        $s4, 0x50($sp)
/* B6D230 80240EA0 8FB3004C */  lw        $s3, 0x4c($sp)
/* B6D234 80240EA4 8FB20048 */  lw        $s2, 0x48($sp)
/* B6D238 80240EA8 8FB10044 */  lw        $s1, 0x44($sp)
/* B6D23C 80240EAC 8FB00040 */  lw        $s0, 0x40($sp)
/* B6D240 80240EB0 D7B40068 */  ldc1      $f20, 0x68($sp)
/* B6D244 80240EB4 03E00008 */  jr        $ra
/* B6D248 80240EB8 27BD0070 */   addiu    $sp, $sp, 0x70
