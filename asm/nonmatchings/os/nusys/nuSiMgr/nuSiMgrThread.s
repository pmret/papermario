.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuSiMgrThread
/* 83D0 8002CFD0 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 83D4 8002CFD4 AFB00048 */  sw        $s0, 0x48($sp)
/* 83D8 8002CFD8 3C10800E */  lui       $s0, %hi(D_800D91F8)
/* 83DC 8002CFDC 261091F8 */  addiu     $s0, $s0, %lo(D_800D91F8)
/* 83E0 8002CFE0 0200202D */  daddu     $a0, $s0, $zero
/* 83E4 8002CFE4 27A50020 */  addiu     $a1, $sp, 0x20
/* 83E8 8002CFE8 24060008 */  addiu     $a2, $zero, 8
/* 83EC 8002CFEC AFBF0050 */  sw        $ra, 0x50($sp)
/* 83F0 8002CFF0 0C019560 */  jal       osCreateMesgQueue
/* 83F4 8002CFF4 AFB1004C */   sw       $s1, 0x4c($sp)
/* 83F8 8002CFF8 27A40010 */  addiu     $a0, $sp, 0x10
/* 83FC 8002CFFC 0200282D */  daddu     $a1, $s0, $zero
/* 8400 8002D000 0C017B8C */  jal       nuScAddClient
/* 8404 8002D004 24060001 */   addiu    $a2, $zero, 1
.L8002D008:
/* 8408 8002D008 3C04800E */  lui       $a0, %hi(D_800D91F8)
/* 840C 8002D00C 248491F8 */  addiu     $a0, $a0, %lo(D_800D91F8)
/* 8410 8002D010 27A50040 */  addiu     $a1, $sp, 0x40
/* 8414 8002D014 0C0195BC */  jal       osRecvMesg
/* 8418 8002D018 24060001 */   addiu    $a2, $zero, 1
/* 841C 8002D01C 8FA40040 */  lw        $a0, 0x40($sp)
/* 8420 8002D020 3C108007 */  lui       $s0, %hi(D_80077400)
/* 8424 8002D024 26107400 */  addiu     $s0, $s0, %lo(D_80077400)
/* 8428 8002D028 84830000 */  lh        $v1, ($a0)
/* 842C 8002D02C 24020001 */  addiu     $v0, $zero, 1
/* 8430 8002D030 10620005 */  beq       $v1, $v0, .L8002D048
/* 8434 8002D034 24027F00 */   addiu    $v0, $zero, 0x7f00
/* 8438 8002D038 10620016 */  beq       $v1, $v0, .L8002D094
/* 843C 8002D03C 0000282D */   daddu    $a1, $zero, $zero
/* 8440 8002D040 0800B432 */  j         .L8002D0C8
/* 8444 8002D044 00000000 */   nop
.L8002D048:
/* 8448 8002D048 8E020000 */  lw        $v0, ($s0)
/* 844C 8002D04C 1040FFEE */  beqz      $v0, .L8002D008
/* 8450 8002D050 00000000 */   nop
.L8002D054:
/* 8454 8002D054 8E020000 */  lw        $v0, ($s0)
/* 8458 8002D058 8C420004 */  lw        $v0, 4($v0)
/* 845C 8002D05C 8C420000 */  lw        $v0, ($v0)
/* 8460 8002D060 10400004 */  beqz      $v0, .L8002D074
/* 8464 8002D064 00000000 */   nop
/* 8468 8002D068 0040F809 */  jalr      $v0
/* 846C 8002D06C 8FA40040 */   lw       $a0, 0x40($sp)
/* 8470 8002D070 0040882D */  daddu     $s1, $v0, $zero
.L8002D074:
/* 8474 8002D074 1620FFE4 */  bnez      $s1, .L8002D008
/* 8478 8002D078 00000000 */   nop
/* 847C 8002D07C 8E100000 */  lw        $s0, ($s0)
/* 8480 8002D080 8E020000 */  lw        $v0, ($s0)
/* 8484 8002D084 1440FFF3 */  bnez      $v0, .L8002D054
/* 8488 8002D088 00000000 */   nop
/* 848C 8002D08C 0800B402 */  j         .L8002D008
/* 8490 8002D090 00000000 */   nop
.L8002D094:
/* 8494 8002D094 8C840004 */  lw        $a0, 4($a0)
/* 8498 8002D098 0C019608 */  jal       osSendMesg
/* 849C 8002D09C 24060001 */   addiu    $a2, $zero, 1
/* 84A0 8002D0A0 27A40010 */  addiu     $a0, $sp, 0x10
/* 84A4 8002D0A4 0C017BCE */  jal       nuScResetClientMesgType
/* 84A8 8002D0A8 0000282D */   daddu    $a1, $zero, $zero
/* 84AC 8002D0AC 0C019850 */  jal       osStopThread
/* 84B0 8002D0B0 0000202D */   daddu    $a0, $zero, $zero
/* 84B4 8002D0B4 27A40010 */  addiu     $a0, $sp, 0x10
/* 84B8 8002D0B8 0C017BCE */  jal       nuScResetClientMesgType
/* 84BC 8002D0BC 24050001 */   addiu    $a1, $zero, 1
/* 84C0 8002D0C0 0800B402 */  j         .L8002D008
/* 84C4 8002D0C4 00000000 */   nop
.L8002D0C8:
/* 84C8 8002D0C8 8FA20040 */  lw        $v0, 0x40($sp)
/* 84CC 8002D0CC 94420000 */  lhu       $v0, ($v0)
/* 84D0 8002D0D0 8E030000 */  lw        $v1, ($s0)
/* 84D4 8002D0D4 3044FF00 */  andi      $a0, $v0, 0xff00
/* 84D8 8002D0D8 1060FFCB */  beqz      $v1, .L8002D008
/* 84DC 8002D0DC 304200FF */   andi     $v0, $v0, 0xff
/* 84E0 8002D0E0 3085FFFF */  andi      $a1, $a0, 0xffff
/* 84E4 8002D0E4 3044FFFF */  andi      $a0, $v0, 0xffff
/* 84E8 8002D0E8 00043080 */  sll       $a2, $a0, 2
.L8002D0EC:
/* 84EC 8002D0EC 8E030000 */  lw        $v1, ($s0)
/* 84F0 8002D0F0 94620008 */  lhu       $v0, 8($v1)
/* 84F4 8002D0F4 54450015 */  bnel      $v0, $a1, .L8002D14C
/* 84F8 8002D0F8 0060802D */   daddu    $s0, $v1, $zero
/* 84FC 8002D0FC 9062000A */  lbu       $v0, 0xa($v1)
/* 8500 8002D100 0082102B */  sltu      $v0, $a0, $v0
/* 8504 8002D104 10400009 */  beqz      $v0, .L8002D12C
/* 8508 8002D108 00000000 */   nop
/* 850C 8002D10C 8C620004 */  lw        $v0, 4($v1)
/* 8510 8002D110 8FA40040 */  lw        $a0, 0x40($sp)
/* 8514 8002D114 00C21021 */  addu      $v0, $a2, $v0
/* 8518 8002D118 8C420000 */  lw        $v0, ($v0)
/* 851C 8002D11C 0040F809 */  jalr      $v0
/* 8520 8002D120 00000000 */   nop
/* 8524 8002D124 8FA30040 */  lw        $v1, 0x40($sp)
/* 8528 8002D128 AC620008 */  sw        $v0, 8($v1)
.L8002D12C:
/* 852C 8002D12C 8FA20040 */  lw        $v0, 0x40($sp)
/* 8530 8002D130 8C440004 */  lw        $a0, 4($v0)
/* 8534 8002D134 1080FFB4 */  beqz      $a0, .L8002D008
/* 8538 8002D138 0000282D */   daddu    $a1, $zero, $zero
/* 853C 8002D13C 0C019608 */  jal       osSendMesg
/* 8540 8002D140 24060001 */   addiu    $a2, $zero, 1
/* 8544 8002D144 0800B402 */  j         .L8002D008
/* 8548 8002D148 00000000 */   nop
.L8002D14C:
/* 854C 8002D14C 8E020000 */  lw        $v0, ($s0)
/* 8550 8002D150 1440FFE6 */  bnez      $v0, .L8002D0EC
/* 8554 8002D154 00000000 */   nop
/* 8558 8002D158 0800B402 */  j         .L8002D008
/* 855C 8002D15C 00000000 */   nop
