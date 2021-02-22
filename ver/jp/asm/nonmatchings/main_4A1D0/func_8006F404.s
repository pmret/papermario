.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006F404
/* 4A804 8006F404 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4A808 8006F408 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4A80C 8006F40C AFA40020 */  sw        $a0, 0x20($sp)
/* 4A810 8006F410 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A814 8006F414 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A818 8006F418 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A81C 8006F41C 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A820 8006F420 3C010001 */  lui       $at, 1
/* 4A824 8006F424 00A17025 */  or        $t6, $a1, $at
/* 4A828 8006F428 01C02825 */  or        $a1, $t6, $zero
/* 4A82C 8006F42C 8FA60020 */  lw        $a2, 0x20($sp)
/* 4A830 8006F430 3C014B00 */  lui       $at, 0x4b00
/* 4A834 8006F434 00C17825 */  or        $t7, $a2, $at
/* 4A838 8006F438 01E03025 */  or        $a2, $t7, $zero
/* 4A83C 8006F43C 0C01834C */  jal       func_80060D30
/* 4A840 8006F440 00000000 */   nop
/* 4A844 8006F444 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A848 8006F448 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A84C 8006F44C 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A850 8006F450 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A854 8006F454 3C010001 */  lui       $at, 1
/* 4A858 8006F458 00A1C025 */  or        $t8, $a1, $at
/* 4A85C 8006F45C 03002825 */  or        $a1, $t8, $zero
/* 4A860 8006F460 3C067800 */  lui       $a2, 0x7800
/* 4A864 8006F464 0C01834C */  jal       func_80060D30
/* 4A868 8006F468 00000000 */   nop
.L8006F46C:
/* 4A86C 8006F46C 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A870 8006F470 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A874 8006F474 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A878 8006F478 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A87C 8006F47C 27A6001C */  addiu     $a2, $sp, 0x1c
/* 4A880 8006F480 0C018364 */  jal       func_80060D90
/* 4A884 8006F484 00000000 */   nop
/* 4A888 8006F488 8FB9001C */  lw        $t9, 0x1c($sp)
/* 4A88C 8006F48C 00000000 */  nop
/* 4A890 8006F490 33280002 */  andi      $t0, $t9, 2
/* 4A894 8006F494 24010002 */  addiu     $at, $zero, 2
/* 4A898 8006F498 1101FFF4 */  beq       $t0, $at, .L8006F46C
/* 4A89C 8006F49C 00000000 */   nop
/* 4A8A0 8006F4A0 3C04800B */  lui       $a0, %hi(D_800B0C50)
/* 4A8A4 8006F4A4 24840C50 */  addiu     $a0, $a0, %lo(D_800B0C50)
/* 4A8A8 8006F4A8 3C05800B */  lui       $a1, %hi(D_800B0C5C)
/* 4A8AC 8006F4AC 8CA50C5C */  lw        $a1, %lo(D_800B0C5C)($a1)
/* 4A8B0 8006F4B0 27A6001C */  addiu     $a2, $sp, 0x1c
/* 4A8B4 8006F4B4 0C018364 */  jal       func_80060D90
/* 4A8B8 8006F4B8 00000000 */   nop
/* 4A8BC 8006F4BC 0C01BC9F */  jal       func_8006F27C
/* 4A8C0 8006F4C0 00000000 */   nop
/* 4A8C4 8006F4C4 8FA9001C */  lw        $t1, 0x1c($sp)
/* 4A8C8 8006F4C8 00000000 */  nop
/* 4A8CC 8006F4CC 312A00FF */  andi      $t2, $t1, 0xff
/* 4A8D0 8006F4D0 24010008 */  addiu     $at, $zero, 8
/* 4A8D4 8006F4D4 11410008 */  beq       $t2, $at, .L8006F4F8
/* 4A8D8 8006F4D8 00000000 */   nop
/* 4A8DC 8006F4DC 24010048 */  addiu     $at, $zero, 0x48
/* 4A8E0 8006F4E0 11410005 */  beq       $t2, $at, .L8006F4F8
/* 4A8E4 8006F4E4 00000000 */   nop
/* 4A8E8 8006F4E8 312B0008 */  andi      $t3, $t1, 8
/* 4A8EC 8006F4EC 24010008 */  addiu     $at, $zero, 8
/* 4A8F0 8006F4F0 15610006 */  bne       $t3, $at, .L8006F50C
/* 4A8F4 8006F4F4 00000000 */   nop
.L8006F4F8:
/* 4A8F8 8006F4F8 00001025 */  or        $v0, $zero, $zero
/* 4A8FC 8006F4FC 10000008 */  b         .L8006F520
/* 4A900 8006F500 00000000 */   nop
/* 4A904 8006F504 10000004 */  b         .L8006F518
/* 4A908 8006F508 00000000 */   nop
.L8006F50C:
/* 4A90C 8006F50C 2402FFFF */  addiu     $v0, $zero, -1
/* 4A910 8006F510 10000003 */  b         .L8006F520
/* 4A914 8006F514 00000000 */   nop
.L8006F518:
/* 4A918 8006F518 10000001 */  b         .L8006F520
/* 4A91C 8006F51C 00000000 */   nop
.L8006F520:
/* 4A920 8006F520 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4A924 8006F524 27BD0020 */  addiu     $sp, $sp, 0x20
/* 4A928 8006F528 03E00008 */  jr        $ra
/* 4A92C 8006F52C 00000000 */   nop
