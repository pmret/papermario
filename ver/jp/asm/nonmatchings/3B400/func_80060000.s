.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060000
/* 3B400 80060000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3B404 80060004 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3B408 80060008 0C019BFC */  jal       func_80066FF0
/* 3B40C 8006000C 8C84000C */   lw       $a0, 0xc($a0)
/* 3B410 80060010 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3B414 80060014 03E00008 */  jr        $ra
/* 3B418 80060018 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3B41C 8006001C 00000000 */  nop
