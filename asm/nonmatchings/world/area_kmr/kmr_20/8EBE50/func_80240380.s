.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240380
/* 8EC1A0 80240380 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8EC1A4 80240384 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 8EC1A8 80240388 4485A000 */  mtc1      $a1, $f20
/* 8EC1AC 8024038C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 8EC1B0 80240390 4486B000 */  mtc1      $a2, $f22
/* 8EC1B4 80240394 AFB00010 */  sw        $s0, 0x10($sp)
/* 8EC1B8 80240398 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 8EC1BC 8024039C 4487C000 */  mtc1      $a3, $f24
/* 8EC1C0 802403A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8EC1C4 802403A4 0C019D28 */  jal       guMtxIdentF
/* 8EC1C8 802403A8 0080802D */   daddu    $s0, $a0, $zero
/* 8EC1CC 802403AC 4616A582 */  mul.s     $f22, $f20, $f22
/* 8EC1D0 802403B0 00000000 */  nop       
/* 8EC1D4 802403B4 4618A502 */  mul.s     $f20, $f20, $f24
/* 8EC1D8 802403B8 00000000 */  nop       
/* 8EC1DC 802403BC 3C013F80 */  lui       $at, 0x3f80
/* 8EC1E0 802403C0 44810000 */  mtc1      $at, $f0
/* 8EC1E4 802403C4 00000000 */  nop       
/* 8EC1E8 802403C8 E6000014 */  swc1      $f0, 0x14($s0)
/* 8EC1EC 802403CC E6160010 */  swc1      $f22, 0x10($s0)
/* 8EC1F0 802403D0 E6140018 */  swc1      $f20, 0x18($s0)
/* 8EC1F4 802403D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8EC1F8 802403D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8EC1FC 802403DC D7B80028 */  ldc1      $f24, 0x28($sp)
/* 8EC200 802403E0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 8EC204 802403E4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 8EC208 802403E8 03E00008 */  jr        $ra
/* 8EC20C 802403EC 27BD0030 */   addiu    $sp, $sp, 0x30
