.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80260948
/* 18F228 80260948 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 18F22C 8026094C 3C03800E */  lui       $v1, %hi(gBattleStatus+0x46C)
/* 18F230 80260950 8C63C4DC */  lw        $v1, %lo(gBattleStatus+0x46C)($v1)
/* 18F234 80260954 24020008 */  addiu     $v0, $zero, 8
/* 18F238 80260958 10620008 */  beq       $v1, $v0, .L8026097C
/* 18F23C 8026095C AFBF0018 */   sw       $ra, 0x18($sp)
/* 18F240 80260960 0062102A */  slt       $v0, $v1, $v0
/* 18F244 80260964 1440002B */  bnez      $v0, .L80260A14
/* 18F248 80260968 28620011 */   slti     $v0, $v1, 0x11
/* 18F24C 8026096C 10400029 */  beqz      $v0, .L80260A14
/* 18F250 80260970 2862000F */   slti     $v0, $v1, 0xf
/* 18F254 80260974 14400027 */  bnez      $v0, .L80260A14
/* 18F258 80260978 00000000 */   nop      
.L8026097C:
/* 18F25C 8026097C 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 18F260 80260980 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 18F264 80260984 80430048 */  lb        $v1, 0x48($v0)
/* 18F268 80260988 10600005 */  beqz      $v1, .L802609A0
/* 18F26C 8026098C 24020001 */   addiu    $v0, $zero, 1
/* 18F270 80260990 1062000B */  beq       $v1, $v0, .L802609C0
/* 18F274 80260994 3C04001D */   lui      $a0, 0x1d
/* 18F278 80260998 08098277 */  j         .L802609DC
/* 18F27C 8026099C 00000000 */   nop      
.L802609A0:
/* 18F280 802609A0 3C04001D */  lui       $a0, 0x1d
/* 18F284 802609A4 3C02802A */  lui       $v0, %hi(D_8029FB60)
/* 18F288 802609A8 8C42FB60 */  lw        $v0, %lo(D_8029FB60)($v0)
/* 18F28C 802609AC 14400011 */  bnez      $v0, .L802609F4
/* 18F290 802609B0 348400A8 */   ori      $a0, $a0, 0xa8
/* 18F294 802609B4 3C04001D */  lui       $a0, 0x1d
/* 18F298 802609B8 0809827D */  j         .L802609F4
/* 18F29C 802609BC 348400A5 */   ori      $a0, $a0, 0xa5
.L802609C0:
/* 18F2A0 802609C0 3C02802A */  lui       $v0, %hi(D_8029FB64)
/* 18F2A4 802609C4 8C42FB64 */  lw        $v0, %lo(D_8029FB64)($v0)
/* 18F2A8 802609C8 1440000A */  bnez      $v0, .L802609F4
/* 18F2AC 802609CC 348400A9 */   ori      $a0, $a0, 0xa9
/* 18F2B0 802609D0 3C04001D */  lui       $a0, 0x1d
/* 18F2B4 802609D4 0809827D */  j         .L802609F4
/* 18F2B8 802609D8 348400A6 */   ori      $a0, $a0, 0xa6
.L802609DC:
/* 18F2BC 802609DC 3C02802A */  lui       $v0, %hi(D_8029FB68)
/* 18F2C0 802609E0 8C42FB68 */  lw        $v0, %lo(D_8029FB68)($v0)
/* 18F2C4 802609E4 14400003 */  bnez      $v0, .L802609F4
/* 18F2C8 802609E8 348400AA */   ori      $a0, $a0, 0xaa
/* 18F2CC 802609EC 3C04001D */  lui       $a0, 0x1d
/* 18F2D0 802609F0 348400A7 */  ori       $a0, $a0, 0xa7
.L802609F4:
/* 18F2D4 802609F4 24030009 */  addiu     $v1, $zero, 9
/* 18F2D8 802609F8 2402000A */  addiu     $v0, $zero, 0xa
/* 18F2DC 802609FC 00A32821 */  addu      $a1, $a1, $v1
/* 18F2E0 80260A00 24A50011 */  addiu     $a1, $a1, 0x11
/* 18F2E4 80260A04 240700FF */  addiu     $a3, $zero, 0xff
/* 18F2E8 80260A08 AFA20010 */  sw        $v0, 0x10($sp)
/* 18F2EC 80260A0C 0C04993B */  jal       draw_string
/* 18F2F0 80260A10 AFA00014 */   sw       $zero, 0x14($sp)
.L80260A14:
/* 18F2F4 80260A14 8FBF0018 */  lw        $ra, 0x18($sp)
/* 18F2F8 80260A18 03E00008 */  jr        $ra
/* 18F2FC 80260A1C 27BD0020 */   addiu    $sp, $sp, 0x20
