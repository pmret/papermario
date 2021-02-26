.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80038540
/* 13940 80038540 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 13944 80038544 0000282D */  daddu     $a1, $zero, $zero
/* 13948 80038548 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1394C 8003854C 0C00E096 */  jal       func_80038258
/* 13950 80038550 24060001 */   addiu    $a2, $zero, 1
/* 13954 80038554 8FBF0010 */  lw        $ra, 0x10($sp)
/* 13958 80038558 03E00008 */  jr        $ra
/* 1395C 8003855C 27BD0018 */   addiu    $sp, $sp, 0x18
