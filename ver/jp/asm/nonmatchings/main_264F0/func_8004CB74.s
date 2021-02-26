.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CB74
/* 27F74 8004CB74 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 27F78 8004CB78 AFB00010 */  sw        $s0, 0x10($sp)
/* 27F7C 8004CB7C 00A0802D */  daddu     $s0, $a1, $zero
/* 27F80 8004CB80 AFBF0014 */  sw        $ra, 0x14($sp)
/* 27F84 8004CB84 8E020000 */  lw        $v0, ($s0)
/* 27F88 8004CB88 90450000 */  lbu       $a1, ($v0)
/* 27F8C 8004CB8C 90460001 */  lbu       $a2, 1($v0)
/* 27F90 8004CB90 24420002 */  addiu     $v0, $v0, 2
/* 27F94 8004CB94 AE020000 */  sw        $v0, ($s0)
/* 27F98 8004CB98 A206009D */  sb        $a2, 0x9d($s0)
/* 27F9C 8004CB9C 8C840000 */  lw        $a0, ($a0)
/* 27FA0 8004CBA0 0C014E26 */  jal       func_80053898
/* 27FA4 8004CBA4 26070010 */   addiu    $a3, $s0, 0x10
/* 27FA8 8004CBA8 AE02001C */  sw        $v0, 0x1c($s0)
/* 27FAC 8004CBAC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 27FB0 8004CBB0 8FB00010 */  lw        $s0, 0x10($sp)
/* 27FB4 8004CBB4 03E00008 */  jr        $ra
/* 27FB8 8004CBB8 27BD0018 */   addiu    $sp, $sp, 0x18
