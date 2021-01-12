.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A984C_429B6C
/* 429B6C 802A984C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 429B70 802A9850 AFB1001C */  sw        $s1, 0x1c($sp)
/* 429B74 802A9854 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 429B78 802A9858 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 429B7C 802A985C AFBF0020 */  sw        $ra, 0x20($sp)
/* 429B80 802A9860 AFB00018 */  sw        $s0, 0x18($sp)
/* 429B84 802A9864 0C0511EA */  jal       draw_icon_0
/* 429B88 802A9868 8E240004 */   lw       $a0, 4($s1)
/* 429B8C 802A986C 8E300008 */  lw        $s0, 8($s1)
/* 429B90 802A9870 0C0511EA */  jal       draw_icon_0
/* 429B94 802A9874 0200202D */   daddu    $a0, $s0, $zero
/* 429B98 802A9878 0200202D */  daddu     $a0, $s0, $zero
/* 429B9C 802A987C 27A50010 */  addiu     $a1, $sp, 0x10
/* 429BA0 802A9880 0C05126B */  jal       get_icon_render_pos
/* 429BA4 802A9884 27A60014 */   addiu    $a2, $sp, 0x14
/* 429BA8 802A9888 86220068 */  lh        $v0, 0x68($s1)
/* 429BAC 802A988C 14400011 */  bnez      $v0, .L802A98D4
/* 429BB0 802A9890 3C0451EB */   lui      $a0, 0x51eb
/* 429BB4 802A9894 96230044 */  lhu       $v1, 0x44($s1)
/* 429BB8 802A9898 3484851F */  ori       $a0, $a0, 0x851f
/* 429BBC 802A989C 00031C00 */  sll       $v1, $v1, 0x10
/* 429BC0 802A98A0 00031403 */  sra       $v0, $v1, 0x10
/* 429BC4 802A98A4 00440018 */  mult      $v0, $a0
/* 429BC8 802A98A8 8FA50014 */  lw        $a1, 0x14($sp)
/* 429BCC 802A98AC 00031FC3 */  sra       $v1, $v1, 0x1f
/* 429BD0 802A98B0 8FA40010 */  lw        $a0, 0x10($sp)
/* 429BD4 802A98B4 00003810 */  mfhi      $a3
/* 429BD8 802A98B8 00073143 */  sra       $a2, $a3, 5
/* 429BDC 802A98BC 00C33023 */  subu      $a2, $a2, $v1
/* 429BE0 802A98C0 00063400 */  sll       $a2, $a2, 0x10
/* 429BE4 802A98C4 0C09A1DC */  jal       func_80268770
/* 429BE8 802A98C8 00063403 */   sra      $a2, $a2, 0x10
/* 429BEC 802A98CC 080AA643 */  j         .L802A990C
/* 429BF0 802A98D0 00000000 */   nop
.L802A98D4:
/* 429BF4 802A98D4 96230044 */  lhu       $v1, 0x44($s1)
/* 429BF8 802A98D8 3484851F */  ori       $a0, $a0, 0x851f
/* 429BFC 802A98DC 00031C00 */  sll       $v1, $v1, 0x10
/* 429C00 802A98E0 00031403 */  sra       $v0, $v1, 0x10
/* 429C04 802A98E4 00440018 */  mult      $v0, $a0
/* 429C08 802A98E8 8FA50014 */  lw        $a1, 0x14($sp)
/* 429C0C 802A98EC 00031FC3 */  sra       $v1, $v1, 0x1f
/* 429C10 802A98F0 8FA40010 */  lw        $a0, 0x10($sp)
/* 429C14 802A98F4 00003810 */  mfhi      $a3
/* 429C18 802A98F8 00073143 */  sra       $a2, $a3, 5
/* 429C1C 802A98FC 00C33023 */  subu      $a2, $a2, $v1
/* 429C20 802A9900 00063400 */  sll       $a2, $a2, 0x10
/* 429C24 802A9904 0C09A203 */  jal       func_8026880C
/* 429C28 802A9908 00063403 */   sra      $a2, $a2, 0x10
.L802A990C:
/* 429C2C 802A990C 8E24000C */  lw        $a0, 0xc($s1)
/* 429C30 802A9910 0C0511EA */  jal       draw_icon_0
/* 429C34 802A9914 00000000 */   nop
/* 429C38 802A9918 8FBF0020 */  lw        $ra, 0x20($sp)
/* 429C3C 802A991C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 429C40 802A9920 8FB00018 */  lw        $s0, 0x18($sp)
/* 429C44 802A9924 03E00008 */  jr        $ra
/* 429C48 802A9928 27BD0028 */   addiu    $sp, $sp, 0x28
