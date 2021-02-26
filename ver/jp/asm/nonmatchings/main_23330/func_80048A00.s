.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80048A00
/* 23E00 80048A00 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 23E04 80048A04 AFB20018 */  sw        $s2, 0x18($sp)
/* 23E08 80048A08 0080902D */  daddu     $s2, $a0, $zero
/* 23E0C 80048A0C AFBF001C */  sw        $ra, 0x1c($sp)
/* 23E10 80048A10 AFB10014 */  sw        $s1, 0x14($sp)
/* 23E14 80048A14 AFB00010 */  sw        $s0, 0x10($sp)
/* 23E18 80048A18 8E4200D4 */  lw        $v0, 0xd4($s2)
/* 23E1C 80048A1C 3C11800B */  lui       $s1, %hi(D_800B0EF0)
/* 23E20 80048A20 26310EF0 */  addiu     $s1, $s1, %lo(D_800B0EF0)
/* 23E24 80048A24 845000B2 */  lh        $s0, 0xb2($v0)
/* 23E28 80048A28 844300B4 */  lh        $v1, 0xb4($v0)
/* 23E2C 80048A2C 0070102A */  slt       $v0, $v1, $s0
/* 23E30 80048A30 10400003 */  beqz      $v0, .L80048A40
/* 23E34 80048A34 0200202D */   daddu    $a0, $s0, $zero
/* 23E38 80048A38 0060802D */  daddu     $s0, $v1, $zero
/* 23E3C 80048A3C 0080182D */  daddu     $v1, $a0, $zero
.L80048A40:
/* 23E40 80048A40 06000003 */  bltz      $s0, .L80048A50
/* 23E44 80048A44 00702023 */   subu     $a0, $v1, $s0
/* 23E48 80048A48 10800004 */  beqz      $a0, .L80048A5C
/* 23E4C 80048A4C 00000000 */   nop
.L80048A50:
/* 23E50 80048A50 0C00A66F */  jal       func_800299BC
/* 23E54 80048A54 00000000 */   nop
/* 23E58 80048A58 00508021 */  addu      $s0, $v0, $s0
.L80048A5C:
/* 23E5C 80048A5C 06020001 */  bltzl     $s0, .L80048A64
/* 23E60 80048A60 0000802D */   daddu    $s0, $zero, $zero
.L80048A64:
/* 23E64 80048A64 0C03A73A */  jal       func_800E9CE8
/* 23E68 80048A68 24040019 */   addiu    $a0, $zero, 0x19
/* 23E6C 80048A6C 10400004 */  beqz      $v0, .L80048A80
/* 23E70 80048A70 00000000 */   nop
/* 23E74 80048A74 9222000C */  lbu       $v0, 0xc($s1)
/* 23E78 80048A78 00021042 */  srl       $v0, $v0, 1
/* 23E7C 80048A7C 02028021 */  addu      $s0, $s0, $v0
.L80048A80:
/* 23E80 80048A80 8222000B */  lb        $v0, 0xb($s1)
/* 23E84 80048A84 10400002 */  beqz      $v0, .L80048A90
/* 23E88 80048A88 00101040 */   sll      $v0, $s0, 1
/* 23E8C 80048A8C 02028021 */  addu      $s0, $s0, $v0
.L80048A90:
/* 23E90 80048A90 0C03A73A */  jal       func_800E9CE8
/* 23E94 80048A94 24040010 */   addiu    $a0, $zero, 0x10
/* 23E98 80048A98 54400001 */  bnel      $v0, $zero, .L80048AA0
/* 23E9C 80048A9C 00108040 */   sll      $s0, $s0, 1
.L80048AA0:
/* 23EA0 80048AA0 8622000E */  lh        $v0, 0xe($s1)
/* 23EA4 80048AA4 02028021 */  addu      $s0, $s0, $v0
/* 23EA8 80048AA8 8E420000 */  lw        $v0, ($s2)
/* 23EAC 80048AAC 3C030084 */  lui       $v1, 0x84
/* 23EB0 80048AB0 00431024 */  and       $v0, $v0, $v1
/* 23EB4 80048AB4 54400001 */  bnel      $v0, $zero, .L80048ABC
/* 23EB8 80048AB8 0000802D */   daddu    $s0, $zero, $zero
.L80048ABC:
/* 23EBC 80048ABC 2A020015 */  slti      $v0, $s0, 0x15
/* 23EC0 80048AC0 50400001 */  beql      $v0, $zero, .L80048AC8
/* 23EC4 80048AC4 24100014 */   addiu    $s0, $zero, 0x14
.L80048AC8:
/* 23EC8 80048AC8 0200102D */  daddu     $v0, $s0, $zero
/* 23ECC 80048ACC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 23ED0 80048AD0 8FB20018 */  lw        $s2, 0x18($sp)
/* 23ED4 80048AD4 8FB10014 */  lw        $s1, 0x14($sp)
/* 23ED8 80048AD8 8FB00010 */  lw        $s0, 0x10($sp)
/* 23EDC 80048ADC 03E00008 */  jr        $ra
/* 23EE0 80048AE0 27BD0020 */   addiu    $sp, $sp, 0x20
