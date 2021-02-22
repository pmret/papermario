.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D74_7ECA84
/* 7ECA84 80241D74 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7ECA88 80241D78 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7ECA8C 80241D7C 0C00EABB */  jal       get_npc_unsafe
/* 7ECA90 80241D80 8C84008C */   lw       $a0, 0x8c($a0)
/* 7ECA94 80241D84 3C038025 */  lui       $v1, %hi(D_80255ED8)
/* 7ECA98 80241D88 8C635ED8 */  lw        $v1, %lo(D_80255ED8)($v1)
/* 7ECA9C 80241D8C AC430028 */  sw        $v1, 0x28($v0)
/* 7ECAA0 80241D90 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7ECAA4 80241D94 24020002 */  addiu     $v0, $zero, 2
/* 7ECAA8 80241D98 03E00008 */  jr        $ra
/* 7ECAAC 80241D9C 27BD0018 */   addiu    $sp, $sp, 0x18
