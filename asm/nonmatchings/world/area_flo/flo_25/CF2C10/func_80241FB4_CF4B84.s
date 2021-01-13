.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FB4_CF4B84
/* CF4B84 80241FB4 2404005A */  addiu     $a0, $zero, 0x5a
/* CF4B88 80241FB8 3C038024 */  lui       $v1, %hi(D_80245278)
/* CF4B8C 80241FBC 24635278 */  addiu     $v1, $v1, %lo(D_80245278)
/* CF4B90 80241FC0 240200DA */  addiu     $v0, $zero, 0xda
.L80241FC4:
/* CF4B94 80241FC4 AC620000 */  sw        $v0, ($v1)
/* CF4B98 80241FC8 2463FFFC */  addiu     $v1, $v1, -4
/* CF4B9C 80241FCC 2484FFFF */  addiu     $a0, $a0, -1
/* CF4BA0 80241FD0 0481FFFC */  bgez      $a0, .L80241FC4
/* CF4BA4 80241FD4 2442FFFF */   addiu    $v0, $v0, -1
/* CF4BA8 80241FD8 3C018024 */  lui       $at, %hi(D_8024527C)
/* CF4BAC 80241FDC AC20527C */  sw        $zero, %lo(D_8024527C)($at)
/* CF4BB0 80241FE0 03E00008 */  jr        $ra
/* CF4BB4 80241FE4 24020002 */   addiu    $v0, $zero, 2
/* CF4BB8 80241FE8 00000000 */  nop
/* CF4BBC 80241FEC 00000000 */  nop
