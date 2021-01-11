.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E01166E8
/* 402D28 E01166E8 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 402D2C E01166EC AFB000A0 */  sw        $s0, 0xa0($sp)
/* 402D30 E01166F0 AFBF00AC */  sw        $ra, 0xac($sp)
/* 402D34 E01166F4 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 402D38 E01166F8 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 402D3C E01166FC F7B400B0 */  sdc1      $f20, 0xb0($sp)
/* 402D40 E0116700 1480000F */  bnez      $a0, .LE0116740
/* 402D44 E0116704 00A0802D */   daddu    $s0, $a1, $zero
/* 402D48 E0116708 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 402D4C E011670C 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 402D50 E0116710 00021880 */  sll       $v1, $v0, 2
/* 402D54 E0116714 00621821 */  addu      $v1, $v1, $v0
/* 402D58 E0116718 00031880 */  sll       $v1, $v1, 2
/* 402D5C E011671C 00621823 */  subu      $v1, $v1, $v0
/* 402D60 E0116720 000310C0 */  sll       $v0, $v1, 3
/* 402D64 E0116724 00621821 */  addu      $v1, $v1, $v0
/* 402D68 E0116728 000318C0 */  sll       $v1, $v1, 3
/* 402D6C E011672C 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 402D70 E0116730 00230821 */  addu      $at, $at, $v1
/* 402D74 E0116734 C4261DEC */  lwc1      $f6, %lo(D_800B1DEC)($at)
/* 402D78 E0116738 080459D1 */  j         .LE0116744
/* 402D7C E011673C 00000000 */   nop      
.LE0116740:
/* 402D80 E0116740 44803000 */  mtc1      $zero, $f6
.LE0116744:
/* 402D84 E0116744 C6000018 */  lwc1      $f0, 0x18($s0)
/* 402D88 E0116748 C6040020 */  lwc1      $f4, 0x20($s0)
/* 402D8C E011674C 3C014000 */  lui       $at, 0x4000
/* 402D90 E0116750 44811000 */  mtc1      $at, $f2
/* 402D94 E0116754 E7A00010 */  swc1      $f0, 0x10($sp)
/* 402D98 E0116758 C6000004 */  lwc1      $f0, 4($s0)
/* 402D9C E011675C 4480A000 */  mtc1      $zero, $f20
/* 402DA0 E0116760 46020000 */  add.s     $f0, $f0, $f2
/* 402DA4 E0116764 4405A000 */  mfc1      $a1, $f20
/* 402DA8 E0116768 27A40020 */  addiu     $a0, $sp, 0x20
/* 402DAC E011676C E7A00014 */  swc1      $f0, 0x14($sp)
/* 402DB0 E0116770 C6000008 */  lwc1      $f0, 8($s0)
/* 402DB4 E0116774 46062101 */  sub.s     $f4, $f4, $f6
/* 402DB8 E0116778 E7A00018 */  swc1      $f0, 0x18($sp)
/* 402DBC E011677C C600000C */  lwc1      $f0, 0xc($s0)
/* 402DC0 E0116780 4407A000 */  mfc1      $a3, $f20
/* 402DC4 E0116784 46020000 */  add.s     $f0, $f0, $f2
/* 402DC8 E0116788 44062000 */  mfc1      $a2, $f4
/* 402DCC E011678C 3C120001 */  lui       $s2, 1
/* 402DD0 E0116790 0C080180 */  jal       func_E0200600
/* 402DD4 E0116794 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 402DD8 E0116798 4406A000 */  mfc1      $a2, $f20
/* 402DDC E011679C 4407A000 */  mfc1      $a3, $f20
/* 402DE0 E01167A0 3C013F80 */  lui       $at, 0x3f80
/* 402DE4 E01167A4 44810000 */  mtc1      $at, $f0
/* 402DE8 E01167A8 36521630 */  ori       $s2, $s2, 0x1630
/* 402DEC E01167AC E7A00010 */  swc1      $f0, 0x10($sp)
/* 402DF0 E01167B0 8E05001C */  lw        $a1, 0x1c($s0)
/* 402DF4 E01167B4 27B00060 */  addiu     $s0, $sp, 0x60
/* 402DF8 E01167B8 0C080104 */  jal       func_E0200410
/* 402DFC E01167BC 0200202D */   daddu    $a0, $s0, $zero
/* 402E00 E01167C0 0200202D */  daddu     $a0, $s0, $zero
/* 402E04 E01167C4 27A50020 */  addiu     $a1, $sp, 0x20
/* 402E08 E01167C8 0C080114 */  jal       func_E0200450
/* 402E0C E01167CC 00A0302D */   daddu    $a2, $a1, $zero
/* 402E10 E01167D0 0200202D */  daddu     $a0, $s0, $zero
/* 402E14 E01167D4 4405A000 */  mfc1      $a1, $f20
/* 402E18 E01167D8 3C07C000 */  lui       $a3, 0xc000
/* 402E1C E01167DC 0C080108 */  jal       func_E0200420
/* 402E20 E01167E0 00A0302D */   daddu    $a2, $a1, $zero
/* 402E24 E01167E4 0200202D */  daddu     $a0, $s0, $zero
/* 402E28 E01167E8 27A50020 */  addiu     $a1, $sp, 0x20
/* 402E2C E01167EC 0C080114 */  jal       func_E0200450
/* 402E30 E01167F0 00A0302D */   daddu    $a2, $a1, $zero
/* 402E34 E01167F4 27A40020 */  addiu     $a0, $sp, 0x20
/* 402E38 E01167F8 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 402E3C E01167FC 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 402E40 E0116800 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 402E44 E0116804 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 402E48 E0116808 96050000 */  lhu       $a1, ($s0)
/* 402E4C E011680C 8E220000 */  lw        $v0, ($s1)
/* 402E50 E0116810 00052980 */  sll       $a1, $a1, 6
/* 402E54 E0116814 00B22821 */  addu      $a1, $a1, $s2
/* 402E58 E0116818 0C080118 */  jal       func_E0200460
/* 402E5C E011681C 00452821 */   addu     $a1, $v0, $a1
/* 402E60 E0116820 3C05DA38 */  lui       $a1, 0xda38
/* 402E64 E0116824 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 402E68 E0116828 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 402E6C E011682C 34A50002 */  ori       $a1, $a1, 2
/* 402E70 E0116830 8C830000 */  lw        $v1, ($a0)
/* 402E74 E0116834 96020000 */  lhu       $v0, ($s0)
/* 402E78 E0116838 0060302D */  daddu     $a2, $v1, $zero
/* 402E7C E011683C 24630008 */  addiu     $v1, $v1, 8
/* 402E80 E0116840 AC830000 */  sw        $v1, ($a0)
/* 402E84 E0116844 24430001 */  addiu     $v1, $v0, 1
/* 402E88 E0116848 3042FFFF */  andi      $v0, $v0, 0xffff
/* 402E8C E011684C 00021180 */  sll       $v0, $v0, 6
/* 402E90 E0116850 ACC50000 */  sw        $a1, ($a2)
/* 402E94 E0116854 A6030000 */  sh        $v1, ($s0)
/* 402E98 E0116858 8E230000 */  lw        $v1, ($s1)
/* 402E9C E011685C 00521021 */  addu      $v0, $v0, $s2
/* 402EA0 E0116860 00621821 */  addu      $v1, $v1, $v0
/* 402EA4 E0116864 ACC30004 */  sw        $v1, 4($a2)
/* 402EA8 E0116868 8FBF00AC */  lw        $ra, 0xac($sp)
/* 402EAC E011686C 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 402EB0 E0116870 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 402EB4 E0116874 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 402EB8 E0116878 D7B400B0 */  ldc1      $f20, 0xb0($sp)
/* 402EBC E011687C 03E00008 */  jr        $ra
/* 402EC0 E0116880 27BD00B8 */   addiu    $sp, $sp, 0xb8
