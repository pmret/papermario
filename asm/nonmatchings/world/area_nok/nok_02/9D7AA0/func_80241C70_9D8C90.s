.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C70_9D8C90
/* 9D8C90 80241C70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D8C94 80241C74 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9D8C98 80241C78 AFB00010 */  sw        $s0, 0x10($sp)
/* 9D8C9C 80241C7C 0C00EABB */  jal       get_npc_unsafe
/* 9D8CA0 80241C80 8C84014C */   lw       $a0, 0x14c($a0)
/* 9D8CA4 80241C84 24040008 */  addiu     $a0, $zero, 8
/* 9D8CA8 80241C88 0040802D */  daddu     $s0, $v0, $zero
/* 9D8CAC 80241C8C 3C028024 */  lui       $v0, %hi(D_80241CDC)
/* 9D8CB0 80241C90 24421CDC */  addiu     $v0, $v0, %lo(D_80241CDC)
/* 9D8CB4 80241C94 0C00AB39 */  jal       heap_malloc
/* 9D8CB8 80241C98 AE020008 */   sw       $v0, 8($s0)
/* 9D8CBC 80241C9C 0040182D */  daddu     $v1, $v0, $zero
/* 9D8CC0 80241CA0 AE030020 */  sw        $v1, 0x20($s0)
/* 9D8CC4 80241CA4 AC600000 */  sw        $zero, ($v1)
/* 9D8CC8 80241CA8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9D8CCC 80241CAC 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D8CD0 80241CB0 24020001 */  addiu     $v0, $zero, 1
/* 9D8CD4 80241CB4 03E00008 */  jr        $ra
/* 9D8CD8 80241CB8 27BD0018 */   addiu    $sp, $sp, 0x18
