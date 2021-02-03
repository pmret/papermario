.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_42A4F0
/* 42A4F0 802A9000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42A4F4 802A9004 AFB10014 */  sw        $s1, 0x14($sp)
/* 42A4F8 802A9008 0080882D */  daddu     $s1, $a0, $zero
/* 42A4FC 802A900C 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 42A500 802A9010 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 42A504 802A9014 AFBF0020 */  sw        $ra, 0x20($sp)
/* 42A508 802A9018 AFB3001C */  sw        $s3, 0x1c($sp)
/* 42A50C 802A901C AFB20018 */  sw        $s2, 0x18($sp)
/* 42A510 802A9020 AFB00010 */  sw        $s0, 0x10($sp)
/* 42A514 802A9024 8E30000C */  lw        $s0, 0xc($s1)
/* 42A518 802A9028 24020005 */  addiu     $v0, $zero, 5
/* 42A51C 802A902C A0620082 */  sb        $v0, 0x82($v1)
/* 42A520 802A9030 3C028029 */  lui       $v0, %hi(D_80294460)
/* 42A524 802A9034 24424460 */  addiu     $v0, $v0, %lo(D_80294460)
/* 42A528 802A9038 3C12802A */  lui       $s2, %hi(D_8029FBE0)
/* 42A52C 802A903C 2652FBE0 */  addiu     $s2, $s2, %lo(D_8029FBE0)
/* 42A530 802A9040 AC620434 */  sw        $v0, 0x434($v1)
/* 42A534 802A9044 80620083 */  lb        $v0, 0x83($v1)
/* 42A538 802A9048 14400003 */  bnez      $v0, .L802A9058
/* 42A53C 802A904C 0060982D */   daddu    $s3, $v1, $zero
/* 42A540 802A9050 080AA4DE */  j         .L802A9378
/* 42A544 802A9054 A0600081 */   sb       $zero, 0x81($v1)
.L802A9058:
/* 42A548 802A9058 0C09A216 */  jal       func_80268858
/* 42A54C 802A905C 00000000 */   nop
/* 42A550 802A9060 24020016 */  addiu     $v0, $zero, 0x16
/* 42A554 802A9064 A642004A */  sh        $v0, 0x4a($s2)
/* 42A558 802A9068 A640004C */  sh        $zero, 0x4c($s2)
/* 42A55C 802A906C A2400060 */  sb        $zero, 0x60($s2)
/* 42A560 802A9070 A6400044 */  sh        $zero, 0x44($s2)
/* 42A564 802A9074 A6400048 */  sh        $zero, 0x48($s2)
/* 42A568 802A9078 8E050000 */  lw        $a1, ($s0)
/* 42A56C 802A907C 0C0B1EAF */  jal       get_variable
/* 42A570 802A9080 0220202D */   daddu    $a0, $s1, $zero
/* 42A574 802A9084 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 42A578 802A9088 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 42A57C 802A908C A6420064 */  sh        $v0, 0x64($s2)
/* 42A580 802A9090 24020001 */  addiu     $v0, $zero, 1
/* 42A584 802A9094 A2620084 */  sb        $v0, 0x84($s3)
/* 42A588 802A9098 2402001E */  addiu     $v0, $zero, 0x1e
/* 42A58C 802A909C A642006C */  sh        $v0, 0x6c($s2)
/* 42A590 802A90A0 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 42A594 802A90A4 A6420056 */  sh        $v0, 0x56($s2)
/* 42A598 802A90A8 24020050 */  addiu     $v0, $zero, 0x50
/* 42A59C 802A90AC 0C050529 */  jal       create_icon
/* 42A5A0 802A90B0 A6420058 */   sh       $v0, 0x58($s2)
/* 42A5A4 802A90B4 0040882D */  daddu     $s1, $v0, $zero
/* 42A5A8 802A90B8 0220202D */  daddu     $a0, $s1, $zero
/* 42A5AC 802A90BC 24050082 */  addiu     $a1, $zero, 0x82
/* 42A5B0 802A90C0 0C051280 */  jal       set_icon_flags
/* 42A5B4 802A90C4 AE510004 */   sw       $s1, 4($s2)
/* 42A5B8 802A90C8 86450056 */  lh        $a1, 0x56($s2)
/* 42A5BC 802A90CC 86460058 */  lh        $a2, 0x58($s2)
/* 42A5C0 802A90D0 0C051261 */  jal       set_icon_render_pos
/* 42A5C4 802A90D4 0220202D */   daddu    $a0, $s1, $zero
/* 42A5C8 802A90D8 0220202D */  daddu     $a0, $s1, $zero
/* 42A5CC 802A90DC 0C051277 */  jal       func_801449DC
/* 42A5D0 802A90E0 0000282D */   daddu    $a1, $zero, $zero
/* 42A5D4 802A90E4 3C048029 */  lui       $a0, %hi(D_80292AFC)
/* 42A5D8 802A90E8 24842AFC */  addiu     $a0, $a0, %lo(D_80292AFC)
/* 42A5DC 802A90EC 0C050529 */  jal       create_icon
/* 42A5E0 802A90F0 00000000 */   nop
/* 42A5E4 802A90F4 0040882D */  daddu     $s1, $v0, $zero
/* 42A5E8 802A90F8 86450056 */  lh        $a1, 0x56($s2)
/* 42A5EC 802A90FC 86460058 */  lh        $a2, 0x58($s2)
/* 42A5F0 802A9100 0220202D */  daddu     $a0, $s1, $zero
/* 42A5F4 802A9104 AE510008 */  sw        $s1, 8($s2)
/* 42A5F8 802A9108 0C051261 */  jal       set_icon_render_pos
/* 42A5FC 802A910C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42A600 802A9110 0220202D */  daddu     $a0, $s1, $zero
/* 42A604 802A9114 0C051277 */  jal       func_801449DC
/* 42A608 802A9118 0000282D */   daddu    $a1, $zero, $zero
/* 42A60C 802A911C 0220202D */  daddu     $a0, $s1, $zero
/* 42A610 802A9120 0C051280 */  jal       set_icon_flags
/* 42A614 802A9124 24050082 */   addiu    $a1, $zero, 0x82
/* 42A618 802A9128 3C108029 */  lui       $s0, %hi(D_8029275C)
/* 42A61C 802A912C 2610275C */  addiu     $s0, $s0, %lo(D_8029275C)
/* 42A620 802A9130 0C050529 */  jal       create_icon
/* 42A624 802A9134 0200202D */   daddu    $a0, $s0, $zero
/* 42A628 802A9138 0040882D */  daddu     $s1, $v0, $zero
/* 42A62C 802A913C 86450056 */  lh        $a1, 0x56($s2)
/* 42A630 802A9140 86460058 */  lh        $a2, 0x58($s2)
/* 42A634 802A9144 0220202D */  daddu     $a0, $s1, $zero
/* 42A638 802A9148 AE51000C */  sw        $s1, 0xc($s2)
/* 42A63C 802A914C 0C051261 */  jal       set_icon_render_pos
/* 42A640 802A9150 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42A644 802A9154 0220202D */  daddu     $a0, $s1, $zero
/* 42A648 802A9158 0C051277 */  jal       func_801449DC
/* 42A64C 802A915C 0000282D */   daddu    $a1, $zero, $zero
/* 42A650 802A9160 0220202D */  daddu     $a0, $s1, $zero
/* 42A654 802A9164 0C051280 */  jal       set_icon_flags
/* 42A658 802A9168 24050082 */   addiu    $a1, $zero, 0x82
/* 42A65C 802A916C 0C050529 */  jal       create_icon
/* 42A660 802A9170 0200202D */   daddu    $a0, $s0, $zero
/* 42A664 802A9174 0040882D */  daddu     $s1, $v0, $zero
/* 42A668 802A9178 86450056 */  lh        $a1, 0x56($s2)
/* 42A66C 802A917C 86460058 */  lh        $a2, 0x58($s2)
/* 42A670 802A9180 0220202D */  daddu     $a0, $s1, $zero
/* 42A674 802A9184 AE510010 */  sw        $s1, 0x10($s2)
/* 42A678 802A9188 0C051261 */  jal       set_icon_render_pos
/* 42A67C 802A918C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42A680 802A9190 0220202D */  daddu     $a0, $s1, $zero
/* 42A684 802A9194 0C051277 */  jal       func_801449DC
/* 42A688 802A9198 0000282D */   daddu    $a1, $zero, $zero
/* 42A68C 802A919C 0220202D */  daddu     $a0, $s1, $zero
/* 42A690 802A91A0 0C051280 */  jal       set_icon_flags
/* 42A694 802A91A4 24050082 */   addiu    $a1, $zero, 0x82
/* 42A698 802A91A8 0C050529 */  jal       create_icon
/* 42A69C 802A91AC 0200202D */   daddu    $a0, $s0, $zero
/* 42A6A0 802A91B0 0040882D */  daddu     $s1, $v0, $zero
/* 42A6A4 802A91B4 86450056 */  lh        $a1, 0x56($s2)
/* 42A6A8 802A91B8 86460058 */  lh        $a2, 0x58($s2)
/* 42A6AC 802A91BC 0220202D */  daddu     $a0, $s1, $zero
/* 42A6B0 802A91C0 AE510014 */  sw        $s1, 0x14($s2)
/* 42A6B4 802A91C4 0C051261 */  jal       set_icon_render_pos
/* 42A6B8 802A91C8 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42A6BC 802A91CC 0220202D */  daddu     $a0, $s1, $zero
/* 42A6C0 802A91D0 0C051277 */  jal       func_801449DC
/* 42A6C4 802A91D4 0000282D */   daddu    $a1, $zero, $zero
/* 42A6C8 802A91D8 0220202D */  daddu     $a0, $s1, $zero
/* 42A6CC 802A91DC 0C051280 */  jal       set_icon_flags
/* 42A6D0 802A91E0 24050082 */   addiu    $a1, $zero, 0x82
/* 42A6D4 802A91E4 3C108029 */  lui       $s0, %hi(D_80292B54)
/* 42A6D8 802A91E8 26102B54 */  addiu     $s0, $s0, %lo(D_80292B54)
/* 42A6DC 802A91EC 0C050529 */  jal       create_icon
/* 42A6E0 802A91F0 0200202D */   daddu    $a0, $s0, $zero
/* 42A6E4 802A91F4 0040882D */  daddu     $s1, $v0, $zero
/* 42A6E8 802A91F8 86450056 */  lh        $a1, 0x56($s2)
/* 42A6EC 802A91FC 86460058 */  lh        $a2, 0x58($s2)
/* 42A6F0 802A9200 0220202D */  daddu     $a0, $s1, $zero
/* 42A6F4 802A9204 0C051261 */  jal       set_icon_render_pos
/* 42A6F8 802A9208 AE51001C */   sw       $s1, 0x1c($s2)
/* 42A6FC 802A920C 0220202D */  daddu     $a0, $s1, $zero
/* 42A700 802A9210 0C051277 */  jal       func_801449DC
/* 42A704 802A9214 0000282D */   daddu    $a1, $zero, $zero
/* 42A708 802A9218 0220202D */  daddu     $a0, $s1, $zero
/* 42A70C 802A921C 0C051280 */  jal       set_icon_flags
/* 42A710 802A9220 24050082 */   addiu    $a1, $zero, 0x82
/* 42A714 802A9224 0C050529 */  jal       create_icon
/* 42A718 802A9228 0200202D */   daddu    $a0, $s0, $zero
/* 42A71C 802A922C 0040882D */  daddu     $s1, $v0, $zero
/* 42A720 802A9230 86450056 */  lh        $a1, 0x56($s2)
/* 42A724 802A9234 86460058 */  lh        $a2, 0x58($s2)
/* 42A728 802A9238 0220202D */  daddu     $a0, $s1, $zero
/* 42A72C 802A923C 0C051261 */  jal       set_icon_render_pos
/* 42A730 802A9240 AE510020 */   sw       $s1, 0x20($s2)
/* 42A734 802A9244 0220202D */  daddu     $a0, $s1, $zero
/* 42A738 802A9248 0C051277 */  jal       func_801449DC
/* 42A73C 802A924C 0000282D */   daddu    $a1, $zero, $zero
/* 42A740 802A9250 0220202D */  daddu     $a0, $s1, $zero
/* 42A744 802A9254 0C051280 */  jal       set_icon_flags
/* 42A748 802A9258 24050082 */   addiu    $a1, $zero, 0x82
/* 42A74C 802A925C 0C050529 */  jal       create_icon
/* 42A750 802A9260 0200202D */   daddu    $a0, $s0, $zero
/* 42A754 802A9264 0040882D */  daddu     $s1, $v0, $zero
/* 42A758 802A9268 86450056 */  lh        $a1, 0x56($s2)
/* 42A75C 802A926C 86460058 */  lh        $a2, 0x58($s2)
/* 42A760 802A9270 0220202D */  daddu     $a0, $s1, $zero
/* 42A764 802A9274 0C051261 */  jal       set_icon_render_pos
/* 42A768 802A9278 AE510024 */   sw       $s1, 0x24($s2)
/* 42A76C 802A927C 0220202D */  daddu     $a0, $s1, $zero
/* 42A770 802A9280 0C051277 */  jal       func_801449DC
/* 42A774 802A9284 0000282D */   daddu    $a1, $zero, $zero
/* 42A778 802A9288 0220202D */  daddu     $a0, $s1, $zero
/* 42A77C 802A928C 0C051280 */  jal       set_icon_flags
/* 42A780 802A9290 24050082 */   addiu    $a1, $zero, 0x82
/* 42A784 802A9294 3C04802B */  lui       $a0, %hi(D_802AB184_42C674)
/* 42A788 802A9298 0C050529 */  jal       create_icon
/* 42A78C 802A929C 8C84B184 */   lw       $a0, %lo(D_802AB184_42C674)($a0)
/* 42A790 802A92A0 86450056 */  lh        $a1, 0x56($s2)
/* 42A794 802A92A4 86460058 */  lh        $a2, 0x58($s2)
/* 42A798 802A92A8 0040202D */  daddu     $a0, $v0, $zero
/* 42A79C 802A92AC 0C051261 */  jal       set_icon_render_pos
/* 42A7A0 802A92B0 AE44002C */   sw       $a0, 0x2c($s2)
/* 42A7A4 802A92B4 3C048029 */  lui       $a0, %hi(D_802928A0)
/* 42A7A8 802A92B8 248428A0 */  addiu     $a0, $a0, %lo(D_802928A0)
/* 42A7AC 802A92BC 0C050529 */  jal       create_icon
/* 42A7B0 802A92C0 00000000 */   nop
/* 42A7B4 802A92C4 86450056 */  lh        $a1, 0x56($s2)
/* 42A7B8 802A92C8 86460058 */  lh        $a2, 0x58($s2)
/* 42A7BC 802A92CC 0040202D */  daddu     $a0, $v0, $zero
/* 42A7C0 802A92D0 0C051261 */  jal       set_icon_render_pos
/* 42A7C4 802A92D4 AE440030 */   sw       $a0, 0x30($s2)
/* 42A7C8 802A92D8 3C048029 */  lui       $a0, %hi(D_80292848)
/* 42A7CC 802A92DC 24842848 */  addiu     $a0, $a0, %lo(D_80292848)
/* 42A7D0 802A92E0 0C050529 */  jal       create_icon
/* 42A7D4 802A92E4 00000000 */   nop
/* 42A7D8 802A92E8 0040882D */  daddu     $s1, $v0, $zero
/* 42A7DC 802A92EC 86450056 */  lh        $a1, 0x56($s2)
/* 42A7E0 802A92F0 86460058 */  lh        $a2, 0x58($s2)
/* 42A7E4 802A92F4 0220202D */  daddu     $a0, $s1, $zero
/* 42A7E8 802A92F8 0C051261 */  jal       set_icon_render_pos
/* 42A7EC 802A92FC AE510034 */   sw       $s1, 0x34($s2)
/* 42A7F0 802A9300 86430064 */  lh        $v1, 0x64($s2)
/* 42A7F4 802A9304 24020001 */  addiu     $v0, $zero, 1
/* 42A7F8 802A9308 1062000E */  beq       $v1, $v0, .L802A9344
/* 42A7FC 802A930C 28620002 */   slti     $v0, $v1, 2
/* 42A800 802A9310 10400005 */  beqz      $v0, .L802A9328
/* 42A804 802A9314 24020002 */   addiu    $v0, $zero, 2
/* 42A808 802A9318 10600007 */  beqz      $v1, .L802A9338
/* 42A80C 802A931C 00000000 */   nop
/* 42A810 802A9320 080AA4DA */  j         .L802A9368
/* 42A814 802A9324 00000000 */   nop
.L802A9328:
/* 42A818 802A9328 10620009 */  beq       $v1, $v0, .L802A9350
/* 42A81C 802A932C 00000000 */   nop
/* 42A820 802A9330 080AA4DA */  j         .L802A9368
/* 42A824 802A9334 00000000 */   nop
.L802A9338:
/* 42A828 802A9338 3C04802B */  lui       $a0, %hi(D_802AB108_42C5F8)
/* 42A82C 802A933C 080AA4D6 */  j         .L802A9358
/* 42A830 802A9340 2484B108 */   addiu    $a0, $a0, %lo(D_802AB108_42C5F8)
.L802A9344:
/* 42A834 802A9344 3C04802B */  lui       $a0, %hi(D_802AB130_42C620)
/* 42A838 802A9348 080AA4D6 */  j         .L802A9358
/* 42A83C 802A934C 2484B130 */   addiu    $a0, $a0, %lo(D_802AB130_42C620)
.L802A9350:
/* 42A840 802A9350 3C04802B */  lui       $a0, %hi(D_802AB158_42C648)
/* 42A844 802A9354 2484B158 */  addiu     $a0, $a0, %lo(D_802AB158_42C648)
.L802A9358:
/* 42A848 802A9358 0C050529 */  jal       create_icon
/* 42A84C 802A935C 00000000 */   nop
/* 42A850 802A9360 AE420038 */  sw        $v0, 0x38($s2)
/* 42A854 802A9364 0040882D */  daddu     $s1, $v0, $zero
.L802A9368:
/* 42A858 802A9368 86450056 */  lh        $a1, 0x56($s2)
/* 42A85C 802A936C 86460058 */  lh        $a2, 0x58($s2)
/* 42A860 802A9370 0C051261 */  jal       set_icon_render_pos
/* 42A864 802A9374 0220202D */   daddu    $a0, $s1, $zero
.L802A9378:
/* 42A868 802A9378 24020002 */  addiu     $v0, $zero, 2
/* 42A86C 802A937C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42A870 802A9380 8FB3001C */  lw        $s3, 0x1c($sp)
/* 42A874 802A9384 8FB20018 */  lw        $s2, 0x18($sp)
/* 42A878 802A9388 8FB10014 */  lw        $s1, 0x14($sp)
/* 42A87C 802A938C 8FB00010 */  lw        $s0, 0x10($sp)
/* 42A880 802A9390 03E00008 */  jr        $ra
/* 42A884 802A9394 27BD0028 */   addiu    $sp, $sp, 0x28
