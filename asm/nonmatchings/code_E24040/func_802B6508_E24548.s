.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6508_E24548
/* E24548 802B6508 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2454C 802B650C AFB00010 */  sw        $s0, 0x10($sp)
/* E24550 802B6510 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E24554 802B6514 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E24558 802B6518 AFBF0014 */  sw        $ra, 0x14($sp)
/* E2455C 802B651C 8E030000 */  lw        $v1, ($s0)
/* E24560 802B6520 04610012 */  bgez      $v1, .L802B656C
/* E24564 802B6524 3C027FFF */   lui      $v0, 0x7fff
/* E24568 802B6528 3442FFFF */  ori       $v0, $v0, 0xffff
/* E2456C 802B652C 00621024 */  and       $v0, $v1, $v0
/* E24570 802B6530 2403FFF5 */  addiu     $v1, $zero, -0xb
/* E24574 802B6534 00431024 */  and       $v0, $v0, $v1
/* E24578 802B6538 34420004 */  ori       $v0, $v0, 4
/* E2457C 802B653C 3C04800B */  lui       $a0, %hi(gCameras)
/* E24580 802B6540 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* E24584 802B6544 AE020000 */  sw        $v0, ($s0)
/* E24588 802B6548 94820002 */  lhu       $v0, 2($a0)
/* E2458C 802B654C 8E030004 */  lw        $v1, 4($s0)
/* E24590 802B6550 34420001 */  ori       $v0, $v0, 1
/* E24594 802B6554 30631000 */  andi      $v1, $v1, 0x1000
/* E24598 802B6558 10600004 */  beqz      $v1, .L802B656C
/* E2459C 802B655C A4820002 */   sh       $v0, 2($a0)
/* E245A0 802B6560 3C04000A */  lui       $a0, 0xa
/* E245A4 802B6564 0C037FBF */  jal       func_800DFEFC
/* E245A8 802B6568 34840006 */   ori      $a0, $a0, 6
.L802B656C:
/* E245AC 802B656C 960200C0 */  lhu       $v0, 0xc0($s0)
/* E245B0 802B6570 24420001 */  addiu     $v0, $v0, 1
/* E245B4 802B6574 0C039454 */  jal       func_800E5150
/* E245B8 802B6578 A60200C0 */   sh       $v0, 0xc0($s0)
/* E245BC 802B657C 8FBF0014 */  lw        $ra, 0x14($sp)
/* E245C0 802B6580 8FB00010 */  lw        $s0, 0x10($sp)
/* E245C4 802B6584 03E00008 */  jr        $ra
/* E245C8 802B6588 27BD0018 */   addiu    $sp, $sp, 0x18
/* E245CC 802B658C 00000000 */  nop
