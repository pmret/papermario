.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A91B0_4235A0
/* 4235A0 802A91B0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4235A4 802A91B4 AFB20018 */  sw        $s2, 0x18($sp)
/* 4235A8 802A91B8 0080902D */  daddu     $s2, $a0, $zero
/* 4235AC 802A91BC AFB10014 */  sw        $s1, 0x14($sp)
/* 4235B0 802A91C0 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 4235B4 802A91C4 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 4235B8 802A91C8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4235BC 802A91CC 3C13800E */  lui       $s3, %hi(gBattleStatus)
/* 4235C0 802A91D0 2673C070 */  addiu     $s3, $s3, %lo(gBattleStatus)
/* 4235C4 802A91D4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 4235C8 802A91D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 4235CC 802A91DC 82620083 */  lb        $v0, 0x83($s3)
/* 4235D0 802A91E0 8E50000C */  lw        $s0, 0xc($s2)
/* 4235D4 802A91E4 10400034 */  beqz      $v0, .L802A92B8
/* 4235D8 802A91E8 0260182D */   daddu    $v1, $s3, $zero
/* 4235DC 802A91EC 0C09A216 */  jal       func_80268858
/* 4235E0 802A91F0 00000000 */   nop
/* 4235E4 802A91F4 8E050000 */  lw        $a1, ($s0)
/* 4235E8 802A91F8 26100004 */  addiu     $s0, $s0, 4
/* 4235EC 802A91FC 0C0B1EAF */  jal       get_variable
/* 4235F0 802A9200 0240202D */   daddu    $a0, $s2, $zero
/* 4235F4 802A9204 A622004E */  sh        $v0, 0x4e($s1)
/* 4235F8 802A9208 8E050000 */  lw        $a1, ($s0)
/* 4235FC 802A920C 26100004 */  addiu     $s0, $s0, 4
/* 423600 802A9210 0C0B1EAF */  jal       get_variable
/* 423604 802A9214 0240202D */   daddu    $a0, $s2, $zero
/* 423608 802A9218 A6220052 */  sh        $v0, 0x52($s1)
/* 42360C 802A921C 8E050000 */  lw        $a1, ($s0)
/* 423610 802A9220 26100004 */  addiu     $s0, $s0, 4
/* 423614 802A9224 0C0B1EAF */  jal       get_variable
/* 423618 802A9228 0240202D */   daddu    $a0, $s2, $zero
/* 42361C 802A922C A622005A */  sh        $v0, 0x5a($s1)
/* 423620 802A9230 8E050000 */  lw        $a1, ($s0)
/* 423624 802A9234 0C0B1EAF */  jal       get_variable
/* 423628 802A9238 0240202D */   daddu    $a0, $s2, $zero
/* 42362C 802A923C 00022400 */  sll       $a0, $v0, 0x10
/* 423630 802A9240 00042403 */  sra       $a0, $a0, 0x10
/* 423634 802A9244 0C09A089 */  jal       func_80268224
/* 423638 802A9248 A6220050 */   sh       $v0, 0x50($s1)
/* 42363C 802A924C 8624005A */  lh        $a0, 0x5a($s1)
/* 423640 802A9250 A6220050 */  sh        $v0, 0x50($s1)
/* 423644 802A9254 A2200060 */  sb        $zero, 0x60($s1)
/* 423648 802A9258 A6200044 */  sh        $zero, 0x44($s1)
/* 42364C 802A925C A6200046 */  sh        $zero, 0x46($s1)
/* 423650 802A9260 A6200048 */  sh        $zero, 0x48($s1)
/* 423654 802A9264 A2600081 */  sb        $zero, 0x81($s3)
/* 423658 802A9268 82220080 */  lb        $v0, 0x80($s1)
/* 42365C 802A926C 2403007F */  addiu     $v1, $zero, 0x7f
/* 423660 802A9270 A2630086 */  sb        $v1, 0x86($s3)
/* 423664 802A9274 2442FFFF */  addiu     $v0, $v0, -1
/* 423668 802A9278 00021040 */  sll       $v0, $v0, 1
/* 42366C 802A927C 00511021 */  addu      $v0, $v0, $s1
/* 423670 802A9280 90420075 */  lbu       $v0, 0x75($v0)
/* 423674 802A9284 0C00A67F */  jal       rand_int
/* 423678 802A9288 A2620082 */   sb       $v0, 0x82($s3)
/* 42367C 802A928C 3C05FFFF */  lui       $a1, 0xffff
/* 423680 802A9290 34A57FFF */  ori       $a1, $a1, 0x7fff
/* 423684 802A9294 A6220046 */  sh        $v0, 0x46($s1)
/* 423688 802A9298 24020002 */  addiu     $v0, $zero, 2
/* 42368C 802A929C A220005C */  sb        $zero, 0x5c($s1)
/* 423690 802A92A0 8E630000 */  lw        $v1, ($s3)
/* 423694 802A92A4 2404000A */  addiu     $a0, $zero, 0xa
/* 423698 802A92A8 A624004C */  sh        $a0, 0x4c($s1)
/* 42369C 802A92AC 00651824 */  and       $v1, $v1, $a1
/* 4236A0 802A92B0 080AA4B0 */  j         .L802A92C0
/* 4236A4 802A92B4 AE630000 */   sw       $v1, ($s3)
.L802A92B8:
/* 4236A8 802A92B8 A0600081 */  sb        $zero, 0x81($v1)
/* 4236AC 802A92BC 24020002 */  addiu     $v0, $zero, 2
.L802A92C0:
/* 4236B0 802A92C0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4236B4 802A92C4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4236B8 802A92C8 8FB20018 */  lw        $s2, 0x18($sp)
/* 4236BC 802A92CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 4236C0 802A92D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 4236C4 802A92D4 03E00008 */  jr        $ra
/* 4236C8 802A92D8 27BD0028 */   addiu    $sp, $sp, 0x28
