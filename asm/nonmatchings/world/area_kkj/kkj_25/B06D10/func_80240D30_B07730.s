.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D30_B07730
/* B07730 80240D30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B07734 80240D34 AFB00010 */  sw        $s0, 0x10($sp)
/* B07738 80240D38 0080802D */  daddu     $s0, $a0, $zero
/* B0773C 80240D3C 10A00003 */  beqz      $a1, .L80240D4C
/* B07740 80240D40 AFBF0014 */   sw       $ra, 0x14($sp)
/* B07744 80240D44 AE000074 */  sw        $zero, 0x74($s0)
/* B07748 80240D48 AE000078 */  sw        $zero, 0x78($s0)
.L80240D4C:
/* B0774C 80240D4C 8E030078 */  lw        $v1, 0x78($s0)
/* B07750 80240D50 10600005 */  beqz      $v1, .L80240D68
/* B07754 80240D54 24020001 */   addiu    $v0, $zero, 1
/* B07758 80240D58 10620015 */  beq       $v1, $v0, .L80240DB0
/* B0775C 80240D5C 3C048080 */   lui      $a0, 0x8080
/* B07760 80240D60 0809038D */  j         .L80240E34
/* B07764 80240D64 00000000 */   nop
.L80240D68:
/* B07768 80240D68 0000202D */  daddu     $a0, $zero, $zero
/* B0776C 80240D6C 240500D0 */  addiu     $a1, $zero, 0xd0
/* B07770 80240D70 0080302D */  daddu     $a2, $a0, $zero
/* B07774 80240D74 0C04DF84 */  jal       set_transition_stencil_color
/* B07778 80240D78 0080382D */   daddu    $a3, $a0, $zero
/* B0777C 80240D7C C6000074 */  lwc1      $f0, 0x74($s0)
/* B07780 80240D80 46800020 */  cvt.s.w   $f0, $f0
/* B07784 80240D84 44050000 */  mfc1      $a1, $f0
/* B07788 80240D88 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* B0778C 80240D8C 24040001 */   addiu    $a0, $zero, 1
/* B07790 80240D90 8E020074 */  lw        $v0, 0x74($s0)
/* B07794 80240D94 240300FF */  addiu     $v1, $zero, 0xff
/* B07798 80240D98 14430022 */  bne       $v0, $v1, .L80240E24
/* B0779C 80240D9C 24420007 */   addiu    $v0, $v0, 7
/* B077A0 80240DA0 24020001 */  addiu     $v0, $zero, 1
/* B077A4 80240DA4 AE000074 */  sw        $zero, 0x74($s0)
/* B077A8 80240DA8 0809038D */  j         .L80240E34
/* B077AC 80240DAC AE020078 */   sw       $v0, 0x78($s0)
.L80240DB0:
/* B077B0 80240DB0 8E030074 */  lw        $v1, 0x74($s0)
/* B077B4 80240DB4 34848081 */  ori       $a0, $a0, 0x8081
/* B077B8 80240DB8 00031040 */  sll       $v0, $v1, 1
/* B077BC 80240DBC 00431021 */  addu      $v0, $v0, $v1
/* B077C0 80240DC0 00021080 */  sll       $v0, $v0, 2
/* B077C4 80240DC4 00431021 */  addu      $v0, $v0, $v1
/* B077C8 80240DC8 00021100 */  sll       $v0, $v0, 4
/* B077CC 80240DCC 00440018 */  mult      $v0, $a0
/* B077D0 80240DD0 240500D0 */  addiu     $a1, $zero, 0xd0
/* B077D4 80240DD4 0000202D */  daddu     $a0, $zero, $zero
/* B077D8 80240DD8 00004010 */  mfhi      $t0
/* B077DC 80240DDC 01023021 */  addu      $a2, $t0, $v0
/* B077E0 80240DE0 000631C3 */  sra       $a2, $a2, 7
/* B077E4 80240DE4 000217C3 */  sra       $v0, $v0, 0x1f
/* B077E8 80240DE8 00C23023 */  subu      $a2, $a2, $v0
/* B077EC 80240DEC 30C600FF */  andi      $a2, $a2, 0xff
/* B077F0 80240DF0 0C04DF84 */  jal       set_transition_stencil_color
/* B077F4 80240DF4 00C0382D */   daddu    $a3, $a2, $zero
/* B077F8 80240DF8 3C05437F */  lui       $a1, 0x437f
/* B077FC 80240DFC 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* B07800 80240E00 24040001 */   addiu    $a0, $zero, 1
/* B07804 80240E04 8E020074 */  lw        $v0, 0x74($s0)
/* B07808 80240E08 240300FF */  addiu     $v1, $zero, 0xff
/* B0780C 80240E0C 14430005 */  bne       $v0, $v1, .L80240E24
/* B07810 80240E10 2442000E */   addiu    $v0, $v0, 0xe
/* B07814 80240E14 24020002 */  addiu     $v0, $zero, 2
/* B07818 80240E18 AE020078 */  sw        $v0, 0x78($s0)
/* B0781C 80240E1C 8E020074 */  lw        $v0, 0x74($s0)
/* B07820 80240E20 2442000E */  addiu     $v0, $v0, 0xe
.L80240E24:
/* B07824 80240E24 AE020074 */  sw        $v0, 0x74($s0)
/* B07828 80240E28 28420100 */  slti      $v0, $v0, 0x100
/* B0782C 80240E2C 50400001 */  beql      $v0, $zero, .L80240E34
/* B07830 80240E30 AE030074 */   sw       $v1, 0x74($s0)
.L80240E34:
/* B07834 80240E34 8E020078 */  lw        $v0, 0x78($s0)
/* B07838 80240E38 8FBF0014 */  lw        $ra, 0x14($sp)
/* B0783C 80240E3C 8FB00010 */  lw        $s0, 0x10($sp)
/* B07840 80240E40 38420002 */  xori      $v0, $v0, 2
/* B07844 80240E44 2C420001 */  sltiu     $v0, $v0, 1
/* B07848 80240E48 00021040 */  sll       $v0, $v0, 1
/* B0784C 80240E4C 03E00008 */  jr        $ra
/* B07850 80240E50 27BD0018 */   addiu    $sp, $sp, 0x18
