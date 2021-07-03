.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80244820_9BB1A0
.double 0.8

.section .text

glabel func_8024038C_9B6D0C
/* 9B6D0C 8024038C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9B6D10 80240390 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9B6D14 80240394 0080982D */  daddu     $s3, $a0, $zero
/* 9B6D18 80240398 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9B6D1C 8024039C AFB20018 */  sw        $s2, 0x18($sp)
/* 9B6D20 802403A0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9B6D24 802403A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9B6D28 802403A8 8E710148 */  lw        $s1, 0x148($s3)
/* 9B6D2C 802403AC 86240008 */  lh        $a0, 8($s1)
/* 9B6D30 802403B0 0C00EABB */  jal       get_npc_unsafe
/* 9B6D34 802403B4 00A0902D */   daddu    $s2, $a1, $zero
/* 9B6D38 802403B8 0040802D */  daddu     $s0, $v0, $zero
/* 9B6D3C 802403BC 8602008E */  lh        $v0, 0x8e($s0)
/* 9B6D40 802403C0 9603008E */  lhu       $v1, 0x8e($s0)
/* 9B6D44 802403C4 18400005 */  blez      $v0, .L802403DC
/* 9B6D48 802403C8 2462FFFF */   addiu    $v0, $v1, -1
/* 9B6D4C 802403CC A602008E */  sh        $v0, 0x8e($s0)
/* 9B6D50 802403D0 00021400 */  sll       $v0, $v0, 0x10
/* 9B6D54 802403D4 1C400033 */  bgtz      $v0, .L802404A4
/* 9B6D58 802403D8 00000000 */   nop
.L802403DC:
/* 9B6D5C 802403DC 8602008C */  lh        $v0, 0x8c($s0)
/* 9B6D60 802403E0 14400030 */  bnez      $v0, .L802404A4
/* 9B6D64 802403E4 00000000 */   nop
/* 9B6D68 802403E8 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9B6D6C 802403EC 8C420024 */  lw        $v0, 0x24($v0)
/* 9B6D70 802403F0 AE020028 */  sw        $v0, 0x28($s0)
/* 9B6D74 802403F4 C6400018 */  lwc1      $f0, 0x18($s2)
/* 9B6D78 802403F8 E6000018 */  swc1      $f0, 0x18($s0)
/* 9B6D7C 802403FC 8E230088 */  lw        $v1, 0x88($s1)
/* 9B6D80 80240400 24020005 */  addiu     $v0, $zero, 5
/* 9B6D84 80240404 10620005 */  beq       $v1, $v0, .L8024041C
/* 9B6D88 80240408 00000000 */   nop
/* 9B6D8C 8024040C 10600003 */  beqz      $v1, .L8024041C
/* 9B6D90 80240410 24020001 */   addiu    $v0, $zero, 1
/* 9B6D94 80240414 14620006 */  bne       $v1, $v0, .L80240430
/* 9B6D98 80240418 00000000 */   nop
.L8024041C:
/* 9B6D9C 8024041C 8E220084 */  lw        $v0, 0x84($s1)
/* 9B6DA0 80240420 00021FC2 */  srl       $v1, $v0, 0x1f
/* 9B6DA4 80240424 00431021 */  addu      $v0, $v0, $v1
/* 9B6DA8 80240428 00021043 */  sra       $v0, $v0, 1
/* 9B6DAC 8024042C A60200A8 */  sh        $v0, 0xa8($s0)
.L80240430:
/* 9B6DB0 80240430 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9B6DB4 80240434 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9B6DB8 80240438 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9B6DBC 8024043C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9B6DC0 80240440 8C460028 */  lw        $a2, 0x28($v0)
/* 9B6DC4 80240444 0C00A7B5 */  jal       dist2D
/* 9B6DC8 80240448 8C470030 */   lw       $a3, 0x30($v0)
/* 9B6DCC 8024044C C6020018 */  lwc1      $f2, 0x18($s0)
/* 9B6DD0 80240450 46020003 */  div.s     $f0, $f0, $f2
/* 9B6DD4 80240454 3C018024 */  lui       $at, %hi(D_80244820_9BB1A0)
/* 9B6DD8 80240458 D4224820 */  ldc1      $f2, %lo(D_80244820_9BB1A0)($at)
/* 9B6DDC 8024045C 46000021 */  cvt.d.s   $f0, $f0
/* 9B6DE0 80240460 46220000 */  add.d     $f0, $f0, $f2
/* 9B6DE4 80240464 4620010D */  trunc.w.d $f4, $f0
/* 9B6DE8 80240468 44022000 */  mfc1      $v0, $f4
/* 9B6DEC 8024046C 00000000 */  nop
/* 9B6DF0 80240470 A602008E */  sh        $v0, 0x8e($s0)
/* 9B6DF4 80240474 00021400 */  sll       $v0, $v0, 0x10
/* 9B6DF8 80240478 8E230078 */  lw        $v1, 0x78($s1)
/* 9B6DFC 8024047C 00021403 */  sra       $v0, $v0, 0x10
/* 9B6E00 80240480 0043102A */  slt       $v0, $v0, $v1
/* 9B6E04 80240484 10400003 */  beqz      $v0, .L80240494
/* 9B6E08 80240488 00000000 */   nop
/* 9B6E0C 8024048C 9622007A */  lhu       $v0, 0x7a($s1)
/* 9B6E10 80240490 A602008E */  sh        $v0, 0x8e($s0)
.L80240494:
/* 9B6E14 80240494 8602008E */  lh        $v0, 0x8e($s0)
/* 9B6E18 80240498 AE22007C */  sw        $v0, 0x7c($s1)
/* 9B6E1C 8024049C 2402000E */  addiu     $v0, $zero, 0xe
/* 9B6E20 802404A0 AE620070 */  sw        $v0, 0x70($s3)
.L802404A4:
/* 9B6E24 802404A4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9B6E28 802404A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9B6E2C 802404AC 8FB20018 */  lw        $s2, 0x18($sp)
/* 9B6E30 802404B0 8FB10014 */  lw        $s1, 0x14($sp)
/* 9B6E34 802404B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B6E38 802404B8 03E00008 */  jr        $ra
/* 9B6E3C 802404BC 27BD0028 */   addiu    $sp, $sp, 0x28
