.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003B3D0
/* 167D0 8003B3D0 808200B4 */  lb        $v0, 0xb4($a0)
/* 167D4 8003B3D4 908300B4 */  lbu       $v1, 0xb4($a0)
/* 167D8 8003B3D8 10450005 */  beq       $v0, $a1, .L8003B3F0
/* 167DC 8003B3DC 24020001 */   addiu    $v0, $zero, 1
/* 167E0 8003B3E0 A08300B5 */  sb        $v1, 0xb5($a0)
/* 167E4 8003B3E4 A08500B4 */  sb        $a1, 0xb4($a0)
/* 167E8 8003B3E8 A08000B7 */  sb        $zero, 0xb7($a0)
/* 167EC 8003B3EC A08200B6 */  sb        $v0, 0xb6($a0)
.L8003B3F0:
/* 167F0 8003B3F0 03E00008 */  jr        $ra
/* 167F4 8003B3F4 00000000 */   nop      
