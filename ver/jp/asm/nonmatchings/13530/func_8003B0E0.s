.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003B0E0
/* 164E0 8003B0E0 808200B5 */  lb        $v0, 0xb5($a0)
/* 164E4 8003B0E4 908300B5 */  lbu       $v1, 0xb5($a0)
/* 164E8 8003B0E8 14400003 */  bnez      $v0, .L8003B0F8
/* 164EC 8003B0EC 24020001 */   addiu    $v0, $zero, 1
/* 164F0 8003B0F0 03E00008 */  jr        $ra
/* 164F4 8003B0F4 A08000B4 */   sb       $zero, 0xb4($a0)
.L8003B0F8:
/* 164F8 8003B0F8 A08300B4 */  sb        $v1, 0xb4($a0)
/* 164FC 8003B0FC A08000B5 */  sb        $zero, 0xb5($a0)
/* 16500 8003B100 A08000B7 */  sb        $zero, 0xb7($a0)
/* 16504 8003B104 03E00008 */  jr        $ra
/* 16508 8003B108 A08200B6 */   sb       $v0, 0xb6($a0)
