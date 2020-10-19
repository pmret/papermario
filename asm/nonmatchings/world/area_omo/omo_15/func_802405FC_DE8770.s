.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405FC_DE8D6C
/* DE8D6C 802405FC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DE8D70 80240600 AFB20020 */  sw        $s2, 0x20($sp)
/* DE8D74 80240604 0080902D */  daddu     $s2, $a0, $zero
/* DE8D78 80240608 AFBF0024 */  sw        $ra, 0x24($sp)
/* DE8D7C 8024060C AFB1001C */  sw        $s1, 0x1c($sp)
/* DE8D80 80240610 AFB00018 */  sw        $s0, 0x18($sp)
/* DE8D84 80240614 10A00035 */  beqz      $a1, .L802406EC
/* DE8D88 80240618 8E51000C */   lw       $s1, 0xc($s2)
/* DE8D8C 8024061C 0C00AB39 */  jal       heap_malloc
/* DE8D90 80240620 24040058 */   addiu    $a0, $zero, 0x58
/* DE8D94 80240624 0040802D */  daddu     $s0, $v0, $zero
/* DE8D98 80240628 AE500084 */  sw        $s0, 0x84($s2)
/* DE8D9C 8024062C 8E250000 */  lw        $a1, ($s1)
/* DE8DA0 80240630 26310004 */  addiu     $s1, $s1, 4
/* DE8DA4 80240634 0C0B1EAF */  jal       get_variable
/* DE8DA8 80240638 0240202D */   daddu    $a0, $s2, $zero
/* DE8DAC 8024063C AE020038 */  sw        $v0, 0x38($s0)
/* DE8DB0 80240640 8E250000 */  lw        $a1, ($s1)
/* DE8DB4 80240644 26310004 */  addiu     $s1, $s1, 4
/* DE8DB8 80240648 0C0B210B */  jal       get_float_variable
/* DE8DBC 8024064C 0240202D */   daddu    $a0, $s2, $zero
/* DE8DC0 80240650 E6000018 */  swc1      $f0, 0x18($s0)
/* DE8DC4 80240654 8E250000 */  lw        $a1, ($s1)
/* DE8DC8 80240658 26310004 */  addiu     $s1, $s1, 4
/* DE8DCC 8024065C 0C0B210B */  jal       get_float_variable
/* DE8DD0 80240660 0240202D */   daddu    $a0, $s2, $zero
/* DE8DD4 80240664 E6000024 */  swc1      $f0, 0x24($s0)
/* DE8DD8 80240668 8E250000 */  lw        $a1, ($s1)
/* DE8DDC 8024066C 26310004 */  addiu     $s1, $s1, 4
/* DE8DE0 80240670 0C0B210B */  jal       get_float_variable
/* DE8DE4 80240674 0240202D */   daddu    $a0, $s2, $zero
/* DE8DE8 80240678 E6000020 */  swc1      $f0, 0x20($s0)
/* DE8DEC 8024067C 8E250000 */  lw        $a1, ($s1)
/* DE8DF0 80240680 0C0B210B */  jal       get_float_variable
/* DE8DF4 80240684 0240202D */   daddu    $a0, $s2, $zero
/* DE8DF8 80240688 3C013F80 */  lui       $at, 0x3f80
/* DE8DFC 8024068C 44811000 */  mtc1      $at, $f2
/* DE8E00 80240690 E6000028 */  swc1      $f0, 0x28($s0)
/* DE8E04 80240694 AFA00014 */  sw        $zero, 0x14($sp)
/* DE8E08 80240698 E7A20010 */  swc1      $f2, 0x10($sp)
/* DE8E0C 8024069C 8E050018 */  lw        $a1, 0x18($s0)
/* DE8E10 802406A0 8E060024 */  lw        $a2, 0x24($s0)
/* DE8E14 802406A4 8E070020 */  lw        $a3, 0x20($s0)
/* DE8E18 802406A8 0C01C9AC */  jal       func_800726B0
/* DE8E1C 802406AC 24040001 */   addiu    $a0, $zero, 1
/* DE8E20 802406B0 AE020054 */  sw        $v0, 0x54($s0)
/* DE8E24 802406B4 8C43000C */  lw        $v1, 0xc($v0)
/* DE8E28 802406B8 9202003B */  lbu       $v0, 0x3b($s0)
/* DE8E2C 802406BC A0620034 */  sb        $v0, 0x34($v1)
/* DE8E30 802406C0 8E020054 */  lw        $v0, 0x54($s0)
/* DE8E34 802406C4 8C42000C */  lw        $v0, 0xc($v0)
/* DE8E38 802406C8 AC400020 */  sw        $zero, 0x20($v0)
/* DE8E3C 802406CC 8E050018 */  lw        $a1, 0x18($s0)
/* DE8E40 802406D0 8E060028 */  lw        $a2, 0x28($s0)
/* DE8E44 802406D4 8E070020 */  lw        $a3, 0x20($s0)
/* DE8E48 802406D8 0C044898 */  jal       create_shadow_type
/* DE8E4C 802406DC 0000202D */   daddu    $a0, $zero, $zero
/* DE8E50 802406E0 AE020040 */  sw        $v0, 0x40($s0)
/* DE8E54 802406E4 2402010E */  addiu     $v0, $zero, 0x10e
/* DE8E58 802406E8 A602004C */  sh        $v0, 0x4c($s0)
.L802406EC:
/* DE8E5C 802406EC 8FBF0024 */  lw        $ra, 0x24($sp)
/* DE8E60 802406F0 8FB20020 */  lw        $s2, 0x20($sp)
/* DE8E64 802406F4 8FB1001C */  lw        $s1, 0x1c($sp)
/* DE8E68 802406F8 8FB00018 */  lw        $s0, 0x18($sp)
/* DE8E6C 802406FC 24020002 */  addiu     $v0, $zero, 2
/* DE8E70 80240700 03E00008 */  jr        $ra
/* DE8E74 80240704 27BD0028 */   addiu    $sp, $sp, 0x28
