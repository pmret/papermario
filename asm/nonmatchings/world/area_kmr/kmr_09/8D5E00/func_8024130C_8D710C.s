.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024130C_8D710C
/* 8D710C 8024130C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 8D7110 80241310 AFB40040 */  sw        $s4, 0x40($sp)
/* 8D7114 80241314 0080A02D */  daddu     $s4, $a0, $zero
/* 8D7118 80241318 AFBF0048 */  sw        $ra, 0x48($sp)
/* 8D711C 8024131C AFB50044 */  sw        $s5, 0x44($sp)
/* 8D7120 80241320 AFB3003C */  sw        $s3, 0x3c($sp)
/* 8D7124 80241324 AFB20038 */  sw        $s2, 0x38($sp)
/* 8D7128 80241328 AFB10034 */  sw        $s1, 0x34($sp)
/* 8D712C 8024132C AFB00030 */  sw        $s0, 0x30($sp)
/* 8D7130 80241330 8E920148 */  lw        $s2, 0x148($s4)
/* 8D7134 80241334 86440008 */  lh        $a0, 8($s2)
/* 8D7138 80241338 8E90000C */  lw        $s0, 0xc($s4)
/* 8D713C 8024133C 0C00EABB */  jal       get_npc_unsafe
/* 8D7140 80241340 00A0882D */   daddu    $s1, $a1, $zero
/* 8D7144 80241344 0280202D */  daddu     $a0, $s4, $zero
/* 8D7148 80241348 8E050000 */  lw        $a1, ($s0)
/* 8D714C 8024134C 0C0B1EAF */  jal       get_variable
/* 8D7150 80241350 0040A82D */   daddu    $s5, $v0, $zero
/* 8D7154 80241354 AFA00010 */  sw        $zero, 0x10($sp)
/* 8D7158 80241358 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8D715C 8024135C 8C630030 */  lw        $v1, 0x30($v1)
/* 8D7160 80241360 AFA30014 */  sw        $v1, 0x14($sp)
/* 8D7164 80241364 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8D7168 80241368 8C63001C */  lw        $v1, 0x1c($v1)
/* 8D716C 8024136C AFA30018 */  sw        $v1, 0x18($sp)
/* 8D7170 80241370 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8D7174 80241374 8C630024 */  lw        $v1, 0x24($v1)
/* 8D7178 80241378 AFA3001C */  sw        $v1, 0x1c($sp)
/* 8D717C 8024137C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8D7180 80241380 8C630028 */  lw        $v1, 0x28($v1)
/* 8D7184 80241384 27B30010 */  addiu     $s3, $sp, 0x10
/* 8D7188 80241388 AFA30020 */  sw        $v1, 0x20($sp)
/* 8D718C 8024138C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8D7190 80241390 3C0142F0 */  lui       $at, 0x42f0
/* 8D7194 80241394 44810000 */  mtc1      $at, $f0
/* 8D7198 80241398 8C63002C */  lw        $v1, 0x2c($v1)
/* 8D719C 8024139C 0040802D */  daddu     $s0, $v0, $zero
/* 8D71A0 802413A0 E7A00028 */  swc1      $f0, 0x28($sp)
/* 8D71A4 802413A4 A7A0002C */  sh        $zero, 0x2c($sp)
/* 8D71A8 802413A8 12200006 */  beqz      $s1, .L802413C4
/* 8D71AC 802413AC AFA30024 */   sw       $v1, 0x24($sp)
/* 8D71B0 802413B0 02A0202D */  daddu     $a0, $s5, $zero
/* 8D71B4 802413B4 0240282D */  daddu     $a1, $s2, $zero
/* 8D71B8 802413B8 0280302D */  daddu     $a2, $s4, $zero
/* 8D71BC 802413BC 0C09047A */  jal       func_802411E8_8D6FE8
/* 8D71C0 802413C0 0200382D */   daddu    $a3, $s0, $zero
.L802413C4:
/* 8D71C4 802413C4 2402FFFE */  addiu     $v0, $zero, -2
/* 8D71C8 802413C8 A2A200AB */  sb        $v0, 0xab($s5)
/* 8D71CC 802413CC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 8D71D0 802413D0 30620004 */  andi      $v0, $v1, 4
/* 8D71D4 802413D4 10400007 */  beqz      $v0, .L802413F4
/* 8D71D8 802413D8 00000000 */   nop      
/* 8D71DC 802413DC 824200B4 */  lb        $v0, 0xb4($s2)
/* 8D71E0 802413E0 1440003C */  bnez      $v0, .L802414D4
/* 8D71E4 802413E4 0000102D */   daddu    $v0, $zero, $zero
/* 8D71E8 802413E8 2402FFFB */  addiu     $v0, $zero, -5
/* 8D71EC 802413EC 00621024 */  and       $v0, $v1, $v0
/* 8D71F0 802413F0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802413F4:
/* 8D71F4 802413F4 8E830070 */  lw        $v1, 0x70($s4)
/* 8D71F8 802413F8 2C62000F */  sltiu     $v0, $v1, 0xf
/* 8D71FC 802413FC 10400034 */  beqz      $v0, .L802414D0
/* 8D7200 80241400 00031080 */   sll      $v0, $v1, 2
/* 8D7204 80241404 3C018024 */  lui       $at, 0x8024
/* 8D7208 80241408 00220821 */  addu      $at, $at, $v0
/* 8D720C 8024140C 8C222688 */  lw        $v0, 0x2688($at)
/* 8D7210 80241410 00400008 */  jr        $v0
/* 8D7214 80241414 00000000 */   nop      
/* 8D7218 80241418 0280202D */  daddu     $a0, $s4, $zero
/* 8D721C 8024141C 0200282D */  daddu     $a1, $s0, $zero
/* 8D7220 80241420 0C090000 */  jal       func_80240000_8D5E00
/* 8D7224 80241424 0260302D */   daddu    $a2, $s3, $zero
/* 8D7228 80241428 0280202D */  daddu     $a0, $s4, $zero
/* 8D722C 8024142C 0200282D */  daddu     $a1, $s0, $zero
/* 8D7230 80241430 0C09006C */  jal       func_802401B0_8D5FB0
/* 8D7234 80241434 0260302D */   daddu    $a2, $s3, $zero
/* 8D7238 80241438 08090535 */  j         .L802414D4
/* 8D723C 8024143C 0000102D */   daddu    $v0, $zero, $zero
/* 8D7240 80241440 0280202D */  daddu     $a0, $s4, $zero
/* 8D7244 80241444 0200282D */  daddu     $a1, $s0, $zero
/* 8D7248 80241448 0C0901F6 */  jal       UnkNpcAIFunc1
/* 8D724C 8024144C 0260302D */   daddu    $a2, $s3, $zero
/* 8D7250 80241450 0280202D */  daddu     $a0, $s4, $zero
/* 8D7254 80241454 0200282D */  daddu     $a1, $s0, $zero
/* 8D7258 80241458 0C090226 */  jal       func_80240898_8D6698
/* 8D725C 8024145C 0260302D */   daddu    $a2, $s3, $zero
/* 8D7260 80241460 08090535 */  j         .L802414D4
/* 8D7264 80241464 0000102D */   daddu    $v0, $zero, $zero
/* 8D7268 80241468 0280202D */  daddu     $a0, $s4, $zero
/* 8D726C 8024146C 0200282D */  daddu     $a1, $s0, $zero
/* 8D7270 80241470 0C0902F7 */  jal       UnkNpcAIFunc2
/* 8D7274 80241474 0260302D */   daddu    $a2, $s3, $zero
/* 8D7278 80241478 0280202D */  daddu     $a0, $s4, $zero
/* 8D727C 8024147C 0200282D */  daddu     $a1, $s0, $zero
/* 8D7280 80241480 0C090315 */  jal       func_80240C54_8D6A54
/* 8D7284 80241484 0260302D */   daddu    $a2, $s3, $zero
/* 8D7288 80241488 08090535 */  j         .L802414D4
/* 8D728C 8024148C 0000102D */   daddu    $v0, $zero, $zero
/* 8D7290 80241490 0280202D */  daddu     $a0, $s4, $zero
/* 8D7294 80241494 0200282D */  daddu     $a1, $s0, $zero
/* 8D7298 80241498 0C090330 */  jal       func_80240CC0_8D6AC0
/* 8D729C 8024149C 0260302D */   daddu    $a2, $s3, $zero
/* 8D72A0 802414A0 08090535 */  j         .L802414D4
/* 8D72A4 802414A4 0000102D */   daddu    $v0, $zero, $zero
/* 8D72A8 802414A8 0280202D */  daddu     $a0, $s4, $zero
/* 8D72AC 802414AC 0200282D */  daddu     $a1, $s0, $zero
/* 8D72B0 802414B0 0C09037D */  jal       UnkNpcAIFunc3
/* 8D72B4 802414B4 0260302D */   daddu    $a2, $s3, $zero
/* 8D72B8 802414B8 08090535 */  j         .L802414D4
/* 8D72BC 802414BC 0000102D */   daddu    $v0, $zero, $zero
/* 8D72C0 802414C0 0280202D */  daddu     $a0, $s4, $zero
/* 8D72C4 802414C4 0200282D */  daddu     $a1, $s0, $zero
/* 8D72C8 802414C8 0C090396 */  jal       func_80240E58_8D6C58
/* 8D72CC 802414CC 0260302D */   daddu    $a2, $s3, $zero
.L802414D0:
/* 8D72D0 802414D0 0000102D */  daddu     $v0, $zero, $zero
.L802414D4:
/* 8D72D4 802414D4 8FBF0048 */  lw        $ra, 0x48($sp)
/* 8D72D8 802414D8 8FB50044 */  lw        $s5, 0x44($sp)
/* 8D72DC 802414DC 8FB40040 */  lw        $s4, 0x40($sp)
/* 8D72E0 802414E0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8D72E4 802414E4 8FB20038 */  lw        $s2, 0x38($sp)
/* 8D72E8 802414E8 8FB10034 */  lw        $s1, 0x34($sp)
/* 8D72EC 802414EC 8FB00030 */  lw        $s0, 0x30($sp)
/* 8D72F0 802414F0 03E00008 */  jr        $ra
/* 8D72F4 802414F4 27BD0050 */   addiu    $sp, $sp, 0x50
