.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C88_969E48
/* 969E48 80240C88 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 969E4C 80240C8C 10A0000B */  beqz      $a1, .L80240CBC
/* 969E50 80240C90 AFBF0010 */   sw       $ra, 0x10($sp)
/* 969E54 80240C94 3C038025 */  lui       $v1, 0x8025
/* 969E58 80240C98 8C63EFC4 */  lw        $v1, -0x103c($v1)
/* 969E5C 80240C9C 8C620000 */  lw        $v0, ($v1)
/* 969E60 80240CA0 3C048025 */  lui       $a0, 0x8025
/* 969E64 80240CA4 8C84EFC8 */  lw        $a0, -0x1038($a0)
/* 969E68 80240CA8 34420010 */  ori       $v0, $v0, 0x10
/* 969E6C 80240CAC AC620000 */  sw        $v0, ($v1)
/* 969E70 80240CB0 8C820000 */  lw        $v0, ($a0)
/* 969E74 80240CB4 34420010 */  ori       $v0, $v0, 0x10
/* 969E78 80240CB8 AC820000 */  sw        $v0, ($a0)
.L80240CBC:
/* 969E7C 80240CBC 3C048025 */  lui       $a0, 0x8025
/* 969E80 80240CC0 8C84EFC0 */  lw        $a0, -0x1040($a0)
/* 969E84 80240CC4 8C85000C */  lw        $a1, 0xc($a0)
/* 969E88 80240CC8 8CA20018 */  lw        $v0, 0x18($a1)
/* 969E8C 80240CCC 8CA30020 */  lw        $v1, 0x20($a1)
/* 969E90 80240CD0 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 969E94 80240CD4 ACA20018 */  sw        $v0, 0x18($a1)
/* 969E98 80240CD8 8CA20024 */  lw        $v0, 0x24($a1)
/* 969E9C 80240CDC 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 969EA0 80240CE0 ACA30020 */  sw        $v1, 0x20($a1)
/* 969EA4 80240CE4 8CA30028 */  lw        $v1, 0x28($a1)
/* 969EA8 80240CE8 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 969EAC 80240CEC ACA20024 */  sw        $v0, 0x24($a1)
/* 969EB0 80240CF0 8CA2001C */  lw        $v0, 0x1c($a1)
/* 969EB4 80240CF4 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 969EB8 80240CF8 ACA30028 */  sw        $v1, 0x28($a1)
/* 969EBC 80240CFC 8CA30018 */  lw        $v1, 0x18($a1)
/* 969EC0 80240D00 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 969EC4 80240D04 18600003 */  blez      $v1, .L80240D14
/* 969EC8 80240D08 ACA2001C */   sw       $v0, 0x1c($a1)
/* 969ECC 80240D0C 0809034C */  j         .L80240D30
/* 969ED0 80240D10 0000102D */   daddu    $v0, $zero, $zero
.L80240D14:
/* 969ED4 80240D14 0C016914 */  jal       remove_effect
/* 969ED8 80240D18 ACA00018 */   sw       $zero, 0x18($a1)
/* 969EDC 80240D1C 3C048025 */  lui       $a0, %hi(gPauseMenuCursorPosY)
/* 969EE0 80240D20 8C84EFA0 */  lw        $a0, %lo(gPauseMenuCursorPosY)($a0)
/* 969EE4 80240D24 0C048D70 */  jal       func_801235C0
/* 969EE8 80240D28 00000000 */   nop      
/* 969EEC 80240D2C 24020002 */  addiu     $v0, $zero, 2
.L80240D30:
/* 969EF0 80240D30 8FBF0010 */  lw        $ra, 0x10($sp)
/* 969EF4 80240D34 03E00008 */  jr        $ra
/* 969EF8 80240D38 27BD0018 */   addiu    $sp, $sp, 0x18
