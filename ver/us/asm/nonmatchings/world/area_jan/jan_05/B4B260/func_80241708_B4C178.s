.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80247A78_B524E8
.word L80241788_B4C1F8, L802417A0_B4C210, L802417C0_B4C230, L802417D8_B4C248, L80241814_B4C284, L80241860_B4C2D0

.section .text

glabel func_80241708_B4C178
/* B4C178 80241708 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B4C17C 8024170C AFB20028 */  sw        $s2, 0x28($sp)
/* B4C180 80241710 0080902D */  daddu     $s2, $a0, $zero
/* B4C184 80241714 AFBF002C */  sw        $ra, 0x2c($sp)
/* B4C188 80241718 AFB10024 */  sw        $s1, 0x24($sp)
/* B4C18C 8024171C AFB00020 */  sw        $s0, 0x20($sp)
/* B4C190 80241720 8E500148 */  lw        $s0, 0x148($s2)
/* B4C194 80241724 0C00EABB */  jal       get_npc_unsafe
/* B4C198 80241728 86040008 */   lh       $a0, 8($s0)
/* B4C19C 8024172C 8E03006C */  lw        $v1, 0x6c($s0)
/* B4C1A0 80241730 1460000B */  bnez      $v1, .L80241760
/* B4C1A4 80241734 0040882D */   daddu    $s1, $v0, $zero
/* B4C1A8 80241738 0C00A67F */  jal       rand_int
/* B4C1AC 8024173C 24040064 */   addiu    $a0, $zero, 0x64
/* B4C1B0 80241740 28420032 */  slti      $v0, $v0, 0x32
/* B4C1B4 80241744 14400002 */  bnez      $v0, .L80241750
/* B4C1B8 80241748 24020001 */   addiu    $v0, $zero, 1
/* B4C1BC 8024174C 24020003 */  addiu     $v0, $zero, 3
.L80241750:
/* B4C1C0 80241750 AE02006C */  sw        $v0, 0x6c($s0)
/* B4C1C4 80241754 3C054387 */  lui       $a1, 0x4387
/* B4C1C8 80241758 0C00ECD0 */  jal       set_npc_yaw
/* B4C1CC 8024175C 0220202D */   daddu    $a0, $s1, $zero
.L80241760:
/* B4C1D0 80241760 8E02006C */  lw        $v0, 0x6c($s0)
/* B4C1D4 80241764 2443FFFF */  addiu     $v1, $v0, -1
/* B4C1D8 80241768 2C620006 */  sltiu     $v0, $v1, 6
/* B4C1DC 8024176C 1040004D */  beqz      $v0, .L802418A4
/* B4C1E0 80241770 00031080 */   sll      $v0, $v1, 2
/* B4C1E4 80241774 3C018024 */  lui       $at, %hi(jtbl_80247A78_B524E8)
/* B4C1E8 80241778 00220821 */  addu      $at, $at, $v0
/* B4C1EC 8024177C 8C227A78 */  lw        $v0, %lo(jtbl_80247A78_B524E8)($at)
/* B4C1F0 80241780 00400008 */  jr        $v0
/* B4C1F4 80241784 00000000 */   nop
glabel L80241788_B4C1F8
/* B4C1F8 80241788 3C030042 */  lui       $v1, 0x42
/* B4C1FC 8024178C 3463000F */  ori       $v1, $v1, 0xf
/* B4C200 80241790 24020002 */  addiu     $v0, $zero, 2
/* B4C204 80241794 AE02006C */  sw        $v0, 0x6c($s0)
/* B4C208 80241798 AE000070 */  sw        $zero, 0x70($s0)
/* B4C20C 8024179C AE230028 */  sw        $v1, 0x28($s1)
glabel L802417A0_B4C210
/* B4C210 802417A0 8E020070 */  lw        $v0, 0x70($s0)
/* B4C214 802417A4 24420001 */  addiu     $v0, $v0, 1
/* B4C218 802417A8 AE020070 */  sw        $v0, 0x70($s0)
/* B4C21C 802417AC 28420033 */  slti      $v0, $v0, 0x33
/* B4C220 802417B0 1440003C */  bnez      $v0, .L802418A4
/* B4C224 802417B4 24020005 */   addiu    $v0, $zero, 5
/* B4C228 802417B8 08090629 */  j         .L802418A4
/* B4C22C 802417BC AE02006C */   sw       $v0, 0x6c($s0)
glabel L802417C0_B4C230
/* B4C230 802417C0 3C030042 */  lui       $v1, 0x42
/* B4C234 802417C4 34630010 */  ori       $v1, $v1, 0x10
/* B4C238 802417C8 24020004 */  addiu     $v0, $zero, 4
/* B4C23C 802417CC AE02006C */  sw        $v0, 0x6c($s0)
/* B4C240 802417D0 AE000070 */  sw        $zero, 0x70($s0)
/* B4C244 802417D4 AE230028 */  sw        $v1, 0x28($s1)
glabel L802417D8_B4C248
/* B4C248 802417D8 8E020070 */  lw        $v0, 0x70($s0)
/* B4C24C 802417DC 24030019 */  addiu     $v1, $zero, 0x19
/* B4C250 802417E0 24420001 */  addiu     $v0, $v0, 1
/* B4C254 802417E4 14430005 */  bne       $v0, $v1, .L802417FC
/* B4C258 802417E8 AE020070 */   sw       $v0, 0x70($s0)
/* B4C25C 802417EC 3C0142B4 */  lui       $at, 0x42b4
/* B4C260 802417F0 44810000 */  mtc1      $at, $f0
/* B4C264 802417F4 00000000 */  nop
/* B4C268 802417F8 E620000C */  swc1      $f0, 0xc($s1)
.L802417FC:
/* B4C26C 802417FC 8E020070 */  lw        $v0, 0x70($s0)
/* B4C270 80241800 2842003D */  slti      $v0, $v0, 0x3d
/* B4C274 80241804 14400027 */  bnez      $v0, .L802418A4
/* B4C278 80241808 24020005 */   addiu    $v0, $zero, 5
/* B4C27C 8024180C 08090629 */  j         .L802418A4
/* B4C280 80241810 AE02006C */   sw       $v0, 0x6c($s0)
glabel L80241814_B4C284
/* B4C284 80241814 3C030042 */  lui       $v1, 0x42
/* B4C288 80241818 24020006 */  addiu     $v0, $zero, 6
/* B4C28C 8024181C 34630003 */  ori       $v1, $v1, 3
/* B4C290 80241820 AE02006C */  sw        $v0, 0x6c($s0)
/* B4C294 80241824 AE000070 */  sw        $zero, 0x70($s0)
/* B4C298 80241828 862400A8 */  lh        $a0, 0xa8($s1)
/* B4C29C 8024182C 2402000A */  addiu     $v0, $zero, 0xa
/* B4C2A0 80241830 AE230028 */  sw        $v1, 0x28($s1)
/* B4C2A4 80241834 AFA00014 */  sw        $zero, 0x14($sp)
/* B4C2A8 80241838 AFA20018 */  sw        $v0, 0x18($sp)
/* B4C2AC 8024183C 44840000 */  mtc1      $a0, $f0
/* B4C2B0 80241840 00000000 */  nop
/* B4C2B4 80241844 46800020 */  cvt.s.w   $f0, $f0
/* B4C2B8 80241848 E7A00010 */  swc1      $f0, 0x10($sp)
/* B4C2BC 8024184C 8E250038 */  lw        $a1, 0x38($s1)
/* B4C2C0 80241850 8E26003C */  lw        $a2, 0x3c($s1)
/* B4C2C4 80241854 8E270040 */  lw        $a3, 0x40($s1)
/* B4C2C8 80241858 0C01C1E4 */  jal       fx_sweat
/* B4C2CC 8024185C 0000202D */   daddu    $a0, $zero, $zero
glabel L80241860_B4C2D0
/* B4C2D0 80241860 8E020070 */  lw        $v0, 0x70($s0)
/* B4C2D4 80241864 24420001 */  addiu     $v0, $v0, 1
/* B4C2D8 80241868 AE020070 */  sw        $v0, 0x70($s0)
/* B4C2DC 8024186C 2842000B */  slti      $v0, $v0, 0xb
/* B4C2E0 80241870 1440000C */  bnez      $v0, .L802418A4
/* B4C2E4 80241874 00000000 */   nop
/* B4C2E8 80241878 0C00A67F */  jal       rand_int
/* B4C2EC 8024187C 24040064 */   addiu    $a0, $zero, 0x64
/* B4C2F0 80241880 0040182D */  daddu     $v1, $v0, $zero
/* B4C2F4 80241884 2862005A */  slti      $v0, $v1, 0x5a
/* B4C2F8 80241888 14400005 */  bnez      $v0, .L802418A0
/* B4C2FC 8024188C 24020007 */   addiu    $v0, $zero, 7
/* B4C300 80241890 2862005F */  slti      $v0, $v1, 0x5f
/* B4C304 80241894 14400002 */  bnez      $v0, .L802418A0
/* B4C308 80241898 24020001 */   addiu    $v0, $zero, 1
/* B4C30C 8024189C 24020003 */  addiu     $v0, $zero, 3
.L802418A0:
/* B4C310 802418A0 AE02006C */  sw        $v0, 0x6c($s0)
.L802418A4:
/* B4C314 802418A4 8E03006C */  lw        $v1, 0x6c($s0)
/* B4C318 802418A8 24020007 */  addiu     $v0, $zero, 7
/* B4C31C 802418AC 50620001 */  beql      $v1, $v0, .L802418B4
/* B4C320 802418B0 AE400070 */   sw       $zero, 0x70($s2)
.L802418B4:
/* B4C324 802418B4 8FBF002C */  lw        $ra, 0x2c($sp)
/* B4C328 802418B8 8FB20028 */  lw        $s2, 0x28($sp)
/* B4C32C 802418BC 8FB10024 */  lw        $s1, 0x24($sp)
/* B4C330 802418C0 8FB00020 */  lw        $s0, 0x20($sp)
/* B4C334 802418C4 03E00008 */  jr        $ra
/* B4C338 802418C8 27BD0030 */   addiu    $sp, $sp, 0x30
