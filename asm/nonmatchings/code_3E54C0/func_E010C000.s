.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E010C000
/* 3E54C0 E010C000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3E54C4 E010C004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3E54C8 E010C008 4485A000 */  mtc1      $a1, $f20
/* 3E54CC E010C00C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3E54D0 E010C010 4486C000 */  mtc1      $a2, $f24
/* 3E54D4 E010C014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3E54D8 E010C018 0080902D */  daddu     $s2, $a0, $zero
/* 3E54DC E010C01C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3E54E0 E010C020 4487B000 */  mtc1      $a3, $f22
/* 3E54E4 E010C024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3E54E8 E010C028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3E54EC E010C02C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3E54F0 E010C030 3C02E011 */  lui       $v0, %hi(func_E010C190)
/* 3E54F4 E010C034 2442C190 */  addiu     $v0, $v0, %lo(func_E010C190)
/* 3E54F8 E010C038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3E54FC E010C03C 3C02E011 */  lui       $v0, %hi(func_E010C198)
/* 3E5500 E010C040 2442C198 */  addiu     $v0, $v0, %lo(func_E010C198)
/* 3E5504 E010C044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3E5508 E010C048 3C02E011 */  lui       $v0, %hi(func_E010C354)
/* 3E550C E010C04C 2442C354 */  addiu     $v0, $v0, %lo(func_E010C354)
/* 3E5510 E010C050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3E5514 E010C054 24020078 */  addiu     $v0, $zero, 0x78
/* 3E5518 E010C058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3E551C E010C05C AFB00028 */  sw        $s0, 0x28($sp)
/* 3E5520 E010C060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3E5524 E010C064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3E5528 E010C068 0C080124 */  jal       func_E0200490
/* 3E552C E010C06C AFA20014 */   sw       $v0, 0x14($sp)
/* 3E5530 E010C070 2404013C */  addiu     $a0, $zero, 0x13c
/* 3E5534 E010C074 24030001 */  addiu     $v1, $zero, 1
/* 3E5538 E010C078 0040802D */  daddu     $s0, $v0, $zero
/* 3E553C E010C07C 0C08012C */  jal       func_E02004B0
/* 3E5540 E010C080 AE030008 */   sw       $v1, 8($s0)
/* 3E5544 E010C084 0040202D */  daddu     $a0, $v0, $zero
/* 3E5548 E010C088 14800003 */  bnez      $a0, .LE010C098
/* 3E554C E010C08C AE02000C */   sw       $v0, 0xc($s0)
.LE010C090:
/* 3E5550 E010C090 08043024 */  j         .LE010C090
/* 3E5554 E010C094 00000000 */   nop      
.LE010C098:
/* 3E5558 E010C098 AC920000 */  sw        $s2, ($a0)
/* 3E555C E010C09C 1E200004 */  bgtz      $s1, .LE010C0B0
/* 3E5560 E010C0A0 AC800014 */   sw       $zero, 0x14($a0)
/* 3E5564 E010C0A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3E5568 E010C0A8 0804302D */  j         .LE010C0B4
/* 3E556C E010C0AC AC820010 */   sw       $v0, 0x10($a0)
.LE010C0B0:
/* 3E5570 E010C0B0 AC910010 */  sw        $s1, 0x10($a0)
.LE010C0B4:
/* 3E5574 E010C0B4 0000282D */  daddu     $a1, $zero, $zero
/* 3E5578 E010C0B8 240200E0 */  addiu     $v0, $zero, 0xe0
/* 3E557C E010C0BC AC820024 */  sw        $v0, 0x24($a0)
/* 3E5580 E010C0C0 240200FF */  addiu     $v0, $zero, 0xff
/* 3E5584 E010C0C4 E4940004 */  swc1      $f20, 4($a0)
/* 3E5588 E010C0C8 E4980008 */  swc1      $f24, 8($a0)
/* 3E558C E010C0CC E496000C */  swc1      $f22, 0xc($a0)
/* 3E5590 E010C0D0 AC82003C */  sw        $v0, 0x3c($a0)
/* 3E5594 E010C0D4 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3E5598 E010C0D8 3C0140A0 */  lui       $at, 0x40a0
/* 3E559C E010C0DC 44811000 */  mtc1      $at, $f2
/* 3E55A0 E010C0E0 24070001 */  addiu     $a3, $zero, 1
/* 3E55A4 E010C0E4 E4800038 */  swc1      $f0, 0x38($a0)
/* 3E55A8 E010C0E8 3C0142A0 */  lui       $at, 0x42a0
/* 3E55AC E010C0EC 44810000 */  mtc1      $at, $f0
/* 3E55B0 E010C0F0 2406005C */  addiu     $a2, $zero, 0x5c
/* 3E55B4 E010C0F4 E4800048 */  swc1      $f0, 0x48($a0)
/* 3E55B8 E010C0F8 3C014248 */  lui       $at, 0x4248
/* 3E55BC E010C0FC 44810000 */  mtc1      $at, $f0
/* 3E55C0 E010C100 24030078 */  addiu     $v1, $zero, 0x78
/* 3E55C4 E010C104 AC820018 */  sw        $v0, 0x18($a0)
/* 3E55C8 E010C108 AC82001C */  sw        $v0, 0x1c($a0)
/* 3E55CC E010C10C AC830020 */  sw        $v1, 0x20($a0)
/* 3E55D0 E010C110 AC820028 */  sw        $v0, 0x28($a0)
/* 3E55D4 E010C114 AC82002C */  sw        $v0, 0x2c($a0)
/* 3E55D8 E010C118 AC820030 */  sw        $v0, 0x30($a0)
/* 3E55DC E010C11C AC820034 */  sw        $v0, 0x34($a0)
/* 3E55E0 E010C120 AC800044 */  sw        $zero, 0x44($a0)
/* 3E55E4 E010C124 E494004C */  swc1      $f20, 0x4c($a0)
/* 3E55E8 E010C128 E4960054 */  swc1      $f22, 0x54($a0)
/* 3E55EC E010C12C 4600C100 */  add.s     $f4, $f24, $f0
/* 3E55F0 E010C130 E4820040 */  swc1      $f2, 0x40($a0)
/* 3E55F4 E010C134 E4800058 */  swc1      $f0, 0x58($a0)
/* 3E55F8 E010C138 E4840050 */  swc1      $f4, 0x50($a0)
.LE010C13C:
/* 3E55FC E010C13C 16400005 */  bnez      $s2, .LE010C154
/* 3E5600 E010C140 00861021 */   addu     $v0, $a0, $a2
/* 3E5604 E010C144 54A00004 */  bnel      $a1, $zero, .LE010C158
/* 3E5608 E010C148 AC470000 */   sw       $a3, ($v0)
/* 3E560C E010C14C 08043056 */  j         .LE010C158
/* 3E5610 E010C150 AC400000 */   sw       $zero, ($v0)
.LE010C154:
/* 3E5614 E010C154 AC470000 */  sw        $a3, ($v0)
.LE010C158:
/* 3E5618 E010C158 24A50001 */  addiu     $a1, $a1, 1
/* 3E561C E010C15C 28A20008 */  slti      $v0, $a1, 8
/* 3E5620 E010C160 1440FFF6 */  bnez      $v0, .LE010C13C
/* 3E5624 E010C164 24C6001C */   addiu    $a2, $a2, 0x1c
/* 3E5628 E010C168 0200102D */  daddu     $v0, $s0, $zero
/* 3E562C E010C16C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3E5630 E010C170 8FB20030 */  lw        $s2, 0x30($sp)
/* 3E5634 E010C174 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3E5638 E010C178 8FB00028 */  lw        $s0, 0x28($sp)
/* 3E563C E010C17C D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3E5640 E010C180 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3E5644 E010C184 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3E5648 E010C188 03E00008 */  jr        $ra
/* 3E564C E010C18C 27BD0050 */   addiu    $sp, $sp, 0x50
