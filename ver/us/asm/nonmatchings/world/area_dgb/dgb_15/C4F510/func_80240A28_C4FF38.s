.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A28_C4FF38
/* C4FF38 80240A28 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* C4FF3C 80240A2C AFB20038 */  sw        $s2, 0x38($sp)
/* C4FF40 80240A30 0080902D */  daddu     $s2, $a0, $zero
/* C4FF44 80240A34 AFBF0044 */  sw        $ra, 0x44($sp)
/* C4FF48 80240A38 AFB40040 */  sw        $s4, 0x40($sp)
/* C4FF4C 80240A3C AFB3003C */  sw        $s3, 0x3c($sp)
/* C4FF50 80240A40 AFB10034 */  sw        $s1, 0x34($sp)
/* C4FF54 80240A44 AFB00030 */  sw        $s0, 0x30($sp)
/* C4FF58 80240A48 F7B60050 */  sdc1      $f22, 0x50($sp)
/* C4FF5C 80240A4C F7B40048 */  sdc1      $f20, 0x48($sp)
/* C4FF60 80240A50 8E510148 */  lw        $s1, 0x148($s2)
/* C4FF64 80240A54 00A0982D */  daddu     $s3, $a1, $zero
/* C4FF68 80240A58 86240008 */  lh        $a0, 8($s1)
/* C4FF6C 80240A5C 0C00EABB */  jal       get_npc_unsafe
/* C4FF70 80240A60 00C0A02D */   daddu    $s4, $a2, $zero
/* C4FF74 80240A64 8E630014 */  lw        $v1, 0x14($s3)
/* C4FF78 80240A68 04600030 */  bltz      $v1, .L80240B2C
/* C4FF7C 80240A6C 0040802D */   daddu    $s0, $v0, $zero
/* C4FF80 80240A70 8E420074 */  lw        $v0, 0x74($s2)
/* C4FF84 80240A74 1C40002C */  bgtz      $v0, .L80240B28
/* C4FF88 80240A78 2442FFFF */   addiu    $v0, $v0, -1
/* C4FF8C 80240A7C 0280202D */  daddu     $a0, $s4, $zero
/* C4FF90 80240A80 AE430074 */  sw        $v1, 0x74($s2)
/* C4FF94 80240A84 AFA00010 */  sw        $zero, 0x10($sp)
/* C4FF98 80240A88 8E66000C */  lw        $a2, 0xc($s3)
/* C4FF9C 80240A8C 8E670010 */  lw        $a3, 0x10($s3)
/* C4FFA0 80240A90 0C01242D */  jal       func_800490B4
/* C4FFA4 80240A94 0220282D */   daddu    $a1, $s1, $zero
/* C4FFA8 80240A98 10400021 */  beqz      $v0, .L80240B20
/* C4FFAC 80240A9C 0000202D */   daddu    $a0, $zero, $zero
/* C4FFB0 80240AA0 0200282D */  daddu     $a1, $s0, $zero
/* C4FFB4 80240AA4 0000302D */  daddu     $a2, $zero, $zero
/* C4FFB8 80240AA8 860300A8 */  lh        $v1, 0xa8($s0)
/* C4FFBC 80240AAC 3C013F80 */  lui       $at, 0x3f80
/* C4FFC0 80240AB0 44810000 */  mtc1      $at, $f0
/* C4FFC4 80240AB4 3C014000 */  lui       $at, 0x4000
/* C4FFC8 80240AB8 44811000 */  mtc1      $at, $f2
/* C4FFCC 80240ABC 3C01C1A0 */  lui       $at, 0xc1a0
/* C4FFD0 80240AC0 44812000 */  mtc1      $at, $f4
/* C4FFD4 80240AC4 2402000F */  addiu     $v0, $zero, 0xf
/* C4FFD8 80240AC8 AFA2001C */  sw        $v0, 0x1c($sp)
/* C4FFDC 80240ACC 44833000 */  mtc1      $v1, $f6
/* C4FFE0 80240AD0 00000000 */  nop
/* C4FFE4 80240AD4 468031A0 */  cvt.s.w   $f6, $f6
/* C4FFE8 80240AD8 44073000 */  mfc1      $a3, $f6
/* C4FFEC 80240ADC 27A20028 */  addiu     $v0, $sp, 0x28
/* C4FFF0 80240AE0 AFA20020 */  sw        $v0, 0x20($sp)
/* C4FFF4 80240AE4 E7A00010 */  swc1      $f0, 0x10($sp)
/* C4FFF8 80240AE8 E7A20014 */  swc1      $f2, 0x14($sp)
/* C4FFFC 80240AEC 0C01BFA4 */  jal       fx_emote
/* C50000 80240AF0 E7A40018 */   swc1     $f4, 0x18($sp)
/* C50004 80240AF4 0200202D */  daddu     $a0, $s0, $zero
/* C50008 80240AF8 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C5000C 80240AFC 0C012530 */  jal       func_800494C0
/* C50010 80240B00 3C060020 */   lui      $a2, 0x20
/* C50014 80240B04 8E220018 */  lw        $v0, 0x18($s1)
/* C50018 80240B08 9442002A */  lhu       $v0, 0x2a($v0)
/* C5001C 80240B0C 30420001 */  andi      $v0, $v0, 1
/* C50020 80240B10 14400064 */  bnez      $v0, .L80240CA4
/* C50024 80240B14 2402000A */   addiu    $v0, $zero, 0xa
/* C50028 80240B18 08090329 */  j         .L80240CA4
/* C5002C 80240B1C 2402000C */   addiu    $v0, $zero, 0xc
.L80240B20:
/* C50030 80240B20 8E420074 */  lw        $v0, 0x74($s2)
/* C50034 80240B24 2442FFFF */  addiu     $v0, $v0, -1
.L80240B28:
/* C50038 80240B28 AE420074 */  sw        $v0, 0x74($s2)
.L80240B2C:
/* C5003C 80240B2C 8602008C */  lh        $v0, 0x8c($s0)
/* C50040 80240B30 1440005D */  bnez      $v0, .L80240CA8
/* C50044 80240B34 00000000 */   nop
/* C50048 80240B38 C6000018 */  lwc1      $f0, 0x18($s0)
/* C5004C 80240B3C 3C014010 */  lui       $at, 0x4010
/* C50050 80240B40 44811800 */  mtc1      $at, $f3
/* C50054 80240B44 44801000 */  mtc1      $zero, $f2
/* C50058 80240B48 46000021 */  cvt.d.s   $f0, $f0
/* C5005C 80240B4C 4622003C */  c.lt.d    $f0, $f2
/* C50060 80240B50 00000000 */  nop
/* C50064 80240B54 45000003 */  bc1f      .L80240B64
/* C50068 80240B58 0200202D */   daddu    $a0, $s0, $zero
/* C5006C 80240B5C 080902DA */  j         .L80240B68
/* C50070 80240B60 0000282D */   daddu    $a1, $zero, $zero
.L80240B64:
/* C50074 80240B64 24050001 */  addiu     $a1, $zero, 1
.L80240B68:
/* C50078 80240B68 0C00F598 */  jal       func_8003D660
/* C5007C 80240B6C 00000000 */   nop
/* C50080 80240B70 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C50084 80240B74 8E430078 */  lw        $v1, 0x78($s2)
/* C50088 80240B78 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C5008C 80240B7C 00031040 */  sll       $v0, $v1, 1
/* C50090 80240B80 00431021 */  addu      $v0, $v0, $v1
/* C50094 80240B84 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C50098 80240B88 00021080 */  sll       $v0, $v0, 2
/* C5009C 80240B8C 00431021 */  addu      $v0, $v0, $v1
/* C500A0 80240B90 C4560004 */  lwc1      $f22, 4($v0)
/* C500A4 80240B94 4680B5A0 */  cvt.s.w   $f22, $f22
/* C500A8 80240B98 C454000C */  lwc1      $f20, 0xc($v0)
/* C500AC 80240B9C 4680A520 */  cvt.s.w   $f20, $f20
/* C500B0 80240BA0 4406B000 */  mfc1      $a2, $f22
/* C500B4 80240BA4 4407A000 */  mfc1      $a3, $f20
/* C500B8 80240BA8 0C00A720 */  jal       atan2
/* C500BC 80240BAC 00000000 */   nop
/* C500C0 80240BB0 8E050018 */  lw        $a1, 0x18($s0)
/* C500C4 80240BB4 44060000 */  mfc1      $a2, $f0
/* C500C8 80240BB8 0200202D */  daddu     $a0, $s0, $zero
/* C500CC 80240BBC 0C00EA95 */  jal       npc_move_heading
/* C500D0 80240BC0 AE06000C */   sw       $a2, 0xc($s0)
/* C500D4 80240BC4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C500D8 80240BC8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C500DC 80240BCC 4406B000 */  mfc1      $a2, $f22
/* C500E0 80240BD0 4407A000 */  mfc1      $a3, $f20
/* C500E4 80240BD4 0C00A7B5 */  jal       dist2D
/* C500E8 80240BD8 00000000 */   nop
/* C500EC 80240BDC C6020018 */  lwc1      $f2, 0x18($s0)
/* C500F0 80240BE0 4602003E */  c.le.s    $f0, $f2
/* C500F4 80240BE4 00000000 */  nop
/* C500F8 80240BE8 4500002F */  bc1f      .L80240CA8
/* C500FC 80240BEC 240403E8 */   addiu    $a0, $zero, 0x3e8
/* C50100 80240BF0 24020002 */  addiu     $v0, $zero, 2
/* C50104 80240BF4 0C00A67F */  jal       rand_int
/* C50108 80240BF8 AE420070 */   sw       $v0, 0x70($s2)
/* C5010C 80240BFC 3C035555 */  lui       $v1, 0x5555
/* C50110 80240C00 34635556 */  ori       $v1, $v1, 0x5556
/* C50114 80240C04 00430018 */  mult      $v0, $v1
/* C50118 80240C08 000227C3 */  sra       $a0, $v0, 0x1f
/* C5011C 80240C0C 00004010 */  mfhi      $t0
/* C50120 80240C10 01042023 */  subu      $a0, $t0, $a0
/* C50124 80240C14 00041840 */  sll       $v1, $a0, 1
/* C50128 80240C18 00641821 */  addu      $v1, $v1, $a0
/* C5012C 80240C1C 00431023 */  subu      $v0, $v0, $v1
/* C50130 80240C20 24430002 */  addiu     $v1, $v0, 2
/* C50134 80240C24 AE430074 */  sw        $v1, 0x74($s2)
/* C50138 80240C28 8E62002C */  lw        $v0, 0x2c($s3)
/* C5013C 80240C2C 18400009 */  blez      $v0, .L80240C54
/* C50140 80240C30 24020004 */   addiu    $v0, $zero, 4
/* C50144 80240C34 8E620004 */  lw        $v0, 4($s3)
/* C50148 80240C38 18400006 */  blez      $v0, .L80240C54
/* C5014C 80240C3C 24020004 */   addiu    $v0, $zero, 4
/* C50150 80240C40 8E620008 */  lw        $v0, 8($s3)
/* C50154 80240C44 18400003 */  blez      $v0, .L80240C54
/* C50158 80240C48 24020004 */   addiu    $v0, $zero, 4
/* C5015C 80240C4C 14600002 */  bnez      $v1, .L80240C58
/* C50160 80240C50 00000000 */   nop
.L80240C54:
/* C50164 80240C54 AE420070 */  sw        $v0, 0x70($s2)
.L80240C58:
/* C50168 80240C58 0C00A67F */  jal       rand_int
/* C5016C 80240C5C 24042710 */   addiu    $a0, $zero, 0x2710
/* C50170 80240C60 3C0351EB */  lui       $v1, 0x51eb
/* C50174 80240C64 3463851F */  ori       $v1, $v1, 0x851f
/* C50178 80240C68 00430018 */  mult      $v0, $v1
/* C5017C 80240C6C 00021FC3 */  sra       $v1, $v0, 0x1f
/* C50180 80240C70 00004010 */  mfhi      $t0
/* C50184 80240C74 00082143 */  sra       $a0, $t0, 5
/* C50188 80240C78 00832023 */  subu      $a0, $a0, $v1
/* C5018C 80240C7C 00041840 */  sll       $v1, $a0, 1
/* C50190 80240C80 00641821 */  addu      $v1, $v1, $a0
/* C50194 80240C84 000318C0 */  sll       $v1, $v1, 3
/* C50198 80240C88 00641821 */  addu      $v1, $v1, $a0
/* C5019C 80240C8C 00031880 */  sll       $v1, $v1, 2
/* C501A0 80240C90 8E640004 */  lw        $a0, 4($s3)
/* C501A4 80240C94 00431023 */  subu      $v0, $v0, $v1
/* C501A8 80240C98 0044102A */  slt       $v0, $v0, $a0
/* C501AC 80240C9C 10400002 */  beqz      $v0, .L80240CA8
/* C501B0 80240CA0 24020004 */   addiu    $v0, $zero, 4
.L80240CA4:
/* C501B4 80240CA4 AE420070 */  sw        $v0, 0x70($s2)
.L80240CA8:
/* C501B8 80240CA8 8FBF0044 */  lw        $ra, 0x44($sp)
/* C501BC 80240CAC 8FB40040 */  lw        $s4, 0x40($sp)
/* C501C0 80240CB0 8FB3003C */  lw        $s3, 0x3c($sp)
/* C501C4 80240CB4 8FB20038 */  lw        $s2, 0x38($sp)
/* C501C8 80240CB8 8FB10034 */  lw        $s1, 0x34($sp)
/* C501CC 80240CBC 8FB00030 */  lw        $s0, 0x30($sp)
/* C501D0 80240CC0 D7B60050 */  ldc1      $f22, 0x50($sp)
/* C501D4 80240CC4 D7B40048 */  ldc1      $f20, 0x48($sp)
/* C501D8 80240CC8 03E00008 */  jr        $ra
/* C501DC 80240CCC 27BD0058 */   addiu    $sp, $sp, 0x58
