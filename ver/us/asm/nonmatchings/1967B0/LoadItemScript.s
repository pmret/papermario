.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel LoadItemScript
/* 1967B0 80267ED0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1967B4 80267ED4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1967B8 80267ED8 0080982D */  daddu     $s3, $a0, $zero
/* 1967BC 80267EDC AFB00010 */  sw        $s0, 0x10($sp)
/* 1967C0 80267EE0 0000802D */  daddu     $s0, $zero, $zero
/* 1967C4 80267EE4 3C068011 */  lui       $a2, %hi(gPlayerData)
/* 1967C8 80267EE8 24C6F290 */  addiu     $a2, $a2, %lo(gPlayerData)
/* 1967CC 80267EEC 00C0282D */  daddu     $a1, $a2, $zero
/* 1967D0 80267EF0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1967D4 80267EF4 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 1967D8 80267EF8 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 1967DC 80267EFC AFBF0020 */  sw        $ra, 0x20($sp)
/* 1967E0 80267F00 AFB20018 */  sw        $s2, 0x18($sp)
/* 1967E4 80267F04 8624017A */  lh        $a0, 0x17a($s1)
/* 1967E8 80267F08 3C038008 */  lui       $v1, %hi(gItemTable)
/* 1967EC 80267F0C 246378E0 */  addiu     $v1, $v1, %lo(gItemTable)
/* 1967F0 80267F10 00041140 */  sll       $v0, $a0, 5
/* 1967F4 80267F14 00439021 */  addu      $s2, $v0, $v1
.L80267F18:
/* 1967F8 80267F18 84A201B4 */  lh        $v0, 0x1b4($a1)
/* 1967FC 80267F1C 10440004 */  beq       $v0, $a0, .L80267F30
/* 196800 80267F20 00101840 */   sll      $v1, $s0, 1
/* 196804 80267F24 24A50002 */  addiu     $a1, $a1, 2
/* 196808 80267F28 08099FC6 */  j         .L80267F18
/* 19680C 80267F2C 26100001 */   addiu    $s0, $s0, 1
.L80267F30:
/* 196810 80267F30 00C31021 */  addu      $v0, $a2, $v1
/* 196814 80267F34 0C039DB3 */  jal       sort_items
/* 196818 80267F38 A44001B4 */   sh       $zero, 0x1b4($v0)
/* 19681C 80267F3C 8623017C */  lh        $v1, 0x17c($s1)
/* 196820 80267F40 24020035 */  addiu     $v0, $zero, 0x35
/* 196824 80267F44 14620009 */  bne       $v1, $v0, .L80267F6C
/* 196828 80267F48 24020036 */   addiu    $v0, $zero, 0x36
/* 19682C 80267F4C 82230088 */  lb        $v1, 0x88($s1)
/* 196830 80267F50 24020002 */  addiu     $v0, $zero, 2
/* 196834 80267F54 14620003 */  bne       $v1, $v0, .L80267F64
/* 196838 80267F58 00000000 */   nop
/* 19683C 80267F5C 0C098EF2 */  jal       deduct_current_move_fp
/* 196840 80267F60 00000000 */   nop
.L80267F64:
/* 196844 80267F64 8623017C */  lh        $v1, 0x17c($s1)
/* 196848 80267F68 24020036 */  addiu     $v0, $zero, 0x36
.L80267F6C:
/* 19684C 80267F6C 14620006 */  bne       $v1, $v0, .L80267F88
/* 196850 80267F70 24020003 */   addiu    $v0, $zero, 3
/* 196854 80267F74 82230088 */  lb        $v1, 0x88($s1)
/* 196858 80267F78 14620003 */  bne       $v1, $v0, .L80267F88
/* 19685C 80267F7C 00000000 */   nop
/* 196860 80267F80 0C098EF2 */  jal       deduct_current_move_fp
/* 196864 80267F84 00000000 */   nop
.L80267F88:
/* 196868 80267F88 3C038029 */  lui       $v1, %hi(D_80293B80)
/* 19686C 80267F8C 24633B80 */  addiu     $v1, $v1, %lo(D_80293B80)
/* 196870 80267F90 8C620000 */  lw        $v0, ($v1)
/* 196874 80267F94 1040000B */  beqz      $v0, .L80267FC4
/* 196878 80267F98 0000802D */   daddu    $s0, $zero, $zero
/* 19687C 80267F9C 8624017A */  lh        $a0, 0x17a($s1)
/* 196880 80267FA0 8C620000 */  lw        $v0, ($v1)
.L80267FA4:
/* 196884 80267FA4 10440005 */  beq       $v0, $a0, .L80267FBC
/* 196888 80267FA8 24630004 */   addiu    $v1, $v1, 4
/* 19688C 80267FAC 8C620000 */  lw        $v0, ($v1)
/* 196890 80267FB0 1440FFFC */  bnez      $v0, .L80267FA4
/* 196894 80267FB4 26100001 */   addiu    $s0, $s0, 1
/* 196898 80267FB8 8C620000 */  lw        $v0, ($v1)
.L80267FBC:
/* 19689C 80267FBC 14400004 */  bnez      $v0, .L80267FD0
/* 1968A0 80267FC0 00000000 */   nop
.L80267FC4:
/* 1968A4 80267FC4 96420018 */  lhu       $v0, 0x18($s2)
/* 1968A8 80267FC8 30420080 */  andi      $v0, $v0, 0x80
/* 1968AC 80267FCC 2C500001 */  sltiu     $s0, $v0, 1
.L80267FD0:
/* 1968B0 80267FD0 3C028029 */  lui       $v0, %hi(gBattleItemTable)
/* 1968B4 80267FD4 24423C04 */  addiu     $v0, $v0, %lo(gBattleItemTable)
/* 1968B8 80267FD8 00108100 */  sll       $s0, $s0, 4
/* 1968BC 80267FDC 02028021 */  addu      $s0, $s0, $v0
/* 1968C0 80267FE0 8E040000 */  lw        $a0, ($s0)
/* 1968C4 80267FE4 8E050004 */  lw        $a1, 4($s0)
/* 1968C8 80267FE8 0C00A5CF */  jal       dma_copy
/* 1968CC 80267FEC 8E060008 */   lw       $a2, 8($s0)
/* 1968D0 80267FF0 8E03000C */  lw        $v1, 0xc($s0)
/* 1968D4 80267FF4 AE600088 */  sw        $zero, 0x88($s3)
/* 1968D8 80267FF8 AE630084 */  sw        $v1, 0x84($s3)
/* 1968DC 80267FFC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1968E0 80268000 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1968E4 80268004 8FB20018 */  lw        $s2, 0x18($sp)
/* 1968E8 80268008 8FB10014 */  lw        $s1, 0x14($sp)
/* 1968EC 8026800C 8FB00010 */  lw        $s0, 0x10($sp)
/* 1968F0 80268010 24020002 */  addiu     $v0, $zero, 2
/* 1968F4 80268014 03E00008 */  jr        $ra
/* 1968F8 80268018 27BD0028 */   addiu    $sp, $sp, 0x28
