.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_02_Quizmo_UnkB
/* 8251F0 80241F30 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 8251F4 80241F34 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8251F8 80241F38 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8251FC 80241F3C AFB00018 */  sw        $s0, 0x18($sp)
/* 825200 80241F40 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 825204 80241F44 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 825208 80241F48 10A00060 */  beqz      $a1, .L802420CC
/* 82520C 80241F4C 0080882D */   daddu    $s1, $a0, $zero
/* 825210 80241F50 3C05F4AC */  lui       $a1, 0xf4ac
/* 825214 80241F54 0C0B1EAF */  jal       evt_get_variable
/* 825218 80241F58 34A5D481 */   ori      $a1, $a1, 0xd481
/* 82521C 80241F5C 0220202D */  daddu     $a0, $s1, $zero
/* 825220 80241F60 3C05F4AC */  lui       $a1, 0xf4ac
/* 825224 80241F64 4482B000 */  mtc1      $v0, $f22
/* 825228 80241F68 00000000 */  nop
/* 82522C 80241F6C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 825230 80241F70 0C0B1EAF */  jal       evt_get_variable
/* 825234 80241F74 34A5D482 */   ori      $a1, $a1, 0xd482
/* 825238 80241F78 0220202D */  daddu     $a0, $s1, $zero
/* 82523C 80241F7C 3C05F4AC */  lui       $a1, 0xf4ac
/* 825240 80241F80 4482A000 */  mtc1      $v0, $f20
/* 825244 80241F84 00000000 */  nop
/* 825248 80241F88 4680A520 */  cvt.s.w   $f20, $f20
/* 82524C 80241F8C 0C0B1EAF */  jal       evt_get_variable
/* 825250 80241F90 34A5D483 */   ori      $a1, $a1, 0xd483
/* 825254 80241F94 44821000 */  mtc1      $v0, $f2
/* 825258 80241F98 00000000 */  nop
/* 82525C 80241F9C 468010A0 */  cvt.s.w   $f2, $f2
/* 825260 80241FA0 4405B000 */  mfc1      $a1, $f22
/* 825264 80241FA4 4406A000 */  mfc1      $a2, $f20
/* 825268 80241FA8 44071000 */  mfc1      $a3, $f2
/* 82526C 80241FAC 0C01C574 */  jal       fx_quizmo_stage
/* 825270 80241FB0 0000202D */   daddu    $a0, $zero, $zero
/* 825274 80241FB4 0220202D */  daddu     $a0, $s1, $zero
/* 825278 80241FB8 3C05F4AC */  lui       $a1, 0xf4ac
/* 82527C 80241FBC 34A5D481 */  ori       $a1, $a1, 0xd481
/* 825280 80241FC0 3C108025 */  lui       $s0, %hi(mac_02_Quizmo_StageEffect)
/* 825284 80241FC4 2610E560 */  addiu     $s0, $s0, %lo(mac_02_Quizmo_StageEffect)
/* 825288 80241FC8 0C0B1EAF */  jal       evt_get_variable
/* 82528C 80241FCC AE020000 */   sw       $v0, ($s0)
/* 825290 80241FD0 0220202D */  daddu     $a0, $s1, $zero
/* 825294 80241FD4 3C05F4AC */  lui       $a1, 0xf4ac
/* 825298 80241FD8 4482B000 */  mtc1      $v0, $f22
/* 82529C 80241FDC 00000000 */  nop
/* 8252A0 80241FE0 4680B5A0 */  cvt.s.w   $f22, $f22
/* 8252A4 80241FE4 0C0B1EAF */  jal       evt_get_variable
/* 8252A8 80241FE8 34A5D482 */   ori      $a1, $a1, 0xd482
/* 8252AC 80241FEC 0220202D */  daddu     $a0, $s1, $zero
/* 8252B0 80241FF0 3C05F4AC */  lui       $a1, 0xf4ac
/* 8252B4 80241FF4 4482A000 */  mtc1      $v0, $f20
/* 8252B8 80241FF8 00000000 */  nop
/* 8252BC 80241FFC 4680A520 */  cvt.s.w   $f20, $f20
/* 8252C0 80242000 0C0B1EAF */  jal       evt_get_variable
/* 8252C4 80242004 34A5D483 */   ori      $a1, $a1, 0xd483
/* 8252C8 80242008 44821000 */  mtc1      $v0, $f2
/* 8252CC 8024200C 00000000 */  nop
/* 8252D0 80242010 468010A0 */  cvt.s.w   $f2, $f2
/* 8252D4 80242014 4405B000 */  mfc1      $a1, $f22
/* 8252D8 80242018 4406A000 */  mfc1      $a2, $f20
/* 8252DC 8024201C 44071000 */  mfc1      $a3, $f2
/* 8252E0 80242020 0C01C604 */  jal       fx_quizmo_audience
/* 8252E4 80242024 0000202D */   daddu    $a0, $zero, $zero
/* 8252E8 80242028 0220202D */  daddu     $a0, $s1, $zero
/* 8252EC 8024202C 3C05F4AC */  lui       $a1, 0xf4ac
/* 8252F0 80242030 3C018025 */  lui       $at, %hi(mac_02_Quizmo_AudienceEffect)
/* 8252F4 80242034 AC22E564 */  sw        $v0, %lo(mac_02_Quizmo_AudienceEffect)($at)
/* 8252F8 80242038 0C0B1EAF */  jal       evt_get_variable
/* 8252FC 8024203C 34A5D481 */   ori      $a1, $a1, 0xd481
/* 825300 80242040 0220202D */  daddu     $a0, $s1, $zero
/* 825304 80242044 3C05F4AC */  lui       $a1, 0xf4ac
/* 825308 80242048 4482B000 */  mtc1      $v0, $f22
/* 82530C 8024204C 00000000 */  nop
/* 825310 80242050 4680B5A0 */  cvt.s.w   $f22, $f22
/* 825314 80242054 0C0B1EAF */  jal       evt_get_variable
/* 825318 80242058 34A5D482 */   ori      $a1, $a1, 0xd482
/* 82531C 8024205C 0220202D */  daddu     $a0, $s1, $zero
/* 825320 80242060 3C05F4AC */  lui       $a1, 0xf4ac
/* 825324 80242064 4482A000 */  mtc1      $v0, $f20
/* 825328 80242068 00000000 */  nop
/* 82532C 8024206C 4680A520 */  cvt.s.w   $f20, $f20
/* 825330 80242070 0C0B1EAF */  jal       evt_get_variable
/* 825334 80242074 34A5D483 */   ori      $a1, $a1, 0xd483
/* 825338 80242078 44821000 */  mtc1      $v0, $f2
/* 82533C 8024207C 00000000 */  nop
/* 825340 80242080 468010A0 */  cvt.s.w   $f2, $f2
/* 825344 80242084 4405B000 */  mfc1      $a1, $f22
/* 825348 80242088 4406A000 */  mfc1      $a2, $f20
/* 82534C 8024208C 3C013F80 */  lui       $at, 0x3f80
/* 825350 80242090 44810000 */  mtc1      $at, $f0
/* 825354 80242094 44071000 */  mfc1      $a3, $f2
/* 825358 80242098 0000202D */  daddu     $a0, $zero, $zero
/* 82535C 8024209C AFA00014 */  sw        $zero, 0x14($sp)
/* 825360 802420A0 0C01CA24 */  jal       fx_quizmo_assistant
/* 825364 802420A4 E7A00010 */   swc1     $f0, 0x10($sp)
/* 825368 802420A8 8E030000 */  lw        $v1, ($s0)
/* 82536C 802420AC 8C64000C */  lw        $a0, 0xc($v1)
/* 825370 802420B0 3C018025 */  lui       $at, %hi(mac_02_Quizmo_VannaTEffect)
/* 825374 802420B4 AC22E568 */  sw        $v0, %lo(mac_02_Quizmo_VannaTEffect)($at)
/* 825378 802420B8 AC800018 */  sw        $zero, 0x18($a0)
/* 82537C 802420BC AC800020 */  sw        $zero, 0x20($a0)
/* 825380 802420C0 AC800024 */  sw        $zero, 0x24($a0)
/* 825384 802420C4 AC800028 */  sw        $zero, 0x28($a0)
/* 825388 802420C8 AC80001C */  sw        $zero, 0x1c($a0)
.L802420CC:
/* 82538C 802420CC 3C028025 */  lui       $v0, %hi(mac_02_Quizmo_StageEffect)
/* 825390 802420D0 8C42E560 */  lw        $v0, %lo(mac_02_Quizmo_StageEffect)($v0)
/* 825394 802420D4 8C44000C */  lw        $a0, 0xc($v0)
/* 825398 802420D8 8C820020 */  lw        $v0, 0x20($a0)
/* 82539C 802420DC 8C830028 */  lw        $v1, 0x28($a0)
/* 8253A0 802420E0 2442000A */  addiu     $v0, $v0, 0xa
/* 8253A4 802420E4 AC820020 */  sw        $v0, 0x20($a0)
/* 8253A8 802420E8 8C820024 */  lw        $v0, 0x24($a0)
/* 8253AC 802420EC 2463000A */  addiu     $v1, $v1, 0xa
/* 8253B0 802420F0 AC830028 */  sw        $v1, 0x28($a0)
/* 8253B4 802420F4 8C830018 */  lw        $v1, 0x18($a0)
/* 8253B8 802420F8 2442000A */  addiu     $v0, $v0, 0xa
/* 8253BC 802420FC AC820024 */  sw        $v0, 0x24($a0)
/* 8253C0 80242100 8C82001C */  lw        $v0, 0x1c($a0)
/* 8253C4 80242104 2463000A */  addiu     $v1, $v1, 0xa
/* 8253C8 80242108 AC830018 */  sw        $v1, 0x18($a0)
/* 8253CC 8024210C 286300FF */  slti      $v1, $v1, 0xff
/* 8253D0 80242110 2442000A */  addiu     $v0, $v0, 0xa
/* 8253D4 80242114 AC82001C */  sw        $v0, 0x1c($a0)
/* 8253D8 80242118 14600004 */  bnez      $v1, .L8024212C
/* 8253DC 8024211C 0000102D */   daddu    $v0, $zero, $zero
/* 8253E0 80242120 240200FF */  addiu     $v0, $zero, 0xff
/* 8253E4 80242124 AC820018 */  sw        $v0, 0x18($a0)
/* 8253E8 80242128 24020002 */  addiu     $v0, $zero, 2
.L8024212C:
/* 8253EC 8024212C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8253F0 80242130 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8253F4 80242134 8FB00018 */  lw        $s0, 0x18($sp)
/* 8253F8 80242138 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 8253FC 8024213C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 825400 80242140 03E00008 */  jr        $ra
/* 825404 80242144 27BD0038 */   addiu    $sp, $sp, 0x38
