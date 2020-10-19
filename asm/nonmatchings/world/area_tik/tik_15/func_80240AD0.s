.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AD0
/* 890670 80240AD0 3C068011 */  lui       $a2, 0x8011
/* 890674 80240AD4 84C6F29C */  lh        $a2, -0xd64($a2)
/* 890678 80240AD8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 89067C 80240ADC AFBF0010 */  sw        $ra, 0x10($sp)
/* 890680 80240AE0 8C82000C */  lw        $v0, 0xc($a0)
/* 890684 80240AE4 28C60040 */  slti      $a2, $a2, 0x40
/* 890688 80240AE8 8C450000 */  lw        $a1, ($v0)
/* 89068C 80240AEC 0C0B2026 */  jal       set_variable
/* 890690 80240AF0 38C60001 */   xori     $a2, $a2, 1
/* 890694 80240AF4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 890698 80240AF8 24020002 */  addiu     $v0, $zero, 2
/* 89069C 80240AFC 03E00008 */  jr        $ra
/* 8906A0 80240B00 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8906A4 80240B04 00000000 */  nop       
/* 8906A8 80240B08 00000000 */  nop       
/* 8906AC 80240B0C 00000000 */  nop       
