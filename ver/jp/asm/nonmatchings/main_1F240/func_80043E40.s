.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80043E40
/* 1F240 80043E40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1F244 80043E44 AFB10014 */  sw        $s1, 0x14($sp)
/* 1F248 80043E48 3C11800B */  lui       $s1, %hi(D_800B0EF0)
/* 1F24C 80043E4C 26310EF0 */  addiu     $s1, $s1, %lo(D_800B0EF0)
/* 1F250 80043E50 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1F254 80043E54 AFB20018 */  sw        $s2, 0x18($sp)
/* 1F258 80043E58 AFB00010 */  sw        $s0, 0x10($sp)
/* 1F25C 80043E5C 8C82000C */  lw        $v0, 0xc($a0)
/* 1F260 80043E60 8C450004 */  lw        $a1, 4($v0)
/* 1F264 80043E64 8C500000 */  lw        $s0, ($v0)
/* 1F268 80043E68 0C0B1EAF */  jal       func_802C7ABC
/* 1F26C 80043E6C 0220902D */   daddu    $s2, $s1, $zero
/* 1F270 80043E70 10400005 */  beqz      $v0, .L80043E88
/* 1F274 80043E74 00101827 */   nor      $v1, $zero, $s0
/* 1F278 80043E78 8E220000 */  lw        $v0, ($s1)
/* 1F27C 80043E7C 00501025 */  or        $v0, $v0, $s0
/* 1F280 80043E80 08010FA5 */  j         .L80043E94
/* 1F284 80043E84 AE220000 */   sw       $v0, ($s1)
.L80043E88:
/* 1F288 80043E88 8E420000 */  lw        $v0, ($s2)
/* 1F28C 80043E8C 00431024 */  and       $v0, $v0, $v1
/* 1F290 80043E90 AE420000 */  sw        $v0, ($s2)
.L80043E94:
/* 1F294 80043E94 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1F298 80043E98 8FB20018 */  lw        $s2, 0x18($sp)
/* 1F29C 80043E9C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1F2A0 80043EA0 8FB00010 */  lw        $s0, 0x10($sp)
/* 1F2A4 80043EA4 24020002 */  addiu     $v0, $zero, 2
/* 1F2A8 80043EA8 03E00008 */  jr        $ra
/* 1F2AC 80043EAC 27BD0020 */   addiu    $sp, $sp, 0x20
