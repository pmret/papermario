.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_8010BEE0
.double 180.0

.section .text

glabel func_800E45E0
/* 7DA90 800E45E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7DA94 800E45E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 7DA98 800E45E8 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 7DA9C 800E45EC 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 7DAA0 800E45F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7DAA4 800E45F4 0C044181 */  jal       get_shadow_by_index
/* 7DAA8 800E45F8 8E0400CC */   lw       $a0, 0xcc($s0)
/* 7DAAC 800E45FC 3C068007 */  lui       $a2, %hi(gGameStatusPtr)
/* 7DAB0 800E4600 8CC6419C */  lw        $a2, %lo(gGameStatusPtr)($a2)
/* 7DAB4 800E4604 0040202D */  daddu     $a0, $v0, $zero
/* 7DAB8 800E4608 84C30086 */  lh        $v1, 0x86($a2)
/* 7DABC 800E460C 24020008 */  addiu     $v0, $zero, 8
/* 7DAC0 800E4610 14620028 */  bne       $v1, $v0, .L800E46B4
/* 7DAC4 800E4614 0000282D */   daddu    $a1, $zero, $zero
/* 7DAC8 800E4618 C4800030 */  lwc1      $f0, 0x30($a0)
/* 7DACC 800E461C 3C018011 */  lui       $at, %hi(D_8010BEE0)
/* 7DAD0 800E4620 D422BEE0 */  ldc1      $f2, %lo(D_8010BEE0)($at)
/* 7DAD4 800E4624 46000021 */  cvt.d.s   $f0, $f0
/* 7DAD8 800E4628 46220000 */  add.d     $f0, $f0, $f2
/* 7DADC 800E462C 44801000 */  mtc1      $zero, $f2
/* 7DAE0 800E4630 46200020 */  cvt.s.d   $f0, $f0
/* 7DAE4 800E4634 46020032 */  c.eq.s    $f0, $f2
/* 7DAE8 800E4638 00000000 */  nop
/* 7DAEC 800E463C 4501001D */  bc1t      .L800E46B4
/* 7DAF0 800E4640 00000000 */   nop
/* 7DAF4 800E4644 84C2008C */  lh        $v0, 0x8c($a2)
/* 7DAF8 800E4648 10400005 */  beqz      $v0, .L800E4660
/* 7DAFC 800E464C 24050001 */   addiu    $a1, $zero, 1
/* 7DB00 800E4650 10450009 */  beq       $v0, $a1, .L800E4678
/* 7DB04 800E4654 00000000 */   nop
/* 7DB08 800E4658 080391AD */  j         .L800E46B4
/* 7DB0C 800E465C 00000000 */   nop
.L800E4660:
/* 7DB10 800E4660 3C0141A0 */  lui       $at, 0x41a0
/* 7DB14 800E4664 44811000 */  mtc1      $at, $f2
/* 7DB18 800E4668 46000005 */  abs.s     $f0, $f0
/* 7DB1C 800E466C 4602003C */  c.lt.s    $f0, $f2
/* 7DB20 800E4670 080391AB */  j         .L800E46AC
/* 7DB24 800E4674 00000000 */   nop
.L800E4678:
/* 7DB28 800E4678 C6020028 */  lwc1      $f2, 0x28($s0)
/* 7DB2C 800E467C 3C01C396 */  lui       $at, 0xc396
/* 7DB30 800E4680 44810000 */  mtc1      $at, $f0
/* 7DB34 800E4684 00000000 */  nop
/* 7DB38 800E4688 4602003E */  c.le.s    $f0, $f2
/* 7DB3C 800E468C 00000000 */  nop
/* 7DB40 800E4690 45000008 */  bc1f      .L800E46B4
/* 7DB44 800E4694 00000000 */   nop
/* 7DB48 800E4698 3C01C30C */  lui       $at, 0xc30c
/* 7DB4C 800E469C 44810000 */  mtc1      $at, $f0
/* 7DB50 800E46A0 00000000 */  nop
/* 7DB54 800E46A4 4600103E */  c.le.s    $f2, $f0
/* 7DB58 800E46A8 00000000 */  nop
.L800E46AC:
/* 7DB5C 800E46AC 45030001 */  bc1tl     .L800E46B4
/* 7DB60 800E46B0 0000282D */   daddu    $a1, $zero, $zero
.L800E46B4:
/* 7DB64 800E46B4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7DB68 800E46B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 7DB6C 800E46BC 00A0102D */  daddu     $v0, $a1, $zero
/* 7DB70 800E46C0 03E00008 */  jr        $ra
/* 7DB74 800E46C4 27BD0018 */   addiu    $sp, $sp, 0x18
