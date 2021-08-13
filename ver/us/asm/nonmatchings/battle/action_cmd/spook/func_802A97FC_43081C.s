.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A97FC_43081C
/* 43081C 802A97FC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 430820 802A9800 AFB1001C */  sw        $s1, 0x1c($sp)
/* 430824 802A9804 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 430828 802A9808 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 43082C 802A980C AFBF0020 */  sw        $ra, 0x20($sp)
/* 430830 802A9810 AFB00018 */  sw        $s0, 0x18($sp)
/* 430834 802A9814 0C0511EA */  jal       draw_hud_element_clipped
/* 430838 802A9818 8E240004 */   lw       $a0, 4($s1)
/* 43083C 802A981C 8E300008 */  lw        $s0, 8($s1)
/* 430840 802A9820 0C0511EA */  jal       draw_hud_element_clipped
/* 430844 802A9824 0200202D */   daddu    $a0, $s0, $zero
/* 430848 802A9828 0200202D */  daddu     $a0, $s0, $zero
/* 43084C 802A982C 27A50010 */  addiu     $a1, $sp, 0x10
/* 430850 802A9830 0C05126B */  jal       get_hud_element_render_pos
/* 430854 802A9834 27A60014 */   addiu    $a2, $sp, 0x14
/* 430858 802A9838 86220068 */  lh        $v0, 0x68($s1)
/* 43085C 802A983C 14400011 */  bnez      $v0, .L802A9884
/* 430860 802A9840 3C0451EB */   lui      $a0, 0x51eb
/* 430864 802A9844 96230044 */  lhu       $v1, 0x44($s1)
/* 430868 802A9848 3484851F */  ori       $a0, $a0, 0x851f
/* 43086C 802A984C 00031C00 */  sll       $v1, $v1, 0x10
/* 430870 802A9850 00031403 */  sra       $v0, $v1, 0x10
/* 430874 802A9854 00440018 */  mult      $v0, $a0
/* 430878 802A9858 8FA50014 */  lw        $a1, 0x14($sp)
/* 43087C 802A985C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 430880 802A9860 8FA40010 */  lw        $a0, 0x10($sp)
/* 430884 802A9864 00003810 */  mfhi      $a3
/* 430888 802A9868 00073143 */  sra       $a2, $a3, 5
/* 43088C 802A986C 00C33023 */  subu      $a2, $a2, $v1
/* 430890 802A9870 00063400 */  sll       $a2, $a2, 0x10
/* 430894 802A9874 0C09A1DC */  jal       func_80268770
/* 430898 802A9878 00063403 */   sra      $a2, $a2, 0x10
/* 43089C 802A987C 080AA62F */  j         .L802A98BC
/* 4308A0 802A9880 00000000 */   nop
.L802A9884:
/* 4308A4 802A9884 96230044 */  lhu       $v1, 0x44($s1)
/* 4308A8 802A9888 3484851F */  ori       $a0, $a0, 0x851f
/* 4308AC 802A988C 00031C00 */  sll       $v1, $v1, 0x10
/* 4308B0 802A9890 00031403 */  sra       $v0, $v1, 0x10
/* 4308B4 802A9894 00440018 */  mult      $v0, $a0
/* 4308B8 802A9898 8FA50014 */  lw        $a1, 0x14($sp)
/* 4308BC 802A989C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 4308C0 802A98A0 8FA40010 */  lw        $a0, 0x10($sp)
/* 4308C4 802A98A4 00003810 */  mfhi      $a3
/* 4308C8 802A98A8 00073143 */  sra       $a2, $a3, 5
/* 4308CC 802A98AC 00C33023 */  subu      $a2, $a2, $v1
/* 4308D0 802A98B0 00063400 */  sll       $a2, $a2, 0x10
/* 4308D4 802A98B4 0C09A203 */  jal       func_8026880C
/* 4308D8 802A98B8 00063403 */   sra      $a2, $a2, 0x10
.L802A98BC:
/* 4308DC 802A98BC 8E24000C */  lw        $a0, 0xc($s1)
/* 4308E0 802A98C0 0C0511EA */  jal       draw_hud_element_clipped
/* 4308E4 802A98C4 00000000 */   nop
/* 4308E8 802A98C8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4308EC 802A98CC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 4308F0 802A98D0 8FB00018 */  lw        $s0, 0x18($sp)
/* 4308F4 802A98D4 03E00008 */  jr        $ra
/* 4308F8 802A98D8 27BD0028 */   addiu    $sp, $sp, 0x28
