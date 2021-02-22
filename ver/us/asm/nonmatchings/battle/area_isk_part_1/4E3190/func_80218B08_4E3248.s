.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B08_4E3248
/* 4E3248 80218B08 3C048022 */  lui       $a0, %hi(D_80224D90)
/* 4E324C 80218B0C 8C844D90 */  lw        $a0, %lo(D_80224D90)($a0)
/* 4E3250 80218B10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4E3254 80218B14 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4E3258 80218B18 0C016914 */  jal       remove_effect
/* 4E325C 80218B1C 00000000 */   nop
/* 4E3260 80218B20 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4E3264 80218B24 24020002 */  addiu     $v0, $zero, 2
/* 4E3268 80218B28 03E00008 */  jr        $ra
/* 4E326C 80218B2C 27BD0018 */   addiu    $sp, $sp, 0x18
