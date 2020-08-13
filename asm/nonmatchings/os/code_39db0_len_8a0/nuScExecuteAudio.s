.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuScExecuteAudio
/* 039FE0 8005EBE0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 039FE4 8005EBE4 AFB40028 */  sw    $s4, 0x28($sp)
/* 039FE8 8005EBE8 3C14800E */  lui   $s4, 0x800e
/* 039FEC 8005EBEC 2694A444 */  addiu $s4, $s4, -0x5bbc
/* 039FF0 8005EBF0 AFB30024 */  sw    $s3, 0x24($sp)
/* 039FF4 8005EBF4 2693066C */  addiu $s3, $s4, 0x66c
/* 039FF8 8005EBF8 AFB5002C */  sw    $s5, 0x2c($sp)
/* 039FFC 8005EBFC 269500A8 */  addiu $s5, $s4, 0xa8
/* 03A000 8005EC00 AFB20020 */  sw    $s2, 0x20($sp)
/* 03A004 8005EC04 27B20014 */  addiu $s2, $sp, 0x14
/* 03A008 8005EC08 AFBF0030 */  sw    $ra, 0x30($sp)
/* 03A00C 8005EC0C AFB1001C */  sw    $s1, 0x1c($sp)
/* 03A010 8005EC10 AFB00018 */  sw    $s0, 0x18($sp)
/* 03A014 8005EC14 0280202D */  daddu $a0, $s4, $zero
.L8005EC18:
/* 03A018 8005EC18 27A50010 */  addiu $a1, $sp, 0x10
/* 03A01C 8005EC1C 0C0195BC */  jal   osRecvMesg
/* 03A020 8005EC20 24060001 */   addiu $a2, $zero, 1
/* 03A024 8005EC24 3C02800A */  lui   $v0, 0x800a
/* 03A028 8005EC28 9042A5B0 */  lbu   $v0, -0x5a50($v0)
/* 03A02C 8005EC2C 30420002 */  andi  $v0, $v0, 2
/* 03A030 8005EC30 14400031 */  bnez  $v0, .L8005ECF8
/* 03A034 8005EC34 00000000 */   nop   
/* 03A038 8005EC38 0C018634 */  jal   osWritebackDCacheAll
/* 03A03C 8005EC3C 0000802D */   daddu $s0, $zero, $zero
/* 03A040 8005EC40 8E910668 */  lw    $s1, 0x668($s4)
/* 03A044 8005EC44 1220000B */  beqz  $s1, .L8005EC74
/* 03A048 8005EC48 00000000 */   nop   
/* 03A04C 8005EC4C 0C019714 */  jal   osSpTaskYield
/* 03A050 8005EC50 24100002 */   addiu $s0, $zero, 2
/* 03A054 8005EC54 268400A8 */  addiu $a0, $s4, 0xa8
/* 03A058 8005EC58 27A50014 */  addiu $a1, $sp, 0x14
/* 03A05C 8005EC5C 0C0195BC */  jal   osRecvMesg
/* 03A060 8005EC60 24060001 */   addiu $a2, $zero, 1
/* 03A064 8005EC64 0C01971C */  jal   osSpTaskYielded
/* 03A068 8005EC68 26240010 */   addiu $a0, $s1, 0x10
/* 03A06C 8005EC6C 54400001 */  bnel  $v0, $zero, .L8005EC74
/* 03A070 8005EC70 24100001 */   addiu $s0, $zero, 1
.L8005EC74:
/* 03A074 8005EC74 8FA20010 */  lw    $v0, 0x10($sp)
/* 03A078 8005EC78 24440010 */  addiu $a0, $v0, 0x10
/* 03A07C 8005EC7C 0C019684 */  jal   osSpTaskLoad
/* 03A080 8005EC80 AE620000 */   sw    $v0, ($s3)
/* 03A084 8005EC84 8FA40010 */  lw    $a0, 0x10($sp)
/* 03A088 8005EC88 0C019707 */  jal   osSpTaskStartGo
/* 03A08C 8005EC8C 24840010 */   addiu $a0, $a0, 0x10
/* 03A090 8005EC90 02A0202D */  daddu $a0, $s5, $zero
/* 03A094 8005EC94 0240282D */  daddu $a1, $s2, $zero
/* 03A098 8005EC98 0C0195BC */  jal   osRecvMesg
/* 03A09C 8005EC9C 24060001 */   addiu $a2, $zero, 1
/* 03A0A0 8005ECA0 8E620004 */  lw    $v0, 4($s3)
/* 03A0A4 8005ECA4 10400005 */  beqz  $v0, .L8005ECBC
/* 03A0A8 8005ECA8 AE600000 */   sw    $zero, ($s3)
/* 03A0AC 8005ECAC 2664FAAC */  addiu $a0, $s3, -0x554
/* 03A0B0 8005ECB0 0240282D */  daddu $a1, $s2, $zero
/* 03A0B4 8005ECB4 0C019608 */  jal   osSendMesg
/* 03A0B8 8005ECB8 24060001 */   addiu $a2, $zero, 1
.L8005ECBC:
/* 03A0BC 8005ECBC 24020001 */  addiu $v0, $zero, 1
/* 03A0C0 8005ECC0 16020008 */  bne   $s0, $v0, .L8005ECE4
/* 03A0C4 8005ECC4 24020002 */   addiu $v0, $zero, 2
/* 03A0C8 8005ECC8 26300010 */  addiu $s0, $s1, 0x10
/* 03A0CC 8005ECCC 0C019684 */  jal   osSpTaskLoad
/* 03A0D0 8005ECD0 0200202D */   daddu $a0, $s0, $zero
/* 03A0D4 8005ECD4 0C019707 */  jal   osSpTaskStartGo
/* 03A0D8 8005ECD8 0200202D */   daddu $a0, $s0, $zero
/* 03A0DC 8005ECDC 08017B3E */  j     .L8005ECF8
/* 03A0E0 8005ECE0 00000000 */   nop   

.L8005ECE4:
/* 03A0E4 8005ECE4 16020004 */  bne   $s0, $v0, .L8005ECF8
/* 03A0E8 8005ECE8 02A0202D */   daddu $a0, $s5, $zero
/* 03A0EC 8005ECEC 0240282D */  daddu $a1, $s2, $zero
/* 03A0F0 8005ECF0 0C019608 */  jal   osSendMesg
/* 03A0F4 8005ECF4 24060001 */   addiu $a2, $zero, 1
.L8005ECF8:
/* 03A0F8 8005ECF8 8FA20010 */  lw    $v0, 0x10($sp)
/* 03A0FC 8005ECFC 8C440050 */  lw    $a0, 0x50($v0)
/* 03A100 8005ED00 8C450054 */  lw    $a1, 0x54($v0)
/* 03A104 8005ED04 0C019608 */  jal   osSendMesg
/* 03A108 8005ED08 24060001 */   addiu $a2, $zero, 1
/* 03A10C 8005ED0C 08017B06 */  j     .L8005EC18
/* 03A110 8005ED10 0280202D */   daddu $a0, $s4, $zero

