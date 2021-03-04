.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410B0_B7B100
/* B7B100 802410B0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B7B104 802410B4 AFB3003C */  sw        $s3, 0x3c($sp)
/* B7B108 802410B8 0080982D */  daddu     $s3, $a0, $zero
/* B7B10C 802410BC AFBF0048 */  sw        $ra, 0x48($sp)
/* B7B110 802410C0 AFB50044 */  sw        $s5, 0x44($sp)
/* B7B114 802410C4 AFB40040 */  sw        $s4, 0x40($sp)
/* B7B118 802410C8 AFB20038 */  sw        $s2, 0x38($sp)
/* B7B11C 802410CC AFB10034 */  sw        $s1, 0x34($sp)
/* B7B120 802410D0 AFB00030 */  sw        $s0, 0x30($sp)
/* B7B124 802410D4 8E720148 */  lw        $s2, 0x148($s3)
/* B7B128 802410D8 86440008 */  lh        $a0, 8($s2)
/* B7B12C 802410DC 8E70000C */  lw        $s0, 0xc($s3)
/* B7B130 802410E0 0C00EABB */  jal       get_npc_unsafe
/* B7B134 802410E4 00A0882D */   daddu    $s1, $a1, $zero
/* B7B138 802410E8 8E050000 */  lw        $a1, ($s0)
/* B7B13C 802410EC 26100004 */  addiu     $s0, $s0, 4
/* B7B140 802410F0 0260202D */  daddu     $a0, $s3, $zero
/* B7B144 802410F4 0C0B1EAF */  jal       get_variable
/* B7B148 802410F8 0040A82D */   daddu    $s5, $v0, $zero
/* B7B14C 802410FC 0260202D */  daddu     $a0, $s3, $zero
/* B7B150 80241100 8E050000 */  lw        $a1, ($s0)
/* B7B154 80241104 0C0B1EAF */  jal       get_variable
/* B7B158 80241108 0040A02D */   daddu    $s4, $v0, $zero
/* B7B15C 8024110C AE420094 */  sw        $v0, 0x94($s2)
/* B7B160 80241110 AFA00010 */  sw        $zero, 0x10($sp)
/* B7B164 80241114 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B7B168 80241118 8C420030 */  lw        $v0, 0x30($v0)
/* B7B16C 8024111C AFA20014 */  sw        $v0, 0x14($sp)
/* B7B170 80241120 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B7B174 80241124 8C42001C */  lw        $v0, 0x1c($v0)
/* B7B178 80241128 AFA20018 */  sw        $v0, 0x18($sp)
/* B7B17C 8024112C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B7B180 80241130 8C420024 */  lw        $v0, 0x24($v0)
/* B7B184 80241134 AFA2001C */  sw        $v0, 0x1c($sp)
/* B7B188 80241138 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B7B18C 8024113C 8C420028 */  lw        $v0, 0x28($v0)
/* B7B190 80241140 AFA20020 */  sw        $v0, 0x20($sp)
/* B7B194 80241144 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B7B198 80241148 3C0142C8 */  lui       $at, 0x42c8
/* B7B19C 8024114C 44810000 */  mtc1      $at, $f0
/* B7B1A0 80241150 8C42002C */  lw        $v0, 0x2c($v0)
/* B7B1A4 80241154 27B00010 */  addiu     $s0, $sp, 0x10
/* B7B1A8 80241158 E7A00028 */  swc1      $f0, 0x28($sp)
/* B7B1AC 8024115C A7A0002C */  sh        $zero, 0x2c($sp)
/* B7B1B0 80241160 12200019 */  beqz      $s1, .L802411C8
/* B7B1B4 80241164 AFA20024 */   sw       $v0, 0x24($sp)
/* B7B1B8 80241168 AE600070 */  sw        $zero, 0x70($s3)
/* B7B1BC 8024116C A6A0008E */  sh        $zero, 0x8e($s5)
/* B7B1C0 80241170 AE600074 */  sw        $zero, 0x74($s3)
/* B7B1C4 80241174 8EA20000 */  lw        $v0, ($s5)
/* B7B1C8 80241178 2403F7FF */  addiu     $v1, $zero, -0x801
/* B7B1CC 8024117C 00431024 */  and       $v0, $v0, $v1
/* B7B1D0 80241180 2403FDFF */  addiu     $v1, $zero, -0x201
/* B7B1D4 80241184 00431024 */  and       $v0, $v0, $v1
/* B7B1D8 80241188 34420008 */  ori       $v0, $v0, 8
/* B7B1DC 8024118C AEA20000 */  sw        $v0, ($s5)
/* B7B1E0 80241190 8E4200B0 */  lw        $v0, 0xb0($s2)
/* B7B1E4 80241194 34420018 */  ori       $v0, $v0, 0x18
/* B7B1E8 80241198 AE4200B0 */  sw        $v0, 0xb0($s2)
/* B7B1EC 8024119C 8E420000 */  lw        $v0, ($s2)
/* B7B1F0 802411A0 3C034000 */  lui       $v1, 0x4000
/* B7B1F4 802411A4 00431024 */  and       $v0, $v0, $v1
/* B7B1F8 802411A8 10400007 */  beqz      $v0, .L802411C8
/* B7B1FC 802411AC 3C03BFFF */   lui      $v1, 0xbfff
/* B7B200 802411B0 2402000C */  addiu     $v0, $zero, 0xc
/* B7B204 802411B4 AE620070 */  sw        $v0, 0x70($s3)
/* B7B208 802411B8 8E420000 */  lw        $v0, ($s2)
/* B7B20C 802411BC 3463FFFF */  ori       $v1, $v1, 0xffff
/* B7B210 802411C0 00431024 */  and       $v0, $v0, $v1
/* B7B214 802411C4 AE420000 */  sw        $v0, ($s2)
.L802411C8:
/* B7B218 802411C8 8E4300B0 */  lw        $v1, 0xb0($s2)
/* B7B21C 802411CC 30620004 */  andi      $v0, $v1, 4
/* B7B220 802411D0 10400007 */  beqz      $v0, .L802411F0
/* B7B224 802411D4 00000000 */   nop
/* B7B228 802411D8 824200B4 */  lb        $v0, 0xb4($s2)
/* B7B22C 802411DC 14400034 */  bnez      $v0, .L802412B0
/* B7B230 802411E0 0000102D */   daddu    $v0, $zero, $zero
/* B7B234 802411E4 2402FFFB */  addiu     $v0, $zero, -5
/* B7B238 802411E8 00621024 */  and       $v0, $v1, $v0
/* B7B23C 802411EC AE4200B0 */  sw        $v0, 0xb0($s2)
.L802411F0:
/* B7B240 802411F0 8E630070 */  lw        $v1, 0x70($s3)
/* B7B244 802411F4 2C62000F */  sltiu     $v0, $v1, 0xf
/* B7B248 802411F8 1040002C */  beqz      $v0, L802412AC_B7B2FC
/* B7B24C 802411FC 00031080 */   sll      $v0, $v1, 2
/* B7B250 80241200 3C018024 */  lui       $at, %hi(jtbl_80243888_B7D8D8)
/* B7B254 80241204 00220821 */  addu      $at, $at, $v0
/* B7B258 80241208 8C223888 */  lw        $v0, %lo(jtbl_80243888_B7D8D8)($at)
/* B7B25C 8024120C 00400008 */  jr        $v0
/* B7B260 80241210 00000000 */   nop
glabel L80241214_B7B264
/* B7B264 80241214 0260202D */  daddu     $a0, $s3, $zero
/* B7B268 80241218 0280282D */  daddu     $a1, $s4, $zero
/* B7B26C 8024121C 0C090130 */  jal       func_802404C0_B7A510
/* B7B270 80241220 0200302D */   daddu    $a2, $s0, $zero
glabel L80241224_B7B274
/* B7B274 80241224 0260202D */  daddu     $a0, $s3, $zero
/* B7B278 80241228 0280282D */  daddu     $a1, $s4, $zero
/* B7B27C 8024122C 0C0901BC */  jal       func_802406F0_B7A740
/* B7B280 80241230 0200302D */   daddu    $a2, $s0, $zero
/* B7B284 80241234 080904AC */  j         .L802412B0
/* B7B288 80241238 0000102D */   daddu    $v0, $zero, $zero
glabel L8024123C_B7B28C
/* B7B28C 8024123C 0260202D */  daddu     $a0, $s3, $zero
/* B7B290 80241240 0280282D */  daddu     $a1, $s4, $zero
/* B7B294 80241244 0C09028A */  jal       jan_14_UnkNpcAIFunc1
/* B7B298 80241248 0200302D */   daddu    $a2, $s0, $zero
/* B7B29C 8024124C 8E630070 */  lw        $v1, 0x70($s3)
/* B7B2A0 80241250 24020003 */  addiu     $v0, $zero, 3
/* B7B2A4 80241254 14620016 */  bne       $v1, $v0, .L802412B0
/* B7B2A8 80241258 0000102D */   daddu    $v0, $zero, $zero
glabel L8024125C_B7B2AC
/* B7B2AC 8024125C 0260202D */  daddu     $a0, $s3, $zero
/* B7B2B0 80241260 0280282D */  daddu     $a1, $s4, $zero
/* B7B2B4 80241264 0C0902BA */  jal       func_80240AE8_B7AB38
/* B7B2B8 80241268 0200302D */   daddu    $a2, $s0, $zero
/* B7B2BC 8024126C 080904AC */  j         .L802412B0
/* B7B2C0 80241270 0000102D */   daddu    $v0, $zero, $zero
glabel L80241274_B7B2C4
/* B7B2C4 80241274 0260202D */  daddu     $a0, $s3, $zero
/* B7B2C8 80241278 0280282D */  daddu     $a1, $s4, $zero
/* B7B2CC 8024127C 0C090323 */  jal       jan_14_UnkNpcAIFunc15
/* B7B2D0 80241280 0200302D */   daddu    $a2, $s0, $zero
glabel L80241284_B7B2D4
/* B7B2D4 80241284 0260202D */  daddu     $a0, $s3, $zero
/* B7B2D8 80241288 0280282D */  daddu     $a1, $s4, $zero
/* B7B2DC 8024128C 0C09035B */  jal       func_80240D6C_B7ADBC
/* B7B2E0 80241290 0200302D */   daddu    $a2, $s0, $zero
/* B7B2E4 80241294 080904AC */  j         .L802412B0
/* B7B2E8 80241298 0000102D */   daddu    $v0, $zero, $zero
glabel L8024129C_B7B2EC
/* B7B2EC 8024129C 0260202D */  daddu     $a0, $s3, $zero
/* B7B2F0 802412A0 0280282D */  daddu     $a1, $s4, $zero
/* B7B2F4 802412A4 0C09041B */  jal       jan_14_UnkDurationCheck
/* B7B2F8 802412A8 0200302D */   daddu    $a2, $s0, $zero
glabel L802412AC_B7B2FC
/* B7B2FC 802412AC 0000102D */  daddu     $v0, $zero, $zero
.L802412B0:
/* B7B300 802412B0 8FBF0048 */  lw        $ra, 0x48($sp)
/* B7B304 802412B4 8FB50044 */  lw        $s5, 0x44($sp)
/* B7B308 802412B8 8FB40040 */  lw        $s4, 0x40($sp)
/* B7B30C 802412BC 8FB3003C */  lw        $s3, 0x3c($sp)
/* B7B310 802412C0 8FB20038 */  lw        $s2, 0x38($sp)
/* B7B314 802412C4 8FB10034 */  lw        $s1, 0x34($sp)
/* B7B318 802412C8 8FB00030 */  lw        $s0, 0x30($sp)
/* B7B31C 802412CC 03E00008 */  jr        $ra
/* B7B320 802412D0 27BD0050 */   addiu    $sp, $sp, 0x50
/* B7B324 802412D4 00000000 */  nop
/* B7B328 802412D8 00000000 */  nop
/* B7B32C 802412DC 00000000 */  nop
