.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D3C_D4DD7C
/* D4DD7C 80240D3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D4DD80 80240D40 AFB00010 */  sw        $s0, 0x10($sp)
/* D4DD84 80240D44 0080802D */  daddu     $s0, $a0, $zero
/* D4DD88 80240D48 AFBF0014 */  sw        $ra, 0x14($sp)
/* D4DD8C 80240D4C 8E020088 */  lw        $v0, 0x88($s0)
/* D4DD90 80240D50 14400017 */  bnez      $v0, .L80240DB0
/* D4DD94 80240D54 24020001 */   addiu    $v0, $zero, 1
/* D4DD98 80240D58 8E030084 */  lw        $v1, 0x84($s0)
/* D4DD9C 80240D5C 1062001A */  beq       $v1, $v0, .L80240DC8
/* D4DDA0 80240D60 00000000 */   nop
/* D4DDA4 80240D64 28620002 */  slti      $v0, $v1, 2
/* D4DDA8 80240D68 50400005 */  beql      $v0, $zero, .L80240D80
/* D4DDAC 80240D6C 24020002 */   addiu    $v0, $zero, 2
/* D4DDB0 80240D70 10600007 */  beqz      $v1, .L80240D90
/* D4DDB4 80240D74 00000000 */   nop
/* D4DDB8 80240D78 08090378 */  j         .L80240DE0
/* D4DDBC 80240D7C 00000000 */   nop
.L80240D80:
/* D4DDC0 80240D80 10620007 */  beq       $v1, $v0, .L80240DA0
/* D4DDC4 80240D84 00000000 */   nop
/* D4DDC8 80240D88 08090378 */  j         .L80240DE0
/* D4DDCC 80240D8C 00000000 */   nop
.L80240D90:
/* D4DDD0 80240D90 3C048024 */  lui       $a0, %hi(pra_01_SetPartnerFlagsA0000)
/* D4DDD4 80240D94 24840E84 */  addiu     $a0, $a0, %lo(pra_01_SetPartnerFlagsA0000)
/* D4DDD8 80240D98 08090374 */  j         .L80240DD0
/* D4DDDC 80240D9C 00000000 */   nop
.L80240DA0:
/* D4DDE0 80240DA0 3C048024 */  lui       $a0, %hi(pra_01_SetPartnerFlags20000)
/* D4DDE4 80240DA4 24840EEC */  addiu     $a0, $a0, %lo(pra_01_SetPartnerFlags20000)
/* D4DDE8 80240DA8 08090374 */  j         .L80240DD0
/* D4DDEC 80240DAC 00000000 */   nop
.L80240DB0:
/* D4DDF0 80240DB0 8E020084 */  lw        $v0, 0x84($s0)
/* D4DDF4 80240DB4 0440000A */  bltz      $v0, .L80240DE0
/* D4DDF8 80240DB8 00000000 */   nop
/* D4DDFC 80240DBC 28420002 */  slti      $v0, $v0, 2
/* D4DE00 80240DC0 10400007 */  beqz      $v0, .L80240DE0
/* D4DE04 80240DC4 00000000 */   nop
.L80240DC8:
/* D4DE08 80240DC8 3C048024 */  lui       $a0, %hi(pra_01_SetPartnerFlags80000)
/* D4DE0C 80240DCC 24840EB8 */  addiu     $a0, $a0, %lo(pra_01_SetPartnerFlags80000)
.L80240DD0:
/* D4DE10 80240DD0 0C048C56 */  jal       bind_dynamic_entity_3
/* D4DE14 80240DD4 0000282D */   daddu    $a1, $zero, $zero
/* D4DE18 80240DD8 8E03013C */  lw        $v1, 0x13c($s0)
/* D4DE1C 80240DDC AC620004 */  sw        $v0, 4($v1)
.L80240DE0:
/* D4DE20 80240DE0 0C00EAD2 */  jal       get_npc_safe
/* D4DE24 80240DE4 2404FFFC */   addiu    $a0, $zero, -4
/* D4DE28 80240DE8 0040282D */  daddu     $a1, $v0, $zero
/* D4DE2C 80240DEC 10A00021 */  beqz      $a1, .L80240E74
/* D4DE30 80240DF0 24020002 */   addiu    $v0, $zero, 2
/* D4DE34 80240DF4 8E020088 */  lw        $v0, 0x88($s0)
/* D4DE38 80240DF8 14400014 */  bnez      $v0, .L80240E4C
/* D4DE3C 80240DFC 24020001 */   addiu    $v0, $zero, 1
/* D4DE40 80240E00 8E040084 */  lw        $a0, 0x84($s0)
/* D4DE44 80240E04 10820016 */  beq       $a0, $v0, .L80240E60
/* D4DE48 80240E08 28820002 */   slti     $v0, $a0, 2
/* D4DE4C 80240E0C 10400005 */  beqz      $v0, .L80240E24
/* D4DE50 80240E10 24020002 */   addiu    $v0, $zero, 2
/* D4DE54 80240E14 10800007 */  beqz      $a0, .L80240E34
/* D4DE58 80240E18 00000000 */   nop
/* D4DE5C 80240E1C 0809039D */  j         .L80240E74
/* D4DE60 80240E20 00000000 */   nop
.L80240E24:
/* D4DE64 80240E24 10820006 */  beq       $a0, $v0, .L80240E40
/* D4DE68 80240E28 24020002 */   addiu    $v0, $zero, 2
/* D4DE6C 80240E2C 0809039D */  j         .L80240E74
/* D4DE70 80240E30 00000000 */   nop
.L80240E34:
/* D4DE74 80240E34 8CA20000 */  lw        $v0, ($a1)
/* D4DE78 80240E38 0809039A */  j         .L80240E68
/* D4DE7C 80240E3C 3C03000A */   lui      $v1, 0xa
.L80240E40:
/* D4DE80 80240E40 8CA20000 */  lw        $v0, ($a1)
/* D4DE84 80240E44 0809039A */  j         .L80240E68
/* D4DE88 80240E48 3C030002 */   lui      $v1, 2
.L80240E4C:
/* D4DE8C 80240E4C 8E020084 */  lw        $v0, 0x84($s0)
/* D4DE90 80240E50 04400007 */  bltz      $v0, .L80240E70
/* D4DE94 80240E54 28420002 */   slti     $v0, $v0, 2
/* D4DE98 80240E58 10400006 */  beqz      $v0, .L80240E74
/* D4DE9C 80240E5C 24020002 */   addiu    $v0, $zero, 2
.L80240E60:
/* D4DEA0 80240E60 8CA20000 */  lw        $v0, ($a1)
/* D4DEA4 80240E64 3C030008 */  lui       $v1, 8
.L80240E68:
/* D4DEA8 80240E68 00431025 */  or        $v0, $v0, $v1
/* D4DEAC 80240E6C ACA20000 */  sw        $v0, ($a1)
.L80240E70:
/* D4DEB0 80240E70 24020002 */  addiu     $v0, $zero, 2
.L80240E74:
/* D4DEB4 80240E74 8FBF0014 */  lw        $ra, 0x14($sp)
/* D4DEB8 80240E78 8FB00010 */  lw        $s0, 0x10($sp)
/* D4DEBC 80240E7C 03E00008 */  jr        $ra
/* D4DEC0 80240E80 27BD0018 */   addiu    $sp, $sp, 0x18
