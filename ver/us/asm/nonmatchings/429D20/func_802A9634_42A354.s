.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9634_42A354
/* 42A354 802A9634 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 42A358 802A9638 AFB10024 */  sw        $s1, 0x24($sp)
/* 42A35C 802A963C 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42A360 802A9640 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42A364 802A9644 AFBF0028 */  sw        $ra, 0x28($sp)
/* 42A368 802A9648 AFB00020 */  sw        $s0, 0x20($sp)
/* 42A36C 802A964C 0C0511EA */  jal       draw_hud_element_clipped
/* 42A370 802A9650 8E240004 */   lw       $a0, 4($s1)
/* 42A374 802A9654 8E300008 */  lw        $s0, 8($s1)
/* 42A378 802A9658 0C0511EA */  jal       draw_hud_element_clipped
/* 42A37C 802A965C 0200202D */   daddu    $a0, $s0, $zero
/* 42A380 802A9660 0200202D */  daddu     $a0, $s0, $zero
/* 42A384 802A9664 27A50018 */  addiu     $a1, $sp, 0x18
/* 42A388 802A9668 0C05126B */  jal       get_hud_element_render_pos
/* 42A38C 802A966C 27A6001C */   addiu    $a2, $sp, 0x1c
/* 42A390 802A9670 8222005C */  lb        $v0, 0x5c($s1)
/* 42A394 802A9674 14400013 */  bnez      $v0, .L802A96C4
/* 42A398 802A9678 0220802D */   daddu    $s0, $s1, $zero
/* 42A39C 802A967C 3C0451EB */  lui       $a0, 0x51eb
/* 42A3A0 802A9680 96230044 */  lhu       $v1, 0x44($s1)
/* 42A3A4 802A9684 3484851F */  ori       $a0, $a0, 0x851f
/* 42A3A8 802A9688 00031C00 */  sll       $v1, $v1, 0x10
/* 42A3AC 802A968C 00031403 */  sra       $v0, $v1, 0x10
/* 42A3B0 802A9690 00440018 */  mult      $v0, $a0
/* 42A3B4 802A9694 24070001 */  addiu     $a3, $zero, 1
/* 42A3B8 802A9698 8FA5001C */  lw        $a1, 0x1c($sp)
/* 42A3BC 802A969C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42A3C0 802A96A0 8FA40018 */  lw        $a0, 0x18($sp)
/* 42A3C4 802A96A4 00004010 */  mfhi      $t0
/* 42A3C8 802A96A8 00083143 */  sra       $a2, $t0, 5
/* 42A3CC 802A96AC 00C33023 */  subu      $a2, $a2, $v1
/* 42A3D0 802A96B0 00063400 */  sll       $a2, $a2, 0x10
/* 42A3D4 802A96B4 0C09A1E6 */  jal       func_80268798
/* 42A3D8 802A96B8 00063403 */   sra      $a2, $a2, 0x10
/* 42A3DC 802A96BC 080AA5C3 */  j         .L802A970C
/* 42A3E0 802A96C0 00000000 */   nop
.L802A96C4:
/* 42A3E4 802A96C4 3C0451EB */  lui       $a0, 0x51eb
/* 42A3E8 802A96C8 3484851F */  ori       $a0, $a0, 0x851f
/* 42A3EC 802A96CC 24070001 */  addiu     $a3, $zero, 1
/* 42A3F0 802A96D0 96030044 */  lhu       $v1, 0x44($s0)
/* 42A3F4 802A96D4 8FA5001C */  lw        $a1, 0x1c($sp)
/* 42A3F8 802A96D8 00031C00 */  sll       $v1, $v1, 0x10
/* 42A3FC 802A96DC 00031403 */  sra       $v0, $v1, 0x10
/* 42A400 802A96E0 00440018 */  mult      $v0, $a0
/* 42A404 802A96E4 00E0102D */  daddu     $v0, $a3, $zero
/* 42A408 802A96E8 8FA40018 */  lw        $a0, 0x18($sp)
/* 42A40C 802A96EC 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42A410 802A96F0 AFA20010 */  sw        $v0, 0x10($sp)
/* 42A414 802A96F4 00004010 */  mfhi      $t0
/* 42A418 802A96F8 00083143 */  sra       $a2, $t0, 5
/* 42A41C 802A96FC 00C33023 */  subu      $a2, $a2, $v1
/* 42A420 802A9700 00063400 */  sll       $a2, $a2, 0x10
/* 42A424 802A9704 0C09A1F9 */  jal       func_802687E4
/* 42A428 802A9708 00063403 */   sra      $a2, $a2, 0x10
.L802A970C:
/* 42A42C 802A970C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 42A430 802A9710 8FB10024 */  lw        $s1, 0x24($sp)
/* 42A434 802A9714 8FB00020 */  lw        $s0, 0x20($sp)
/* 42A438 802A9718 03E00008 */  jr        $ra
/* 42A43C 802A971C 27BD0030 */   addiu    $sp, $sp, 0x30
