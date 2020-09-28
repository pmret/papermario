.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E0088
/* 79538 800E0088 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7953C 800E008C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 79540 800E0090 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 79544 800E0094 AFBF0010 */  sw        $ra, 0x10($sp)
/* 79548 800E0098 8C460028 */  lw        $a2, 0x28($v0)
/* 7954C 800E009C 0C00A7B5 */  jal       dist2D
/* 79550 800E00A0 8C470030 */   lw       $a3, 0x30($v0)
/* 79554 800E00A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 79558 800E00A8 03E00008 */  jr        $ra
/* 7955C 800E00AC 27BD0018 */   addiu    $sp, $sp, 0x18
