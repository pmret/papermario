.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002BF70
/* 7370 8002BF70 3C08800A */  lui       $t0, %hi(D_8009BB10)
/* 7374 8002BF74 2508BB10 */  addiu     $t0, $t0, %lo(D_8009BB10)
/* 7378 8002BF78 950309D0 */  lhu       $v1, 0x9d0($t0)
/* 737C 8002BF7C 24020280 */  addiu     $v0, $zero, 0x280
/* 7380 8002BF80 14620005 */  bne       $v1, $v0, .L8002BF98
/* 7384 8002BF84 00000000 */   nop
/* 7388 8002BF88 00042040 */  sll       $a0, $a0, 1
/* 738C 8002BF8C 00052840 */  sll       $a1, $a1, 1
/* 7390 8002BF90 00063040 */  sll       $a2, $a2, 1
/* 7394 8002BF94 00073840 */  sll       $a3, $a3, 1
.L8002BF98:
/* 7398 8002BF98 950209D0 */  lhu       $v0, 0x9d0($t0)
/* 739C 8002BF9C 00450018 */  mult      $v0, $a1
/* 73A0 8002BFA0 0000282D */  daddu     $a1, $zero, $zero
/* 73A4 8002BFA4 8D0209CC */  lw        $v0, 0x9cc($t0)
/* 73A8 8002BFA8 00004812 */  mflo      $t1
/* 73AC 8002BFAC 00091840 */  sll       $v1, $t1, 1
/* 73B0 8002BFB0 00431021 */  addu      $v0, $v0, $v1
/* 73B4 8002BFB4 00041840 */  sll       $v1, $a0, 1
/* 73B8 8002BFB8 18E00014 */  blez      $a3, .L8002C00C
/* 73BC 8002BFBC 00432021 */   addu     $a0, $v0, $v1
.L8002BFC0:
/* 73C0 8002BFC0 18C0000A */  blez      $a2, .L8002BFEC
/* 73C4 8002BFC4 0000182D */   daddu    $v1, $zero, $zero
.L8002BFC8:
/* 73C8 8002BFC8 94820000 */  lhu       $v0, ($a0)
/* 73CC 8002BFCC 24630001 */  addiu     $v1, $v1, 1
/* 73D0 8002BFD0 3042E738 */  andi      $v0, $v0, 0xe738
/* 73D4 8002BFD4 00021082 */  srl       $v0, $v0, 2
/* 73D8 8002BFD8 34420001 */  ori       $v0, $v0, 1
/* 73DC 8002BFDC A4820000 */  sh        $v0, ($a0)
/* 73E0 8002BFE0 0066102A */  slt       $v0, $v1, $a2
/* 73E4 8002BFE4 1440FFF8 */  bnez      $v0, .L8002BFC8
/* 73E8 8002BFE8 24840002 */   addiu    $a0, $a0, 2
.L8002BFEC:
/* 73EC 8002BFEC 950209D0 */  lhu       $v0, 0x9d0($t0)
/* 73F0 8002BFF0 24A50001 */  addiu     $a1, $a1, 1
/* 73F4 8002BFF4 00461023 */  subu      $v0, $v0, $a2
/* 73F8 8002BFF8 00021040 */  sll       $v0, $v0, 1
/* 73FC 8002BFFC 00822021 */  addu      $a0, $a0, $v0
/* 7400 8002C000 00A7102A */  slt       $v0, $a1, $a3
/* 7404 8002C004 1440FFEE */  bnez      $v0, .L8002BFC0
/* 7408 8002C008 00000000 */   nop
.L8002C00C:
/* 740C 8002C00C 03E00008 */  jr        $ra
/* 7410 8002C010 00000000 */   nop
