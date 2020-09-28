.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DFF50
/* 79400 800DFF50 3C02EFFF */  lui       $v0, 0xefff
/* 79404 800DFF54 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 79408 800DFF58 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 7940C 800DFF5C 8C650000 */  lw        $a1, ($v1)
/* 79410 800DFF60 3442FFFF */  ori       $v0, $v0, 0xffff
/* 79414 800DFF64 AC6400B8 */  sw        $a0, 0xb8($v1)
/* 79418 800DFF68 A46000BC */  sh        $zero, 0xbc($v1)
/* 7941C 800DFF6C 00A22824 */  and       $a1, $a1, $v0
/* 79420 800DFF70 03E00008 */  jr        $ra
/* 79424 800DFF74 AC650000 */   sw       $a1, ($v1)
