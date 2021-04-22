.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242E2C_A1DF2C
/* A1DF2C 80242E2C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1DF30 80242E30 10A0000B */  beqz      $a1, .L80242E60
/* A1DF34 80242E34 AFBF0010 */   sw       $ra, 0x10($sp)
/* A1DF38 80242E38 3C038025 */  lui       $v1, %hi(D_8024BDF4)
/* A1DF3C 80242E3C 8C63BDF4 */  lw        $v1, %lo(D_8024BDF4)($v1)
/* A1DF40 80242E40 8C620000 */  lw        $v0, ($v1)
/* A1DF44 80242E44 3C048025 */  lui       $a0, %hi(D_8024BDF8)
/* A1DF48 80242E48 8C84BDF8 */  lw        $a0, %lo(D_8024BDF8)($a0)
/* A1DF4C 80242E4C 34420010 */  ori       $v0, $v0, 0x10
/* A1DF50 80242E50 AC620000 */  sw        $v0, ($v1)
/* A1DF54 80242E54 8C820000 */  lw        $v0, ($a0)
/* A1DF58 80242E58 34420010 */  ori       $v0, $v0, 0x10
/* A1DF5C 80242E5C AC820000 */  sw        $v0, ($a0)
.L80242E60:
/* A1DF60 80242E60 3C048025 */  lui       $a0, %hi(D_8024BDF0)
/* A1DF64 80242E64 8C84BDF0 */  lw        $a0, %lo(D_8024BDF0)($a0)
/* A1DF68 80242E68 8C85000C */  lw        $a1, 0xc($a0)
/* A1DF6C 80242E6C 8CA20018 */  lw        $v0, 0x18($a1)
/* A1DF70 80242E70 8CA30020 */  lw        $v1, 0x20($a1)
/* A1DF74 80242E74 2442FFF6 */  addiu     $v0, $v0, -0xa
/* A1DF78 80242E78 ACA20018 */  sw        $v0, 0x18($a1)
/* A1DF7C 80242E7C 8CA20024 */  lw        $v0, 0x24($a1)
/* A1DF80 80242E80 2463FFF6 */  addiu     $v1, $v1, -0xa
/* A1DF84 80242E84 ACA30020 */  sw        $v1, 0x20($a1)
/* A1DF88 80242E88 8CA30028 */  lw        $v1, 0x28($a1)
/* A1DF8C 80242E8C 2442FFF6 */  addiu     $v0, $v0, -0xa
/* A1DF90 80242E90 ACA20024 */  sw        $v0, 0x24($a1)
/* A1DF94 80242E94 8CA2001C */  lw        $v0, 0x1c($a1)
/* A1DF98 80242E98 2463FFF6 */  addiu     $v1, $v1, -0xa
/* A1DF9C 80242E9C ACA30028 */  sw        $v1, 0x28($a1)
/* A1DFA0 80242EA0 8CA30018 */  lw        $v1, 0x18($a1)
/* A1DFA4 80242EA4 2442FFF6 */  addiu     $v0, $v0, -0xa
/* A1DFA8 80242EA8 18600003 */  blez      $v1, .L80242EB8
/* A1DFAC 80242EAC ACA2001C */   sw       $v0, 0x1c($a1)
/* A1DFB0 80242EB0 08090BB5 */  j         .L80242ED4
/* A1DFB4 80242EB4 0000102D */   daddu    $v0, $zero, $zero
.L80242EB8:
/* A1DFB8 80242EB8 0C016914 */  jal       remove_effect
/* A1DFBC 80242EBC ACA00018 */   sw       $zero, 0x18($a1)
/* A1DFC0 80242EC0 3C048025 */  lui       $a0, %hi(D_8024BDD0)
/* A1DFC4 80242EC4 8C84BDD0 */  lw        $a0, %lo(D_8024BDD0)($a0)
/* A1DFC8 80242EC8 0C048D70 */  jal       free_dynamic_entity
/* A1DFCC 80242ECC 00000000 */   nop
/* A1DFD0 80242ED0 24020002 */  addiu     $v0, $zero, 2
.L80242ED4:
/* A1DFD4 80242ED4 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1DFD8 80242ED8 03E00008 */  jr        $ra
/* A1DFDC 80242EDC 27BD0018 */   addiu    $sp, $sp, 0x18
