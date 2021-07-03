.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80246568_C8C018
.double 0.8

.section .text

glabel func_80241D30_C877E0
/* C877E0 80241D30 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C877E4 80241D34 AFB3001C */  sw        $s3, 0x1c($sp)
/* C877E8 80241D38 0080982D */  daddu     $s3, $a0, $zero
/* C877EC 80241D3C AFBF0020 */  sw        $ra, 0x20($sp)
/* C877F0 80241D40 AFB20018 */  sw        $s2, 0x18($sp)
/* C877F4 80241D44 AFB10014 */  sw        $s1, 0x14($sp)
/* C877F8 80241D48 AFB00010 */  sw        $s0, 0x10($sp)
/* C877FC 80241D4C 8E710148 */  lw        $s1, 0x148($s3)
/* C87800 80241D50 86240008 */  lh        $a0, 8($s1)
/* C87804 80241D54 0C00EABB */  jal       get_npc_unsafe
/* C87808 80241D58 00A0902D */   daddu    $s2, $a1, $zero
/* C8780C 80241D5C 0040802D */  daddu     $s0, $v0, $zero
/* C87810 80241D60 8602008E */  lh        $v0, 0x8e($s0)
/* C87814 80241D64 9603008E */  lhu       $v1, 0x8e($s0)
/* C87818 80241D68 18400005 */  blez      $v0, .L80241D80
/* C8781C 80241D6C 2462FFFF */   addiu    $v0, $v1, -1
/* C87820 80241D70 A602008E */  sh        $v0, 0x8e($s0)
/* C87824 80241D74 00021400 */  sll       $v0, $v0, 0x10
/* C87828 80241D78 1C400033 */  bgtz      $v0, .L80241E48
/* C8782C 80241D7C 00000000 */   nop
.L80241D80:
/* C87830 80241D80 8602008C */  lh        $v0, 0x8c($s0)
/* C87834 80241D84 14400030 */  bnez      $v0, .L80241E48
/* C87838 80241D88 00000000 */   nop
/* C8783C 80241D8C 8E2200CC */  lw        $v0, 0xcc($s1)
/* C87840 80241D90 8C420024 */  lw        $v0, 0x24($v0)
/* C87844 80241D94 AE020028 */  sw        $v0, 0x28($s0)
/* C87848 80241D98 C6400018 */  lwc1      $f0, 0x18($s2)
/* C8784C 80241D9C E6000018 */  swc1      $f0, 0x18($s0)
/* C87850 80241DA0 8E230088 */  lw        $v1, 0x88($s1)
/* C87854 80241DA4 24020005 */  addiu     $v0, $zero, 5
/* C87858 80241DA8 10620005 */  beq       $v1, $v0, .L80241DC0
/* C8785C 80241DAC 00000000 */   nop
/* C87860 80241DB0 10600003 */  beqz      $v1, .L80241DC0
/* C87864 80241DB4 24020001 */   addiu    $v0, $zero, 1
/* C87868 80241DB8 14620006 */  bne       $v1, $v0, .L80241DD4
/* C8786C 80241DBC 00000000 */   nop
.L80241DC0:
/* C87870 80241DC0 8E220084 */  lw        $v0, 0x84($s1)
/* C87874 80241DC4 00021FC2 */  srl       $v1, $v0, 0x1f
/* C87878 80241DC8 00431021 */  addu      $v0, $v0, $v1
/* C8787C 80241DCC 00021043 */  sra       $v0, $v0, 1
/* C87880 80241DD0 A60200A8 */  sh        $v0, 0xa8($s0)
.L80241DD4:
/* C87884 80241DD4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C87888 80241DD8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C8788C 80241DDC C60C0038 */  lwc1      $f12, 0x38($s0)
/* C87890 80241DE0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C87894 80241DE4 8C460028 */  lw        $a2, 0x28($v0)
/* C87898 80241DE8 0C00A7B5 */  jal       dist2D
/* C8789C 80241DEC 8C470030 */   lw       $a3, 0x30($v0)
/* C878A0 80241DF0 C6020018 */  lwc1      $f2, 0x18($s0)
/* C878A4 80241DF4 46020003 */  div.s     $f0, $f0, $f2
/* C878A8 80241DF8 3C018024 */  lui       $at, %hi(D_80246568_C8C018)
/* C878AC 80241DFC D4226568 */  ldc1      $f2, %lo(D_80246568_C8C018)($at)
/* C878B0 80241E00 46000021 */  cvt.d.s   $f0, $f0
/* C878B4 80241E04 46220000 */  add.d     $f0, $f0, $f2
/* C878B8 80241E08 4620010D */  trunc.w.d $f4, $f0
/* C878BC 80241E0C 44022000 */  mfc1      $v0, $f4
/* C878C0 80241E10 00000000 */  nop
/* C878C4 80241E14 A602008E */  sh        $v0, 0x8e($s0)
/* C878C8 80241E18 00021400 */  sll       $v0, $v0, 0x10
/* C878CC 80241E1C 8E230078 */  lw        $v1, 0x78($s1)
/* C878D0 80241E20 00021403 */  sra       $v0, $v0, 0x10
/* C878D4 80241E24 0043102A */  slt       $v0, $v0, $v1
/* C878D8 80241E28 10400003 */  beqz      $v0, .L80241E38
/* C878DC 80241E2C 00000000 */   nop
/* C878E0 80241E30 9622007A */  lhu       $v0, 0x7a($s1)
/* C878E4 80241E34 A602008E */  sh        $v0, 0x8e($s0)
.L80241E38:
/* C878E8 80241E38 8602008E */  lh        $v0, 0x8e($s0)
/* C878EC 80241E3C AE22007C */  sw        $v0, 0x7c($s1)
/* C878F0 80241E40 2402000E */  addiu     $v0, $zero, 0xe
/* C878F4 80241E44 AE620070 */  sw        $v0, 0x70($s3)
.L80241E48:
/* C878F8 80241E48 8FBF0020 */  lw        $ra, 0x20($sp)
/* C878FC 80241E4C 8FB3001C */  lw        $s3, 0x1c($sp)
/* C87900 80241E50 8FB20018 */  lw        $s2, 0x18($sp)
/* C87904 80241E54 8FB10014 */  lw        $s1, 0x14($sp)
/* C87908 80241E58 8FB00010 */  lw        $s0, 0x10($sp)
/* C8790C 80241E5C 03E00008 */  jr        $ra
/* C87910 80241E60 27BD0028 */   addiu    $sp, $sp, 0x28
