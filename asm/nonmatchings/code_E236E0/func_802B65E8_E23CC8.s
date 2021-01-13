.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B65E8_E23CC8
/* E23CC8 802B65E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E23CCC 802B65EC AFB00018 */  sw        $s0, 0x18($sp)
/* E23CD0 802B65F0 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E23CD4 802B65F4 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E23CD8 802B65F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* E23CDC 802B65FC 8E030000 */  lw        $v1, ($s0)
/* E23CE0 802B6600 0461000B */  bgez      $v1, .L802B6630
/* E23CE4 802B6604 3C027FFF */   lui      $v0, 0x7fff
/* E23CE8 802B6608 3442FFFF */  ori       $v0, $v0, 0xffff
/* E23CEC 802B660C 00621024 */  and       $v0, $v1, $v0
/* E23CF0 802B6610 AE020000 */  sw        $v0, ($s0)
/* E23CF4 802B6614 30624000 */  andi      $v0, $v1, 0x4000
/* E23CF8 802B6618 14400003 */  bnez      $v0, .L802B6628
/* E23CFC 802B661C AE000060 */   sw       $zero, 0x60($s0)
/* E23D00 802B6620 C6000058 */  lwc1      $f0, 0x58($s0)
/* E23D04 802B6624 E6000054 */  swc1      $f0, 0x54($s0)
.L802B6628:
/* E23D08 802B6628 0C0AD954 */  jal       func_802B6550_E23C30
/* E23D0C 802B662C 00000000 */   nop
.L802B6630:
/* E23D10 802B6630 8E020000 */  lw        $v0, ($s0)
/* E23D14 802B6634 30424000 */  andi      $v0, $v0, 0x4000
/* E23D18 802B6638 10400004 */  beqz      $v0, .L802B664C
/* E23D1C 802B663C 24040008 */   addiu    $a0, $zero, 8
/* E23D20 802B6640 C60000A0 */  lwc1      $f0, 0xa0($s0)
/* E23D24 802B6644 080AD9C8 */  j         .L802B6720
/* E23D28 802B6648 E6000080 */   swc1     $f0, 0x80($s0)
.L802B664C:
/* E23D2C 802B664C 27A40010 */  addiu     $a0, $sp, 0x10
/* E23D30 802B6650 0C0388C1 */  jal       input_to_move_vector
/* E23D34 802B6654 27A50014 */   addiu    $a1, $sp, 0x14
/* E23D38 802B6658 0C039454 */  jal       func_800E5150
/* E23D3C 802B665C 00000000 */   nop
/* E23D40 802B6660 C7A20014 */  lwc1      $f2, 0x14($sp)
/* E23D44 802B6664 44800000 */  mtc1      $zero, $f0
/* E23D48 802B6668 00000000 */  nop
/* E23D4C 802B666C 46001032 */  c.eq.s    $f2, $f0
/* E23D50 802B6670 00000000 */  nop
/* E23D54 802B6674 45000005 */  bc1f      .L802B668C
/* E23D58 802B6678 00000000 */   nop
/* E23D5C 802B667C 0C039769 */  jal       set_action_state
/* E23D60 802B6680 0000202D */   daddu    $a0, $zero, $zero
/* E23D64 802B6684 080AD9CA */  j         .L802B6728
/* E23D68 802B6688 00000000 */   nop
.L802B668C:
/* E23D6C 802B668C C7A00010 */  lwc1      $f0, 0x10($sp)
/* E23D70 802B6690 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E23D74 802B6694 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E23D78 802B6698 E6000080 */  swc1      $f0, 0x80($s0)
/* E23D7C 802B669C 90420080 */  lbu       $v0, 0x80($v0)
/* E23D80 802B66A0 1440001F */  bnez      $v0, .L802B6720
/* E23D84 802B66A4 24040008 */   addiu    $a0, $zero, 8
/* E23D88 802B66A8 8E0200E8 */  lw        $v0, 0xe8($s0)
/* E23D8C 802B66AC 00420018 */  mult      $v0, $v0
/* E23D90 802B66B0 00001812 */  mflo      $v1
/* E23D94 802B66B4 8E0200EC */  lw        $v0, 0xec($s0)
/* E23D98 802B66B8 00000000 */  nop
/* E23D9C 802B66BC 00420018 */  mult      $v0, $v0
/* E23DA0 802B66C0 00001012 */  mflo      $v0
/* E23DA4 802B66C4 00621021 */  addu      $v0, $v1, $v0
/* E23DA8 802B66C8 44826000 */  mtc1      $v0, $f12
/* E23DAC 802B66CC 00000000 */  nop
/* E23DB0 802B66D0 46806320 */  cvt.s.w   $f12, $f12
/* E23DB4 802B66D4 46006084 */  sqrt.s    $f2, $f12
/* E23DB8 802B66D8 46021032 */  c.eq.s    $f2, $f2
/* E23DBC 802B66DC 00000000 */  nop
/* E23DC0 802B66E0 45010004 */  bc1t      .L802B66F4
/* E23DC4 802B66E4 00000000 */   nop
/* E23DC8 802B66E8 0C0187BC */  jal       sqrtf
/* E23DCC 802B66EC 00000000 */   nop
/* E23DD0 802B66F0 46000086 */  mov.s     $f2, $f0
.L802B66F4:
/* E23DD4 802B66F4 3C01425C */  lui       $at, 0x425c
/* E23DD8 802B66F8 44810000 */  mtc1      $at, $f0
/* E23DDC 802B66FC 00000000 */  nop
/* E23DE0 802B6700 4602003C */  c.lt.s    $f0, $f2
/* E23DE4 802B6704 00000000 */  nop
/* E23DE8 802B6708 45000005 */  bc1f      .L802B6720
/* E23DEC 802B670C 24040008 */   addiu    $a0, $zero, 8
/* E23DF0 802B6710 0C039769 */  jal       set_action_state
/* E23DF4 802B6714 24040002 */   addiu    $a0, $zero, 2
/* E23DF8 802B6718 080AD9CA */  j         .L802B6728
/* E23DFC 802B671C 00000000 */   nop
.L802B6720:
/* E23E00 802B6720 0C039426 */  jal       func_800E5098
/* E23E04 802B6724 00000000 */   nop
.L802B6728:
/* E23E08 802B6728 8FBF001C */  lw        $ra, 0x1c($sp)
/* E23E0C 802B672C 8FB00018 */  lw        $s0, 0x18($sp)
/* E23E10 802B6730 03E00008 */  jr        $ra
/* E23E14 802B6734 27BD0020 */   addiu    $sp, $sp, 0x20
