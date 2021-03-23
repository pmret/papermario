.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240048_7E73E8
/* 7E73E8 80240048 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E73EC 8024004C AFB00010 */  sw        $s0, 0x10($sp)
/* 7E73F0 80240050 0080802D */  daddu     $s0, $a0, $zero
/* 7E73F4 80240054 10A00008 */  beqz      $a1, .L80240078
/* 7E73F8 80240058 AFBF0014 */   sw       $ra, 0x14($sp)
/* 7E73FC 8024005C 3C03800A */  lui       $v1, %hi(gOverrideFlags)
/* 7E7400 80240060 2463A650 */  addiu     $v1, $v1, %lo(gOverrideFlags)
/* 7E7404 80240064 8C620000 */  lw        $v0, ($v1)
/* 7E7408 80240068 AE000070 */  sw        $zero, 0x70($s0)
/* 7E740C 8024006C AE000074 */  sw        $zero, 0x74($s0)
/* 7E7410 80240070 34420010 */  ori       $v0, $v0, 0x10
/* 7E7414 80240074 AC620000 */  sw        $v0, ($v1)
.L80240078:
/* 7E7418 80240078 C6000074 */  lwc1      $f0, 0x74($s0)
/* 7E741C 8024007C 46800020 */  cvt.s.w   $f0, $f0
/* 7E7420 80240080 44050000 */  mfc1      $a1, $f0
/* 7E7424 80240084 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* 7E7428 80240088 0000202D */   daddu    $a0, $zero, $zero
/* 7E742C 8024008C 8E020074 */  lw        $v0, 0x74($s0)
/* 7E7430 80240090 240300FF */  addiu     $v1, $zero, 0xff
/* 7E7434 80240094 14430003 */  bne       $v0, $v1, .L802400A4
/* 7E7438 80240098 2442000A */   addiu    $v0, $v0, 0xa
/* 7E743C 8024009C 0809002E */  j         .L802400B8
/* 7E7440 802400A0 24020002 */   addiu    $v0, $zero, 2
.L802400A4:
/* 7E7444 802400A4 AE020074 */  sw        $v0, 0x74($s0)
/* 7E7448 802400A8 28420100 */  slti      $v0, $v0, 0x100
/* 7E744C 802400AC 50400001 */  beql      $v0, $zero, .L802400B4
/* 7E7450 802400B0 AE030074 */   sw       $v1, 0x74($s0)
.L802400B4:
/* 7E7454 802400B4 0000102D */  daddu     $v0, $zero, $zero
.L802400B8:
/* 7E7458 802400B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7E745C 802400BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E7460 802400C0 03E00008 */  jr        $ra
/* 7E7464 802400C4 27BD0018 */   addiu    $sp, $sp, 0x18
