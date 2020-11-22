.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241064_A9FDA4
/* A9FDA4 80241064 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A9FDA8 80241068 AFB3003C */  sw        $s3, 0x3c($sp)
/* A9FDAC 8024106C 0080982D */  daddu     $s3, $a0, $zero
/* A9FDB0 80241070 AFBF0048 */  sw        $ra, 0x48($sp)
/* A9FDB4 80241074 AFB50044 */  sw        $s5, 0x44($sp)
/* A9FDB8 80241078 AFB40040 */  sw        $s4, 0x40($sp)
/* A9FDBC 8024107C AFB20038 */  sw        $s2, 0x38($sp)
/* A9FDC0 80241080 AFB10034 */  sw        $s1, 0x34($sp)
/* A9FDC4 80241084 AFB00030 */  sw        $s0, 0x30($sp)
/* A9FDC8 80241088 8E720148 */  lw        $s2, 0x148($s3)
/* A9FDCC 8024108C 86440008 */  lh        $a0, 8($s2)
/* A9FDD0 80241090 8E70000C */  lw        $s0, 0xc($s3)
/* A9FDD4 80241094 0C00EABB */  jal       get_npc_unsafe
/* A9FDD8 80241098 00A0882D */   daddu    $s1, $a1, $zero
/* A9FDDC 8024109C 0260202D */  daddu     $a0, $s3, $zero
/* A9FDE0 802410A0 8E050000 */  lw        $a1, ($s0)
/* A9FDE4 802410A4 0C0B1EAF */  jal       get_variable
/* A9FDE8 802410A8 0040A02D */   daddu    $s4, $v0, $zero
/* A9FDEC 802410AC AFA00010 */  sw        $zero, 0x10($sp)
/* A9FDF0 802410B0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A9FDF4 802410B4 8C630030 */  lw        $v1, 0x30($v1)
/* A9FDF8 802410B8 AFA30014 */  sw        $v1, 0x14($sp)
/* A9FDFC 802410BC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A9FE00 802410C0 8C63001C */  lw        $v1, 0x1c($v1)
/* A9FE04 802410C4 AFA30018 */  sw        $v1, 0x18($sp)
/* A9FE08 802410C8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A9FE0C 802410CC 8C630024 */  lw        $v1, 0x24($v1)
/* A9FE10 802410D0 AFA3001C */  sw        $v1, 0x1c($sp)
/* A9FE14 802410D4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A9FE18 802410D8 8C630028 */  lw        $v1, 0x28($v1)
/* A9FE1C 802410DC 27B50010 */  addiu     $s5, $sp, 0x10
/* A9FE20 802410E0 AFA30020 */  sw        $v1, 0x20($sp)
/* A9FE24 802410E4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A9FE28 802410E8 3C014220 */  lui       $at, 0x4220
/* A9FE2C 802410EC 44810000 */  mtc1      $at, $f0
/* A9FE30 802410F0 8C63002C */  lw        $v1, 0x2c($v1)
/* A9FE34 802410F4 0040802D */  daddu     $s0, $v0, $zero
/* A9FE38 802410F8 E7A00028 */  swc1      $f0, 0x28($sp)
/* A9FE3C 802410FC A7A0002C */  sh        $zero, 0x2c($sp)
/* A9FE40 80241100 16200005 */  bnez      $s1, .L80241118
/* A9FE44 80241104 AFA30024 */   sw       $v1, 0x24($sp)
/* A9FE48 80241108 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A9FE4C 8024110C 30420004 */  andi      $v0, $v0, 4
/* A9FE50 80241110 1040002F */  beqz      $v0, .L802411D0
/* A9FE54 80241114 00000000 */   nop      
.L80241118:
/* A9FE58 80241118 2404F7FF */  addiu     $a0, $zero, -0x801
/* A9FE5C 8024111C AE600070 */  sw        $zero, 0x70($s3)
/* A9FE60 80241120 A680008E */  sh        $zero, 0x8e($s4)
/* A9FE64 80241124 8E4200CC */  lw        $v0, 0xcc($s2)
/* A9FE68 80241128 8E830000 */  lw        $v1, ($s4)
/* A9FE6C 8024112C 8C420000 */  lw        $v0, ($v0)
/* A9FE70 80241130 00641824 */  and       $v1, $v1, $a0
/* A9FE74 80241134 AE830000 */  sw        $v1, ($s4)
/* A9FE78 80241138 AE820028 */  sw        $v0, 0x28($s4)
/* A9FE7C 8024113C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* A9FE80 80241140 8C420034 */  lw        $v0, 0x34($v0)
/* A9FE84 80241144 54400005 */  bnel      $v0, $zero, .L8024115C
/* A9FE88 80241148 2402FDFF */   addiu    $v0, $zero, -0x201
/* A9FE8C 8024114C 34620200 */  ori       $v0, $v1, 0x200
/* A9FE90 80241150 2403FFF7 */  addiu     $v1, $zero, -9
/* A9FE94 80241154 08090459 */  j         .L80241164
/* A9FE98 80241158 00431024 */   and      $v0, $v0, $v1
.L8024115C:
/* A9FE9C 8024115C 00621024 */  and       $v0, $v1, $v0
/* A9FEA0 80241160 34420008 */  ori       $v0, $v0, 8
.L80241164:
/* A9FEA4 80241164 AE820000 */  sw        $v0, ($s4)
/* A9FEA8 80241168 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A9FEAC 8024116C 30420004 */  andi      $v0, $v0, 4
/* A9FEB0 80241170 10400008 */  beqz      $v0, .L80241194
/* A9FEB4 80241174 24020063 */   addiu    $v0, $zero, 0x63
/* A9FEB8 80241178 AE620070 */  sw        $v0, 0x70($s3)
/* A9FEBC 8024117C AE600074 */  sw        $zero, 0x74($s3)
/* A9FEC0 80241180 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A9FEC4 80241184 2403FFFB */  addiu     $v1, $zero, -5
/* A9FEC8 80241188 00431024 */  and       $v0, $v0, $v1
/* A9FECC 8024118C 0809046B */  j         .L802411AC
/* A9FED0 80241190 AE4200B0 */   sw       $v0, 0xb0($s2)
.L80241194:
/* A9FED4 80241194 8E420000 */  lw        $v0, ($s2)
/* A9FED8 80241198 3C034000 */  lui       $v1, 0x4000
/* A9FEDC 8024119C 00431024 */  and       $v0, $v0, $v1
/* A9FEE0 802411A0 10400002 */  beqz      $v0, .L802411AC
/* A9FEE4 802411A4 2402000C */   addiu    $v0, $zero, 0xc
/* A9FEE8 802411A8 AE620070 */  sw        $v0, 0x70($s3)
.L802411AC:
/* A9FEEC 802411AC 3C05BFFF */  lui       $a1, 0xbfff
/* A9FEF0 802411B0 34A5FFFF */  ori       $a1, $a1, 0xffff
/* A9FEF4 802411B4 2404FFFB */  addiu     $a0, $zero, -5
/* A9FEF8 802411B8 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A9FEFC 802411BC 8E430000 */  lw        $v1, ($s2)
/* A9FF00 802411C0 00441024 */  and       $v0, $v0, $a0
/* A9FF04 802411C4 00651824 */  and       $v1, $v1, $a1
/* A9FF08 802411C8 AE4200B0 */  sw        $v0, 0xb0($s2)
/* A9FF0C 802411CC AE430000 */  sw        $v1, ($s2)
.L802411D0:
/* A9FF10 802411D0 8E630070 */  lw        $v1, 0x70($s3)
/* A9FF14 802411D4 2C620064 */  sltiu     $v0, $v1, 0x64
/* A9FF18 802411D8 10400060 */  beqz      $v0, .L8024135C
/* A9FF1C 802411DC 00031080 */   sll      $v0, $v1, 2
/* A9FF20 802411E0 3C018024 */  lui       $at, 0x8024
/* A9FF24 802411E4 00220821 */  addu      $at, $at, $v0
/* A9FF28 802411E8 8C223008 */  lw        $v0, 0x3008($at)
/* A9FF2C 802411EC 00400008 */  jr        $v0
/* A9FF30 802411F0 00000000 */   nop      
/* A9FF34 802411F4 0260202D */  daddu     $a0, $s3, $zero
/* A9FF38 802411F8 0200282D */  daddu     $a1, $s0, $zero
/* A9FF3C 802411FC 0C012568 */  jal       func_800495A0
/* A9FF40 80241200 02A0302D */   daddu    $a2, $s5, $zero
/* A9FF44 80241204 0260202D */  daddu     $a0, $s3, $zero
/* A9FF48 80241208 0200282D */  daddu     $a1, $s0, $zero
/* A9FF4C 8024120C 0C0125AE */  jal       func_800496B8
/* A9FF50 80241210 02A0302D */   daddu    $a2, $s5, $zero
/* A9FF54 80241214 080904D7 */  j         .L8024135C
/* A9FF58 80241218 00000000 */   nop      
/* A9FF5C 8024121C 0260202D */  daddu     $a0, $s3, $zero
/* A9FF60 80241220 0200282D */  daddu     $a1, $s0, $zero
/* A9FF64 80241224 0C0126D1 */  jal       func_80049B44
/* A9FF68 80241228 02A0302D */   daddu    $a2, $s5, $zero
/* A9FF6C 8024122C 0260202D */  daddu     $a0, $s3, $zero
/* A9FF70 80241230 0200282D */  daddu     $a1, $s0, $zero
/* A9FF74 80241234 0C012701 */  jal       func_80049C04
/* A9FF78 80241238 02A0302D */   daddu    $a2, $s5, $zero
/* A9FF7C 8024123C 080904D7 */  j         .L8024135C
/* A9FF80 80241240 00000000 */   nop      
/* A9FF84 80241244 0260202D */  daddu     $a0, $s3, $zero
/* A9FF88 80241248 0200282D */  daddu     $a1, $s0, $zero
/* A9FF8C 8024124C 0C01278F */  jal       func_80049E3C
/* A9FF90 80241250 02A0302D */   daddu    $a2, $s5, $zero
/* A9FF94 80241254 0260202D */  daddu     $a0, $s3, $zero
/* A9FF98 80241258 0200282D */  daddu     $a1, $s0, $zero
/* A9FF9C 8024125C 0C0127B3 */  jal       func_80049ECC
/* A9FFA0 80241260 02A0302D */   daddu    $a2, $s5, $zero
/* A9FFA4 80241264 080904D7 */  j         .L8024135C
/* A9FFA8 80241268 00000000 */   nop      
/* A9FFAC 8024126C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A9FFB0 80241270 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A9FFB4 80241274 C68C0038 */  lwc1      $f12, 0x38($s4)
/* A9FFB8 80241278 C68E0040 */  lwc1      $f14, 0x40($s4)
/* A9FFBC 8024127C 8C460028 */  lw        $a2, 0x28($v0)
/* A9FFC0 80241280 0C00A7B5 */  jal       dist2D
/* A9FFC4 80241284 8C470030 */   lw       $a3, 0x30($v0)
/* A9FFC8 80241288 8E42006C */  lw        $v0, 0x6c($s2)
/* A9FFCC 8024128C 10400008 */  beqz      $v0, .L802412B0
/* A9FFD0 80241290 46000086 */   mov.s    $f2, $f0
/* A9FFD4 80241294 44820000 */  mtc1      $v0, $f0
/* A9FFD8 80241298 00000000 */  nop       
/* A9FFDC 8024129C 46800020 */  cvt.s.w   $f0, $f0
/* A9FFE0 802412A0 4602003C */  c.lt.s    $f0, $f2
/* A9FFE4 802412A4 00000000 */  nop       
/* A9FFE8 802412A8 4500000B */  bc1f      .L802412D8
/* A9FFEC 802412AC 0260202D */   daddu    $a0, $s3, $zero
.L802412B0:
/* A9FFF0 802412B0 0260202D */  daddu     $a0, $s3, $zero
/* A9FFF4 802412B4 8E050024 */  lw        $a1, 0x24($s0)
/* A9FFF8 802412B8 8E060028 */  lw        $a2, 0x28($s0)
/* A9FFFC 802412BC 0C0900D8 */  jal       func_80240360_A9F0A0
/* AA0000 802412C0 02A0382D */   daddu    $a3, $s5, $zero
/* AA0004 802412C4 8E630070 */  lw        $v1, 0x70($s3)
/* AA0008 802412C8 2402000C */  addiu     $v0, $zero, 0xc
/* AA000C 802412CC 14620023 */  bne       $v1, $v0, .L8024135C
/* AA0010 802412D0 00000000 */   nop      
/* AA0014 802412D4 0260202D */  daddu     $a0, $s3, $zero
.L802412D8:
/* AA0018 802412D8 0200282D */  daddu     $a1, $s0, $zero
/* AA001C 802412DC 0C0127DF */  jal       func_80049F7C
/* AA0020 802412E0 02A0302D */   daddu    $a2, $s5, $zero
/* AA0024 802412E4 0260202D */  daddu     $a0, $s3, $zero
/* AA0028 802412E8 0200282D */  daddu     $a1, $s0, $zero
/* AA002C 802412EC 0C012849 */  jal       func_8004A124
/* AA0030 802412F0 02A0302D */   daddu    $a2, $s5, $zero
/* AA0034 802412F4 080904D7 */  j         .L8024135C
/* AA0038 802412F8 00000000 */   nop      
/* AA003C 802412FC 0260202D */  daddu     $a0, $s3, $zero
/* AA0040 80241300 0200282D */  daddu     $a1, $s0, $zero
/* AA0044 80241304 0C0128FA */  jal       func_8004A3E8
/* AA0048 80241308 02A0302D */   daddu    $a2, $s5, $zero
/* AA004C 8024130C 080904D7 */  j         .L8024135C
/* AA0050 80241310 00000000 */   nop      
/* AA0054 80241314 0C090129 */  jal       func_802404A4_A9F1E4
/* AA0058 80241318 0260202D */   daddu    $a0, $s3, $zero
/* AA005C 8024131C 080904D7 */  j         .L8024135C
/* AA0060 80241320 00000000 */   nop      
/* AA0064 80241324 0C090169 */  jal       UnkSetDurationFunc
/* AA0068 80241328 0260202D */   daddu    $a0, $s3, $zero
/* AA006C 8024132C 080904D7 */  j         .L8024135C
/* AA0070 80241330 00000000 */   nop      
/* AA0074 80241334 0C09017A */  jal       func_802405E8_A9F328
/* AA0078 80241338 0260202D */   daddu    $a0, $s3, $zero
/* AA007C 8024133C 080904D7 */  j         .L8024135C
/* AA0080 80241340 00000000 */   nop      
/* AA0084 80241344 0C0901A2 */  jal       UnkDurationCheck
/* AA0088 80241348 0260202D */   daddu    $a0, $s3, $zero
/* AA008C 8024134C 080904D7 */  j         .L8024135C
/* AA0090 80241350 00000000 */   nop      
/* AA0094 80241354 0C0129CF */  jal       func_8004A73C
/* AA0098 80241358 0260202D */   daddu    $a0, $s3, $zero
.L8024135C:
/* AA009C 8024135C 8FBF0048 */  lw        $ra, 0x48($sp)
/* AA00A0 80241360 8FB50044 */  lw        $s5, 0x44($sp)
/* AA00A4 80241364 8FB40040 */  lw        $s4, 0x40($sp)
/* AA00A8 80241368 8FB3003C */  lw        $s3, 0x3c($sp)
/* AA00AC 8024136C 8FB20038 */  lw        $s2, 0x38($sp)
/* AA00B0 80241370 8FB10034 */  lw        $s1, 0x34($sp)
/* AA00B4 80241374 8FB00030 */  lw        $s0, 0x30($sp)
/* AA00B8 80241378 0000102D */  daddu     $v0, $zero, $zero
/* AA00BC 8024137C 03E00008 */  jr        $ra
/* AA00C0 80241380 27BD0050 */   addiu    $sp, $sp, 0x50
