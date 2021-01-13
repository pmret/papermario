.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240500_D89BE0
/* D89BE0 80240500 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D89BE4 80240504 AFB00040 */  sw        $s0, 0x40($sp)
/* D89BE8 80240508 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D89BEC 8024050C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D89BF0 80240510 AFB10044 */  sw        $s1, 0x44($sp)
/* D89BF4 80240514 AFBF004C */  sw        $ra, 0x4c($sp)
/* D89BF8 80240518 AFB20048 */  sw        $s2, 0x48($sp)
/* D89BFC 8024051C 8E020000 */  lw        $v0, ($s0)
/* D89C00 80240520 821200BE */  lb        $s2, 0xbe($s0)
/* D89C04 80240524 30420001 */  andi      $v0, $v0, 1
/* D89C08 80240528 10400052 */  beqz      $v0, .L80240674
/* D89C0C 8024052C 27B10020 */   addiu    $s1, $sp, 0x20
/* D89C10 80240530 8E0400CC */  lw        $a0, 0xcc($s0)
/* D89C14 80240534 0C044181 */  jal       get_shadow_by_index
/* D89C18 80240538 00000000 */   nop
/* D89C1C 8024053C 0C048B77 */  jal       func_80122DDC
/* D89C20 80240540 84440008 */   lh       $a0, 8($v0)
/* D89C24 80240544 8E050028 */  lw        $a1, 0x28($s0)
/* D89C28 80240548 8E070030 */  lw        $a3, 0x30($s0)
/* D89C2C 8024054C 27A20030 */  addiu     $v0, $sp, 0x30
/* D89C30 80240550 AFA20010 */  sw        $v0, 0x10($sp)
/* D89C34 80240554 27A20034 */  addiu     $v0, $sp, 0x34
/* D89C38 80240558 AFA20014 */  sw        $v0, 0x14($sp)
/* D89C3C 8024055C 27A20038 */  addiu     $v0, $sp, 0x38
/* D89C40 80240560 AFA20018 */  sw        $v0, 0x18($sp)
/* D89C44 80240564 C600002C */  lwc1      $f0, 0x2c($s0)
/* D89C48 80240568 3C04800A */  lui       $a0, %hi(D_8009A634)
/* D89C4C 8024056C 8484A634 */  lh        $a0, %lo(D_8009A634)($a0)
/* D89C50 80240570 46000007 */  neg.s     $f0, $f0
/* D89C54 80240574 44060000 */  mfc1      $a2, $f0
/* D89C58 80240578 0C00B94E */  jal       get_screen_coords
/* D89C5C 8024057C 00000000 */   nop
/* D89C60 80240580 8E0500A4 */  lw        $a1, 0xa4($s0)
/* D89C64 80240584 3C063F80 */  lui       $a2, 0x3f80
/* D89C68 80240588 0C0B76A3 */  jal       func_802DDA8C
/* D89C6C 8024058C 24040001 */   addiu    $a0, $zero, 1
/* D89C70 80240590 8E020000 */  lw        $v0, ($s0)
/* D89C74 80240594 3C030002 */  lui       $v1, 2
/* D89C78 80240598 00431024 */  and       $v0, $v0, $v1
/* D89C7C 8024059C 54400022 */  bnel      $v0, $zero, .L80240628
/* D89C80 802405A0 24120011 */   addiu    $s2, $zero, 0x11
/* D89C84 802405A4 9203000E */  lbu       $v1, 0xe($s0)
/* D89C88 802405A8 3C02802E */  lui       $v0, %hi(D_802D9D71)
/* D89C8C 802405AC 90429D71 */  lbu       $v0, %lo(D_802D9D71)($v0)
/* D89C90 802405B0 10620018 */  beq       $v1, $v0, .L80240614
/* D89C94 802405B4 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D89C98 802405B8 1040000B */  beqz      $v0, .L802405E8
/* D89C9C 802405BC 24120011 */   addiu    $s2, $zero, 0x11
/* D89CA0 802405C0 24040001 */  addiu     $a0, $zero, 1
/* D89CA4 802405C4 2405FFFF */  addiu     $a1, $zero, -1
/* D89CA8 802405C8 24060007 */  addiu     $a2, $zero, 7
/* D89CAC 802405CC 0060102D */  daddu     $v0, $v1, $zero
/* D89CB0 802405D0 0000382D */  daddu     $a3, $zero, $zero
/* D89CB4 802405D4 AFA00010 */  sw        $zero, 0x10($sp)
/* D89CB8 802405D8 AFA00014 */  sw        $zero, 0x14($sp)
/* D89CBC 802405DC AFA0001C */  sw        $zero, 0x1c($sp)
/* D89CC0 802405E0 08090183 */  j         .L8024060C
/* D89CC4 802405E4 AFA20018 */   sw       $v0, 0x18($sp)
.L802405E8:
/* D89CC8 802405E8 2412000D */  addiu     $s2, $zero, 0xd
/* D89CCC 802405EC 24040001 */  addiu     $a0, $zero, 1
/* D89CD0 802405F0 2405FFFF */  addiu     $a1, $zero, -1
/* D89CD4 802405F4 0000302D */  daddu     $a2, $zero, $zero
/* D89CD8 802405F8 00C0382D */  daddu     $a3, $a2, $zero
/* D89CDC 802405FC AFA00010 */  sw        $zero, 0x10($sp)
/* D89CE0 80240600 AFA00014 */  sw        $zero, 0x14($sp)
/* D89CE4 80240604 AFA00018 */  sw        $zero, 0x18($sp)
/* D89CE8 80240608 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024060C:
/* D89CEC 8024060C 0C0B77B9 */  jal       func_802DDEE4
/* D89CF0 80240610 00000000 */   nop
.L80240614:
/* D89CF4 80240614 9202000E */  lbu       $v0, 0xe($s0)
/* D89CF8 80240618 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D89CFC 8024061C A0229D71 */  sb        $v0, %lo(D_802D9D71)($at)
/* D89D00 80240620 0809018C */  j         .L80240630
/* D89D04 80240624 00000000 */   nop
.L80240628:
/* D89D08 80240628 3C01802E */  lui       $at, %hi(D_802D9D71)
/* D89D0C 8024062C A0209D71 */  sb        $zero, %lo(D_802D9D71)($at)
.L80240630:
/* D89D10 80240630 8FA20038 */  lw        $v0, 0x38($sp)
/* D89D14 80240634 3C048024 */  lui       $a0, %hi(func_80240870_D89F50)
/* D89D18 80240638 24840870 */  addiu     $a0, $a0, %lo(func_80240870_D89F50)
/* D89D1C 8024063C AE320000 */  sw        $s2, ($s1)
/* D89D20 80240640 AE300008 */  sw        $s0, 8($s1)
/* D89D24 80240644 00021023 */  negu      $v0, $v0
/* D89D28 80240648 AE220004 */  sw        $v0, 4($s1)
/* D89D2C 8024064C 8E020000 */  lw        $v0, ($s0)
/* D89D30 80240650 3C030002 */  lui       $v1, 2
/* D89D34 80240654 00431024 */  and       $v0, $v0, $v1
/* D89D38 80240658 54400004 */  bnel      $v0, $zero, .L8024066C
/* D89D3C 8024065C AE24000C */   sw       $a0, 0xc($s1)
/* D89D40 80240660 3C048024 */  lui       $a0, %hi(func_8024068C_D89D6C)
/* D89D44 80240664 2484068C */  addiu     $a0, $a0, %lo(func_8024068C_D89D6C)
/* D89D48 80240668 AE24000C */  sw        $a0, 0xc($s1)
.L8024066C:
/* D89D4C 8024066C 0C047644 */  jal       queue_render_task
/* D89D50 80240670 0220202D */   daddu    $a0, $s1, $zero
.L80240674:
/* D89D54 80240674 8FBF004C */  lw        $ra, 0x4c($sp)
/* D89D58 80240678 8FB20048 */  lw        $s2, 0x48($sp)
/* D89D5C 8024067C 8FB10044 */  lw        $s1, 0x44($sp)
/* D89D60 80240680 8FB00040 */  lw        $s0, 0x40($sp)
/* D89D64 80240684 03E00008 */  jr        $ra
/* D89D68 80240688 27BD0050 */   addiu    $sp, $sp, 0x50
