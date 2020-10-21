.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024216C_8EDF8C
/* 8EDF8C 8024216C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EDF90 80242170 0000202D */  daddu     $a0, $zero, $zero
/* 8EDF94 80242174 240503E8 */  addiu     $a1, $zero, 0x3e8
/* 8EDF98 80242178 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8EDF9C 8024217C 0C01559B */  jal       func_8005566C
/* 8EDFA0 80242180 2406007F */   addiu    $a2, $zero, 0x7f
/* 8EDFA4 80242184 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8EDFA8 80242188 24020002 */  addiu     $v0, $zero, 2
/* 8EDFAC 8024218C 03E00008 */  jr        $ra
/* 8EDFB0 80242190 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8EDFB4 80242194 00000000 */  nop       
/* 8EDFB8 80242198 00000000 */  nop       
/* 8EDFBC 8024219C 00000000 */  nop       
