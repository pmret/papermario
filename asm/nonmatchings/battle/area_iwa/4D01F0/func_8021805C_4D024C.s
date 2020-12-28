.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021805C_4D024C
/* 4D024C 8021805C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4D0250 80218060 AFB10014 */  sw        $s1, 0x14($sp)
/* 4D0254 80218064 0080882D */  daddu     $s1, $a0, $zero
/* 4D0258 80218068 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4D025C 8021806C AFB00010 */  sw        $s0, 0x10($sp)
/* 4D0260 80218070 8E30000C */  lw        $s0, 0xc($s1)
/* 4D0264 80218074 8E050000 */  lw        $a1, ($s0)
/* 4D0268 80218078 0C0B1EAF */  jal       get_variable
/* 4D026C 8021807C 26100004 */   addiu    $s0, $s0, 4
/* 4D0270 80218080 0220202D */  daddu     $a0, $s1, $zero
/* 4D0274 80218084 8E050000 */  lw        $a1, ($s0)
/* 4D0278 80218088 0C0B1EAF */  jal       get_variable
/* 4D027C 8021808C 0040802D */   daddu    $s0, $v0, $zero
/* 4D0280 80218090 0200202D */  daddu     $a0, $s0, $zero
/* 4D0284 80218094 0C00A3C2 */  jal       start_rumble
/* 4D0288 80218098 0040282D */   daddu    $a1, $v0, $zero
/* 4D028C 8021809C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4D0290 802180A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 4D0294 802180A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 4D0298 802180A8 24020002 */  addiu     $v0, $zero, 2
/* 4D029C 802180AC 03E00008 */  jr        $ra
/* 4D02A0 802180B0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 4D02A4 802180B4 00000000 */  nop       
/* 4D02A8 802180B8 00000000 */  nop       
/* 4D02AC 802180BC 00000000 */  nop       
