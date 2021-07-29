.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CA8_853E18
/* 853E18 80241CA8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 853E1C 80241CAC 10A0000B */  beqz      $a1, .L80241CDC
/* 853E20 80241CB0 AFBF0010 */   sw       $ra, 0x10($sp)
/* 853E24 80241CB4 3C038025 */  lui       $v1, %hi(D_802529F4)
/* 853E28 80241CB8 8C6329F4 */  lw        $v1, %lo(D_802529F4)($v1)
/* 853E2C 80241CBC 8C620000 */  lw        $v0, ($v1)
/* 853E30 80241CC0 3C048025 */  lui       $a0, %hi(dgb_01_D_802529F8_C10278)
/* 853E34 80241CC4 8C8429F8 */  lw        $a0, %lo(dgb_01_D_802529F8_C10278)($a0)
/* 853E38 80241CC8 34420010 */  ori       $v0, $v0, 0x10
/* 853E3C 80241CCC AC620000 */  sw        $v0, ($v1)
/* 853E40 80241CD0 8C820000 */  lw        $v0, ($a0)
/* 853E44 80241CD4 34420010 */  ori       $v0, $v0, 0x10
/* 853E48 80241CD8 AC820000 */  sw        $v0, ($a0)
.L80241CDC:
/* 853E4C 80241CDC 3C048025 */  lui       $a0, %hi(D_802529F0)
/* 853E50 80241CE0 8C8429F0 */  lw        $a0, %lo(D_802529F0)($a0)
/* 853E54 80241CE4 8C85000C */  lw        $a1, 0xc($a0)
/* 853E58 80241CE8 8CA20018 */  lw        $v0, 0x18($a1)
/* 853E5C 80241CEC 8CA30020 */  lw        $v1, 0x20($a1)
/* 853E60 80241CF0 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 853E64 80241CF4 ACA20018 */  sw        $v0, 0x18($a1)
/* 853E68 80241CF8 8CA20024 */  lw        $v0, 0x24($a1)
/* 853E6C 80241CFC 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 853E70 80241D00 ACA30020 */  sw        $v1, 0x20($a1)
/* 853E74 80241D04 8CA30028 */  lw        $v1, 0x28($a1)
/* 853E78 80241D08 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 853E7C 80241D0C ACA20024 */  sw        $v0, 0x24($a1)
/* 853E80 80241D10 8CA2001C */  lw        $v0, 0x1c($a1)
/* 853E84 80241D14 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 853E88 80241D18 ACA30028 */  sw        $v1, 0x28($a1)
/* 853E8C 80241D1C 8CA30018 */  lw        $v1, 0x18($a1)
/* 853E90 80241D20 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 853E94 80241D24 18600003 */  blez      $v1, .L80241D34
/* 853E98 80241D28 ACA2001C */   sw       $v0, 0x1c($a1)
/* 853E9C 80241D2C 08090754 */  j         .L80241D50
/* 853EA0 80241D30 0000102D */   daddu    $v0, $zero, $zero
.L80241D34:
/* 853EA4 80241D34 0C016914 */  jal       remove_effect
/* 853EA8 80241D38 ACA00018 */   sw       $zero, 0x18($a1)
/* 853EAC 80241D3C 3C048025 */  lui       $a0, %hi(D_802529D0)
/* 853EB0 80241D40 8C8429D0 */  lw        $a0, %lo(D_802529D0)($a0)
/* 853EB4 80241D44 0C048D70 */  jal       free_generic_entity
/* 853EB8 80241D48 00000000 */   nop
/* 853EBC 80241D4C 24020002 */  addiu     $v0, $zero, 2
.L80241D50:
/* 853EC0 80241D50 8FBF0010 */  lw        $ra, 0x10($sp)
/* 853EC4 80241D54 03E00008 */  jr        $ra
/* 853EC8 80241D58 27BD0018 */   addiu    $sp, $sp, 0x18
