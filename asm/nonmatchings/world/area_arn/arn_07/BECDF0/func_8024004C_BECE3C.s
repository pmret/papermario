.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024004C_BECE3C
/* BECE3C 8024004C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BECE40 80240050 AFB20020 */  sw        $s2, 0x20($sp)
/* BECE44 80240054 0080902D */  daddu     $s2, $a0, $zero
/* BECE48 80240058 AFBF0024 */  sw        $ra, 0x24($sp)
/* BECE4C 8024005C AFB1001C */  sw        $s1, 0x1c($sp)
/* BECE50 80240060 AFB00018 */  sw        $s0, 0x18($sp)
/* BECE54 80240064 10A0004A */  beqz      $a1, .L80240190
/* BECE58 80240068 8E51000C */   lw       $s1, 0xc($s2)
/* BECE5C 8024006C 0C00AB39 */  jal       heap_malloc
/* BECE60 80240070 24040058 */   addiu    $a0, $zero, 0x58
/* BECE64 80240074 0000202D */  daddu     $a0, $zero, $zero
/* BECE68 80240078 3C05FD05 */  lui       $a1, 0xfd05
/* BECE6C 8024007C 34A50F81 */  ori       $a1, $a1, 0xf81
/* BECE70 80240080 0040802D */  daddu     $s0, $v0, $zero
/* BECE74 80240084 0200302D */  daddu     $a2, $s0, $zero
/* BECE78 80240088 0C0B2026 */  jal       set_variable
/* BECE7C 8024008C AE500084 */   sw       $s0, 0x84($s2)
/* BECE80 80240090 8E250000 */  lw        $a1, ($s1)
/* BECE84 80240094 26310004 */  addiu     $s1, $s1, 4
/* BECE88 80240098 0C0B1EAF */  jal       get_variable
/* BECE8C 8024009C 0240202D */   daddu    $a0, $s2, $zero
/* BECE90 802400A0 AE020038 */  sw        $v0, 0x38($s0)
/* BECE94 802400A4 8E250000 */  lw        $a1, ($s1)
/* BECE98 802400A8 26310004 */  addiu     $s1, $s1, 4
/* BECE9C 802400AC 0C0B1EAF */  jal       get_variable
/* BECEA0 802400B0 0240202D */   daddu    $a0, $s2, $zero
/* BECEA4 802400B4 AE02003C */  sw        $v0, 0x3c($s0)
/* BECEA8 802400B8 8E250000 */  lw        $a1, ($s1)
/* BECEAC 802400BC 26310004 */  addiu     $s1, $s1, 4
/* BECEB0 802400C0 0C0B210B */  jal       get_float_variable
/* BECEB4 802400C4 0240202D */   daddu    $a0, $s2, $zero
/* BECEB8 802400C8 E600000C */  swc1      $f0, 0xc($s0)
/* BECEBC 802400CC 8E250000 */  lw        $a1, ($s1)
/* BECEC0 802400D0 26310004 */  addiu     $s1, $s1, 4
/* BECEC4 802400D4 0C0B210B */  jal       get_float_variable
/* BECEC8 802400D8 0240202D */   daddu    $a0, $s2, $zero
/* BECECC 802400DC E6000010 */  swc1      $f0, 0x10($s0)
/* BECED0 802400E0 8E250000 */  lw        $a1, ($s1)
/* BECED4 802400E4 26310004 */  addiu     $s1, $s1, 4
/* BECED8 802400E8 0C0B210B */  jal       get_float_variable
/* BECEDC 802400EC 0240202D */   daddu    $a0, $s2, $zero
/* BECEE0 802400F0 E6000014 */  swc1      $f0, 0x14($s0)
/* BECEE4 802400F4 8E250000 */  lw        $a1, ($s1)
/* BECEE8 802400F8 26310004 */  addiu     $s1, $s1, 4
/* BECEEC 802400FC 0C0B210B */  jal       get_float_variable
/* BECEF0 80240100 0240202D */   daddu    $a0, $s2, $zero
/* BECEF4 80240104 E6000018 */  swc1      $f0, 0x18($s0)
/* BECEF8 80240108 8E250000 */  lw        $a1, ($s1)
/* BECEFC 8024010C 26310004 */  addiu     $s1, $s1, 4
/* BECF00 80240110 0C0B210B */  jal       get_float_variable
/* BECF04 80240114 0240202D */   daddu    $a0, $s2, $zero
/* BECF08 80240118 E600001C */  swc1      $f0, 0x1c($s0)
/* BECF0C 8024011C 8E250000 */  lw        $a1, ($s1)
/* BECF10 80240120 26310004 */  addiu     $s1, $s1, 4
/* BECF14 80240124 0C0B210B */  jal       get_float_variable
/* BECF18 80240128 0240202D */   daddu    $a0, $s2, $zero
/* BECF1C 8024012C E6000020 */  swc1      $f0, 0x20($s0)
/* BECF20 80240130 8E250000 */  lw        $a1, ($s1)
/* BECF24 80240134 26310004 */  addiu     $s1, $s1, 4
/* BECF28 80240138 0C0B210B */  jal       get_float_variable
/* BECF2C 8024013C 0240202D */   daddu    $a0, $s2, $zero
/* BECF30 80240140 E6000024 */  swc1      $f0, 0x24($s0)
/* BECF34 80240144 8E250000 */  lw        $a1, ($s1)
/* BECF38 80240148 0C0B210B */  jal       get_float_variable
/* BECF3C 8024014C 0240202D */   daddu    $a0, $s2, $zero
/* BECF40 80240150 3C013F80 */  lui       $at, 0x3f80
/* BECF44 80240154 44811000 */  mtc1      $at, $f2
/* BECF48 80240158 E6000028 */  swc1      $f0, 0x28($s0)
/* BECF4C 8024015C AFA00014 */  sw        $zero, 0x14($sp)
/* BECF50 80240160 E7A20010 */  swc1      $f2, 0x10($sp)
/* BECF54 80240164 8E05000C */  lw        $a1, 0xc($s0)
/* BECF58 80240168 8E060010 */  lw        $a2, 0x10($s0)
/* BECF5C 8024016C 8E070014 */  lw        $a3, 0x14($s0)
/* BECF60 80240170 0C01CA6C */  jal       func_800729B0
/* BECF64 80240174 24040002 */   addiu    $a0, $zero, 2
/* BECF68 80240178 AE020050 */  sw        $v0, 0x50($s0)
/* BECF6C 8024017C A600004E */  sh        $zero, 0x4e($s0)
/* BECF70 80240180 A6000048 */  sh        $zero, 0x48($s0)
/* BECF74 80240184 A600004A */  sh        $zero, 0x4a($s0)
/* BECF78 80240188 A6000044 */  sh        $zero, 0x44($s0)
/* BECF7C 8024018C A6000046 */  sh        $zero, 0x46($s0)
.L80240190:
/* BECF80 80240190 8FBF0024 */  lw        $ra, 0x24($sp)
/* BECF84 80240194 8FB20020 */  lw        $s2, 0x20($sp)
/* BECF88 80240198 8FB1001C */  lw        $s1, 0x1c($sp)
/* BECF8C 8024019C 8FB00018 */  lw        $s0, 0x18($sp)
/* BECF90 802401A0 24020002 */  addiu     $v0, $zero, 2
/* BECF94 802401A4 03E00008 */  jr        $ra
/* BECF98 802401A8 27BD0028 */   addiu    $sp, $sp, 0x28
