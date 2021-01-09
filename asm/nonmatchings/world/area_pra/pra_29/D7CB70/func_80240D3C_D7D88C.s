.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D3C_D7D88C
/* D7D88C 80240D3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7D890 80240D40 AFB00010 */  sw        $s0, 0x10($sp)
/* D7D894 80240D44 0080802D */  daddu     $s0, $a0, $zero
/* D7D898 80240D48 AFBF0014 */  sw        $ra, 0x14($sp)
/* D7D89C 80240D4C 8E020088 */  lw        $v0, 0x88($s0)
/* D7D8A0 80240D50 14400017 */  bnez      $v0, .L80240DB0
/* D7D8A4 80240D54 24020001 */   addiu    $v0, $zero, 1
/* D7D8A8 80240D58 8E030084 */  lw        $v1, 0x84($s0)
/* D7D8AC 80240D5C 1062001A */  beq       $v1, $v0, .L80240DC8
/* D7D8B0 80240D60 00000000 */   nop      
/* D7D8B4 80240D64 28620002 */  slti      $v0, $v1, 2
/* D7D8B8 80240D68 50400005 */  beql      $v0, $zero, .L80240D80
/* D7D8BC 80240D6C 24020002 */   addiu    $v0, $zero, 2
/* D7D8C0 80240D70 10600007 */  beqz      $v1, .L80240D90
/* D7D8C4 80240D74 00000000 */   nop      
/* D7D8C8 80240D78 08090378 */  j         .L80240DE0
/* D7D8CC 80240D7C 00000000 */   nop      
.L80240D80:
/* D7D8D0 80240D80 10620007 */  beq       $v1, $v0, .L80240DA0
/* D7D8D4 80240D84 00000000 */   nop      
/* D7D8D8 80240D88 08090378 */  j         .L80240DE0
/* D7D8DC 80240D8C 00000000 */   nop      
.L80240D90:
/* D7D8E0 80240D90 3C048024 */  lui       $a0, %hi(func_80240E84_D7CCB8)
/* D7D8E4 80240D94 24840E84 */  addiu     $a0, $a0, %lo(func_80240E84_D7CCB8)
/* D7D8E8 80240D98 08090374 */  j         .L80240DD0
/* D7D8EC 80240D9C 00000000 */   nop      
.L80240DA0:
/* D7D8F0 80240DA0 3C048024 */  lui       $a0, %hi(func_80240EEC_D7CD20)
/* D7D8F4 80240DA4 24840EEC */  addiu     $a0, $a0, %lo(func_80240EEC_D7CD20)
/* D7D8F8 80240DA8 08090374 */  j         .L80240DD0
/* D7D8FC 80240DAC 00000000 */   nop      
.L80240DB0:
/* D7D900 80240DB0 8E020084 */  lw        $v0, 0x84($s0)
/* D7D904 80240DB4 0440000A */  bltz      $v0, .L80240DE0
/* D7D908 80240DB8 00000000 */   nop      
/* D7D90C 80240DBC 28420002 */  slti      $v0, $v0, 2
/* D7D910 80240DC0 10400007 */  beqz      $v0, .L80240DE0
/* D7D914 80240DC4 00000000 */   nop      
.L80240DC8:
/* D7D918 80240DC8 3C048024 */  lui       $a0, %hi(func_80240EB8_D7CCEC)
/* D7D91C 80240DCC 24840EB8 */  addiu     $a0, $a0, %lo(func_80240EB8_D7CCEC)
.L80240DD0:
/* D7D920 80240DD0 0C048C56 */  jal       bind_dynamic_entity_3
/* D7D924 80240DD4 0000282D */   daddu    $a1, $zero, $zero
/* D7D928 80240DD8 8E03013C */  lw        $v1, 0x13c($s0)
/* D7D92C 80240DDC AC620004 */  sw        $v0, 4($v1)
.L80240DE0:
/* D7D930 80240DE0 0C00EAD2 */  jal       get_npc_safe
/* D7D934 80240DE4 2404FFFC */   addiu    $a0, $zero, -4
/* D7D938 80240DE8 0040282D */  daddu     $a1, $v0, $zero
/* D7D93C 80240DEC 10A00021 */  beqz      $a1, .L80240E74
/* D7D940 80240DF0 24020002 */   addiu    $v0, $zero, 2
/* D7D944 80240DF4 8E020088 */  lw        $v0, 0x88($s0)
/* D7D948 80240DF8 14400014 */  bnez      $v0, .L80240E4C
/* D7D94C 80240DFC 24020001 */   addiu    $v0, $zero, 1
/* D7D950 80240E00 8E040084 */  lw        $a0, 0x84($s0)
/* D7D954 80240E04 10820016 */  beq       $a0, $v0, .L80240E60
/* D7D958 80240E08 28820002 */   slti     $v0, $a0, 2
/* D7D95C 80240E0C 10400005 */  beqz      $v0, .L80240E24
/* D7D960 80240E10 24020002 */   addiu    $v0, $zero, 2
/* D7D964 80240E14 10800007 */  beqz      $a0, .L80240E34
/* D7D968 80240E18 00000000 */   nop      
/* D7D96C 80240E1C 0809039D */  j         .L80240E74
/* D7D970 80240E20 00000000 */   nop      
.L80240E24:
/* D7D974 80240E24 10820006 */  beq       $a0, $v0, .L80240E40
/* D7D978 80240E28 24020002 */   addiu    $v0, $zero, 2
/* D7D97C 80240E2C 0809039D */  j         .L80240E74
/* D7D980 80240E30 00000000 */   nop      
.L80240E34:
/* D7D984 80240E34 8CA20000 */  lw        $v0, ($a1)
/* D7D988 80240E38 0809039A */  j         .L80240E68
/* D7D98C 80240E3C 3C03000A */   lui      $v1, 0xa
.L80240E40:
/* D7D990 80240E40 8CA20000 */  lw        $v0, ($a1)
/* D7D994 80240E44 0809039A */  j         .L80240E68
/* D7D998 80240E48 3C030002 */   lui      $v1, 2
.L80240E4C:
/* D7D99C 80240E4C 8E020084 */  lw        $v0, 0x84($s0)
/* D7D9A0 80240E50 04400007 */  bltz      $v0, .L80240E70
/* D7D9A4 80240E54 28420002 */   slti     $v0, $v0, 2
/* D7D9A8 80240E58 10400006 */  beqz      $v0, .L80240E74
/* D7D9AC 80240E5C 24020002 */   addiu    $v0, $zero, 2
.L80240E60:
/* D7D9B0 80240E60 8CA20000 */  lw        $v0, ($a1)
/* D7D9B4 80240E64 3C030008 */  lui       $v1, 8
.L80240E68:
/* D7D9B8 80240E68 00431025 */  or        $v0, $v0, $v1
/* D7D9BC 80240E6C ACA20000 */  sw        $v0, ($a1)
.L80240E70:
/* D7D9C0 80240E70 24020002 */  addiu     $v0, $zero, 2
.L80240E74:
/* D7D9C4 80240E74 8FBF0014 */  lw        $ra, 0x14($sp)
/* D7D9C8 80240E78 8FB00010 */  lw        $s0, 0x10($sp)
/* D7D9CC 80240E7C 03E00008 */  jr        $ra
/* D7D9D0 80240E80 27BD0018 */   addiu    $sp, $sp, 0x18
