.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_HiddenPanel_setupGfx
/* 107A30 802E61B0 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* 107A34 802E61B4 AFBF00A4 */  sw        $ra, 0xa4($sp)
/* 107A38 802E61B8 AFB400A0 */  sw        $s4, 0xa0($sp)
/* 107A3C 802E61BC AFB3009C */  sw        $s3, 0x9c($sp)
/* 107A40 802E61C0 AFB20098 */  sw        $s2, 0x98($sp)
/* 107A44 802E61C4 AFB10094 */  sw        $s1, 0x94($sp)
/* 107A48 802E61C8 0C04417A */  jal       get_entity_by_index
/* 107A4C 802E61CC AFB00090 */   sw       $s0, 0x90($sp)
/* 107A50 802E61D0 0040982D */  daddu     $s3, $v0, $zero
/* 107A54 802E61D4 8E740040 */  lw        $s4, 0x40($s3)
/* 107A58 802E61D8 C662004C */  lwc1      $f2, 0x4c($s3)
/* 107A5C 802E61DC C6800024 */  lwc1      $f0, 0x24($s4)
/* 107A60 802E61E0 46001032 */  c.eq.s    $f2, $f0
/* 107A64 802E61E4 00000000 */  nop
/* 107A68 802E61E8 45010041 */  bc1t      .L802E62F0
/* 107A6C 802E61EC 00000000 */   nop
/* 107A70 802E61F0 0C019D28 */  jal       guMtxIdentF
/* 107A74 802E61F4 27A40010 */   addiu    $a0, $sp, 0x10
/* 107A78 802E61F8 27B00050 */  addiu     $s0, $sp, 0x50
/* 107A7C 802E61FC 0200202D */  daddu     $a0, $s0, $zero
/* 107A80 802E6200 C6820024 */  lwc1      $f2, 0x24($s4)
/* 107A84 802E6204 3C013F80 */  lui       $at, 0x3f80
/* 107A88 802E6208 44810000 */  mtc1      $at, $f0
/* 107A8C 802E620C 3C120001 */  lui       $s2, 1
/* 107A90 802E6210 46001080 */  add.s     $f2, $f2, $f0
/* 107A94 802E6214 8E650048 */  lw        $a1, 0x48($s3)
/* 107A98 802E6218 8E670050 */  lw        $a3, 0x50($s3)
/* 107A9C 802E621C 44061000 */  mfc1      $a2, $f2
/* 107AA0 802E6220 0C019E40 */  jal       guTranslateF
/* 107AA4 802E6224 36521630 */   ori      $s2, $s2, 0x1630
/* 107AA8 802E6228 0200202D */  daddu     $a0, $s0, $zero
/* 107AAC 802E622C 27A50010 */  addiu     $a1, $sp, 0x10
/* 107AB0 802E6230 0C019D80 */  jal       guMtxCatF
/* 107AB4 802E6234 0200302D */   daddu    $a2, $s0, $zero
/* 107AB8 802E6238 0200202D */  daddu     $a0, $s0, $zero
/* 107ABC 802E623C 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 107AC0 802E6240 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 107AC4 802E6244 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 107AC8 802E6248 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 107ACC 802E624C 96050000 */  lhu       $a1, ($s0)
/* 107AD0 802E6250 8E220000 */  lw        $v0, ($s1)
/* 107AD4 802E6254 00052980 */  sll       $a1, $a1, 6
/* 107AD8 802E6258 00B22821 */  addu      $a1, $a1, $s2
/* 107ADC 802E625C 0C019D40 */  jal       guMtxF2L
/* 107AE0 802E6260 00452821 */   addu     $a1, $v0, $a1
/* 107AE4 802E6264 3C03DA38 */  lui       $v1, 0xda38
/* 107AE8 802E6268 34630002 */  ori       $v1, $v1, 2
/* 107AEC 802E626C 3C07D838 */  lui       $a3, 0xd838
/* 107AF0 802E6270 3C05800A */  lui       $a1, %hi(gMasterGfxPos)
/* 107AF4 802E6274 24A5A66C */  addiu     $a1, $a1, %lo(gMasterGfxPos)
/* 107AF8 802E6278 34E70002 */  ori       $a3, $a3, 2
/* 107AFC 802E627C 8CA40000 */  lw        $a0, ($a1)
/* 107B00 802E6280 96020000 */  lhu       $v0, ($s0)
/* 107B04 802E6284 0080302D */  daddu     $a2, $a0, $zero
/* 107B08 802E6288 24840008 */  addiu     $a0, $a0, 8
/* 107B0C 802E628C ACA40000 */  sw        $a0, ($a1)
/* 107B10 802E6290 ACC30000 */  sw        $v1, ($a2)
/* 107B14 802E6294 24430001 */  addiu     $v1, $v0, 1
/* 107B18 802E6298 3042FFFF */  andi      $v0, $v0, 0xffff
/* 107B1C 802E629C 00021180 */  sll       $v0, $v0, 6
/* 107B20 802E62A0 A6030000 */  sh        $v1, ($s0)
/* 107B24 802E62A4 8E230000 */  lw        $v1, ($s1)
/* 107B28 802E62A8 00521021 */  addu      $v0, $v0, $s2
/* 107B2C 802E62AC 00621821 */  addu      $v1, $v1, $v0
/* 107B30 802E62B0 24820008 */  addiu     $v0, $a0, 8
/* 107B34 802E62B4 ACC30004 */  sw        $v1, 4($a2)
/* 107B38 802E62B8 ACA20000 */  sw        $v0, ($a1)
/* 107B3C 802E62BC 3C02DE00 */  lui       $v0, 0xde00
/* 107B40 802E62C0 AC820000 */  sw        $v0, ($a0)
/* 107B44 802E62C4 8E630044 */  lw        $v1, 0x44($s3)
/* 107B48 802E62C8 24820010 */  addiu     $v0, $a0, 0x10
/* 107B4C 802E62CC ACA20000 */  sw        $v0, ($a1)
/* 107B50 802E62D0 24020040 */  addiu     $v0, $zero, 0x40
/* 107B54 802E62D4 AC82000C */  sw        $v0, 0xc($a0)
/* 107B58 802E62D8 3C020A00 */  lui       $v0, 0xa00
/* 107B5C 802E62DC 24420230 */  addiu     $v0, $v0, 0x230
/* 107B60 802E62E0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 107B64 802E62E4 AC870008 */  sw        $a3, 8($a0)
/* 107B68 802E62E8 00621821 */  addu      $v1, $v1, $v0
/* 107B6C 802E62EC AC830004 */  sw        $v1, 4($a0)
.L802E62F0:
/* 107B70 802E62F0 96840074 */  lhu       $a0, 0x74($s4)
/* 107B74 802E62F4 8E850078 */  lw        $a1, 0x78($s4)
/* 107B78 802E62F8 8E670044 */  lw        $a3, 0x44($s3)
/* 107B7C 802E62FC 0C0470CB */  jal       mdl_project_tex_coords
/* 107B80 802E6300 26860034 */   addiu    $a2, $s4, 0x34
/* 107B84 802E6304 96850074 */  lhu       $a1, 0x74($s4)
/* 107B88 802E6308 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 107B8C 802E630C 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 107B90 802E6310 0C0475CB */  jal       mdl_draw_hidden_panel_surface
/* 107B94 802E6314 00000000 */   nop
/* 107B98 802E6318 8FBF00A4 */  lw        $ra, 0xa4($sp)
/* 107B9C 802E631C 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 107BA0 802E6320 8FB3009C */  lw        $s3, 0x9c($sp)
/* 107BA4 802E6324 8FB20098 */  lw        $s2, 0x98($sp)
/* 107BA8 802E6328 8FB10094 */  lw        $s1, 0x94($sp)
/* 107BAC 802E632C 8FB00090 */  lw        $s0, 0x90($sp)
/* 107BB0 802E6330 03E00008 */  jr        $ra
/* 107BB4 802E6334 27BD00A8 */   addiu    $sp, $sp, 0xa8
