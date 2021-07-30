.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F100
/* 3A500 8005F100 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A504 8005F104 24040096 */  addiu     $a0, $zero, 0x96
/* 3A508 8005F108 3C05800B */  lui       $a1, %hi(D_800AA3E0)
/* 3A50C 8005F10C 24A5A3E0 */  addiu     $a1, $a1, %lo(D_800AA3E0)
/* 3A510 8005F110 3C06800B */  lui       $a2, %hi(D_800AA3F8)
/* 3A514 8005F114 24C6A3F8 */  addiu     $a2, $a2, %lo(D_800AA3F8)
/* 3A518 8005F118 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3A51C 8005F11C 0C01826C */  jal       func_800609B0
/* 3A520 8005F120 24070032 */   addiu    $a3, $zero, 0x32
/* 3A524 8005F124 0C0183B8 */  jal       func_80060EE0
/* 3A528 8005F128 00000000 */   nop
/* 3A52C 8005F12C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3A530 8005F130 3C01800A */  lui       $at, %hi(nuPiCartHandle)
/* 3A534 8005F134 AC22A618 */  sw        $v0, %lo(nuPiCartHandle)($at)
/* 3A538 8005F138 03E00008 */  jr        $ra
/* 3A53C 8005F13C 27BD0018 */   addiu    $sp, $sp, 0x18
