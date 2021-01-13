.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A98_59F178
/* 59F178 80218A98 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 59F17C 80218A9C 3C038022 */  lui       $v1, %hi(D_80222B68)
/* 59F180 80218AA0 24632B68 */  addiu     $v1, $v1, %lo(D_80222B68)
/* 59F184 80218AA4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 59F188 80218AA8 8C620000 */  lw        $v0, ($v1)
/* 59F18C 80218AAC 24440001 */  addiu     $a0, $v0, 1
/* 59F190 80218AB0 10A0000C */  beqz      $a1, .L80218AE4
/* 59F194 80218AB4 AC640000 */   sw       $a0, ($v1)
/* 59F198 80218AB8 0C05272D */  jal       play_sound
/* 59F19C 80218ABC 240400D4 */   addiu    $a0, $zero, 0xd4
/* 59F1A0 80218AC0 24020008 */  addiu     $v0, $zero, 8
/* 59F1A4 80218AC4 AFA20010 */  sw        $v0, 0x10($sp)
/* 59F1A8 80218AC8 0000202D */  daddu     $a0, $zero, $zero
/* 59F1AC 80218ACC 2405008B */  addiu     $a1, $zero, 0x8b
/* 59F1B0 80218AD0 0080302D */  daddu     $a2, $a0, $zero
/* 59F1B4 80218AD4 0C052A46 */  jal       set_music_track
/* 59F1B8 80218AD8 240701F4 */   addiu    $a3, $zero, 0x1f4
/* 59F1BC 80218ADC 080862CB */  j         .L80218B2C
/* 59F1C0 80218AE0 0000102D */   daddu    $v0, $zero, $zero
.L80218AE4:
/* 59F1C4 80218AE4 24020050 */  addiu     $v0, $zero, 0x50
/* 59F1C8 80218AE8 10820005 */  beq       $a0, $v0, .L80218B00
/* 59F1CC 80218AEC 24020154 */   addiu    $v0, $zero, 0x154
/* 59F1D0 80218AF0 10820007 */  beq       $a0, $v0, .L80218B10
/* 59F1D4 80218AF4 24020008 */   addiu    $v0, $zero, 8
/* 59F1D8 80218AF8 080862CB */  j         .L80218B2C
/* 59F1DC 80218AFC 0000102D */   daddu    $v0, $zero, $zero
.L80218B00:
/* 59F1E0 80218B00 0C052B02 */  jal       func_8014AC08
/* 59F1E4 80218B04 00000000 */   nop
/* 59F1E8 80218B08 080862CB */  j         .L80218B2C
/* 59F1EC 80218B0C 0000102D */   daddu    $v0, $zero, $zero
.L80218B10:
/* 59F1F0 80218B10 AFA20010 */  sw        $v0, 0x10($sp)
/* 59F1F4 80218B14 0000202D */  daddu     $a0, $zero, $zero
/* 59F1F8 80218B18 2405000D */  addiu     $a1, $zero, 0xd
/* 59F1FC 80218B1C 24060001 */  addiu     $a2, $zero, 1
/* 59F200 80218B20 0C052A46 */  jal       set_music_track
/* 59F204 80218B24 240701F4 */   addiu    $a3, $zero, 0x1f4
/* 59F208 80218B28 24020002 */  addiu     $v0, $zero, 2
.L80218B2C:
/* 59F20C 80218B2C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 59F210 80218B30 03E00008 */  jr        $ra
/* 59F214 80218B34 27BD0020 */   addiu    $sp, $sp, 0x20
