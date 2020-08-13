.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8004E5D8
/* 0299D8 8004E5D8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0299DC 8004E5DC AFB10014 */  sw    $s1, 0x14($sp)
/* 0299E0 8004E5E0 0080882D */  daddu $s1, $a0, $zero
/* 0299E4 8004E5E4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0299E8 8004E5E8 0000802D */  daddu $s0, $zero, $zero
/* 0299EC 8004E5EC 2408FFFF */  addiu $t0, $zero, -1
/* 0299F0 8004E5F0 3C057FFF */  lui   $a1, 0x7fff
/* 0299F4 8004E5F4 24070040 */  addiu $a3, $zero, 0x40
/* 0299F8 8004E5F8 2406007F */  addiu $a2, $zero, 0x7f
/* 0299FC 8004E5FC 2404025C */  addiu $a0, $zero, 0x25c
/* 029A00 8004E600 AFBF0018 */  sw    $ra, 0x18($sp)
.L8004E604:
/* 029A04 8004E604 02241021 */  addu  $v0, $s1, $a0
/* 029A08 8004E608 AC48000C */  sw    $t0, 0xc($v0)
/* 029A0C 8004E60C AC450018 */  sw    $a1, 0x18($v0)
/* 029A10 8004E610 A047004A */  sb    $a3, 0x4a($v0)
/* 029A14 8004E614 A040004B */  sb    $zero, 0x4b($v0)
/* 029A18 8004E618 A4400044 */  sh    $zero, 0x44($v0)
/* 029A1C 8004E61C A4400046 */  sh    $zero, 0x46($v0)
/* 029A20 8004E620 A0400048 */  sb    $zero, 0x48($v0)
/* 029A24 8004E624 A0460049 */  sb    $a2, 0x49($v0)
/* 029A28 8004E628 A040004C */  sb    $zero, 0x4c($v0)
/* 029A2C 8004E62C AC45002C */  sw    $a1, 0x2c($v0)
/* 029A30 8004E630 AC400004 */  sw    $zero, 4($v0)
/* 029A34 8004E634 AC400008 */  sw    $zero, 8($v0)
/* 029A38 8004E638 A440003E */  sh    $zero, 0x3e($v0)
/* 029A3C 8004E63C A4400038 */  sh    $zero, 0x38($v0)
/* 029A40 8004E640 A0400056 */  sb    $zero, 0x56($v0)
/* 029A44 8004E644 A440003A */  sh    $zero, 0x3a($v0)
/* 029A48 8004E648 A0400055 */  sb    $zero, 0x55($v0)
/* 029A4C 8004E64C AC40001C */  sw    $zero, 0x1c($v0)
/* 029A50 8004E650 AC400020 */  sw    $zero, 0x20($v0)
/* 029A54 8004E654 AC400024 */  sw    $zero, 0x24($v0)
/* 029A58 8004E658 AC400030 */  sw    $zero, 0x30($v0)
/* 029A5C 8004E65C A4400034 */  sh    $zero, 0x34($v0)
/* 029A60 8004E660 A4400036 */  sh    $zero, 0x36($v0)
/* 029A64 8004E664 A040004D */  sb    $zero, 0x4d($v0)
/* 029A68 8004E668 A040004E */  sb    $zero, 0x4e($v0)
/* 029A6C 8004E66C A040004F */  sb    $zero, 0x4f($v0)
/* 029A70 8004E670 A0400050 */  sb    $zero, 0x50($v0)
/* 029A74 8004E674 A0400051 */  sb    $zero, 0x51($v0)
/* 029A78 8004E678 A0400054 */  sb    $zero, 0x54($v0)
/* 029A7C 8004E67C A0400057 */  sb    $zero, 0x57($v0)
/* 029A80 8004E680 A0400058 */  sb    $zero, 0x58($v0)
/* 029A84 8004E684 A0400059 */  sb    $zero, 0x59($v0)
/* 029A88 8004E688 A040005A */  sb    $zero, 0x5a($v0)
/* 029A8C 8004E68C 92230235 */  lbu   $v1, 0x235($s1)
/* 029A90 8004E690 A043005B */  sb    $v1, 0x5b($v0)
/* 029A94 8004E694 A050005C */  sb    $s0, 0x5c($v0)
/* 029A98 8004E698 26100001 */  addiu $s0, $s0, 1
/* 029A9C 8004E69C 2A020010 */  slti  $v0, $s0, 0x10
/* 029AA0 8004E6A0 1440FFD8 */  bnez  $v0, .L8004E604
/* 029AA4 8004E6A4 24840060 */   addiu $a0, $a0, 0x60
/* 029AA8 8004E6A8 0000802D */  daddu $s0, $zero, $zero
/* 029AAC 8004E6AC 2404FFFF */  addiu $a0, $zero, -1
/* 029AB0 8004E6B0 3C014000 */  lui   $at, 0x4000
/* 029AB4 8004E6B4 44810000 */  mtc1  $at, $f0
/* 029AB8 8004E6B8 2403085C */  addiu $v1, $zero, 0x85c
.L8004E6BC:
/* 029ABC 8004E6BC 02231021 */  addu  $v0, $s1, $v1
/* 029AC0 8004E6C0 26100001 */  addiu $s0, $s0, 1
/* 029AC4 8004E6C4 AC440000 */  sw    $a0, ($v0)
/* 029AC8 8004E6C8 E4400004 */  swc1  $f0, 4($v0)
/* 029ACC 8004E6CC A4400014 */  sh    $zero, 0x14($v0)
/* 029AD0 8004E6D0 A0400016 */  sb    $zero, 0x16($v0)
/* 029AD4 8004E6D4 AC40000C */  sw    $zero, 0xc($v0)
/* 029AD8 8004E6D8 A0400012 */  sb    $zero, 0x12($v0)
/* 029ADC 8004E6DC 2A020018 */  slti  $v0, $s0, 0x18
/* 029AE0 8004E6E0 1440FFF6 */  bnez  $v0, .L8004E6BC
/* 029AE4 8004E6E4 24630018 */   addiu $v1, $v1, 0x18
/* 029AE8 8004E6E8 0C014240 */  jal   func_80050900
/* 029AEC 8004E6EC 0220202D */   daddu $a0, $s1, $zero
/* 029AF0 8004E6F0 0000802D */  daddu $s0, $zero, $zero
/* 029AF4 8004E6F4 3C014300 */  lui   $at, 0x4300
/* 029AF8 8004E6F8 44810000 */  mtc1  $at, $f0
/* 029AFC 8004E6FC 3C013F80 */  lui   $at, 0x3f80
/* 029B00 8004E700 44811000 */  mtc1  $at, $f2
/* 029B04 8004E704 24023CF0 */  addiu $v0, $zero, 0x3cf0
/* 029B08 8004E708 AE2200B0 */  sw    $v0, 0xb0($s1)
/* 029B0C 8004E70C 2402009C */  addiu $v0, $zero, 0x9c
/* 029B10 8004E710 A6220208 */  sh    $v0, 0x208($s1)
/* 029B14 8004E714 24020080 */  addiu $v0, $zero, 0x80
/* 029B18 8004E718 A222021E */  sb    $v0, 0x21e($s1)
/* 029B1C 8004E71C 3C027F00 */  lui   $v0, 0x7f00
/* 029B20 8004E720 AE2200C0 */  sw    $v0, 0xc0($s1)
/* 029B24 8004E724 24020001 */  addiu $v0, $zero, 1
/* 029B28 8004E728 AE200020 */  sw    $zero, 0x20($s1)
/* 029B2C 8004E72C AE200074 */  sw    $zero, 0x74($s1)
/* 029B30 8004E730 AE2000B8 */  sw    $zero, 0xb8($s1)
/* 029B34 8004E734 A620020C */  sh    $zero, 0x20c($s1)
/* 029B38 8004E738 A620020E */  sh    $zero, 0x20e($s1)
/* 029B3C 8004E73C AE2000CC */  sw    $zero, 0xcc($s1)
/* 029B40 8004E740 AE2000C8 */  sw    $zero, 0xc8($s1)
/* 029B44 8004E744 AE2000C4 */  sw    $zero, 0xc4($s1)
/* 029B48 8004E748 AE20016C */  sw    $zero, 0x16c($s1)
/* 029B4C 8004E74C A2200170 */  sb    $zero, 0x170($s1)
/* 029B50 8004E750 A2200171 */  sb    $zero, 0x171($s1)
/* 029B54 8004E754 AE200164 */  sw    $zero, 0x164($s1)
/* 029B58 8004E758 AE200160 */  sw    $zero, 0x160($s1)
/* 029B5C 8004E75C AE20015C */  sw    $zero, 0x15c($s1)
/* 029B60 8004E760 AE200158 */  sw    $zero, 0x158($s1)
/* 029B64 8004E764 AE200168 */  sw    $zero, 0x168($s1)
/* 029B68 8004E768 A2200210 */  sb    $zero, 0x210($s1)
/* 029B6C 8004E76C A2200222 */  sb    $zero, 0x222($s1)
/* 029B70 8004E770 A2200223 */  sb    $zero, 0x223($s1)
/* 029B74 8004E774 AE200204 */  sw    $zero, 0x204($s1)
/* 029B78 8004E778 A2200232 */  sb    $zero, 0x232($s1)
/* 029B7C 8004E77C A2220233 */  sb    $v0, 0x233($s1)
/* 029B80 8004E780 A2200211 */  sb    $zero, 0x211($s1)
/* 029B84 8004E784 E62000D0 */  swc1  $f0, 0xd0($s1)
/* 029B88 8004E788 E62200D0 */  swc1  $f2, 0xd0($s1)
/* 029B8C 8004E78C 0220202D */  daddu $a0, $s1, $zero
.L8004E790:
/* 029B90 8004E790 0C013A11 */  jal   func_8004E844
/* 029B94 8004E794 0200282D */   daddu $a1, $s0, $zero
/* 029B98 8004E798 26100001 */  addiu $s0, $s0, 1
/* 029B9C 8004E79C 2A020008 */  slti  $v0, $s0, 8
/* 029BA0 8004E7A0 1440FFFB */  bnez  $v0, .L8004E790
/* 029BA4 8004E7A4 0220202D */   daddu $a0, $s1, $zero
/* 029BA8 8004E7A8 24100003 */  addiu $s0, $zero, 3
/* 029BAC 8004E7AC 02301021 */  addu  $v0, $s1, $s0
.L8004E7B0:
/* 029BB0 8004E7B0 A0400224 */  sb    $zero, 0x224($v0)
/* 029BB4 8004E7B4 2610FFFF */  addiu $s0, $s0, -1
/* 029BB8 8004E7B8 0601FFFD */  bgez  $s0, .L8004E7B0
/* 029BBC 8004E7BC 2442FFFF */   addiu $v0, $v0, -1
/* 029BC0 8004E7C0 0000802D */  daddu $s0, $zero, $zero
/* 029BC4 8004E7C4 0220182D */  daddu $v1, $s1, $zero
/* 029BC8 8004E7C8 A2200220 */  sb    $zero, 0x220($s1)
/* 029BCC 8004E7CC AE200018 */  sw    $zero, 0x18($s1)
.L8004E7D0:
/* 029BD0 8004E7D0 8E220068 */  lw    $v0, 0x68($s1)
/* 029BD4 8004E7D4 26100001 */  addiu $s0, $s0, 1
/* 029BD8 8004E7D8 AC6200D8 */  sw    $v0, 0xd8($v1)
/* 029BDC 8004E7DC 2A020020 */  slti  $v0, $s0, 0x20
/* 029BE0 8004E7E0 1440FFFB */  bnez  $v0, .L8004E7D0
/* 029BE4 8004E7E4 24630004 */   addiu $v1, $v1, 4
/* 029BE8 8004E7E8 8E240068 */  lw    $a0, 0x68($s1)
/* 029BEC 8004E7EC 24050001 */  addiu $a1, $zero, 1
/* 029BF0 8004E7F0 3C07F000 */  lui   $a3, 0xf000
/* 029BF4 8004E7F4 3C063000 */  lui   $a2, 0x3000
.L8004E7F8:
/* 029BF8 8004E7F8 8C830000 */  lw    $v1, ($a0)
/* 029BFC 8004E7FC 14600003 */  bnez  $v1, .L8004E80C
/* 029C00 8004E800 24840004 */   addiu $a0, $a0, 4
/* 029C04 8004E804 08013A09 */  j     .L8004E824
/* 029C08 8004E808 0000282D */   daddu $a1, $zero, $zero

.L8004E80C:
/* 029C0C 8004E80C 00671024 */  and   $v0, $v1, $a3
/* 029C10 8004E810 14460004 */  bne   $v0, $a2, .L8004E824
/* 029C14 8004E814 3062001F */   andi  $v0, $v1, 0x1f
/* 029C18 8004E818 00021080 */  sll   $v0, $v0, 2
/* 029C1C 8004E81C 02221021 */  addu  $v0, $s1, $v0
/* 029C20 8004E820 AC4400D8 */  sw    $a0, 0xd8($v0)
.L8004E824:
/* 029C24 8004E824 14A0FFF4 */  bnez  $a1, .L8004E7F8
/* 029C28 8004E828 24020002 */   addiu $v0, $zero, 2
/* 029C2C 8004E82C A2220221 */  sb    $v0, 0x221($s1)
/* 029C30 8004E830 8FBF0018 */  lw    $ra, 0x18($sp)
/* 029C34 8004E834 8FB10014 */  lw    $s1, 0x14($sp)
/* 029C38 8004E838 8FB00010 */  lw    $s0, 0x10($sp)
/* 029C3C 8004E83C 03E00008 */  jr    $ra
/* 029C40 8004E840 27BD0020 */   addiu $sp, $sp, 0x20

