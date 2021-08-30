.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetPushBlock
/* 7E4440 802835C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7E4444 802835C4 AFB40020 */  sw        $s4, 0x20($sp)
/* 7E4448 802835C8 0080A02D */  daddu     $s4, $a0, $zero
/* 7E444C 802835CC AFBF0024 */  sw        $ra, 0x24($sp)
/* 7E4450 802835D0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7E4454 802835D4 AFB20018 */  sw        $s2, 0x18($sp)
/* 7E4458 802835D8 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E445C 802835DC AFB00010 */  sw        $s0, 0x10($sp)
/* 7E4460 802835E0 8E90000C */  lw        $s0, 0xc($s4)
/* 7E4464 802835E4 8E050000 */  lw        $a1, ($s0)
/* 7E4468 802835E8 0C0B1EAF */  jal       evt_get_variable
/* 7E446C 802835EC 26100004 */   addiu    $s0, $s0, 4
/* 7E4470 802835F0 8E050000 */  lw        $a1, ($s0)
/* 7E4474 802835F4 26100004 */  addiu     $s0, $s0, 4
/* 7E4478 802835F8 0280202D */  daddu     $a0, $s4, $zero
/* 7E447C 802835FC 0C0B1EAF */  jal       evt_get_variable
/* 7E4480 80283600 0040882D */   daddu    $s1, $v0, $zero
/* 7E4484 80283604 0280202D */  daddu     $a0, $s4, $zero
/* 7E4488 80283608 8E050000 */  lw        $a1, ($s0)
/* 7E448C 8028360C 0C0B1EAF */  jal       evt_get_variable
/* 7E4490 80283610 0040982D */   daddu    $s3, $v0, $zero
/* 7E4494 80283614 00118880 */  sll       $s1, $s1, 2
/* 7E4498 80283618 26100004 */  addiu     $s0, $s0, 4
/* 7E449C 8028361C 3C12802E */  lui       $s2, %hi(D_802DBC88)
/* 7E44A0 80283620 02519021 */  addu      $s2, $s2, $s1
/* 7E44A4 80283624 8E52BC88 */  lw        $s2, %lo(D_802DBC88)($s2)
/* 7E44A8 80283628 92430004 */  lbu       $v1, 4($s2)
/* 7E44AC 8028362C 8E100000 */  lw        $s0, ($s0)
/* 7E44B0 80283630 0263182A */  slt       $v1, $s3, $v1
/* 7E44B4 80283634 10600009 */  beqz      $v1, .L8028365C
/* 7E44B8 80283638 0040882D */   daddu    $s1, $v0, $zero
/* 7E44BC 8028363C 06600008 */  bltz      $s3, .L80283660
/* 7E44C0 80283640 0280202D */   daddu    $a0, $s4, $zero
/* 7E44C4 80283644 92420005 */  lbu       $v0, 5($s2)
/* 7E44C8 80283648 0222102A */  slt       $v0, $s1, $v0
/* 7E44CC 8028364C 10400005 */  beqz      $v0, .L80283664
/* 7E44D0 80283650 0200282D */   daddu    $a1, $s0, $zero
/* 7E44D4 80283654 06210005 */  bgez      $s1, .L8028366C
/* 7E44D8 80283658 00000000 */   nop
.L8028365C:
/* 7E44DC 8028365C 0280202D */  daddu     $a0, $s4, $zero
.L80283660:
/* 7E44E0 80283660 0200282D */  daddu     $a1, $s0, $zero
.L80283664:
/* 7E44E4 80283664 0C0B2026 */  jal       evt_set_variable
/* 7E44E8 80283668 24060003 */   addiu    $a2, $zero, 3
.L8028366C:
/* 7E44EC 8028366C 92420004 */  lbu       $v0, 4($s2)
/* 7E44F0 80283670 02220018 */  mult      $s1, $v0
/* 7E44F4 80283674 0280202D */  daddu     $a0, $s4, $zero
/* 7E44F8 80283678 8E420000 */  lw        $v0, ($s2)
/* 7E44FC 8028367C 00003812 */  mflo      $a3
/* 7E4500 80283680 02671821 */  addu      $v1, $s3, $a3
/* 7E4504 80283684 00431021 */  addu      $v0, $v0, $v1
/* 7E4508 80283688 90460000 */  lbu       $a2, ($v0)
/* 7E450C 8028368C 0C0B2026 */  jal       evt_set_variable
/* 7E4510 80283690 0200282D */   daddu    $a1, $s0, $zero
/* 7E4514 80283694 8FBF0024 */  lw        $ra, 0x24($sp)
/* 7E4518 80283698 8FB40020 */  lw        $s4, 0x20($sp)
/* 7E451C 8028369C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7E4520 802836A0 8FB20018 */  lw        $s2, 0x18($sp)
/* 7E4524 802836A4 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E4528 802836A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E452C 802836AC 24020002 */  addiu     $v0, $zero, 2
/* 7E4530 802836B0 03E00008 */  jr        $ra
/* 7E4534 802836B4 27BD0028 */   addiu    $sp, $sp, 0x28
