.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D6C_D93CAC
/* D93CAC 80240D6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D93CB0 80240D70 AFB00010 */  sw        $s0, 0x10($sp)
/* D93CB4 80240D74 0080802D */  daddu     $s0, $a0, $zero
/* D93CB8 80240D78 AFBF0014 */  sw        $ra, 0x14($sp)
/* D93CBC 80240D7C 8E020088 */  lw        $v0, 0x88($s0)
/* D93CC0 80240D80 14400017 */  bnez      $v0, .L80240DE0
/* D93CC4 80240D84 24020001 */   addiu    $v0, $zero, 1
/* D93CC8 80240D88 8E030084 */  lw        $v1, 0x84($s0)
/* D93CCC 80240D8C 1062001A */  beq       $v1, $v0, .L80240DF8
/* D93CD0 80240D90 00000000 */   nop
/* D93CD4 80240D94 28620002 */  slti      $v0, $v1, 2
/* D93CD8 80240D98 50400005 */  beql      $v0, $zero, .L80240DB0
/* D93CDC 80240D9C 24020002 */   addiu    $v0, $zero, 2
/* D93CE0 80240DA0 10600007 */  beqz      $v1, .L80240DC0
/* D93CE4 80240DA4 00000000 */   nop
/* D93CE8 80240DA8 08090384 */  j         .L80240E10
/* D93CEC 80240DAC 00000000 */   nop
.L80240DB0:
/* D93CF0 80240DB0 10620007 */  beq       $v1, $v0, .L80240DD0
/* D93CF4 80240DB4 00000000 */   nop
/* D93CF8 80240DB8 08090384 */  j         .L80240E10
/* D93CFC 80240DBC 00000000 */   nop
.L80240DC0:
/* D93D00 80240DC0 3C048024 */  lui       $a0, %hi(pra_37_SetPartnerFlagsA0000)
/* D93D04 80240DC4 24840EB4 */  addiu     $a0, $a0, %lo(pra_37_SetPartnerFlagsA0000)
/* D93D08 80240DC8 08090380 */  j         .L80240E00
/* D93D0C 80240DCC 00000000 */   nop
.L80240DD0:
/* D93D10 80240DD0 3C048024 */  lui       $a0, %hi(pra_37_SetPartnerFlags20000)
/* D93D14 80240DD4 24840F1C */  addiu     $a0, $a0, %lo(pra_37_SetPartnerFlags20000)
/* D93D18 80240DD8 08090380 */  j         .L80240E00
/* D93D1C 80240DDC 00000000 */   nop
.L80240DE0:
/* D93D20 80240DE0 8E020084 */  lw        $v0, 0x84($s0)
/* D93D24 80240DE4 0440000A */  bltz      $v0, .L80240E10
/* D93D28 80240DE8 00000000 */   nop
/* D93D2C 80240DEC 28420002 */  slti      $v0, $v0, 2
/* D93D30 80240DF0 10400007 */  beqz      $v0, .L80240E10
/* D93D34 80240DF4 00000000 */   nop
.L80240DF8:
/* D93D38 80240DF8 3C048024 */  lui       $a0, %hi(pra_37_SetPartnerFlags80000)
/* D93D3C 80240DFC 24840EE8 */  addiu     $a0, $a0, %lo(pra_37_SetPartnerFlags80000)
.L80240E00:
/* D93D40 80240E00 0C048C56 */  jal       create_dynamic_entity_world
/* D93D44 80240E04 0000282D */   daddu    $a1, $zero, $zero
/* D93D48 80240E08 8E03013C */  lw        $v1, 0x13c($s0)
/* D93D4C 80240E0C AC620004 */  sw        $v0, 4($v1)
.L80240E10:
/* D93D50 80240E10 0C00EAD2 */  jal       get_npc_safe
/* D93D54 80240E14 2404FFFC */   addiu    $a0, $zero, -4
/* D93D58 80240E18 0040282D */  daddu     $a1, $v0, $zero
/* D93D5C 80240E1C 10A00021 */  beqz      $a1, .L80240EA4
/* D93D60 80240E20 24020002 */   addiu    $v0, $zero, 2
/* D93D64 80240E24 8E020088 */  lw        $v0, 0x88($s0)
/* D93D68 80240E28 14400014 */  bnez      $v0, .L80240E7C
/* D93D6C 80240E2C 24020001 */   addiu    $v0, $zero, 1
/* D93D70 80240E30 8E040084 */  lw        $a0, 0x84($s0)
/* D93D74 80240E34 10820016 */  beq       $a0, $v0, .L80240E90
/* D93D78 80240E38 28820002 */   slti     $v0, $a0, 2
/* D93D7C 80240E3C 10400005 */  beqz      $v0, .L80240E54
/* D93D80 80240E40 24020002 */   addiu    $v0, $zero, 2
/* D93D84 80240E44 10800007 */  beqz      $a0, .L80240E64
/* D93D88 80240E48 00000000 */   nop
/* D93D8C 80240E4C 080903A9 */  j         .L80240EA4
/* D93D90 80240E50 00000000 */   nop
.L80240E54:
/* D93D94 80240E54 10820006 */  beq       $a0, $v0, .L80240E70
/* D93D98 80240E58 24020002 */   addiu    $v0, $zero, 2
/* D93D9C 80240E5C 080903A9 */  j         .L80240EA4
/* D93DA0 80240E60 00000000 */   nop
.L80240E64:
/* D93DA4 80240E64 8CA20000 */  lw        $v0, ($a1)
/* D93DA8 80240E68 080903A6 */  j         .L80240E98
/* D93DAC 80240E6C 3C03000A */   lui      $v1, 0xa
.L80240E70:
/* D93DB0 80240E70 8CA20000 */  lw        $v0, ($a1)
/* D93DB4 80240E74 080903A6 */  j         .L80240E98
/* D93DB8 80240E78 3C030002 */   lui      $v1, 2
.L80240E7C:
/* D93DBC 80240E7C 8E020084 */  lw        $v0, 0x84($s0)
/* D93DC0 80240E80 04400007 */  bltz      $v0, .L80240EA0
/* D93DC4 80240E84 28420002 */   slti     $v0, $v0, 2
/* D93DC8 80240E88 10400006 */  beqz      $v0, .L80240EA4
/* D93DCC 80240E8C 24020002 */   addiu    $v0, $zero, 2
.L80240E90:
/* D93DD0 80240E90 8CA20000 */  lw        $v0, ($a1)
/* D93DD4 80240E94 3C030008 */  lui       $v1, 8
.L80240E98:
/* D93DD8 80240E98 00431025 */  or        $v0, $v0, $v1
/* D93DDC 80240E9C ACA20000 */  sw        $v0, ($a1)
.L80240EA0:
/* D93DE0 80240EA0 24020002 */  addiu     $v0, $zero, 2
.L80240EA4:
/* D93DE4 80240EA4 8FBF0014 */  lw        $ra, 0x14($sp)
/* D93DE8 80240EA8 8FB00010 */  lw        $s0, 0x10($sp)
/* D93DEC 80240EAC 03E00008 */  jr        $ra
/* D93DF0 80240EB0 27BD0018 */   addiu    $sp, $sp, 0x18
