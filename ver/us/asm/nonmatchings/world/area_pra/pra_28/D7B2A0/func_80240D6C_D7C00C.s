.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D6C_D7C00C
/* D7C00C 80240D6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7C010 80240D70 AFB00010 */  sw        $s0, 0x10($sp)
/* D7C014 80240D74 0080802D */  daddu     $s0, $a0, $zero
/* D7C018 80240D78 AFBF0014 */  sw        $ra, 0x14($sp)
/* D7C01C 80240D7C 8E020088 */  lw        $v0, 0x88($s0)
/* D7C020 80240D80 14400017 */  bnez      $v0, .L80240DE0
/* D7C024 80240D84 24020001 */   addiu    $v0, $zero, 1
/* D7C028 80240D88 8E030084 */  lw        $v1, 0x84($s0)
/* D7C02C 80240D8C 1062001A */  beq       $v1, $v0, .L80240DF8
/* D7C030 80240D90 00000000 */   nop
/* D7C034 80240D94 28620002 */  slti      $v0, $v1, 2
/* D7C038 80240D98 50400005 */  beql      $v0, $zero, .L80240DB0
/* D7C03C 80240D9C 24020002 */   addiu    $v0, $zero, 2
/* D7C040 80240DA0 10600007 */  beqz      $v1, .L80240DC0
/* D7C044 80240DA4 00000000 */   nop
/* D7C048 80240DA8 08090384 */  j         .L80240E10
/* D7C04C 80240DAC 00000000 */   nop
.L80240DB0:
/* D7C050 80240DB0 10620007 */  beq       $v1, $v0, .L80240DD0
/* D7C054 80240DB4 00000000 */   nop
/* D7C058 80240DB8 08090384 */  j         .L80240E10
/* D7C05C 80240DBC 00000000 */   nop
.L80240DC0:
/* D7C060 80240DC0 3C048024 */  lui       $a0, %hi(pra_28_SetPartnerFlagsA0000)
/* D7C064 80240DC4 24840EB4 */  addiu     $a0, $a0, %lo(pra_28_SetPartnerFlagsA0000)
/* D7C068 80240DC8 08090380 */  j         .L80240E00
/* D7C06C 80240DCC 00000000 */   nop
.L80240DD0:
/* D7C070 80240DD0 3C048024 */  lui       $a0, %hi(pra_28_SetPartnerFlags20000)
/* D7C074 80240DD4 24840F1C */  addiu     $a0, $a0, %lo(pra_28_SetPartnerFlags20000)
/* D7C078 80240DD8 08090380 */  j         .L80240E00
/* D7C07C 80240DDC 00000000 */   nop
.L80240DE0:
/* D7C080 80240DE0 8E020084 */  lw        $v0, 0x84($s0)
/* D7C084 80240DE4 0440000A */  bltz      $v0, .L80240E10
/* D7C088 80240DE8 00000000 */   nop
/* D7C08C 80240DEC 28420002 */  slti      $v0, $v0, 2
/* D7C090 80240DF0 10400007 */  beqz      $v0, .L80240E10
/* D7C094 80240DF4 00000000 */   nop
.L80240DF8:
/* D7C098 80240DF8 3C048024 */  lui       $a0, %hi(pra_28_SetPartnerFlags80000)
/* D7C09C 80240DFC 24840EE8 */  addiu     $a0, $a0, %lo(pra_28_SetPartnerFlags80000)
.L80240E00:
/* D7C0A0 80240E00 0C048C56 */  jal       create_dynamic_entity_world
/* D7C0A4 80240E04 0000282D */   daddu    $a1, $zero, $zero
/* D7C0A8 80240E08 8E03013C */  lw        $v1, 0x13c($s0)
/* D7C0AC 80240E0C AC620004 */  sw        $v0, 4($v1)
.L80240E10:
/* D7C0B0 80240E10 0C00EAD2 */  jal       get_npc_safe
/* D7C0B4 80240E14 2404FFFC */   addiu    $a0, $zero, -4
/* D7C0B8 80240E18 0040282D */  daddu     $a1, $v0, $zero
/* D7C0BC 80240E1C 10A00021 */  beqz      $a1, .L80240EA4
/* D7C0C0 80240E20 24020002 */   addiu    $v0, $zero, 2
/* D7C0C4 80240E24 8E020088 */  lw        $v0, 0x88($s0)
/* D7C0C8 80240E28 14400014 */  bnez      $v0, .L80240E7C
/* D7C0CC 80240E2C 24020001 */   addiu    $v0, $zero, 1
/* D7C0D0 80240E30 8E040084 */  lw        $a0, 0x84($s0)
/* D7C0D4 80240E34 10820016 */  beq       $a0, $v0, .L80240E90
/* D7C0D8 80240E38 28820002 */   slti     $v0, $a0, 2
/* D7C0DC 80240E3C 10400005 */  beqz      $v0, .L80240E54
/* D7C0E0 80240E40 24020002 */   addiu    $v0, $zero, 2
/* D7C0E4 80240E44 10800007 */  beqz      $a0, .L80240E64
/* D7C0E8 80240E48 00000000 */   nop
/* D7C0EC 80240E4C 080903A9 */  j         .L80240EA4
/* D7C0F0 80240E50 00000000 */   nop
.L80240E54:
/* D7C0F4 80240E54 10820006 */  beq       $a0, $v0, .L80240E70
/* D7C0F8 80240E58 24020002 */   addiu    $v0, $zero, 2
/* D7C0FC 80240E5C 080903A9 */  j         .L80240EA4
/* D7C100 80240E60 00000000 */   nop
.L80240E64:
/* D7C104 80240E64 8CA20000 */  lw        $v0, ($a1)
/* D7C108 80240E68 080903A6 */  j         .L80240E98
/* D7C10C 80240E6C 3C03000A */   lui      $v1, 0xa
.L80240E70:
/* D7C110 80240E70 8CA20000 */  lw        $v0, ($a1)
/* D7C114 80240E74 080903A6 */  j         .L80240E98
/* D7C118 80240E78 3C030002 */   lui      $v1, 2
.L80240E7C:
/* D7C11C 80240E7C 8E020084 */  lw        $v0, 0x84($s0)
/* D7C120 80240E80 04400007 */  bltz      $v0, .L80240EA0
/* D7C124 80240E84 28420002 */   slti     $v0, $v0, 2
/* D7C128 80240E88 10400006 */  beqz      $v0, .L80240EA4
/* D7C12C 80240E8C 24020002 */   addiu    $v0, $zero, 2
.L80240E90:
/* D7C130 80240E90 8CA20000 */  lw        $v0, ($a1)
/* D7C134 80240E94 3C030008 */  lui       $v1, 8
.L80240E98:
/* D7C138 80240E98 00431025 */  or        $v0, $v0, $v1
/* D7C13C 80240E9C ACA20000 */  sw        $v0, ($a1)
.L80240EA0:
/* D7C140 80240EA0 24020002 */  addiu     $v0, $zero, 2
.L80240EA4:
/* D7C144 80240EA4 8FBF0014 */  lw        $ra, 0x14($sp)
/* D7C148 80240EA8 8FB00010 */  lw        $s0, 0x10($sp)
/* D7C14C 80240EAC 03E00008 */  jr        $ra
/* D7C150 80240EB0 27BD0018 */   addiu    $sp, $sp, 0x18
