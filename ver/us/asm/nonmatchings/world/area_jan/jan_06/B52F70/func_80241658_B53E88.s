.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80246CF8_B59528
.word L802416D8_B53F08, L802416F0_B53F20, L80241710_B53F40, L80241728_B53F58, L80241764_B53F94, L802417B0_B53FE0

.section .text

glabel func_80241658_B53E88
/* B53E88 80241658 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B53E8C 8024165C AFB20028 */  sw        $s2, 0x28($sp)
/* B53E90 80241660 0080902D */  daddu     $s2, $a0, $zero
/* B53E94 80241664 AFBF002C */  sw        $ra, 0x2c($sp)
/* B53E98 80241668 AFB10024 */  sw        $s1, 0x24($sp)
/* B53E9C 8024166C AFB00020 */  sw        $s0, 0x20($sp)
/* B53EA0 80241670 8E500148 */  lw        $s0, 0x148($s2)
/* B53EA4 80241674 0C00EABB */  jal       get_npc_unsafe
/* B53EA8 80241678 86040008 */   lh       $a0, 8($s0)
/* B53EAC 8024167C 8E03006C */  lw        $v1, 0x6c($s0)
/* B53EB0 80241680 1460000B */  bnez      $v1, .L802416B0
/* B53EB4 80241684 0040882D */   daddu    $s1, $v0, $zero
/* B53EB8 80241688 0C00A67F */  jal       rand_int
/* B53EBC 8024168C 24040064 */   addiu    $a0, $zero, 0x64
/* B53EC0 80241690 28420032 */  slti      $v0, $v0, 0x32
/* B53EC4 80241694 14400002 */  bnez      $v0, .L802416A0
/* B53EC8 80241698 24020001 */   addiu    $v0, $zero, 1
/* B53ECC 8024169C 24020003 */  addiu     $v0, $zero, 3
.L802416A0:
/* B53ED0 802416A0 AE02006C */  sw        $v0, 0x6c($s0)
/* B53ED4 802416A4 3C054387 */  lui       $a1, 0x4387
/* B53ED8 802416A8 0C00ECD0 */  jal       set_npc_yaw
/* B53EDC 802416AC 0220202D */   daddu    $a0, $s1, $zero
.L802416B0:
/* B53EE0 802416B0 8E02006C */  lw        $v0, 0x6c($s0)
/* B53EE4 802416B4 2443FFFF */  addiu     $v1, $v0, -1
/* B53EE8 802416B8 2C620006 */  sltiu     $v0, $v1, 6
/* B53EEC 802416BC 1040004D */  beqz      $v0, .L802417F4
/* B53EF0 802416C0 00031080 */   sll      $v0, $v1, 2
/* B53EF4 802416C4 3C018024 */  lui       $at, %hi(jtbl_80246CF8_B59528)
/* B53EF8 802416C8 00220821 */  addu      $at, $at, $v0
/* B53EFC 802416CC 8C226CF8 */  lw        $v0, %lo(jtbl_80246CF8_B59528)($at)
/* B53F00 802416D0 00400008 */  jr        $v0
/* B53F04 802416D4 00000000 */   nop
glabel L802416D8_B53F08
/* B53F08 802416D8 3C030042 */  lui       $v1, 0x42
/* B53F0C 802416DC 3463000F */  ori       $v1, $v1, 0xf
/* B53F10 802416E0 24020002 */  addiu     $v0, $zero, 2
/* B53F14 802416E4 AE02006C */  sw        $v0, 0x6c($s0)
/* B53F18 802416E8 AE000070 */  sw        $zero, 0x70($s0)
/* B53F1C 802416EC AE230028 */  sw        $v1, 0x28($s1)
glabel L802416F0_B53F20
/* B53F20 802416F0 8E020070 */  lw        $v0, 0x70($s0)
/* B53F24 802416F4 24420001 */  addiu     $v0, $v0, 1
/* B53F28 802416F8 AE020070 */  sw        $v0, 0x70($s0)
/* B53F2C 802416FC 28420033 */  slti      $v0, $v0, 0x33
/* B53F30 80241700 1440003C */  bnez      $v0, .L802417F4
/* B53F34 80241704 24020005 */   addiu    $v0, $zero, 5
/* B53F38 80241708 080905FD */  j         .L802417F4
/* B53F3C 8024170C AE02006C */   sw       $v0, 0x6c($s0)
glabel L80241710_B53F40
/* B53F40 80241710 3C030042 */  lui       $v1, 0x42
/* B53F44 80241714 34630010 */  ori       $v1, $v1, 0x10
/* B53F48 80241718 24020004 */  addiu     $v0, $zero, 4
/* B53F4C 8024171C AE02006C */  sw        $v0, 0x6c($s0)
/* B53F50 80241720 AE000070 */  sw        $zero, 0x70($s0)
/* B53F54 80241724 AE230028 */  sw        $v1, 0x28($s1)
glabel L80241728_B53F58
/* B53F58 80241728 8E020070 */  lw        $v0, 0x70($s0)
/* B53F5C 8024172C 24030019 */  addiu     $v1, $zero, 0x19
/* B53F60 80241730 24420001 */  addiu     $v0, $v0, 1
/* B53F64 80241734 14430005 */  bne       $v0, $v1, .L8024174C
/* B53F68 80241738 AE020070 */   sw       $v0, 0x70($s0)
/* B53F6C 8024173C 3C0142B4 */  lui       $at, 0x42b4
/* B53F70 80241740 44810000 */  mtc1      $at, $f0
/* B53F74 80241744 00000000 */  nop
/* B53F78 80241748 E620000C */  swc1      $f0, 0xc($s1)
.L8024174C:
/* B53F7C 8024174C 8E020070 */  lw        $v0, 0x70($s0)
/* B53F80 80241750 2842003D */  slti      $v0, $v0, 0x3d
/* B53F84 80241754 14400027 */  bnez      $v0, .L802417F4
/* B53F88 80241758 24020005 */   addiu    $v0, $zero, 5
/* B53F8C 8024175C 080905FD */  j         .L802417F4
/* B53F90 80241760 AE02006C */   sw       $v0, 0x6c($s0)
glabel L80241764_B53F94
/* B53F94 80241764 3C030042 */  lui       $v1, 0x42
/* B53F98 80241768 24020006 */  addiu     $v0, $zero, 6
/* B53F9C 8024176C 34630003 */  ori       $v1, $v1, 3
/* B53FA0 80241770 AE02006C */  sw        $v0, 0x6c($s0)
/* B53FA4 80241774 AE000070 */  sw        $zero, 0x70($s0)
/* B53FA8 80241778 862400A8 */  lh        $a0, 0xa8($s1)
/* B53FAC 8024177C 2402000A */  addiu     $v0, $zero, 0xa
/* B53FB0 80241780 AE230028 */  sw        $v1, 0x28($s1)
/* B53FB4 80241784 AFA00014 */  sw        $zero, 0x14($sp)
/* B53FB8 80241788 AFA20018 */  sw        $v0, 0x18($sp)
/* B53FBC 8024178C 44840000 */  mtc1      $a0, $f0
/* B53FC0 80241790 00000000 */  nop
/* B53FC4 80241794 46800020 */  cvt.s.w   $f0, $f0
/* B53FC8 80241798 E7A00010 */  swc1      $f0, 0x10($sp)
/* B53FCC 8024179C 8E250038 */  lw        $a1, 0x38($s1)
/* B53FD0 802417A0 8E26003C */  lw        $a2, 0x3c($s1)
/* B53FD4 802417A4 8E270040 */  lw        $a3, 0x40($s1)
/* B53FD8 802417A8 0C01C1E4 */  jal       fx_sweat
/* B53FDC 802417AC 0000202D */   daddu    $a0, $zero, $zero
glabel L802417B0_B53FE0
/* B53FE0 802417B0 8E020070 */  lw        $v0, 0x70($s0)
/* B53FE4 802417B4 24420001 */  addiu     $v0, $v0, 1
/* B53FE8 802417B8 AE020070 */  sw        $v0, 0x70($s0)
/* B53FEC 802417BC 2842000B */  slti      $v0, $v0, 0xb
/* B53FF0 802417C0 1440000C */  bnez      $v0, .L802417F4
/* B53FF4 802417C4 00000000 */   nop
/* B53FF8 802417C8 0C00A67F */  jal       rand_int
/* B53FFC 802417CC 24040064 */   addiu    $a0, $zero, 0x64
/* B54000 802417D0 0040182D */  daddu     $v1, $v0, $zero
/* B54004 802417D4 2862005A */  slti      $v0, $v1, 0x5a
/* B54008 802417D8 14400005 */  bnez      $v0, .L802417F0
/* B5400C 802417DC 24020007 */   addiu    $v0, $zero, 7
/* B54010 802417E0 2862005F */  slti      $v0, $v1, 0x5f
/* B54014 802417E4 14400002 */  bnez      $v0, .L802417F0
/* B54018 802417E8 24020001 */   addiu    $v0, $zero, 1
/* B5401C 802417EC 24020003 */  addiu     $v0, $zero, 3
.L802417F0:
/* B54020 802417F0 AE02006C */  sw        $v0, 0x6c($s0)
.L802417F4:
/* B54024 802417F4 8E03006C */  lw        $v1, 0x6c($s0)
/* B54028 802417F8 24020007 */  addiu     $v0, $zero, 7
/* B5402C 802417FC 50620001 */  beql      $v1, $v0, .L80241804
/* B54030 80241800 AE400070 */   sw       $zero, 0x70($s2)
.L80241804:
/* B54034 80241804 8FBF002C */  lw        $ra, 0x2c($sp)
/* B54038 80241808 8FB20028 */  lw        $s2, 0x28($sp)
/* B5403C 8024180C 8FB10024 */  lw        $s1, 0x24($sp)
/* B54040 80241810 8FB00020 */  lw        $s0, 0x20($sp)
/* B54044 80241814 03E00008 */  jr        $ra
/* B54048 80241818 27BD0030 */   addiu    $sp, $sp, 0x30
