.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A96EC_42815C
/* 42815C 802A96EC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 428160 802A96F0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 428164 802A96F4 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 428168 802A96F8 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42816C 802A96FC AFBF0020 */  sw        $ra, 0x20($sp)
/* 428170 802A9700 AFB00018 */  sw        $s0, 0x18($sp)
/* 428174 802A9704 0C0511EA */  jal       draw_hud_element_clipped
/* 428178 802A9708 8E240004 */   lw       $a0, 4($s1)
/* 42817C 802A970C 8E300008 */  lw        $s0, 8($s1)
/* 428180 802A9710 0C0511EA */  jal       draw_hud_element_clipped
/* 428184 802A9714 0200202D */   daddu    $a0, $s0, $zero
/* 428188 802A9718 0200202D */  daddu     $a0, $s0, $zero
/* 42818C 802A971C 27A50010 */  addiu     $a1, $sp, 0x10
/* 428190 802A9720 0C05126B */  jal       get_hud_element_render_pos
/* 428194 802A9724 27A60014 */   addiu    $a2, $sp, 0x14
/* 428198 802A9728 86220068 */  lh        $v0, 0x68($s1)
/* 42819C 802A972C 14400011 */  bnez      $v0, .L802A9774
/* 4281A0 802A9730 3C0451EB */   lui      $a0, 0x51eb
/* 4281A4 802A9734 96230044 */  lhu       $v1, 0x44($s1)
/* 4281A8 802A9738 3484851F */  ori       $a0, $a0, 0x851f
/* 4281AC 802A973C 00031C00 */  sll       $v1, $v1, 0x10
/* 4281B0 802A9740 00031403 */  sra       $v0, $v1, 0x10
/* 4281B4 802A9744 00440018 */  mult      $v0, $a0
/* 4281B8 802A9748 8FA50014 */  lw        $a1, 0x14($sp)
/* 4281BC 802A974C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 4281C0 802A9750 8FA40010 */  lw        $a0, 0x10($sp)
/* 4281C4 802A9754 00003810 */  mfhi      $a3
/* 4281C8 802A9758 00073143 */  sra       $a2, $a3, 5
/* 4281CC 802A975C 00C33023 */  subu      $a2, $a2, $v1
/* 4281D0 802A9760 00063400 */  sll       $a2, $a2, 0x10
/* 4281D4 802A9764 0C09A1DC */  jal       func_80268770
/* 4281D8 802A9768 00063403 */   sra      $a2, $a2, 0x10
/* 4281DC 802A976C 080AA5EB */  j         .L802A97AC
/* 4281E0 802A9770 00000000 */   nop
.L802A9774:
/* 4281E4 802A9774 96230044 */  lhu       $v1, 0x44($s1)
/* 4281E8 802A9778 3484851F */  ori       $a0, $a0, 0x851f
/* 4281EC 802A977C 00031C00 */  sll       $v1, $v1, 0x10
/* 4281F0 802A9780 00031403 */  sra       $v0, $v1, 0x10
/* 4281F4 802A9784 00440018 */  mult      $v0, $a0
/* 4281F8 802A9788 8FA50014 */  lw        $a1, 0x14($sp)
/* 4281FC 802A978C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 428200 802A9790 8FA40010 */  lw        $a0, 0x10($sp)
/* 428204 802A9794 00003810 */  mfhi      $a3
/* 428208 802A9798 00073143 */  sra       $a2, $a3, 5
/* 42820C 802A979C 00C33023 */  subu      $a2, $a2, $v1
/* 428210 802A97A0 00063400 */  sll       $a2, $a2, 0x10
/* 428214 802A97A4 0C09A203 */  jal       func_8026880C
/* 428218 802A97A8 00063403 */   sra      $a2, $a2, 0x10
.L802A97AC:
/* 42821C 802A97AC 8E24000C */  lw        $a0, 0xc($s1)
/* 428220 802A97B0 0C0511EA */  jal       draw_hud_element_clipped
/* 428224 802A97B4 00000000 */   nop
/* 428228 802A97B8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42822C 802A97BC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 428230 802A97C0 8FB00018 */  lw        $s0, 0x18($sp)
/* 428234 802A97C4 03E00008 */  jr        $ra
/* 428238 802A97C8 27BD0028 */   addiu    $sp, $sp, 0x28
