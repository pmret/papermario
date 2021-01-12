.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242DE0_EA36E0
/* EA36E0 80242DE0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA36E4 80242DE4 AFBF0010 */  sw        $ra, 0x10($sp)
/* EA36E8 80242DE8 0C03C7BE */  jal       func_800F1EF8
/* EA36EC 80242DEC 24040001 */   addiu    $a0, $zero, 1
/* EA36F0 80242DF0 8FBF0010 */  lw        $ra, 0x10($sp)
/* EA36F4 80242DF4 24020002 */  addiu     $v0, $zero, 2
/* EA36F8 80242DF8 03E00008 */  jr        $ra
/* EA36FC 80242DFC 27BD0018 */   addiu    $sp, $sp, 0x18
