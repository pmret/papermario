.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240500_D5F7B0
/* D5F7B0 80240500 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D5F7B4 80240504 AFB00040 */  sw        $s0, 0x40($sp)
/* D5F7B8 80240508 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D5F7BC 8024050C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D5F7C0 80240510 AFB10044 */  sw        $s1, 0x44($sp)
/* D5F7C4 80240514 AFBF004C */  sw        $ra, 0x4c($sp)
/* D5F7C8 80240518 AFB20048 */  sw        $s2, 0x48($sp)
/* D5F7CC 8024051C 8E020000 */  lw        $v0, ($s0)
/* D5F7D0 80240520 821200BE */  lb        $s2, 0xbe($s0)
/* D5F7D4 80240524 30420001 */  andi      $v0, $v0, 1
/* D5F7D8 80240528 10400052 */  beqz      $v0, .L80240674
/* D5F7DC 8024052C 27B10020 */   addiu    $s1, $sp, 0x20
/* D5F7E0 80240530 8E0400CC */  lw        $a0, 0xcc($s0)
/* D5F7E4 80240534 0C044181 */  jal       get_shadow_by_index
/* D5F7E8 80240538 00000000 */   nop
/* D5F7EC 8024053C 0C048B77 */  jal       func_80122DDC
/* D5F7F0 80240540 84440008 */   lh       $a0, 8($v0)
/* D5F7F4 80240544 8E050028 */  lw        $a1, 0x28($s0)
/* D5F7F8 80240548 8E070030 */  lw        $a3, 0x30($s0)
/* D5F7FC 8024054C 27A20030 */  addiu     $v0, $sp, 0x30
/* D5F800 80240550 AFA20010 */  sw        $v0, 0x10($sp)
/* D5F804 80240554 27A20034 */  addiu     $v0, $sp, 0x34
/* D5F808 80240558 AFA20014 */  sw        $v0, 0x14($sp)
/* D5F80C 8024055C 27A20038 */  addiu     $v0, $sp, 0x38
/* D5F810 80240560 AFA20018 */  sw        $v0, 0x18($sp)
/* D5F814 80240564 C600002C */  lwc1      $f0, 0x2c($s0)
/* D5F818 80240568 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D5F81C 8024056C 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D5F820 80240570 46000007 */  neg.s     $f0, $f0
/* D5F824 80240574 44060000 */  mfc1      $a2, $f0
/* D5F828 80240578 0C00B94E */  jal       get_screen_coords
/* D5F82C 8024057C 00000000 */   nop
/* D5F830 80240580 8E0500A4 */  lw        $a1, 0xa4($s0)
/* D5F834 80240584 3C063F80 */  lui       $a2, 0x3f80
/* D5F838 80240588 0C0B76A3 */  jal       func_802DDA8C
/* D5F83C 8024058C 24040001 */   addiu    $a0, $zero, 1
/* D5F840 80240590 8E020000 */  lw        $v0, ($s0)
/* D5F844 80240594 3C030002 */  lui       $v1, 2
/* D5F848 80240598 00431024 */  and       $v0, $v0, $v1
/* D5F84C 8024059C 54400022 */  bnel      $v0, $zero, .L80240628
/* D5F850 802405A0 24120011 */   addiu    $s2, $zero, 0x11
/* D5F854 802405A4 9203000E */  lbu       $v1, 0xe($s0)
/* D5F858 802405A8 3C02802E */  lui       $v0, %hi(D_802D9D71)
/* D5F85C 802405AC 90429D71 */  lbu       $v0, %lo(D_802D9D71)($v0)
/* D5F860 802405B0 10620018 */  beq       $v1, $v0, .L80240614
/* D5F864 802405B4 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D5F868 802405B8 1040000B */  beqz      $v0, .L802405E8
/* D5F86C 802405BC 24120011 */   addiu    $s2, $zero, 0x11
/* D5F870 802405C0 24040001 */  addiu     $a0, $zero, 1
/* D5F874 802405C4 2405FFFF */  addiu     $a1, $zero, -1
/* D5F878 802405C8 24060007 */  addiu     $a2, $zero, 7
/* D5F87C 802405CC 0060102D */  daddu     $v0, $v1, $zero
/* D5F880 802405D0 0000382D */  daddu     $a3, $zero, $zero
/* D5F884 802405D4 AFA00010 */  sw        $zero, 0x10($sp)
/* D5F888 802405D8 AFA00014 */  sw        $zero, 0x14($sp)
/* D5F88C 802405DC AFA0001C */  sw        $zero, 0x1c($sp)
/* D5F890 802405E0 08090183 */  j         .L8024060C
/* D5F894 802405E4 AFA20018 */   sw       $v0, 0x18($sp)
.L802405E8:
/* D5F898 802405E8 2412000D */  addiu     $s2, $zero, 0xd
/* D5F89C 802405EC 24040001 */  addiu     $a0, $zero, 1
/* D5F8A0 802405F0 2405FFFF */  addiu     $a1, $zero, -1
/* D5F8A4 802405F4 0000302D */  daddu     $a2, $zero, $zero
/* D5F8A8 802405F8 00C0382D */  daddu     $a3, $a2, $zero
/* D5F8AC 802405FC AFA00010 */  sw        $zero, 0x10($sp)
/* D5F8B0 80240600 AFA00014 */  sw        $zero, 0x14($sp)
/* D5F8B4 80240604 AFA00018 */  sw        $zero, 0x18($sp)
/* D5F8B8 80240608 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024060C:
/* D5F8BC 8024060C 0C0B77B9 */  jal       func_802DDEE4
/* D5F8C0 80240610 00000000 */   nop
.L80240614:
/* D5F8C4 80240614 9202000E */  lbu       $v0, 0xe($s0)
/* D5F8C8 80240618 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D5F8CC 8024061C A0229D71 */  sb        $v0, %lo(D_802D9D71)($at)
/* D5F8D0 80240620 0809018C */  j         .L80240630
/* D5F8D4 80240624 00000000 */   nop
.L80240628:
/* D5F8D8 80240628 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D5F8DC 8024062C A0209D71 */  sb        $zero, %lo(D_802D9D71)($at)
.L80240630:
/* D5F8E0 80240630 8FA20038 */  lw        $v0, 0x38($sp)
/* D5F8E4 80240634 3C048024 */  lui       $a0, %hi(func_80240870_D5FB20)
/* D5F8E8 80240638 24840870 */  addiu     $a0, $a0, %lo(func_80240870_D5FB20)
/* D5F8EC 8024063C AE320000 */  sw        $s2, ($s1)
/* D5F8F0 80240640 AE300008 */  sw        $s0, 8($s1)
/* D5F8F4 80240644 00021023 */  negu      $v0, $v0
/* D5F8F8 80240648 AE220004 */  sw        $v0, 4($s1)
/* D5F8FC 8024064C 8E020000 */  lw        $v0, ($s0)
/* D5F900 80240650 3C030002 */  lui       $v1, 2
/* D5F904 80240654 00431024 */  and       $v0, $v0, $v1
/* D5F908 80240658 54400004 */  bnel      $v0, $zero, .L8024066C
/* D5F90C 8024065C AE24000C */   sw       $a0, 0xc($s1)
/* D5F910 80240660 3C048024 */  lui       $a0, %hi(func_8024068C_D5F93C)
/* D5F914 80240664 2484068C */  addiu     $a0, $a0, %lo(func_8024068C_D5F93C)
/* D5F918 80240668 AE24000C */  sw        $a0, 0xc($s1)
.L8024066C:
/* D5F91C 8024066C 0C047644 */  jal       queue_render_task
/* D5F920 80240670 0220202D */   daddu    $a0, $s1, $zero
.L80240674:
/* D5F924 80240674 8FBF004C */  lw        $ra, 0x4c($sp)
/* D5F928 80240678 8FB20048 */  lw        $s2, 0x48($sp)
/* D5F92C 8024067C 8FB10044 */  lw        $s1, 0x44($sp)
/* D5F930 80240680 8FB00040 */  lw        $s0, 0x40($sp)
/* D5F934 80240684 03E00008 */  jr        $ra
/* D5F938 80240688 27BD0050 */   addiu    $sp, $sp, 0x50
