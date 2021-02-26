.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057AB8
/* 32EB8 80057AB8 0000302D */  daddu     $a2, $zero, $zero
/* 32EBC 80057ABC 3C05800A */  lui       $a1, %hi(D_800A1DF0)
/* 32EC0 80057AC0 8CA51DF0 */  lw        $a1, %lo(D_800A1DF0)($a1)
/* 32EC4 80057AC4 3C03800A */  lui       $v1, %hi(D_800A1DF4)
/* 32EC8 80057AC8 8C631DF4 */  lw        $v1, %lo(D_800A1DF4)($v1)
.L80057ACC:
/* 32ECC 80057ACC ACA00000 */  sw        $zero, ($a1)
/* 32ED0 80057AD0 24A50004 */  addiu     $a1, $a1, 4
/* 32ED4 80057AD4 AC600000 */  sw        $zero, ($v1)
/* 32ED8 80057AD8 24C60001 */  addiu     $a2, $a2, 1
/* 32EDC 80057ADC 28C20170 */  slti      $v0, $a2, 0x170
/* 32EE0 80057AE0 1440FFFA */  bnez      $v0, .L80057ACC
/* 32EE4 80057AE4 24630004 */   addiu    $v1, $v1, 4
/* 32EE8 80057AE8 24020001 */  addiu     $v0, $zero, 1
/* 32EEC 80057AEC 3C01800A */  lui       $at, %hi(D_800A1DFC)
/* 32EF0 80057AF0 A0241DFC */  sb        $a0, %lo(D_800A1DFC)($at)
/* 32EF4 80057AF4 3C01800A */  lui       $at, %hi(D_800A1DFE)
/* 32EF8 80057AF8 A4221DFE */  sh        $v0, %lo(D_800A1DFE)($at)
/* 32EFC 80057AFC 3C01800A */  lui       $at, %hi(D_800A1DF8)
/* 32F00 80057B00 AC201DF8 */  sw        $zero, %lo(D_800A1DF8)($at)
/* 32F04 80057B04 03E00008 */  jr        $ra
/* 32F08 80057B08 00000000 */   nop
