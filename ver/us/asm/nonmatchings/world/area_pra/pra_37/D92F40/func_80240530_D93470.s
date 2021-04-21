.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240530_D93470
/* D93470 80240530 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D93474 80240534 AFB00040 */  sw        $s0, 0x40($sp)
/* D93478 80240538 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D9347C 8024053C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D93480 80240540 AFB10044 */  sw        $s1, 0x44($sp)
/* D93484 80240544 AFBF004C */  sw        $ra, 0x4c($sp)
/* D93488 80240548 AFB20048 */  sw        $s2, 0x48($sp)
/* D9348C 8024054C 8E020000 */  lw        $v0, ($s0)
/* D93490 80240550 821200BE */  lb        $s2, 0xbe($s0)
/* D93494 80240554 30420001 */  andi      $v0, $v0, 1
/* D93498 80240558 10400052 */  beqz      $v0, .L802406A4
/* D9349C 8024055C 27B10020 */   addiu    $s1, $sp, 0x20
/* D934A0 80240560 8E0400CC */  lw        $a0, 0xcc($s0)
/* D934A4 80240564 0C044181 */  jal       get_shadow_by_index
/* D934A8 80240568 00000000 */   nop
/* D934AC 8024056C 0C048B77 */  jal       get_entity_model
/* D934B0 80240570 84440008 */   lh       $a0, 8($v0)
/* D934B4 80240574 8E050028 */  lw        $a1, 0x28($s0)
/* D934B8 80240578 8E070030 */  lw        $a3, 0x30($s0)
/* D934BC 8024057C 27A20030 */  addiu     $v0, $sp, 0x30
/* D934C0 80240580 AFA20010 */  sw        $v0, 0x10($sp)
/* D934C4 80240584 27A20034 */  addiu     $v0, $sp, 0x34
/* D934C8 80240588 AFA20014 */  sw        $v0, 0x14($sp)
/* D934CC 8024058C 27A20038 */  addiu     $v0, $sp, 0x38
/* D934D0 80240590 AFA20018 */  sw        $v0, 0x18($sp)
/* D934D4 80240594 C600002C */  lwc1      $f0, 0x2c($s0)
/* D934D8 80240598 3C04800A */  lui       $a0, %hi(gCurrentCamID)
/* D934DC 8024059C 8484A634 */  lh        $a0, %lo(gCurrentCamID)($a0)
/* D934E0 802405A0 46000007 */  neg.s     $f0, $f0
/* D934E4 802405A4 44060000 */  mfc1      $a2, $f0
/* D934E8 802405A8 0C00B94E */  jal       get_screen_coords
/* D934EC 802405AC 00000000 */   nop
/* D934F0 802405B0 8E0500A4 */  lw        $a1, 0xa4($s0)
/* D934F4 802405B4 3C063F80 */  lui       $a2, 0x3f80
/* D934F8 802405B8 0C0B76A3 */  jal       func_802DDA8C
/* D934FC 802405BC 24040001 */   addiu    $a0, $zero, 1
/* D93500 802405C0 8E020000 */  lw        $v0, ($s0)
/* D93504 802405C4 3C030002 */  lui       $v1, 2
/* D93508 802405C8 00431024 */  and       $v0, $v0, $v1
/* D9350C 802405CC 54400022 */  bnel      $v0, $zero, .L80240658
/* D93510 802405D0 24120011 */   addiu    $s2, $zero, 0x11
/* D93514 802405D4 9203000E */  lbu       $v1, 0xe($s0)
/* D93518 802405D8 3C02802E */  lui       $v0, %hi(D_802D9D71)
/* D9351C 802405DC 90429D71 */  lbu       $v0, %lo(D_802D9D71)($v0)
/* D93520 802405E0 10620018 */  beq       $v1, $v0, .L80240644
/* D93524 802405E4 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D93528 802405E8 1040000B */  beqz      $v0, .L80240618
/* D9352C 802405EC 24120011 */   addiu    $s2, $zero, 0x11
/* D93530 802405F0 24040001 */  addiu     $a0, $zero, 1
/* D93534 802405F4 2405FFFF */  addiu     $a1, $zero, -1
/* D93538 802405F8 24060007 */  addiu     $a2, $zero, 7
/* D9353C 802405FC 0060102D */  daddu     $v0, $v1, $zero
/* D93540 80240600 0000382D */  daddu     $a3, $zero, $zero
/* D93544 80240604 AFA00010 */  sw        $zero, 0x10($sp)
/* D93548 80240608 AFA00014 */  sw        $zero, 0x14($sp)
/* D9354C 8024060C AFA0001C */  sw        $zero, 0x1c($sp)
/* D93550 80240610 0809018F */  j         .L8024063C
/* D93554 80240614 AFA20018 */   sw       $v0, 0x18($sp)
.L80240618:
/* D93558 80240618 2412000D */  addiu     $s2, $zero, 0xd
/* D9355C 8024061C 24040001 */  addiu     $a0, $zero, 1
/* D93560 80240620 2405FFFF */  addiu     $a1, $zero, -1
/* D93564 80240624 0000302D */  daddu     $a2, $zero, $zero
/* D93568 80240628 00C0382D */  daddu     $a3, $a2, $zero
/* D9356C 8024062C AFA00010 */  sw        $zero, 0x10($sp)
/* D93570 80240630 AFA00014 */  sw        $zero, 0x14($sp)
/* D93574 80240634 AFA00018 */  sw        $zero, 0x18($sp)
/* D93578 80240638 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024063C:
/* D9357C 8024063C 0C0B77B9 */  jal       func_802DDEE4
/* D93580 80240640 00000000 */   nop
.L80240644:
/* D93584 80240644 9202000E */  lbu       $v0, 0xe($s0)
/* D93588 80240648 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D9358C 8024064C A0229D71 */  sb        $v0, %lo(D_802D9D71)($at)
/* D93590 80240650 08090198 */  j         .L80240660
/* D93594 80240654 00000000 */   nop
.L80240658:
/* D93598 80240658 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D9359C 8024065C A0209D71 */  sb        $zero, %lo(D_802D9D71)($at)
.L80240660:
/* D935A0 80240660 8FA20038 */  lw        $v0, 0x38($sp)
/* D935A4 80240664 3C048024 */  lui       $a0, %hi(func_802408A0_D937E0)
/* D935A8 80240668 248408A0 */  addiu     $a0, $a0, %lo(func_802408A0_D937E0)
/* D935AC 8024066C AE320000 */  sw        $s2, ($s1)
/* D935B0 80240670 AE300008 */  sw        $s0, 8($s1)
/* D935B4 80240674 00021023 */  negu      $v0, $v0
/* D935B8 80240678 AE220004 */  sw        $v0, 4($s1)
/* D935BC 8024067C 8E020000 */  lw        $v0, ($s0)
/* D935C0 80240680 3C030002 */  lui       $v1, 2
/* D935C4 80240684 00431024 */  and       $v0, $v0, $v1
/* D935C8 80240688 54400004 */  bnel      $v0, $zero, .L8024069C
/* D935CC 8024068C AE24000C */   sw       $a0, 0xc($s1)
/* D935D0 80240690 3C048024 */  lui       $a0, %hi(func_802406BC_D935FC)
/* D935D4 80240694 248406BC */  addiu     $a0, $a0, %lo(func_802406BC_D935FC)
/* D935D8 80240698 AE24000C */  sw        $a0, 0xc($s1)
.L8024069C:
/* D935DC 8024069C 0C047644 */  jal       queue_render_task
/* D935E0 802406A0 0220202D */   daddu    $a0, $s1, $zero
.L802406A4:
/* D935E4 802406A4 8FBF004C */  lw        $ra, 0x4c($sp)
/* D935E8 802406A8 8FB20048 */  lw        $s2, 0x48($sp)
/* D935EC 802406AC 8FB10044 */  lw        $s1, 0x44($sp)
/* D935F0 802406B0 8FB00040 */  lw        $s0, 0x40($sp)
/* D935F4 802406B4 03E00008 */  jr        $ra
/* D935F8 802406B8 27BD0050 */   addiu    $sp, $sp, 0x50
