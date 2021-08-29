.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242AD4_825D94
/* 825D94 80242AD4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 825D98 80242AD8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 825D9C 80242ADC 8C82000C */  lw        $v0, 0xc($a0)
/* 825DA0 80242AE0 0C0B1EAF */  jal       evt_get_variable
/* 825DA4 80242AE4 8C450000 */   lw       $a1, ($v0)
/* 825DA8 80242AE8 3C018025 */  lui       $at, %hi(D_8024877C_82BA3C)
/* 825DAC 80242AEC AC22877C */  sw        $v0, %lo(D_8024877C_82BA3C)($at)
/* 825DB0 80242AF0 24020002 */  addiu     $v0, $zero, 2
/* 825DB4 80242AF4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 825DB8 80242AF8 24030001 */  addiu     $v1, $zero, 1
/* 825DBC 80242AFC 3C018025 */  lui       $at, %hi(D_80248778_82BA38)
/* 825DC0 80242B00 AC238778 */  sw        $v1, %lo(D_80248778_82BA38)($at)
/* 825DC4 80242B04 03E00008 */  jr        $ra
/* 825DC8 80242B08 27BD0018 */   addiu    $sp, $sp, 0x18
