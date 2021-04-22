.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_font_data
/* B9E08 80123708 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B9E0C 8012370C 3C020011 */  lui       $v0, 0x11
/* B9E10 80123710 2442F1B0 */  addiu     $v0, $v0, -0xe50
/* B9E14 80123714 00822021 */  addu      $a0, $a0, $v0
/* B9E18 80123718 30A5FFFF */  andi      $a1, $a1, 0xffff
/* B9E1C 8012371C AFBF0010 */  sw        $ra, 0x10($sp)
/* B9E20 80123720 0C00A5CF */  jal       dma_copy
/* B9E24 80123724 00852821 */   addu     $a1, $a0, $a1
/* B9E28 80123728 8FBF0010 */  lw        $ra, 0x10($sp)
/* B9E2C 8012372C 03E00008 */  jr        $ra
/* B9E30 80123730 27BD0018 */   addiu    $sp, $sp, 0x18
