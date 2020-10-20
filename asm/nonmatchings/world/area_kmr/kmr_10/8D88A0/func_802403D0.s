.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403D0
/* 8D88A0 802403D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8D88A4 802403D4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 8D88A8 802403D8 4485A000 */  mtc1      $a1, $f20
/* 8D88AC 802403DC F7B60020 */  sdc1      $f22, 0x20($sp)
/* 8D88B0 802403E0 4486B000 */  mtc1      $a2, $f22
/* 8D88B4 802403E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 8D88B8 802403E8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 8D88BC 802403EC 4487C000 */  mtc1      $a3, $f24
/* 8D88C0 802403F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8D88C4 802403F4 0C019D28 */  jal       guMtxIdentF
/* 8D88C8 802403F8 0080802D */   daddu    $s0, $a0, $zero
/* 8D88CC 802403FC 4616A582 */  mul.s     $f22, $f20, $f22
/* 8D88D0 80240400 00000000 */  nop       
/* 8D88D4 80240404 4618A502 */  mul.s     $f20, $f20, $f24
/* 8D88D8 80240408 00000000 */  nop       
/* 8D88DC 8024040C 3C013F80 */  lui       $at, 0x3f80
/* 8D88E0 80240410 44810000 */  mtc1      $at, $f0
/* 8D88E4 80240414 00000000 */  nop       
/* 8D88E8 80240418 E6000014 */  swc1      $f0, 0x14($s0)
/* 8D88EC 8024041C E6160010 */  swc1      $f22, 0x10($s0)
/* 8D88F0 80240420 E6140018 */  swc1      $f20, 0x18($s0)
/* 8D88F4 80240424 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8D88F8 80240428 8FB00010 */  lw        $s0, 0x10($sp)
/* 8D88FC 8024042C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 8D8900 80240430 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 8D8904 80240434 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 8D8908 80240438 03E00008 */  jr        $ra
/* 8D890C 8024043C 27BD0030 */   addiu    $sp, $sp, 0x30
