.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243314_96C4D4
/* 96C4D4 80243314 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96C4D8 80243318 AFBF0010 */  sw        $ra, 0x10($sp)
/* 96C4DC 8024331C 8C82000C */  lw        $v0, 0xc($a0)
/* 96C4E0 80243320 0C0B1EAF */  jal       get_variable
/* 96C4E4 80243324 8C450000 */   lw       $a1, ($v0)
/* 96C4E8 80243328 3C018025 */  lui       $at, 0x8025
/* 96C4EC 8024332C AC228784 */  sw        $v0, -0x787c($at)
/* 96C4F0 80243330 24020002 */  addiu     $v0, $zero, 2
/* 96C4F4 80243334 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96C4F8 80243338 24030001 */  addiu     $v1, $zero, 1
/* 96C4FC 8024333C 3C018025 */  lui       $at, 0x8025
/* 96C500 80243340 AC238780 */  sw        $v1, -0x7880($at)
/* 96C504 80243344 03E00008 */  jr        $ra
/* 96C508 80243348 27BD0018 */   addiu    $sp, $sp, 0x18
