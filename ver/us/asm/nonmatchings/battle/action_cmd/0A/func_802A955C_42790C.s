.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A955C_42790C
/* 42790C 802A955C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 427910 802A9560 AFB1001C */  sw        $s1, 0x1c($sp)
/* 427914 802A9564 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 427918 802A9568 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 42791C 802A956C AFBF0020 */  sw        $ra, 0x20($sp)
/* 427920 802A9570 AFB00018 */  sw        $s0, 0x18($sp)
/* 427924 802A9574 0C0511EA */  jal       draw_hud_element_clipped
/* 427928 802A9578 8E240004 */   lw       $a0, 4($s1)
/* 42792C 802A957C 8E300008 */  lw        $s0, 8($s1)
/* 427930 802A9580 0C0511EA */  jal       draw_hud_element_clipped
/* 427934 802A9584 0200202D */   daddu    $a0, $s0, $zero
/* 427938 802A9588 0200202D */  daddu     $a0, $s0, $zero
/* 42793C 802A958C 27A50010 */  addiu     $a1, $sp, 0x10
/* 427940 802A9590 0C05126B */  jal       get_hud_element_render_pos
/* 427944 802A9594 27A60014 */   addiu    $a2, $sp, 0x14
/* 427948 802A9598 86220068 */  lh        $v0, 0x68($s1)
/* 42794C 802A959C 14400011 */  bnez      $v0, .L802A95E4
/* 427950 802A95A0 3C0451EB */   lui      $a0, 0x51eb
/* 427954 802A95A4 96230044 */  lhu       $v1, 0x44($s1)
/* 427958 802A95A8 3484851F */  ori       $a0, $a0, 0x851f
/* 42795C 802A95AC 00031C00 */  sll       $v1, $v1, 0x10
/* 427960 802A95B0 00031403 */  sra       $v0, $v1, 0x10
/* 427964 802A95B4 00440018 */  mult      $v0, $a0
/* 427968 802A95B8 8FA50014 */  lw        $a1, 0x14($sp)
/* 42796C 802A95BC 00031FC3 */  sra       $v1, $v1, 0x1f
/* 427970 802A95C0 8FA40010 */  lw        $a0, 0x10($sp)
/* 427974 802A95C4 00003810 */  mfhi      $a3
/* 427978 802A95C8 00073143 */  sra       $a2, $a3, 5
/* 42797C 802A95CC 00C33023 */  subu      $a2, $a2, $v1
/* 427980 802A95D0 00063400 */  sll       $a2, $a2, 0x10
/* 427984 802A95D4 0C09A1DC */  jal       func_80268770
/* 427988 802A95D8 00063403 */   sra      $a2, $a2, 0x10
/* 42798C 802A95DC 080AA587 */  j         .L802A961C
/* 427990 802A95E0 00000000 */   nop
.L802A95E4:
/* 427994 802A95E4 96230044 */  lhu       $v1, 0x44($s1)
/* 427998 802A95E8 3484851F */  ori       $a0, $a0, 0x851f
/* 42799C 802A95EC 00031C00 */  sll       $v1, $v1, 0x10
/* 4279A0 802A95F0 00031403 */  sra       $v0, $v1, 0x10
/* 4279A4 802A95F4 00440018 */  mult      $v0, $a0
/* 4279A8 802A95F8 8FA50014 */  lw        $a1, 0x14($sp)
/* 4279AC 802A95FC 00031FC3 */  sra       $v1, $v1, 0x1f
/* 4279B0 802A9600 8FA40010 */  lw        $a0, 0x10($sp)
/* 4279B4 802A9604 00003810 */  mfhi      $a3
/* 4279B8 802A9608 00073143 */  sra       $a2, $a3, 5
/* 4279BC 802A960C 00C33023 */  subu      $a2, $a2, $v1
/* 4279C0 802A9610 00063400 */  sll       $a2, $a2, 0x10
/* 4279C4 802A9614 0C09A203 */  jal       func_8026880C
/* 4279C8 802A9618 00063403 */   sra      $a2, $a2, 0x10
.L802A961C:
/* 4279CC 802A961C 8E24000C */  lw        $a0, 0xc($s1)
/* 4279D0 802A9620 0C0511EA */  jal       draw_hud_element_clipped
/* 4279D4 802A9624 00000000 */   nop
/* 4279D8 802A9628 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4279DC 802A962C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 4279E0 802A9630 8FB00018 */  lw        $s0, 0x18($sp)
/* 4279E4 802A9634 03E00008 */  jr        $ra
/* 4279E8 802A9638 27BD0028 */   addiu    $sp, $sp, 0x28
