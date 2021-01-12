.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB7E0_E30130
/* E30130 802BB7E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E30134 802BB7E4 AFBF0018 */  sw        $ra, 0x18($sp)
/* E30138 802BB7E8 AFB10014 */  sw        $s1, 0x14($sp)
/* E3013C 802BB7EC AFB00010 */  sw        $s0, 0x10($sp)
/* E30140 802BB7F0 8C900040 */  lw        $s0, 0x40($a0)
/* E30144 802BB7F4 861100AA */  lh        $s1, 0xaa($s0)
/* E30148 802BB7F8 8E0400A0 */  lw        $a0, 0xa0($s0)
/* E3014C 802BB7FC 1620001A */  bnez      $s1, .L802BB868
/* E30150 802BB800 2402FFFF */   addiu    $v0, $zero, -1
/* E30154 802BB804 8C830000 */  lw        $v1, ($a0)
/* E30158 802BB808 10620006 */  beq       $v1, $v0, .L802BB824
/* E3015C 802BB80C 0000282D */   daddu    $a1, $zero, $zero
/* E30160 802BB810 0040182D */  daddu     $v1, $v0, $zero
.L802BB814:
/* E30164 802BB814 24840004 */  addiu     $a0, $a0, 4
/* E30168 802BB818 8C820000 */  lw        $v0, ($a0)
/* E3016C 802BB81C 1443FFFD */  bne       $v0, $v1, .L802BB814
/* E30170 802BB820 24A50001 */   addiu    $a1, $a1, 1
.L802BB824:
/* E30174 802BB824 00052080 */  sll       $a0, $a1, 2
/* E30178 802BB828 00852021 */  addu      $a0, $a0, $a1
/* E3017C 802BB82C 00042040 */  sll       $a0, $a0, 1
/* E30180 802BB830 0C00A67F */  jal       rand_int
/* E30184 802BB834 2484FFFF */   addiu    $a0, $a0, -1
/* E30188 802BB838 3C036666 */  lui       $v1, 0x6666
/* E3018C 802BB83C 34636667 */  ori       $v1, $v1, 0x6667
/* E30190 802BB840 00430018 */  mult      $v0, $v1
/* E30194 802BB844 000217C3 */  sra       $v0, $v0, 0x1f
/* E30198 802BB848 8E0400A0 */  lw        $a0, 0xa0($s0)
/* E3019C 802BB84C 00003010 */  mfhi      $a2
/* E301A0 802BB850 00061883 */  sra       $v1, $a2, 2
/* E301A4 802BB854 00621823 */  subu      $v1, $v1, $v0
/* E301A8 802BB858 00031880 */  sll       $v1, $v1, 2
/* E301AC 802BB85C 00641821 */  addu      $v1, $v1, $a0
/* E301B0 802BB860 8C620000 */  lw        $v0, ($v1)
/* E301B4 802BB864 AE02009C */  sw        $v0, 0x9c($s0)
.L802BB868:
/* E301B8 802BB868 8E05009C */  lw        $a1, 0x9c($s0)
/* E301BC 802BB86C 00111080 */  sll       $v0, $s1, 2
/* E301C0 802BB870 00A21821 */  addu      $v1, $a1, $v0
/* E301C4 802BB874 8C640000 */  lw        $a0, ($v1)
/* E301C8 802BB878 3C028000 */  lui       $v0, 0x8000
/* E301CC 802BB87C 10820013 */  beq       $a0, $v0, .L802BB8CC
/* E301D0 802BB880 34420001 */   ori      $v0, $v0, 1
/* E301D4 802BB884 1482000A */  bne       $a0, $v0, .L802BB8B0
/* E301D8 802BB888 26310003 */   addiu    $s1, $s1, 3
/* E301DC 802BB88C 00A0182D */  daddu     $v1, $a1, $zero
/* E301E0 802BB890 94620002 */  lhu       $v0, 2($v1)
/* E301E4 802BB894 24630004 */  addiu     $v1, $v1, 4
/* E301E8 802BB898 A60200A4 */  sh        $v0, 0xa4($s0)
/* E301EC 802BB89C 94620002 */  lhu       $v0, 2($v1)
/* E301F0 802BB8A0 A60200A6 */  sh        $v0, 0xa6($s0)
/* E301F4 802BB8A4 94620006 */  lhu       $v0, 6($v1)
/* E301F8 802BB8A8 080AEE32 */  j         .L802BB8C8
/* E301FC 802BB8AC 0000882D */   daddu    $s1, $zero, $zero
.L802BB8B0:
/* E30200 802BB8B0 94620002 */  lhu       $v0, 2($v1)
/* E30204 802BB8B4 24630004 */  addiu     $v1, $v1, 4
/* E30208 802BB8B8 A60200A4 */  sh        $v0, 0xa4($s0)
/* E3020C 802BB8BC 94620002 */  lhu       $v0, 2($v1)
/* E30210 802BB8C0 A60200A6 */  sh        $v0, 0xa6($s0)
/* E30214 802BB8C4 94620006 */  lhu       $v0, 6($v1)
.L802BB8C8:
/* E30218 802BB8C8 A60200A8 */  sh        $v0, 0xa8($s0)
.L802BB8CC:
/* E3021C 802BB8CC A61100AA */  sh        $s1, 0xaa($s0)
/* E30220 802BB8D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* E30224 802BB8D4 8FB10014 */  lw        $s1, 0x14($sp)
/* E30228 802BB8D8 8FB00010 */  lw        $s0, 0x10($sp)
/* E3022C 802BB8DC 03E00008 */  jr        $ra
/* E30230 802BB8E0 27BD0020 */   addiu    $sp, $sp, 0x20
