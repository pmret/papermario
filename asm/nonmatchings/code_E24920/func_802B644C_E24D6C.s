.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B644C_E24D6C
/* E24D6C 802B644C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E24D70 802B6450 3C058016 */  lui       $a1, %hi(gCollisionStatus)
/* E24D74 802B6454 24A5A550 */  addiu     $a1, $a1, %lo(gCollisionStatus)
/* E24D78 802B6458 AFB00018 */  sw        $s0, 0x18($sp)
/* E24D7C 802B645C 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E24D80 802B6460 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E24D84 802B6464 AFBF0020 */  sw        $ra, 0x20($sp)
/* E24D88 802B6468 AFB1001C */  sw        $s1, 0x1c($sp)
/* E24D8C 802B646C 8E020000 */  lw        $v0, ($s0)
/* E24D90 802B6470 04410016 */  bgez      $v0, .L802B64CC
/* E24D94 802B6474 00A0882D */   daddu    $s1, $a1, $zero
/* E24D98 802B6478 3C037FFF */  lui       $v1, 0x7fff
/* E24D9C 802B647C 3463FFFF */  ori       $v1, $v1, 0xffff
/* E24DA0 802B6480 00431824 */  and       $v1, $v0, $v1
/* E24DA4 802B6484 C6000028 */  lwc1      $f0, 0x28($s0)
/* E24DA8 802B6488 C6020030 */  lwc1      $f2, 0x30($s0)
/* E24DAC 802B648C 2404FFF1 */  addiu     $a0, $zero, -0xf
/* E24DB0 802B6490 AE030000 */  sw        $v1, ($s0)
/* E24DB4 802B6494 A20000B6 */  sb        $zero, 0xb6($s0)
/* E24DB8 802B6498 A60000C0 */  sh        $zero, 0xc0($s0)
/* E24DBC 802B649C A60000C2 */  sh        $zero, 0xc2($s0)
/* E24DC0 802B64A0 94A20002 */  lhu       $v0, 2($a1)
/* E24DC4 802B64A4 00641824 */  and       $v1, $v1, $a0
/* E24DC8 802B64A8 AE030000 */  sw        $v1, ($s0)
/* E24DCC 802B64AC 30424000 */  andi      $v0, $v0, 0x4000
/* E24DD0 802B64B0 E6000044 */  swc1      $f0, 0x44($s0)
/* E24DD4 802B64B4 14400003 */  bnez      $v0, .L802B64C4
/* E24DD8 802B64B8 E6020048 */   swc1     $f2, 0x48($s0)
/* E24DDC 802B64BC 0C03954C */  jal       func_800E5530
/* E24DE0 802B64C0 00000000 */   nop      
.L802B64C4:
/* E24DE4 802B64C4 2402FFFF */  addiu     $v0, $zero, -1
/* E24DE8 802B64C8 A6220004 */  sh        $v0, 4($s1)
.L802B64CC:
/* E24DEC 802B64CC C6020054 */  lwc1      $f2, 0x54($s0)
/* E24DF0 802B64D0 3C013F19 */  lui       $at, 0x3f19
/* E24DF4 802B64D4 3421999A */  ori       $at, $at, 0x999a
/* E24DF8 802B64D8 44810000 */  mtc1      $at, $f0
/* E24DFC 802B64DC 27A40010 */  addiu     $a0, $sp, 0x10
/* E24E00 802B64E0 46001082 */  mul.s     $f2, $f2, $f0
/* E24E04 802B64E4 00000000 */  nop       
/* E24E08 802B64E8 920200B6 */  lbu       $v0, 0xb6($s0)
/* E24E0C 802B64EC 27A50014 */  addiu     $a1, $sp, 0x14
/* E24E10 802B64F0 24420001 */  addiu     $v0, $v0, 1
/* E24E14 802B64F4 A20200B6 */  sb        $v0, 0xb6($s0)
/* E24E18 802B64F8 0C0388C1 */  jal       input_to_move_vector
/* E24E1C 802B64FC E6020054 */   swc1     $f2, 0x54($s0)
/* E24E20 802B6500 C7A20014 */  lwc1      $f2, 0x14($sp)
/* E24E24 802B6504 44800000 */  mtc1      $zero, $f0
/* E24E28 802B6508 00000000 */  nop       
/* E24E2C 802B650C 46001032 */  c.eq.s    $f2, $f0
/* E24E30 802B6510 00000000 */  nop       
/* E24E34 802B6514 45010003 */  bc1t      .L802B6524
/* E24E38 802B6518 00000000 */   nop      
/* E24E3C 802B651C C7A00010 */  lwc1      $f0, 0x10($sp)
/* E24E40 802B6520 E6000080 */  swc1      $f0, 0x80($s0)
.L802B6524:
/* E24E44 802B6524 8E0200E8 */  lw        $v0, 0xe8($s0)
/* E24E48 802B6528 00420018 */  mult      $v0, $v0
/* E24E4C 802B652C 00001812 */  mflo      $v1
/* E24E50 802B6530 8E0200EC */  lw        $v0, 0xec($s0)
/* E24E54 802B6534 00000000 */  nop       
/* E24E58 802B6538 00420018 */  mult      $v0, $v0
/* E24E5C 802B653C 00003812 */  mflo      $a3
/* E24E60 802B6540 00671021 */  addu      $v0, $v1, $a3
/* E24E64 802B6544 44826000 */  mtc1      $v0, $f12
/* E24E68 802B6548 00000000 */  nop       
/* E24E6C 802B654C 46806320 */  cvt.s.w   $f12, $f12
/* E24E70 802B6550 46006084 */  sqrt.s    $f2, $f12
/* E24E74 802B6554 46021032 */  c.eq.s    $f2, $f2
/* E24E78 802B6558 00000000 */  nop       
/* E24E7C 802B655C 45010004 */  bc1t      .L802B6570
/* E24E80 802B6560 00000000 */   nop      
/* E24E84 802B6564 0C0187BC */  jal       sqrtf
/* E24E88 802B6568 00000000 */   nop      
/* E24E8C 802B656C 46000086 */  mov.s     $f2, $f0
.L802B6570:
/* E24E90 802B6570 3C01425C */  lui       $at, 0x425c
/* E24E94 802B6574 44810000 */  mtc1      $at, $f0
/* E24E98 802B6578 00000000 */  nop       
/* E24E9C 802B657C 4602003C */  c.lt.s    $f0, $f2
/* E24EA0 802B6580 00000000 */  nop       
/* E24EA4 802B6584 45000002 */  bc1f      .L802B6590
/* E24EA8 802B6588 24040001 */   addiu    $a0, $zero, 1
/* E24EAC 802B658C 24040002 */  addiu     $a0, $zero, 2
.L802B6590:
/* E24EB0 802B6590 0C039769 */  jal       set_action_state
/* E24EB4 802B6594 00000000 */   nop      
/* E24EB8 802B6598 8FBF0020 */  lw        $ra, 0x20($sp)
/* E24EBC 802B659C 8FB1001C */  lw        $s1, 0x1c($sp)
/* E24EC0 802B65A0 8FB00018 */  lw        $s0, 0x18($sp)
/* E24EC4 802B65A4 03E00008 */  jr        $ra
/* E24EC8 802B65A8 27BD0028 */   addiu    $sp, $sp, 0x28
/* E24ECC 802B65AC 00000000 */  nop       
