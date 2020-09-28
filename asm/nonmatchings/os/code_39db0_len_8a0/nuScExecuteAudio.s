.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuScExecuteAudio
/* 39FE0 8005EBE0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 39FE4 8005EBE4 AFB40028 */  sw        $s4, 0x28($sp)
/* 39FE8 8005EBE8 3C14800E */  lui       $s4, 0x800e
/* 39FEC 8005EBEC 2694A444 */  addiu     $s4, $s4, -0x5bbc
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
/* 3A024 8005EC24 3C02800A */  lui       $v0, 0x800a
/* 3A028 8005EC28 9042A5B0 */  lbu       $v0, -0x5a50($v0)
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
/* 3A114 8005ED14 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3A118 8005ED18 AFB00018 */  sw        $s0, 0x18($sp)
/* 3A11C 8005ED1C 3C10800E */  lui       $s0, 0x800e
/* 3A120 8005ED20 2610A47C */  addiu     $s0, $s0, -0x5b84
/* 3A124 8005ED24 AFB1001C */  sw        $s1, 0x1c($sp)
/* 3A128 8005ED28 27B10014 */  addiu     $s1, $sp, 0x14
/* 3A12C 8005ED2C AFBF0020 */  sw        $ra, 0x20($sp)
/* 3A130 8005ED30 0200202D */  daddu     $a0, $s0, $zero
.L8005ED34:
/* 3A134 8005ED34 27A50010 */  addiu     $a1, $sp, 0x10
/* 3A138 8005ED38 0C0195BC */  jal       osRecvMesg
/* 3A13C 8005ED3C 24060001 */   addiu    $a2, $zero, 1
/* 3A140 8005ED40 3C02800A */  lui       $v0, 0x800a
/* 3A144 8005ED44 9042A5B0 */  lbu       $v0, -0x5a50($v0)
/* 3A148 8005ED48 30420002 */  andi      $v0, $v0, 2
/* 3A14C 8005ED4C 14400032 */  bnez      $v0, .L8005EE18
/* 3A150 8005ED50 00000000 */   nop      
/* 3A154 8005ED54 0C017C48 */  jal       nuScWaitTaskReady
/* 3A158 8005ED58 8FA40010 */   lw       $a0, 0x10($sp)
/* 3A15C 8005ED5C 0C018250 */  jal       osSetIntMask
/* 3A160 8005ED60 24040001 */   addiu    $a0, $zero, 1
/* 3A164 8005ED64 8E030634 */  lw        $v1, 0x634($s0)
/* 3A168 8005ED68 1060000C */  beqz      $v1, .L8005ED9C
/* 3A16C 8005ED6C 0040202D */   daddu    $a0, $v0, $zero
/* 3A170 8005ED70 8FA20010 */  lw        $v0, 0x10($sp)
/* 3A174 8005ED74 0C018250 */  jal       osSetIntMask
/* 3A178 8005ED78 AE020638 */   sw       $v0, 0x638($s0)
/* 3A17C 8005ED7C 260400E0 */  addiu     $a0, $s0, 0xe0
/* 3A180 8005ED80 27A50014 */  addiu     $a1, $sp, 0x14
/* 3A184 8005ED84 0C0195BC */  jal       osRecvMesg
/* 3A188 8005ED88 24060001 */   addiu    $a2, $zero, 1
/* 3A18C 8005ED8C 0C018250 */  jal       osSetIntMask
/* 3A190 8005ED90 24040001 */   addiu    $a0, $zero, 1
/* 3A194 8005ED94 0040202D */  daddu     $a0, $v0, $zero
/* 3A198 8005ED98 AE000638 */  sw        $zero, 0x638($s0)
.L8005ED9C:
/* 3A19C 8005ED9C 0C018250 */  jal       osSetIntMask
/* 3A1A0 8005EDA0 00000000 */   nop      
/* 3A1A4 8005EDA4 0C018250 */  jal       osSetIntMask
/* 3A1A8 8005EDA8 24040001 */   addiu    $a0, $zero, 1
/* 3A1AC 8005EDAC 8FA30010 */  lw        $v1, 0x10($sp)
/* 3A1B0 8005EDB0 0040202D */  daddu     $a0, $v0, $zero
/* 3A1B4 8005EDB4 0C018250 */  jal       osSetIntMask
/* 3A1B8 8005EDB8 AE030630 */   sw       $v1, 0x630($s0)
/* 3A1BC 8005EDBC 8FA40010 */  lw        $a0, 0x10($sp)
/* 3A1C0 8005EDC0 0C019684 */  jal       osSpTaskLoad
/* 3A1C4 8005EDC4 24840010 */   addiu    $a0, $a0, 0x10
/* 3A1C8 8005EDC8 8FA40010 */  lw        $a0, 0x10($sp)
/* 3A1CC 8005EDCC 0C019707 */  jal       osSpTaskStartGo
/* 3A1D0 8005EDD0 24840010 */   addiu    $a0, $a0, 0x10
/* 3A1D4 8005EDD4 26040070 */  addiu     $a0, $s0, 0x70
/* 3A1D8 8005EDD8 0220282D */  daddu     $a1, $s1, $zero
/* 3A1DC 8005EDDC 0C0195BC */  jal       osRecvMesg
/* 3A1E0 8005EDE0 24060001 */   addiu    $a2, $zero, 1
/* 3A1E4 8005EDE4 0C018250 */  jal       osSetIntMask
/* 3A1E8 8005EDE8 24040001 */   addiu    $a0, $zero, 1
/* 3A1EC 8005EDEC 0040202D */  daddu     $a0, $v0, $zero
/* 3A1F0 8005EDF0 0C018250 */  jal       osSetIntMask
/* 3A1F4 8005EDF4 AE000630 */   sw       $zero, 0x630($s0)
/* 3A1F8 8005EDF8 8FA20010 */  lw        $v0, 0x10($sp)
/* 3A1FC 8005EDFC 8C420008 */  lw        $v0, 8($v0)
/* 3A200 8005EE00 30420002 */  andi      $v0, $v0, 2
/* 3A204 8005EE04 14400004 */  bnez      $v0, .L8005EE18
/* 3A208 8005EE08 260400A8 */   addiu    $a0, $s0, 0xa8
/* 3A20C 8005EE0C 0220282D */  daddu     $a1, $s1, $zero
/* 3A210 8005EE10 0C0195BC */  jal       osRecvMesg
/* 3A214 8005EE14 24060001 */   addiu    $a2, $zero, 1
.L8005EE18:
/* 3A218 8005EE18 8FA50010 */  lw        $a1, 0x10($sp)
/* 3A21C 8005EE1C 8CA40050 */  lw        $a0, 0x50($a1)
/* 3A220 8005EE20 0C019608 */  jal       osSendMesg
/* 3A224 8005EE24 24060001 */   addiu    $a2, $zero, 1
/* 3A228 8005EE28 08017B4D */  j         .L8005ED34
/* 3A22C 8005EE2C 0200202D */   daddu    $a0, $s0, $zero
