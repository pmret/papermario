.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A0C_9A19EC
/* 9A19EC 80240A0C 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 9A19F0 80240A10 AFB20038 */  sw        $s2, 0x38($sp)
/* 9A19F4 80240A14 0080902D */  daddu     $s2, $a0, $zero
/* 9A19F8 80240A18 AFBF0044 */  sw        $ra, 0x44($sp)
/* 9A19FC 80240A1C AFB40040 */  sw        $s4, 0x40($sp)
/* 9A1A00 80240A20 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9A1A04 80240A24 AFB10034 */  sw        $s1, 0x34($sp)
/* 9A1A08 80240A28 AFB00030 */  sw        $s0, 0x30($sp)
/* 9A1A0C 80240A2C F7B60050 */  sdc1      $f22, 0x50($sp)
/* 9A1A10 80240A30 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 9A1A14 80240A34 8E510148 */  lw        $s1, 0x148($s2)
/* 9A1A18 80240A38 00A0982D */  daddu     $s3, $a1, $zero
/* 9A1A1C 80240A3C 86240008 */  lh        $a0, 8($s1)
/* 9A1A20 80240A40 0C00EABB */  jal       get_npc_unsafe
/* 9A1A24 80240A44 00C0A02D */   daddu    $s4, $a2, $zero
/* 9A1A28 80240A48 8E630014 */  lw        $v1, 0x14($s3)
/* 9A1A2C 80240A4C 04600030 */  bltz      $v1, .L80240B10
/* 9A1A30 80240A50 0040802D */   daddu    $s0, $v0, $zero
/* 9A1A34 80240A54 8E420074 */  lw        $v0, 0x74($s2)
/* 9A1A38 80240A58 1C40002C */  bgtz      $v0, .L80240B0C
/* 9A1A3C 80240A5C 2442FFFF */   addiu    $v0, $v0, -1
/* 9A1A40 80240A60 0280202D */  daddu     $a0, $s4, $zero
/* 9A1A44 80240A64 AE430074 */  sw        $v1, 0x74($s2)
/* 9A1A48 80240A68 AFA00010 */  sw        $zero, 0x10($sp)
/* 9A1A4C 80240A6C 8E66000C */  lw        $a2, 0xc($s3)
/* 9A1A50 80240A70 8E670010 */  lw        $a3, 0x10($s3)
/* 9A1A54 80240A74 0C01242D */  jal       func_800490B4
/* 9A1A58 80240A78 0220282D */   daddu    $a1, $s1, $zero
/* 9A1A5C 80240A7C 10400021 */  beqz      $v0, .L80240B04
/* 9A1A60 80240A80 0000202D */   daddu    $a0, $zero, $zero
/* 9A1A64 80240A84 0200282D */  daddu     $a1, $s0, $zero
/* 9A1A68 80240A88 0000302D */  daddu     $a2, $zero, $zero
/* 9A1A6C 80240A8C 860300A8 */  lh        $v1, 0xa8($s0)
/* 9A1A70 80240A90 3C013F80 */  lui       $at, 0x3f80
/* 9A1A74 80240A94 44810000 */  mtc1      $at, $f0
/* 9A1A78 80240A98 3C014000 */  lui       $at, 0x4000
/* 9A1A7C 80240A9C 44811000 */  mtc1      $at, $f2
/* 9A1A80 80240AA0 3C01C1A0 */  lui       $at, 0xc1a0
/* 9A1A84 80240AA4 44812000 */  mtc1      $at, $f4
/* 9A1A88 80240AA8 2402000F */  addiu     $v0, $zero, 0xf
/* 9A1A8C 80240AAC AFA2001C */  sw        $v0, 0x1c($sp)
/* 9A1A90 80240AB0 44833000 */  mtc1      $v1, $f6
/* 9A1A94 80240AB4 00000000 */  nop
/* 9A1A98 80240AB8 468031A0 */  cvt.s.w   $f6, $f6
/* 9A1A9C 80240ABC 44073000 */  mfc1      $a3, $f6
/* 9A1AA0 80240AC0 27A20028 */  addiu     $v0, $sp, 0x28
/* 9A1AA4 80240AC4 AFA20020 */  sw        $v0, 0x20($sp)
/* 9A1AA8 80240AC8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9A1AAC 80240ACC E7A20014 */  swc1      $f2, 0x14($sp)
/* 9A1AB0 80240AD0 0C01BFA4 */  jal       fx_emote
/* 9A1AB4 80240AD4 E7A40018 */   swc1     $f4, 0x18($sp)
/* 9A1AB8 80240AD8 0200202D */  daddu     $a0, $s0, $zero
/* 9A1ABC 80240ADC 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 9A1AC0 80240AE0 0C012530 */  jal       func_800494C0
/* 9A1AC4 80240AE4 3C060020 */   lui      $a2, 0x20
/* 9A1AC8 80240AE8 8E220018 */  lw        $v0, 0x18($s1)
/* 9A1ACC 80240AEC 9442002A */  lhu       $v0, 0x2a($v0)
/* 9A1AD0 80240AF0 30420001 */  andi      $v0, $v0, 1
/* 9A1AD4 80240AF4 14400064 */  bnez      $v0, .L80240C88
/* 9A1AD8 80240AF8 2402000A */   addiu    $v0, $zero, 0xa
/* 9A1ADC 80240AFC 08090322 */  j         .L80240C88
/* 9A1AE0 80240B00 2402000C */   addiu    $v0, $zero, 0xc
.L80240B04:
/* 9A1AE4 80240B04 8E420074 */  lw        $v0, 0x74($s2)
/* 9A1AE8 80240B08 2442FFFF */  addiu     $v0, $v0, -1
.L80240B0C:
/* 9A1AEC 80240B0C AE420074 */  sw        $v0, 0x74($s2)
.L80240B10:
/* 9A1AF0 80240B10 8602008C */  lh        $v0, 0x8c($s0)
/* 9A1AF4 80240B14 1440005D */  bnez      $v0, .L80240C8C
/* 9A1AF8 80240B18 00000000 */   nop
/* 9A1AFC 80240B1C C6000018 */  lwc1      $f0, 0x18($s0)
/* 9A1B00 80240B20 3C014010 */  lui       $at, 0x4010
/* 9A1B04 80240B24 44811800 */  mtc1      $at, $f3
/* 9A1B08 80240B28 44801000 */  mtc1      $zero, $f2
/* 9A1B0C 80240B2C 46000021 */  cvt.d.s   $f0, $f0
/* 9A1B10 80240B30 4622003C */  c.lt.d    $f0, $f2
/* 9A1B14 80240B34 00000000 */  nop
/* 9A1B18 80240B38 45000003 */  bc1f      .L80240B48
/* 9A1B1C 80240B3C 0200202D */   daddu    $a0, $s0, $zero
/* 9A1B20 80240B40 080902D3 */  j         .L80240B4C
/* 9A1B24 80240B44 0000282D */   daddu    $a1, $zero, $zero
.L80240B48:
/* 9A1B28 80240B48 24050001 */  addiu     $a1, $zero, 1
.L80240B4C:
/* 9A1B2C 80240B4C 0C00F598 */  jal       func_8003D660
/* 9A1B30 80240B50 00000000 */   nop
/* 9A1B34 80240B54 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9A1B38 80240B58 8E430078 */  lw        $v1, 0x78($s2)
/* 9A1B3C 80240B5C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9A1B40 80240B60 00031040 */  sll       $v0, $v1, 1
/* 9A1B44 80240B64 00431021 */  addu      $v0, $v0, $v1
/* 9A1B48 80240B68 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A1B4C 80240B6C 00021080 */  sll       $v0, $v0, 2
/* 9A1B50 80240B70 00431021 */  addu      $v0, $v0, $v1
/* 9A1B54 80240B74 C4560004 */  lwc1      $f22, 4($v0)
/* 9A1B58 80240B78 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9A1B5C 80240B7C C454000C */  lwc1      $f20, 0xc($v0)
/* 9A1B60 80240B80 4680A520 */  cvt.s.w   $f20, $f20
/* 9A1B64 80240B84 4406B000 */  mfc1      $a2, $f22
/* 9A1B68 80240B88 4407A000 */  mfc1      $a3, $f20
/* 9A1B6C 80240B8C 0C00A720 */  jal       atan2
/* 9A1B70 80240B90 00000000 */   nop
/* 9A1B74 80240B94 8E050018 */  lw        $a1, 0x18($s0)
/* 9A1B78 80240B98 44060000 */  mfc1      $a2, $f0
/* 9A1B7C 80240B9C 0200202D */  daddu     $a0, $s0, $zero
/* 9A1B80 80240BA0 0C00EA95 */  jal       npc_move_heading
/* 9A1B84 80240BA4 AE06000C */   sw       $a2, 0xc($s0)
/* 9A1B88 80240BA8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9A1B8C 80240BAC C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9A1B90 80240BB0 4406B000 */  mfc1      $a2, $f22
/* 9A1B94 80240BB4 4407A000 */  mfc1      $a3, $f20
/* 9A1B98 80240BB8 0C00A7B5 */  jal       dist2D
/* 9A1B9C 80240BBC 00000000 */   nop
/* 9A1BA0 80240BC0 C6020018 */  lwc1      $f2, 0x18($s0)
/* 9A1BA4 80240BC4 4602003E */  c.le.s    $f0, $f2
/* 9A1BA8 80240BC8 00000000 */  nop
/* 9A1BAC 80240BCC 4500002F */  bc1f      .L80240C8C
/* 9A1BB0 80240BD0 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 9A1BB4 80240BD4 24020002 */  addiu     $v0, $zero, 2
/* 9A1BB8 80240BD8 0C00A67F */  jal       rand_int
/* 9A1BBC 80240BDC AE420070 */   sw       $v0, 0x70($s2)
/* 9A1BC0 80240BE0 3C035555 */  lui       $v1, 0x5555
/* 9A1BC4 80240BE4 34635556 */  ori       $v1, $v1, 0x5556
/* 9A1BC8 80240BE8 00430018 */  mult      $v0, $v1
/* 9A1BCC 80240BEC 000227C3 */  sra       $a0, $v0, 0x1f
/* 9A1BD0 80240BF0 00004010 */  mfhi      $t0
/* 9A1BD4 80240BF4 01042023 */  subu      $a0, $t0, $a0
/* 9A1BD8 80240BF8 00041840 */  sll       $v1, $a0, 1
/* 9A1BDC 80240BFC 00641821 */  addu      $v1, $v1, $a0
/* 9A1BE0 80240C00 00431023 */  subu      $v0, $v0, $v1
/* 9A1BE4 80240C04 24430002 */  addiu     $v1, $v0, 2
/* 9A1BE8 80240C08 AE430074 */  sw        $v1, 0x74($s2)
/* 9A1BEC 80240C0C 8E62002C */  lw        $v0, 0x2c($s3)
/* 9A1BF0 80240C10 18400009 */  blez      $v0, .L80240C38
/* 9A1BF4 80240C14 24020004 */   addiu    $v0, $zero, 4
/* 9A1BF8 80240C18 8E620004 */  lw        $v0, 4($s3)
/* 9A1BFC 80240C1C 18400006 */  blez      $v0, .L80240C38
/* 9A1C00 80240C20 24020004 */   addiu    $v0, $zero, 4
/* 9A1C04 80240C24 8E620008 */  lw        $v0, 8($s3)
/* 9A1C08 80240C28 18400003 */  blez      $v0, .L80240C38
/* 9A1C0C 80240C2C 24020004 */   addiu    $v0, $zero, 4
/* 9A1C10 80240C30 14600002 */  bnez      $v1, .L80240C3C
/* 9A1C14 80240C34 00000000 */   nop
.L80240C38:
/* 9A1C18 80240C38 AE420070 */  sw        $v0, 0x70($s2)
.L80240C3C:
/* 9A1C1C 80240C3C 0C00A67F */  jal       rand_int
/* 9A1C20 80240C40 24042710 */   addiu    $a0, $zero, 0x2710
/* 9A1C24 80240C44 3C0351EB */  lui       $v1, 0x51eb
/* 9A1C28 80240C48 3463851F */  ori       $v1, $v1, 0x851f
/* 9A1C2C 80240C4C 00430018 */  mult      $v0, $v1
/* 9A1C30 80240C50 00021FC3 */  sra       $v1, $v0, 0x1f
/* 9A1C34 80240C54 00004010 */  mfhi      $t0
/* 9A1C38 80240C58 00082143 */  sra       $a0, $t0, 5
/* 9A1C3C 80240C5C 00832023 */  subu      $a0, $a0, $v1
/* 9A1C40 80240C60 00041840 */  sll       $v1, $a0, 1
/* 9A1C44 80240C64 00641821 */  addu      $v1, $v1, $a0
/* 9A1C48 80240C68 000318C0 */  sll       $v1, $v1, 3
/* 9A1C4C 80240C6C 00641821 */  addu      $v1, $v1, $a0
/* 9A1C50 80240C70 00031880 */  sll       $v1, $v1, 2
/* 9A1C54 80240C74 8E640004 */  lw        $a0, 4($s3)
/* 9A1C58 80240C78 00431023 */  subu      $v0, $v0, $v1
/* 9A1C5C 80240C7C 0044102A */  slt       $v0, $v0, $a0
/* 9A1C60 80240C80 10400002 */  beqz      $v0, .L80240C8C
/* 9A1C64 80240C84 24020004 */   addiu    $v0, $zero, 4
.L80240C88:
/* 9A1C68 80240C88 AE420070 */  sw        $v0, 0x70($s2)
.L80240C8C:
/* 9A1C6C 80240C8C 8FBF0044 */  lw        $ra, 0x44($sp)
/* 9A1C70 80240C90 8FB40040 */  lw        $s4, 0x40($sp)
/* 9A1C74 80240C94 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9A1C78 80240C98 8FB20038 */  lw        $s2, 0x38($sp)
/* 9A1C7C 80240C9C 8FB10034 */  lw        $s1, 0x34($sp)
/* 9A1C80 80240CA0 8FB00030 */  lw        $s0, 0x30($sp)
/* 9A1C84 80240CA4 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 9A1C88 80240CA8 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 9A1C8C 80240CAC 03E00008 */  jr        $ra
/* 9A1C90 80240CB0 27BD0058 */   addiu    $sp, $sp, 0x58
