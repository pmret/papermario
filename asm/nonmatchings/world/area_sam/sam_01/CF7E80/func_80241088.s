.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241088
/* CF8BF8 80241088 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF8BFC 8024108C 10A0000B */  beqz      $a1, .L802410BC
/* CF8C00 80241090 AFBF0010 */   sw       $ra, 0x10($sp)
/* CF8C04 80241094 3C038025 */  lui       $v1, 0x8025
/* CF8C08 80241098 8C63DF1C */  lw        $v1, -0x20e4($v1)
/* CF8C0C 8024109C 8C620000 */  lw        $v0, ($v1)
/* CF8C10 802410A0 3C048025 */  lui       $a0, 0x8025
/* CF8C14 802410A4 8C84DF20 */  lw        $a0, -0x20e0($a0)
/* CF8C18 802410A8 34420010 */  ori       $v0, $v0, 0x10
/* CF8C1C 802410AC AC620000 */  sw        $v0, ($v1)
/* CF8C20 802410B0 8C820000 */  lw        $v0, ($a0)
/* CF8C24 802410B4 34420010 */  ori       $v0, $v0, 0x10
/* CF8C28 802410B8 AC820000 */  sw        $v0, ($a0)
.L802410BC:
/* CF8C2C 802410BC 3C048025 */  lui       $a0, 0x8025
/* CF8C30 802410C0 8C84DF18 */  lw        $a0, -0x20e8($a0)
/* CF8C34 802410C4 8C85000C */  lw        $a1, 0xc($a0)
/* CF8C38 802410C8 8CA20018 */  lw        $v0, 0x18($a1)
/* CF8C3C 802410CC 8CA30020 */  lw        $v1, 0x20($a1)
/* CF8C40 802410D0 2442FFF6 */  addiu     $v0, $v0, -0xa
/* CF8C44 802410D4 ACA20018 */  sw        $v0, 0x18($a1)
/* CF8C48 802410D8 8CA20024 */  lw        $v0, 0x24($a1)
/* CF8C4C 802410DC 2463FFF6 */  addiu     $v1, $v1, -0xa
/* CF8C50 802410E0 ACA30020 */  sw        $v1, 0x20($a1)
/* CF8C54 802410E4 8CA30028 */  lw        $v1, 0x28($a1)
/* CF8C58 802410E8 2442FFF6 */  addiu     $v0, $v0, -0xa
/* CF8C5C 802410EC ACA20024 */  sw        $v0, 0x24($a1)
/* CF8C60 802410F0 8CA2001C */  lw        $v0, 0x1c($a1)
/* CF8C64 802410F4 2463FFF6 */  addiu     $v1, $v1, -0xa
/* CF8C68 802410F8 ACA30028 */  sw        $v1, 0x28($a1)
/* CF8C6C 802410FC 8CA30018 */  lw        $v1, 0x18($a1)
/* CF8C70 80241100 2442FFF6 */  addiu     $v0, $v0, -0xa
/* CF8C74 80241104 18600003 */  blez      $v1, .L80241114
/* CF8C78 80241108 ACA2001C */   sw       $v0, 0x1c($a1)
/* CF8C7C 8024110C 0809044C */  j         .L80241130
/* CF8C80 80241110 0000102D */   daddu    $v0, $zero, $zero
.L80241114:
/* CF8C84 80241114 0C016914 */  jal       remove_effect
/* CF8C88 80241118 ACA00018 */   sw       $zero, 0x18($a1)
/* CF8C8C 8024111C 3C048025 */  lui       $a0, 0x8025
/* CF8C90 80241120 8C84DEF8 */  lw        $a0, -0x2108($a0)
/* CF8C94 80241124 0C048D70 */  jal       func_801235C0
/* CF8C98 80241128 00000000 */   nop      
/* CF8C9C 8024112C 24020002 */  addiu     $v0, $zero, 2
.L80241130:
/* CF8CA0 80241130 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF8CA4 80241134 03E00008 */  jr        $ra
/* CF8CA8 80241138 27BD0018 */   addiu    $sp, $sp, 0x18
