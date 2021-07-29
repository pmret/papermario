.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_430020
/* 430020 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 430024 802A9004 AFB00010 */  sw        $s0, 0x10($sp)
/* 430028 802A9008 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 43002C 802A900C 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 430030 802A9010 24020064 */  addiu     $v0, $zero, 0x64
/* 430034 802A9014 AFBF0018 */  sw        $ra, 0x18($sp)
/* 430038 802A9018 AFB10014 */  sw        $s1, 0x14($sp)
/* 43003C 802A901C A2020082 */  sb        $v0, 0x82($s0)
/* 430040 802A9020 3C028029 */  lui       $v0, %hi(D_80294440)
/* 430044 802A9024 24424440 */  addiu     $v0, $v0, %lo(D_80294440)
/* 430048 802A9028 AE020434 */  sw        $v0, 0x434($s0)
/* 43004C 802A902C 2402007F */  addiu     $v0, $zero, 0x7f
/* 430050 802A9030 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 430054 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 430058 802A9038 A2020086 */  sb        $v0, 0x86($s0)
/* 43005C 802A903C 82020083 */  lb        $v0, 0x83($s0)
/* 430060 802A9040 10400047 */  beqz      $v0, .L802A9160
/* 430064 802A9044 0200182D */   daddu    $v1, $s0, $zero
/* 430068 802A9048 0C09A216 */  jal       func_80268858
/* 43006C 802A904C 00000000 */   nop
/* 430070 802A9050 3C048011 */  lui       $a0, %hi(D_80108E1C)
/* 430074 802A9054 24848E1C */  addiu     $a0, $a0, %lo(D_80108E1C)
/* 430078 802A9058 24020015 */  addiu     $v0, $zero, 0x15
/* 43007C 802A905C A622004A */  sh        $v0, 0x4a($s1)
/* 430080 802A9060 24020001 */  addiu     $v0, $zero, 1
/* 430084 802A9064 A2220061 */  sb        $v0, 0x61($s1)
/* 430088 802A9068 2402001E */  addiu     $v0, $zero, 0x1e
/* 43008C 802A906C A622006C */  sh        $v0, 0x6c($s1)
/* 430090 802A9070 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 430094 802A9074 A620004C */  sh        $zero, 0x4c($s1)
/* 430098 802A9078 A2200060 */  sb        $zero, 0x60($s1)
/* 43009C 802A907C A6200044 */  sh        $zero, 0x44($s1)
/* 4300A0 802A9080 A6200048 */  sh        $zero, 0x48($s1)
/* 4300A4 802A9084 A6200068 */  sh        $zero, 0x68($s1)
/* 4300A8 802A9088 A2000081 */  sb        $zero, 0x81($s0)
/* 4300AC 802A908C A2000084 */  sb        $zero, 0x84($s0)
/* 4300B0 802A9090 A6220056 */  sh        $v0, 0x56($s1)
/* 4300B4 802A9094 24020050 */  addiu     $v0, $zero, 0x50
/* 4300B8 802A9098 0C050529 */  jal       create_hud_element
/* 4300BC 802A909C A6220058 */   sh       $v0, 0x58($s1)
/* 4300C0 802A90A0 0040802D */  daddu     $s0, $v0, $zero
/* 4300C4 802A90A4 86250056 */  lh        $a1, 0x56($s1)
/* 4300C8 802A90A8 86260058 */  lh        $a2, 0x58($s1)
/* 4300CC 802A90AC 0200202D */  daddu     $a0, $s0, $zero
/* 4300D0 802A90B0 0C051261 */  jal       set_hud_element_render_pos
/* 4300D4 802A90B4 AE300004 */   sw       $s0, 4($s1)
/* 4300D8 802A90B8 0200202D */  daddu     $a0, $s0, $zero
/* 4300DC 802A90BC 0C051277 */  jal       set_hud_element_render_depth
/* 4300E0 802A90C0 0000282D */   daddu    $a1, $zero, $zero
/* 4300E4 802A90C4 0200202D */  daddu     $a0, $s0, $zero
/* 4300E8 802A90C8 0C051280 */  jal       set_hud_element_flags
/* 4300EC 802A90CC 24050082 */   addiu    $a1, $zero, 0x82
/* 4300F0 802A90D0 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 4300F4 802A90D4 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 4300F8 802A90D8 0C050529 */  jal       create_hud_element
/* 4300FC 802A90DC 00000000 */   nop
/* 430100 802A90E0 0040802D */  daddu     $s0, $v0, $zero
/* 430104 802A90E4 86250056 */  lh        $a1, 0x56($s1)
/* 430108 802A90E8 86260058 */  lh        $a2, 0x58($s1)
/* 43010C 802A90EC 0200202D */  daddu     $a0, $s0, $zero
/* 430110 802A90F0 AE300008 */  sw        $s0, 8($s1)
/* 430114 802A90F4 0C051261 */  jal       set_hud_element_render_pos
/* 430118 802A90F8 24C6001C */   addiu    $a2, $a2, 0x1c
/* 43011C 802A90FC 0200202D */  daddu     $a0, $s0, $zero
/* 430120 802A9100 0C051277 */  jal       set_hud_element_render_depth
/* 430124 802A9104 0000282D */   daddu    $a1, $zero, $zero
/* 430128 802A9108 0200202D */  daddu     $a0, $s0, $zero
/* 43012C 802A910C 0C051280 */  jal       set_hud_element_flags
/* 430130 802A9110 24050082 */   addiu    $a1, $zero, 0x82
/* 430134 802A9114 3C048029 */  lui       $a0, %hi(D_80292974)
/* 430138 802A9118 24842974 */  addiu     $a0, $a0, %lo(D_80292974)
/* 43013C 802A911C 0C050529 */  jal       create_hud_element
/* 430140 802A9120 00000000 */   nop
/* 430144 802A9124 0040802D */  daddu     $s0, $v0, $zero
/* 430148 802A9128 86250056 */  lh        $a1, 0x56($s1)
/* 43014C 802A912C 86260058 */  lh        $a2, 0x58($s1)
/* 430150 802A9130 0200202D */  daddu     $a0, $s0, $zero
/* 430154 802A9134 AE30000C */  sw        $s0, 0xc($s1)
/* 430158 802A9138 0C051261 */  jal       set_hud_element_render_pos
/* 43015C 802A913C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 430160 802A9140 0200202D */  daddu     $a0, $s0, $zero
/* 430164 802A9144 0C051277 */  jal       set_hud_element_render_depth
/* 430168 802A9148 0000282D */   daddu    $a1, $zero, $zero
/* 43016C 802A914C 0200202D */  daddu     $a0, $s0, $zero
/* 430170 802A9150 0C051280 */  jal       set_hud_element_flags
/* 430174 802A9154 24050082 */   addiu    $a1, $zero, 0x82
/* 430178 802A9158 080AA45A */  j         .L802A9168
/* 43017C 802A915C 24020002 */   addiu    $v0, $zero, 2
.L802A9160:
/* 430180 802A9160 A0600081 */  sb        $zero, 0x81($v1)
/* 430184 802A9164 24020002 */  addiu     $v0, $zero, 2
.L802A9168:
/* 430188 802A9168 8FBF0018 */  lw        $ra, 0x18($sp)
/* 43018C 802A916C 8FB10014 */  lw        $s1, 0x14($sp)
/* 430190 802A9170 8FB00010 */  lw        $s0, 0x10($sp)
/* 430194 802A9174 03E00008 */  jr        $ra
/* 430198 802A9178 27BD0020 */   addiu    $sp, $sp, 0x20
