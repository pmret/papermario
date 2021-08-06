.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_4282E0
/* 4282E0 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4282E4 802A9004 AFB00010 */  sw        $s0, 0x10($sp)
/* 4282E8 802A9008 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 4282EC 802A900C 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 4282F0 802A9010 24020064 */  addiu     $v0, $zero, 0x64
/* 4282F4 802A9014 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4282F8 802A9018 AFB10014 */  sw        $s1, 0x14($sp)
/* 4282FC 802A901C A2020082 */  sb        $v0, 0x82($s0)
/* 428300 802A9020 3C028029 */  lui       $v0, %hi(D_80294320)
/* 428304 802A9024 24424320 */  addiu     $v0, $v0, %lo(D_80294320)
/* 428308 802A9028 AE020434 */  sw        $v0, 0x434($s0)
/* 42830C 802A902C 2402007F */  addiu     $v0, $zero, 0x7f
/* 428310 802A9030 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 428314 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 428318 802A9038 A2020086 */  sb        $v0, 0x86($s0)
/* 42831C 802A903C 82020083 */  lb        $v0, 0x83($s0)
/* 428320 802A9040 10400056 */  beqz      $v0, .L802A919C
/* 428324 802A9044 0200182D */   daddu    $v1, $s0, $zero
/* 428328 802A9048 0C09A216 */  jal       func_80268858
/* 42832C 802A904C 00000000 */   nop
/* 428330 802A9050 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 428334 802A9054 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 428338 802A9058 2402000C */  addiu     $v0, $zero, 0xc
/* 42833C 802A905C A622004A */  sh        $v0, 0x4a($s1)
/* 428340 802A9060 24020001 */  addiu     $v0, $zero, 1
/* 428344 802A9064 A2220061 */  sb        $v0, 0x61($s1)
/* 428348 802A9068 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 42834C 802A906C A620004C */  sh        $zero, 0x4c($s1)
/* 428350 802A9070 A2200060 */  sb        $zero, 0x60($s1)
/* 428354 802A9074 A6200044 */  sh        $zero, 0x44($s1)
/* 428358 802A9078 A6200048 */  sh        $zero, 0x48($s1)
/* 42835C 802A907C A6200068 */  sh        $zero, 0x68($s1)
/* 428360 802A9080 A2000081 */  sb        $zero, 0x81($s0)
/* 428364 802A9084 A6220056 */  sh        $v0, 0x56($s1)
/* 428368 802A9088 24020050 */  addiu     $v0, $zero, 0x50
/* 42836C 802A908C 0C050529 */  jal       create_hud_element
/* 428370 802A9090 A6220058 */   sh       $v0, 0x58($s1)
/* 428374 802A9094 0040802D */  daddu     $s0, $v0, $zero
/* 428378 802A9098 86250056 */  lh        $a1, 0x56($s1)
/* 42837C 802A909C 86260058 */  lh        $a2, 0x58($s1)
/* 428380 802A90A0 0200202D */  daddu     $a0, $s0, $zero
/* 428384 802A90A4 0C051261 */  jal       set_hud_element_render_pos
/* 428388 802A90A8 AE300004 */   sw       $s0, 4($s1)
/* 42838C 802A90AC 0200202D */  daddu     $a0, $s0, $zero
/* 428390 802A90B0 0C051277 */  jal       set_hud_element_render_depth
/* 428394 802A90B4 0000282D */   daddu    $a1, $zero, $zero
/* 428398 802A90B8 0200202D */  daddu     $a0, $s0, $zero
/* 42839C 802A90BC 0C051280 */  jal       set_hud_element_flags
/* 4283A0 802A90C0 24050082 */   addiu    $a1, $zero, 0x82
/* 4283A4 802A90C4 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 4283A8 802A90C8 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 4283AC 802A90CC 0C050529 */  jal       create_hud_element
/* 4283B0 802A90D0 00000000 */   nop
/* 4283B4 802A90D4 0040802D */  daddu     $s0, $v0, $zero
/* 4283B8 802A90D8 86250056 */  lh        $a1, 0x56($s1)
/* 4283BC 802A90DC 86260058 */  lh        $a2, 0x58($s1)
/* 4283C0 802A90E0 0200202D */  daddu     $a0, $s0, $zero
/* 4283C4 802A90E4 AE300008 */  sw        $s0, 8($s1)
/* 4283C8 802A90E8 0C051261 */  jal       set_hud_element_render_pos
/* 4283CC 802A90EC 24C6001C */   addiu    $a2, $a2, 0x1c
/* 4283D0 802A90F0 0200202D */  daddu     $a0, $s0, $zero
/* 4283D4 802A90F4 0C051277 */  jal       set_hud_element_render_depth
/* 4283D8 802A90F8 0000282D */   daddu    $a1, $zero, $zero
/* 4283DC 802A90FC 0200202D */  daddu     $a0, $s0, $zero
/* 4283E0 802A9100 0C051280 */  jal       set_hud_element_flags
/* 4283E4 802A9104 24050082 */   addiu    $a1, $zero, 0x82
/* 4283E8 802A9108 3C048029 */  lui       $a0, %hi(D_80292BAC)
/* 4283EC 802A910C 24842BAC */  addiu     $a0, $a0, %lo(D_80292BAC)
/* 4283F0 802A9110 0C050529 */  jal       create_hud_element
/* 4283F4 802A9114 00000000 */   nop
/* 4283F8 802A9118 0040802D */  daddu     $s0, $v0, $zero
/* 4283FC 802A911C 86250056 */  lh        $a1, 0x56($s1)
/* 428400 802A9120 86260058 */  lh        $a2, 0x58($s1)
/* 428404 802A9124 0200202D */  daddu     $a0, $s0, $zero
/* 428408 802A9128 AE300010 */  sw        $s0, 0x10($s1)
/* 42840C 802A912C 0C051261 */  jal       set_hud_element_render_pos
/* 428410 802A9130 24C6001C */   addiu    $a2, $a2, 0x1c
/* 428414 802A9134 0200202D */  daddu     $a0, $s0, $zero
/* 428418 802A9138 0C051277 */  jal       set_hud_element_render_depth
/* 42841C 802A913C 0000282D */   daddu    $a1, $zero, $zero
/* 428420 802A9140 0200202D */  daddu     $a0, $s0, $zero
/* 428424 802A9144 0C051280 */  jal       set_hud_element_flags
/* 428428 802A9148 24050082 */   addiu    $a1, $zero, 0x82
/* 42842C 802A914C 3C048029 */  lui       $a0, %hi(D_8029275C)
/* 428430 802A9150 2484275C */  addiu     $a0, $a0, %lo(D_8029275C)
/* 428434 802A9154 0C050529 */  jal       create_hud_element
/* 428438 802A9158 00000000 */   nop
/* 42843C 802A915C 0040802D */  daddu     $s0, $v0, $zero
/* 428440 802A9160 86250056 */  lh        $a1, 0x56($s1)
/* 428444 802A9164 86260058 */  lh        $a2, 0x58($s1)
/* 428448 802A9168 0200202D */  daddu     $a0, $s0, $zero
/* 42844C 802A916C AE30000C */  sw        $s0, 0xc($s1)
/* 428450 802A9170 24A50029 */  addiu     $a1, $a1, 0x29
/* 428454 802A9174 0C051261 */  jal       set_hud_element_render_pos
/* 428458 802A9178 24C60016 */   addiu    $a2, $a2, 0x16
/* 42845C 802A917C 0200202D */  daddu     $a0, $s0, $zero
/* 428460 802A9180 0C051277 */  jal       set_hud_element_render_depth
/* 428464 802A9184 0000282D */   daddu    $a1, $zero, $zero
/* 428468 802A9188 0200202D */  daddu     $a0, $s0, $zero
/* 42846C 802A918C 0C051280 */  jal       set_hud_element_flags
/* 428470 802A9190 24050080 */   addiu    $a1, $zero, 0x80
/* 428474 802A9194 080AA469 */  j         .L802A91A4
/* 428478 802A9198 24020002 */   addiu    $v0, $zero, 2
.L802A919C:
/* 42847C 802A919C A0600081 */  sb        $zero, 0x81($v1)
/* 428480 802A91A0 24020002 */  addiu     $v0, $zero, 2
.L802A91A4:
/* 428484 802A91A4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 428488 802A91A8 8FB10014 */  lw        $s1, 0x14($sp)
/* 42848C 802A91AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 428490 802A91B0 03E00008 */  jr        $ra
/* 428494 802A91B4 27BD0020 */   addiu    $sp, $sp, 0x20
