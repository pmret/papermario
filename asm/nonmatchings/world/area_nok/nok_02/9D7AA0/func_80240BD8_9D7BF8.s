.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BD8_9D7BF8
/* 9D7BF8 80240BD8 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 9D7BFC 80240BDC AFB20038 */  sw        $s2, 0x38($sp)
/* 9D7C00 80240BE0 0080902D */  daddu     $s2, $a0, $zero
/* 9D7C04 80240BE4 AFBF0044 */  sw        $ra, 0x44($sp)
/* 9D7C08 80240BE8 AFB40040 */  sw        $s4, 0x40($sp)
/* 9D7C0C 80240BEC AFB3003C */  sw        $s3, 0x3c($sp)
/* 9D7C10 80240BF0 AFB10034 */  sw        $s1, 0x34($sp)
/* 9D7C14 80240BF4 AFB00030 */  sw        $s0, 0x30($sp)
/* 9D7C18 80240BF8 F7B60050 */  sdc1      $f22, 0x50($sp)
/* 9D7C1C 80240BFC F7B40048 */  sdc1      $f20, 0x48($sp)
/* 9D7C20 80240C00 8E510148 */  lw        $s1, 0x148($s2)
/* 9D7C24 80240C04 00A0982D */  daddu     $s3, $a1, $zero
/* 9D7C28 80240C08 86240008 */  lh        $a0, 8($s1)
/* 9D7C2C 80240C0C 0C00EABB */  jal       get_npc_unsafe
/* 9D7C30 80240C10 00C0A02D */   daddu    $s4, $a2, $zero
/* 9D7C34 80240C14 8E630014 */  lw        $v1, 0x14($s3)
/* 9D7C38 80240C18 04600030 */  bltz      $v1, .L80240CDC
/* 9D7C3C 80240C1C 0040802D */   daddu    $s0, $v0, $zero
/* 9D7C40 80240C20 8E420074 */  lw        $v0, 0x74($s2)
/* 9D7C44 80240C24 1C40002C */  bgtz      $v0, .L80240CD8
/* 9D7C48 80240C28 2442FFFF */   addiu    $v0, $v0, -1
/* 9D7C4C 80240C2C 0280202D */  daddu     $a0, $s4, $zero
/* 9D7C50 80240C30 AE430074 */  sw        $v1, 0x74($s2)
/* 9D7C54 80240C34 AFA00010 */  sw        $zero, 0x10($sp)
/* 9D7C58 80240C38 8E66000C */  lw        $a2, 0xc($s3)
/* 9D7C5C 80240C3C 8E670010 */  lw        $a3, 0x10($s3)
/* 9D7C60 80240C40 0C01242D */  jal       func_800490B4
/* 9D7C64 80240C44 0220282D */   daddu    $a1, $s1, $zero
/* 9D7C68 80240C48 10400021 */  beqz      $v0, .L80240CD0
/* 9D7C6C 80240C4C 0000202D */   daddu    $a0, $zero, $zero
/* 9D7C70 80240C50 0200282D */  daddu     $a1, $s0, $zero
/* 9D7C74 80240C54 0000302D */  daddu     $a2, $zero, $zero
/* 9D7C78 80240C58 860300A8 */  lh        $v1, 0xa8($s0)
/* 9D7C7C 80240C5C 3C013F80 */  lui       $at, 0x3f80
/* 9D7C80 80240C60 44810000 */  mtc1      $at, $f0
/* 9D7C84 80240C64 3C014000 */  lui       $at, 0x4000
/* 9D7C88 80240C68 44811000 */  mtc1      $at, $f2
/* 9D7C8C 80240C6C 3C01C1A0 */  lui       $at, 0xc1a0
/* 9D7C90 80240C70 44812000 */  mtc1      $at, $f4
/* 9D7C94 80240C74 2402000F */  addiu     $v0, $zero, 0xf
/* 9D7C98 80240C78 AFA2001C */  sw        $v0, 0x1c($sp)
/* 9D7C9C 80240C7C 44833000 */  mtc1      $v1, $f6
/* 9D7CA0 80240C80 00000000 */  nop
/* 9D7CA4 80240C84 468031A0 */  cvt.s.w   $f6, $f6
/* 9D7CA8 80240C88 44073000 */  mfc1      $a3, $f6
/* 9D7CAC 80240C8C 27A20028 */  addiu     $v0, $sp, 0x28
/* 9D7CB0 80240C90 AFA20020 */  sw        $v0, 0x20($sp)
/* 9D7CB4 80240C94 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9D7CB8 80240C98 E7A20014 */  swc1      $f2, 0x14($sp)
/* 9D7CBC 80240C9C 0C01BFA4 */  jal       fx_emote
/* 9D7CC0 80240CA0 E7A40018 */   swc1     $f4, 0x18($sp)
/* 9D7CC4 80240CA4 0200202D */  daddu     $a0, $s0, $zero
/* 9D7CC8 80240CA8 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 9D7CCC 80240CAC 0C012530 */  jal       func_800494C0
/* 9D7CD0 80240CB0 3C060020 */   lui      $a2, 0x20
/* 9D7CD4 80240CB4 8E220018 */  lw        $v0, 0x18($s1)
/* 9D7CD8 80240CB8 9442002A */  lhu       $v0, 0x2a($v0)
/* 9D7CDC 80240CBC 30420001 */  andi      $v0, $v0, 1
/* 9D7CE0 80240CC0 14400064 */  bnez      $v0, .L80240E54
/* 9D7CE4 80240CC4 2402000A */   addiu    $v0, $zero, 0xa
/* 9D7CE8 80240CC8 08090395 */  j         .L80240E54
/* 9D7CEC 80240CCC 2402000C */   addiu    $v0, $zero, 0xc
.L80240CD0:
/* 9D7CF0 80240CD0 8E420074 */  lw        $v0, 0x74($s2)
/* 9D7CF4 80240CD4 2442FFFF */  addiu     $v0, $v0, -1
.L80240CD8:
/* 9D7CF8 80240CD8 AE420074 */  sw        $v0, 0x74($s2)
.L80240CDC:
/* 9D7CFC 80240CDC 8602008C */  lh        $v0, 0x8c($s0)
/* 9D7D00 80240CE0 1440005D */  bnez      $v0, .L80240E58
/* 9D7D04 80240CE4 00000000 */   nop
/* 9D7D08 80240CE8 C6000018 */  lwc1      $f0, 0x18($s0)
/* 9D7D0C 80240CEC 3C014010 */  lui       $at, 0x4010
/* 9D7D10 80240CF0 44811800 */  mtc1      $at, $f3
/* 9D7D14 80240CF4 44801000 */  mtc1      $zero, $f2
/* 9D7D18 80240CF8 46000021 */  cvt.d.s   $f0, $f0
/* 9D7D1C 80240CFC 4622003C */  c.lt.d    $f0, $f2
/* 9D7D20 80240D00 00000000 */  nop
/* 9D7D24 80240D04 45000003 */  bc1f      .L80240D14
/* 9D7D28 80240D08 0200202D */   daddu    $a0, $s0, $zero
/* 9D7D2C 80240D0C 08090346 */  j         .L80240D18
/* 9D7D30 80240D10 0000282D */   daddu    $a1, $zero, $zero
.L80240D14:
/* 9D7D34 80240D14 24050001 */  addiu     $a1, $zero, 1
.L80240D18:
/* 9D7D38 80240D18 0C00F598 */  jal       func_8003D660
/* 9D7D3C 80240D1C 00000000 */   nop
/* 9D7D40 80240D20 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9D7D44 80240D24 8E430078 */  lw        $v1, 0x78($s2)
/* 9D7D48 80240D28 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9D7D4C 80240D2C 00031040 */  sll       $v0, $v1, 1
/* 9D7D50 80240D30 00431021 */  addu      $v0, $v0, $v1
/* 9D7D54 80240D34 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9D7D58 80240D38 00021080 */  sll       $v0, $v0, 2
/* 9D7D5C 80240D3C 00431021 */  addu      $v0, $v0, $v1
/* 9D7D60 80240D40 C4560004 */  lwc1      $f22, 4($v0)
/* 9D7D64 80240D44 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9D7D68 80240D48 C454000C */  lwc1      $f20, 0xc($v0)
/* 9D7D6C 80240D4C 4680A520 */  cvt.s.w   $f20, $f20
/* 9D7D70 80240D50 4406B000 */  mfc1      $a2, $f22
/* 9D7D74 80240D54 4407A000 */  mfc1      $a3, $f20
/* 9D7D78 80240D58 0C00A720 */  jal       atan2
/* 9D7D7C 80240D5C 00000000 */   nop
/* 9D7D80 80240D60 8E050018 */  lw        $a1, 0x18($s0)
/* 9D7D84 80240D64 44060000 */  mfc1      $a2, $f0
/* 9D7D88 80240D68 0200202D */  daddu     $a0, $s0, $zero
/* 9D7D8C 80240D6C 0C00EA95 */  jal       npc_move_heading
/* 9D7D90 80240D70 AE06000C */   sw       $a2, 0xc($s0)
/* 9D7D94 80240D74 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9D7D98 80240D78 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9D7D9C 80240D7C 4406B000 */  mfc1      $a2, $f22
/* 9D7DA0 80240D80 4407A000 */  mfc1      $a3, $f20
/* 9D7DA4 80240D84 0C00A7B5 */  jal       dist2D
/* 9D7DA8 80240D88 00000000 */   nop
/* 9D7DAC 80240D8C C6020018 */  lwc1      $f2, 0x18($s0)
/* 9D7DB0 80240D90 4602003E */  c.le.s    $f0, $f2
/* 9D7DB4 80240D94 00000000 */  nop
/* 9D7DB8 80240D98 4500002F */  bc1f      .L80240E58
/* 9D7DBC 80240D9C 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 9D7DC0 80240DA0 24020002 */  addiu     $v0, $zero, 2
/* 9D7DC4 80240DA4 0C00A67F */  jal       rand_int
/* 9D7DC8 80240DA8 AE420070 */   sw       $v0, 0x70($s2)
/* 9D7DCC 80240DAC 3C035555 */  lui       $v1, 0x5555
/* 9D7DD0 80240DB0 34635556 */  ori       $v1, $v1, 0x5556
/* 9D7DD4 80240DB4 00430018 */  mult      $v0, $v1
/* 9D7DD8 80240DB8 000227C3 */  sra       $a0, $v0, 0x1f
/* 9D7DDC 80240DBC 00004010 */  mfhi      $t0
/* 9D7DE0 80240DC0 01042023 */  subu      $a0, $t0, $a0
/* 9D7DE4 80240DC4 00041840 */  sll       $v1, $a0, 1
/* 9D7DE8 80240DC8 00641821 */  addu      $v1, $v1, $a0
/* 9D7DEC 80240DCC 00431023 */  subu      $v0, $v0, $v1
/* 9D7DF0 80240DD0 24430002 */  addiu     $v1, $v0, 2
/* 9D7DF4 80240DD4 AE430074 */  sw        $v1, 0x74($s2)
/* 9D7DF8 80240DD8 8E62002C */  lw        $v0, 0x2c($s3)
/* 9D7DFC 80240DDC 18400009 */  blez      $v0, .L80240E04
/* 9D7E00 80240DE0 24020004 */   addiu    $v0, $zero, 4
/* 9D7E04 80240DE4 8E620004 */  lw        $v0, 4($s3)
/* 9D7E08 80240DE8 18400006 */  blez      $v0, .L80240E04
/* 9D7E0C 80240DEC 24020004 */   addiu    $v0, $zero, 4
/* 9D7E10 80240DF0 8E620008 */  lw        $v0, 8($s3)
/* 9D7E14 80240DF4 18400003 */  blez      $v0, .L80240E04
/* 9D7E18 80240DF8 24020004 */   addiu    $v0, $zero, 4
/* 9D7E1C 80240DFC 14600002 */  bnez      $v1, .L80240E08
/* 9D7E20 80240E00 00000000 */   nop
.L80240E04:
/* 9D7E24 80240E04 AE420070 */  sw        $v0, 0x70($s2)
.L80240E08:
/* 9D7E28 80240E08 0C00A67F */  jal       rand_int
/* 9D7E2C 80240E0C 24042710 */   addiu    $a0, $zero, 0x2710
/* 9D7E30 80240E10 3C0351EB */  lui       $v1, 0x51eb
/* 9D7E34 80240E14 3463851F */  ori       $v1, $v1, 0x851f
/* 9D7E38 80240E18 00430018 */  mult      $v0, $v1
/* 9D7E3C 80240E1C 00021FC3 */  sra       $v1, $v0, 0x1f
/* 9D7E40 80240E20 00004010 */  mfhi      $t0
/* 9D7E44 80240E24 00082143 */  sra       $a0, $t0, 5
/* 9D7E48 80240E28 00832023 */  subu      $a0, $a0, $v1
/* 9D7E4C 80240E2C 00041840 */  sll       $v1, $a0, 1
/* 9D7E50 80240E30 00641821 */  addu      $v1, $v1, $a0
/* 9D7E54 80240E34 000318C0 */  sll       $v1, $v1, 3
/* 9D7E58 80240E38 00641821 */  addu      $v1, $v1, $a0
/* 9D7E5C 80240E3C 00031880 */  sll       $v1, $v1, 2
/* 9D7E60 80240E40 8E640004 */  lw        $a0, 4($s3)
/* 9D7E64 80240E44 00431023 */  subu      $v0, $v0, $v1
/* 9D7E68 80240E48 0044102A */  slt       $v0, $v0, $a0
/* 9D7E6C 80240E4C 10400002 */  beqz      $v0, .L80240E58
/* 9D7E70 80240E50 24020004 */   addiu    $v0, $zero, 4
.L80240E54:
/* 9D7E74 80240E54 AE420070 */  sw        $v0, 0x70($s2)
.L80240E58:
/* 9D7E78 80240E58 8FBF0044 */  lw        $ra, 0x44($sp)
/* 9D7E7C 80240E5C 8FB40040 */  lw        $s4, 0x40($sp)
/* 9D7E80 80240E60 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9D7E84 80240E64 8FB20038 */  lw        $s2, 0x38($sp)
/* 9D7E88 80240E68 8FB10034 */  lw        $s1, 0x34($sp)
/* 9D7E8C 80240E6C 8FB00030 */  lw        $s0, 0x30($sp)
/* 9D7E90 80240E70 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 9D7E94 80240E74 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 9D7E98 80240E78 03E00008 */  jr        $ra
/* 9D7E9C 80240E7C 27BD0058 */   addiu    $sp, $sp, 0x58
