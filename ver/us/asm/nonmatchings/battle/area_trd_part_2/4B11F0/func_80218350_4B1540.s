.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218350_4B1540
/* 4B1540 80218350 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4B1544 80218354 24040008 */  addiu     $a0, $zero, 8
/* 4B1548 80218358 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4B154C 8021835C 0C052BE3 */  jal       bgm_set_battle_song
/* 4B1550 80218360 0000282D */   daddu    $a1, $zero, $zero
/* 4B1554 80218364 0C052BBE */  jal       bgm_push_battle_song
/* 4B1558 80218368 00000000 */   nop
/* 4B155C 8021836C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4B1560 80218370 24020002 */  addiu     $v0, $zero, 2
/* 4B1564 80218374 03E00008 */  jr        $ra
/* 4B1568 80218378 27BD0018 */   addiu    $sp, $sp, 0x18
