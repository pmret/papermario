.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802420EC_8EDF0C
/* 8EDF0C 802420EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EDF10 802420F0 10A00003 */  beqz      $a1, .L80242100
/* 8EDF14 802420F4 AFBF0010 */   sw       $ra, 0x10($sp)
/* 8EDF18 802420F8 240200FF */  addiu     $v0, $zero, 0xff
/* 8EDF1C 802420FC AC820074 */  sw        $v0, 0x74($a0)
.L80242100:
/* 8EDF20 80242100 8C820074 */  lw        $v0, 0x74($a0)
/* 8EDF24 80242104 2442FFF0 */  addiu     $v0, $v0, -0x10
/* 8EDF28 80242108 18400009 */  blez      $v0, .L80242130
/* 8EDF2C 8024210C AC820074 */   sw       $v0, 0x74($a0)
/* 8EDF30 80242110 44820000 */  mtc1      $v0, $f0
/* 8EDF34 80242114 00000000 */  nop
/* 8EDF38 80242118 46800020 */  cvt.s.w   $f0, $f0
/* 8EDF3C 8024211C 44050000 */  mfc1      $a1, $f0
/* 8EDF40 80242120 0C04DF62 */  jal       set_screen_overlay_params_front
/* 8EDF44 80242124 0000202D */   daddu    $a0, $zero, $zero
/* 8EDF48 80242128 0809084E */  j         .L80242138
/* 8EDF4C 8024212C 0000102D */   daddu    $v0, $zero, $zero
.L80242130:
/* 8EDF50 80242130 AC800074 */  sw        $zero, 0x74($a0)
/* 8EDF54 80242134 24020002 */  addiu     $v0, $zero, 2
.L80242138:
/* 8EDF58 80242138 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8EDF5C 8024213C 03E00008 */  jr        $ra
/* 8EDF60 80242140 27BD0018 */   addiu    $sp, $sp, 0x18
