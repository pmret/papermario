.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D14_908744
/* 908744 80240D14 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 908748 80240D18 3C05FD05 */  lui       $a1, 0xfd05
/* 90874C 80240D1C 34A50F80 */  ori       $a1, $a1, 0xf80
/* 908750 80240D20 AFBF0010 */  sw        $ra, 0x10($sp)
/* 908754 80240D24 0C0B1EAF */  jal       evt_get_variable
/* 908758 80240D28 0000202D */   daddu    $a0, $zero, $zero
/* 90875C 80240D2C 24030001 */  addiu     $v1, $zero, 1
/* 908760 80240D30 3C05800A */  lui       $a1, %hi(gOverrideFlags)
/* 908764 80240D34 24A5A650 */  addiu     $a1, $a1, %lo(gOverrideFlags)
/* 908768 80240D38 A443001E */  sh        $v1, 0x1e($v0)
/* 90876C 80240D3C 8CA30000 */  lw        $v1, ($a1)
/* 908770 80240D40 3C040010 */  lui       $a0, 0x10
/* 908774 80240D44 00641825 */  or        $v1, $v1, $a0
/* 908778 80240D48 ACA30000 */  sw        $v1, ($a1)
/* 90877C 80240D4C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 908780 80240D50 24020002 */  addiu     $v0, $zero, 2
/* 908784 80240D54 03E00008 */  jr        $ra
/* 908788 80240D58 27BD0018 */   addiu    $sp, $sp, 0x18
