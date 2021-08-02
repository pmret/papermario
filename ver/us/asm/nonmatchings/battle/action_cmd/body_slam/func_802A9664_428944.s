.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9664_428944
/* 428944 802A9664 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 428948 802A9668 AFB1001C */  sw        $s1, 0x1c($sp)
/* 42894C 802A966C 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 428950 802A9670 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 428954 802A9674 AFBF0020 */  sw        $ra, 0x20($sp)
/* 428958 802A9678 AFB00018 */  sw        $s0, 0x18($sp)
/* 42895C 802A967C 0C0511EA */  jal       draw_hud_element_clipped
/* 428960 802A9680 8E240004 */   lw       $a0, 4($s1)
/* 428964 802A9684 8E300008 */  lw        $s0, 8($s1)
/* 428968 802A9688 0C0511EA */  jal       draw_hud_element_clipped
/* 42896C 802A968C 0200202D */   daddu    $a0, $s0, $zero
/* 428970 802A9690 0200202D */  daddu     $a0, $s0, $zero
/* 428974 802A9694 27A50010 */  addiu     $a1, $sp, 0x10
/* 428978 802A9698 0C05126B */  jal       get_hud_element_render_pos
/* 42897C 802A969C 27A60014 */   addiu    $a2, $sp, 0x14
/* 428980 802A96A0 8E240010 */  lw        $a0, 0x10($s1)
/* 428984 802A96A4 0C0511EA */  jal       draw_hud_element_clipped
/* 428988 802A96A8 00000000 */   nop
/* 42898C 802A96AC 3C0451EB */  lui       $a0, 0x51eb
/* 428990 802A96B0 96230044 */  lhu       $v1, 0x44($s1)
/* 428994 802A96B4 3484851F */  ori       $a0, $a0, 0x851f
/* 428998 802A96B8 00031C00 */  sll       $v1, $v1, 0x10
/* 42899C 802A96BC 00031403 */  sra       $v0, $v1, 0x10
/* 4289A0 802A96C0 00440018 */  mult      $v0, $a0
/* 4289A4 802A96C4 8FA50014 */  lw        $a1, 0x14($sp)
/* 4289A8 802A96C8 00031FC3 */  sra       $v1, $v1, 0x1f
/* 4289AC 802A96CC 8FA40010 */  lw        $a0, 0x10($sp)
/* 4289B0 802A96D0 00003810 */  mfhi      $a3
/* 4289B4 802A96D4 00073143 */  sra       $a2, $a3, 5
/* 4289B8 802A96D8 00C33023 */  subu      $a2, $a2, $v1
/* 4289BC 802A96DC 00063400 */  sll       $a2, $a2, 0x10
/* 4289C0 802A96E0 0C09A1DC */  jal       func_80268770
/* 4289C4 802A96E4 00063403 */   sra      $a2, $a2, 0x10
/* 4289C8 802A96E8 8E24000C */  lw        $a0, 0xc($s1)
/* 4289CC 802A96EC 0C0511EA */  jal       draw_hud_element_clipped
/* 4289D0 802A96F0 00000000 */   nop
/* 4289D4 802A96F4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4289D8 802A96F8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 4289DC 802A96FC 8FB00018 */  lw        $s0, 0x18($sp)
/* 4289E0 802A9700 03E00008 */  jr        $ra
/* 4289E4 802A9704 27BD0028 */   addiu    $sp, $sp, 0x28
