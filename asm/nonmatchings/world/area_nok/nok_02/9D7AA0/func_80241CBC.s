.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CBC
/* 9D8CDC 80241CBC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D8CE0 80241CC0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9D8CE4 80241CC4 0C00EABB */  jal       get_npc_unsafe
/* 9D8CE8 80241CC8 8C84014C */   lw       $a0, 0x14c($a0)
/* 9D8CEC 80241CCC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9D8CF0 80241CD0 0000102D */  daddu     $v0, $zero, $zero
/* 9D8CF4 80241CD4 03E00008 */  jr        $ra
/* 9D8CF8 80241CD8 27BD0018 */   addiu    $sp, $sp, 0x18
