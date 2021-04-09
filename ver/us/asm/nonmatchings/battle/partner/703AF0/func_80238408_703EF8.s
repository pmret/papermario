.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238408_703EF8
/* 703EF8 80238408 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 703EFC 8023840C AFBF0010 */  sw        $ra, 0x10($sp)
/* 703F00 80238410 8C82000C */  lw        $v0, 0xc($a0)
/* 703F04 80238414 0C0B1EAF */  jal       get_variable
/* 703F08 80238418 8C450000 */   lw       $a1, ($v0)
/* 703F0C 8023841C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 703F10 80238420 3C018024 */  lui       $at, %hi(D_8023C1C8)
/* 703F14 80238424 AC22C1C8 */  sw        $v0, %lo(D_8023C1C8)($at)
/* 703F18 80238428 24020002 */  addiu     $v0, $zero, 2
/* 703F1C 8023842C 03E00008 */  jr        $ra
/* 703F20 80238430 27BD0018 */   addiu    $sp, $sp, 0x18
