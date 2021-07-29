.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414BC_D65A9C
/* D65A9C 802414BC 27BDFED0 */  addiu     $sp, $sp, -0x130
/* D65AA0 802414C0 AFB1011C */  sw        $s1, 0x11c($sp)
/* D65AA4 802414C4 AFBF0120 */  sw        $ra, 0x120($sp)
/* D65AA8 802414C8 AFB00118 */  sw        $s0, 0x118($sp)
/* D65AAC 802414CC F7B40128 */  sdc1      $f20, 0x128($sp)
/* D65AB0 802414D0 0C00E769 */  jal       npc_get_render_yaw
/* D65AB4 802414D4 0080882D */   daddu    $s1, $a0, $zero
/* D65AB8 802414D8 44800000 */  mtc1      $zero, $f0
/* D65ABC 802414DC 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D65AC0 802414E0 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D65AC4 802414E4 C6220034 */  lwc1      $f2, 0x34($s1)
/* D65AC8 802414E8 00031080 */  sll       $v0, $v1, 2
/* D65ACC 802414EC 00431021 */  addu      $v0, $v0, $v1
/* D65AD0 802414F0 00021080 */  sll       $v0, $v0, 2
/* D65AD4 802414F4 00431023 */  subu      $v0, $v0, $v1
/* D65AD8 802414F8 000218C0 */  sll       $v1, $v0, 3
/* D65ADC 802414FC 00431021 */  addu      $v0, $v0, $v1
/* D65AE0 80241500 000210C0 */  sll       $v0, $v0, 3
/* D65AE4 80241504 44060000 */  mfc1      $a2, $f0
/* D65AE8 80241508 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* D65AEC 8024150C 00220821 */  addu      $at, $at, $v0
/* D65AF0 80241510 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* D65AF4 80241514 3C013F80 */  lui       $at, 0x3f80
/* D65AF8 80241518 4481A000 */  mtc1      $at, $f20
/* D65AFC 8024151C 46001080 */  add.s     $f2, $f2, $f0
/* D65B00 80241520 4407A000 */  mfc1      $a3, $f20
/* D65B04 80241524 44051000 */  mfc1      $a1, $f2
/* D65B08 80241528 27A40018 */  addiu     $a0, $sp, 0x18
/* D65B0C 8024152C 0C019EC8 */  jal       guRotateF
/* D65B10 80241530 AFA60010 */   sw       $a2, 0x10($sp)
/* D65B14 80241534 3C013F36 */  lui       $at, 0x3f36
/* D65B18 80241538 3421DB6E */  ori       $at, $at, 0xdb6e
/* D65B1C 8024153C 44810000 */  mtc1      $at, $f0
/* D65B20 80241540 27B000D8 */  addiu     $s0, $sp, 0xd8
/* D65B24 80241544 44050000 */  mfc1      $a1, $f0
/* D65B28 80241548 0200202D */  daddu     $a0, $s0, $zero
/* D65B2C 8024154C 00A0302D */  daddu     $a2, $a1, $zero
/* D65B30 80241550 0C019DF0 */  jal       guScaleF
/* D65B34 80241554 00A0382D */   daddu    $a3, $a1, $zero
/* D65B38 80241558 27A40018 */  addiu     $a0, $sp, 0x18
/* D65B3C 8024155C 0200282D */  daddu     $a1, $s0, $zero
/* D65B40 80241560 0C019D80 */  jal       guMtxCatF
/* D65B44 80241564 0080302D */   daddu    $a2, $a0, $zero
/* D65B48 80241568 27B00058 */  addiu     $s0, $sp, 0x58
/* D65B4C 8024156C 8E250038 */  lw        $a1, 0x38($s1)
/* D65B50 80241570 8E26003C */  lw        $a2, 0x3c($s1)
/* D65B54 80241574 8E270040 */  lw        $a3, 0x40($s1)
/* D65B58 80241578 0C019E40 */  jal       guTranslateF
/* D65B5C 8024157C 0200202D */   daddu    $a0, $s0, $zero
/* D65B60 80241580 27A40018 */  addiu     $a0, $sp, 0x18
/* D65B64 80241584 0200282D */  daddu     $a1, $s0, $zero
/* D65B68 80241588 0C019D80 */  jal       guMtxCatF
/* D65B6C 8024158C 0080302D */   daddu    $a2, $a0, $zero
/* D65B70 80241590 8E250028 */  lw        $a1, 0x28($s1)
/* D65B74 80241594 4406A000 */  mfc1      $a2, $f20
/* D65B78 80241598 0C0B76A3 */  jal       spr_update_player_sprite
/* D65B7C 8024159C 24040002 */   addiu    $a0, $zero, 2
/* D65B80 802415A0 24040002 */  addiu     $a0, $zero, 2
/* D65B84 802415A4 0000282D */  daddu     $a1, $zero, $zero
/* D65B88 802415A8 00A0302D */  daddu     $a2, $a1, $zero
/* D65B8C 802415AC 00A0382D */  daddu     $a3, $a1, $zero
/* D65B90 802415B0 27A20018 */  addiu     $v0, $sp, 0x18
/* D65B94 802415B4 0C0B7710 */  jal       spr_draw_player_sprite
/* D65B98 802415B8 AFA20010 */   sw       $v0, 0x10($sp)
/* D65B9C 802415BC 8FBF0120 */  lw        $ra, 0x120($sp)
/* D65BA0 802415C0 8FB1011C */  lw        $s1, 0x11c($sp)
/* D65BA4 802415C4 8FB00118 */  lw        $s0, 0x118($sp)
/* D65BA8 802415C8 D7B40128 */  ldc1      $f20, 0x128($sp)
/* D65BAC 802415CC 03E00008 */  jr        $ra
/* D65BB0 802415D0 27BD0130 */   addiu    $sp, $sp, 0x130
/* D65BB4 802415D4 00000000 */  nop
/* D65BB8 802415D8 00000000 */  nop
/* D65BBC 802415DC 00000000 */  nop
