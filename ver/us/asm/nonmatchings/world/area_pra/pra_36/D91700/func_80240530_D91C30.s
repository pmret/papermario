.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240530_D91C30
/* D91C30 80240530 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D91C34 80240534 AFB00040 */  sw        $s0, 0x40($sp)
/* D91C38 80240538 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D91C3C 8024053C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D91C40 80240540 AFB10044 */  sw        $s1, 0x44($sp)
/* D91C44 80240544 AFBF004C */  sw        $ra, 0x4c($sp)
/* D91C48 80240548 AFB20048 */  sw        $s2, 0x48($sp)
/* D91C4C 8024054C 8E020000 */  lw        $v0, ($s0)
/* D91C50 80240550 821200BE */  lb        $s2, 0xbe($s0)
/* D91C54 80240554 30420001 */  andi      $v0, $v0, 1
/* D91C58 80240558 10400052 */  beqz      $v0, .L802406A4
/* D91C5C 8024055C 27B10020 */   addiu    $s1, $sp, 0x20
/* D91C60 80240560 8E0400CC */  lw        $a0, 0xcc($s0)
/* D91C64 80240564 0C044181 */  jal       get_shadow_by_index
/* D91C68 80240568 00000000 */   nop
/* D91C6C 8024056C 0C048B77 */  jal       func_80122DDC
/* D91C70 80240570 84440008 */   lh       $a0, 8($v0)
/* D91C74 80240574 8E050028 */  lw        $a1, 0x28($s0)
/* D91C78 80240578 8E070030 */  lw        $a3, 0x30($s0)
/* D91C7C 8024057C 27A20030 */  addiu     $v0, $sp, 0x30
/* D91C80 80240580 AFA20010 */  sw        $v0, 0x10($sp)
/* D91C84 80240584 27A20034 */  addiu     $v0, $sp, 0x34
/* D91C88 80240588 AFA20014 */  sw        $v0, 0x14($sp)
/* D91C8C 8024058C 27A20038 */  addiu     $v0, $sp, 0x38
/* D91C90 80240590 AFA20018 */  sw        $v0, 0x18($sp)
/* D91C94 80240594 C600002C */  lwc1      $f0, 0x2c($s0)
/* D91C98 80240598 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D91C9C 8024059C 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D91CA0 802405A0 46000007 */  neg.s     $f0, $f0
/* D91CA4 802405A4 44060000 */  mfc1      $a2, $f0
/* D91CA8 802405A8 0C00B94E */  jal       get_screen_coords
/* D91CAC 802405AC 00000000 */   nop
/* D91CB0 802405B0 8E0500A4 */  lw        $a1, 0xa4($s0)
/* D91CB4 802405B4 3C063F80 */  lui       $a2, 0x3f80
/* D91CB8 802405B8 0C0B76A3 */  jal       func_802DDA8C
/* D91CBC 802405BC 24040001 */   addiu    $a0, $zero, 1
/* D91CC0 802405C0 8E020000 */  lw        $v0, ($s0)
/* D91CC4 802405C4 3C030002 */  lui       $v1, 2
/* D91CC8 802405C8 00431024 */  and       $v0, $v0, $v1
/* D91CCC 802405CC 54400022 */  bnel      $v0, $zero, .L80240658
/* D91CD0 802405D0 24120011 */   addiu    $s2, $zero, 0x11
/* D91CD4 802405D4 9203000E */  lbu       $v1, 0xe($s0)
/* D91CD8 802405D8 3C02802E */  lui       $v0, %hi(D_802D9D71)
/* D91CDC 802405DC 90429D71 */  lbu       $v0, %lo(D_802D9D71)($v0)
/* D91CE0 802405E0 10620018 */  beq       $v1, $v0, .L80240644
/* D91CE4 802405E4 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D91CE8 802405E8 1040000B */  beqz      $v0, .L80240618
/* D91CEC 802405EC 24120011 */   addiu    $s2, $zero, 0x11
/* D91CF0 802405F0 24040001 */  addiu     $a0, $zero, 1
/* D91CF4 802405F4 2405FFFF */  addiu     $a1, $zero, -1
/* D91CF8 802405F8 24060007 */  addiu     $a2, $zero, 7
/* D91CFC 802405FC 0060102D */  daddu     $v0, $v1, $zero
/* D91D00 80240600 0000382D */  daddu     $a3, $zero, $zero
/* D91D04 80240604 AFA00010 */  sw        $zero, 0x10($sp)
/* D91D08 80240608 AFA00014 */  sw        $zero, 0x14($sp)
/* D91D0C 8024060C AFA0001C */  sw        $zero, 0x1c($sp)
/* D91D10 80240610 0809018F */  j         .L8024063C
/* D91D14 80240614 AFA20018 */   sw       $v0, 0x18($sp)
.L80240618:
/* D91D18 80240618 2412000D */  addiu     $s2, $zero, 0xd
/* D91D1C 8024061C 24040001 */  addiu     $a0, $zero, 1
/* D91D20 80240620 2405FFFF */  addiu     $a1, $zero, -1
/* D91D24 80240624 0000302D */  daddu     $a2, $zero, $zero
/* D91D28 80240628 00C0382D */  daddu     $a3, $a2, $zero
/* D91D2C 8024062C AFA00010 */  sw        $zero, 0x10($sp)
/* D91D30 80240630 AFA00014 */  sw        $zero, 0x14($sp)
/* D91D34 80240634 AFA00018 */  sw        $zero, 0x18($sp)
/* D91D38 80240638 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024063C:
/* D91D3C 8024063C 0C0B77B9 */  jal       func_802DDEE4
/* D91D40 80240640 00000000 */   nop
.L80240644:
/* D91D44 80240644 9202000E */  lbu       $v0, 0xe($s0)
/* D91D48 80240648 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D91D4C 8024064C A0229D71 */  sb        $v0, %lo(D_802D9D71)($at)
/* D91D50 80240650 08090198 */  j         .L80240660
/* D91D54 80240654 00000000 */   nop
.L80240658:
/* D91D58 80240658 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D91D5C 8024065C A0209D71 */  sb        $zero, %lo(D_802D9D71)($at)
.L80240660:
/* D91D60 80240660 8FA20038 */  lw        $v0, 0x38($sp)
/* D91D64 80240664 3C048024 */  lui       $a0, %hi(func_802408A0_D91FA0)
/* D91D68 80240668 248408A0 */  addiu     $a0, $a0, %lo(func_802408A0_D91FA0)
/* D91D6C 8024066C AE320000 */  sw        $s2, ($s1)
/* D91D70 80240670 AE300008 */  sw        $s0, 8($s1)
/* D91D74 80240674 00021023 */  negu      $v0, $v0
/* D91D78 80240678 AE220004 */  sw        $v0, 4($s1)
/* D91D7C 8024067C 8E020000 */  lw        $v0, ($s0)
/* D91D80 80240680 3C030002 */  lui       $v1, 2
/* D91D84 80240684 00431024 */  and       $v0, $v0, $v1
/* D91D88 80240688 54400004 */  bnel      $v0, $zero, .L8024069C
/* D91D8C 8024068C AE24000C */   sw       $a0, 0xc($s1)
/* D91D90 80240690 3C048024 */  lui       $a0, %hi(func_802406BC_D91DBC)
/* D91D94 80240694 248406BC */  addiu     $a0, $a0, %lo(func_802406BC_D91DBC)
/* D91D98 80240698 AE24000C */  sw        $a0, 0xc($s1)
.L8024069C:
/* D91D9C 8024069C 0C047644 */  jal       queue_render_task
/* D91DA0 802406A0 0220202D */   daddu    $a0, $s1, $zero
.L802406A4:
/* D91DA4 802406A4 8FBF004C */  lw        $ra, 0x4c($sp)
/* D91DA8 802406A8 8FB20048 */  lw        $s2, 0x48($sp)
/* D91DAC 802406AC 8FB10044 */  lw        $s1, 0x44($sp)
/* D91DB0 802406B0 8FB00040 */  lw        $s0, 0x40($sp)
/* D91DB4 802406B4 03E00008 */  jr        $ra
/* D91DB8 802406B8 27BD0050 */   addiu    $sp, $sp, 0x50
