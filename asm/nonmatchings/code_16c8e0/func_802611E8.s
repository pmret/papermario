.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802611E8
/* 18FAC8 802611E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 18FACC 802611EC AFB20018 */  sw        $s2, 0x18($sp)
/* 18FAD0 802611F0 0080902D */  daddu     $s2, $a0, $zero
/* 18FAD4 802611F4 3C048011 */  lui       $a0, %hi(gPlayerData)
/* 18FAD8 802611F8 2484F290 */  addiu     $a0, $a0, %lo(gPlayerData)
/* 18FADC 802611FC AFB10014 */  sw        $s1, 0x14($sp)
/* 18FAE0 80261200 3C118009 */  lui       $s1, 0x8009
/* 18FAE4 80261204 26318B80 */  addiu     $s1, $s1, -0x7480
/* 18FAE8 80261208 AFBF001C */  sw        $ra, 0x1c($sp)
/* 18FAEC 8026120C AFB00010 */  sw        $s0, 0x10($sp)
/* 18FAF0 80261210 90820002 */  lbu       $v0, 2($a0)
/* 18FAF4 80261214 9223001B */  lbu       $v1, 0x1b($s1)
/* 18FAF8 80261218 00431021 */  addu      $v0, $v0, $v1
/* 18FAFC 8026121C A0820002 */  sb        $v0, 2($a0)
/* 18FB00 80261220 00021600 */  sll       $v0, $v0, 0x18
/* 18FB04 80261224 80830003 */  lb        $v1, 3($a0)
/* 18FB08 80261228 00021603 */  sra       $v0, $v0, 0x18
/* 18FB0C 8026122C 0062182A */  slt       $v1, $v1, $v0
/* 18FB10 80261230 90820003 */  lbu       $v0, 3($a0)
/* 18FB14 80261234 10600002 */  beqz      $v1, .L80261240
/* 18FB18 80261238 0080802D */   daddu    $s0, $a0, $zero
/* 18FB1C 8026123C A0820002 */  sb        $v0, 2($a0)
.L80261240:
/* 18FB20 80261240 0C039D91 */  jal       find_item
/* 18FB24 80261244 24040095 */   addiu    $a0, $zero, 0x95
/* 18FB28 80261248 00021040 */  sll       $v0, $v0, 1
/* 18FB2C 8026124C 00501021 */  addu      $v0, $v0, $s0
/* 18FB30 80261250 0C039DB3 */  jal       sort_items
/* 18FB34 80261254 A44001B4 */   sh       $zero, 0x1b4($v0)
/* 18FB38 80261258 8223001B */  lb        $v1, 0x1b($s1)
/* 18FB3C 8026125C AE430090 */  sw        $v1, 0x90($s2)
/* 18FB40 80261260 8FBF001C */  lw        $ra, 0x1c($sp)
/* 18FB44 80261264 8FB20018 */  lw        $s2, 0x18($sp)
/* 18FB48 80261268 8FB10014 */  lw        $s1, 0x14($sp)
/* 18FB4C 8026126C 8FB00010 */  lw        $s0, 0x10($sp)
/* 18FB50 80261270 24020002 */  addiu     $v0, $zero, 2
/* 18FB54 80261274 03E00008 */  jr        $ra
/* 18FB58 80261278 27BD0020 */   addiu    $sp, $sp, 0x20
