.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel remove_part_decoration
/* 195AF8 80267218 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 195AFC 8026721C AFBF0010 */  sw    $ra, 0x10($sp)
/* 195B00 80267220 0C09740F */  jal   _remove_part_decoration
/* 195B04 80267224 00000000 */   nop   
/* 195B08 80267228 8FBF0010 */  lw    $ra, 0x10($sp)
/* 195B0C 8026722C 03E00008 */  jr    $ra
/* 195B10 80267230 27BD0018 */   addiu $sp, $sp, 0x18

