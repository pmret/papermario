.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005EC58
/* 3A058 8005EC58 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 3A05C 8005EC5C AFB1001C */  sw        $s1, 0x1c($sp)
/* 3A060 8005EC60 3C11800E */  lui       $s1, %hi(D_800DA494)
/* 3A064 8005EC64 2631A494 */  addiu     $s1, $s1, %lo(D_800DA494)
/* 3A068 8005EC68 AFB40028 */  sw        $s4, 0x28($sp)
/* 3A06C 8005EC6C 2414029A */  addiu     $s4, $zero, 0x29a
/* 3A070 8005EC70 AFB30024 */  sw        $s3, 0x24($sp)
/* 3A074 8005EC74 2413029D */  addiu     $s3, $zero, 0x29d
/* 3A078 8005EC78 AFB20020 */  sw        $s2, 0x20($sp)
/* 3A07C 8005EC7C 24120001 */  addiu     $s2, $zero, 1
/* 3A080 8005EC80 AFBF002C */  sw        $ra, 0x2c($sp)
/* 3A084 8005EC84 AFB00018 */  sw        $s0, 0x18($sp)
/* 3A088 8005EC88 3C018009 */  lui       $at, %hi(D_80093B64)
/* 3A08C 8005EC8C AC203B64 */  sw        $zero, %lo(D_80093B64)($at)
.L8005EC90:
/* 3A090 8005EC90 0220202D */  daddu     $a0, $s1, $zero
.L8005EC94:
/* 3A094 8005EC94 27A50010 */  addiu     $a1, $sp, 0x10
.L8005EC98:
/* 3A098 8005EC98 0C0195B0 */  jal       func_800656C0
/* 3A09C 8005EC9C 24060001 */   addiu    $a2, $zero, 1
/* 3A0A0 8005ECA0 8FA20010 */  lw        $v0, 0x10($sp)
/* 3A0A4 8005ECA4 10540005 */  beq       $v0, $s4, .L8005ECBC
/* 3A0A8 8005ECA8 00000000 */   nop
/* 3A0AC 8005ECAC 1053001D */  beq       $v0, $s3, .L8005ED24
/* 3A0B0 8005ECB0 0220202D */   daddu    $a0, $s1, $zero
/* 3A0B4 8005ECB4 08017B26 */  j         .L8005EC98
/* 3A0B8 8005ECB8 27A50010 */   addiu    $a1, $sp, 0x10
.L8005ECBC:
/* 3A0BC 8005ECBC 3C028009 */  lui       $v0, %hi(D_80093B64)
/* 3A0C0 8005ECC0 8C423B64 */  lw        $v0, %lo(D_80093B64)($v0)
/* 3A0C4 8005ECC4 24420001 */  addiu     $v0, $v0, 1
/* 3A0C8 8005ECC8 3C018009 */  lui       $at, %hi(D_80093B64)
/* 3A0CC 8005ECCC AC223B64 */  sw        $v0, %lo(D_80093B64)($at)
/* 3A0D0 8005ECD0 0C017B5C */  jal       func_8005ED70
/* 3A0D4 8005ECD4 2624FF8C */   addiu    $a0, $s1, -0x74
/* 3A0D8 8005ECD8 3C02800A */  lui       $v0, %hi(D_8009A590)
/* 3A0DC 8005ECDC 9042A590 */  lbu       $v0, %lo(D_8009A590)($v0)
/* 3A0E0 8005ECE0 1040FFEC */  beqz      $v0, .L8005EC94
/* 3A0E4 8005ECE4 0220202D */   daddu    $a0, $s1, $zero
/* 3A0E8 8005ECE8 12000003 */  beqz      $s0, .L8005ECF8
/* 3A0EC 8005ECEC 34420002 */   ori      $v0, $v0, 2
/* 3A0F0 8005ECF0 08017B25 */  j         .L8005EC94
/* 3A0F4 8005ECF4 2610FFFF */   addiu    $s0, $s0, -1
.L8005ECF8:
/* 3A0F8 8005ECF8 3C01800A */  lui       $at, %hi(D_8009A590)
/* 3A0FC 8005ECFC 0C01A984 */  jal       func_8006A610
/* 3A100 8005ED00 A022A590 */   sb       $v0, %lo(D_8009A590)($at)
/* 3A104 8005ED04 3C013F80 */  lui       $at, 0x3f80
/* 3A108 8005ED08 44816000 */  mtc1      $at, $f12
/* 3A10C 8005ED0C 0C019BE8 */  jal       func_80066FA0
/* 3A110 8005ED10 00000000 */   nop
/* 3A114 8005ED14 0C019CD4 */  jal       func_80067350
/* 3A118 8005ED18 24040001 */   addiu    $a0, $zero, 1
/* 3A11C 8005ED1C 08017B25 */  j         .L8005EC94
/* 3A120 8005ED20 0220202D */   daddu    $a0, $s1, $zero
.L8005ED24:
/* 3A124 8005ED24 3C01800A */  lui       $at, %hi(D_8009A590)
/* 3A128 8005ED28 A032A590 */  sb        $s2, %lo(D_8009A590)($at)
/* 3A12C 8005ED2C 0C017B5C */  jal       func_8005ED70
/* 3A130 8005ED30 2624FF8E */   addiu    $a0, $s1, -0x72
/* 3A134 8005ED34 3C028009 */  lui       $v0, %hi(D_80093B50)
/* 3A138 8005ED38 8C423B50 */  lw        $v0, %lo(D_80093B50)($v0)
/* 3A13C 8005ED3C 10400003 */  beqz      $v0, .L8005ED4C
/* 3A140 8005ED40 00000000 */   nop
/* 3A144 8005ED44 0040F809 */  jalr      $v0
/* 3A148 8005ED48 00000000 */   nop
.L8005ED4C:
/* 3A14C 8005ED4C 92220608 */  lbu       $v0, 0x608($s1)
/* 3A150 8005ED50 8E230604 */  lw        $v1, 0x604($s1)
/* 3A154 8005ED54 00021042 */  srl       $v0, $v0, 1
/* 3A158 8005ED58 14600002 */  bnez      $v1, .L8005ED64
/* 3A15C 8005ED5C 0043001B */   divu     $zero, $v0, $v1
/* 3A160 8005ED60 0007000D */  break     7
.L8005ED64:
/* 3A164 8005ED64 00001012 */   mflo     $v0
/* 3A168 8005ED68 08017B24 */  j         .L8005EC90
/* 3A16C 8005ED6C 2450FFFD */   addiu    $s0, $v0, -3
