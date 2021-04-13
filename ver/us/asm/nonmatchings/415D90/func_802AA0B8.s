.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802ACC08
.word L802AA110_41EEA0, L802AA4BC_41F24C, L802AA548_41F2D8, L802AA61C_41F3AC, L802AA594_41F324, L802AA5C0_41F350, L802AA61C_41F3AC, L802AA61C_41F3AC, L802AA5D0_41F360, L802AA5F4_41F384, L802AA1F0_41EF80, L802AA394_41F124

.section .text

glabel func_802AA0B8
/* 41EE48 802AA0B8 3C03800E */  lui       $v1, %hi(gBattleStatus+0x46C)
/* 41EE4C 802AA0BC 8C63C4DC */  lw        $v1, %lo(gBattleStatus+0x46C)($v1)
/* 41EE50 802AA0C0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 41EE54 802AA0C4 AFB20018 */  sw        $s2, 0x18($sp)
/* 41EE58 802AA0C8 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 41EE5C 802AA0CC 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 41EE60 802AA0D0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 41EE64 802AA0D4 AFB10014 */  sw        $s1, 0x14($sp)
/* 41EE68 802AA0D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 41EE6C 802AA0DC F7B80030 */  sdc1      $f24, 0x30($sp)
/* 41EE70 802AA0E0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 41EE74 802AA0E4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 41EE78 802AA0E8 8E5000D8 */  lw        $s0, 0xd8($s2)
/* 41EE7C 802AA0EC 8E5100DC */  lw        $s1, 0xdc($s2)
/* 41EE80 802AA0F0 2C62000C */  sltiu     $v0, $v1, 0xc
/* 41EE84 802AA0F4 10400149 */  beqz      $v0, L802AA61C_41F3AC
/* 41EE88 802AA0F8 00031080 */   sll      $v0, $v1, 2
/* 41EE8C 802AA0FC 3C01802B */  lui       $at, %hi(jtbl_802ACC08)
/* 41EE90 802AA100 00220821 */  addu      $at, $at, $v0
/* 41EE94 802AA104 8C22CC08 */  lw        $v0, %lo(jtbl_802ACC08)($at)
/* 41EE98 802AA108 00400008 */  jr        $v0
/* 41EE9C 802AA10C 00000000 */   nop
glabel L802AA110_41EEA0
/* 41EEA0 802AA110 82030210 */  lb        $v1, 0x210($s0)
/* 41EEA4 802AA114 38620006 */  xori      $v0, $v1, 6
/* 41EEA8 802AA118 2C440001 */  sltiu     $a0, $v0, 1
/* 41EEAC 802AA11C 24020003 */  addiu     $v0, $zero, 3
/* 41EEB0 802AA120 50620001 */  beql      $v1, $v0, .L802AA128
/* 41EEB4 802AA124 24040001 */   addiu    $a0, $zero, 1
.L802AA128:
/* 41EEB8 802AA128 24120004 */  addiu     $s2, $zero, 4
/* 41EEBC 802AA12C 50720001 */  beql      $v1, $s2, .L802AA134
/* 41EEC0 802AA130 24040001 */   addiu    $a0, $zero, 1
.L802AA134:
/* 41EEC4 802AA134 24020005 */  addiu     $v0, $zero, 5
/* 41EEC8 802AA138 50620001 */  beql      $v1, $v0, .L802AA140
/* 41EECC 802AA13C 24040001 */   addiu    $a0, $zero, 1
.L802AA140:
/* 41EED0 802AA140 24020007 */  addiu     $v0, $zero, 7
/* 41EED4 802AA144 50620001 */  beql      $v1, $v0, .L802AA14C
/* 41EED8 802AA148 24040001 */   addiu    $a0, $zero, 1
.L802AA14C:
/* 41EEDC 802AA14C 24020008 */  addiu     $v0, $zero, 8
/* 41EEE0 802AA150 50620001 */  beql      $v1, $v0, .L802AA158
/* 41EEE4 802AA154 24040001 */   addiu    $a0, $zero, 1
.L802AA158:
/* 41EEE8 802AA158 82030214 */  lb        $v1, 0x214($s0)
/* 41EEEC 802AA15C 2402000C */  addiu     $v0, $zero, 0xc
/* 41EEF0 802AA160 50620001 */  beql      $v1, $v0, .L802AA168
/* 41EEF4 802AA164 24040001 */   addiu    $a0, $zero, 1
.L802AA168:
/* 41EEF8 802AA168 82030216 */  lb        $v1, 0x216($s0)
/* 41EEFC 802AA16C 2402000D */  addiu     $v0, $zero, 0xd
/* 41EF00 802AA170 50620001 */  beql      $v1, $v0, .L802AA178
/* 41EF04 802AA174 24040001 */   addiu    $a0, $zero, 1
.L802AA178:
/* 41EF08 802AA178 10800005 */  beqz      $a0, .L802AA190
/* 41EF0C 802AA17C 00000000 */   nop
/* 41EF10 802AA180 0C090464 */  jal       func_80241190
/* 41EF14 802AA184 24040016 */   addiu    $a0, $zero, 0x16
/* 41EF18 802AA188 080AA987 */  j         L802AA61C_41F3AC
/* 41EF1C 802AA18C 00000000 */   nop
.L802AA190:
/* 41EF20 802AA190 0C093903 */  jal       func_8024E40C
/* 41EF24 802AA194 24040002 */   addiu    $a0, $zero, 2
/* 41EF28 802AA198 0C093936 */  jal       move_cam_over
/* 41EF2C 802AA19C 2404000A */   addiu    $a0, $zero, 0xa
/* 41EF30 802AA1A0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 41EF34 802AA1A4 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 41EF38 802AA1A8 3C030010 */  lui       $v1, 0x10
/* 41EF3C 802AA1AC 00431024 */  and       $v0, $v0, $v1
/* 41EF40 802AA1B0 14400118 */  bnez      $v0, .L802AA614
/* 41EF44 802AA1B4 2402000B */   addiu    $v0, $zero, 0xb
/* 41EF48 802AA1B8 C6000138 */  lwc1      $f0, 0x138($s0)
/* 41EF4C 802AA1BC C6020140 */  lwc1      $f2, 0x140($s0)
/* 41EF50 802AA1C0 E600000C */  swc1      $f0, 0xc($s0)
/* 41EF54 802AA1C4 E6020014 */  swc1      $f2, 0x14($s0)
/* 41EF58 802AA1C8 C6200138 */  lwc1      $f0, 0x138($s1)
/* 41EF5C 802AA1CC E6000018 */  swc1      $f0, 0x18($s0)
/* 41EF60 802AA1D0 C6200140 */  lwc1      $f0, 0x140($s1)
/* 41EF64 802AA1D4 2402000A */  addiu     $v0, $zero, 0xa
/* 41EF68 802AA1D8 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 41EF6C 802AA1DC AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 41EF70 802AA1E0 A6120070 */  sh        $s2, 0x70($s0)
/* 41EF74 802AA1E4 AE000054 */  sw        $zero, 0x54($s0)
/* 41EF78 802AA1E8 080AA987 */  j         L802AA61C_41F3AC
/* 41EF7C 802AA1EC E6000020 */   swc1     $f0, 0x20($s0)
glabel L802AA1F0_41EF80
/* 41EF80 802AA1F0 86020070 */  lh        $v0, 0x70($s0)
/* 41EF84 802AA1F4 10400022 */  beqz      $v0, .L802AA280
/* 41EF88 802AA1F8 00000000 */   nop
/* 41EF8C 802AA1FC C6000018 */  lwc1      $f0, 0x18($s0)
/* 41EF90 802AA200 C6080144 */  lwc1      $f8, 0x144($s0)
/* 41EF94 802AA204 C6020020 */  lwc1      $f2, 0x20($s0)
/* 41EF98 802AA208 46080001 */  sub.s     $f0, $f0, $f8
/* 41EF9C 802AA20C C604014C */  lwc1      $f4, 0x14c($s0)
/* 41EFA0 802AA210 46041081 */  sub.s     $f2, $f2, $f4
/* 41EFA4 802AA214 44823000 */  mtc1      $v0, $f6
/* 41EFA8 802AA218 00000000 */  nop
/* 41EFAC 802AA21C 468031A0 */  cvt.s.w   $f6, $f6
/* 41EFB0 802AA220 46060003 */  div.s     $f0, $f0, $f6
/* 41EFB4 802AA224 46004200 */  add.s     $f8, $f8, $f0
/* 41EFB8 802AA228 46003006 */  mov.s     $f0, $f6
/* 41EFBC 802AA22C 46061083 */  div.s     $f2, $f2, $f6
/* 41EFC0 802AA230 C600000C */  lwc1      $f0, 0xc($s0)
/* 41EFC4 802AA234 46022100 */  add.s     $f4, $f4, $f2
/* 41EFC8 802AA238 E6080144 */  swc1      $f8, 0x144($s0)
/* 41EFCC 802AA23C E604014C */  swc1      $f4, 0x14c($s0)
/* 41EFD0 802AA240 C6240144 */  lwc1      $f4, 0x144($s1)
/* 41EFD4 802AA244 46040001 */  sub.s     $f0, $f0, $f4
/* 41EFD8 802AA248 46003086 */  mov.s     $f2, $f6
/* 41EFDC 802AA24C 46060003 */  div.s     $f0, $f0, $f6
/* 41EFE0 802AA250 46002100 */  add.s     $f4, $f4, $f0
/* 41EFE4 802AA254 E6240144 */  swc1      $f4, 0x144($s1)
/* 41EFE8 802AA258 C6000014 */  lwc1      $f0, 0x14($s0)
/* 41EFEC 802AA25C C624014C */  lwc1      $f4, 0x14c($s1)
/* 41EFF0 802AA260 86020070 */  lh        $v0, 0x70($s0)
/* 41EFF4 802AA264 46040001 */  sub.s     $f0, $f0, $f4
/* 41EFF8 802AA268 44821000 */  mtc1      $v0, $f2
/* 41EFFC 802AA26C 00000000 */  nop
/* 41F000 802AA270 468010A0 */  cvt.s.w   $f2, $f2
/* 41F004 802AA274 46020003 */  div.s     $f0, $f0, $f2
/* 41F008 802AA278 46002100 */  add.s     $f4, $f4, $f0
/* 41F00C 802AA27C E624014C */  swc1      $f4, 0x14c($s1)
.L802AA280:
/* 41F010 802AA280 C60C0054 */  lwc1      $f12, 0x54($s0)
/* 41F014 802AA284 3C0140C9 */  lui       $at, 0x40c9
/* 41F018 802AA288 34210FD0 */  ori       $at, $at, 0xfd0
/* 41F01C 802AA28C 4481B000 */  mtc1      $at, $f22
/* 41F020 802AA290 00000000 */  nop
/* 41F024 802AA294 46166302 */  mul.s     $f12, $f12, $f22
/* 41F028 802AA298 00000000 */  nop
/* 41F02C 802AA29C 3C0143B4 */  lui       $at, 0x43b4
/* 41F030 802AA2A0 4481C000 */  mtc1      $at, $f24
/* 41F034 802AA2A4 3C014180 */  lui       $at, 0x4180
/* 41F038 802AA2A8 4481A000 */  mtc1      $at, $f20
/* 41F03C 802AA2AC 0C00A85B */  jal       sin_rad
/* 41F040 802AA2B0 46186303 */   div.s    $f12, $f12, $f24
/* 41F044 802AA2B4 46140002 */  mul.s     $f0, $f0, $f20
/* 41F048 802AA2B8 00000000 */  nop
/* 41F04C 802AA2BC C602014C */  lwc1      $f2, 0x14c($s0)
/* 41F050 802AA2C0 46001080 */  add.s     $f2, $f2, $f0
/* 41F054 802AA2C4 C60C0054 */  lwc1      $f12, 0x54($s0)
/* 41F058 802AA2C8 46006307 */  neg.s     $f12, $f12
/* 41F05C 802AA2CC 0C00A6C9 */  jal       clamp_angle
/* 41F060 802AA2D0 E602014C */   swc1     $f2, 0x14c($s0)
/* 41F064 802AA2D4 C60C0054 */  lwc1      $f12, 0x54($s0)
/* 41F068 802AA2D8 46166302 */  mul.s     $f12, $f12, $f22
/* 41F06C 802AA2DC 00000000 */  nop
/* 41F070 802AA2E0 E600018C */  swc1      $f0, 0x18c($s0)
/* 41F074 802AA2E4 0C00A85B */  jal       sin_rad
/* 41F078 802AA2E8 46186303 */   div.s    $f12, $f12, $f24
/* 41F07C 802AA2EC 46140002 */  mul.s     $f0, $f0, $f20
/* 41F080 802AA2F0 00000000 */  nop
/* 41F084 802AA2F4 C622014C */  lwc1      $f2, 0x14c($s1)
/* 41F088 802AA2F8 46001081 */  sub.s     $f2, $f2, $f0
/* 41F08C 802AA2FC E622014C */  swc1      $f2, 0x14c($s1)
/* 41F090 802AA300 C60C0054 */  lwc1      $f12, 0x54($s0)
/* 41F094 802AA304 0C00A6C9 */  jal       clamp_angle
/* 41F098 802AA308 46006307 */   neg.s    $f12, $f12
/* 41F09C 802AA30C E620018C */  swc1      $f0, 0x18c($s1)
/* 41F0A0 802AA310 C6000054 */  lwc1      $f0, 0x54($s0)
/* 41F0A4 802AA314 3C0142B4 */  lui       $at, 0x42b4
/* 41F0A8 802AA318 44811000 */  mtc1      $at, $f2
/* 41F0AC 802AA31C 86020070 */  lh        $v0, 0x70($s0)
/* 41F0B0 802AA320 46020000 */  add.s     $f0, $f0, $f2
/* 41F0B4 802AA324 96030070 */  lhu       $v1, 0x70($s0)
/* 41F0B8 802AA328 10400004 */  beqz      $v0, .L802AA33C
/* 41F0BC 802AA32C E6000054 */   swc1     $f0, 0x54($s0)
/* 41F0C0 802AA330 2462FFFF */  addiu     $v0, $v1, -1
/* 41F0C4 802AA334 080AA987 */  j         L802AA61C_41F3AC
/* 41F0C8 802AA338 A6020070 */   sh       $v0, 0x70($s0)
.L802AA33C:
/* 41F0CC 802AA33C C6000018 */  lwc1      $f0, 0x18($s0)
/* 41F0D0 802AA340 C6020020 */  lwc1      $f2, 0x20($s0)
/* 41F0D4 802AA344 C604000C */  lwc1      $f4, 0xc($s0)
/* 41F0D8 802AA348 E6000144 */  swc1      $f0, 0x144($s0)
/* 41F0DC 802AA34C E602014C */  swc1      $f2, 0x14c($s0)
/* 41F0E0 802AA350 E6240144 */  swc1      $f4, 0x144($s1)
/* 41F0E4 802AA354 C6000014 */  lwc1      $f0, 0x14($s0)
/* 41F0E8 802AA358 E620014C */  swc1      $f0, 0x14c($s1)
/* 41F0EC 802AA35C C6000144 */  lwc1      $f0, 0x144($s0)
/* 41F0F0 802AA360 C602014C */  lwc1      $f2, 0x14c($s0)
/* 41F0F4 802AA364 E6000138 */  swc1      $f0, 0x138($s0)
/* 41F0F8 802AA368 E6020140 */  swc1      $f2, 0x140($s0)
/* 41F0FC 802AA36C C6200144 */  lwc1      $f0, 0x144($s1)
/* 41F100 802AA370 C622014C */  lwc1      $f2, 0x14c($s1)
/* 41F104 802AA374 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 41F108 802AA378 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 41F10C 802AA37C E6200138 */  swc1      $f0, 0x138($s1)
/* 41F110 802AA380 E6220140 */  swc1      $f2, 0x140($s1)
/* 41F114 802AA384 8C820000 */  lw        $v0, ($a0)
/* 41F118 802AA388 3C030010 */  lui       $v1, 0x10
/* 41F11C 802AA38C 00431025 */  or        $v0, $v0, $v1
/* 41F120 802AA390 AC820000 */  sw        $v0, ($a0)
glabel L802AA394_41F124
/* 41F124 802AA394 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 41F128 802AA398 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 41F12C 802AA39C 8C620000 */  lw        $v0, ($v1)
/* 41F130 802AA3A0 3C04FBFF */  lui       $a0, 0xfbff
/* 41F134 802AA3A4 34420002 */  ori       $v0, $v0, 2
/* 41F138 802AA3A8 AC620000 */  sw        $v0, ($v1)
/* 41F13C 802AA3AC 8E020000 */  lw        $v0, ($s0)
/* 41F140 802AA3B0 3484FFFF */  ori       $a0, $a0, 0xffff
/* 41F144 802AA3B4 00441024 */  and       $v0, $v0, $a0
/* 41F148 802AA3B8 3C040800 */  lui       $a0, 0x800
/* 41F14C 802AA3BC 00441025 */  or        $v0, $v0, $a0
/* 41F150 802AA3C0 12200006 */  beqz      $s1, .L802AA3DC
/* 41F154 802AA3C4 AE020000 */   sw       $v0, ($s0)
/* 41F158 802AA3C8 8E220000 */  lw        $v0, ($s1)
/* 41F15C 802AA3CC 3C030400 */  lui       $v1, 0x400
/* 41F160 802AA3D0 00431025 */  or        $v0, $v0, $v1
/* 41F164 802AA3D4 00441025 */  or        $v0, $v0, $a0
/* 41F168 802AA3D8 AE220000 */  sw        $v0, ($s1)
.L802AA3DC:
/* 41F16C 802AA3DC 24020008 */  addiu     $v0, $zero, 8
/* 41F170 802AA3E0 3C07802B */  lui       $a3, %hi(battle_menu_isEnabled)
/* 41F174 802AA3E4 24E7D0D0 */  addiu     $a3, $a3, %lo(battle_menu_isEnabled)
/* 41F178 802AA3E8 A640017C */  sh        $zero, 0x17c($s2)
/* 41F17C 802AA3EC 3C01802B */  lui       $at, %hi(battle_menu_submenuIDs)
/* 41F180 802AA3F0 AC22D0B8 */  sw        $v0, %lo(battle_menu_submenuIDs)($at)
/* 41F184 802AA3F4 24020001 */  addiu     $v0, $zero, 1
/* 41F188 802AA3F8 3C08802B */  lui       $t0, %hi(battle_menu_isMessageDisabled)
/* 41F18C 802AA3FC 2508D0E8 */  addiu     $t0, $t0, %lo(battle_menu_isMessageDisabled)
/* 41F190 802AA400 3C06802B */  lui       $a2, %hi(D_802AB72C)
/* 41F194 802AA404 24C6B72C */  addiu     $a2, $a2, %lo(D_802AB72C)
/* 41F198 802AA408 3C05802B */  lui       $a1, %hi(main_battle_menu_iconScripts)
/* 41F19C 802AA40C 24A5D078 */  addiu     $a1, $a1, %lo(main_battle_menu_iconScripts)
/* 41F1A0 802AA410 ACE20000 */  sw        $v0, ($a3)
/* 41F1A4 802AA414 AD000000 */  sw        $zero, ($t0)
/* 41F1A8 802AA418 8CC30000 */  lw        $v1, ($a2)
/* 41F1AC 802AA41C 96420070 */  lhu       $v0, 0x70($s2)
/* 41F1B0 802AA420 3C04802B */  lui       $a0, %hi(D_802AB734)
/* 41F1B4 802AA424 8C84B734 */  lw        $a0, %lo(D_802AB734)($a0)
/* 41F1B8 802AA428 30420100 */  andi      $v0, $v0, 0x100
/* 41F1BC 802AA42C ACA30000 */  sw        $v1, ($a1)
/* 41F1C0 802AA430 3C01802B */  lui       $at, %hi(battle_menu_messageIDs)
/* 41F1C4 802AA434 AC24D090 */  sw        $a0, %lo(battle_menu_messageIDs)($at)
/* 41F1C8 802AA438 14400006 */  bnez      $v0, .L802AA454
/* 41F1CC 802AA43C 0000882D */   daddu    $s1, $zero, $zero
/* 41F1D0 802AA440 ACE00000 */  sw        $zero, ($a3)
/* 41F1D4 802AA444 8CC30004 */  lw        $v1, 4($a2)
/* 41F1D8 802AA448 24020048 */  addiu     $v0, $zero, 0x48
/* 41F1DC 802AA44C AD020000 */  sw        $v0, ($t0)
/* 41F1E0 802AA450 ACA30000 */  sw        $v1, ($a1)
.L802AA454:
/* 41F1E4 802AA454 0C0AA829 */  jal       func_802AA0A4
/* 41F1E8 802AA458 24100001 */   addiu    $s0, $zero, 1
/* 41F1EC 802AA45C 10400005 */  beqz      $v0, .L802AA474
/* 41F1F0 802AA460 24020002 */   addiu    $v0, $zero, 2
/* 41F1F4 802AA464 3C01802B */  lui       $at, %hi(D_802AD104)
/* 41F1F8 802AA468 AC30D104 */  sw        $s0, %lo(D_802AD104)($at)
/* 41F1FC 802AA46C 080AA920 */  j         .L802AA480
/* 41F200 802AA470 00511023 */   subu     $v0, $v0, $s1
.L802AA474:
/* 41F204 802AA474 3C01802B */  lui       $at, %hi(D_802AD104)
/* 41F208 802AA478 AC20D104 */  sw        $zero, %lo(D_802AD104)($at)
/* 41F20C 802AA47C 00511023 */  subu      $v0, $v0, $s1
.L802AA480:
/* 41F210 802AA480 3C01802B */  lui       $at, %hi(main_menu_numOptions)
/* 41F214 802AA484 AC30D0AC */  sw        $s0, %lo(main_menu_numOptions)($at)
/* 41F218 802AA488 3C01802B */  lui       $at, %hi(D_802AD0A8)
/* 41F21C 802AA48C AC20D0A8 */  sw        $zero, %lo(D_802AD0A8)($at)
/* 41F220 802AA490 3C01802B */  lui       $at, %hi(D_802AD0B0)
/* 41F224 802AA494 AC20D0B0 */  sw        $zero, %lo(D_802AD0B0)($at)
/* 41F228 802AA498 3C01802B */  lui       $at, %hi(D_802AD100)
/* 41F22C 802AA49C AC22D100 */  sw        $v0, %lo(D_802AD100)($at)
/* 41F230 802AA4A0 0C0A8400 */  jal       func_802A1000
/* 41F234 802AA4A4 00000000 */   nop
/* 41F238 802AA4A8 24020008 */  addiu     $v0, $zero, 8
/* 41F23C 802AA4AC 3C01802B */  lui       $at, %hi(D_802ACC60)
/* 41F240 802AA4B0 AC22CC60 */  sw        $v0, %lo(D_802ACC60)($at)
/* 41F244 802AA4B4 080AA985 */  j         .L802AA614
/* 41F248 802AA4B8 24020001 */   addiu    $v0, $zero, 1
glabel L802AA4BC_41F24C
/* 41F24C 802AA4BC 24040100 */  addiu     $a0, $zero, 0x100
/* 41F250 802AA4C0 0000282D */  daddu     $a1, $zero, $zero
/* 41F254 802AA4C4 3C060020 */  lui       $a2, 0x20
/* 41F258 802AA4C8 0C098F3F */  jal       set_animation
/* 41F25C 802AA4CC 34C60001 */   ori      $a2, $a2, 1
/* 41F260 802AA4D0 0C0A846C */  jal       func_802A11B0
/* 41F264 802AA4D4 00000000 */   nop
/* 41F268 802AA4D8 3C11802B */  lui       $s1, %hi(D_802ACC60)
/* 41F26C 802AA4DC 2631CC60 */  addiu     $s1, $s1, %lo(D_802ACC60)
/* 41F270 802AA4E0 8E230000 */  lw        $v1, ($s1)
/* 41F274 802AA4E4 10600004 */  beqz      $v1, .L802AA4F8
/* 41F278 802AA4E8 0040802D */   daddu    $s0, $v0, $zero
/* 41F27C 802AA4EC 2462FFFF */  addiu     $v0, $v1, -1
/* 41F280 802AA4F0 080AA987 */  j         L802AA61C_41F3AC
/* 41F284 802AA4F4 AE220000 */   sw       $v0, ($s1)
.L802AA4F8:
/* 41F288 802AA4F8 12000048 */  beqz      $s0, L802AA61C_41F3AC
/* 41F28C 802AA4FC 24040100 */   addiu    $a0, $zero, 0x100
/* 41F290 802AA500 0000282D */  daddu     $a1, $zero, $zero
/* 41F294 802AA504 3C060020 */  lui       $a2, 0x20
/* 41F298 802AA508 0C098F3F */  jal       set_animation
/* 41F29C 802AA50C 34C60008 */   ori      $a2, $a2, 8
/* 41F2A0 802AA510 2602FFFF */  addiu     $v0, $s0, -1
/* 41F2A4 802AA514 00021080 */  sll       $v0, $v0, 2
/* 41F2A8 802AA518 3C01802B */  lui       $at, %hi(D_802AD0BB)
/* 41F2AC 802AA51C 00220821 */  addu      $at, $at, $v0
/* 41F2B0 802AA520 9022D0BB */  lbu       $v0, %lo(D_802AD0BB)($at)
/* 41F2B4 802AA524 0C0A840C */  jal       func_802A1030
/* 41F2B8 802AA528 A2420048 */   sb       $v0, 0x48($s2)
/* 41F2BC 802AA52C 24020008 */  addiu     $v0, $zero, 8
/* 41F2C0 802AA530 AE220000 */  sw        $v0, ($s1)
/* 41F2C4 802AA534 24020004 */  addiu     $v0, $zero, 4
/* 41F2C8 802AA538 3C01802B */  lui       $at, %hi(D_802ACC6C)
/* 41F2CC 802AA53C AC22CC6C */  sw        $v0, %lo(D_802ACC6C)($at)
/* 41F2D0 802AA540 080AA985 */  j         .L802AA614
/* 41F2D4 802AA544 24020002 */   addiu    $v0, $zero, 2
glabel L802AA548_41F2D8
/* 41F2D8 802AA548 0C0A846C */  jal       func_802A11B0
/* 41F2DC 802AA54C 00000000 */   nop
/* 41F2E0 802AA550 10400032 */  beqz      $v0, L802AA61C_41F3AC
/* 41F2E4 802AA554 24040011 */   addiu    $a0, $zero, 0x11
/* 41F2E8 802AA558 24020004 */  addiu     $v0, $zero, 4
/* 41F2EC 802AA55C A642006C */  sh        $v0, 0x6c($s2)
/* 41F2F0 802AA560 24020005 */  addiu     $v0, $zero, 5
/* 41F2F4 802AA564 A642006E */  sh        $v0, 0x6e($s2)
/* 41F2F8 802AA568 24020008 */  addiu     $v0, $zero, 8
/* 41F2FC 802AA56C A2420178 */  sb        $v0, 0x178($s2)
/* 41F300 802AA570 3C038009 */  lui       $v1, %hi(D_8008FA8C)
/* 41F304 802AA574 8C63FA8C */  lw        $v1, %lo(D_8008FA8C)($v1)
/* 41F308 802AA578 24020082 */  addiu     $v0, $zero, 0x82
/* 41F30C 802AA57C A642017C */  sh        $v0, 0x17c($s2)
/* 41F310 802AA580 A640017A */  sh        $zero, 0x17a($s2)
/* 41F314 802AA584 0C090464 */  jal       func_80241190
/* 41F318 802AA588 AE430184 */   sw       $v1, 0x184($s2)
/* 41F31C 802AA58C 080AA987 */  j         L802AA61C_41F3AC
/* 41F320 802AA590 00000000 */   nop
glabel L802AA594_41F324
/* 41F324 802AA594 0C0A8414 */  jal       func_802A1050
/* 41F328 802AA598 00000000 */   nop
/* 41F32C 802AA59C 24020001 */  addiu     $v0, $zero, 1
/* 41F330 802AA5A0 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 41F334 802AA5A4 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 41F338 802AA5A8 0C0AA82E */  jal       func_802AA0B8
/* 41F33C 802AA5AC 00000000 */   nop
/* 41F340 802AA5B0 0C0AA82E */  jal       func_802AA0B8
/* 41F344 802AA5B4 00000000 */   nop
/* 41F348 802AA5B8 080AA987 */  j         L802AA61C_41F3AC
/* 41F34C 802AA5BC 00000000 */   nop
glabel L802AA5C0_41F350
/* 41F350 802AA5C0 0C0A842E */  jal       func_802A10B8
/* 41F354 802AA5C4 00000000 */   nop
/* 41F358 802AA5C8 080AA987 */  j         L802AA61C_41F3AC
/* 41F35C 802AA5CC 00000000 */   nop
glabel L802AA5D0_41F360
/* 41F360 802AA5D0 24040050 */  addiu     $a0, $zero, 0x50
/* 41F364 802AA5D4 2405003C */  addiu     $a1, $zero, 0x3c
/* 41F368 802AA5D8 0C093E81 */  jal       show_variable_battle_message
/* 41F36C 802AA5DC 0000302D */   daddu    $a2, $zero, $zero
/* 41F370 802AA5E0 24020001 */  addiu     $v0, $zero, 1
/* 41F374 802AA5E4 3C01802B */  lui       $at, %hi(D_802AD607)
/* 41F378 802AA5E8 A022D607 */  sb        $v0, %lo(D_802AD607)($at)
/* 41F37C 802AA5EC 080AA985 */  j         .L802AA614
/* 41F380 802AA5F0 24020009 */   addiu    $v0, $zero, 9
glabel L802AA5F4_41F384
/* 41F384 802AA5F4 0C093EAD */  jal       is_popup_displayed
/* 41F388 802AA5F8 00000000 */   nop
/* 41F38C 802AA5FC 14400007 */  bnez      $v0, L802AA61C_41F3AC
/* 41F390 802AA600 24020001 */   addiu    $v0, $zero, 1
/* 41F394 802AA604 3C01802B */  lui       $at, %hi(D_802AD607)
/* 41F398 802AA608 A020D607 */  sb        $zero, %lo(D_802AD607)($at)
/* 41F39C 802AA60C 3C01802B */  lui       $at, %hi(D_802ACC60)
/* 41F3A0 802AA610 AC20CC60 */  sw        $zero, %lo(D_802ACC60)($at)
.L802AA614:
/* 41F3A4 802AA614 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 41F3A8 802AA618 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
glabel L802AA61C_41F3AC
/* 41F3AC 802AA61C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 41F3B0 802AA620 8FB20018 */  lw        $s2, 0x18($sp)
/* 41F3B4 802AA624 8FB10014 */  lw        $s1, 0x14($sp)
/* 41F3B8 802AA628 8FB00010 */  lw        $s0, 0x10($sp)
/* 41F3BC 802AA62C D7B80030 */  ldc1      $f24, 0x30($sp)
/* 41F3C0 802AA630 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 41F3C4 802AA634 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 41F3C8 802AA638 03E00008 */  jr        $ra
/* 41F3CC 802AA63C 27BD0038 */   addiu    $sp, $sp, 0x38
