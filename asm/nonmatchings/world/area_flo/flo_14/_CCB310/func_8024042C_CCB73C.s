.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024042C_CCB73C
/* CCB73C 8024042C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CCB740 80240430 2404FFFC */  addiu     $a0, $zero, -4
/* CCB744 80240434 AFBF0014 */  sw        $ra, 0x14($sp)
/* CCB748 80240438 0C00EABB */  jal       get_npc_unsafe
/* CCB74C 8024043C AFB00010 */   sw       $s0, 0x10($sp)
/* CCB750 80240440 0000202D */  daddu     $a0, $zero, $zero
/* CCB754 80240444 3C05FD05 */  lui       $a1, 0xfd05
/* CCB758 80240448 34A50F80 */  ori       $a1, $a1, 0xf80
/* CCB75C 8024044C 0C0B1EAF */  jal       get_variable
/* CCB760 80240450 0040802D */   daddu    $s0, $v0, $zero
/* CCB764 80240454 AE020000 */  sw        $v0, ($s0)
/* CCB768 80240458 8FBF0014 */  lw        $ra, 0x14($sp)
/* CCB76C 8024045C 8FB00010 */  lw        $s0, 0x10($sp)
/* CCB770 80240460 24020002 */  addiu     $v0, $zero, 2
/* CCB774 80240464 03E00008 */  jr        $ra
/* CCB778 80240468 27BD0018 */   addiu    $sp, $sp, 0x18
