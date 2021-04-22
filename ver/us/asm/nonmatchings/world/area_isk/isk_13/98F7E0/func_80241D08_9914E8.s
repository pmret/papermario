.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D08_9914E8
/* 9914E8 80241D08 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9914EC 80241D0C 3C05FD05 */  lui       $a1, 0xfd05
/* 9914F0 80241D10 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9914F4 80241D14 0C0B1EAF */  jal       get_variable
/* 9914F8 80241D18 34A50F8A */   ori      $a1, $a1, 0xf8a
/* 9914FC 80241D1C 8C440008 */  lw        $a0, 8($v0)
/* 991500 80241D20 0C048D70 */  jal       free_dynamic_entity
/* 991504 80241D24 00000000 */   nop
/* 991508 80241D28 8FBF0010 */  lw        $ra, 0x10($sp)
/* 99150C 80241D2C 24020002 */  addiu     $v0, $zero, 2
/* 991510 80241D30 03E00008 */  jr        $ra
/* 991514 80241D34 27BD0018 */   addiu    $sp, $sp, 0x18
