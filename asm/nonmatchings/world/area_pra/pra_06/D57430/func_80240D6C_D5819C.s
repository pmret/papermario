.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D6C_D5819C
/* D5819C 80240D6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D581A0 80240D70 AFB00010 */  sw        $s0, 0x10($sp)
/* D581A4 80240D74 0080802D */  daddu     $s0, $a0, $zero
/* D581A8 80240D78 AFBF0014 */  sw        $ra, 0x14($sp)
/* D581AC 80240D7C 8E020088 */  lw        $v0, 0x88($s0)
/* D581B0 80240D80 14400017 */  bnez      $v0, .L80240DE0
/* D581B4 80240D84 24020001 */   addiu    $v0, $zero, 1
/* D581B8 80240D88 8E030084 */  lw        $v1, 0x84($s0)
/* D581BC 80240D8C 1062001A */  beq       $v1, $v0, .L80240DF8
/* D581C0 80240D90 00000000 */   nop      
/* D581C4 80240D94 28620002 */  slti      $v0, $v1, 2
/* D581C8 80240D98 50400005 */  beql      $v0, $zero, .L80240DB0
/* D581CC 80240D9C 24020002 */   addiu    $v0, $zero, 2
/* D581D0 80240DA0 10600007 */  beqz      $v1, .L80240DC0
/* D581D4 80240DA4 00000000 */   nop      
/* D581D8 80240DA8 08090384 */  j         .L80240E10
/* D581DC 80240DAC 00000000 */   nop      
.L80240DB0:
/* D581E0 80240DB0 10620007 */  beq       $v1, $v0, .L80240DD0
/* D581E4 80240DB4 00000000 */   nop      
/* D581E8 80240DB8 08090384 */  j         .L80240E10
/* D581EC 80240DBC 00000000 */   nop      
.L80240DC0:
/* D581F0 80240DC0 3C048024 */  lui       $a0, %hi(pra_06_SetPartnerFlagsA0000)
/* D581F4 80240DC4 24840EB4 */  addiu     $a0, $a0, %lo(pra_06_SetPartnerFlagsA0000)
/* D581F8 80240DC8 08090380 */  j         .L80240E00
/* D581FC 80240DCC 00000000 */   nop      
.L80240DD0:
/* D58200 80240DD0 3C048024 */  lui       $a0, %hi(pra_06_SetPartnerFlags20000)
/* D58204 80240DD4 24840F1C */  addiu     $a0, $a0, %lo(pra_06_SetPartnerFlags20000)
/* D58208 80240DD8 08090380 */  j         .L80240E00
/* D5820C 80240DDC 00000000 */   nop      
.L80240DE0:
/* D58210 80240DE0 8E020084 */  lw        $v0, 0x84($s0)
/* D58214 80240DE4 0440000A */  bltz      $v0, .L80240E10
/* D58218 80240DE8 00000000 */   nop      
/* D5821C 80240DEC 28420002 */  slti      $v0, $v0, 2
/* D58220 80240DF0 10400007 */  beqz      $v0, .L80240E10
/* D58224 80240DF4 00000000 */   nop      
.L80240DF8:
/* D58228 80240DF8 3C048024 */  lui       $a0, %hi(pra_06_SetPartnerFlags80000)
/* D5822C 80240DFC 24840EE8 */  addiu     $a0, $a0, %lo(pra_06_SetPartnerFlags80000)
.L80240E00:
/* D58230 80240E00 0C048C56 */  jal       bind_dynamic_entity_3
/* D58234 80240E04 0000282D */   daddu    $a1, $zero, $zero
/* D58238 80240E08 8E03013C */  lw        $v1, 0x13c($s0)
/* D5823C 80240E0C AC620004 */  sw        $v0, 4($v1)
.L80240E10:
/* D58240 80240E10 0C00EAD2 */  jal       get_npc_safe
/* D58244 80240E14 2404FFFC */   addiu    $a0, $zero, -4
/* D58248 80240E18 0040282D */  daddu     $a1, $v0, $zero
/* D5824C 80240E1C 10A00021 */  beqz      $a1, .L80240EA4
/* D58250 80240E20 24020002 */   addiu    $v0, $zero, 2
/* D58254 80240E24 8E020088 */  lw        $v0, 0x88($s0)
/* D58258 80240E28 14400014 */  bnez      $v0, .L80240E7C
/* D5825C 80240E2C 24020001 */   addiu    $v0, $zero, 1
/* D58260 80240E30 8E040084 */  lw        $a0, 0x84($s0)
/* D58264 80240E34 10820016 */  beq       $a0, $v0, .L80240E90
/* D58268 80240E38 28820002 */   slti     $v0, $a0, 2
/* D5826C 80240E3C 10400005 */  beqz      $v0, .L80240E54
/* D58270 80240E40 24020002 */   addiu    $v0, $zero, 2
/* D58274 80240E44 10800007 */  beqz      $a0, .L80240E64
/* D58278 80240E48 00000000 */   nop      
/* D5827C 80240E4C 080903A9 */  j         .L80240EA4
/* D58280 80240E50 00000000 */   nop      
.L80240E54:
/* D58284 80240E54 10820006 */  beq       $a0, $v0, .L80240E70
/* D58288 80240E58 24020002 */   addiu    $v0, $zero, 2
/* D5828C 80240E5C 080903A9 */  j         .L80240EA4
/* D58290 80240E60 00000000 */   nop      
.L80240E64:
/* D58294 80240E64 8CA20000 */  lw        $v0, ($a1)
/* D58298 80240E68 080903A6 */  j         .L80240E98
/* D5829C 80240E6C 3C03000A */   lui      $v1, 0xa
.L80240E70:
/* D582A0 80240E70 8CA20000 */  lw        $v0, ($a1)
/* D582A4 80240E74 080903A6 */  j         .L80240E98
/* D582A8 80240E78 3C030002 */   lui      $v1, 2
.L80240E7C:
/* D582AC 80240E7C 8E020084 */  lw        $v0, 0x84($s0)
/* D582B0 80240E80 04400007 */  bltz      $v0, .L80240EA0
/* D582B4 80240E84 28420002 */   slti     $v0, $v0, 2
/* D582B8 80240E88 10400006 */  beqz      $v0, .L80240EA4
/* D582BC 80240E8C 24020002 */   addiu    $v0, $zero, 2
.L80240E90:
/* D582C0 80240E90 8CA20000 */  lw        $v0, ($a1)
/* D582C4 80240E94 3C030008 */  lui       $v1, 8
.L80240E98:
/* D582C8 80240E98 00431025 */  or        $v0, $v0, $v1
/* D582CC 80240E9C ACA20000 */  sw        $v0, ($a1)
.L80240EA0:
/* D582D0 80240EA0 24020002 */  addiu     $v0, $zero, 2
.L80240EA4:
/* D582D4 80240EA4 8FBF0014 */  lw        $ra, 0x14($sp)
/* D582D8 80240EA8 8FB00010 */  lw        $s0, 0x10($sp)
/* D582DC 80240EAC 03E00008 */  jr        $ra
/* D582E0 80240EB0 27BD0018 */   addiu    $sp, $sp, 0x18
