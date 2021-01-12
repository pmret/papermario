.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802423F0_7ED100
/* 7ED100 802423F0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7ED104 802423F4 AFB20018 */  sw        $s2, 0x18($sp)
/* 7ED108 802423F8 3C12E200 */  lui       $s2, 0xe200
/* 7ED10C 802423FC 36521D00 */  ori       $s2, $s2, 0x1d00
/* 7ED110 80242400 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7ED114 80242404 3C13E200 */  lui       $s3, 0xe200
/* 7ED118 80242408 3673001C */  ori       $s3, $s3, 0x1c
/* 7ED11C 8024240C 3C060F0A */  lui       $a2, 0xf0a
/* 7ED120 80242410 34C64010 */  ori       $a2, $a2, 0x4010
/* 7ED124 80242414 3C08FCFF */  lui       $t0, 0xfcff
/* 7ED128 80242418 3508FFFF */  ori       $t0, $t0, 0xffff
/* 7ED12C 8024241C 3C07FFFD */  lui       $a3, 0xfffd
/* 7ED130 80242420 34E7FEFF */  ori       $a3, $a3, 0xfeff
/* 7ED134 80242424 AFB00010 */  sw        $s0, 0x10($sp)
/* 7ED138 80242428 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* 7ED13C 8024242C 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* 7ED140 80242430 240400D6 */  addiu     $a0, $zero, 0xd6
/* 7ED144 80242434 24030004 */  addiu     $v1, $zero, 4
/* 7ED148 80242438 AFBF0020 */  sw        $ra, 0x20($sp)
/* 7ED14C 8024243C AFB10014 */  sw        $s1, 0x14($sp)
/* 7ED150 80242440 8E020000 */  lw        $v0, ($s0)
/* 7ED154 80242444 3C11E700 */  lui       $s1, 0xe700
/* 7ED158 80242448 0040282D */  daddu     $a1, $v0, $zero
/* 7ED15C 8024244C 24420008 */  addiu     $v0, $v0, 8
/* 7ED160 80242450 AE020000 */  sw        $v0, ($s0)
/* 7ED164 80242454 ACA30004 */  sw        $v1, 4($a1)
/* 7ED168 80242458 24430008 */  addiu     $v1, $v0, 8
/* 7ED16C 8024245C ACB20000 */  sw        $s2, ($a1)
/* 7ED170 80242460 AE030000 */  sw        $v1, ($s0)
/* 7ED174 80242464 3C03EE00 */  lui       $v1, 0xee00
/* 7ED178 80242468 AC430000 */  sw        $v1, ($v0)
/* 7ED17C 8024246C 3C037FF0 */  lui       $v1, 0x7ff0
/* 7ED180 80242470 AC430004 */  sw        $v1, 4($v0)
/* 7ED184 80242474 24430010 */  addiu     $v1, $v0, 0x10
/* 7ED188 80242478 AE030000 */  sw        $v1, ($s0)
/* 7ED18C 8024247C 24430018 */  addiu     $v1, $v0, 0x18
/* 7ED190 80242480 AC530008 */  sw        $s3, 8($v0)
/* 7ED194 80242484 AC46000C */  sw        $a2, 0xc($v0)
/* 7ED198 80242488 AE030000 */  sw        $v1, ($s0)
/* 7ED19C 8024248C 24430020 */  addiu     $v1, $v0, 0x20
/* 7ED1A0 80242490 AC480010 */  sw        $t0, 0x10($v0)
/* 7ED1A4 80242494 AC470014 */  sw        $a3, 0x14($v0)
/* 7ED1A8 80242498 AE030000 */  sw        $v1, ($s0)
/* 7ED1AC 8024249C 3C03FA00 */  lui       $v1, 0xfa00
/* 7ED1B0 802424A0 AC430018 */  sw        $v1, 0x18($v0)
/* 7ED1B4 802424A4 34038000 */  ori       $v1, $zero, 0x8000
/* 7ED1B8 802424A8 AC43001C */  sw        $v1, 0x1c($v0)
/* 7ED1BC 802424AC 24430028 */  addiu     $v1, $v0, 0x28
/* 7ED1C0 802424B0 AE030000 */  sw        $v1, ($s0)
/* 7ED1C4 802424B4 AC510020 */  sw        $s1, 0x20($v0)
/* 7ED1C8 802424B8 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 7ED1CC 802424BC AC400024 */   sw       $zero, 0x24($v0)
/* 7ED1D0 802424C0 0C046B4C */  jal       get_model_from_list_index
/* 7ED1D4 802424C4 0040202D */   daddu    $a0, $v0, $zero
/* 7ED1D8 802424C8 3C07E300 */  lui       $a3, 0xe300
/* 7ED1DC 802424CC 34E70A01 */  ori       $a3, $a3, 0xa01
/* 7ED1E0 802424D0 3C080C18 */  lui       $t0, 0xc18
/* 7ED1E4 802424D4 350849D8 */  ori       $t0, $t0, 0x49d8
/* 7ED1E8 802424D8 0200202D */  daddu     $a0, $s0, $zero
/* 7ED1EC 802424DC 8E030000 */  lw        $v1, ($s0)
/* 7ED1F0 802424E0 3C05DE00 */  lui       $a1, 0xde00
/* 7ED1F4 802424E4 0060302D */  daddu     $a2, $v1, $zero
/* 7ED1F8 802424E8 24630008 */  addiu     $v1, $v1, 8
/* 7ED1FC 802424EC AC830000 */  sw        $v1, ($a0)
/* 7ED200 802424F0 ACC50000 */  sw        $a1, ($a2)
/* 7ED204 802424F4 24650008 */  addiu     $a1, $v1, 8
/* 7ED208 802424F8 AC850000 */  sw        $a1, ($a0)
/* 7ED20C 802424FC 8C450008 */  lw        $a1, 8($v0)
/* 7ED210 80242500 24620010 */  addiu     $v0, $v1, 0x10
/* 7ED214 80242504 AC820000 */  sw        $v0, ($a0)
/* 7ED218 80242508 8CA50004 */  lw        $a1, 4($a1)
/* 7ED21C 8024250C 24620018 */  addiu     $v0, $v1, 0x18
/* 7ED220 80242510 AC820000 */  sw        $v0, ($a0)
/* 7ED224 80242514 8CA50000 */  lw        $a1, ($a1)
/* 7ED228 80242518 24620020 */  addiu     $v0, $v1, 0x20
/* 7ED22C 8024251C AC820000 */  sw        $v0, ($a0)
/* 7ED230 80242520 3C020010 */  lui       $v0, 0x10
/* 7ED234 80242524 ACC50004 */  sw        $a1, 4($a2)
/* 7ED238 80242528 240500D6 */  addiu     $a1, $zero, 0xd6
/* 7ED23C 8024252C AC710000 */  sw        $s1, ($v1)
/* 7ED240 80242530 AC600004 */  sw        $zero, 4($v1)
/* 7ED244 80242534 AC670008 */  sw        $a3, 8($v1)
/* 7ED248 80242538 AC62000C */  sw        $v0, 0xc($v1)
/* 7ED24C 8024253C AC720010 */  sw        $s2, 0x10($v1)
/* 7ED250 80242540 AC600014 */  sw        $zero, 0x14($v1)
/* 7ED254 80242544 AC730018 */  sw        $s3, 0x18($v1)
/* 7ED258 80242548 0C0475CB */  jal       func_8011D72C
/* 7ED25C 8024254C AC68001C */   sw       $t0, 0x1c($v1)
/* 7ED260 80242550 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7ED264 80242554 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7ED268 80242558 8FB20018 */  lw        $s2, 0x18($sp)
/* 7ED26C 8024255C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7ED270 80242560 8FB00010 */  lw        $s0, 0x10($sp)
/* 7ED274 80242564 03E00008 */  jr        $ra
/* 7ED278 80242568 27BD0028 */   addiu    $sp, $sp, 0x28
/* 7ED27C 8024256C 00000000 */  nop
