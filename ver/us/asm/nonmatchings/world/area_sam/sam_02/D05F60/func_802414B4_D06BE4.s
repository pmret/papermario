.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414B4_D06BE4
/* D06BE4 802414B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D06BE8 802414B8 10A0000B */  beqz      $a1, .L802414E8
/* D06BEC 802414BC AFBF0010 */   sw       $ra, 0x10($sp)
/* D06BF0 802414C0 3C038025 */  lui       $v1, %hi(D_8024B9B4)
/* D06BF4 802414C4 8C63B9B4 */  lw        $v1, %lo(D_8024B9B4)($v1)
/* D06BF8 802414C8 8C620000 */  lw        $v0, ($v1)
/* D06BFC 802414CC 3C048025 */  lui       $a0, %hi(D_8024B9B8)
/* D06C00 802414D0 8C84B9B8 */  lw        $a0, %lo(D_8024B9B8)($a0)
/* D06C04 802414D4 34420010 */  ori       $v0, $v0, 0x10
/* D06C08 802414D8 AC620000 */  sw        $v0, ($v1)
/* D06C0C 802414DC 8C820000 */  lw        $v0, ($a0)
/* D06C10 802414E0 34420010 */  ori       $v0, $v0, 0x10
/* D06C14 802414E4 AC820000 */  sw        $v0, ($a0)
.L802414E8:
/* D06C18 802414E8 3C048025 */  lui       $a0, %hi(jtbl_8024B9B0_B8FB30)
/* D06C1C 802414EC 8C84B9B0 */  lw        $a0, %lo(jtbl_8024B9B0_B8FB30)($a0)
/* D06C20 802414F0 8C85000C */  lw        $a1, 0xc($a0)
/* D06C24 802414F4 8CA20018 */  lw        $v0, 0x18($a1)
/* D06C28 802414F8 8CA30020 */  lw        $v1, 0x20($a1)
/* D06C2C 802414FC 2442FFF6 */  addiu     $v0, $v0, -0xa
/* D06C30 80241500 ACA20018 */  sw        $v0, 0x18($a1)
/* D06C34 80241504 8CA20024 */  lw        $v0, 0x24($a1)
/* D06C38 80241508 2463FFF6 */  addiu     $v1, $v1, -0xa
/* D06C3C 8024150C ACA30020 */  sw        $v1, 0x20($a1)
/* D06C40 80241510 8CA30028 */  lw        $v1, 0x28($a1)
/* D06C44 80241514 2442FFF6 */  addiu     $v0, $v0, -0xa
/* D06C48 80241518 ACA20024 */  sw        $v0, 0x24($a1)
/* D06C4C 8024151C 8CA2001C */  lw        $v0, 0x1c($a1)
/* D06C50 80241520 2463FFF6 */  addiu     $v1, $v1, -0xa
/* D06C54 80241524 ACA30028 */  sw        $v1, 0x28($a1)
/* D06C58 80241528 8CA30018 */  lw        $v1, 0x18($a1)
/* D06C5C 8024152C 2442FFF6 */  addiu     $v0, $v0, -0xa
/* D06C60 80241530 18600003 */  blez      $v1, .L80241540
/* D06C64 80241534 ACA2001C */   sw       $v0, 0x1c($a1)
/* D06C68 80241538 08090557 */  j         .L8024155C
/* D06C6C 8024153C 0000102D */   daddu    $v0, $zero, $zero
.L80241540:
/* D06C70 80241540 0C016914 */  jal       remove_effect
/* D06C74 80241544 ACA00018 */   sw       $zero, 0x18($a1)
/* D06C78 80241548 3C048025 */  lui       $a0, %hi(D_8024B990)
/* D06C7C 8024154C 8C84B990 */  lw        $a0, %lo(D_8024B990)($a0)
/* D06C80 80241550 0C048D70 */  jal       free_dynamic_entity
/* D06C84 80241554 00000000 */   nop
/* D06C88 80241558 24020002 */  addiu     $v0, $zero, 2
.L8024155C:
/* D06C8C 8024155C 8FBF0010 */  lw        $ra, 0x10($sp)
/* D06C90 80241560 03E00008 */  jr        $ra
/* D06C94 80241564 27BD0018 */   addiu    $sp, $sp, 0x18
