.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80260AD4
/* 18F3B4 80260AD4 3C03800E */  lui       $v1, 0x800e
/* 18F3B8 80260AD8 8C63C148 */  lw        $v1, -0x3eb8($v1)
/* 18F3BC 80260ADC 90620210 */  lbu       $v0, 0x210($v1)
/* 18F3C0 80260AE0 80630214 */  lb        $v1, 0x214($v1)
/* 18F3C4 80260AE4 2442FFFD */  addiu     $v0, $v0, -3
/* 18F3C8 80260AE8 2C450006 */  sltiu     $a1, $v0, 6
/* 18F3CC 80260AEC 2402000C */  addiu     $v0, $zero, 0xc
/* 18F3D0 80260AF0 50620001 */  beql      $v1, $v0, .L80260AF8
/* 18F3D4 80260AF4 24050001 */   addiu    $a1, $zero, 1
.L80260AF8:
/* 18F3D8 80260AF8 AC850084 */  sw        $a1, 0x84($a0)
/* 18F3DC 80260AFC 03E00008 */  jr        $ra
/* 18F3E0 80260B00 24020002 */   addiu    $v0, $zero, 2
