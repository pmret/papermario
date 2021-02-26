.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057B0C
/* 32F0C 80057B0C 0000302D */  daddu     $a2, $zero, $zero
/* 32F10 80057B10 3C05800A */  lui       $a1, %hi(D_800A1DF0)
/* 32F14 80057B14 8CA51DF0 */  lw        $a1, %lo(D_800A1DF0)($a1)
/* 32F18 80057B18 3C03800A */  lui       $v1, %hi(D_800A1DF4)
/* 32F1C 80057B1C 8C631DF4 */  lw        $v1, %lo(D_800A1DF4)($v1)
.L80057B20:
/* 32F20 80057B20 ACA00000 */  sw        $zero, ($a1)
/* 32F24 80057B24 24A50004 */  addiu     $a1, $a1, 4
/* 32F28 80057B28 AC600000 */  sw        $zero, ($v1)
/* 32F2C 80057B2C 24C60001 */  addiu     $a2, $a2, 1
/* 32F30 80057B30 28C20170 */  slti      $v0, $a2, 0x170
/* 32F34 80057B34 1440FFFA */  bnez      $v0, .L80057B20
/* 32F38 80057B38 24630004 */   addiu    $v1, $v1, 4
/* 32F3C 80057B3C 24020002 */  addiu     $v0, $zero, 2
/* 32F40 80057B40 3C01800A */  lui       $at, %hi(D_800A1DFC)
/* 32F44 80057B44 A0241DFC */  sb        $a0, %lo(D_800A1DFC)($at)
/* 32F48 80057B48 3C01800A */  lui       $at, %hi(D_800A1DFE)
/* 32F4C 80057B4C A4221DFE */  sh        $v0, %lo(D_800A1DFE)($at)
/* 32F50 80057B50 3C01800A */  lui       $at, %hi(D_800A1DF8)
/* 32F54 80057B54 AC201DF8 */  sw        $zero, %lo(D_800A1DF8)($at)
/* 32F58 80057B58 03E00008 */  jr        $ra
/* 32F5C 80057B5C 00000000 */   nop
