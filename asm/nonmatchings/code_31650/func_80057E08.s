.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057E08
/* 33208 80057E08 0000302D */  daddu     $a2, $zero, $zero
/* 3320C 80057E0C 3C05800A */  lui       $a1, %hi(D_800A3FE0)
/* 33210 80057E10 8CA53FE0 */  lw        $a1, %lo(D_800A3FE0)($a1)
/* 33214 80057E14 3C03800A */  lui       $v1, %hi(D_800A3FE4)
/* 33218 80057E18 8C633FE4 */  lw        $v1, %lo(D_800A3FE4)($v1)
.L80057E1C:
/* 3321C 80057E1C ACA00000 */  sw        $zero, ($a1)
/* 33220 80057E20 24A50004 */  addiu     $a1, $a1, 4
/* 33224 80057E24 AC600000 */  sw        $zero, ($v1)
/* 33228 80057E28 24C60001 */  addiu     $a2, $a2, 1
/* 3322C 80057E2C 28C20170 */  slti      $v0, $a2, 0x170
/* 33230 80057E30 1440FFFA */  bnez      $v0, .L80057E1C
/* 33234 80057E34 24630004 */   addiu    $v1, $v1, 4
/* 33238 80057E38 24020001 */  addiu     $v0, $zero, 1
/* 3323C 80057E3C 3C01800A */  lui       $at, %hi(D_800A3FEC)
/* 33240 80057E40 A0243FEC */  sb        $a0, %lo(D_800A3FEC)($at)
/* 33244 80057E44 3C01800A */  lui       $at, %hi(D_800A3FEE)
/* 33248 80057E48 A4223FEE */  sh        $v0, %lo(D_800A3FEE)($at)
/* 3324C 80057E4C 3C01800A */  lui       $at, %hi(D_800A3FE8)
/* 33250 80057E50 AC203FE8 */  sw        $zero, %lo(D_800A3FE8)($at)
/* 33254 80057E54 03E00008 */  jr        $ra
/* 33258 80057E58 00000000 */   nop      
