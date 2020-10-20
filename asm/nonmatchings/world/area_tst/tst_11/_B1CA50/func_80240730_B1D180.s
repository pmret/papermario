.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240730_B1D180
/* B1D180 80240730 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B1D184 80240734 AFBF0010 */  sw        $ra, 0x10($sp)
/* B1D188 80240738 0C00EAD2 */  jal       get_npc_safe
/* B1D18C 8024073C 2404FFFC */   addiu    $a0, $zero, -4
/* B1D190 80240740 0040202D */  daddu     $a0, $v0, $zero
/* B1D194 80240744 10800004 */  beqz      $a0, .L80240758
/* B1D198 80240748 3C03000A */   lui      $v1, 0xa
/* B1D19C 8024074C 8C820000 */  lw        $v0, ($a0)
/* B1D1A0 80240750 00431025 */  or        $v0, $v0, $v1
/* B1D1A4 80240754 AC820000 */  sw        $v0, ($a0)
.L80240758:
/* B1D1A8 80240758 8FBF0010 */  lw        $ra, 0x10($sp)
/* B1D1AC 8024075C 03E00008 */  jr        $ra
/* B1D1B0 80240760 27BD0018 */   addiu    $sp, $sp, 0x18
/* B1D1B4 80240764 00000000 */  nop       
/* B1D1B8 80240768 00000000 */  nop       
/* B1D1BC 8024076C 00000000 */  nop       
