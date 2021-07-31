.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A96B8_423AA8
/* 423AA8 802A96B8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 423AAC 802A96BC AFB00018 */  sw        $s0, 0x18($sp)
/* 423AB0 802A96C0 3C10802A */  lui       $s0, %hi(D_8029FBE0)
/* 423AB4 802A96C4 2610FBE0 */  addiu     $s0, $s0, %lo(D_8029FBE0)
/* 423AB8 802A96C8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 423ABC 802A96CC AFB1001C */  sw        $s1, 0x1c($sp)
/* 423AC0 802A96D0 82020080 */  lb        $v0, 0x80($s0)
/* 423AC4 802A96D4 86030046 */  lh        $v1, 0x46($s0)
/* 423AC8 802A96D8 00021040 */  sll       $v0, $v0, 1
/* 423ACC 802A96DC 00501021 */  addu      $v0, $v0, $s0
/* 423AD0 802A96E0 84440074 */  lh        $a0, 0x74($v0)
/* 423AD4 802A96E4 00831823 */  subu      $v1, $a0, $v1
/* 423AD8 802A96E8 00031100 */  sll       $v0, $v1, 4
/* 423ADC 802A96EC 00431023 */  subu      $v0, $v0, $v1
/* 423AE0 802A96F0 00021080 */  sll       $v0, $v0, 2
/* 423AE4 802A96F4 14800002 */  bnez      $a0, .L802A9700
/* 423AE8 802A96F8 0044001A */   div      $zero, $v0, $a0
/* 423AEC 802A96FC 0007000D */  break     7
.L802A9700:
/* 423AF0 802A9700 2401FFFF */   addiu    $at, $zero, -1
/* 423AF4 802A9704 14810004 */  bne       $a0, $at, .L802A9718
/* 423AF8 802A9708 3C018000 */   lui      $at, 0x8000
/* 423AFC 802A970C 14410002 */  bne       $v0, $at, .L802A9718
/* 423B00 802A9710 00000000 */   nop
/* 423B04 802A9714 0006000D */  break     6
.L802A9718:
/* 423B08 802A9718 00001012 */   mflo     $v0
/* 423B0C 802A971C 86060058 */  lh        $a2, 0x58($s0)
/* 423B10 802A9720 24C60011 */  addiu     $a2, $a2, 0x11
/* 423B14 802A9724 2403003C */  addiu     $v1, $zero, 0x3c
/* 423B18 802A9728 8E040010 */  lw        $a0, 0x10($s0)
/* 423B1C 802A972C 00621823 */  subu      $v1, $v1, $v0
/* 423B20 802A9730 86020056 */  lh        $v0, 0x56($s0)
/* 423B24 802A9734 2465FFE1 */  addiu     $a1, $v1, -0x1f
/* 423B28 802A9738 AFA30010 */  sw        $v1, 0x10($sp)
/* 423B2C 802A973C 0C051261 */  jal       set_hud_element_render_pos
/* 423B30 802A9740 00452823 */   subu     $a1, $v0, $a1
/* 423B34 802A9744 8FA50010 */  lw        $a1, 0x10($sp)
/* 423B38 802A9748 8E04000C */  lw        $a0, 0xc($s0)
/* 423B3C 802A974C 86020056 */  lh        $v0, 0x56($s0)
/* 423B40 802A9750 86060058 */  lh        $a2, 0x58($s0)
/* 423B44 802A9754 24A5FFE1 */  addiu     $a1, $a1, -0x1f
/* 423B48 802A9758 00452823 */  subu      $a1, $v0, $a1
/* 423B4C 802A975C 0C051261 */  jal       set_hud_element_render_pos
/* 423B50 802A9760 24C6FFFF */   addiu    $a2, $a2, -1
/* 423B54 802A9764 8602006A */  lh        $v0, 0x6a($s0)
/* 423B58 802A9768 14400004 */  bnez      $v0, .L802A977C
/* 423B5C 802A976C 0200882D */   daddu    $s1, $s0, $zero
/* 423B60 802A9770 8E040004 */  lw        $a0, 4($s0)
/* 423B64 802A9774 0C0511EA */  jal       draw_hud_element_clipped
/* 423B68 802A9778 00000000 */   nop
.L802A977C:
/* 423B6C 802A977C 8E300008 */  lw        $s0, 8($s1)
/* 423B70 802A9780 0C0511EA */  jal       draw_hud_element_clipped
/* 423B74 802A9784 0200202D */   daddu    $a0, $s0, $zero
/* 423B78 802A9788 0200202D */  daddu     $a0, $s0, $zero
/* 423B7C 802A978C 27A50010 */  addiu     $a1, $sp, 0x10
/* 423B80 802A9790 0C05126B */  jal       get_hud_element_render_pos
/* 423B84 802A9794 27A60014 */   addiu    $a2, $sp, 0x14
/* 423B88 802A9798 3C0451EB */  lui       $a0, 0x51eb
/* 423B8C 802A979C 96230044 */  lhu       $v1, 0x44($s1)
/* 423B90 802A97A0 3484851F */  ori       $a0, $a0, 0x851f
/* 423B94 802A97A4 00031C00 */  sll       $v1, $v1, 0x10
/* 423B98 802A97A8 00031403 */  sra       $v0, $v1, 0x10
/* 423B9C 802A97AC 00440018 */  mult      $v0, $a0
/* 423BA0 802A97B0 8FA50014 */  lw        $a1, 0x14($sp)
/* 423BA4 802A97B4 00031FC3 */  sra       $v1, $v1, 0x1f
/* 423BA8 802A97B8 8FA40010 */  lw        $a0, 0x10($sp)
/* 423BAC 802A97BC 00003810 */  mfhi      $a3
/* 423BB0 802A97C0 00073143 */  sra       $a2, $a3, 5
/* 423BB4 802A97C4 00C33023 */  subu      $a2, $a2, $v1
/* 423BB8 802A97C8 00063400 */  sll       $a2, $a2, 0x10
/* 423BBC 802A97CC 0C09A1DC */  jal       func_80268770
/* 423BC0 802A97D0 00063403 */   sra      $a2, $a2, 0x10
/* 423BC4 802A97D4 8E24000C */  lw        $a0, 0xc($s1)
/* 423BC8 802A97D8 0C0511EA */  jal       draw_hud_element_clipped
/* 423BCC 802A97DC 00000000 */   nop
/* 423BD0 802A97E0 0C0511EA */  jal       draw_hud_element_clipped
/* 423BD4 802A97E4 8E240010 */   lw       $a0, 0x10($s1)
/* 423BD8 802A97E8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 423BDC 802A97EC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 423BE0 802A97F0 8FB00018 */  lw        $s0, 0x18($sp)
/* 423BE4 802A97F4 03E00008 */  jr        $ra
/* 423BE8 802A97F8 27BD0028 */   addiu    $sp, $sp, 0x28
