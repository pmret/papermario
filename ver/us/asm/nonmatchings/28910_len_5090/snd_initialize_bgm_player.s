.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_initialize_bgm_player
/* 299D8 8004E5D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 299DC 8004E5DC AFB10014 */  sw        $s1, 0x14($sp)
/* 299E0 8004E5E0 0080882D */  daddu     $s1, $a0, $zero
/* 299E4 8004E5E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 299E8 8004E5E8 0000802D */  daddu     $s0, $zero, $zero
/* 299EC 8004E5EC 2408FFFF */  addiu     $t0, $zero, -1
/* 299F0 8004E5F0 3C057FFF */  lui       $a1, 0x7fff
/* 299F4 8004E5F4 24070040 */  addiu     $a3, $zero, 0x40
/* 299F8 8004E5F8 2406007F */  addiu     $a2, $zero, 0x7f
/* 299FC 8004E5FC 2404025C */  addiu     $a0, $zero, 0x25c
/* 29A00 8004E600 AFBF0018 */  sw        $ra, 0x18($sp)
.L8004E604:
/* 29A04 8004E604 02241021 */  addu      $v0, $s1, $a0
/* 29A08 8004E608 AC48000C */  sw        $t0, 0xc($v0)
/* 29A0C 8004E60C AC450018 */  sw        $a1, 0x18($v0)
/* 29A10 8004E610 A047004A */  sb        $a3, 0x4a($v0)
/* 29A14 8004E614 A040004B */  sb        $zero, 0x4b($v0)
/* 29A18 8004E618 A4400044 */  sh        $zero, 0x44($v0)
/* 29A1C 8004E61C A4400046 */  sh        $zero, 0x46($v0)
/* 29A20 8004E620 A0400048 */  sb        $zero, 0x48($v0)
/* 29A24 8004E624 A0460049 */  sb        $a2, 0x49($v0)
/* 29A28 8004E628 A040004C */  sb        $zero, 0x4c($v0)
/* 29A2C 8004E62C AC45002C */  sw        $a1, 0x2c($v0)
/* 29A30 8004E630 AC400004 */  sw        $zero, 4($v0)
/* 29A34 8004E634 AC400008 */  sw        $zero, 8($v0)
/* 29A38 8004E638 A440003E */  sh        $zero, 0x3e($v0)
/* 29A3C 8004E63C A4400038 */  sh        $zero, 0x38($v0)
/* 29A40 8004E640 A0400056 */  sb        $zero, 0x56($v0)
/* 29A44 8004E644 A440003A */  sh        $zero, 0x3a($v0)
/* 29A48 8004E648 A0400055 */  sb        $zero, 0x55($v0)
/* 29A4C 8004E64C AC40001C */  sw        $zero, 0x1c($v0)
/* 29A50 8004E650 AC400020 */  sw        $zero, 0x20($v0)
/* 29A54 8004E654 AC400024 */  sw        $zero, 0x24($v0)
/* 29A58 8004E658 AC400030 */  sw        $zero, 0x30($v0)
/* 29A5C 8004E65C A4400034 */  sh        $zero, 0x34($v0)
/* 29A60 8004E660 A4400036 */  sh        $zero, 0x36($v0)
/* 29A64 8004E664 A040004D */  sb        $zero, 0x4d($v0)
/* 29A68 8004E668 A040004E */  sb        $zero, 0x4e($v0)
/* 29A6C 8004E66C A040004F */  sb        $zero, 0x4f($v0)
/* 29A70 8004E670 A0400050 */  sb        $zero, 0x50($v0)
/* 29A74 8004E674 A0400051 */  sb        $zero, 0x51($v0)
/* 29A78 8004E678 A0400054 */  sb        $zero, 0x54($v0)
/* 29A7C 8004E67C A0400057 */  sb        $zero, 0x57($v0)
/* 29A80 8004E680 A0400058 */  sb        $zero, 0x58($v0)
/* 29A84 8004E684 A0400059 */  sb        $zero, 0x59($v0)
/* 29A88 8004E688 A040005A */  sb        $zero, 0x5a($v0)
/* 29A8C 8004E68C 92230235 */  lbu       $v1, 0x235($s1)
/* 29A90 8004E690 A043005B */  sb        $v1, 0x5b($v0)
/* 29A94 8004E694 A050005C */  sb        $s0, 0x5c($v0)
/* 29A98 8004E698 26100001 */  addiu     $s0, $s0, 1
/* 29A9C 8004E69C 2A020010 */  slti      $v0, $s0, 0x10
/* 29AA0 8004E6A0 1440FFD8 */  bnez      $v0, .L8004E604
/* 29AA4 8004E6A4 24840060 */   addiu    $a0, $a0, 0x60
/* 29AA8 8004E6A8 0000802D */  daddu     $s0, $zero, $zero
/* 29AAC 8004E6AC 2404FFFF */  addiu     $a0, $zero, -1
/* 29AB0 8004E6B0 3C014000 */  lui       $at, 0x4000
/* 29AB4 8004E6B4 44810000 */  mtc1      $at, $f0
/* 29AB8 8004E6B8 2403085C */  addiu     $v1, $zero, 0x85c
.L8004E6BC:
/* 29ABC 8004E6BC 02231021 */  addu      $v0, $s1, $v1
/* 29AC0 8004E6C0 26100001 */  addiu     $s0, $s0, 1
/* 29AC4 8004E6C4 AC440000 */  sw        $a0, ($v0)
/* 29AC8 8004E6C8 E4400004 */  swc1      $f0, 4($v0)
/* 29ACC 8004E6CC A4400014 */  sh        $zero, 0x14($v0)
/* 29AD0 8004E6D0 A0400016 */  sb        $zero, 0x16($v0)
/* 29AD4 8004E6D4 AC40000C */  sw        $zero, 0xc($v0)
/* 29AD8 8004E6D8 A0400012 */  sb        $zero, 0x12($v0)
/* 29ADC 8004E6DC 2A020018 */  slti      $v0, $s0, 0x18
/* 29AE0 8004E6E0 1440FFF6 */  bnez      $v0, .L8004E6BC
/* 29AE4 8004E6E4 24630018 */   addiu    $v1, $v1, 0x18
/* 29AE8 8004E6E8 0C014240 */  jal       func_80050900
/* 29AEC 8004E6EC 0220202D */   daddu    $a0, $s1, $zero
/* 29AF0 8004E6F0 0000802D */  daddu     $s0, $zero, $zero
/* 29AF4 8004E6F4 3C014300 */  lui       $at, 0x4300
/* 29AF8 8004E6F8 44810000 */  mtc1      $at, $f0
/* 29AFC 8004E6FC 3C013F80 */  lui       $at, 0x3f80
/* 29B00 8004E700 44811000 */  mtc1      $at, $f2
/* 29B04 8004E704 24023CF0 */  addiu     $v0, $zero, 0x3cf0
/* 29B08 8004E708 AE2200B0 */  sw        $v0, 0xb0($s1)
/* 29B0C 8004E70C 2402009C */  addiu     $v0, $zero, 0x9c
/* 29B10 8004E710 A6220208 */  sh        $v0, 0x208($s1)
/* 29B14 8004E714 24020080 */  addiu     $v0, $zero, 0x80
/* 29B18 8004E718 A222021E */  sb        $v0, 0x21e($s1)
/* 29B1C 8004E71C 3C027F00 */  lui       $v0, 0x7f00
/* 29B20 8004E720 AE2200C0 */  sw        $v0, 0xc0($s1)
/* 29B24 8004E724 24020001 */  addiu     $v0, $zero, 1
/* 29B28 8004E728 AE200020 */  sw        $zero, 0x20($s1)
/* 29B2C 8004E72C AE200074 */  sw        $zero, 0x74($s1)
/* 29B30 8004E730 AE2000B8 */  sw        $zero, 0xb8($s1)
/* 29B34 8004E734 A620020C */  sh        $zero, 0x20c($s1)
/* 29B38 8004E738 A620020E */  sh        $zero, 0x20e($s1)
/* 29B3C 8004E73C AE2000CC */  sw        $zero, 0xcc($s1)
/* 29B40 8004E740 AE2000C8 */  sw        $zero, 0xc8($s1)
/* 29B44 8004E744 AE2000C4 */  sw        $zero, 0xc4($s1)
/* 29B48 8004E748 AE20016C */  sw        $zero, 0x16c($s1)
/* 29B4C 8004E74C A2200170 */  sb        $zero, 0x170($s1)
/* 29B50 8004E750 A2200171 */  sb        $zero, 0x171($s1)
/* 29B54 8004E754 AE200164 */  sw        $zero, 0x164($s1)
/* 29B58 8004E758 AE200160 */  sw        $zero, 0x160($s1)
/* 29B5C 8004E75C AE20015C */  sw        $zero, 0x15c($s1)
/* 29B60 8004E760 AE200158 */  sw        $zero, 0x158($s1)
/* 29B64 8004E764 AE200168 */  sw        $zero, 0x168($s1)
/* 29B68 8004E768 A2200210 */  sb        $zero, 0x210($s1)
/* 29B6C 8004E76C A2200222 */  sb        $zero, 0x222($s1)
/* 29B70 8004E770 A2200223 */  sb        $zero, 0x223($s1)
/* 29B74 8004E774 AE200204 */  sw        $zero, 0x204($s1)
/* 29B78 8004E778 A2200232 */  sb        $zero, 0x232($s1)
/* 29B7C 8004E77C A2220233 */  sb        $v0, 0x233($s1)
/* 29B80 8004E780 A2200211 */  sb        $zero, 0x211($s1)
/* 29B84 8004E784 E62000D0 */  swc1      $f0, 0xd0($s1)
/* 29B88 8004E788 E62200D0 */  swc1      $f2, 0xd0($s1)
/* 29B8C 8004E78C 0220202D */  daddu     $a0, $s1, $zero
.L8004E790:
/* 29B90 8004E790 0C013A11 */  jal       func_8004E844
/* 29B94 8004E794 0200282D */   daddu    $a1, $s0, $zero
/* 29B98 8004E798 26100001 */  addiu     $s0, $s0, 1
/* 29B9C 8004E79C 2A020008 */  slti      $v0, $s0, 8
/* 29BA0 8004E7A0 1440FFFB */  bnez      $v0, .L8004E790
/* 29BA4 8004E7A4 0220202D */   daddu    $a0, $s1, $zero
/* 29BA8 8004E7A8 24100003 */  addiu     $s0, $zero, 3
/* 29BAC 8004E7AC 02301021 */  addu      $v0, $s1, $s0
.L8004E7B0:
/* 29BB0 8004E7B0 A0400224 */  sb        $zero, 0x224($v0)
/* 29BB4 8004E7B4 2610FFFF */  addiu     $s0, $s0, -1
/* 29BB8 8004E7B8 0601FFFD */  bgez      $s0, .L8004E7B0
/* 29BBC 8004E7BC 2442FFFF */   addiu    $v0, $v0, -1
/* 29BC0 8004E7C0 0000802D */  daddu     $s0, $zero, $zero
/* 29BC4 8004E7C4 0220182D */  daddu     $v1, $s1, $zero
/* 29BC8 8004E7C8 A2200220 */  sb        $zero, 0x220($s1)
/* 29BCC 8004E7CC AE200018 */  sw        $zero, 0x18($s1)
.L8004E7D0:
/* 29BD0 8004E7D0 8E220068 */  lw        $v0, 0x68($s1)
/* 29BD4 8004E7D4 26100001 */  addiu     $s0, $s0, 1
/* 29BD8 8004E7D8 AC6200D8 */  sw        $v0, 0xd8($v1)
/* 29BDC 8004E7DC 2A020020 */  slti      $v0, $s0, 0x20
/* 29BE0 8004E7E0 1440FFFB */  bnez      $v0, .L8004E7D0
/* 29BE4 8004E7E4 24630004 */   addiu    $v1, $v1, 4
/* 29BE8 8004E7E8 8E240068 */  lw        $a0, 0x68($s1)
/* 29BEC 8004E7EC 24050001 */  addiu     $a1, $zero, 1
/* 29BF0 8004E7F0 3C07F000 */  lui       $a3, 0xf000
/* 29BF4 8004E7F4 3C063000 */  lui       $a2, 0x3000
.L8004E7F8:
/* 29BF8 8004E7F8 8C830000 */  lw        $v1, ($a0)
/* 29BFC 8004E7FC 14600003 */  bnez      $v1, .L8004E80C
/* 29C00 8004E800 24840004 */   addiu    $a0, $a0, 4
/* 29C04 8004E804 08013A09 */  j         .L8004E824
/* 29C08 8004E808 0000282D */   daddu    $a1, $zero, $zero
.L8004E80C:
/* 29C0C 8004E80C 00671024 */  and       $v0, $v1, $a3
/* 29C10 8004E810 14460004 */  bne       $v0, $a2, .L8004E824
/* 29C14 8004E814 3062001F */   andi     $v0, $v1, 0x1f
/* 29C18 8004E818 00021080 */  sll       $v0, $v0, 2
/* 29C1C 8004E81C 02221021 */  addu      $v0, $s1, $v0
/* 29C20 8004E820 AC4400D8 */  sw        $a0, 0xd8($v0)
.L8004E824:
/* 29C24 8004E824 14A0FFF4 */  bnez      $a1, .L8004E7F8
/* 29C28 8004E828 24020002 */   addiu    $v0, $zero, 2
/* 29C2C 8004E82C A2220221 */  sb        $v0, 0x221($s1)
/* 29C30 8004E830 8FBF0018 */  lw        $ra, 0x18($sp)
/* 29C34 8004E834 8FB10014 */  lw        $s1, 0x14($sp)
/* 29C38 8004E838 8FB00010 */  lw        $s0, 0x10($sp)
/* 29C3C 8004E83C 03E00008 */  jr        $ra
/* 29C40 8004E840 27BD0020 */   addiu    $sp, $sp, 0x20
