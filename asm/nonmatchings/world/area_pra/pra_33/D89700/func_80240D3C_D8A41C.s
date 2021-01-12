.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D3C_D8A41C
/* D8A41C 80240D3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D8A420 80240D40 AFB00010 */  sw        $s0, 0x10($sp)
/* D8A424 80240D44 0080802D */  daddu     $s0, $a0, $zero
/* D8A428 80240D48 AFBF0014 */  sw        $ra, 0x14($sp)
/* D8A42C 80240D4C 8E020088 */  lw        $v0, 0x88($s0)
/* D8A430 80240D50 14400017 */  bnez      $v0, .L80240DB0
/* D8A434 80240D54 24020001 */   addiu    $v0, $zero, 1
/* D8A438 80240D58 8E030084 */  lw        $v1, 0x84($s0)
/* D8A43C 80240D5C 1062001A */  beq       $v1, $v0, .L80240DC8
/* D8A440 80240D60 00000000 */   nop      
/* D8A444 80240D64 28620002 */  slti      $v0, $v1, 2
/* D8A448 80240D68 50400005 */  beql      $v0, $zero, .L80240D80
/* D8A44C 80240D6C 24020002 */   addiu    $v0, $zero, 2
/* D8A450 80240D70 10600007 */  beqz      $v1, .L80240D90
/* D8A454 80240D74 00000000 */   nop      
/* D8A458 80240D78 08090378 */  j         .L80240DE0
/* D8A45C 80240D7C 00000000 */   nop      
.L80240D80:
/* D8A460 80240D80 10620007 */  beq       $v1, $v0, .L80240DA0
/* D8A464 80240D84 00000000 */   nop      
/* D8A468 80240D88 08090378 */  j         .L80240DE0
/* D8A46C 80240D8C 00000000 */   nop      
.L80240D90:
/* D8A470 80240D90 3C048024 */  lui       $a0, %hi(pra_33_SetPartnerFlagsA0000)
/* D8A474 80240D94 24840E84 */  addiu     $a0, $a0, %lo(pra_33_SetPartnerFlagsA0000)
/* D8A478 80240D98 08090374 */  j         .L80240DD0
/* D8A47C 80240D9C 00000000 */   nop      
.L80240DA0:
/* D8A480 80240DA0 3C048024 */  lui       $a0, %hi(pra_33_SetPartnerFlags20000)
/* D8A484 80240DA4 24840EEC */  addiu     $a0, $a0, %lo(pra_33_SetPartnerFlags20000)
/* D8A488 80240DA8 08090374 */  j         .L80240DD0
/* D8A48C 80240DAC 00000000 */   nop      
.L80240DB0:
/* D8A490 80240DB0 8E020084 */  lw        $v0, 0x84($s0)
/* D8A494 80240DB4 0440000A */  bltz      $v0, .L80240DE0
/* D8A498 80240DB8 00000000 */   nop      
/* D8A49C 80240DBC 28420002 */  slti      $v0, $v0, 2
/* D8A4A0 80240DC0 10400007 */  beqz      $v0, .L80240DE0
/* D8A4A4 80240DC4 00000000 */   nop      
.L80240DC8:
/* D8A4A8 80240DC8 3C048024 */  lui       $a0, %hi(pra_33_SetPartnerFlags80000)
/* D8A4AC 80240DCC 24840EB8 */  addiu     $a0, $a0, %lo(pra_33_SetPartnerFlags80000)
.L80240DD0:
/* D8A4B0 80240DD0 0C048C56 */  jal       bind_dynamic_entity_3
/* D8A4B4 80240DD4 0000282D */   daddu    $a1, $zero, $zero
/* D8A4B8 80240DD8 8E03013C */  lw        $v1, 0x13c($s0)
/* D8A4BC 80240DDC AC620004 */  sw        $v0, 4($v1)
.L80240DE0:
/* D8A4C0 80240DE0 0C00EAD2 */  jal       get_npc_safe
/* D8A4C4 80240DE4 2404FFFC */   addiu    $a0, $zero, -4
/* D8A4C8 80240DE8 0040282D */  daddu     $a1, $v0, $zero
/* D8A4CC 80240DEC 10A00021 */  beqz      $a1, .L80240E74
/* D8A4D0 80240DF0 24020002 */   addiu    $v0, $zero, 2
/* D8A4D4 80240DF4 8E020088 */  lw        $v0, 0x88($s0)
/* D8A4D8 80240DF8 14400014 */  bnez      $v0, .L80240E4C
/* D8A4DC 80240DFC 24020001 */   addiu    $v0, $zero, 1
/* D8A4E0 80240E00 8E040084 */  lw        $a0, 0x84($s0)
/* D8A4E4 80240E04 10820016 */  beq       $a0, $v0, .L80240E60
/* D8A4E8 80240E08 28820002 */   slti     $v0, $a0, 2
/* D8A4EC 80240E0C 10400005 */  beqz      $v0, .L80240E24
/* D8A4F0 80240E10 24020002 */   addiu    $v0, $zero, 2
/* D8A4F4 80240E14 10800007 */  beqz      $a0, .L80240E34
/* D8A4F8 80240E18 00000000 */   nop      
/* D8A4FC 80240E1C 0809039D */  j         .L80240E74
/* D8A500 80240E20 00000000 */   nop      
.L80240E24:
/* D8A504 80240E24 10820006 */  beq       $a0, $v0, .L80240E40
/* D8A508 80240E28 24020002 */   addiu    $v0, $zero, 2
/* D8A50C 80240E2C 0809039D */  j         .L80240E74
/* D8A510 80240E30 00000000 */   nop      
.L80240E34:
/* D8A514 80240E34 8CA20000 */  lw        $v0, ($a1)
/* D8A518 80240E38 0809039A */  j         .L80240E68
/* D8A51C 80240E3C 3C03000A */   lui      $v1, 0xa
.L80240E40:
/* D8A520 80240E40 8CA20000 */  lw        $v0, ($a1)
/* D8A524 80240E44 0809039A */  j         .L80240E68
/* D8A528 80240E48 3C030002 */   lui      $v1, 2
.L80240E4C:
/* D8A52C 80240E4C 8E020084 */  lw        $v0, 0x84($s0)
/* D8A530 80240E50 04400007 */  bltz      $v0, .L80240E70
/* D8A534 80240E54 28420002 */   slti     $v0, $v0, 2
/* D8A538 80240E58 10400006 */  beqz      $v0, .L80240E74
/* D8A53C 80240E5C 24020002 */   addiu    $v0, $zero, 2
.L80240E60:
/* D8A540 80240E60 8CA20000 */  lw        $v0, ($a1)
/* D8A544 80240E64 3C030008 */  lui       $v1, 8
.L80240E68:
/* D8A548 80240E68 00431025 */  or        $v0, $v0, $v1
/* D8A54C 80240E6C ACA20000 */  sw        $v0, ($a1)
.L80240E70:
/* D8A550 80240E70 24020002 */  addiu     $v0, $zero, 2
.L80240E74:
/* D8A554 80240E74 8FBF0014 */  lw        $ra, 0x14($sp)
/* D8A558 80240E78 8FB00010 */  lw        $s0, 0x10($sp)
/* D8A55C 80240E7C 03E00008 */  jr        $ra
/* D8A560 80240E80 27BD0018 */   addiu    $sp, $sp, 0x18
