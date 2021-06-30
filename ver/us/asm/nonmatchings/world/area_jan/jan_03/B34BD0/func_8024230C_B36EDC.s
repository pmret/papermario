.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024230C_B36EDC
/* B36EDC 8024230C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* B36EE0 80242310 AFB1001C */  sw        $s1, 0x1c($sp)
/* B36EE4 80242314 AFBF0020 */  sw        $ra, 0x20($sp)
/* B36EE8 80242318 AFB00018 */  sw        $s0, 0x18($sp)
/* B36EEC 8024231C F7B60030 */  sdc1      $f22, 0x30($sp)
/* B36EF0 80242320 F7B40028 */  sdc1      $f20, 0x28($sp)
/* B36EF4 80242324 10A00060 */  beqz      $a1, .L802424A8
/* B36EF8 80242328 0080882D */   daddu    $s1, $a0, $zero
/* B36EFC 8024232C 3C05F4AC */  lui       $a1, 0xf4ac
/* B36F00 80242330 0C0B1EAF */  jal       get_variable
/* B36F04 80242334 34A5D481 */   ori      $a1, $a1, 0xd481
/* B36F08 80242338 0220202D */  daddu     $a0, $s1, $zero
/* B36F0C 8024233C 3C05F4AC */  lui       $a1, 0xf4ac
/* B36F10 80242340 4482B000 */  mtc1      $v0, $f22
/* B36F14 80242344 00000000 */  nop
/* B36F18 80242348 4680B5A0 */  cvt.s.w   $f22, $f22
/* B36F1C 8024234C 0C0B1EAF */  jal       get_variable
/* B36F20 80242350 34A5D482 */   ori      $a1, $a1, 0xd482
/* B36F24 80242354 0220202D */  daddu     $a0, $s1, $zero
/* B36F28 80242358 3C05F4AC */  lui       $a1, 0xf4ac
/* B36F2C 8024235C 4482A000 */  mtc1      $v0, $f20
/* B36F30 80242360 00000000 */  nop
/* B36F34 80242364 4680A520 */  cvt.s.w   $f20, $f20
/* B36F38 80242368 0C0B1EAF */  jal       get_variable
/* B36F3C 8024236C 34A5D483 */   ori      $a1, $a1, 0xd483
/* B36F40 80242370 44821000 */  mtc1      $v0, $f2
/* B36F44 80242374 00000000 */  nop
/* B36F48 80242378 468010A0 */  cvt.s.w   $f2, $f2
/* B36F4C 8024237C 4405B000 */  mfc1      $a1, $f22
/* B36F50 80242380 4406A000 */  mfc1      $a2, $f20
/* B36F54 80242384 44071000 */  mfc1      $a3, $f2
/* B36F58 80242388 0C01C574 */  jal       playFX_4E
/* B36F5C 8024238C 0000202D */   daddu    $a0, $zero, $zero
/* B36F60 80242390 0220202D */  daddu     $a0, $s1, $zero
/* B36F64 80242394 3C05F4AC */  lui       $a1, 0xf4ac
/* B36F68 80242398 34A5D481 */  ori       $a1, $a1, 0xd481
/* B36F6C 8024239C 3C108025 */  lui       $s0, %hi(D_8024FEF8)
/* B36F70 802423A0 2610FEF8 */  addiu     $s0, $s0, %lo(D_8024FEF8)
/* B36F74 802423A4 0C0B1EAF */  jal       get_variable
/* B36F78 802423A8 AE020000 */   sw       $v0, ($s0)
/* B36F7C 802423AC 0220202D */  daddu     $a0, $s1, $zero
/* B36F80 802423B0 3C05F4AC */  lui       $a1, 0xf4ac
/* B36F84 802423B4 4482B000 */  mtc1      $v0, $f22
/* B36F88 802423B8 00000000 */  nop
/* B36F8C 802423BC 4680B5A0 */  cvt.s.w   $f22, $f22
/* B36F90 802423C0 0C0B1EAF */  jal       get_variable
/* B36F94 802423C4 34A5D482 */   ori      $a1, $a1, 0xd482
/* B36F98 802423C8 0220202D */  daddu     $a0, $s1, $zero
/* B36F9C 802423CC 3C05F4AC */  lui       $a1, 0xf4ac
/* B36FA0 802423D0 4482A000 */  mtc1      $v0, $f20
/* B36FA4 802423D4 00000000 */  nop
/* B36FA8 802423D8 4680A520 */  cvt.s.w   $f20, $f20
/* B36FAC 802423DC 0C0B1EAF */  jal       get_variable
/* B36FB0 802423E0 34A5D483 */   ori      $a1, $a1, 0xd483
/* B36FB4 802423E4 44821000 */  mtc1      $v0, $f2
/* B36FB8 802423E8 00000000 */  nop
/* B36FBC 802423EC 468010A0 */  cvt.s.w   $f2, $f2
/* B36FC0 802423F0 4405B000 */  mfc1      $a1, $f22
/* B36FC4 802423F4 4406A000 */  mfc1      $a2, $f20
/* B36FC8 802423F8 44071000 */  mfc1      $a3, $f2
/* B36FCC 802423FC 0C01C604 */  jal       playFX_54
/* B36FD0 80242400 0000202D */   daddu    $a0, $zero, $zero
/* B36FD4 80242404 0220202D */  daddu     $a0, $s1, $zero
/* B36FD8 80242408 3C05F4AC */  lui       $a1, 0xf4ac
/* B36FDC 8024240C 3C018025 */  lui       $at, %hi(D_8024FEFC)
/* B36FE0 80242410 AC22FEFC */  sw        $v0, %lo(D_8024FEFC)($at)
/* B36FE4 80242414 0C0B1EAF */  jal       get_variable
/* B36FE8 80242418 34A5D481 */   ori      $a1, $a1, 0xd481
/* B36FEC 8024241C 0220202D */  daddu     $a0, $s1, $zero
/* B36FF0 80242420 3C05F4AC */  lui       $a1, 0xf4ac
/* B36FF4 80242424 4482B000 */  mtc1      $v0, $f22
/* B36FF8 80242428 00000000 */  nop
/* B36FFC 8024242C 4680B5A0 */  cvt.s.w   $f22, $f22
/* B37000 80242430 0C0B1EAF */  jal       get_variable
/* B37004 80242434 34A5D482 */   ori      $a1, $a1, 0xd482
/* B37008 80242438 0220202D */  daddu     $a0, $s1, $zero
/* B3700C 8024243C 3C05F4AC */  lui       $a1, 0xf4ac
/* B37010 80242440 4482A000 */  mtc1      $v0, $f20
/* B37014 80242444 00000000 */  nop
/* B37018 80242448 4680A520 */  cvt.s.w   $f20, $f20
/* B3701C 8024244C 0C0B1EAF */  jal       get_variable
/* B37020 80242450 34A5D483 */   ori      $a1, $a1, 0xd483
/* B37024 80242454 44821000 */  mtc1      $v0, $f2
/* B37028 80242458 00000000 */  nop
/* B3702C 8024245C 468010A0 */  cvt.s.w   $f2, $f2
/* B37030 80242460 4405B000 */  mfc1      $a1, $f22
/* B37034 80242464 4406A000 */  mfc1      $a2, $f20
/* B37038 80242468 3C013F80 */  lui       $at, 0x3f80
/* B3703C 8024246C 44810000 */  mtc1      $at, $f0
/* B37040 80242470 44071000 */  mfc1      $a3, $f2
/* B37044 80242474 0000202D */  daddu     $a0, $zero, $zero
/* B37048 80242478 AFA00014 */  sw        $zero, 0x14($sp)
/* B3704C 8024247C 0C01CA24 */  jal       playFX_80
/* B37050 80242480 E7A00010 */   swc1     $f0, 0x10($sp)
/* B37054 80242484 8E030000 */  lw        $v1, ($s0)
/* B37058 80242488 8C64000C */  lw        $a0, 0xc($v1)
/* B3705C 8024248C 3C018025 */  lui       $at, %hi(D_8024FF00)
/* B37060 80242490 AC22FF00 */  sw        $v0, %lo(D_8024FF00)($at)
/* B37064 80242494 AC800018 */  sw        $zero, 0x18($a0)
/* B37068 80242498 AC800020 */  sw        $zero, 0x20($a0)
/* B3706C 8024249C AC800024 */  sw        $zero, 0x24($a0)
/* B37070 802424A0 AC800028 */  sw        $zero, 0x28($a0)
/* B37074 802424A4 AC80001C */  sw        $zero, 0x1c($a0)
.L802424A8:
/* B37078 802424A8 3C028025 */  lui       $v0, %hi(D_8024FEF8)
/* B3707C 802424AC 8C42FEF8 */  lw        $v0, %lo(D_8024FEF8)($v0)
/* B37080 802424B0 8C44000C */  lw        $a0, 0xc($v0)
/* B37084 802424B4 8C820020 */  lw        $v0, 0x20($a0)
/* B37088 802424B8 8C830028 */  lw        $v1, 0x28($a0)
/* B3708C 802424BC 2442000A */  addiu     $v0, $v0, 0xa
/* B37090 802424C0 AC820020 */  sw        $v0, 0x20($a0)
/* B37094 802424C4 8C820024 */  lw        $v0, 0x24($a0)
/* B37098 802424C8 2463000A */  addiu     $v1, $v1, 0xa
/* B3709C 802424CC AC830028 */  sw        $v1, 0x28($a0)
/* B370A0 802424D0 8C830018 */  lw        $v1, 0x18($a0)
/* B370A4 802424D4 2442000A */  addiu     $v0, $v0, 0xa
/* B370A8 802424D8 AC820024 */  sw        $v0, 0x24($a0)
/* B370AC 802424DC 8C82001C */  lw        $v0, 0x1c($a0)
/* B370B0 802424E0 2463000A */  addiu     $v1, $v1, 0xa
/* B370B4 802424E4 AC830018 */  sw        $v1, 0x18($a0)
/* B370B8 802424E8 286300FF */  slti      $v1, $v1, 0xff
/* B370BC 802424EC 2442000A */  addiu     $v0, $v0, 0xa
/* B370C0 802424F0 AC82001C */  sw        $v0, 0x1c($a0)
/* B370C4 802424F4 14600004 */  bnez      $v1, .L80242508
/* B370C8 802424F8 0000102D */   daddu    $v0, $zero, $zero
/* B370CC 802424FC 240200FF */  addiu     $v0, $zero, 0xff
/* B370D0 80242500 AC820018 */  sw        $v0, 0x18($a0)
/* B370D4 80242504 24020002 */  addiu     $v0, $zero, 2
.L80242508:
/* B370D8 80242508 8FBF0020 */  lw        $ra, 0x20($sp)
/* B370DC 8024250C 8FB1001C */  lw        $s1, 0x1c($sp)
/* B370E0 80242510 8FB00018 */  lw        $s0, 0x18($sp)
/* B370E4 80242514 D7B60030 */  ldc1      $f22, 0x30($sp)
/* B370E8 80242518 D7B40028 */  ldc1      $f20, 0x28($sp)
/* B370EC 8024251C 03E00008 */  jr        $ra
/* B370F0 80242520 27BD0038 */   addiu    $sp, $sp, 0x38
