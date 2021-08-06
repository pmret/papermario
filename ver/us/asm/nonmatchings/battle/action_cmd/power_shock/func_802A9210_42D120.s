.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9210_42D120
/* 42D120 802A9210 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42D124 802A9214 AFB20018 */  sw        $s2, 0x18($sp)
/* 42D128 802A9218 0080902D */  daddu     $s2, $a0, $zero
/* 42D12C 802A921C AFB10014 */  sw        $s1, 0x14($sp)
/* 42D130 802A9220 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 42D134 802A9224 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 42D138 802A9228 AFB3001C */  sw        $s3, 0x1c($sp)
/* 42D13C 802A922C 3C13800E */  lui       $s3, %hi(gBattleStatus)
/* 42D140 802A9230 2673C070 */  addiu     $s3, $s3, %lo(gBattleStatus)
/* 42D144 802A9234 AFBF0020 */  sw        $ra, 0x20($sp)
/* 42D148 802A9238 AFB00010 */  sw        $s0, 0x10($sp)
/* 42D14C 802A923C 82620083 */  lb        $v0, 0x83($s3)
/* 42D150 802A9240 8E50000C */  lw        $s0, 0xc($s2)
/* 42D154 802A9244 10400029 */  beqz      $v0, .L802A92EC
/* 42D158 802A9248 0260182D */   daddu    $v1, $s3, $zero
/* 42D15C 802A924C 0C09A216 */  jal       func_80268858
/* 42D160 802A9250 00000000 */   nop
/* 42D164 802A9254 8E050000 */  lw        $a1, ($s0)
/* 42D168 802A9258 26100004 */  addiu     $s0, $s0, 4
/* 42D16C 802A925C 0C0B1EAF */  jal       get_variable
/* 42D170 802A9260 0240202D */   daddu    $a0, $s2, $zero
/* 42D174 802A9264 A622004E */  sh        $v0, 0x4e($s1)
/* 42D178 802A9268 8E050000 */  lw        $a1, ($s0)
/* 42D17C 802A926C 26100004 */  addiu     $s0, $s0, 4
/* 42D180 802A9270 0C0B1EAF */  jal       get_variable
/* 42D184 802A9274 0240202D */   daddu    $a0, $s2, $zero
/* 42D188 802A9278 A6220052 */  sh        $v0, 0x52($s1)
/* 42D18C 802A927C 8E050000 */  lw        $a1, ($s0)
/* 42D190 802A9280 26100004 */  addiu     $s0, $s0, 4
/* 42D194 802A9284 0C0B1EAF */  jal       get_variable
/* 42D198 802A9288 0240202D */   daddu    $a0, $s2, $zero
/* 42D19C 802A928C 00022400 */  sll       $a0, $v0, 0x10
/* 42D1A0 802A9290 00042403 */  sra       $a0, $a0, 0x10
/* 42D1A4 802A9294 0C09A089 */  jal       func_80268224
/* 42D1A8 802A9298 A6220050 */   sh       $v0, 0x50($s1)
/* 42D1AC 802A929C A6220050 */  sh        $v0, 0x50($s1)
/* 42D1B0 802A92A0 8E050000 */  lw        $a1, ($s0)
/* 42D1B4 802A92A4 0C0B1EAF */  jal       get_variable
/* 42D1B8 802A92A8 0240202D */   daddu    $a0, $s2, $zero
/* 42D1BC 802A92AC 3C04FFFF */  lui       $a0, 0xffff
/* 42D1C0 802A92B0 34847FFF */  ori       $a0, $a0, 0x7fff
/* 42D1C4 802A92B4 A6220064 */  sh        $v0, 0x64($s1)
/* 42D1C8 802A92B8 A2200060 */  sb        $zero, 0x60($s1)
/* 42D1CC 802A92BC A6200044 */  sh        $zero, 0x44($s1)
/* 42D1D0 802A92C0 A6200048 */  sh        $zero, 0x48($s1)
/* 42D1D4 802A92C4 8E620000 */  lw        $v0, ($s3)
/* 42D1D8 802A92C8 2403000A */  addiu     $v1, $zero, 0xa
/* 42D1DC 802A92CC A2600081 */  sb        $zero, 0x81($s3)
/* 42D1E0 802A92D0 A2600086 */  sb        $zero, 0x86($s3)
/* 42D1E4 802A92D4 A623004C */  sh        $v1, 0x4c($s1)
/* 42D1E8 802A92D8 00441024 */  and       $v0, $v0, $a0
/* 42D1EC 802A92DC 0C09A446 */  jal       func_80269118
/* 42D1F0 802A92E0 AE620000 */   sw       $v0, ($s3)
/* 42D1F4 802A92E4 080AA4BD */  j         .L802A92F4
/* 42D1F8 802A92E8 24020002 */   addiu    $v0, $zero, 2
.L802A92EC:
/* 42D1FC 802A92EC A0600081 */  sb        $zero, 0x81($v1)
/* 42D200 802A92F0 24020002 */  addiu     $v0, $zero, 2
.L802A92F4:
/* 42D204 802A92F4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42D208 802A92F8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 42D20C 802A92FC 8FB20018 */  lw        $s2, 0x18($sp)
/* 42D210 802A9300 8FB10014 */  lw        $s1, 0x14($sp)
/* 42D214 802A9304 8FB00010 */  lw        $s0, 0x10($sp)
/* 42D218 802A9308 03E00008 */  jr        $ra
/* 42D21C 802A930C 27BD0028 */   addiu    $sp, $sp, 0x28
