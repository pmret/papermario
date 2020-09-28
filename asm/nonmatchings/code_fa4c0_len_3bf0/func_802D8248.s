.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D8248
/* FCBF8 802D8248 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* FCBFC 802D824C AFB10014 */  sw        $s1, 0x14($sp)
/* FCC00 802D8250 0080882D */  daddu     $s1, $a0, $zero
/* FCC04 802D8254 AFBF0018 */  sw        $ra, 0x18($sp)
/* FCC08 802D8258 AFB00010 */  sw        $s0, 0x10($sp)
/* FCC0C 802D825C 8E30000C */  lw        $s0, 0xc($s1)
/* FCC10 802D8260 8E050000 */  lw        $a1, ($s0)
/* FCC14 802D8264 0C0B1EAF */  jal       get_variable
/* FCC18 802D8268 26100004 */   addiu    $s0, $s0, 4
/* FCC1C 802D826C 0220202D */  daddu     $a0, $s1, $zero
/* FCC20 802D8270 8E050000 */  lw        $a1, ($s0)
/* FCC24 802D8274 0C0B1EAF */  jal       get_variable
/* FCC28 802D8278 0040802D */   daddu    $s0, $v0, $zero
/* FCC2C 802D827C 8E03000C */  lw        $v1, 0xc($s0)
/* FCC30 802D8280 AC62001C */  sw        $v0, 0x1c($v1)
/* FCC34 802D8284 8FBF0018 */  lw        $ra, 0x18($sp)
/* FCC38 802D8288 8FB10014 */  lw        $s1, 0x14($sp)
/* FCC3C 802D828C 8FB00010 */  lw        $s0, 0x10($sp)
/* FCC40 802D8290 24020002 */  addiu     $v0, $zero, 2
/* FCC44 802D8294 03E00008 */  jr        $ra
/* FCC48 802D8298 27BD0020 */   addiu    $sp, $sp, 0x20
