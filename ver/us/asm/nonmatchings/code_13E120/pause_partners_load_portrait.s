.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_partners_load_portrait
/* 13E120 8024ADE0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 13E124 8024ADE4 AFB20020 */  sw        $s2, 0x20($sp)
/* 13E128 8024ADE8 0080902D */  daddu     $s2, $a0, $zero
/* 13E12C 8024ADEC 3C078025 */  lui       $a3, %hi(D_8024F7C0)
/* 13E130 8024ADF0 24E7F7C0 */  addiu     $a3, $a3, %lo(D_8024F7C0)
/* 13E134 8024ADF4 00121080 */  sll       $v0, $s2, 2
/* 13E138 8024ADF8 AFBF0024 */  sw        $ra, 0x24($sp)
/* 13E13C 8024ADFC AFB1001C */  sw        $s1, 0x1c($sp)
/* 13E140 8024AE00 AFB00018 */  sw        $s0, 0x18($sp)
/* 13E144 8024AE04 8CE30000 */  lw        $v1, ($a3)
/* 13E148 8024AE08 3C068027 */  lui       $a2, %hi(D_80270680)
/* 13E14C 8024AE0C 00C23021 */  addu      $a2, $a2, $v0
/* 13E150 8024AE10 8CC60680 */  lw        $a2, %lo(D_80270680)($a2)
/* 13E154 8024AE14 3C118027 */  lui       $s1, %hi(D_80270680)
/* 13E158 8024AE18 26310680 */  addiu     $s1, $s1, %lo(D_80270680)
/* 13E15C 8024AE1C 1066000E */  beq       $v1, $a2, .L8024AE58
/* 13E160 8024AE20 00061080 */   sll      $v0, $a2, 2
/* 13E164 8024AE24 3C048025 */  lui       $a0, %hi(D_8024F718)
/* 13E168 8024AE28 00822021 */  addu      $a0, $a0, $v0
/* 13E16C 8024AE2C 8C84F718 */  lw        $a0, %lo(D_8024F718)($a0)
/* 13E170 8024AE30 27A50010 */  addiu     $a1, $sp, 0x10
/* 13E174 8024AE34 0C016B3A */  jal       load_asset_by_name
/* 13E178 8024AE38 ACE60000 */   sw       $a2, ($a3)
/* 13E17C 8024AE3C 0040802D */  daddu     $s0, $v0, $zero
/* 13E180 8024AE40 3C058025 */  lui       $a1, %hi(D_8024F744)
/* 13E184 8024AE44 8CA5F744 */  lw        $a1, %lo(D_8024F744)($a1)
/* 13E188 8024AE48 0C01BB7C */  jal       decode_yay0
/* 13E18C 8024AE4C 0200202D */   daddu    $a0, $s0, $zero
/* 13E190 8024AE50 0C00AB1E */  jal       general_heap_free
/* 13E194 8024AE54 0200202D */   daddu    $a0, $s0, $zero
.L8024AE58:
/* 13E198 8024AE58 3C038027 */  lui       $v1, %hi(D_802706B0)
/* 13E19C 8024AE5C 8C6306B0 */  lw        $v1, %lo(D_802706B0)($v1)
/* 13E1A0 8024AE60 26420001 */  addiu     $v0, $s2, 1
/* 13E1A4 8024AE64 14600002 */  bnez      $v1, .L8024AE70
/* 13E1A8 8024AE68 0043001A */   div      $zero, $v0, $v1
/* 13E1AC 8024AE6C 0007000D */  break     7
.L8024AE70:
/* 13E1B0 8024AE70 2401FFFF */   addiu    $at, $zero, -1
/* 13E1B4 8024AE74 14610004 */  bne       $v1, $at, .L8024AE88
/* 13E1B8 8024AE78 3C018000 */   lui      $at, 0x8000
/* 13E1BC 8024AE7C 14410002 */  bne       $v0, $at, .L8024AE88
/* 13E1C0 8024AE80 00000000 */   nop
/* 13E1C4 8024AE84 0006000D */  break     6
.L8024AE88:
/* 13E1C8 8024AE88 00001810 */   mfhi     $v1
/* 13E1CC 8024AE8C 3C068025 */  lui       $a2, %hi(D_8024F7C4)
/* 13E1D0 8024AE90 24C6F7C4 */  addiu     $a2, $a2, %lo(D_8024F7C4)
/* 13E1D4 8024AE94 8CC20000 */  lw        $v0, ($a2)
/* 13E1D8 8024AE98 00031880 */  sll       $v1, $v1, 2
/* 13E1DC 8024AE9C 00711821 */  addu      $v1, $v1, $s1
/* 13E1E0 8024AEA0 8C630000 */  lw        $v1, ($v1)
/* 13E1E4 8024AEA4 1043000E */  beq       $v0, $v1, .L8024AEE0
/* 13E1E8 8024AEA8 00031080 */   sll      $v0, $v1, 2
/* 13E1EC 8024AEAC 3C048025 */  lui       $a0, %hi(D_8024F718)
/* 13E1F0 8024AEB0 00822021 */  addu      $a0, $a0, $v0
/* 13E1F4 8024AEB4 8C84F718 */  lw        $a0, %lo(D_8024F718)($a0)
/* 13E1F8 8024AEB8 27A50010 */  addiu     $a1, $sp, 0x10
/* 13E1FC 8024AEBC 0C016B3A */  jal       load_asset_by_name
/* 13E200 8024AEC0 ACC30000 */   sw       $v1, ($a2)
/* 13E204 8024AEC4 0040802D */  daddu     $s0, $v0, $zero
/* 13E208 8024AEC8 3C058025 */  lui       $a1, %hi(D_8024F748)
/* 13E20C 8024AECC 8CA5F748 */  lw        $a1, %lo(D_8024F748)($a1)
/* 13E210 8024AED0 0C01BB7C */  jal       decode_yay0
/* 13E214 8024AED4 0200202D */   daddu    $a0, $s0, $zero
/* 13E218 8024AED8 0C00AB1E */  jal       general_heap_free
/* 13E21C 8024AEDC 0200202D */   daddu    $a0, $s0, $zero
.L8024AEE0:
/* 13E220 8024AEE0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 13E224 8024AEE4 8FB20020 */  lw        $s2, 0x20($sp)
/* 13E228 8024AEE8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 13E22C 8024AEEC 8FB00018 */  lw        $s0, 0x18($sp)
/* 13E230 8024AEF0 03E00008 */  jr        $ra
/* 13E234 8024AEF4 27BD0028 */   addiu    $sp, $sp, 0x28
