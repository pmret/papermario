.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80150220
.word L80122440_B8B40, L80122980_B9080, L80122980_B9080, L80122650_B8D50, L80122470_B8B70, L80122980_B9080, L80122980_B9080, L80122980_B9080, L801224A0_B8BA0, L80122980_B9080, L80122980_B9080, L80122980_B9080, L801224D0_B8BD0, L80122980_B9080, L80122620_B8D20, L80122680_B8D80, L80122500_B8C00, L80122980_B9080, L80122530_B8C30, L801226B0_B8DB0, L80122980_B9080, L80122500_B8C00, L80122980_B9080, L80122980_B9080, L80122980_B9080, L80122560_B8C60, L80122980_B9080, L80122590_B8C90, L80122980_B9080, L80122560_B8C60, L80122980_B9080, L80122590_B8C90, L80122980_B9080, L80122500_B8C00, L80122980_B9080, L80122980_B9080, L80122980_B9080, L801225C0_B8CC0, L80122980_B9080, L801225F0_B8CF0, L80122980_B9080, L80122650_B8D50, L80122680_B8D80, L801226B0_B8DB0, L801226E0_B8DE0, 0

glabel jtbl_801502D8
.word L80122740_B8E40, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L80122770_B8E70, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L801227A0_B8EA0, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L801227D0_B8ED0, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L80122800_B8F00, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L80122830_B8F30, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L8012288C_B8F8C, L80122860_B8F60

.section .text

