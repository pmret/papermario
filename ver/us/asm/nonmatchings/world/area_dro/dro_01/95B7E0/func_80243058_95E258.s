.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243058_95E258
/* 95E258 80243058 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95E25C 8024305C AFBF0010 */  sw        $ra, 0x10($sp)
/* 95E260 80243060 0C00EABB */  jal       get_npc_unsafe
/* 95E264 80243064 8C84008C */   lw       $a0, 0x8c($a0)
/* 95E268 80243068 3C038025 */  lui       $v1, %hi(D_8024E1B4)
/* 95E26C 8024306C 8C63E1B4 */  lw        $v1, %lo(D_8024E1B4)($v1)
/* 95E270 80243070 AC430028 */  sw        $v1, 0x28($v0)
/* 95E274 80243074 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95E278 80243078 24020002 */  addiu     $v0, $zero, 2
/* 95E27C 8024307C 03E00008 */  jr        $ra
/* 95E280 80243080 27BD0018 */   addiu    $sp, $sp, 0x18
