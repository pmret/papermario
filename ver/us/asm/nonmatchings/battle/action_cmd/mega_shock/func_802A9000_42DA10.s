.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_42DA10
/* 42DA10 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42DA14 802A9004 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 42DA18 802A9008 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 42DA1C 802A900C 24020005 */  addiu     $v0, $zero, 5
/* 42DA20 802A9010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 42DA24 802A9014 AFB10014 */  sw        $s1, 0x14($sp)
/* 42DA28 802A9018 AFB00010 */  sw        $s0, 0x10($sp)
/* 42DA2C 802A901C A0620082 */  sb        $v0, 0x82($v1)
/* 42DA30 802A9020 3C028029 */  lui       $v0, %hi(D_802943C0)
/* 42DA34 802A9024 244243C0 */  addiu     $v0, $v0, %lo(D_802943C0)
/* 42DA38 802A9028 AC620434 */  sw        $v0, 0x434($v1)
/* 42DA3C 802A902C 80620083 */  lb        $v0, 0x83($v1)
/* 42DA40 802A9030 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 42DA44 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 42DA48 802A9038 50400053 */  beql      $v0, $zero, .L802A9188
/* 42DA4C 802A903C A0600081 */   sb       $zero, 0x81($v1)
/* 42DA50 802A9040 0C09A216 */  jal       func_80268858
/* 42DA54 802A9044 00000000 */   nop
/* 42DA58 802A9048 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 42DA5C 802A904C 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 42DA60 802A9050 24020011 */  addiu     $v0, $zero, 0x11
/* 42DA64 802A9054 A622004A */  sh        $v0, 0x4a($s1)
/* 42DA68 802A9058 2402001E */  addiu     $v0, $zero, 0x1e
/* 42DA6C 802A905C A622006C */  sh        $v0, 0x6c($s1)
/* 42DA70 802A9060 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 42DA74 802A9064 A6220056 */  sh        $v0, 0x56($s1)
/* 42DA78 802A9068 24020050 */  addiu     $v0, $zero, 0x50
/* 42DA7C 802A906C A620004C */  sh        $zero, 0x4c($s1)
/* 42DA80 802A9070 A2200060 */  sb        $zero, 0x60($s1)
/* 42DA84 802A9074 A6200044 */  sh        $zero, 0x44($s1)
/* 42DA88 802A9078 A6200048 */  sh        $zero, 0x48($s1)
/* 42DA8C 802A907C A6200068 */  sh        $zero, 0x68($s1)
/* 42DA90 802A9080 0C050529 */  jal       create_hud_element
/* 42DA94 802A9084 A6220058 */   sh       $v0, 0x58($s1)
/* 42DA98 802A9088 0040802D */  daddu     $s0, $v0, $zero
/* 42DA9C 802A908C 0200202D */  daddu     $a0, $s0, $zero
/* 42DAA0 802A9090 24050082 */  addiu     $a1, $zero, 0x82
/* 42DAA4 802A9094 0C051280 */  jal       set_hud_element_flags
/* 42DAA8 802A9098 AE300004 */   sw       $s0, 4($s1)
/* 42DAAC 802A909C 86250056 */  lh        $a1, 0x56($s1)
/* 42DAB0 802A90A0 86260058 */  lh        $a2, 0x58($s1)
/* 42DAB4 802A90A4 0C051261 */  jal       set_hud_element_render_pos
/* 42DAB8 802A90A8 0200202D */   daddu    $a0, $s0, $zero
/* 42DABC 802A90AC 0200202D */  daddu     $a0, $s0, $zero
/* 42DAC0 802A90B0 0C051277 */  jal       set_hud_element_render_depth
/* 42DAC4 802A90B4 0000282D */   daddu    $a1, $zero, $zero
/* 42DAC8 802A90B8 3C048029 */  lui       $a0, %hi(D_8029231C)
/* 42DACC 802A90BC 2484231C */  addiu     $a0, $a0, %lo(D_8029231C)
/* 42DAD0 802A90C0 0C050529 */  jal       create_hud_element
/* 42DAD4 802A90C4 00000000 */   nop
/* 42DAD8 802A90C8 0040802D */  daddu     $s0, $v0, $zero
/* 42DADC 802A90CC 0200202D */  daddu     $a0, $s0, $zero
/* 42DAE0 802A90D0 24050082 */  addiu     $a1, $zero, 0x82
/* 42DAE4 802A90D4 0C051280 */  jal       set_hud_element_flags
/* 42DAE8 802A90D8 AE30000C */   sw       $s0, 0xc($s1)
/* 42DAEC 802A90DC 86250056 */  lh        $a1, 0x56($s1)
/* 42DAF0 802A90E0 86260058 */  lh        $a2, 0x58($s1)
/* 42DAF4 802A90E4 0C051261 */  jal       set_hud_element_render_pos
/* 42DAF8 802A90E8 0200202D */   daddu    $a0, $s0, $zero
/* 42DAFC 802A90EC 0200202D */  daddu     $a0, $s0, $zero
/* 42DB00 802A90F0 0C051277 */  jal       set_hud_element_render_depth
/* 42DB04 802A90F4 0000282D */   daddu    $a1, $zero, $zero
/* 42DB08 802A90F8 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 42DB0C 802A90FC 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 42DB10 802A9100 0C050529 */  jal       create_hud_element
/* 42DB14 802A9104 00000000 */   nop
/* 42DB18 802A9108 0040802D */  daddu     $s0, $v0, $zero
/* 42DB1C 802A910C 86250056 */  lh        $a1, 0x56($s1)
/* 42DB20 802A9110 86260058 */  lh        $a2, 0x58($s1)
/* 42DB24 802A9114 0200202D */  daddu     $a0, $s0, $zero
/* 42DB28 802A9118 AE300008 */  sw        $s0, 8($s1)
/* 42DB2C 802A911C 0C051261 */  jal       set_hud_element_render_pos
/* 42DB30 802A9120 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42DB34 802A9124 0200202D */  daddu     $a0, $s0, $zero
/* 42DB38 802A9128 0C051277 */  jal       set_hud_element_render_depth
/* 42DB3C 802A912C 0000282D */   daddu    $a1, $zero, $zero
/* 42DB40 802A9130 0200202D */  daddu     $a0, $s0, $zero
/* 42DB44 802A9134 0C051280 */  jal       set_hud_element_flags
/* 42DB48 802A9138 24050082 */   addiu    $a1, $zero, 0x82
/* 42DB4C 802A913C 3C048029 */  lui       $a0, %hi(D_80292974)
/* 42DB50 802A9140 24842974 */  addiu     $a0, $a0, %lo(D_80292974)
/* 42DB54 802A9144 0C050529 */  jal       create_hud_element
/* 42DB58 802A9148 00000000 */   nop
/* 42DB5C 802A914C 0040802D */  daddu     $s0, $v0, $zero
/* 42DB60 802A9150 86250056 */  lh        $a1, 0x56($s1)
/* 42DB64 802A9154 86260058 */  lh        $a2, 0x58($s1)
/* 42DB68 802A9158 0200202D */  daddu     $a0, $s0, $zero
/* 42DB6C 802A915C AE300014 */  sw        $s0, 0x14($s1)
/* 42DB70 802A9160 0C051261 */  jal       set_hud_element_render_pos
/* 42DB74 802A9164 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42DB78 802A9168 0200202D */  daddu     $a0, $s0, $zero
/* 42DB7C 802A916C 0C051277 */  jal       set_hud_element_render_depth
/* 42DB80 802A9170 0000282D */   daddu    $a1, $zero, $zero
/* 42DB84 802A9174 0200202D */  daddu     $a0, $s0, $zero
/* 42DB88 802A9178 0C051280 */  jal       set_hud_element_flags
/* 42DB8C 802A917C 24050082 */   addiu    $a1, $zero, 0x82
/* 42DB90 802A9180 080AA463 */  j         .L802A918C
/* 42DB94 802A9184 24020002 */   addiu    $v0, $zero, 2
.L802A9188:
/* 42DB98 802A9188 24020002 */  addiu     $v0, $zero, 2
.L802A918C:
/* 42DB9C 802A918C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 42DBA0 802A9190 8FB10014 */  lw        $s1, 0x14($sp)
/* 42DBA4 802A9194 8FB00010 */  lw        $s0, 0x10($sp)
/* 42DBA8 802A9198 03E00008 */  jr        $ra
/* 42DBAC 802A919C 27BD0020 */   addiu    $sp, $sp, 0x20
