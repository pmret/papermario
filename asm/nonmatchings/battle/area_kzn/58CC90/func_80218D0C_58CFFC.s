.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218D0C_58CFFC
/* 58CFFC 80218D0C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 58D000 80218D10 AFB10014 */  sw        $s1, 0x14($sp)
/* 58D004 80218D14 0080882D */  daddu     $s1, $a0, $zero
/* 58D008 80218D18 AFB20018 */  sw        $s2, 0x18($sp)
/* 58D00C 80218D1C 3C128011 */  lui       $s2, %hi(gPlayerData)
/* 58D010 80218D20 2652F290 */  addiu     $s2, $s2, %lo(gPlayerData)
/* 58D014 80218D24 AFBF001C */  sw        $ra, 0x1c($sp)
/* 58D018 80218D28 AFB00010 */  sw        $s0, 0x10($sp)
/* 58D01C 80218D2C 8E30000C */  lw        $s0, 0xc($s1)
/* 58D020 80218D30 82460000 */  lb        $a2, ($s2)
/* 58D024 80218D34 8E050000 */  lw        $a1, ($s0)
/* 58D028 80218D38 0C0B2026 */  jal       set_variable
/* 58D02C 80218D3C 26100004 */   addiu    $s0, $s0, 4
/* 58D030 80218D40 8E050000 */  lw        $a1, ($s0)
/* 58D034 80218D44 82460001 */  lb        $a2, 1($s2)
/* 58D038 80218D48 0C0B2026 */  jal       set_variable
/* 58D03C 80218D4C 0220202D */   daddu    $a0, $s1, $zero
/* 58D040 80218D50 8FBF001C */  lw        $ra, 0x1c($sp)
/* 58D044 80218D54 8FB20018 */  lw        $s2, 0x18($sp)
/* 58D048 80218D58 8FB10014 */  lw        $s1, 0x14($sp)
/* 58D04C 80218D5C 8FB00010 */  lw        $s0, 0x10($sp)
/* 58D050 80218D60 24020002 */  addiu     $v0, $zero, 2
/* 58D054 80218D64 03E00008 */  jr        $ra
/* 58D058 80218D68 27BD0020 */   addiu    $sp, $sp, 0x20
