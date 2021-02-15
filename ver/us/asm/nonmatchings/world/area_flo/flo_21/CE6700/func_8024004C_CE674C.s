.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024004C_CE674C
/* CE674C 8024004C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CE6750 80240050 AFB20020 */  sw        $s2, 0x20($sp)
/* CE6754 80240054 0080902D */  daddu     $s2, $a0, $zero
/* CE6758 80240058 AFBF0024 */  sw        $ra, 0x24($sp)
/* CE675C 8024005C AFB1001C */  sw        $s1, 0x1c($sp)
/* CE6760 80240060 AFB00018 */  sw        $s0, 0x18($sp)
/* CE6764 80240064 10A0004A */  beqz      $a1, .L80240190
/* CE6768 80240068 8E51000C */   lw       $s1, 0xc($s2)
/* CE676C 8024006C 0C00AB39 */  jal       heap_malloc
/* CE6770 80240070 24040058 */   addiu    $a0, $zero, 0x58
/* CE6774 80240074 0000202D */  daddu     $a0, $zero, $zero
/* CE6778 80240078 3C05FD05 */  lui       $a1, 0xfd05
/* CE677C 8024007C 34A50F81 */  ori       $a1, $a1, 0xf81
/* CE6780 80240080 0040802D */  daddu     $s0, $v0, $zero
/* CE6784 80240084 0200302D */  daddu     $a2, $s0, $zero
/* CE6788 80240088 0C0B2026 */  jal       set_variable
/* CE678C 8024008C AE500084 */   sw       $s0, 0x84($s2)
/* CE6790 80240090 8E250000 */  lw        $a1, ($s1)
/* CE6794 80240094 26310004 */  addiu     $s1, $s1, 4
/* CE6798 80240098 0C0B1EAF */  jal       get_variable
/* CE679C 8024009C 0240202D */   daddu    $a0, $s2, $zero
/* CE67A0 802400A0 AE020038 */  sw        $v0, 0x38($s0)
/* CE67A4 802400A4 8E250000 */  lw        $a1, ($s1)
/* CE67A8 802400A8 26310004 */  addiu     $s1, $s1, 4
/* CE67AC 802400AC 0C0B1EAF */  jal       get_variable
/* CE67B0 802400B0 0240202D */   daddu    $a0, $s2, $zero
/* CE67B4 802400B4 AE02003C */  sw        $v0, 0x3c($s0)
/* CE67B8 802400B8 8E250000 */  lw        $a1, ($s1)
/* CE67BC 802400BC 26310004 */  addiu     $s1, $s1, 4
/* CE67C0 802400C0 0C0B210B */  jal       get_float_variable
/* CE67C4 802400C4 0240202D */   daddu    $a0, $s2, $zero
/* CE67C8 802400C8 E600000C */  swc1      $f0, 0xc($s0)
/* CE67CC 802400CC 8E250000 */  lw        $a1, ($s1)
/* CE67D0 802400D0 26310004 */  addiu     $s1, $s1, 4
/* CE67D4 802400D4 0C0B210B */  jal       get_float_variable
/* CE67D8 802400D8 0240202D */   daddu    $a0, $s2, $zero
/* CE67DC 802400DC E6000010 */  swc1      $f0, 0x10($s0)
/* CE67E0 802400E0 8E250000 */  lw        $a1, ($s1)
/* CE67E4 802400E4 26310004 */  addiu     $s1, $s1, 4
/* CE67E8 802400E8 0C0B210B */  jal       get_float_variable
/* CE67EC 802400EC 0240202D */   daddu    $a0, $s2, $zero
/* CE67F0 802400F0 E6000014 */  swc1      $f0, 0x14($s0)
/* CE67F4 802400F4 8E250000 */  lw        $a1, ($s1)
/* CE67F8 802400F8 26310004 */  addiu     $s1, $s1, 4
/* CE67FC 802400FC 0C0B210B */  jal       get_float_variable
/* CE6800 80240100 0240202D */   daddu    $a0, $s2, $zero
/* CE6804 80240104 E6000018 */  swc1      $f0, 0x18($s0)
/* CE6808 80240108 8E250000 */  lw        $a1, ($s1)
/* CE680C 8024010C 26310004 */  addiu     $s1, $s1, 4
/* CE6810 80240110 0C0B210B */  jal       get_float_variable
/* CE6814 80240114 0240202D */   daddu    $a0, $s2, $zero
/* CE6818 80240118 E600001C */  swc1      $f0, 0x1c($s0)
/* CE681C 8024011C 8E250000 */  lw        $a1, ($s1)
/* CE6820 80240120 26310004 */  addiu     $s1, $s1, 4
/* CE6824 80240124 0C0B210B */  jal       get_float_variable
/* CE6828 80240128 0240202D */   daddu    $a0, $s2, $zero
/* CE682C 8024012C E6000020 */  swc1      $f0, 0x20($s0)
/* CE6830 80240130 8E250000 */  lw        $a1, ($s1)
/* CE6834 80240134 26310004 */  addiu     $s1, $s1, 4
/* CE6838 80240138 0C0B210B */  jal       get_float_variable
/* CE683C 8024013C 0240202D */   daddu    $a0, $s2, $zero
/* CE6840 80240140 E6000024 */  swc1      $f0, 0x24($s0)
/* CE6844 80240144 8E250000 */  lw        $a1, ($s1)
/* CE6848 80240148 0C0B210B */  jal       get_float_variable
/* CE684C 8024014C 0240202D */   daddu    $a0, $s2, $zero
/* CE6850 80240150 3C013F80 */  lui       $at, 0x3f80
/* CE6854 80240154 44811000 */  mtc1      $at, $f2
/* CE6858 80240158 E6000028 */  swc1      $f0, 0x28($s0)
/* CE685C 8024015C AFA00014 */  sw        $zero, 0x14($sp)
/* CE6860 80240160 E7A20010 */  swc1      $f2, 0x10($sp)
/* CE6864 80240164 8E05000C */  lw        $a1, 0xc($s0)
/* CE6868 80240168 8E060010 */  lw        $a2, 0x10($s0)
/* CE686C 8024016C 8E070014 */  lw        $a3, 0x14($s0)
/* CE6870 80240170 0C01CA6C */  jal       func_800729B0
/* CE6874 80240174 24040002 */   addiu    $a0, $zero, 2
/* CE6878 80240178 AE020050 */  sw        $v0, 0x50($s0)
/* CE687C 8024017C A600004E */  sh        $zero, 0x4e($s0)
/* CE6880 80240180 A6000048 */  sh        $zero, 0x48($s0)
/* CE6884 80240184 A600004A */  sh        $zero, 0x4a($s0)
/* CE6888 80240188 A6000044 */  sh        $zero, 0x44($s0)
/* CE688C 8024018C A6000046 */  sh        $zero, 0x46($s0)
.L80240190:
/* CE6890 80240190 8FBF0024 */  lw        $ra, 0x24($sp)
/* CE6894 80240194 8FB20020 */  lw        $s2, 0x20($sp)
/* CE6898 80240198 8FB1001C */  lw        $s1, 0x1c($sp)
/* CE689C 8024019C 8FB00018 */  lw        $s0, 0x18($sp)
/* CE68A0 802401A0 24020002 */  addiu     $v0, $zero, 2
/* CE68A4 802401A4 03E00008 */  jr        $ra
/* CE68A8 802401A8 27BD0028 */   addiu    $sp, $sp, 0x28
