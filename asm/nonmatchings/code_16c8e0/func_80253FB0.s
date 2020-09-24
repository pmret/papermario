.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80253FB0
/* 182890 80253FB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 182894 80253FB4 24020003 */  addiu     $v0, $zero, 3
/* 182898 80253FB8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 18289C 80253FBC 3C01800B */  lui       $at, 0x800b
/* 1828A0 80253FC0 A0220F19 */  sb        $v0, 0xf19($at)
/* 1828A4 80253FC4 0C090464 */  jal       func_80241190
/* 1828A8 80253FC8 24040020 */   addiu    $a0, $zero, 0x20
/* 1828AC 80253FCC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1828B0 80253FD0 24020002 */  addiu     $v0, $zero, 2
/* 1828B4 80253FD4 03E00008 */  jr        $ra
/* 1828B8 80253FD8 27BD0018 */   addiu    $sp, $sp, 0x18
