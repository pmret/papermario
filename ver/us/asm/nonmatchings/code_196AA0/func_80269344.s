.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80269344
/* 197C24 80269344 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197C28 80269348 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197C2C 8026934C 8C82000C */  lw        $v0, 0xc($a0)
/* 197C30 80269350 0C0B1EAF */  jal       get_variable
/* 197C34 80269354 8C450000 */   lw       $a1, ($v0)
/* 197C38 80269358 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197C3C 8026935C 3C01802A */  lui       $at, %hi(D_8029FC4C)
/* 197C40 80269360 A422FC4C */  sh        $v0, %lo(D_8029FC4C)($at)
/* 197C44 80269364 24020002 */  addiu     $v0, $zero, 2
/* 197C48 80269368 03E00008 */  jr        $ra
/* 197C4C 8026936C 27BD0018 */   addiu    $sp, $sp, 0x18
