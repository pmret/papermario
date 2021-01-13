.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9170_427BE0
/* 427BE0 802A9170 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 427BE4 802A9174 AFB3001C */  sw        $s3, 0x1c($sp)
/* 427BE8 802A9178 0080982D */  daddu     $s3, $a0, $zero
/* 427BEC 802A917C AFB10014 */  sw        $s1, 0x14($sp)
/* 427BF0 802A9180 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 427BF4 802A9184 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 427BF8 802A9188 AFB20018 */  sw        $s2, 0x18($sp)
/* 427BFC 802A918C 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 427C00 802A9190 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 427C04 802A9194 AFBF0020 */  sw        $ra, 0x20($sp)
/* 427C08 802A9198 AFB00010 */  sw        $s0, 0x10($sp)
/* 427C0C 802A919C 82420083 */  lb        $v0, 0x83($s2)
/* 427C10 802A91A0 8E70000C */  lw        $s0, 0xc($s3)
/* 427C14 802A91A4 10400030 */  beqz      $v0, .L802A9268
/* 427C18 802A91A8 0240182D */   daddu    $v1, $s2, $zero
/* 427C1C 802A91AC 0C09A216 */  jal       func_80268858
/* 427C20 802A91B0 00000000 */   nop
/* 427C24 802A91B4 8E050000 */  lw        $a1, ($s0)
/* 427C28 802A91B8 26100004 */  addiu     $s0, $s0, 4
/* 427C2C 802A91BC 0C0B1EAF */  jal       get_variable
/* 427C30 802A91C0 0260202D */   daddu    $a0, $s3, $zero
/* 427C34 802A91C4 A622004E */  sh        $v0, 0x4e($s1)
/* 427C38 802A91C8 8E050000 */  lw        $a1, ($s0)
/* 427C3C 802A91CC 26100004 */  addiu     $s0, $s0, 4
/* 427C40 802A91D0 0C0B1EAF */  jal       get_variable
/* 427C44 802A91D4 0260202D */   daddu    $a0, $s3, $zero
/* 427C48 802A91D8 A6220052 */  sh        $v0, 0x52($s1)
/* 427C4C 802A91DC 8E050000 */  lw        $a1, ($s0)
/* 427C50 802A91E0 26100004 */  addiu     $s0, $s0, 4
/* 427C54 802A91E4 0C0B1EAF */  jal       get_variable
/* 427C58 802A91E8 0260202D */   daddu    $a0, $s3, $zero
/* 427C5C 802A91EC 00022400 */  sll       $a0, $v0, 0x10
/* 427C60 802A91F0 00042403 */  sra       $a0, $a0, 0x10
/* 427C64 802A91F4 0C09A089 */  jal       func_80268224
/* 427C68 802A91F8 A6220050 */   sh       $v0, 0x50($s1)
/* 427C6C 802A91FC A6220050 */  sh        $v0, 0x50($s1)
/* 427C70 802A9200 8E050000 */  lw        $a1, ($s0)
/* 427C74 802A9204 0C0B1EAF */  jal       get_variable
/* 427C78 802A9208 0260202D */   daddu    $a0, $s3, $zero
/* 427C7C 802A920C 3C05FFFF */  lui       $a1, 0xffff
/* 427C80 802A9210 34A57FFF */  ori       $a1, $a1, 0x7fff
/* 427C84 802A9214 A6220064 */  sh        $v0, 0x64($s1)
/* 427C88 802A9218 A2200060 */  sb        $zero, 0x60($s1)
/* 427C8C 802A921C A6200044 */  sh        $zero, 0x44($s1)
/* 427C90 802A9220 A6200048 */  sh        $zero, 0x48($s1)
/* 427C94 802A9224 A2400081 */  sb        $zero, 0x81($s2)
/* 427C98 802A9228 82220080 */  lb        $v0, 0x80($s1)
/* 427C9C 802A922C 2403007F */  addiu     $v1, $zero, 0x7f
/* 427CA0 802A9230 A2430086 */  sb        $v1, 0x86($s2)
/* 427CA4 802A9234 8E430000 */  lw        $v1, ($s2)
/* 427CA8 802A9238 2442FFFF */  addiu     $v0, $v0, -1
/* 427CAC 802A923C 00021040 */  sll       $v0, $v0, 1
/* 427CB0 802A9240 00511021 */  addu      $v0, $v0, $s1
/* 427CB4 802A9244 00651824 */  and       $v1, $v1, $a1
/* 427CB8 802A9248 90440075 */  lbu       $a0, 0x75($v0)
/* 427CBC 802A924C 2402000A */  addiu     $v0, $zero, 0xa
/* 427CC0 802A9250 AE430000 */  sw        $v1, ($s2)
/* 427CC4 802A9254 A622004C */  sh        $v0, 0x4c($s1)
/* 427CC8 802A9258 0C09A446 */  jal       func_80269118
/* 427CCC 802A925C A2440082 */   sb       $a0, 0x82($s2)
/* 427CD0 802A9260 080AA49C */  j         .L802A9270
/* 427CD4 802A9264 24020002 */   addiu    $v0, $zero, 2
.L802A9268:
/* 427CD8 802A9268 A0600081 */  sb        $zero, 0x81($v1)
/* 427CDC 802A926C 24020002 */  addiu     $v0, $zero, 2
.L802A9270:
/* 427CE0 802A9270 8FBF0020 */  lw        $ra, 0x20($sp)
/* 427CE4 802A9274 8FB3001C */  lw        $s3, 0x1c($sp)
/* 427CE8 802A9278 8FB20018 */  lw        $s2, 0x18($sp)
/* 427CEC 802A927C 8FB10014 */  lw        $s1, 0x14($sp)
/* 427CF0 802A9280 8FB00010 */  lw        $s0, 0x10($sp)
/* 427CF4 802A9284 03E00008 */  jr        $ra
/* 427CF8 802A9288 27BD0028 */   addiu    $sp, $sp, 0x28
