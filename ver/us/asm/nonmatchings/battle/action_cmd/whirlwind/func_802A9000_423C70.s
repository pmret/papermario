.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_423C70
/* 423C70 802A9000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 423C74 802A9004 AFB3001C */  sw        $s3, 0x1c($sp)
/* 423C78 802A9008 0080982D */  daddu     $s3, $a0, $zero
/* 423C7C 802A900C AFB00010 */  sw        $s0, 0x10($sp)
/* 423C80 802A9010 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 423C84 802A9014 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 423C88 802A9018 AFBF0024 */  sw        $ra, 0x24($sp)
/* 423C8C 802A901C AFB40020 */  sw        $s4, 0x20($sp)
/* 423C90 802A9020 AFB20018 */  sw        $s2, 0x18($sp)
/* 423C94 802A9024 AFB10014 */  sw        $s1, 0x14($sp)
/* 423C98 802A9028 8E72000C */  lw        $s2, 0xc($s3)
/* 423C9C 802A902C 24020005 */  addiu     $v0, $zero, 5
/* 423CA0 802A9030 A2020082 */  sb        $v0, 0x82($s0)
/* 423CA4 802A9034 3C028029 */  lui       $v0, %hi(D_80294240)
/* 423CA8 802A9038 24424240 */  addiu     $v0, $v0, %lo(D_80294240)
/* 423CAC 802A903C 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 423CB0 802A9040 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 423CB4 802A9044 AE020434 */  sw        $v0, 0x434($s0)
/* 423CB8 802A9048 82020083 */  lb        $v0, 0x83($s0)
/* 423CBC 802A904C 14400003 */  bnez      $v0, .L802A905C
/* 423CC0 802A9050 0200A02D */   daddu    $s4, $s0, $zero
/* 423CC4 802A9054 080AA46F */  j         .L802A91BC
/* 423CC8 802A9058 A2000081 */   sb       $zero, 0x81($s0)
.L802A905C:
/* 423CCC 802A905C 0C09A216 */  jal       func_80268858
/* 423CD0 802A9060 00000000 */   nop
/* 423CD4 802A9064 8E450000 */  lw        $a1, ($s2)
/* 423CD8 802A9068 0C0B1EAF */  jal       evt_get_variable
/* 423CDC 802A906C 0260202D */   daddu    $a0, $s3, $zero
/* 423CE0 802A9070 24030005 */  addiu     $v1, $zero, 5
/* 423CE4 802A9074 A6220064 */  sh        $v0, 0x64($s1)
/* 423CE8 802A9078 00021400 */  sll       $v0, $v0, 0x10
/* 423CEC 802A907C A623004A */  sh        $v1, 0x4a($s1)
/* 423CF0 802A9080 A620004C */  sh        $zero, 0x4c($s1)
/* 423CF4 802A9084 A2200060 */  sb        $zero, 0x60($s1)
/* 423CF8 802A9088 A6200044 */  sh        $zero, 0x44($s1)
/* 423CFC 802A908C 14400003 */  bnez      $v0, .L802A909C
/* 423D00 802A9090 A6200048 */   sh       $zero, 0x48($s1)
/* 423D04 802A9094 080AA429 */  j         .L802A90A4
/* 423D08 802A9098 A2000084 */   sb       $zero, 0x84($s0)
.L802A909C:
/* 423D0C 802A909C 24020003 */  addiu     $v0, $zero, 3
/* 423D10 802A90A0 A2820084 */  sb        $v0, 0x84($s4)
.L802A90A4:
/* 423D14 802A90A4 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 423D18 802A90A8 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 423D1C 802A90AC 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 423D20 802A90B0 A6220056 */  sh        $v0, 0x56($s1)
/* 423D24 802A90B4 24020050 */  addiu     $v0, $zero, 0x50
/* 423D28 802A90B8 0C050529 */  jal       create_hud_element
/* 423D2C 802A90BC A6220058 */   sh       $v0, 0x58($s1)
/* 423D30 802A90C0 0040802D */  daddu     $s0, $v0, $zero
/* 423D34 802A90C4 0200202D */  daddu     $a0, $s0, $zero
/* 423D38 802A90C8 24050082 */  addiu     $a1, $zero, 0x82
/* 423D3C 802A90CC 0C051280 */  jal       set_hud_element_flags
/* 423D40 802A90D0 AE300004 */   sw       $s0, 4($s1)
/* 423D44 802A90D4 86250056 */  lh        $a1, 0x56($s1)
/* 423D48 802A90D8 86260058 */  lh        $a2, 0x58($s1)
/* 423D4C 802A90DC 0C051261 */  jal       set_hud_element_render_pos
/* 423D50 802A90E0 0200202D */   daddu    $a0, $s0, $zero
/* 423D54 802A90E4 0200202D */  daddu     $a0, $s0, $zero
/* 423D58 802A90E8 0C051277 */  jal       set_hud_element_render_depth
/* 423D5C 802A90EC 0000282D */   daddu    $a1, $zero, $zero
/* 423D60 802A90F0 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 423D64 802A90F4 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 423D68 802A90F8 0C050529 */  jal       create_hud_element
/* 423D6C 802A90FC 00000000 */   nop
/* 423D70 802A9100 0040802D */  daddu     $s0, $v0, $zero
/* 423D74 802A9104 86250056 */  lh        $a1, 0x56($s1)
/* 423D78 802A9108 86260058 */  lh        $a2, 0x58($s1)
/* 423D7C 802A910C 0200202D */  daddu     $a0, $s0, $zero
/* 423D80 802A9110 AE300008 */  sw        $s0, 8($s1)
/* 423D84 802A9114 0C051261 */  jal       set_hud_element_render_pos
/* 423D88 802A9118 24C6001C */   addiu    $a2, $a2, 0x1c
/* 423D8C 802A911C 0200202D */  daddu     $a0, $s0, $zero
/* 423D90 802A9120 0C051277 */  jal       set_hud_element_render_depth
/* 423D94 802A9124 0000282D */   daddu    $a1, $zero, $zero
/* 423D98 802A9128 0200202D */  daddu     $a0, $s0, $zero
/* 423D9C 802A912C 0C051280 */  jal       set_hud_element_flags
/* 423DA0 802A9130 24050082 */   addiu    $a1, $zero, 0x82
/* 423DA4 802A9134 3C04802B */  lui       $a0, %hi(D_802AA7F0_425460)
/* 423DA8 802A9138 0C050529 */  jal       create_hud_element
/* 423DAC 802A913C 2484A7F0 */   addiu    $a0, $a0, %lo(D_802AA7F0_425460)
/* 423DB0 802A9140 0040802D */  daddu     $s0, $v0, $zero
/* 423DB4 802A9144 86250056 */  lh        $a1, 0x56($s1)
/* 423DB8 802A9148 86260058 */  lh        $a2, 0x58($s1)
/* 423DBC 802A914C 0200202D */  daddu     $a0, $s0, $zero
/* 423DC0 802A9150 AE30000C */  sw        $s0, 0xc($s1)
/* 423DC4 802A9154 24A50036 */  addiu     $a1, $a1, 0x36
/* 423DC8 802A9158 0C051261 */  jal       set_hud_element_render_pos
/* 423DCC 802A915C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 423DD0 802A9160 0200202D */  daddu     $a0, $s0, $zero
/* 423DD4 802A9164 0C051277 */  jal       set_hud_element_render_depth
/* 423DD8 802A9168 0000282D */   daddu    $a1, $zero, $zero
/* 423DDC 802A916C 0200202D */  daddu     $a0, $s0, $zero
/* 423DE0 802A9170 0C051280 */  jal       set_hud_element_flags
/* 423DE4 802A9174 24050082 */   addiu    $a1, $zero, 0x82
/* 423DE8 802A9178 3C04802B */  lui       $a0, %hi(D_802AA818_425488)
/* 423DEC 802A917C 0C050529 */  jal       create_hud_element
/* 423DF0 802A9180 2484A818 */   addiu    $a0, $a0, %lo(D_802AA818_425488)
/* 423DF4 802A9184 0040802D */  daddu     $s0, $v0, $zero
/* 423DF8 802A9188 86250056 */  lh        $a1, 0x56($s1)
/* 423DFC 802A918C 86260058 */  lh        $a2, 0x58($s1)
/* 423E00 802A9190 0200202D */  daddu     $a0, $s0, $zero
/* 423E04 802A9194 AE300010 */  sw        $s0, 0x10($s1)
/* 423E08 802A9198 24A5003C */  addiu     $a1, $a1, 0x3c
/* 423E0C 802A919C 0C051261 */  jal       set_hud_element_render_pos
/* 423E10 802A91A0 24C6001C */   addiu    $a2, $a2, 0x1c
/* 423E14 802A91A4 0200202D */  daddu     $a0, $s0, $zero
/* 423E18 802A91A8 0C051277 */  jal       set_hud_element_render_depth
/* 423E1C 802A91AC 0000282D */   daddu    $a1, $zero, $zero
/* 423E20 802A91B0 0200202D */  daddu     $a0, $s0, $zero
/* 423E24 802A91B4 0C051280 */  jal       set_hud_element_flags
/* 423E28 802A91B8 24050082 */   addiu    $a1, $zero, 0x82
.L802A91BC:
/* 423E2C 802A91BC 24020002 */  addiu     $v0, $zero, 2
/* 423E30 802A91C0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 423E34 802A91C4 8FB40020 */  lw        $s4, 0x20($sp)
/* 423E38 802A91C8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 423E3C 802A91CC 8FB20018 */  lw        $s2, 0x18($sp)
/* 423E40 802A91D0 8FB10014 */  lw        $s1, 0x14($sp)
/* 423E44 802A91D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 423E48 802A91D8 03E00008 */  jr        $ra
/* 423E4C 802A91DC 27BD0028 */   addiu    $sp, $sp, 0x28
