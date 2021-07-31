.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A97F8_42E208
/* 42E208 802A97F8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42E20C 802A97FC AFB1001C */  sw        $s1, 0x1c($sp)
/* 42E210 802A9800 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42E214 802A9804 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42E218 802A9808 AFBF0020 */  sw        $ra, 0x20($sp)
/* 42E21C 802A980C AFB00018 */  sw        $s0, 0x18($sp)
/* 42E220 802A9810 0C0511EA */  jal       draw_hud_element_clipped
/* 42E224 802A9814 8E240004 */   lw       $a0, 4($s1)
/* 42E228 802A9818 0C0511EA */  jal       draw_hud_element_clipped
/* 42E22C 802A981C 8E24000C */   lw       $a0, 0xc($s1)
/* 42E230 802A9820 8E300008 */  lw        $s0, 8($s1)
/* 42E234 802A9824 0C0511EA */  jal       draw_hud_element_clipped
/* 42E238 802A9828 0200202D */   daddu    $a0, $s0, $zero
/* 42E23C 802A982C 0200202D */  daddu     $a0, $s0, $zero
/* 42E240 802A9830 27A50010 */  addiu     $a1, $sp, 0x10
/* 42E244 802A9834 0C05126B */  jal       get_hud_element_render_pos
/* 42E248 802A9838 27A60014 */   addiu    $a2, $sp, 0x14
/* 42E24C 802A983C 86220068 */  lh        $v0, 0x68($s1)
/* 42E250 802A9840 14400011 */  bnez      $v0, .L802A9888
/* 42E254 802A9844 3C0451EB */   lui      $a0, 0x51eb
/* 42E258 802A9848 96230044 */  lhu       $v1, 0x44($s1)
/* 42E25C 802A984C 3484851F */  ori       $a0, $a0, 0x851f
/* 42E260 802A9850 00031C00 */  sll       $v1, $v1, 0x10
/* 42E264 802A9854 00031403 */  sra       $v0, $v1, 0x10
/* 42E268 802A9858 00440018 */  mult      $v0, $a0
/* 42E26C 802A985C 8FA50014 */  lw        $a1, 0x14($sp)
/* 42E270 802A9860 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42E274 802A9864 8FA40010 */  lw        $a0, 0x10($sp)
/* 42E278 802A9868 00003810 */  mfhi      $a3
/* 42E27C 802A986C 00073143 */  sra       $a2, $a3, 5
/* 42E280 802A9870 00C33023 */  subu      $a2, $a2, $v1
/* 42E284 802A9874 00063400 */  sll       $a2, $a2, 0x10
/* 42E288 802A9878 0C09A1DC */  jal       func_80268770
/* 42E28C 802A987C 00063403 */   sra      $a2, $a2, 0x10
/* 42E290 802A9880 080AA630 */  j         .L802A98C0
/* 42E294 802A9884 00000000 */   nop
.L802A9888:
/* 42E298 802A9888 96230044 */  lhu       $v1, 0x44($s1)
/* 42E29C 802A988C 3484851F */  ori       $a0, $a0, 0x851f
/* 42E2A0 802A9890 00031C00 */  sll       $v1, $v1, 0x10
/* 42E2A4 802A9894 00031403 */  sra       $v0, $v1, 0x10
/* 42E2A8 802A9898 00440018 */  mult      $v0, $a0
/* 42E2AC 802A989C 8FA50014 */  lw        $a1, 0x14($sp)
/* 42E2B0 802A98A0 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42E2B4 802A98A4 8FA40010 */  lw        $a0, 0x10($sp)
/* 42E2B8 802A98A8 00003810 */  mfhi      $a3
/* 42E2BC 802A98AC 00073143 */  sra       $a2, $a3, 5
/* 42E2C0 802A98B0 00C33023 */  subu      $a2, $a2, $v1
/* 42E2C4 802A98B4 00063400 */  sll       $a2, $a2, 0x10
/* 42E2C8 802A98B8 0C09A203 */  jal       func_8026880C
/* 42E2CC 802A98BC 00063403 */   sra      $a2, $a2, 0x10
.L802A98C0:
/* 42E2D0 802A98C0 8E240014 */  lw        $a0, 0x14($s1)
/* 42E2D4 802A98C4 0C0511EA */  jal       draw_hud_element_clipped
/* 42E2D8 802A98C8 00000000 */   nop
/* 42E2DC 802A98CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42E2E0 802A98D0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 42E2E4 802A98D4 8FB00018 */  lw        $s0, 0x18($sp)
/* 42E2E8 802A98D8 03E00008 */  jr        $ra
/* 42E2EC 802A98DC 27BD0028 */   addiu    $sp, $sp, 0x28
