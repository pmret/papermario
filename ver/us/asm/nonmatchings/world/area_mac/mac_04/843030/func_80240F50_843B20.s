.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F50_843B20
/* 843B20 80240F50 3C028025 */  lui       $v0, %hi(D_8024F5C8)
/* 843B24 80240F54 8C42F5C8 */  lw        $v0, %lo(D_8024F5C8)($v0)
/* 843B28 80240F58 8C42000C */  lw        $v0, 0xc($v0)
/* 843B2C 80240F5C AC40001C */  sw        $zero, 0x1c($v0)
/* 843B30 80240F60 03E00008 */  jr        $ra
/* 843B34 80240F64 24020002 */   addiu    $v0, $zero, 2
