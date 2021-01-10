.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A98B0_42EC50
/* 42EC50 802A98B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42EC54 802A98B4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 42EC58 802A98B8 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42EC5C 802A98BC 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42EC60 802A98C0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 42EC64 802A98C4 AFB00018 */  sw        $s0, 0x18($sp)
/* 42EC68 802A98C8 0C0511EA */  jal       draw_icon_0
/* 42EC6C 802A98CC 8E240004 */   lw       $a0, 4($s1)
/* 42EC70 802A98D0 8E300008 */  lw        $s0, 8($s1)
/* 42EC74 802A98D4 0C0511EA */  jal       draw_icon_0
/* 42EC78 802A98D8 0200202D */   daddu    $a0, $s0, $zero
/* 42EC7C 802A98DC 0200202D */  daddu     $a0, $s0, $zero
/* 42EC80 802A98E0 27A50010 */  addiu     $a1, $sp, 0x10
/* 42EC84 802A98E4 0C05126B */  jal       get_icon_render_pos
/* 42EC88 802A98E8 27A60014 */   addiu    $a2, $sp, 0x14
/* 42EC8C 802A98EC 86220068 */  lh        $v0, 0x68($s1)
/* 42EC90 802A98F0 14400011 */  bnez      $v0, .L802A9938
/* 42EC94 802A98F4 3C0451EB */   lui      $a0, 0x51eb
/* 42EC98 802A98F8 96230044 */  lhu       $v1, 0x44($s1)
/* 42EC9C 802A98FC 3484851F */  ori       $a0, $a0, 0x851f
/* 42ECA0 802A9900 00031C00 */  sll       $v1, $v1, 0x10
/* 42ECA4 802A9904 00031403 */  sra       $v0, $v1, 0x10
/* 42ECA8 802A9908 00440018 */  mult      $v0, $a0
/* 42ECAC 802A990C 8FA50014 */  lw        $a1, 0x14($sp)
/* 42ECB0 802A9910 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42ECB4 802A9914 8FA40010 */  lw        $a0, 0x10($sp)
/* 42ECB8 802A9918 00003810 */  mfhi      $a3
/* 42ECBC 802A991C 00073143 */  sra       $a2, $a3, 5
/* 42ECC0 802A9920 00C33023 */  subu      $a2, $a2, $v1
/* 42ECC4 802A9924 00063400 */  sll       $a2, $a2, 0x10
/* 42ECC8 802A9928 0C09A1DC */  jal       func_80268770
/* 42ECCC 802A992C 00063403 */   sra      $a2, $a2, 0x10
/* 42ECD0 802A9930 080AA65C */  j         .L802A9970
/* 42ECD4 802A9934 00000000 */   nop      
.L802A9938:
/* 42ECD8 802A9938 96230044 */  lhu       $v1, 0x44($s1)
/* 42ECDC 802A993C 3484851F */  ori       $a0, $a0, 0x851f
/* 42ECE0 802A9940 00031C00 */  sll       $v1, $v1, 0x10
/* 42ECE4 802A9944 00031403 */  sra       $v0, $v1, 0x10
/* 42ECE8 802A9948 00440018 */  mult      $v0, $a0
/* 42ECEC 802A994C 8FA50014 */  lw        $a1, 0x14($sp)
/* 42ECF0 802A9950 00031FC3 */  sra       $v1, $v1, 0x1f
/* 42ECF4 802A9954 8FA40010 */  lw        $a0, 0x10($sp)
/* 42ECF8 802A9958 00003810 */  mfhi      $a3
/* 42ECFC 802A995C 00073143 */  sra       $a2, $a3, 5
/* 42ED00 802A9960 00C33023 */  subu      $a2, $a2, $v1
/* 42ED04 802A9964 00063400 */  sll       $a2, $a2, 0x10
/* 42ED08 802A9968 0C09A203 */  jal       func_8026880C
/* 42ED0C 802A996C 00063403 */   sra      $a2, $a2, 0x10
.L802A9970:
/* 42ED10 802A9970 8E24000C */  lw        $a0, 0xc($s1)
/* 42ED14 802A9974 0C0511EA */  jal       draw_icon_0
/* 42ED18 802A9978 00000000 */   nop      
/* 42ED1C 802A997C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42ED20 802A9980 8FB1001C */  lw        $s1, 0x1c($sp)
/* 42ED24 802A9984 8FB00018 */  lw        $s0, 0x18($sp)
/* 42ED28 802A9988 03E00008 */  jr        $ra
/* 42ED2C 802A998C 27BD0028 */   addiu    $sp, $sp, 0x28
