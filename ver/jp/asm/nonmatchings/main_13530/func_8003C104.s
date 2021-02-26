.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C104
/* 17504 8003C104 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17508 8003C108 AFB10014 */  sw        $s1, 0x14($sp)
/* 1750C 8003C10C 0080882D */  daddu     $s1, $a0, $zero
/* 17510 8003C110 AFB00010 */  sw        $s0, 0x10($sp)
/* 17514 8003C114 0000802D */  daddu     $s0, $zero, $zero
/* 17518 8003C118 AFB20018 */  sw        $s2, 0x18($sp)
/* 1751C 8003C11C 3C12800A */  lui       $s2, %hi(D_800984C0)
/* 17520 8003C120 265284C0 */  addiu     $s2, $s2, %lo(D_800984C0)
/* 17524 8003C124 AFBF001C */  sw        $ra, 0x1c($sp)
/* 17528 8003C128 02301021 */  addu      $v0, $s1, $s0
.L8003C12C:
/* 1752C 8003C12C 8043032C */  lb        $v1, 0x32c($v0)
/* 17530 8003C130 2C620007 */  sltiu     $v0, $v1, 7
/* 17534 8003C134 50400028 */  beql      $v0, $zero, .L8003C1D8
/* 17538 8003C138 26100001 */   addiu    $s0, $s0, 1
/* 1753C 8003C13C 00031080 */  sll       $v0, $v1, 2
/* 17540 8003C140 00521021 */  addu      $v0, $v0, $s2
/* 17544 8003C144 8C420000 */  lw        $v0, ($v0)
/* 17548 8003C148 00400008 */  jr        $v0
/* 1754C 8003C14C 00000000 */   nop
/* 17550 8003C150 0220202D */  daddu     $a0, $s1, $zero
/* 17554 8003C154 0C00F0C6 */  jal       func_8003C318
/* 17558 8003C158 0200282D */   daddu    $a1, $s0, $zero
/* 1755C 8003C15C 0800F076 */  j         .L8003C1D8
/* 17560 8003C160 26100001 */   addiu    $s0, $s0, 1
/* 17564 8003C164 0220202D */  daddu     $a0, $s1, $zero
/* 17568 8003C168 0C00F0CA */  jal       func_8003C328
/* 1756C 8003C16C 0200282D */   daddu    $a1, $s0, $zero
/* 17570 8003C170 0800F076 */  j         .L8003C1D8
/* 17574 8003C174 26100001 */   addiu    $s0, $s0, 1
/* 17578 8003C178 0220202D */  daddu     $a0, $s1, $zero
/* 1757C 8003C17C 0C00F11A */  jal       func_8003C468
/* 17580 8003C180 0200282D */   daddu    $a1, $s0, $zero
/* 17584 8003C184 0800F076 */  j         .L8003C1D8
/* 17588 8003C188 26100001 */   addiu    $s0, $s0, 1
/* 1758C 8003C18C 0220202D */  daddu     $a0, $s1, $zero
/* 17590 8003C190 0C00F15D */  jal       func_8003C574
/* 17594 8003C194 0200282D */   daddu    $a1, $s0, $zero
/* 17598 8003C198 0800F076 */  j         .L8003C1D8
/* 1759C 8003C19C 26100001 */   addiu    $s0, $s0, 1
/* 175A0 8003C1A0 0220202D */  daddu     $a0, $s1, $zero
/* 175A4 8003C1A4 0C00F19A */  jal       func_8003C668
/* 175A8 8003C1A8 0200282D */   daddu    $a1, $s0, $zero
/* 175AC 8003C1AC 0800F076 */  j         .L8003C1D8
/* 175B0 8003C1B0 26100001 */   addiu    $s0, $s0, 1
/* 175B4 8003C1B4 0220202D */  daddu     $a0, $s1, $zero
/* 175B8 8003C1B8 0C00F201 */  jal       func_8003C804
/* 175BC 8003C1BC 0200282D */   daddu    $a1, $s0, $zero
/* 175C0 8003C1C0 0800F076 */  j         .L8003C1D8
/* 175C4 8003C1C4 26100001 */   addiu    $s0, $s0, 1
/* 175C8 8003C1C8 0220202D */  daddu     $a0, $s1, $zero
/* 175CC 8003C1CC 0C00F25C */  jal       func_8003C970
/* 175D0 8003C1D0 0200282D */   daddu    $a1, $s0, $zero
/* 175D4 8003C1D4 26100001 */  addiu     $s0, $s0, 1
.L8003C1D8:
/* 175D8 8003C1D8 2A020002 */  slti      $v0, $s0, 2
/* 175DC 8003C1DC 5440FFD3 */  bnel      $v0, $zero, .L8003C12C
/* 175E0 8003C1E0 02301021 */   addu     $v0, $s1, $s0
/* 175E4 8003C1E4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 175E8 8003C1E8 8FB20018 */  lw        $s2, 0x18($sp)
/* 175EC 8003C1EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 175F0 8003C1F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 175F4 8003C1F4 03E00008 */  jr        $ra
/* 175F8 8003C1F8 27BD0020 */   addiu    $sp, $sp, 0x20
