.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240344_CAC534
/* CAC534 80240344 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CAC538 80240348 24020008 */  addiu     $v0, $zero, 8
/* CAC53C 8024034C 3C014348 */  lui       $at, 0x4348
/* CAC540 80240350 44810000 */  mtc1      $at, $f0
/* CAC544 80240354 3C0142F0 */  lui       $at, 0x42f0
/* CAC548 80240358 44811000 */  mtc1      $at, $f2
/* CAC54C 8024035C 3C014080 */  lui       $at, 0x4080
/* CAC550 80240360 44812000 */  mtc1      $at, $f4
/* CAC554 80240364 3C05C388 */  lui       $a1, 0xc388
/* CAC558 80240368 3C0642A0 */  lui       $a2, 0x42a0
/* CAC55C 8024036C 3C0741A0 */  lui       $a3, 0x41a0
/* CAC560 80240370 24040003 */  addiu     $a0, $zero, 3
/* CAC564 80240374 AFBF0028 */  sw        $ra, 0x28($sp)
/* CAC568 80240378 AFA2001C */  sw        $v0, 0x1c($sp)
/* CAC56C 8024037C AFA00020 */  sw        $zero, 0x20($sp)
/* CAC570 80240380 E7A00010 */  swc1      $f0, 0x10($sp)
/* CAC574 80240384 E7A20014 */  swc1      $f2, 0x14($sp)
/* CAC578 80240388 0C01C8D4 */  jal       func_80072350
/* CAC57C 8024038C E7A40018 */   swc1     $f4, 0x18($sp)
/* CAC580 80240390 8C43000C */  lw        $v1, 0xc($v0)
/* CAC584 80240394 240500F0 */  addiu     $a1, $zero, 0xf0
/* CAC588 80240398 AC650038 */  sw        $a1, 0x38($v1)
/* CAC58C 8024039C 8C43000C */  lw        $v1, 0xc($v0)
/* CAC590 802403A0 AC65003C */  sw        $a1, 0x3c($v1)
/* CAC594 802403A4 8C43000C */  lw        $v1, 0xc($v0)
/* CAC598 802403A8 AC650040 */  sw        $a1, 0x40($v1)
/* CAC59C 802403AC 8C43000C */  lw        $v1, 0xc($v0)
/* CAC5A0 802403B0 240400E6 */  addiu     $a0, $zero, 0xe6
/* CAC5A4 802403B4 AC640048 */  sw        $a0, 0x48($v1)
/* CAC5A8 802403B8 8C43000C */  lw        $v1, 0xc($v0)
/* CAC5AC 802403BC AC64004C */  sw        $a0, 0x4c($v1)
/* CAC5B0 802403C0 8C43000C */  lw        $v1, 0xc($v0)
/* CAC5B4 802403C4 AC650050 */  sw        $a1, 0x50($v1)
/* CAC5B8 802403C8 8FBF0028 */  lw        $ra, 0x28($sp)
/* CAC5BC 802403CC 24020002 */  addiu     $v0, $zero, 2
/* CAC5C0 802403D0 03E00008 */  jr        $ra
/* CAC5C4 802403D4 27BD0030 */   addiu    $sp, $sp, 0x30
/* CAC5C8 802403D8 00000000 */  nop       
/* CAC5CC 802403DC 00000000 */  nop       
