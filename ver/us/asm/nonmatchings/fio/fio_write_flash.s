.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fio_write_flash
/* 6D48 8002B948 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 6D4C 8002B94C AFB5005C */  sw        $s5, 0x5c($sp)
/* 6D50 8002B950 0080A82D */  daddu     $s5, $a0, $zero
/* 6D54 8002B954 AFB20050 */  sw        $s2, 0x50($sp)
/* 6D58 8002B958 00A0902D */  daddu     $s2, $a1, $zero
/* 6D5C 8002B95C AFB1004C */  sw        $s1, 0x4c($sp)
/* 6D60 8002B960 00C0882D */  daddu     $s1, $a2, $zero
/* 6D64 8002B964 0240202D */  daddu     $a0, $s2, $zero
/* 6D68 8002B968 0220282D */  daddu     $a1, $s1, $zero
/* 6D6C 8002B96C AFBF0060 */  sw        $ra, 0x60($sp)
/* 6D70 8002B970 AFB40058 */  sw        $s4, 0x58($sp)
/* 6D74 8002B974 AFB30054 */  sw        $s3, 0x54($sp)
/* 6D78 8002B978 0C018614 */  jal       osWritebackDCache
/* 6D7C 8002B97C AFB00048 */   sw       $s0, 0x48($sp)
/* 6D80 8002B980 27B00028 */  addiu     $s0, $sp, 0x28
/* 6D84 8002B984 0200202D */  daddu     $a0, $s0, $zero
/* 6D88 8002B988 27A50040 */  addiu     $a1, $sp, 0x40
/* 6D8C 8002B98C 0C019560 */  jal       osCreateMesgQueue
/* 6D90 8002B990 24060001 */   addiu    $a2, $zero, 1
/* 6D94 8002B994 12200017 */  beqz      $s1, .L8002B9F4
/* 6D98 8002B998 0000982D */   daddu    $s3, $zero, $zero
/* 6D9C 8002B99C 0200A02D */  daddu     $s4, $s0, $zero
/* 6DA0 8002B9A0 0015A9C0 */  sll       $s5, $s5, 7
.L8002B9A4:
/* 6DA4 8002B9A4 2E220081 */  sltiu     $v0, $s1, 0x81
/* 6DA8 8002B9A8 14400002 */  bnez      $v0, .L8002B9B4
/* 6DAC 8002B9AC 0220802D */   daddu    $s0, $s1, $zero
/* 6DB0 8002B9B0 24100080 */  addiu     $s0, $zero, 0x80
.L8002B9B4:
/* 6DB4 8002B9B4 27A40010 */  addiu     $a0, $sp, 0x10
/* 6DB8 8002B9B8 0000282D */  daddu     $a1, $zero, $zero
/* 6DBC 8002B9BC 0240302D */  daddu     $a2, $s2, $zero
/* 6DC0 8002B9C0 0C01BD54 */  jal       osFlashWriteBuffer
/* 6DC4 8002B9C4 0280382D */   daddu    $a3, $s4, $zero
/* 6DC8 8002B9C8 3264FFFF */  andi      $a0, $s3, 0xffff
/* 6DCC 8002B9CC 0C01BD87 */  jal       osFlashWriteArray
/* 6DD0 8002B9D0 02A42021 */   addu     $a0, $s5, $a0
/* 6DD4 8002B9D4 0280202D */  daddu     $a0, $s4, $zero
/* 6DD8 8002B9D8 0000282D */  daddu     $a1, $zero, $zero
/* 6DDC 8002B9DC 0C0195BC */  jal       osRecvMesg
/* 6DE0 8002B9E0 24060001 */   addiu    $a2, $zero, 1
/* 6DE4 8002B9E4 26730001 */  addiu     $s3, $s3, 1
/* 6DE8 8002B9E8 02308823 */  subu      $s1, $s1, $s0
/* 6DEC 8002B9EC 1620FFED */  bnez      $s1, .L8002B9A4
/* 6DF0 8002B9F0 02509021 */   addu     $s2, $s2, $s0
.L8002B9F4:
/* 6DF4 8002B9F4 8FBF0060 */  lw        $ra, 0x60($sp)
/* 6DF8 8002B9F8 8FB5005C */  lw        $s5, 0x5c($sp)
/* 6DFC 8002B9FC 8FB40058 */  lw        $s4, 0x58($sp)
/* 6E00 8002BA00 8FB30054 */  lw        $s3, 0x54($sp)
/* 6E04 8002BA04 8FB20050 */  lw        $s2, 0x50($sp)
/* 6E08 8002BA08 8FB1004C */  lw        $s1, 0x4c($sp)
/* 6E0C 8002BA0C 8FB00048 */  lw        $s0, 0x48($sp)
/* 6E10 8002BA10 24020001 */  addiu     $v0, $zero, 1
/* 6E14 8002BA14 03E00008 */  jr        $ra
/* 6E18 8002BA18 27BD0068 */   addiu    $sp, $sp, 0x68
