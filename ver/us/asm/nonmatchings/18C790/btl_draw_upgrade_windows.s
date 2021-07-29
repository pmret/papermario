.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_draw_upgrade_windows
/* 18E86C 8025FF8C 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 18E870 8025FF90 AFBF007C */  sw        $ra, 0x7c($sp)
/* 18E874 8025FF94 AFBE0078 */  sw        $fp, 0x78($sp)
/* 18E878 8025FF98 AFB70074 */  sw        $s7, 0x74($sp)
/* 18E87C 8025FF9C AFB60070 */  sw        $s6, 0x70($sp)
/* 18E880 8025FFA0 AFB5006C */  sw        $s5, 0x6c($sp)
/* 18E884 8025FFA4 AFB40068 */  sw        $s4, 0x68($sp)
/* 18E888 8025FFA8 AFB30064 */  sw        $s3, 0x64($sp)
/* 18E88C 8025FFAC AFB20060 */  sw        $s2, 0x60($sp)
/* 18E890 8025FFB0 AFB1005C */  sw        $s1, 0x5c($sp)
/* 18E894 8025FFB4 AFB00058 */  sw        $s0, 0x58($sp)
/* 18E898 8025FFB8 F7B40080 */  sdc1      $f20, 0x80($sp)
/* 18E89C 8025FFBC 10800014 */  beqz      $a0, .L80260010
/* 18E8A0 8025FFC0 24020001 */   addiu    $v0, $zero, 1
/* 18E8A4 8025FFC4 14820013 */  bne       $a0, $v0, .L80260014
/* 18E8A8 8025FFC8 24110064 */   addiu    $s1, $zero, 0x64
/* 18E8AC 8025FFCC 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 18E8B0 8025FFD0 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 18E8B4 8025FFD4 80420048 */  lb        $v0, 0x48($v0)
/* 18E8B8 8025FFD8 10400005 */  beqz      $v0, .L8025FFF0
/* 18E8BC 8025FFDC 0000882D */   daddu    $s1, $zero, $zero
/* 18E8C0 8025FFE0 10440006 */  beq       $v0, $a0, .L8025FFFC
/* 18E8C4 8025FFE4 24110064 */   addiu    $s1, $zero, 0x64
/* 18E8C8 8025FFE8 08098002 */  j         .L80260008
/* 18E8CC 8025FFEC 0220B82D */   daddu    $s7, $s1, $zero
.L8025FFF0:
/* 18E8D0 8025FFF0 24170064 */  addiu     $s7, $zero, 0x64
/* 18E8D4 8025FFF4 08098007 */  j         .L8026001C
/* 18E8D8 8025FFF8 241E0064 */   addiu    $fp, $zero, 0x64
.L8025FFFC:
/* 18E8DC 8025FFFC 0000B82D */  daddu     $s7, $zero, $zero
/* 18E8E0 80260000 08098007 */  j         .L8026001C
/* 18E8E4 80260004 241E0064 */   addiu    $fp, $zero, 0x64
.L80260008:
/* 18E8E8 80260008 08098007 */  j         .L8026001C
/* 18E8EC 8026000C 0000F02D */   daddu    $fp, $zero, $zero
.L80260010:
/* 18E8F0 80260010 24110064 */  addiu     $s1, $zero, 0x64
.L80260014:
/* 18E8F4 80260014 0220B82D */  daddu     $s7, $s1, $zero
/* 18E8F8 80260018 0220F02D */  daddu     $fp, $s1, $zero
.L8026001C:
/* 18E8FC 8026001C 27B60050 */  addiu     $s6, $sp, 0x50
/* 18E900 80260020 02C0282D */  daddu     $a1, $s6, $zero
/* 18E904 80260024 3C15802A */  lui       $s5, %hi(D_8029FA80)
/* 18E908 80260028 26B5FA80 */  addiu     $s5, $s5, %lo(D_8029FA80)
/* 18E90C 8026002C 27B40054 */  addiu     $s4, $sp, 0x54
/* 18E910 80260030 8EA40000 */  lw        $a0, ($s5)
/* 18E914 80260034 0C05126B */  jal       get_hud_element_render_pos
/* 18E918 80260038 0280302D */   daddu    $a2, $s4, $zero
/* 18E91C 8026003C 0000202D */  daddu     $a0, $zero, $zero
/* 18E920 80260040 2405000F */  addiu     $a1, $zero, 0xf
/* 18E924 80260044 2410002C */  addiu     $s0, $zero, 0x2c
/* 18E928 80260048 241300FF */  addiu     $s3, $zero, 0xff
/* 18E92C 8026004C 8FA60050 */  lw        $a2, 0x50($sp)
/* 18E930 80260050 8FA70054 */  lw        $a3, 0x54($sp)
/* 18E934 80260054 3C013F80 */  lui       $at, 0x3f80
/* 18E938 80260058 4481A000 */  mtc1      $at, $f20
/* 18E93C 8026005C 24120140 */  addiu     $s2, $zero, 0x140
/* 18E940 80260060 AFB10020 */  sw        $s1, 0x20($sp)
/* 18E944 80260064 241100F0 */  addiu     $s1, $zero, 0xf0
/* 18E948 80260068 AFA00010 */  sw        $zero, 0x10($sp)
/* 18E94C 8026006C AFB00014 */  sw        $s0, 0x14($sp)
/* 18E950 80260070 AFB00018 */  sw        $s0, 0x18($sp)
/* 18E954 80260074 AFB3001C */  sw        $s3, 0x1c($sp)
/* 18E958 80260078 AFA0002C */  sw        $zero, 0x2c($sp)
/* 18E95C 8026007C AFA00030 */  sw        $zero, 0x30($sp)
/* 18E960 80260080 AFA00034 */  sw        $zero, 0x34($sp)
/* 18E964 80260084 AFA00038 */  sw        $zero, 0x38($sp)
/* 18E968 80260088 AFA0003C */  sw        $zero, 0x3c($sp)
/* 18E96C 8026008C AFA00040 */  sw        $zero, 0x40($sp)
/* 18E970 80260090 AFB20044 */  sw        $s2, 0x44($sp)
/* 18E974 80260094 AFB10048 */  sw        $s1, 0x48($sp)
/* 18E978 80260098 AFA0004C */  sw        $zero, 0x4c($sp)
/* 18E97C 8026009C 24C6FFEA */  addiu     $a2, $a2, -0x16
/* 18E980 802600A0 24E7FFEA */  addiu     $a3, $a3, -0x16
/* 18E984 802600A4 E7B40024 */  swc1      $f20, 0x24($sp)
/* 18E988 802600A8 0C03D4B8 */  jal       draw_box
/* 18E98C 802600AC E7B40028 */   swc1     $f20, 0x28($sp)
/* 18E990 802600B0 02C0282D */  daddu     $a1, $s6, $zero
/* 18E994 802600B4 8EA4000C */  lw        $a0, 0xc($s5)
/* 18E998 802600B8 0C05126B */  jal       get_hud_element_render_pos
/* 18E99C 802600BC 0280302D */   daddu    $a2, $s4, $zero
/* 18E9A0 802600C0 0000202D */  daddu     $a0, $zero, $zero
/* 18E9A4 802600C4 8FA60050 */  lw        $a2, 0x50($sp)
/* 18E9A8 802600C8 8FA70054 */  lw        $a3, 0x54($sp)
/* 18E9AC 802600CC 2405000F */  addiu     $a1, $zero, 0xf
/* 18E9B0 802600D0 AFA00010 */  sw        $zero, 0x10($sp)
/* 18E9B4 802600D4 AFB00014 */  sw        $s0, 0x14($sp)
/* 18E9B8 802600D8 AFB00018 */  sw        $s0, 0x18($sp)
/* 18E9BC 802600DC AFB3001C */  sw        $s3, 0x1c($sp)
/* 18E9C0 802600E0 AFB70020 */  sw        $s7, 0x20($sp)
/* 18E9C4 802600E4 E7B40024 */  swc1      $f20, 0x24($sp)
/* 18E9C8 802600E8 E7B40028 */  swc1      $f20, 0x28($sp)
/* 18E9CC 802600EC AFA0002C */  sw        $zero, 0x2c($sp)
/* 18E9D0 802600F0 AFA00030 */  sw        $zero, 0x30($sp)
/* 18E9D4 802600F4 AFA00034 */  sw        $zero, 0x34($sp)
/* 18E9D8 802600F8 AFA00038 */  sw        $zero, 0x38($sp)
/* 18E9DC 802600FC AFA0003C */  sw        $zero, 0x3c($sp)
/* 18E9E0 80260100 AFA00040 */  sw        $zero, 0x40($sp)
/* 18E9E4 80260104 AFB20044 */  sw        $s2, 0x44($sp)
/* 18E9E8 80260108 AFB10048 */  sw        $s1, 0x48($sp)
/* 18E9EC 8026010C AFA0004C */  sw        $zero, 0x4c($sp)
/* 18E9F0 80260110 24C6FFEA */  addiu     $a2, $a2, -0x16
/* 18E9F4 80260114 0C03D4B8 */  jal       draw_box
/* 18E9F8 80260118 24E7FFEA */   addiu    $a3, $a3, -0x16
/* 18E9FC 8026011C 02C0282D */  daddu     $a1, $s6, $zero
/* 18EA00 80260120 8EA40008 */  lw        $a0, 8($s5)
/* 18EA04 80260124 0C05126B */  jal       get_hud_element_render_pos
/* 18EA08 80260128 0280302D */   daddu    $a2, $s4, $zero
/* 18EA0C 8026012C 0000202D */  daddu     $a0, $zero, $zero
/* 18EA10 80260130 8FA60050 */  lw        $a2, 0x50($sp)
/* 18EA14 80260134 8FA70054 */  lw        $a3, 0x54($sp)
/* 18EA18 80260138 2405000F */  addiu     $a1, $zero, 0xf
/* 18EA1C 8026013C AFA00010 */  sw        $zero, 0x10($sp)
/* 18EA20 80260140 AFB00014 */  sw        $s0, 0x14($sp)
/* 18EA24 80260144 AFB00018 */  sw        $s0, 0x18($sp)
/* 18EA28 80260148 AFB3001C */  sw        $s3, 0x1c($sp)
/* 18EA2C 8026014C AFBE0020 */  sw        $fp, 0x20($sp)
/* 18EA30 80260150 E7B40024 */  swc1      $f20, 0x24($sp)
/* 18EA34 80260154 E7B40028 */  swc1      $f20, 0x28($sp)
/* 18EA38 80260158 AFA0002C */  sw        $zero, 0x2c($sp)
/* 18EA3C 8026015C AFA00030 */  sw        $zero, 0x30($sp)
/* 18EA40 80260160 AFA00034 */  sw        $zero, 0x34($sp)
/* 18EA44 80260164 AFA00038 */  sw        $zero, 0x38($sp)
/* 18EA48 80260168 AFA0003C */  sw        $zero, 0x3c($sp)
/* 18EA4C 8026016C AFA00040 */  sw        $zero, 0x40($sp)
/* 18EA50 80260170 AFB20044 */  sw        $s2, 0x44($sp)
/* 18EA54 80260174 AFB10048 */  sw        $s1, 0x48($sp)
/* 18EA58 80260178 AFA0004C */  sw        $zero, 0x4c($sp)
/* 18EA5C 8026017C 24C6FFEA */  addiu     $a2, $a2, -0x16
/* 18EA60 80260180 0C03D4B8 */  jal       draw_box
/* 18EA64 80260184 24E7FFEA */   addiu    $a3, $a3, -0x16
/* 18EA68 80260188 8FBF007C */  lw        $ra, 0x7c($sp)
/* 18EA6C 8026018C 8FBE0078 */  lw        $fp, 0x78($sp)
/* 18EA70 80260190 8FB70074 */  lw        $s7, 0x74($sp)
/* 18EA74 80260194 8FB60070 */  lw        $s6, 0x70($sp)
/* 18EA78 80260198 8FB5006C */  lw        $s5, 0x6c($sp)
/* 18EA7C 8026019C 8FB40068 */  lw        $s4, 0x68($sp)
/* 18EA80 802601A0 8FB30064 */  lw        $s3, 0x64($sp)
/* 18EA84 802601A4 8FB20060 */  lw        $s2, 0x60($sp)
/* 18EA88 802601A8 8FB1005C */  lw        $s1, 0x5c($sp)
/* 18EA8C 802601AC 8FB00058 */  lw        $s0, 0x58($sp)
/* 18EA90 802601B0 D7B40080 */  ldc1      $f20, 0x80($sp)
/* 18EA94 802601B4 03E00008 */  jr        $ra
/* 18EA98 802601B8 27BD0088 */   addiu    $sp, $sp, 0x88
