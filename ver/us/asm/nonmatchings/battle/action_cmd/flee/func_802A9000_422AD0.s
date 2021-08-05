.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_422AD0
/* 422AD0 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 422AD4 802A9004 AFB00010 */  sw        $s0, 0x10($sp)
/* 422AD8 802A9008 0080802D */  daddu     $s0, $a0, $zero
/* 422ADC 802A900C AFB10014 */  sw        $s1, 0x14($sp)
/* 422AE0 802A9010 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 422AE4 802A9014 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 422AE8 802A9018 AFBF001C */  sw        $ra, 0x1c($sp)
/* 422AEC 802A901C AFB20018 */  sw        $s2, 0x18($sp)
/* 422AF0 802A9020 8E12000C */  lw        $s2, 0xc($s0)
/* 422AF4 802A9024 3C028029 */  lui       $v0, %hi(D_80294200)
/* 422AF8 802A9028 24424200 */  addiu     $v0, $v0, %lo(D_80294200)
/* 422AFC 802A902C AE220434 */  sw        $v0, 0x434($s1)
/* 422B00 802A9030 2402007F */  addiu     $v0, $zero, 0x7f
/* 422B04 802A9034 A2200082 */  sb        $zero, 0x82($s1)
/* 422B08 802A9038 0C09A216 */  jal       func_80268858
/* 422B0C 802A903C A2220086 */   sb       $v0, 0x86($s1)
/* 422B10 802A9040 8E450000 */  lw        $a1, ($s2)
/* 422B14 802A9044 0C0B1EAF */  jal       get_variable
/* 422B18 802A9048 0200202D */   daddu    $a0, $s0, $zero
/* 422B1C 802A904C 24040032 */  addiu     $a0, $zero, 0x32
/* 422B20 802A9050 3C10802A */  lui       $s0, %hi(gActionCommandStatus)
/* 422B24 802A9054 2610FBE0 */  addiu     $s0, $s0, %lo(gActionCommandStatus)
/* 422B28 802A9058 24030003 */  addiu     $v1, $zero, 3
/* 422B2C 802A905C A602005A */  sh        $v0, 0x5a($s0)
/* 422B30 802A9060 00021400 */  sll       $v0, $v0, 0x10
/* 422B34 802A9064 00021403 */  sra       $v0, $v0, 0x10
/* 422B38 802A9068 A603004A */  sh        $v1, 0x4a($s0)
/* 422B3C 802A906C 00021840 */  sll       $v1, $v0, 1
/* 422B40 802A9070 00621821 */  addu      $v1, $v1, $v0
/* 422B44 802A9074 000318C0 */  sll       $v1, $v1, 3
/* 422B48 802A9078 00621821 */  addu      $v1, $v1, $v0
/* 422B4C 802A907C 00031880 */  sll       $v1, $v1, 2
/* 422B50 802A9080 A600004C */  sh        $zero, 0x4c($s0)
/* 422B54 802A9084 A2000060 */  sb        $zero, 0x60($s0)
/* 422B58 802A9088 0C00A67F */  jal       rand_int
/* 422B5C 802A908C A6030044 */   sh       $v1, 0x44($s0)
/* 422B60 802A9090 24040001 */  addiu     $a0, $zero, 1
/* 422B64 802A9094 A6020046 */  sh        $v0, 0x46($s0)
/* 422B68 802A9098 0080102D */  daddu     $v0, $a0, $zero
/* 422B6C 802A909C A6000048 */  sh        $zero, 0x48($s0)
/* 422B70 802A90A0 0C00A67F */  jal       rand_int
/* 422B74 802A90A4 A202005C */   sb       $v0, 0x5c($s0)
/* 422B78 802A90A8 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 422B7C 802A90AC 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 422B80 802A90B0 A602005A */  sh        $v0, 0x5a($s0)
/* 422B84 802A90B4 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 422B88 802A90B8 A6000068 */  sh        $zero, 0x68($s0)
/* 422B8C 802A90BC A2200081 */  sb        $zero, 0x81($s1)
/* 422B90 802A90C0 A6020056 */  sh        $v0, 0x56($s0)
/* 422B94 802A90C4 24020050 */  addiu     $v0, $zero, 0x50
/* 422B98 802A90C8 3C01802B */  lui       $at, %hi(D_802A9920)
/* 422B9C 802A90CC AC209920 */  sw        $zero, %lo(D_802A9920)($at)
/* 422BA0 802A90D0 0C050529 */  jal       create_hud_element
/* 422BA4 802A90D4 A6020058 */   sh       $v0, 0x58($s0)
/* 422BA8 802A90D8 0040882D */  daddu     $s1, $v0, $zero
/* 422BAC 802A90DC 86050056 */  lh        $a1, 0x56($s0)
/* 422BB0 802A90E0 86060058 */  lh        $a2, 0x58($s0)
/* 422BB4 802A90E4 0220202D */  daddu     $a0, $s1, $zero
/* 422BB8 802A90E8 0C051261 */  jal       set_hud_element_render_pos
/* 422BBC 802A90EC AE110004 */   sw       $s1, 4($s0)
/* 422BC0 802A90F0 0220202D */  daddu     $a0, $s1, $zero
/* 422BC4 802A90F4 0C051277 */  jal       set_hud_element_render_depth
/* 422BC8 802A90F8 0000282D */   daddu    $a1, $zero, $zero
/* 422BCC 802A90FC 0220202D */  daddu     $a0, $s1, $zero
/* 422BD0 802A9100 0C051280 */  jal       set_hud_element_flags
/* 422BD4 802A9104 24050082 */   addiu    $a1, $zero, 0x82
/* 422BD8 802A9108 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 422BDC 802A910C 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 422BE0 802A9110 0C050529 */  jal       create_hud_element
/* 422BE4 802A9114 00000000 */   nop
/* 422BE8 802A9118 0040882D */  daddu     $s1, $v0, $zero
/* 422BEC 802A911C 86050056 */  lh        $a1, 0x56($s0)
/* 422BF0 802A9120 86060058 */  lh        $a2, 0x58($s0)
/* 422BF4 802A9124 0220202D */  daddu     $a0, $s1, $zero
/* 422BF8 802A9128 AE110008 */  sw        $s1, 8($s0)
/* 422BFC 802A912C 0C051261 */  jal       set_hud_element_render_pos
/* 422C00 802A9130 24C6001C */   addiu    $a2, $a2, 0x1c
/* 422C04 802A9134 0220202D */  daddu     $a0, $s1, $zero
/* 422C08 802A9138 0C051277 */  jal       set_hud_element_render_depth
/* 422C0C 802A913C 0000282D */   daddu    $a1, $zero, $zero
/* 422C10 802A9140 0220202D */  daddu     $a0, $s1, $zero
/* 422C14 802A9144 0C051280 */  jal       set_hud_element_flags
/* 422C18 802A9148 24050082 */   addiu    $a1, $zero, 0x82
/* 422C1C 802A914C 3C048029 */  lui       $a0, %hi(D_802928F8)
/* 422C20 802A9150 248428F8 */  addiu     $a0, $a0, %lo(D_802928F8)
/* 422C24 802A9154 0C050529 */  jal       create_hud_element
/* 422C28 802A9158 00000000 */   nop
/* 422C2C 802A915C 0040882D */  daddu     $s1, $v0, $zero
/* 422C30 802A9160 86050056 */  lh        $a1, 0x56($s0)
/* 422C34 802A9164 86060058 */  lh        $a2, 0x58($s0)
/* 422C38 802A9168 0220202D */  daddu     $a0, $s1, $zero
/* 422C3C 802A916C AE11000C */  sw        $s1, 0xc($s0)
/* 422C40 802A9170 0C051261 */  jal       set_hud_element_render_pos
/* 422C44 802A9174 24C6001C */   addiu    $a2, $a2, 0x1c
/* 422C48 802A9178 0220202D */  daddu     $a0, $s1, $zero
/* 422C4C 802A917C 0C051277 */  jal       set_hud_element_render_depth
/* 422C50 802A9180 0000282D */   daddu    $a1, $zero, $zero
/* 422C54 802A9184 0220202D */  daddu     $a0, $s1, $zero
/* 422C58 802A9188 0C051280 */  jal       set_hud_element_flags
/* 422C5C 802A918C 24050082 */   addiu    $a1, $zero, 0x82
/* 422C60 802A9190 3C048011 */  lui       $a0, %hi(D_80109244)
/* 422C64 802A9194 24849244 */  addiu     $a0, $a0, %lo(D_80109244)
/* 422C68 802A9198 0C050529 */  jal       create_hud_element
/* 422C6C 802A919C 00000000 */   nop
/* 422C70 802A91A0 0040882D */  daddu     $s1, $v0, $zero
/* 422C74 802A91A4 86050056 */  lh        $a1, 0x56($s0)
/* 422C78 802A91A8 86060058 */  lh        $a2, 0x58($s0)
/* 422C7C 802A91AC 0220202D */  daddu     $a0, $s1, $zero
/* 422C80 802A91B0 AE110010 */  sw        $s1, 0x10($s0)
/* 422C84 802A91B4 0C051261 */  jal       set_hud_element_render_pos
/* 422C88 802A91B8 24C6001C */   addiu    $a2, $a2, 0x1c
/* 422C8C 802A91BC 0220202D */  daddu     $a0, $s1, $zero
/* 422C90 802A91C0 0C051277 */  jal       set_hud_element_render_depth
/* 422C94 802A91C4 0000282D */   daddu    $a1, $zero, $zero
/* 422C98 802A91C8 0220202D */  daddu     $a0, $s1, $zero
/* 422C9C 802A91CC 0C051280 */  jal       set_hud_element_flags
/* 422CA0 802A91D0 24050082 */   addiu    $a1, $zero, 0x82
/* 422CA4 802A91D4 3C0451EB */  lui       $a0, 0x51eb
/* 422CA8 802A91D8 3484851F */  ori       $a0, $a0, 0x851f
/* 422CAC 802A91DC 24020064 */  addiu     $v0, $zero, 0x64
/* 422CB0 802A91E0 2411001D */  addiu     $s1, $zero, 0x1d
/* 422CB4 802A91E4 86030046 */  lh        $v1, 0x46($s0)
/* 422CB8 802A91E8 86060058 */  lh        $a2, 0x58($s0)
/* 422CBC 802A91EC 00431023 */  subu      $v0, $v0, $v1
/* 422CC0 802A91F0 00021900 */  sll       $v1, $v0, 4
/* 422CC4 802A91F4 00621823 */  subu      $v1, $v1, $v0
/* 422CC8 802A91F8 00031880 */  sll       $v1, $v1, 2
/* 422CCC 802A91FC 00640018 */  mult      $v1, $a0
/* 422CD0 802A9200 86050056 */  lh        $a1, 0x56($s0)
/* 422CD4 802A9204 24C60011 */  addiu     $a2, $a2, 0x11
/* 422CD8 802A9208 00031FC3 */  sra       $v1, $v1, 0x1f
/* 422CDC 802A920C 8E040010 */  lw        $a0, 0x10($s0)
/* 422CE0 802A9210 00003810 */  mfhi      $a3
/* 422CE4 802A9214 00071143 */  sra       $v0, $a3, 5
/* 422CE8 802A9218 00431023 */  subu      $v0, $v0, $v1
/* 422CEC 802A921C 02228823 */  subu      $s1, $s1, $v0
/* 422CF0 802A9220 0C051261 */  jal       set_hud_element_render_pos
/* 422CF4 802A9224 00B12823 */   subu     $a1, $a1, $s1
/* 422CF8 802A9228 8E04000C */  lw        $a0, 0xc($s0)
/* 422CFC 802A922C 86050056 */  lh        $a1, 0x56($s0)
/* 422D00 802A9230 86060058 */  lh        $a2, 0x58($s0)
/* 422D04 802A9234 00B12823 */  subu      $a1, $a1, $s1
/* 422D08 802A9238 0C051261 */  jal       set_hud_element_render_pos
/* 422D0C 802A923C 24C6FFFF */   addiu    $a2, $a2, -1
/* 422D10 802A9240 3C048029 */  lui       $a0, %hi(D_80292974)
/* 422D14 802A9244 24842974 */  addiu     $a0, $a0, %lo(D_80292974)
/* 422D18 802A9248 0C050529 */  jal       create_hud_element
/* 422D1C 802A924C 00000000 */   nop
/* 422D20 802A9250 0040882D */  daddu     $s1, $v0, $zero
/* 422D24 802A9254 86050056 */  lh        $a1, 0x56($s0)
/* 422D28 802A9258 86060058 */  lh        $a2, 0x58($s0)
/* 422D2C 802A925C 0220202D */  daddu     $a0, $s1, $zero
/* 422D30 802A9260 AE110014 */  sw        $s1, 0x14($s0)
/* 422D34 802A9264 0C051261 */  jal       set_hud_element_render_pos
/* 422D38 802A9268 24C6001C */   addiu    $a2, $a2, 0x1c
/* 422D3C 802A926C 0220202D */  daddu     $a0, $s1, $zero
/* 422D40 802A9270 0C051277 */  jal       set_hud_element_render_depth
/* 422D44 802A9274 0000282D */   daddu    $a1, $zero, $zero
/* 422D48 802A9278 0220202D */  daddu     $a0, $s1, $zero
/* 422D4C 802A927C 0C051280 */  jal       set_hud_element_flags
/* 422D50 802A9280 24050082 */   addiu    $a1, $zero, 0x82
/* 422D54 802A9284 8FBF001C */  lw        $ra, 0x1c($sp)
/* 422D58 802A9288 8FB20018 */  lw        $s2, 0x18($sp)
/* 422D5C 802A928C 8FB10014 */  lw        $s1, 0x14($sp)
/* 422D60 802A9290 8FB00010 */  lw        $s0, 0x10($sp)
/* 422D64 802A9294 24020002 */  addiu     $v0, $zero, 2
/* 422D68 802A9298 03E00008 */  jr        $ra
/* 422D6C 802A929C 27BD0020 */   addiu    $sp, $sp, 0x20
