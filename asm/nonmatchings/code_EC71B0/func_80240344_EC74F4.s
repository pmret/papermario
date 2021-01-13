.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240344_EC74F4
/* EC74F4 80240344 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EC74F8 80240348 24020008 */  addiu     $v0, $zero, 8
/* EC74FC 8024034C 3C014348 */  lui       $at, 0x4348
/* EC7500 80240350 44810000 */  mtc1      $at, $f0
/* EC7504 80240354 3C0142F0 */  lui       $at, 0x42f0
/* EC7508 80240358 44811000 */  mtc1      $at, $f2
/* EC750C 8024035C 3C014080 */  lui       $at, 0x4080
/* EC7510 80240360 44812000 */  mtc1      $at, $f4
/* EC7514 80240364 3C05C388 */  lui       $a1, 0xc388
/* EC7518 80240368 3C0642A0 */  lui       $a2, 0x42a0
/* EC751C 8024036C 3C0741A0 */  lui       $a3, 0x41a0
/* EC7520 80240370 24040003 */  addiu     $a0, $zero, 3
/* EC7524 80240374 AFBF0028 */  sw        $ra, 0x28($sp)
/* EC7528 80240378 AFA2001C */  sw        $v0, 0x1c($sp)
/* EC752C 8024037C AFA00020 */  sw        $zero, 0x20($sp)
/* EC7530 80240380 E7A00010 */  swc1      $f0, 0x10($sp)
/* EC7534 80240384 E7A20014 */  swc1      $f2, 0x14($sp)
/* EC7538 80240388 0C01DD74 */  jal       func_800775D0
/* EC753C 8024038C E7A40018 */   swc1     $f4, 0x18($sp)
/* EC7540 80240390 8C43000C */  lw        $v1, 0xc($v0)
/* EC7544 80240394 240500F0 */  addiu     $a1, $zero, 0xf0
/* EC7548 80240398 AC650038 */  sw        $a1, 0x38($v1)
/* EC754C 8024039C 8C43000C */  lw        $v1, 0xc($v0)
/* EC7550 802403A0 AC65003C */  sw        $a1, 0x3c($v1)
/* EC7554 802403A4 8C43000C */  lw        $v1, 0xc($v0)
/* EC7558 802403A8 AC650040 */  sw        $a1, 0x40($v1)
/* EC755C 802403AC 8C43000C */  lw        $v1, 0xc($v0)
/* EC7560 802403B0 240400E6 */  addiu     $a0, $zero, 0xe6
/* EC7564 802403B4 AC640048 */  sw        $a0, 0x48($v1)
/* EC7568 802403B8 8C43000C */  lw        $v1, 0xc($v0)
/* EC756C 802403BC AC64004C */  sw        $a0, 0x4c($v1)
/* EC7570 802403C0 8C43000C */  lw        $v1, 0xc($v0)
/* EC7574 802403C4 AC650050 */  sw        $a1, 0x50($v1)
/* EC7578 802403C8 8FBF0028 */  lw        $ra, 0x28($sp)
/* EC757C 802403CC 24020002 */  addiu     $v0, $zero, 2
/* EC7580 802403D0 03E00008 */  jr        $ra
/* EC7584 802403D4 27BD0030 */   addiu    $sp, $sp, 0x30
/* EC7588 802403D8 00000000 */  nop
/* EC758C 802403DC 00000000 */  nop
