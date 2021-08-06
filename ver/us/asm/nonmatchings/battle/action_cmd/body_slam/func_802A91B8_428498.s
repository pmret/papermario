.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A91B8_428498
/* 428498 802A91B8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42849C 802A91BC AFB3001C */  sw        $s3, 0x1c($sp)
/* 4284A0 802A91C0 0080982D */  daddu     $s3, $a0, $zero
/* 4284A4 802A91C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 4284A8 802A91C8 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 4284AC 802A91CC 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 4284B0 802A91D0 AFB20018 */  sw        $s2, 0x18($sp)
/* 4284B4 802A91D4 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 4284B8 802A91D8 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 4284BC 802A91DC AFBF0020 */  sw        $ra, 0x20($sp)
/* 4284C0 802A91E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 4284C4 802A91E4 82420083 */  lb        $v0, 0x83($s2)
/* 4284C8 802A91E8 8E70000C */  lw        $s0, 0xc($s3)
/* 4284CC 802A91EC 10400030 */  beqz      $v0, .L802A92B0
/* 4284D0 802A91F0 0240182D */   daddu    $v1, $s2, $zero
/* 4284D4 802A91F4 0C09A216 */  jal       func_80268858
/* 4284D8 802A91F8 00000000 */   nop
/* 4284DC 802A91FC 8E050000 */  lw        $a1, ($s0)
/* 4284E0 802A9200 26100004 */  addiu     $s0, $s0, 4
/* 4284E4 802A9204 0C0B1EAF */  jal       get_variable
/* 4284E8 802A9208 0260202D */   daddu    $a0, $s3, $zero
/* 4284EC 802A920C A622004E */  sh        $v0, 0x4e($s1)
/* 4284F0 802A9210 8E050000 */  lw        $a1, ($s0)
/* 4284F4 802A9214 26100004 */  addiu     $s0, $s0, 4
/* 4284F8 802A9218 0C0B1EAF */  jal       get_variable
/* 4284FC 802A921C 0260202D */   daddu    $a0, $s3, $zero
/* 428500 802A9220 A6220052 */  sh        $v0, 0x52($s1)
/* 428504 802A9224 8E050000 */  lw        $a1, ($s0)
/* 428508 802A9228 26100004 */  addiu     $s0, $s0, 4
/* 42850C 802A922C 0C0B1EAF */  jal       get_variable
/* 428510 802A9230 0260202D */   daddu    $a0, $s3, $zero
/* 428514 802A9234 00022400 */  sll       $a0, $v0, 0x10
/* 428518 802A9238 00042403 */  sra       $a0, $a0, 0x10
/* 42851C 802A923C 0C09A089 */  jal       func_80268224
/* 428520 802A9240 A6220050 */   sh       $v0, 0x50($s1)
/* 428524 802A9244 A6220050 */  sh        $v0, 0x50($s1)
/* 428528 802A9248 8E050000 */  lw        $a1, ($s0)
/* 42852C 802A924C 0C0B1EAF */  jal       get_variable
/* 428530 802A9250 0260202D */   daddu    $a0, $s3, $zero
/* 428534 802A9254 3C05FFFF */  lui       $a1, 0xffff
/* 428538 802A9258 34A57FFF */  ori       $a1, $a1, 0x7fff
/* 42853C 802A925C A6220064 */  sh        $v0, 0x64($s1)
/* 428540 802A9260 A2200060 */  sb        $zero, 0x60($s1)
/* 428544 802A9264 A6200044 */  sh        $zero, 0x44($s1)
/* 428548 802A9268 A6200048 */  sh        $zero, 0x48($s1)
/* 42854C 802A926C A2400081 */  sb        $zero, 0x81($s2)
/* 428550 802A9270 82220080 */  lb        $v0, 0x80($s1)
/* 428554 802A9274 2403007F */  addiu     $v1, $zero, 0x7f
/* 428558 802A9278 A2430086 */  sb        $v1, 0x86($s2)
/* 42855C 802A927C 8E430000 */  lw        $v1, ($s2)
/* 428560 802A9280 2442FFFF */  addiu     $v0, $v0, -1
/* 428564 802A9284 00021040 */  sll       $v0, $v0, 1
/* 428568 802A9288 00511021 */  addu      $v0, $v0, $s1
/* 42856C 802A928C 00651824 */  and       $v1, $v1, $a1
/* 428570 802A9290 90440075 */  lbu       $a0, 0x75($v0)
/* 428574 802A9294 2402000A */  addiu     $v0, $zero, 0xa
/* 428578 802A9298 AE430000 */  sw        $v1, ($s2)
/* 42857C 802A929C A622004C */  sh        $v0, 0x4c($s1)
/* 428580 802A92A0 0C09A446 */  jal       func_80269118
/* 428584 802A92A4 A2440082 */   sb       $a0, 0x82($s2)
/* 428588 802A92A8 080AA4AE */  j         .L802A92B8
/* 42858C 802A92AC 24020002 */   addiu    $v0, $zero, 2
.L802A92B0:
/* 428590 802A92B0 A0600081 */  sb        $zero, 0x81($v1)
/* 428594 802A92B4 24020002 */  addiu     $v0, $zero, 2
.L802A92B8:
/* 428598 802A92B8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42859C 802A92BC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4285A0 802A92C0 8FB20018 */  lw        $s2, 0x18($sp)
/* 4285A4 802A92C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 4285A8 802A92C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 4285AC 802A92CC 03E00008 */  jr        $ra
/* 4285B0 802A92D0 27BD0028 */   addiu    $sp, $sp, 0x28
