.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_player_move_history
/* 86968 800ED4B8 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* 8696C 800ED4BC 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* 86970 800ED4C0 24020017 */  addiu     $v0, $zero, 0x17
/* 86974 800ED4C4 80A300B4 */  lb        $v1, 0xb4($a1)
/* 86978 800ED4C8 C4A4002C */  lwc1      $f4, 0x2c($a1)
/* 8697C 800ED4CC 10620004 */  beq       $v1, $v0, .L800ED4E0
/* 86980 800ED4D0 0000302D */   daddu    $a2, $zero, $zero
/* 86984 800ED4D4 24020015 */  addiu     $v0, $zero, 0x15
/* 86988 800ED4D8 14620008 */  bne       $v1, $v0, .L800ED4FC
/* 8698C 800ED4DC 00000000 */   nop      
.L800ED4E0:
/* 86990 800ED4E0 84A20018 */  lh        $v0, 0x18($a1)
/* 86994 800ED4E4 848300A8 */  lh        $v1, 0xa8($a0)
/* 86998 800ED4E8 00431021 */  addu      $v0, $v0, $v1
/* 8699C 800ED4EC 24420005 */  addiu     $v0, $v0, 5
/* 869A0 800ED4F0 44822000 */  mtc1      $v0, $f4
/* 869A4 800ED4F4 00000000 */  nop       
/* 869A8 800ED4F8 46802120 */  cvt.s.w   $f4, $f4
.L800ED4FC:
/* 869AC 800ED4FC 3C028011 */  lui       $v0, %hi(D_8010CFB8)
/* 869B0 800ED500 8C42CFB8 */  lw        $v0, %lo(D_8010CFB8)($v0)
/* 869B4 800ED504 3C038011 */  lui       $v1, %hi(D_8010CD38)
/* 869B8 800ED508 2463CD38 */  addiu     $v1, $v1, %lo(D_8010CD38)
/* 869BC 800ED50C 00021100 */  sll       $v0, $v0, 4
/* 869C0 800ED510 00431821 */  addu      $v1, $v0, $v1
/* 869C4 800ED514 80620000 */  lb        $v0, ($v1)
/* 869C8 800ED518 10400003 */  beqz      $v0, .L800ED528
/* 869CC 800ED51C 00000000 */   nop      
/* 869D0 800ED520 14C00029 */  bnez      $a2, .L800ED5C8
/* 869D4 800ED524 00000000 */   nop      
.L800ED528:
/* 869D8 800ED528 C4620004 */  lwc1      $f2, 4($v1)
/* 869DC 800ED52C C4A00028 */  lwc1      $f0, 0x28($a1)
/* 869E0 800ED530 46001032 */  c.eq.s    $f2, $f0
/* 869E4 800ED534 00000000 */  nop       
/* 869E8 800ED538 4500000C */  bc1f      .L800ED56C
/* 869EC 800ED53C 00000000 */   nop      
/* 869F0 800ED540 C4600008 */  lwc1      $f0, 8($v1)
/* 869F4 800ED544 46040032 */  c.eq.s    $f0, $f4
/* 869F8 800ED548 00000000 */  nop       
/* 869FC 800ED54C 45000007 */  bc1f      .L800ED56C
/* 86A00 800ED550 00000000 */   nop      
/* 86A04 800ED554 C462000C */  lwc1      $f2, 0xc($v1)
/* 86A08 800ED558 C4A00030 */  lwc1      $f0, 0x30($a1)
/* 86A0C 800ED55C 46001032 */  c.eq.s    $f2, $f0
/* 86A10 800ED560 00000000 */  nop       
/* 86A14 800ED564 45010018 */  bc1t      .L800ED5C8
/* 86A18 800ED568 00000000 */   nop      
.L800ED56C:
/* 86A1C 800ED56C 3C048011 */  lui       $a0, %hi(D_8010CFB8)
/* 86A20 800ED570 2484CFB8 */  addiu     $a0, $a0, %lo(D_8010CFB8)
/* 86A24 800ED574 8C820000 */  lw        $v0, ($a0)
/* 86A28 800ED578 3C038011 */  lui       $v1, %hi(D_8010CFBC)
/* 86A2C 800ED57C 8C63CFBC */  lw        $v1, %lo(D_8010CFBC)($v1)
/* 86A30 800ED580 24420001 */  addiu     $v0, $v0, 1
/* 86A34 800ED584 10620010 */  beq       $v1, $v0, .L800ED5C8
/* 86A38 800ED588 00000000 */   nop      
/* 86A3C 800ED58C AC820000 */  sw        $v0, ($a0)
/* 86A40 800ED590 28420028 */  slti      $v0, $v0, 0x28
/* 86A44 800ED594 50400001 */  beql      $v0, $zero, .L800ED59C
/* 86A48 800ED598 AC800000 */   sw       $zero, ($a0)
.L800ED59C:
/* 86A4C 800ED59C 3C038011 */  lui       $v1, %hi(D_8010CD38)
/* 86A50 800ED5A0 2463CD38 */  addiu     $v1, $v1, %lo(D_8010CD38)
/* 86A54 800ED5A4 8C820000 */  lw        $v0, ($a0)
/* 86A58 800ED5A8 C4A00028 */  lwc1      $f0, 0x28($a1)
/* 86A5C 800ED5AC 00021100 */  sll       $v0, $v0, 4
/* 86A60 800ED5B0 00431821 */  addu      $v1, $v0, $v1
/* 86A64 800ED5B4 E4600004 */  swc1      $f0, 4($v1)
/* 86A68 800ED5B8 E4640008 */  swc1      $f4, 8($v1)
/* 86A6C 800ED5BC C4A00030 */  lwc1      $f0, 0x30($a1)
/* 86A70 800ED5C0 A0660000 */  sb        $a2, ($v1)
/* 86A74 800ED5C4 E460000C */  swc1      $f0, 0xc($v1)
.L800ED5C8:
/* 86A78 800ED5C8 03E00008 */  jr        $ra
/* 86A7C 800ED5CC 00000000 */   nop      
