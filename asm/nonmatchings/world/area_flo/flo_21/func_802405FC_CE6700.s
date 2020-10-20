.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405FC_CE6CFC
/* CE6CFC 802405FC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CE6D00 80240600 AFB20020 */  sw        $s2, 0x20($sp)
/* CE6D04 80240604 0080902D */  daddu     $s2, $a0, $zero
/* CE6D08 80240608 AFBF0024 */  sw        $ra, 0x24($sp)
/* CE6D0C 8024060C AFB1001C */  sw        $s1, 0x1c($sp)
/* CE6D10 80240610 AFB00018 */  sw        $s0, 0x18($sp)
/* CE6D14 80240614 10A00035 */  beqz      $a1, .L802406EC
/* CE6D18 80240618 8E51000C */   lw       $s1, 0xc($s2)
/* CE6D1C 8024061C 0C00AB39 */  jal       heap_malloc
/* CE6D20 80240620 24040058 */   addiu    $a0, $zero, 0x58
/* CE6D24 80240624 0040802D */  daddu     $s0, $v0, $zero
/* CE6D28 80240628 AE500084 */  sw        $s0, 0x84($s2)
/* CE6D2C 8024062C 8E250000 */  lw        $a1, ($s1)
/* CE6D30 80240630 26310004 */  addiu     $s1, $s1, 4
/* CE6D34 80240634 0C0B1EAF */  jal       get_variable
/* CE6D38 80240638 0240202D */   daddu    $a0, $s2, $zero
/* CE6D3C 8024063C AE020038 */  sw        $v0, 0x38($s0)
/* CE6D40 80240640 8E250000 */  lw        $a1, ($s1)
/* CE6D44 80240644 26310004 */  addiu     $s1, $s1, 4
/* CE6D48 80240648 0C0B210B */  jal       get_float_variable
/* CE6D4C 8024064C 0240202D */   daddu    $a0, $s2, $zero
/* CE6D50 80240650 E6000018 */  swc1      $f0, 0x18($s0)
/* CE6D54 80240654 8E250000 */  lw        $a1, ($s1)
/* CE6D58 80240658 26310004 */  addiu     $s1, $s1, 4
/* CE6D5C 8024065C 0C0B210B */  jal       get_float_variable
/* CE6D60 80240660 0240202D */   daddu    $a0, $s2, $zero
/* CE6D64 80240664 E6000024 */  swc1      $f0, 0x24($s0)
/* CE6D68 80240668 8E250000 */  lw        $a1, ($s1)
/* CE6D6C 8024066C 26310004 */  addiu     $s1, $s1, 4
/* CE6D70 80240670 0C0B210B */  jal       get_float_variable
/* CE6D74 80240674 0240202D */   daddu    $a0, $s2, $zero
/* CE6D78 80240678 E6000020 */  swc1      $f0, 0x20($s0)
/* CE6D7C 8024067C 8E250000 */  lw        $a1, ($s1)
/* CE6D80 80240680 0C0B210B */  jal       get_float_variable
/* CE6D84 80240684 0240202D */   daddu    $a0, $s2, $zero
/* CE6D88 80240688 3C013F80 */  lui       $at, 0x3f80
/* CE6D8C 8024068C 44811000 */  mtc1      $at, $f2
/* CE6D90 80240690 E6000028 */  swc1      $f0, 0x28($s0)
/* CE6D94 80240694 AFA00014 */  sw        $zero, 0x14($sp)
/* CE6D98 80240698 E7A20010 */  swc1      $f2, 0x10($sp)
/* CE6D9C 8024069C 8E050018 */  lw        $a1, 0x18($s0)
/* CE6DA0 802406A0 8E060024 */  lw        $a2, 0x24($s0)
/* CE6DA4 802406A4 8E070020 */  lw        $a3, 0x20($s0)
/* CE6DA8 802406A8 0C01C9AC */  jal       func_800726B0
/* CE6DAC 802406AC 24040001 */   addiu    $a0, $zero, 1
/* CE6DB0 802406B0 AE020054 */  sw        $v0, 0x54($s0)
/* CE6DB4 802406B4 8C43000C */  lw        $v1, 0xc($v0)
/* CE6DB8 802406B8 9202003B */  lbu       $v0, 0x3b($s0)
/* CE6DBC 802406BC A0620034 */  sb        $v0, 0x34($v1)
/* CE6DC0 802406C0 8E020054 */  lw        $v0, 0x54($s0)
/* CE6DC4 802406C4 8C42000C */  lw        $v0, 0xc($v0)
/* CE6DC8 802406C8 AC400020 */  sw        $zero, 0x20($v0)
/* CE6DCC 802406CC 8E050018 */  lw        $a1, 0x18($s0)
/* CE6DD0 802406D0 8E060028 */  lw        $a2, 0x28($s0)
/* CE6DD4 802406D4 8E070020 */  lw        $a3, 0x20($s0)
/* CE6DD8 802406D8 0C044898 */  jal       create_shadow_type
/* CE6DDC 802406DC 0000202D */   daddu    $a0, $zero, $zero
/* CE6DE0 802406E0 AE020040 */  sw        $v0, 0x40($s0)
/* CE6DE4 802406E4 2402010E */  addiu     $v0, $zero, 0x10e
/* CE6DE8 802406E8 A602004C */  sh        $v0, 0x4c($s0)
.L802406EC:
/* CE6DEC 802406EC 8FBF0024 */  lw        $ra, 0x24($sp)
/* CE6DF0 802406F0 8FB20020 */  lw        $s2, 0x20($sp)
/* CE6DF4 802406F4 8FB1001C */  lw        $s1, 0x1c($sp)
/* CE6DF8 802406F8 8FB00018 */  lw        $s0, 0x18($sp)
/* CE6DFC 802406FC 24020002 */  addiu     $v0, $zero, 2
/* CE6E00 80240700 03E00008 */  jr        $ra
/* CE6E04 80240704 27BD0028 */   addiu    $sp, $sp, 0x28
