.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A94D8_426028
/* 426028 802A94D8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42602C 802A94DC AFB1001C */  sw        $s1, 0x1c($sp)
/* 426030 802A94E0 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 426034 802A94E4 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 426038 802A94E8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 42603C 802A94EC AFB00018 */  sw        $s0, 0x18($sp)
/* 426040 802A94F0 0C0511EA */  jal       draw_hud_element_clipped
/* 426044 802A94F4 8E240004 */   lw       $a0, 4($s1)
/* 426048 802A94F8 8E300008 */  lw        $s0, 8($s1)
/* 42604C 802A94FC 0C0511EA */  jal       draw_hud_element_clipped
/* 426050 802A9500 0200202D */   daddu    $a0, $s0, $zero
/* 426054 802A9504 0200202D */  daddu     $a0, $s0, $zero
/* 426058 802A9508 27A50010 */  addiu     $a1, $sp, 0x10
/* 42605C 802A950C 0C05126B */  jal       get_hud_element_render_pos
/* 426060 802A9510 27A60014 */   addiu    $a2, $sp, 0x14
/* 426064 802A9514 3C02802B */  lui       $v0, %hi(D_802A9620)
/* 426068 802A9518 8C429620 */  lw        $v0, %lo(D_802A9620)($v0)
/* 42606C 802A951C 14400008 */  bnez      $v0, .L802A9540
/* 426070 802A9520 3C0451EB */   lui      $a0, 0x51eb
/* 426074 802A9524 96230044 */  lhu       $v1, 0x44($s1)
/* 426078 802A9528 3484851F */  ori       $a0, $a0, 0x851f
/* 42607C 802A952C 00031C00 */  sll       $v1, $v1, 0x10
/* 426080 802A9530 00031403 */  sra       $v0, $v1, 0x10
/* 426084 802A9534 00440018 */  mult      $v0, $a0
/* 426088 802A9538 080AA556 */  j         .L802A9558
/* 42608C 802A953C 24070001 */   addiu    $a3, $zero, 1
.L802A9540:
/* 426090 802A9540 96230044 */  lhu       $v1, 0x44($s1)
/* 426094 802A9544 3484851F */  ori       $a0, $a0, 0x851f
/* 426098 802A9548 00031C00 */  sll       $v1, $v1, 0x10
/* 42609C 802A954C 00031403 */  sra       $v0, $v1, 0x10
/* 4260A0 802A9550 00440018 */  mult      $v0, $a0
/* 4260A4 802A9554 24070002 */  addiu     $a3, $zero, 2
.L802A9558:
/* 4260A8 802A9558 8FA50014 */  lw        $a1, 0x14($sp)
/* 4260AC 802A955C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 4260B0 802A9560 8FA40010 */  lw        $a0, 0x10($sp)
/* 4260B4 802A9564 00004010 */  mfhi      $t0
/* 4260B8 802A9568 00083143 */  sra       $a2, $t0, 5
/* 4260BC 802A956C 00C33023 */  subu      $a2, $a2, $v1
/* 4260C0 802A9570 00063400 */  sll       $a2, $a2, 0x10
/* 4260C4 802A9574 0C09A1E6 */  jal       func_80268798
/* 4260C8 802A9578 00063403 */   sra      $a2, $a2, 0x10
/* 4260CC 802A957C 8E24000C */  lw        $a0, 0xc($s1)
/* 4260D0 802A9580 0C0511EA */  jal       draw_hud_element_clipped
/* 4260D4 802A9584 00000000 */   nop
/* 4260D8 802A9588 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4260DC 802A958C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 4260E0 802A9590 8FB00018 */  lw        $s0, 0x18($sp)
/* 4260E4 802A9594 03E00008 */  jr        $ra
/* 4260E8 802A9598 27BD0028 */   addiu    $sp, $sp, 0x28
