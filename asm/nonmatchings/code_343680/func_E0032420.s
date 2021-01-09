.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0032420
/* 343AA0 E0032420 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 343AA4 E0032424 3C02E003 */  lui       $v0, %hi(func_E003245C)
/* 343AA8 E0032428 2442245C */  addiu     $v0, $v0, %lo(func_E003245C)
/* 343AAC E003242C AFA2001C */  sw        $v0, 0x1c($sp)
/* 343AB0 E0032430 2402000A */  addiu     $v0, $zero, 0xa
/* 343AB4 E0032434 AFA20014 */  sw        $v0, 0x14($sp)
/* 343AB8 E0032438 2402002D */  addiu     $v0, $zero, 0x2d
/* 343ABC E003243C AFA40018 */  sw        $a0, 0x18($sp)
/* 343AC0 E0032440 27A40010 */  addiu     $a0, $sp, 0x10
/* 343AC4 E0032444 AFBF0020 */  sw        $ra, 0x20($sp)
/* 343AC8 E0032448 0C080120 */  jal       func_E0200480
/* 343ACC E003244C AFA20010 */   sw       $v0, 0x10($sp)
/* 343AD0 E0032450 8FBF0020 */  lw        $ra, 0x20($sp)
/* 343AD4 E0032454 03E00008 */  jr        $ra
/* 343AD8 E0032458 27BD0028 */   addiu    $sp, $sp, 0x28
