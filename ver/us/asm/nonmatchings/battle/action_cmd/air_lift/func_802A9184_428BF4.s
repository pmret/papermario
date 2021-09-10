.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9184_428BF4
/* 428BF4 802A9184 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 428BF8 802A9188 AFB20018 */  sw        $s2, 0x18($sp)
/* 428BFC 802A918C 0080902D */  daddu     $s2, $a0, $zero
/* 428C00 802A9190 AFBF001C */  sw        $ra, 0x1c($sp)
/* 428C04 802A9194 AFB10014 */  sw        $s1, 0x14($sp)
/* 428C08 802A9198 AFB00010 */  sw        $s0, 0x10($sp)
/* 428C0C 802A919C 0C09A216 */  jal       func_80268858
/* 428C10 802A91A0 8E50000C */   lw       $s0, 0xc($s2)
/* 428C14 802A91A4 0240202D */  daddu     $a0, $s2, $zero
/* 428C18 802A91A8 8E050000 */  lw        $a1, ($s0)
/* 428C1C 802A91AC 0C0B1EAF */  jal       evt_get_variable
/* 428C20 802A91B0 26100004 */   addiu    $s0, $s0, 4
/* 428C24 802A91B4 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 428C28 802A91B8 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 428C2C 802A91BC A622004E */  sh        $v0, 0x4e($s1)
/* 428C30 802A91C0 8E050000 */  lw        $a1, ($s0)
/* 428C34 802A91C4 26100004 */  addiu     $s0, $s0, 4
/* 428C38 802A91C8 0C0B1EAF */  jal       evt_get_variable
/* 428C3C 802A91CC 0240202D */   daddu    $a0, $s2, $zero
/* 428C40 802A91D0 A6220052 */  sh        $v0, 0x52($s1)
/* 428C44 802A91D4 8E050000 */  lw        $a1, ($s0)
/* 428C48 802A91D8 26100004 */  addiu     $s0, $s0, 4
/* 428C4C 802A91DC 0C0B1EAF */  jal       evt_get_variable
/* 428C50 802A91E0 0240202D */   daddu    $a0, $s2, $zero
/* 428C54 802A91E4 00022400 */  sll       $a0, $v0, 0x10
/* 428C58 802A91E8 00042403 */  sra       $a0, $a0, 0x10
/* 428C5C 802A91EC 0C09A089 */  jal       func_80268224
/* 428C60 802A91F0 A6220050 */   sh       $v0, 0x50($s1)
/* 428C64 802A91F4 A6220050 */  sh        $v0, 0x50($s1)
/* 428C68 802A91F8 8E050000 */  lw        $a1, ($s0)
/* 428C6C 802A91FC 0C0B1EAF */  jal       evt_get_variable
/* 428C70 802A9200 0240202D */   daddu    $a0, $s2, $zero
/* 428C74 802A9204 3C05FFFF */  lui       $a1, 0xffff
/* 428C78 802A9208 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 428C7C 802A920C 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 428C80 802A9210 A6220064 */  sh        $v0, 0x64($s1)
/* 428C84 802A9214 A2200060 */  sb        $zero, 0x60($s1)
/* 428C88 802A9218 A0800081 */  sb        $zero, 0x81($a0)
/* 428C8C 802A921C 82220080 */  lb        $v0, 0x80($s1)
/* 428C90 802A9220 2403007F */  addiu     $v1, $zero, 0x7f
/* 428C94 802A9224 A0830086 */  sb        $v1, 0x86($a0)
/* 428C98 802A9228 2442FFFF */  addiu     $v0, $v0, -1
/* 428C9C 802A922C 00021040 */  sll       $v0, $v0, 1
/* 428CA0 802A9230 00511021 */  addu      $v0, $v0, $s1
/* 428CA4 802A9234 90430075 */  lbu       $v1, 0x75($v0)
/* 428CA8 802A9238 8C820000 */  lw        $v0, ($a0)
/* 428CAC 802A923C 34A57FFF */  ori       $a1, $a1, 0x7fff
/* 428CB0 802A9240 A220005C */  sb        $zero, 0x5c($s1)
/* 428CB4 802A9244 00451024 */  and       $v0, $v0, $a1
/* 428CB8 802A9248 AC820000 */  sw        $v0, ($a0)
/* 428CBC 802A924C 2402000A */  addiu     $v0, $zero, 0xa
/* 428CC0 802A9250 A622004C */  sh        $v0, 0x4c($s1)
/* 428CC4 802A9254 0C09A446 */  jal       func_80269118
/* 428CC8 802A9258 A0830082 */   sb       $v1, 0x82($a0)
/* 428CCC 802A925C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 428CD0 802A9260 8FB20018 */  lw        $s2, 0x18($sp)
/* 428CD4 802A9264 8FB10014 */  lw        $s1, 0x14($sp)
/* 428CD8 802A9268 8FB00010 */  lw        $s0, 0x10($sp)
/* 428CDC 802A926C 24020002 */  addiu     $v0, $zero, 2
/* 428CE0 802A9270 03E00008 */  jr        $ra
/* 428CE4 802A9274 27BD0020 */   addiu    $sp, $sp, 0x20
