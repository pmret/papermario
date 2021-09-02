.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_partners_draw_title
/* 13EEEC 8024BBAC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 13EEF0 8024BBB0 AFB00018 */  sw        $s0, 0x18($sp)
/* 13EEF4 8024BBB4 3C108027 */  lui       $s0, %hi(D_802706A0)
/* 13EEF8 8024BBB8 261006A0 */  addiu     $s0, $s0, %lo(D_802706A0)
/* 13EEFC 8024BBBC AFBF002C */  sw        $ra, 0x2c($sp)
/* 13EF00 8024BBC0 AFB40028 */  sw        $s4, 0x28($sp)
/* 13EF04 8024BBC4 AFB30024 */  sw        $s3, 0x24($sp)
/* 13EF08 8024BBC8 AFB20020 */  sw        $s2, 0x20($sp)
/* 13EF0C 8024BBCC AFB1001C */  sw        $s1, 0x1c($sp)
/* 13EF10 8024BBD0 8E020000 */  lw        $v0, ($s0)
/* 13EF14 8024BBD4 00A0902D */  daddu     $s2, $a1, $zero
/* 13EF18 8024BBD8 00021080 */  sll       $v0, $v0, 2
/* 13EF1C 8024BBDC 3C018027 */  lui       $at, %hi(D_80270680)
/* 13EF20 8024BBE0 00220821 */  addu      $at, $at, $v0
/* 13EF24 8024BBE4 8C220680 */  lw        $v0, %lo(D_80270680)($at)
/* 13EF28 8024BBE8 00C0982D */  daddu     $s3, $a2, $zero
/* 13EF2C 8024BBEC 00021080 */  sll       $v0, $v0, 2
/* 13EF30 8024BBF0 3C018025 */  lui       $at, %hi(D_8024F6B0)
/* 13EF34 8024BBF4 00220821 */  addu      $at, $at, $v0
/* 13EF38 8024BBF8 8C22F6B0 */  lw        $v0, %lo(D_8024F6B0)($at)
/* 13EF3C 8024BBFC 00021100 */  sll       $v0, $v0, 4
/* 13EF40 8024BC00 3C118009 */  lui       $s1, %hi(D_8008EF20)
/* 13EF44 8024BC04 02228821 */  addu      $s1, $s1, $v0
/* 13EF48 8024BC08 8E31EF20 */  lw        $s1, %lo(D_8008EF20)($s1)
/* 13EF4C 8024BC0C 0C039D59 */  jal       get_player_data
/* 13EF50 8024BC10 00E0A02D */   daddu    $s4, $a3, $zero
/* 13EF54 8024BC14 8E030000 */  lw        $v1, ($s0)
/* 13EF58 8024BC18 00031880 */  sll       $v1, $v1, 2
/* 13EF5C 8024BC1C 3C018027 */  lui       $at, %hi(D_80270680)
/* 13EF60 8024BC20 00230821 */  addu      $at, $at, $v1
/* 13EF64 8024BC24 8C230680 */  lw        $v1, %lo(D_80270680)($at)
/* 13EF68 8024BC28 0000282D */  daddu     $a1, $zero, $zero
/* 13EF6C 8024BC2C 00031880 */  sll       $v1, $v1, 2
/* 13EF70 8024BC30 3C018025 */  lui       $at, %hi(D_8024F6B0)
/* 13EF74 8024BC34 00230821 */  addu      $at, $at, $v1
/* 13EF78 8024BC38 8C23F6B0 */  lw        $v1, %lo(D_8024F6B0)($at)
/* 13EF7C 8024BC3C 000318C0 */  sll       $v1, $v1, 3
/* 13EF80 8024BC40 00431021 */  addu      $v0, $v0, $v1
/* 13EF84 8024BC44 80500015 */  lb        $s0, 0x15($v0)
/* 13EF88 8024BC48 0C04991D */  jal       get_msg_width
/* 13EF8C 8024BC4C 0220202D */   daddu    $a0, $s1, $zero
/* 13EF90 8024BC50 0040302D */  daddu     $a2, $v0, $zero
/* 13EF94 8024BC54 24020001 */  addiu     $v0, $zero, 1
/* 13EF98 8024BC58 12020005 */  beq       $s0, $v0, .L8024BC70
/* 13EF9C 8024BC5C 24030010 */   addiu    $v1, $zero, 0x10
/* 13EFA0 8024BC60 24020002 */  addiu     $v0, $zero, 2
/* 13EFA4 8024BC64 16020002 */  bne       $s0, $v0, .L8024BC70
/* 13EFA8 8024BC68 0000182D */   daddu    $v1, $zero, $zero
/* 13EFAC 8024BC6C 24030014 */  addiu     $v1, $zero, 0x14
.L8024BC70:
/* 13EFB0 8024BC70 54600001 */  bnel      $v1, $zero, .L8024BC78
/* 13EFB4 8024BC74 24C60004 */   addiu    $a2, $a2, 4
.L8024BC78:
/* 13EFB8 8024BC78 0220202D */  daddu     $a0, $s1, $zero
/* 13EFBC 8024BC7C 02832823 */  subu      $a1, $s4, $v1
/* 13EFC0 8024BC80 00A62823 */  subu      $a1, $a1, $a2
/* 13EFC4 8024BC84 00052843 */  sra       $a1, $a1, 1
/* 13EFC8 8024BC88 02452821 */  addu      $a1, $s2, $a1
/* 13EFCC 8024BC8C 26660001 */  addiu     $a2, $s3, 1
/* 13EFD0 8024BC90 240700FF */  addiu     $a3, $zero, 0xff
/* 13EFD4 8024BC94 AFA00010 */  sw        $zero, 0x10($sp)
/* 13EFD8 8024BC98 0C04993B */  jal       draw_msg
/* 13EFDC 8024BC9C AFA00014 */   sw       $zero, 0x14($sp)
/* 13EFE0 8024BCA0 24020001 */  addiu     $v0, $zero, 1
/* 13EFE4 8024BCA4 1602000A */  bne       $s0, $v0, .L8024BCD0
/* 13EFE8 8024BCA8 24020002 */   addiu    $v0, $zero, 2
/* 13EFEC 8024BCAC 2645005F */  addiu     $a1, $s2, 0x5f
/* 13EFF0 8024BCB0 3C108027 */  lui       $s0, %hi(D_80270640)
/* 13EFF4 8024BCB4 26100640 */  addiu     $s0, $s0, %lo(D_80270640)
/* 13EFF8 8024BCB8 8E040008 */  lw        $a0, 8($s0)
/* 13EFFC 8024BCBC 0C051261 */  jal       set_hud_element_render_pos
/* 13F000 8024BCC0 2666000A */   addiu    $a2, $s3, 0xa
/* 13F004 8024BCC4 8E040008 */  lw        $a0, 8($s0)
/* 13F008 8024BCC8 08092F44 */  j         .L8024BD10
/* 13F00C 8024BCCC 00000000 */   nop
.L8024BCD0:
/* 13F010 8024BCD0 16020011 */  bne       $s0, $v0, .L8024BD18
/* 13F014 8024BCD4 2645005B */   addiu    $a1, $s2, 0x5b
/* 13F018 8024BCD8 3C108027 */  lui       $s0, %hi(D_80270640)
/* 13F01C 8024BCDC 26100640 */  addiu     $s0, $s0, %lo(D_80270640)
/* 13F020 8024BCE0 2671000A */  addiu     $s1, $s3, 0xa
/* 13F024 8024BCE4 8E040008 */  lw        $a0, 8($s0)
/* 13F028 8024BCE8 0C051261 */  jal       set_hud_element_render_pos
/* 13F02C 8024BCEC 0220302D */   daddu    $a2, $s1, $zero
/* 13F030 8024BCF0 8E040008 */  lw        $a0, 8($s0)
/* 13F034 8024BCF4 0C0511F8 */  jal       draw_hud_element_3
/* 13F038 8024BCF8 00000000 */   nop
/* 13F03C 8024BCFC 26450065 */  addiu     $a1, $s2, 0x65
/* 13F040 8024BD00 8E04000C */  lw        $a0, 0xc($s0)
/* 13F044 8024BD04 0C051261 */  jal       set_hud_element_render_pos
/* 13F048 8024BD08 0220302D */   daddu    $a2, $s1, $zero
/* 13F04C 8024BD0C 8E04000C */  lw        $a0, 0xc($s0)
.L8024BD10:
/* 13F050 8024BD10 0C0511F8 */  jal       draw_hud_element_3
/* 13F054 8024BD14 00000000 */   nop
.L8024BD18:
/* 13F058 8024BD18 8FBF002C */  lw        $ra, 0x2c($sp)
/* 13F05C 8024BD1C 8FB40028 */  lw        $s4, 0x28($sp)
/* 13F060 8024BD20 8FB30024 */  lw        $s3, 0x24($sp)
/* 13F064 8024BD24 8FB20020 */  lw        $s2, 0x20($sp)
/* 13F068 8024BD28 8FB1001C */  lw        $s1, 0x1c($sp)
/* 13F06C 8024BD2C 8FB00018 */  lw        $s0, 0x18($sp)
/* 13F070 8024BD30 03E00008 */  jr        $ra
/* 13F074 8024BD34 27BD0030 */   addiu    $sp, $sp, 0x30
