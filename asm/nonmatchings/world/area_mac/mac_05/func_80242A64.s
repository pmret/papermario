.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A64
/* 854BD4 80242A64 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 854BD8 80242A68 AFBF0010 */  sw        $ra, 0x10($sp)
/* 854BDC 80242A6C 0C00EABB */  jal       get_npc_unsafe
/* 854BE0 80242A70 8C84008C */   lw       $a0, 0x8c($a0)
/* 854BE4 80242A74 3C038025 */  lui       $v1, 0x8025
/* 854BE8 80242A78 8C632D38 */  lw        $v1, 0x2d38($v1)
/* 854BEC 80242A7C AC430028 */  sw        $v1, 0x28($v0)
/* 854BF0 80242A80 8FBF0010 */  lw        $ra, 0x10($sp)
/* 854BF4 80242A84 24020002 */  addiu     $v0, $zero, 2
/* 854BF8 80242A88 03E00008 */  jr        $ra
/* 854BFC 80242A8C 27BD0018 */   addiu    $sp, $sp, 0x18
