.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80245504_805D84
/* 805D84 80245504 3C0141A0 */  lui       $at, 0x41a0
/* 805D88 80245508 44816000 */  mtc1      $at, $f12
/* 805D8C 8024550C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 805D90 80245510 AFBF0010 */  sw        $ra, 0x10($sp)
/* 805D94 80245514 0C03BCE5 */  jal       func_800EF394
/* 805D98 80245518 00000000 */   nop      
/* 805D9C 8024551C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 805DA0 80245520 24020002 */  addiu     $v0, $zero, 2
/* 805DA4 80245524 03E00008 */  jr        $ra
/* 805DA8 80245528 27BD0018 */   addiu    $sp, $sp, 0x18
