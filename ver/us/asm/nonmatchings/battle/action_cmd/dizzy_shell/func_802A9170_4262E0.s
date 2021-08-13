.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9170_4262E0
/* 4262E0 802A9170 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4262E4 802A9174 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4262E8 802A9178 0080982D */  daddu     $s3, $a0, $zero
/* 4262EC 802A917C AFB10014 */  sw        $s1, 0x14($sp)
/* 4262F0 802A9180 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 4262F4 802A9184 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 4262F8 802A9188 AFB20018 */  sw        $s2, 0x18($sp)
/* 4262FC 802A918C 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 426300 802A9190 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 426304 802A9194 AFBF0020 */  sw        $ra, 0x20($sp)
/* 426308 802A9198 AFB00010 */  sw        $s0, 0x10($sp)
/* 42630C 802A919C 82420083 */  lb        $v0, 0x83($s2)
/* 426310 802A91A0 8E70000C */  lw        $s0, 0xc($s3)
/* 426314 802A91A4 10400030 */  beqz      $v0, .L802A9268
/* 426318 802A91A8 0240182D */   daddu    $v1, $s2, $zero
/* 42631C 802A91AC 0C09A216 */  jal       func_80268858
/* 426320 802A91B0 00000000 */   nop
/* 426324 802A91B4 8E050000 */  lw        $a1, ($s0)
/* 426328 802A91B8 26100004 */  addiu     $s0, $s0, 4
/* 42632C 802A91BC 0C0B1EAF */  jal       get_variable
/* 426330 802A91C0 0260202D */   daddu    $a0, $s3, $zero
/* 426334 802A91C4 A622004E */  sh        $v0, 0x4e($s1)
/* 426338 802A91C8 8E050000 */  lw        $a1, ($s0)
/* 42633C 802A91CC 26100004 */  addiu     $s0, $s0, 4
/* 426340 802A91D0 0C0B1EAF */  jal       get_variable
/* 426344 802A91D4 0260202D */   daddu    $a0, $s3, $zero
/* 426348 802A91D8 A6220052 */  sh        $v0, 0x52($s1)
/* 42634C 802A91DC 8E050000 */  lw        $a1, ($s0)
/* 426350 802A91E0 26100004 */  addiu     $s0, $s0, 4
/* 426354 802A91E4 0C0B1EAF */  jal       get_variable
/* 426358 802A91E8 0260202D */   daddu    $a0, $s3, $zero
/* 42635C 802A91EC 00022400 */  sll       $a0, $v0, 0x10
/* 426360 802A91F0 00042403 */  sra       $a0, $a0, 0x10
/* 426364 802A91F4 0C09A089 */  jal       func_80268224
/* 426368 802A91F8 A6220050 */   sh       $v0, 0x50($s1)
/* 42636C 802A91FC A6220050 */  sh        $v0, 0x50($s1)
/* 426370 802A9200 8E050000 */  lw        $a1, ($s0)
/* 426374 802A9204 0C0B1EAF */  jal       get_variable
/* 426378 802A9208 0260202D */   daddu    $a0, $s3, $zero
/* 42637C 802A920C 3C05FFFF */  lui       $a1, 0xffff
/* 426380 802A9210 34A57FFF */  ori       $a1, $a1, 0x7fff
/* 426384 802A9214 A6220064 */  sh        $v0, 0x64($s1)
/* 426388 802A9218 A2200060 */  sb        $zero, 0x60($s1)
/* 42638C 802A921C A6200044 */  sh        $zero, 0x44($s1)
/* 426390 802A9220 A6200048 */  sh        $zero, 0x48($s1)
/* 426394 802A9224 A2400081 */  sb        $zero, 0x81($s2)
/* 426398 802A9228 82220080 */  lb        $v0, 0x80($s1)
/* 42639C 802A922C 2403007F */  addiu     $v1, $zero, 0x7f
/* 4263A0 802A9230 A2430086 */  sb        $v1, 0x86($s2)
/* 4263A4 802A9234 8E430000 */  lw        $v1, ($s2)
/* 4263A8 802A9238 2442FFFF */  addiu     $v0, $v0, -1
/* 4263AC 802A923C 00021040 */  sll       $v0, $v0, 1
/* 4263B0 802A9240 00511021 */  addu      $v0, $v0, $s1
/* 4263B4 802A9244 00651824 */  and       $v1, $v1, $a1
/* 4263B8 802A9248 90440075 */  lbu       $a0, 0x75($v0)
/* 4263BC 802A924C 2402000A */  addiu     $v0, $zero, 0xa
/* 4263C0 802A9250 AE430000 */  sw        $v1, ($s2)
/* 4263C4 802A9254 A622004C */  sh        $v0, 0x4c($s1)
/* 4263C8 802A9258 0C09A446 */  jal       func_80269118
/* 4263CC 802A925C A2440082 */   sb       $a0, 0x82($s2)
/* 4263D0 802A9260 080AA49C */  j         .L802A9270
/* 4263D4 802A9264 24020002 */   addiu    $v0, $zero, 2
.L802A9268:
/* 4263D8 802A9268 A0600081 */  sb        $zero, 0x81($v1)
/* 4263DC 802A926C 24020002 */  addiu     $v0, $zero, 2
.L802A9270:
/* 4263E0 802A9270 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4263E4 802A9274 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4263E8 802A9278 8FB20018 */  lw        $s2, 0x18($sp)
/* 4263EC 802A927C 8FB10014 */  lw        $s1, 0x14($sp)
/* 4263F0 802A9280 8FB00010 */  lw        $s0, 0x10($sp)
/* 4263F4 802A9284 03E00008 */  jr        $ra
/* 4263F8 802A9288 27BD0028 */   addiu    $sp, $sp, 0x28
