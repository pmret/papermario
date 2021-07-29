.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80035AD4
/* 10ED4 80035AD4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 10ED8 80035AD8 24020004 */  addiu     $v0, $zero, 4
/* 10EDC 80035ADC AFB10014 */  sw        $s1, 0x14($sp)
/* 10EE0 80035AE0 3C118007 */  lui       $s1, %hi(D_8007417C)
/* 10EE4 80035AE4 2631417C */  addiu     $s1, $s1, %lo(D_8007417C)
/* 10EE8 80035AE8 AFB00010 */  sw        $s0, 0x10($sp)
/* 10EEC 80035AEC 3C10800A */  lui       $s0, %hi(D_8009E750)
/* 10EF0 80035AF0 2610E750 */  addiu     $s0, $s0, %lo(D_8009E750)
/* 10EF4 80035AF4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 10EF8 80035AF8 3C01800A */  lui       $at, %hi(D_8009E754)
/* 10EFC 80035AFC A420E754 */  sh        $zero, %lo(D_8009E754)($at)
/* 10F00 80035B00 3C01800A */  lui       $at, %hi(D_8009E756)
/* 10F04 80035B04 A422E756 */  sh        $v0, %lo(D_8009E756)($at)
/* 10F08 80035B08 8E230000 */  lw        $v1, ($s1)
/* 10F0C 80035B0C 240200FF */  addiu     $v0, $zero, 0xff
/* 10F10 80035B10 A6020000 */  sh        $v0, ($s0)
/* 10F14 80035B14 0C017F5C */  jal       func_8005FD70
/* 10F18 80035B18 AC600094 */   sw       $zero, 0x94($v1)
/* 10F1C 80035B1C 0C04F4D7 */  jal       func_8013D35C
/* 10F20 80035B20 0200202D */   daddu    $a0, $s0, $zero
/* 10F24 80035B24 0000202D */  daddu     $a0, $zero, $zero
/* 10F28 80035B28 3C05F5DE */  lui       $a1, 0xf5de
/* 10F2C 80035B2C 3C03800A */  lui       $v1, %hi(D_8009A630)
/* 10F30 80035B30 2463A630 */  addiu     $v1, $v1, %lo(D_8009A630)
/* 10F34 80035B34 8C620000 */  lw        $v0, ($v1)
/* 10F38 80035B38 8E260000 */  lw        $a2, ($s1)
/* 10F3C 80035B3C 34420008 */  ori       $v0, $v0, 8
/* 10F40 80035B40 AC620000 */  sw        $v0, ($v1)
/* 10F44 80035B44 80C600A9 */  lb        $a2, 0xa9($a2)
/* 10F48 80035B48 0C0B2026 */  jal       func_802C8098
/* 10F4C 80035B4C 34A50181 */   ori      $a1, $a1, 0x181
/* 10F50 80035B50 8FBF0018 */  lw        $ra, 0x18($sp)
/* 10F54 80035B54 8FB10014 */  lw        $s1, 0x14($sp)
/* 10F58 80035B58 8FB00010 */  lw        $s0, 0x10($sp)
/* 10F5C 80035B5C 3C01800A */  lui       $at, %hi(D_8009A5B8)
/* 10F60 80035B60 AC20A5B8 */  sw        $zero, %lo(D_8009A5B8)($at)
/* 10F64 80035B64 03E00008 */  jr        $ra
/* 10F68 80035B68 27BD0020 */   addiu    $sp, $sp, 0x20
