.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240444_8CAD44
/* 8CAD44 80240444 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8CAD48 80240448 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8CAD4C 8024044C 0C04417A */  jal       get_entity_by_index
/* 8CAD50 80240450 8C840084 */   lw       $a0, 0x84($a0)
/* 8CAD54 80240454 0C043F5A */  jal       func_8010FD68
/* 8CAD58 80240458 0040202D */   daddu    $a0, $v0, $zero
/* 8CAD5C 8024045C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8CAD60 80240460 24020002 */  addiu     $v0, $zero, 2
/* 8CAD64 80240464 03E00008 */  jr        $ra
/* 8CAD68 80240468 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8CAD6C 8024046C 00000000 */  nop       
