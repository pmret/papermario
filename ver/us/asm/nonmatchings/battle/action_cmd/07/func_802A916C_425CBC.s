.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A916C_425CBC
/* 425CBC 802A916C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 425CC0 802A9170 AFB20018 */  sw        $s2, 0x18($sp)
/* 425CC4 802A9174 0080902D */  daddu     $s2, $a0, $zero
/* 425CC8 802A9178 AFBF001C */  sw        $ra, 0x1c($sp)
/* 425CCC 802A917C AFB10014 */  sw        $s1, 0x14($sp)
/* 425CD0 802A9180 AFB00010 */  sw        $s0, 0x10($sp)
/* 425CD4 802A9184 8E50000C */  lw        $s0, 0xc($s2)
/* 425CD8 802A9188 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 425CDC 802A918C 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 425CE0 802A9190 A220005E */  sb        $zero, 0x5e($s1)
/* 425CE4 802A9194 8E050000 */  lw        $a1, ($s0)
/* 425CE8 802A9198 0C0B1EAF */  jal       evt_get_variable
/* 425CEC 802A919C 26100004 */   addiu    $s0, $s0, 4
/* 425CF0 802A91A0 A622004E */  sh        $v0, 0x4e($s1)
/* 425CF4 802A91A4 8E050000 */  lw        $a1, ($s0)
/* 425CF8 802A91A8 26100004 */  addiu     $s0, $s0, 4
/* 425CFC 802A91AC 0C0B1EAF */  jal       evt_get_variable
/* 425D00 802A91B0 0240202D */   daddu    $a0, $s2, $zero
/* 425D04 802A91B4 A6220052 */  sh        $v0, 0x52($s1)
/* 425D08 802A91B8 8E050000 */  lw        $a1, ($s0)
/* 425D0C 802A91BC 0C0B1EAF */  jal       evt_get_variable
/* 425D10 802A91C0 0240202D */   daddu    $a0, $s2, $zero
/* 425D14 802A91C4 00022400 */  sll       $a0, $v0, 0x10
/* 425D18 802A91C8 00042403 */  sra       $a0, $a0, 0x10
/* 425D1C 802A91CC 0C09A089 */  jal       func_80268224
/* 425D20 802A91D0 A6220050 */   sh       $v0, 0x50($s1)
/* 425D24 802A91D4 3C05FFFF */  lui       $a1, 0xffff
/* 425D28 802A91D8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 425D2C 802A91DC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 425D30 802A91E0 8C640000 */  lw        $a0, ($v1)
/* 425D34 802A91E4 34A57FFF */  ori       $a1, $a1, 0x7fff
/* 425D38 802A91E8 A6220050 */  sh        $v0, 0x50($s1)
/* 425D3C 802A91EC A2200060 */  sb        $zero, 0x60($s1)
/* 425D40 802A91F0 A0600081 */  sb        $zero, 0x81($v1)
/* 425D44 802A91F4 A0600086 */  sb        $zero, 0x86($v1)
/* 425D48 802A91F8 00852024 */  and       $a0, $a0, $a1
/* 425D4C 802A91FC 0C093EBF */  jal       func_8024FAFC
/* 425D50 802A9200 AC640000 */   sw       $a0, ($v1)
/* 425D54 802A9204 2403000A */  addiu     $v1, $zero, 0xa
/* 425D58 802A9208 A623004C */  sh        $v1, 0x4c($s1)
/* 425D5C 802A920C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 425D60 802A9210 8FB20018 */  lw        $s2, 0x18($sp)
/* 425D64 802A9214 8FB10014 */  lw        $s1, 0x14($sp)
/* 425D68 802A9218 8FB00010 */  lw        $s0, 0x10($sp)
/* 425D6C 802A921C 24020002 */  addiu     $v0, $zero, 2
/* 425D70 802A9220 03E00008 */  jr        $ra
/* 425D74 802A9224 27BD0020 */   addiu    $sp, $sp, 0x20
