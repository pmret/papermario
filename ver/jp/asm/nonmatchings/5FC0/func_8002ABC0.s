.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002ABC0
/* 5FC0 8002ABC0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5FC4 8002ABC4 3C050005 */  lui       $a1, 5
/* 5FC8 8002ABC8 3C048030 */  lui       $a0, %hi(D_802FB800)
/* 5FCC 8002ABCC 2484B800 */  addiu     $a0, $a0, %lo(D_802FB800)
/* 5FD0 8002ABD0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 5FD4 8002ABD4 0C00A3FC */  jal       func_80028FF0
/* 5FD8 8002ABD8 34A54000 */   ori      $a1, $a1, 0x4000
/* 5FDC 8002ABDC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5FE0 8002ABE0 03E00008 */  jr        $ra
/* 5FE4 8002ABE4 27BD0018 */   addiu    $sp, $sp, 0x18
