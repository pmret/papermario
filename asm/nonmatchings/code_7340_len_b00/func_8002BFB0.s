.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002BFB0
/* 73B0 8002BFB0 3C08800A */  lui       $t0, 0x800a
/* 73B4 8002BFB4 2508BB30 */  addiu     $t0, $t0, -0x44d0
/* 73B8 8002BFB8 950309D0 */  lhu       $v1, 0x9d0($t0)
/* 73BC 8002BFBC 24020280 */  addiu     $v0, $zero, 0x280
/* 73C0 8002BFC0 14620005 */  bne       $v1, $v0, .L8002BFD8
/* 73C4 8002BFC4 00000000 */   nop      
/* 73C8 8002BFC8 00042040 */  sll       $a0, $a0, 1
/* 73CC 8002BFCC 00052840 */  sll       $a1, $a1, 1
/* 73D0 8002BFD0 00063040 */  sll       $a2, $a2, 1
/* 73D4 8002BFD4 00073840 */  sll       $a3, $a3, 1
.L8002BFD8:
/* 73D8 8002BFD8 950209D0 */  lhu       $v0, 0x9d0($t0)
/* 73DC 8002BFDC 00450018 */  mult      $v0, $a1
/* 73E0 8002BFE0 0000282D */  daddu     $a1, $zero, $zero
/* 73E4 8002BFE4 8D0209CC */  lw        $v0, 0x9cc($t0)
/* 73E8 8002BFE8 00004812 */  mflo      $t1
/* 73EC 8002BFEC 00091840 */  sll       $v1, $t1, 1
/* 73F0 8002BFF0 00431021 */  addu      $v0, $v0, $v1
/* 73F4 8002BFF4 00041840 */  sll       $v1, $a0, 1
/* 73F8 8002BFF8 18E00014 */  blez      $a3, .L8002C04C
/* 73FC 8002BFFC 00432021 */   addu     $a0, $v0, $v1
.L8002C000:
/* 7400 8002C000 18C0000A */  blez      $a2, .L8002C02C
/* 7404 8002C004 0000182D */   daddu    $v1, $zero, $zero
.L8002C008:
/* 7408 8002C008 94820000 */  lhu       $v0, ($a0)
/* 740C 8002C00C 24630001 */  addiu     $v1, $v1, 1
/* 7410 8002C010 3042E738 */  andi      $v0, $v0, 0xe738
/* 7414 8002C014 00021082 */  srl       $v0, $v0, 2
/* 7418 8002C018 34420001 */  ori       $v0, $v0, 1
/* 741C 8002C01C A4820000 */  sh        $v0, ($a0)
/* 7420 8002C020 0066102A */  slt       $v0, $v1, $a2
/* 7424 8002C024 1440FFF8 */  bnez      $v0, .L8002C008
/* 7428 8002C028 24840002 */   addiu    $a0, $a0, 2
.L8002C02C:
/* 742C 8002C02C 950209D0 */  lhu       $v0, 0x9d0($t0)
/* 7430 8002C030 24A50001 */  addiu     $a1, $a1, 1
/* 7434 8002C034 00461023 */  subu      $v0, $v0, $a2
/* 7438 8002C038 00021040 */  sll       $v0, $v0, 1
/* 743C 8002C03C 00822021 */  addu      $a0, $a0, $v0
/* 7440 8002C040 00A7102A */  slt       $v0, $a1, $a3
/* 7444 8002C044 1440FFEE */  bnez      $v0, .L8002C000
/* 7448 8002C048 00000000 */   nop      
.L8002C04C:
/* 744C 8002C04C 03E00008 */  jr        $ra
/* 7450 8002C050 00000000 */   nop      
