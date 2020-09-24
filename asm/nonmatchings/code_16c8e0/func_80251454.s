.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80251454
/* 17FD34 80251454 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17FD38 80251458 AFBF0010 */  sw        $ra, 0x10($sp)
/* 17FD3C 8025145C 0C093EBF */  jal       func_8024FAFC
/* 17FD40 80251460 00000000 */   nop      
/* 17FD44 80251464 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17FD48 80251468 24020002 */  addiu     $v0, $zero, 2
/* 17FD4C 8025146C 03E00008 */  jr        $ra
/* 17FD50 80251470 27BD0018 */   addiu    $sp, $sp, 0x18
