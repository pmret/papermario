.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240500_B52D30
/* B52D30 80240500 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B52D34 80240504 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B52D38 80240508 4485A000 */  mtc1      $a1, $f20
/* B52D3C 8024050C F7B60020 */  sdc1      $f22, 0x20($sp)
/* B52D40 80240510 4486B000 */  mtc1      $a2, $f22
/* B52D44 80240514 AFB00010 */  sw        $s0, 0x10($sp)
/* B52D48 80240518 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B52D4C 8024051C 4487C000 */  mtc1      $a3, $f24
/* B52D50 80240520 AFBF0014 */  sw        $ra, 0x14($sp)
/* B52D54 80240524 0C019D28 */  jal       guMtxIdentF
/* B52D58 80240528 0080802D */   daddu    $s0, $a0, $zero
/* B52D5C 8024052C 4616A582 */  mul.s     $f22, $f20, $f22
/* B52D60 80240530 00000000 */  nop       
/* B52D64 80240534 4618A502 */  mul.s     $f20, $f20, $f24
/* B52D68 80240538 00000000 */  nop       
/* B52D6C 8024053C 3C013F80 */  lui       $at, 0x3f80
/* B52D70 80240540 44810000 */  mtc1      $at, $f0
/* B52D74 80240544 00000000 */  nop       
/* B52D78 80240548 E6000014 */  swc1      $f0, 0x14($s0)
/* B52D7C 8024054C E6160010 */  swc1      $f22, 0x10($s0)
/* B52D80 80240550 E6140018 */  swc1      $f20, 0x18($s0)
/* B52D84 80240554 8FBF0014 */  lw        $ra, 0x14($sp)
/* B52D88 80240558 8FB00010 */  lw        $s0, 0x10($sp)
/* B52D8C 8024055C D7B80028 */  ldc1      $f24, 0x28($sp)
/* B52D90 80240560 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B52D94 80240564 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B52D98 80240568 03E00008 */  jr        $ra
/* B52D9C 8024056C 27BD0030 */   addiu    $sp, $sp, 0x30
