.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024255C_BE5D0C
/* BE5D0C 8024255C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* BE5D10 80242560 AFB3003C */  sw        $s3, 0x3c($sp)
/* BE5D14 80242564 0080982D */  daddu     $s3, $a0, $zero
/* BE5D18 80242568 AFBF0044 */  sw        $ra, 0x44($sp)
/* BE5D1C 8024256C AFB40040 */  sw        $s4, 0x40($sp)
/* BE5D20 80242570 AFB20038 */  sw        $s2, 0x38($sp)
/* BE5D24 80242574 AFB10034 */  sw        $s1, 0x34($sp)
/* BE5D28 80242578 AFB00030 */  sw        $s0, 0x30($sp)
/* BE5D2C 8024257C 8E700148 */  lw        $s0, 0x148($s3)
/* BE5D30 80242580 00A0902D */  daddu     $s2, $a1, $zero
/* BE5D34 80242584 86040008 */  lh        $a0, 8($s0)
/* BE5D38 80242588 0C00EABB */  jal       get_npc_unsafe
/* BE5D3C 8024258C 00C0A02D */   daddu    $s4, $a2, $zero
/* BE5D40 80242590 8E630074 */  lw        $v1, 0x74($s3)
/* BE5D44 80242594 1C600032 */  bgtz      $v1, .L80242660
/* BE5D48 80242598 0040882D */   daddu    $s1, $v0, $zero
/* BE5D4C 8024259C 8E420014 */  lw        $v0, 0x14($s2)
/* BE5D50 802425A0 AE620074 */  sw        $v0, 0x74($s3)
/* BE5D54 802425A4 C640000C */  lwc1      $f0, 0xc($s2)
/* BE5D58 802425A8 3C018024 */  lui       $at, %hi(D_80244338)
/* BE5D5C 802425AC D4224338 */  ldc1      $f2, %lo(D_80244338)($at)
/* BE5D60 802425B0 46000021 */  cvt.d.s   $f0, $f0
/* BE5D64 802425B4 46220002 */  mul.d     $f0, $f0, $f2
/* BE5D68 802425B8 00000000 */  nop
/* BE5D6C 802425BC 0280202D */  daddu     $a0, $s4, $zero
/* BE5D70 802425C0 AFA00010 */  sw        $zero, 0x10($sp)
/* BE5D74 802425C4 8E470010 */  lw        $a3, 0x10($s2)
/* BE5D78 802425C8 46200020 */  cvt.s.d   $f0, $f0
/* BE5D7C 802425CC 44060000 */  mfc1      $a2, $f0
/* BE5D80 802425D0 0C01242D */  jal       func_800490B4
/* BE5D84 802425D4 0200282D */   daddu    $a1, $s0, $zero
/* BE5D88 802425D8 10400021 */  beqz      $v0, .L80242660
/* BE5D8C 802425DC 0000202D */   daddu    $a0, $zero, $zero
/* BE5D90 802425E0 0220282D */  daddu     $a1, $s1, $zero
/* BE5D94 802425E4 0000302D */  daddu     $a2, $zero, $zero
/* BE5D98 802425E8 8E0200CC */  lw        $v0, 0xcc($s0)
/* BE5D9C 802425EC 3C013F80 */  lui       $at, 0x3f80
/* BE5DA0 802425F0 44810000 */  mtc1      $at, $f0
/* BE5DA4 802425F4 3C014000 */  lui       $at, 0x4000
/* BE5DA8 802425F8 44811000 */  mtc1      $at, $f2
/* BE5DAC 802425FC 8C430024 */  lw        $v1, 0x24($v0)
/* BE5DB0 80242600 862200A8 */  lh        $v0, 0xa8($s1)
/* BE5DB4 80242604 3C01C1A0 */  lui       $at, 0xc1a0
/* BE5DB8 80242608 44812000 */  mtc1      $at, $f4
/* BE5DBC 8024260C 44823000 */  mtc1      $v0, $f6
/* BE5DC0 80242610 00000000 */  nop
/* BE5DC4 80242614 468031A0 */  cvt.s.w   $f6, $f6
/* BE5DC8 80242618 44073000 */  mfc1      $a3, $f6
/* BE5DCC 8024261C 2402000F */  addiu     $v0, $zero, 0xf
/* BE5DD0 80242620 AE230028 */  sw        $v1, 0x28($s1)
/* BE5DD4 80242624 AFA2001C */  sw        $v0, 0x1c($sp)
/* BE5DD8 80242628 27A20028 */  addiu     $v0, $sp, 0x28
/* BE5DDC 8024262C E7A00010 */  swc1      $f0, 0x10($sp)
/* BE5DE0 80242630 E7A20014 */  swc1      $f2, 0x14($sp)
/* BE5DE4 80242634 E7A40018 */  swc1      $f4, 0x18($sp)
/* BE5DE8 80242638 0C01BFA4 */  jal       fx_emote
/* BE5DEC 8024263C AFA20020 */   sw       $v0, 0x20($sp)
/* BE5DF0 80242640 0220202D */  daddu     $a0, $s1, $zero
/* BE5DF4 80242644 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BE5DF8 80242648 0C012530 */  jal       func_800494C0
/* BE5DFC 8024264C 3C060020 */   lui      $a2, 0x20
/* BE5E00 80242650 2402000C */  addiu     $v0, $zero, 0xc
/* BE5E04 80242654 A622008E */  sh        $v0, 0x8e($s1)
/* BE5E08 80242658 24020002 */  addiu     $v0, $zero, 2
/* BE5E0C 8024265C AE620070 */  sw        $v0, 0x70($s3)
.L80242660:
/* BE5E10 80242660 8E620074 */  lw        $v0, 0x74($s3)
/* BE5E14 80242664 2442FFFF */  addiu     $v0, $v0, -1
/* BE5E18 80242668 AE620074 */  sw        $v0, 0x74($s3)
/* BE5E1C 8024266C 8FBF0044 */  lw        $ra, 0x44($sp)
/* BE5E20 80242670 8FB40040 */  lw        $s4, 0x40($sp)
/* BE5E24 80242674 8FB3003C */  lw        $s3, 0x3c($sp)
/* BE5E28 80242678 8FB20038 */  lw        $s2, 0x38($sp)
/* BE5E2C 8024267C 8FB10034 */  lw        $s1, 0x34($sp)
/* BE5E30 80242680 8FB00030 */  lw        $s0, 0x30($sp)
/* BE5E34 80242684 03E00008 */  jr        $ra
/* BE5E38 80242688 27BD0048 */   addiu    $sp, $sp, 0x48
