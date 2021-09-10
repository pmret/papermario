.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219AC8_4B2CB8
/* 4B2CB8 80219AC8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4B2CBC 80219ACC AFB00010 */  sw        $s0, 0x10($sp)
/* 4B2CC0 80219AD0 0080802D */  daddu     $s0, $a0, $zero
/* 4B2CC4 80219AD4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4B2CC8 80219AD8 AFB10014 */  sw        $s1, 0x14($sp)
/* 4B2CCC 80219ADC 8E040148 */  lw        $a0, 0x148($s0)
/* 4B2CD0 80219AE0 0C09A75B */  jal       get_actor
/* 4B2CD4 80219AE4 8E11000C */   lw       $s1, 0xc($s0)
/* 4B2CD8 80219AE8 0200202D */  daddu     $a0, $s0, $zero
/* 4B2CDC 80219AEC 8E250000 */  lw        $a1, ($s1)
/* 4B2CE0 80219AF0 0C0B1EAF */  jal       evt_get_variable
/* 4B2CE4 80219AF4 0040802D */   daddu    $s0, $v0, $zero
/* 4B2CE8 80219AF8 A20201F0 */  sb        $v0, 0x1f0($s0)
/* 4B2CEC 80219AFC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4B2CF0 80219B00 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B2CF4 80219B04 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B2CF8 80219B08 24020002 */  addiu     $v0, $zero, 2
/* 4B2CFC 80219B0C 03E00008 */  jr        $ra
/* 4B2D00 80219B10 27BD0020 */   addiu    $sp, $sp, 0x20
/* 4B2D04 80219B14 00000000 */  nop
/* 4B2D08 80219B18 00000000 */  nop
/* 4B2D0C 80219B1C 00000000 */  nop
