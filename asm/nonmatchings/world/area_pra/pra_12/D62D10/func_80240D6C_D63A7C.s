.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D6C_D63A7C
/* D63A7C 80240D6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D63A80 80240D70 AFB00010 */  sw        $s0, 0x10($sp)
/* D63A84 80240D74 0080802D */  daddu     $s0, $a0, $zero
/* D63A88 80240D78 AFBF0014 */  sw        $ra, 0x14($sp)
/* D63A8C 80240D7C 8E020088 */  lw        $v0, 0x88($s0)
/* D63A90 80240D80 14400017 */  bnez      $v0, .L80240DE0
/* D63A94 80240D84 24020001 */   addiu    $v0, $zero, 1
/* D63A98 80240D88 8E030084 */  lw        $v1, 0x84($s0)
/* D63A9C 80240D8C 1062001A */  beq       $v1, $v0, .L80240DF8
/* D63AA0 80240D90 00000000 */   nop      
/* D63AA4 80240D94 28620002 */  slti      $v0, $v1, 2
/* D63AA8 80240D98 50400005 */  beql      $v0, $zero, .L80240DB0
/* D63AAC 80240D9C 24020002 */   addiu    $v0, $zero, 2
/* D63AB0 80240DA0 10600007 */  beqz      $v1, .L80240DC0
/* D63AB4 80240DA4 00000000 */   nop      
/* D63AB8 80240DA8 08090384 */  j         .L80240E10
/* D63ABC 80240DAC 00000000 */   nop      
.L80240DB0:
/* D63AC0 80240DB0 10620007 */  beq       $v1, $v0, .L80240DD0
/* D63AC4 80240DB4 00000000 */   nop      
/* D63AC8 80240DB8 08090384 */  j         .L80240E10
/* D63ACC 80240DBC 00000000 */   nop      
.L80240DC0:
/* D63AD0 80240DC0 3C048024 */  lui       $a0, %hi(func_80240EB4_D62E58)
/* D63AD4 80240DC4 24840EB4 */  addiu     $a0, $a0, %lo(func_80240EB4_D62E58)
/* D63AD8 80240DC8 08090380 */  j         .L80240E00
/* D63ADC 80240DCC 00000000 */   nop      
.L80240DD0:
/* D63AE0 80240DD0 3C048024 */  lui       $a0, %hi(func_80240F1C_D62EC0)
/* D63AE4 80240DD4 24840F1C */  addiu     $a0, $a0, %lo(func_80240F1C_D62EC0)
/* D63AE8 80240DD8 08090380 */  j         .L80240E00
/* D63AEC 80240DDC 00000000 */   nop      
.L80240DE0:
/* D63AF0 80240DE0 8E020084 */  lw        $v0, 0x84($s0)
/* D63AF4 80240DE4 0440000A */  bltz      $v0, .L80240E10
/* D63AF8 80240DE8 00000000 */   nop      
/* D63AFC 80240DEC 28420002 */  slti      $v0, $v0, 2
/* D63B00 80240DF0 10400007 */  beqz      $v0, .L80240E10
/* D63B04 80240DF4 00000000 */   nop      
.L80240DF8:
/* D63B08 80240DF8 3C048024 */  lui       $a0, %hi(func_80240EE8_D62E8C)
/* D63B0C 80240DFC 24840EE8 */  addiu     $a0, $a0, %lo(func_80240EE8_D62E8C)
.L80240E00:
/* D63B10 80240E00 0C048C56 */  jal       bind_dynamic_entity_3
/* D63B14 80240E04 0000282D */   daddu    $a1, $zero, $zero
/* D63B18 80240E08 8E03013C */  lw        $v1, 0x13c($s0)
/* D63B1C 80240E0C AC620004 */  sw        $v0, 4($v1)
.L80240E10:
/* D63B20 80240E10 0C00EAD2 */  jal       get_npc_safe
/* D63B24 80240E14 2404FFFC */   addiu    $a0, $zero, -4
/* D63B28 80240E18 0040282D */  daddu     $a1, $v0, $zero
/* D63B2C 80240E1C 10A00021 */  beqz      $a1, .L80240EA4
/* D63B30 80240E20 24020002 */   addiu    $v0, $zero, 2
/* D63B34 80240E24 8E020088 */  lw        $v0, 0x88($s0)
/* D63B38 80240E28 14400014 */  bnez      $v0, .L80240E7C
/* D63B3C 80240E2C 24020001 */   addiu    $v0, $zero, 1
/* D63B40 80240E30 8E040084 */  lw        $a0, 0x84($s0)
/* D63B44 80240E34 10820016 */  beq       $a0, $v0, .L80240E90
/* D63B48 80240E38 28820002 */   slti     $v0, $a0, 2
/* D63B4C 80240E3C 10400005 */  beqz      $v0, .L80240E54
/* D63B50 80240E40 24020002 */   addiu    $v0, $zero, 2
/* D63B54 80240E44 10800007 */  beqz      $a0, .L80240E64
/* D63B58 80240E48 00000000 */   nop      
/* D63B5C 80240E4C 080903A9 */  j         .L80240EA4
/* D63B60 80240E50 00000000 */   nop      
.L80240E54:
/* D63B64 80240E54 10820006 */  beq       $a0, $v0, .L80240E70
/* D63B68 80240E58 24020002 */   addiu    $v0, $zero, 2
/* D63B6C 80240E5C 080903A9 */  j         .L80240EA4
/* D63B70 80240E60 00000000 */   nop      
.L80240E64:
/* D63B74 80240E64 8CA20000 */  lw        $v0, ($a1)
/* D63B78 80240E68 080903A6 */  j         .L80240E98
/* D63B7C 80240E6C 3C03000A */   lui      $v1, 0xa
.L80240E70:
/* D63B80 80240E70 8CA20000 */  lw        $v0, ($a1)
/* D63B84 80240E74 080903A6 */  j         .L80240E98
/* D63B88 80240E78 3C030002 */   lui      $v1, 2
.L80240E7C:
/* D63B8C 80240E7C 8E020084 */  lw        $v0, 0x84($s0)
/* D63B90 80240E80 04400007 */  bltz      $v0, .L80240EA0
/* D63B94 80240E84 28420002 */   slti     $v0, $v0, 2
/* D63B98 80240E88 10400006 */  beqz      $v0, .L80240EA4
/* D63B9C 80240E8C 24020002 */   addiu    $v0, $zero, 2
.L80240E90:
/* D63BA0 80240E90 8CA20000 */  lw        $v0, ($a1)
/* D63BA4 80240E94 3C030008 */  lui       $v1, 8
.L80240E98:
/* D63BA8 80240E98 00431025 */  or        $v0, $v0, $v1
/* D63BAC 80240E9C ACA20000 */  sw        $v0, ($a1)
.L80240EA0:
/* D63BB0 80240EA0 24020002 */  addiu     $v0, $zero, 2
.L80240EA4:
/* D63BB4 80240EA4 8FBF0014 */  lw        $ra, 0x14($sp)
/* D63BB8 80240EA8 8FB00010 */  lw        $s0, 0x10($sp)
/* D63BBC 80240EAC 03E00008 */  jr        $ra
/* D63BC0 80240EB0 27BD0018 */   addiu    $sp, $sp, 0x18
