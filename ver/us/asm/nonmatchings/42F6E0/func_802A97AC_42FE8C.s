.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A97AC_42FE8C
/* 42FE8C 802A97AC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42FE90 802A97B0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 42FE94 802A97B4 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42FE98 802A97B8 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42FE9C 802A97BC AFBF0020 */  sw        $ra, 0x20($sp)
/* 42FEA0 802A97C0 AFB00018 */  sw        $s0, 0x18($sp)
/* 42FEA4 802A97C4 0C0511EA */  jal       draw_hud_element_clipped
/* 42FEA8 802A97C8 8E240004 */   lw       $a0, 4($s1)
/* 42FEAC 802A97CC 0C0511EA */  jal       draw_hud_element_clipped
/* 42FEB0 802A97D0 8E24000C */   lw       $a0, 0xc($s1)
/* 42FEB4 802A97D4 8E300008 */  lw        $s0, 8($s1)
/* 42FEB8 802A97D8 0C0511EA */  jal       draw_hud_element_clipped
/* 42FEBC 802A97DC 0200202D */   daddu    $a0, $s0, $zero
/* 42FEC0 802A97E0 0200202D */  daddu     $a0, $s0, $zero
/* 42FEC4 802A97E4 27A50010 */  addiu     $a1, $sp, 0x10
/* 42FEC8 802A97E8 0C05126B */  jal       get_hud_element_render_pos
/* 42FECC 802A97EC 27A60014 */   addiu    $a2, $sp, 0x14
/* 42FED0 802A97F0 86220068 */  lh        $v0, 0x68($s1)
/* 42FED4 802A97F4 14400011 */  bnez      $v0, .L802A983C
/* 42FED8 802A97F8 3C0451EB */   lui      $a0, 0x51eb
/* 42FEDC 802A97FC 96230044 */  lhu       $v1, 0x44($s1)
/* 42FEE0 802A9800 3484851F */  ori       $a0, $a0, 0x851f
/* 42FEE4 802A9804 00031C00 */  sll       $v1, $v1, 0x10
/* 42FEE8 802A9808 00031403 */  sra       $v0, $v1, 0x10
/* 42FEEC 802A980C 00440018 */  mult      $v0, $a0
/* 42FEF0 802A9810 8FA50014 */  lw        $a1, 0x14($sp)
/* 42FEF4 802A9814 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42FEF8 802A9818 8FA40010 */  lw        $a0, 0x10($sp)
/* 42FEFC 802A981C 00003810 */  mfhi      $a3
/* 42FF00 802A9820 00073143 */  sra       $a2, $a3, 5
/* 42FF04 802A9824 00C33023 */  subu      $a2, $a2, $v1
/* 42FF08 802A9828 00063400 */  sll       $a2, $a2, 0x10
/* 42FF0C 802A982C 0C09A1DC */  jal       func_80268770
/* 42FF10 802A9830 00063403 */   sra      $a2, $a2, 0x10
/* 42FF14 802A9834 080AA61D */  j         .L802A9874
/* 42FF18 802A9838 00000000 */   nop
.L802A983C:
/* 42FF1C 802A983C 96230044 */  lhu       $v1, 0x44($s1)
/* 42FF20 802A9840 3484851F */  ori       $a0, $a0, 0x851f
/* 42FF24 802A9844 00031C00 */  sll       $v1, $v1, 0x10
/* 42FF28 802A9848 00031403 */  sra       $v0, $v1, 0x10
/* 42FF2C 802A984C 00440018 */  mult      $v0, $a0
/* 42FF30 802A9850 8FA50014 */  lw        $a1, 0x14($sp)
/* 42FF34 802A9854 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42FF38 802A9858 8FA40010 */  lw        $a0, 0x10($sp)
/* 42FF3C 802A985C 00003810 */  mfhi      $a3
/* 42FF40 802A9860 00073143 */  sra       $a2, $a3, 5
/* 42FF44 802A9864 00C33023 */  subu      $a2, $a2, $v1
/* 42FF48 802A9868 00063400 */  sll       $a2, $a2, 0x10
/* 42FF4C 802A986C 0C09A203 */  jal       func_8026880C
/* 42FF50 802A9870 00063403 */   sra      $a2, $a2, 0x10
.L802A9874:
/* 42FF54 802A9874 8E240014 */  lw        $a0, 0x14($s1)
/* 42FF58 802A9878 0C0511EA */  jal       draw_hud_element_clipped
/* 42FF5C 802A987C 00000000 */   nop
/* 42FF60 802A9880 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42FF64 802A9884 8FB1001C */  lw        $s1, 0x1c($sp)
/* 42FF68 802A9888 8FB00018 */  lw        $s0, 0x18($sp)
/* 42FF6C 802A988C 03E00008 */  jr        $ra
/* 42FF70 802A9890 27BD0028 */   addiu    $sp, $sp, 0x28
