.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AAC_882C6C
/* 882C6C 80240AAC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 882C70 80240AB0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 882C74 80240AB4 0080982D */  daddu     $s3, $a0, $zero
/* 882C78 80240AB8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 882C7C 80240ABC AFB20018 */  sw        $s2, 0x18($sp)
/* 882C80 80240AC0 AFB10014 */  sw        $s1, 0x14($sp)
/* 882C84 80240AC4 AFB00010 */  sw        $s0, 0x10($sp)
/* 882C88 80240AC8 8E710148 */  lw        $s1, 0x148($s3)
/* 882C8C 80240ACC 86240008 */  lh        $a0, 8($s1)
/* 882C90 80240AD0 0C00EABB */  jal       get_npc_unsafe
/* 882C94 80240AD4 00A0902D */   daddu    $s2, $a1, $zero
/* 882C98 80240AD8 0040802D */  daddu     $s0, $v0, $zero
/* 882C9C 80240ADC 8602008E */  lh        $v0, 0x8e($s0)
/* 882CA0 80240AE0 9603008E */  lhu       $v1, 0x8e($s0)
/* 882CA4 80240AE4 18400005 */  blez      $v0, .L80240AFC
/* 882CA8 80240AE8 2462FFFF */   addiu    $v0, $v1, -1
/* 882CAC 80240AEC A602008E */  sh        $v0, 0x8e($s0)
/* 882CB0 80240AF0 00021400 */  sll       $v0, $v0, 0x10
/* 882CB4 80240AF4 1C400033 */  bgtz      $v0, .L80240BC4
/* 882CB8 80240AF8 00000000 */   nop      
.L80240AFC:
/* 882CBC 80240AFC 8602008C */  lh        $v0, 0x8c($s0)
/* 882CC0 80240B00 14400030 */  bnez      $v0, .L80240BC4
/* 882CC4 80240B04 00000000 */   nop      
/* 882CC8 80240B08 8E2200CC */  lw        $v0, 0xcc($s1)
/* 882CCC 80240B0C 8C420024 */  lw        $v0, 0x24($v0)
/* 882CD0 80240B10 AE020028 */  sw        $v0, 0x28($s0)
/* 882CD4 80240B14 C6400018 */  lwc1      $f0, 0x18($s2)
/* 882CD8 80240B18 E6000018 */  swc1      $f0, 0x18($s0)
/* 882CDC 80240B1C 8E230088 */  lw        $v1, 0x88($s1)
/* 882CE0 80240B20 24020005 */  addiu     $v0, $zero, 5
/* 882CE4 80240B24 10620005 */  beq       $v1, $v0, .L80240B3C
/* 882CE8 80240B28 00000000 */   nop      
/* 882CEC 80240B2C 10600003 */  beqz      $v1, .L80240B3C
/* 882CF0 80240B30 24020001 */   addiu    $v0, $zero, 1
/* 882CF4 80240B34 14620006 */  bne       $v1, $v0, .L80240B50
/* 882CF8 80240B38 00000000 */   nop      
.L80240B3C:
/* 882CFC 80240B3C 8E220084 */  lw        $v0, 0x84($s1)
/* 882D00 80240B40 00021FC2 */  srl       $v1, $v0, 0x1f
/* 882D04 80240B44 00431021 */  addu      $v0, $v0, $v1
/* 882D08 80240B48 00021043 */  sra       $v0, $v0, 1
/* 882D0C 80240B4C A60200A8 */  sh        $v0, 0xa8($s0)
.L80240B50:
/* 882D10 80240B50 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 882D14 80240B54 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 882D18 80240B58 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 882D1C 80240B5C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 882D20 80240B60 8C460028 */  lw        $a2, 0x28($v0)
/* 882D24 80240B64 0C00A7B5 */  jal       dist2D
/* 882D28 80240B68 8C470030 */   lw       $a3, 0x30($v0)
/* 882D2C 80240B6C C6020018 */  lwc1      $f2, 0x18($s0)
/* 882D30 80240B70 46020003 */  div.s     $f0, $f0, $f2
/* 882D34 80240B74 3C018024 */  lui       $at, %hi(D_802441A0)
/* 882D38 80240B78 D42241A0 */  ldc1      $f2, %lo(D_802441A0)($at)
/* 882D3C 80240B7C 46000021 */  cvt.d.s   $f0, $f0
/* 882D40 80240B80 46220000 */  add.d     $f0, $f0, $f2
/* 882D44 80240B84 4620010D */  trunc.w.d $f4, $f0
/* 882D48 80240B88 44022000 */  mfc1      $v0, $f4
/* 882D4C 80240B8C 00000000 */  nop       
/* 882D50 80240B90 A602008E */  sh        $v0, 0x8e($s0)
/* 882D54 80240B94 00021400 */  sll       $v0, $v0, 0x10
/* 882D58 80240B98 8E230078 */  lw        $v1, 0x78($s1)
/* 882D5C 80240B9C 00021403 */  sra       $v0, $v0, 0x10
/* 882D60 80240BA0 0043102A */  slt       $v0, $v0, $v1
/* 882D64 80240BA4 10400003 */  beqz      $v0, .L80240BB4
/* 882D68 80240BA8 00000000 */   nop      
/* 882D6C 80240BAC 9622007A */  lhu       $v0, 0x7a($s1)
/* 882D70 80240BB0 A602008E */  sh        $v0, 0x8e($s0)
.L80240BB4:
/* 882D74 80240BB4 8602008E */  lh        $v0, 0x8e($s0)
/* 882D78 80240BB8 AE22007C */  sw        $v0, 0x7c($s1)
/* 882D7C 80240BBC 2402000E */  addiu     $v0, $zero, 0xe
/* 882D80 80240BC0 AE620070 */  sw        $v0, 0x70($s3)
.L80240BC4:
/* 882D84 80240BC4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 882D88 80240BC8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 882D8C 80240BCC 8FB20018 */  lw        $s2, 0x18($sp)
/* 882D90 80240BD0 8FB10014 */  lw        $s1, 0x14($sp)
/* 882D94 80240BD4 8FB00010 */  lw        $s0, 0x10($sp)
/* 882D98 80240BD8 03E00008 */  jr        $ra
/* 882D9C 80240BDC 27BD0028 */   addiu    $sp, $sp, 0x28
