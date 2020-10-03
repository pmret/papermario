.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel guNormalize
/* 47FC0 8006CBC0 C4840000 */  lwc1      $f4, ($a0)
/* 47FC4 8006CBC4 C4A60000 */  lwc1      $f6, ($a1)
/* 47FC8 8006CBC8 C4C80000 */  lwc1      $f8, ($a2)
/* 47FCC 8006CBCC 46042282 */  mul.s     $f10, $f4, $f4
/* 47FD0 8006CBD0 3C083F80 */  lui       $t0, 0x3f80
/* 47FD4 8006CBD4 46063402 */  mul.s     $f16, $f6, $f6
/* 47FD8 8006CBD8 46105480 */  add.s     $f18, $f10, $f16
/* 47FDC 8006CBDC 46084402 */  mul.s     $f16, $f8, $f8
/* 47FE0 8006CBE0 46128280 */  add.s     $f10, $f16, $f18
/* 47FE4 8006CBE4 44889000 */  mtc1      $t0, $f18
/* 47FE8 8006CBE8 46005404 */  sqrt.s    $f16, $f10
/* 47FEC 8006CBEC 46109283 */  div.s     $f10, $f18, $f16
/* 47FF0 8006CBF0 460A2402 */  mul.s     $f16, $f4, $f10
/* 47FF4 8006CBF4 00000000 */  nop       
/* 47FF8 8006CBF8 460A3482 */  mul.s     $f18, $f6, $f10
/* 47FFC 8006CBFC 00000000 */  nop       
/* 48000 8006CC00 460A4102 */  mul.s     $f4, $f8, $f10
/* 48004 8006CC04 E4900000 */  swc1      $f16, ($a0)
/* 48008 8006CC08 E4B20000 */  swc1      $f18, ($a1)
/* 4800C 8006CC0C 03E00008 */  jr        $ra
/* 48010 8006CC10 E4C40000 */   swc1     $f4, ($a2)
/* 48014 8006CC14 00000000 */  nop       
/* 48018 8006CC18 00000000 */  nop       
/* 4801C 8006CC1C 00000000 */  nop       
