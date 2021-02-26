.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006CBA0
/* 47FA0 8006CBA0 C4840000 */  lwc1      $f4, ($a0)
/* 47FA4 8006CBA4 C4A60000 */  lwc1      $f6, ($a1)
/* 47FA8 8006CBA8 C4C80000 */  lwc1      $f8, ($a2)
/* 47FAC 8006CBAC 46042282 */  mul.s     $f10, $f4, $f4
/* 47FB0 8006CBB0 3C083F80 */  lui       $t0, 0x3f80
/* 47FB4 8006CBB4 46063402 */  mul.s     $f16, $f6, $f6
/* 47FB8 8006CBB8 46105480 */  add.s     $f18, $f10, $f16
/* 47FBC 8006CBBC 46084402 */  mul.s     $f16, $f8, $f8
/* 47FC0 8006CBC0 46128280 */  add.s     $f10, $f16, $f18
/* 47FC4 8006CBC4 44889000 */  mtc1      $t0, $f18
/* 47FC8 8006CBC8 46005404 */  sqrt.s    $f16, $f10
/* 47FCC 8006CBCC 46109283 */  div.s     $f10, $f18, $f16
/* 47FD0 8006CBD0 460A2402 */  mul.s     $f16, $f4, $f10
/* 47FD4 8006CBD4 00000000 */  nop
/* 47FD8 8006CBD8 460A3482 */  mul.s     $f18, $f6, $f10
/* 47FDC 8006CBDC 00000000 */  nop
/* 47FE0 8006CBE0 460A4102 */  mul.s     $f4, $f8, $f10
/* 47FE4 8006CBE4 E4900000 */  swc1      $f16, ($a0)
/* 47FE8 8006CBE8 E4B20000 */  swc1      $f18, ($a1)
/* 47FEC 8006CBEC 03E00008 */  jr        $ra
/* 47FF0 8006CBF0 E4C40000 */   swc1     $f4, ($a2)
/* 47FF4 8006CBF4 00000000 */  nop
/* 47FF8 8006CBF8 00000000 */  nop
/* 47FFC 8006CBFC 00000000 */  nop
