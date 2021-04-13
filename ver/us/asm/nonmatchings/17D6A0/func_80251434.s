.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80251434
/* 17FD14 80251434 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17FD18 80251438 AFBF0010 */  sw        $ra, 0x10($sp)
/* 17FD1C 8025143C 0C093EBA */  jal       func_8024FAE8
/* 17FD20 80251440 00000000 */   nop
/* 17FD24 80251444 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17FD28 80251448 24020002 */  addiu     $v0, $zero, 2
/* 17FD2C 8025144C 03E00008 */  jr        $ra
/* 17FD30 80251450 27BD0018 */   addiu    $sp, $sp, 0x18
