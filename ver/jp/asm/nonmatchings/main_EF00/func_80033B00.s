.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033B00
/* EF00 80033B00 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EF04 80033B04 AFBF0024 */  sw        $ra, 0x24($sp)
/* EF08 80033B08 AFB20020 */  sw        $s2, 0x20($sp)
/* EF0C 80033B0C AFB1001C */  sw        $s1, 0x1c($sp)
/* EF10 80033B10 AFB00018 */  sw        $s0, 0x18($sp)
/* EF14 80033B14 0C00AAF0 */  jal       func_8002ABC0
/* EF18 80033B18 F7B40028 */   sdc1     $f20, 0x28($sp)
/* EF1C 80033B1C 3C128007 */  lui       $s2, %hi(D_8007417C)
/* EF20 80033B20 2652417C */  addiu     $s2, $s2, %lo(D_8007417C)
/* EF24 80033B24 8E420000 */  lw        $v0, ($s2)
/* EF28 80033B28 A04000AC */  sb        $zero, 0xac($v0)
/* EF2C 80033B2C 8E420000 */  lw        $v0, ($s2)
/* EF30 80033B30 A04000AD */  sb        $zero, 0xad($v0)
/* EF34 80033B34 8E420000 */  lw        $v0, ($s2)
/* EF38 80033B38 240400FF */  addiu     $a0, $zero, 0xff
/* EF3C 80033B3C 0C00CD18 */  jal       func_80033460
/* EF40 80033B40 A04000AE */   sb       $zero, 0xae($v0)
/* EF44 80033B44 0C00CD1C */  jal       func_80033470
/* EF48 80033B48 0000202D */   daddu    $a0, $zero, $zero
/* EF4C 80033B4C 3C110022 */  lui       $s1, 0x22
/* EF50 80033B50 263115C0 */  addiu     $s1, $s1, 0x15c0
/* EF54 80033B54 3C100020 */  lui       $s0, 0x20
/* EF58 80033B58 261065C0 */  addiu     $s0, $s0, 0x65c0
/* EF5C 80033B5C 0C00AB29 */  jal       func_8002ACA4
/* EF60 80033B60 02302023 */   subu     $a0, $s1, $s0
/* EF64 80033B64 0200202D */  daddu     $a0, $s0, $zero
/* EF68 80033B68 0220282D */  daddu     $a1, $s1, $zero
/* EF6C 80033B6C 0040302D */  daddu     $a2, $v0, $zero
/* EF70 80033B70 3C10800A */  lui       $s0, %hi(D_8009E720)
/* EF74 80033B74 2610E720 */  addiu     $s0, $s0, %lo(D_8009E720)
/* EF78 80033B78 0C00A5BF */  jal       func_800296FC
/* EF7C 80033B7C AE060000 */   sw       $a2, ($s0)
/* EF80 80033B80 3C040001 */  lui       $a0, 1
/* EF84 80033B84 8E020000 */  lw        $v0, ($s0)
/* EF88 80033B88 34845000 */  ori       $a0, $a0, 0x5000
/* EF8C 80033B8C 24437000 */  addiu     $v1, $v0, 0x7000
/* EF90 80033B90 3C01800A */  lui       $at, %hi(D_8009E728)
/* EF94 80033B94 AC22E728 */  sw        $v0, %lo(D_8009E728)($at)
/* EF98 80033B98 00441021 */  addu      $v0, $v0, $a0
/* EF9C 80033B9C 3C01800A */  lui       $at, %hi(D_8009E724)
/* EFA0 80033BA0 AC23E724 */  sw        $v1, %lo(D_8009E724)($at)
/* EFA4 80033BA4 3C01800A */  lui       $at, %hi(D_8009E72C)
/* EFA8 80033BA8 AC22E72C */  sw        $v0, %lo(D_8009E72C)($at)
/* EFAC 80033BAC 0C017F54 */  jal       func_8005FD50
/* EFB0 80033BB0 00000000 */   nop
/* EFB4 80033BB4 0C00B6E1 */  jal       func_8002DB84
/* EFB8 80033BB8 00000000 */   nop
/* EFBC 80033BBC 0000202D */  daddu     $a0, $zero, $zero
/* EFC0 80033BC0 2405000C */  addiu     $a1, $zero, 0xc
/* EFC4 80033BC4 2406001C */  addiu     $a2, $zero, 0x1c
/* EFC8 80033BC8 3C10800B */  lui       $s0, %hi(D_800B1D60)
/* EFCC 80033BCC 26101D60 */  addiu     $s0, $s0, %lo(D_800B1D60)
/* EFD0 80033BD0 24020006 */  addiu     $v0, $zero, 6
/* EFD4 80033BD4 A6020004 */  sh        $v0, 4($s0)
/* EFD8 80033BD8 24020001 */  addiu     $v0, $zero, 1
/* EFDC 80033BDC A6020006 */  sh        $v0, 6($s0)
/* EFE0 80033BE0 24020010 */  addiu     $v0, $zero, 0x10
/* EFE4 80033BE4 A6020012 */  sh        $v0, 0x12($s0)
/* EFE8 80033BE8 24021000 */  addiu     $v0, $zero, 0x1000
/* EFEC 80033BEC A6020014 */  sh        $v0, 0x14($s0)
/* EFF0 80033BF0 240200B8 */  addiu     $v0, $zero, 0xb8
/* EFF4 80033BF4 3C0141C8 */  lui       $at, 0x41c8
/* EFF8 80033BF8 4481A000 */  mtc1      $at, $f20
/* EFFC 80033BFC 24070128 */  addiu     $a3, $zero, 0x128
/* F000 80033C00 3C018007 */  lui       $at, %hi(D_800773E0)
/* F004 80033C04 AC2073E0 */  sw        $zero, %lo(D_800773E0)($at)
/* F008 80033C08 E6140018 */  swc1      $f20, 0x18($s0)
/* F00C 80033C0C AFA20010 */  sw        $v0, 0x10($sp)
/* F010 80033C10 96020000 */  lhu       $v0, ($s0)
/* F014 80033C14 96030558 */  lhu       $v1, 0x558($s0)
/* F018 80033C18 34420002 */  ori       $v0, $v0, 2
/* F01C 80033C1C A6020000 */  sh        $v0, ($s0)
/* F020 80033C20 96020AB0 */  lhu       $v0, 0xab0($s0)
/* F024 80033C24 34630002 */  ori       $v1, $v1, 2
/* F028 80033C28 A6030558 */  sh        $v1, 0x558($s0)
/* F02C 80033C2C 96031008 */  lhu       $v1, 0x1008($s0)
/* F030 80033C30 34420002 */  ori       $v0, $v0, 2
/* F034 80033C34 34630002 */  ori       $v1, $v1, 2
/* F038 80033C38 A6020AB0 */  sh        $v0, 0xab0($s0)
/* F03C 80033C3C 0C00B7E9 */  jal       func_8002DFA4
/* F040 80033C40 A6031008 */   sh       $v1, 0x1008($s0)
/* F044 80033C44 3C0143FA */  lui       $at, 0x43fa
/* F048 80033C48 44810000 */  mtc1      $at, $f0
/* F04C 80033C4C 3C01447A */  lui       $at, 0x447a
/* F050 80033C50 44811000 */  mtc1      $at, $f2
/* F054 80033C54 3C0144BB */  lui       $at, 0x44bb
/* F058 80033C58 34218000 */  ori       $at, $at, 0x8000
/* F05C 80033C5C 44812000 */  mtc1      $at, $f4
/* F060 80033C60 3C014316 */  lui       $at, 0x4316
/* F064 80033C64 44813000 */  mtc1      $at, $f6
/* F068 80033C68 24020028 */  addiu     $v0, $zero, 0x28
/* F06C 80033C6C A602001E */  sh        $v0, 0x1e($s0)
/* F070 80033C70 24020064 */  addiu     $v0, $zero, 0x64
/* F074 80033C74 A600002C */  sh        $zero, 0x2c($s0)
/* F078 80033C78 A600002E */  sh        $zero, 0x2e($s0)
/* F07C 80033C7C A6000030 */  sh        $zero, 0x30($s0)
/* F080 80033C80 E6140054 */  swc1      $f20, 0x54($s0)
/* F084 80033C84 E6140058 */  swc1      $f20, 0x58($s0)
/* F088 80033C88 A600001C */  sh        $zero, 0x1c($s0)
/* F08C 80033C8C A6020020 */  sh        $v0, 0x20($s0)
/* F090 80033C90 A6000022 */  sh        $zero, 0x22($s0)
/* F094 80033C94 E600003C */  swc1      $f0, 0x3c($s0)
/* F098 80033C98 E6020040 */  swc1      $f2, 0x40($s0)
/* F09C 80033C9C E6040044 */  swc1      $f4, 0x44($s0)
/* F0A0 80033CA0 0C0B0C77 */  jal       func_802C31DC
/* F0A4 80033CA4 E606005C */   swc1     $f6, 0x5c($s0)
/* F0A8 80033CA8 0C04A0B2 */  jal       func_801282C8
/* F0AC 80033CAC 00000000 */   nop
/* F0B0 80033CB0 0C048AA8 */  jal       func_80122AA0
/* F0B4 80033CB4 00000000 */   nop
/* F0B8 80033CB8 0C044512 */  jal       func_80111448
/* F0BC 80033CBC 0000202D */   daddu    $a0, $zero, $zero
/* F0C0 80033CC0 0C048D0D */  jal       func_80123434
/* F0C4 80033CC4 00000000 */   nop
/* F0C8 80033CC8 0C049770 */  jal       func_80125DC0
/* F0CC 80033CCC 00000000 */   nop
/* F0D0 80033CD0 0C00E05F */  jal       func_8003817C
/* F0D4 80033CD4 00000000 */   nop
/* F0D8 80033CD8 0C05186C */  jal       func_801461B0
/* F0DC 80033CDC 00000000 */   nop
/* F0E0 80033CE0 0C052BAA */  jal       func_8014AEA8
/* F0E4 80033CE4 00000000 */   nop
/* F0E8 80033CE8 0C0457B2 */  jal       func_80115EC8
/* F0EC 80033CEC 24040001 */   addiu    $a0, $zero, 1
/* F0F0 80033CF0 0C016653 */  jal       func_8005994C
/* F0F4 80033CF4 00000000 */   nop
/* F0F8 80033CF8 3C03800A */  lui       $v1, %hi(D_8009A630)
/* F0FC 80033CFC 2463A630 */  addiu     $v1, $v1, %lo(D_8009A630)
/* F100 80033D00 8C620000 */  lw        $v0, ($v1)
/* F104 80033D04 34420002 */  ori       $v0, $v0, 2
/* F108 80033D08 0C00CD41 */  jal       func_80033504
/* F10C 80033D0C AC620000 */   sw       $v0, ($v1)
/* F110 80033D10 8E420000 */  lw        $v0, ($s2)
/* F114 80033D14 A4400148 */  sh        $zero, 0x148($v0)
/* F118 80033D18 8FBF0024 */  lw        $ra, 0x24($sp)
/* F11C 80033D1C 8FB20020 */  lw        $s2, 0x20($sp)
/* F120 80033D20 8FB1001C */  lw        $s1, 0x1c($sp)
/* F124 80033D24 8FB00018 */  lw        $s0, 0x18($sp)
/* F128 80033D28 D7B40028 */  ldc1      $f20, 0x28($sp)
/* F12C 80033D2C 03E00008 */  jr        $ra
/* F130 80033D30 27BD0030 */   addiu    $sp, $sp, 0x30
