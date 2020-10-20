.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422C0_DF1160
/* DF1160 802422C0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* DF1164 802422C4 AFB40040 */  sw        $s4, 0x40($sp)
/* DF1168 802422C8 0080A02D */  daddu     $s4, $a0, $zero
/* DF116C 802422CC AFBF0048 */  sw        $ra, 0x48($sp)
/* DF1170 802422D0 AFB50044 */  sw        $s5, 0x44($sp)
/* DF1174 802422D4 AFB3003C */  sw        $s3, 0x3c($sp)
/* DF1178 802422D8 AFB20038 */  sw        $s2, 0x38($sp)
/* DF117C 802422DC AFB10034 */  sw        $s1, 0x34($sp)
/* DF1180 802422E0 AFB00030 */  sw        $s0, 0x30($sp)
/* DF1184 802422E4 8E920148 */  lw        $s2, 0x148($s4)
/* DF1188 802422E8 86440008 */  lh        $a0, 8($s2)
/* DF118C 802422EC 8E90000C */  lw        $s0, 0xc($s4)
/* DF1190 802422F0 0C00EABB */  jal       get_npc_unsafe
/* DF1194 802422F4 00A0882D */   daddu    $s1, $a1, $zero
/* DF1198 802422F8 0280202D */  daddu     $a0, $s4, $zero
/* DF119C 802422FC 8E050000 */  lw        $a1, ($s0)
/* DF11A0 80242300 0C0B1EAF */  jal       get_variable
/* DF11A4 80242304 0040A82D */   daddu    $s5, $v0, $zero
/* DF11A8 80242308 AFA00010 */  sw        $zero, 0x10($sp)
/* DF11AC 8024230C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DF11B0 80242310 8C630030 */  lw        $v1, 0x30($v1)
/* DF11B4 80242314 AFA30014 */  sw        $v1, 0x14($sp)
/* DF11B8 80242318 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DF11BC 8024231C 8C63001C */  lw        $v1, 0x1c($v1)
/* DF11C0 80242320 AFA30018 */  sw        $v1, 0x18($sp)
/* DF11C4 80242324 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DF11C8 80242328 8C630024 */  lw        $v1, 0x24($v1)
/* DF11CC 8024232C AFA3001C */  sw        $v1, 0x1c($sp)
/* DF11D0 80242330 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DF11D4 80242334 8C630028 */  lw        $v1, 0x28($v1)
/* DF11D8 80242338 27B30010 */  addiu     $s3, $sp, 0x10
/* DF11DC 8024233C AFA30020 */  sw        $v1, 0x20($sp)
/* DF11E0 80242340 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DF11E4 80242344 3C0142F0 */  lui       $at, 0x42f0
/* DF11E8 80242348 44810000 */  mtc1      $at, $f0
/* DF11EC 8024234C 8C63002C */  lw        $v1, 0x2c($v1)
/* DF11F0 80242350 0040802D */  daddu     $s0, $v0, $zero
/* DF11F4 80242354 E7A00028 */  swc1      $f0, 0x28($sp)
/* DF11F8 80242358 A7A0002C */  sh        $zero, 0x2c($sp)
/* DF11FC 8024235C 12200006 */  beqz      $s1, .L80242378
/* DF1200 80242360 AFA30024 */   sw       $v1, 0x24($sp)
/* DF1204 80242364 02A0202D */  daddu     $a0, $s5, $zero
/* DF1208 80242368 0240282D */  daddu     $a1, $s2, $zero
/* DF120C 8024236C 0280302D */  daddu     $a2, $s4, $zero
/* DF1210 80242370 0C090867 */  jal       func_8024219C
/* DF1214 80242374 0200382D */   daddu    $a3, $s0, $zero
.L80242378:
/* DF1218 80242378 2402FFFE */  addiu     $v0, $zero, -2
/* DF121C 8024237C A2A200AB */  sb        $v0, 0xab($s5)
/* DF1220 80242380 8E4300B0 */  lw        $v1, 0xb0($s2)
/* DF1224 80242384 30620004 */  andi      $v0, $v1, 4
/* DF1228 80242388 10400007 */  beqz      $v0, .L802423A8
/* DF122C 8024238C 00000000 */   nop      
/* DF1230 80242390 824200B4 */  lb        $v0, 0xb4($s2)
/* DF1234 80242394 1440003C */  bnez      $v0, .L80242488
/* DF1238 80242398 0000102D */   daddu    $v0, $zero, $zero
/* DF123C 8024239C 2402FFFB */  addiu     $v0, $zero, -5
/* DF1240 802423A0 00621024 */  and       $v0, $v1, $v0
/* DF1244 802423A4 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802423A8:
/* DF1248 802423A8 8E830070 */  lw        $v1, 0x70($s4)
/* DF124C 802423AC 2C62000F */  sltiu     $v0, $v1, 0xf
/* DF1250 802423B0 10400034 */  beqz      $v0, .L80242484
/* DF1254 802423B4 00031080 */   sll      $v0, $v1, 2
/* DF1258 802423B8 3C018024 */  lui       $at, 0x8024
/* DF125C 802423BC 00220821 */  addu      $at, $at, $v0
/* DF1260 802423C0 8C227968 */  lw        $v0, 0x7968($at)
/* DF1264 802423C4 00400008 */  jr        $v0
/* DF1268 802423C8 00000000 */   nop      
/* DF126C 802423CC 0280202D */  daddu     $a0, $s4, $zero
/* DF1270 802423D0 0200282D */  daddu     $a1, $s0, $zero
/* DF1274 802423D4 0C0903ED */  jal       func_80240FB4
/* DF1278 802423D8 0260302D */   daddu    $a2, $s3, $zero
/* DF127C 802423DC 0280202D */  daddu     $a0, $s4, $zero
/* DF1280 802423E0 0200282D */  daddu     $a1, $s0, $zero
/* DF1284 802423E4 0C090459 */  jal       func_80241164
/* DF1288 802423E8 0260302D */   daddu    $a2, $s3, $zero
/* DF128C 802423EC 08090922 */  j         .L80242488
/* DF1290 802423F0 0000102D */   daddu    $v0, $zero, $zero
/* DF1294 802423F4 0280202D */  daddu     $a0, $s4, $zero
/* DF1298 802423F8 0200282D */  daddu     $a1, $s0, $zero
/* DF129C 802423FC 0C0905E3 */  jal       func_8024178C
/* DF12A0 80242400 0260302D */   daddu    $a2, $s3, $zero
/* DF12A4 80242404 0280202D */  daddu     $a0, $s4, $zero
/* DF12A8 80242408 0200282D */  daddu     $a1, $s0, $zero
/* DF12AC 8024240C 0C090613 */  jal       func_8024184C
/* DF12B0 80242410 0260302D */   daddu    $a2, $s3, $zero
/* DF12B4 80242414 08090922 */  j         .L80242488
/* DF12B8 80242418 0000102D */   daddu    $v0, $zero, $zero
/* DF12BC 8024241C 0280202D */  daddu     $a0, $s4, $zero
/* DF12C0 80242420 0200282D */  daddu     $a1, $s0, $zero
/* DF12C4 80242424 0C0906E4 */  jal       func_80241B90
/* DF12C8 80242428 0260302D */   daddu    $a2, $s3, $zero
/* DF12CC 8024242C 0280202D */  daddu     $a0, $s4, $zero
/* DF12D0 80242430 0200282D */  daddu     $a1, $s0, $zero
/* DF12D4 80242434 0C090702 */  jal       func_80241C08
/* DF12D8 80242438 0260302D */   daddu    $a2, $s3, $zero
/* DF12DC 8024243C 08090922 */  j         .L80242488
/* DF12E0 80242440 0000102D */   daddu    $v0, $zero, $zero
/* DF12E4 80242444 0280202D */  daddu     $a0, $s4, $zero
/* DF12E8 80242448 0200282D */  daddu     $a1, $s0, $zero
/* DF12EC 8024244C 0C09071D */  jal       func_80241C74
/* DF12F0 80242450 0260302D */   daddu    $a2, $s3, $zero
/* DF12F4 80242454 08090922 */  j         .L80242488
/* DF12F8 80242458 0000102D */   daddu    $v0, $zero, $zero
/* DF12FC 8024245C 0280202D */  daddu     $a0, $s4, $zero
/* DF1300 80242460 0200282D */  daddu     $a1, $s0, $zero
/* DF1304 80242464 0C09076A */  jal       func_80241DA8
/* DF1308 80242468 0260302D */   daddu    $a2, $s3, $zero
/* DF130C 8024246C 08090922 */  j         .L80242488
/* DF1310 80242470 0000102D */   daddu    $v0, $zero, $zero
/* DF1314 80242474 0280202D */  daddu     $a0, $s4, $zero
/* DF1318 80242478 0200282D */  daddu     $a1, $s0, $zero
/* DF131C 8024247C 0C090783 */  jal       func_80241E0C
/* DF1320 80242480 0260302D */   daddu    $a2, $s3, $zero
.L80242484:
/* DF1324 80242484 0000102D */  daddu     $v0, $zero, $zero
.L80242488:
/* DF1328 80242488 8FBF0048 */  lw        $ra, 0x48($sp)
/* DF132C 8024248C 8FB50044 */  lw        $s5, 0x44($sp)
/* DF1330 80242490 8FB40040 */  lw        $s4, 0x40($sp)
/* DF1334 80242494 8FB3003C */  lw        $s3, 0x3c($sp)
/* DF1338 80242498 8FB20038 */  lw        $s2, 0x38($sp)
/* DF133C 8024249C 8FB10034 */  lw        $s1, 0x34($sp)
/* DF1340 802424A0 8FB00030 */  lw        $s0, 0x30($sp)
/* DF1344 802424A4 03E00008 */  jr        $ra
/* DF1348 802424A8 27BD0050 */   addiu    $sp, $sp, 0x50
