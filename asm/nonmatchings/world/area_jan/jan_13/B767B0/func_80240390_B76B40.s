.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240390_B76B40
/* B76B40 80240390 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B76B44 80240394 F7B40018 */  sdc1      $f20, 0x18($sp)
/* B76B48 80240398 4485A000 */  mtc1      $a1, $f20
/* B76B4C 8024039C F7B60020 */  sdc1      $f22, 0x20($sp)
/* B76B50 802403A0 4486B000 */  mtc1      $a2, $f22
/* B76B54 802403A4 AFB00010 */  sw        $s0, 0x10($sp)
/* B76B58 802403A8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* B76B5C 802403AC 4487C000 */  mtc1      $a3, $f24
/* B76B60 802403B0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B76B64 802403B4 0C019D28 */  jal       guMtxIdentF
/* B76B68 802403B8 0080802D */   daddu    $s0, $a0, $zero
/* B76B6C 802403BC 4616A582 */  mul.s     $f22, $f20, $f22
/* B76B70 802403C0 00000000 */  nop       
/* B76B74 802403C4 4618A502 */  mul.s     $f20, $f20, $f24
/* B76B78 802403C8 00000000 */  nop       
/* B76B7C 802403CC 3C013F80 */  lui       $at, 0x3f80
/* B76B80 802403D0 44810000 */  mtc1      $at, $f0
/* B76B84 802403D4 00000000 */  nop       
/* B76B88 802403D8 E6000014 */  swc1      $f0, 0x14($s0)
/* B76B8C 802403DC E6160010 */  swc1      $f22, 0x10($s0)
/* B76B90 802403E0 E6140018 */  swc1      $f20, 0x18($s0)
/* B76B94 802403E4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B76B98 802403E8 8FB00010 */  lw        $s0, 0x10($sp)
/* B76B9C 802403EC D7B80028 */  ldc1      $f24, 0x28($sp)
/* B76BA0 802403F0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* B76BA4 802403F4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* B76BA8 802403F8 03E00008 */  jr        $ra
/* B76BAC 802403FC 27BD0030 */   addiu    $sp, $sp, 0x30
