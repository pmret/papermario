.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_game_mode
/* E8F0 800334F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E8F4 800334F4 3C01800A */  lui       $at, 0x800a
/* E8F8 800334F8 A42408F0 */  sh        $a0, 0x8f0($at)
/* E8FC 800334FC 00042400 */  sll       $a0, $a0, 0x10
/* E900 80033500 00042383 */  sra       $a0, $a0, 0xe
/* E904 80033504 AFBF0010 */  sw        $ra, 0x10($sp)
/* E908 80033508 3C058007 */  lui       $a1, 0x8007
/* E90C 8003350C 00A42821 */  addu      $a1, $a1, $a0
/* E910 80033510 8CA57850 */  lw        $a1, 0x7850($a1)
/* E914 80033514 0C044B2A */  jal       _set_game_mode
/* E918 80033518 0000202D */   daddu    $a0, $zero, $zero
/* E91C 8003351C 8FBF0010 */  lw        $ra, 0x10($sp)
/* E920 80033520 03E00008 */  jr        $ra
/* E924 80033524 27BD0018 */   addiu    $sp, $sp, 0x18
