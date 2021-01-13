.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021893C_43A3CC
/* 43A3CC 8021893C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 43A3D0 80218940 AFB40020 */  sw        $s4, 0x20($sp)
/* 43A3D4 80218944 0080A02D */  daddu     $s4, $a0, $zero
/* 43A3D8 80218948 AFBF0024 */  sw        $ra, 0x24($sp)
/* 43A3DC 8021894C AFB3001C */  sw        $s3, 0x1c($sp)
/* 43A3E0 80218950 AFB20018 */  sw        $s2, 0x18($sp)
/* 43A3E4 80218954 AFB10014 */  sw        $s1, 0x14($sp)
/* 43A3E8 80218958 AFB00010 */  sw        $s0, 0x10($sp)
/* 43A3EC 8021895C 8E92000C */  lw        $s2, 0xc($s4)
/* 43A3F0 80218960 8E450000 */  lw        $a1, ($s2)
/* 43A3F4 80218964 0C0B1EAF */  jal       get_variable
/* 43A3F8 80218968 26520004 */   addiu    $s2, $s2, 4
/* 43A3FC 8021896C 8E450000 */  lw        $a1, ($s2)
/* 43A400 80218970 26520004 */  addiu     $s2, $s2, 4
/* 43A404 80218974 0280202D */  daddu     $a0, $s4, $zero
/* 43A408 80218978 0C0B1EAF */  jal       get_variable
/* 43A40C 8021897C 0040802D */   daddu    $s0, $v0, $zero
/* 43A410 80218980 8E450000 */  lw        $a1, ($s2)
/* 43A414 80218984 26520004 */  addiu     $s2, $s2, 4
/* 43A418 80218988 0280202D */  daddu     $a0, $s4, $zero
/* 43A41C 8021898C 0C0B1EAF */  jal       get_variable
/* 43A420 80218990 0040882D */   daddu    $s1, $v0, $zero
/* 43A424 80218994 0040982D */  daddu     $s3, $v0, $zero
/* 43A428 80218998 8E450000 */  lw        $a1, ($s2)
/* 43A42C 8021899C 26520004 */  addiu     $s2, $s2, 4
/* 43A430 802189A0 0280202D */  daddu     $a0, $s4, $zero
/* 43A434 802189A4 0C0B1EAF */  jal       get_variable
/* 43A438 802189A8 02709823 */   subu     $s3, $s3, $s0
/* 43A43C 802189AC 0040802D */  daddu     $s0, $v0, $zero
/* 43A440 802189B0 0280202D */  daddu     $a0, $s4, $zero
/* 43A444 802189B4 8E450000 */  lw        $a1, ($s2)
/* 43A448 802189B8 0C0B1EAF */  jal       get_variable
/* 43A44C 802189BC 02118023 */   subu     $s0, $s0, $s1
/* 43A450 802189C0 16600006 */  bnez      $s3, .L802189DC
/* 43A454 802189C4 00000000 */   nop
/* 43A458 802189C8 16000004 */  bnez      $s0, .L802189DC
/* 43A45C 802189CC 0280202D */   daddu    $a0, $s4, $zero
/* 43A460 802189D0 8E450000 */  lw        $a1, ($s2)
/* 43A464 802189D4 08086281 */  j         .L80218A04
/* 43A468 802189D8 0040302D */   daddu    $a2, $v0, $zero
.L802189DC:
/* 43A46C 802189DC 44936000 */  mtc1      $s3, $f12
/* 43A470 802189E0 00000000 */  nop
/* 43A474 802189E4 46806320 */  cvt.s.w   $f12, $f12
/* 43A478 802189E8 44907000 */  mtc1      $s0, $f14
/* 43A47C 802189EC 00000000 */  nop
/* 43A480 802189F0 0C0861EC */  jal       func_802187B0_43A240
/* 43A484 802189F4 468073A0 */   cvt.s.w  $f14, $f14
/* 43A488 802189F8 0280202D */  daddu     $a0, $s4, $zero
/* 43A48C 802189FC 8E450000 */  lw        $a1, ($s2)
/* 43A490 80218A00 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L80218A04:
/* 43A494 80218A04 0C0B2026 */  jal       set_variable
/* 43A498 80218A08 00000000 */   nop
/* 43A49C 80218A0C 24020002 */  addiu     $v0, $zero, 2
/* 43A4A0 80218A10 8FBF0024 */  lw        $ra, 0x24($sp)
/* 43A4A4 80218A14 8FB40020 */  lw        $s4, 0x20($sp)
/* 43A4A8 80218A18 8FB3001C */  lw        $s3, 0x1c($sp)
/* 43A4AC 80218A1C 8FB20018 */  lw        $s2, 0x18($sp)
/* 43A4B0 80218A20 8FB10014 */  lw        $s1, 0x14($sp)
/* 43A4B4 80218A24 8FB00010 */  lw        $s0, 0x10($sp)
/* 43A4B8 80218A28 03E00008 */  jr        $ra
/* 43A4BC 80218A2C 27BD0028 */   addiu    $sp, $sp, 0x28
