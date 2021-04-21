.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pra_11_ReflectPartner
/* D6223C 80240D3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D62240 80240D40 AFB00010 */  sw        $s0, 0x10($sp)
/* D62244 80240D44 0080802D */  daddu     $s0, $a0, $zero
/* D62248 80240D48 AFBF0014 */  sw        $ra, 0x14($sp)
/* D6224C 80240D4C 8E020088 */  lw        $v0, 0x88($s0)
/* D62250 80240D50 14400017 */  bnez      $v0, .L80240DB0
/* D62254 80240D54 24020001 */   addiu    $v0, $zero, 1
/* D62258 80240D58 8E030084 */  lw        $v1, 0x84($s0)
/* D6225C 80240D5C 1062001A */  beq       $v1, $v0, .L80240DC8
/* D62260 80240D60 00000000 */   nop
/* D62264 80240D64 28620002 */  slti      $v0, $v1, 2
/* D62268 80240D68 50400005 */  beql      $v0, $zero, .L80240D80
/* D6226C 80240D6C 24020002 */   addiu    $v0, $zero, 2
/* D62270 80240D70 10600007 */  beqz      $v1, .L80240D90
/* D62274 80240D74 00000000 */   nop
/* D62278 80240D78 08090378 */  j         .L80240DE0
/* D6227C 80240D7C 00000000 */   nop
.L80240D80:
/* D62280 80240D80 10620007 */  beq       $v1, $v0, .L80240DA0
/* D62284 80240D84 00000000 */   nop
/* D62288 80240D88 08090378 */  j         .L80240DE0
/* D6228C 80240D8C 00000000 */   nop
.L80240D90:
/* D62290 80240D90 3C048024 */  lui       $a0, %hi(pra_11_SetPartnerFlagsA0000)
/* D62294 80240D94 24840E84 */  addiu     $a0, $a0, %lo(pra_11_SetPartnerFlagsA0000)
/* D62298 80240D98 08090374 */  j         .L80240DD0
/* D6229C 80240D9C 00000000 */   nop
.L80240DA0:
/* D622A0 80240DA0 3C048024 */  lui       $a0, %hi(pra_11_SetPartnerFlags20000)
/* D622A4 80240DA4 24840EEC */  addiu     $a0, $a0, %lo(pra_11_SetPartnerFlags20000)
/* D622A8 80240DA8 08090374 */  j         .L80240DD0
/* D622AC 80240DAC 00000000 */   nop
.L80240DB0:
/* D622B0 80240DB0 8E020084 */  lw        $v0, 0x84($s0)
/* D622B4 80240DB4 0440000A */  bltz      $v0, .L80240DE0
/* D622B8 80240DB8 00000000 */   nop
/* D622BC 80240DBC 28420002 */  slti      $v0, $v0, 2
/* D622C0 80240DC0 10400007 */  beqz      $v0, .L80240DE0
/* D622C4 80240DC4 00000000 */   nop
.L80240DC8:
/* D622C8 80240DC8 3C048024 */  lui       $a0, %hi(pra_11_SetPartnerFlags80000)
/* D622CC 80240DCC 24840EB8 */  addiu     $a0, $a0, %lo(pra_11_SetPartnerFlags80000)
.L80240DD0:
/* D622D0 80240DD0 0C048C56 */  jal       create_dynamic_entity_world
/* D622D4 80240DD4 0000282D */   daddu    $a1, $zero, $zero
/* D622D8 80240DD8 8E03013C */  lw        $v1, 0x13c($s0)
/* D622DC 80240DDC AC620004 */  sw        $v0, 4($v1)
.L80240DE0:
/* D622E0 80240DE0 0C00EAD2 */  jal       get_npc_safe
/* D622E4 80240DE4 2404FFFC */   addiu    $a0, $zero, -4
/* D622E8 80240DE8 0040282D */  daddu     $a1, $v0, $zero
/* D622EC 80240DEC 10A00021 */  beqz      $a1, .L80240E74
/* D622F0 80240DF0 24020002 */   addiu    $v0, $zero, 2
/* D622F4 80240DF4 8E020088 */  lw        $v0, 0x88($s0)
/* D622F8 80240DF8 14400014 */  bnez      $v0, .L80240E4C
/* D622FC 80240DFC 24020001 */   addiu    $v0, $zero, 1
/* D62300 80240E00 8E040084 */  lw        $a0, 0x84($s0)
/* D62304 80240E04 10820016 */  beq       $a0, $v0, .L80240E60
/* D62308 80240E08 28820002 */   slti     $v0, $a0, 2
/* D6230C 80240E0C 10400005 */  beqz      $v0, .L80240E24
/* D62310 80240E10 24020002 */   addiu    $v0, $zero, 2
/* D62314 80240E14 10800007 */  beqz      $a0, .L80240E34
/* D62318 80240E18 00000000 */   nop
/* D6231C 80240E1C 0809039D */  j         .L80240E74
/* D62320 80240E20 00000000 */   nop
.L80240E24:
/* D62324 80240E24 10820006 */  beq       $a0, $v0, .L80240E40
/* D62328 80240E28 24020002 */   addiu    $v0, $zero, 2
/* D6232C 80240E2C 0809039D */  j         .L80240E74
/* D62330 80240E30 00000000 */   nop
.L80240E34:
/* D62334 80240E34 8CA20000 */  lw        $v0, ($a1)
/* D62338 80240E38 0809039A */  j         .L80240E68
/* D6233C 80240E3C 3C03000A */   lui      $v1, 0xa
.L80240E40:
/* D62340 80240E40 8CA20000 */  lw        $v0, ($a1)
/* D62344 80240E44 0809039A */  j         .L80240E68
/* D62348 80240E48 3C030002 */   lui      $v1, 2
.L80240E4C:
/* D6234C 80240E4C 8E020084 */  lw        $v0, 0x84($s0)
/* D62350 80240E50 04400007 */  bltz      $v0, .L80240E70
/* D62354 80240E54 28420002 */   slti     $v0, $v0, 2
/* D62358 80240E58 10400006 */  beqz      $v0, .L80240E74
/* D6235C 80240E5C 24020002 */   addiu    $v0, $zero, 2
.L80240E60:
/* D62360 80240E60 8CA20000 */  lw        $v0, ($a1)
/* D62364 80240E64 3C030008 */  lui       $v1, 8
.L80240E68:
/* D62368 80240E68 00431025 */  or        $v0, $v0, $v1
/* D6236C 80240E6C ACA20000 */  sw        $v0, ($a1)
.L80240E70:
/* D62370 80240E70 24020002 */  addiu     $v0, $zero, 2
.L80240E74:
/* D62374 80240E74 8FBF0014 */  lw        $ra, 0x14($sp)
/* D62378 80240E78 8FB00010 */  lw        $s0, 0x10($sp)
/* D6237C 80240E7C 03E00008 */  jr        $ra
/* D62380 80240E80 27BD0018 */   addiu    $sp, $sp, 0x18
