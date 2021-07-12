.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_42CF10
/* 42CF10 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42CF14 802A9004 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 42CF18 802A9008 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 42CF1C 802A900C 24020064 */  addiu     $v0, $zero, 0x64
/* 42CF20 802A9010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 42CF24 802A9014 AFB10014 */  sw        $s1, 0x14($sp)
/* 42CF28 802A9018 AFB00010 */  sw        $s0, 0x10($sp)
/* 42CF2C 802A901C A0620082 */  sb        $v0, 0x82($v1)
/* 42CF30 802A9020 3C028029 */  lui       $v0, %hi(D_802943A0)
/* 42CF34 802A9024 244243A0 */  addiu     $v0, $v0, %lo(D_802943A0)
/* 42CF38 802A9028 AC620434 */  sw        $v0, 0x434($v1)
/* 42CF3C 802A902C 80620083 */  lb        $v0, 0x83($v1)
/* 42CF40 802A9030 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42CF44 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42CF48 802A9038 5040006F */  beql      $v0, $zero, .L802A91F8
/* 42CF4C 802A903C A0600081 */   sb       $zero, 0x81($v1)
/* 42CF50 802A9040 0C09A216 */  jal       func_80268858
/* 42CF54 802A9044 00000000 */   nop
/* 42CF58 802A9048 24040064 */  addiu     $a0, $zero, 0x64
/* 42CF5C 802A904C 24020010 */  addiu     $v0, $zero, 0x10
/* 42CF60 802A9050 A622004A */  sh        $v0, 0x4a($s1)
/* 42CF64 802A9054 A620004C */  sh        $zero, 0x4c($s1)
/* 42CF68 802A9058 A2200060 */  sb        $zero, 0x60($s1)
/* 42CF6C 802A905C A6200044 */  sh        $zero, 0x44($s1)
/* 42CF70 802A9060 0C00A67F */  jal       rand_int
/* 42CF74 802A9064 A6200048 */   sh       $zero, 0x48($s1)
/* 42CF78 802A9068 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 42CF7C 802A906C 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 42CF80 802A9070 A6220046 */  sh        $v0, 0x46($s1)
/* 42CF84 802A9074 2402001E */  addiu     $v0, $zero, 0x1e
/* 42CF88 802A9078 A622006C */  sh        $v0, 0x6c($s1)
/* 42CF8C 802A907C 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 42CF90 802A9080 A6220056 */  sh        $v0, 0x56($s1)
/* 42CF94 802A9084 24020050 */  addiu     $v0, $zero, 0x50
/* 42CF98 802A9088 A6200068 */  sh        $zero, 0x68($s1)
/* 42CF9C 802A908C A6200066 */  sh        $zero, 0x66($s1)
/* 42CFA0 802A9090 3C01802B */  lui       $at, %hi(D_802A9B00)
/* 42CFA4 802A9094 AC209B00 */  sw        $zero, %lo(D_802A9B00)($at)
/* 42CFA8 802A9098 0C050529 */  jal       create_hud_element
/* 42CFAC 802A909C A6220058 */   sh       $v0, 0x58($s1)
/* 42CFB0 802A90A0 0040802D */  daddu     $s0, $v0, $zero
/* 42CFB4 802A90A4 0200202D */  daddu     $a0, $s0, $zero
/* 42CFB8 802A90A8 24050082 */  addiu     $a1, $zero, 0x82
/* 42CFBC 802A90AC 0C051280 */  jal       set_hud_element_flags
/* 42CFC0 802A90B0 AE300004 */   sw       $s0, 4($s1)
/* 42CFC4 802A90B4 86250056 */  lh        $a1, 0x56($s1)
/* 42CFC8 802A90B8 86260058 */  lh        $a2, 0x58($s1)
/* 42CFCC 802A90BC 0C051261 */  jal       set_hud_element_render_pos
/* 42CFD0 802A90C0 0200202D */   daddu    $a0, $s0, $zero
/* 42CFD4 802A90C4 0200202D */  daddu     $a0, $s0, $zero
/* 42CFD8 802A90C8 0C051277 */  jal       set_hud_element_render_depth
/* 42CFDC 802A90CC 0000282D */   daddu    $a1, $zero, $zero
/* 42CFE0 802A90D0 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 42CFE4 802A90D4 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 42CFE8 802A90D8 0C050529 */  jal       create_hud_element
/* 42CFEC 802A90DC 00000000 */   nop
/* 42CFF0 802A90E0 0040802D */  daddu     $s0, $v0, $zero
/* 42CFF4 802A90E4 86250056 */  lh        $a1, 0x56($s1)
/* 42CFF8 802A90E8 86260058 */  lh        $a2, 0x58($s1)
/* 42CFFC 802A90EC 0200202D */  daddu     $a0, $s0, $zero
/* 42D000 802A90F0 AE300008 */  sw        $s0, 8($s1)
/* 42D004 802A90F4 0C051261 */  jal       set_hud_element_render_pos
/* 42D008 802A90F8 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42D00C 802A90FC 0200202D */  daddu     $a0, $s0, $zero
/* 42D010 802A9100 0C051277 */  jal       set_hud_element_render_depth
/* 42D014 802A9104 0000282D */   daddu    $a1, $zero, $zero
/* 42D018 802A9108 0200202D */  daddu     $a0, $s0, $zero
/* 42D01C 802A910C 0C051280 */  jal       set_hud_element_flags
/* 42D020 802A9110 24050082 */   addiu    $a1, $zero, 0x82
/* 42D024 802A9114 3C048029 */  lui       $a0, %hi(D_80292974)
/* 42D028 802A9118 24842974 */  addiu     $a0, $a0, %lo(D_80292974)
/* 42D02C 802A911C 0C050529 */  jal       create_hud_element
/* 42D030 802A9120 00000000 */   nop
/* 42D034 802A9124 0040802D */  daddu     $s0, $v0, $zero
/* 42D038 802A9128 86250056 */  lh        $a1, 0x56($s1)
/* 42D03C 802A912C 86260058 */  lh        $a2, 0x58($s1)
/* 42D040 802A9130 0200202D */  daddu     $a0, $s0, $zero
/* 42D044 802A9134 AE300010 */  sw        $s0, 0x10($s1)
/* 42D048 802A9138 0C051261 */  jal       set_hud_element_render_pos
/* 42D04C 802A913C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42D050 802A9140 0200202D */  daddu     $a0, $s0, $zero
/* 42D054 802A9144 0C051277 */  jal       set_hud_element_render_depth
/* 42D058 802A9148 0000282D */   daddu    $a1, $zero, $zero
/* 42D05C 802A914C 0200202D */  daddu     $a0, $s0, $zero
/* 42D060 802A9150 0C051280 */  jal       set_hud_element_flags
/* 42D064 802A9154 24050082 */   addiu    $a1, $zero, 0x82
/* 42D068 802A9158 3C048011 */  lui       $a0, %hi(D_80109244)
/* 42D06C 802A915C 24849244 */  addiu     $a0, $a0, %lo(D_80109244)
/* 42D070 802A9160 0C050529 */  jal       create_hud_element
/* 42D074 802A9164 00000000 */   nop
/* 42D078 802A9168 0040802D */  daddu     $s0, $v0, $zero
/* 42D07C 802A916C 86250056 */  lh        $a1, 0x56($s1)
/* 42D080 802A9170 86260058 */  lh        $a2, 0x58($s1)
/* 42D084 802A9174 0200202D */  daddu     $a0, $s0, $zero
/* 42D088 802A9178 AE300014 */  sw        $s0, 0x14($s1)
/* 42D08C 802A917C 0C051261 */  jal       set_hud_element_render_pos
/* 42D090 802A9180 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42D094 802A9184 0200202D */  daddu     $a0, $s0, $zero
/* 42D098 802A9188 0C051277 */  jal       set_hud_element_render_depth
/* 42D09C 802A918C 0000282D */   daddu    $a1, $zero, $zero
/* 42D0A0 802A9190 0200202D */  daddu     $a0, $s0, $zero
/* 42D0A4 802A9194 0C051280 */  jal       set_hud_element_flags
/* 42D0A8 802A9198 24050082 */   addiu    $a1, $zero, 0x82
/* 42D0AC 802A919C 3C0451EB */  lui       $a0, 0x51eb
/* 42D0B0 802A91A0 3484851F */  ori       $a0, $a0, 0x851f
/* 42D0B4 802A91A4 24020064 */  addiu     $v0, $zero, 0x64
/* 42D0B8 802A91A8 86230046 */  lh        $v1, 0x46($s1)
/* 42D0BC 802A91AC 86260058 */  lh        $a2, 0x58($s1)
/* 42D0C0 802A91B0 00431023 */  subu      $v0, $v0, $v1
/* 42D0C4 802A91B4 00021900 */  sll       $v1, $v0, 4
/* 42D0C8 802A91B8 00621823 */  subu      $v1, $v1, $v0
/* 42D0CC 802A91BC 00031880 */  sll       $v1, $v1, 2
/* 42D0D0 802A91C0 00640018 */  mult      $v1, $a0
/* 42D0D4 802A91C4 2405001D */  addiu     $a1, $zero, 0x1d
/* 42D0D8 802A91C8 24C60011 */  addiu     $a2, $a2, 0x11
/* 42D0DC 802A91CC 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42D0E0 802A91D0 8E240010 */  lw        $a0, 0x10($s1)
/* 42D0E4 802A91D4 00003810 */  mfhi      $a3
/* 42D0E8 802A91D8 00071143 */  sra       $v0, $a3, 5
/* 42D0EC 802A91DC 00431023 */  subu      $v0, $v0, $v1
/* 42D0F0 802A91E0 86230056 */  lh        $v1, 0x56($s1)
/* 42D0F4 802A91E4 00A22823 */  subu      $a1, $a1, $v0
/* 42D0F8 802A91E8 0C051261 */  jal       set_hud_element_render_pos
/* 42D0FC 802A91EC 00652823 */   subu     $a1, $v1, $a1
/* 42D100 802A91F0 080AA47F */  j         .L802A91FC
/* 42D104 802A91F4 24020002 */   addiu    $v0, $zero, 2
.L802A91F8:
/* 42D108 802A91F8 24020002 */  addiu     $v0, $zero, 2
.L802A91FC:
/* 42D10C 802A91FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 42D110 802A9200 8FB10014 */  lw        $s1, 0x14($sp)
/* 42D114 802A9204 8FB00010 */  lw        $s0, 0x10($sp)
/* 42D118 802A9208 03E00008 */  jr        $ra
/* 42D11C 802A920C 27BD0020 */   addiu    $sp, $sp, 0x20
