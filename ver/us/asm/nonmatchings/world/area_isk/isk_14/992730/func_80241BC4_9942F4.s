.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BC4_9942F4
/* 9942F4 80241BC4 3C048024 */  lui       $a0, %hi(flo_11_defeat_80242AC4)
/* 9942F8 80241BC8 8C842AC4 */  lw        $a0, %lo(flo_11_defeat_80242AC4)($a0)
/* 9942FC 80241BCC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 994300 80241BD0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 994304 80241BD4 0C048D70 */  jal       free_generic_entity
/* 994308 80241BD8 00000000 */   nop
/* 99430C 80241BDC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 994310 80241BE0 24020002 */  addiu     $v0, $zero, 2
/* 994314 80241BE4 03E00008 */  jr        $ra
/* 994318 80241BE8 27BD0018 */   addiu    $sp, $sp, 0x18
