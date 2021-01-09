.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242384_8544F4
/* 8544F4 80242384 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8544F8 80242388 3C058024 */  lui       $a1, %hi(func_80242318_852104)
/* 8544FC 8024238C 24A52318 */  addiu     $a1, $a1, %lo(func_80242318_852104)
/* 854500 80242390 AFBF0010 */  sw        $ra, 0x10($sp)
/* 854504 80242394 0C048C8F */  jal       bind_dynamic_entity_7
/* 854508 80242398 0000202D */   daddu    $a0, $zero, $zero
/* 85450C 8024239C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 854510 802423A0 3C018025 */  lui       $at, %hi(D_802529D0)
/* 854514 802423A4 AC2229D0 */  sw        $v0, %lo(D_802529D0)($at)
/* 854518 802423A8 24020002 */  addiu     $v0, $zero, 2
/* 85451C 802423AC 03E00008 */  jr        $ra
/* 854520 802423B0 27BD0018 */   addiu    $sp, $sp, 0x18
