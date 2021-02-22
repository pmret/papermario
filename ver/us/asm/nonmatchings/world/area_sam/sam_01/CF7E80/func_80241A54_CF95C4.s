.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A54_CF95C4
/* CF95C4 80241A54 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF95C8 80241A58 AFBF0010 */  sw        $ra, 0x10($sp)
/* CF95CC 80241A5C 0C00EABB */  jal       get_npc_unsafe
/* CF95D0 80241A60 8C84008C */   lw       $a0, 0x8c($a0)
/* CF95D4 80241A64 3C038025 */  lui       $v1, %hi(D_8024DF24)
/* CF95D8 80241A68 8C63DF24 */  lw        $v1, %lo(D_8024DF24)($v1)
/* CF95DC 80241A6C AC430028 */  sw        $v1, 0x28($v0)
/* CF95E0 80241A70 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF95E4 80241A74 24020002 */  addiu     $v0, $zero, 2
/* CF95E8 80241A78 03E00008 */  jr        $ra
/* CF95EC 80241A7C 27BD0018 */   addiu    $sp, $sp, 0x18
