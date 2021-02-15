.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E26C4
/* 7BB74 800E26C4 3C04800F */  lui       $a0, %hi(gPlayerStatusPtr)
/* 7BB78 800E26C8 8C847B30 */  lw        $a0, %lo(gPlayerStatusPtr)($a0)
/* 7BB7C 800E26CC 808300B4 */  lb        $v1, 0xb4($a0)
/* 7BB80 800E26D0 3C058011 */  lui       $a1, %hi(D_8010EBB0)
/* 7BB84 800E26D4 24A5EBB0 */  addiu     $a1, $a1, %lo(D_8010EBB0)
/* 7BB88 800E26D8 2C620003 */  sltiu     $v0, $v1, 3
/* 7BB8C 800E26DC 14400005 */  bnez      $v0, .L800E26F4
/* 7BB90 800E26E0 2402001F */   addiu    $v0, $zero, 0x1f
/* 7BB94 800E26E4 10620003 */  beq       $v1, $v0, .L800E26F4
/* 7BB98 800E26E8 2402001A */   addiu    $v0, $zero, 0x1a
/* 7BB9C 800E26EC 14620003 */  bne       $v1, $v0, .L800E26FC
/* 7BBA0 800E26F0 24020021 */   addiu    $v0, $zero, 0x21
.L800E26F4:
/* 7BBA4 800E26F4 03E00008 */  jr        $ra
/* 7BBA8 800E26F8 24020001 */   addiu    $v0, $zero, 1
.L800E26FC:
/* 7BBAC 800E26FC 1462001C */  bne       $v1, $v0, .L800E2770
/* 7BBB0 800E2700 00000000 */   nop
/* 7BBB4 800E2704 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 7BBB8 800E2708 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 7BBBC 800E270C 90420012 */  lbu       $v0, 0x12($v0)
/* 7BBC0 800E2710 2442FFF8 */  addiu     $v0, $v0, -8
/* 7BBC4 800E2714 2C420002 */  sltiu     $v0, $v0, 2
/* 7BBC8 800E2718 10400009 */  beqz      $v0, .L800E2740
/* 7BBCC 800E271C 00000000 */   nop
/* 7BBD0 800E2720 80A20000 */  lb        $v0, ($a1)
/* 7BBD4 800E2724 1440FFF3 */  bnez      $v0, .L800E26F4
/* 7BBD8 800E2728 00000000 */   nop
.L800E272C:
/* 7BBDC 800E272C 8C830004 */  lw        $v1, 4($a0)
/* 7BBE0 800E2730 0000102D */  daddu     $v0, $zero, $zero
/* 7BBE4 800E2734 34630004 */  ori       $v1, $v1, 4
/* 7BBE8 800E2738 03E00008 */  jr        $ra
/* 7BBEC 800E273C AC830004 */   sw       $v1, 4($a0)
.L800E2740:
/* 7BBF0 800E2740 90A30003 */  lbu       $v1, 3($a1)
/* 7BBF4 800E2744 2462FFFA */  addiu     $v0, $v1, -6
/* 7BBF8 800E2748 2C420002 */  sltiu     $v0, $v0, 2
/* 7BBFC 800E274C 50400004 */  beql      $v0, $zero, .L800E2760
/* 7BC00 800E2750 00031600 */   sll      $v0, $v1, 0x18
/* 7BC04 800E2754 80A20000 */  lb        $v0, ($a1)
/* 7BC08 800E2758 03E00008 */  jr        $ra
/* 7BC0C 800E275C 0002102B */   sltu     $v0, $zero, $v0
.L800E2760:
/* 7BC10 800E2760 00021603 */  sra       $v0, $v0, 0x18
/* 7BC14 800E2764 24030004 */  addiu     $v1, $zero, 4
/* 7BC18 800E2768 1043FFF0 */  beq       $v0, $v1, .L800E272C
/* 7BC1C 800E276C 00000000 */   nop
.L800E2770:
/* 7BC20 800E2770 03E00008 */  jr        $ra
/* 7BC24 800E2774 0000102D */   daddu    $v0, $zero, $zero
