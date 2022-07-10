.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050BA0
/* 2BFA0 80050BA0 00041100 */  sll       $v0, $a0, 4
/* 2BFA4 80050BA4 00441023 */  subu      $v0, $v0, $a0
/* 2BFA8 80050BA8 000210C0 */  sll       $v0, $v0, 3
/* 2BFAC 80050BAC 00441021 */  addu      $v0, $v0, $a0
/* 2BFB0 80050BB0 00021080 */  sll       $v0, $v0, 2
/* 2BFB4 80050BB4 3C03800A */  lui       $v1, %hi(D_8009A608)
/* 2BFB8 80050BB8 8C63A608 */  lw        $v1, %lo(D_8009A608)($v1)
/* 2BFBC 80050BBC 24420024 */  addiu     $v0, $v0, 0x24
/* 2BFC0 80050BC0 00621821 */  addu      $v1, $v1, $v0
/* 2BFC4 80050BC4 8C620004 */  lw        $v0, 4($v1)
/* 2BFC8 80050BC8 10400010 */  beqz      $v0, .L80050C0C
/* 2BFCC 80050BCC 00000000 */   nop
/* 2BFD0 80050BD0 8C620008 */  lw        $v0, 8($v1)
/* 2BFD4 80050BD4 1040000D */  beqz      $v0, .L80050C0C
/* 2BFD8 80050BD8 00000000 */   nop
/* 2BFDC 80050BDC 90620024 */  lbu       $v0, 0x24($v1)
/* 2BFE0 80050BE0 10400005 */  beqz      $v0, .L80050BF8
/* 2BFE4 80050BE4 00000000 */   nop
/* 2BFE8 80050BE8 AC600008 */  sw        $zero, 8($v1)
/* 2BFEC 80050BEC AC600020 */  sw        $zero, 0x20($v1)
/* 2BFF0 80050BF0 03E00008 */  jr        $ra
/* 2BFF4 80050BF4 A0600024 */   sb       $zero, 0x24($v1)
.L80050BF8:
/* 2BFF8 80050BF8 3C028008 */  lui       $v0, %hi(D_800784F0)
/* 2BFFC 80050BFC 244284F0 */  addiu     $v0, $v0, %lo(D_800784F0)
/* 2C000 80050C00 AC620008 */  sw        $v0, 8($v1)
/* 2C004 80050C04 24020001 */  addiu     $v0, $zero, 1
/* 2C008 80050C08 AC620018 */  sw        $v0, 0x18($v1)
.L80050C0C:
/* 2C00C 80050C0C 03E00008 */  jr        $ra
/* 2C010 80050C10 00000000 */   nop
