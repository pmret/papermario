.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024036C_EB549C
/* EB549C 8024036C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB54A0 80240370 0000202D */  daddu     $a0, $zero, $zero
/* EB54A4 80240374 AFBF0010 */  sw        $ra, 0x10($sp)
/* EB54A8 80240378 0C0166B2 */  jal       func_80059AC8
/* EB54AC 8024037C 24050001 */   addiu    $a1, $zero, 1
/* EB54B0 80240380 8FBF0010 */  lw        $ra, 0x10($sp)
/* EB54B4 80240384 24020002 */  addiu     $v0, $zero, 2
/* EB54B8 80240388 03E00008 */  jr        $ra
/* EB54BC 8024038C 27BD0018 */   addiu    $sp, $sp, 0x18
