.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_422000
/* 422000 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 422004 802A9004 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 422008 802A9008 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 42200C 802A900C 24020001 */  addiu     $v0, $zero, 1
/* 422010 802A9010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 422014 802A9014 AFB10014 */  sw        $s1, 0x14($sp)
/* 422018 802A9018 AFB00010 */  sw        $s0, 0x10($sp)
/* 42201C 802A901C A0620082 */  sb        $v0, 0x82($v1)
/* 422020 802A9020 3C028029 */  lui       $v0, %hi(D_802941E0)
/* 422024 802A9024 244241E0 */  addiu     $v0, $v0, %lo(D_802941E0)
/* 422028 802A9028 AC620434 */  sw        $v0, 0x434($v1)
/* 42202C 802A902C 80620083 */  lb        $v0, 0x83($v1)
/* 422030 802A9030 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 422034 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 422038 802A9038 1040007F */  beqz      $v0, .L802A9238
/* 42203C 802A903C A0600086 */   sb       $zero, 0x86($v1)
/* 422040 802A9040 0C09A216 */  jal       func_80268858
/* 422044 802A9044 00000000 */   nop
/* 422048 802A9048 3C048029 */  lui       $a0, %hi(D_802922F0)
/* 42204C 802A904C 248422F0 */  addiu     $a0, $a0, %lo(D_802922F0)
/* 422050 802A9050 24020002 */  addiu     $v0, $zero, 2
/* 422054 802A9054 A622004A */  sh        $v0, 0x4a($s1)
/* 422058 802A9058 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 42205C 802A905C A6220056 */  sh        $v0, 0x56($s1)
/* 422060 802A9060 24020060 */  addiu     $v0, $zero, 0x60
/* 422064 802A9064 A620004C */  sh        $zero, 0x4c($s1)
/* 422068 802A9068 A2200060 */  sb        $zero, 0x60($s1)
/* 42206C 802A906C 0C050529 */  jal       create_icon
/* 422070 802A9070 A6220058 */   sh       $v0, 0x58($s1)
/* 422074 802A9074 0040802D */  daddu     $s0, $v0, $zero
/* 422078 802A9078 0200202D */  daddu     $a0, $s0, $zero
/* 42207C 802A907C 24050082 */  addiu     $a1, $zero, 0x82
/* 422080 802A9080 0C051280 */  jal       set_icon_flags
/* 422084 802A9084 AE300004 */   sw       $s0, 4($s1)
/* 422088 802A9088 86250056 */  lh        $a1, 0x56($s1)
/* 42208C 802A908C 86260058 */  lh        $a2, 0x58($s1)
/* 422090 802A9090 0C051261 */  jal       set_icon_render_pos
/* 422094 802A9094 0200202D */   daddu    $a0, $s0, $zero
/* 422098 802A9098 0200202D */  daddu     $a0, $s0, $zero
/* 42209C 802A909C 0C051277 */  jal       func_801449DC
/* 4220A0 802A90A0 2405000A */   addiu    $a1, $zero, 0xa
/* 4220A4 802A90A4 3C048029 */  lui       $a0, %hi(D_8029275C)
/* 4220A8 802A90A8 2484275C */  addiu     $a0, $a0, %lo(D_8029275C)
/* 4220AC 802A90AC 0C050529 */  jal       create_icon
/* 4220B0 802A90B0 00000000 */   nop
/* 4220B4 802A90B4 0040802D */  daddu     $s0, $v0, $zero
/* 4220B8 802A90B8 0200202D */  daddu     $a0, $s0, $zero
/* 4220BC 802A90BC 24050082 */  addiu     $a1, $zero, 0x82
/* 4220C0 802A90C0 0C051280 */  jal       set_icon_flags
/* 4220C4 802A90C4 AE300008 */   sw       $s0, 8($s1)
/* 4220C8 802A90C8 86250056 */  lh        $a1, 0x56($s1)
/* 4220CC 802A90CC 86260058 */  lh        $a2, 0x58($s1)
/* 4220D0 802A90D0 0C051261 */  jal       set_icon_render_pos
/* 4220D4 802A90D4 0200202D */   daddu    $a0, $s0, $zero
/* 4220D8 802A90D8 0200202D */  daddu     $a0, $s0, $zero
/* 4220DC 802A90DC 0C051277 */  jal       func_801449DC
/* 4220E0 802A90E0 0000282D */   daddu    $a1, $zero, $zero
/* 4220E4 802A90E4 3C048029 */  lui       $a0, %hi(D_802927F0)
/* 4220E8 802A90E8 248427F0 */  addiu     $a0, $a0, %lo(D_802927F0)
/* 4220EC 802A90EC 0C050529 */  jal       create_icon
/* 4220F0 802A90F0 00000000 */   nop
/* 4220F4 802A90F4 0040802D */  daddu     $s0, $v0, $zero
/* 4220F8 802A90F8 0200202D */  daddu     $a0, $s0, $zero
/* 4220FC 802A90FC 24050082 */  addiu     $a1, $zero, 0x82
/* 422100 802A9100 0C051280 */  jal       set_icon_flags
/* 422104 802A9104 AE30000C */   sw       $s0, 0xc($s1)
/* 422108 802A9108 86250056 */  lh        $a1, 0x56($s1)
/* 42210C 802A910C 86260058 */  lh        $a2, 0x58($s1)
/* 422110 802A9110 0C051261 */  jal       set_icon_render_pos
/* 422114 802A9114 0200202D */   daddu    $a0, $s0, $zero
/* 422118 802A9118 0200202D */  daddu     $a0, $s0, $zero
/* 42211C 802A911C 0C051277 */  jal       func_801449DC
/* 422120 802A9120 0000282D */   daddu    $a1, $zero, $zero
/* 422124 802A9124 3C048029 */  lui       $a0, %hi(D_80292848)
/* 422128 802A9128 24842848 */  addiu     $a0, $a0, %lo(D_80292848)
/* 42212C 802A912C 0C050529 */  jal       create_icon
/* 422130 802A9130 00000000 */   nop
/* 422134 802A9134 0040802D */  daddu     $s0, $v0, $zero
/* 422138 802A9138 0200202D */  daddu     $a0, $s0, $zero
/* 42213C 802A913C 24050082 */  addiu     $a1, $zero, 0x82
/* 422140 802A9140 0C051280 */  jal       set_icon_flags
/* 422144 802A9144 AE300010 */   sw       $s0, 0x10($s1)
/* 422148 802A9148 86250056 */  lh        $a1, 0x56($s1)
/* 42214C 802A914C 86260058 */  lh        $a2, 0x58($s1)
/* 422150 802A9150 0C051261 */  jal       set_icon_render_pos
/* 422154 802A9154 0200202D */   daddu    $a0, $s0, $zero
/* 422158 802A9158 0200202D */  daddu     $a0, $s0, $zero
/* 42215C 802A915C 0C051277 */  jal       func_801449DC
/* 422160 802A9160 0000282D */   daddu    $a1, $zero, $zero
/* 422164 802A9164 3C048029 */  lui       $a0, %hi(D_802928A0)
/* 422168 802A9168 248428A0 */  addiu     $a0, $a0, %lo(D_802928A0)
/* 42216C 802A916C 0C050529 */  jal       create_icon
/* 422170 802A9170 00000000 */   nop
/* 422174 802A9174 0040802D */  daddu     $s0, $v0, $zero
/* 422178 802A9178 0200202D */  daddu     $a0, $s0, $zero
/* 42217C 802A917C 24050082 */  addiu     $a1, $zero, 0x82
/* 422180 802A9180 0C051280 */  jal       set_icon_flags
/* 422184 802A9184 AE300014 */   sw       $s0, 0x14($s1)
/* 422188 802A9188 86250056 */  lh        $a1, 0x56($s1)
/* 42218C 802A918C 86260058 */  lh        $a2, 0x58($s1)
/* 422190 802A9190 0C051261 */  jal       set_icon_render_pos
/* 422194 802A9194 0200202D */   daddu    $a0, $s0, $zero
/* 422198 802A9198 0200202D */  daddu     $a0, $s0, $zero
/* 42219C 802A919C 0C051277 */  jal       func_801449DC
/* 4221A0 802A91A0 0000282D */   daddu    $a1, $zero, $zero
/* 4221A4 802A91A4 3C048011 */  lui       $a0, %hi(D_80108E48)
/* 4221A8 802A91A8 24848E48 */  addiu     $a0, $a0, %lo(D_80108E48)
/* 4221AC 802A91AC 0C050529 */  jal       create_icon
/* 4221B0 802A91B0 00000000 */   nop
/* 4221B4 802A91B4 0040802D */  daddu     $s0, $v0, $zero
/* 4221B8 802A91B8 0200202D */  daddu     $a0, $s0, $zero
/* 4221BC 802A91BC 24050082 */  addiu     $a1, $zero, 0x82
/* 4221C0 802A91C0 0C051280 */  jal       set_icon_flags
/* 4221C4 802A91C4 AE300018 */   sw       $s0, 0x18($s1)
/* 4221C8 802A91C8 86250056 */  lh        $a1, 0x56($s1)
/* 4221CC 802A91CC 86260058 */  lh        $a2, 0x58($s1)
/* 4221D0 802A91D0 0C051261 */  jal       set_icon_render_pos
/* 4221D4 802A91D4 0200202D */   daddu    $a0, $s0, $zero
/* 4221D8 802A91D8 0200202D */  daddu     $a0, $s0, $zero
/* 4221DC 802A91DC 0C051277 */  jal       func_801449DC
/* 4221E0 802A91E0 0000282D */   daddu    $a1, $zero, $zero
/* 4221E4 802A91E4 3C048029 */  lui       $a0, %hi(D_80292A2C)
/* 4221E8 802A91E8 24842A2C */  addiu     $a0, $a0, %lo(D_80292A2C)
/* 4221EC 802A91EC 0C050529 */  jal       create_icon
/* 4221F0 802A91F0 00000000 */   nop
/* 4221F4 802A91F4 0040802D */  daddu     $s0, $v0, $zero
/* 4221F8 802A91F8 0200202D */  daddu     $a0, $s0, $zero
/* 4221FC 802A91FC 24050082 */  addiu     $a1, $zero, 0x82
/* 422200 802A9200 0C051280 */  jal       set_icon_flags
/* 422204 802A9204 AE30001C */   sw       $s0, 0x1c($s1)
/* 422208 802A9208 86250056 */  lh        $a1, 0x56($s1)
/* 42220C 802A920C 86260058 */  lh        $a2, 0x58($s1)
/* 422210 802A9210 0C051261 */  jal       set_icon_render_pos
/* 422214 802A9214 0200202D */   daddu    $a0, $s0, $zero
/* 422218 802A9218 0200202D */  daddu     $a0, $s0, $zero
/* 42221C 802A921C 0C051277 */  jal       func_801449DC
/* 422220 802A9220 0000282D */   daddu    $a1, $zero, $zero
/* 422224 802A9224 0200202D */  daddu     $a0, $s0, $zero
/* 422228 802A9228 0C0513AC */  jal       icon_set_opacity
/* 42222C 802A922C 240500FF */   addiu    $a1, $zero, 0xff
/* 422230 802A9230 080AA491 */  j         .L802A9244
/* 422234 802A9234 24020002 */   addiu    $v0, $zero, 2
.L802A9238:
/* 422238 802A9238 24020002 */  addiu     $v0, $zero, 2
/* 42223C 802A923C A0600081 */  sb        $zero, 0x81($v1)
/* 422240 802A9240 A0600084 */  sb        $zero, 0x84($v1)
.L802A9244:
/* 422244 802A9244 8FBF0018 */  lw        $ra, 0x18($sp)
/* 422248 802A9248 8FB10014 */  lw        $s1, 0x14($sp)
/* 42224C 802A924C 8FB00010 */  lw        $s0, 0x10($sp)
/* 422250 802A9250 03E00008 */  jr        $ra
/* 422254 802A9254 27BD0020 */   addiu    $sp, $sp, 0x20
