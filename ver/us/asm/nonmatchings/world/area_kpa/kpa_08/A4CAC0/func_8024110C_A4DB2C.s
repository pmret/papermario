.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80242570_A4EF90
.word L80241258_A4DC78, L80241278_A4DC98, L80241350_A4DD70, L80241350_A4DD70, L80241350_A4DD70, L80241290_A4DCB0, L802412A0_A4DCC0, L80241350_A4DD70, L80241350_A4DD70, L80241350_A4DD70, L802412B8_A4DCD8, L802412C8_A4DCE8, L80241350_A4DD70, L80241350_A4DD70, L80241350_A4DD70, L80241350_A4DD70, L80241350_A4DD70, L80241350_A4DD70, L80241350_A4DD70, L80241350_A4DD70, L802412E0_A4DD00, L802412F8_A4DD18, L80241310_A4DD30, L80241328_A4DD48, L80241340_A4DD60, 0, 0, 0

.section .text

glabel func_8024110C_A4DB2C
/* A4DB2C 8024110C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A4DB30 80241110 AFB50044 */  sw        $s5, 0x44($sp)
/* A4DB34 80241114 0080A82D */  daddu     $s5, $a0, $zero
/* A4DB38 80241118 AFBF0048 */  sw        $ra, 0x48($sp)
/* A4DB3C 8024111C AFB40040 */  sw        $s4, 0x40($sp)
/* A4DB40 80241120 AFB3003C */  sw        $s3, 0x3c($sp)
/* A4DB44 80241124 AFB20038 */  sw        $s2, 0x38($sp)
/* A4DB48 80241128 AFB10034 */  sw        $s1, 0x34($sp)
/* A4DB4C 8024112C AFB00030 */  sw        $s0, 0x30($sp)
/* A4DB50 80241130 8EB10148 */  lw        $s1, 0x148($s5)
/* A4DB54 80241134 86240008 */  lh        $a0, 8($s1)
/* A4DB58 80241138 0C00EABB */  jal       get_npc_unsafe
/* A4DB5C 8024113C 00A0802D */   daddu    $s0, $a1, $zero
/* A4DB60 80241140 8EA3000C */  lw        $v1, 0xc($s5)
/* A4DB64 80241144 02A0202D */  daddu     $a0, $s5, $zero
/* A4DB68 80241148 8C650000 */  lw        $a1, ($v1)
/* A4DB6C 8024114C 0C0B1EAF */  jal       evt_get_variable
/* A4DB70 80241150 0040902D */   daddu    $s2, $v0, $zero
/* A4DB74 80241154 AFA00010 */  sw        $zero, 0x10($sp)
/* A4DB78 80241158 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A4DB7C 8024115C 8C630030 */  lw        $v1, 0x30($v1)
/* A4DB80 80241160 AFA30014 */  sw        $v1, 0x14($sp)
/* A4DB84 80241164 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A4DB88 80241168 8C63001C */  lw        $v1, 0x1c($v1)
/* A4DB8C 8024116C AFA30018 */  sw        $v1, 0x18($sp)
/* A4DB90 80241170 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A4DB94 80241174 8C630024 */  lw        $v1, 0x24($v1)
/* A4DB98 80241178 AFA3001C */  sw        $v1, 0x1c($sp)
/* A4DB9C 8024117C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A4DBA0 80241180 8C630028 */  lw        $v1, 0x28($v1)
/* A4DBA4 80241184 27B40010 */  addiu     $s4, $sp, 0x10
/* A4DBA8 80241188 AFA30020 */  sw        $v1, 0x20($sp)
/* A4DBAC 8024118C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A4DBB0 80241190 3C0142C8 */  lui       $at, 0x42c8
/* A4DBB4 80241194 44810000 */  mtc1      $at, $f0
/* A4DBB8 80241198 8C63002C */  lw        $v1, 0x2c($v1)
/* A4DBBC 8024119C 0040982D */  daddu     $s3, $v0, $zero
/* A4DBC0 802411A0 E7A00028 */  swc1      $f0, 0x28($sp)
/* A4DBC4 802411A4 A7A0002C */  sh        $zero, 0x2c($sp)
/* A4DBC8 802411A8 16000005 */  bnez      $s0, .L802411C0
/* A4DBCC 802411AC AFA30024 */   sw       $v1, 0x24($sp)
/* A4DBD0 802411B0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A4DBD4 802411B4 30420004 */  andi      $v0, $v0, 4
/* A4DBD8 802411B8 1040001E */  beqz      $v0, .L80241234
/* A4DBDC 802411BC 00000000 */   nop
.L802411C0:
/* A4DBE0 802411C0 8E430000 */  lw        $v1, ($s2)
/* A4DBE4 802411C4 2402F7FF */  addiu     $v0, $zero, -0x801
/* A4DBE8 802411C8 00621824 */  and       $v1, $v1, $v0
/* A4DBEC 802411CC 8E2200CC */  lw        $v0, 0xcc($s1)
/* A4DBF0 802411D0 3C040020 */  lui       $a0, 0x20
/* A4DBF4 802411D4 8C420000 */  lw        $v0, ($v0)
/* A4DBF8 802411D8 00641825 */  or        $v1, $v1, $a0
/* A4DBFC 802411DC AE430000 */  sw        $v1, ($s2)
/* A4DC00 802411E0 AE420028 */  sw        $v0, 0x28($s2)
/* A4DC04 802411E4 8E220000 */  lw        $v0, ($s1)
/* A4DC08 802411E8 00441025 */  or        $v0, $v0, $a0
/* A4DC0C 802411EC AE220000 */  sw        $v0, ($s1)
/* A4DC10 802411F0 A640008E */  sh        $zero, 0x8e($s2)
/* A4DC14 802411F4 8E2300B0 */  lw        $v1, 0xb0($s1)
/* A4DC18 802411F8 30620004 */  andi      $v0, $v1, 4
/* A4DC1C 802411FC 1040000C */  beqz      $v0, .L80241230
/* A4DC20 80241200 2402FFFB */   addiu    $v0, $zero, -5
/* A4DC24 80241204 3C013F80 */  lui       $at, 0x3f80
/* A4DC28 80241208 44810000 */  mtc1      $at, $f0
/* A4DC2C 8024120C 00621024 */  and       $v0, $v1, $v0
/* A4DC30 80241210 AE2200B0 */  sw        $v0, 0xb0($s1)
/* A4DC34 80241214 240200FF */  addiu     $v0, $zero, 0xff
/* A4DC38 80241218 A24200AC */  sb        $v0, 0xac($s2)
/* A4DC3C 8024121C 24020014 */  addiu     $v0, $zero, 0x14
/* A4DC40 80241220 A642008E */  sh        $v0, 0x8e($s2)
/* A4DC44 80241224 E6400054 */  swc1      $f0, 0x54($s2)
/* A4DC48 80241228 E6400058 */  swc1      $f0, 0x58($s2)
/* A4DC4C 8024122C E640005C */  swc1      $f0, 0x5c($s2)
.L80241230:
/* A4DC50 80241230 AEA00070 */  sw        $zero, 0x70($s5)
.L80241234:
/* A4DC54 80241234 8EA30070 */  lw        $v1, 0x70($s5)
/* A4DC58 80241238 2C620019 */  sltiu     $v0, $v1, 0x19
/* A4DC5C 8024123C 10400044 */  beqz      $v0, L80241350_A4DD70
/* A4DC60 80241240 00031080 */   sll      $v0, $v1, 2
/* A4DC64 80241244 3C018024 */  lui       $at, %hi(jtbl_80242570_A4EF90)
/* A4DC68 80241248 00220821 */  addu      $at, $at, $v0
/* A4DC6C 8024124C 8C222570 */  lw        $v0, %lo(jtbl_80242570_A4EF90)($at)
/* A4DC70 80241250 00400008 */  jr        $v0
/* A4DC74 80241254 00000000 */   nop
glabel L80241258_A4DC78
/* A4DC78 80241258 02A0202D */  daddu     $a0, $s5, $zero
/* A4DC7C 8024125C 0260282D */  daddu     $a1, $s3, $zero
/* A4DC80 80241260 0C0901E0 */  jal       func_80240780_A4D1A0
/* A4DC84 80241264 0280302D */   daddu    $a2, $s4, $zero
/* A4DC88 80241268 8EA30070 */  lw        $v1, 0x70($s5)
/* A4DC8C 8024126C 24020001 */  addiu     $v0, $zero, 1
/* A4DC90 80241270 14620037 */  bne       $v1, $v0, L80241350_A4DD70
/* A4DC94 80241274 00000000 */   nop
glabel L80241278_A4DC98
/* A4DC98 80241278 02A0202D */  daddu     $a0, $s5, $zero
/* A4DC9C 8024127C 0260282D */  daddu     $a1, $s3, $zero
/* A4DCA0 80241280 0C0901FD */  jal       func_802407F4_A4D214
/* A4DCA4 80241284 0280302D */   daddu    $a2, $s4, $zero
/* A4DCA8 80241288 080904D4 */  j         L80241350_A4DD70
/* A4DCAC 8024128C 00000000 */   nop
glabel L80241290_A4DCB0
/* A4DCB0 80241290 02A0202D */  daddu     $a0, $s5, $zero
/* A4DCB4 80241294 0260282D */  daddu     $a1, $s3, $zero
/* A4DCB8 80241298 0C090248 */  jal       func_80240920_A4D340
/* A4DCBC 8024129C 0280302D */   daddu    $a2, $s4, $zero
glabel L802412A0_A4DCC0
/* A4DCC0 802412A0 02A0202D */  daddu     $a0, $s5, $zero
/* A4DCC4 802412A4 0260282D */  daddu     $a1, $s3, $zero
/* A4DCC8 802412A8 0C090270 */  jal       func_802409C0_A4D3E0
/* A4DCCC 802412AC 0280302D */   daddu    $a2, $s4, $zero
/* A4DCD0 802412B0 080904D4 */  j         L80241350_A4DD70
/* A4DCD4 802412B4 00000000 */   nop
glabel L802412B8_A4DCD8
/* A4DCD8 802412B8 02A0202D */  daddu     $a0, $s5, $zero
/* A4DCDC 802412BC 0260282D */  daddu     $a1, $s3, $zero
/* A4DCE0 802412C0 0C090289 */  jal       func_80240A24_A4D444
/* A4DCE4 802412C4 0280302D */   daddu    $a2, $s4, $zero
glabel L802412C8_A4DCE8
/* A4DCE8 802412C8 02A0202D */  daddu     $a0, $s5, $zero
/* A4DCEC 802412CC 0260282D */  daddu     $a1, $s3, $zero
/* A4DCF0 802412D0 0C0902D9 */  jal       func_80240B64_A4D584
/* A4DCF4 802412D4 0280302D */   daddu    $a2, $s4, $zero
/* A4DCF8 802412D8 080904D4 */  j         L80241350_A4DD70
/* A4DCFC 802412DC 00000000 */   nop
glabel L802412E0_A4DD00
/* A4DD00 802412E0 02A0202D */  daddu     $a0, $s5, $zero
/* A4DD04 802412E4 0260282D */  daddu     $a1, $s3, $zero
/* A4DD08 802412E8 0C090342 */  jal       func_80240D08_A4D728
/* A4DD0C 802412EC 0280302D */   daddu    $a2, $s4, $zero
/* A4DD10 802412F0 080904D4 */  j         L80241350_A4DD70
/* A4DD14 802412F4 00000000 */   nop
glabel L802412F8_A4DD18
/* A4DD18 802412F8 02A0202D */  daddu     $a0, $s5, $zero
/* A4DD1C 802412FC 0260282D */  daddu     $a1, $s3, $zero
/* A4DD20 80241300 0C090351 */  jal       func_80240D44_A4D764
/* A4DD24 80241304 0280302D */   daddu    $a2, $s4, $zero
/* A4DD28 80241308 080904D4 */  j         L80241350_A4DD70
/* A4DD2C 8024130C 00000000 */   nop
glabel L80241310_A4DD30
/* A4DD30 80241310 02A0202D */  daddu     $a0, $s5, $zero
/* A4DD34 80241314 0260282D */  daddu     $a1, $s3, $zero
/* A4DD38 80241318 0C0903C1 */  jal       func_80240F04_A4D924
/* A4DD3C 8024131C 0280302D */   daddu    $a2, $s4, $zero
/* A4DD40 80241320 080904D4 */  j         L80241350_A4DD70
/* A4DD44 80241324 00000000 */   nop
glabel L80241328_A4DD48
/* A4DD48 80241328 02A0202D */  daddu     $a0, $s5, $zero
/* A4DD4C 8024132C 0260282D */  daddu     $a1, $s3, $zero
/* A4DD50 80241330 0C0903DC */  jal       func_80240F70_A4D990
/* A4DD54 80241334 0280302D */   daddu    $a2, $s4, $zero
/* A4DD58 80241338 080904D4 */  j         L80241350_A4DD70
/* A4DD5C 8024133C 00000000 */   nop
glabel L80241340_A4DD60
/* A4DD60 80241340 02A0202D */  daddu     $a0, $s5, $zero
/* A4DD64 80241344 0260282D */  daddu     $a1, $s3, $zero
/* A4DD68 80241348 0C090429 */  jal       func_802410A4_A4DAC4
/* A4DD6C 8024134C 0280302D */   daddu    $a2, $s4, $zero
glabel L80241350_A4DD70
/* A4DD70 80241350 8FBF0048 */  lw        $ra, 0x48($sp)
/* A4DD74 80241354 8FB50044 */  lw        $s5, 0x44($sp)
/* A4DD78 80241358 8FB40040 */  lw        $s4, 0x40($sp)
/* A4DD7C 8024135C 8FB3003C */  lw        $s3, 0x3c($sp)
/* A4DD80 80241360 8FB20038 */  lw        $s2, 0x38($sp)
/* A4DD84 80241364 8FB10034 */  lw        $s1, 0x34($sp)
/* A4DD88 80241368 8FB00030 */  lw        $s0, 0x30($sp)
/* A4DD8C 8024136C 0000102D */  daddu     $v0, $zero, $zero
/* A4DD90 80241370 03E00008 */  jr        $ra
/* A4DD94 80241374 27BD0050 */   addiu    $sp, $sp, 0x50
