.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80043EF8
/* 1F2F8 80043EF8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1F2FC 80043EFC AFBF0010 */  sw        $ra, 0x10($sp)
/* 1F300 80043F00 8C82000C */  lw        $v0, 0xc($a0)
/* 1F304 80043F04 0C0B1EAF */  jal       func_802C7ABC
/* 1F308 80043F08 8C450000 */   lw       $a1, ($v0)
/* 1F30C 80043F0C 0C01CAEB */  jal       func_80072BAC
/* 1F310 80043F10 0040202D */   daddu    $a0, $v0, $zero
/* 1F314 80043F14 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1F318 80043F18 24020002 */  addiu     $v0, $zero, 2
/* 1F31C 80043F1C 03E00008 */  jr        $ra
/* 1F320 80043F20 27BD0018 */   addiu    $sp, $sp, 0x18
