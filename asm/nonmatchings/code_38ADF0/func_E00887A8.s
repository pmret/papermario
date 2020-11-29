.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00887A8
/* 38B598 E00887A8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 38B59C E00887AC 3C02E009 */  lui       $v0, %hi(D_E00887E0)
/* 38B5A0 E00887B0 244287E0 */  addiu     $v0, $v0, %lo(D_E00887E0)
/* 38B5A4 E00887B4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 38B5A8 E00887B8 2402002D */  addiu     $v0, $zero, 0x2d
/* 38B5AC E00887BC AFA40018 */  sw        $a0, 0x18($sp)
/* 38B5B0 E00887C0 27A40010 */  addiu     $a0, $sp, 0x10
/* 38B5B4 E00887C4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 38B5B8 E00887C8 AFA00014 */  sw        $zero, 0x14($sp)
/* 38B5BC E00887CC 0C080120 */  jal       func_E0200480
/* 38B5C0 E00887D0 AFA20010 */   sw       $v0, 0x10($sp)
/* 38B5C4 E00887D4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 38B5C8 E00887D8 03E00008 */  jr        $ra
/* 38B5CC E00887DC 27BD0028 */   addiu    $sp, $sp, 0x28
