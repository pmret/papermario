.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800508E0
/* 2BCE0 800508E0 3C02800A */  lui       $v0, %hi(D_8009A608)
/* 2BCE4 800508E4 8C42A608 */  lw        $v0, %lo(D_8009A608)($v0)
/* 2BCE8 800508E8 90430020 */  lbu       $v1, 0x20($v0)
/* 2BCEC 800508EC 0083202B */  sltu      $a0, $a0, $v1
/* 2BCF0 800508F0 10800002 */  beqz      $a0, .L800508FC
/* 2BCF4 800508F4 24020003 */   addiu    $v0, $zero, 3
/* 2BCF8 800508F8 0000102D */  daddu     $v0, $zero, $zero
.L800508FC:
/* 2BCFC 800508FC 03E00008 */  jr        $ra
/* 2BD00 80050900 00000000 */   nop
