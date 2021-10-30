.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80036A70
/* 11E70 80036A70 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 11E74 80036A74 AFB20028 */  sw        $s2, 0x28($sp)
/* 11E78 80036A78 3C12800A */  lui       $s2, %hi(D_8009A630)
/* 11E7C 80036A7C 2652A630 */  addiu     $s2, $s2, %lo(D_8009A630)
/* 11E80 80036A80 24020001 */  addiu     $v0, $zero, 1
/* 11E84 80036A84 AFBF002C */  sw        $ra, 0x2c($sp)
/* 11E88 80036A88 AFB10024 */  sw        $s1, 0x24($sp)
/* 11E8C 80036A8C AFB00020 */  sw        $s0, 0x20($sp)
/* 11E90 80036A90 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 11E94 80036A94 AE400000 */  sw        $zero, ($s2)
/* 11E98 80036A98 3C01800A */  lui       $at, %hi(D_8009A5B8)
/* 11E9C 80036A9C AC20A5B8 */  sw        $zero, %lo(D_8009A5B8)($at)
/* 11EA0 80036AA0 3C018015 */  lui       $at, %hi(D_801512F8)
/* 11EA4 80036AA4 A02212F8 */  sb        $v0, %lo(D_801512F8)($at)
/* 11EA8 80036AA8 0C00AAF0 */  jal       func_8002ABC0
/* 11EAC 80036AAC 00000000 */   nop
/* 11EB0 80036AB0 0C04A221 */  jal       func_80128884
/* 11EB4 80036AB4 00000000 */   nop
/* 11EB8 80036AB8 0C053A2B */  jal       func_8014E8AC
/* 11EBC 80036ABC 0000202D */   daddu    $a0, $zero, $zero
/* 11EC0 80036AC0 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 11EC4 80036AC4 2463417C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 11EC8 80036AC8 8C620000 */  lw        $v0, ($v1)
/* 11ECC 80036ACC A04000AC */  sb        $zero, 0xac($v0)
/* 11ED0 80036AD0 8C620000 */  lw        $v0, ($v1)
/* 11ED4 80036AD4 A04000AD */  sb        $zero, 0xad($v0)
/* 11ED8 80036AD8 8C620000 */  lw        $v0, ($v1)
/* 11EDC 80036ADC A0400070 */  sb        $zero, 0x70($v0)
/* 11EE0 80036AE0 8C630000 */  lw        $v1, ($v1)
/* 11EE4 80036AE4 2402FFFF */  addiu     $v0, $zero, -1
/* 11EE8 80036AE8 0C00CD41 */  jal       func_80033504
/* 11EEC 80036AEC A06200A8 */   sb       $v0, 0xa8($v1)
/* 11EF0 80036AF0 3C04800A */  lui       $a0, %hi(D_80098370)
/* 11EF4 80036AF4 24848370 */  addiu     $a0, $a0, %lo(D_80098370)
/* 11EF8 80036AF8 0C016A68 */  jal       func_8005A9A0
/* 11EFC 80036AFC 27A50018 */   addiu    $a1, $sp, 0x18
/* 11F00 80036B00 8FA40018 */  lw        $a0, 0x18($sp)
/* 11F04 80036B04 0C00AB29 */  jal       func_8002ACA4
/* 11F08 80036B08 0040882D */   daddu    $s1, $v0, $zero
/* 11F0C 80036B0C 0220202D */  daddu     $a0, $s1, $zero
/* 11F10 80036B10 0040282D */  daddu     $a1, $v0, $zero
/* 11F14 80036B14 3C10800A */  lui       $s0, %hi(D_8009E784)
/* 11F18 80036B18 2610E784 */  addiu     $s0, $s0, %lo(D_8009E784)
/* 11F1C 80036B1C 0C01BB74 */  jal       func_8006EDD0
/* 11F20 80036B20 AE050000 */   sw       $a1, ($s0)
/* 11F24 80036B24 0C00AB0E */  jal       func_8002AC38
/* 11F28 80036B28 0220202D */   daddu    $a0, $s1, $zero
/* 11F2C 80036B2C 8E030000 */  lw        $v1, ($s0)
/* 11F30 80036B30 8C620000 */  lw        $v0, ($v1)
/* 11F34 80036B34 8C640004 */  lw        $a0, 4($v1)
/* 11F38 80036B38 00431021 */  addu      $v0, $v0, $v1
/* 11F3C 80036B3C 3C01800A */  lui       $at, %hi(D_8009E788)
/* 11F40 80036B40 AC22E788 */  sw        $v0, %lo(D_8009E788)($at)
/* 11F44 80036B44 8C620008 */  lw        $v0, 8($v1)
/* 11F48 80036B48 00832021 */  addu      $a0, $a0, $v1
/* 11F4C 80036B4C 3C01800A */  lui       $at, %hi(D_8009E78C)
/* 11F50 80036B50 AC24E78C */  sw        $a0, %lo(D_8009E78C)($at)
/* 11F54 80036B54 8C64000C */  lw        $a0, 0xc($v1)
/* 11F58 80036B58 00431021 */  addu      $v0, $v0, $v1
/* 11F5C 80036B5C 00832021 */  addu      $a0, $a0, $v1
/* 11F60 80036B60 3C01800A */  lui       $at, %hi(D_8009E790)
/* 11F64 80036B64 AC22E790 */  sw        $v0, %lo(D_8009E790)($at)
/* 11F68 80036B68 3C01800A */  lui       $at, %hi(D_8009E794)
/* 11F6C 80036B6C AC24E794 */  sw        $a0, %lo(D_8009E794)($at)
/* 11F70 80036B70 0C00B6E1 */  jal       func_8002DB84
/* 11F74 80036B74 00000000 */   nop
/* 11F78 80036B78 0000202D */  daddu     $a0, $zero, $zero
/* 11F7C 80036B7C 2405000C */  addiu     $a1, $zero, 0xc
/* 11F80 80036B80 2406001C */  addiu     $a2, $zero, 0x1c
/* 11F84 80036B84 24070128 */  addiu     $a3, $zero, 0x128
/* 11F88 80036B88 3C10800B */  lui       $s0, %hi(D_800B1D60)
/* 11F8C 80036B8C 26101D60 */  addiu     $s0, $s0, %lo(D_800B1D60)
/* 11F90 80036B90 3C0141C8 */  lui       $at, 0x41c8
/* 11F94 80036B94 4481A000 */  mtc1      $at, $f20
/* 11F98 80036B98 24020006 */  addiu     $v0, $zero, 6
/* 11F9C 80036B9C A6020004 */  sh        $v0, 4($s0)
/* 11FA0 80036BA0 24020001 */  addiu     $v0, $zero, 1
/* 11FA4 80036BA4 A6020006 */  sh        $v0, 6($s0)
/* 11FA8 80036BA8 24020010 */  addiu     $v0, $zero, 0x10
/* 11FAC 80036BAC A6020012 */  sh        $v0, 0x12($s0)
/* 11FB0 80036BB0 24021000 */  addiu     $v0, $zero, 0x1000
/* 11FB4 80036BB4 A6020014 */  sh        $v0, 0x14($s0)
/* 11FB8 80036BB8 240200B8 */  addiu     $v0, $zero, 0xb8
/* 11FBC 80036BBC 3C018007 */  lui       $at, %hi(D_800773E0)
/* 11FC0 80036BC0 AC2073E0 */  sw        $zero, %lo(D_800773E0)($at)
/* 11FC4 80036BC4 E6140018 */  swc1      $f20, 0x18($s0)
/* 11FC8 80036BC8 AFA20010 */  sw        $v0, 0x10($sp)
/* 11FCC 80036BCC 96020000 */  lhu       $v0, ($s0)
/* 11FD0 80036BD0 96030558 */  lhu       $v1, 0x558($s0)
/* 11FD4 80036BD4 34420002 */  ori       $v0, $v0, 2
/* 11FD8 80036BD8 A6020000 */  sh        $v0, ($s0)
/* 11FDC 80036BDC 96020AB0 */  lhu       $v0, 0xab0($s0)
/* 11FE0 80036BE0 34630002 */  ori       $v1, $v1, 2
/* 11FE4 80036BE4 A6030558 */  sh        $v1, 0x558($s0)
/* 11FE8 80036BE8 96031008 */  lhu       $v1, 0x1008($s0)
/* 11FEC 80036BEC 34420002 */  ori       $v0, $v0, 2
/* 11FF0 80036BF0 34630002 */  ori       $v1, $v1, 2
/* 11FF4 80036BF4 A6020AB0 */  sh        $v0, 0xab0($s0)
/* 11FF8 80036BF8 0C00B7E9 */  jal       func_8002DFA4
/* 11FFC 80036BFC A6031008 */   sh       $v1, 0x1008($s0)
/* 12000 80036C00 3C0143FA */  lui       $at, 0x43fa
/* 12004 80036C04 44810000 */  mtc1      $at, $f0
/* 12008 80036C08 3C01447A */  lui       $at, 0x447a
/* 1200C 80036C0C 44811000 */  mtc1      $at, $f2
/* 12010 80036C10 3C0144BB */  lui       $at, 0x44bb
/* 12014 80036C14 34218000 */  ori       $at, $at, 0x8000
/* 12018 80036C18 44812000 */  mtc1      $at, $f4
/* 1201C 80036C1C 3C014316 */  lui       $at, 0x4316
/* 12020 80036C20 44813000 */  mtc1      $at, $f6
/* 12024 80036C24 24020028 */  addiu     $v0, $zero, 0x28
/* 12028 80036C28 A602001E */  sh        $v0, 0x1e($s0)
/* 1202C 80036C2C 24020064 */  addiu     $v0, $zero, 0x64
/* 12030 80036C30 A600002C */  sh        $zero, 0x2c($s0)
/* 12034 80036C34 A600002E */  sh        $zero, 0x2e($s0)
/* 12038 80036C38 A6000030 */  sh        $zero, 0x30($s0)
/* 1203C 80036C3C E6140054 */  swc1      $f20, 0x54($s0)
/* 12040 80036C40 E6140058 */  swc1      $f20, 0x58($s0)
/* 12044 80036C44 A600001C */  sh        $zero, 0x1c($s0)
/* 12048 80036C48 A6020020 */  sh        $v0, 0x20($s0)
/* 1204C 80036C4C A6000022 */  sh        $zero, 0x22($s0)
/* 12050 80036C50 E600003C */  swc1      $f0, 0x3c($s0)
/* 12054 80036C54 E6020040 */  swc1      $f2, 0x40($s0)
/* 12058 80036C58 E6040044 */  swc1      $f4, 0x44($s0)
/* 1205C 80036C5C 0C0B0C77 */  jal       func_802C31DC
/* 12060 80036C60 E606005C */   swc1     $f6, 0x5c($s0)
/* 12064 80036C64 0C04A0B2 */  jal       func_801282C8
/* 12068 80036C68 00000000 */   nop
/* 1206C 80036C6C 0C048AA8 */  jal       func_80122AA0
/* 12070 80036C70 00000000 */   nop
/* 12074 80036C74 0C044512 */  jal       func_80111448
/* 12078 80036C78 0000202D */   daddu    $a0, $zero, $zero
/* 1207C 80036C7C 0C048D0D */  jal       func_80123434
/* 12080 80036C80 00000000 */   nop
/* 12084 80036C84 0C049770 */  jal       func_80125DC0
/* 12088 80036C88 00000000 */   nop
/* 1208C 80036C8C 0C00E05F */  jal       func_8003817C
/* 12090 80036C90 00000000 */   nop
/* 12094 80036C94 0C05186C */  jal       func_801461B0
/* 12098 80036C98 00000000 */   nop
/* 1209C 80036C9C 0C052BAA */  jal       func_8014AEA8
/* 120A0 80036CA0 00000000 */   nop
/* 120A4 80036CA4 0C0457B2 */  jal       func_80115EC8
/* 120A8 80036CA8 24040001 */   addiu    $a0, $zero, 1
/* 120AC 80036CAC 0C016653 */  jal       func_8005994C
/* 120B0 80036CB0 00000000 */   nop
/* 120B4 80036CB4 8E420000 */  lw        $v0, ($s2)
/* 120B8 80036CB8 34420002 */  ori       $v0, $v0, 2
/* 120BC 80036CBC 0C039CD0 */  jal       func_800E7340
/* 120C0 80036CC0 AE420000 */   sw       $v0, ($s2)
/* 120C4 80036CC4 0000202D */  daddu     $a0, $zero, $zero
/* 120C8 80036CC8 3C058003 */  lui       $a1, %hi(func_800372C8)
/* 120CC 80036CCC 24A572C8 */  addiu     $a1, $a1, %lo(func_800372C8)
/* 120D0 80036CD0 8E420000 */  lw        $v0, ($s2)
/* 120D4 80036CD4 2403FFF7 */  addiu     $v1, $zero, -9
/* 120D8 80036CD8 00431024 */  and       $v0, $v0, $v1
/* 120DC 80036CDC 0C045FE5 */  jal       func_80117F94
/* 120E0 80036CE0 AE420000 */   sw       $v0, ($s2)
/* 120E4 80036CE4 3C04800A */  lui       $a0, %hi(D_8009837C)
/* 120E8 80036CE8 0C052B88 */  jal       func_8014AE20
/* 120EC 80036CEC 2484837C */   addiu    $a0, $a0, %lo(D_8009837C)
/* 120F0 80036CF0 3C048020 */  lui       $a0, %hi(D_80200000)
/* 120F4 80036CF4 24840000 */  addiu     $a0, $a0, %lo(D_80200000)
/* 120F8 80036CF8 0C052BB6 */  jal       func_8014AED8
/* 120FC 80036CFC 00000000 */   nop
/* 12100 80036D00 0000202D */  daddu     $a0, $zero, $zero
/* 12104 80036D04 2405006A */  addiu     $a1, $zero, 0x6a
/* 12108 80036D08 0080302D */  daddu     $a2, $a0, $zero
/* 1210C 80036D0C 240701F4 */  addiu     $a3, $zero, 0x1f4
/* 12110 80036D10 24020008 */  addiu     $v0, $zero, 8
/* 12114 80036D14 0C053E72 */  jal       func_8014F9C8
/* 12118 80036D18 AFA20010 */   sw       $v0, 0x10($sp)
/* 1211C 80036D1C 8FBF002C */  lw        $ra, 0x2c($sp)
/* 12120 80036D20 8FB20028 */  lw        $s2, 0x28($sp)
/* 12124 80036D24 8FB10024 */  lw        $s1, 0x24($sp)
/* 12128 80036D28 8FB00020 */  lw        $s0, 0x20($sp)
/* 1212C 80036D2C D7B40030 */  ldc1      $f20, 0x30($sp)
/* 12130 80036D30 240201E0 */  addiu     $v0, $zero, 0x1e0
/* 12134 80036D34 3C01800A */  lui       $at, %hi(D_8009E798)
/* 12138 80036D38 A422E798 */  sh        $v0, %lo(D_8009E798)($at)
/* 1213C 80036D3C 03E00008 */  jr        $ra
/* 12140 80036D40 27BD0038 */   addiu    $sp, $sp, 0x38
