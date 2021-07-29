.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B20_8EC940
/* 8EC940 80240B20 3C048026 */  lui       $a0, %hi(D_8025B2A8)
/* 8EC944 80240B24 8C84B2A8 */  lw        $a0, %lo(D_8025B2A8)($a0)
/* 8EC948 80240B28 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EC94C 80240B2C AFBF0010 */  sw        $ra, 0x10($sp)
/* 8EC950 80240B30 0C048D70 */  jal       free_generic_entity
/* 8EC954 80240B34 00000000 */   nop
/* 8EC958 80240B38 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8EC95C 80240B3C 24020002 */  addiu     $v0, $zero, 2
/* 8EC960 80240B40 03E00008 */  jr        $ra
/* 8EC964 80240B44 27BD0018 */   addiu    $sp, $sp, 0x18
