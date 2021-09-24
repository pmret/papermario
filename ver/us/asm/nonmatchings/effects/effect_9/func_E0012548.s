.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0012548
/* 32E258 E0012548 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 32E25C E001254C AFBF0010 */  sw        $ra, 0x10($sp)
/* 32E260 E0012550 0C080128 */  jal       shim_remove_effect
/* 32E264 E0012554 00000000 */   nop
/* 32E268 E0012558 8FBF0010 */  lw        $ra, 0x10($sp)
/* 32E26C E001255C 03E00008 */  jr        $ra
/* 32E270 E0012560 27BD0018 */   addiu    $sp, $sp, 0x18
