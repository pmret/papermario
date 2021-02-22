.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414A4_B5F754
/* B5F754 802414A4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B5F758 802414A8 AFB20028 */  sw        $s2, 0x28($sp)
/* B5F75C 802414AC 0080902D */  daddu     $s2, $a0, $zero
/* B5F760 802414B0 AFBF002C */  sw        $ra, 0x2c($sp)
/* B5F764 802414B4 AFB10024 */  sw        $s1, 0x24($sp)
/* B5F768 802414B8 AFB00020 */  sw        $s0, 0x20($sp)
/* B5F76C 802414BC 8E500148 */  lw        $s0, 0x148($s2)
/* B5F770 802414C0 0C00EABB */  jal       get_npc_unsafe
/* B5F774 802414C4 86040008 */   lh       $a0, 8($s0)
/* B5F778 802414C8 8E03006C */  lw        $v1, 0x6c($s0)
/* B5F77C 802414CC 1460000B */  bnez      $v1, .L802414FC
/* B5F780 802414D0 0040882D */   daddu    $s1, $v0, $zero
/* B5F784 802414D4 0C00A67F */  jal       rand_int
/* B5F788 802414D8 24040064 */   addiu    $a0, $zero, 0x64
/* B5F78C 802414DC 28420032 */  slti      $v0, $v0, 0x32
/* B5F790 802414E0 14400002 */  bnez      $v0, .L802414EC
/* B5F794 802414E4 24020001 */   addiu    $v0, $zero, 1
/* B5F798 802414E8 24020003 */  addiu     $v0, $zero, 3
.L802414EC:
/* B5F79C 802414EC AE02006C */  sw        $v0, 0x6c($s0)
/* B5F7A0 802414F0 3C054387 */  lui       $a1, 0x4387
/* B5F7A4 802414F4 0C00ECD0 */  jal       set_npc_yaw
/* B5F7A8 802414F8 0220202D */   daddu    $a0, $s1, $zero
.L802414FC:
/* B5F7AC 802414FC 8E02006C */  lw        $v0, 0x6c($s0)
/* B5F7B0 80241500 2443FFFF */  addiu     $v1, $v0, -1
/* B5F7B4 80241504 2C620006 */  sltiu     $v0, $v1, 6
/* B5F7B8 80241508 1040004D */  beqz      $v0, .L80241640
/* B5F7BC 8024150C 00031080 */   sll      $v0, $v1, 2
/* B5F7C0 80241510 3C018024 */  lui       $at, %hi(jtbl_802474C0_B65770)
/* B5F7C4 80241514 00220821 */  addu      $at, $at, $v0
/* B5F7C8 80241518 8C2274C0 */  lw        $v0, %lo(jtbl_802474C0_B65770)($at)
/* B5F7CC 8024151C 00400008 */  jr        $v0
/* B5F7D0 80241520 00000000 */   nop
glabel L80241524_B5F7D4
/* B5F7D4 80241524 3C030042 */  lui       $v1, 0x42
/* B5F7D8 80241528 3463000F */  ori       $v1, $v1, 0xf
/* B5F7DC 8024152C 24020002 */  addiu     $v0, $zero, 2
/* B5F7E0 80241530 AE02006C */  sw        $v0, 0x6c($s0)
/* B5F7E4 80241534 AE000070 */  sw        $zero, 0x70($s0)
/* B5F7E8 80241538 AE230028 */  sw        $v1, 0x28($s1)
glabel L8024153C_B5F7EC
/* B5F7EC 8024153C 8E020070 */  lw        $v0, 0x70($s0)
/* B5F7F0 80241540 24420001 */  addiu     $v0, $v0, 1
/* B5F7F4 80241544 AE020070 */  sw        $v0, 0x70($s0)
/* B5F7F8 80241548 28420033 */  slti      $v0, $v0, 0x33
/* B5F7FC 8024154C 1440003C */  bnez      $v0, .L80241640
/* B5F800 80241550 24020005 */   addiu    $v0, $zero, 5
/* B5F804 80241554 08090590 */  j         .L80241640
/* B5F808 80241558 AE02006C */   sw       $v0, 0x6c($s0)
glabel L8024155C_B5F80C
/* B5F80C 8024155C 3C030042 */  lui       $v1, 0x42
/* B5F810 80241560 34630010 */  ori       $v1, $v1, 0x10
/* B5F814 80241564 24020004 */  addiu     $v0, $zero, 4
/* B5F818 80241568 AE02006C */  sw        $v0, 0x6c($s0)
/* B5F81C 8024156C AE000070 */  sw        $zero, 0x70($s0)
/* B5F820 80241570 AE230028 */  sw        $v1, 0x28($s1)
glabel L80241574_B5F824
/* B5F824 80241574 8E020070 */  lw        $v0, 0x70($s0)
/* B5F828 80241578 24030019 */  addiu     $v1, $zero, 0x19
/* B5F82C 8024157C 24420001 */  addiu     $v0, $v0, 1
/* B5F830 80241580 14430005 */  bne       $v0, $v1, .L80241598
/* B5F834 80241584 AE020070 */   sw       $v0, 0x70($s0)
/* B5F838 80241588 3C0142B4 */  lui       $at, 0x42b4
/* B5F83C 8024158C 44810000 */  mtc1      $at, $f0
/* B5F840 80241590 00000000 */  nop
/* B5F844 80241594 E620000C */  swc1      $f0, 0xc($s1)
.L80241598:
/* B5F848 80241598 8E020070 */  lw        $v0, 0x70($s0)
/* B5F84C 8024159C 2842003D */  slti      $v0, $v0, 0x3d
/* B5F850 802415A0 14400027 */  bnez      $v0, .L80241640
/* B5F854 802415A4 24020005 */   addiu    $v0, $zero, 5
/* B5F858 802415A8 08090590 */  j         .L80241640
/* B5F85C 802415AC AE02006C */   sw       $v0, 0x6c($s0)
glabel L802415B0_B5F860
/* B5F860 802415B0 3C030042 */  lui       $v1, 0x42
/* B5F864 802415B4 24020006 */  addiu     $v0, $zero, 6
/* B5F868 802415B8 34630003 */  ori       $v1, $v1, 3
/* B5F86C 802415BC AE02006C */  sw        $v0, 0x6c($s0)
/* B5F870 802415C0 AE000070 */  sw        $zero, 0x70($s0)
/* B5F874 802415C4 862400A8 */  lh        $a0, 0xa8($s1)
/* B5F878 802415C8 2402000A */  addiu     $v0, $zero, 0xa
/* B5F87C 802415CC AE230028 */  sw        $v1, 0x28($s1)
/* B5F880 802415D0 AFA00014 */  sw        $zero, 0x14($sp)
/* B5F884 802415D4 AFA20018 */  sw        $v0, 0x18($sp)
/* B5F888 802415D8 44840000 */  mtc1      $a0, $f0
/* B5F88C 802415DC 00000000 */  nop
/* B5F890 802415E0 46800020 */  cvt.s.w   $f0, $f0
/* B5F894 802415E4 E7A00010 */  swc1      $f0, 0x10($sp)
/* B5F898 802415E8 8E250038 */  lw        $a1, 0x38($s1)
/* B5F89C 802415EC 8E26003C */  lw        $a2, 0x3c($s1)
/* B5F8A0 802415F0 8E270040 */  lw        $a3, 0x40($s1)
/* B5F8A4 802415F4 0C01C1E4 */  jal       fx_sweat
/* B5F8A8 802415F8 0000202D */   daddu    $a0, $zero, $zero
glabel L802415FC_B5F8AC
/* B5F8AC 802415FC 8E020070 */  lw        $v0, 0x70($s0)
/* B5F8B0 80241600 24420001 */  addiu     $v0, $v0, 1
/* B5F8B4 80241604 AE020070 */  sw        $v0, 0x70($s0)
/* B5F8B8 80241608 2842000B */  slti      $v0, $v0, 0xb
/* B5F8BC 8024160C 1440000C */  bnez      $v0, .L80241640
/* B5F8C0 80241610 00000000 */   nop
/* B5F8C4 80241614 0C00A67F */  jal       rand_int
/* B5F8C8 80241618 24040064 */   addiu    $a0, $zero, 0x64
/* B5F8CC 8024161C 0040182D */  daddu     $v1, $v0, $zero
/* B5F8D0 80241620 2862005A */  slti      $v0, $v1, 0x5a
/* B5F8D4 80241624 14400005 */  bnez      $v0, .L8024163C
/* B5F8D8 80241628 24020007 */   addiu    $v0, $zero, 7
/* B5F8DC 8024162C 2862005F */  slti      $v0, $v1, 0x5f
/* B5F8E0 80241630 14400002 */  bnez      $v0, .L8024163C
/* B5F8E4 80241634 24020001 */   addiu    $v0, $zero, 1
/* B5F8E8 80241638 24020003 */  addiu     $v0, $zero, 3
.L8024163C:
/* B5F8EC 8024163C AE02006C */  sw        $v0, 0x6c($s0)
.L80241640:
/* B5F8F0 80241640 8E03006C */  lw        $v1, 0x6c($s0)
/* B5F8F4 80241644 24020007 */  addiu     $v0, $zero, 7
/* B5F8F8 80241648 50620001 */  beql      $v1, $v0, .L80241650
/* B5F8FC 8024164C AE400070 */   sw       $zero, 0x70($s2)
.L80241650:
/* B5F900 80241650 8FBF002C */  lw        $ra, 0x2c($sp)
/* B5F904 80241654 8FB20028 */  lw        $s2, 0x28($sp)
/* B5F908 80241658 8FB10024 */  lw        $s1, 0x24($sp)
/* B5F90C 8024165C 8FB00020 */  lw        $s0, 0x20($sp)
/* B5F910 80241660 03E00008 */  jr        $ra
/* B5F914 80241664 27BD0030 */   addiu    $sp, $sp, 0x30
