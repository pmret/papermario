.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026880C
/* 1970EC 8026880C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1970F0 80268810 24020002 */  addiu     $v0, $zero, 2
/* 1970F4 80268814 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1970F8 80268818 3C01802A */  lui       $at, %hi(D_8029FBC0)
/* 1970FC 8026881C AC22FBC0 */  sw        $v0, %lo(D_8029FBC0)($at)
/* 197100 80268820 0C09A0A1 */  jal       func_80268284
/* 197104 80268824 2407FFFF */   addiu    $a3, $zero, -1
/* 197108 80268828 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19710C 8026882C 03E00008 */  jr        $ra
/* 197110 80268830 27BD0018 */   addiu    $sp, $sp, 0x18
