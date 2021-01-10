.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_426170
/* 426170 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 426174 802A9004 AFB00010 */  sw        $s0, 0x10($sp)
/* 426178 802A9008 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 42617C 802A900C 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 426180 802A9010 24020064 */  addiu     $v0, $zero, 0x64
/* 426184 802A9014 AFBF0018 */  sw        $ra, 0x18($sp)
/* 426188 802A9018 AFB10014 */  sw        $s1, 0x14($sp)
/* 42618C 802A901C A2020082 */  sb        $v0, 0x82($s0)
/* 426190 802A9020 3C028029 */  lui       $v0, %hi(D_802942A0)
/* 426194 802A9024 244242A0 */  addiu     $v0, $v0, %lo(D_802942A0)
/* 426198 802A9028 AE020434 */  sw        $v0, 0x434($s0)
/* 42619C 802A902C 2402007F */  addiu     $v0, $zero, 0x7f
/* 4261A0 802A9030 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 4261A4 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 4261A8 802A9038 A2020086 */  sb        $v0, 0x86($s0)
/* 4261AC 802A903C 82020083 */  lb        $v0, 0x83($s0)
/* 4261B0 802A9040 10400044 */  beqz      $v0, .L802A9154
/* 4261B4 802A9044 0200182D */   daddu    $v1, $s0, $zero
/* 4261B8 802A9048 0C09A216 */  jal       func_80268858
/* 4261BC 802A904C 00000000 */   nop      
/* 4261C0 802A9050 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 4261C4 802A9054 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 4261C8 802A9058 24020008 */  addiu     $v0, $zero, 8
/* 4261CC 802A905C A622004A */  sh        $v0, 0x4a($s1)
/* 4261D0 802A9060 24020001 */  addiu     $v0, $zero, 1
/* 4261D4 802A9064 A2220061 */  sb        $v0, 0x61($s1)
/* 4261D8 802A9068 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 4261DC 802A906C A620004C */  sh        $zero, 0x4c($s1)
/* 4261E0 802A9070 A2200060 */  sb        $zero, 0x60($s1)
/* 4261E4 802A9074 A6200044 */  sh        $zero, 0x44($s1)
/* 4261E8 802A9078 A6200048 */  sh        $zero, 0x48($s1)
/* 4261EC 802A907C A6200068 */  sh        $zero, 0x68($s1)
/* 4261F0 802A9080 A2000081 */  sb        $zero, 0x81($s0)
/* 4261F4 802A9084 A6220056 */  sh        $v0, 0x56($s1)
/* 4261F8 802A9088 24020050 */  addiu     $v0, $zero, 0x50
/* 4261FC 802A908C 0C050529 */  jal       create_icon
/* 426200 802A9090 A6220058 */   sh       $v0, 0x58($s1)
/* 426204 802A9094 0040802D */  daddu     $s0, $v0, $zero
/* 426208 802A9098 86250056 */  lh        $a1, 0x56($s1)
/* 42620C 802A909C 86260058 */  lh        $a2, 0x58($s1)
/* 426210 802A90A0 0200202D */  daddu     $a0, $s0, $zero
/* 426214 802A90A4 0C051261 */  jal       set_icon_render_pos
/* 426218 802A90A8 AE300004 */   sw       $s0, 4($s1)
/* 42621C 802A90AC 0200202D */  daddu     $a0, $s0, $zero
/* 426220 802A90B0 0C051277 */  jal       func_801449DC
/* 426224 802A90B4 0000282D */   daddu    $a1, $zero, $zero
/* 426228 802A90B8 0200202D */  daddu     $a0, $s0, $zero
/* 42622C 802A90BC 0C051280 */  jal       set_icon_flags
/* 426230 802A90C0 24050082 */   addiu    $a1, $zero, 0x82
/* 426234 802A90C4 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 426238 802A90C8 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 42623C 802A90CC 0C050529 */  jal       create_icon
/* 426240 802A90D0 00000000 */   nop      
/* 426244 802A90D4 0040802D */  daddu     $s0, $v0, $zero
/* 426248 802A90D8 86250056 */  lh        $a1, 0x56($s1)
/* 42624C 802A90DC 86260058 */  lh        $a2, 0x58($s1)
/* 426250 802A90E0 0200202D */  daddu     $a0, $s0, $zero
/* 426254 802A90E4 AE300008 */  sw        $s0, 8($s1)
/* 426258 802A90E8 0C051261 */  jal       set_icon_render_pos
/* 42625C 802A90EC 24C6001C */   addiu    $a2, $a2, 0x1c
/* 426260 802A90F0 0200202D */  daddu     $a0, $s0, $zero
/* 426264 802A90F4 0C051277 */  jal       func_801449DC
/* 426268 802A90F8 0000282D */   daddu    $a1, $zero, $zero
/* 42626C 802A90FC 0200202D */  daddu     $a0, $s0, $zero
/* 426270 802A9100 0C051280 */  jal       set_icon_flags
/* 426274 802A9104 24050082 */   addiu    $a1, $zero, 0x82
/* 426278 802A9108 3C048029 */  lui       $a0, %hi(D_80292974)
/* 42627C 802A910C 24842974 */  addiu     $a0, $a0, %lo(D_80292974)
/* 426280 802A9110 0C050529 */  jal       create_icon
/* 426284 802A9114 00000000 */   nop      
/* 426288 802A9118 0040802D */  daddu     $s0, $v0, $zero
/* 42628C 802A911C 86250056 */  lh        $a1, 0x56($s1)
/* 426290 802A9120 86260058 */  lh        $a2, 0x58($s1)
/* 426294 802A9124 0200202D */  daddu     $a0, $s0, $zero
/* 426298 802A9128 AE30000C */  sw        $s0, 0xc($s1)
/* 42629C 802A912C 0C051261 */  jal       set_icon_render_pos
/* 4262A0 802A9130 24C6001C */   addiu    $a2, $a2, 0x1c
/* 4262A4 802A9134 0200202D */  daddu     $a0, $s0, $zero
/* 4262A8 802A9138 0C051277 */  jal       func_801449DC
/* 4262AC 802A913C 0000282D */   daddu    $a1, $zero, $zero
/* 4262B0 802A9140 0200202D */  daddu     $a0, $s0, $zero
/* 4262B4 802A9144 0C051280 */  jal       set_icon_flags
/* 4262B8 802A9148 24050082 */   addiu    $a1, $zero, 0x82
/* 4262BC 802A914C 080AA457 */  j         .L802A915C
/* 4262C0 802A9150 24020002 */   addiu    $v0, $zero, 2
.L802A9154:
/* 4262C4 802A9154 A0600081 */  sb        $zero, 0x81($v1)
/* 4262C8 802A9158 24020002 */  addiu     $v0, $zero, 2
.L802A915C:
/* 4262CC 802A915C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4262D0 802A9160 8FB10014 */  lw        $s1, 0x14($sp)
/* 4262D4 802A9164 8FB00010 */  lw        $s0, 0x10($sp)
/* 4262D8 802A9168 03E00008 */  jr        $ra
/* 4262DC 802A916C 27BD0020 */   addiu    $sp, $sp, 0x20
