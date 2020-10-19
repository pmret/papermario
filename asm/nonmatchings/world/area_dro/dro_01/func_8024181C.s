.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024181C
/* 95CA1C 8024181C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95CA20 80241820 AFBF0010 */  sw        $ra, 0x10($sp)
/* 95CA24 80241824 0C00EABB */  jal       get_npc_unsafe
/* 95CA28 80241828 8C84014C */   lw       $a0, 0x14c($a0)
/* 95CA2C 8024182C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95CA30 80241830 0000102D */  daddu     $v0, $zero, $zero
/* 95CA34 80241834 03E00008 */  jr        $ra
/* 95CA38 80241838 27BD0018 */   addiu    $sp, $sp, 0x18
