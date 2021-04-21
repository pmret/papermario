.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pra_14_ReflectPartner
/* D68A3C 80240D3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D68A40 80240D40 AFB00010 */  sw        $s0, 0x10($sp)
/* D68A44 80240D44 0080802D */  daddu     $s0, $a0, $zero
/* D68A48 80240D48 AFBF0014 */  sw        $ra, 0x14($sp)
/* D68A4C 80240D4C 8E020088 */  lw        $v0, 0x88($s0)
/* D68A50 80240D50 14400017 */  bnez      $v0, .L80240DB0
/* D68A54 80240D54 24020001 */   addiu    $v0, $zero, 1
/* D68A58 80240D58 8E030084 */  lw        $v1, 0x84($s0)
/* D68A5C 80240D5C 1062001A */  beq       $v1, $v0, .L80240DC8
/* D68A60 80240D60 00000000 */   nop
/* D68A64 80240D64 28620002 */  slti      $v0, $v1, 2
/* D68A68 80240D68 50400005 */  beql      $v0, $zero, .L80240D80
/* D68A6C 80240D6C 24020002 */   addiu    $v0, $zero, 2
/* D68A70 80240D70 10600007 */  beqz      $v1, .L80240D90
/* D68A74 80240D74 00000000 */   nop
/* D68A78 80240D78 08090378 */  j         .L80240DE0
/* D68A7C 80240D7C 00000000 */   nop
.L80240D80:
/* D68A80 80240D80 10620007 */  beq       $v1, $v0, .L80240DA0
/* D68A84 80240D84 00000000 */   nop
/* D68A88 80240D88 08090378 */  j         .L80240DE0
/* D68A8C 80240D8C 00000000 */   nop
.L80240D90:
/* D68A90 80240D90 3C048024 */  lui       $a0, %hi(pra_14_SetPartnerFlagsA0000)
/* D68A94 80240D94 24840E84 */  addiu     $a0, $a0, %lo(pra_14_SetPartnerFlagsA0000)
/* D68A98 80240D98 08090374 */  j         .L80240DD0
/* D68A9C 80240D9C 00000000 */   nop
.L80240DA0:
/* D68AA0 80240DA0 3C048024 */  lui       $a0, %hi(pra_14_SetPartnerFlags20000)
/* D68AA4 80240DA4 24840EEC */  addiu     $a0, $a0, %lo(pra_14_SetPartnerFlags20000)
/* D68AA8 80240DA8 08090374 */  j         .L80240DD0
/* D68AAC 80240DAC 00000000 */   nop
.L80240DB0:
/* D68AB0 80240DB0 8E020084 */  lw        $v0, 0x84($s0)
/* D68AB4 80240DB4 0440000A */  bltz      $v0, .L80240DE0
/* D68AB8 80240DB8 00000000 */   nop
/* D68ABC 80240DBC 28420002 */  slti      $v0, $v0, 2
/* D68AC0 80240DC0 10400007 */  beqz      $v0, .L80240DE0
/* D68AC4 80240DC4 00000000 */   nop
.L80240DC8:
/* D68AC8 80240DC8 3C048024 */  lui       $a0, %hi(pra_14_SetPartnerFlags80000)
/* D68ACC 80240DCC 24840EB8 */  addiu     $a0, $a0, %lo(pra_14_SetPartnerFlags80000)
.L80240DD0:
/* D68AD0 80240DD0 0C048C56 */  jal       create_dynamic_entity_world
/* D68AD4 80240DD4 0000282D */   daddu    $a1, $zero, $zero
/* D68AD8 80240DD8 8E03013C */  lw        $v1, 0x13c($s0)
/* D68ADC 80240DDC AC620004 */  sw        $v0, 4($v1)
.L80240DE0:
/* D68AE0 80240DE0 0C00EAD2 */  jal       get_npc_safe
/* D68AE4 80240DE4 2404FFFC */   addiu    $a0, $zero, -4
/* D68AE8 80240DE8 0040282D */  daddu     $a1, $v0, $zero
/* D68AEC 80240DEC 10A00021 */  beqz      $a1, .L80240E74
/* D68AF0 80240DF0 24020002 */   addiu    $v0, $zero, 2
/* D68AF4 80240DF4 8E020088 */  lw        $v0, 0x88($s0)
/* D68AF8 80240DF8 14400014 */  bnez      $v0, .L80240E4C
/* D68AFC 80240DFC 24020001 */   addiu    $v0, $zero, 1
/* D68B00 80240E00 8E040084 */  lw        $a0, 0x84($s0)
/* D68B04 80240E04 10820016 */  beq       $a0, $v0, .L80240E60
/* D68B08 80240E08 28820002 */   slti     $v0, $a0, 2
/* D68B0C 80240E0C 10400005 */  beqz      $v0, .L80240E24
/* D68B10 80240E10 24020002 */   addiu    $v0, $zero, 2
/* D68B14 80240E14 10800007 */  beqz      $a0, .L80240E34
/* D68B18 80240E18 00000000 */   nop
/* D68B1C 80240E1C 0809039D */  j         .L80240E74
/* D68B20 80240E20 00000000 */   nop
.L80240E24:
/* D68B24 80240E24 10820006 */  beq       $a0, $v0, .L80240E40
/* D68B28 80240E28 24020002 */   addiu    $v0, $zero, 2
/* D68B2C 80240E2C 0809039D */  j         .L80240E74
/* D68B30 80240E30 00000000 */   nop
.L80240E34:
/* D68B34 80240E34 8CA20000 */  lw        $v0, ($a1)
/* D68B38 80240E38 0809039A */  j         .L80240E68
/* D68B3C 80240E3C 3C03000A */   lui      $v1, 0xa
.L80240E40:
/* D68B40 80240E40 8CA20000 */  lw        $v0, ($a1)
/* D68B44 80240E44 0809039A */  j         .L80240E68
/* D68B48 80240E48 3C030002 */   lui      $v1, 2
.L80240E4C:
/* D68B4C 80240E4C 8E020084 */  lw        $v0, 0x84($s0)
/* D68B50 80240E50 04400007 */  bltz      $v0, .L80240E70
/* D68B54 80240E54 28420002 */   slti     $v0, $v0, 2
/* D68B58 80240E58 10400006 */  beqz      $v0, .L80240E74
/* D68B5C 80240E5C 24020002 */   addiu    $v0, $zero, 2
.L80240E60:
/* D68B60 80240E60 8CA20000 */  lw        $v0, ($a1)
/* D68B64 80240E64 3C030008 */  lui       $v1, 8
.L80240E68:
/* D68B68 80240E68 00431025 */  or        $v0, $v0, $v1
/* D68B6C 80240E6C ACA20000 */  sw        $v0, ($a1)
.L80240E70:
/* D68B70 80240E70 24020002 */  addiu     $v0, $zero, 2
.L80240E74:
/* D68B74 80240E74 8FBF0014 */  lw        $ra, 0x14($sp)
/* D68B78 80240E78 8FB00010 */  lw        $s0, 0x10($sp)
/* D68B7C 80240E7C 03E00008 */  jr        $ra
/* D68B80 80240E80 27BD0018 */   addiu    $sp, $sp, 0x18
