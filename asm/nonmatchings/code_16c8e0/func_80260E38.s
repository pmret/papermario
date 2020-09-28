.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80260E38
/* 18F718 80260E38 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18F71C 80260E3C 24040031 */  addiu     $a0, $zero, 0x31
/* 18F720 80260E40 AFBF0010 */  sw        $ra, 0x10($sp)
/* 18F724 80260E44 0C093E58 */  jal       show_battle_message
/* 18F728 80260E48 2405003C */   addiu    $a1, $zero, 0x3c
/* 18F72C 80260E4C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 18F730 80260E50 24020002 */  addiu     $v0, $zero, 2
/* 18F734 80260E54 03E00008 */  jr        $ra
/* 18F738 80260E58 27BD0018 */   addiu    $sp, $sp, 0x18
