.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240530_D7B7D0
/* D7B7D0 80240530 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D7B7D4 80240534 AFB00040 */  sw        $s0, 0x40($sp)
/* D7B7D8 80240538 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D7B7DC 8024053C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D7B7E0 80240540 AFB10044 */  sw        $s1, 0x44($sp)
/* D7B7E4 80240544 AFBF004C */  sw        $ra, 0x4c($sp)
/* D7B7E8 80240548 AFB20048 */  sw        $s2, 0x48($sp)
/* D7B7EC 8024054C 8E020000 */  lw        $v0, ($s0)
/* D7B7F0 80240550 821200BE */  lb        $s2, 0xbe($s0)
/* D7B7F4 80240554 30420001 */  andi      $v0, $v0, 1
/* D7B7F8 80240558 10400052 */  beqz      $v0, .L802406A4
/* D7B7FC 8024055C 27B10020 */   addiu    $s1, $sp, 0x20
/* D7B800 80240560 8E0400CC */  lw        $a0, 0xcc($s0)
/* D7B804 80240564 0C044181 */  jal       get_shadow_by_index
/* D7B808 80240568 00000000 */   nop      
/* D7B80C 8024056C 0C048B77 */  jal       func_80122DDC
/* D7B810 80240570 84440008 */   lh       $a0, 8($v0)
/* D7B814 80240574 8E050028 */  lw        $a1, 0x28($s0)
/* D7B818 80240578 8E070030 */  lw        $a3, 0x30($s0)
/* D7B81C 8024057C 27A20030 */  addiu     $v0, $sp, 0x30
/* D7B820 80240580 AFA20010 */  sw        $v0, 0x10($sp)
/* D7B824 80240584 27A20034 */  addiu     $v0, $sp, 0x34
/* D7B828 80240588 AFA20014 */  sw        $v0, 0x14($sp)
/* D7B82C 8024058C 27A20038 */  addiu     $v0, $sp, 0x38
/* D7B830 80240590 AFA20018 */  sw        $v0, 0x18($sp)
/* D7B834 80240594 C600002C */  lwc1      $f0, 0x2c($s0)
/* D7B838 80240598 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D7B83C 8024059C 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D7B840 802405A0 46000007 */  neg.s     $f0, $f0
/* D7B844 802405A4 44060000 */  mfc1      $a2, $f0
/* D7B848 802405A8 0C00B94E */  jal       get_screen_coords
/* D7B84C 802405AC 00000000 */   nop      
/* D7B850 802405B0 8E0500A4 */  lw        $a1, 0xa4($s0)
/* D7B854 802405B4 3C063F80 */  lui       $a2, 0x3f80
/* D7B858 802405B8 0C0B76A3 */  jal       func_802DDA8C
/* D7B85C 802405BC 24040001 */   addiu    $a0, $zero, 1
/* D7B860 802405C0 8E020000 */  lw        $v0, ($s0)
/* D7B864 802405C4 3C030002 */  lui       $v1, 2
/* D7B868 802405C8 00431024 */  and       $v0, $v0, $v1
/* D7B86C 802405CC 54400022 */  bnel      $v0, $zero, .L80240658
/* D7B870 802405D0 24120011 */   addiu    $s2, $zero, 0x11
/* D7B874 802405D4 9203000E */  lbu       $v1, 0xe($s0)
/* D7B878 802405D8 3C02802E */  lui       $v0, %hi(D_802D9D71)
/* D7B87C 802405DC 90429D71 */  lbu       $v0, %lo(D_802D9D71)($v0)
/* D7B880 802405E0 10620018 */  beq       $v1, $v0, .L80240644
/* D7B884 802405E4 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D7B888 802405E8 1040000B */  beqz      $v0, .L80240618
/* D7B88C 802405EC 24120011 */   addiu    $s2, $zero, 0x11
/* D7B890 802405F0 24040001 */  addiu     $a0, $zero, 1
/* D7B894 802405F4 2405FFFF */  addiu     $a1, $zero, -1
/* D7B898 802405F8 24060007 */  addiu     $a2, $zero, 7
/* D7B89C 802405FC 0060102D */  daddu     $v0, $v1, $zero
/* D7B8A0 80240600 0000382D */  daddu     $a3, $zero, $zero
/* D7B8A4 80240604 AFA00010 */  sw        $zero, 0x10($sp)
/* D7B8A8 80240608 AFA00014 */  sw        $zero, 0x14($sp)
/* D7B8AC 8024060C AFA0001C */  sw        $zero, 0x1c($sp)
/* D7B8B0 80240610 0809018F */  j         .L8024063C
/* D7B8B4 80240614 AFA20018 */   sw       $v0, 0x18($sp)
.L80240618:
/* D7B8B8 80240618 2412000D */  addiu     $s2, $zero, 0xd
/* D7B8BC 8024061C 24040001 */  addiu     $a0, $zero, 1
/* D7B8C0 80240620 2405FFFF */  addiu     $a1, $zero, -1
/* D7B8C4 80240624 0000302D */  daddu     $a2, $zero, $zero
/* D7B8C8 80240628 00C0382D */  daddu     $a3, $a2, $zero
/* D7B8CC 8024062C AFA00010 */  sw        $zero, 0x10($sp)
/* D7B8D0 80240630 AFA00014 */  sw        $zero, 0x14($sp)
/* D7B8D4 80240634 AFA00018 */  sw        $zero, 0x18($sp)
/* D7B8D8 80240638 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024063C:
/* D7B8DC 8024063C 0C0B77B9 */  jal       func_802DDEE4
/* D7B8E0 80240640 00000000 */   nop      
.L80240644:
/* D7B8E4 80240644 9202000E */  lbu       $v0, 0xe($s0)
/* D7B8E8 80240648 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D7B8EC 8024064C A0229D71 */  sb        $v0, %lo(D_802D9D71)($at)
/* D7B8F0 80240650 08090198 */  j         .L80240660
/* D7B8F4 80240654 00000000 */   nop      
.L80240658:
/* D7B8F8 80240658 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D7B8FC 8024065C A0209D71 */  sb        $zero, %lo(D_802D9D71)($at)
.L80240660:
/* D7B900 80240660 8FA20038 */  lw        $v0, 0x38($sp)
/* D7B904 80240664 3C048024 */  lui       $a0, %hi(func_802408A0_D7BB40)
/* D7B908 80240668 248408A0 */  addiu     $a0, $a0, %lo(func_802408A0_D7BB40)
/* D7B90C 8024066C AE320000 */  sw        $s2, ($s1)
/* D7B910 80240670 AE300008 */  sw        $s0, 8($s1)
/* D7B914 80240674 00021023 */  negu      $v0, $v0
/* D7B918 80240678 AE220004 */  sw        $v0, 4($s1)
/* D7B91C 8024067C 8E020000 */  lw        $v0, ($s0)
/* D7B920 80240680 3C030002 */  lui       $v1, 2
/* D7B924 80240684 00431024 */  and       $v0, $v0, $v1
/* D7B928 80240688 54400004 */  bnel      $v0, $zero, .L8024069C
/* D7B92C 8024068C AE24000C */   sw       $a0, 0xc($s1)
/* D7B930 80240690 3C048024 */  lui       $a0, %hi(func_802406BC_D7B95C)
/* D7B934 80240694 248406BC */  addiu     $a0, $a0, %lo(func_802406BC_D7B95C)
/* D7B938 80240698 AE24000C */  sw        $a0, 0xc($s1)
.L8024069C:
/* D7B93C 8024069C 0C047644 */  jal       queue_render_task
/* D7B940 802406A0 0220202D */   daddu    $a0, $s1, $zero
.L802406A4:
/* D7B944 802406A4 8FBF004C */  lw        $ra, 0x4c($sp)
/* D7B948 802406A8 8FB20048 */  lw        $s2, 0x48($sp)
/* D7B94C 802406AC 8FB10044 */  lw        $s1, 0x44($sp)
/* D7B950 802406B0 8FB00040 */  lw        $s0, 0x40($sp)
/* D7B954 802406B4 03E00008 */  jr        $ra
/* D7B958 802406B8 27BD0050 */   addiu    $sp, $sp, 0x50
