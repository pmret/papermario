.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242824_825AE4
/* 825AE4 80242824 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 825AE8 80242828 3C058024 */  lui       $a1, %hi(func_802427B8_823B84)
/* 825AEC 8024282C 24A527B8 */  addiu     $a1, $a1, %lo(func_802427B8_823B84)
/* 825AF0 80242830 AFBF0010 */  sw        $ra, 0x10($sp)
/* 825AF4 80242834 0C048C8F */  jal       bind_dynamic_entity_7
/* 825AF8 80242838 0000202D */   daddu    $a0, $zero, $zero
/* 825AFC 8024283C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 825B00 80242840 3C018025 */  lui       $at, %hi(D_8024E540)
/* 825B04 80242844 AC22E540 */  sw        $v0, %lo(D_8024E540)($at)
/* 825B08 80242848 24020002 */  addiu     $v0, $zero, 2
/* 825B0C 8024284C 03E00008 */  jr        $ra
/* 825B10 80242850 27BD0018 */   addiu    $sp, $sp, 0x18
