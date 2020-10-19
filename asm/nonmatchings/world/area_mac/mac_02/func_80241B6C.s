.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B6C
/* 824E2C 80241B6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 824E30 80241B70 AFBF0010 */  sw        $ra, 0x10($sp)
/* 824E34 80241B74 0C00EABB */  jal       get_npc_unsafe
/* 824E38 80241B78 8C84014C */   lw       $a0, 0x14c($a0)
/* 824E3C 80241B7C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 824E40 80241B80 0000102D */  daddu     $v0, $zero, $zero
/* 824E44 80241B84 03E00008 */  jr        $ra
/* 824E48 80241B88 27BD0018 */   addiu    $sp, $sp, 0x18
