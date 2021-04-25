.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414D8_9C68B8
/* 9C68B8 802414D8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 9C68BC 802414DC AFB1001C */  sw        $s1, 0x1c($sp)
/* 9C68C0 802414E0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9C68C4 802414E4 AFB00018 */  sw        $s0, 0x18($sp)
/* 9C68C8 802414E8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 9C68CC 802414EC F7B40028 */  sdc1      $f20, 0x28($sp)
/* 9C68D0 802414F0 10A00060 */  beqz      $a1, .L80241674
/* 9C68D4 802414F4 0080882D */   daddu    $s1, $a0, $zero
/* 9C68D8 802414F8 3C05F4AC */  lui       $a1, 0xf4ac
/* 9C68DC 802414FC 0C0B1EAF */  jal       get_variable
/* 9C68E0 80241500 34A5D481 */   ori      $a1, $a1, 0xd481
/* 9C68E4 80241504 0220202D */  daddu     $a0, $s1, $zero
/* 9C68E8 80241508 3C05F4AC */  lui       $a1, 0xf4ac
/* 9C68EC 8024150C 4482B000 */  mtc1      $v0, $f22
/* 9C68F0 80241510 00000000 */  nop
/* 9C68F4 80241514 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9C68F8 80241518 0C0B1EAF */  jal       get_variable
/* 9C68FC 8024151C 34A5D482 */   ori      $a1, $a1, 0xd482
/* 9C6900 80241520 0220202D */  daddu     $a0, $s1, $zero
/* 9C6904 80241524 3C05F4AC */  lui       $a1, 0xf4ac
/* 9C6908 80241528 4482A000 */  mtc1      $v0, $f20
/* 9C690C 8024152C 00000000 */  nop
/* 9C6910 80241530 4680A520 */  cvt.s.w   $f20, $f20
/* 9C6914 80241534 0C0B1EAF */  jal       get_variable
/* 9C6918 80241538 34A5D483 */   ori      $a1, $a1, 0xd483
/* 9C691C 8024153C 44821000 */  mtc1      $v0, $f2
/* 9C6920 80241540 00000000 */  nop
/* 9C6924 80241544 468010A0 */  cvt.s.w   $f2, $f2
/* 9C6928 80241548 4405B000 */  mfc1      $a1, $f22
/* 9C692C 8024154C 4406A000 */  mfc1      $a2, $f20
/* 9C6930 80241550 44071000 */  mfc1      $a3, $f2
/* 9C6934 80241554 0C01C574 */  jal       func_800715D0
/* 9C6938 80241558 0000202D */   daddu    $a0, $zero, $zero
/* 9C693C 8024155C 0220202D */  daddu     $a0, $s1, $zero
/* 9C6940 80241560 3C05F4AC */  lui       $a1, 0xf4ac
/* 9C6944 80241564 34A5D481 */  ori       $a1, $a1, 0xd481
/* 9C6948 80241568 3C108025 */  lui       $s0, %hi(D_80251C60)
/* 9C694C 8024156C 26101C60 */  addiu     $s0, $s0, %lo(D_80251C60)
/* 9C6950 80241570 0C0B1EAF */  jal       get_variable
/* 9C6954 80241574 AE020000 */   sw       $v0, ($s0)
/* 9C6958 80241578 0220202D */  daddu     $a0, $s1, $zero
/* 9C695C 8024157C 3C05F4AC */  lui       $a1, 0xf4ac
/* 9C6960 80241580 4482B000 */  mtc1      $v0, $f22
/* 9C6964 80241584 00000000 */  nop
/* 9C6968 80241588 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9C696C 8024158C 0C0B1EAF */  jal       get_variable
/* 9C6970 80241590 34A5D482 */   ori      $a1, $a1, 0xd482
/* 9C6974 80241594 0220202D */  daddu     $a0, $s1, $zero
/* 9C6978 80241598 3C05F4AC */  lui       $a1, 0xf4ac
/* 9C697C 8024159C 4482A000 */  mtc1      $v0, $f20
/* 9C6980 802415A0 00000000 */  nop
/* 9C6984 802415A4 4680A520 */  cvt.s.w   $f20, $f20
/* 9C6988 802415A8 0C0B1EAF */  jal       get_variable
/* 9C698C 802415AC 34A5D483 */   ori      $a1, $a1, 0xd483
/* 9C6990 802415B0 44821000 */  mtc1      $v0, $f2
/* 9C6994 802415B4 00000000 */  nop
/* 9C6998 802415B8 468010A0 */  cvt.s.w   $f2, $f2
/* 9C699C 802415BC 4405B000 */  mfc1      $a1, $f22
/* 9C69A0 802415C0 4406A000 */  mfc1      $a2, $f20
/* 9C69A4 802415C4 44071000 */  mfc1      $a3, $f2
/* 9C69A8 802415C8 0C01C604 */  jal       func_80071810
/* 9C69AC 802415CC 0000202D */   daddu    $a0, $zero, $zero
/* 9C69B0 802415D0 0220202D */  daddu     $a0, $s1, $zero
/* 9C69B4 802415D4 3C05F4AC */  lui       $a1, 0xf4ac
/* 9C69B8 802415D8 3C018025 */  lui       $at, %hi(dgb_01_D_80251C64_C0F4E4)
/* 9C69BC 802415DC AC221C64 */  sw        $v0, %lo(dgb_01_D_80251C64_C0F4E4)($at)
/* 9C69C0 802415E0 0C0B1EAF */  jal       get_variable
/* 9C69C4 802415E4 34A5D481 */   ori      $a1, $a1, 0xd481
/* 9C69C8 802415E8 0220202D */  daddu     $a0, $s1, $zero
/* 9C69CC 802415EC 3C05F4AC */  lui       $a1, 0xf4ac
/* 9C69D0 802415F0 4482B000 */  mtc1      $v0, $f22
/* 9C69D4 802415F4 00000000 */  nop
/* 9C69D8 802415F8 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9C69DC 802415FC 0C0B1EAF */  jal       get_variable
/* 9C69E0 80241600 34A5D482 */   ori      $a1, $a1, 0xd482
/* 9C69E4 80241604 0220202D */  daddu     $a0, $s1, $zero
/* 9C69E8 80241608 3C05F4AC */  lui       $a1, 0xf4ac
/* 9C69EC 8024160C 4482A000 */  mtc1      $v0, $f20
/* 9C69F0 80241610 00000000 */  nop
/* 9C69F4 80241614 4680A520 */  cvt.s.w   $f20, $f20
/* 9C69F8 80241618 0C0B1EAF */  jal       get_variable
/* 9C69FC 8024161C 34A5D483 */   ori      $a1, $a1, 0xd483
/* 9C6A00 80241620 44821000 */  mtc1      $v0, $f2
/* 9C6A04 80241624 00000000 */  nop
/* 9C6A08 80241628 468010A0 */  cvt.s.w   $f2, $f2
/* 9C6A0C 8024162C 4405B000 */  mfc1      $a1, $f22
/* 9C6A10 80241630 4406A000 */  mfc1      $a2, $f20
/* 9C6A14 80241634 3C013F80 */  lui       $at, 0x3f80
/* 9C6A18 80241638 44810000 */  mtc1      $at, $f0
/* 9C6A1C 8024163C 44071000 */  mfc1      $a3, $f2
/* 9C6A20 80241640 0000202D */  daddu     $a0, $zero, $zero
/* 9C6A24 80241644 AFA00014 */  sw        $zero, 0x14($sp)
/* 9C6A28 80241648 0C01CA24 */  jal       func_80072890
/* 9C6A2C 8024164C E7A00010 */   swc1     $f0, 0x10($sp)
/* 9C6A30 80241650 8E030000 */  lw        $v1, ($s0)
/* 9C6A34 80241654 8C64000C */  lw        $a0, 0xc($v1)
/* 9C6A38 80241658 3C018025 */  lui       $at, %hi(D_80251C68)
/* 9C6A3C 8024165C AC221C68 */  sw        $v0, %lo(D_80251C68)($at)
/* 9C6A40 80241660 AC800018 */  sw        $zero, 0x18($a0)
/* 9C6A44 80241664 AC800020 */  sw        $zero, 0x20($a0)
/* 9C6A48 80241668 AC800024 */  sw        $zero, 0x24($a0)
/* 9C6A4C 8024166C AC800028 */  sw        $zero, 0x28($a0)
/* 9C6A50 80241670 AC80001C */  sw        $zero, 0x1c($a0)
.L80241674:
/* 9C6A54 80241674 3C028025 */  lui       $v0, %hi(D_80251C60)
/* 9C6A58 80241678 8C421C60 */  lw        $v0, %lo(D_80251C60)($v0)
/* 9C6A5C 8024167C 8C44000C */  lw        $a0, 0xc($v0)
/* 9C6A60 80241680 8C820020 */  lw        $v0, 0x20($a0)
/* 9C6A64 80241684 8C830028 */  lw        $v1, 0x28($a0)
/* 9C6A68 80241688 2442000A */  addiu     $v0, $v0, 0xa
/* 9C6A6C 8024168C AC820020 */  sw        $v0, 0x20($a0)
/* 9C6A70 80241690 8C820024 */  lw        $v0, 0x24($a0)
/* 9C6A74 80241694 2463000A */  addiu     $v1, $v1, 0xa
/* 9C6A78 80241698 AC830028 */  sw        $v1, 0x28($a0)
/* 9C6A7C 8024169C 8C830018 */  lw        $v1, 0x18($a0)
/* 9C6A80 802416A0 2442000A */  addiu     $v0, $v0, 0xa
/* 9C6A84 802416A4 AC820024 */  sw        $v0, 0x24($a0)
/* 9C6A88 802416A8 8C82001C */  lw        $v0, 0x1c($a0)
/* 9C6A8C 802416AC 2463000A */  addiu     $v1, $v1, 0xa
/* 9C6A90 802416B0 AC830018 */  sw        $v1, 0x18($a0)
/* 9C6A94 802416B4 286300FF */  slti      $v1, $v1, 0xff
/* 9C6A98 802416B8 2442000A */  addiu     $v0, $v0, 0xa
/* 9C6A9C 802416BC AC82001C */  sw        $v0, 0x1c($a0)
/* 9C6AA0 802416C0 14600004 */  bnez      $v1, .L802416D4
/* 9C6AA4 802416C4 0000102D */   daddu    $v0, $zero, $zero
/* 9C6AA8 802416C8 240200FF */  addiu     $v0, $zero, 0xff
/* 9C6AAC 802416CC AC820018 */  sw        $v0, 0x18($a0)
/* 9C6AB0 802416D0 24020002 */  addiu     $v0, $zero, 2
.L802416D4:
/* 9C6AB4 802416D4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9C6AB8 802416D8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 9C6ABC 802416DC 8FB00018 */  lw        $s0, 0x18($sp)
/* 9C6AC0 802416E0 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 9C6AC4 802416E4 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 9C6AC8 802416E8 03E00008 */  jr        $ra
/* 9C6ACC 802416EC 27BD0038 */   addiu    $sp, $sp, 0x38
