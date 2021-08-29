.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242AD4_DF94D4
/* DF94D4 80242AD4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DF94D8 80242AD8 AFBF0010 */  sw        $ra, 0x10($sp)
/* DF94DC 80242ADC 8C82000C */  lw        $v0, 0xc($a0)
/* DF94E0 80242AE0 0C0B1EAF */  jal       evt_get_variable
/* DF94E4 80242AE4 8C450000 */   lw       $a1, ($v0)
/* DF94E8 80242AE8 8C44000C */  lw        $a0, 0xc($v0)
/* DF94EC 80242AEC 24030001 */  addiu     $v1, $zero, 1
/* DF94F0 80242AF0 AC830004 */  sw        $v1, 4($a0)
/* DF94F4 80242AF4 8FBF0010 */  lw        $ra, 0x10($sp)
/* DF94F8 80242AF8 24020002 */  addiu     $v0, $zero, 2
/* DF94FC 80242AFC 03E00008 */  jr        $ra
/* DF9500 80242B00 27BD0018 */   addiu    $sp, $sp, 0x18
/* DF9504 80242B04 00000000 */  nop
/* DF9508 80242B08 00000000 */  nop
/* DF950C 80242B0C 00000000 */  nop
