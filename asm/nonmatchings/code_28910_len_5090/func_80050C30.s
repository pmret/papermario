.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050C30
/* 2C030 80050C30 3C02800A */  lui       $v0, %hi(D_8009A628)
/* 2C034 80050C34 8C42A628 */  lw        $v0, %lo(D_8009A628)($v0)
/* 2C038 80050C38 90430020 */  lbu       $v1, 0x20($v0)
/* 2C03C 80050C3C 0083202B */  sltu      $a0, $a0, $v1
/* 2C040 80050C40 10800002 */  beqz      $a0, .L80050C4C
/* 2C044 80050C44 24020003 */   addiu    $v0, $zero, 3
/* 2C048 80050C48 0000102D */  daddu     $v0, $zero, $zero
.L80050C4C:
/* 2C04C 80050C4C 03E00008 */  jr        $ra
/* 2C050 80050C50 00000000 */   nop      
