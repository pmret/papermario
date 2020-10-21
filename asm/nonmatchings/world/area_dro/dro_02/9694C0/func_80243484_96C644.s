.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243484_96C644
/* 96C644 80243484 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96C648 80243488 AFBF0010 */  sw        $ra, 0x10($sp)
/* 96C64C 8024348C 0C03A625 */  jal       func_800E9894
/* 96C650 80243490 00000000 */   nop      
/* 96C654 80243494 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96C658 80243498 24020002 */  addiu     $v0, $zero, 2
/* 96C65C 8024349C 03E00008 */  jr        $ra
/* 96C660 802434A0 27BD0018 */   addiu    $sp, $sp, 0x18
