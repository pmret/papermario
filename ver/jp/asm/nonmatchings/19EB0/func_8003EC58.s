.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003EC58
/* 1A058 8003EC58 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A05C 8003EC5C AFB00010 */  sw        $s0, 0x10($sp)
/* 1A060 8003EC60 0080802D */  daddu     $s0, $a0, $zero
/* 1A064 8003EC64 10A00003 */  beqz      $a1, .L8003EC74
/* 1A068 8003EC68 AFBF0014 */   sw       $ra, 0x14($sp)
/* 1A06C 8003EC6C 24020019 */  addiu     $v0, $zero, 0x19
/* 1A070 8003EC70 AE020070 */  sw        $v0, 0x70($s0)
.L8003EC74:
/* 1A074 8003EC74 0000202D */  daddu     $a0, $zero, $zero
/* 1A078 8003EC78 0080282D */  daddu     $a1, $a0, $zero
/* 1A07C 8003EC7C 8E020070 */  lw        $v0, 0x70($s0)
/* 1A080 8003EC80 0080302D */  daddu     $a2, $a0, $zero
/* 1A084 8003EC84 00023880 */  sll       $a3, $v0, 2
/* 1A088 8003EC88 00E23821 */  addu      $a3, $a3, $v0
/* 1A08C 8003EC8C 00073840 */  sll       $a3, $a3, 1
/* 1A090 8003EC90 0C04841B */  jal       func_8012106C
/* 1A094 8003EC94 30E700FE */   andi     $a3, $a3, 0xfe
/* 1A098 8003EC98 8E020070 */  lw        $v0, 0x70($s0)
/* 1A09C 8003EC9C 2442FFFB */  addiu     $v0, $v0, -5
/* 1A0A0 8003ECA0 10400003 */  beqz      $v0, .L8003ECB0
/* 1A0A4 8003ECA4 AE020070 */   sw       $v0, 0x70($s0)
/* 1A0A8 8003ECA8 0800FB32 */  j         .L8003ECC8
/* 1A0AC 8003ECAC 0000102D */   daddu    $v0, $zero, $zero
.L8003ECB0:
/* 1A0B0 8003ECB0 0000202D */  daddu     $a0, $zero, $zero
/* 1A0B4 8003ECB4 0080282D */  daddu     $a1, $a0, $zero
/* 1A0B8 8003ECB8 0080302D */  daddu     $a2, $a0, $zero
/* 1A0BC 8003ECBC 0C04841B */  jal       func_8012106C
/* 1A0C0 8003ECC0 0080382D */   daddu    $a3, $a0, $zero
/* 1A0C4 8003ECC4 24020002 */  addiu     $v0, $zero, 2
.L8003ECC8:
/* 1A0C8 8003ECC8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1A0CC 8003ECCC 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A0D0 8003ECD0 03E00008 */  jr        $ra
/* 1A0D4 8003ECD4 27BD0018 */   addiu    $sp, $sp, 0x18
