.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A917C_42E51C
/* 42E51C 802A917C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42E520 802A9180 AFB3001C */  sw        $s3, 0x1c($sp)
/* 42E524 802A9184 0080982D */  daddu     $s3, $a0, $zero
/* 42E528 802A9188 AFB10014 */  sw        $s1, 0x14($sp)
/* 42E52C 802A918C 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 42E530 802A9190 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 42E534 802A9194 AFB20018 */  sw        $s2, 0x18($sp)
/* 42E538 802A9198 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 42E53C 802A919C 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 42E540 802A91A0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 42E544 802A91A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 42E548 802A91A8 82420083 */  lb        $v0, 0x83($s2)
/* 42E54C 802A91AC 8E70000C */  lw        $s0, 0xc($s3)
/* 42E550 802A91B0 10400030 */  beqz      $v0, .L802A9274
/* 42E554 802A91B4 0240182D */   daddu    $v1, $s2, $zero
/* 42E558 802A91B8 0C09A216 */  jal       func_80268858
/* 42E55C 802A91BC 00000000 */   nop
/* 42E560 802A91C0 8E050000 */  lw        $a1, ($s0)
/* 42E564 802A91C4 26100004 */  addiu     $s0, $s0, 4
/* 42E568 802A91C8 0C0B1EAF */  jal       get_variable
/* 42E56C 802A91CC 0260202D */   daddu    $a0, $s3, $zero
/* 42E570 802A91D0 A622004E */  sh        $v0, 0x4e($s1)
/* 42E574 802A91D4 8E050000 */  lw        $a1, ($s0)
/* 42E578 802A91D8 26100004 */  addiu     $s0, $s0, 4
/* 42E57C 802A91DC 0C0B1EAF */  jal       get_variable
/* 42E580 802A91E0 0260202D */   daddu    $a0, $s3, $zero
/* 42E584 802A91E4 A6220052 */  sh        $v0, 0x52($s1)
/* 42E588 802A91E8 8E050000 */  lw        $a1, ($s0)
/* 42E58C 802A91EC 26100004 */  addiu     $s0, $s0, 4
/* 42E590 802A91F0 0C0B1EAF */  jal       get_variable
/* 42E594 802A91F4 0260202D */   daddu    $a0, $s3, $zero
/* 42E598 802A91F8 00022400 */  sll       $a0, $v0, 0x10
/* 42E59C 802A91FC 00042403 */  sra       $a0, $a0, 0x10
/* 42E5A0 802A9200 0C09A089 */  jal       func_80268224
/* 42E5A4 802A9204 A6220050 */   sh       $v0, 0x50($s1)
/* 42E5A8 802A9208 A6220050 */  sh        $v0, 0x50($s1)
/* 42E5AC 802A920C 8E050000 */  lw        $a1, ($s0)
/* 42E5B0 802A9210 0C0B1EAF */  jal       get_variable
/* 42E5B4 802A9214 0260202D */   daddu    $a0, $s3, $zero
/* 42E5B8 802A9218 3C05FFFF */  lui       $a1, 0xffff
/* 42E5BC 802A921C 34A57FFF */  ori       $a1, $a1, 0x7fff
/* 42E5C0 802A9220 A6220064 */  sh        $v0, 0x64($s1)
/* 42E5C4 802A9224 A2200060 */  sb        $zero, 0x60($s1)
/* 42E5C8 802A9228 A6200044 */  sh        $zero, 0x44($s1)
/* 42E5CC 802A922C A6200048 */  sh        $zero, 0x48($s1)
/* 42E5D0 802A9230 A2400081 */  sb        $zero, 0x81($s2)
/* 42E5D4 802A9234 82220080 */  lb        $v0, 0x80($s1)
/* 42E5D8 802A9238 2403007F */  addiu     $v1, $zero, 0x7f
/* 42E5DC 802A923C A2430086 */  sb        $v1, 0x86($s2)
/* 42E5E0 802A9240 8E430000 */  lw        $v1, ($s2)
/* 42E5E4 802A9244 2442FFFF */  addiu     $v0, $v0, -1
/* 42E5E8 802A9248 00021040 */  sll       $v0, $v0, 1
/* 42E5EC 802A924C 00511021 */  addu      $v0, $v0, $s1
/* 42E5F0 802A9250 00651824 */  and       $v1, $v1, $a1
/* 42E5F4 802A9254 90440075 */  lbu       $a0, 0x75($v0)
/* 42E5F8 802A9258 2402000A */  addiu     $v0, $zero, 0xa
/* 42E5FC 802A925C AE430000 */  sw        $v1, ($s2)
/* 42E600 802A9260 A622004C */  sh        $v0, 0x4c($s1)
/* 42E604 802A9264 0C09A446 */  jal       func_80269118
/* 42E608 802A9268 A2440082 */   sb       $a0, 0x82($s2)
/* 42E60C 802A926C 080AA49F */  j         .L802A927C
/* 42E610 802A9270 24020002 */   addiu    $v0, $zero, 2
.L802A9274:
/* 42E614 802A9274 A0600081 */  sb        $zero, 0x81($v1)
/* 42E618 802A9278 24020002 */  addiu     $v0, $zero, 2
.L802A927C:
/* 42E61C 802A927C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 42E620 802A9280 8FB3001C */  lw        $s3, 0x1c($sp)
/* 42E624 802A9284 8FB20018 */  lw        $s2, 0x18($sp)
/* 42E628 802A9288 8FB10014 */  lw        $s1, 0x14($sp)
/* 42E62C 802A928C 8FB00010 */  lw        $s0, 0x10($sp)
/* 42E630 802A9290 03E00008 */  jr        $ra
/* 42E634 802A9294 27BD0028 */   addiu    $sp, $sp, 0x28
