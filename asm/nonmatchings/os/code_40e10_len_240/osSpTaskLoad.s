.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osSpTaskLoad
/* 40E10 80065A10 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 40E14 80065A14 AFB00010 */  sw        $s0, 0x10($sp)
/* 40E18 80065A18 00808021 */  addu      $s0, $a0, $zero
/* 40E1C 80065A1C AFB10014 */  sw        $s1, 0x14($sp)
/* 40E20 80065A20 3C11800B */  lui       $s1, %hi(D_800AF8C0)
/* 40E24 80065A24 2631F8C0 */  addiu     $s1, $s1, %lo(D_800AF8C0)
/* 40E28 80065A28 02202821 */  addu      $a1, $s1, $zero
/* 40E2C 80065A2C AFBF0018 */  sw        $ra, 0x18($sp)
/* 40E30 80065A30 0C019194 */  jal       bcopy
/* 40E34 80065A34 24060040 */   addiu    $a2, $zero, 0x40
/* 40E38 80065A38 3C04800B */  lui       $a0, %hi(D_800AF8D0)
/* 40E3C 80065A3C 8C84F8D0 */  lw        $a0, %lo(D_800AF8D0)($a0)
/* 40E40 80065A40 10800005 */  beqz      $a0, .L80065A58
/* 40E44 80065A44 00000000 */   nop
/* 40E48 80065A48 0C0187A4 */  jal       osVirtualToPhysical
/* 40E4C 80065A4C 00000000 */   nop
/* 40E50 80065A50 3C01800B */  lui       $at, %hi(D_800AF8D0)
/* 40E54 80065A54 AC22F8D0 */  sw        $v0, %lo(D_800AF8D0)($at)
.L80065A58:
/* 40E58 80065A58 3C04800B */  lui       $a0, %hi(D_800AF8D8)
/* 40E5C 80065A5C 8C84F8D8 */  lw        $a0, %lo(D_800AF8D8)($a0)
/* 40E60 80065A60 10800005 */  beqz      $a0, .L80065A78
/* 40E64 80065A64 00000000 */   nop
/* 40E68 80065A68 0C0187A4 */  jal       osVirtualToPhysical
/* 40E6C 80065A6C 00000000 */   nop
/* 40E70 80065A70 3C01800B */  lui       $at, %hi(D_800AF8D8)
/* 40E74 80065A74 AC22F8D8 */  sw        $v0, %lo(D_800AF8D8)($at)
.L80065A78:
/* 40E78 80065A78 3C04800B */  lui       $a0, %hi(D_800AF8E0)
/* 40E7C 80065A7C 8C84F8E0 */  lw        $a0, %lo(D_800AF8E0)($a0)
/* 40E80 80065A80 10800005 */  beqz      $a0, .L80065A98
/* 40E84 80065A84 00000000 */   nop
/* 40E88 80065A88 0C0187A4 */  jal       osVirtualToPhysical
/* 40E8C 80065A8C 00000000 */   nop
/* 40E90 80065A90 3C01800B */  lui       $at, %hi(D_800AF8E0)
/* 40E94 80065A94 AC22F8E0 */  sw        $v0, %lo(D_800AF8E0)($at)
.L80065A98:
/* 40E98 80065A98 3C04800B */  lui       $a0, %hi(D_800AF8E8)
/* 40E9C 80065A9C 8C84F8E8 */  lw        $a0, %lo(D_800AF8E8)($a0)
/* 40EA0 80065AA0 10800005 */  beqz      $a0, .L80065AB8
/* 40EA4 80065AA4 00000000 */   nop
/* 40EA8 80065AA8 0C0187A4 */  jal       osVirtualToPhysical
/* 40EAC 80065AAC 00000000 */   nop
/* 40EB0 80065AB0 3C01800B */  lui       $at, %hi(D_800AF8E8)
/* 40EB4 80065AB4 AC22F8E8 */  sw        $v0, %lo(D_800AF8E8)($at)
.L80065AB8:
/* 40EB8 80065AB8 3C04800B */  lui       $a0, %hi(D_800AF8EC)
/* 40EBC 80065ABC 8C84F8EC */  lw        $a0, %lo(D_800AF8EC)($a0)
/* 40EC0 80065AC0 10800005 */  beqz      $a0, .L80065AD8
/* 40EC4 80065AC4 00000000 */   nop
/* 40EC8 80065AC8 0C0187A4 */  jal       osVirtualToPhysical
/* 40ECC 80065ACC 00000000 */   nop
/* 40ED0 80065AD0 3C01800B */  lui       $at, %hi(D_800AF8EC)
/* 40ED4 80065AD4 AC22F8EC */  sw        $v0, %lo(D_800AF8EC)($at)
.L80065AD8:
/* 40ED8 80065AD8 3C04800B */  lui       $a0, %hi(D_800AF8F0)
/* 40EDC 80065ADC 8C84F8F0 */  lw        $a0, %lo(D_800AF8F0)($a0)
/* 40EE0 80065AE0 10800005 */  beqz      $a0, .L80065AF8
/* 40EE4 80065AE4 00000000 */   nop
/* 40EE8 80065AE8 0C0187A4 */  jal       osVirtualToPhysical
/* 40EEC 80065AEC 00000000 */   nop
/* 40EF0 80065AF0 3C01800B */  lui       $at, %hi(D_800AF8F0)
/* 40EF4 80065AF4 AC22F8F0 */  sw        $v0, %lo(D_800AF8F0)($at)
.L80065AF8:
/* 40EF8 80065AF8 3C04800B */  lui       $a0, %hi(D_800AF8F8)
/* 40EFC 80065AFC 8C84F8F8 */  lw        $a0, %lo(D_800AF8F8)($a0)
/* 40F00 80065B00 10800005 */  beqz      $a0, .L80065B18
/* 40F04 80065B04 00000000 */   nop
/* 40F08 80065B08 0C0187A4 */  jal       osVirtualToPhysical
/* 40F0C 80065B0C 00000000 */   nop
/* 40F10 80065B10 3C01800B */  lui       $at, %hi(D_800AF8F8)
/* 40F14 80065B14 AC22F8F8 */  sw        $v0, %lo(D_800AF8F8)($at)
.L80065B18:
/* 40F18 80065B18 3C02800B */  lui       $v0, %hi(D_800AF8C4)
/* 40F1C 80065B1C 8C42F8C4 */  lw        $v0, %lo(D_800AF8C4)($v0)
/* 40F20 80065B20 30420001 */  andi      $v0, $v0, 1
/* 40F24 80065B24 10400019 */  beqz      $v0, .L80065B8C
/* 40F28 80065B28 02202021 */   addu     $a0, $s1, $zero
/* 40F2C 80065B2C 3C02800B */  lui       $v0, %hi(D_800AF8F8)
/* 40F30 80065B30 8C42F8F8 */  lw        $v0, %lo(D_800AF8F8)($v0)
/* 40F34 80065B34 3C03800B */  lui       $v1, %hi(D_800AF8FC)
/* 40F38 80065B38 8C63F8FC */  lw        $v1, %lo(D_800AF8FC)($v1)
/* 40F3C 80065B3C 3C01800B */  lui       $at, %hi(D_800AF8D8)
/* 40F40 80065B40 AC22F8D8 */  sw        $v0, %lo(D_800AF8D8)($at)
/* 40F44 80065B44 3C01800B */  lui       $at, %hi(D_800AF8DC)
/* 40F48 80065B48 AC23F8DC */  sw        $v1, %lo(D_800AF8DC)($at)
/* 40F4C 80065B4C 8E020004 */  lw        $v0, 4($s0)
/* 40F50 80065B50 2403FFFE */  addiu     $v1, $zero, -2
/* 40F54 80065B54 00431024 */  and       $v0, $v0, $v1
/* 40F58 80065B58 AE020004 */  sw        $v0, 4($s0)
/* 40F5C 80065B5C 3C02800B */  lui       $v0, %hi(D_800AF8C4)
/* 40F60 80065B60 8C42F8C4 */  lw        $v0, %lo(D_800AF8C4)($v0)
/* 40F64 80065B64 30420004 */  andi      $v0, $v0, 4
/* 40F68 80065B68 10400008 */  beqz      $v0, .L80065B8C
/* 40F6C 80065B6C 3C03A000 */   lui      $v1, 0xa000
/* 40F70 80065B70 8E020038 */  lw        $v0, 0x38($s0)
/* 40F74 80065B74 24420BFC */  addiu     $v0, $v0, 0xbfc
/* 40F78 80065B78 00431025 */  or        $v0, $v0, $v1
/* 40F7C 80065B7C 8C420000 */  lw        $v0, ($v0)
/* 40F80 80065B80 3C01800B */  lui       $at, %hi(D_800AF8D0)
/* 40F84 80065B84 AC22F8D0 */  sw        $v0, %lo(D_800AF8D0)($at)
/* 40F88 80065B88 02202021 */  addu      $a0, $s1, $zero
.L80065B8C:
/* 40F8C 80065B8C 0C018614 */  jal       osWritebackDCache
/* 40F90 80065B90 24050040 */   addiu    $a1, $zero, 0x40
/* 40F94 80065B94 0C01B1BC */  jal       osSpSetStatus
/* 40F98 80065B98 24042B00 */   addiu    $a0, $zero, 0x2b00
/* 40F9C 80065B9C 2410FFFF */  addiu     $s0, $zero, -1
/* 40FA0 80065BA0 3C040400 */  lui       $a0, 0x400
.L80065BA4:
/* 40FA4 80065BA4 0C01B1C0 */  jal       osSpSetPc
/* 40FA8 80065BA8 34841000 */   ori      $a0, $a0, 0x1000
/* 40FAC 80065BAC 1050FFFD */  beq       $v0, $s0, .L80065BA4
/* 40FB0 80065BB0 3C040400 */   lui      $a0, 0x400
/* 40FB4 80065BB4 2410FFFF */  addiu     $s0, $zero, -1
/* 40FB8 80065BB8 24040001 */  addiu     $a0, $zero, 1
.L80065BBC:
/* 40FBC 80065BBC 3C050400 */  lui       $a1, 0x400
/* 40FC0 80065BC0 34A50FC0 */  ori       $a1, $a1, 0xfc0
/* 40FC4 80065BC4 02203021 */  addu      $a2, $s1, $zero
/* 40FC8 80065BC8 0C01B1CC */  jal       osSpRawStartDma
/* 40FCC 80065BCC 24070040 */   addiu    $a3, $zero, 0x40
/* 40FD0 80065BD0 1050FFFA */  beq       $v0, $s0, .L80065BBC
/* 40FD4 80065BD4 24040001 */   addiu    $a0, $zero, 1
.L80065BD8:
/* 40FD8 80065BD8 0C01B1B0 */  jal       osSpDeviceBusy
/* 40FDC 80065BDC 00000000 */   nop
/* 40FE0 80065BE0 1440FFFD */  bnez      $v0, .L80065BD8
/* 40FE4 80065BE4 24040001 */   addiu    $a0, $zero, 1
/* 40FE8 80065BE8 2410FFFF */  addiu     $s0, $zero, -1
.L80065BEC:
/* 40FEC 80065BEC 8E260008 */  lw        $a2, 8($s1)
/* 40FF0 80065BF0 8E27000C */  lw        $a3, 0xc($s1)
/* 40FF4 80065BF4 3C050400 */  lui       $a1, 0x400
/* 40FF8 80065BF8 0C01B1CC */  jal       osSpRawStartDma
/* 40FFC 80065BFC 34A51000 */   ori      $a1, $a1, 0x1000
/* 41000 80065C00 1050FFFA */  beq       $v0, $s0, .L80065BEC
/* 41004 80065C04 24040001 */   addiu    $a0, $zero, 1
/* 41008 80065C08 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4100C 80065C0C 8FB10014 */  lw        $s1, 0x14($sp)
/* 41010 80065C10 8FB00010 */  lw        $s0, 0x10($sp)
/* 41014 80065C14 03E00008 */  jr        $ra
/* 41018 80065C18 27BD0020 */   addiu    $sp, $sp, 0x20
