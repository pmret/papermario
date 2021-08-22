.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuScExecuteAudio
/* 39FE0 8005EBE0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 39FE4 8005EBE4 AFB40028 */  sw        $s4, 0x28($sp)
/* 39FE8 8005EBE8 3C14800E */  lui       $s4, %hi(D_800DA444)
/* 39FEC 8005EBEC 2694A444 */  addiu     $s4, $s4, %lo(D_800DA444)
/* 39FF0 8005EBF0 AFB30024 */  sw        $s3, 0x24($sp)
/* 39FF4 8005EBF4 2693066C */  addiu     $s3, $s4, 0x66c
/* 39FF8 8005EBF8 AFB5002C */  sw        $s5, 0x2c($sp)
/* 39FFC 8005EBFC 269500A8 */  addiu     $s5, $s4, 0xa8
/* 3A000 8005EC00 AFB20020 */  sw        $s2, 0x20($sp)
/* 3A004 8005EC04 27B20014 */  addiu     $s2, $sp, 0x14
/* 3A008 8005EC08 AFBF0030 */  sw        $ra, 0x30($sp)
/* 3A00C 8005EC0C AFB1001C */  sw        $s1, 0x1c($sp)
/* 3A010 8005EC10 AFB00018 */  sw        $s0, 0x18($sp)
/* 3A014 8005EC14 0280202D */  daddu     $a0, $s4, $zero
.L8005EC18:
/* 3A018 8005EC18 27A50010 */  addiu     $a1, $sp, 0x10
/* 3A01C 8005EC1C 0C0195BC */  jal       osRecvMesg
/* 3A020 8005EC20 24060001 */   addiu    $a2, $zero, 1
/* 3A024 8005EC24 3C02800A */  lui       $v0, %hi(nuScPreNMIFlag)
/* 3A028 8005EC28 9042A5B0 */  lbu       $v0, %lo(nuScPreNMIFlag)($v0)
/* 3A02C 8005EC2C 30420002 */  andi      $v0, $v0, 2
/* 3A030 8005EC30 14400031 */  bnez      $v0, .L8005ECF8
/* 3A034 8005EC34 00000000 */   nop
/* 3A038 8005EC38 0C018634 */  jal       osWritebackDCacheAll
/* 3A03C 8005EC3C 0000802D */   daddu    $s0, $zero, $zero
/* 3A040 8005EC40 8E910668 */  lw        $s1, 0x668($s4)
/* 3A044 8005EC44 1220000B */  beqz      $s1, .L8005EC74
/* 3A048 8005EC48 00000000 */   nop
/* 3A04C 8005EC4C 0C019714 */  jal       osSpTaskYield
/* 3A050 8005EC50 24100002 */   addiu    $s0, $zero, 2
/* 3A054 8005EC54 268400A8 */  addiu     $a0, $s4, 0xa8
/* 3A058 8005EC58 27A50014 */  addiu     $a1, $sp, 0x14
/* 3A05C 8005EC5C 0C0195BC */  jal       osRecvMesg
/* 3A060 8005EC60 24060001 */   addiu    $a2, $zero, 1
/* 3A064 8005EC64 0C01971C */  jal       osSpTaskYielded
/* 3A068 8005EC68 26240010 */   addiu    $a0, $s1, 0x10
/* 3A06C 8005EC6C 54400001 */  bnel      $v0, $zero, .L8005EC74
/* 3A070 8005EC70 24100001 */   addiu    $s0, $zero, 1
.L8005EC74:
/* 3A074 8005EC74 8FA20010 */  lw        $v0, 0x10($sp)
/* 3A078 8005EC78 24440010 */  addiu     $a0, $v0, 0x10
/* 3A07C 8005EC7C 0C019684 */  jal       osSpTaskLoad
/* 3A080 8005EC80 AE620000 */   sw       $v0, ($s3)
/* 3A084 8005EC84 8FA40010 */  lw        $a0, 0x10($sp)
/* 3A088 8005EC88 0C019707 */  jal       osSpTaskStartGo
/* 3A08C 8005EC8C 24840010 */   addiu    $a0, $a0, 0x10
/* 3A090 8005EC90 02A0202D */  daddu     $a0, $s5, $zero
/* 3A094 8005EC94 0240282D */  daddu     $a1, $s2, $zero
/* 3A098 8005EC98 0C0195BC */  jal       osRecvMesg
/* 3A09C 8005EC9C 24060001 */   addiu    $a2, $zero, 1
/* 3A0A0 8005ECA0 8E620004 */  lw        $v0, 4($s3)
/* 3A0A4 8005ECA4 10400005 */  beqz      $v0, .L8005ECBC
/* 3A0A8 8005ECA8 AE600000 */   sw       $zero, ($s3)
/* 3A0AC 8005ECAC 2664FAAC */  addiu     $a0, $s3, -0x554
/* 3A0B0 8005ECB0 0240282D */  daddu     $a1, $s2, $zero
/* 3A0B4 8005ECB4 0C019608 */  jal       osSendMesg
/* 3A0B8 8005ECB8 24060001 */   addiu    $a2, $zero, 1
.L8005ECBC:
/* 3A0BC 8005ECBC 24020001 */  addiu     $v0, $zero, 1
/* 3A0C0 8005ECC0 16020008 */  bne       $s0, $v0, .L8005ECE4
/* 3A0C4 8005ECC4 24020002 */   addiu    $v0, $zero, 2
/* 3A0C8 8005ECC8 26300010 */  addiu     $s0, $s1, 0x10
/* 3A0CC 8005ECCC 0C019684 */  jal       osSpTaskLoad
/* 3A0D0 8005ECD0 0200202D */   daddu    $a0, $s0, $zero
/* 3A0D4 8005ECD4 0C019707 */  jal       osSpTaskStartGo
/* 3A0D8 8005ECD8 0200202D */   daddu    $a0, $s0, $zero
/* 3A0DC 8005ECDC 08017B3E */  j         .L8005ECF8
/* 3A0E0 8005ECE0 00000000 */   nop
.L8005ECE4:
/* 3A0E4 8005ECE4 16020004 */  bne       $s0, $v0, .L8005ECF8
/* 3A0E8 8005ECE8 02A0202D */   daddu    $a0, $s5, $zero
/* 3A0EC 8005ECEC 0240282D */  daddu     $a1, $s2, $zero
/* 3A0F0 8005ECF0 0C019608 */  jal       osSendMesg
/* 3A0F4 8005ECF4 24060001 */   addiu    $a2, $zero, 1
.L8005ECF8:
/* 3A0F8 8005ECF8 8FA20010 */  lw        $v0, 0x10($sp)
/* 3A0FC 8005ECFC 8C440050 */  lw        $a0, 0x50($v0)
/* 3A100 8005ED00 8C450054 */  lw        $a1, 0x54($v0)
/* 3A104 8005ED04 0C019608 */  jal       osSendMesg
/* 3A108 8005ED08 24060001 */   addiu    $a2, $zero, 1
/* 3A10C 8005ED0C 08017B06 */  j         .L8005EC18
/* 3A110 8005ED10 0280202D */   daddu    $a0, $s4, $zero
