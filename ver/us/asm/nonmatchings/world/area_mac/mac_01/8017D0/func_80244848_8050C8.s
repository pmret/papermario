.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244848_8050C8
/* 8050C8 80244848 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8050CC 8024484C 10A00003 */  beqz      $a1, .L8024485C
/* 8050D0 80244850 AFBF0010 */   sw       $ra, 0x10($sp)
/* 8050D4 80244854 240200FF */  addiu     $v0, $zero, 0xff
/* 8050D8 80244858 AC820074 */  sw        $v0, 0x74($a0)
.L8024485C:
/* 8050DC 8024485C 8C820074 */  lw        $v0, 0x74($a0)
/* 8050E0 80244860 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 8050E4 80244864 18400009 */  blez      $v0, .L8024488C
/* 8050E8 80244868 AC820074 */   sw       $v0, 0x74($a0)
/* 8050EC 8024486C 44820000 */  mtc1      $v0, $f0
/* 8050F0 80244870 00000000 */  nop
/* 8050F4 80244874 46800020 */  cvt.s.w   $f0, $f0
/* 8050F8 80244878 44050000 */  mfc1      $a1, $f0
/* 8050FC 8024487C 0C04DF62 */  jal       set_screen_overlay_params_front
/* 805100 80244880 0000202D */   daddu    $a0, $zero, $zero
/* 805104 80244884 08091225 */  j         .L80244894
/* 805108 80244888 0000102D */   daddu    $v0, $zero, $zero
.L8024488C:
/* 80510C 8024488C AC800074 */  sw        $zero, 0x74($a0)
/* 805110 80244890 24020002 */  addiu     $v0, $zero, 2
.L80244894:
/* 805114 80244894 8FBF0010 */  lw        $ra, 0x10($sp)
/* 805118 80244898 03E00008 */  jr        $ra
/* 80511C 8024489C 27BD0018 */   addiu    $sp, $sp, 0x18
