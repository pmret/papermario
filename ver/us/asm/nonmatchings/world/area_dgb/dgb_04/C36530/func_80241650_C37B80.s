.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241650_C37B80
/* C37B80 80241650 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C37B84 80241654 AFB30024 */  sw        $s3, 0x24($sp)
/* C37B88 80241658 0080982D */  daddu     $s3, $a0, $zero
/* C37B8C 8024165C AFBF0028 */  sw        $ra, 0x28($sp)
/* C37B90 80241660 AFB20020 */  sw        $s2, 0x20($sp)
/* C37B94 80241664 AFB1001C */  sw        $s1, 0x1c($sp)
/* C37B98 80241668 AFB00018 */  sw        $s0, 0x18($sp)
/* C37B9C 8024166C 8E700148 */  lw        $s0, 0x148($s3)
/* C37BA0 80241670 00A0902D */  daddu     $s2, $a1, $zero
/* C37BA4 80241674 86040008 */  lh        $a0, 8($s0)
/* C37BA8 80241678 0C00EABB */  jal       get_npc_unsafe
/* C37BAC 8024167C 00C0882D */   daddu    $s1, $a2, $zero
/* C37BB0 80241680 0220202D */  daddu     $a0, $s1, $zero
/* C37BB4 80241684 0200282D */  daddu     $a1, $s0, $zero
/* C37BB8 80241688 24030001 */  addiu     $v1, $zero, 1
/* C37BBC 8024168C AFA30010 */  sw        $v1, 0x10($sp)
/* C37BC0 80241690 8E460024 */  lw        $a2, 0x24($s2)
/* C37BC4 80241694 8E470028 */  lw        $a3, 0x28($s2)
/* C37BC8 80241698 0C01242D */  jal       func_800490B4
/* C37BCC 8024169C 0040802D */   daddu    $s0, $v0, $zero
/* C37BD0 802416A0 10400024 */  beqz      $v0, .L80241734
/* C37BD4 802416A4 24020010 */   addiu    $v0, $zero, 0x10
/* C37BD8 802416A8 8E050018 */  lw        $a1, 0x18($s0)
/* C37BDC 802416AC 8E06000C */  lw        $a2, 0xc($s0)
/* C37BE0 802416B0 0C00EA95 */  jal       npc_move_heading
/* C37BE4 802416B4 0200202D */   daddu    $a0, $s0, $zero
/* C37BE8 802416B8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C37BEC 802416BC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C37BF0 802416C0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C37BF4 802416C4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C37BF8 802416C8 8C460028 */  lw        $a2, 0x28($v0)
/* C37BFC 802416CC 0C00A7B5 */  jal       dist2D
/* C37C00 802416D0 8C470030 */   lw       $a3, 0x30($v0)
/* C37C04 802416D4 C6020018 */  lwc1      $f2, 0x18($s0)
/* C37C08 802416D8 3C014004 */  lui       $at, 0x4004
/* C37C0C 802416DC 44812800 */  mtc1      $at, $f5
/* C37C10 802416E0 44802000 */  mtc1      $zero, $f4
/* C37C14 802416E4 460010A1 */  cvt.d.s   $f2, $f2
/* C37C18 802416E8 46241082 */  mul.d     $f2, $f2, $f4
/* C37C1C 802416EC 00000000 */  nop
/* C37C20 802416F0 46000021 */  cvt.d.s   $f0, $f0
/* C37C24 802416F4 4622003E */  c.le.d    $f0, $f2
/* C37C28 802416F8 00000000 */  nop
/* C37C2C 802416FC 45000003 */  bc1f      .L8024170C
/* C37C30 80241700 2402000E */   addiu    $v0, $zero, 0xe
/* C37C34 80241704 080905CD */  j         .L80241734
/* C37C38 80241708 A600008E */   sh       $zero, 0x8e($s0)
.L8024170C:
/* C37C3C 8024170C 9602008E */  lhu       $v0, 0x8e($s0)
/* C37C40 80241710 2442FFFF */  addiu     $v0, $v0, -1
/* C37C44 80241714 A602008E */  sh        $v0, 0x8e($s0)
/* C37C48 80241718 00021400 */  sll       $v0, $v0, 0x10
/* C37C4C 8024171C 1C400006 */  bgtz      $v0, .L80241738
/* C37C50 80241720 3C030020 */   lui      $v1, 0x20
/* C37C54 80241724 8E020000 */  lw        $v0, ($s0)
/* C37C58 80241728 00431025 */  or        $v0, $v0, $v1
/* C37C5C 8024172C AE020000 */  sw        $v0, ($s0)
/* C37C60 80241730 2402000C */  addiu     $v0, $zero, 0xc
.L80241734:
/* C37C64 80241734 AE620070 */  sw        $v0, 0x70($s3)
.L80241738:
/* C37C68 80241738 8FBF0028 */  lw        $ra, 0x28($sp)
/* C37C6C 8024173C 8FB30024 */  lw        $s3, 0x24($sp)
/* C37C70 80241740 8FB20020 */  lw        $s2, 0x20($sp)
/* C37C74 80241744 8FB1001C */  lw        $s1, 0x1c($sp)
/* C37C78 80241748 8FB00018 */  lw        $s0, 0x18($sp)
/* C37C7C 8024174C 03E00008 */  jr        $ra
/* C37C80 80241750 27BD0030 */   addiu    $sp, $sp, 0x30
