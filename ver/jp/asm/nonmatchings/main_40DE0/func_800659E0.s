.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800659E0
/* 40DE0 800659E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 40DE4 800659E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 40DE8 800659E8 00808021 */  addu      $s0, $a0, $zero
/* 40DEC 800659EC AFB10014 */  sw        $s1, 0x14($sp)
/* 40DF0 800659F0 3C11800B */  lui       $s1, %hi(D_800AF8A0)
/* 40DF4 800659F4 2631F8A0 */  addiu     $s1, $s1, %lo(D_800AF8A0)
/* 40DF8 800659F8 02202821 */  addu      $a1, $s1, $zero
/* 40DFC 800659FC AFBF0018 */  sw        $ra, 0x18($sp)
/* 40E00 80065A00 0C019188 */  jal       func_80064620
/* 40E04 80065A04 24060040 */   addiu    $a2, $zero, 0x40
/* 40E08 80065A08 3C04800B */  lui       $a0, %hi(D_800AF8B0)
/* 40E0C 80065A0C 8C84F8B0 */  lw        $a0, %lo(D_800AF8B0)($a0)
/* 40E10 80065A10 10800005 */  beqz      $a0, .L80065A28
/* 40E14 80065A14 00000000 */   nop
/* 40E18 80065A18 0C018798 */  jal       func_80061E60
/* 40E1C 80065A1C 00000000 */   nop
/* 40E20 80065A20 3C01800B */  lui       $at, %hi(D_800AF8B0)
/* 40E24 80065A24 AC22F8B0 */  sw        $v0, %lo(D_800AF8B0)($at)
.L80065A28:
/* 40E28 80065A28 3C04800B */  lui       $a0, %hi(D_800AF8B8)
/* 40E2C 80065A2C 8C84F8B8 */  lw        $a0, %lo(D_800AF8B8)($a0)
/* 40E30 80065A30 10800005 */  beqz      $a0, .L80065A48
/* 40E34 80065A34 00000000 */   nop
/* 40E38 80065A38 0C018798 */  jal       func_80061E60
/* 40E3C 80065A3C 00000000 */   nop
/* 40E40 80065A40 3C01800B */  lui       $at, %hi(D_800AF8B8)
/* 40E44 80065A44 AC22F8B8 */  sw        $v0, %lo(D_800AF8B8)($at)
.L80065A48:
/* 40E48 80065A48 3C04800B */  lui       $a0, %hi(D_800AF8C0)
/* 40E4C 80065A4C 8C84F8C0 */  lw        $a0, %lo(D_800AF8C0)($a0)
/* 40E50 80065A50 10800005 */  beqz      $a0, .L80065A68
/* 40E54 80065A54 00000000 */   nop
/* 40E58 80065A58 0C018798 */  jal       func_80061E60
/* 40E5C 80065A5C 00000000 */   nop
/* 40E60 80065A60 3C01800B */  lui       $at, %hi(D_800AF8C0)
/* 40E64 80065A64 AC22F8C0 */  sw        $v0, %lo(D_800AF8C0)($at)
.L80065A68:
/* 40E68 80065A68 3C04800B */  lui       $a0, %hi(D_800AF8C8)
/* 40E6C 80065A6C 8C84F8C8 */  lw        $a0, %lo(D_800AF8C8)($a0)
/* 40E70 80065A70 10800005 */  beqz      $a0, .L80065A88
/* 40E74 80065A74 00000000 */   nop
/* 40E78 80065A78 0C018798 */  jal       func_80061E60
/* 40E7C 80065A7C 00000000 */   nop
/* 40E80 80065A80 3C01800B */  lui       $at, %hi(D_800AF8C8)
/* 40E84 80065A84 AC22F8C8 */  sw        $v0, %lo(D_800AF8C8)($at)
.L80065A88:
/* 40E88 80065A88 3C04800B */  lui       $a0, %hi(D_800AF8CC)
/* 40E8C 80065A8C 8C84F8CC */  lw        $a0, %lo(D_800AF8CC)($a0)
/* 40E90 80065A90 10800005 */  beqz      $a0, .L80065AA8
/* 40E94 80065A94 00000000 */   nop
/* 40E98 80065A98 0C018798 */  jal       func_80061E60
/* 40E9C 80065A9C 00000000 */   nop
/* 40EA0 80065AA0 3C01800B */  lui       $at, %hi(D_800AF8CC)
/* 40EA4 80065AA4 AC22F8CC */  sw        $v0, %lo(D_800AF8CC)($at)
.L80065AA8:
/* 40EA8 80065AA8 3C04800B */  lui       $a0, %hi(D_800AF8D0)
/* 40EAC 80065AAC 8C84F8D0 */  lw        $a0, %lo(D_800AF8D0)($a0)
/* 40EB0 80065AB0 10800005 */  beqz      $a0, .L80065AC8
/* 40EB4 80065AB4 00000000 */   nop
/* 40EB8 80065AB8 0C018798 */  jal       func_80061E60
/* 40EBC 80065ABC 00000000 */   nop
/* 40EC0 80065AC0 3C01800B */  lui       $at, %hi(D_800AF8D0)
/* 40EC4 80065AC4 AC22F8D0 */  sw        $v0, %lo(D_800AF8D0)($at)
.L80065AC8:
/* 40EC8 80065AC8 3C04800B */  lui       $a0, %hi(D_800AF8D8)
/* 40ECC 80065ACC 8C84F8D8 */  lw        $a0, %lo(D_800AF8D8)($a0)
/* 40ED0 80065AD0 10800005 */  beqz      $a0, .L80065AE8
/* 40ED4 80065AD4 00000000 */   nop
/* 40ED8 80065AD8 0C018798 */  jal       func_80061E60
/* 40EDC 80065ADC 00000000 */   nop
/* 40EE0 80065AE0 3C01800B */  lui       $at, %hi(D_800AF8D8)
/* 40EE4 80065AE4 AC22F8D8 */  sw        $v0, %lo(D_800AF8D8)($at)
.L80065AE8:
/* 40EE8 80065AE8 3C02800B */  lui       $v0, %hi(D_800AF8A4)
/* 40EEC 80065AEC 8C42F8A4 */  lw        $v0, %lo(D_800AF8A4)($v0)
/* 40EF0 80065AF0 30420001 */  andi      $v0, $v0, 1
/* 40EF4 80065AF4 10400019 */  beqz      $v0, .L80065B5C
/* 40EF8 80065AF8 02202021 */   addu     $a0, $s1, $zero
/* 40EFC 80065AFC 3C02800B */  lui       $v0, %hi(D_800AF8D8)
/* 40F00 80065B00 8C42F8D8 */  lw        $v0, %lo(D_800AF8D8)($v0)
/* 40F04 80065B04 3C03800B */  lui       $v1, %hi(D_800AF8DC)
/* 40F08 80065B08 8C63F8DC */  lw        $v1, %lo(D_800AF8DC)($v1)
/* 40F0C 80065B0C 3C01800B */  lui       $at, %hi(D_800AF8B8)
/* 40F10 80065B10 AC22F8B8 */  sw        $v0, %lo(D_800AF8B8)($at)
/* 40F14 80065B14 3C01800B */  lui       $at, %hi(D_800AF8BC)
/* 40F18 80065B18 AC23F8BC */  sw        $v1, %lo(D_800AF8BC)($at)
/* 40F1C 80065B1C 8E020004 */  lw        $v0, 4($s0)
/* 40F20 80065B20 2403FFFE */  addiu     $v1, $zero, -2
/* 40F24 80065B24 00431024 */  and       $v0, $v0, $v1
/* 40F28 80065B28 AE020004 */  sw        $v0, 4($s0)
/* 40F2C 80065B2C 3C02800B */  lui       $v0, %hi(D_800AF8A4)
/* 40F30 80065B30 8C42F8A4 */  lw        $v0, %lo(D_800AF8A4)($v0)
/* 40F34 80065B34 30420004 */  andi      $v0, $v0, 4
/* 40F38 80065B38 10400008 */  beqz      $v0, .L80065B5C
/* 40F3C 80065B3C 3C03A000 */   lui      $v1, 0xa000
/* 40F40 80065B40 8E020038 */  lw        $v0, 0x38($s0)
/* 40F44 80065B44 24420BFC */  addiu     $v0, $v0, 0xbfc
/* 40F48 80065B48 00431025 */  or        $v0, $v0, $v1
/* 40F4C 80065B4C 8C420000 */  lw        $v0, ($v0)
/* 40F50 80065B50 3C01800B */  lui       $at, %hi(D_800AF8B0)
/* 40F54 80065B54 AC22F8B0 */  sw        $v0, %lo(D_800AF8B0)($at)
/* 40F58 80065B58 02202021 */  addu      $a0, $s1, $zero
.L80065B5C:
/* 40F5C 80065B5C 0C018608 */  jal       func_80061820
/* 40F60 80065B60 24050040 */   addiu    $a1, $zero, 0x40
/* 40F64 80065B64 0C01B1B4 */  jal       func_8006C6D0
/* 40F68 80065B68 24042B00 */   addiu    $a0, $zero, 0x2b00
/* 40F6C 80065B6C 2410FFFF */  addiu     $s0, $zero, -1
/* 40F70 80065B70 3C040400 */  lui       $a0, 0x400
.L80065B74:
/* 40F74 80065B74 0C01B1B8 */  jal       func_8006C6E0
/* 40F78 80065B78 34841000 */   ori      $a0, $a0, 0x1000
/* 40F7C 80065B7C 1050FFFD */  beq       $v0, $s0, .L80065B74
/* 40F80 80065B80 3C040400 */   lui      $a0, 0x400
/* 40F84 80065B84 2410FFFF */  addiu     $s0, $zero, -1
/* 40F88 80065B88 24040001 */  addiu     $a0, $zero, 1
.L80065B8C:
/* 40F8C 80065B8C 3C050400 */  lui       $a1, 0x400
/* 40F90 80065B90 34A50FC0 */  ori       $a1, $a1, 0xfc0
/* 40F94 80065B94 02203021 */  addu      $a2, $s1, $zero
/* 40F98 80065B98 0C01B1C4 */  jal       func_8006C710
/* 40F9C 80065B9C 24070040 */   addiu    $a3, $zero, 0x40
/* 40FA0 80065BA0 1050FFFA */  beq       $v0, $s0, .L80065B8C
/* 40FA4 80065BA4 24040001 */   addiu    $a0, $zero, 1
.L80065BA8:
/* 40FA8 80065BA8 0C01B1A8 */  jal       func_8006C6A0
/* 40FAC 80065BAC 00000000 */   nop
/* 40FB0 80065BB0 1440FFFD */  bnez      $v0, .L80065BA8
/* 40FB4 80065BB4 24040001 */   addiu    $a0, $zero, 1
/* 40FB8 80065BB8 2410FFFF */  addiu     $s0, $zero, -1
.L80065BBC:
/* 40FBC 80065BBC 8E260008 */  lw        $a2, 8($s1)
/* 40FC0 80065BC0 8E27000C */  lw        $a3, 0xc($s1)
/* 40FC4 80065BC4 3C050400 */  lui       $a1, 0x400
/* 40FC8 80065BC8 0C01B1C4 */  jal       func_8006C710
/* 40FCC 80065BCC 34A51000 */   ori      $a1, $a1, 0x1000
/* 40FD0 80065BD0 1050FFFA */  beq       $v0, $s0, .L80065BBC
/* 40FD4 80065BD4 24040001 */   addiu    $a0, $zero, 1
/* 40FD8 80065BD8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 40FDC 80065BDC 8FB10014 */  lw        $s1, 0x14($sp)
/* 40FE0 80065BE0 8FB00010 */  lw        $s0, 0x10($sp)
/* 40FE4 80065BE4 03E00008 */  jr        $ra
/* 40FE8 80065BE8 27BD0020 */   addiu    $sp, $sp, 0x20
