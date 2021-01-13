.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C78_99D608
/* 99D608 80240C78 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 99D60C 80240C7C AFB40040 */  sw        $s4, 0x40($sp)
/* 99D610 80240C80 0080A02D */  daddu     $s4, $a0, $zero
/* 99D614 80240C84 AFBF0044 */  sw        $ra, 0x44($sp)
/* 99D618 80240C88 AFB3003C */  sw        $s3, 0x3c($sp)
/* 99D61C 80240C8C AFB20038 */  sw        $s2, 0x38($sp)
/* 99D620 80240C90 AFB10034 */  sw        $s1, 0x34($sp)
/* 99D624 80240C94 AFB00030 */  sw        $s0, 0x30($sp)
/* 99D628 80240C98 8E920148 */  lw        $s2, 0x148($s4)
/* 99D62C 80240C9C 00A0802D */  daddu     $s0, $a1, $zero
/* 99D630 80240CA0 86440008 */  lh        $a0, 8($s2)
/* 99D634 80240CA4 0C00EABB */  jal       get_npc_unsafe
/* 99D638 80240CA8 00C0982D */   daddu    $s3, $a2, $zero
/* 99D63C 80240CAC 8E030008 */  lw        $v1, 8($s0)
/* 99D640 80240CB0 04600031 */  bltz      $v1, .L80240D78
/* 99D644 80240CB4 0040882D */   daddu    $s1, $v0, $zero
/* 99D648 80240CB8 0260202D */  daddu     $a0, $s3, $zero
/* 99D64C 80240CBC AFA00010 */  sw        $zero, 0x10($sp)
/* 99D650 80240CC0 8E060018 */  lw        $a2, 0x18($s0)
/* 99D654 80240CC4 8E07001C */  lw        $a3, 0x1c($s0)
/* 99D658 80240CC8 0C01242D */  jal       func_800490B4
/* 99D65C 80240CCC 0240282D */   daddu    $a1, $s2, $zero
/* 99D660 80240CD0 10400029 */  beqz      $v0, .L80240D78
/* 99D664 80240CD4 0000202D */   daddu    $a0, $zero, $zero
/* 99D668 80240CD8 0220282D */  daddu     $a1, $s1, $zero
/* 99D66C 80240CDC 0000302D */  daddu     $a2, $zero, $zero
/* 99D670 80240CE0 862300A8 */  lh        $v1, 0xa8($s1)
/* 99D674 80240CE4 3C013F80 */  lui       $at, 0x3f80
/* 99D678 80240CE8 44810000 */  mtc1      $at, $f0
/* 99D67C 80240CEC 3C014000 */  lui       $at, 0x4000
/* 99D680 80240CF0 44811000 */  mtc1      $at, $f2
/* 99D684 80240CF4 3C01C1A0 */  lui       $at, 0xc1a0
/* 99D688 80240CF8 44812000 */  mtc1      $at, $f4
/* 99D68C 80240CFC 2402000F */  addiu     $v0, $zero, 0xf
/* 99D690 80240D00 AFA2001C */  sw        $v0, 0x1c($sp)
/* 99D694 80240D04 44833000 */  mtc1      $v1, $f6
/* 99D698 80240D08 00000000 */  nop
/* 99D69C 80240D0C 468031A0 */  cvt.s.w   $f6, $f6
/* 99D6A0 80240D10 44073000 */  mfc1      $a3, $f6
/* 99D6A4 80240D14 27A20028 */  addiu     $v0, $sp, 0x28
/* 99D6A8 80240D18 AFA20020 */  sw        $v0, 0x20($sp)
/* 99D6AC 80240D1C E7A00010 */  swc1      $f0, 0x10($sp)
/* 99D6B0 80240D20 E7A20014 */  swc1      $f2, 0x14($sp)
/* 99D6B4 80240D24 0C01BFA4 */  jal       fx_emote
/* 99D6B8 80240D28 E7A40018 */   swc1     $f4, 0x18($sp)
/* 99D6BC 80240D2C 0220202D */  daddu     $a0, $s1, $zero
/* 99D6C0 80240D30 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 99D6C4 80240D34 0C012530 */  jal       func_800494C0
/* 99D6C8 80240D38 3C060020 */   lui      $a2, 0x20
/* 99D6CC 80240D3C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 99D6D0 80240D40 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 99D6D4 80240D44 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 99D6D8 80240D48 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 99D6DC 80240D4C 8C460028 */  lw        $a2, 0x28($v0)
/* 99D6E0 80240D50 0C00A720 */  jal       atan2
/* 99D6E4 80240D54 8C470030 */   lw       $a3, 0x30($v0)
/* 99D6E8 80240D58 E620000C */  swc1      $f0, 0xc($s1)
/* 99D6EC 80240D5C 8E420018 */  lw        $v0, 0x18($s2)
/* 99D6F0 80240D60 9442002A */  lhu       $v0, 0x2a($v0)
/* 99D6F4 80240D64 30420001 */  andi      $v0, $v0, 1
/* 99D6F8 80240D68 14400002 */  bnez      $v0, .L80240D74
/* 99D6FC 80240D6C 2402000A */   addiu    $v0, $zero, 0xa
/* 99D700 80240D70 2402000C */  addiu     $v0, $zero, 0xc
.L80240D74:
/* 99D704 80240D74 AE820070 */  sw        $v0, 0x70($s4)
.L80240D78:
/* 99D708 80240D78 8FBF0044 */  lw        $ra, 0x44($sp)
/* 99D70C 80240D7C 8FB40040 */  lw        $s4, 0x40($sp)
/* 99D710 80240D80 8FB3003C */  lw        $s3, 0x3c($sp)
/* 99D714 80240D84 8FB20038 */  lw        $s2, 0x38($sp)
/* 99D718 80240D88 8FB10034 */  lw        $s1, 0x34($sp)
/* 99D71C 80240D8C 8FB00030 */  lw        $s0, 0x30($sp)
/* 99D720 80240D90 03E00008 */  jr        $ra
/* 99D724 80240D94 27BD0048 */   addiu    $sp, $sp, 0x48
