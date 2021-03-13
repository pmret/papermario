.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80150E20
.word L801357A8_CBEA8, L80135B24_CC224, L80135E48_CC548, L80135E78_CC578, L80135F08_CC608, L80135F78_CC678, L8013637C_CCA7C, L8013637C_CCA7C, L80135F94_CC694, L80135FE8_CC6E8, L8013610C_CC80C, L8013614C_CC84C, L8013629C_CC99C, L801362D0_CC9D0, L80136310_CCA10, 0

.section .text

glabel update_item_entity_temp
/* CBDDC 801356DC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* CBDE0 801356E0 AFB10024 */  sw        $s1, 0x24($sp)
/* CBDE4 801356E4 0080882D */  daddu     $s1, $a0, $zero
/* CBDE8 801356E8 AFB40030 */  sw        $s4, 0x30($sp)
/* CBDEC 801356EC 3C148011 */  lui       $s4, %hi(gPlayerData)
/* CBDF0 801356F0 2694F290 */  addiu     $s4, $s4, %lo(gPlayerData)
/* CBDF4 801356F4 AFB3002C */  sw        $s3, 0x2c($sp)
/* CBDF8 801356F8 3C138011 */  lui       $s3, %hi(gPlayerStatus)
/* CBDFC 801356FC 2673EFC8 */  addiu     $s3, $s3, %lo(gPlayerStatus)
/* CBE00 80135700 AFBF0038 */  sw        $ra, 0x38($sp)
/* CBE04 80135704 AFB50034 */  sw        $s5, 0x34($sp)
/* CBE08 80135708 AFB20028 */  sw        $s2, 0x28($sp)
/* CBE0C 8013570C AFB00020 */  sw        $s0, 0x20($sp)
/* CBE10 80135710 8222001A */  lb        $v0, 0x1a($s1)
/* CBE14 80135714 3C108015 */  lui       $s0, %hi(D_801565B0)
/* CBE18 80135718 261065B0 */  addiu     $s0, $s0, %lo(D_801565B0)
/* CBE1C 8013571C 14400016 */  bnez      $v0, .L80135778
/* CBE20 80135720 24120001 */   addiu    $s2, $zero, 1
/* CBE24 80135724 8E220000 */  lw        $v0, ($s1)
/* CBE28 80135728 3C030200 */  lui       $v1, 0x200
/* CBE2C 8013572C 3C018015 */  lui       $at, %hi(D_801565A4)
/* CBE30 80135730 A43265A4 */  sh        $s2, %lo(D_801565A4)($at)
/* CBE34 80135734 00431024 */  and       $v0, $v0, $v1
/* CBE38 80135738 1440000C */  bnez      $v0, .L8013576C
/* CBE3C 8013573C 00000000 */   nop
/* CBE40 80135740 0C03805E */  jal       disable_player_input
/* CBE44 80135744 00000000 */   nop
/* CBE48 80135748 0C03BD8A */  jal       func_800EF628
/* CBE4C 8013574C 00000000 */   nop
/* CBE50 80135750 3C03800A */  lui       $v1, %hi(D_8009A650)
/* CBE54 80135754 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* CBE58 80135758 8C620000 */  lw        $v0, ($v1)
/* CBE5C 8013575C 24040002 */  addiu     $a0, $zero, 2
/* CBE60 80135760 34420040 */  ori       $v0, $v0, 0x40
/* CBE64 80135764 0C009C22 */  jal       func_80027088
/* CBE68 80135768 AC620000 */   sw       $v0, ($v1)
.L8013576C:
/* CBE6C 8013576C 0C04C3DC */  jal       func_80130F70
/* CBE70 80135770 0220202D */   daddu    $a0, $s1, $zero
/* CBE74 80135774 A232001A */  sb        $s2, 0x1a($s1)
.L80135778:
/* CBE78 80135778 9222001A */  lbu       $v0, 0x1a($s1)
/* CBE7C 8013577C 2442FFFF */  addiu     $v0, $v0, -1
/* CBE80 80135780 00021600 */  sll       $v0, $v0, 0x18
/* CBE84 80135784 00021E03 */  sra       $v1, $v0, 0x18
/* CBE88 80135788 2C62000F */  sltiu     $v0, $v1, 0xf
/* CBE8C 8013578C 104002FB */  beqz      $v0, L8013637C_CCA7C
/* CBE90 80135790 00031080 */   sll      $v0, $v1, 2
/* CBE94 80135794 3C018015 */  lui       $at, %hi(jtbl_80150E20)
/* CBE98 80135798 00220821 */  addu      $at, $at, $v0
/* CBE9C 8013579C 8C220E20 */  lw        $v0, %lo(jtbl_80150E20)($at)
/* CBEA0 801357A0 00400008 */  jr        $v0
/* CBEA4 801357A4 00000000 */   nop
glabel L801357A8_CBEA8
/* CBEA8 801357A8 8E220000 */  lw        $v0, ($s1)
/* CBEAC 801357AC 3C030200 */  lui       $v1, 0x200
/* CBEB0 801357B0 00431024 */  and       $v0, $v0, $v1
/* CBEB4 801357B4 1440001D */  bnez      $v0, .L8013582C
/* CBEB8 801357B8 3C031000 */   lui      $v1, 0x1000
/* CBEBC 801357BC 8E620004 */  lw        $v0, 4($s3)
/* CBEC0 801357C0 00431024 */  and       $v0, $v0, $v1
/* CBEC4 801357C4 14400019 */  bnez      $v0, .L8013582C
/* CBEC8 801357C8 826300B4 */   lb       $v1, 0xb4($s3)
/* CBECC 801357CC 866200C0 */  lh        $v0, 0xc0($s3)
/* CBED0 801357D0 14400005 */  bnez      $v0, .L801357E8
/* CBED4 801357D4 24020003 */   addiu    $v0, $zero, 3
/* CBED8 801357D8 10620003 */  beq       $v1, $v0, .L801357E8
/* CBEDC 801357DC 24020008 */   addiu    $v0, $zero, 8
/* CBEE0 801357E0 14620007 */  bne       $v1, $v0, .L80135800
/* CBEE4 801357E4 24020006 */   addiu    $v0, $zero, 6
.L801357E8:
/* CBEE8 801357E8 82620014 */  lb        $v0, 0x14($s3)
/* CBEEC 801357EC 10400004 */  beqz      $v0, .L80135800
/* CBEF0 801357F0 24020006 */   addiu    $v0, $zero, 6
/* CBEF4 801357F4 82620015 */  lb        $v0, 0x15($s3)
/* CBEF8 801357F8 1440000C */  bnez      $v0, .L8013582C
/* CBEFC 801357FC 24020006 */   addiu    $v0, $zero, 6
.L80135800:
/* CBF00 80135800 1062000A */  beq       $v1, $v0, .L8013582C
/* CBF04 80135804 24020021 */   addiu    $v0, $zero, 0x21
/* CBF08 80135808 10620008 */  beq       $v1, $v0, .L8013582C
/* CBF0C 8013580C 00000000 */   nop
/* CBF10 80135810 10600006 */  beqz      $v1, .L8013582C
/* CBF14 80135814 2402001D */   addiu    $v0, $zero, 0x1d
/* CBF18 80135818 146202D8 */  bne       $v1, $v0, L8013637C_CCA7C
/* CBF1C 8013581C 24020001 */   addiu    $v0, $zero, 1
/* CBF20 80135820 826300B6 */  lb        $v1, 0xb6($s3)
/* CBF24 80135824 146202D5 */  bne       $v1, $v0, L8013637C_CCA7C
/* CBF28 80135828 00000000 */   nop
.L8013582C:
/* CBF2C 8013582C 96220006 */  lhu       $v0, 6($s1)
/* CBF30 80135830 30420001 */  andi      $v0, $v0, 1
/* CBF34 80135834 1440001C */  bnez      $v0, .L801358A8
/* CBF38 80135838 00000000 */   nop
/* CBF3C 8013583C 86240018 */  lh        $a0, 0x18($s1)
/* CBF40 80135840 00041140 */  sll       $v0, $a0, 5
/* CBF44 80135844 3C038008 */  lui       $v1, %hi(gItemTable+0x18)
/* CBF48 80135848 00621821 */  addu      $v1, $v1, $v0
/* CBF4C 8013584C 946378F8 */  lhu       $v1, %lo(gItemTable+0x18)($v1)
/* CBF50 80135850 30620040 */  andi      $v0, $v1, 0x40
/* CBF54 80135854 10400003 */  beqz      $v0, .L80135864
/* CBF58 80135858 30620008 */   andi     $v0, $v1, 8
/* CBF5C 8013585C 0804D628 */  j         .L801358A0
/* CBF60 80135860 240400D3 */   addiu    $a0, $zero, 0xd3
.L80135864:
/* CBF64 80135864 10400003 */  beqz      $v0, .L80135874
/* CBF68 80135868 24020157 */   addiu    $v0, $zero, 0x157
/* CBF6C 8013586C 0804D628 */  j         .L801358A0
/* CBF70 80135870 240400D2 */   addiu    $a0, $zero, 0xd2
.L80135874:
/* CBF74 80135874 1482000A */  bne       $a0, $v0, .L801358A0
/* CBF78 80135878 240400D1 */   addiu    $a0, $zero, 0xd1
/* CBF7C 8013587C C6200010 */  lwc1      $f0, 0x10($s1)
/* CBF80 80135880 24040211 */  addiu     $a0, $zero, 0x211
/* CBF84 80135884 E7A00010 */  swc1      $f0, 0x10($sp)
/* CBF88 80135888 8E260008 */  lw        $a2, 8($s1)
/* CBF8C 8013588C 8E27000C */  lw        $a3, 0xc($s1)
/* CBF90 80135890 0C052757 */  jal       play_sound_at_position
/* CBF94 80135894 0000282D */   daddu    $a1, $zero, $zero
/* CBF98 80135898 0804D62A */  j         .L801358A8
/* CBF9C 8013589C 00000000 */   nop
.L801358A0:
/* CBFA0 801358A0 0C05272D */  jal       play_sound
/* CBFA4 801358A4 00000000 */   nop
.L801358A8:
/* CBFA8 801358A8 86220018 */  lh        $v0, 0x18($s1)
/* CBFAC 801358AC 00021140 */  sll       $v0, $v0, 5
/* CBFB0 801358B0 3C018008 */  lui       $at, %hi(gItemTable+0x4)
/* CBFB4 801358B4 00220821 */  addu      $at, $at, $v0
/* CBFB8 801358B8 842278E4 */  lh        $v0, %lo(gItemTable+0x4)($at)
/* CBFBC 801358BC 000210C0 */  sll       $v0, $v0, 3
/* CBFC0 801358C0 3C048009 */  lui       $a0, %hi(D_8008A680)
/* CBFC4 801358C4 00822021 */  addu      $a0, $a0, $v0
/* CBFC8 801358C8 8C84A680 */  lw        $a0, %lo(D_8008A680)($a0)
/* CBFCC 801358CC 0C050529 */  jal       create_icon
/* CBFD0 801358D0 00000000 */   nop
/* CBFD4 801358D4 0040202D */  daddu     $a0, $v0, $zero
/* CBFD8 801358D8 24050080 */  addiu     $a1, $zero, 0x80
/* CBFDC 801358DC 3C108015 */  lui       $s0, %hi(D_801568E0)
/* CBFE0 801358E0 261068E0 */  addiu     $s0, $s0, %lo(D_801568E0)
/* CBFE4 801358E4 0C051280 */  jal       set_icon_flags
/* CBFE8 801358E8 AE040000 */   sw       $a0, ($s0)
/* CBFEC 801358EC 2405FF9C */  addiu     $a1, $zero, -0x64
/* CBFF0 801358F0 8E040000 */  lw        $a0, ($s0)
/* CBFF4 801358F4 0C051261 */  jal       set_icon_render_pos
/* CBFF8 801358F8 00A0302D */   daddu    $a2, $a1, $zero
/* CBFFC 801358FC 24020002 */  addiu     $v0, $zero, 2
/* CC000 80135900 3C108008 */  lui       $s0, %hi(gItemTable)
/* CC004 80135904 261078E0 */  addiu     $s0, $s0, %lo(gItemTable)
/* CC008 80135908 A222001A */  sb        $v0, 0x1a($s1)
/* CC00C 8013590C 8E220000 */  lw        $v0, ($s1)
/* CC010 80135910 3C030200 */  lui       $v1, 0x200
/* CC014 80135914 00431024 */  and       $v0, $v0, $v1
/* CC018 80135918 14400066 */  bnez      $v0, .L80135AB4
/* CC01C 8013591C 00000000 */   nop
/* CC020 80135920 86220018 */  lh        $v0, 0x18($s1)
/* CC024 80135924 00021140 */  sll       $v0, $v0, 5
/* CC028 80135928 00501021 */  addu      $v0, $v0, $s0
/* CC02C 8013592C 94420018 */  lhu       $v0, 0x18($v0)
/* CC030 80135930 30420004 */  andi      $v0, $v0, 4
/* CC034 80135934 1040000F */  beqz      $v0, .L80135974
/* CC038 80135938 0000202D */   daddu    $a0, $zero, $zero
/* CC03C 8013593C 0280182D */  daddu     $v1, $s4, $zero
.L80135940:
/* CC040 80135940 846201B4 */  lh        $v0, 0x1b4($v1)
/* CC044 80135944 10400006 */  beqz      $v0, .L80135960
/* CC048 80135948 2882000A */   slti     $v0, $a0, 0xa
/* CC04C 8013594C 24840001 */  addiu     $a0, $a0, 1
/* CC050 80135950 2882000A */  slti      $v0, $a0, 0xa
/* CC054 80135954 1440FFFA */  bnez      $v0, .L80135940
/* CC058 80135958 24630002 */   addiu    $v1, $v1, 2
/* CC05C 8013595C 2882000A */  slti      $v0, $a0, 0xa
.L80135960:
/* CC060 80135960 1040002D */  beqz      $v0, .L80135A18
/* CC064 80135964 00041040 */   sll      $v0, $a0, 1
/* CC068 80135968 96230018 */  lhu       $v1, 0x18($s1)
/* CC06C 8013596C 02821021 */  addu      $v0, $s4, $v0
/* CC070 80135970 A44301B4 */  sh        $v1, 0x1b4($v0)
.L80135974:
/* CC074 80135974 86220018 */  lh        $v0, 0x18($s1)
/* CC078 80135978 00021140 */  sll       $v0, $v0, 5
/* CC07C 8013597C 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* CC080 80135980 00220821 */  addu      $at, $at, $v0
/* CC084 80135984 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* CC088 80135988 30420008 */  andi      $v0, $v0, 8
/* CC08C 8013598C 1040000F */  beqz      $v0, .L801359CC
/* CC090 80135990 0000202D */   daddu    $a0, $zero, $zero
/* CC094 80135994 0280182D */  daddu     $v1, $s4, $zero
.L80135998:
/* CC098 80135998 84620074 */  lh        $v0, 0x74($v1)
/* CC09C 8013599C 10400006 */  beqz      $v0, .L801359B8
/* CC0A0 801359A0 28820020 */   slti     $v0, $a0, 0x20
/* CC0A4 801359A4 24840001 */  addiu     $a0, $a0, 1
/* CC0A8 801359A8 28820020 */  slti      $v0, $a0, 0x20
/* CC0AC 801359AC 1440FFFA */  bnez      $v0, .L80135998
/* CC0B0 801359B0 24630002 */   addiu    $v1, $v1, 2
/* CC0B4 801359B4 28820020 */  slti      $v0, $a0, 0x20
.L801359B8:
/* CC0B8 801359B8 10400017 */  beqz      $v0, .L80135A18
/* CC0BC 801359BC 00041040 */   sll      $v0, $a0, 1
/* CC0C0 801359C0 96230018 */  lhu       $v1, 0x18($s1)
/* CC0C4 801359C4 02821021 */  addu      $v0, $s4, $v0
/* CC0C8 801359C8 A4430074 */  sh        $v1, 0x74($v0)
.L801359CC:
/* CC0CC 801359CC 86220018 */  lh        $v0, 0x18($s1)
/* CC0D0 801359D0 00021140 */  sll       $v0, $v0, 5
/* CC0D4 801359D4 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* CC0D8 801359D8 00220821 */  addu      $at, $at, $v0
/* CC0DC 801359DC 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* CC0E0 801359E0 30420040 */  andi      $v0, $v0, 0x40
/* CC0E4 801359E4 10400012 */  beqz      $v0, .L80135A30
/* CC0E8 801359E8 0000202D */   daddu    $a0, $zero, $zero
/* CC0EC 801359EC 0280182D */  daddu     $v1, $s4, $zero
.L801359F0:
/* CC0F0 801359F0 846200B4 */  lh        $v0, 0xb4($v1)
/* CC0F4 801359F4 10400006 */  beqz      $v0, .L80135A10
/* CC0F8 801359F8 28820080 */   slti     $v0, $a0, 0x80
/* CC0FC 801359FC 24840001 */  addiu     $a0, $a0, 1
/* CC100 80135A00 28820080 */  slti      $v0, $a0, 0x80
/* CC104 80135A04 1440FFFA */  bnez      $v0, .L801359F0
/* CC108 80135A08 24630002 */   addiu    $v1, $v1, 2
/* CC10C 80135A0C 28820080 */  slti      $v0, $a0, 0x80
.L80135A10:
/* CC110 80135A10 14400004 */  bnez      $v0, .L80135A24
/* CC114 80135A14 00041040 */   sll      $v0, $a0, 1
.L80135A18:
/* CC118 80135A18 2402000A */  addiu     $v0, $zero, 0xa
/* CC11C 80135A1C 0804D6AD */  j         .L80135AB4
/* CC120 80135A20 A222001A */   sb       $v0, 0x1a($s1)
.L80135A24:
/* CC124 80135A24 96230018 */  lhu       $v1, 0x18($s1)
/* CC128 80135A28 02821021 */  addu      $v0, $s4, $v0
/* CC12C 80135A2C A44300B4 */  sh        $v1, 0xb4($v0)
.L80135A30:
/* CC130 80135A30 86230018 */  lh        $v1, 0x18($s1)
/* CC134 80135A34 2402015C */  addiu     $v0, $zero, 0x15c
/* CC138 80135A38 1462000B */  bne       $v1, $v0, .L80135A68
/* CC13C 80135A3C 24020007 */   addiu    $v0, $zero, 7
/* CC140 80135A40 9282000F */  lbu       $v0, 0xf($s4)
/* CC144 80135A44 24420001 */  addiu     $v0, $v0, 1
/* CC148 80135A48 A282000F */  sb        $v0, 0xf($s4)
/* CC14C 80135A4C 304200FF */  andi      $v0, $v0, 0xff
/* CC150 80135A50 2C4200DF */  sltiu     $v0, $v0, 0xdf
/* CC154 80135A54 14400002 */  bnez      $v0, .L80135A60
/* CC158 80135A58 240200DE */   addiu    $v0, $zero, 0xde
/* CC15C 80135A5C A282000F */  sb        $v0, 0xf($s4)
.L80135A60:
/* CC160 80135A60 86230018 */  lh        $v1, 0x18($s1)
/* CC164 80135A64 24020007 */  addiu     $v0, $zero, 7
.L80135A68:
/* CC168 80135A68 14620002 */  bne       $v1, $v0, .L80135A74
/* CC16C 80135A6C 24020001 */   addiu    $v0, $zero, 1
/* CC170 80135A70 A282000A */  sb        $v0, 0xa($s4)
.L80135A74:
/* CC174 80135A74 96220018 */  lhu       $v0, 0x18($s1)
/* CC178 80135A78 2442FFFC */  addiu     $v0, $v0, -4
/* CC17C 80135A7C 2C420003 */  sltiu     $v0, $v0, 3
/* CC180 80135A80 10400004 */  beqz      $v0, .L80135A94
/* CC184 80135A84 00000000 */   nop
/* CC188 80135A88 92220019 */  lbu       $v0, 0x19($s1)
/* CC18C 80135A8C 2442FFFC */  addiu     $v0, $v0, -4
/* CC190 80135A90 A2820001 */  sb        $v0, 1($s4)
.L80135A94:
/* CC194 80135A94 96220018 */  lhu       $v0, 0x18($s1)
/* CC198 80135A98 2442FFFF */  addiu     $v0, $v0, -1
/* CC19C 80135A9C 2C420003 */  sltiu     $v0, $v0, 3
/* CC1A0 80135AA0 10400004 */  beqz      $v0, .L80135AB4
/* CC1A4 80135AA4 00000000 */   nop
/* CC1A8 80135AA8 92220019 */  lbu       $v0, 0x19($s1)
/* CC1AC 80135AAC 2442FFFF */  addiu     $v0, $v0, -1
/* CC1B0 80135AB0 A2820000 */  sb        $v0, ($s4)
.L80135AB4:
/* CC1B4 80135AB4 8E220000 */  lw        $v0, ($s1)
/* CC1B8 80135AB8 04410003 */  bgez      $v0, .L80135AC8
/* CC1BC 80135ABC 00000000 */   nop
/* CC1C0 80135AC0 0C051514 */  jal       set_global_flag
/* CC1C4 80135AC4 86240004 */   lh       $a0, 4($s1)
.L80135AC8:
/* CC1C8 80135AC8 8222001A */  lb        $v0, 0x1a($s1)
/* CC1CC 80135ACC 2412000A */  addiu     $s2, $zero, 0xa
/* CC1D0 80135AD0 1452000E */  bne       $v0, $s2, .L80135B0C
/* CC1D4 80135AD4 00000000 */   nop
/* CC1D8 80135AD8 0C04D8E8 */  jal       func_801363A0
/* CC1DC 80135ADC 0220202D */   daddu    $a0, $s1, $zero
/* CC1E0 80135AE0 2404000C */  addiu     $a0, $zero, 0xc
/* CC1E4 80135AE4 3C108014 */  lui       $s0, %hi(basic_window_update)
/* CC1E8 80135AE8 26107474 */  addiu     $s0, $s0, %lo(basic_window_update)
/* CC1EC 80135AEC 0C051F9F */  jal       set_window_update
/* CC1F0 80135AF0 0200282D */   daddu    $a1, $s0, $zero
/* CC1F4 80135AF4 24040011 */  addiu     $a0, $zero, 0x11
/* CC1F8 80135AF8 0C051F9F */  jal       set_window_update
/* CC1FC 80135AFC 0200282D */   daddu    $a1, $s0, $zero
/* CC200 80135B00 24040013 */  addiu     $a0, $zero, 0x13
/* CC204 80135B04 0C051F9F */  jal       set_window_update
/* CC208 80135B08 0200282D */   daddu    $a1, $s0, $zero
.L80135B0C:
/* CC20C 80135B0C 0C03A6D5 */  jal       increment_status_menu_disabled
/* CC210 80135B10 00000000 */   nop
/* CC214 80135B14 3C018015 */  lui       $at, %hi(D_801568E4)
/* CC218 80135B18 AC3268E4 */  sw        $s2, %lo(D_801568E4)($at)
/* CC21C 80135B1C 0804D8DF */  j         L8013637C_CCA7C
/* CC220 80135B20 00000000 */   nop
glabel L80135B24_CC224
/* CC224 80135B24 3C038015 */  lui       $v1, %hi(D_801568E4)
/* CC228 80135B28 8C6368E4 */  lw        $v1, %lo(D_801568E4)($v1)
/* CC22C 80135B2C 24020009 */  addiu     $v0, $zero, 9
/* CC230 80135B30 1462003C */  bne       $v1, $v0, .L80135C24
/* CC234 80135B34 00000000 */   nop
/* CC238 80135B38 86240018 */  lh        $a0, 0x18($s1)
/* CC23C 80135B3C 00041140 */  sll       $v0, $a0, 5
/* CC240 80135B40 3C038008 */  lui       $v1, %hi(gItemTable+0x18)
/* CC244 80135B44 00621821 */  addu      $v1, $v1, $v0
/* CC248 80135B48 946378F8 */  lhu       $v1, %lo(gItemTable+0x18)($v1)
/* CC24C 80135B4C 30620040 */  andi      $v0, $v1, 0x40
/* CC250 80135B50 1440000F */  bnez      $v0, .L80135B90
/* CC254 80135B54 30620008 */   andi     $v0, $v1, 8
/* CC258 80135B58 1440000D */  bnez      $v0, .L80135B90
/* CC25C 80135B5C 2402015C */   addiu    $v0, $zero, 0x15c
/* CC260 80135B60 1082000B */  beq       $a0, $v0, .L80135B90
/* CC264 80135B64 30620020 */   andi     $v0, $v1, 0x20
/* CC268 80135B68 14400009 */  bnez      $v0, .L80135B90
/* CC26C 80135B6C 3C030400 */   lui      $v1, 0x400
/* CC270 80135B70 8E220000 */  lw        $v0, ($s1)
/* CC274 80135B74 00431024 */  and       $v0, $v0, $v1
/* CC278 80135B78 14400005 */  bnez      $v0, .L80135B90
/* CC27C 80135B7C 00000000 */   nop
/* CC280 80135B80 96220006 */  lhu       $v0, 6($s1)
/* CC284 80135B84 30420002 */  andi      $v0, $v0, 2
/* CC288 80135B88 1040000F */  beqz      $v0, .L80135BC8
/* CC28C 80135B8C 00000000 */   nop
.L80135B90:
/* CC290 80135B90 C6600028 */  lwc1      $f0, 0x28($s3)
/* CC294 80135B94 E6200008 */  swc1      $f0, 8($s1)
/* CC298 80135B98 866200B0 */  lh        $v0, 0xb0($s3)
/* CC29C 80135B9C C660002C */  lwc1      $f0, 0x2c($s3)
/* CC2A0 80135BA0 44821000 */  mtc1      $v0, $f2
/* CC2A4 80135BA4 00000000 */  nop
/* CC2A8 80135BA8 468010A0 */  cvt.s.w   $f2, $f2
/* CC2AC 80135BAC 46020000 */  add.s     $f0, $f0, $f2
/* CC2B0 80135BB0 3C040006 */  lui       $a0, 6
/* CC2B4 80135BB4 E620000C */  swc1      $f0, 0xc($s1)
/* CC2B8 80135BB8 C6600030 */  lwc1      $f0, 0x30($s3)
/* CC2BC 80135BBC 3484000C */  ori       $a0, $a0, 0xc
/* CC2C0 80135BC0 0C037FDE */  jal       func_800DFF78
/* CC2C4 80135BC4 E6200010 */   swc1     $f0, 0x10($s1)
.L80135BC8:
/* CC2C8 80135BC8 86220018 */  lh        $v0, 0x18($s1)
/* CC2CC 80135BCC 00021140 */  sll       $v0, $v0, 5
/* CC2D0 80135BD0 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* CC2D4 80135BD4 00220821 */  addu      $at, $at, $v0
/* CC2D8 80135BD8 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* CC2DC 80135BDC 30420020 */  andi      $v0, $v0, 0x20
/* CC2E0 80135BE0 10400010 */  beqz      $v0, .L80135C24
/* CC2E4 80135BE4 00000000 */   nop
/* CC2E8 80135BE8 C624000C */  lwc1      $f4, 0xc($s1)
/* CC2EC 80135BEC 3C014100 */  lui       $at, 0x4100
/* CC2F0 80135BF0 44810000 */  mtc1      $at, $f0
/* CC2F4 80135BF4 3C013F80 */  lui       $at, 0x3f80
/* CC2F8 80135BF8 44811000 */  mtc1      $at, $f2
/* CC2FC 80135BFC 3C028015 */  lui       $v0, %hi(D_801568F0)
/* CC300 80135C00 244268F0 */  addiu     $v0, $v0, %lo(D_801568F0)
/* CC304 80135C04 AFA20014 */  sw        $v0, 0x14($sp)
/* CC308 80135C08 46002100 */  add.s     $f4, $f4, $f0
/* CC30C 80135C0C E7A20010 */  swc1      $f2, 0x10($sp)
/* CC310 80135C10 8E250008 */  lw        $a1, 8($s1)
/* CC314 80135C14 8E270010 */  lw        $a3, 0x10($s1)
/* CC318 80135C18 44062000 */  mfc1      $a2, $f4
/* CC31C 80135C1C 0C01C0AC */  jal       func_800702B0
/* CC320 80135C20 24040001 */   addiu    $a0, $zero, 1
.L80135C24:
/* CC324 80135C24 3C028015 */  lui       $v0, %hi(D_801568E4)
/* CC328 80135C28 8C4268E4 */  lw        $v0, %lo(D_801568E4)($v0)
/* CC32C 80135C2C 28420009 */  slti      $v0, $v0, 9
/* CC330 80135C30 1040001D */  beqz      $v0, .L80135CA8
/* CC334 80135C34 00000000 */   nop
/* CC338 80135C38 86240018 */  lh        $a0, 0x18($s1)
/* CC33C 80135C3C 00041140 */  sll       $v0, $a0, 5
/* CC340 80135C40 3C038008 */  lui       $v1, %hi(gItemTable+0x18)
/* CC344 80135C44 00621821 */  addu      $v1, $v1, $v0
/* CC348 80135C48 946378F8 */  lhu       $v1, %lo(gItemTable+0x18)($v1)
/* CC34C 80135C4C 30620040 */  andi      $v0, $v1, 0x40
/* CC350 80135C50 54400013 */  bnel      $v0, $zero, .L80135CA0
/* CC354 80135C54 3C040006 */   lui      $a0, 6
/* CC358 80135C58 30620008 */  andi      $v0, $v1, 8
/* CC35C 80135C5C 54400010 */  bnel      $v0, $zero, .L80135CA0
/* CC360 80135C60 3C040006 */   lui      $a0, 6
/* CC364 80135C64 2402015C */  addiu     $v0, $zero, 0x15c
/* CC368 80135C68 1082000C */  beq       $a0, $v0, .L80135C9C
/* CC36C 80135C6C 30620020 */   andi     $v0, $v1, 0x20
/* CC370 80135C70 5440000B */  bnel      $v0, $zero, .L80135CA0
/* CC374 80135C74 3C040006 */   lui      $a0, 6
/* CC378 80135C78 8E220000 */  lw        $v0, ($s1)
/* CC37C 80135C7C 3C030400 */  lui       $v1, 0x400
/* CC380 80135C80 00431024 */  and       $v0, $v0, $v1
/* CC384 80135C84 54400006 */  bnel      $v0, $zero, .L80135CA0
/* CC388 80135C88 3C040006 */   lui      $a0, 6
/* CC38C 80135C8C 96220006 */  lhu       $v0, 6($s1)
/* CC390 80135C90 30420002 */  andi      $v0, $v0, 2
/* CC394 80135C94 10400004 */  beqz      $v0, .L80135CA8
/* CC398 80135C98 00000000 */   nop
.L80135C9C:
/* CC39C 80135C9C 3C040006 */  lui       $a0, 6
.L80135CA0:
/* CC3A0 80135CA0 0C037FDE */  jal       func_800DFF78
/* CC3A4 80135CA4 3484000C */   ori      $a0, $a0, 0xc
.L80135CA8:
/* CC3A8 80135CA8 3C038015 */  lui       $v1, %hi(D_801568E4)
/* CC3AC 80135CAC 8C6368E4 */  lw        $v1, %lo(D_801568E4)($v1)
/* CC3B0 80135CB0 24020007 */  addiu     $v0, $zero, 7
/* CC3B4 80135CB4 1462001E */  bne       $v1, $v0, .L80135D30
/* CC3B8 80135CB8 24020006 */   addiu    $v0, $zero, 6
/* CC3BC 80135CBC 86240018 */  lh        $a0, 0x18($s1)
/* CC3C0 80135CC0 00041140 */  sll       $v0, $a0, 5
/* CC3C4 80135CC4 3C038008 */  lui       $v1, %hi(gItemTable+0x18)
/* CC3C8 80135CC8 00621821 */  addu      $v1, $v1, $v0
/* CC3CC 80135CCC 946378F8 */  lhu       $v1, %lo(gItemTable+0x18)($v1)
/* CC3D0 80135CD0 30620040 */  andi      $v0, $v1, 0x40
/* CC3D4 80135CD4 1440000F */  bnez      $v0, .L80135D14
/* CC3D8 80135CD8 30620008 */   andi     $v0, $v1, 8
/* CC3DC 80135CDC 1440000D */  bnez      $v0, .L80135D14
/* CC3E0 80135CE0 2402015C */   addiu    $v0, $zero, 0x15c
/* CC3E4 80135CE4 1082000B */  beq       $a0, $v0, .L80135D14
/* CC3E8 80135CE8 30620020 */   andi     $v0, $v1, 0x20
/* CC3EC 80135CEC 14400009 */  bnez      $v0, .L80135D14
/* CC3F0 80135CF0 3C030400 */   lui      $v1, 0x400
/* CC3F4 80135CF4 8E220000 */  lw        $v0, ($s1)
/* CC3F8 80135CF8 00431024 */  and       $v0, $v0, $v1
/* CC3FC 80135CFC 14400005 */  bnez      $v0, .L80135D14
/* CC400 80135D00 00000000 */   nop
/* CC404 80135D04 96220006 */  lhu       $v0, 6($s1)
/* CC408 80135D08 30420002 */  andi      $v0, $v0, 2
/* CC40C 80135D0C 10400005 */  beqz      $v0, .L80135D24
/* CC410 80135D10 00000000 */   nop
.L80135D14:
/* CC414 80135D14 8E220000 */  lw        $v0, ($s1)
/* CC418 80135D18 2403FFBF */  addiu     $v1, $zero, -0x41
/* CC41C 80135D1C 00431024 */  and       $v0, $v0, $v1
/* CC420 80135D20 AE220000 */  sw        $v0, ($s1)
.L80135D24:
/* CC424 80135D24 3C038015 */  lui       $v1, %hi(D_801568E4)
/* CC428 80135D28 8C6368E4 */  lw        $v1, %lo(D_801568E4)($v1)
/* CC42C 80135D2C 24020006 */  addiu     $v0, $zero, 6
.L80135D30:
/* CC430 80135D30 14620010 */  bne       $v1, $v0, .L80135D74
/* CC434 80135D34 00000000 */   nop
/* CC438 80135D38 0C04D8E8 */  jal       func_801363A0
/* CC43C 80135D3C 0220202D */   daddu    $a0, $s1, $zero
/* CC440 80135D40 2404000C */  addiu     $a0, $zero, 0xc
/* CC444 80135D44 3C108014 */  lui       $s0, %hi(basic_window_update)
/* CC448 80135D48 26107474 */  addiu     $s0, $s0, %lo(basic_window_update)
/* CC44C 80135D4C 0C051F9F */  jal       set_window_update
/* CC450 80135D50 0200282D */   daddu    $a1, $s0, $zero
/* CC454 80135D54 86230018 */  lh        $v1, 0x18($s1)
/* CC458 80135D58 2402015C */  addiu     $v0, $zero, 0x15c
/* CC45C 80135D5C 10620005 */  beq       $v1, $v0, .L80135D74
/* CC460 80135D60 24020157 */   addiu    $v0, $zero, 0x157
/* CC464 80135D64 10620003 */  beq       $v1, $v0, .L80135D74
/* CC468 80135D68 24040013 */   addiu    $a0, $zero, 0x13
/* CC46C 80135D6C 0C051F9F */  jal       set_window_update
/* CC470 80135D70 0200282D */   daddu    $a1, $s0, $zero
.L80135D74:
/* CC474 80135D74 3C038015 */  lui       $v1, %hi(D_801568E4)
/* CC478 80135D78 246368E4 */  addiu     $v1, $v1, %lo(D_801568E4)
/* CC47C 80135D7C 8C620000 */  lw        $v0, ($v1)
/* CC480 80135D80 10400003 */  beqz      $v0, .L80135D90
/* CC484 80135D84 2442FFFF */   addiu    $v0, $v0, -1
/* CC488 80135D88 0804D8DF */  j         L8013637C_CCA7C
/* CC48C 80135D8C AC620000 */   sw       $v0, ($v1)
.L80135D90:
/* CC490 80135D90 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* CC494 80135D94 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* CC498 80135D98 3C03000F */  lui       $v1, 0xf
/* CC49C 80135D9C 8C420010 */  lw        $v0, 0x10($v0)
/* CC4A0 80135DA0 3463C000 */  ori       $v1, $v1, 0xc000
/* CC4A4 80135DA4 00431024 */  and       $v0, $v0, $v1
/* CC4A8 80135DA8 10400174 */  beqz      $v0, L8013637C_CCA7C
/* CC4AC 80135DAC 00000000 */   nop
/* CC4B0 80135DB0 0C04C3DC */  jal       func_80130F70
/* CC4B4 80135DB4 0220202D */   daddu    $a0, $s1, $zero
/* CC4B8 80135DB8 0C037F3D */  jal       func_800DFCF4
/* CC4BC 80135DBC 00000000 */   nop
/* CC4C0 80135DC0 1040000A */  beqz      $v0, .L80135DEC
/* CC4C4 80135DC4 2402001D */   addiu    $v0, $zero, 0x1d
/* CC4C8 80135DC8 826300B4 */  lb        $v1, 0xb4($s3)
/* CC4CC 80135DCC 10620007 */  beq       $v1, $v0, .L80135DEC
/* CC4D0 80135DD0 3C031000 */   lui      $v1, 0x1000
/* CC4D4 80135DD4 8E620004 */  lw        $v0, 4($s3)
/* CC4D8 80135DD8 00431024 */  and       $v0, $v0, $v1
/* CC4DC 80135DDC 14400003 */  bnez      $v0, .L80135DEC
/* CC4E0 80135DE0 00000000 */   nop
/* CC4E4 80135DE4 0C039769 */  jal       set_action_state
/* CC4E8 80135DE8 0000202D */   daddu    $a0, $zero, $zero
.L80135DEC:
/* CC4EC 80135DEC 86220018 */  lh        $v0, 0x18($s1)
/* CC4F0 80135DF0 00021140 */  sll       $v0, $v0, 5
/* CC4F4 80135DF4 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* CC4F8 80135DF8 00220821 */  addu      $at, $at, $v0
/* CC4FC 80135DFC 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* CC500 80135E00 30420020 */  andi      $v0, $v0, 0x20
/* CC504 80135E04 10400006 */  beqz      $v0, .L80135E20
/* CC508 80135E08 2404000C */   addiu    $a0, $zero, 0xc
/* CC50C 80135E0C 3C028015 */  lui       $v0, %hi(D_801568F0)
/* CC510 80135E10 8C4268F0 */  lw        $v0, %lo(D_801568F0)($v0)
/* CC514 80135E14 8C43000C */  lw        $v1, 0xc($v0)
/* CC518 80135E18 2402000A */  addiu     $v0, $zero, 0xa
/* CC51C 80135E1C AC620014 */  sw        $v0, 0x14($v1)
.L80135E20:
/* CC520 80135E20 3C108014 */  lui       $s0, %hi(basic_hidden_window_update)
/* CC524 80135E24 26107574 */  addiu     $s0, $s0, %lo(basic_hidden_window_update)
/* CC528 80135E28 0C051F9F */  jal       set_window_update
/* CC52C 80135E2C 0200282D */   daddu    $a1, $s0, $zero
/* CC530 80135E30 24040013 */  addiu     $a0, $zero, 0x13
/* CC534 80135E34 0C051F9F */  jal       set_window_update
/* CC538 80135E38 0200282D */   daddu    $a1, $s0, $zero
/* CC53C 80135E3C 24020003 */  addiu     $v0, $zero, 3
/* CC540 80135E40 0804D8DF */  j         L8013637C_CCA7C
/* CC544 80135E44 A222001A */   sb       $v0, 0x1a($s1)
glabel L80135E48_CC548
/* CC548 80135E48 3C038016 */  lui       $v1, %hi(gUIPanels)
/* CC54C 80135E4C 24639D50 */  addiu     $v1, $v1, %lo(gUIPanels)
/* CC550 80135E50 90620180 */  lbu       $v0, 0x180($v1)
/* CC554 80135E54 30420008 */  andi      $v0, $v0, 8
/* CC558 80135E58 14400148 */  bnez      $v0, L8013637C_CCA7C
/* CC55C 80135E5C 00000000 */   nop
/* CC560 80135E60 90620260 */  lbu       $v0, 0x260($v1)
/* CC564 80135E64 30420008 */  andi      $v0, $v0, 8
/* CC568 80135E68 14400144 */  bnez      $v0, L8013637C_CCA7C
/* CC56C 80135E6C 24020004 */   addiu    $v0, $zero, 4
/* CC570 80135E70 0804D8DF */  j         L8013637C_CCA7C
/* CC574 80135E74 A222001A */   sb       $v0, 0x1a($s1)
glabel L80135E78_CC578
/* CC578 80135E78 86220018 */  lh        $v0, 0x18($s1)
/* CC57C 80135E7C 00021140 */  sll       $v0, $v0, 5
/* CC580 80135E80 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* CC584 80135E84 00220821 */  addu      $at, $at, $v0
/* CC588 80135E88 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* CC58C 80135E8C 30420004 */  andi      $v0, $v0, 4
/* CC590 80135E90 10400009 */  beqz      $v0, .L80135EB8
/* CC594 80135E94 0000202D */   daddu    $a0, $zero, $zero
/* CC598 80135E98 3C05F840 */  lui       $a1, 0xf840
/* CC59C 80135E9C 0C0B1EAF */  jal       get_variable
/* CC5A0 80135EA0 34A55BE1 */   ori      $a1, $a1, 0x5be1
/* CC5A4 80135EA4 14400004 */  bnez      $v0, .L80135EB8
/* CC5A8 80135EA8 0000202D */   daddu    $a0, $zero, $zero
/* CC5AC 80135EAC 3C05F840 */  lui       $a1, 0xf840
/* CC5B0 80135EB0 0804D7BB */  j         .L80135EEC
/* CC5B4 80135EB4 34A55BE1 */   ori      $a1, $a1, 0x5be1
.L80135EB8:
/* CC5B8 80135EB8 86230018 */  lh        $v1, 0x18($s1)
/* CC5BC 80135EBC 2402015C */  addiu     $v0, $zero, 0x15c
/* CC5C0 80135EC0 1462000F */  bne       $v1, $v0, .L80135F00
/* CC5C4 80135EC4 24020009 */   addiu    $v0, $zero, 9
/* CC5C8 80135EC8 0000202D */  daddu     $a0, $zero, $zero
/* CC5CC 80135ECC 3C05F840 */  lui       $a1, 0xf840
/* CC5D0 80135ED0 0C0B1EAF */  jal       get_variable
/* CC5D4 80135ED4 34A55BE5 */   ori      $a1, $a1, 0x5be5
/* CC5D8 80135ED8 14400009 */  bnez      $v0, .L80135F00
/* CC5DC 80135EDC 24020009 */   addiu    $v0, $zero, 9
/* CC5E0 80135EE0 0000202D */  daddu     $a0, $zero, $zero
/* CC5E4 80135EE4 3C05F840 */  lui       $a1, 0xf840
/* CC5E8 80135EE8 34A55BE5 */  ori       $a1, $a1, 0x5be5
.L80135EEC:
/* CC5EC 80135EEC 0C0B2026 */  jal       set_variable
/* CC5F0 80135EF0 24060001 */   addiu    $a2, $zero, 1
/* CC5F4 80135EF4 24020005 */  addiu     $v0, $zero, 5
/* CC5F8 80135EF8 0804D8DF */  j         L8013637C_CCA7C
/* CC5FC 80135EFC A222001A */   sb       $v0, 0x1a($s1)
.L80135F00:
/* CC600 80135F00 0804D8DF */  j         L8013637C_CCA7C
/* CC604 80135F04 A222001A */   sb       $v0, 0x1a($s1)
glabel L80135F08_CC608
/* CC608 80135F08 86230018 */  lh        $v1, 0x18($s1)
/* CC60C 80135F0C 00031140 */  sll       $v0, $v1, 5
/* CC610 80135F10 3C018008 */  lui       $at, %hi(gItemTable+0x18)
/* CC614 80135F14 00220821 */  addu      $at, $at, $v0
/* CC618 80135F18 942278F8 */  lhu       $v0, %lo(gItemTable+0x18)($at)
/* CC61C 80135F1C 30420004 */  andi      $v0, $v0, 4
/* CC620 80135F20 10400003 */  beqz      $v0, .L80135F30
/* CC624 80135F24 0000202D */   daddu    $a0, $zero, $zero
/* CC628 80135F28 3C04001D */  lui       $a0, 0x1d
/* CC62C 80135F2C 34840002 */  ori       $a0, $a0, 2
.L80135F30:
/* CC630 80135F30 2402015C */  addiu     $v0, $zero, 0x15c
/* CC634 80135F34 14620003 */  bne       $v1, $v0, .L80135F44
/* CC638 80135F38 00000000 */   nop
/* CC63C 80135F3C 3C04001D */  lui       $a0, 0x1d
/* CC640 80135F40 34840003 */  ori       $a0, $a0, 3
.L80135F44:
/* CC644 80135F44 3C058015 */  lui       $a1, %hi(D_801568F8)
/* CC648 80135F48 24A568F8 */  addiu     $a1, $a1, %lo(D_801568F8)
/* CC64C 80135F4C 0C049640 */  jal       load_string
/* CC650 80135F50 00000000 */   nop
/* CC654 80135F54 0040202D */  daddu     $a0, $v0, $zero
/* CC658 80135F58 0000282D */  daddu     $a1, $zero, $zero
/* CC65C 80135F5C 3C018015 */  lui       $at, %hi(D_801568F4)
/* CC660 80135F60 AC2468F4 */  sw        $a0, %lo(D_801568F4)($at)
/* CC664 80135F64 0C0496AE */  jal       clamp_printer_coords
/* CC668 80135F68 00A0302D */   daddu    $a2, $a1, $zero
/* CC66C 80135F6C 24020006 */  addiu     $v0, $zero, 6
/* CC670 80135F70 0804D8DF */  j         L8013637C_CCA7C
/* CC674 80135F74 A222001A */   sb       $v0, 0x1a($s1)
glabel L80135F78_CC678
/* CC678 80135F78 3C038015 */  lui       $v1, %hi(D_801568F8)
/* CC67C 80135F7C 8C6368F8 */  lw        $v1, %lo(D_801568F8)($v1)
/* CC680 80135F80 24020001 */  addiu     $v0, $zero, 1
/* CC684 80135F84 146200FD */  bne       $v1, $v0, L8013637C_CCA7C
/* CC688 80135F88 00000000 */   nop
/* CC68C 80135F8C 3C018015 */  lui       $at, %hi(D_801565A4)
/* CC690 80135F90 A42065A4 */  sh        $zero, %lo(D_801565A4)($at)
glabel L80135F94_CC694
/* CC694 80135F94 8E220000 */  lw        $v0, ($s1)
/* CC698 80135F98 3C030200 */  lui       $v1, 0x200
/* CC69C 80135F9C 00431024 */  and       $v0, $v0, $v1
/* CC6A0 80135FA0 1440000D */  bnez      $v0, .L80135FD8
/* CC6A4 80135FA4 00000000 */   nop
/* CC6A8 80135FA8 0C009C22 */  jal       func_80027088
/* CC6AC 80135FAC 0000202D */   daddu    $a0, $zero, $zero
/* CC6B0 80135FB0 0C038069 */  jal       enable_player_input
/* CC6B4 80135FB4 00000000 */   nop
/* CC6B8 80135FB8 0C03BD80 */  jal       func_800EF600
/* CC6BC 80135FBC 00000000 */   nop
/* CC6C0 80135FC0 3C02800A */  lui       $v0, %hi(D_8009A650)
/* CC6C4 80135FC4 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* CC6C8 80135FC8 8C430000 */  lw        $v1, ($v0)
/* CC6CC 80135FCC 2404FFBF */  addiu     $a0, $zero, -0x41
/* CC6D0 80135FD0 00641824 */  and       $v1, $v1, $a0
/* CC6D4 80135FD4 AC430000 */  sw        $v1, ($v0)
.L80135FD8:
/* CC6D8 80135FD8 3C048015 */  lui       $a0, %hi(D_801568E0)
/* CC6DC 80135FDC 8C8468E0 */  lw        $a0, %lo(D_801568E0)($a0)
/* CC6E0 80135FE0 0804D8D5 */  j         .L80136354
/* CC6E4 80135FE4 00000000 */   nop
glabel L80135FE8_CC6E8
/* CC6E8 80135FE8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* CC6EC 80135FEC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* CC6F0 80135FF0 8C420010 */  lw        $v0, 0x10($v0)
/* CC6F4 80135FF4 30428000 */  andi      $v0, $v0, 0x8000
/* CC6F8 80135FF8 104000E0 */  beqz      $v0, L8013637C_CCA7C
/* CC6FC 80135FFC 24070001 */   addiu    $a3, $zero, 1
/* CC700 80136000 0000202D */  daddu     $a0, $zero, $zero
/* CC704 80136004 3C038008 */  lui       $v1, %hi(gItemTable)
/* CC708 80136008 246378E0 */  addiu     $v1, $v1, %lo(gItemTable)
/* CC70C 8013600C 86220018 */  lh        $v0, 0x18($s1)
/* CC710 80136010 0060402D */  daddu     $t0, $v1, $zero
/* CC714 80136014 00021140 */  sll       $v0, $v0, 5
/* CC718 80136018 00482821 */  addu      $a1, $v0, $t0
/* CC71C 8013601C 84A20004 */  lh        $v0, 4($a1)
/* CC720 80136020 3C0A8009 */  lui       $t2, %hi(D_8008A680)
/* CC724 80136024 254AA680 */  addiu     $t2, $t2, %lo(D_8008A680)
/* CC728 80136028 000210C0 */  sll       $v0, $v0, 3
/* CC72C 8013602C 3C018009 */  lui       $at, %hi(D_8008A680)
/* CC730 80136030 00220821 */  addu      $at, $at, $v0
/* CC734 80136034 8C22A680 */  lw        $v0, %lo(D_8008A680)($at)
/* CC738 80136038 00E0482D */  daddu     $t1, $a3, $zero
/* CC73C 8013603C AE020000 */  sw        $v0, ($s0)
/* CC740 80136040 86230018 */  lh        $v1, 0x18($s1)
/* CC744 80136044 00E0102D */  daddu     $v0, $a3, $zero
/* CC748 80136048 AE02018C */  sw        $v0, 0x18c($s0)
/* CC74C 8013604C AE030108 */  sw        $v1, 0x108($s0)
/* CC750 80136050 8CA20000 */  lw        $v0, ($a1)
/* CC754 80136054 0280302D */  daddu     $a2, $s4, $zero
/* CC758 80136058 AE020084 */  sw        $v0, 0x84($s0)
/* CC75C 8013605C 8CA20014 */  lw        $v0, 0x14($a1)
/* CC760 80136060 26030004 */  addiu     $v1, $s0, 4
/* CC764 80136064 AE020294 */  sw        $v0, 0x294($s0)
.L80136068:
/* CC768 80136068 84C201B4 */  lh        $v0, 0x1b4($a2)
/* CC76C 8013606C 10400011 */  beqz      $v0, .L801360B4
/* CC770 80136070 24840001 */   addiu    $a0, $a0, 1
/* CC774 80136074 00021140 */  sll       $v0, $v0, 5
/* CC778 80136078 00482821 */  addu      $a1, $v0, $t0
/* CC77C 8013607C 84A20004 */  lh        $v0, 4($a1)
/* CC780 80136080 000210C0 */  sll       $v0, $v0, 3
/* CC784 80136084 004A1021 */  addu      $v0, $v0, $t2
/* CC788 80136088 8C420000 */  lw        $v0, ($v0)
/* CC78C 8013608C AC620000 */  sw        $v0, ($v1)
/* CC790 80136090 84C201B4 */  lh        $v0, 0x1b4($a2)
/* CC794 80136094 AC69018C */  sw        $t1, 0x18c($v1)
/* CC798 80136098 AC620108 */  sw        $v0, 0x108($v1)
/* CC79C 8013609C 8CA20000 */  lw        $v0, ($a1)
/* CC7A0 801360A0 AC620084 */  sw        $v0, 0x84($v1)
/* CC7A4 801360A4 8CA20014 */  lw        $v0, 0x14($a1)
/* CC7A8 801360A8 24E70001 */  addiu     $a3, $a3, 1
/* CC7AC 801360AC AC620294 */  sw        $v0, 0x294($v1)
/* CC7B0 801360B0 24630004 */  addiu     $v1, $v1, 4
.L801360B4:
/* CC7B4 801360B4 2882000A */  slti      $v0, $a0, 0xa
/* CC7B8 801360B8 1440FFEB */  bnez      $v0, .L80136068
/* CC7BC 801360BC 24C60002 */   addiu    $a2, $a2, 2
/* CC7C0 801360C0 0200202D */  daddu     $a0, $s0, $zero
/* CC7C4 801360C4 24020002 */  addiu     $v0, $zero, 2
/* CC7C8 801360C8 AC820318 */  sw        $v0, 0x318($a0)
/* CC7CC 801360CC AC870324 */  sw        $a3, 0x324($a0)
/* CC7D0 801360D0 0C03D390 */  jal       func_800F4E40
/* CC7D4 801360D4 AC800328 */   sw       $zero, 0x328($a0)
/* CC7D8 801360D8 2404000C */  addiu     $a0, $zero, 0xc
/* CC7DC 801360DC 3C108014 */  lui       $s0, %hi(basic_hidden_window_update)
/* CC7E0 801360E0 26107574 */  addiu     $s0, $s0, %lo(basic_hidden_window_update)
/* CC7E4 801360E4 0C051F9F */  jal       set_window_update
/* CC7E8 801360E8 0200282D */   daddu    $a1, $s0, $zero
/* CC7EC 801360EC 24040011 */  addiu     $a0, $zero, 0x11
/* CC7F0 801360F0 0C051F9F */  jal       set_window_update
/* CC7F4 801360F4 0200282D */   daddu    $a1, $s0, $zero
/* CC7F8 801360F8 2402000B */  addiu     $v0, $zero, 0xb
/* CC7FC 801360FC 3C018015 */  lui       $at, %hi(D_801568E4)
/* CC800 80136100 AC2068E4 */  sw        $zero, %lo(D_801568E4)($at)
/* CC804 80136104 0804D8DF */  j         L8013637C_CCA7C
/* CC808 80136108 A222001A */   sb       $v0, 0x1a($s1)
glabel L8013610C_CC80C
/* CC80C 8013610C 3C038016 */  lui       $v1, %hi(gUIPanels)
/* CC810 80136110 24639D50 */  addiu     $v1, $v1, %lo(gUIPanels)
/* CC814 80136114 90620180 */  lbu       $v0, 0x180($v1)
/* CC818 80136118 30420008 */  andi      $v0, $v0, 8
/* CC81C 8013611C 14400097 */  bnez      $v0, L8013637C_CCA7C
/* CC820 80136120 00000000 */   nop
/* CC824 80136124 90620220 */  lbu       $v0, 0x220($v1)
/* CC828 80136128 30420008 */  andi      $v0, $v0, 8
/* CC82C 8013612C 14400093 */  bnez      $v0, L8013637C_CCA7C
/* CC830 80136130 00000000 */   nop
/* CC834 80136134 90620260 */  lbu       $v0, 0x260($v1)
/* CC838 80136138 30420008 */  andi      $v0, $v0, 8
/* CC83C 8013613C 1440008F */  bnez      $v0, L8013637C_CCA7C
/* CC840 80136140 2402000C */   addiu    $v0, $zero, 0xc
/* CC844 80136144 0804D8DF */  j         L8013637C_CCA7C
/* CC848 80136148 A222001A */   sb       $v0, 0x1a($s1)
glabel L8013614C_CC84C
/* CC84C 8013614C 3C158015 */  lui       $s5, %hi(D_801568E4)
/* CC850 80136150 26B568E4 */  addiu     $s5, $s5, %lo(D_801568E4)
/* CC854 80136154 8EA20000 */  lw        $v0, ($s5)
/* CC858 80136158 1440000A */  bnez      $v0, .L80136184
/* CC85C 8013615C 24420001 */   addiu    $v0, $v0, 1
/* CC860 80136160 8602032C */  lh        $v0, 0x32c($s0)
/* CC864 80136164 3C018015 */  lui       $at, %hi(D_801568E8)
/* CC868 80136168 AC2268E8 */  sw        $v0, %lo(D_801568E8)($at)
/* CC86C 8013616C 10400083 */  beqz      $v0, L8013637C_CCA7C
/* CC870 80136170 00000000 */   nop
/* CC874 80136174 0C03C4EC */  jal       func_800F13B0
/* CC878 80136178 00000000 */   nop
/* CC87C 8013617C 8EA20000 */  lw        $v0, ($s5)
/* CC880 80136180 24420001 */  addiu     $v0, $v0, 1
.L80136184:
/* CC884 80136184 AEA20000 */  sw        $v0, ($s5)
/* CC888 80136188 2842000F */  slti      $v0, $v0, 0xf
/* CC88C 8013618C 1440007B */  bnez      $v0, L8013637C_CCA7C
/* CC890 80136190 00000000 */   nop
/* CC894 80136194 0C03C54E */  jal       func_800F1538
/* CC898 80136198 00000000 */   nop
/* CC89C 8013619C 3C128015 */  lui       $s2, %hi(D_801568E8)
/* CC8A0 801361A0 265268E8 */  addiu     $s2, $s2, %lo(D_801568E8)
/* CC8A4 801361A4 8E430000 */  lw        $v1, ($s2)
/* CC8A8 801361A8 240200FF */  addiu     $v0, $zero, 0xff
/* CC8AC 801361AC 14620002 */  bne       $v1, $v0, .L801361B8
/* CC8B0 801361B0 24020001 */   addiu    $v0, $zero, 1
/* CC8B4 801361B4 AE420000 */  sw        $v0, ($s2)
.L801361B8:
/* CC8B8 801361B8 8E420000 */  lw        $v0, ($s2)
/* CC8BC 801361BC 3C048015 */  lui       $a0, %hi(D_801568E0)
/* CC8C0 801361C0 8C8468E0 */  lw        $a0, %lo(D_801568E0)($a0)
/* CC8C4 801361C4 2442FFFF */  addiu     $v0, $v0, -1
/* CC8C8 801361C8 00021080 */  sll       $v0, $v0, 2
/* CC8CC 801361CC 02021021 */  addu      $v0, $s0, $v0
/* CC8D0 801361D0 8C450000 */  lw        $a1, ($v0)
/* CC8D4 801361D4 8C420108 */  lw        $v0, 0x108($v0)
/* CC8D8 801361D8 3C108015 */  lui       $s0, %hi(D_801568EC)
/* CC8DC 801361DC 261068EC */  addiu     $s0, $s0, %lo(D_801568EC)
/* CC8E0 801361E0 0C0511FF */  jal       set_menu_icon_script
/* CC8E4 801361E4 AE020000 */   sw       $v0, ($s0)
/* CC8E8 801361E8 8E040000 */  lw        $a0, ($s0)
/* CC8EC 801361EC 8E650028 */  lw        $a1, 0x28($s3)
/* CC8F0 801361F0 8E670030 */  lw        $a3, 0x30($s3)
/* CC8F4 801361F4 24020003 */  addiu     $v0, $zero, 3
/* CC8F8 801361F8 AFA20010 */  sw        $v0, 0x10($sp)
/* CC8FC 801361FC 866200B0 */  lh        $v0, 0xb0($s3)
/* CC900 80136200 C662002C */  lwc1      $f2, 0x2c($s3)
/* CC904 80136204 44820000 */  mtc1      $v0, $f0
/* CC908 80136208 00000000 */  nop
/* CC90C 8013620C 46800020 */  cvt.s.w   $f0, $f0
/* CC910 80136210 46001080 */  add.s     $f2, $f2, $f0
/* CC914 80136214 44061000 */  mfc1      $a2, $f2
/* CC918 80136218 AFA00014 */  sw        $zero, 0x14($sp)
/* CC91C 8013621C 0C04C6B2 */  jal       make_item_entity_delayed
/* CC920 80136220 AFA00018 */   sw       $zero, 0x18($sp)
/* CC924 80136224 0C04C3D6 */  jal       get_item_entity
/* CC928 80136228 0040202D */   daddu    $a0, $v0, $zero
/* CC92C 8013622C 2403FFFF */  addiu     $v1, $zero, -1
/* CC930 80136230 A043001D */  sb        $v1, 0x1d($v0)
/* CC934 80136234 8E430000 */  lw        $v1, ($s2)
/* CC938 80136238 28620002 */  slti      $v0, $v1, 2
/* CC93C 8013623C 1440000A */  bnez      $v0, .L80136268
/* CC940 80136240 3C040006 */   lui      $a0, 6
/* CC944 80136244 2462FFFE */  addiu     $v0, $v1, -2
/* CC948 80136248 00021040 */  sll       $v0, $v0, 1
/* CC94C 8013624C 02821021 */  addu      $v0, $s4, $v0
/* CC950 80136250 0C039DB3 */  jal       sort_items
/* CC954 80136254 A44001B4 */   sh       $zero, 0x1b4($v0)
/* CC958 80136258 86240018 */  lh        $a0, 0x18($s1)
/* CC95C 8013625C 0C039D5D */  jal       add_item
/* CC960 80136260 00000000 */   nop
/* CC964 80136264 3C040006 */  lui       $a0, 6
.L80136268:
/* CC968 80136268 0C037FDE */  jal       func_800DFF78
/* CC96C 8013626C 3484000C */   ori      $a0, $a0, 0xc
/* CC970 80136270 0C04D8E8 */  jal       func_801363A0
/* CC974 80136274 0220202D */   daddu    $a0, $s1, $zero
/* CC978 80136278 3C058014 */  lui       $a1, %hi(basic_window_update)
/* CC97C 8013627C 24A57474 */  addiu     $a1, $a1, %lo(basic_window_update)
/* CC980 80136280 0C051F9F */  jal       set_window_update
/* CC984 80136284 2404000C */   addiu    $a0, $zero, 0xc
/* CC988 80136288 24020032 */  addiu     $v0, $zero, 0x32
/* CC98C 8013628C AEA20000 */  sw        $v0, ($s5)
/* CC990 80136290 2402000D */  addiu     $v0, $zero, 0xd
/* CC994 80136294 0804D8DF */  j         L8013637C_CCA7C
/* CC998 80136298 A222001A */   sb       $v0, 0x1a($s1)
glabel L8013629C_CC99C
/* CC99C 8013629C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* CC9A0 801362A0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* CC9A4 801362A4 8C420010 */  lw        $v0, 0x10($v0)
/* CC9A8 801362A8 30428000 */  andi      $v0, $v0, 0x8000
/* CC9AC 801362AC 10400033 */  beqz      $v0, L8013637C_CCA7C
/* CC9B0 801362B0 00000000 */   nop
/* CC9B4 801362B4 3C058014 */  lui       $a1, %hi(basic_hidden_window_update)
/* CC9B8 801362B8 24A57574 */  addiu     $a1, $a1, %lo(basic_hidden_window_update)
/* CC9BC 801362BC 0C051F9F */  jal       set_window_update
/* CC9C0 801362C0 2404000C */   addiu    $a0, $zero, 0xc
/* CC9C4 801362C4 2402000E */  addiu     $v0, $zero, 0xe
/* CC9C8 801362C8 0804D8DF */  j         L8013637C_CCA7C
/* CC9CC 801362CC A222001A */   sb       $v0, 0x1a($s1)
glabel L801362D0_CC9D0
/* CC9D0 801362D0 3C038016 */  lui       $v1, %hi(gUIPanels)
/* CC9D4 801362D4 24639D50 */  addiu     $v1, $v1, %lo(gUIPanels)
/* CC9D8 801362D8 90620180 */  lbu       $v0, 0x180($v1)
/* CC9DC 801362DC 30420008 */  andi      $v0, $v0, 8
/* CC9E0 801362E0 14400026 */  bnez      $v0, L8013637C_CCA7C
/* CC9E4 801362E4 00000000 */   nop
/* CC9E8 801362E8 90620220 */  lbu       $v0, 0x220($v1)
/* CC9EC 801362EC 30420008 */  andi      $v0, $v0, 8
/* CC9F0 801362F0 14400022 */  bnez      $v0, L8013637C_CCA7C
/* CC9F4 801362F4 00000000 */   nop
/* CC9F8 801362F8 90620260 */  lbu       $v0, 0x260($v1)
/* CC9FC 801362FC 30420008 */  andi      $v0, $v0, 8
/* CCA00 80136300 1440001E */  bnez      $v0, L8013637C_CCA7C
/* CCA04 80136304 2402000F */   addiu    $v0, $zero, 0xf
/* CCA08 80136308 0804D8DF */  j         L8013637C_CCA7C
/* CCA0C 8013630C A222001A */   sb       $v0, 0x1a($s1)
glabel L80136310_CCA10
/* CCA10 80136310 3C040001 */  lui       $a0, 1
/* CCA14 80136314 0C037FDE */  jal       func_800DFF78
/* CCA18 80136318 34840002 */   ori      $a0, $a0, 2
/* CCA1C 8013631C 0C009C22 */  jal       func_80027088
/* CCA20 80136320 0000202D */   daddu    $a0, $zero, $zero
/* CCA24 80136324 0C038069 */  jal       enable_player_input
/* CCA28 80136328 00000000 */   nop
/* CCA2C 8013632C 0C03BD80 */  jal       func_800EF600
/* CCA30 80136330 00000000 */   nop
/* CCA34 80136334 3C02800A */  lui       $v0, %hi(D_8009A650)
/* CCA38 80136338 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* CCA3C 8013633C 2405FFBF */  addiu     $a1, $zero, -0x41
/* CCA40 80136340 8C430000 */  lw        $v1, ($v0)
/* CCA44 80136344 3C048015 */  lui       $a0, %hi(D_801568E0)
/* CCA48 80136348 8C8468E0 */  lw        $a0, %lo(D_801568E0)($a0)
/* CCA4C 8013634C 00651824 */  and       $v1, $v1, $a1
/* CCA50 80136350 AC430000 */  sw        $v1, ($v0)
.L80136354:
/* CCA54 80136354 0C05123D */  jal       free_icon
/* CCA58 80136358 00000000 */   nop
/* CCA5C 8013635C 0C04CE4C */  jal       remove_item_entity_by_reference
/* CCA60 80136360 0220202D */   daddu    $a0, $s1, $zero
/* CCA64 80136364 0C039DB3 */  jal       sort_items
/* CCA68 80136368 00000000 */   nop
/* CCA6C 8013636C 0C03A6CC */  jal       decrement_status_menu_disabled
/* CCA70 80136370 00000000 */   nop
/* CCA74 80136374 3C018015 */  lui       $at, %hi(D_801565A4)
/* CCA78 80136378 A42065A4 */  sh        $zero, %lo(D_801565A4)($at)
glabel L8013637C_CCA7C
/* CCA7C 8013637C 8FBF0038 */  lw        $ra, 0x38($sp)
/* CCA80 80136380 8FB50034 */  lw        $s5, 0x34($sp)
/* CCA84 80136384 8FB40030 */  lw        $s4, 0x30($sp)
/* CCA88 80136388 8FB3002C */  lw        $s3, 0x2c($sp)
/* CCA8C 8013638C 8FB20028 */  lw        $s2, 0x28($sp)
/* CCA90 80136390 8FB10024 */  lw        $s1, 0x24($sp)
/* CCA94 80136394 8FB00020 */  lw        $s0, 0x20($sp)
/* CCA98 80136398 03E00008 */  jr        $ra
/* CCA9C 8013639C 27BD0040 */   addiu    $sp, $sp, 0x40
