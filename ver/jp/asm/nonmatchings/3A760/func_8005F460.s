.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F460
/* 3A860 8005F460 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 3A864 8005F464 AFBF002C */  sw        $ra, 0x2c($sp)
/* 3A868 8005F468 AFB20028 */  sw        $s2, 0x28($sp)
/* 3A86C 8005F46C AFB10024 */  sw        $s1, 0x24($sp)
/* 3A870 8005F470 AFB00020 */  sw        $s0, 0x20($sp)
/* 3A874 8005F474 8C90000C */  lw        $s0, 0xc($a0)
/* 3A878 8005F478 3C058009 */  lui       $a1, %hi(D_80093C70)
/* 3A87C 8005F47C 94A53C70 */  lhu       $a1, %lo(D_80093C70)($a1)
/* 3A880 8005F480 3C068009 */  lui       $a2, %hi(D_80093C74)
/* 3A884 8005F484 8CC63C74 */  lw        $a2, %lo(D_80093C74)($a2)
/* 3A888 8005F488 8E110000 */  lw        $s1, ($s0)
/* 3A88C 8005F48C 8E020008 */  lw        $v0, 8($s0)
/* 3A890 8005F490 26320004 */  addiu     $s2, $s1, 4
/* 3A894 8005F494 AFA20010 */  sw        $v0, 0x10($sp)
/* 3A898 8005F498 AFB20014 */  sw        $s2, 0x14($sp)
/* 3A89C 8005F49C 8E240000 */  lw        $a0, ($s1)
/* 3A8A0 8005F4A0 0C01A368 */  jal       func_80068DA0
/* 3A8A4 8005F4A4 8E070004 */   lw       $a3, 4($s0)
/* 3A8A8 8005F4A8 0040202D */  daddu     $a0, $v0, $zero
/* 3A8AC 8005F4AC 24020005 */  addiu     $v0, $zero, 5
/* 3A8B0 8005F4B0 14820011 */  bne       $a0, $v0, .L8005F4F8
/* 3A8B4 8005F4B4 24020001 */   addiu    $v0, $zero, 1
/* 3A8B8 8005F4B8 8E030010 */  lw        $v1, 0x10($s0)
/* 3A8BC 8005F4BC 1462000E */  bne       $v1, $v0, .L8005F4F8
/* 3A8C0 8005F4C0 00000000 */   nop
/* 3A8C4 8005F4C4 8E020008 */  lw        $v0, 8($s0)
/* 3A8C8 8005F4C8 3C058009 */  lui       $a1, %hi(D_80093C70)
/* 3A8CC 8005F4CC 94A53C70 */  lhu       $a1, %lo(D_80093C70)($a1)
/* 3A8D0 8005F4D0 3C068009 */  lui       $a2, %hi(D_80093C74)
/* 3A8D4 8005F4D4 8CC63C74 */  lw        $a2, %lo(D_80093C74)($a2)
/* 3A8D8 8005F4D8 AFA20010 */  sw        $v0, 0x10($sp)
/* 3A8DC 8005F4DC 8E02000C */  lw        $v0, 0xc($s0)
/* 3A8E0 8005F4E0 AFB20018 */  sw        $s2, 0x18($sp)
/* 3A8E4 8005F4E4 AFA20014 */  sw        $v0, 0x14($sp)
/* 3A8E8 8005F4E8 8E240000 */  lw        $a0, ($s1)
/* 3A8EC 8005F4EC 0C01A05C */  jal       func_80068170
/* 3A8F0 8005F4F0 8E070004 */   lw       $a3, 4($s0)
/* 3A8F4 8005F4F4 0040202D */  daddu     $a0, $v0, $zero
.L8005F4F8:
/* 3A8F8 8005F4F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* 3A8FC 8005F4FC 8FB20028 */  lw        $s2, 0x28($sp)
/* 3A900 8005F500 8FB10024 */  lw        $s1, 0x24($sp)
/* 3A904 8005F504 8FB00020 */  lw        $s0, 0x20($sp)
/* 3A908 8005F508 0080102D */  daddu     $v0, $a0, $zero
/* 3A90C 8005F50C 03E00008 */  jr        $ra
/* 3A910 8005F510 27BD0030 */   addiu    $sp, $sp, 0x30
