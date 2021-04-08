.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003B090
/* 16490 8003B090 808200B4 */  lb        $v0, 0xb4($a0)
/* 16494 8003B094 908300B4 */  lbu       $v1, 0xb4($a0)
/* 16498 8003B098 10450005 */  beq       $v0, $a1, .L8003B0B0
/* 1649C 8003B09C 24020001 */   addiu    $v0, $zero, 1
/* 164A0 8003B0A0 A08300B5 */  sb        $v1, 0xb5($a0)
/* 164A4 8003B0A4 A08500B4 */  sb        $a1, 0xb4($a0)
/* 164A8 8003B0A8 A08000B7 */  sb        $zero, 0xb7($a0)
/* 164AC 8003B0AC A08200B6 */  sb        $v0, 0xb6($a0)
.L8003B0B0:
/* 164B0 8003B0B0 03E00008 */  jr        $ra
/* 164B4 8003B0B4 00000000 */   nop
