.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_draw_contents_file_create_header
/* 168A18 802481B8 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 168A1C 802481BC AFB3002C */  sw        $s3, 0x2c($sp)
/* 168A20 802481C0 00A0982D */  daddu     $s3, $a1, $zero
/* 168A24 802481C4 AFB40030 */  sw        $s4, 0x30($sp)
/* 168A28 802481C8 00C0A02D */  daddu     $s4, $a2, $zero
/* 168A2C 802481CC 24040020 */  addiu     $a0, $zero, 0x20
/* 168A30 802481D0 AFBF0038 */  sw        $ra, 0x38($sp)
/* 168A34 802481D4 AFB50034 */  sw        $s5, 0x34($sp)
/* 168A38 802481D8 AFB20028 */  sw        $s2, 0x28($sp)
/* 168A3C 802481DC AFB10024 */  sw        $s1, 0x24($sp)
/* 168A40 802481E0 0C0926A9 */  jal       filemenu_get_menu_message
/* 168A44 802481E4 AFB00020 */   sw       $s0, 0x20($sp)
/* 168A48 802481E8 0040202D */  daddu     $a0, $v0, $zero
/* 168A4C 802481EC 2665000A */  addiu     $a1, $s3, 0xa
/* 168A50 802481F0 26860006 */  addiu     $a2, $s4, 6
/* 168A54 802481F4 240700FF */  addiu     $a3, $zero, 0xff
/* 168A58 802481F8 AFA00010 */  sw        $zero, 0x10($sp)
/* 168A5C 802481FC 0C09265F */  jal       filemenu_draw_message
/* 168A60 80248200 AFA00014 */   sw       $zero, 0x14($sp)
/* 168A64 80248204 3C048025 */  lui       $a0, %hi(D_8024C110)
/* 168A68 80248208 2484C110 */  addiu     $a0, $a0, %lo(D_8024C110)
/* 168A6C 8024820C 24050008 */  addiu     $a1, $zero, 8
/* 168A70 80248210 26660024 */  addiu     $a2, $s3, 0x24
/* 168A74 80248214 26870016 */  addiu     $a3, $s4, 0x16
/* 168A78 80248218 240200FF */  addiu     $v0, $zero, 0xff
/* 168A7C 8024821C AFA20010 */  sw        $v0, 0x10($sp)
/* 168A80 80248220 2402000B */  addiu     $v0, $zero, 0xb
/* 168A84 80248224 AFA00014 */  sw        $zero, 0x14($sp)
/* 168A88 80248228 AFA00018 */  sw        $zero, 0x18($sp)
/* 168A8C 8024822C 0C0926AE */  jal       filemenu_draw_file_name
/* 168A90 80248230 AFA2001C */   sw       $v0, 0x1c($sp)
/* 168A94 80248234 24150029 */  addiu     $s5, $zero, 0x29
/* 168A98 80248238 0000802D */  daddu     $s0, $zero, $zero
/* 168A9C 8024823C 3C128025 */  lui       $s2, %hi(D_8024C100_C09980)
/* 168AA0 80248240 2652C100 */  addiu     $s2, $s2, %lo(D_8024C100_C09980)
/* 168AA4 80248244 2411002A */  addiu     $s1, $zero, 0x2a
.L80248248:
/* 168AA8 80248248 8E440004 */  lw        $a0, 4($s2)
/* 168AAC 8024824C 02712821 */  addu      $a1, $s3, $s1
/* 168AB0 80248250 0C051261 */  jal       set_hud_element_render_pos
/* 168AB4 80248254 02953021 */   addu     $a2, $s4, $s5
/* 168AB8 80248258 16000006 */  bnez      $s0, .L80248274
/* 168ABC 8024825C 00000000 */   nop
/* 168AC0 80248260 8E440004 */  lw        $a0, 4($s2)
/* 168AC4 80248264 0C0511F8 */  jal       draw_hud_element_3
/* 168AC8 80248268 2631000B */   addiu    $s1, $s1, 0xb
/* 168ACC 8024826C 080920A1 */  j         .L80248284
/* 168AD0 80248270 26100001 */   addiu    $s0, $s0, 1
.L80248274:
/* 168AD4 80248274 8E440004 */  lw        $a0, 4($s2)
/* 168AD8 80248278 0C0511F1 */  jal       draw_hud_element_2
/* 168ADC 8024827C 2631000B */   addiu    $s1, $s1, 0xb
/* 168AE0 80248280 26100001 */  addiu     $s0, $s0, 1
.L80248284:
/* 168AE4 80248284 2A020008 */  slti      $v0, $s0, 8
/* 168AE8 80248288 1440FFEF */  bnez      $v0, .L80248248
/* 168AEC 8024828C 24020003 */   addiu    $v0, $zero, 3
/* 168AF0 80248290 3C038025 */  lui       $v1, %hi(D_8024C098_C09918)
/* 168AF4 80248294 8063C098 */  lb        $v1, %lo(D_8024C098_C09918)($v1)
/* 168AF8 80248298 14620013 */  bne       $v1, $v0, .L802482E8
/* 168AFC 8024829C 24040008 */   addiu    $a0, $zero, 8
/* 168B00 802482A0 3C038025 */  lui       $v1, %hi(D_8024C090)
/* 168B04 802482A4 8063C090 */  lb        $v1, %lo(D_8024C090)($v1)
/* 168B08 802482A8 10640006 */  beq       $v1, $a0, .L802482C4
/* 168B0C 802482AC 2402007A */   addiu    $v0, $zero, 0x7a
/* 168B10 802482B0 00031040 */  sll       $v0, $v1, 1
/* 168B14 802482B4 00431021 */  addu      $v0, $v0, $v1
/* 168B18 802482B8 00021080 */  sll       $v0, $v0, 2
/* 168B1C 802482BC 00431023 */  subu      $v0, $v0, $v1
/* 168B20 802482C0 2442002D */  addiu     $v0, $v0, 0x2d
.L802482C4:
/* 168B24 802482C4 02622821 */  addu      $a1, $s3, $v0
/* 168B28 802482C8 3C108025 */  lui       $s0, %hi(D_8024C100_C09980)
/* 168B2C 802482CC 2610C100 */  addiu     $s0, $s0, %lo(D_8024C100_C09980)
/* 168B30 802482D0 8E040000 */  lw        $a0, ($s0)
/* 168B34 802482D4 0C051261 */  jal       set_hud_element_render_pos
/* 168B38 802482D8 2686002D */   addiu    $a2, $s4, 0x2d
/* 168B3C 802482DC 8E040000 */  lw        $a0, ($s0)
/* 168B40 802482E0 0C0511F1 */  jal       draw_hud_element_2
/* 168B44 802482E4 00000000 */   nop
.L802482E8:
/* 168B48 802482E8 8FBF0038 */  lw        $ra, 0x38($sp)
/* 168B4C 802482EC 8FB50034 */  lw        $s5, 0x34($sp)
/* 168B50 802482F0 8FB40030 */  lw        $s4, 0x30($sp)
/* 168B54 802482F4 8FB3002C */  lw        $s3, 0x2c($sp)
/* 168B58 802482F8 8FB20028 */  lw        $s2, 0x28($sp)
/* 168B5C 802482FC 8FB10024 */  lw        $s1, 0x24($sp)
/* 168B60 80248300 8FB00020 */  lw        $s0, 0x20($sp)
/* 168B64 80248304 03E00008 */  jr        $ra
/* 168B68 80248308 27BD0040 */   addiu    $sp, $sp, 0x40
