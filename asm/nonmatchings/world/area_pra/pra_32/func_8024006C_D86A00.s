.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024006C_D86A6C
/* D86A6C 8024006C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D86A70 80240070 AFB20020 */  sw        $s2, 0x20($sp)
/* D86A74 80240074 0080902D */  daddu     $s2, $a0, $zero
/* D86A78 80240078 AFBF0024 */  sw        $ra, 0x24($sp)
/* D86A7C 8024007C AFB1001C */  sw        $s1, 0x1c($sp)
/* D86A80 80240080 AFB00018 */  sw        $s0, 0x18($sp)
/* D86A84 80240084 10A0004A */  beqz      $a1, .L802401B0
/* D86A88 80240088 8E51000C */   lw       $s1, 0xc($s2)
/* D86A8C 8024008C 0C00AB39 */  jal       heap_malloc
/* D86A90 80240090 24040058 */   addiu    $a0, $zero, 0x58
/* D86A94 80240094 0000202D */  daddu     $a0, $zero, $zero
/* D86A98 80240098 3C05FD05 */  lui       $a1, 0xfd05
/* D86A9C 8024009C 34A50F81 */  ori       $a1, $a1, 0xf81
/* D86AA0 802400A0 0040802D */  daddu     $s0, $v0, $zero
/* D86AA4 802400A4 0200302D */  daddu     $a2, $s0, $zero
/* D86AA8 802400A8 0C0B2026 */  jal       set_variable
/* D86AAC 802400AC AE500084 */   sw       $s0, 0x84($s2)
/* D86AB0 802400B0 8E250000 */  lw        $a1, ($s1)
/* D86AB4 802400B4 26310004 */  addiu     $s1, $s1, 4
/* D86AB8 802400B8 0C0B1EAF */  jal       get_variable
/* D86ABC 802400BC 0240202D */   daddu    $a0, $s2, $zero
/* D86AC0 802400C0 AE020038 */  sw        $v0, 0x38($s0)
/* D86AC4 802400C4 8E250000 */  lw        $a1, ($s1)
/* D86AC8 802400C8 26310004 */  addiu     $s1, $s1, 4
/* D86ACC 802400CC 0C0B1EAF */  jal       get_variable
/* D86AD0 802400D0 0240202D */   daddu    $a0, $s2, $zero
/* D86AD4 802400D4 AE02003C */  sw        $v0, 0x3c($s0)
/* D86AD8 802400D8 8E250000 */  lw        $a1, ($s1)
/* D86ADC 802400DC 26310004 */  addiu     $s1, $s1, 4
/* D86AE0 802400E0 0C0B210B */  jal       get_float_variable
/* D86AE4 802400E4 0240202D */   daddu    $a0, $s2, $zero
/* D86AE8 802400E8 E600000C */  swc1      $f0, 0xc($s0)
/* D86AEC 802400EC 8E250000 */  lw        $a1, ($s1)
/* D86AF0 802400F0 26310004 */  addiu     $s1, $s1, 4
/* D86AF4 802400F4 0C0B210B */  jal       get_float_variable
/* D86AF8 802400F8 0240202D */   daddu    $a0, $s2, $zero
/* D86AFC 802400FC E6000010 */  swc1      $f0, 0x10($s0)
/* D86B00 80240100 8E250000 */  lw        $a1, ($s1)
/* D86B04 80240104 26310004 */  addiu     $s1, $s1, 4
/* D86B08 80240108 0C0B210B */  jal       get_float_variable
/* D86B0C 8024010C 0240202D */   daddu    $a0, $s2, $zero
/* D86B10 80240110 E6000014 */  swc1      $f0, 0x14($s0)
/* D86B14 80240114 8E250000 */  lw        $a1, ($s1)
/* D86B18 80240118 26310004 */  addiu     $s1, $s1, 4
/* D86B1C 8024011C 0C0B210B */  jal       get_float_variable
/* D86B20 80240120 0240202D */   daddu    $a0, $s2, $zero
/* D86B24 80240124 E6000018 */  swc1      $f0, 0x18($s0)
/* D86B28 80240128 8E250000 */  lw        $a1, ($s1)
/* D86B2C 8024012C 26310004 */  addiu     $s1, $s1, 4
/* D86B30 80240130 0C0B210B */  jal       get_float_variable
/* D86B34 80240134 0240202D */   daddu    $a0, $s2, $zero
/* D86B38 80240138 E600001C */  swc1      $f0, 0x1c($s0)
/* D86B3C 8024013C 8E250000 */  lw        $a1, ($s1)
/* D86B40 80240140 26310004 */  addiu     $s1, $s1, 4
/* D86B44 80240144 0C0B210B */  jal       get_float_variable
/* D86B48 80240148 0240202D */   daddu    $a0, $s2, $zero
/* D86B4C 8024014C E6000020 */  swc1      $f0, 0x20($s0)
/* D86B50 80240150 8E250000 */  lw        $a1, ($s1)
/* D86B54 80240154 26310004 */  addiu     $s1, $s1, 4
/* D86B58 80240158 0C0B210B */  jal       get_float_variable
/* D86B5C 8024015C 0240202D */   daddu    $a0, $s2, $zero
/* D86B60 80240160 E6000024 */  swc1      $f0, 0x24($s0)
/* D86B64 80240164 8E250000 */  lw        $a1, ($s1)
/* D86B68 80240168 0C0B210B */  jal       get_float_variable
/* D86B6C 8024016C 0240202D */   daddu    $a0, $s2, $zero
/* D86B70 80240170 3C013F80 */  lui       $at, 0x3f80
/* D86B74 80240174 44811000 */  mtc1      $at, $f2
/* D86B78 80240178 E6000028 */  swc1      $f0, 0x28($s0)
/* D86B7C 8024017C AFA00014 */  sw        $zero, 0x14($sp)
/* D86B80 80240180 E7A20010 */  swc1      $f2, 0x10($sp)
/* D86B84 80240184 8E05000C */  lw        $a1, 0xc($s0)
/* D86B88 80240188 8E060010 */  lw        $a2, 0x10($s0)
/* D86B8C 8024018C 8E070014 */  lw        $a3, 0x14($s0)
/* D86B90 80240190 0C01CA6C */  jal       func_800729B0
/* D86B94 80240194 24040002 */   addiu    $a0, $zero, 2
/* D86B98 80240198 AE020050 */  sw        $v0, 0x50($s0)
/* D86B9C 8024019C A600004E */  sh        $zero, 0x4e($s0)
/* D86BA0 802401A0 A6000048 */  sh        $zero, 0x48($s0)
/* D86BA4 802401A4 A600004A */  sh        $zero, 0x4a($s0)
/* D86BA8 802401A8 A6000044 */  sh        $zero, 0x44($s0)
/* D86BAC 802401AC A6000046 */  sh        $zero, 0x46($s0)
.L802401B0:
/* D86BB0 802401B0 8FBF0024 */  lw        $ra, 0x24($sp)
/* D86BB4 802401B4 8FB20020 */  lw        $s2, 0x20($sp)
/* D86BB8 802401B8 8FB1001C */  lw        $s1, 0x1c($sp)
/* D86BBC 802401BC 8FB00018 */  lw        $s0, 0x18($sp)
/* D86BC0 802401C0 24020002 */  addiu     $v0, $zero, 2
/* D86BC4 802401C4 03E00008 */  jr        $ra
/* D86BC8 802401C8 27BD0028 */   addiu    $sp, $sp, 0x28
