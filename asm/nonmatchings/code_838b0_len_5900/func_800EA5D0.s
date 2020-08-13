.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800EA5D0
/* 083A80 800EA5D0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 083A84 800EA5D4 3C028011 */  lui   $v0, 0x8011
/* 083A88 800EA5D8 8C42CFD8 */  lw    $v0, -0x3028($v0)
/* 083A8C 800EA5DC 3C038010 */  lui   $v1, 0x8010
/* 083A90 800EA5E0 2463803C */  addiu $v1, $v1, -0x7fc4
/* 083A94 800EA5E4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 083A98 800EA5E8 AFB00020 */  sw    $s0, 0x20($sp)
/* 083A9C 800EA5EC 00021180 */  sll   $v0, $v0, 6
/* 083AA0 800EA5F0 00431021 */  addu  $v0, $v0, $v1
/* 083AA4 800EA5F4 8C440000 */  lw    $a0, ($v0)
/* 083AA8 800EA5F8 8C450004 */  lw    $a1, 4($v0)
/* 083AAC 800EA5FC 8C460008 */  lw    $a2, 8($v0)
/* 083AB0 800EA600 3C108011 */  lui   $s0, 0x8011
/* 083AB4 800EA604 2610CFEC */  addiu $s0, $s0, -0x3014
/* 083AB8 800EA608 0C00A5CF */  jal   dma_copy
/* 083ABC 800EA60C AE020000 */   sw    $v0, ($s0)
/* 083AC0 800EA610 3C020400 */  lui   $v0, 0x400
/* 083AC4 800EA614 34420100 */  ori   $v0, $v0, 0x100
/* 083AC8 800EA618 AFA20010 */  sw    $v0, 0x10($sp)
/* 083ACC 800EA61C 8E020000 */  lw    $v0, ($s0)
/* 083AD0 800EA620 8C420024 */  lw    $v0, 0x24($v0)
/* 083AD4 800EA624 27A40010 */  addiu $a0, $sp, 0x10
/* 083AD8 800EA628 AFA00018 */  sw    $zero, 0x18($sp)
/* 083ADC 800EA62C AFA0001C */  sw    $zero, 0x1c($sp)
/* 083AE0 800EA630 0C00E211 */  jal   func_80038844
/* 083AE4 800EA634 AFA20014 */   sw    $v0, 0x14($sp)
/* 083AE8 800EA638 0040202D */  daddu $a0, $v0, $zero
/* 083AEC 800EA63C 3C018011 */  lui   $at, 0x8011
/* 083AF0 800EA640 AC24CFD0 */  sw    $a0, -0x3030($at)
/* 083AF4 800EA644 0C00E2B7 */  jal   get_npc_by_index
/* 083AF8 800EA648 00000000 */   nop   
/* 083AFC 800EA64C 3C048011 */  lui   $a0, 0x8011
/* 083B00 800EA650 2484C930 */  addiu $a0, $a0, -0x36d0
/* 083B04 800EA654 2403FFFC */  addiu $v1, $zero, -4
/* 083B08 800EA658 AC820000 */  sw    $v0, ($a0)
/* 083B0C 800EA65C A04300A4 */  sb    $v1, 0xa4($v0)
/* 083B10 800EA660 8C840000 */  lw    $a0, ($a0)
/* 083B14 800EA664 3C01C47A */  lui   $at, 0xc47a
/* 083B18 800EA668 44810000 */  mtc1  $at, $f0
/* 083B1C 800EA66C 2403000A */  addiu $v1, $zero, 0xa
/* 083B20 800EA670 A44300A6 */  sh    $v1, 0xa6($v0)
/* 083B24 800EA674 A44300A8 */  sh    $v1, 0xa8($v0)
/* 083B28 800EA678 AC800038 */  sw    $zero, 0x38($a0)
/* 083B2C 800EA67C E480003C */  swc1  $f0, 0x3c($a0)
/* 083B30 800EA680 AC800040 */  sw    $zero, 0x40($a0)
/* 083B34 800EA684 AC800054 */  sw    $zero, 0x54($a0)
/* 083B38 800EA688 AC800058 */  sw    $zero, 0x58($a0)
/* 083B3C 800EA68C AC80005C */  sw    $zero, 0x5c($a0)
/* 083B40 800EA690 8FBF0024 */  lw    $ra, 0x24($sp)
/* 083B44 800EA694 8FB00020 */  lw    $s0, 0x20($sp)
/* 083B48 800EA698 3C018011 */  lui   $at, 0x8011
/* 083B4C 800EA69C AC20C954 */  sw    $zero, -0x36ac($at)
/* 083B50 800EA6A0 03E00008 */  jr    $ra
/* 083B54 800EA6A4 27BD0028 */   addiu $sp, $sp, 0x28

