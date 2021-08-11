.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A98D0_42D7E0
/* 42D7E0 802A98D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 42D7E4 802A98D4 AFB40028 */  sw        $s4, 0x28($sp)
/* 42D7E8 802A98D8 3C1451EB */  lui       $s4, 0x51eb
/* 42D7EC 802A98DC AFB30024 */  sw        $s3, 0x24($sp)
/* 42D7F0 802A98E0 3C13802A */  lui       $s3, %hi(gActionCommandStatus)
/* 42D7F4 802A98E4 2673FBE0 */  addiu     $s3, $s3, %lo(gActionCommandStatus)
/* 42D7F8 802A98E8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 42D7FC 802A98EC AFB20020 */  sw        $s2, 0x20($sp)
/* 42D800 802A98F0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 42D804 802A98F4 AFB00018 */  sw        $s0, 0x18($sp)
/* 42D808 802A98F8 86630046 */  lh        $v1, 0x46($s3)
/* 42D80C 802A98FC 3694851F */  ori       $s4, $s4, 0x851f
/* 42D810 802A9900 00031100 */  sll       $v0, $v1, 4
/* 42D814 802A9904 00431023 */  subu      $v0, $v0, $v1
/* 42D818 802A9908 00021080 */  sll       $v0, $v0, 2
/* 42D81C 802A990C 00540018 */  mult      $v0, $s4
/* 42D820 802A9910 86660058 */  lh        $a2, 0x58($s3)
/* 42D824 802A9914 8E640014 */  lw        $a0, 0x14($s3)
/* 42D828 802A9918 24C60011 */  addiu     $a2, $a2, 0x11
/* 42D82C 802A991C 000217C3 */  sra       $v0, $v0, 0x1f
/* 42D830 802A9920 00004010 */  mfhi      $t0
/* 42D834 802A9924 00081943 */  sra       $v1, $t0, 5
/* 42D838 802A9928 00621823 */  subu      $v1, $v1, $v0
/* 42D83C 802A992C 2402003C */  addiu     $v0, $zero, 0x3c
/* 42D840 802A9930 00431023 */  subu      $v0, $v0, $v1
/* 42D844 802A9934 86630056 */  lh        $v1, 0x56($s3)
/* 42D848 802A9938 2445FFE1 */  addiu     $a1, $v0, -0x1f
/* 42D84C 802A993C AFA20010 */  sw        $v0, 0x10($sp)
/* 42D850 802A9940 0C051261 */  jal       set_hud_element_render_pos
/* 42D854 802A9944 00652823 */   subu     $a1, $v1, $a1
/* 42D858 802A9948 8E640004 */  lw        $a0, 4($s3)
/* 42D85C 802A994C 0C0511EA */  jal       draw_hud_element_clipped
/* 42D860 802A9950 00000000 */   nop
/* 42D864 802A9954 8E720008 */  lw        $s2, 8($s3)
/* 42D868 802A9958 0C0511EA */  jal       draw_hud_element_clipped
/* 42D86C 802A995C 0240202D */   daddu    $a0, $s2, $zero
/* 42D870 802A9960 0240202D */  daddu     $a0, $s2, $zero
/* 42D874 802A9964 27B10010 */  addiu     $s1, $sp, 0x10
/* 42D878 802A9968 0220282D */  daddu     $a1, $s1, $zero
/* 42D87C 802A996C 27B00014 */  addiu     $s0, $sp, 0x14
/* 42D880 802A9970 0C05126B */  jal       get_hud_element_render_pos
/* 42D884 802A9974 0200302D */   daddu    $a2, $s0, $zero
/* 42D888 802A9978 0240202D */  daddu     $a0, $s2, $zero
/* 42D88C 802A997C 0220282D */  daddu     $a1, $s1, $zero
/* 42D890 802A9980 0C05126B */  jal       get_hud_element_render_pos
/* 42D894 802A9984 0200302D */   daddu    $a2, $s0, $zero
/* 42D898 802A9988 3C02802B */  lui       $v0, %hi(D_802A9B00)
/* 42D89C 802A998C 8C429B00 */  lw        $v0, %lo(D_802A9B00)($v0)
/* 42D8A0 802A9990 14400006 */  bnez      $v0, .L802A99AC
/* 42D8A4 802A9994 24070001 */   addiu    $a3, $zero, 1
/* 42D8A8 802A9998 96630044 */  lhu       $v1, 0x44($s3)
/* 42D8AC 802A999C 00031C00 */  sll       $v1, $v1, 0x10
/* 42D8B0 802A99A0 00031403 */  sra       $v0, $v1, 0x10
/* 42D8B4 802A99A4 080AA672 */  j         .L802A99C8
/* 42D8B8 802A99A8 00540018 */   mult     $v0, $s4
.L802A99AC:
/* 42D8BC 802A99AC 86620068 */  lh        $v0, 0x68($s3)
/* 42D8C0 802A99B0 14400010 */  bnez      $v0, .L802A99F4
/* 42D8C4 802A99B4 24070004 */   addiu    $a3, $zero, 4
/* 42D8C8 802A99B8 96630044 */  lhu       $v1, 0x44($s3)
/* 42D8CC 802A99BC 00031C00 */  sll       $v1, $v1, 0x10
/* 42D8D0 802A99C0 00031403 */  sra       $v0, $v1, 0x10
/* 42D8D4 802A99C4 00540018 */  mult      $v0, $s4
.L802A99C8:
/* 42D8D8 802A99C8 8FA40010 */  lw        $a0, 0x10($sp)
/* 42D8DC 802A99CC 8FA50014 */  lw        $a1, 0x14($sp)
/* 42D8E0 802A99D0 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42D8E4 802A99D4 00004010 */  mfhi      $t0
/* 42D8E8 802A99D8 00083143 */  sra       $a2, $t0, 5
/* 42D8EC 802A99DC 00C33023 */  subu      $a2, $a2, $v1
/* 42D8F0 802A99E0 00063400 */  sll       $a2, $a2, 0x10
/* 42D8F4 802A99E4 0C09A1E6 */  jal       func_80268798
/* 42D8F8 802A99E8 00063403 */   sra      $a2, $a2, 0x10
/* 42D8FC 802A99EC 080AA68A */  j         .L802A9A28
/* 42D900 802A99F0 00000000 */   nop
.L802A99F4:
/* 42D904 802A99F4 96630044 */  lhu       $v1, 0x44($s3)
/* 42D908 802A99F8 00031C00 */  sll       $v1, $v1, 0x10
/* 42D90C 802A99FC 00031403 */  sra       $v0, $v1, 0x10
/* 42D910 802A9A00 00540018 */  mult      $v0, $s4
/* 42D914 802A9A04 8FA40010 */  lw        $a0, 0x10($sp)
/* 42D918 802A9A08 8FA50014 */  lw        $a1, 0x14($sp)
/* 42D91C 802A9A0C 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42D920 802A9A10 00004010 */  mfhi      $t0
/* 42D924 802A9A14 00083143 */  sra       $a2, $t0, 5
/* 42D928 802A9A18 00C33023 */  subu      $a2, $a2, $v1
/* 42D92C 802A9A1C 00063400 */  sll       $a2, $a2, 0x10
/* 42D930 802A9A20 0C09A20D */  jal       func_80268834
/* 42D934 802A9A24 00063403 */   sra      $a2, $a2, 0x10
.L802A9A28:
/* 42D938 802A9A28 8E640010 */  lw        $a0, 0x10($s3)
/* 42D93C 802A9A2C 0C0511EA */  jal       draw_hud_element_clipped
/* 42D940 802A9A30 00000000 */   nop
/* 42D944 802A9A34 8FBF002C */  lw        $ra, 0x2c($sp)
/* 42D948 802A9A38 8FB40028 */  lw        $s4, 0x28($sp)
/* 42D94C 802A9A3C 8FB30024 */  lw        $s3, 0x24($sp)
/* 42D950 802A9A40 8FB20020 */  lw        $s2, 0x20($sp)
/* 42D954 802A9A44 8FB1001C */  lw        $s1, 0x1c($sp)
/* 42D958 802A9A48 8FB00018 */  lw        $s0, 0x18($sp)
/* 42D95C 802A9A4C 03E00008 */  jr        $ra
/* 42D960 802A9A50 27BD0030 */   addiu    $sp, $sp, 0x30
