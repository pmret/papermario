.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800F4E40
/* 08E2F0 800F4E40 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08E2F4 800F4E44 AFB00010 */  sw    $s0, 0x10($sp)
/* 08E2F8 800F4E48 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08E2FC 800F4E4C 0C03A635 */  jal   func_800E98D4
/* 08E300 800F4E50 0080802D */   daddu $s0, $a0, $zero
/* 08E304 800F4E54 3C018011 */  lui   $at, 0x8011
/* 08E308 800F4E58 A022D69A */  sb    $v0, -0x2966($at)
/* 08E30C 800F4E5C 0C03A625 */  jal   status_menu_enable_ignore_changes
/* 08E310 800F4E60 00000000 */   nop   
/* 08E314 800F4E64 0C03A5E3 */  jal   open_status_menu_short
/* 08E318 800F4E68 00000000 */   nop   
/* 08E31C 800F4E6C 3C048011 */  lui   $a0, 0x8011
/* 08E320 800F4E70 2484D699 */  addiu $a0, $a0, -0x2967
/* 08E324 800F4E74 3C068011 */  lui   $a2, 0x8011
/* 08E328 800F4E78 24C6D698 */  addiu $a2, $a2, -0x2968
/* 08E32C 800F4E7C 3C018011 */  lui   $at, 0x8011
/* 08E330 800F4E80 AC30D69C */  sw    $s0, -0x2964($at)
/* 08E334 800F4E84 A600032C */  sh    $zero, 0x32c($s0)
/* 08E338 800F4E88 AE00031C */  sw    $zero, 0x31c($s0)
/* 08E33C 800F4E8C AE000320 */  sw    $zero, 0x320($s0)
/* 08E340 800F4E90 A0800000 */  sb    $zero, ($a0)
/* 08E344 800F4E94 8E030318 */  lw    $v1, 0x318($s0)
/* 08E348 800F4E98 24050001 */  addiu $a1, $zero, 1
/* 08E34C 800F4E9C 28620064 */  slti  $v0, $v1, 0x64
/* 08E350 800F4EA0 1440000C */  bnez  $v0, .L800F4ED4
/* 08E354 800F4EA4 A0C50000 */   sb    $a1, ($a2)
/* 08E358 800F4EA8 2462FF9C */  addiu $v0, $v1, -0x64
/* 08E35C 800F4EAC AE020318 */  sw    $v0, 0x318($s0)
/* 08E360 800F4EB0 0040182D */  daddu $v1, $v0, $zero
/* 08E364 800F4EB4 28620064 */  slti  $v0, $v1, 0x64
/* 08E368 800F4EB8 14400005 */  bnez  $v0, .L800F4ED0
/* 08E36C 800F4EBC A0850000 */   sb    $a1, ($a0)
/* 08E370 800F4EC0 2462FF9C */  addiu $v0, $v1, -0x64
/* 08E374 800F4EC4 AE020318 */  sw    $v0, 0x318($s0)
/* 08E378 800F4EC8 24020002 */  addiu $v0, $zero, 2
/* 08E37C 800F4ECC A0820000 */  sb    $v0, ($a0)
.L800F4ED0:
/* 08E380 800F4ED0 A0C00000 */  sb    $zero, ($a2)
.L800F4ED4:
/* 08E384 800F4ED4 3C058011 */  lui   $a1, 0x8011
/* 08E388 800F4ED8 8CA5D69C */  lw    $a1, -0x2964($a1)
/* 08E38C 800F4EDC 24020001 */  addiu $v0, $zero, 1
/* 08E390 800F4EE0 3C018011 */  lui   $at, 0x8011
/* 08E394 800F4EE4 A022D68E */  sb    $v0, -0x2972($at)
/* 08E398 800F4EE8 24020006 */  addiu $v0, $zero, 6
/* 08E39C 800F4EEC 3C018011 */  lui   $at, 0x8011
/* 08E3A0 800F4EF0 A022D68F */  sb    $v0, -0x2971($at)
/* 08E3A4 800F4EF4 8CA20328 */  lw    $v0, 0x328($a1)
/* 08E3A8 800F4EF8 8CA40324 */  lw    $a0, 0x324($a1)
/* 08E3AC 800F4EFC 3C038011 */  lui   $v1, 0x8011
/* 08E3B0 800F4F00 2463D648 */  addiu $v1, $v1, -0x29b8
/* 08E3B4 800F4F04 3C018011 */  lui   $at, 0x8011
/* 08E3B8 800F4F08 AC20D640 */  sw    $zero, -0x29c0($at)
/* 08E3BC 800F4F0C AC620000 */  sw    $v0, ($v1)
/* 08E3C0 800F4F10 0044102A */  slt   $v0, $v0, $a0
/* 08E3C4 800F4F14 14400002 */  bnez  $v0, .L800F4F20
/* 08E3C8 800F4F18 2482FFFF */   addiu $v0, $a0, -1
/* 08E3CC 800F4F1C AC620000 */  sw    $v0, ($v1)
.L800F4F20:
/* 08E3D0 800F4F20 8C620000 */  lw    $v0, ($v1)
/* 08E3D4 800F4F24 3C048011 */  lui   $a0, 0x8011
/* 08E3D8 800F4F28 2484D656 */  addiu $a0, $a0, -0x29aa
/* 08E3DC 800F4F2C 3C018011 */  lui   $at, 0x8011
/* 08E3E0 800F4F30 A020D654 */  sb    $zero, -0x29ac($at)
/* 08E3E4 800F4F34 3C018011 */  lui   $at, 0x8011
/* 08E3E8 800F4F38 AC22D64C */  sw    $v0, -0x29b4($at)
/* 08E3EC 800F4F3C 90A20327 */  lbu   $v0, 0x327($a1)
/* 08E3F0 800F4F40 24030006 */  addiu $v1, $zero, 6
/* 08E3F4 800F4F44 A0820000 */  sb    $v0, ($a0)
/* 08E3F8 800F4F48 00021600 */  sll   $v0, $v0, 0x18
/* 08E3FC 800F4F4C 00021603 */  sra   $v0, $v0, 0x18
/* 08E400 800F4F50 0062102A */  slt   $v0, $v1, $v0
/* 08E404 800F4F54 54400001 */  bnezl $v0, .L800F4F5C
/* 08E408 800F4F58 A0830000 */   sb    $v1, ($a0)
.L800F4F5C:
/* 08E40C 800F4F5C 8CA20324 */  lw    $v0, 0x324($a1)
/* 08E410 800F4F60 3C048011 */  lui   $a0, 0x8011
/* 08E414 800F4F64 2484D655 */  addiu $a0, $a0, -0x29ab
/* 08E418 800F4F68 28420006 */  slti  $v0, $v0, 6
/* 08E41C 800F4F6C 10400003 */  beqz  $v0, .L800F4F7C
/* 08E420 800F4F70 A0830000 */   sb    $v1, ($a0)
/* 08E424 800F4F74 90A20327 */  lbu   $v0, 0x327($a1)
/* 08E428 800F4F78 A0820000 */  sb    $v0, ($a0)
.L800F4F7C:
/* 08E42C 800F4F7C 240200FF */  addiu $v0, $zero, 0xff
/* 08E430 800F4F80 3C018011 */  lui   $at, 0x8011
/* 08E434 800F4F84 AC22D650 */  sw    $v0, -0x29b0($at)
/* 08E438 800F4F88 24020004 */  addiu $v0, $zero, 4
/* 08E43C 800F4F8C 3C04800F */  lui   $a0, 0x800f
/* 08E440 800F4F90 24841A10 */  addiu $a0, $a0, 0x1a10
/* 08E444 800F4F94 3C018011 */  lui   $at, 0x8011
/* 08E448 800F4F98 A022D691 */  sb    $v0, -0x296f($at)
/* 08E44C 800F4F9C 3C018011 */  lui   $at, 0x8011
/* 08E450 800F4FA0 A023D692 */  sb    $v1, -0x296e($at)
/* 08E454 800F4FA4 0C048C8F */  jal   func_8012323C
/* 08E458 800F4FA8 0000282D */   daddu $a1, $zero, $zero
/* 08E45C 800F4FAC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 08E460 800F4FB0 8FB00010 */  lw    $s0, 0x10($sp)
/* 08E464 800F4FB4 3C018011 */  lui   $at, 0x8011
/* 08E468 800F4FB8 AC22D694 */  sw    $v0, -0x296c($at)
/* 08E46C 800F4FBC 03E00008 */  jr    $ra
/* 08E470 800F4FC0 27BD0018 */   addiu $sp, $sp, 0x18

