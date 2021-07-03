.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80245BA0_A92620
.double 0.8

.section .text

glabel func_80240FEC_A8DA6C
/* A8DA6C 80240FEC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A8DA70 80240FF0 AFB3001C */  sw        $s3, 0x1c($sp)
/* A8DA74 80240FF4 0080982D */  daddu     $s3, $a0, $zero
/* A8DA78 80240FF8 AFBF0020 */  sw        $ra, 0x20($sp)
/* A8DA7C 80240FFC AFB20018 */  sw        $s2, 0x18($sp)
/* A8DA80 80241000 AFB10014 */  sw        $s1, 0x14($sp)
/* A8DA84 80241004 AFB00010 */  sw        $s0, 0x10($sp)
/* A8DA88 80241008 8E710148 */  lw        $s1, 0x148($s3)
/* A8DA8C 8024100C 86240008 */  lh        $a0, 8($s1)
/* A8DA90 80241010 0C00EABB */  jal       get_npc_unsafe
/* A8DA94 80241014 00A0902D */   daddu    $s2, $a1, $zero
/* A8DA98 80241018 0040802D */  daddu     $s0, $v0, $zero
/* A8DA9C 8024101C 8602008E */  lh        $v0, 0x8e($s0)
/* A8DAA0 80241020 9603008E */  lhu       $v1, 0x8e($s0)
/* A8DAA4 80241024 18400005 */  blez      $v0, .L8024103C
/* A8DAA8 80241028 2462FFFF */   addiu    $v0, $v1, -1
/* A8DAAC 8024102C A602008E */  sh        $v0, 0x8e($s0)
/* A8DAB0 80241030 00021400 */  sll       $v0, $v0, 0x10
/* A8DAB4 80241034 1C400033 */  bgtz      $v0, .L80241104
/* A8DAB8 80241038 00000000 */   nop
.L8024103C:
/* A8DABC 8024103C 8602008C */  lh        $v0, 0x8c($s0)
/* A8DAC0 80241040 14400030 */  bnez      $v0, .L80241104
/* A8DAC4 80241044 00000000 */   nop
/* A8DAC8 80241048 8E2200CC */  lw        $v0, 0xcc($s1)
/* A8DACC 8024104C 8C420024 */  lw        $v0, 0x24($v0)
/* A8DAD0 80241050 AE020028 */  sw        $v0, 0x28($s0)
/* A8DAD4 80241054 C6400018 */  lwc1      $f0, 0x18($s2)
/* A8DAD8 80241058 E6000018 */  swc1      $f0, 0x18($s0)
/* A8DADC 8024105C 8E230088 */  lw        $v1, 0x88($s1)
/* A8DAE0 80241060 24020005 */  addiu     $v0, $zero, 5
/* A8DAE4 80241064 10620005 */  beq       $v1, $v0, .L8024107C
/* A8DAE8 80241068 00000000 */   nop
/* A8DAEC 8024106C 10600003 */  beqz      $v1, .L8024107C
/* A8DAF0 80241070 24020001 */   addiu    $v0, $zero, 1
/* A8DAF4 80241074 14620006 */  bne       $v1, $v0, .L80241090
/* A8DAF8 80241078 00000000 */   nop
.L8024107C:
/* A8DAFC 8024107C 8E220084 */  lw        $v0, 0x84($s1)
/* A8DB00 80241080 00021FC2 */  srl       $v1, $v0, 0x1f
/* A8DB04 80241084 00431021 */  addu      $v0, $v0, $v1
/* A8DB08 80241088 00021043 */  sra       $v0, $v0, 1
/* A8DB0C 8024108C A60200A8 */  sh        $v0, 0xa8($s0)
.L80241090:
/* A8DB10 80241090 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A8DB14 80241094 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A8DB18 80241098 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A8DB1C 8024109C C60E0040 */  lwc1      $f14, 0x40($s0)
/* A8DB20 802410A0 8C460028 */  lw        $a2, 0x28($v0)
/* A8DB24 802410A4 0C00A7B5 */  jal       dist2D
/* A8DB28 802410A8 8C470030 */   lw       $a3, 0x30($v0)
/* A8DB2C 802410AC C6020018 */  lwc1      $f2, 0x18($s0)
/* A8DB30 802410B0 46020003 */  div.s     $f0, $f0, $f2
/* A8DB34 802410B4 3C018024 */  lui       $at, %hi(D_80245BA0_A92620)
/* A8DB38 802410B8 D4225BA0 */  ldc1      $f2, %lo(D_80245BA0_A92620)($at)
/* A8DB3C 802410BC 46000021 */  cvt.d.s   $f0, $f0
/* A8DB40 802410C0 46220000 */  add.d     $f0, $f0, $f2
/* A8DB44 802410C4 4620010D */  trunc.w.d $f4, $f0
/* A8DB48 802410C8 44022000 */  mfc1      $v0, $f4
/* A8DB4C 802410CC 00000000 */  nop
/* A8DB50 802410D0 A602008E */  sh        $v0, 0x8e($s0)
/* A8DB54 802410D4 00021400 */  sll       $v0, $v0, 0x10
/* A8DB58 802410D8 8E230078 */  lw        $v1, 0x78($s1)
/* A8DB5C 802410DC 00021403 */  sra       $v0, $v0, 0x10
/* A8DB60 802410E0 0043102A */  slt       $v0, $v0, $v1
/* A8DB64 802410E4 10400003 */  beqz      $v0, .L802410F4
/* A8DB68 802410E8 00000000 */   nop
/* A8DB6C 802410EC 9622007A */  lhu       $v0, 0x7a($s1)
/* A8DB70 802410F0 A602008E */  sh        $v0, 0x8e($s0)
.L802410F4:
/* A8DB74 802410F4 8602008E */  lh        $v0, 0x8e($s0)
/* A8DB78 802410F8 AE22007C */  sw        $v0, 0x7c($s1)
/* A8DB7C 802410FC 2402000E */  addiu     $v0, $zero, 0xe
/* A8DB80 80241100 AE620070 */  sw        $v0, 0x70($s3)
.L80241104:
/* A8DB84 80241104 8FBF0020 */  lw        $ra, 0x20($sp)
/* A8DB88 80241108 8FB3001C */  lw        $s3, 0x1c($sp)
/* A8DB8C 8024110C 8FB20018 */  lw        $s2, 0x18($sp)
/* A8DB90 80241110 8FB10014 */  lw        $s1, 0x14($sp)
/* A8DB94 80241114 8FB00010 */  lw        $s0, 0x10($sp)
/* A8DB98 80241118 03E00008 */  jr        $ra
/* A8DB9C 8024111C 27BD0028 */   addiu    $sp, $sp, 0x28
