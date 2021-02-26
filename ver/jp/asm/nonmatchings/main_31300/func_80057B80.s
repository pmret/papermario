.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057B80
/* 32F80 80057B80 0000302D */  daddu     $a2, $zero, $zero
/* 32F84 80057B84 3C05800A */  lui       $a1, %hi(D_800A1DF0)
/* 32F88 80057B88 8CA51DF0 */  lw        $a1, %lo(D_800A1DF0)($a1)
/* 32F8C 80057B8C 3C03800A */  lui       $v1, %hi(D_800A1DF4)
/* 32F90 80057B90 8C631DF4 */  lw        $v1, %lo(D_800A1DF4)($v1)
.L80057B94:
/* 32F94 80057B94 ACA00000 */  sw        $zero, ($a1)
/* 32F98 80057B98 24A50004 */  addiu     $a1, $a1, 4
/* 32F9C 80057B9C AC600000 */  sw        $zero, ($v1)
/* 32FA0 80057BA0 24C60001 */  addiu     $a2, $a2, 1
/* 32FA4 80057BA4 28C20170 */  slti      $v0, $a2, 0x170
/* 32FA8 80057BA8 1440FFFA */  bnez      $v0, .L80057B94
/* 32FAC 80057BAC 24630004 */   addiu    $v1, $v1, 4
/* 32FB0 80057BB0 3C01800A */  lui       $at, %hi(D_800A1DFC)
/* 32FB4 80057BB4 A0201DFC */  sb        $zero, %lo(D_800A1DFC)($at)
/* 32FB8 80057BB8 3C01800A */  lui       $at, %hi(D_800A1DFE)
/* 32FBC 80057BBC A4241DFE */  sh        $a0, %lo(D_800A1DFE)($at)
/* 32FC0 80057BC0 3C01800A */  lui       $at, %hi(D_800A1DF8)
/* 32FC4 80057BC4 AC201DF8 */  sw        $zero, %lo(D_800A1DF8)($at)
/* 32FC8 80057BC8 03E00008 */  jr        $ra
/* 32FCC 80057BCC 00000000 */   nop
