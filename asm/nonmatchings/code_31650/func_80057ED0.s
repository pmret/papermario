.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057ED0
/* 332D0 80057ED0 0000302D */  daddu     $a2, $zero, $zero
/* 332D4 80057ED4 3C05800A */  lui       $a1, %hi(D_800A3FE0)
/* 332D8 80057ED8 8CA53FE0 */  lw        $a1, %lo(D_800A3FE0)($a1)
/* 332DC 80057EDC 3C03800A */  lui       $v1, %hi(D_800A3FE4)
/* 332E0 80057EE0 8C633FE4 */  lw        $v1, %lo(D_800A3FE4)($v1)
.L80057EE4:
/* 332E4 80057EE4 ACA00000 */  sw        $zero, ($a1)
/* 332E8 80057EE8 24A50004 */  addiu     $a1, $a1, 4
/* 332EC 80057EEC AC600000 */  sw        $zero, ($v1)
/* 332F0 80057EF0 24C60001 */  addiu     $a2, $a2, 1
/* 332F4 80057EF4 28C20170 */  slti      $v0, $a2, 0x170
/* 332F8 80057EF8 1440FFFA */  bnez      $v0, .L80057EE4
/* 332FC 80057EFC 24630004 */   addiu    $v1, $v1, 4
/* 33300 80057F00 3C01800A */  lui       $at, %hi(D_800A3FEC)
/* 33304 80057F04 A0203FEC */  sb        $zero, %lo(D_800A3FEC)($at)
/* 33308 80057F08 3C01800A */  lui       $at, %hi(D_800A3FEE)
/* 3330C 80057F0C A4243FEE */  sh        $a0, %lo(D_800A3FEE)($at)
/* 33310 80057F10 3C01800A */  lui       $at, %hi(D_800A3FE8)
/* 33314 80057F14 AC203FE8 */  sw        $zero, %lo(D_800A3FE8)($at)
/* 33318 80057F18 03E00008 */  jr        $ra
/* 3331C 80057F1C 00000000 */   nop      
