.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A10
/* 8B1A80 80241A10 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 8B1A84 80241A14 AFB3003C */  sw        $s3, 0x3c($sp)
/* 8B1A88 80241A18 0080982D */  daddu     $s3, $a0, $zero
/* 8B1A8C 80241A1C AFBF0044 */  sw        $ra, 0x44($sp)
/* 8B1A90 80241A20 AFB40040 */  sw        $s4, 0x40($sp)
/* 8B1A94 80241A24 AFB20038 */  sw        $s2, 0x38($sp)
/* 8B1A98 80241A28 AFB10034 */  sw        $s1, 0x34($sp)
/* 8B1A9C 80241A2C AFB00030 */  sw        $s0, 0x30($sp)
/* 8B1AA0 80241A30 8E710148 */  lw        $s1, 0x148($s3)
/* 8B1AA4 80241A34 00A0902D */  daddu     $s2, $a1, $zero
/* 8B1AA8 80241A38 86240008 */  lh        $a0, 8($s1)
/* 8B1AAC 80241A3C 0C00EABB */  jal       get_npc_unsafe
/* 8B1AB0 80241A40 00C0A02D */   daddu    $s4, $a2, $zero
/* 8B1AB4 80241A44 8E430008 */  lw        $v1, 8($s2)
/* 8B1AB8 80241A48 0460003B */  bltz      $v1, .L80241B38
/* 8B1ABC 80241A4C 0040802D */   daddu    $s0, $v0, $zero
/* 8B1AC0 80241A50 8E620074 */  lw        $v0, 0x74($s3)
/* 8B1AC4 80241A54 1C400037 */  bgtz      $v0, .L80241B34
/* 8B1AC8 80241A58 2442FFFF */   addiu    $v0, $v0, -1
/* 8B1ACC 80241A5C 0280202D */  daddu     $a0, $s4, $zero
/* 8B1AD0 80241A60 AE630074 */  sw        $v1, 0x74($s3)
/* 8B1AD4 80241A64 AFA00010 */  sw        $zero, 0x10($sp)
/* 8B1AD8 80241A68 8E460018 */  lw        $a2, 0x18($s2)
/* 8B1ADC 80241A6C 8E47001C */  lw        $a3, 0x1c($s2)
/* 8B1AE0 80241A70 0C01242D */  jal       func_800490B4
/* 8B1AE4 80241A74 0220282D */   daddu    $a1, $s1, $zero
/* 8B1AE8 80241A78 1040002C */  beqz      $v0, .L80241B2C
/* 8B1AEC 80241A7C 0000202D */   daddu    $a0, $zero, $zero
/* 8B1AF0 80241A80 0200282D */  daddu     $a1, $s0, $zero
/* 8B1AF4 80241A84 0000302D */  daddu     $a2, $zero, $zero
/* 8B1AF8 80241A88 860300A8 */  lh        $v1, 0xa8($s0)
/* 8B1AFC 80241A8C 3C013F80 */  lui       $at, 0x3f80
/* 8B1B00 80241A90 44810000 */  mtc1      $at, $f0
/* 8B1B04 80241A94 3C014000 */  lui       $at, 0x4000
/* 8B1B08 80241A98 44811000 */  mtc1      $at, $f2
/* 8B1B0C 80241A9C 3C01C1A0 */  lui       $at, 0xc1a0
/* 8B1B10 80241AA0 44812000 */  mtc1      $at, $f4
/* 8B1B14 80241AA4 2402000F */  addiu     $v0, $zero, 0xf
/* 8B1B18 80241AA8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 8B1B1C 80241AAC 44833000 */  mtc1      $v1, $f6
/* 8B1B20 80241AB0 00000000 */  nop       
/* 8B1B24 80241AB4 468031A0 */  cvt.s.w   $f6, $f6
/* 8B1B28 80241AB8 44073000 */  mfc1      $a3, $f6
/* 8B1B2C 80241ABC 27A20028 */  addiu     $v0, $sp, 0x28
/* 8B1B30 80241AC0 AFA20020 */  sw        $v0, 0x20($sp)
/* 8B1B34 80241AC4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8B1B38 80241AC8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 8B1B3C 80241ACC 0C01BFA4 */  jal       fx_emote
/* 8B1B40 80241AD0 E7A40018 */   swc1     $f4, 0x18($sp)
/* 8B1B44 80241AD4 0200202D */  daddu     $a0, $s0, $zero
/* 8B1B48 80241AD8 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 8B1B4C 80241ADC 0C012530 */  jal       func_800494C0
/* 8B1B50 80241AE0 3C060020 */   lui      $a2, 0x20
/* 8B1B54 80241AE4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8B1B58 80241AE8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8B1B5C 80241AEC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8B1B60 80241AF0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 8B1B64 80241AF4 8C460028 */  lw        $a2, 0x28($v0)
/* 8B1B68 80241AF8 0C00A720 */  jal       atan2
/* 8B1B6C 80241AFC 8C470030 */   lw       $a3, 0x30($v0)
/* 8B1B70 80241B00 E600000C */  swc1      $f0, 0xc($s0)
/* 8B1B74 80241B04 8E220018 */  lw        $v0, 0x18($s1)
/* 8B1B78 80241B08 9442002A */  lhu       $v0, 0x2a($v0)
/* 8B1B7C 80241B0C 30420001 */  andi      $v0, $v0, 1
/* 8B1B80 80241B10 10400003 */  beqz      $v0, .L80241B20
/* 8B1B84 80241B14 2402000A */   addiu    $v0, $zero, 0xa
/* 8B1B88 80241B18 080906FE */  j         .L80241BF8
/* 8B1B8C 80241B1C AE620070 */   sw       $v0, 0x70($s3)
.L80241B20:
/* 8B1B90 80241B20 2402000C */  addiu     $v0, $zero, 0xc
/* 8B1B94 80241B24 080906FE */  j         .L80241BF8
/* 8B1B98 80241B28 AE620070 */   sw       $v0, 0x70($s3)
.L80241B2C:
/* 8B1B9C 80241B2C 8E620074 */  lw        $v0, 0x74($s3)
/* 8B1BA0 80241B30 2442FFFF */  addiu     $v0, $v0, -1
.L80241B34:
/* 8B1BA4 80241B34 AE620074 */  sw        $v0, 0x74($s3)
.L80241B38:
/* 8B1BA8 80241B38 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8B1BAC 80241B3C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8B1BB0 80241B40 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 8B1BB4 80241B44 C4460000 */  lwc1      $f6, ($v0)
/* 8B1BB8 80241B48 468031A0 */  cvt.s.w   $f6, $f6
/* 8B1BBC 80241B4C 44063000 */  mfc1      $a2, $f6
/* 8B1BC0 80241B50 C4460008 */  lwc1      $f6, 8($v0)
/* 8B1BC4 80241B54 468031A0 */  cvt.s.w   $f6, $f6
/* 8B1BC8 80241B58 44073000 */  mfc1      $a3, $f6
/* 8B1BCC 80241B5C 0C00A7B5 */  jal       dist2D
/* 8B1BD0 80241B60 00000000 */   nop      
/* 8B1BD4 80241B64 C6020018 */  lwc1      $f2, 0x18($s0)
/* 8B1BD8 80241B68 4602003C */  c.lt.s    $f0, $f2
/* 8B1BDC 80241B6C 00000000 */  nop       
/* 8B1BE0 80241B70 4500000E */  bc1f      .L80241BAC
/* 8B1BE4 80241B74 00000000 */   nop      
/* 8B1BE8 80241B78 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8B1BEC 80241B7C C4400000 */  lwc1      $f0, ($v0)
/* 8B1BF0 80241B80 46800020 */  cvt.s.w   $f0, $f0
/* 8B1BF4 80241B84 E6000038 */  swc1      $f0, 0x38($s0)
/* 8B1BF8 80241B88 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8B1BFC 80241B8C C4400008 */  lwc1      $f0, 8($v0)
/* 8B1C00 80241B90 46800020 */  cvt.s.w   $f0, $f0
/* 8B1C04 80241B94 E6000040 */  swc1      $f0, 0x40($s0)
/* 8B1C08 80241B98 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8B1C0C 80241B9C C440000C */  lwc1      $f0, 0xc($v0)
/* 8B1C10 80241BA0 46800020 */  cvt.s.w   $f0, $f0
/* 8B1C14 80241BA4 E600000C */  swc1      $f0, 0xc($s0)
/* 8B1C18 80241BA8 AE600070 */  sw        $zero, 0x70($s3)
.L80241BAC:
/* 8B1C1C 80241BAC 8602008C */  lh        $v0, 0x8c($s0)
/* 8B1C20 80241BB0 14400011 */  bnez      $v0, .L80241BF8
/* 8B1C24 80241BB4 00000000 */   nop      
/* 8B1C28 80241BB8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 8B1C2C 80241BBC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8B1C30 80241BC0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 8B1C34 80241BC4 C4460000 */  lwc1      $f6, ($v0)
/* 8B1C38 80241BC8 468031A0 */  cvt.s.w   $f6, $f6
/* 8B1C3C 80241BCC 44063000 */  mfc1      $a2, $f6
/* 8B1C40 80241BD0 C4460008 */  lwc1      $f6, 8($v0)
/* 8B1C44 80241BD4 468031A0 */  cvt.s.w   $f6, $f6
/* 8B1C48 80241BD8 44073000 */  mfc1      $a3, $f6
/* 8B1C4C 80241BDC 0C00A720 */  jal       atan2
/* 8B1C50 80241BE0 00000000 */   nop      
/* 8B1C54 80241BE4 8E050018 */  lw        $a1, 0x18($s0)
/* 8B1C58 80241BE8 44060000 */  mfc1      $a2, $f0
/* 8B1C5C 80241BEC 0200202D */  daddu     $a0, $s0, $zero
/* 8B1C60 80241BF0 0C00EA95 */  jal       npc_move_heading
/* 8B1C64 80241BF4 AC86000C */   sw       $a2, 0xc($a0)
.L80241BF8:
/* 8B1C68 80241BF8 8FBF0044 */  lw        $ra, 0x44($sp)
/* 8B1C6C 80241BFC 8FB40040 */  lw        $s4, 0x40($sp)
/* 8B1C70 80241C00 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8B1C74 80241C04 8FB20038 */  lw        $s2, 0x38($sp)
/* 8B1C78 80241C08 8FB10034 */  lw        $s1, 0x34($sp)
/* 8B1C7C 80241C0C 8FB00030 */  lw        $s0, 0x30($sp)
/* 8B1C80 80241C10 03E00008 */  jr        $ra
/* 8B1C84 80241C14 27BD0048 */   addiu    $sp, $sp, 0x48
