.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024023C_A02A7C
/* A02A7C 8024023C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A02A80 80240240 AFB3001C */  sw        $s3, 0x1c($sp)
/* A02A84 80240244 0080982D */  daddu     $s3, $a0, $zero
/* A02A88 80240248 AFBF0020 */  sw        $ra, 0x20($sp)
/* A02A8C 8024024C AFB20018 */  sw        $s2, 0x18($sp)
/* A02A90 80240250 AFB10014 */  sw        $s1, 0x14($sp)
/* A02A94 80240254 AFB00010 */  sw        $s0, 0x10($sp)
/* A02A98 80240258 8E710148 */  lw        $s1, 0x148($s3)
/* A02A9C 8024025C 86240008 */  lh        $a0, 8($s1)
/* A02AA0 80240260 0C00EABB */  jal       get_npc_unsafe
/* A02AA4 80240264 00A0902D */   daddu    $s2, $a1, $zero
/* A02AA8 80240268 0040802D */  daddu     $s0, $v0, $zero
/* A02AAC 8024026C 8602008E */  lh        $v0, 0x8e($s0)
/* A02AB0 80240270 9603008E */  lhu       $v1, 0x8e($s0)
/* A02AB4 80240274 18400005 */  blez      $v0, .L8024028C
/* A02AB8 80240278 2462FFFF */   addiu    $v0, $v1, -1
/* A02ABC 8024027C A602008E */  sh        $v0, 0x8e($s0)
/* A02AC0 80240280 00021400 */  sll       $v0, $v0, 0x10
/* A02AC4 80240284 1C400033 */  bgtz      $v0, .L80240354
/* A02AC8 80240288 00000000 */   nop
.L8024028C:
/* A02ACC 8024028C 8602008C */  lh        $v0, 0x8c($s0)
/* A02AD0 80240290 14400030 */  bnez      $v0, .L80240354
/* A02AD4 80240294 00000000 */   nop
/* A02AD8 80240298 8E2200CC */  lw        $v0, 0xcc($s1)
/* A02ADC 8024029C 8C420024 */  lw        $v0, 0x24($v0)
/* A02AE0 802402A0 AE020028 */  sw        $v0, 0x28($s0)
/* A02AE4 802402A4 C6400018 */  lwc1      $f0, 0x18($s2)
/* A02AE8 802402A8 E6000018 */  swc1      $f0, 0x18($s0)
/* A02AEC 802402AC 8E230088 */  lw        $v1, 0x88($s1)
/* A02AF0 802402B0 24020005 */  addiu     $v0, $zero, 5
/* A02AF4 802402B4 10620005 */  beq       $v1, $v0, .L802402CC
/* A02AF8 802402B8 00000000 */   nop
/* A02AFC 802402BC 10600003 */  beqz      $v1, .L802402CC
/* A02B00 802402C0 24020001 */   addiu    $v0, $zero, 1
/* A02B04 802402C4 14620006 */  bne       $v1, $v0, .L802402E0
/* A02B08 802402C8 00000000 */   nop
.L802402CC:
/* A02B0C 802402CC 8E220084 */  lw        $v0, 0x84($s1)
/* A02B10 802402D0 00021FC2 */  srl       $v1, $v0, 0x1f
/* A02B14 802402D4 00431021 */  addu      $v0, $v0, $v1
/* A02B18 802402D8 00021043 */  sra       $v0, $v0, 1
/* A02B1C 802402DC A60200A8 */  sh        $v0, 0xa8($s0)
.L802402E0:
/* A02B20 802402E0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A02B24 802402E4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A02B28 802402E8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A02B2C 802402EC C60E0040 */  lwc1      $f14, 0x40($s0)
/* A02B30 802402F0 8C460028 */  lw        $a2, 0x28($v0)
/* A02B34 802402F4 0C00A7B5 */  jal       dist2D
/* A02B38 802402F8 8C470030 */   lw       $a3, 0x30($v0)
/* A02B3C 802402FC C6020018 */  lwc1      $f2, 0x18($s0)
/* A02B40 80240300 46020003 */  div.s     $f0, $f0, $f2
/* A02B44 80240304 3C018024 */  lui       $at, %hi(D_802445C0)
/* A02B48 80240308 D42245C0 */  ldc1      $f2, %lo(D_802445C0)($at)
/* A02B4C 8024030C 46000021 */  cvt.d.s   $f0, $f0
/* A02B50 80240310 46220000 */  add.d     $f0, $f0, $f2
/* A02B54 80240314 4620010D */  trunc.w.d $f4, $f0
/* A02B58 80240318 44022000 */  mfc1      $v0, $f4
/* A02B5C 8024031C 00000000 */  nop
/* A02B60 80240320 A602008E */  sh        $v0, 0x8e($s0)
/* A02B64 80240324 00021400 */  sll       $v0, $v0, 0x10
/* A02B68 80240328 8E230078 */  lw        $v1, 0x78($s1)
/* A02B6C 8024032C 00021403 */  sra       $v0, $v0, 0x10
/* A02B70 80240330 0043102A */  slt       $v0, $v0, $v1
/* A02B74 80240334 10400003 */  beqz      $v0, .L80240344
/* A02B78 80240338 00000000 */   nop
/* A02B7C 8024033C 9622007A */  lhu       $v0, 0x7a($s1)
/* A02B80 80240340 A602008E */  sh        $v0, 0x8e($s0)
.L80240344:
/* A02B84 80240344 8602008E */  lh        $v0, 0x8e($s0)
/* A02B88 80240348 AE22007C */  sw        $v0, 0x7c($s1)
/* A02B8C 8024034C 2402000E */  addiu     $v0, $zero, 0xe
/* A02B90 80240350 AE620070 */  sw        $v0, 0x70($s3)
.L80240354:
/* A02B94 80240354 8FBF0020 */  lw        $ra, 0x20($sp)
/* A02B98 80240358 8FB3001C */  lw        $s3, 0x1c($sp)
/* A02B9C 8024035C 8FB20018 */  lw        $s2, 0x18($sp)
/* A02BA0 80240360 8FB10014 */  lw        $s1, 0x14($sp)
/* A02BA4 80240364 8FB00010 */  lw        $s0, 0x10($sp)
/* A02BA8 80240368 03E00008 */  jr        $ra
/* A02BAC 8024036C 27BD0028 */   addiu    $sp, $sp, 0x28
