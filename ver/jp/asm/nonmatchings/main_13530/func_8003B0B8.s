.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003B0B8
/* 164B8 8003B0B8 808200B4 */  lb        $v0, 0xb4($a0)
/* 164BC 8003B0BC 908300B4 */  lbu       $v1, 0xb4($a0)
/* 164C0 8003B0C0 10450005 */  beq       $v0, $a1, .L8003B0D8
/* 164C4 8003B0C4 2402FFFF */   addiu    $v0, $zero, -1
/* 164C8 8003B0C8 A08300B5 */  sb        $v1, 0xb5($a0)
/* 164CC 8003B0CC A08500B4 */  sb        $a1, 0xb4($a0)
/* 164D0 8003B0D0 A08000B7 */  sb        $zero, 0xb7($a0)
/* 164D4 8003B0D4 A08200B6 */  sb        $v0, 0xb6($a0)
.L8003B0D8:
/* 164D8 8003B0D8 03E00008 */  jr        $ra
/* 164DC 8003B0DC 00000000 */   nop
