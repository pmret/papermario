.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D3C_D50D2C
/* D50D2C 80240D3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D50D30 80240D40 AFB00010 */  sw        $s0, 0x10($sp)
/* D50D34 80240D44 0080802D */  daddu     $s0, $a0, $zero
/* D50D38 80240D48 AFBF0014 */  sw        $ra, 0x14($sp)
/* D50D3C 80240D4C 8E020088 */  lw        $v0, 0x88($s0)
/* D50D40 80240D50 14400017 */  bnez      $v0, .L80240DB0
/* D50D44 80240D54 24020001 */   addiu    $v0, $zero, 1
/* D50D48 80240D58 8E030084 */  lw        $v1, 0x84($s0)
/* D50D4C 80240D5C 1062001A */  beq       $v1, $v0, .L80240DC8
/* D50D50 80240D60 00000000 */   nop
/* D50D54 80240D64 28620002 */  slti      $v0, $v1, 2
/* D50D58 80240D68 50400005 */  beql      $v0, $zero, .L80240D80
/* D50D5C 80240D6C 24020002 */   addiu    $v0, $zero, 2
/* D50D60 80240D70 10600007 */  beqz      $v1, .L80240D90
/* D50D64 80240D74 00000000 */   nop
/* D50D68 80240D78 08090378 */  j         .L80240DE0
/* D50D6C 80240D7C 00000000 */   nop
.L80240D80:
/* D50D70 80240D80 10620007 */  beq       $v1, $v0, .L80240DA0
/* D50D74 80240D84 00000000 */   nop
/* D50D78 80240D88 08090378 */  j         .L80240DE0
/* D50D7C 80240D8C 00000000 */   nop
.L80240D90:
/* D50D80 80240D90 3C048024 */  lui       $a0, %hi(pra_02_SetPartnerFlagsA0000)
/* D50D84 80240D94 24840E84 */  addiu     $a0, $a0, %lo(pra_02_SetPartnerFlagsA0000)
/* D50D88 80240D98 08090374 */  j         .L80240DD0
/* D50D8C 80240D9C 00000000 */   nop
.L80240DA0:
/* D50D90 80240DA0 3C048024 */  lui       $a0, %hi(pra_02_SetPartnerFlags20000)
/* D50D94 80240DA4 24840EEC */  addiu     $a0, $a0, %lo(pra_02_SetPartnerFlags20000)
/* D50D98 80240DA8 08090374 */  j         .L80240DD0
/* D50D9C 80240DAC 00000000 */   nop
.L80240DB0:
/* D50DA0 80240DB0 8E020084 */  lw        $v0, 0x84($s0)
/* D50DA4 80240DB4 0440000A */  bltz      $v0, .L80240DE0
/* D50DA8 80240DB8 00000000 */   nop
/* D50DAC 80240DBC 28420002 */  slti      $v0, $v0, 2
/* D50DB0 80240DC0 10400007 */  beqz      $v0, .L80240DE0
/* D50DB4 80240DC4 00000000 */   nop
.L80240DC8:
/* D50DB8 80240DC8 3C048024 */  lui       $a0, %hi(pra_02_SetPartnerFlags80000)
/* D50DBC 80240DCC 24840EB8 */  addiu     $a0, $a0, %lo(pra_02_SetPartnerFlags80000)
.L80240DD0:
/* D50DC0 80240DD0 0C048C56 */  jal       create_dynamic_entity_world
/* D50DC4 80240DD4 0000282D */   daddu    $a1, $zero, $zero
/* D50DC8 80240DD8 8E03013C */  lw        $v1, 0x13c($s0)
/* D50DCC 80240DDC AC620004 */  sw        $v0, 4($v1)
.L80240DE0:
/* D50DD0 80240DE0 0C00EAD2 */  jal       get_npc_safe
/* D50DD4 80240DE4 2404FFFC */   addiu    $a0, $zero, -4
/* D50DD8 80240DE8 0040282D */  daddu     $a1, $v0, $zero
/* D50DDC 80240DEC 10A00021 */  beqz      $a1, .L80240E74
/* D50DE0 80240DF0 24020002 */   addiu    $v0, $zero, 2
/* D50DE4 80240DF4 8E020088 */  lw        $v0, 0x88($s0)
/* D50DE8 80240DF8 14400014 */  bnez      $v0, .L80240E4C
/* D50DEC 80240DFC 24020001 */   addiu    $v0, $zero, 1
/* D50DF0 80240E00 8E040084 */  lw        $a0, 0x84($s0)
/* D50DF4 80240E04 10820016 */  beq       $a0, $v0, .L80240E60
/* D50DF8 80240E08 28820002 */   slti     $v0, $a0, 2
/* D50DFC 80240E0C 10400005 */  beqz      $v0, .L80240E24
/* D50E00 80240E10 24020002 */   addiu    $v0, $zero, 2
/* D50E04 80240E14 10800007 */  beqz      $a0, .L80240E34
/* D50E08 80240E18 00000000 */   nop
/* D50E0C 80240E1C 0809039D */  j         .L80240E74
/* D50E10 80240E20 00000000 */   nop
.L80240E24:
/* D50E14 80240E24 10820006 */  beq       $a0, $v0, .L80240E40
/* D50E18 80240E28 24020002 */   addiu    $v0, $zero, 2
/* D50E1C 80240E2C 0809039D */  j         .L80240E74
/* D50E20 80240E30 00000000 */   nop
.L80240E34:
/* D50E24 80240E34 8CA20000 */  lw        $v0, ($a1)
/* D50E28 80240E38 0809039A */  j         .L80240E68
/* D50E2C 80240E3C 3C03000A */   lui      $v1, 0xa
.L80240E40:
/* D50E30 80240E40 8CA20000 */  lw        $v0, ($a1)
/* D50E34 80240E44 0809039A */  j         .L80240E68
/* D50E38 80240E48 3C030002 */   lui      $v1, 2
.L80240E4C:
/* D50E3C 80240E4C 8E020084 */  lw        $v0, 0x84($s0)
/* D50E40 80240E50 04400007 */  bltz      $v0, .L80240E70
/* D50E44 80240E54 28420002 */   slti     $v0, $v0, 2
/* D50E48 80240E58 10400006 */  beqz      $v0, .L80240E74
/* D50E4C 80240E5C 24020002 */   addiu    $v0, $zero, 2
.L80240E60:
/* D50E50 80240E60 8CA20000 */  lw        $v0, ($a1)
/* D50E54 80240E64 3C030008 */  lui       $v1, 8
.L80240E68:
/* D50E58 80240E68 00431025 */  or        $v0, $v0, $v1
/* D50E5C 80240E6C ACA20000 */  sw        $v0, ($a1)
.L80240E70:
/* D50E60 80240E70 24020002 */  addiu     $v0, $zero, 2
.L80240E74:
/* D50E64 80240E74 8FBF0014 */  lw        $ra, 0x14($sp)
/* D50E68 80240E78 8FB00010 */  lw        $s0, 0x10($sp)
/* D50E6C 80240E7C 03E00008 */  jr        $ra
/* D50E70 80240E80 27BD0018 */   addiu    $sp, $sp, 0x18
