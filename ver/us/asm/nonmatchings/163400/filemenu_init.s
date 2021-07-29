.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_init
/* 165140 802448E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 165144 802448E4 AFB40020 */  sw        $s4, 0x20($sp)
/* 165148 802448E8 0080A02D */  daddu     $s4, $a0, $zero
/* 16514C 802448EC 3C040013 */  lui       $a0, 0x13
/* 165150 802448F0 24841340 */  addiu     $a0, $a0, 0x1340
/* 165154 802448F4 3C050013 */  lui       $a1, 0x13
/* 165158 802448F8 24A55EE0 */  addiu     $a1, $a1, 0x5ee0
/* 16515C 802448FC 3C068024 */  lui       $a2, %hi(get_dpad_input_radial)
/* 165160 80244900 24C6E000 */  addiu     $a2, $a2, %lo(get_dpad_input_radial)
/* 165164 80244904 AFBF0028 */  sw        $ra, 0x28($sp)
/* 165168 80244908 AFB50024 */  sw        $s5, 0x24($sp)
/* 16516C 8024490C AFB3001C */  sw        $s3, 0x1c($sp)
/* 165170 80244910 AFB20018 */  sw        $s2, 0x18($sp)
/* 165174 80244914 AFB10014 */  sw        $s1, 0x14($sp)
/* 165178 80244918 0C00A5CF */  jal       dma_copy
/* 16517C 8024491C AFB00010 */   sw       $s0, 0x10($sp)
/* 165180 80244920 0000802D */  daddu     $s0, $zero, $zero
/* 165184 80244924 3C128025 */  lui       $s2, %hi(pause_partners_draw_movelist_flower)
/* 165188 80244928 2652C0A0 */  addiu     $s2, $s2, %lo(pause_partners_draw_movelist_flower)
/* 16518C 8024492C 3C118025 */  lui       $s1, %hi(D_80249B80)
/* 165190 80244930 26319B80 */  addiu     $s1, $s1, %lo(D_80249B80)
.L80244934:
/* 165194 80244934 8E240000 */  lw        $a0, ($s1)
/* 165198 80244938 26310004 */  addiu     $s1, $s1, 4
/* 16519C 8024493C 0C050529 */  jal       create_hud_element
/* 1651A0 80244940 26100001 */   addiu    $s0, $s0, 1
/* 1651A4 80244944 0040202D */  daddu     $a0, $v0, $zero
/* 1651A8 80244948 3C052000 */  lui       $a1, 0x2000
/* 1651AC 8024494C 34A50080 */  ori       $a1, $a1, 0x80
/* 1651B0 80244950 0C051280 */  jal       set_hud_element_flags
/* 1651B4 80244954 AE440000 */   sw       $a0, ($s2)
/* 1651B8 80244958 1A00FFF6 */  blez      $s0, .L80244934
/* 1651BC 8024495C 26520004 */   addiu    $s2, $s2, 4
/* 1651C0 80244960 3C028025 */  lui       $v0, %hi(pause_partners_draw_movelist_flower)
/* 1651C4 80244964 8C42C0A0 */  lw        $v0, %lo(pause_partners_draw_movelist_flower)($v0)
/* 1651C8 80244968 3C018025 */  lui       $at, %hi(D_8024C088)
/* 1651CC 8024496C AC22C088 */  sw        $v0, %lo(D_8024C088)($at)
/* 1651D0 80244970 16800004 */  bnez      $s4, .L80244984
/* 1651D4 80244974 00000000 */   nop
/* 1651D8 80244978 3C028025 */  lui       $v0, %hi(D_80249DCC)
/* 1651DC 8024497C 8C429DCC */  lw        $v0, %lo(D_80249DCC)($v0)
/* 1651E0 80244980 AC400000 */  sw        $zero, ($v0)
.L80244984:
/* 1651E4 80244984 3C048025 */  lui       $a0, %hi(D_80249DAC)
/* 1651E8 80244988 24849DAC */  addiu     $a0, $a0, %lo(D_80249DAC)
/* 1651EC 8024498C 0C051FCC */  jal       setup_pause_menu_tab
/* 1651F0 80244990 24050003 */   addiu    $a1, $zero, 3
/* 1651F4 80244994 3C138025 */  lui       $s3, %hi(D_80249B84)
/* 1651F8 80244998 8E739B84 */  lw        $s3, %lo(D_80249B84)($s3)
/* 1651FC 8024499C 3C018025 */  lui       $at, %hi(D_8024C098_C09918)
/* 165200 802449A0 A020C098 */  sb        $zero, %lo(D_8024C098_C09918)($at)
/* 165204 802449A4 16800003 */  bnez      $s4, .L802449B4
/* 165208 802449A8 24020002 */   addiu    $v0, $zero, 2
/* 16520C 802449AC 0809126E */  j         .L802449B8
/* 165210 802449B0 A2600004 */   sb       $zero, 4($s3)
.L802449B4:
/* 165214 802449B4 A2620004 */  sb        $v0, 4($s3)
.L802449B8:
/* 165218 802449B8 82620004 */  lb        $v0, 4($s3)
/* 16521C 802449BC 14400031 */  bnez      $v0, .L80244A84
/* 165220 802449C0 0260202D */   daddu    $a0, $s3, $zero
/* 165224 802449C4 0000802D */  daddu     $s0, $zero, $zero
/* 165228 802449C8 3C15800E */  lui       $s5, %hi(gCurrentSaveFile)
/* 16522C 802449CC 26B5ACC0 */  addiu     $s5, $s5, %lo(gCurrentSaveFile)
/* 165230 802449D0 24140001 */  addiu     $s4, $zero, 1
/* 165234 802449D4 3C118007 */  lui       $s1, %hi(D_80077A24)
/* 165238 802449D8 26317A24 */  addiu     $s1, $s1, %lo(D_80077A24)
/* 16523C 802449DC 3C128007 */  lui       $s2, %hi(D_800779C4)
/* 165240 802449E0 265279C4 */  addiu     $s2, $s2, %lo(D_800779C4)
.L802449E4:
/* 165244 802449E4 0C00ACB4 */  jal       fio_load_game
/* 165248 802449E8 0200202D */   daddu    $a0, $s0, $zero
/* 16524C 802449EC 14400003 */  bnez      $v0, .L802449FC
/* 165250 802449F0 00000000 */   nop
/* 165254 802449F4 0809128C */  j         .L80244A30
/* 165258 802449F8 A2200000 */   sb       $zero, ($s1)
.L802449FC:
/* 16525C 802449FC 8EA712EC */  lw        $a3, 0x12ec($s5)
/* 165260 80244A00 8EA812F0 */  lw        $t0, 0x12f0($s5)
/* 165264 80244A04 8EA912F4 */  lw        $t1, 0x12f4($s5)
/* 165268 80244A08 8EAA12F8 */  lw        $t2, 0x12f8($s5)
/* 16526C 80244A0C AE470000 */  sw        $a3, ($s2)
/* 165270 80244A10 AE480004 */  sw        $t0, 4($s2)
/* 165274 80244A14 AE490008 */  sw        $t1, 8($s2)
/* 165278 80244A18 AE4A000C */  sw        $t2, 0xc($s2)
/* 16527C 80244A1C 8EA712FC */  lw        $a3, 0x12fc($s5)
/* 165280 80244A20 8EA81300 */  lw        $t0, 0x1300($s5)
/* 165284 80244A24 AE470010 */  sw        $a3, 0x10($s2)
/* 165288 80244A28 AE480014 */  sw        $t0, 0x14($s2)
/* 16528C 80244A2C A2340000 */  sb        $s4, ($s1)
.L80244A30:
/* 165290 80244A30 26310001 */  addiu     $s1, $s1, 1
/* 165294 80244A34 26100001 */  addiu     $s0, $s0, 1
/* 165298 80244A38 2A020004 */  slti      $v0, $s0, 4
/* 16529C 80244A3C 1440FFE9 */  bnez      $v0, .L802449E4
/* 1652A0 80244A40 26520018 */   addiu    $s2, $s2, 0x18
/* 1652A4 80244A44 82620004 */  lb        $v0, 4($s3)
/* 1652A8 80244A48 1440000E */  bnez      $v0, .L80244A84
/* 1652AC 80244A4C 0260202D */   daddu    $a0, $s3, $zero
/* 1652B0 80244A50 0C00ABF6 */  jal       fio_has_valid_backup
/* 1652B4 80244A54 00000000 */   nop
/* 1652B8 80244A58 3C04800E */  lui       $a0, %hi(D_800D95E8)
/* 1652BC 80244A5C 248495E8 */  addiu     $a0, $a0, %lo(D_800D95E8)
/* 1652C0 80244A60 8C82003C */  lw        $v0, 0x3c($a0)
/* 1652C4 80244A64 2C420004 */  sltiu     $v0, $v0, 4
/* 1652C8 80244A68 50400001 */  beql      $v0, $zero, .L80244A70
/* 1652CC 80244A6C AC80003C */   sw       $zero, 0x3c($a0)
.L80244A70:
/* 1652D0 80244A70 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 1652D4 80244A74 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 1652D8 80244A78 9082003F */  lbu       $v0, 0x3f($a0)
/* 1652DC 80244A7C A0620166 */  sb        $v0, 0x166($v1)
/* 1652E0 80244A80 0260202D */  daddu     $a0, $s3, $zero
.L80244A84:
/* 1652E4 80244A84 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1652E8 80244A88 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 1652EC 80244A8C 3C118025 */  lui       $s1, %hi(D_80249B84)
/* 1652F0 80244A90 26319B84 */  addiu     $s1, $s1, %lo(D_80249B84)
/* 1652F4 80244A94 90460166 */  lbu       $a2, 0x166($v0)
/* 1652F8 80244A98 0000802D */  daddu     $s0, $zero, $zero
/* 1652FC 80244A9C 30C50001 */  andi      $a1, $a2, 1
/* 165300 80244AA0 00052840 */  sll       $a1, $a1, 1
/* 165304 80244AA4 0C090B65 */  jal       filemenu_set_selected
/* 165308 80244AA8 00063042 */   srl      $a2, $a2, 1
.L80244AAC:
/* 16530C 80244AAC 8E240000 */  lw        $a0, ($s1)
/* 165310 80244AB0 8C82000C */  lw        $v0, 0xc($a0)
/* 165314 80244AB4 10400003 */  beqz      $v0, .L80244AC4
/* 165318 80244AB8 26100001 */   addiu    $s0, $s0, 1
/* 16531C 80244ABC 0040F809 */  jalr      $v0
/* 165320 80244AC0 00000000 */   nop
.L80244AC4:
/* 165324 80244AC4 2A020004 */  slti      $v0, $s0, 4
/* 165328 80244AC8 1440FFF8 */  bnez      $v0, .L80244AAC
/* 16532C 80244ACC 26310004 */   addiu    $s1, $s1, 4
/* 165330 80244AD0 24040017 */  addiu     $a0, $zero, 0x17
/* 165334 80244AD4 0C051F5C */  jal       update_window_hierarchy
/* 165338 80244AD8 24050040 */   addiu    $a1, $zero, 0x40
/* 16533C 80244ADC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 165340 80244AE0 8FB50024 */  lw        $s5, 0x24($sp)
/* 165344 80244AE4 8FB40020 */  lw        $s4, 0x20($sp)
/* 165348 80244AE8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 16534C 80244AEC 8FB20018 */  lw        $s2, 0x18($sp)
/* 165350 80244AF0 8FB10014 */  lw        $s1, 0x14($sp)
/* 165354 80244AF4 8FB00010 */  lw        $s0, 0x10($sp)
/* 165358 80244AF8 03E00008 */  jr        $ra
/* 16535C 80244AFC 27BD0030 */   addiu    $sp, $sp, 0x30
