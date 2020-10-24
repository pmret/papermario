.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242B70_DA0040
/* DA0040 80242B70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DA0044 80242B74 3C05FE36 */  lui       $a1, 0xfe36
/* DA0048 80242B78 AFBF0010 */  sw        $ra, 0x10($sp)
/* DA004C 80242B7C 8C820148 */  lw        $v0, 0x148($a0)
/* DA0050 80242B80 3C06800B */  lui       $a2, 0x800b
/* DA0054 80242B84 8CC60F9C */  lw        $a2, 0xf9c($a2)
/* DA0058 80242B88 34A53C80 */  ori       $a1, $a1, 0x3c80
/* DA005C 80242B8C 00C23026 */  xor       $a2, $a2, $v0
/* DA0060 80242B90 0C0B2026 */  jal       set_variable
/* DA0064 80242B94 2CC60001 */   sltiu    $a2, $a2, 1
/* DA0068 80242B98 8FBF0010 */  lw        $ra, 0x10($sp)
/* DA006C 80242B9C 24020002 */  addiu     $v0, $zero, 2
/* DA0070 80242BA0 03E00008 */  jr        $ra
/* DA0074 80242BA4 27BD0018 */   addiu    $sp, $sp, 0x18
/* DA0078 80242BA8 00000000 */  nop       
/* DA007C 80242BAC 00000000 */  nop       
