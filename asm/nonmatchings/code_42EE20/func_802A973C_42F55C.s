.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A973C_42F55C
/* 42F55C 802A973C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42F560 802A9740 AFB1001C */  sw        $s1, 0x1c($sp)
/* 42F564 802A9744 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42F568 802A9748 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42F56C 802A974C AFBF0020 */  sw        $ra, 0x20($sp)
/* 42F570 802A9750 AFB00018 */  sw        $s0, 0x18($sp)
/* 42F574 802A9754 0C0511EA */  jal       draw_icon_0
/* 42F578 802A9758 8E240004 */   lw       $a0, 4($s1)
/* 42F57C 802A975C 8E300008 */  lw        $s0, 8($s1)
/* 42F580 802A9760 0C0511EA */  jal       draw_icon_0
/* 42F584 802A9764 0200202D */   daddu    $a0, $s0, $zero
/* 42F588 802A9768 0200202D */  daddu     $a0, $s0, $zero
/* 42F58C 802A976C 27A50010 */  addiu     $a1, $sp, 0x10
/* 42F590 802A9770 0C05126B */  jal       get_icon_render_pos
/* 42F594 802A9774 27A60014 */   addiu    $a2, $sp, 0x14
/* 42F598 802A9778 86220068 */  lh        $v0, 0x68($s1)
/* 42F59C 802A977C 14400011 */  bnez      $v0, .L802A97C4
/* 42F5A0 802A9780 3C0451EB */   lui      $a0, 0x51eb
/* 42F5A4 802A9784 96230044 */  lhu       $v1, 0x44($s1)
/* 42F5A8 802A9788 3484851F */  ori       $a0, $a0, 0x851f
/* 42F5AC 802A978C 00031C00 */  sll       $v1, $v1, 0x10
/* 42F5B0 802A9790 00031403 */  sra       $v0, $v1, 0x10
/* 42F5B4 802A9794 00440018 */  mult      $v0, $a0
/* 42F5B8 802A9798 8FA50014 */  lw        $a1, 0x14($sp)
/* 42F5BC 802A979C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42F5C0 802A97A0 8FA40010 */  lw        $a0, 0x10($sp)
/* 42F5C4 802A97A4 00003810 */  mfhi      $a3
/* 42F5C8 802A97A8 00073143 */  sra       $a2, $a3, 5
/* 42F5CC 802A97AC 00C33023 */  subu      $a2, $a2, $v1
/* 42F5D0 802A97B0 00063400 */  sll       $a2, $a2, 0x10
/* 42F5D4 802A97B4 0C09A1DC */  jal       func_80268770
/* 42F5D8 802A97B8 00063403 */   sra      $a2, $a2, 0x10
/* 42F5DC 802A97BC 080AA5FF */  j         .L802A97FC
/* 42F5E0 802A97C0 00000000 */   nop      
.L802A97C4:
/* 42F5E4 802A97C4 96230044 */  lhu       $v1, 0x44($s1)
/* 42F5E8 802A97C8 3484851F */  ori       $a0, $a0, 0x851f
/* 42F5EC 802A97CC 00031C00 */  sll       $v1, $v1, 0x10
/* 42F5F0 802A97D0 00031403 */  sra       $v0, $v1, 0x10
/* 42F5F4 802A97D4 00440018 */  mult      $v0, $a0
/* 42F5F8 802A97D8 8FA50014 */  lw        $a1, 0x14($sp)
/* 42F5FC 802A97DC 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42F600 802A97E0 8FA40010 */  lw        $a0, 0x10($sp)
/* 42F604 802A97E4 00003810 */  mfhi      $a3
/* 42F608 802A97E8 00073143 */  sra       $a2, $a3, 5
/* 42F60C 802A97EC 00C33023 */  subu      $a2, $a2, $v1
/* 42F610 802A97F0 00063400 */  sll       $a2, $a2, 0x10
/* 42F614 802A97F4 0C09A203 */  jal       func_8026880C
/* 42F618 802A97F8 00063403 */   sra      $a2, $a2, 0x10
.L802A97FC:
/* 42F61C 802A97FC 8E24000C */  lw        $a0, 0xc($s1)
/* 42F620 802A9800 0C0511EA */  jal       draw_icon_0
/* 42F624 802A9804 00000000 */   nop      
/* 42F628 802A9808 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42F62C 802A980C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 42F630 802A9810 8FB00018 */  lw        $s0, 0x18($sp)
/* 42F634 802A9814 03E00008 */  jr        $ra
/* 42F638 802A9818 27BD0028 */   addiu    $sp, $sp, 0x28
