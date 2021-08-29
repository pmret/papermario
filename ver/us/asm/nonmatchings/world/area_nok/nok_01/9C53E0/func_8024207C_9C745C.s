.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024207C_9C745C
/* 9C745C 8024207C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C7460 80242080 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C7464 80242084 8C82000C */  lw        $v0, 0xc($a0)
/* 9C7468 80242088 0C0B1EAF */  jal       evt_get_variable
/* 9C746C 8024208C 8C450000 */   lw       $a1, ($v0)
/* 9C7470 80242090 3C018025 */  lui       $at, %hi(D_80248570_9CD950)
/* 9C7474 80242094 AC228570 */  sw        $v0, %lo(D_80248570_9CD950)($at)
/* 9C7478 80242098 24020002 */  addiu     $v0, $zero, 2
/* 9C747C 8024209C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C7480 802420A0 24030001 */  addiu     $v1, $zero, 1
/* 9C7484 802420A4 3C018025 */  lui       $at, %hi(D_8024856C_9CD94C)
/* 9C7488 802420A8 AC23856C */  sw        $v1, %lo(D_8024856C_9CD94C)($at)
/* 9C748C 802420AC 03E00008 */  jr        $ra
/* 9C7490 802420B0 27BD0018 */   addiu    $sp, $sp, 0x18
