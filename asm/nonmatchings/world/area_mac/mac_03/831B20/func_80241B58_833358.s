.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B58_833358
/* 833358 80241B58 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 83335C 80241B5C AFBF0010 */  sw        $ra, 0x10($sp)
/* 833360 80241B60 0C00EABB */  jal       get_npc_unsafe
/* 833364 80241B64 8C84008C */   lw       $a0, 0x8c($a0)
/* 833368 80241B68 3C038025 */  lui       $v1, 0x8025
/* 83336C 80241B6C 8C6315C4 */  lw        $v1, 0x15c4($v1)
/* 833370 80241B70 AC430028 */  sw        $v1, 0x28($v0)
/* 833374 80241B74 8FBF0010 */  lw        $ra, 0x10($sp)
/* 833378 80241B78 24020002 */  addiu     $v0, $zero, 2
/* 83337C 80241B7C 03E00008 */  jr        $ra
/* 833380 80241B80 27BD0018 */   addiu    $sp, $sp, 0x18
