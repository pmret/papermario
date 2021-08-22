.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802AB9F0
.word L802A5054_419DE4, L802A4F74_419D04, L802A4AA8_419838, L802A4D4C_419ADC, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A505C_419DEC, L802A5090_419E20, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A50A0_419E30, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A50E0_419E70, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A5270_41A000, L802A510C_419E9C, L802A5130_419EC0, L802A51F0_419F80, 0

.section .text

glabel func_802A4A54
/* 4197E4 802A4A54 3C02802B */  lui       $v0, %hi(D_802AD604)
/* 4197E8 802A4A58 9042D604 */  lbu       $v0, %lo(D_802AD604)($v0)
/* 4197EC 802A4A5C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 4197F0 802A4A60 AFB20030 */  sw        $s2, 0x30($sp)
/* 4197F4 802A4A64 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 4197F8 802A4A68 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 4197FC 802A4A6C AFBF0038 */  sw        $ra, 0x38($sp)
/* 419800 802A4A70 AFB30034 */  sw        $s3, 0x34($sp)
/* 419804 802A4A74 AFB1002C */  sw        $s1, 0x2c($sp)
/* 419808 802A4A78 24420002 */  addiu     $v0, $v0, 2
/* 41980C 802A4A7C 00021600 */  sll       $v0, $v0, 0x18
/* 419810 802A4A80 00021E03 */  sra       $v1, $v0, 0x18
/* 419814 802A4A84 2C62002D */  sltiu     $v0, $v1, 0x2d
/* 419818 802A4A88 104001F9 */  beqz      $v0, L802A5270_41A000
/* 41981C 802A4A8C AFB00028 */   sw       $s0, 0x28($sp)
/* 419820 802A4A90 00031080 */  sll       $v0, $v1, 2
/* 419824 802A4A94 3C01802B */  lui       $at, %hi(jtbl_802AB9F0)
/* 419828 802A4A98 00220821 */  addu      $at, $at, $v0
/* 41982C 802A4A9C 8C22B9F0 */  lw        $v0, %lo(jtbl_802AB9F0)($at)
/* 419830 802A4AA0 00400008 */  jr        $v0
/* 419834 802A4AA4 00000000 */   nop
glabel L802A4AA8_419838
/* 419838 802A4AA8 3C05802B */  lui       $a1, %hi(D_802AD608)
/* 41983C 802A4AAC 80A5D608 */  lb        $a1, %lo(D_802AD608)($a1)
/* 419840 802A4AB0 3C04802B */  lui       $a0, %hi(D_802AD605)
/* 419844 802A4AB4 8084D605 */  lb        $a0, %lo(D_802AD605)($a0)
/* 419848 802A4AB8 24020014 */  addiu     $v0, $zero, 0x14
/* 41984C 802A4ABC 3C01802B */  lui       $at, %hi(D_802AD63C)
/* 419850 802A4AC0 A422D63C */  sh        $v0, %lo(D_802AD63C)($at)
/* 419854 802A4AC4 24020044 */  addiu     $v0, $zero, 0x44
/* 419858 802A4AC8 3C01802B */  lui       $at, %hi(D_802AD63E)
/* 41985C 802A4ACC A422D63E */  sh        $v0, %lo(D_802AD63E)($at)
/* 419860 802A4AD0 00051823 */  negu      $v1, $a1
/* 419864 802A4AD4 00031040 */  sll       $v0, $v1, 1
/* 419868 802A4AD8 00431021 */  addu      $v0, $v0, $v1
/* 41986C 802A4ADC 00021080 */  sll       $v0, $v0, 2
/* 419870 802A4AE0 00431021 */  addu      $v0, $v0, $v1
/* 419874 802A4AE4 00852023 */  subu      $a0, $a0, $a1
/* 419878 802A4AE8 3C01802B */  lui       $at, %hi(D_802AD60C)
/* 41987C 802A4AEC A422D60C */  sh        $v0, %lo(D_802AD60C)($at)
/* 419880 802A4AF0 00041040 */  sll       $v0, $a0, 1
/* 419884 802A4AF4 00441021 */  addu      $v0, $v0, $a0
/* 419888 802A4AF8 00021080 */  sll       $v0, $v0, 2
/* 41988C 802A4AFC 3C03802B */  lui       $v1, %hi(D_802AD66C)
/* 419890 802A4B00 8C63D66C */  lw        $v1, %lo(D_802AD66C)($v1)
/* 419894 802A4B04 00441021 */  addu      $v0, $v0, $a0
/* 419898 802A4B08 3C01802B */  lui       $at, %hi(D_802AD60E)
/* 41989C 802A4B0C A422D60E */  sh        $v0, %lo(D_802AD60E)($at)
/* 4198A0 802A4B10 18600017 */  blez      $v1, .L802A4B70
/* 4198A4 802A4B14 0000882D */   daddu    $s1, $zero, $zero
/* 4198A8 802A4B18 3C13802B */  lui       $s3, %hi(D_802AD628)
/* 4198AC 802A4B1C 2673D628 */  addiu     $s3, $s3, %lo(D_802AD628)
/* 4198B0 802A4B20 3C10802B */  lui       $s0, %hi(D_802AD640)
/* 4198B4 802A4B24 2610D640 */  addiu     $s0, $s0, %lo(D_802AD640)
.L802A4B28:
/* 4198B8 802A4B28 8E040000 */  lw        $a0, ($s0)
/* 4198BC 802A4B2C 26100004 */  addiu     $s0, $s0, 4
/* 4198C0 802A4B30 0C050529 */  jal       create_hud_element
/* 4198C4 802A4B34 26310001 */   addiu    $s1, $s1, 1
/* 4198C8 802A4B38 0040902D */  daddu     $s2, $v0, $zero
/* 4198CC 802A4B3C 3C053EE6 */  lui       $a1, 0x3ee6
/* 4198D0 802A4B40 34A56666 */  ori       $a1, $a1, 0x6666
/* 4198D4 802A4B44 0240202D */  daddu     $a0, $s2, $zero
/* 4198D8 802A4B48 0C051308 */  jal       set_hud_element_scale
/* 4198DC 802A4B4C AE720000 */   sw       $s2, ($s3)
/* 4198E0 802A4B50 0240202D */  daddu     $a0, $s2, $zero
/* 4198E4 802A4B54 0C051280 */  jal       set_hud_element_flags
/* 4198E8 802A4B58 34058080 */   ori      $a1, $zero, 0x8080
/* 4198EC 802A4B5C 3C02802B */  lui       $v0, %hi(D_802AD66C)
/* 4198F0 802A4B60 8C42D66C */  lw        $v0, %lo(D_802AD66C)($v0)
/* 4198F4 802A4B64 0222102A */  slt       $v0, $s1, $v0
/* 4198F8 802A4B68 1440FFEF */  bnez      $v0, .L802A4B28
/* 4198FC 802A4B6C 26730004 */   addiu    $s3, $s3, 4
.L802A4B70:
/* 419900 802A4B70 3C048010 */  lui       $a0, %hi(D_80104A28)
/* 419904 802A4B74 24844A28 */  addiu     $a0, $a0, %lo(D_80104A28)
/* 419908 802A4B78 0C050529 */  jal       create_hud_element
/* 41990C 802A4B7C 00000000 */   nop
/* 419910 802A4B80 0040902D */  daddu     $s2, $v0, $zero
/* 419914 802A4B84 0240202D */  daddu     $a0, $s2, $zero
/* 419918 802A4B88 3C052000 */  lui       $a1, 0x2000
/* 41991C 802A4B8C 3C01802B */  lui       $at, %hi(D_802AD618)
/* 419920 802A4B90 AC32D618 */  sw        $s2, %lo(D_802AD618)($at)
/* 419924 802A4B94 0C051280 */  jal       set_hud_element_flags
/* 419928 802A4B98 34A50080 */   ori      $a1, $a1, 0x80
/* 41992C 802A4B9C 3C10802B */  lui       $s0, %hi(D_802AD63C)
/* 419930 802A4BA0 2610D63C */  addiu     $s0, $s0, %lo(D_802AD63C)
/* 419934 802A4BA4 3C11802B */  lui       $s1, %hi(D_802AD63E)
/* 419938 802A4BA8 2631D63E */  addiu     $s1, $s1, %lo(D_802AD63E)
/* 41993C 802A4BAC 86050000 */  lh        $a1, ($s0)
/* 419940 802A4BB0 86260000 */  lh        $a2, ($s1)
/* 419944 802A4BB4 0C051261 */  jal       set_hud_element_render_pos
/* 419948 802A4BB8 0240202D */   daddu    $a0, $s2, $zero
/* 41994C 802A4BBC 3C048010 */  lui       $a0, %hi(D_801077E4)
/* 419950 802A4BC0 248477E4 */  addiu     $a0, $a0, %lo(D_801077E4)
/* 419954 802A4BC4 0C050529 */  jal       create_hud_element
/* 419958 802A4BC8 00000000 */   nop
/* 41995C 802A4BCC 0040902D */  daddu     $s2, $v0, $zero
/* 419960 802A4BD0 0240202D */  daddu     $a0, $s2, $zero
/* 419964 802A4BD4 3C052000 */  lui       $a1, 0x2000
/* 419968 802A4BD8 3C01802B */  lui       $at, %hi(D_802AD61C)
/* 41996C 802A4BDC AC32D61C */  sw        $s2, %lo(D_802AD61C)($at)
/* 419970 802A4BE0 0C051280 */  jal       set_hud_element_flags
/* 419974 802A4BE4 34A50080 */   ori      $a1, $a1, 0x80
/* 419978 802A4BE8 0240202D */  daddu     $a0, $s2, $zero
/* 41997C 802A4BEC 86050000 */  lh        $a1, ($s0)
/* 419980 802A4BF0 86260000 */  lh        $a2, ($s1)
/* 419984 802A4BF4 24A50027 */  addiu     $a1, $a1, 0x27
/* 419988 802A4BF8 0C051261 */  jal       set_hud_element_render_pos
/* 41998C 802A4BFC 24C6FFF9 */   addiu    $a2, $a2, -7
/* 419990 802A4C00 3C048010 */  lui       $a0, %hi(D_80107798)
/* 419994 802A4C04 24847798 */  addiu     $a0, $a0, %lo(D_80107798)
/* 419998 802A4C08 0C050529 */  jal       create_hud_element
/* 41999C 802A4C0C 00000000 */   nop
/* 4199A0 802A4C10 0040902D */  daddu     $s2, $v0, $zero
/* 4199A4 802A4C14 0240202D */  daddu     $a0, $s2, $zero
/* 4199A8 802A4C18 3C052000 */  lui       $a1, 0x2000
/* 4199AC 802A4C1C 3C01802B */  lui       $at, %hi(D_802AD620)
/* 4199B0 802A4C20 AC32D620 */  sw        $s2, %lo(D_802AD620)($at)
/* 4199B4 802A4C24 0C051280 */  jal       set_hud_element_flags
/* 4199B8 802A4C28 34A50080 */   ori      $a1, $a1, 0x80
/* 4199BC 802A4C2C 0240202D */  daddu     $a0, $s2, $zero
/* 4199C0 802A4C30 86050000 */  lh        $a1, ($s0)
/* 4199C4 802A4C34 86260000 */  lh        $a2, ($s1)
/* 4199C8 802A4C38 24A50027 */  addiu     $a1, $a1, 0x27
/* 4199CC 802A4C3C 0C051261 */  jal       set_hud_element_render_pos
/* 4199D0 802A4C40 24C6004E */   addiu    $a2, $a2, 0x4e
/* 4199D4 802A4C44 24040006 */  addiu     $a0, $zero, 6
/* 4199D8 802A4C48 24070090 */  addiu     $a3, $zero, 0x90
/* 4199DC 802A4C4C 86130000 */  lh        $s3, ($s0)
/* 4199E0 802A4C50 2402000A */  addiu     $v0, $zero, 0xa
/* 4199E4 802A4C54 3C01802B */  lui       $at, %hi(D_802AD614)
/* 4199E8 802A4C58 A022D614 */  sb        $v0, %lo(D_802AD614)($at)
/* 4199EC 802A4C5C 3C02802A */  lui       $v0, %hi(func_802A5290)
/* 4199F0 802A4C60 24425290 */  addiu     $v0, $v0, %lo(func_802A5290)
/* 4199F4 802A4C64 2412FFFF */  addiu     $s2, $zero, -1
/* 4199F8 802A4C68 AFA00014 */  sw        $zero, 0x14($sp)
/* 4199FC 802A4C6C AFA20018 */  sw        $v0, 0x18($sp)
/* 419A00 802A4C70 AFA0001C */  sw        $zero, 0x1c($sp)
/* 419A04 802A4C74 AFB20020 */  sw        $s2, 0x20($sp)
/* 419A08 802A4C78 86300000 */  lh        $s0, ($s1)
/* 419A0C 802A4C7C 3C03802B */  lui       $v1, %hi(D_802AD60A)
/* 419A10 802A4C80 8063D60A */  lb        $v1, %lo(D_802AD60A)($v1)
/* 419A14 802A4C84 0260282D */  daddu     $a1, $s3, $zero
/* 419A18 802A4C88 0200302D */  daddu     $a2, $s0, $zero
/* 419A1C 802A4C8C 00031040 */  sll       $v0, $v1, 1
/* 419A20 802A4C90 00431021 */  addu      $v0, $v0, $v1
/* 419A24 802A4C94 00021080 */  sll       $v0, $v0, 2
/* 419A28 802A4C98 00431021 */  addu      $v0, $v0, $v1
/* 419A2C 802A4C9C 2442001A */  addiu     $v0, $v0, 0x1a
/* 419A30 802A4CA0 0C051F32 */  jal       set_window_properties
/* 419A34 802A4CA4 AFA20010 */   sw       $v0, 0x10($sp)
/* 419A38 802A4CA8 24040007 */  addiu     $a0, $zero, 7
/* 419A3C 802A4CAC 26650012 */  addiu     $a1, $s3, 0x12
/* 419A40 802A4CB0 2606FFFA */  addiu     $a2, $s0, -6
/* 419A44 802A4CB4 2407006C */  addiu     $a3, $zero, 0x6c
/* 419A48 802A4CB8 24020010 */  addiu     $v0, $zero, 0x10
/* 419A4C 802A4CBC 24100001 */  addiu     $s0, $zero, 1
/* 419A50 802A4CC0 AFA20010 */  sw        $v0, 0x10($sp)
/* 419A54 802A4CC4 3C02802A */  lui       $v0, %hi(func_802A56F8)
/* 419A58 802A4CC8 244256F8 */  addiu     $v0, $v0, %lo(func_802A56F8)
/* 419A5C 802A4CCC AFB00014 */  sw        $s0, 0x14($sp)
/* 419A60 802A4CD0 AFA20018 */  sw        $v0, 0x18($sp)
/* 419A64 802A4CD4 AFA0001C */  sw        $zero, 0x1c($sp)
/* 419A68 802A4CD8 0C051F32 */  jal       set_window_properties
/* 419A6C 802A4CDC AFB20020 */   sw       $s2, 0x20($sp)
/* 419A70 802A4CE0 24130014 */  addiu     $s3, $zero, 0x14
/* 419A74 802A4CE4 24040008 */  addiu     $a0, $zero, 8
/* 419A78 802A4CE8 0260282D */  daddu     $a1, $s3, $zero
/* 419A7C 802A4CEC 240600BA */  addiu     $a2, $zero, 0xba
/* 419A80 802A4CF0 24070118 */  addiu     $a3, $zero, 0x118
/* 419A84 802A4CF4 24020020 */  addiu     $v0, $zero, 0x20
/* 419A88 802A4CF8 AFA20010 */  sw        $v0, 0x10($sp)
/* 419A8C 802A4CFC 3C02802A */  lui       $v0, %hi(func_802A5738)
/* 419A90 802A4D00 24425738 */  addiu     $v0, $v0, %lo(func_802A5738)
/* 419A94 802A4D04 AFB30014 */  sw        $s3, 0x14($sp)
/* 419A98 802A4D08 AFA20018 */  sw        $v0, 0x18($sp)
/* 419A9C 802A4D0C AFA0001C */  sw        $zero, 0x1c($sp)
/* 419AA0 802A4D10 0C051F32 */  jal       set_window_properties
/* 419AA4 802A4D14 AFB20020 */   sw       $s2, 0x20($sp)
/* 419AA8 802A4D18 24040006 */  addiu     $a0, $zero, 6
/* 419AAC 802A4D1C 0C051F9F */  jal       set_window_update
/* 419AB0 802A4D20 0200282D */   daddu    $a1, $s0, $zero
/* 419AB4 802A4D24 24040007 */  addiu     $a0, $zero, 7
/* 419AB8 802A4D28 0C051F9F */  jal       set_window_update
/* 419ABC 802A4D2C 0200282D */   daddu    $a1, $s0, $zero
/* 419AC0 802A4D30 24040008 */  addiu     $a0, $zero, 8
/* 419AC4 802A4D34 0C051F9F */  jal       set_window_update
/* 419AC8 802A4D38 0200282D */   daddu    $a1, $s0, $zero
/* 419ACC 802A4D3C 3C01802B */  lui       $at, %hi(D_802AD604)
/* 419AD0 802A4D40 A030D604 */  sb        $s0, %lo(D_802AD604)($at)
/* 419AD4 802A4D44 080A949D */  j         .L802A5274
/* 419AD8 802A4D48 0000102D */   daddu    $v0, $zero, $zero
glabel L802A4D4C_419ADC
/* 419ADC 802A4D4C 3C02802B */  lui       $v0, %hi(D_802AD607)
/* 419AE0 802A4D50 8042D607 */  lb        $v0, %lo(D_802AD607)($v0)
/* 419AE4 802A4D54 14400147 */  bnez      $v0, .L802A5274
/* 419AE8 802A4D58 0000102D */   daddu    $v0, $zero, $zero
/* 419AEC 802A4D5C 3C04802B */  lui       $a0, %hi(D_802AD605)
/* 419AF0 802A4D60 2484D605 */  addiu     $a0, $a0, %lo(D_802AD605)
/* 419AF4 802A4D64 3C050001 */  lui       $a1, 1
/* 419AF8 802A4D68 8E420218 */  lw        $v0, 0x218($s2)
/* 419AFC 802A4D6C 90830000 */  lbu       $v1, ($a0)
/* 419B00 802A4D70 00451024 */  and       $v0, $v0, $a1
/* 419B04 802A4D74 3C01802B */  lui       $at, %hi(D_802AD606)
/* 419B08 802A4D78 A023D606 */  sb        $v1, %lo(D_802AD606)($at)
/* 419B0C 802A4D7C 10400008 */  beqz      $v0, .L802A4DA0
/* 419B10 802A4D80 00031600 */   sll      $v0, $v1, 0x18
/* 419B14 802A4D84 1C400005 */  bgtz      $v0, .L802A4D9C
/* 419B18 802A4D88 2462FFFF */   addiu    $v0, $v1, -1
/* 419B1C 802A4D8C 8E420214 */  lw        $v0, 0x214($s2)
/* 419B20 802A4D90 00451024 */  and       $v0, $v0, $a1
/* 419B24 802A4D94 10400002 */  beqz      $v0, .L802A4DA0
/* 419B28 802A4D98 2462FFFF */   addiu    $v0, $v1, -1
.L802A4D9C:
/* 419B2C 802A4D9C A0820000 */  sb        $v0, ($a0)
.L802A4DA0:
/* 419B30 802A4DA0 8E420218 */  lw        $v0, 0x218($s2)
/* 419B34 802A4DA4 3C060002 */  lui       $a2, 2
/* 419B38 802A4DA8 00461024 */  and       $v0, $v0, $a2
/* 419B3C 802A4DAC 10400010 */  beqz      $v0, .L802A4DF0
/* 419B40 802A4DB0 00000000 */   nop
/* 419B44 802A4DB4 3C05802B */  lui       $a1, %hi(D_802AD605)
/* 419B48 802A4DB8 24A5D605 */  addiu     $a1, $a1, %lo(D_802AD605)
/* 419B4C 802A4DBC 3C02802B */  lui       $v0, %hi(D_802AD66C)
/* 419B50 802A4DC0 8C42D66C */  lw        $v0, %lo(D_802AD66C)($v0)
/* 419B54 802A4DC4 80A30000 */  lb        $v1, ($a1)
/* 419B58 802A4DC8 90A40000 */  lbu       $a0, ($a1)
/* 419B5C 802A4DCC 2442FFFF */  addiu     $v0, $v0, -1
/* 419B60 802A4DD0 0062182A */  slt       $v1, $v1, $v0
/* 419B64 802A4DD4 14600005 */  bnez      $v1, .L802A4DEC
/* 419B68 802A4DD8 24820001 */   addiu    $v0, $a0, 1
/* 419B6C 802A4DDC 8E420214 */  lw        $v0, 0x214($s2)
/* 419B70 802A4DE0 00461024 */  and       $v0, $v0, $a2
/* 419B74 802A4DE4 10400002 */  beqz      $v0, .L802A4DF0
/* 419B78 802A4DE8 24820001 */   addiu    $v0, $a0, 1
.L802A4DEC:
/* 419B7C 802A4DEC A0A20000 */  sb        $v0, ($a1)
.L802A4DF0:
/* 419B80 802A4DF0 3C10802B */  lui       $s0, %hi(D_802AD605)
/* 419B84 802A4DF4 2610D605 */  addiu     $s0, $s0, %lo(D_802AD605)
/* 419B88 802A4DF8 82020000 */  lb        $v0, ($s0)
/* 419B8C 802A4DFC 04410005 */  bgez      $v0, .L802A4E14
/* 419B90 802A4E00 00000000 */   nop
/* 419B94 802A4E04 3C02802B */  lui       $v0, %hi(D_802AD66F)
/* 419B98 802A4E08 9042D66F */  lbu       $v0, %lo(D_802AD66F)($v0)
/* 419B9C 802A4E0C 2442FFFF */  addiu     $v0, $v0, -1
/* 419BA0 802A4E10 A2020000 */  sb        $v0, ($s0)
.L802A4E14:
/* 419BA4 802A4E14 3C11802B */  lui       $s1, %hi(D_802AD66C)
/* 419BA8 802A4E18 2631D66C */  addiu     $s1, $s1, %lo(D_802AD66C)
/* 419BAC 802A4E1C 8E220000 */  lw        $v0, ($s1)
/* 419BB0 802A4E20 82030000 */  lb        $v1, ($s0)
/* 419BB4 802A4E24 2442FFFF */  addiu     $v0, $v0, -1
/* 419BB8 802A4E28 0043102A */  slt       $v0, $v0, $v1
/* 419BBC 802A4E2C 54400001 */  bnel      $v0, $zero, .L802A4E34
/* 419BC0 802A4E30 A2000000 */   sb       $zero, ($s0)
.L802A4E34:
/* 419BC4 802A4E34 3C03802B */  lui       $v1, %hi(D_802AD606)
/* 419BC8 802A4E38 8063D606 */  lb        $v1, %lo(D_802AD606)($v1)
/* 419BCC 802A4E3C 82020000 */  lb        $v0, ($s0)
/* 419BD0 802A4E40 10620009 */  beq       $v1, $v0, .L802A4E68
/* 419BD4 802A4E44 00031080 */   sll      $v0, $v1, 2
/* 419BD8 802A4E48 3C04802B */  lui       $a0, %hi(D_802AD628)
/* 419BDC 802A4E4C 00822021 */  addu      $a0, $a0, $v0
/* 419BE0 802A4E50 8C84D628 */  lw        $a0, %lo(D_802AD628)($a0)
/* 419BE4 802A4E54 3C053EE6 */  lui       $a1, 0x3ee6
/* 419BE8 802A4E58 0C051308 */  jal       set_hud_element_scale
/* 419BEC 802A4E5C 34A56666 */   ori      $a1, $a1, 0x6666
/* 419BF0 802A4E60 0C05272D */  jal       sfx_play_sound
/* 419BF4 802A4E64 240400C7 */   addiu    $a0, $zero, 0xc7
.L802A4E68:
/* 419BF8 802A4E68 3C04802B */  lui       $a0, %hi(D_802AD608)
/* 419BFC 802A4E6C 2484D608 */  addiu     $a0, $a0, %lo(D_802AD608)
/* 419C00 802A4E70 82050000 */  lb        $a1, ($s0)
/* 419C04 802A4E74 80820000 */  lb        $v0, ($a0)
/* 419C08 802A4E78 92030000 */  lbu       $v1, ($s0)
/* 419C0C 802A4E7C 00A2102A */  slt       $v0, $a1, $v0
/* 419C10 802A4E80 54400001 */  bnel      $v0, $zero, .L802A4E88
/* 419C14 802A4E84 A0830000 */   sb       $v1, ($a0)
.L802A4E88:
/* 419C18 802A4E88 3C06802B */  lui       $a2, %hi(D_802AD609)
/* 419C1C 802A4E8C 24C6D609 */  addiu     $a2, $a2, %lo(D_802AD609)
/* 419C20 802A4E90 80C20000 */  lb        $v0, ($a2)
/* 419C24 802A4E94 00A2102A */  slt       $v0, $a1, $v0
/* 419C28 802A4E98 14400006 */  bnez      $v0, .L802A4EB4
/* 419C2C 802A4E9C 00000000 */   nop
/* 419C30 802A4EA0 3C02802B */  lui       $v0, %hi(D_802AD60A)
/* 419C34 802A4EA4 9042D60A */  lbu       $v0, %lo(D_802AD60A)($v0)
/* 419C38 802A4EA8 2442FFFF */  addiu     $v0, $v0, -1
/* 419C3C 802A4EAC 00621023 */  subu      $v0, $v1, $v0
/* 419C40 802A4EB0 A0820000 */  sb        $v0, ($a0)
.L802A4EB4:
/* 419C44 802A4EB4 90820000 */  lbu       $v0, ($a0)
/* 419C48 802A4EB8 24420006 */  addiu     $v0, $v0, 6
/* 419C4C 802A4EBC A0C20000 */  sb        $v0, ($a2)
/* 419C50 802A4EC0 00021600 */  sll       $v0, $v0, 0x18
/* 419C54 802A4EC4 8E230000 */  lw        $v1, ($s1)
/* 419C58 802A4EC8 00021603 */  sra       $v0, $v0, 0x18
/* 419C5C 802A4ECC 0062182A */  slt       $v1, $v1, $v0
/* 419C60 802A4ED0 10600003 */  beqz      $v1, .L802A4EE0
/* 419C64 802A4ED4 00000000 */   nop
/* 419C68 802A4ED8 92220003 */  lbu       $v0, 3($s1)
/* 419C6C 802A4EDC A0C20000 */  sb        $v0, ($a2)
.L802A4EE0:
/* 419C70 802A4EE0 8E430214 */  lw        $v1, 0x214($s2)
/* 419C74 802A4EE4 30628000 */  andi      $v0, $v1, 0x8000
/* 419C78 802A4EE8 10400019 */  beqz      $v0, .L802A4F50
/* 419C7C 802A4EEC 00051080 */   sll      $v0, $a1, 2
/* 419C80 802A4EF0 3C03802B */  lui       $v1, %hi(D_802AD690)
/* 419C84 802A4EF4 00621821 */  addu      $v1, $v1, $v0
/* 419C88 802A4EF8 8C63D690 */  lw        $v1, %lo(D_802AD690)($v1)
/* 419C8C 802A4EFC 24020001 */  addiu     $v0, $zero, 1
/* 419C90 802A4F00 14620005 */  bne       $v1, $v0, .L802A4F18
/* 419C94 802A4F04 00000000 */   nop
/* 419C98 802A4F08 0C05272D */  jal       sfx_play_sound
/* 419C9C 802A4F0C 240400C9 */   addiu    $a0, $zero, 0xc9
/* 419CA0 802A4F10 080A949A */  j         .L802A5268
/* 419CA4 802A4F14 2402FFFF */   addiu    $v0, $zero, -1
.L802A4F18:
/* 419CA8 802A4F18 0C05272D */  jal       sfx_play_sound
/* 419CAC 802A4F1C 2404021D */   addiu    $a0, $zero, 0x21d
/* 419CB0 802A4F20 82020000 */  lb        $v0, ($s0)
/* 419CB4 802A4F24 00021080 */  sll       $v0, $v0, 2
/* 419CB8 802A4F28 3C03802B */  lui       $v1, %hi(D_802AD6AA)
/* 419CBC 802A4F2C 00621821 */  addu      $v1, $v1, $v0
/* 419CC0 802A4F30 9463D6AA */  lhu       $v1, %lo(D_802AD6AA)($v1)
/* 419CC4 802A4F34 24020028 */  addiu     $v0, $zero, 0x28
/* 419CC8 802A4F38 3C01802B */  lui       $at, %hi(D_802AD604)
/* 419CCC 802A4F3C A022D604 */  sb        $v0, %lo(D_802AD604)($at)
/* 419CD0 802A4F40 3C01802B */  lui       $at, %hi(D_802AD610)
/* 419CD4 802A4F44 A423D610 */  sh        $v1, %lo(D_802AD610)($at)
/* 419CD8 802A4F48 080A949D */  j         .L802A5274
/* 419CDC 802A4F4C 0000102D */   daddu    $v0, $zero, $zero
.L802A4F50:
/* 419CE0 802A4F50 30624000 */  andi      $v0, $v1, 0x4000
/* 419CE4 802A4F54 104000C7 */  beqz      $v0, .L802A5274
/* 419CE8 802A4F58 0000102D */   daddu    $v0, $zero, $zero
/* 419CEC 802A4F5C 0C05272D */  jal       sfx_play_sound
/* 419CF0 802A4F60 240400CA */   addiu    $a0, $zero, 0xca
/* 419CF4 802A4F64 0C0A91CB */  jal       func_802A472C
/* 419CF8 802A4F68 00000000 */   nop
/* 419CFC 802A4F6C 080A949A */  j         .L802A5268
/* 419D00 802A4F70 2402FFFE */   addiu    $v0, $zero, -2
glabel L802A4F74_419D04
/* 419D04 802A4F74 3C02802B */  lui       $v0, %hi(D_802AD66C)
/* 419D08 802A4F78 8C42D66C */  lw        $v0, %lo(D_802AD66C)($v0)
/* 419D0C 802A4F7C 1840000F */  blez      $v0, .L802A4FBC
/* 419D10 802A4F80 0000882D */   daddu    $s1, $zero, $zero
/* 419D14 802A4F84 3C10802B */  lui       $s0, %hi(D_802AD628)
/* 419D18 802A4F88 2610D628 */  addiu     $s0, $s0, %lo(D_802AD628)
/* 419D1C 802A4F8C 240500A0 */  addiu     $a1, $zero, 0xa0
.L802A4F90:
/* 419D20 802A4F90 00A0302D */  daddu     $a2, $a1, $zero
/* 419D24 802A4F94 00A0382D */  daddu     $a3, $a1, $zero
/* 419D28 802A4F98 8E040000 */  lw        $a0, ($s0)
/* 419D2C 802A4F9C 0C0513BF */  jal       set_hud_element_tint
/* 419D30 802A4FA0 26100004 */   addiu    $s0, $s0, 4
/* 419D34 802A4FA4 3C02802B */  lui       $v0, %hi(D_802AD66C)
/* 419D38 802A4FA8 8C42D66C */  lw        $v0, %lo(D_802AD66C)($v0)
/* 419D3C 802A4FAC 26310001 */  addiu     $s1, $s1, 1
/* 419D40 802A4FB0 0222102A */  slt       $v0, $s1, $v0
/* 419D44 802A4FB4 1440FFF6 */  bnez      $v0, .L802A4F90
/* 419D48 802A4FB8 240500A0 */   addiu    $a1, $zero, 0xa0
.L802A4FBC:
/* 419D4C 802A4FBC 240500A0 */  addiu     $a1, $zero, 0xa0
/* 419D50 802A4FC0 00A0302D */  daddu     $a2, $a1, $zero
/* 419D54 802A4FC4 3C10802B */  lui       $s0, %hi(D_802AD618)
/* 419D58 802A4FC8 2610D618 */  addiu     $s0, $s0, %lo(D_802AD618)
/* 419D5C 802A4FCC 8E040000 */  lw        $a0, ($s0)
/* 419D60 802A4FD0 0C0513BF */  jal       set_hud_element_tint
/* 419D64 802A4FD4 00A0382D */   daddu    $a3, $a1, $zero
/* 419D68 802A4FD8 240500A0 */  addiu     $a1, $zero, 0xa0
/* 419D6C 802A4FDC 00A0302D */  daddu     $a2, $a1, $zero
/* 419D70 802A4FE0 3C04802B */  lui       $a0, %hi(D_802AD61C)
/* 419D74 802A4FE4 8C84D61C */  lw        $a0, %lo(D_802AD61C)($a0)
/* 419D78 802A4FE8 0C0513BF */  jal       set_hud_element_tint
/* 419D7C 802A4FEC 00A0382D */   daddu    $a3, $a1, $zero
/* 419D80 802A4FF0 240500A0 */  addiu     $a1, $zero, 0xa0
/* 419D84 802A4FF4 00A0302D */  daddu     $a2, $a1, $zero
/* 419D88 802A4FF8 3C04802B */  lui       $a0, %hi(D_802AD620)
/* 419D8C 802A4FFC 8C84D620 */  lw        $a0, %lo(D_802AD620)($a0)
/* 419D90 802A5000 0C0513BF */  jal       set_hud_element_tint
/* 419D94 802A5004 00A0382D */   daddu    $a3, $a1, $zero
/* 419D98 802A5008 8E040000 */  lw        $a0, ($s0)
/* 419D9C 802A500C 3C058010 */  lui       $a1, %hi(D_80104A00)
/* 419DA0 802A5010 24A54A00 */  addiu     $a1, $a1, %lo(D_80104A00)
/* 419DA4 802A5014 0C0511FF */  jal       set_hud_element_anim
/* 419DA8 802A5018 00000000 */   nop
/* 419DAC 802A501C 24040006 */  addiu     $a0, $zero, 6
/* 419DB0 802A5020 2402000D */  addiu     $v0, $zero, 0xd
/* 419DB4 802A5024 3C01802B */  lui       $at, %hi(D_802AD614)
/* 419DB8 802A5028 A022D614 */  sb        $v0, %lo(D_802AD614)($at)
/* 419DBC 802A502C 0C051F9F */  jal       set_window_update
/* 419DC0 802A5030 24050004 */   addiu    $a1, $zero, 4
/* 419DC4 802A5034 24040007 */  addiu     $a0, $zero, 7
/* 419DC8 802A5038 0C051F9F */  jal       set_window_update
/* 419DCC 802A503C 24050004 */   addiu    $a1, $zero, 4
/* 419DD0 802A5040 24040008 */  addiu     $a0, $zero, 8
/* 419DD4 802A5044 0C051F9F */  jal       set_window_update
/* 419DD8 802A5048 24050002 */   addiu    $a1, $zero, 2
/* 419DDC 802A504C 080A9424 */  j         L802A5090_419E20
/* 419DE0 802A5050 00000000 */   nop
glabel L802A5054_419DE4
/* 419DE4 802A5054 080A949D */  j         .L802A5274
/* 419DE8 802A5058 240200FF */   addiu    $v0, $zero, 0xff
glabel L802A505C_419DEC
/* 419DEC 802A505C 24040006 */  addiu     $a0, $zero, 6
/* 419DF0 802A5060 0C051F9F */  jal       set_window_update
/* 419DF4 802A5064 24050002 */   addiu    $a1, $zero, 2
/* 419DF8 802A5068 24040007 */  addiu     $a0, $zero, 7
/* 419DFC 802A506C 0C051F9F */  jal       set_window_update
/* 419E00 802A5070 24050002 */   addiu    $a1, $zero, 2
/* 419E04 802A5074 24040008 */  addiu     $a0, $zero, 8
/* 419E08 802A5078 0C051F9F */  jal       set_window_update
/* 419E0C 802A507C 24050002 */   addiu    $a1, $zero, 2
/* 419E10 802A5080 3C02802B */  lui       $v0, %hi(D_802AD605)
/* 419E14 802A5084 8042D605 */  lb        $v0, %lo(D_802AD605)($v0)
/* 419E18 802A5088 080A9434 */  j         .L802A50D0
/* 419E1C 802A508C 2403000B */   addiu    $v1, $zero, 0xb
glabel L802A5090_419E20
/* 419E20 802A5090 3C02802B */  lui       $v0, %hi(D_802AD605)
/* 419E24 802A5094 8042D605 */  lb        $v0, %lo(D_802AD605)($v0)
/* 419E28 802A5098 080A949D */  j         .L802A5274
/* 419E2C 802A509C 24420001 */   addiu    $v0, $v0, 1
glabel L802A50A0_419E30
/* 419E30 802A50A0 24040006 */  addiu     $a0, $zero, 6
/* 419E34 802A50A4 0C051F9F */  jal       set_window_update
/* 419E38 802A50A8 24050001 */   addiu    $a1, $zero, 1
/* 419E3C 802A50AC 24040007 */  addiu     $a0, $zero, 7
/* 419E40 802A50B0 0C051F9F */  jal       set_window_update
/* 419E44 802A50B4 24050001 */   addiu    $a1, $zero, 1
/* 419E48 802A50B8 24040008 */  addiu     $a0, $zero, 8
/* 419E4C 802A50BC 0C051F9F */  jal       set_window_update
/* 419E50 802A50C0 24050001 */   addiu    $a1, $zero, 1
/* 419E54 802A50C4 3C02802B */  lui       $v0, %hi(D_802AD605)
/* 419E58 802A50C8 8042D605 */  lb        $v0, %lo(D_802AD605)($v0)
/* 419E5C 802A50CC 24030001 */  addiu     $v1, $zero, 1
.L802A50D0:
/* 419E60 802A50D0 3C01802B */  lui       $at, %hi(D_802AD604)
/* 419E64 802A50D4 A023D604 */  sb        $v1, %lo(D_802AD604)($at)
/* 419E68 802A50D8 080A949D */  j         .L802A5274
/* 419E6C 802A50DC 24420001 */   addiu    $v0, $v0, 1
glabel L802A50E0_419E70
/* 419E70 802A50E0 24040006 */  addiu     $a0, $zero, 6
/* 419E74 802A50E4 0C051F9F */  jal       set_window_update
/* 419E78 802A50E8 24050001 */   addiu    $a1, $zero, 1
/* 419E7C 802A50EC 24040007 */  addiu     $a0, $zero, 7
/* 419E80 802A50F0 0C051F9F */  jal       set_window_update
/* 419E84 802A50F4 24050001 */   addiu    $a1, $zero, 1
/* 419E88 802A50F8 24040008 */  addiu     $a0, $zero, 8
/* 419E8C 802A50FC 0C051F9F */  jal       set_window_update
/* 419E90 802A5100 24050001 */   addiu    $a1, $zero, 1
/* 419E94 802A5104 080A949A */  j         .L802A5268
/* 419E98 802A5108 2402FFFF */   addiu    $v0, $zero, -1
glabel L802A510C_419E9C
/* 419E9C 802A510C 2402FFFF */  addiu     $v0, $zero, -1
/* 419EA0 802A5110 0040182D */  daddu     $v1, $v0, $zero
/* 419EA4 802A5114 3C01802B */  lui       $at, %hi(D_802AD6D4)
/* 419EA8 802A5118 AC23D6D4 */  sw        $v1, %lo(D_802AD6D4)($at)
/* 419EAC 802A511C 24030029 */  addiu     $v1, $zero, 0x29
/* 419EB0 802A5120 3C01802B */  lui       $at, %hi(D_802AD604)
/* 419EB4 802A5124 A023D604 */  sb        $v1, %lo(D_802AD604)($at)
/* 419EB8 802A5128 080A949D */  j         .L802A5274
/* 419EBC 802A512C 00000000 */   nop
glabel L802A5130_419EC0
/* 419EC0 802A5130 24040006 */  addiu     $a0, $zero, 6
/* 419EC4 802A5134 0C051F9F */  jal       set_window_update
/* 419EC8 802A5138 24050002 */   addiu    $a1, $zero, 2
/* 419ECC 802A513C 24040007 */  addiu     $a0, $zero, 7
/* 419ED0 802A5140 0C051F9F */  jal       set_window_update
/* 419ED4 802A5144 24050002 */   addiu    $a1, $zero, 2
/* 419ED8 802A5148 24040008 */  addiu     $a0, $zero, 8
/* 419EDC 802A514C 0C051F9F */  jal       set_window_update
/* 419EE0 802A5150 24050002 */   addiu    $a1, $zero, 2
/* 419EE4 802A5154 3C03802B */  lui       $v1, %hi(D_802AD610)
/* 419EE8 802A5158 8463D610 */  lh        $v1, %lo(D_802AD610)($v1)
/* 419EEC 802A515C 14600003 */  bnez      $v1, .L802A516C
/* 419EF0 802A5160 3C04001D */   lui      $a0, 0x1d
/* 419EF4 802A5164 080A945C */  j         .L802A5170
/* 419EF8 802A5168 348400CB */   ori      $a0, $a0, 0xcb
.L802A516C:
/* 419EFC 802A516C 348400CC */  ori       $a0, $a0, 0xcc
.L802A5170:
/* 419F00 802A5170 0C04991D */  jal       get_string_width
/* 419F04 802A5174 0000282D */   daddu    $a1, $zero, $zero
/* 419F08 802A5178 24040009 */  addiu     $a0, $zero, 9
/* 419F0C 802A517C 24470017 */  addiu     $a3, $v0, 0x17
/* 419F10 802A5180 00072FC2 */  srl       $a1, $a3, 0x1f
/* 419F14 802A5184 00E52821 */  addu      $a1, $a3, $a1
/* 419F18 802A5188 00052843 */  sra       $a1, $a1, 1
/* 419F1C 802A518C 240200A0 */  addiu     $v0, $zero, 0xa0
/* 419F20 802A5190 00452823 */  subu      $a1, $v0, $a1
/* 419F24 802A5194 24060050 */  addiu     $a2, $zero, 0x50
/* 419F28 802A5198 2402001C */  addiu     $v0, $zero, 0x1c
/* 419F2C 802A519C AFA20010 */  sw        $v0, 0x10($sp)
/* 419F30 802A51A0 24020014 */  addiu     $v0, $zero, 0x14
/* 419F34 802A51A4 AFA20014 */  sw        $v0, 0x14($sp)
/* 419F38 802A51A8 3C02802A */  lui       $v0, %hi(func_802A57C8)
/* 419F3C 802A51AC 244257C8 */  addiu     $v0, $v0, %lo(func_802A57C8)
/* 419F40 802A51B0 AFA20018 */  sw        $v0, 0x18($sp)
/* 419F44 802A51B4 2402FFFF */  addiu     $v0, $zero, -1
/* 419F48 802A51B8 AFA0001C */  sw        $zero, 0x1c($sp)
/* 419F4C 802A51BC 0C051F32 */  jal       set_window_properties
/* 419F50 802A51C0 AFA20020 */   sw       $v0, 0x20($sp)
/* 419F54 802A51C4 24040009 */  addiu     $a0, $zero, 9
/* 419F58 802A51C8 0C051F9F */  jal       set_window_update
/* 419F5C 802A51CC 24050001 */   addiu    $a1, $zero, 1
/* 419F60 802A51D0 2403003C */  addiu     $v1, $zero, 0x3c
/* 419F64 802A51D4 3C01802B */  lui       $at, %hi(D_802AD612)
/* 419F68 802A51D8 A423D612 */  sh        $v1, %lo(D_802AD612)($at)
/* 419F6C 802A51DC 2403002A */  addiu     $v1, $zero, 0x2a
/* 419F70 802A51E0 3C01802B */  lui       $at, %hi(D_802AD604)
/* 419F74 802A51E4 A023D604 */  sb        $v1, %lo(D_802AD604)($at)
/* 419F78 802A51E8 080A949D */  j         .L802A5274
/* 419F7C 802A51EC 2402FFFF */   addiu    $v0, $zero, -1
glabel L802A51F0_419F80
/* 419F80 802A51F0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 419F84 802A51F4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 419F88 802A51F8 8C420010 */  lw        $v0, 0x10($v0)
/* 419F8C 802A51FC 3042C000 */  andi      $v0, $v0, 0xc000
/* 419F90 802A5200 10400003 */  beqz      $v0, .L802A5210
/* 419F94 802A5204 00000000 */   nop
/* 419F98 802A5208 3C01802B */  lui       $at, %hi(D_802AD612)
/* 419F9C 802A520C A420D612 */  sh        $zero, %lo(D_802AD612)($at)
.L802A5210:
/* 419FA0 802A5210 3C04802B */  lui       $a0, %hi(D_802AD612)
/* 419FA4 802A5214 2484D612 */  addiu     $a0, $a0, %lo(D_802AD612)
/* 419FA8 802A5218 84820000 */  lh        $v0, ($a0)
/* 419FAC 802A521C 94830000 */  lhu       $v1, ($a0)
/* 419FB0 802A5220 10400004 */  beqz      $v0, .L802A5234
/* 419FB4 802A5224 2462FFFF */   addiu    $v0, $v1, -1
/* 419FB8 802A5228 A4820000 */  sh        $v0, ($a0)
/* 419FBC 802A522C 080A949D */  j         .L802A5274
/* 419FC0 802A5230 2402FFFF */   addiu    $v0, $zero, -1
.L802A5234:
/* 419FC4 802A5234 24040009 */  addiu     $a0, $zero, 9
/* 419FC8 802A5238 0C051F9F */  jal       set_window_update
/* 419FCC 802A523C 24050002 */   addiu    $a1, $zero, 2
/* 419FD0 802A5240 24040006 */  addiu     $a0, $zero, 6
/* 419FD4 802A5244 0C051F9F */  jal       set_window_update
/* 419FD8 802A5248 24050001 */   addiu    $a1, $zero, 1
/* 419FDC 802A524C 24040007 */  addiu     $a0, $zero, 7
/* 419FE0 802A5250 0C051F9F */  jal       set_window_update
/* 419FE4 802A5254 24050001 */   addiu    $a1, $zero, 1
/* 419FE8 802A5258 24040008 */  addiu     $a0, $zero, 8
/* 419FEC 802A525C 0C051F9F */  jal       set_window_update
/* 419FF0 802A5260 24050001 */   addiu    $a1, $zero, 1
/* 419FF4 802A5264 24020001 */  addiu     $v0, $zero, 1
.L802A5268:
/* 419FF8 802A5268 3C01802B */  lui       $at, %hi(D_802AD604)
/* 419FFC 802A526C A022D604 */  sb        $v0, %lo(D_802AD604)($at)
glabel L802A5270_41A000
/* 41A000 802A5270 0000102D */  daddu     $v0, $zero, $zero
.L802A5274:
/* 41A004 802A5274 8FBF0038 */  lw        $ra, 0x38($sp)
/* 41A008 802A5278 8FB30034 */  lw        $s3, 0x34($sp)
/* 41A00C 802A527C 8FB20030 */  lw        $s2, 0x30($sp)
/* 41A010 802A5280 8FB1002C */  lw        $s1, 0x2c($sp)
/* 41A014 802A5284 8FB00028 */  lw        $s0, 0x28($sp)
/* 41A018 802A5288 03E00008 */  jr        $ra
/* 41A01C 802A528C 27BD0040 */   addiu    $sp, $sp, 0x40
