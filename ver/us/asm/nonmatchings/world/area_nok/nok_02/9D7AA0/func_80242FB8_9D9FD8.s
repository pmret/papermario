.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242FB8_9D9FD8
/* 9D9FD8 80242FB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D9FDC 80242FBC AFBF0010 */  sw        $ra, 0x10($sp)
/* 9D9FE0 80242FC0 0C00EABB */  jal       get_npc_unsafe
/* 9D9FE4 80242FC4 8C84008C */   lw       $a0, 0x8c($a0)
/* 9D9FE8 80242FC8 3C038025 */  lui       $v1, %hi(D_80254B94)
/* 9D9FEC 80242FCC 8C634B94 */  lw        $v1, %lo(D_80254B94)($v1)
/* 9D9FF0 80242FD0 AC430028 */  sw        $v1, 0x28($v0)
/* 9D9FF4 80242FD4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9D9FF8 80242FD8 24020002 */  addiu     $v0, $zero, 2
/* 9D9FFC 80242FDC 03E00008 */  jr        $ra
/* 9DA000 80242FE0 27BD0018 */   addiu    $sp, $sp, 0x18
