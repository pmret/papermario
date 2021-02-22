.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242410_9C77F0
/* 9C77F0 80242410 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C77F4 80242414 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C77F8 80242418 0C00EABB */  jal       get_npc_unsafe
/* 9C77FC 8024241C 8C84008C */   lw       $a0, 0x8c($a0)
/* 9C7800 80242420 3C038025 */  lui       $v1, %hi(D_80251E34)
/* 9C7804 80242424 8C631E34 */  lw        $v1, %lo(D_80251E34)($v1)
/* 9C7808 80242428 AC430028 */  sw        $v1, 0x28($v0)
/* 9C780C 8024242C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C7810 80242430 24020002 */  addiu     $v0, $zero, 2
/* 9C7814 80242434 03E00008 */  jr        $ra
/* 9C7818 80242438 27BD0018 */   addiu    $sp, $sp, 0x18
