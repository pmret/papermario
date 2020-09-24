.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004BA54
/* 26E54 8004BA54 14A00003 */  bnez      $a1, .L8004BA64
/* 26E58 8004BA58 24020001 */   addiu    $v0, $zero, 1
/* 26E5C 8004BA5C 03E00008 */  jr        $ra
/* 26E60 8004BA60 A08000C0 */   sb       $zero, 0xc0($a0)
.L8004BA64:
/* 26E64 8004BA64 50A20001 */  beql      $a1, $v0, .L8004BA6C
/* 26E68 8004BA68 A08500C0 */   sb       $a1, 0xc0($a0)
.L8004BA6C:
/* 26E6C 8004BA6C 03E00008 */  jr        $ra
/* 26E70 8004BA70 00000000 */   nop      
