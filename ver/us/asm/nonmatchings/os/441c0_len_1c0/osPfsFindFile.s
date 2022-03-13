.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPfsFindFile
/* 441C0 80068DC0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 441C4 80068DC4 AFB30044 */  sw        $s3, 0x44($sp)
/* 441C8 80068DC8 8FB30070 */  lw        $s3, 0x70($sp)
/* 441CC 80068DCC AFB00038 */  sw        $s0, 0x38($sp)
/* 441D0 80068DD0 00808021 */  addu      $s0, $a0, $zero
/* 441D4 80068DD4 AFBE0058 */  sw        $fp, 0x58($sp)
/* 441D8 80068DD8 00C0F021 */  addu      $fp, $a2, $zero
/* 441DC 80068DDC AFB20040 */  sw        $s2, 0x40($sp)
/* 441E0 80068DE0 00E09021 */  addu      $s2, $a3, $zero
/* 441E4 80068DE4 AFBF005C */  sw        $ra, 0x5c($sp)
/* 441E8 80068DE8 AFB70054 */  sw        $s7, 0x54($sp)
/* 441EC 80068DEC AFB60050 */  sw        $s6, 0x50($sp)
/* 441F0 80068DF0 AFB5004C */  sw        $s5, 0x4c($sp)
/* 441F4 80068DF4 AFB40048 */  sw        $s4, 0x48($sp)
/* 441F8 80068DF8 AFB1003C */  sw        $s1, 0x3c($sp)
/* 441FC 80068DFC 8E020000 */  lw        $v0, ($s0)
/* 44200 80068E00 8FB40074 */  lw        $s4, 0x74($sp)
/* 44204 80068E04 30420001 */  andi      $v0, $v0, 1
/* 44208 80068E08 1040004E */  beqz      $v0, .L80068F44
/* 4420C 80068E0C 00A0B821 */   addu     $s7, $a1, $zero
/* 44210 80068E10 0C01A775 */  jal       __osCheckId
/* 44214 80068E14 02002021 */   addu     $a0, $s0, $zero
/* 44218 80068E18 00403821 */  addu      $a3, $v0, $zero
/* 4421C 80068E1C 14E0004A */  bnez      $a3, .L80068F48
/* 44220 80068E20 00000000 */   nop
/* 44224 80068E24 8E020050 */  lw        $v0, 0x50($s0)
/* 44228 80068E28 18400044 */  blez      $v0, .L80068F3C
/* 4422C 80068E2C 00008821 */   addu     $s1, $zero, $zero
/* 44230 80068E30 27B60020 */  addiu     $s6, $sp, 0x20
/* 44234 80068E34 27B5001C */  addiu     $s5, $sp, 0x1c
.L80068E38:
/* 44238 80068E38 8E06005C */  lw        $a2, 0x5c($s0)
/* 4423C 80068E3C 8E040004 */  lw        $a0, 4($s0)
/* 44240 80068E40 8E050008 */  lw        $a1, 8($s0)
/* 44244 80068E44 27A70010 */  addiu     $a3, $sp, 0x10
/* 44248 80068E48 00D13021 */  addu      $a2, $a2, $s1
/* 4424C 80068E4C 0C01A874 */  jal       __osContRamRead
/* 44250 80068E50 30C6FFFF */   andi     $a2, $a2, 0xffff
/* 44254 80068E54 00403821 */  addu      $a3, $v0, $zero
/* 44258 80068E58 14E0003B */  bnez      $a3, .L80068F48
/* 4425C 80068E5C 00E01021 */   addu     $v0, $a3, $zero
/* 44260 80068E60 8E040004 */  lw        $a0, 4($s0)
/* 44264 80068E64 0C01A530 */  jal       __osPfsGetStatus
/* 44268 80068E68 8E050008 */   lw       $a1, 8($s0)
/* 4426C 80068E6C 00403821 */  addu      $a3, $v0, $zero
/* 44270 80068E70 14E00027 */  bnez      $a3, .L80068F10
/* 44274 80068E74 32E2FFFF */   andi     $v0, $s7, 0xffff
/* 44278 80068E78 97A30014 */  lhu       $v1, 0x14($sp)
/* 4427C 80068E7C 1462002A */  bne       $v1, $v0, .L80068F28
/* 44280 80068E80 00000000 */   nop
/* 44284 80068E84 8FA20010 */  lw        $v0, 0x10($sp)
/* 44288 80068E88 145E0027 */  bne       $v0, $fp, .L80068F28
/* 4428C 80068E8C 00000000 */   nop
/* 44290 80068E90 1240000C */  beqz      $s2, .L80068EC4
/* 44294 80068E94 00004021 */   addu     $t0, $zero, $zero
/* 44298 80068E98 00002021 */  addu      $a0, $zero, $zero
/* 4429C 80068E9C 02403021 */  addu      $a2, $s2, $zero
/* 442A0 80068EA0 02C02821 */  addu      $a1, $s6, $zero
.L80068EA4:
/* 442A4 80068EA4 90A30000 */  lbu       $v1, ($a1)
/* 442A8 80068EA8 90C20000 */  lbu       $v0, ($a2)
/* 442AC 80068EAC 1462001C */  bne       $v1, $v0, .L80068F20
/* 442B0 80068EB0 24C60001 */   addiu    $a2, $a2, 1
/* 442B4 80068EB4 24840001 */  addiu     $a0, $a0, 1
/* 442B8 80068EB8 28820010 */  slti      $v0, $a0, 0x10
/* 442BC 80068EBC 1440FFF9 */  bnez      $v0, .L80068EA4
/* 442C0 80068EC0 24A50001 */   addiu    $a1, $a1, 1
.L80068EC4:
/* 442C4 80068EC4 0013102B */  sltu      $v0, $zero, $s3
/* 442C8 80068EC8 2D030001 */  sltiu     $v1, $t0, 1
/* 442CC 80068ECC 00431024 */  and       $v0, $v0, $v1
/* 442D0 80068ED0 1040000C */  beqz      $v0, .L80068F04
/* 442D4 80068ED4 00000000 */   nop
/* 442D8 80068ED8 00002021 */  addu      $a0, $zero, $zero
/* 442DC 80068EDC 02603021 */  addu      $a2, $s3, $zero
/* 442E0 80068EE0 02A02821 */  addu      $a1, $s5, $zero
.L80068EE4:
/* 442E4 80068EE4 90A30000 */  lbu       $v1, ($a1)
/* 442E8 80068EE8 90C20000 */  lbu       $v0, ($a2)
/* 442EC 80068EEC 1462000A */  bne       $v1, $v0, .L80068F18
/* 442F0 80068EF0 24C60001 */   addiu    $a2, $a2, 1
/* 442F4 80068EF4 24840001 */  addiu     $a0, $a0, 1
/* 442F8 80068EF8 28820004 */  slti      $v0, $a0, 4
/* 442FC 80068EFC 1440FFF9 */  bnez      $v0, .L80068EE4
/* 44300 80068F00 24A50001 */   addiu    $a1, $a1, 1
.L80068F04:
/* 44304 80068F04 15000008 */  bnez      $t0, .L80068F28
/* 44308 80068F08 00000000 */   nop
/* 4430C 80068F0C AE910000 */  sw        $s1, ($s4)
.L80068F10:
/* 44310 80068F10 0801A3D2 */  j         .L80068F48
/* 44314 80068F14 00E01021 */   addu     $v0, $a3, $zero
.L80068F18:
/* 44318 80068F18 0801A3C1 */  j         .L80068F04
/* 4431C 80068F1C 24080001 */   addiu    $t0, $zero, 1
.L80068F20:
/* 44320 80068F20 0801A3B1 */  j         .L80068EC4
/* 44324 80068F24 24080001 */   addiu    $t0, $zero, 1
.L80068F28:
/* 44328 80068F28 8E020050 */  lw        $v0, 0x50($s0)
/* 4432C 80068F2C 26310001 */  addiu     $s1, $s1, 1
/* 44330 80068F30 0222102A */  slt       $v0, $s1, $v0
/* 44334 80068F34 1440FFC0 */  bnez      $v0, .L80068E38
/* 44338 80068F38 00000000 */   nop
.L80068F3C:
/* 4433C 80068F3C 2402FFFF */  addiu     $v0, $zero, -1
/* 44340 80068F40 AE820000 */  sw        $v0, ($s4)
.L80068F44:
/* 44344 80068F44 24020005 */  addiu     $v0, $zero, 5
.L80068F48:
/* 44348 80068F48 8FBF005C */  lw        $ra, 0x5c($sp)
/* 4434C 80068F4C 8FBE0058 */  lw        $fp, 0x58($sp)
/* 44350 80068F50 8FB70054 */  lw        $s7, 0x54($sp)
/* 44354 80068F54 8FB60050 */  lw        $s6, 0x50($sp)
/* 44358 80068F58 8FB5004C */  lw        $s5, 0x4c($sp)
/* 4435C 80068F5C 8FB40048 */  lw        $s4, 0x48($sp)
/* 44360 80068F60 8FB30044 */  lw        $s3, 0x44($sp)
/* 44364 80068F64 8FB20040 */  lw        $s2, 0x40($sp)
/* 44368 80068F68 8FB1003C */  lw        $s1, 0x3c($sp)
/* 4436C 80068F6C 8FB00038 */  lw        $s0, 0x38($sp)
/* 44370 80068F70 03E00008 */  jr        $ra
/* 44374 80068F74 27BD0060 */   addiu    $sp, $sp, 0x60
/* 44378 80068F78 00000000 */  nop
/* 4437C 80068F7C 00000000 */  nop
