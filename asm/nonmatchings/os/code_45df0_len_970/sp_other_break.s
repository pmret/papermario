.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sp_other_break
/* 4612C 8006AD2C 0C01ABDF */  jal       send_mesg
/* 46130 8006AD30 24040058 */   addiu    $a0, $zero, 0x58
/* 46134 8006AD34 1220003E */  beqz      $s1, NoMoreRcpInts
/* 46138 8006AD38 00000000 */   nop      
