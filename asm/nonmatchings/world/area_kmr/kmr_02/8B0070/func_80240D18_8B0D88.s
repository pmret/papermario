.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D18_8B0D88
/* 8B0D88 80240D18 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B0D8C 80240D1C 10A0000B */  beqz      $a1, .L80240D4C
/* 8B0D90 80240D20 AFBF0010 */   sw       $ra, 0x10($sp)
/* 8B0D94 80240D24 3C038025 */  lui       $v1, 0x8025
/* 8B0D98 80240D28 8C637F4C */  lw        $v1, 0x7f4c($v1)
/* 8B0D9C 80240D2C 8C620000 */  lw        $v0, ($v1)
/* 8B0DA0 80240D30 3C048025 */  lui       $a0, 0x8025
/* 8B0DA4 80240D34 8C847F50 */  lw        $a0, 0x7f50($a0)
/* 8B0DA8 80240D38 34420010 */  ori       $v0, $v0, 0x10
/* 8B0DAC 80240D3C AC620000 */  sw        $v0, ($v1)
/* 8B0DB0 80240D40 8C820000 */  lw        $v0, ($a0)
/* 8B0DB4 80240D44 34420010 */  ori       $v0, $v0, 0x10
/* 8B0DB8 80240D48 AC820000 */  sw        $v0, ($a0)
.L80240D4C:
/* 8B0DBC 80240D4C 3C048025 */  lui       $a0, 0x8025
/* 8B0DC0 80240D50 8C847F48 */  lw        $a0, 0x7f48($a0)
/* 8B0DC4 80240D54 8C85000C */  lw        $a1, 0xc($a0)
/* 8B0DC8 80240D58 8CA20018 */  lw        $v0, 0x18($a1)
/* 8B0DCC 80240D5C 8CA30020 */  lw        $v1, 0x20($a1)
/* 8B0DD0 80240D60 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 8B0DD4 80240D64 ACA20018 */  sw        $v0, 0x18($a1)
/* 8B0DD8 80240D68 8CA20024 */  lw        $v0, 0x24($a1)
/* 8B0DDC 80240D6C 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 8B0DE0 80240D70 ACA30020 */  sw        $v1, 0x20($a1)
/* 8B0DE4 80240D74 8CA30028 */  lw        $v1, 0x28($a1)
/* 8B0DE8 80240D78 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 8B0DEC 80240D7C ACA20024 */  sw        $v0, 0x24($a1)
/* 8B0DF0 80240D80 8CA2001C */  lw        $v0, 0x1c($a1)
/* 8B0DF4 80240D84 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 8B0DF8 80240D88 ACA30028 */  sw        $v1, 0x28($a1)
/* 8B0DFC 80240D8C 8CA30018 */  lw        $v1, 0x18($a1)
/* 8B0E00 80240D90 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 8B0E04 80240D94 18600003 */  blez      $v1, .L80240DA4
/* 8B0E08 80240D98 ACA2001C */   sw       $v0, 0x1c($a1)
/* 8B0E0C 80240D9C 08090370 */  j         .L80240DC0
/* 8B0E10 80240DA0 0000102D */   daddu    $v0, $zero, $zero
.L80240DA4:
/* 8B0E14 80240DA4 0C016914 */  jal       remove_effect
/* 8B0E18 80240DA8 ACA00018 */   sw       $zero, 0x18($a1)
/* 8B0E1C 80240DAC 3C048025 */  lui       $a0, 0x8025
/* 8B0E20 80240DB0 8C847F2C */  lw        $a0, 0x7f2c($a0)
/* 8B0E24 80240DB4 0C048D70 */  jal       func_801235C0
/* 8B0E28 80240DB8 00000000 */   nop      
/* 8B0E2C 80240DBC 24020002 */  addiu     $v0, $zero, 2
.L80240DC0:
/* 8B0E30 80240DC0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B0E34 80240DC4 03E00008 */  jr        $ra
/* 8B0E38 80240DC8 27BD0018 */   addiu    $sp, $sp, 0x18
