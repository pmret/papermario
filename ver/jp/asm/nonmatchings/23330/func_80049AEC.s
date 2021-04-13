.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80049AEC
/* 24EEC 80049AEC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 24EF0 80049AF0 AFB20018 */  sw        $s2, 0x18($sp)
/* 24EF4 80049AF4 0080902D */  daddu     $s2, $a0, $zero
/* 24EF8 80049AF8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 24EFC 80049AFC AFB10014 */  sw        $s1, 0x14($sp)
/* 24F00 80049B00 AFB00010 */  sw        $s0, 0x10($sp)
/* 24F04 80049B04 8E510148 */  lw        $s1, 0x148($s2)
/* 24F08 80049B08 0C00E9EB */  jal       func_8003A7AC
/* 24F0C 80049B0C 86240008 */   lh       $a0, 8($s1)
/* 24F10 80049B10 0040802D */  daddu     $s0, $v0, $zero
/* 24F14 80049B14 0200202D */  daddu     $a0, $s0, $zero
/* 24F18 80049B18 240503E1 */  addiu     $a1, $zero, 0x3e1
/* 24F1C 80049B1C 0C01245C */  jal       func_80049170
/* 24F20 80049B20 0000302D */   daddu    $a2, $zero, $zero
/* 24F24 80049B24 8E2200CC */  lw        $v0, 0xcc($s1)
/* 24F28 80049B28 3C014120 */  lui       $at, 0x4120
/* 24F2C 80049B2C 44812000 */  mtc1      $at, $f4
/* 24F30 80049B30 3C014020 */  lui       $at, 0x4020
/* 24F34 80049B34 44810000 */  mtc1      $at, $f0
/* 24F38 80049B38 C602003C */  lwc1      $f2, 0x3c($s0)
/* 24F3C 80049B3C 8C430010 */  lw        $v1, 0x10($v0)
/* 24F40 80049B40 8E020000 */  lw        $v0, ($s0)
/* 24F44 80049B44 E604001C */  swc1      $f4, 0x1c($s0)
/* 24F48 80049B48 E6000014 */  swc1      $f0, 0x14($s0)
/* 24F4C 80049B4C E6020064 */  swc1      $f2, 0x64($s0)
/* 24F50 80049B50 34420800 */  ori       $v0, $v0, 0x800
/* 24F54 80049B54 AE020000 */  sw        $v0, ($s0)
/* 24F58 80049B58 2402000B */  addiu     $v0, $zero, 0xb
/* 24F5C 80049B5C AE030028 */  sw        $v1, 0x28($s0)
/* 24F60 80049B60 AE420070 */  sw        $v0, 0x70($s2)
/* 24F64 80049B64 8FBF001C */  lw        $ra, 0x1c($sp)
/* 24F68 80049B68 8FB20018 */  lw        $s2, 0x18($sp)
/* 24F6C 80049B6C 8FB10014 */  lw        $s1, 0x14($sp)
/* 24F70 80049B70 8FB00010 */  lw        $s0, 0x10($sp)
/* 24F74 80049B74 03E00008 */  jr        $ra
/* 24F78 80049B78 27BD0020 */   addiu    $sp, $sp, 0x20
