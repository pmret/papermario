.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241114_9C64F4
/* 9C64F4 80241114 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C64F8 80241118 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C64FC 8024111C 0C00EABB */  jal       get_npc_unsafe
/* 9C6500 80241120 8C84014C */   lw       $a0, 0x14c($a0)
/* 9C6504 80241124 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C6508 80241128 0000102D */  daddu     $v0, $zero, $zero
/* 9C650C 8024112C 03E00008 */  jr        $ra
/* 9C6510 80241130 27BD0018 */   addiu    $sp, $sp, 0x18
