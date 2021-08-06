.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A91E0_423E50
/* 423E50 802A91E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 423E54 802A91E4 AFB20018 */  sw        $s2, 0x18($sp)
/* 423E58 802A91E8 0080902D */  daddu     $s2, $a0, $zero
/* 423E5C 802A91EC AFB10014 */  sw        $s1, 0x14($sp)
/* 423E60 802A91F0 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 423E64 802A91F4 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 423E68 802A91F8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 423E6C 802A91FC 3C13800E */  lui       $s3, %hi(gBattleStatus)
/* 423E70 802A9200 2673C070 */  addiu     $s3, $s3, %lo(gBattleStatus)
/* 423E74 802A9204 AFB40020 */  sw        $s4, 0x20($sp)
/* 423E78 802A9208 AFBF0024 */  sw        $ra, 0x24($sp)
/* 423E7C 802A920C AFB00010 */  sw        $s0, 0x10($sp)
/* 423E80 802A9210 82620083 */  lb        $v0, 0x83($s3)
/* 423E84 802A9214 8E50000C */  lw        $s0, 0xc($s2)
/* 423E88 802A9218 14400004 */  bnez      $v0, .L802A922C
/* 423E8C 802A921C 0260A02D */   daddu    $s4, $s3, $zero
/* 423E90 802A9220 A2600081 */  sb        $zero, 0x81($s3)
/* 423E94 802A9224 080AA4B4 */  j         .L802A92D0
/* 423E98 802A9228 24020002 */   addiu    $v0, $zero, 2
.L802A922C:
/* 423E9C 802A922C 0C09A216 */  jal       func_80268858
/* 423EA0 802A9230 00000000 */   nop
/* 423EA4 802A9234 8E050000 */  lw        $a1, ($s0)
/* 423EA8 802A9238 26100004 */  addiu     $s0, $s0, 4
/* 423EAC 802A923C 0C0B1EAF */  jal       get_variable
/* 423EB0 802A9240 0240202D */   daddu    $a0, $s2, $zero
/* 423EB4 802A9244 A622004E */  sh        $v0, 0x4e($s1)
/* 423EB8 802A9248 8E050000 */  lw        $a1, ($s0)
/* 423EBC 802A924C 26100004 */  addiu     $s0, $s0, 4
/* 423EC0 802A9250 0C0B1EAF */  jal       get_variable
/* 423EC4 802A9254 0240202D */   daddu    $a0, $s2, $zero
/* 423EC8 802A9258 A6220052 */  sh        $v0, 0x52($s1)
/* 423ECC 802A925C 8E050000 */  lw        $a1, ($s0)
/* 423ED0 802A9260 0C0B1EAF */  jal       get_variable
/* 423ED4 802A9264 0240202D */   daddu    $a0, $s2, $zero
/* 423ED8 802A9268 00022400 */  sll       $a0, $v0, 0x10
/* 423EDC 802A926C 00042403 */  sra       $a0, $a0, 0x10
/* 423EE0 802A9270 0C09A089 */  jal       func_80268224
/* 423EE4 802A9274 A6220050 */   sh       $v0, 0x50($s1)
/* 423EE8 802A9278 86230064 */  lh        $v1, 0x64($s1)
/* 423EEC 802A927C A6220050 */  sh        $v0, 0x50($s1)
/* 423EF0 802A9280 A2200060 */  sb        $zero, 0x60($s1)
/* 423EF4 802A9284 A6200044 */  sh        $zero, 0x44($s1)
/* 423EF8 802A9288 A6200048 */  sh        $zero, 0x48($s1)
/* 423EFC 802A928C A2600081 */  sb        $zero, 0x81($s3)
/* 423F00 802A9290 14600003 */  bnez      $v1, .L802A92A0
/* 423F04 802A9294 A2600086 */   sb       $zero, 0x86($s3)
/* 423F08 802A9298 080AA4AA */  j         .L802A92A8
/* 423F0C 802A929C A2600084 */   sb       $zero, 0x84($s3)
.L802A92A0:
/* 423F10 802A92A0 24020003 */  addiu     $v0, $zero, 3
/* 423F14 802A92A4 A2820084 */  sb        $v0, 0x84($s4)
.L802A92A8:
/* 423F18 802A92A8 3C06FFFF */  lui       $a2, 0xffff
/* 423F1C 802A92AC 34C67FFF */  ori       $a2, $a2, 0x7fff
/* 423F20 802A92B0 24020002 */  addiu     $v0, $zero, 2
/* 423F24 802A92B4 3C05800E */  lui       $a1, %hi(gBattleStatus)
/* 423F28 802A92B8 24A5C070 */  addiu     $a1, $a1, %lo(gBattleStatus)
/* 423F2C 802A92BC 8CA30000 */  lw        $v1, ($a1)
/* 423F30 802A92C0 2404000A */  addiu     $a0, $zero, 0xa
/* 423F34 802A92C4 A624004C */  sh        $a0, 0x4c($s1)
/* 423F38 802A92C8 00661824 */  and       $v1, $v1, $a2
/* 423F3C 802A92CC ACA30000 */  sw        $v1, ($a1)
.L802A92D0:
/* 423F40 802A92D0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 423F44 802A92D4 8FB40020 */  lw        $s4, 0x20($sp)
/* 423F48 802A92D8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 423F4C 802A92DC 8FB20018 */  lw        $s2, 0x18($sp)
/* 423F50 802A92E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 423F54 802A92E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 423F58 802A92E8 03E00008 */  jr        $ra
/* 423F5C 802A92EC 27BD0028 */   addiu    $sp, $sp, 0x28
