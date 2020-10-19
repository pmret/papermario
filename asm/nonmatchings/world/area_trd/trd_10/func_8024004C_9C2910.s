.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024004C_9C295C
/* 9C295C 8024004C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9C2960 80240050 AFB20020 */  sw        $s2, 0x20($sp)
/* 9C2964 80240054 0080902D */  daddu     $s2, $a0, $zero
/* 9C2968 80240058 AFBF0024 */  sw        $ra, 0x24($sp)
/* 9C296C 8024005C AFB1001C */  sw        $s1, 0x1c($sp)
/* 9C2970 80240060 AFB00018 */  sw        $s0, 0x18($sp)
/* 9C2974 80240064 10A0004A */  beqz      $a1, .L80240190
/* 9C2978 80240068 8E51000C */   lw       $s1, 0xc($s2)
/* 9C297C 8024006C 0C00AB39 */  jal       heap_malloc
/* 9C2980 80240070 24040058 */   addiu    $a0, $zero, 0x58
/* 9C2984 80240074 0000202D */  daddu     $a0, $zero, $zero
/* 9C2988 80240078 3C05FD05 */  lui       $a1, 0xfd05
/* 9C298C 8024007C 34A50F81 */  ori       $a1, $a1, 0xf81
/* 9C2990 80240080 0040802D */  daddu     $s0, $v0, $zero
/* 9C2994 80240084 0200302D */  daddu     $a2, $s0, $zero
/* 9C2998 80240088 0C0B2026 */  jal       set_variable
/* 9C299C 8024008C AE500084 */   sw       $s0, 0x84($s2)
/* 9C29A0 80240090 8E250000 */  lw        $a1, ($s1)
/* 9C29A4 80240094 26310004 */  addiu     $s1, $s1, 4
/* 9C29A8 80240098 0C0B1EAF */  jal       get_variable
/* 9C29AC 8024009C 0240202D */   daddu    $a0, $s2, $zero
/* 9C29B0 802400A0 AE020038 */  sw        $v0, 0x38($s0)
/* 9C29B4 802400A4 8E250000 */  lw        $a1, ($s1)
/* 9C29B8 802400A8 26310004 */  addiu     $s1, $s1, 4
/* 9C29BC 802400AC 0C0B1EAF */  jal       get_variable
/* 9C29C0 802400B0 0240202D */   daddu    $a0, $s2, $zero
/* 9C29C4 802400B4 AE02003C */  sw        $v0, 0x3c($s0)
/* 9C29C8 802400B8 8E250000 */  lw        $a1, ($s1)
/* 9C29CC 802400BC 26310004 */  addiu     $s1, $s1, 4
/* 9C29D0 802400C0 0C0B210B */  jal       get_float_variable
/* 9C29D4 802400C4 0240202D */   daddu    $a0, $s2, $zero
/* 9C29D8 802400C8 E600000C */  swc1      $f0, 0xc($s0)
/* 9C29DC 802400CC 8E250000 */  lw        $a1, ($s1)
/* 9C29E0 802400D0 26310004 */  addiu     $s1, $s1, 4
/* 9C29E4 802400D4 0C0B210B */  jal       get_float_variable
/* 9C29E8 802400D8 0240202D */   daddu    $a0, $s2, $zero
/* 9C29EC 802400DC E6000010 */  swc1      $f0, 0x10($s0)
/* 9C29F0 802400E0 8E250000 */  lw        $a1, ($s1)
/* 9C29F4 802400E4 26310004 */  addiu     $s1, $s1, 4
/* 9C29F8 802400E8 0C0B210B */  jal       get_float_variable
/* 9C29FC 802400EC 0240202D */   daddu    $a0, $s2, $zero
/* 9C2A00 802400F0 E6000014 */  swc1      $f0, 0x14($s0)
/* 9C2A04 802400F4 8E250000 */  lw        $a1, ($s1)
/* 9C2A08 802400F8 26310004 */  addiu     $s1, $s1, 4
/* 9C2A0C 802400FC 0C0B210B */  jal       get_float_variable
/* 9C2A10 80240100 0240202D */   daddu    $a0, $s2, $zero
/* 9C2A14 80240104 E6000018 */  swc1      $f0, 0x18($s0)
/* 9C2A18 80240108 8E250000 */  lw        $a1, ($s1)
/* 9C2A1C 8024010C 26310004 */  addiu     $s1, $s1, 4
/* 9C2A20 80240110 0C0B210B */  jal       get_float_variable
/* 9C2A24 80240114 0240202D */   daddu    $a0, $s2, $zero
/* 9C2A28 80240118 E600001C */  swc1      $f0, 0x1c($s0)
/* 9C2A2C 8024011C 8E250000 */  lw        $a1, ($s1)
/* 9C2A30 80240120 26310004 */  addiu     $s1, $s1, 4
/* 9C2A34 80240124 0C0B210B */  jal       get_float_variable
/* 9C2A38 80240128 0240202D */   daddu    $a0, $s2, $zero
/* 9C2A3C 8024012C E6000020 */  swc1      $f0, 0x20($s0)
/* 9C2A40 80240130 8E250000 */  lw        $a1, ($s1)
/* 9C2A44 80240134 26310004 */  addiu     $s1, $s1, 4
/* 9C2A48 80240138 0C0B210B */  jal       get_float_variable
/* 9C2A4C 8024013C 0240202D */   daddu    $a0, $s2, $zero
/* 9C2A50 80240140 E6000024 */  swc1      $f0, 0x24($s0)
/* 9C2A54 80240144 8E250000 */  lw        $a1, ($s1)
/* 9C2A58 80240148 0C0B210B */  jal       get_float_variable
/* 9C2A5C 8024014C 0240202D */   daddu    $a0, $s2, $zero
/* 9C2A60 80240150 3C013F80 */  lui       $at, 0x3f80
/* 9C2A64 80240154 44811000 */  mtc1      $at, $f2
/* 9C2A68 80240158 E6000028 */  swc1      $f0, 0x28($s0)
/* 9C2A6C 8024015C AFA00014 */  sw        $zero, 0x14($sp)
/* 9C2A70 80240160 E7A20010 */  swc1      $f2, 0x10($sp)
/* 9C2A74 80240164 8E05000C */  lw        $a1, 0xc($s0)
/* 9C2A78 80240168 8E060010 */  lw        $a2, 0x10($s0)
/* 9C2A7C 8024016C 8E070014 */  lw        $a3, 0x14($s0)
/* 9C2A80 80240170 0C01CA6C */  jal       func_800729B0
/* 9C2A84 80240174 24040002 */   addiu    $a0, $zero, 2
/* 9C2A88 80240178 AE020050 */  sw        $v0, 0x50($s0)
/* 9C2A8C 8024017C A600004E */  sh        $zero, 0x4e($s0)
/* 9C2A90 80240180 A6000048 */  sh        $zero, 0x48($s0)
/* 9C2A94 80240184 A600004A */  sh        $zero, 0x4a($s0)
/* 9C2A98 80240188 A6000044 */  sh        $zero, 0x44($s0)
/* 9C2A9C 8024018C A6000046 */  sh        $zero, 0x46($s0)
.L80240190:
/* 9C2AA0 80240190 8FBF0024 */  lw        $ra, 0x24($sp)
/* 9C2AA4 80240194 8FB20020 */  lw        $s2, 0x20($sp)
/* 9C2AA8 80240198 8FB1001C */  lw        $s1, 0x1c($sp)
/* 9C2AAC 8024019C 8FB00018 */  lw        $s0, 0x18($sp)
/* 9C2AB0 802401A0 24020002 */  addiu     $v0, $zero, 2
/* 9C2AB4 802401A4 03E00008 */  jr        $ra
/* 9C2AB8 802401A8 27BD0028 */   addiu    $sp, $sp, 0x28
