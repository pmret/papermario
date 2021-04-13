.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9178_426B48
/* 426B48 802A9178 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 426B4C 802A917C AFB3001C */  sw        $s3, 0x1c($sp)
/* 426B50 802A9180 0080982D */  daddu     $s3, $a0, $zero
/* 426B54 802A9184 AFB10014 */  sw        $s1, 0x14($sp)
/* 426B58 802A9188 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 426B5C 802A918C 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 426B60 802A9190 AFB20018 */  sw        $s2, 0x18($sp)
/* 426B64 802A9194 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 426B68 802A9198 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 426B6C 802A919C AFBF0020 */  sw        $ra, 0x20($sp)
/* 426B70 802A91A0 AFB00010 */  sw        $s0, 0x10($sp)
/* 426B74 802A91A4 82420083 */  lb        $v0, 0x83($s2)
/* 426B78 802A91A8 8E70000C */  lw        $s0, 0xc($s3)
/* 426B7C 802A91AC 10400030 */  beqz      $v0, .L802A9270
/* 426B80 802A91B0 0240182D */   daddu    $v1, $s2, $zero
/* 426B84 802A91B4 0C09A216 */  jal       func_80268858
/* 426B88 802A91B8 00000000 */   nop
/* 426B8C 802A91BC 8E050000 */  lw        $a1, ($s0)
/* 426B90 802A91C0 26100004 */  addiu     $s0, $s0, 4
/* 426B94 802A91C4 0C0B1EAF */  jal       get_variable
/* 426B98 802A91C8 0260202D */   daddu    $a0, $s3, $zero
/* 426B9C 802A91CC A622004E */  sh        $v0, 0x4e($s1)
/* 426BA0 802A91D0 8E050000 */  lw        $a1, ($s0)
/* 426BA4 802A91D4 26100004 */  addiu     $s0, $s0, 4
/* 426BA8 802A91D8 0C0B1EAF */  jal       get_variable
/* 426BAC 802A91DC 0260202D */   daddu    $a0, $s3, $zero
/* 426BB0 802A91E0 A6220052 */  sh        $v0, 0x52($s1)
/* 426BB4 802A91E4 8E050000 */  lw        $a1, ($s0)
/* 426BB8 802A91E8 26100004 */  addiu     $s0, $s0, 4
/* 426BBC 802A91EC 0C0B1EAF */  jal       get_variable
/* 426BC0 802A91F0 0260202D */   daddu    $a0, $s3, $zero
/* 426BC4 802A91F4 00022400 */  sll       $a0, $v0, 0x10
/* 426BC8 802A91F8 00042403 */  sra       $a0, $a0, 0x10
/* 426BCC 802A91FC 0C09A089 */  jal       func_80268224
/* 426BD0 802A9200 A6220050 */   sh       $v0, 0x50($s1)
/* 426BD4 802A9204 A6220050 */  sh        $v0, 0x50($s1)
/* 426BD8 802A9208 8E050000 */  lw        $a1, ($s0)
/* 426BDC 802A920C 0C0B1EAF */  jal       get_variable
/* 426BE0 802A9210 0260202D */   daddu    $a0, $s3, $zero
/* 426BE4 802A9214 3C05FFFF */  lui       $a1, 0xffff
/* 426BE8 802A9218 34A57FFF */  ori       $a1, $a1, 0x7fff
/* 426BEC 802A921C A6220064 */  sh        $v0, 0x64($s1)
/* 426BF0 802A9220 A2200060 */  sb        $zero, 0x60($s1)
/* 426BF4 802A9224 A6200044 */  sh        $zero, 0x44($s1)
/* 426BF8 802A9228 A6200048 */  sh        $zero, 0x48($s1)
/* 426BFC 802A922C A2400081 */  sb        $zero, 0x81($s2)
/* 426C00 802A9230 82220080 */  lb        $v0, 0x80($s1)
/* 426C04 802A9234 2403007F */  addiu     $v1, $zero, 0x7f
/* 426C08 802A9238 A2430086 */  sb        $v1, 0x86($s2)
/* 426C0C 802A923C 8E430000 */  lw        $v1, ($s2)
/* 426C10 802A9240 2442FFFF */  addiu     $v0, $v0, -1
/* 426C14 802A9244 00021040 */  sll       $v0, $v0, 1
/* 426C18 802A9248 00511021 */  addu      $v0, $v0, $s1
/* 426C1C 802A924C 00651824 */  and       $v1, $v1, $a1
/* 426C20 802A9250 90440075 */  lbu       $a0, 0x75($v0)
/* 426C24 802A9254 2402000A */  addiu     $v0, $zero, 0xa
/* 426C28 802A9258 AE430000 */  sw        $v1, ($s2)
/* 426C2C 802A925C A622004C */  sh        $v0, 0x4c($s1)
/* 426C30 802A9260 0C09A446 */  jal       func_80269118
/* 426C34 802A9264 A2440082 */   sb       $a0, 0x82($s2)
/* 426C38 802A9268 080AA49E */  j         .L802A9278
/* 426C3C 802A926C 24020002 */   addiu    $v0, $zero, 2
.L802A9270:
/* 426C40 802A9270 A0600081 */  sb        $zero, 0x81($v1)
/* 426C44 802A9274 24020002 */  addiu     $v0, $zero, 2
.L802A9278:
/* 426C48 802A9278 8FBF0020 */  lw        $ra, 0x20($sp)
/* 426C4C 802A927C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 426C50 802A9280 8FB20018 */  lw        $s2, 0x18($sp)
/* 426C54 802A9284 8FB10014 */  lw        $s1, 0x14($sp)
/* 426C58 802A9288 8FB00010 */  lw        $s0, 0x10($sp)
/* 426C5C 802A928C 03E00008 */  jr        $ra
/* 426C60 802A9290 27BD0028 */   addiu    $sp, $sp, 0x28
