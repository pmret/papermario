.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuPiReadRom
/* 03A890 8005F490 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 03A894 8005F494 AFB30054 */  sw    $s3, 0x54($sp)
/* 03A898 8005F498 0080982D */  daddu $s3, $a0, $zero
/* 03A89C 8005F49C AFB20050 */  sw    $s2, 0x50($sp)
/* 03A8A0 8005F4A0 00A0902D */  daddu $s2, $a1, $zero
/* 03A8A4 8005F4A4 AFB1004C */  sw    $s1, 0x4c($sp)
/* 03A8A8 8005F4A8 00C0882D */  daddu $s1, $a2, $zero
/* 03A8AC 8005F4AC AFB00048 */  sw    $s0, 0x48($sp)
/* 03A8B0 8005F4B0 27B00028 */  addiu $s0, $sp, 0x28
/* 03A8B4 8005F4B4 0200202D */  daddu $a0, $s0, $zero
/* 03A8B8 8005F4B8 27A50040 */  addiu $a1, $sp, 0x40
/* 03A8BC 8005F4BC AFBF0058 */  sw    $ra, 0x58($sp)
/* 03A8C0 8005F4C0 0C019560 */  jal   osCreateMesgQueue
/* 03A8C4 8005F4C4 24060001 */   addiu $a2, $zero, 1
/* 03A8C8 8005F4C8 0240202D */  daddu $a0, $s2, $zero
/* 03A8CC 8005F4CC 0220282D */  daddu $a1, $s1, $zero
/* 03A8D0 8005F4D0 A3A00012 */  sb    $zero, 0x12($sp)
/* 03A8D4 8005F4D4 0C0185C8 */  jal   osInvalDCache
/* 03A8D8 8005F4D8 AFB00014 */   sw    $s0, 0x14($sp)
/* 03A8DC 8005F4DC 0240202D */  daddu $a0, $s2, $zero
/* 03A8E0 8005F4E0 0C0185F4 */  jal   osInvalICache
/* 03A8E4 8005F4E4 0220282D */   daddu $a1, $s1, $zero
/* 03A8E8 8005F4E8 12200015 */  beqz  $s1, .L8005F540
/* 03A8EC 8005F4EC 00000000 */   nop   
.L8005F4F0:
/* 03A8F0 8005F4F0 2E224001 */  sltiu $v0, $s1, 0x4001
/* 03A8F4 8005F4F4 14400002 */  bnez  $v0, .L8005F500
/* 03A8F8 8005F4F8 0220802D */   daddu $s0, $s1, $zero
/* 03A8FC 8005F4FC 24104000 */  addiu $s0, $zero, 0x4000
.L8005F500:
/* 03A900 8005F500 27A50010 */  addiu $a1, $sp, 0x10
/* 03A904 8005F504 3C04800A */  lui   $a0, 0x800a
/* 03A908 8005F508 8C84A638 */  lw    $a0, -0x59c8($a0)
/* 03A90C 8005F50C 0000302D */  daddu $a2, $zero, $zero
/* 03A910 8005F510 AFB20018 */  sw    $s2, 0x18($sp)
/* 03A914 8005F514 AFB3001C */  sw    $s3, 0x1c($sp)
/* 03A918 8005F518 0C018388 */  jal   osEPiStartDma
/* 03A91C 8005F51C AFB00020 */   sw    $s0, 0x20($sp)
/* 03A920 8005F520 27A40028 */  addiu $a0, $sp, 0x28
/* 03A924 8005F524 27A50040 */  addiu $a1, $sp, 0x40
/* 03A928 8005F528 0C0195BC */  jal   osRecvMesg
/* 03A92C 8005F52C 24060001 */   addiu $a2, $zero, 1
/* 03A930 8005F530 02709821 */  addu  $s3, $s3, $s0
/* 03A934 8005F534 02308823 */  subu  $s1, $s1, $s0
/* 03A938 8005F538 1620FFED */  bnez  $s1, .L8005F4F0
/* 03A93C 8005F53C 02509021 */   addu  $s2, $s2, $s0
.L8005F540:
/* 03A940 8005F540 8FBF0058 */  lw    $ra, 0x58($sp)
/* 03A944 8005F544 8FB30054 */  lw    $s3, 0x54($sp)
/* 03A948 8005F548 8FB20050 */  lw    $s2, 0x50($sp)
/* 03A94C 8005F54C 8FB1004C */  lw    $s1, 0x4c($sp)
/* 03A950 8005F550 8FB00048 */  lw    $s0, 0x48($sp)
/* 03A954 8005F554 03E00008 */  jr    $ra
/* 03A958 8005F558 27BD0060 */   addiu $sp, $sp, 0x60

/* 03A95C 8005F55C 00000000 */  nop   
