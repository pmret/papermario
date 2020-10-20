.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C20
/* 832420 80240C20 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 832424 80240C24 AFB1001C */  sw        $s1, 0x1c($sp)
/* 832428 80240C28 AFBF0020 */  sw        $ra, 0x20($sp)
/* 83242C 80240C2C AFB00018 */  sw        $s0, 0x18($sp)
/* 832430 80240C30 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 832434 80240C34 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 832438 80240C38 10A00060 */  beqz      $a1, .L80240DBC
/* 83243C 80240C3C 0080882D */   daddu    $s1, $a0, $zero
/* 832440 80240C40 3C05F4AC */  lui       $a1, 0xf4ac
/* 832444 80240C44 0C0B1EAF */  jal       get_variable
/* 832448 80240C48 34A5D481 */   ori      $a1, $a1, 0xd481
/* 83244C 80240C4C 0220202D */  daddu     $a0, $s1, $zero
/* 832450 80240C50 3C05F4AC */  lui       $a1, 0xf4ac
/* 832454 80240C54 4482B000 */  mtc1      $v0, $f22
/* 832458 80240C58 00000000 */  nop       
/* 83245C 80240C5C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 832460 80240C60 0C0B1EAF */  jal       get_variable
/* 832464 80240C64 34A5D482 */   ori      $a1, $a1, 0xd482
/* 832468 80240C68 0220202D */  daddu     $a0, $s1, $zero
/* 83246C 80240C6C 3C05F4AC */  lui       $a1, 0xf4ac
/* 832470 80240C70 4482A000 */  mtc1      $v0, $f20
/* 832474 80240C74 00000000 */  nop       
/* 832478 80240C78 4680A520 */  cvt.s.w   $f20, $f20
/* 83247C 80240C7C 0C0B1EAF */  jal       get_variable
/* 832480 80240C80 34A5D483 */   ori      $a1, $a1, 0xd483
/* 832484 80240C84 44821000 */  mtc1      $v0, $f2
/* 832488 80240C88 00000000 */  nop       
/* 83248C 80240C8C 468010A0 */  cvt.s.w   $f2, $f2
/* 832490 80240C90 4405B000 */  mfc1      $a1, $f22
/* 832494 80240C94 4406A000 */  mfc1      $a2, $f20
/* 832498 80240C98 44071000 */  mfc1      $a3, $f2
/* 83249C 80240C9C 0C01C574 */  jal       func_800715D0
/* 8324A0 80240CA0 0000202D */   daddu    $a0, $zero, $zero
/* 8324A4 80240CA4 0220202D */  daddu     $a0, $s1, $zero
/* 8324A8 80240CA8 3C05F4AC */  lui       $a1, 0xf4ac
/* 8324AC 80240CAC 34A5D481 */  ori       $a1, $a1, 0xd481
/* 8324B0 80240CB0 3C108025 */  lui       $s0, %hi(ForceCloseMessageBox)
/* 8324B4 80240CB4 261013F0 */  addiu     $s0, $s0, %lo(ForceCloseMessageBox)
/* 8324B8 80240CB8 0C0B1EAF */  jal       get_variable
/* 8324BC 80240CBC AE020000 */   sw       $v0, ($s0)
/* 8324C0 80240CC0 0220202D */  daddu     $a0, $s1, $zero
/* 8324C4 80240CC4 3C05F4AC */  lui       $a1, 0xf4ac
/* 8324C8 80240CC8 4482B000 */  mtc1      $v0, $f22
/* 8324CC 80240CCC 00000000 */  nop       
/* 8324D0 80240CD0 4680B5A0 */  cvt.s.w   $f22, $f22
/* 8324D4 80240CD4 0C0B1EAF */  jal       get_variable
/* 8324D8 80240CD8 34A5D482 */   ori      $a1, $a1, 0xd482
/* 8324DC 80240CDC 0220202D */  daddu     $a0, $s1, $zero
/* 8324E0 80240CE0 3C05F4AC */  lui       $a1, 0xf4ac
/* 8324E4 80240CE4 4482A000 */  mtc1      $v0, $f20
/* 8324E8 80240CE8 00000000 */  nop       
/* 8324EC 80240CEC 4680A520 */  cvt.s.w   $f20, $f20
/* 8324F0 80240CF0 0C0B1EAF */  jal       get_variable
/* 8324F4 80240CF4 34A5D483 */   ori      $a1, $a1, 0xd483
/* 8324F8 80240CF8 44821000 */  mtc1      $v0, $f2
/* 8324FC 80240CFC 00000000 */  nop       
/* 832500 80240D00 468010A0 */  cvt.s.w   $f2, $f2
/* 832504 80240D04 4405B000 */  mfc1      $a1, $f22
/* 832508 80240D08 4406A000 */  mfc1      $a2, $f20
/* 83250C 80240D0C 44071000 */  mfc1      $a3, $f2
/* 832510 80240D10 0C01C604 */  jal       func_80071810
/* 832514 80240D14 0000202D */   daddu    $a0, $zero, $zero
/* 832518 80240D18 0220202D */  daddu     $a0, $s1, $zero
/* 83251C 80240D1C 3C05F4AC */  lui       $a1, 0xf4ac
/* 832520 80240D20 3C018025 */  lui       $at, 0x8025
/* 832524 80240D24 AC2213F4 */  sw        $v0, 0x13f4($at)
/* 832528 80240D28 0C0B1EAF */  jal       get_variable
/* 83252C 80240D2C 34A5D481 */   ori      $a1, $a1, 0xd481
/* 832530 80240D30 0220202D */  daddu     $a0, $s1, $zero
/* 832534 80240D34 3C05F4AC */  lui       $a1, 0xf4ac
/* 832538 80240D38 4482B000 */  mtc1      $v0, $f22
/* 83253C 80240D3C 00000000 */  nop       
/* 832540 80240D40 4680B5A0 */  cvt.s.w   $f22, $f22
/* 832544 80240D44 0C0B1EAF */  jal       get_variable
/* 832548 80240D48 34A5D482 */   ori      $a1, $a1, 0xd482
/* 83254C 80240D4C 0220202D */  daddu     $a0, $s1, $zero
/* 832550 80240D50 3C05F4AC */  lui       $a1, 0xf4ac
/* 832554 80240D54 4482A000 */  mtc1      $v0, $f20
/* 832558 80240D58 00000000 */  nop       
/* 83255C 80240D5C 4680A520 */  cvt.s.w   $f20, $f20
/* 832560 80240D60 0C0B1EAF */  jal       get_variable
/* 832564 80240D64 34A5D483 */   ori      $a1, $a1, 0xd483
/* 832568 80240D68 44821000 */  mtc1      $v0, $f2
/* 83256C 80240D6C 00000000 */  nop       
/* 832570 80240D70 468010A0 */  cvt.s.w   $f2, $f2
/* 832574 80240D74 4405B000 */  mfc1      $a1, $f22
/* 832578 80240D78 4406A000 */  mfc1      $a2, $f20
/* 83257C 80240D7C 3C013F80 */  lui       $at, 0x3f80
/* 832580 80240D80 44810000 */  mtc1      $at, $f0
/* 832584 80240D84 44071000 */  mfc1      $a3, $f2
/* 832588 80240D88 0000202D */  daddu     $a0, $zero, $zero
/* 83258C 80240D8C AFA00014 */  sw        $zero, 0x14($sp)
/* 832590 80240D90 0C01CA24 */  jal       func_80072890
/* 832594 80240D94 E7A00010 */   swc1     $f0, 0x10($sp)
/* 832598 80240D98 8E030000 */  lw        $v1, ($s0)
/* 83259C 80240D9C 8C64000C */  lw        $a0, 0xc($v1)
/* 8325A0 80240DA0 3C018025 */  lui       $at, 0x8025
/* 8325A4 80240DA4 AC2213F8 */  sw        $v0, 0x13f8($at)
/* 8325A8 80240DA8 AC800018 */  sw        $zero, 0x18($a0)
/* 8325AC 80240DAC AC800020 */  sw        $zero, 0x20($a0)
/* 8325B0 80240DB0 AC800024 */  sw        $zero, 0x24($a0)
/* 8325B4 80240DB4 AC800028 */  sw        $zero, 0x28($a0)
/* 8325B8 80240DB8 AC80001C */  sw        $zero, 0x1c($a0)
.L80240DBC:
/* 8325BC 80240DBC 3C028025 */  lui       $v0, %hi(ForceCloseMessageBox)
/* 8325C0 80240DC0 8C4213F0 */  lw        $v0, %lo(ForceCloseMessageBox)($v0)
/* 8325C4 80240DC4 8C44000C */  lw        $a0, 0xc($v0)
/* 8325C8 80240DC8 8C820020 */  lw        $v0, 0x20($a0)
/* 8325CC 80240DCC 8C830028 */  lw        $v1, 0x28($a0)
/* 8325D0 80240DD0 2442000A */  addiu     $v0, $v0, 0xa
/* 8325D4 80240DD4 AC820020 */  sw        $v0, 0x20($a0)
/* 8325D8 80240DD8 8C820024 */  lw        $v0, 0x24($a0)
/* 8325DC 80240DDC 2463000A */  addiu     $v1, $v1, 0xa
/* 8325E0 80240DE0 AC830028 */  sw        $v1, 0x28($a0)
/* 8325E4 80240DE4 8C830018 */  lw        $v1, 0x18($a0)
/* 8325E8 80240DE8 2442000A */  addiu     $v0, $v0, 0xa
/* 8325EC 80240DEC AC820024 */  sw        $v0, 0x24($a0)
/* 8325F0 80240DF0 8C82001C */  lw        $v0, 0x1c($a0)
/* 8325F4 80240DF4 2463000A */  addiu     $v1, $v1, 0xa
/* 8325F8 80240DF8 AC830018 */  sw        $v1, 0x18($a0)
/* 8325FC 80240DFC 286300FF */  slti      $v1, $v1, 0xff
/* 832600 80240E00 2442000A */  addiu     $v0, $v0, 0xa
/* 832604 80240E04 AC82001C */  sw        $v0, 0x1c($a0)
/* 832608 80240E08 14600004 */  bnez      $v1, .L80240E1C
/* 83260C 80240E0C 0000102D */   daddu    $v0, $zero, $zero
/* 832610 80240E10 240200FF */  addiu     $v0, $zero, 0xff
/* 832614 80240E14 AC820018 */  sw        $v0, 0x18($a0)
/* 832618 80240E18 24020002 */  addiu     $v0, $zero, 2
.L80240E1C:
/* 83261C 80240E1C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 832620 80240E20 8FB1001C */  lw        $s1, 0x1c($sp)
/* 832624 80240E24 8FB00018 */  lw        $s0, 0x18($sp)
/* 832628 80240E28 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 83262C 80240E2C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 832630 80240E30 03E00008 */  jr        $ra
/* 832634 80240E34 27BD0038 */   addiu    $sp, $sp, 0x38