glabel draw_entity_model_E
/* B8988 80122288 27BDFF08 */  addiu     $sp, $sp, -0xf8
/* B898C 8012228C 2402F7FF */  addiu     $v0, $zero, -0x801
/* B8990 80122290 00822024 */  and       $a0, $a0, $v0
/* B8994 80122294 3C028015 */  lui       $v0, %hi(gCurrentEntityModelList)
/* B8998 80122298 8C424370 */  lw        $v0, %lo(gCurrentEntityModelList)($v0)
/* B899C 8012229C 00042080 */  sll       $a0, $a0, 2
/* B89A0 801222A0 AFBF00F4 */  sw        $ra, 0xf4($sp)
/* B89A4 801222A4 AFB200F0 */  sw        $s2, 0xf0($sp)
/* B89A8 801222A8 AFB100EC */  sw        $s1, 0xec($sp)
/* B89AC 801222AC AFB000E8 */  sw        $s0, 0xe8($sp)
/* B89B0 801222B0 00822021 */  addu      $a0, $a0, $v0
/* B89B4 801222B4 8C920000 */  lw        $s2, ($a0)
/* B89B8 801222B8 124002AA */  beqz      $s2, .L80122D64
/* B89BC 801222BC 00000000 */   nop
/* B89C0 801222C0 8E430000 */  lw        $v1, ($s2)
/* B89C4 801222C4 106002A7 */  beqz      $v1, .L80122D64
/* B89C8 801222C8 30620100 */   andi     $v0, $v1, 0x100
/* B89CC 801222CC 144002A5 */  bnez      $v0, .L80122D64
/* B89D0 801222D0 30620020 */   andi     $v0, $v1, 0x20
/* B89D4 801222D4 144002A3 */  bnez      $v0, .L80122D64
/* B89D8 801222D8 30620040 */   andi     $v0, $v1, 0x40
/* B89DC 801222DC 144002A1 */  bnez      $v0, .L80122D64
/* B89E0 801222E0 30620008 */   andi     $v0, $v1, 8
/* B89E4 801222E4 1040029F */  beqz      $v0, .L80122D64
/* B89E8 801222E8 26420018 */   addiu    $v0, $s2, 0x18
/* B89EC 801222EC 24A30040 */  addiu     $v1, $a1, 0x40
.L801222F0:
/* B89F0 801222F0 8CAE0000 */  lw        $t6, ($a1)
/* B89F4 801222F4 8CAF0004 */  lw        $t7, 4($a1)
/* B89F8 801222F8 8CB80008 */  lw        $t8, 8($a1)
/* B89FC 801222FC 8CB9000C */  lw        $t9, 0xc($a1)
/* B8A00 80122300 AC4E0000 */  sw        $t6, ($v0)
/* B8A04 80122304 AC4F0004 */  sw        $t7, 4($v0)
/* B8A08 80122308 AC580008 */  sw        $t8, 8($v0)
/* B8A0C 8012230C AC59000C */  sw        $t9, 0xc($v0)
/* B8A10 80122310 24A50010 */  addiu     $a1, $a1, 0x10
/* B8A14 80122314 14A3FFF6 */  bne       $a1, $v1, .L801222F0
/* B8A18 80122318 24420010 */   addiu    $v0, $v0, 0x10
/* B8A1C 8012231C 3C020001 */  lui       $v0, 1
/* B8A20 80122320 34421630 */  ori       $v0, $v0, 0x1630
/* B8A24 80122324 26450018 */  addiu     $a1, $s2, 0x18
/* B8A28 80122328 3C038007 */  lui       $v1, %hi(gMatrixListPos)
/* B8A2C 8012232C 946341F0 */  lhu       $v1, %lo(gMatrixListPos)($v1)
/* B8A30 80122330 3C04800A */  lui       $a0, %hi(gDisplayContext)
/* B8A34 80122334 8C84A674 */  lw        $a0, %lo(gDisplayContext)($a0)
/* B8A38 80122338 26460058 */  addiu     $a2, $s2, 0x58
/* B8A3C 8012233C AE40005C */  sw        $zero, 0x5c($s2)
/* B8A40 80122340 00031980 */  sll       $v1, $v1, 6
/* B8A44 80122344 00832021 */  addu      $a0, $a0, $v1
/* B8A48 80122348 00822021 */  addu      $a0, $a0, $v0
.L8012234C:
/* B8A4C 8012234C 8CAE0000 */  lw        $t6, ($a1)
/* B8A50 80122350 8CAF0004 */  lw        $t7, 4($a1)
/* B8A54 80122354 8CB80008 */  lw        $t8, 8($a1)
/* B8A58 80122358 8CB9000C */  lw        $t9, 0xc($a1)
/* B8A5C 8012235C AC8E0000 */  sw        $t6, ($a0)
/* B8A60 80122360 AC8F0004 */  sw        $t7, 4($a0)
/* B8A64 80122364 AC980008 */  sw        $t8, 8($a0)
/* B8A68 80122368 AC99000C */  sw        $t9, 0xc($a0)
/* B8A6C 8012236C 24A50010 */  addiu     $a1, $a1, 0x10
/* B8A70 80122370 14A6FFF6 */  bne       $a1, $a2, .L8012234C
/* B8A74 80122374 24840010 */   addiu    $a0, $a0, 0x10
/* B8A78 80122378 3C02DA38 */  lui       $v0, 0xda38
/* B8A7C 8012237C 34420002 */  ori       $v0, $v0, 2
/* B8A80 80122380 3C070001 */  lui       $a3, 1
/* B8A84 80122384 3C0D800A */  lui       $t5, %hi(gMasterGfxPos)
/* B8A88 80122388 25ADA66C */  addiu     $t5, $t5, %lo(gMasterGfxPos)
/* B8A8C 8012238C 34E71630 */  ori       $a3, $a3, 0x1630
/* B8A90 80122390 3C068007 */  lui       $a2, %hi(gMatrixListPos)
/* B8A94 80122394 24C641F0 */  addiu     $a2, $a2, %lo(gMatrixListPos)
/* B8A98 80122398 8DAC0000 */  lw        $t4, ($t5)
/* B8A9C 8012239C 94C40000 */  lhu       $a0, ($a2)
/* B8AA0 801223A0 0180282D */  daddu     $a1, $t4, $zero
/* B8AA4 801223A4 258C0008 */  addiu     $t4, $t4, 8
/* B8AA8 801223A8 ADAC0000 */  sw        $t4, ($t5)
/* B8AAC 801223AC ACA20000 */  sw        $v0, ($a1)
/* B8AB0 801223B0 3082FFFF */  andi      $v0, $a0, 0xffff
/* B8AB4 801223B4 00021180 */  sll       $v0, $v0, 6
/* B8AB8 801223B8 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* B8ABC 801223BC 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* B8AC0 801223C0 00471021 */  addu      $v0, $v0, $a3
/* B8AC4 801223C4 00621821 */  addu      $v1, $v1, $v0
/* B8AC8 801223C8 ACA30004 */  sw        $v1, 4($a1)
/* B8ACC 801223CC 8E450000 */  lw        $a1, ($s2)
/* B8AD0 801223D0 24840001 */  addiu     $a0, $a0, 1
/* B8AD4 801223D4 30A20400 */  andi      $v0, $a1, 0x400
/* B8AD8 801223D8 144001F6 */  bnez      $v0, .L80122BB4
/* B8ADC 801223DC A4C40000 */   sh       $a0, ($a2)
/* B8AE0 801223E0 3C028015 */  lui       $v0, %hi(entity_fog_enabled)
/* B8AE4 801223E4 8C424378 */  lw        $v0, %lo(entity_fog_enabled)($v0)
/* B8AE8 801223E8 10400003 */  beqz      $v0, .L801223F8
/* B8AEC 801223EC 0000182D */   daddu    $v1, $zero, $zero
/* B8AF0 801223F0 30A20800 */  andi      $v0, $a1, 0x800
/* B8AF4 801223F4 2C430001 */  sltiu     $v1, $v0, 1
.L801223F8:
/* B8AF8 801223F8 10600005 */  beqz      $v1, .L80122410
/* B8AFC 801223FC 24020001 */   addiu    $v0, $zero, 1
/* B8B00 80122400 106200C3 */  beq       $v1, $v0, .L80122710
/* B8B04 80122404 3C02D9FD */   lui      $v0, %hi(D_D9FCFFFF)
/* B8B08 80122408 08048A61 */  j         .L80122984
/* B8B0C 8012240C 00000000 */   nop
.L80122410:
/* B8B10 80122410 92420004 */  lbu       $v0, 4($s2)
/* B8B14 80122414 2442FFFF */  addiu     $v0, $v0, %lo(D_D9FCFFFF)
/* B8B18 80122418 00021600 */  sll       $v0, $v0, 0x18
/* B8B1C 8012241C 00021E03 */  sra       $v1, $v0, 0x18
/* B8B20 80122420 2C62002D */  sltiu     $v0, $v1, 0x2d
/* B8B24 80122424 10400156 */  beqz      $v0, L80122980_B9080
/* B8B28 80122428 00031080 */   sll      $v0, $v1, 2
/* B8B2C 8012242C 3C018015 */  lui       $at, %hi(jtbl_80150220)
/* B8B30 80122430 00220821 */  addu      $at, $at, $v0
/* B8B34 80122434 8C220220 */  lw        $v0, %lo(jtbl_80150220)($at)
/* B8B38 80122438 00400008 */  jr        $v0
/* B8B3C 8012243C 00000000 */   nop
glabel L80122440_B8B40
/* B8B40 80122440 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8B44 80122444 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8B48 80122448 8C620000 */  lw        $v0, ($v1)
/* B8B4C 8012244C 0040202D */  daddu     $a0, $v0, $zero
/* B8B50 80122450 24420008 */  addiu     $v0, $v0, 8
/* B8B54 80122454 AC620000 */  sw        $v0, ($v1)
/* B8B58 80122458 3C02DE00 */  lui       $v0, 0xde00
/* B8B5C 8012245C AC820000 */  sw        $v0, ($a0)
/* B8B60 80122460 3C028015 */  lui       $v0, %hi(D_8014B7F8)
/* B8B64 80122464 2442B7F8 */  addiu     $v0, $v0, %lo(D_8014B7F8)
/* B8B68 80122468 08048A60 */  j         L80122980_B9080
/* B8B6C 8012246C AC820004 */   sw       $v0, 4($a0)
glabel L80122470_B8B70
/* B8B70 80122470 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8B74 80122474 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8B78 80122478 8C620000 */  lw        $v0, ($v1)
/* B8B7C 8012247C 0040202D */  daddu     $a0, $v0, $zero
/* B8B80 80122480 24420008 */  addiu     $v0, $v0, 8
/* B8B84 80122484 AC620000 */  sw        $v0, ($v1)
/* B8B88 80122488 3C02DE00 */  lui       $v0, 0xde00
/* B8B8C 8012248C AC820000 */  sw        $v0, ($a0)
/* B8B90 80122490 3C028015 */  lui       $v0, %hi(D_8014B820)
/* B8B94 80122494 2442B820 */  addiu     $v0, $v0, %lo(D_8014B820)
/* B8B98 80122498 08048A60 */  j         L80122980_B9080
/* B8B9C 8012249C AC820004 */   sw       $v0, 4($a0)
glabel L801224A0_B8BA0
/* B8BA0 801224A0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8BA4 801224A4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8BA8 801224A8 8C620000 */  lw        $v0, ($v1)
/* B8BAC 801224AC 0040202D */  daddu     $a0, $v0, $zero
/* B8BB0 801224B0 24420008 */  addiu     $v0, $v0, 8
/* B8BB4 801224B4 AC620000 */  sw        $v0, ($v1)
/* B8BB8 801224B8 3C02DE00 */  lui       $v0, 0xde00
/* B8BBC 801224BC AC820000 */  sw        $v0, ($a0)
/* B8BC0 801224C0 3C028015 */  lui       $v0, %hi(D_8014B848)
/* B8BC4 801224C4 2442B848 */  addiu     $v0, $v0, %lo(D_8014B848)
/* B8BC8 801224C8 08048A60 */  j         L80122980_B9080
/* B8BCC 801224CC AC820004 */   sw       $v0, 4($a0)
glabel L801224D0_B8BD0
/* B8BD0 801224D0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8BD4 801224D4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8BD8 801224D8 8C620000 */  lw        $v0, ($v1)
/* B8BDC 801224DC 0040202D */  daddu     $a0, $v0, $zero
/* B8BE0 801224E0 24420008 */  addiu     $v0, $v0, 8
/* B8BE4 801224E4 AC620000 */  sw        $v0, ($v1)
/* B8BE8 801224E8 3C02DE00 */  lui       $v0, 0xde00
/* B8BEC 801224EC AC820000 */  sw        $v0, ($a0)
/* B8BF0 801224F0 3C028015 */  lui       $v0, %hi(D_8014B870)
/* B8BF4 801224F4 2442B870 */  addiu     $v0, $v0, %lo(D_8014B870)
/* B8BF8 801224F8 08048A60 */  j         L80122980_B9080
/* B8BFC 801224FC AC820004 */   sw       $v0, 4($a0)
glabel L80122500_B8C00
/* B8C00 80122500 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8C04 80122504 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8C08 80122508 8C620000 */  lw        $v0, ($v1)
/* B8C0C 8012250C 0040202D */  daddu     $a0, $v0, $zero
/* B8C10 80122510 24420008 */  addiu     $v0, $v0, 8
/* B8C14 80122514 AC620000 */  sw        $v0, ($v1)
/* B8C18 80122518 3C02DE00 */  lui       $v0, 0xde00
/* B8C1C 8012251C AC820000 */  sw        $v0, ($a0)
/* B8C20 80122520 3C028015 */  lui       $v0, %hi(D_8014B898)
/* B8C24 80122524 2442B898 */  addiu     $v0, $v0, %lo(D_8014B898)
/* B8C28 80122528 08048A60 */  j         L80122980_B9080
/* B8C2C 8012252C AC820004 */   sw       $v0, 4($a0)
glabel L80122530_B8C30
/* B8C30 80122530 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8C34 80122534 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8C38 80122538 8C620000 */  lw        $v0, ($v1)
/* B8C3C 8012253C 0040202D */  daddu     $a0, $v0, $zero
/* B8C40 80122540 24420008 */  addiu     $v0, $v0, 8
/* B8C44 80122544 AC620000 */  sw        $v0, ($v1)
/* B8C48 80122548 3C02DE00 */  lui       $v0, 0xde00
/* B8C4C 8012254C AC820000 */  sw        $v0, ($a0)
/* B8C50 80122550 3C028015 */  lui       $v0, %hi(D_8014B9B0)
/* B8C54 80122554 2442B9B0 */  addiu     $v0, $v0, %lo(D_8014B9B0)
/* B8C58 80122558 08048A60 */  j         L80122980_B9080
/* B8C5C 8012255C AC820004 */   sw       $v0, 4($a0)
glabel L80122560_B8C60
/* B8C60 80122560 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8C64 80122564 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8C68 80122568 8C620000 */  lw        $v0, ($v1)
/* B8C6C 8012256C 0040202D */  daddu     $a0, $v0, $zero
/* B8C70 80122570 24420008 */  addiu     $v0, $v0, 8
/* B8C74 80122574 AC620000 */  sw        $v0, ($v1)
/* B8C78 80122578 3C02DE00 */  lui       $v0, 0xde00
/* B8C7C 8012257C AC820000 */  sw        $v0, ($a0)
/* B8C80 80122580 3C028015 */  lui       $v0, %hi(D_8014B8C0)
/* B8C84 80122584 2442B8C0 */  addiu     $v0, $v0, %lo(D_8014B8C0)
/* B8C88 80122588 08048A60 */  j         L80122980_B9080
/* B8C8C 8012258C AC820004 */   sw       $v0, 4($a0)
glabel L80122590_B8C90
/* B8C90 80122590 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8C94 80122594 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8C98 80122598 8C620000 */  lw        $v0, ($v1)
/* B8C9C 8012259C 0040202D */  daddu     $a0, $v0, $zero
/* B8CA0 801225A0 24420008 */  addiu     $v0, $v0, 8
/* B8CA4 801225A4 AC620000 */  sw        $v0, ($v1)
/* B8CA8 801225A8 3C02DE00 */  lui       $v0, 0xde00
/* B8CAC 801225AC AC820000 */  sw        $v0, ($a0)
/* B8CB0 801225B0 3C028015 */  lui       $v0, %hi(D_8014B9D8)
/* B8CB4 801225B4 2442B9D8 */  addiu     $v0, $v0, %lo(D_8014B9D8)
/* B8CB8 801225B8 08048A60 */  j         L80122980_B9080
/* B8CBC 801225BC AC820004 */   sw       $v0, 4($a0)
glabel L801225C0_B8CC0
/* B8CC0 801225C0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8CC4 801225C4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8CC8 801225C8 8C620000 */  lw        $v0, ($v1)
/* B8CCC 801225CC 0040202D */  daddu     $a0, $v0, $zero
/* B8CD0 801225D0 24420008 */  addiu     $v0, $v0, 8
/* B8CD4 801225D4 AC620000 */  sw        $v0, ($v1)
/* B8CD8 801225D8 3C02DE00 */  lui       $v0, 0xde00
/* B8CDC 801225DC AC820000 */  sw        $v0, ($a0)
/* B8CE0 801225E0 3C028015 */  lui       $v0, %hi(D_8014B8E8)
/* B8CE4 801225E4 2442B8E8 */  addiu     $v0, $v0, %lo(D_8014B8E8)
/* B8CE8 801225E8 08048A60 */  j         L80122980_B9080
/* B8CEC 801225EC AC820004 */   sw       $v0, 4($a0)
glabel L801225F0_B8CF0
/* B8CF0 801225F0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8CF4 801225F4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8CF8 801225F8 8C620000 */  lw        $v0, ($v1)
/* B8CFC 801225FC 0040202D */  daddu     $a0, $v0, $zero
/* B8D00 80122600 24420008 */  addiu     $v0, $v0, 8
/* B8D04 80122604 AC620000 */  sw        $v0, ($v1)
/* B8D08 80122608 3C02DE00 */  lui       $v0, 0xde00
/* B8D0C 8012260C AC820000 */  sw        $v0, ($a0)
/* B8D10 80122610 3C028015 */  lui       $v0, %hi(D_8014BA00)
/* B8D14 80122614 2442BA00 */  addiu     $v0, $v0, %lo(D_8014BA00)
/* B8D18 80122618 08048A60 */  j         L80122980_B9080
/* B8D1C 8012261C AC820004 */   sw       $v0, 4($a0)
glabel L80122620_B8D20
/* B8D20 80122620 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8D24 80122624 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8D28 80122628 8C620000 */  lw        $v0, ($v1)
/* B8D2C 8012262C 0040202D */  daddu     $a0, $v0, $zero
/* B8D30 80122630 24420008 */  addiu     $v0, $v0, 8
/* B8D34 80122634 AC620000 */  sw        $v0, ($v1)
/* B8D38 80122638 3C02DE00 */  lui       $v0, 0xde00
/* B8D3C 8012263C AC820000 */  sw        $v0, ($a0)
/* B8D40 80122640 3C028015 */  lui       $v0, %hi(D_8014B988)
/* B8D44 80122644 2442B988 */  addiu     $v0, $v0, %lo(D_8014B988)
/* B8D48 80122648 08048A60 */  j         L80122980_B9080
/* B8D4C 8012264C AC820004 */   sw       $v0, 4($a0)
glabel L80122650_B8D50
/* B8D50 80122650 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8D54 80122654 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8D58 80122658 8C620000 */  lw        $v0, ($v1)
/* B8D5C 8012265C 0040202D */  daddu     $a0, $v0, $zero
/* B8D60 80122660 24420008 */  addiu     $v0, $v0, 8
/* B8D64 80122664 AC620000 */  sw        $v0, ($v1)
/* B8D68 80122668 3C02DE00 */  lui       $v0, 0xde00
/* B8D6C 8012266C AC820000 */  sw        $v0, ($a0)
/* B8D70 80122670 3C028015 */  lui       $v0, %hi(D_8014BA48)
/* B8D74 80122674 2442BA48 */  addiu     $v0, $v0, %lo(D_8014BA48)
/* B8D78 80122678 08048A60 */  j         L80122980_B9080
/* B8D7C 8012267C AC820004 */   sw       $v0, 4($a0)
glabel L80122680_B8D80
/* B8D80 80122680 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8D84 80122684 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8D88 80122688 8C620000 */  lw        $v0, ($v1)
/* B8D8C 8012268C 0040202D */  daddu     $a0, $v0, $zero
/* B8D90 80122690 24420008 */  addiu     $v0, $v0, 8
/* B8D94 80122694 AC620000 */  sw        $v0, ($v1)
/* B8D98 80122698 3C02DE00 */  lui       $v0, 0xde00
/* B8D9C 8012269C AC820000 */  sw        $v0, ($a0)
/* B8DA0 801226A0 3C028015 */  lui       $v0, %hi(D_8014BA70)
/* B8DA4 801226A4 2442BA70 */  addiu     $v0, $v0, %lo(D_8014BA70)
/* B8DA8 801226A8 08048A60 */  j         L80122980_B9080
/* B8DAC 801226AC AC820004 */   sw       $v0, 4($a0)
glabel L801226B0_B8DB0
/* B8DB0 801226B0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8DB4 801226B4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8DB8 801226B8 8C620000 */  lw        $v0, ($v1)
/* B8DBC 801226BC 0040202D */  daddu     $a0, $v0, $zero
/* B8DC0 801226C0 24420008 */  addiu     $v0, $v0, 8
/* B8DC4 801226C4 AC620000 */  sw        $v0, ($v1)
/* B8DC8 801226C8 3C02DE00 */  lui       $v0, 0xde00
/* B8DCC 801226CC AC820000 */  sw        $v0, ($a0)
/* B8DD0 801226D0 3C028015 */  lui       $v0, %hi(D_8014BA98)
/* B8DD4 801226D4 2442BA98 */  addiu     $v0, $v0, %lo(D_8014BA98)
/* B8DD8 801226D8 08048A60 */  j         L80122980_B9080
/* B8DDC 801226DC AC820004 */   sw       $v0, 4($a0)
glabel L801226E0_B8DE0
/* B8DE0 801226E0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8DE4 801226E4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8DE8 801226E8 8C620000 */  lw        $v0, ($v1)
/* B8DEC 801226EC 0040202D */  daddu     $a0, $v0, $zero
/* B8DF0 801226F0 24420008 */  addiu     $v0, $v0, 8
/* B8DF4 801226F4 AC620000 */  sw        $v0, ($v1)
/* B8DF8 801226F8 3C02DE00 */  lui       $v0, 0xde00
/* B8DFC 801226FC AC820000 */  sw        $v0, ($a0)
/* B8E00 80122700 3C028015 */  lui       $v0, %hi(D_8014BAE8)
/* B8E04 80122704 2442BAE8 */  addiu     $v0, $v0, %lo(D_8014BAE8)
/* B8E08 80122708 08048A60 */  j         L80122980_B9080
/* B8E0C 8012270C AC820004 */   sw       $v0, 4($a0)
.L80122710:
/* B8E10 80122710 92420004 */  lbu       $v0, 4($s2)
/* B8E14 80122714 2442FFFF */  addiu     $v0, $v0, -1
/* B8E18 80122718 00021600 */  sll       $v0, $v0, 0x18
/* B8E1C 8012271C 00021E03 */  sra       $v1, $v0, 0x18
/* B8E20 80122720 2C620026 */  sltiu     $v0, $v1, 0x26
/* B8E24 80122724 10400059 */  beqz      $v0, L8012288C_B8F8C
/* B8E28 80122728 00031080 */   sll      $v0, $v1, 2
/* B8E2C 8012272C 3C018015 */  lui       $at, %hi(jtbl_801502D8)
/* B8E30 80122730 00220821 */  addu      $at, $at, $v0
/* B8E34 80122734 8C2202D8 */  lw        $v0, %lo(jtbl_801502D8)($at)
/* B8E38 80122738 00400008 */  jr        $v0
/* B8E3C 8012273C 00000000 */   nop
glabel L80122740_B8E40
/* B8E40 80122740 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8E44 80122744 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8E48 80122748 8C620000 */  lw        $v0, ($v1)
/* B8E4C 8012274C 0040202D */  daddu     $a0, $v0, $zero
/* B8E50 80122750 24420008 */  addiu     $v0, $v0, 8
/* B8E54 80122754 AC620000 */  sw        $v0, ($v1)
/* B8E58 80122758 3C02DE00 */  lui       $v0, 0xde00
/* B8E5C 8012275C AC820000 */  sw        $v0, ($a0)
/* B8E60 80122760 3C028015 */  lui       $v0, %hi(D_8014BE78)
/* B8E64 80122764 2442BE78 */  addiu     $v0, $v0, %lo(D_8014BE78)
/* B8E68 80122768 08048A23 */  j         L8012288C_B8F8C
/* B8E6C 8012276C AC820004 */   sw       $v0, 4($a0)
glabel L80122770_B8E70
/* B8E70 80122770 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8E74 80122774 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8E78 80122778 8C620000 */  lw        $v0, ($v1)
/* B8E7C 8012277C 0040202D */  daddu     $a0, $v0, $zero
/* B8E80 80122780 24420008 */  addiu     $v0, $v0, 8
/* B8E84 80122784 AC620000 */  sw        $v0, ($v1)
/* B8E88 80122788 3C02DE00 */  lui       $v0, 0xde00
/* B8E8C 8012278C AC820000 */  sw        $v0, ($a0)
/* B8E90 80122790 3C028015 */  lui       $v0, %hi(D_8014BEA0)
/* B8E94 80122794 2442BEA0 */  addiu     $v0, $v0, %lo(D_8014BEA0)
/* B8E98 80122798 08048A23 */  j         L8012288C_B8F8C
/* B8E9C 8012279C AC820004 */   sw       $v0, 4($a0)
glabel L801227A0_B8EA0
/* B8EA0 801227A0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8EA4 801227A4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8EA8 801227A8 8C620000 */  lw        $v0, ($v1)
/* B8EAC 801227AC 0040202D */  daddu     $a0, $v0, $zero
/* B8EB0 801227B0 24420008 */  addiu     $v0, $v0, 8
/* B8EB4 801227B4 AC620000 */  sw        $v0, ($v1)
/* B8EB8 801227B8 3C02DE00 */  lui       $v0, 0xde00
/* B8EBC 801227BC AC820000 */  sw        $v0, ($a0)
/* B8EC0 801227C0 3C028015 */  lui       $v0, %hi(D_8014BEC8)
/* B8EC4 801227C4 2442BEC8 */  addiu     $v0, $v0, %lo(D_8014BEC8)
/* B8EC8 801227C8 08048A23 */  j         L8012288C_B8F8C
/* B8ECC 801227CC AC820004 */   sw       $v0, 4($a0)
glabel L801227D0_B8ED0
/* B8ED0 801227D0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8ED4 801227D4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8ED8 801227D8 8C620000 */  lw        $v0, ($v1)
/* B8EDC 801227DC 0040202D */  daddu     $a0, $v0, $zero
/* B8EE0 801227E0 24420008 */  addiu     $v0, $v0, 8
/* B8EE4 801227E4 AC620000 */  sw        $v0, ($v1)
/* B8EE8 801227E8 3C02DE00 */  lui       $v0, 0xde00
/* B8EEC 801227EC AC820000 */  sw        $v0, ($a0)
/* B8EF0 801227F0 3C028015 */  lui       $v0, %hi(D_8014BEF0)
/* B8EF4 801227F4 2442BEF0 */  addiu     $v0, $v0, %lo(D_8014BEF0)
/* B8EF8 801227F8 08048A23 */  j         L8012288C_B8F8C
/* B8EFC 801227FC AC820004 */   sw       $v0, 4($a0)
glabel L80122800_B8F00
/* B8F00 80122800 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8F04 80122804 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8F08 80122808 8C620000 */  lw        $v0, ($v1)
/* B8F0C 8012280C 0040202D */  daddu     $a0, $v0, $zero
/* B8F10 80122810 24420008 */  addiu     $v0, $v0, 8
/* B8F14 80122814 AC620000 */  sw        $v0, ($v1)
/* B8F18 80122818 3C02DE00 */  lui       $v0, 0xde00
/* B8F1C 8012281C AC820000 */  sw        $v0, ($a0)
/* B8F20 80122820 3C028015 */  lui       $v0, %hi(D_8014BF18)
/* B8F24 80122824 2442BF18 */  addiu     $v0, $v0, %lo(D_8014BF18)
/* B8F28 80122828 08048A23 */  j         L8012288C_B8F8C
/* B8F2C 8012282C AC820004 */   sw       $v0, 4($a0)
glabel L80122830_B8F30
/* B8F30 80122830 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8F34 80122834 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8F38 80122838 8C620000 */  lw        $v0, ($v1)
/* B8F3C 8012283C 0040202D */  daddu     $a0, $v0, $zero
/* B8F40 80122840 24420008 */  addiu     $v0, $v0, 8
/* B8F44 80122844 AC620000 */  sw        $v0, ($v1)
/* B8F48 80122848 3C02DE00 */  lui       $v0, 0xde00
/* B8F4C 8012284C AC820000 */  sw        $v0, ($a0)
/* B8F50 80122850 3C028015 */  lui       $v0, %hi(D_8014BF40)
/* B8F54 80122854 2442BF40 */  addiu     $v0, $v0, %lo(D_8014BF40)
/* B8F58 80122858 08048A23 */  j         L8012288C_B8F8C
/* B8F5C 8012285C AC820004 */   sw       $v0, 4($a0)
glabel L80122860_B8F60
/* B8F60 80122860 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B8F64 80122864 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B8F68 80122868 8C620000 */  lw        $v0, ($v1)
/* B8F6C 8012286C 0040202D */  daddu     $a0, $v0, $zero
/* B8F70 80122870 24420008 */  addiu     $v0, $v0, 8
/* B8F74 80122874 AC620000 */  sw        $v0, ($v1)
/* B8F78 80122878 3C02DE00 */  lui       $v0, 0xde00
/* B8F7C 8012287C AC820000 */  sw        $v0, ($a0)
/* B8F80 80122880 3C028015 */  lui       $v0, %hi(D_8014BF68)
/* B8F84 80122884 2442BF68 */  addiu     $v0, $v0, %lo(D_8014BF68)
/* B8F88 80122888 AC820004 */  sw        $v0, 4($a0)
glabel L8012288C_B8F8C
/* B8F8C 8012288C 3C070001 */  lui       $a3, 1
/* B8F90 80122890 3C028015 */  lui       $v0, %hi(entity_fog_dist_max)
/* B8F94 80122894 8C424390 */  lw        $v0, %lo(entity_fog_dist_max)($v0)
/* B8F98 80122898 3C038015 */  lui       $v1, %hi(entity_fog_dist_min)
/* B8F9C 8012289C 8C63438C */  lw        $v1, %lo(entity_fog_dist_min)($v1)
/* B8FA0 801228A0 34E7F400 */  ori       $a3, $a3, 0xf400
/* B8FA4 801228A4 00431023 */  subu      $v0, $v0, $v1
/* B8FA8 801228A8 14400002 */  bnez      $v0, .L801228B4
/* B8FAC 801228AC 00E2001A */   div      $zero, $a3, $v0
/* B8FB0 801228B0 0007000D */  break     7
.L801228B4:
/* B8FB4 801228B4 2401FFFF */   addiu    $at, $zero, -1
/* B8FB8 801228B8 14410004 */  bne       $v0, $at, .L801228CC
/* B8FBC 801228BC 3C018000 */   lui      $at, 0x8000
/* B8FC0 801228C0 14E10002 */  bne       $a3, $at, .L801228CC
/* B8FC4 801228C4 00000000 */   nop
/* B8FC8 801228C8 0006000D */  break     6
.L801228CC:
/* B8FCC 801228CC 00003812 */   mflo     $a3
/* B8FD0 801228D0 240501F4 */  addiu     $a1, $zero, 0x1f4
/* B8FD4 801228D4 00A32823 */  subu      $a1, $a1, $v1
/* B8FD8 801228D8 00052A00 */  sll       $a1, $a1, 8
/* B8FDC 801228DC 14400002 */  bnez      $v0, .L801228E8
/* B8FE0 801228E0 00A2001A */   div      $zero, $a1, $v0
/* B8FE4 801228E4 0007000D */  break     7
.L801228E8:
/* B8FE8 801228E8 2401FFFF */   addiu    $at, $zero, -1
/* B8FEC 801228EC 14410004 */  bne       $v0, $at, .L80122900
/* B8FF0 801228F0 3C018000 */   lui      $at, 0x8000
/* B8FF4 801228F4 14A10002 */  bne       $a1, $at, .L80122900
/* B8FF8 801228F8 00000000 */   nop
/* B8FFC 801228FC 0006000D */  break     6
.L80122900:
/* B9000 80122900 00002812 */   mflo     $a1
/* B9004 80122904 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* B9008 80122908 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* B900C 8012290C 8D060000 */  lw        $a2, ($t0)
/* B9010 80122910 00C0482D */  daddu     $t1, $a2, $zero
/* B9014 80122914 24C60008 */  addiu     $a2, $a2, 8
/* B9018 80122918 3C02F800 */  lui       $v0, 0xf800
/* B901C 8012291C AD060000 */  sw        $a2, ($t0)
/* B9020 80122920 AD220000 */  sw        $v0, ($t1)
/* B9024 80122924 3C028015 */  lui       $v0, %hi(D_8015437F)
/* B9028 80122928 9042437F */  lbu       $v0, %lo(D_8015437F)($v0)
/* B902C 8012292C 3C038015 */  lui       $v1, %hi(D_80154383)
/* B9030 80122930 90634383 */  lbu       $v1, %lo(D_80154383)($v1)
/* B9034 80122934 3C048015 */  lui       $a0, %hi(D_80154387)
/* B9038 80122938 90844387 */  lbu       $a0, %lo(D_80154387)($a0)
/* B903C 8012293C 00021600 */  sll       $v0, $v0, 0x18
/* B9040 80122940 00031C00 */  sll       $v1, $v1, 0x10
/* B9044 80122944 00431025 */  or        $v0, $v0, $v1
/* B9048 80122948 00042200 */  sll       $a0, $a0, 8
/* B904C 8012294C 3C038015 */  lui       $v1, %hi(D_8015438B)
/* B9050 80122950 9063438B */  lbu       $v1, %lo(D_8015438B)($v1)
/* B9054 80122954 00441025 */  or        $v0, $v0, $a0
/* B9058 80122958 00431025 */  or        $v0, $v0, $v1
/* B905C 8012295C AD220004 */  sw        $v0, 4($t1)
/* B9060 80122960 24C20008 */  addiu     $v0, $a2, 8
/* B9064 80122964 AD020000 */  sw        $v0, ($t0)
/* B9068 80122968 3C02DB08 */  lui       $v0, 0xdb08
/* B906C 8012296C ACC20000 */  sw        $v0, ($a2)
/* B9070 80122970 00073C00 */  sll       $a3, $a3, 0x10
/* B9074 80122974 30A5FFFF */  andi      $a1, $a1, 0xffff
/* B9078 80122978 00E53825 */  or        $a3, $a3, $a1
/* B907C 8012297C ACC70004 */  sw        $a3, 4($a2)
glabel L80122980_B9080
/* B9080 80122980 3C02D9FD */  lui       $v0, 0xd9fd
.L80122984:
/* B9084 80122984 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* B9088 80122988 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* B908C 8012298C 3442FFFF */  ori       $v0, $v0, 0xffff
/* B9090 80122990 8CC50000 */  lw        $a1, ($a2)
/* B9094 80122994 3C048015 */  lui       $a0, %hi(entity_fog_enabled)
/* B9098 80122998 8C844378 */  lw        $a0, %lo(entity_fog_enabled)($a0)
/* B909C 8012299C 00A0182D */  daddu     $v1, $a1, $zero
/* B90A0 801229A0 24A50008 */  addiu     $a1, $a1, 8
/* B90A4 801229A4 ACC50000 */  sw        $a1, ($a2)
/* B90A8 801229A8 AC620000 */  sw        $v0, ($v1)
/* B90AC 801229AC 10800005 */  beqz      $a0, .L801229C4
/* B90B0 801229B0 AC600004 */   sw       $zero, 4($v1)
/* B90B4 801229B4 8E420000 */  lw        $v0, ($s2)
/* B90B8 801229B8 30420800 */  andi      $v0, $v0, 0x800
/* B90BC 801229BC 1040000A */  beqz      $v0, .L801229E8
/* B90C0 801229C0 3C02FC12 */   lui      $v0, 0xfc12
.L801229C4:
/* B90C4 801229C4 3C04FC12 */  lui       $a0, 0xfc12
/* B90C8 801229C8 34841824 */  ori       $a0, $a0, 0x1824
/* B90CC 801229CC 3C03FF33 */  lui       $v1, 0xff33
/* B90D0 801229D0 3463FFFF */  ori       $v1, $v1, 0xffff
/* B90D4 801229D4 24A20008 */  addiu     $v0, $a1, 8
/* B90D8 801229D8 ACC20000 */  sw        $v0, ($a2)
/* B90DC 801229DC ACA40000 */  sw        $a0, ($a1)
/* B90E0 801229E0 08048A80 */  j         .L80122A00
/* B90E4 801229E4 ACA30004 */   sw       $v1, 4($a1)
.L801229E8:
/* B90E8 801229E8 34421E04 */  ori       $v0, $v0, 0x1e04
/* B90EC 801229EC 24A30008 */  addiu     $v1, $a1, 8
/* B90F0 801229F0 ACC30000 */  sw        $v1, ($a2)
/* B90F4 801229F4 ACA20000 */  sw        $v0, ($a1)
/* B90F8 801229F8 2402F3F8 */  addiu     $v0, $zero, -0xc08
/* B90FC 801229FC ACA20004 */  sw        $v0, 4($a1)
.L80122A00:
/* B9100 80122A00 8E42005C */  lw        $v0, 0x5c($s2)
/* B9104 80122A04 10400012 */  beqz      $v0, .L80122A50
/* B9108 80122A08 3C07D838 */   lui      $a3, 0xd838
/* B910C 80122A0C 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* B9110 80122A10 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* B9114 80122A14 8C830000 */  lw        $v1, ($a0)
/* B9118 80122A18 3C028015 */  lui       $v0, %hi(D_80154374)
/* B911C 80122A1C 8C424374 */  lw        $v0, %lo(D_80154374)($v0)
/* B9120 80122A20 0060282D */  daddu     $a1, $v1, $zero
/* B9124 80122A24 24630008 */  addiu     $v1, $v1, 8
/* B9128 80122A28 00021080 */  sll       $v0, $v0, 2
/* B912C 80122A2C 3042FFFF */  andi      $v0, $v0, 0xffff
/* B9130 80122A30 AC830000 */  sw        $v1, ($a0)
/* B9134 80122A34 3C03DB06 */  lui       $v1, 0xdb06
/* B9138 80122A38 00431025 */  or        $v0, $v0, $v1
/* B913C 80122A3C ACA20000 */  sw        $v0, ($a1)
/* B9140 80122A40 8E42005C */  lw        $v0, 0x5c($s2)
/* B9144 80122A44 3C038000 */  lui       $v1, 0x8000
/* B9148 80122A48 00431021 */  addu      $v0, $v0, $v1
/* B914C 80122A4C ACA20004 */  sw        $v0, 4($a1)
.L80122A50:
/* B9150 80122A50 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* B9154 80122A54 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* B9158 80122A58 34E70002 */  ori       $a3, $a3, 2
/* B915C 80122A5C 8CA20000 */  lw        $v0, ($a1)
/* B9160 80122A60 3C03DE00 */  lui       $v1, 0xde00
/* B9164 80122A64 0040302D */  daddu     $a2, $v0, $zero
/* B9168 80122A68 24420008 */  addiu     $v0, $v0, 8
/* B916C 80122A6C ACA20000 */  sw        $v0, ($a1)
/* B9170 80122A70 ACC30000 */  sw        $v1, ($a2)
/* B9174 80122A74 8E440014 */  lw        $a0, 0x14($s2)
/* B9178 80122A78 24430008 */  addiu     $v1, $v0, 8
/* B917C 80122A7C ACA30000 */  sw        $v1, ($a1)
/* B9180 80122A80 24030040 */  addiu     $v1, $zero, 0x40
/* B9184 80122A84 ACC40004 */  sw        $a0, 4($a2)
/* B9188 80122A88 AC430004 */  sw        $v1, 4($v0)
/* B918C 80122A8C 3C03E700 */  lui       $v1, 0xe700
/* B9190 80122A90 AC470000 */  sw        $a3, ($v0)
/* B9194 80122A94 AC430008 */  sw        $v1, 8($v0)
/* B9198 80122A98 AC40000C */  sw        $zero, 0xc($v0)
/* B919C 80122A9C 8E430000 */  lw        $v1, ($s2)
/* B91A0 80122AA0 24420010 */  addiu     $v0, $v0, 0x10
/* B91A4 80122AA4 30630200 */  andi      $v1, $v1, 0x200
/* B91A8 80122AA8 106000AE */  beqz      $v1, .L80122D64
/* B91AC 80122AAC ACA20000 */   sw       $v0, ($a1)
/* B91B0 80122AB0 27A40010 */  addiu     $a0, $sp, 0x10
/* B91B4 80122AB4 26510018 */  addiu     $s1, $s2, 0x18
/* B91B8 80122AB8 0C019D60 */  jal       guMtxL2F
/* B91BC 80122ABC 0220282D */   daddu    $a1, $s1, $zero
/* B91C0 80122AC0 27B00050 */  addiu     $s0, $sp, 0x50
/* B91C4 80122AC4 0C048450 */  jal       make_entity_model_mtx_flipZ
/* B91C8 80122AC8 0200202D */   daddu    $a0, $s0, $zero
/* B91CC 80122ACC 27A40010 */  addiu     $a0, $sp, 0x10
/* B91D0 80122AD0 0200282D */  daddu     $a1, $s0, $zero
/* B91D4 80122AD4 0C019D80 */  jal       guMtxCatF
/* B91D8 80122AD8 0080302D */   daddu    $a2, $a0, $zero
/* B91DC 80122ADC 27A40010 */  addiu     $a0, $sp, 0x10
/* B91E0 80122AE0 0C019D40 */  jal       guMtxF2L
/* B91E4 80122AE4 0220282D */   daddu    $a1, $s1, $zero
/* B91E8 80122AE8 3C040001 */  lui       $a0, 1
/* B91EC 80122AEC 34841630 */  ori       $a0, $a0, 0x1630
/* B91F0 80122AF0 26450058 */  addiu     $a1, $s2, 0x58
/* B91F4 80122AF4 3C028007 */  lui       $v0, %hi(gMatrixListPos)
/* B91F8 80122AF8 944241F0 */  lhu       $v0, %lo(gMatrixListPos)($v0)
/* B91FC 80122AFC 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* B9200 80122B00 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* B9204 80122B04 00021180 */  sll       $v0, $v0, 6
/* B9208 80122B08 00621821 */  addu      $v1, $v1, $v0
/* B920C 80122B0C 00641821 */  addu      $v1, $v1, $a0
.L80122B10:
/* B9210 80122B10 8E2E0000 */  lw        $t6, ($s1)
/* B9214 80122B14 8E2F0004 */  lw        $t7, 4($s1)
/* B9218 80122B18 8E380008 */  lw        $t8, 8($s1)
/* B921C 80122B1C 8E39000C */  lw        $t9, 0xc($s1)
/* B9220 80122B20 AC6E0000 */  sw        $t6, ($v1)
/* B9224 80122B24 AC6F0004 */  sw        $t7, 4($v1)
/* B9228 80122B28 AC780008 */  sw        $t8, 8($v1)
/* B922C 80122B2C AC79000C */  sw        $t9, 0xc($v1)
/* B9230 80122B30 26310010 */  addiu     $s1, $s1, 0x10
/* B9234 80122B34 1625FFF6 */  bne       $s1, $a1, .L80122B10
/* B9238 80122B38 24630010 */   addiu    $v1, $v1, 0x10
/* B923C 80122B3C 3C03DA38 */  lui       $v1, 0xda38
/* B9240 80122B40 34630002 */  ori       $v1, $v1, 2
/* B9244 80122B44 3C080001 */  lui       $t0, 1
/* B9248 80122B48 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* B924C 80122B4C 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* B9250 80122B50 35081630 */  ori       $t0, $t0, 0x1630
/* B9254 80122B54 3C058007 */  lui       $a1, %hi(gMatrixListPos)
/* B9258 80122B58 24A541F0 */  addiu     $a1, $a1, %lo(gMatrixListPos)
/* B925C 80122B5C 8CC40000 */  lw        $a0, ($a2)
/* B9260 80122B60 94A20000 */  lhu       $v0, ($a1)
/* B9264 80122B64 0080382D */  daddu     $a3, $a0, $zero
/* B9268 80122B68 24840008 */  addiu     $a0, $a0, 8
/* B926C 80122B6C ACC40000 */  sw        $a0, ($a2)
/* B9270 80122B70 ACE30000 */  sw        $v1, ($a3)
/* B9274 80122B74 24430001 */  addiu     $v1, $v0, 1
/* B9278 80122B78 3042FFFF */  andi      $v0, $v0, 0xffff
/* B927C 80122B7C 00021180 */  sll       $v0, $v0, 6
/* B9280 80122B80 A4A30000 */  sh        $v1, ($a1)
/* B9284 80122B84 3C03800A */  lui       $v1, %hi(gDisplayContext)
/* B9288 80122B88 8C63A674 */  lw        $v1, %lo(gDisplayContext)($v1)
/* B928C 80122B8C 00481021 */  addu      $v0, $v0, $t0
/* B9290 80122B90 00621821 */  addu      $v1, $v1, $v0
/* B9294 80122B94 3C02DE00 */  lui       $v0, 0xde00
/* B9298 80122B98 ACE30004 */  sw        $v1, 4($a3)
/* B929C 80122B9C AC820000 */  sw        $v0, ($a0)
/* B92A0 80122BA0 8E430014 */  lw        $v1, 0x14($s2)
/* B92A4 80122BA4 24820008 */  addiu     $v0, $a0, 8
/* B92A8 80122BA8 ACC20000 */  sw        $v0, ($a2)
/* B92AC 80122BAC 08048B49 */  j         .L80122D24
/* B92B0 80122BB0 AC830004 */   sw       $v1, 4($a0)
.L80122BB4:
/* B92B4 80122BB4 3C03D9C0 */  lui       $v1, 0xd9c0
/* B92B8 80122BB8 3463F9FA */  ori       $v1, $v1, 0xf9fa
/* B92BC 80122BBC 3C05D9FF */  lui       $a1, 0xd9ff
/* B92C0 80122BC0 34A5FFFF */  ori       $a1, $a1, 0xffff
/* B92C4 80122BC4 3C040022 */  lui       $a0, 0x22
/* B92C8 80122BC8 34840005 */  ori       $a0, $a0, 5
/* B92CC 80122BCC 3C06DC08 */  lui       $a2, 0xdc08
/* B92D0 80122BD0 34C6060A */  ori       $a2, $a2, 0x60a
/* B92D4 80122BD4 3C07DC08 */  lui       $a3, 0xdc08
/* B92D8 80122BD8 34E7090A */  ori       $a3, $a3, 0x90a
/* B92DC 80122BDC 3C08D700 */  lui       $t0, 0xd700
/* B92E0 80122BE0 35080002 */  ori       $t0, $t0, 2
/* B92E4 80122BE4 3C0AE200 */  lui       $t2, 0xe200
/* B92E8 80122BE8 354A1E01 */  ori       $t2, $t2, 0x1e01
/* B92EC 80122BEC 3C0BE300 */  lui       $t3, 0xe300
/* B92F0 80122BF0 356B0A11 */  ori       $t3, $t3, 0xa11
/* B92F4 80122BF4 3C090008 */  lui       $t1, 8
/* B92F8 80122BF8 35292CF0 */  ori       $t1, $t1, 0x2cf0
/* B92FC 80122BFC 25820008 */  addiu     $v0, $t4, 8
/* B9300 80122C00 ADA20000 */  sw        $v0, ($t5)
/* B9304 80122C04 3C02E700 */  lui       $v0, 0xe700
/* B9308 80122C08 AD820000 */  sw        $v0, ($t4)
/* B930C 80122C0C 25820010 */  addiu     $v0, $t4, 0x10
/* B9310 80122C10 AD800004 */  sw        $zero, 4($t4)
/* B9314 80122C14 ADA20000 */  sw        $v0, ($t5)
/* B9318 80122C18 25820018 */  addiu     $v0, $t4, 0x18
/* B931C 80122C1C AD830008 */  sw        $v1, 8($t4)
/* B9320 80122C20 AD80000C */  sw        $zero, 0xc($t4)
/* B9324 80122C24 ADA20000 */  sw        $v0, ($t5)
/* B9328 80122C28 25820020 */  addiu     $v0, $t4, 0x20
/* B932C 80122C2C AD850010 */  sw        $a1, 0x10($t4)
/* B9330 80122C30 AD840014 */  sw        $a0, 0x14($t4)
/* B9334 80122C34 ADA20000 */  sw        $v0, ($t5)
/* B9338 80122C38 3C02DB02 */  lui       $v0, 0xdb02
/* B933C 80122C3C AD820018 */  sw        $v0, 0x18($t4)
/* B9340 80122C40 24020018 */  addiu     $v0, $zero, 0x18
/* B9344 80122C44 AD82001C */  sw        $v0, 0x1c($t4)
/* B9348 80122C48 25820028 */  addiu     $v0, $t4, 0x28
/* B934C 80122C4C ADA20000 */  sw        $v0, ($t5)
/* B9350 80122C50 3C028015 */  lui       $v0, %hi(D_8014C270)
/* B9354 80122C54 2442C270 */  addiu     $v0, $v0, %lo(D_8014C270)
/* B9358 80122C58 AD820024 */  sw        $v0, 0x24($t4)
/* B935C 80122C5C 2442FFF8 */  addiu     $v0, $v0, -8
/* B9360 80122C60 AD82002C */  sw        $v0, 0x2c($t4)
/* B9364 80122C64 2402FFFF */  addiu     $v0, $zero, -1
/* B9368 80122C68 AD860020 */  sw        $a2, 0x20($t4)
/* B936C 80122C6C AD870028 */  sw        $a3, 0x28($t4)
/* B9370 80122C70 AD880030 */  sw        $t0, 0x30($t4)
/* B9374 80122C74 AD820034 */  sw        $v0, 0x34($t4)
/* B9378 80122C78 AD8A0038 */  sw        $t2, 0x38($t4)
/* B937C 80122C7C AD80003C */  sw        $zero, 0x3c($t4)
/* B9380 80122C80 AD8B0040 */  sw        $t3, 0x40($t4)
/* B9384 80122C84 AD890044 */  sw        $t1, 0x44($t4)
/* B9388 80122C88 8E460014 */  lw        $a2, 0x14($s2)
/* B938C 80122C8C 25820030 */  addiu     $v0, $t4, 0x30
/* B9390 80122C90 ADA20000 */  sw        $v0, ($t5)
/* B9394 80122C94 25820038 */  addiu     $v0, $t4, 0x38
/* B9398 80122C98 8CC30000 */  lw        $v1, ($a2)
/* B939C 80122C9C 27B000A8 */  addiu     $s0, $sp, 0xa8
/* B93A0 80122CA0 ADA20000 */  sw        $v0, ($t5)
/* B93A4 80122CA4 AFA30090 */  sw        $v1, 0x90($sp)
/* B93A8 80122CA8 8CC30004 */  lw        $v1, 4($a2)
/* B93AC 80122CAC 25820040 */  addiu     $v0, $t4, 0x40
/* B93B0 80122CB0 ADA20000 */  sw        $v0, ($t5)
/* B93B4 80122CB4 AFA30094 */  sw        $v1, 0x94($sp)
/* B93B8 80122CB8 94C3000A */  lhu       $v1, 0xa($a2)
/* B93BC 80122CBC 25820048 */  addiu     $v0, $t4, 0x48
/* B93C0 80122CC0 ADA20000 */  sw        $v0, ($t5)
/* B93C4 80122CC4 A7A30098 */  sh        $v1, 0x98($sp)
/* B93C8 80122CC8 94C2000E */  lhu       $v0, 0xe($a2)
/* B93CC 80122CCC 0200202D */  daddu     $a0, $s0, $zero
/* B93D0 80122CD0 A7A2009A */  sh        $v0, 0x9a($sp)
/* B93D4 80122CD4 8CC20008 */  lw        $v0, 8($a2)
/* B93D8 80122CD8 26450018 */  addiu     $a1, $s2, 0x18
/* B93DC 80122CDC 00021023 */  negu      $v0, $v0
/* B93E0 80122CE0 00021FC2 */  srl       $v1, $v0, 0x1f
/* B93E4 80122CE4 00431021 */  addu      $v0, $v0, $v1
/* B93E8 80122CE8 00021043 */  sra       $v0, $v0, 1
/* B93EC 80122CEC A7A2009C */  sh        $v0, 0x9c($sp)
/* B93F0 80122CF0 8CC2000C */  lw        $v0, 0xc($a2)
/* B93F4 80122CF4 240300FF */  addiu     $v1, $zero, 0xff
/* B93F8 80122CF8 A3A300A0 */  sb        $v1, 0xa0($sp)
/* B93FC 80122CFC 00021FC2 */  srl       $v1, $v0, 0x1f
/* B9400 80122D00 00431021 */  addu      $v0, $v0, $v1
/* B9404 80122D04 00021043 */  sra       $v0, $v0, 1
/* B9408 80122D08 0C019D60 */  jal       guMtxL2F
/* B940C 80122D0C A7A2009E */   sh       $v0, 0x9e($sp)
/* B9410 80122D10 0000202D */  daddu     $a0, $zero, $zero
/* B9414 80122D14 27A50090 */  addiu     $a1, $sp, 0x90
/* B9418 80122D18 0080302D */  daddu     $a2, $a0, $zero
/* B941C 80122D1C 0C04EBDC */  jal       func_8013AF70
/* B9420 80122D20 0200382D */   daddu    $a3, $s0, $zero
.L80122D24:
/* B9424 80122D24 3C03D838 */  lui       $v1, 0xd838
/* B9428 80122D28 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* B942C 80122D2C 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* B9430 80122D30 8C820000 */  lw        $v0, ($a0)
/* B9434 80122D34 34630002 */  ori       $v1, $v1, 2
/* B9438 80122D38 0040282D */  daddu     $a1, $v0, $zero
/* B943C 80122D3C 24420008 */  addiu     $v0, $v0, 8
/* B9440 80122D40 AC820000 */  sw        $v0, ($a0)
/* B9444 80122D44 ACA30000 */  sw        $v1, ($a1)
/* B9448 80122D48 24030040 */  addiu     $v1, $zero, 0x40
/* B944C 80122D4C ACA30004 */  sw        $v1, 4($a1)
/* B9450 80122D50 24430008 */  addiu     $v1, $v0, 8
/* B9454 80122D54 AC830000 */  sw        $v1, ($a0)
/* B9458 80122D58 3C03E700 */  lui       $v1, 0xe700
/* B945C 80122D5C AC430000 */  sw        $v1, ($v0)
/* B9460 80122D60 AC400004 */  sw        $zero, 4($v0)
.L80122D64:
/* B9464 80122D64 8FBF00F4 */  lw        $ra, 0xf4($sp)
/* B9468 80122D68 8FB200F0 */  lw        $s2, 0xf0($sp)
/* B946C 80122D6C 8FB100EC */  lw        $s1, 0xec($sp)
/* B9470 80122D70 8FB000E8 */  lw        $s0, 0xe8($sp)
/* B9474 80122D74 03E00008 */  jr        $ra
/* B9478 80122D78 27BD00F8 */   addiu    $sp, $sp, 0xf8
