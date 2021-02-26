.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050B34
/* 2BF34 80050B34 00041100 */  sll       $v0, $a0, 4
/* 2BF38 80050B38 00441023 */  subu      $v0, $v0, $a0
/* 2BF3C 80050B3C 000210C0 */  sll       $v0, $v0, 3
/* 2BF40 80050B40 00441021 */  addu      $v0, $v0, $a0
/* 2BF44 80050B44 00021080 */  sll       $v0, $v0, 2
/* 2BF48 80050B48 3C03800A */  lui       $v1, %hi(D_8009A608)
/* 2BF4C 80050B4C 8C63A608 */  lw        $v1, %lo(D_8009A608)($v1)
/* 2BF50 80050B50 24420024 */  addiu     $v0, $v0, 0x24
/* 2BF54 80050B54 00621821 */  addu      $v1, $v1, $v0
/* 2BF58 80050B58 8C620004 */  lw        $v0, 4($v1)
/* 2BF5C 80050B5C 1040000E */  beqz      $v0, .L80050B98
/* 2BF60 80050B60 00000000 */   nop
/* 2BF64 80050B64 8C620008 */  lw        $v0, 8($v1)
/* 2BF68 80050B68 1040000B */  beqz      $v0, .L80050B98
/* 2BF6C 80050B6C 24020001 */   addiu    $v0, $zero, 1
/* 2BF70 80050B70 10A00003 */  beqz      $a1, .L80050B80
/* 2BF74 80050B74 A0620024 */   sb       $v0, 0x24($v1)
/* 2BF78 80050B78 080142E2 */  j         .L80050B88
/* 2BF7C 80050B7C A4650028 */   sh       $a1, 0x28($v1)
.L80050B80:
/* 2BF80 80050B80 240200FA */  addiu     $v0, $zero, 0xfa
/* 2BF84 80050B84 A4620028 */  sh        $v0, 0x28($v1)
.L80050B88:
/* 2BF88 80050B88 2402007F */  addiu     $v0, $zero, 0x7f
/* 2BF8C 80050B8C A060002A */  sb        $zero, 0x2a($v1)
/* 2BF90 80050B90 A062002B */  sb        $v0, 0x2b($v1)
/* 2BF94 80050B94 A0600026 */  sb        $zero, 0x26($v1)
.L80050B98:
/* 2BF98 80050B98 03E00008 */  jr        $ra
/* 2BF9C 80050B9C 00000000 */   nop
