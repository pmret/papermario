.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243798_7EE4A8
/* 7EE4A8 80243798 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EE4AC 8024379C AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EE4B0 802437A0 8C82000C */  lw        $v0, 0xc($a0)
/* 7EE4B4 802437A4 0C0B1EAF */  jal       get_variable
/* 7EE4B8 802437A8 8C450000 */   lw       $a1, ($v0)
/* 7EE4BC 802437AC 3C018025 */  lui       $at, %hi(D_8024ED50)
/* 7EE4C0 802437B0 AC22ED50 */  sw        $v0, %lo(D_8024ED50)($at)
/* 7EE4C4 802437B4 24020002 */  addiu     $v0, $zero, 2
/* 7EE4C8 802437B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EE4CC 802437BC 24030001 */  addiu     $v1, $zero, 1
/* 7EE4D0 802437C0 3C018025 */  lui       $at, %hi(D_8024ED4C)
/* 7EE4D4 802437C4 AC23ED4C */  sw        $v1, %lo(D_8024ED4C)($at)
/* 7EE4D8 802437C8 03E00008 */  jr        $ra
/* 7EE4DC 802437CC 27BD0018 */   addiu    $sp, $sp, 0x18
